/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pll.c
 * @version   1.0.2.0
 * @date      May-14-2012
 * @brief     Phase-Locked Loop (PLL) driver source code.
 ******************************************************************************/
#include "common.h"
#include "pll.h"

/******************************************************************************
 * macro definitions                                                          *
 ******************************************************************************/
#define WAIT_FOR_FLAG(reg,name1,name2)                                        \
{                                                                             \
  while (((MCG_S&MCG_S_##name2##_MASK)>>MCG_S_##name2##_SHIFT)!=              \
    ((reg&reg##_##name1##_MASK)>>reg##_##name1##_SHIFT));                     \
}

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
void PLL_Init (tPLL pll)
{
  MCG_SC = pll.SC;  /* Setup FCRDIV and trimming                              */
  MCG_C8 = pll.C8;
  MCG_C7 = pll.C7;  /* Select MCG PLL and FLL Reference Clocks                */
  MCG_C2 = pll.C2;  /* Low Power and clock select                             */
  /* Wait for oscillator initialization if External Reference Clock Selected  */
  if (MCG_C2 & MCG_C2_EREFS0_MASK) { WAIT_FOR_FLAG (MCG_C2, EREFS0, OSCINIT0); }
  /* Setup C1 register keeping MCGOUTCLK clocked in either PBI or PBE mode    */
  if ((pll.C7 & MCG_C7_PLL32KREFSEL_MASK) == MCG_C7_PLL32KREFSEL(1))
    MCG_C1 = (pll.C1 & ~MCG_C1_CLKS_MASK) | MCG_C1_CLKS(1);     /* PBI mode   */
  else
    MCG_C1 = (pll.C1 & ~MCG_C1_CLKS_MASK) | MCG_C1_CLKS(2);     /* PBE mode   */
  MCG_C5 = pll.C5;  /* Powers PLL and enables PLL in normal stop mode         */
  /* Wait until PLL locks                                                     */
  if (MCG_C5 & MCG_C5_PLLCLKEN0_MASK) { WAIT_FOR_FLAG (MCG_C5, PLLCLKEN0, LOCK0); }
  MCG_C6 = pll.C6;  /* Choose PLL as MCG source                               */
  MCG_C1 = pll.C1;  /* Switch MCGOUTCLK clock source                          */
  /* if PLL is selected CLKST=3'b11 but CLKS=0'b00 and PLLS=1                 */
  if (!(MCG_C1 & MCG_C1_CLKS_MASK) && (MCG_C6 & MCG_C6_PLLS_MASK))
    while (((MCG_S&MCG_S_CLKST_MASK)>>MCG_S_CLKST_SHIFT)!= 0x03);
  else
    WAIT_FOR_FLAG (MCG_C1, CLKS, CLKST);
  if (MCG_C1 & MCG_C1_IRCLKEN_MASK) { WAIT_FOR_FLAG (MCG_C2, IRCS, IRCST); }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/