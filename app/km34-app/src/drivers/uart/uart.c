/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      uart.c
 * @version   1.0.5.0
 * @date      Apr-20-2015
 * @brief     Universal Asynchronous Receiver/Transmitter (UART) driver source
 *            code.
 ******************************************************************************/
#include "common.h"
#include "uart.h"

#if !defined(MCU_MKM34ZA5)
  #error "The uart.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static UART_CALLBACK pCallbackUART0_UART1;
static UART_CALLBACK pCallbackUART2_UART3;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void UART_InstallCallbackUART0_UART1 (uint8 ip, UART_CALLBACK pCallback)
{
  if (pCallback) { pCallbackUART0_UART1 = pCallback; NVIC_SetIsr(INT_SCI0_SCI1,ip); }
}

void UART_InstallCallbackUART2_UART3 (uint8 ip, UART_CALLBACK pCallback)
{
  if (pCallback) { pCallbackUART2_UART3 = pCallback; NVIC_SetIsr(INT_SCI2_SCI3,ip); }
}

void UART0_Init (tUART sci)
{
  UART0_C2 &= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );  /* disable uart operation */
  UART0_BDH     = sci.BDH;
  UART0_BDL     = sci.BDL;
  UART0_C1      = sci.C1;
  UART0_S2      = sci.S2;
  UART0_C3      = sci.C3;
  UART0_MA1     = sci.MA1;
  UART0_MA2     = sci.MA2;
  UART0_C4      = sci.C4;
  UART0_C5      = sci.C5;
  UART0_C2      = sci.C2;                           /* enable uart operation  */
}

void UART1_Init (tUART sci)
{
  UART1_C2 &= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );  /* disable uart operation */
  UART1_BDH     = sci.BDH;
  UART1_BDL     = sci.BDL;
  UART1_C1      = sci.C1;
  UART1_S2      = sci.S2;
  UART1_C3      = sci.C3;
  UART1_MA1     = sci.MA1;
  UART1_MA2     = sci.MA2;
  UART1_C4      = sci.C4;
  UART1_C5      = sci.C5;
  UART1_C2      = sci.C2;                            /* enable uart operation */
}

void UART2_Init (tUART sci)
{
  UART2_C2 &= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );  /* disable uart operation */
  UART2_BDH     = sci.BDH;
  UART2_BDL     = sci.BDL;
  UART2_C1      = sci.C1;
  UART2_S2      = sci.S2;
  UART2_C3      = sci.C3;
  UART2_MA1     = sci.MA1;
  UART2_MA2     = sci.MA2;
  UART2_C4      = sci.C4;
  UART2_C5      = sci.C5;
  UART2_C2      = sci.C2;                            /* enable uart operation */
}

void UART3_Init (tUART sci)
{
  UART3_C2 &= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );  /* disable uart operation */
  UART3_BDH     = sci.BDH;
  UART3_BDL     = sci.BDL;
  UART3_C1      = sci.C1;
  UART3_S2      = sci.S2;
  UART3_C3      = sci.C3;
  UART3_MA1     = sci.MA1;
  UART3_MA2     = sci.MA2;
  UART3_C4      = sci.C4;
  UART3_C5      = sci.C5;
  UART3_C2      = sci.C2;                           /* enable uart operation  */
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
weak void uart01_isr (void)
{
  register int32 tmp;

  /* process UART0 interrupts                                                 */
  if (SIM_SCGC4 & SIM_SCGC4_UART0_MASK)
  {
    tmp = UART0_S2 & (UART0_BDH & UART_BDH_RXEDGIE_MASK);
    if(tmp != 0)
    {
      UART0_S2 = UART0_S2;  /* clear RXEDGIF interrupt flag                   */
      pCallbackUART0_UART1 (UART0_CALLBACK, UART_EDG_CALLBACK, tmp);
    }

    tmp = UART0_S1 & (UART0_C2 & (UART_C2_RIE_MASK|UART_C2_TCIE_MASK|         \
                                  UART_C2_TIE_MASK));
    if(tmp & UART_S1_RDRF_MASK)
      pCallbackUART0_UART1 (UART0_CALLBACK, UART_RX_CALLBACK, tmp);

    if(tmp & (UART_S1_TC_MASK|UART_S1_TDRE_MASK))
      pCallbackUART0_UART1 (UART0_CALLBACK ,UART_TX_CALLBACK, tmp);

    tmp = UART0_S1 & (UART0_C3 & (UART_C3_PEIE_MASK|UART_C3_FEIE_MASK|        \
                                  UART_C3_NEIE_MASK|UART_C3_ORIE_MASK));
    if(tmp != 0)
      pCallbackUART0_UART1 (UART0_CALLBACK, UART_ER_CALLBACK, tmp);
  }

  /* process UART1 interrupts                                                 */
  if (SIM_SCGC4 & SIM_SCGC4_UART1_MASK)
  {
    tmp = UART1_S2 & (UART1_BDH & UART_BDH_RXEDGIE_MASK);
    if(tmp != 0)
    {
      UART1_S2 = UART1_S2;  /* clear RXEDGIF interrupt flag                   */
      pCallbackUART0_UART1 (UART1_CALLBACK, UART_EDG_CALLBACK, tmp);
    }

    tmp = UART1_S1 & (UART1_C2 & (UART_C2_RIE_MASK|UART_C2_TCIE_MASK|         \
                                  UART_C2_TIE_MASK));
    if(tmp & UART_S1_RDRF_MASK)
      pCallbackUART0_UART1 (UART1_CALLBACK, UART_RX_CALLBACK, tmp);

    if(tmp & (UART_S1_TC_MASK|UART_S1_TDRE_MASK))
      pCallbackUART0_UART1 (UART1_CALLBACK, UART_TX_CALLBACK, tmp);

    tmp = UART1_S1 & (UART1_C3 & (UART_C3_PEIE_MASK|UART_C3_FEIE_MASK|        \
                                  UART_C3_NEIE_MASK|UART_C3_ORIE_MASK));
    if(tmp != 0)
      pCallbackUART0_UART1 (UART1_CALLBACK, UART_ER_CALLBACK, tmp);
  }
}

