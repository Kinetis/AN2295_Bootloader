/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      syst.c
 * @version   1.0.1.0
 * @date      May-14-2012
 * @brief     System Timer (SYST) driver source code.
 ******************************************************************************/
#include "common.h"
#include "syst.h"

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static SYST_CALLBACK pCallbackSYST;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void SYST_Init (tSYST syst, uint8 ip, SYST_CALLBACK pCallback)
{
  if (pCallback)
  {
    syst.CSR |= SysTick_CSR_TICKINT_MASK; /* enables system Timer exception   */
    pCallbackSYST = pCallback;
    FAULT_SetIsr (INT_SysTick,ip);
  }
  SYST_RVR = syst.RVR;
  SYST_CVR = 0l;
  SYST_CSR = syst.CSR;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void syst_isr (void) { pCallbackSYST (); }
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
