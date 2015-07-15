/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      xbar.c
 * @version   1.0.3.0
 * @date      Apr-20-2015
 * @brief     Inter-Peripheral Crossbar Switch (XBAR) driver source code.
 ******************************************************************************/
#include "common.h"
#include "xbar.h"

#if !defined(MCU_MKM34ZA5)
  #error "The xbar.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static XBAR_CALLBACK pCallbackXBAR;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void XBAR_Init (tXBAR xbar, uint16 ip, XBAR_CALLBACK pCallback)
{
  if (pCallback) { pCallbackXBAR = pCallback; NVIC_SetIsr(INT_PXBAR,ip); }
  XBAR_CTRL0 = xbar.CTRL0;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void xbar_isr (void)
{
  ioseth (XBAR_CTRL0,XBAR_CTRL0_STS0_MASK); /* clear interrupt flag           */
  pCallbackXBAR ();
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/