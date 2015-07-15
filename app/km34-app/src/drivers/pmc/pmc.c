/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pmc.c
 * @version   1.0.3.0
 * @date      May-4-2012
 * @brief     Power Management Controller (PMC) driver source code.
 ******************************************************************************/
#include "common.h"
#include "pmc.h"

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static PMC_CALLBACK pCallbackPMC;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void PMC_Init (tLVD lvd, tREG reg, uint8 ip, PMC_CALLBACK pCallback)
{
  if (pCallback) { pCallbackPMC = pCallback; NVIC_SetIsr(INT_PMC,ip); }
  PMC_LVDSC1 = lvd.LVDSC1;
  PMC_LVDSC2 = lvd.LVDSC2;
  PMC_REGSC  = reg.REGSC;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void pmc_isr (void)
{
  if ((PMC_LVDSC1 & PMC_LVDSC1_LVDF_MASK) && (PMC_LVDSC1 & PMC_LVDSC1_LVDIE_MASK))
  {
    iosetb (PMC_LVDSC1,PMC_LVDSC1_LVDACK_MASK);   /* clear interrupt flag     */
    pCallbackPMC (LVD_CALLBACK);
  }
  if ((PMC_LVDSC2 & PMC_LVDSC2_LVWF_MASK) && (PMC_LVDSC2 & PMC_LVDSC2_LVWIE_MASK))
  {
    iosetb (PMC_LVDSC2,PMC_LVDSC2_LVWACK_MASK);   /* clear interrupt flag     */
    pCallbackPMC (LVW_CALLBACK);
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
