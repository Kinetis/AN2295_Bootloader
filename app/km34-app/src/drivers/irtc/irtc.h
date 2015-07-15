/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      irtc.h
 * @version   1.0.7.0
 * @date      Jun-11-2015
 * @brief     IRTC Real Time Clock (IRTC) driver header file.
 ******************************************************************************/
#ifndef __IRTC_H
#define __IRTC_H

#if !defined(MCU_MKM34ZA5)
  #error "The irtc.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint16 CTRL, COMPEN, QSCR;    } tIRTC;
typedef struct { uint16 DIRECTION, FILTER_CFG; } tTAMPER;

/******************************************************************************
 * module constant and macro definitions - not in documentation               *
 ******************************************************************************/
#define BASE_YEAR     2112              // Base year of the IRTC module

/******************************************************************************
* Tamper pins used by the @ref irtc_tamperlog. See also
* @ref IRTC_SetTamperPinActiveLow() and IRTC_SetTamperPinActiveHigh() macros.
*
*//*! @addtogroup irtc_tamper_pin
* @{
*******************************************************************************/
#define TAMPER0_PIN   (uint8)(1u << 0)  ///< Tamper pin 0
#define TAMPER1_PIN   (uint8)(1u << 1)  ///< Tamper pin 1
#define TAMPER2_PIN   (uint8)(1u << 2)  ///< Tamper pin 2
/*! @} End of irtc_tamper_pin                                                 */

/******************************************************************************
* Day of week used by the @ref irtc_time and IRTC_SetDST() function.
*
*//*! @addtogroup irtc_wday
* @{
*******************************************************************************/
#define SUNDAY      (uint8)0     ///< Sunday
#define MONDAY      (uint8)1     ///< Monday
#define TUESDAY     (uint8)2     ///< Tuesday
#define WEDNESDAY   (uint8)3     ///< Wednesday
#define THURSDAY    (uint8)4     ///< Thursday
#define FRIDAY      (uint8)5     ///< Friday
#define SATURDAY    (uint8)6     ///< Saturday
/*! @} End of irtc_wday                                                       */

/******************************************************************************
* Months used by the @ref irtc_time and IRTC_SetDST() function.
*
*//*! @addtogroup irtc_mon
* @{
*******************************************************************************/
#define JANUARY     (uint8)1      ///< January
#define FEBRUARY    (uint8)2      ///< February
#define MARCH       (uint8)3      ///< March
#define APRIL       (uint8)4      ///< April
#define MAY         (uint8)5      ///< May
#define JUNE        (uint8)6      ///< June
#define JULY        (uint8)7      ///< July
#define AUGUST      (uint8)8      ///< August
#define SEPTEMBER   (uint8)9      ///< September
#define OCTOBER     (uint8)10     ///< October
#define NOVEMBER    (uint8)11     ///< November
#define DECEMBER    (uint8)12     ///< December
/*! @} End of irtc_mon                                                        */

/******************************************************************************
* The WKUP/TAMPER0 pin states. See also @ref IRTC_Hibernate() macro.
*
*//*! @addtogroup irtc_wakeup_states
* @{
*******************************************************************************/
#define FORCE_PIN_LOG0 (uint16)1u ///< WKUP/TAMPER0 pin forced to logic 0.
#define FORCE_PIN_LOG1 (uint16)2u ///< WKUP/TAMPER0 pin forced to logic 1.
/*! @} End of irtc_wakeup_states                                              */

/******************************************************************************
* Data and time structure used by IRTC_SetClock() and IRTC_GetClock() functions.
*
*//*! @addtogroup irtc_time
* @{
*******************************************************************************/
/*! tTIME data structure definition                                           */
typedef struct
{
  uint8  sec;           ///< Second after the minute [0, 59]
  uint8  min;           ///< Minute after the hour [0, 59]
  uint8  hour;          ///< Hour since midnight [0, 23]
  uint8  day;           ///< Day of the month [1, 31]
  uint8  wday;          ///< @ref irtc_wday since Sunday [0, 6]
  uint8  mon;           ///< @ref irtc_mon since January [1, 12]
  uint16 year;          ///< Year [1984, 2239]
} tTIME;
/*! @} End of irtc_time                                                       */

/******************************************************************************
* Alarm structure used by IRTC_SetAlarm() macro.
*
*//*! @addtogroup irtc_alarm
* @{
*******************************************************************************/
/*! tALARM data structure definition                                          */
typedef struct
{
  uint8  sec;           ///< Second after the minute [0, 59]
  uint8  min;           ///< Minute after the hour [0, 59]
  uint8  hour;          ///< Hour since midnight [0, 23]
  uint8  day;           ///< Day of the month [1, 31]
  uint8  mon;           ///< @ref irtc_mon since January [1, 12]
  uint16 year;          ///< Year [1984, 2239]
} tALARM;
/*! @} End of irtc_alarm                                                      */

/******************************************************************************
* Tamper log structure used by IRTC_CALLBACK.
*
*//*! @addtogroup irtc_tamperlog
* @{
*******************************************************************************/
/*! tTAMPER_LOG data structure definition                                     */
typedef struct
{
  tTIME  time;        ///< Date and time of the active tamper event
  uint8  source;      ///< Mask of the active tamper event @ref irtc_tamper_pin
} tTAMPER_LOG;
/*! @} End of irtc_tamperlog                                                  */

/******************************************************************************
* IRTC interrupts supported by the IRTC block and used by IRTC_Init() function.
*
*//*! @addtogroup irtc_interrupt_mask
* @{
*******************************************************************************/
#define IRTC_TAMPER0_MASK (uint32)(1u <<  0)   ///< TAMPER0 interrupt
#define IRTC_TAMPER1_MASK (uint32)(1u <<  1)   ///< TAMPER1 interrupt
#define IRTC_TAMPER2_MASK (uint32)(1u <<  2)   ///< TAMPER2 interrupt
#define IRTC_CNTDN_MASK   (uint32)(1u <<  3)   ///< Not supported
#define IRTC_ALM_MASK     (uint32)(1u <<  4)   ///< Alarm interrupt
#define IRTC_DAY_MASK     (uint32)(1u <<  5)   ///< Day interrupt
#define IRTC_HOUR_MASK    (uint32)(1u <<  6)   ///< Hour interrupt
#define IRTC_MIN_MASK     (uint32)(1u <<  7)   ///< Minute interrupt
#define IRTC_1HZ_MASK     (uint32)(1u <<  8)   ///< 1Hz interrupt
#define IRTC_2HZ_MASK     (uint32)(1u <<  9)   ///< 2Hz interrupt
#define IRTC_4HZ_MASK     (uint32)(1u << 10)   ///< 4Hz interrupt
#define IRTC_8HZ_MASK     (uint32)(1u << 11)   ///< 8Hz interrupt
#define IRTC_16HZ_MASK    (uint32)(1u << 12)   ///< 16Hz interrupt
#define IRTC_32HZ_MASK    (uint32)(1u << 13)   ///< 32Hz interrupt
#define IRTC_64HZ_MASK    (uint32)(1u << 14)   ///< 64Hz interrupt
#define IRTC_128HZ_MASK   (uint32)(1u << 15)   ///< 128Hz interrupt
#define IRTC_256HZ_MASK   (uint32)(1u << 16)   ///< 256Hz interrupt
#define IRTC_512HZ_MASK   (uint32)(1u << 17)   ///< 512Hz interrupt
#define IRTC_ALL_MASK     (uint32)0x3ffff      ///< All interrupts
/*! @} End of irtc_interrupt_mask                                             */

