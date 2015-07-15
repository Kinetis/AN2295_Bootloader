/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      spi.c
 * @version   1.0.7.0
 * @date      Apr-20-2015
 * @brief     Serial Peripheral Interface (SPI) driver source code.
******************************************************************************/
#include "common.h"
#include "spi.h"

#if !defined(MCU_MKM34ZA5)
  #error "The spi.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static SPI_CALLBACK     pCallbackSPI0, pCallbackSPI1;
static SPI_SSCALLBACK   pCallbackSS0, pCallbackSS1;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
void SPI0_Init (tSPI spi,SPI_SSCALLBACK pC2,uint8 ip,SPI_CALLBACK pC1)
{
  /* main callback function initialization                                    */
  if (pC1) { pCallbackSPI0 = pC1; NVIC_SetIsr(INT_SPI0,ip); }

  /* initialization of SS callback function where SS will be driven manually  */
  if (pC2) { pCallbackSS0 = pC2; pCallbackSS0 (SS_INIT);  }

  /* SPI configuration (without C3 register)                                  */
  SPI0_C1  = spi.C1;              /* SPI control register 1                   */
  SPI0_C2  = spi.C2;              /* SPI control register 2                   */
  SPI0_BR  = spi.BR;              /* SPI baud rate register                   */
  SPI0_ML  = spi.ML;              /* SPI match register low                   */
  SPI0_MH  = spi.MH;              /* SPI match register high                  */
  SPI0_C1 |= SPI_C1_SPE_MASK;     /* Enable SPI                               */
  /* Note: FIFO functionality is not supported in SPI0 module                 */
}

void SPI1_Init (tSPI spi,SPI_SSCALLBACK pC2,uint8 ip, SPI_CALLBACK pC1)
{
  /* main callback function initialization                                    */
  if (pC1) { pCallbackSPI1 = pC1; NVIC_SetIsr(INT_SPI1,ip); }

  /* initialization of SS callback function where SS will be driven manually  */
  if (pC2) { pCallbackSS1 = pC2; pCallbackSS1 (SS_INIT); }

  /* SPI configuration (with C3 register)                                     */
  SPI1_C1  = spi.C1;              /* SPI control register 1                   */
  SPI1_C2  = spi.C2;              /* SPI control register 2                   */
  SPI1_C3  = spi.C3;              /* SPI control register 3                   */
  SPI1_BR  = spi.BR;              /* SPI baud rate register                   */
  SPI1_ML  = spi.ML;              /* SPI match register low                   */
  SPI1_MH  = spi.MH;              /* SPI match register high                  */
  SPI1_C1 |= SPI_C1_SPE_MASK;     /* Enable SPI                               */
}

/******************************************************************************
 * Simple SPI Tx/Rx function (1 word Tx + 1 word Rx)                          *
 ******************************************************************************/
uint16 SPI0_TxRxWord(uint16 txdata)
{
  while (!SPI_TxCmpl(SPI0));      /* wait until Tx buffer is empty            */
  SPI_PutWord(SPI0,txdata);       /* write a 16-bit data                      */
  while(!SPI_RxFull(SPI0));       /* wait until Rx buffer is full             */
  return (SPI_GetWord(SPI0));     /* read data and exit                       */
}

uint16 SPI1_TxRxWord(uint16 txdata)
{
  while (!SPI_TxCmpl(SPI1));      /* wait until Tx buffer is empty            */
  SPI_PutWord(SPI1,txdata);       /* write a 16-bit data                      */
  while(!SPI_RxFull(SPI1));       /* wait until Rx buffer is full             */
  return (SPI_GetWord(SPI1));     /* read data and exit                       */
}

/******************************************************************************
 * Simple SPI Tx/Rx function (1 byte Tx + 1 byte Rx)                          *
 ******************************************************************************/
uint8 SPI0_TxRxByte(uint8 txdata)
{
  while (!SPI_TxCmpl(SPI0));      /* wait until Tx buffer is empty            */
  SPI_PutByte(SPI0,txdata);       /* write an 8-bit data                      */
  while(!SPI_RxFull(SPI0));       /* wait until Rx buffer is full             */
  return (SPI_GetByte(SPI0));     /* read data and exit                       */
}

uint8 SPI1_TxRxByte(uint8 txdata)
{
  while (!SPI_TxCmpl(SPI1));      /* wait until Tx buffer is empty            */
  SPI_PutByte(SPI1,txdata);       /* write an 8-bit data                      */
  while(!SPI_RxFull(SPI1));       /* wait until Rx buffer is full             */
  return (SPI_GetByte(SPI1));     /* read data and exit                       */
}

