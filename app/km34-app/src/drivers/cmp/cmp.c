/******************************************************************************
 * (c) Copyright 2010-2013, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      cmp.c
 * @version   1.0.4.0
 * @date      Feb-13-2013
 * @brief     Analog comparator (CMP) driver source code.
 ******************************************************************************/
#include "common.h"
#include "cmp.h"

#if !defined(MCU_MKM34ZA5)
  #error "The cmp.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static CMP_CALLBACK pCallbackCMPx;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void CMP_InstallCallback (uint8 ip, CMP_CALLBACK pCallback)
{
  if (pCallback) { pCallbackCMPx = pCallback; NVIC_SetIsr(INT_CMP0_CMP1,ip); }
}

void CMP0_Init (tCMP cmp, uint8 psel, uint8 msel)
{
  CMP0_CR0   = cmp.CR0;
  CMP0_FPR   = cmp.FPR;
  CMP0_SCR   = cmp.SCR;
  CMP0_DACCR = cmp.DACCR;
  CMP0_MUXCR = (uint8)((psel<<3)|msel);
  CMP0_CR1   = cmp.CR1;
}

void CMP1_Init (tCMP cmp, uint8 psel, uint8 msel)
{
  CMP1_CR0   = cmp.CR0;
  CMP1_FPR   = cmp.FPR;
  CMP1_SCR   = cmp.SCR;
  CMP1_DACCR = cmp.DACCR;
  CMP1_MUXCR = (uint8)((psel<<3)|msel);
  CMP1_CR1   = cmp.CR1;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void cmpx_isr (void)
{
  /* process CMP0 module callbacks                                            */
  if (SIM_SCGC4 & SIM_SCGC4_CMP0_MASK)
  {
    /* negedge callback                                                       */
    if ((CMP0_SCR & CMP_SCR_IEF_MASK) && (CMP0_SCR & CMP_SCR_CFF_MASK))
    {
      ioclrb(CMP0_SCR,CMP_SCR_CFR_MASK);        /* clear CFF but not CFR flag */
      pCallbackCMPx (CMP0_CALLBACK, CMP_NEGEDGE_CALLBACK);
    }
    /* process posedge callback                                               */
    if ((CMP0_SCR & CMP_SCR_IER_MASK) && (CMP0_SCR & CMP_SCR_CFR_MASK))
    {
      ioclrb(CMP0_SCR,CMP_SCR_CFF_MASK);        /* clear CFR but not CFF flag */
      pCallbackCMPx (CMP0_CALLBACK, CMP_POSEDGE_CALLBACK);
    }
  }

  /* process CMP1 module callbacks                                            */
  if (SIM_SCGC4 & SIM_SCGC4_CMP1_MASK)
  {
    /* negedge callback                                                       */
    if ((CMP1_SCR & CMP_SCR_IEF_MASK) && (CMP1_SCR & CMP_SCR_CFF_MASK))
    {
      ioclrb(CMP1_SCR,CMP_SCR_CFR_MASK);        /* clear CFF but not CFR flag */
      pCallbackCMPx (CMP1_CALLBACK, CMP_NEGEDGE_CALLBACK);
    }
    /* posedge callback                                                       */
    if ((CMP1_SCR & CMP_SCR_IER_MASK) && (CMP1_SCR & CMP_SCR_CFR_MASK))
    {
      ioclrb(CMP1_SCR,CMP_SCR_CFF_MASK);        /* clear CFR but not CFF flag */
      pCallbackCMPx (CMP1_CALLBACK, CMP_POSEDGE_CALLBACK);
    }
  }

}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/