/******************************************************************************
* IRTC alarm match definitions used by IRTC_Init() function
*
*//*! @addtogroup irtc_alarm_match
* @{
*******************************************************************************/
#define ALM_MATCH_SMH    0x00 ///< Match for Second Minute Hour (default)
#define ALM_MATCH_SMHD   0x01 ///< Match for Second Minute Hour Day
#define ALM_MATCH_SMHDM  0x02 ///< Match for Second Minute Hour Day Month
#define ALM_MATCH_SMHDMY 0x03 ///< Match for Second Minute Hour Day Month Year
/*! @} End of irtc_alarm_match                                                */

/******************************************************************************
* IRTC Line Following Shift Register clock definitions used by IRTC_Init()
* function.
*
*//*! @addtogroup irtc_lfsr_clk
* @{
*******************************************************************************/
#define LFSR_CLK_32KHZ    0   ///< Line Following Shift Register clock is 32KHz
                              ///  (default)
#define LFSR_CLK_512HZ    1   ///< Line Following Shift Register clock is 512Hz
#define LFSR_CLK_128HZ    2   ///< Line Following Shift Register clock is 128Hz
#define LFSR_CLK_64HZ     3   ///< Line Following Shift Register clock is 64Hz
#define LFSR_CLK_16HZ     4   ///< Line Following Shift Register clock is 16Hz
#define LFSR_CLK_8HZ      5   ///< Line Following Shift Register clock is 8Hz
#define LFSR_CLK_4HZ      6   ///< Line Following Shift Register clock is 4Hz
#define LFSR_CLK_2HZ      7   ///< Line Following Shift Register clock is 2Hz
/*! @} End of irtc_lfsr_clk                                                   */

/******************************************************************************
* IRTC Tamper filter clock definitions used by IRTC_Init() function
*
*//*! @addtogroup irtc_tamper_filt_clk
* @{
*******************************************************************************/
#define TAMPER_FILT_CLK_32KHZ   0   ///< Filter clock is 32KHz (default)
#define TAMPER_FILT_CLK_512HZ   1   ///< Filter clock is 512Hz
#define TAMPER_FILT_CLK_128HZ   2   ///< Filter clock is 128Hz
#define TAMPER_FILT_CLK_64HZ    3   ///< Filter clock is 64Hz
#define TAMPER_FILT_CLK_16HZ    4   ///< Filter clock is 16Hz
#define TAMPER_FILT_CLK_8HZ     5   ///< Filter clock is 8Hz
#define TAMPER_FILT_CLK_4HZ     6   ///< Filter clock is 4Hz
#define TAMPER_FILT_CLK_2HZ     7   ///< Filter clock is 2Hz
/*! @} End of irtc_tamper_filt_clk                                            */

/******************************************************************************
* IRTC clock output selection definitions used by IRTC_SelClkoutSrc() function
*
*//*! @addtogroup irtc_clkout_src
* @{
*******************************************************************************/
#define RTCCLKOUT_NONE        0x00  ///< No Output Clock
#define RTCCLKOUT_SRC1        0x01  ///< Fine 1 Hz Clock
#define RTCCLKOUT_SRC2        0x02  ///< 32.768 kHz Clock
#define RTCCLKOUT_SRC3        0x03  ///< Coarse 1 Hz Clock
/*! @} End of irtc_clkout_src                                                 */

/******************************************************************************
* IRTC default module configurations used by IRTC_init() function
*
*//*! @addtogroup irtc_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief IRTC basic operation with all enhanced functionality disabled.
 * @details Configuration options:
 * - Software Reset not performed
 * - Daylight Saving disabled (daylight saving registers preset by 0)
 * - Sampling clocks are not gated when in standby mode
 * - Only Seconds, Minutes, and Hours matched to generate an alarm
 * - Compensation disabled (coarse compensation type preselected)
 * - Queue full interrupt disabled
 * @param   lfsr_clk  Clock selection for LFSR module @ref irtc_lfsr_clk.
 * @param   lfsr_dur  LFSR Filter duration period from 0 to 15.
 * @showinitializer
 ******************************************************************************/
#define IRTC_MODULE_COMP_OFF_CONFIG(lfsr_clk,lfsr_dur)                        \
(tIRTC){                                                                      \
/* CTRL     */  CLR(RTC_CTRL_SWR_MASK)|CLR(RTC_CTRL_DST_EN_MASK)|             \
/* ....     */  CLR(RTC_CTRL_TIMER_STB_MASK_MASK)|                            \
/* ....     */  SET(RTC_CTRL_ALM_MATCH(0x00))|                                \
/* ....     */  CLR(RTC_CTRL_COMP_EN_MASK)|CLR(RTC_CTRL_FINEEN_MASK),         \
/* COMPEN   */  SET(RTC_COMPEN_COMPEN_VAL(0x0)),                              \
/* QSCR     */  SET(RTC_TAMPER_QSCR_LFSR_DURATION(lfsr_dur))|                 \
/* ....     */  SET(RTC_TAMPER_QSCR_LFSR_CLK_SEL(lfsr_clk))|                  \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_CLEAR_MASK)|                            \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK)                       \
}

/***************************************************************************//*!
 * @brief IRTC enhanced configuration with coarse crystal compensation enabled.
 * @details Configuration options:
 * - Software Reset not performed
 * - Daylight Saving disabled (daylight saving registers preset by 0)
 * - Sampling clocks are not gated when in standby mode
 * - Only Seconds, Minutes, and Hours matched to generate an alarm
 * - Coarse compensation enabled
 * - Queue full interrupt disabled
 * @param   lfsr_clk  Clock selection for LFSR module @ref irtc_lfsr_clk.
 * @param   lfsr_dur  LFSR Filter duration period from 0 to 15.
 * @param   interval  Compensation Interval is the duration in seconds over
 *                    which the correction is applied. This is the time in which
 *                    the addition or removal of 32.768 KHz clock cycles is done
 *                    thereby ensuring that the compensation interval is close
 *                    to the interval obtained with an ideal 1 Hz clock. Range
 *                    of Compensation Interval: 1 second to 255 seconds.
 * @param   value     Compensation/Correction Value is a 2's complement format
 *                    by which the 1 Hz Clock is modified by either adding or
 *                    removing RTC Oscillator clock cycles. Range of
 *                    Compensation: -128 to +127 (32.768 KHz clock cycles).
 * @showinitializer
 ******************************************************************************/