#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
weak void uart23_isr (void)
{
  register int32 tmp;

  /* process UART2 interrupts                                                 */
  if (SIM_SCGC4 & SIM_SCGC4_UART2_MASK)
  {
    tmp = UART2_S2 & (UART2_BDH & UART_BDH_RXEDGIE_MASK);
    if(tmp != 0)
    {
      UART2_S2 = UART2_S2;  /* clear RXEDGIF interrupt flag                   */
      pCallbackUART2_UART3 (UART2_CALLBACK, UART_EDG_CALLBACK, tmp);
    }

    tmp = UART2_S1 & (UART2_C2 & (UART_C2_RIE_MASK|UART_C2_TCIE_MASK|         \
                                  UART_C2_TIE_MASK));
    if(tmp & UART_S1_RDRF_MASK)
      pCallbackUART2_UART3 (UART2_CALLBACK, UART_RX_CALLBACK, tmp);

    if(tmp & (UART_S1_TC_MASK|UART_S1_TDRE_MASK))
      pCallbackUART2_UART3 (UART2_CALLBACK, UART_TX_CALLBACK, tmp);

    tmp = UART2_S1 & (UART2_C3 & (UART_C3_PEIE_MASK|UART_C3_FEIE_MASK|        \
                                  UART_C3_NEIE_MASK|UART_C3_ORIE_MASK));
    if(tmp != 0)
      pCallbackUART2_UART3 (UART2_CALLBACK, UART_ER_CALLBACK, tmp);
  }

  /* process UART3 interrupts                                                 */
  if (SIM_SCGC4 & SIM_SCGC4_UART3_MASK)
  {
    tmp = UART3_S2 & (UART3_BDH & UART_BDH_RXEDGIE_MASK);
    if(tmp != 0)
    {
      UART3_S2 = UART3_S2;  /* clear RXEDGIF interrupt flag                   */
      pCallbackUART2_UART3 (UART3_CALLBACK, UART_EDG_CALLBACK, tmp);
    }

    tmp = UART3_S1 & (UART3_C2 & (UART_C2_RIE_MASK|UART_C2_TCIE_MASK|         \
                                  UART_C2_TIE_MASK));
    if(tmp & UART_S1_RDRF_MASK)
      pCallbackUART2_UART3 (UART3_CALLBACK, UART_RX_CALLBACK, tmp);

    if(tmp & (UART_S1_TC_MASK|UART_S1_TDRE_MASK))
      pCallbackUART2_UART3 (UART3_CALLBACK ,UART_TX_CALLBACK, tmp);

    tmp = UART3_S1 & (UART3_C3 & (UART_C3_PEIE_MASK|UART_C3_FEIE_MASK|        \
                                  UART_C3_NEIE_MASK|UART_C3_ORIE_MASK));
    if(tmp != 0)
      pCallbackUART2_UART3 (UART3_CALLBACK, UART_ER_CALLBACK, tmp);
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/