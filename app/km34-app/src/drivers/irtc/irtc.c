/******************************************************************************
 * (c) Copyright 2010-2014, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      irtc.c
 * @version   1.0.7.0
 * @date      Apr-20-2014
 * @brief     IRTC Real Time Clock (IRTC) driver source code.
 ******************************************************************************/
#include "common.h"
#include "irtc.h"

#if !defined(MCU_MKM34ZA5)
  #error "The irtc.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
#if defined(__ICCARM__)
  volatile uint8_t IRTC_Ram[32] @0x40051000u;
#elif defined(__GNUC__)
  volatile uint8_t IRTC_Ram[32] __attribute__((section(".RtcRamSection")));
#elif defined(__CC_ARM)
  volatile uint8_t IRTC_Ram[32] __attribute__((section(".RtcRamSection"),used,zero_init));
#endif

static IRTC_CALLBACK pCallbackIRTC;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void IRTC_InstallCallback (uint8 ip, IRTC_CALLBACK pCallback)
{
  if (pCallback) { pCallbackIRTC = pCallback; NVIC_SetIsr(INT_RTC,ip); }
}

void IRTC_Init (tIRTC irtc, tTAMPER t0, tTAMPER t1, tTAMPER t2, uint32 mask)
{
  register uint16 tmp;

  IRTC_LockUnlock();

  /* setting common registers                                                 */
  /* disable and don't support at all TAMPER3 (battery removal) interrupt     */
  RTC_TAMPER_SCR    &=~0x0008;
  RTC_TAMPER_SCR    |= 0x0f08;    /* clear all tamper pin flags               */
  RTC_ISR            = 0xffff;    /* clear all IRTC module interrupt flags    */
  IRTC_DisableIsr(IRTC_ALL_MASK); /* disable all supported interrupts         */
  IRTC_EnableIsr (mask);          /* enable only selected interrupts          */
  RTC_CTRL           =  irtc.CTRL;
  RTC_COMPEN         =  irtc.COMPEN;
  RTC_TAMPER_QSCR    =  irtc.QSCR;

  /* tamper 0 pin setting - used as the tamper pin                            */
  RTC_CTRL2 &= ~RTC_CTRL2_WAKEUP_MODE_MASK;
  tmp  = RTC_TAMPER_DIRECTION_A_P_TAMP(TAMPER0_PIN)|
         RTC_TAMPER_DIRECTION_I_O_TAMP(TAMPER0_PIN);
  RTC_TAMPER_DIRECTION  = (t0.DIRECTION & tmp);
  tmp  = RTC_FILTER01_CFG_POL0_MASK|RTC_FILTER01_CFG_CLK_SEL0_MASK|
         RTC_FILTER01_CFG_FIL_DUR0_MASK;
  RTC_FILTER01_CFG   = ((uint16)(t0.FILTER_CFG<<8) & tmp);

  /* tamper 1 pin setting                                                     */
  tmp  = RTC_TAMPER_DIRECTION_A_P_TAMP(TAMPER1_PIN)|
         RTC_TAMPER_DIRECTION_I_O_TAMP(TAMPER1_PIN);
  RTC_TAMPER_DIRECTION |= (t1.DIRECTION & tmp);
  tmp  = RTC_FILTER01_CFG_POL1_MASK|RTC_FILTER01_CFG_CLK_SEL1_MASK|
         RTC_FILTER01_CFG_FIL_DUR1_MASK;
  RTC_FILTER01_CFG  |= (t1.FILTER_CFG & tmp);

  /* tamper 2 pin setting                                                     */
  tmp  = RTC_TAMPER_DIRECTION_A_P_TAMP(TAMPER2_PIN)|
         RTC_TAMPER_DIRECTION_I_O_TAMP(TAMPER2_PIN);
  RTC_TAMPER_DIRECTION |= (t2.DIRECTION & tmp);
  tmp  = RTC_FILTER2_CFG_POL2_MASK|RTC_FILTER2_CFG_CLK_SEL2_MASK|
         RTC_FILTER2_CFG_FIL_DUR2_MASK;
  RTC_FILTER2_CFG    = ((uint16)(t2.FILTER_CFG<<8) & tmp);

  /* enable tamper filter processing                                          */
  RTC_CTRL2 |= RTC_CTRL2_TAMP_CFG_OVER_MASK;
}