#define IRTC_MODULE_COMP_COARSE_CONFIG(lfsr_clk,lfsr_dur,interval,value)      \
(tIRTC){                                                                      \
/* CTRL     */  CLR(RTC_CTRL_SWR_MASK)|CLR(RTC_CTRL_DST_EN_MASK)|             \
/* ....     */  CLR(RTC_CTRL_TIMER_STB_MASK_MASK)|                            \
/* ....     */  SET(RTC_CTRL_ALM_MATCH(0x00))|                                \
/* ....     */  SET(RTC_CTRL_COMP_EN_MASK)|CLR(RTC_CTRL_FINEEN_MASK),         \
/* COMPEN   */  SET(RTC_COMPEN_COMPEN_VAL((interval<<8)|value)),              \
/* QSCR     */  SET(RTC_TAMPER_QSCR_LFSR_DURATION(lfsr_dur))|                 \
/* ....     */  SET(RTC_TAMPER_QSCR_LFSR_CLK_SEL(lfsr_clk))|                  \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_CLEAR_MASK)|                            \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK)                       \
}

/***************************************************************************//*!
 * @brief IRTC enhanced configuration with fine crystal compensation enabled.
 * @details Configuration options:
 * - Software Reset not performed
 * - Daylight Saving disabled (daylight saving registers preset by 0)
 * - Sampling clocks are not gated when in standby mode
 * - Only Seconds, Minutes, and Hours matched to generate an alarm
 * - Fine  compensation enabled
 * - Queue full interrupt disabled
 * @param   lfsr_clk  Clock selection for LFSR module @ref irtc_lfsr_clk.
 * @param   lfsr_dur  LFSR Filter duration period from 0 to 15.
 * @param   integer   Integral Compensation Value is a 2's complement value of
 *                    the integer part of correction that has to be adjusted
 *                    in every 1 second period. Range of Compensation:
 *                    from -8 to +7 (32.768 KHz clock cycles).
 * @param   fraction  Fraction Compensation Value is the fractional part of the
 *                    correction value that has to be adjusted. This value is
 *                    expressed as number of clock cycles of a fixed 4.194304 MHz
 *                    clock. Range of Compensation Interval: from 0 (0us delay)
 *                    to 127 (30.279us delay).
 * @warning The fine compensation requires MCGIRCLK to operate. You may enable
 *          this clock by calling @ref FLL_CtrlIRCLKEN(TRUE) macro. Since the
 *          IRC clock is generated on MCU, this clock will get disabled when MCU
 *          power is OFF or in certain low power modes. In this case, the coarse
 *          1 Hz clock is outputted from the MCU. The coarse 1 Hz clock is not a
 *          50% duty cycle clock. You can also change MCGIRCLK clock frequency
 *          from 2.097152 MHz (default frequency) to 4.194304 MHz by calling
 *          @ref FLL_SetFastClkDiv(FIRC_DIV1) macro.
 * @showinitializer
 ******************************************************************************/
#define IRTC_MODULE_COMP_FINE_CONFIG(lfsr_clk,lfsr_dur,integer,fraction)      \
(tIRTC){                                                                      \
/* CTRL     */  CLR(RTC_CTRL_SWR_MASK)|CLR(RTC_CTRL_DST_EN_MASK)|             \
/* ....     */  CLR(RTC_CTRL_TIMER_STB_MASK_MASK)|                            \
/* ....     */  SET(RTC_CTRL_ALM_MATCH(0x00))|                                \
/* ....     */  SET(RTC_CTRL_COMP_EN_MASK)|SET(RTC_CTRL_FINEEN_MASK),         \
/* COMPEN   */  SET(RTC_COMPEN_COMPEN_VAL((integer<<12)|fraction)),           \
/* QSCR     */  SET(RTC_TAMPER_QSCR_LFSR_DURATION(lfsr_dur))|                 \
/* ....     */  SET(RTC_TAMPER_QSCR_LFSR_CLK_SEL(lfsr_clk))|                  \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_CLEAR_MASK)|                            \
/* ....     */  CLR(RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK)                       \
}
/*! @} End of irtc_config                                                     */

/******************************************************************************
* IRTC default tamper pin configurations used by IRTC_init() function
*
*//*! @addtogroup irtc_tamper_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief IRTC tamper pin functionality disabled.
 * @details IRTC tamper pin functionality disabled.
 * @showinitializer
 ******************************************************************************/
#define IRTC_TAMPER_PIN_DI_CONFIG                                             \
(tTAMPER){                                                                    \
/*DIRECTION  */ CLR(RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)| /* use mask */       \
/*.........  */ CLR(RTC_TAMPER_DIRECTION_A_P_TAMP_MASK), /* use mask */       \
/*FILTER_CFG */ CLR(RTC_FILTER01_CFG_POL1_MASK)|                              \
/*.......... */ SET(RTC_FILTER01_CFG_CLK_SEL1(TAMPER_FILT_CLK_32KHZ))|        \
/*.......... */ SET(RTC_FILTER01_CFG_FIL_DUR1(0x00)),                         \
}

/***************************************************************************//*!
 * @brief IRTC passive tamper pin polarity high.
 * @details IRTC passive tamper pin polarity high. Configuration options:
 * - Tamper pin interrupt enabled
 * - Tamper pin preset to passive mode
 * - Tamper pin set to input mode
 * - Tamper detect input is active high
 * @param   clksrc  Filter clock source @ref irtc_tamper_filt_clk.
 * @param   period  Filter period from 0 to 15 (0 = filter disabled).
 * @showinitializer
 ******************************************************************************/
#define IRTC_TAMPER_PIN_PASSIVE_POL_HIGH_CONFIG(clksrc,period)                \
(tTAMPER){                                                                    \
/*DIRECTION  */ CLR(RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)|  /* use mask */      \
/*.........  */ CLR(RTC_TAMPER_DIRECTION_A_P_TAMP_MASK),  /* use mask */      \
/*FILTER_CFG */ CLR(RTC_FILTER01_CFG_POL1_MASK)|                              \
/*.......... */ SET(RTC_FILTER01_CFG_CLK_SEL1(clksrc))|                       \
/*.......... */ SET(RTC_FILTER01_CFG_FIL_DUR1(period)),                       \
}

/***************************************************************************//*!
 * @brief IRTC passive tamper pin polarity low.
 * @details IRTC passive tamper pin polarity low. Configuration options:
 * - Tamper pin interrupt enabled
 * - Tamper pin preset to passive mode
 * - Tamper pin set to input mode
 * - Tamper detect input is active low
 * @param   clksrc  Filter clock source @ref irtc_tamper_filt_clk.
 * @param   period  Filter period from 0 to 15 (0 = filter disabled).
 * @showinitializer
 ******************************************************************************/
