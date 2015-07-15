/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      fll.c
 * @version   1.0.2.0
 * @date      May-14-2012
 * @brief     Frequency-Locked Loop (FLL) driver source code.
 ******************************************************************************/
#include "common.h"
#include "fll.h"

/******************************************************************************
 * macro definitions                                                          *
 ******************************************************************************/
#define WAIT_FOR_FLAG(reg,name1,name2)                                        \
{                                                                             \
  while (((MCG_S&MCG_S_##name2##_MASK)>>MCG_S_##name2##_SHIFT)!=              \
        ((reg&reg##_##name1##_MASK)>>reg##_##name1##_SHIFT));                 \
}

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
void FLL_Init (tFLL fll)
{
  MCG_SC = fll.SC;  /* Setup FCRDIV and trimming                              */
  MCG_C8 = fll.C8;
  MCG_C7 = fll.C7;  /* Select MCG FLL external reference clock                */
  MCG_C2 = fll.C2;  /* Low Power and clock select                             */
  /* Wait for oscillator initialization if External Reference Clock Selected  */
  if (MCG_C2 & MCG_C2_EREFS0_MASK) { WAIT_FOR_FLAG (MCG_C2, EREFS0, OSCINIT0); }
  /* Setup C1 register keeping MCGOUTCLK clocked in either FBI or FBE mode    */
  if ((fll.C1 & MCG_C1_IREFS_MASK))
    MCG_C1 = (fll.C1 & ~MCG_C1_CLKS_MASK) | MCG_C1_CLKS(1);     /* FBI mode   */
  else
    MCG_C1 = (fll.C1 & ~MCG_C1_CLKS_MASK) | MCG_C1_CLKS(2);     /* FBE mode   */
  WAIT_FOR_FLAG (MCG_C1, CLKS, CLKST);
  /* Setup FLL frequency                                                      */
  MCG_C4 = (MCG_C4 & (MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK)) | fll.C4;
  /* Wait until FLL frequency settles                                         */
  while ((MCG_C4 & MCG_C4_DRST_DRS_MASK) != (fll.C4 & MCG_C4_DRST_DRS_MASK));
  MCG_C6 = fll.C6;  /* Choose FLL as MCG source                               */
  MCG_C1 = fll.C1;  /* Switch MCGOUTCLK clock source                          */
  WAIT_FOR_FLAG (MCG_C1, CLKS, CLKST);
  if (MCG_C1 & MCG_C1_IRCLKEN_MASK) { WAIT_FOR_FLAG (MCG_C2, IRCS, IRCST); }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/