void IRTC_WkupInit (tIRTC irtc, tTAMPER t1, tTAMPER t2, uint32 mask)
{
  register uint16 tmp;

  IRTC_LockUnlock();

  /* setting common registers                                                 */
  /* disable and don't support at all TAMPER3 (battery removal) interrupt     */
  RTC_TAMPER_SCR    &=~0x0008;
  RTC_TAMPER_SCR    |= 0x0f08;    /* clear all tamper pin flags               */
  RTC_ISR            = 0xffff;    /* clear all IRTC module interrupt flags    */
  IRTC_DisableIsr(IRTC_ALL_MASK); /* disable all supported interrupts         */
  IRTC_EnableIsr (mask);          /* enable only selected interrupts          */
  RTC_CTRL           =  irtc.CTRL;
  RTC_COMPEN         =  irtc.COMPEN;
  RTC_TAMPER_QSCR    =  irtc.QSCR;

  /* tamper 0 pin setting - used as the wakeup/hibernate pin                  */
  RTC_CTRL2 |= RTC_CTRL2_WAKEUP_MODE_MASK;

  /* tamper 1 pin setting                                                     */
  tmp  = RTC_TAMPER_DIRECTION_A_P_TAMP(TAMPER1_PIN)|
         RTC_TAMPER_DIRECTION_I_O_TAMP(TAMPER1_PIN);
  RTC_TAMPER_DIRECTION |= (t1.DIRECTION & tmp);
  tmp  = RTC_FILTER01_CFG_POL1_MASK|RTC_FILTER01_CFG_CLK_SEL1_MASK|
         RTC_FILTER01_CFG_FIL_DUR1_MASK;
  RTC_FILTER01_CFG  |= (t1.FILTER_CFG & tmp);

  /* tamper 2 pin setting                                                     */
  tmp  = RTC_TAMPER_DIRECTION_A_P_TAMP(TAMPER2_PIN)|
         RTC_TAMPER_DIRECTION_I_O_TAMP(TAMPER2_PIN);
  RTC_TAMPER_DIRECTION |= (t2.DIRECTION & tmp);
  tmp  = RTC_FILTER2_CFG_POL2_MASK|RTC_FILTER2_CFG_CLK_SEL2_MASK|
         RTC_FILTER2_CFG_FIL_DUR2_MASK;
  RTC_FILTER2_CFG    = ((uint16)(t2.FILTER_CFG<<8) & tmp);

  /* enable tamper filter processing                                          */
  RTC_CTRL2 |= RTC_CTRL2_TAMP_CFG_OVER_MASK;
}

void IRTC_GetClock (tTIME *ptr)
{
  register uint16 reg_yearmon, reg_days, reg_hourmin, reg_seconds;

  /* read RTC registers and store their values in variables - we're loading   */
  /* variables by content of registers to minimize number of read operations  */
  while (1)
  {
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    reg_yearmon = RTC_YEARMON;
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    reg_days    = RTC_DAYS;
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    reg_hourmin = RTC_HOURMIN;
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    reg_seconds = RTC_SECONDS;
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    break;
  }
  /* clock formating                                                          */
  ptr->year = (((int16)reg_yearmon>>RTC_YEARMON_YROFST_SHIFT) + BASE_YEAR);
  ptr->mon  = ((uint16)reg_yearmon>>RTC_YEARMON_MON_CNT_SHIFT)  & 0x0f;
  ptr->day  = ((uint16)reg_days   >>RTC_DAYS_DAY_CNT_SHIFT)     & 0x1f;
  ptr->wday = ((uint16)reg_days   >>RTC_DAYS_DOW_SHIFT)         & 0x07;
  ptr->hour = ((uint16)reg_hourmin>>RTC_HOURMIN_HOUR_CNT_SHIFT) & 0x1f;
  ptr->min  = ((uint16)reg_hourmin>>RTC_HOURMIN_MIN_CNT_SHIFT)  & 0x3f;
  ptr->sec  = ((uint16)reg_seconds>>RTC_SECONDS_SEC_CNT_SHIFT)  & 0x3f;
}