/******************************************************************************
 * Communication via an SPI (Tx+Rx data packet) with driving a slave select   *
 ******************************************************************************/
void SPI0_CommWord(uint16 *txdata, uint16 txcnt,uint16 *rxdata, uint16 rxcnt)
{
  register uint16 i;

  /* SS=0                                                                     */
  if (pCallbackSS0)  { pCallbackSS0 (SS_CLEAR); }

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      SPI_TxRxWord(SPI0,*txdata); /* Write a 16-bit data                      */
      txdata++;                   /* increment a source address               */
    }
  }

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
      /* read a 16-bit data with writing a dummy data to generate SCLK signal */
      *rxdata=SPI_TxRxWord(SPI0,0xFF);/* 0xFF is dummy data for writing!      */
      rxdata++;                   /* increment a destination address          */
    }
  }

  /* SS=1                                                                     */
  if (pCallbackSS0) { pCallbackSS0 (SS_SET); }
}

void SPI0_CommByte(uint8 *txdata, uint16 txcnt,uint8 *rxdata, uint16 rxcnt)
{
  register uint16 i;

  /* SS=0                                                                     */
  if (pCallbackSS0) { pCallbackSS0 (SS_CLEAR); }

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      SPI_TxRxByte(SPI0,*txdata); /* write an 8-bit data                      */
      txdata++;                   /* increment a source address               */
    }
  }

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
      /* read an 8-bit data with writing a dummy data to generate SCLK signal */
      *rxdata=SPI_TxRxByte(SPI0,0xFF);/* 0xFF is dummy data for writing!      */
      rxdata++;                   /* increment a destination address          */
    }
  }

  /* SS=1                                                                     */
  if (pCallbackSS0) { pCallbackSS0 (SS_SET); }
}

void SPI1_CommWord(uint16 *txdata, uint16 txcnt,uint16 *rxdata, uint16 rxcnt)
{
  register uint16 i;

  /* SS=0                                                                     */
  if (pCallbackSS1) { pCallbackSS1 (SS_CLEAR); }

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      SPI_TxRxWord(SPI1,*txdata); /* write a 16-bit data                      */
      txdata++;                   /* increment a source address               */
    }
  }

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
      /* read a 16-bit data with writing a dummy data to generate SCLK signal */
      *rxdata=SPI_TxRxWord(SPI1,0xFF);/* 0xFF is dummy data for writing!      */
      rxdata++;                   /* increment a destination address          */
    }
  }

  /* SS=1                                                                     */
  if (pCallbackSS1) { pCallbackSS1 (SS_SET); }
}

void SPI1_CommByte(uint8 *txdata, uint16 txcnt,uint8 *rxdata, uint16 rxcnt)
{
  register uint16 i;

  /* SS=0                                                                     */
  if (pCallbackSS1) { pCallbackSS1 (SS_CLEAR); }

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      SPI_TxRxByte(SPI1,*txdata); /* write an 8-bit data                      */
      txdata++;                   /* increment a source address               */
    }
  }

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
      /*read an 8-bit data with writing a dummy data to generate SCLK signal  */
      *rxdata=SPI_TxRxByte(SPI1,0xFF);/* 0xFF is dummy data for writing!      */
      rxdata++;                   /* increment a destination address          */
    }
  }

  /* SS=1                                                                     */
  if (pCallbackSS1) { pCallbackSS1 (SS_SET); }
}

void SPI1_PutWordToFifo(uint16 *txdata, uint32 txcnt)
{
  register uint32 i;

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      if(!(SPI_TxFifoFull(SPI1))) {  /* isn't transmit FIFO full?             */
        SPI_PutWord(SPI1,*txdata);/* write 16-bit data                        */
        txdata++;                 /* increment a source address               */
      }
      else {
        return;
      }
    }
  }
}

void SPI1_PutByteToFifo(uint8 *txdata, uint32 txcnt)
{
  register uint32 i;

  if (txdata) {                   /* any data for transmitting?               */
    for (i=0; i<txcnt; i++) {     /* writing cycle                            */
      if(!(SPI_TxFifoFull(SPI1))) {  /* isn't transmit FIFO full?             */
        SPI_PutByte(SPI1,*txdata);/* write 8-bit data                         */
        txdata++;                 /* increment a source address               */
      }
      else {
        return;
      }
    }
  }
}

