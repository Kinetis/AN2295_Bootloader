/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      dma.c
 * @version   1.0.3.0
 * @date      Apr-21-2015
 * @brief     Direct Memory Access (DMA) driver source code.
 ******************************************************************************/
#include "common.h"
#include "dma.h"

#if !defined(MCU_MKM34ZA5)
  #error "The dma.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static DMA_CH_CALLBACK pCallbackDMA0;
static DMA_CH_CALLBACK pCallbackDMA1;
static DMA_CH_CALLBACK pCallbackDMA2;
static DMA_CH_CALLBACK pCallbackDMA3;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void DMA_InstallCallbackDMA0 (uint8 ip, DMA_CH_CALLBACK pCallback)
{
  if (pCallback) { pCallbackDMA0 = pCallback; NVIC_SetIsr(INT_DMA0,ip); }
}

void DMA_InstallCallbackDMA1 (uint8 ip, DMA_CH_CALLBACK pCallback)
{
  if (pCallback) { pCallbackDMA1 = pCallback; NVIC_SetIsr(INT_DMA1,ip); }
}

void DMA_InstallCallbackDMA2 (uint8 ip, DMA_CH_CALLBACK pCallback)
{
  if (pCallback) { pCallbackDMA2 = pCallback; NVIC_SetIsr(INT_DMA2,ip); }
}

void DMA_InstallCallbackDMA3 (uint8 ip, DMA_CH_CALLBACK pCallback)
{
  if (pCallback) { pCallbackDMA3 = pCallback; NVIC_SetIsr(INT_DMA3,ip); }
}

void DMA0_Init(tDMA_CH dma)
{
  if (pCallbackDMA0)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR0     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX0_CHCFG = 0x00;             }
  DMA_SAR0      = dma.SAR;
  DMA_DAR0      = dma.DAR;
  DMA_DSR_BCR0  = dma.DSR;
  DMA_DCR0      = dma.DCR;
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX0_CHCFG = (uint8)dma.CHCFG; }
}

void DMA1_Init(tDMA_CH dma)
{
  if (pCallbackDMA1)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR1 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR1     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX1_CHCFG = 0x00;             }
  DMA_SAR1      = dma.SAR;
  DMA_DAR1      = dma.DAR;
  DMA_DSR_BCR1  = dma.DSR;
  DMA_DCR1      = dma.DCR;
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX1_CHCFG = (uint8)dma.CHCFG; }
}

void DMA2_Init(tDMA_CH dma)
{
  if (pCallbackDMA2)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR2 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR2     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX2_CHCFG = 0x00;             }
  DMA_SAR2      = dma.SAR;
  DMA_DAR2      = dma.DAR;
  DMA_DSR_BCR2  = dma.DSR;
  DMA_DCR2      = dma.DCR;
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX2_CHCFG = (uint8)dma.CHCFG; }
}

void DMA3_Init(tDMA_CH dma)
{
  if (pCallbackDMA3)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR3 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR3     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX3_CHCFG = 0x00;             }
  DMA_SAR3      = dma.SAR;
  DMA_DAR3      = dma.DAR;
  DMA_DSR_BCR3  = dma.DSR;
  DMA_DCR3      = dma.DCR;
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX3_CHCFG = (uint8)dma.CHCFG; }
}

void DMA0_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm)
{
  if (pCallbackDMA0)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR0     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX0_CHCFG = 0x00;             }
  DMA_SAR0      = dma.SAR;
  DMA_DAR0      = dma.DAR;
  DMA_DSR_BCR0  = dma.DSR;
  DMA_DCR0 = dma.DCR|(chacr<<DMA_DCR_CHACR_SHIFT)|(umnsm<<DMA_DCR_UMNSM_SHIFT);
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX0_CHCFG = (uint8)dma.CHCFG; }
}

void DMA1_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm)
{
  if (pCallbackDMA1)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR1 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR1     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX1_CHCFG = 0x00;             }
  DMA_SAR1      = dma.SAR;
  DMA_DAR1      = dma.DAR;
  DMA_DSR_BCR1  = dma.DSR;
  DMA_DCR1 = dma.DCR|(chacr<<DMA_DCR_CHACR_SHIFT)|(umnsm<<DMA_DCR_UMNSM_SHIFT);
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX1_CHCFG = (uint8)dma.CHCFG; }
}

void DMA2_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm)
{
  if (pCallbackDMA2)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR2 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR2     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX2_CHCFG = 0x00;             }
  DMA_SAR2      = dma.SAR;
  DMA_DAR2      = dma.DAR;
  DMA_DSR_BCR2  = dma.DSR;
  DMA_DCR2 = dma.DCR|(chacr<<DMA_DCR_CHACR_SHIFT)|(umnsm<<DMA_DCR_UMNSM_SHIFT);
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX2_CHCFG = (uint8)dma.CHCFG; }
}

void DMA3_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm)
{
  if (pCallbackDMA3)              { dma.DCR |= DMA_DCR_EINT_MASK;     }
  DMA_DSR_BCR3 |= DMA_DSR_BCR_DONE_MASK;  /* abort DMA channel operation      */
  DMA_DCR3     &= ~DMA_DCR_ERQ_MASK;      /* peripheral request is ignored    */
  /* disable DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX3_CHCFG = 0x00;             }
  DMA_SAR3      = dma.SAR;
  DMA_DAR3      = dma.DAR;
  DMA_DSR_BCR3  = dma.DSR;
  DMA_DCR3 = dma.DCR|(chacr<<DMA_DCR_CHACR_SHIFT)|(umnsm<<DMA_DCR_UMNSM_SHIFT);
  /* program DMA mux if DMA tranfer will be initiated by peripheral request   */
  if (dma.DCR & DMA_DCR_ERQ_MASK) { DMAMUX3_CHCFG = (uint8)dma.CHCFG; }
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void dma0_isr (void)
{
  register uint32 tmp = DMA_DSR_BCR0;

  DMA_Ack(DMA0);  /* acknowledge DMA transfer and/or clear error condition    */

  if (tmp &   DMA_DSR_BCR_CE_MASK) { pCallbackDMA0(  CE_CALLBACK); }
  if (tmp & DMA_DSR_BCR_DONE_MASK) { pCallbackDMA0(DONE_CALLBACK); }
}

weak void dma1_isr (void)
{
  register uint32 tmp = DMA_DSR_BCR1;

  DMA_Ack(DMA1);  /* acknowledge DMA transfer and/or clear error condition    */

  if (tmp &   DMA_DSR_BCR_CE_MASK) { pCallbackDMA1(  CE_CALLBACK); }
  if (tmp & DMA_DSR_BCR_DONE_MASK) { pCallbackDMA1(DONE_CALLBACK); }
}

weak void dma2_isr (void)
{
  register uint32 tmp = DMA_DSR_BCR2;

  DMA_Ack(DMA2);  /* acknowledge DMA transfer and/or clear error condition    */

  if (tmp &   DMA_DSR_BCR_CE_MASK) { pCallbackDMA2(  CE_CALLBACK); }
  if (tmp & DMA_DSR_BCR_DONE_MASK) { pCallbackDMA2(DONE_CALLBACK); }
}

weak void dma3_isr (void)
{
  register uint32 tmp = DMA_DSR_BCR3;

  DMA_Ack(DMA3);  /* acknowledge DMA transfer and/or clear error condition    */

  if (tmp &   DMA_DSR_BCR_CE_MASK) { pCallbackDMA3(  CE_CALLBACK); }
  if (tmp & DMA_DSR_BCR_DONE_MASK) { pCallbackDMA3(DONE_CALLBACK); }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/