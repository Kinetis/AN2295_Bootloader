/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      start.c
 * @version   1.0.5.0
 * @date      Dec-01-2014
 * @brief     startup function (high level part).
 ******************************************************************************/
#include "start.h"
#include "drivers.h"

#define WDOG_DISABLE()                                                        \
{                                                                             \
  /* Write 0xC520 to the unlock register                          */          \
  WDOG_UNLOCK = 0xC520;                                                       \
                                                                              \
  /* Followed by 0xD928 to complete the unlock                    */          \
  WDOG_UNLOCK = 0xD928;                                                       \
                                                                              \
  /* Clear the WDOGEN bit to disable the watchdog timer           */          \
  ioclrh(WDOG_STCTRLH,WDOG_STCTRLH_WDOGEN_MASK);                              \
}

/******************************************************************************
 * Startup function definition - function calls all of the needed startup     *
 * routines and then branches to the main process.                            *
 ******************************************************************************/
void start(void)
{
  #if defined(BOOT_HWVLPR_MODE)
    /* Hardware forced VLPR boot mode. The device will boot in VLPR mode      */
    /* after next POR provided VBAT is powered.                               */
    IRTC_BootVLPR   ();
  #else
    /* Activate VLPR mode by software if BOOT_EXE_MODE constant has been      */
    /* defined in the appconfig.h header file.                                */
    if (NV_FOPT & NV_FOPT_EXE_MODE_MASK)
    {
      SMC_Init (SMC_MODULE_VLPS_ON_VLLS_ON_CONFIG); /* enable all modes       */
      SMC_SetMode (VLPR);                           /* enter VLPR mode        */
    }
  #endif

  WDOG_DISABLE(); /* Disable watchdog timer                                   */
  startup     (); /* Copy any vector or data sections that need to be in RAM  */
  (void)main  (); /* Jump to main process                                     */
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/