#define IRTC_TAMPER_PIN_PASSIVE_POL_LOW_CONFIG(clksrc,period)                 \
(tTAMPER){                                                                    \
/*DIRECTION  */ CLR(RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)|  /* use mask */      \
/*.........  */ CLR(RTC_TAMPER_DIRECTION_A_P_TAMP_MASK),  /* use mask */      \
/*FILTER_CFG */ SET(RTC_FILTER01_CFG_POL1_MASK)|                              \
/*.......... */ SET(RTC_FILTER01_CFG_CLK_SEL1(clksrc))|                       \
/*.......... */ SET(RTC_FILTER01_CFG_FIL_DUR1(period)),                       \
}

/***************************************************************************//*!
 * @brief IRTC active tamper pin output mode.
 * @details IRTC active tamper pin output mode.
 * @showinitializer
 ******************************************************************************/
#define IRTC_TAMPER_PIN_ACTIVE_OUTMODE_CONFIG                                 \
(tTAMPER){                                                                    \
/*DIRECTION  */ SET(RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)|  /* use mask */      \
/*.........  */ SET(RTC_TAMPER_DIRECTION_A_P_TAMP_MASK),  /* use mask */      \
/*FILTER_CFG */ /* register not used in this mode                     */      \
}

/***************************************************************************//*!
 * @brief IRTC active tamper pin input mode.
 * @details IRTC active tamper pin input mode.
 * @param   clksrc    Filter clock source @ref irtc_tamper_filt_clk. This clock
 *                    should be the same as "lfsr_clk" used in @ref irtc_config.
 * @param   period    Filter period from 0 to 15 (0 = filter disabled). This
 *                    value should be the same value used as "lfsr_dur" used in
 *                    @ref irtc_config.
 * @showinitializer
 ******************************************************************************/
#define IRTC_TAMPER_PIN_ACTIVE_INPMODE_CONFIG(clksrc,period)                  \
(tTAMPER){                                                                    \
/*DIRECTION  */ CLR(RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)|  /* use mask */      \
/*.........  */ SET(RTC_TAMPER_DIRECTION_A_P_TAMP_MASK),  /* use mask */      \
/*FILTER_CFG */ CLR(RTC_FILTER01_CFG_POL1_MASK)|                              \
/*.......... */ SET(RTC_FILTER01_CFG_CLK_SEL1(clksrc))|                       \
/*.......... */ SET(RTC_FILTER01_CFG_FIL_DUR1(period)),                       \
}
/*! @} End of irtc_tamper_config                                              */

/******************************************************************************
* IRTC callback type
*
*//*! @addtogroup irtc_callback_type
* @{
*******************************************************************************/
/*! IRTC_CALLBACK type definition                                             */
typedef enum
{
  IRTC_TAMPER0_CALLBACK = IRTC_TAMPER0_MASK,  ///< TAMPER0 interrupt
  IRTC_TAMPER1_CALLBACK = IRTC_TAMPER1_MASK,  ///< TAMPER1 interrupt
  IRTC_TAMPER2_CALLBACK = IRTC_TAMPER2_MASK,  ///< TAMPER2 interrupt
  IRTC_CNTDN_CALLBACK   = IRTC_CNTDN_MASK,    ///< Count Down Timer interrupt
  IRTC_ALM_CALLBACK     = IRTC_ALM_MASK,      ///< Alarm interrupt
  IRTC_DAY_CALLBACK     = IRTC_DAY_MASK,      ///< Day interrupt
  IRTC_HOUR_CALLBACK    = IRTC_HOUR_MASK,     ///< Hour interrupt
  IRTC_MIN_CALLBACK     = IRTC_MIN_MASK,      ///< Minute interrupt
  IRTC_1HZ_CALLBACK     = IRTC_1HZ_MASK,      ///< 1Hz interrupt
  IRTC_2HZ_CALLBACK     = IRTC_2HZ_MASK,      ///< 2Hz interrupt
  IRTC_4HZ_CALLBACK     = IRTC_4HZ_MASK,      ///< 4Hz interrupt
  IRTC_8HZ_CALLBACK     = IRTC_8HZ_MASK,      ///< 8Hz interrupt
  IRTC_16HZ_CALLBACK    = IRTC_16HZ_MASK,     ///< 16Hz interrupt
  IRTC_32HZ_CALLBACK    = IRTC_32HZ_MASK,     ///< 32Hz interrupt
  IRTC_64HZ_CALLBACK    = IRTC_64HZ_MASK,     ///< 64Hz interrupt
  IRTC_128HZ_CALLBACK   = IRTC_128HZ_MASK,    ///< 128Hz interrupt
  IRTC_256HZ_CALLBACK   = IRTC_256HZ_MASK,    ///< 256Hz interrupt
  IRTC_512HZ_CALLBACK   = IRTC_512HZ_MASK     ///< 512Hz interrupt
} IRTC_CALLBACK_TYPE;
/*! @} End of irtc_callback_type                                              */

/******************************************************************************
* IRTC callback registered by IRTC_Init() function
*
*//*! @addtogroup irtc_callback
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief  Pointer to IRTC_CALLBACK function.
 * @param  type  Callback type @ref irtc_callback_type.
 * @param  data  If Callback has been generated by any tamper pin then "data"
 *               points to tamper log @ref irtc_tamperlog. For other callback
 *               types "data" contains time stamp @ref irtc_time of the event
 *               being serviced.
 ******************************************************************************/
typedef void (*IRTC_CALLBACK)(IRTC_CALLBACK_TYPE type, void *data);
/*! @} End of irtc_callback                                                   */

/***************************************************************************//*!
 * @brief   Locks and unlocks IRTC registers for write operations.
 * @details This macro will lock and unlock the IRTC registers for write
 *          operation.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism. When the registers are unlocked, they remain in this
 *          unlocked state for 2 seconds after which they get locked
 *          automatically.
 ******************************************************************************/
#define IRTC_LockUnlock()                                                     \
{                                                                             \
  while (!(RTC_STATUS & RTC_STATUS_WRITE_PROT_EN_MASK))                       \
    *((volatile uint8*)0x40050012)=0x80;                                      \
  while (RTC_STATUS & RTC_STATUS_WRITE_PROT_EN_MASK)                          \
  {                                                                           \
    *((volatile uint8*)0x40050012)=0x00; *((volatile uint8*)0x40050012)=0x40; \
    *((volatile uint8*)0x40050012)=0xC0; *((volatile uint8*)0x40050012)=0x80; \
  }                                                                           \
}

/******************************************************************************
* IRTC Control configurations used by function
*
*//*! @addtogroup irtc_macro
* @{
*******************************************************************************/
#define RET_IRTC_TAMPER0_MASK()                                               \
  (RTC_TAMPER_SCR&RTC_TAMPER_SCR_TMPR_STS(TAMPER0_PIN))
