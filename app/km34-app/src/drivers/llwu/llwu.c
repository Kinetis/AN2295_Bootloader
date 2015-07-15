/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      llwu.c
 * @version   1.0.5.0
 * @date      Jun-03-2015
 * @brief     Low-Leakage Wakeup Unit (LLWU) driver source code.
 ******************************************************************************/
#include "common.h"
#include "llwu.h"

#if !defined(MCU_MKM34ZA5)
  #error "The llwu.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif
/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static LLWU_CALLBACK pCallbackLLWU;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void LLWU_Init (tLLWU llwu, uint8 ip, LLWU_CALLBACK pCallback)
{
  if (pCallback) { pCallbackLLWU = pCallback; NVIC_SetIsr(INT_LLWU,ip); }
  LLWU_PE1    = llwu.PE1;
  LLWU_PE2    = llwu.PE2;
  LLWU_PE3    = llwu.PE3;
  LLWU_PE4    = llwu.PE4;
  LLWU_ME     = llwu.ME;
  LLWU_FILT1  = llwu.FILT1;
  LLWU_FILT2  = llwu.FILT2;

  /* clear flags                                                              */
  LLWU_ClrFlags(LLWU_ALL);
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
#if defined(__ICCARM__)
  #pragma diag_suppress=Pa082
#endif
weak void llwu_isr (void)
{
  register uint32 tmp = LLWU_GetFlags();

  /* clear flags                                                              */
  LLWU_ClrFlags (LLWU_ALL);

  /* call callback function                                                   */
  pCallbackLLWU (tmp);
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/