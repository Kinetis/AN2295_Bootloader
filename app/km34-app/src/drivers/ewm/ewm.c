/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      ewm.c
 * @version   1.0.0.0
 * @date      Apr-20-2015
 * @brief     External Watchdog Monitor (EWM) driver source code.
 ******************************************************************************/
#include "common.h"
#include "ewm.h"

#if !defined(MCU_MKM34ZA5)
  #error "The ewm.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static EWM_CALLBACK pCallbackEWM;

/******************************************************************************
 * Public functions definitions                                               *
 ******************************************************************************/
void EWM_Init (tEWM cfg, uint8 ip, EWM_CALLBACK pCallback)
{
  register uint8 tmp = 0;

  if (pCallback)
  {
    pCallbackEWM = pCallback;
    NVIC_SetIsr(INT_EWM,ip);
    tmp = EWM_CTRL_INTEN_MASK;
  }

  EWM_CMPL = cfg.CMPL;
  EWM_CMPH = cfg.CMPH;
  EWM_CTRL = cfg.CTRL|tmp;
}

/******************************************************************************
 * interrupt functions definitions                                            *
 ******************************************************************************/
weak void ewm_isr (void)                        /* overriden in swisr.c     */
{
  ioclrb (EWM_CTRL,EWM_CTRL_INTEN_MASK);
  pCallbackEWM();
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/