#define RET_IRTC_TAMPER1_MASK()                                               \
  (RTC_TAMPER_SCR&RTC_TAMPER_SCR_TMPR_STS(TAMPER1_PIN))
#define RET_IRTC_TAMPER2_MASK()                                               \
  (RTC_TAMPER_SCR&RTC_TAMPER_SCR_TMPR_STS(TAMPER2_PIN))
#define RET_IRTC_ALM_MASK()     (RTC_ISR&RTC_ISR_ALM_IS_MASK  )
#define RET_IRTC_DAY_MASK()     (RTC_ISR&RTC_ISR_DAY_IS_MASK  )
#define RET_IRTC_HOUR_MASK()    (RTC_ISR&RTC_ISR_HOUR_IS_MASK )
#define RET_IRTC_MIN_MASK()     (RTC_ISR&RTC_ISR_MIN_IS_MASK  )
#define RET_IRTC_1HZ_MASK()     (RTC_ISR&RTC_ISR_IS_1HZ_MASK  )
#define RET_IRTC_2HZ_MASK()     (RTC_ISR&RTC_ISR_IS_2HZ_MASK  )
#define RET_IRTC_4HZ_MASK()     (RTC_ISR&RTC_ISR_IS_4HZ_MASK  )
#define RET_IRTC_8HZ_MASK()     (RTC_ISR&RTC_ISR_IS_8HZ_MASK  )
#define RET_IRTC_16HZ_MASK()    (RTC_ISR&RTC_ISR_IS_16HZ_MASK )
#define RET_IRTC_32HZ_MASK()    (RTC_ISR&RTC_ISR_IS_32HZ_MASK )
#define RET_IRTC_64HZ_MASK()    (RTC_ISR&RTC_ISR_IS_64HZ_MASK )
#define RET_IRTC_128HZ_MASK()   (RTC_ISR&RTC_ISR_IS_128HZ_MASK)
#define RET_IRTC_256HZ_MASK()   (RTC_ISR&RTC_ISR_IS_256HZ_MASK)
#define RET_IRTC_512HZ_MASK()   (RTC_ISR&RTC_ISR_IS_512HZ_MASK)
/***************************************************************************//*!
 * @brief   Returns state of IRTC interrupt pending flag.
 * @details This macro returns state of IRTC interrupt pending interrupt flag.
 * @param   flag    Select one of the @ref irtc_interrupt_mask.
 * @return  true (non-zero) interrupt flag set,
 * @return  false           interrupt flag cleared.
 * @note    Implemented as an inline macro.
 * @see     @ref IRTC_ClrIsrFlag
 ******************************************************************************/
#define IRTC_GetIsrFlag(flag)     RET_##flag()

/***************************************************************************//*!
 * @brief   Clear IRTC pending interrupt flag(s).
 * @details This macro clears IRTC pending interrupt flag(s).
 * @param   mask    Select one or more OR'ed @ref irtc_interrupt_mask.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_GetIsrFlag
 ******************************************************************************/
#define IRTC_ClrIsrFlag(mask)                                                 \
{                                                                             \
  register uint16 tmp_1 = RTC_TAMPER_SCR & 0x000f, tmp_2 = 0 ;                \
                                                                              \
  if((mask)&IRTC_TAMPER0_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_STS(TAMPER0_PIN);} \
  if((mask)&IRTC_TAMPER1_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_STS(TAMPER1_PIN);} \
  if((mask)&IRTC_TAMPER2_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_STS(TAMPER2_PIN);} \
  if((mask)&IRTC_ALM_MASK    ) {tmp_2|=RTC_ISR_ALM_IS_MASK;                 } \
  if((mask)&IRTC_DAY_MASK    ) {tmp_2|=RTC_ISR_DAY_IS_MASK;                 } \
  if((mask)&IRTC_HOUR_MASK   ) {tmp_2|=RTC_ISR_HOUR_IS_MASK;                } \
  if((mask)&IRTC_MIN_MASK    ) {tmp_2|=RTC_ISR_MIN_IS_MASK;                 } \
  if((mask)&IRTC_1HZ_MASK    ) {tmp_2|=RTC_ISR_IS_1HZ_MASK;                 } \
  if((mask)&IRTC_2HZ_MASK    ) {tmp_2|=RTC_ISR_IS_2HZ_MASK;                 } \
  if((mask)&IRTC_4HZ_MASK    ) {tmp_2|=RTC_ISR_IS_4HZ_MASK;                 } \
  if((mask)&IRTC_8HZ_MASK    ) {tmp_2|=RTC_ISR_IS_8HZ_MASK;                 } \
  if((mask)&IRTC_16HZ_MASK   ) {tmp_2|=RTC_ISR_IS_16HZ_MASK;                } \
  if((mask)&IRTC_32HZ_MASK   ) {tmp_2|=RTC_ISR_IS_32HZ_MASK;                } \
  if((mask)&IRTC_64HZ_MASK   ) {tmp_2|=RTC_ISR_IS_64HZ_MASK;                } \
  if((mask)&IRTC_128HZ_MASK  ) {tmp_2|=RTC_ISR_IS_128HZ_MASK;               } \
  if((mask)&IRTC_256HZ_MASK  ) {tmp_2|=RTC_ISR_IS_256HZ_MASK;               } \
  if((mask)&IRTC_512HZ_MASK  ) {tmp_2|=RTC_ISR_IS_512HZ_MASK;               } \
  IRTC_LockUnlock();                                                          \
  RTC_TAMPER_SCR = tmp_1;                                                     \
  RTC_ISR        = tmp_2;                                                     \
}

/***************************************************************************//*!
 * @brief   Disables IRTC interrupt(s).
 * @details This macro disables selected IRTC interrupt(s)
 * @param   mask    Select one or more OR'ed @ref irtc_interrupt_mask.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_EnableIsr
 ******************************************************************************/