void SPI1_GetWordFromFifo(uint16 *rxdata, uint32 rxcnt)
{
  register uint32 i;

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
        *rxdata = SPI_GetWord(SPI1); /* read 16-bit data                      */
        if(SPI_RxFifoEmpty(SPI1)) {  /* is receive FIFO empty?                */
        return;
      }
        rxdata++;                 /* increment a destination address          */
    }
  }
}

void SPI1_GetByteFromFifo(uint8 *rxdata, uint32 rxcnt)
{
  register uint32 i;

  if (rxdata) {                   /* any data for receiving?                  */
    for (i=0; i<rxcnt; i++) {     /* reading cycle                            */
        *rxdata = SPI_GetByte(SPI1); /* read 8-bit data                       */
        if(SPI_RxFifoEmpty(SPI1)) {  /* is receive FIFO empty?                */
        return;
      }
    rxdata++;                     /* increment a destination address          */
    }
  }
}
/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void spi0_isr (void)
{
  register uint8 tmp = SPI0_S;

  /* Rx buffer or FIFO buffer is full; SPRF is cleared by reading data        */
  /* registers DH:DL                                                          */
  if(tmp & SPI_S_SPRF_MASK) { pCallbackSPI0 (SPI0_CALLBACK,SPI_RX_CALLBACK); }

  /* Tx buffer or FIFO buffer is empty; SPTEF is cleared by writing a value   */
  /* to DH:DL                                                                 */
  if(tmp & SPI_S_SPTEF_MASK){ pCallbackSPI0 (SPI0_CALLBACK,SPI_TX_CALLBACK); }

  /* Receive data buffer matches the value in MH:ML registers                 */
  if(tmp & SPI_S_SPMF_MASK)
  {
    SPI0_S = SPI_S_SPMF_MASK;                              /* clear SPMF flag */
    pCallbackSPI0 (SPI0_CALLBACK,SPI_MATCH_CALLBACK);
  }

  /* Mode fault error detected (Only for MSTR=1, MODFEN=1, SSOE=0)            */
  if(tmp & SPI_S_MODF_MASK)
  {
    SPI0_C1 = SPI0_C1;                                     /* clear MODF flag */
    pCallbackSPI0 (SPI0_CALLBACK,SPI_FAULT_CALLBACK);
  }
}

weak void spi1_isr (void)
{
  register uint8 tmp = SPI1_S;

  /* Rx buffer or Rx FIFO buffer is full; SPRF is cleared by reading data     */
  /* registers DH:DL                                                          */
  if(tmp & SPI_S_SPRF_MASK) { pCallbackSPI1 (SPI1_CALLBACK,SPI_RX_CALLBACK); }

  /* Tx buffer or Tx FIFO buffer is empty; SPTEF is cleared by writing a      */
  /* value to DH:DL                                                           */
  if(tmp & SPI_S_SPTEF_MASK){ pCallbackSPI1 (SPI1_CALLBACK,SPI_TX_CALLBACK); }

  /* Receive data buffer matches the value in MH:ML registers                 */
  if(tmp & SPI_S_SPMF_MASK)
  {
    SPI1_S = SPI_S_SPMF_MASK;                              /* clear SPMF flag */
    pCallbackSPI1 (SPI1_CALLBACK,SPI_MATCH_CALLBACK);
  }

  /* Tx FIFO buffer is near to empty; TNEAREF is cleared when enough data is  */
  /* written to FIFO buffer                                                   */
  if((tmp & SPI_S_TNEAREF_MASK) && (SPI1_C3 & SPI_C3_TNEARIEN_MASK))
  {
    pCallbackSPI1 (SPI1_CALLBACK,SPI_TXFNE_CALLBACK);
  }

  /* Rx FIFO buffer is near to full; RNFULLF is cleared when enough data is   */
  /* read from FIFO buffer                                                    */
  if((tmp & SPI_S_RNFULLF_MASK) && (SPI1_C3 & SPI_C3_RNFULLIEN_MASK))
  {
    pCallbackSPI1 (SPI1_CALLBACK,SPI_RXFNF_CALLBACK);
  }

  /* Mode fault error detected (Only for MSTR=1, MODFEN=1, SSOE=0)            */
  if(tmp & SPI_S_MODF_MASK)
  {
    SPI1_C1 = SPI1_C1;                                     /* clear MODF flag */
    pCallbackSPI1 (SPI1_CALLBACK,SPI_FAULT_CALLBACK);
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/