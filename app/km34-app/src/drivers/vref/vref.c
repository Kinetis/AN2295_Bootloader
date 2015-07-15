/******************************************************************************
 * (c) Copyright 2010-2013, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      vref.c
 * @version   1.0.2.0
 * @date      May-8-2011
 * @brief     Voltage Reference (VREF) driver source code.
 ******************************************************************************/
#include "common.h"
#include "vref.h"

#if !defined(MCU_MKM34ZA5)
  #error "The vref.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void VREF_Init (tVREF vref, tVREF_S vref_s)
{
  register uint8  tmp;
  register uint32 tmpl;

  VREF_VREFH_SC = VREF_VREFH_SC_VREFEN_MASK; /* enable module and keep mode 0 */
  /* check and wait until reference is stable                                 */
  if (vref.VREFH_SC & VREF_VREFH_SC_VREFEN_MASK)
    while (!(VREF_VREFH_SC & VREF_VREFH_SC_VREFST_MASK));

  /* Load VREFH_TRM without change trim value                                 */
  tmp            = (VREF_VREFH_TRM & VREF_VREFH_TRM_TRIM_MASK);
  VREF_VREFH_TRM = (vref.VREFH_TRM | tmp);    /* Set actual selection         */
  /* Load control register                                                    */
  VREF_VREFH_SC  = vref.VREFH_SC;             /* write control register       */
  /* Load VREFL_TRM without change trim value                                 */
  tmp            = (VREF_VREFL_TRM & VREF_VREFL_TRM_VREFL_TRIM_MASK);
  VREF_VREFL_TRM = (vref.VREFL_TRM | vref_s.VREFL_TRM_S | tmp);
  /* Load SIM_MISC_CTL without change other flags                             */
  tmpl           = (SIM_MISC_CTL & (                                           \
                                      SIM_MISC_CTL_RTCCLKSEL_MASK|             \
                                      SIM_MISC_CTL_TMR3PCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR2PCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR1PCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR0PCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR3SCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR2SCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR1SCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR0SCSSEL_MASK|            \
                                      SIM_MISC_CTL_TMR0PLLCLKSEL_MASK|         \
                                      SIM_MISC_CTL_EWMINSEL_MASK|              \
                                      SIM_MISC_CTL_XBARPITOUTSEL_MASK|         \
                                      SIM_MISC_CTL_UART3IRSEL_MASK|            \
                                      SIM_MISC_CTL_UART2IRSEL_MASK|            \
                                      SIM_MISC_CTL_UART1IRSEL_MASK|            \
                                      SIM_MISC_CTL_UART0IRSEL_MASK|            \
                                      SIM_MISC_CTL_UARTMODTYPE_MASK|           \
                                      SIM_MISC_CTL_AFECLKPADDIR_MASK|          \
                                      SIM_MISC_CTL_AFECLKSEL_MASK|             \
                                      SIM_MISC_CTL_DMADONESEL_MASK|            \
                                      SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK       \
                                   )                                           \
                   );
  SIM_MISC_CTL   = (vref_s.SIM_MISC_CTL_S | tmpl);
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/