#define IRTC_DisableIsr(mask)                                                 \
{                                                                             \
  register uint16 tmp_1 = 0, tmp_2 = 0 ;                                      \
                                                                              \
  if((mask)&IRTC_TAMPER0_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER0_PIN);}  \
  if((mask)&IRTC_TAMPER1_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER1_PIN);}  \
  if((mask)&IRTC_TAMPER2_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER2_PIN);}  \
  if((mask)&(IRTC_TAMPER0_MASK|IRTC_TAMPER1_MASK|IRTC_TAMPER2_MASK))          \
    tmp_2|=RTC_IER_TAMPER_IE_MASK;                                            \
  if((mask)&IRTC_ALM_MASK    ) {tmp_2|=RTC_IER_ALM_IE_MASK;                }  \
  if((mask)&IRTC_DAY_MASK    ) {tmp_2|=RTC_IER_DAY_IE_MASK;                }  \
  if((mask)&IRTC_HOUR_MASK   ) {tmp_2|=RTC_IER_HOUR_IE_MASK;               }  \
  if((mask)&IRTC_MIN_MASK    ) {tmp_2|=RTC_IER_MIN_IE_MASK;                }  \
  if((mask)&IRTC_1HZ_MASK    ) {tmp_2|=RTC_IER_IE_1HZ_MASK;                }  \
  if((mask)&IRTC_2HZ_MASK    ) {tmp_2|=RTC_IER_IE_2HZ_MASK;                }  \
  if((mask)&IRTC_4HZ_MASK    ) {tmp_2|=RTC_IER_IE_4HZ_MASK;                }  \
  if((mask)&IRTC_8HZ_MASK    ) {tmp_2|=RTC_IER_IE_8HZ_MASK;                }  \
  if((mask)&IRTC_16HZ_MASK   ) {tmp_2|=RTC_IER_IE_16HZ_MASK;               }  \
  if((mask)&IRTC_32HZ_MASK   ) {tmp_2|=RTC_IER_IE_32HZ_MASK;               }  \
  if((mask)&IRTC_64HZ_MASK   ) {tmp_2|=RTC_IER_IE_64HZ_MASK;               }  \
  if((mask)&IRTC_128HZ_MASK  ) {tmp_2|=RTC_IER_IE_128HZ_MASK;              }  \
  if((mask)&IRTC_256HZ_MASK  ) {tmp_2|=RTC_IER_IE_256HZ_MASK;              }  \
  if((mask)&IRTC_512HZ_MASK  ) {tmp_2|=RTC_IER_IE_512HZ_MASK;              }  \
  IRTC_LockUnlock();                                                          \
  ioclrh (RTC_TAMPER_SCR,tmp_1);                                              \
  ioclrh (RTC_IER       ,tmp_2);                                              \
}

/***************************************************************************//*!
 * @brief   Enables selected IRTC interrupt(s).
 * @details This macro enables selected IRTC interrupt(s).
 * @param   mask    Select one or more OR'ed @ref irtc_interrupt_mask.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_DisableIsr
 ******************************************************************************/
#define IRTC_EnableIsr(mask)                                                  \
{                                                                             \
  register uint16 tmp_1 = 0, tmp_2 = 0;                                       \
                                                                              \
  if((mask)&IRTC_TAMPER0_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER0_PIN);}  \
  if((mask)&IRTC_TAMPER1_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER1_PIN);}  \
  if((mask)&IRTC_TAMPER2_MASK) {tmp_1|=RTC_TAMPER_SCR_TMPR_EN(TAMPER2_PIN);}  \
  if((mask)&(IRTC_TAMPER0_MASK|IRTC_TAMPER1_MASK|IRTC_TAMPER2_MASK))          \
    tmp_2|=RTC_IER_TAMPER_IE_MASK;                                            \
  if((mask)&IRTC_ALM_MASK    ) {tmp_2|=RTC_IER_ALM_IE_MASK;                }  \
  if((mask)&IRTC_DAY_MASK    ) {tmp_2|=RTC_IER_DAY_IE_MASK;                }  \
  if((mask)&IRTC_HOUR_MASK   ) {tmp_2|=RTC_IER_HOUR_IE_MASK;               }  \
  if((mask)&IRTC_MIN_MASK    ) {tmp_2|=RTC_IER_MIN_IE_MASK;                }  \
  if((mask)&IRTC_1HZ_MASK    ) {tmp_2|=RTC_IER_IE_1HZ_MASK;                }  \
  if((mask)&IRTC_2HZ_MASK    ) {tmp_2|=RTC_IER_IE_2HZ_MASK;                }  \
  if((mask)&IRTC_4HZ_MASK    ) {tmp_2|=RTC_IER_IE_4HZ_MASK;                }  \
  if((mask)&IRTC_8HZ_MASK    ) {tmp_2|=RTC_IER_IE_8HZ_MASK;                }  \
  if((mask)&IRTC_16HZ_MASK   ) {tmp_2|=RTC_IER_IE_16HZ_MASK;               }  \
  if((mask)&IRTC_32HZ_MASK   ) {tmp_2|=RTC_IER_IE_32HZ_MASK;               }  \
  if((mask)&IRTC_64HZ_MASK   ) {tmp_2|=RTC_IER_IE_64HZ_MASK;               }  \
  if((mask)&IRTC_128HZ_MASK  ) {tmp_2|=RTC_IER_IE_128HZ_MASK;              }  \
  if((mask)&IRTC_256HZ_MASK  ) {tmp_2|=RTC_IER_IE_256HZ_MASK;              }  \
  if((mask)&IRTC_512HZ_MASK  ) {tmp_2|=RTC_IER_IE_512HZ_MASK;              }  \
  IRTC_LockUnlock();                                                          \
  ioseth (RTC_TAMPER_SCR,tmp_1);                                              \
  ioseth (RTC_IER       ,tmp_2);                                              \
}

/***************************************************************************//*!
 * @brief   Selects clock source to be outputted from device for use outside RTC.
 * @details This macro selects clock source to be outputted from device for use
 *          outside RTC. Clock is routed to RTCCLKOUT pins and XBAR input[10].
 * @param   src   Select one of the @ref irtc_clkout_src.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelClkout
 ******************************************************************************/
#define IRTC_SelRtcClkout(src)                                                \
{                                                                             \
    IRTC_LockUnlock();                                                        \
    iobfih (RTC_CTRL,RTC_CTRL_CLKOUT_SHIFT,2,src);                            \
}

/***************************************************************************//*!
 * @brief   Fills @ref irtc_tamperlog with current tamper event time stamp and
 *          status information.
 * @details This macro will fills @ref irtc_tamperlog with current time stamp and
 *          status information.
 * @param   log   Pointer to @ref irtc_tamperlog.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define IRTC_GetTamperLog(log)                                                \
{                                                                             \
  register tTAMPER_LOG *ptr = log;                                            \
  register uint16 tmp;                                                        \
                                                                              \
  tmp         = RTC_TAMPER_QUEUE;                                             \
  ptr->hour   = (tmp >> 0) & 0x1f;                                            \
  ptr->day    = (tmp >> 5) & 0x1f;                                            \
  ptr->mon    = (tmp >>10) & 0x0f;                                            \
  tmp         = RTC_TAMPER_QUEUE;                                             \
  ptr->sec    = (tmp >> 0) & 0x3f;                                            \
  ptr->min    = (tmp >> 6) & 0x3f;                                            \
  ptr->source = (1<<((tmp >>12) & 0x03));                                     \
}

/***************************************************************************//*!
 * @brief   Sets active low polarity for specified tamper pins.
 * @details This macro sets active low polarity for specified tamper pins.
 * @param   pin   Select one of the @ref irtc_tamper_pin.
 * @note    Implemented as an inline macro.
 * @see     @ref IRTC_SetTamperPinActiveHigh
 ******************************************************************************/
