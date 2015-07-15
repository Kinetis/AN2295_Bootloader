/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      wdog.c
 * @version   1.0.3.0
 * @date      Apr-20-2015
 * @brief     Watchdog Timer (WDOG) driver source code.
 ******************************************************************************/
#include "common.h"
#include "wdog.h"

#if !defined(MCU_MKM34ZA5)
  #error "The wdog.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void wdog_isr (void) { for (;;) {} }         /* overriden in swisr.c     */
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/