void IRTC_SetClock (tTIME *ptr)
{
  register int16 tmp = ptr->year - BASE_YEAR;

  IRTC_LockUnlock();
  while (1)
  {
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    RTC_YEARMON = RTC_YEARMON_YROFST(tmp)|RTC_YEARMON_MON_CNT(ptr->mon);
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    RTC_DAYS    = RTC_DAYS_DAY_CNT(ptr->day)|RTC_DAYS_DOW(ptr->wday);
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    RTC_HOURMIN = RTC_HOURMIN_HOUR_CNT(ptr->hour)|RTC_HOURMIN_MIN_CNT(ptr->min);
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    RTC_SECONDS = RTC_SECONDS_SEC_CNT(ptr->sec);
    if (RTC_STATUS & RTC_STATUS_INVAL_BIT_MASK) { continue; }
    break;
  }
}

void IRTC_WrRam (void *src, uint8 size)
{
  register uint8 *ps = src, *pd=(uint8*)IRTC_Ram;
  if (size > sizeof(IRTC_Ram)) size = sizeof(IRTC_Ram);
  IRTC_LockUnlock();
  while (size--) *pd++ = *ps++;
}

void IRTC_RdRam (void *dst, uint8 size)
{
  register uint8 *pd = dst, *ps=(uint8*)IRTC_Ram;
  if (size > sizeof(IRTC_Ram)) size = sizeof(IRTC_Ram);
  while (size--) *pd++ = *ps++;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void irtc_isr (void)
{
  static tTAMPER_LOG tmp;
  register uint16    reg_ier, reg_tamper_scr, reg_isr;

  /* read RTC registers and store their values in variables - we're loading   */
  /* variables by content of registers to minimize number of read operations  */
  reg_ier = RTC_IER; reg_tamper_scr = RTC_TAMPER_SCR; reg_isr = RTC_ISR;

  IRTC_LockUnlock();
  IRTC_GetClock  ((tTIME*)&tmp.time);
  /* TAMPER pin callback processing                                           */
  if(reg_ier & RTC_IER_TAMPER_IE_MASK)
  {
    /* TAMPER0 pin                                                            */
    if((reg_tamper_scr & RTC_TAMPER_SCR_TMPR_EN (TAMPER0_PIN)) &&
       (reg_tamper_scr & RTC_TAMPER_SCR_TMPR_STS(TAMPER0_PIN)))
    {
      tmp.source = TAMPER0_PIN;
      RTC_TAMPER_SCR = RTC_TAMPER_SCR_TMPR_STS(TAMPER0_PIN)|(reg_tamper_scr&0xf);
      pCallbackIRTC(IRTC_TAMPER0_CALLBACK, (tTAMPER_LOG*)&tmp);
    }
    /* TAMPER1 pin                                                            */
    if((reg_tamper_scr & RTC_TAMPER_SCR_TMPR_EN (TAMPER1_PIN)) &&
       (reg_tamper_scr & RTC_TAMPER_SCR_TMPR_STS(TAMPER1_PIN)))
    {
      tmp.source = TAMPER1_PIN;
      RTC_TAMPER_SCR = RTC_TAMPER_SCR_TMPR_STS(TAMPER1_PIN)|(reg_tamper_scr&0xf);
      pCallbackIRTC(IRTC_TAMPER1_CALLBACK, (tTAMPER_LOG*)&tmp);
    }
    /* TAMPER2 pin                                                            */
    if((reg_tamper_scr & RTC_TAMPER_SCR_TMPR_EN (TAMPER2_PIN)) &&
       (reg_tamper_scr & RTC_TAMPER_SCR_TMPR_STS(TAMPER2_PIN)))
    {
      tmp.source = TAMPER2_PIN;
      RTC_TAMPER_SCR = RTC_TAMPER_SCR_TMPR_STS(TAMPER2_PIN)|(reg_tamper_scr&0xf);
      pCallbackIRTC(IRTC_TAMPER2_CALLBACK, (tTAMPER_LOG*)&tmp);
    }
  }
  /* ALARM callback processing                                                */
  if((reg_ier & RTC_IER_ALM_IE_MASK) && (reg_isr & RTC_ISR_ALM_IS_MASK))
  {
    RTC_ISR = RTC_ISR_ALM_IS_MASK;
    pCallbackIRTC(IRTC_ALM_CALLBACK, (tTIME*)&tmp.time);
  }
  /* DAY callback processing                                                  */
  if((reg_ier & RTC_IER_DAY_IE_MASK) && (reg_isr & RTC_ISR_DAY_IS_MASK))
  {
    RTC_ISR = RTC_ISR_DAY_IS_MASK;
    pCallbackIRTC(IRTC_DAY_CALLBACK, (tTIME*)&tmp.time);
  }
  /* HOUR callback processing                                                 */
  if((reg_ier & RTC_IER_HOUR_IE_MASK) && (reg_isr & RTC_ISR_HOUR_IS_MASK))
  {
    RTC_ISR = RTC_ISR_HOUR_IS_MASK;
    pCallbackIRTC(IRTC_HOUR_CALLBACK, (tTIME*)&tmp.time);
  }
  /* MIN callback processing                                                  */
  if((reg_ier & RTC_IER_MIN_IE_MASK) && (reg_isr & RTC_ISR_MIN_IS_MASK))
  {
    RTC_ISR = RTC_ISR_MIN_IS_MASK;
    pCallbackIRTC(IRTC_MIN_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 1HZ callback processing                                                  */
  if((reg_ier & RTC_IER_IE_1HZ_MASK) && (reg_isr & RTC_ISR_IS_1HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_1HZ_MASK;
    pCallbackIRTC(IRTC_1HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 2HZ callback processing                                                  */
  if((reg_ier & RTC_IER_IE_2HZ_MASK) && (reg_isr & RTC_ISR_IS_2HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_2HZ_MASK;
    pCallbackIRTC(IRTC_2HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 4HZ callback processing                                                  */
  if((reg_ier & RTC_IER_IE_4HZ_MASK) && (reg_isr & RTC_ISR_IS_4HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_4HZ_MASK;
    pCallbackIRTC(IRTC_4HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 8HZ callback processing                                                  */
  if((reg_ier & RTC_IER_IE_8HZ_MASK) && (reg_isr & RTC_ISR_IS_8HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_8HZ_MASK;
    pCallbackIRTC(IRTC_8HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 16HZ callback processing                                                 */
  if((reg_ier & RTC_IER_IE_16HZ_MASK) && (reg_isr & RTC_ISR_IS_16HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_16HZ_MASK;
    pCallbackIRTC(IRTC_16HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 32HZ callback processing                                                 */
  if((reg_ier & RTC_IER_IE_32HZ_MASK) && (reg_isr & RTC_ISR_IS_32HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_32HZ_MASK;
    pCallbackIRTC(IRTC_32HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 64HZ callback processing                                                 */
  if((reg_ier & RTC_IER_IE_64HZ_MASK) && (reg_isr & RTC_ISR_IS_64HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_64HZ_MASK;
    pCallbackIRTC(IRTC_64HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 128HZ callback processing                                                */
  if((reg_ier & RTC_IER_IE_128HZ_MASK) && (reg_isr & RTC_ISR_IS_128HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_128HZ_MASK;
    pCallbackIRTC(IRTC_128HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 256HZ callback processing                                                */
  if((reg_ier & RTC_IER_IE_256HZ_MASK) && (reg_isr & RTC_ISR_IS_256HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_256HZ_MASK;
    pCallbackIRTC(IRTC_256HZ_CALLBACK, (tTIME*)&tmp.time);
  }
  /* 512HZ callback processing                                                */
  if((reg_ier & RTC_IER_IE_512HZ_MASK) && (reg_isr & RTC_ISR_IS_512HZ_MASK))
  {
    RTC_ISR = RTC_ISR_IS_512HZ_MASK;
    pCallbackIRTC(IRTC_512HZ_CALLBACK, (tTIME*)&tmp.time);
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/