#define IRTC_SetTamperPinActiveLow(pin)                                       \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  if ((pin)&TAMPER0_PIN) ioseth (RTC_FILTER01_CFG,RTC_FILTER01_CFG_POL0_MASK);\
  if ((pin)&TAMPER1_PIN) ioseth (RTC_FILTER01_CFG,RTC_FILTER01_CFG_POL1_MASK);\
  if ((pin)&TAMPER2_PIN) ioseth (RTC_FILTER2_CFG , RTC_FILTER2_CFG_POL2_MASK);\
}

/***************************************************************************//*!
* @brief   Sets active high polarity for specified tamper pins.
* @details This macro sets active high polarity for specified tamper pins.
* @param   pin   Select one of the @ref irtc_tamper_pin.
* @note    Implemented as an inline macro.
* @see     @ref IRTC_SetTamperPinActiveLow
*****************************************************************************/
#define IRTC_SetTamperPinActiveHigh(pin)                                      \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  if ((pin)&TAMPER0_PIN) ioclrh (RTC_FILTER01_CFG,RTC_FILTER01_CFG_POL0_MASK);\
  if ((pin)&TAMPER1_PIN) ioclrh (RTC_FILTER01_CFG,RTC_FILTER01_CFG_POL1_MASK);\
  if ((pin)&TAMPER2_PIN) ioclrh (RTC_FILTER2_CFG , RTC_FILTER2_CFG_POL2_MASK);\
}

/***************************************************************************//*!
 * @brief   Enables Boot into VLPR mode after POR.
 * @details This macro enables the VLPR Boot Mode after POR.
 * @note    Implemented as an inline macro.
 * @warning Use this macro with precaution. You won't be able to program the MCU
 *          after reset. Make sure there is a way to clear this bit.  An attempt
 *          to debug this macro may fail due to IRTC lock/unlock mechanism.
 * @see     @ref IRTC_BootRUN
 ******************************************************************************/
#define IRTC_BootVLPR()                                                       \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  (*((volatile uint8*)0x40050020))|= 0x0080;                                  \
}

/***************************************************************************//*!
 * @brief   Enables Boot into RUN mode after POR.
 * @details This macro enables the RUN Boot Mode after POR.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_BootVLPR
 ******************************************************************************/
#define IRTC_BootRUN()                                                        \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  (*((volatile uint8*)0x40050020))&=~0x0080;                                  \
}

/***************************************************************************//*!
 * @brief   Gets IRTC clock.
 * @details This function reads date and time from IRTC module. Function
 *          updates the tTIME structure passed by pointer.
 * @param   ptr  Pointer to the @ref irtc_time.
 * @note    Implemented as a function call.
 * @warning An attempt to debug this function may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_SetClock
 ******************************************************************************/
#define IRTC_GetClock(ptr) IRTC_GetClock(ptr)

/***************************************************************************//*!
 * @brief   Sets IRTC clock.
 * @details This function sets date and time of the IRTC module. Function
 *          sets IRTC module with parameters from tTIME structure passed by
 *          pointer.
 * @param   ptr  Pointer to the @ref irtc_time.
 * @note    Implemented as a function call.
 * @warning An attempt to debug this function may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_GetClock
 ******************************************************************************/
#define IRTC_SetClock(ptr) IRTC_SetClock(ptr)

/***************************************************************************//*!
 * @brief   Sets IRTC alarm and alarm match condition.
 * @details This function sets IRTC alarm and alarm match condition.
 * @param   match   Select one of the @ref irtc_alarm_match.
 * @param   time    Pointer to the @ref irtc_alarm.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 ******************************************************************************/
#define IRTC_SetAlarm(match,time)                                             \
{                                                                             \
  register tALARM *ptr = time;                                                \
                                                                              \
  IRTC_LockUnlock();                                                          \
  iobfih (RTC_CTRL,RTC_CTRL_ALM_MATCH_SHIFT,2,match);                         \
  RTC_ALM_YEARMON = RTC_ALM_YEARMON_ALM_YEAR(ptr->year-BASE_YEAR)|            \
                    RTC_ALM_YEARMON_ALM_MON(ptr->mon);                        \
  RTC_ALM_DAYS    = RTC_ALM_DAYS_ALM_DAY(ptr->day);                           \
  RTC_ALM_HOURMIN = RTC_ALM_HOURMIN_ALM_HOUR(ptr->hour)|                      \
                    RTC_ALM_HOURMIN_ALM_MIN(ptr->min);                        \
  RTC_ALM_SECONDS = RTC_ALM_SECONDS_ALM_SEC(ptr->sec);                        \
}

/***************************************************************************//*!
 * @brief   Sets Daylight Saving Time (DST).
 * @details This function sets Daylight Saving Time (DST).
 * @param   hour_start  Daylight Saving Time (DST) Hour Start Value.
 * @param   day_start   Daylight Saving Time (DST) Day Start Value.
 * @param   mon_start   Daylight Saving Time (DST) @ref irtc_mon Start Value .
 * @param   hour_end    Daylight Saving Time (DST) Hour End Value.
 * @param   day_end     Daylight Saving Time (DST) Day End Value.
 * @param   mon_end     Daylight Saving Time (DST) @ref irtc_mon End Value.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 ******************************************************************************/
#define IRTC_SetDST(hour_start,day_start,mon_start,hour_end,day_end,mon_end)  \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  RTC_DST_HOUR  = RTC_DST_HOUR_DST_START_HOUR(hour_start)|                    \
                  RTC_DST_HOUR_DST_END_HOUR(hour_end);                        \
  RTC_DST_DAY   = RTC_DST_DAY_DST_START_DAY(day_start)|                       \
                  RTC_DST_DAY_DST_END_DAY(day_end);                           \
  RTC_DST_MONTH = RTC_DST_MONTH_DST_START_MONTH(mon_start)|                   \
                  RTC_DST_MONTH_DST_END_MONTH(mon_end);                       \
  ioseth (RTC_CTRL,RTC_CTRL_DST_EN_MASK);                                     \
}

/***************************************************************************//*!
 * @brief   Updates coarse compensation value.
 * @details This function updates coarse compensation value.
 * @param   interval  Compensation Interval is the duration in seconds over
 *                    which the correction is applied. This is the time in which
 *                    the addition or removal of 32.768 KHz clock cycles is done
 *                    thereby ensuring that the compensation interval is close
 *                    to the interval obtained with an ideal 1 Hz clock. Range
 *                    of Compensation Interval: 1 second to 255 seconds.
 * @param   value     Compensation/Correction Value is a 2's complement format
 *                    by which the 1 Hz Clock is modified by either adding or
 *                    removing RTC Oscillator clock cycles. Range of
 *                    Compensation: -128 to +127 (32.768 KHz clock cycles).
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_UpdateFineCompVal
 ******************************************************************************/
#define IRTC_UpdateCoarseCompVal(interval,value)                              \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  RTC_COMPEN = RTC_COMPEN_COMPEN_VAL((((uint16)interval<<8)&0xff00)|          \
                                     (((uint16)value)&0x00ff));               \
}

/***************************************************************************//*!
 * @brief   Updates fine compensation value.
 * @details This function updates fine compensation value.
 * @param   integer   Integral Compensation Value is a 2's complement value of
 *                    the integer part of correction that has to be adjusted
 *                    in every 1 second period. Range of Compensation:
 *                    from -8 to +7 (32.768 KHz clock cycles).
 * @param   fraction  Fraction Compensation Value is the fractional part of the
 *                    correction value that has to be adjusted. This value is
 *                    expressed as number of clock cycles of a fixed 4.194304 MHz
 *                    clock. Range of Compensation Interval: from 0 (0us delay)
 *                    to 127 (30.279us delay).
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @see     @ref IRTC_UpdateCoarseCompVal
 ******************************************************************************/
#define IRTC_UpdateFineCompVal(integer,fraction)                              \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  RTC_COMPEN = RTC_COMPEN_COMPEN_VAL((((uint16)integer<<12)&0xf000)|          \
                                     (((uint16)fraction)&0x007f));            \
}

/***************************************************************************//*!
 * @brief   Writes data into 32-byte IRTC RAM.
 * @details This macro writes data into 32-byte IRTC RAM.
 * @param   src     Pointer to the @ref uint8 array to be saved.
 * @param   size    Number of bytes in range from 1 to 32.
 * @note    Implemented as an inline macro.
 * @see     @ref IRTC_RdRam
 ******************************************************************************/
#define IRTC_WrRam(src,size)        IRTC_WrRam(src,size)

/***************************************************************************//*!
 * @brief   Reads data from 32-byte IRTC RAM.
 * @details This macro reads data from 32-byte IRTC RAM.
 * @param   dst     Pointer to the @ref uint8 array to be read.
 * @param   size    Number of bytes in range from 1 to 32.
 * @note    Implemented as an inline macro.
 * @see     @ref IRTC_WrRam
 ******************************************************************************/
#define IRTC_RdRam(dst,size)        IRTC_RdRam(dst,size)

/***************************************************************************//*!
 * @brief   Places device into hibernation mode.
 * @details This macro places device into hibernation mode by forcing
 *          TAMPER0 pin state from HiZ to either logic 0 or logic 1. The TAMPER0
 *          pin is expected to control external LDO regulator or PMOS transistor.
 * @param   state     Select one of the @ref irtc_wakeup_states.
 * @note    Implemented as an inline macro.
 * @warning An attempt to debug this macro may fail due to IRTC lock/unlock
 *          mechanism.
 * @warning Set the required wakeup interrupt sources to recover from
 *          hibernation mode. When the selected event (interrupt) is detected,
 *          the TAMPER0 pin changes back to HiZ mode and switch on supply power
 *          for the device via controlling external LDO regulator or PMOS
 *          transistor.
 * @see     @ref IRTC_WkupInit
 ******************************************************************************/
#define IRTC_Hibernate(state)                                                 \
{                                                                             \
  IRTC_LockUnlock();                                                          \
  iobfih (RTC_CTRL2,RTC_CTRL2_WAKEUP_STATUS_SHIFT,2,state);                   \
}

/***************************************************************************//*!
 * @brief   Installs callback function for IRTC interrupt vector 41.
 * @details This function installs callback function for IRTC interrupt vector 41.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref irtc_callback.
 * @note    Implemented as a function call.
 * @see     @ref IRTC_Init, @ref IRTC_WkupInit
 ******************************************************************************/
#define IRTC_InstallCallback(ip,callback) IRTC_InstallCallback(ip,callback)

/***************************************************************************//*!
 * @brief   Initializes IRTC module with WKUP/TAMPER0 pin assigned to tamper mode.
 * @details This function initializes Independent Real Time Clock (IRTC) and
 *          functionality of all three tamper pins. Call @ref IRTC_InstallCallback
 *          function to install callback function for IRTC interrupt vector 45.
 * @param   irtc      Select one of the @ref irtc_config.
 * @param   t0        TAMPER0 pin configuration @ref irtc_tamper_config.
 * @param   t1        TAMPER1 pin configuration @ref irtc_tamper_config.
 * @param   t2        TAMPER2 pin configuration @ref irtc_tamper_config.
 * @param   mask      Select one or more OR'ed @ref irtc_interrupt_mask.
 *          Remaining interrupts will be disabled.
 * @note    Implemented as a function call.
 * @warning Function disables all interrupts excluding those selected by
 *          <c>mask</c>. An attempt to debug this function may fail due to IRTC
 *          lock/unlock mechanism.
 * @see     @ref IRTC_WkupInit, @ref IRTC_InstallCallback, @ref FLL_CtrlIRCLKEN,
 *          @ref FLL_SetFastClkDiv
 ******************************************************************************/
#define IRTC_Init(irtc,t0,t1,t2,mask)     IRTC_Init(irtc,t0,t1,t2,mask)

/***************************************************************************//*!
 * @brief   Initializes IRTC module with WKUP/TAMPER0 pin assigned to hibernation
 *          mode.
 * @details This function initializes Independent Real Time Clock (IRTC) and
 *          functionality of two tamper pins (TAMPER1 and TAMPER2). The TAMPER0
 *          pin is configured into hibernation mode. Call @ref IRTC_InstallCallback
 *          function to install callback function for IRTC interrupt vector 45.
 * @param   irtc      Select one of the @ref irtc_config.
 * @param   t1        TAMPER1 pin configuration @ref irtc_tamper_config.
 * @param   t2        TAMPER2 pin configuration @ref irtc_tamper_config.
 * @param   mask      Select one or more OR'ed @ref irtc_interrupt_mask.
 *          Remaining interrupts will be disabled.
 * @note    Implemented as a function call.
 * @warning Function disables all interrupts excluding those selected by
 *          <c>mask</c>. An attempt to debug this function may fail due to IRTC
 *          lock/unlock mechanism.
 * @see     @ref IRTC_Init, @ref IRTC_InstallCallback, @ref IRTC_Hibernate,
 *          @ref FLL_CtrlIRCLKEN, @ref FLL_SetFastClkDiv
 ******************************************************************************/
#define IRTC_WkupInit(irtc,t1,t2,mask) IRTC_WkupInit(irtc,t1,t2,mask)
/*! @} End of irtc_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void IRTC_InstallCallback (uint8 ip, IRTC_CALLBACK pCallback);
extern void IRTC_Init (tIRTC irtc, tTAMPER t0, tTAMPER t1, tTAMPER t2, uint32 mask);
extern void IRTC_WkupInit (tIRTC irtc, tTAMPER t1, tTAMPER t2, uint32 mask);
extern void IRTC_GetClock (tTIME *ptr);
extern void IRTC_SetClock (tTIME *ptr);
extern void IRTC_WrRam  (void *src, uint8 size);
extern void IRTC_RdRam  (void *dst, uint8 size);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void irtc_isr (void);

#endif /* __IRTC_H */