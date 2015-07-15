/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      wdog.h
 * @version   1.0.4.0
 * @date      Apr-20-2015
 * @brief     Watchdog Timer (WDOG) driver header file.
 ******************************************************************************/
#ifndef __WDOG_H
#define __WDOG_H

#if !defined(MCU_MKM34ZA5)
  #error "The wdog.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint16 STCTRLH, TOVALH, TOVALL, WINH, WINL, PRESC; } tWDOG;

/******************************************************************************
* WDOG clock sources definitions.
*
*//*! @addtogroup wdog_clk_src
* @{
*******************************************************************************/
#define WDOG_LPO_CLK  (uint8)0x00   ///< 1KHz LPO (default)
#define WDOG_ALT_CLK  (uint8)0x01   ///< Source selected in SIM_SOPT1[OSC32KSEL];
                                    ///  refer to @ref SIM_SelOsc32kClk
/*! @} End of wdog_clk_src                                                    */

/******************************************************************************
* WDOG clock divider definitions.
*
*//*! @addtogroup wdog_clk_div
* @{
*******************************************************************************/
#define WDOG_DIV1    (uint16)0x00   ///< divide by 1
#define WDOG_DIV2    (uint16)0x01   ///< divide by 2
#define WDOG_DIV3    (uint16)0x02   ///< divide by 3
#define WDOG_DIV4    (uint16)0x03   ///< divide by 4
#define WDOG_DIV5    (uint16)0x04   ///< divide by 5 (default)
#define WDOG_DIV6    (uint16)0x05   ///< divide by 6
#define WDOG_DIV7    (uint16)0x06   ///< divide by 7
#define WDOG_DIV8    (uint16)0x07   ///< divide by 8
/*! @} End of wdog_clk_div                                                    */

/******************************************************************************
* WDOG default configurations used by WDOG_Init() function
*
*//*! @addtogroup wdog_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Enables watchdog module in normal (Timer) configuration. Watchdog is
 * active in RUN, VLPR and WAIT modes. It doesn't run in STOP and DBG modes.
 * @details Enables watchdog module in normal (Timer) configuration with the
 * following characteristic:
 *  - WDOG functional test mode is disabled permanently until reset
 *  - WDOG is enabled in CPU Wait mode
 *  - WDOG is disabled in CPU Stop mode
 *  - WDOG is disabled in CPU Debug mode
 *  - WDOG write-once registers can be unlocked for updating
 *  - Windowing mode is disabled
 *  - WDOG time-out generates reset only
 *  - WDOG is enabled
 * @param clksrc  Select one of the @ref wdog_clk_src.
 * @param clkdiv  Select one of the @ref wdog_clk_div.
 * @param period  Watchdog timeout in number of clock cycles (4 to 4294967296).
 * @showinitializer
 ******************************************************************************/
#define WDOG_MODULE_NORMAL_STOP_DI_CONFIG(clksrc,clkdiv,period)               \
(tWDOG){                                                                      \
/* STCTRLH  */  SET(WDOG_STCTRLH_DISTESTWDOG_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_BYTESEL(0x00))|                              \
/* .......  */  CLR(WDOG_STCTRLH_TESTSEL_MASK)|                               \
/* .......  */  CLR(WDOG_STCTRLH_TESTWDOG_MASK)|                              \
/* .......  */  CLR(WDOG_STCTRLH_STOPEN_MASK)|                                \
/* .......  */  CLR(WDOG_STCTRLH_DBGEN_MASK)|                                 \
/* .......  */  SET(WDOG_STCTRLH_ALLOWUPDATE_MASK)|                           \
/* .......  */  CLR(WDOG_STCTRLH_WINEN_MASK)|                                 \
/* .......  */  CLR(WDOG_STCTRLH_IRQRSTEN_MASK)|                              \
/* .......  */  SET(clksrc<<WDOG_STCTRLH_CLKSRC_SHIFT)|                       \
/* .......  */  SET(WDOG_STCTRLH_WDOGEN_MASK),                                \
/* TOVALH   */  SET(WDOG_TOVALH_TOVALHIGH((uint16)((period>>16)&0xffff))),    \
/* TOVALL   */  SET(WDOG_TOVALL_TOVALLOW((uint16)((period>> 0)&0xffff))),     \
/* WINH     */  SET(WDOG_WINH_WINHIGH(0x00)),                                 \
/* WINL     */  SET(WDOG_WINL_WINLOW(0x00)),                                  \
/* PRESC    */  SET(WDOG_PRESC_PRESCVAL((clkdiv&0x07))),                      \
}

/***************************************************************************//*!
 * @brief   Enables watchdog module in windowed configuration. Watchdog is
 * active in RUN, VLPR and WAIT modes. It doesn't run in STOP and DBG modes.
 * @details Enables watchdog module in normal (Timer) configuration with the
 * following characteristic:
 *  - WDOG functional test mode is disabled permanently until reset
 *  - WDOG is enabled in CPU Wait mode
 *  - WDOG is disabled in CPU Stop mode
 *  - WDOG is disabled in CPU Debug mode
 *  - WDOG write-once registers can be unlocked for updating
 *  - Windowing mode is enabled
 *  - WDOG time-out generates reset only
 *  - WDOG is enabled
 * @param clksrc  Select one of the @ref wdog_clk_src.
 * @param clkdiv  Select one of the @ref wdog_clk_div.
 * @param per_hi  Upper watchdog window timeout in number of clock cycles
 *                (4 to 4294967296).
 * @param per_lo  Lower watchdog window timeout in number of clock cycles
 *                (4 to 4294967296).
 * @showinitializer
 ******************************************************************************/
#define WDOG_MODULE_WINDOW_STOP_DI_CONFIG(clksrc,clkdiv,per_hi,per_lo)        \
(tWDOG){                                                                      \
/* STCTRLH  */  SET(WDOG_STCTRLH_DISTESTWDOG_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_BYTESEL(0x00))|                              \
/* .......  */  CLR(WDOG_STCTRLH_TESTSEL_MASK)|                               \
/* .......  */  CLR(WDOG_STCTRLH_TESTWDOG_MASK)|                              \
/* .......  */  CLR(WDOG_STCTRLH_STOPEN_MASK)|                                \
/* .......  */  CLR(WDOG_STCTRLH_DBGEN_MASK)|                                 \
/* .......  */  SET(WDOG_STCTRLH_ALLOWUPDATE_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_WINEN_MASK)|                                 \
/* .......  */  CLR(WDOG_STCTRLH_IRQRSTEN_MASK)|                              \
/* .......  */  SET(clksrc<<WDOG_STCTRLH_CLKSRC_SHIFT)|                       \
                SET(WDOG_STCTRLH_WDOGEN_MASK),                                \
/* TOVALH   */  SET(WDOG_TOVALH_TOVALHIGH((uint16)((per_hi>>16)&0xffff))),    \
/* TOVALL   */  SET(WDOG_TOVALL_TOVALLOW((uint16)((per_hi>> 0)&0xffff))),     \
/* WINH     */  SET(WDOG_WINH_WINHIGH((uint16)((per_lo>>16)&0xffff))),        \
/* WINL     */  SET(WDOG_WINL_WINLOW((uint16)((per_lo>>  0)&0xffff))),        \
/* PRESC    */  SET(WDOG_PRESC_PRESCVAL((clkdiv&0x07))),                      \
}

/***************************************************************************//*!
 * @brief   Enables watchdog module in normal (Timer) configuration. Watchdog is
 * active in RUN, VLPR, WAIT and STOP modes. It doesn't run in DBG mode.
 * @details Enables watchdog module in normal (Timer) configuration with the
 * following characteristic:
 *  - WDOG functional test mode is disabled permanently until reset
 *  - WDOG is enabled in CPU Wait mode
 *  - WDOG is enabled in CPU Stop mode
 *  - WDOG is disabled in CPU Debug mode
 *  - WDOG write-once registers can be unlocked for updating
 *  - Windowing mode is disabled
 *  - WDOG time-out generates reset only
 *  - WDOG is enabled
 * @param clksrc  Select one of the @ref wdog_clk_src.
 * @param clkdiv  Select one of the @ref wdog_clk_div.
 * @param period  Watchdog timeout in number of clock cycles (4 to 4294967296).
 * @showinitializer
 ******************************************************************************/
#define WDOG_MODULE_NORMAL_STOP_EN_CONFIG(clksrc,clkdiv,period)               \
(tWDOG){                                                                      \
/* STCTRLH  */  SET(WDOG_STCTRLH_DISTESTWDOG_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_BYTESEL(0x00))|                              \
/* .......  */  CLR(WDOG_STCTRLH_TESTSEL_MASK)|                               \
/* .......  */  CLR(WDOG_STCTRLH_TESTWDOG_MASK)|                              \
/* .......  */  SET(WDOG_STCTRLH_STOPEN_MASK)|                                \
/* .......  */  CLR(WDOG_STCTRLH_DBGEN_MASK)|                                 \
/* .......  */  SET(WDOG_STCTRLH_ALLOWUPDATE_MASK)|                           \
/* .......  */  CLR(WDOG_STCTRLH_WINEN_MASK)|                                 \
/* .......  */  CLR(WDOG_STCTRLH_IRQRSTEN_MASK)|                              \
/* .......  */  SET(clksrc<<WDOG_STCTRLH_CLKSRC_SHIFT)|                       \
                SET(WDOG_STCTRLH_WDOGEN_MASK),                                \
/* TOVALH   */  SET(WDOG_TOVALH_TOVALHIGH((uint16)((period>>16)&0xffff))),    \
/* TOVALL   */  SET(WDOG_TOVALL_TOVALLOW((uint16)((period>> 0)&0xffff))),     \
/* WINH     */  SET(WDOG_WINH_WINHIGH(0x00)),                                 \
/* WINL     */  SET(WDOG_WINL_WINLOW(0x00)),                                  \
/* PRESC    */  SET(WDOG_PRESC_PRESCVAL((clkdiv&0x07))),                      \
 }

/***************************************************************************//*!
 * @brief   Enables watchdog module in windowed configuration. Watchdog is
 * active in RUN, VLPR, WAIT and STOP modes. It doesn't run in DBG mode.
 * @details Enables watchdog module in normal (Timer) configuration with the
 * following characteristic:
 *  - WDOG functional test mode is disabled permanently until reset
 *  - WDOG is enabled in CPU Wait mode
 *  - WDOG is enabled in CPU Stop mode
 *  - WDOG is disabled in CPU Debug mode
 *  - WDOG write-once registers can be unlocked for updating
 *  - Windowing mode is enabled
 *  - WDOG time-out generates reset only
 *  - WDOG is enabled
 * @param clksrc  Select one of the @ref wdog_clk_src.
 * @param clkdiv  Select one of the @ref wdog_clk_div.
 * @param per_hi  Upper watchdog window timeout in number of clock cycles
 *                (4 to 4294967296).
 * @param per_lo  Lower watchdog window timeout in number of clock cycles
 *                (4 to 4294967296).
 * @showinitializer
 ******************************************************************************/
#define WDOG_MODULE_WINDOW_STOP_EN_CONFIG(clksrc,clkdiv,per_hi,per_lo)        \
(tWDOG){                                                                      \
/* STCTRLH  */  SET(WDOG_STCTRLH_DISTESTWDOG_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_BYTESEL(0x00))|                              \
/* .......  */  CLR(WDOG_STCTRLH_TESTSEL_MASK)|                               \
/* .......  */  CLR(WDOG_STCTRLH_TESTWDOG_MASK)|                              \
/* .......  */  SET(WDOG_STCTRLH_STOPEN_MASK)|                                \
/* .......  */  CLR(WDOG_STCTRLH_DBGEN_MASK)|                                 \
/* .......  */  SET(WDOG_STCTRLH_ALLOWUPDATE_MASK)|                           \
/* .......  */  SET(WDOG_STCTRLH_WINEN_MASK)|                                 \
/* .......  */  CLR(WDOG_STCTRLH_IRQRSTEN_MASK)|                              \
/* .......  */  SET(clksrc<<WDOG_STCTRLH_CLKSRC_SHIFT)|                       \
/* .......  */  SET(WDOG_STCTRLH_WDOGEN_MASK),                                \
/* TOVALH   */  SET(WDOG_TOVALH_TOVALHIGH((uint16)((per_hi>>16)&0xffff))),    \
/* TOVALL   */  SET(WDOG_TOVALL_TOVALLOW((uint16)((per_hi>> 0)&0xffff))),     \
/* WINH     */  SET(WDOG_WINH_WINHIGH((uint16)((per_lo>>16)&0xffff))),        \
/* WINL     */  SET(WDOG_WINL_WINLOW((uint16)((per_lo>>  0)&0xffff))),        \
/* PRESC    */  SET(WDOG_PRESC_PRESCVAL((clkdiv&0x07))),                      \
 }
/*! @} End of wdog_config                                                     */

/******************************************************************************
* VDOG function and macro definitions
*
*//*! @addtogroup wdog_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Sets watchdog timer register.
 * @details This macro sets timeout value of the watchdog timer.
 * @param   period  Watchdog timeout in number of clock cycles (4 to 4294967296).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define WDOG_SetTmrVal(period)                                                \
{                                                                             \
  WDOG_TOVALH=(uint16)((period>>16)&0xffff);                                  \
  WDOG_TOVALL=(uint16)((period>> 0)&0xffff);                                  \
}

/***************************************************************************//*!
 * @brief   Executes unlock sequence.
 * @details This macro  executes unlock sequence for allowing updates to
 *          write-once WDOG control/configuration bits.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define WDOG_WriteUnlockSeq()   WDOG_UNLOCK=0xC520; WDOG_UNLOCK=0xD928

/***************************************************************************//*!
 * @brief   Refreshes watchdog timer.
 * @details This macro refreshes the watchdog timer.
 * @note    Implemented as an inline macro.
 * @warning Watchdog IP requires at least 2 watchdog clock cycles to acknowledge
 *          refresh sequence. If next refresh sequence comes prior acknowledge
 *          the watchdog will reset MCU.
 ******************************************************************************/
#define WDOG_WriteRefreshSeq()  {                                             \
                                  volatile uint32 saveInt=GetInterruptMask(); \
                                  DisableInterrupts();                        \
                                  WDOG_REFRESH=0xA602;                        \
                                  WDOG_REFRESH=0xB480;                        \
                                  SetInterruptMask(saveInt);                  \
                                }

/***************************************************************************//*!
 * @brief   Disables the watchdog timer
 * @details This macro disables the watchdog timer permanently.
 * @note    Implemented as an inline macro.
 * @see     @ref WDOG_Init
 ******************************************************************************/
#define WDOG_Disable()          {                                             \
                                  volatile uint32 saveInt=GetInterruptMask(); \
                                  DisableInterrupts();                        \
                                  WDOG_WriteUnlockSeq();                      \
                                  NOP();                                      \
                                  WDOG_STCTRLH = 0x10|(1u << 7)|(1u << 8);    \
                                  SetInterruptMask(saveInt);                  \
                                }

/***************************************************************************//*!
 * @brief   Returns number of times the watchdog resets the system.
 * @details This macro returns number of times the watchdog resets the system
 *          (WDOG_RSTCNT register).
 * @return  content of RSTCNT register.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define WDOG_GetRSTCNT()      (uint16)WDOG_RSTCNT

/***************************************************************************//*!
 * @brief   Watchdog timer initialization.
 * @details This function initializes the watchdog timer.
 * @param   cfg  Select one of the @ref wdog_config.
 * @note    Implemented as an inline macro.
 * @see     @ref WDOG_Disable
 ******************************************************************************/
#define WDOG_Init(cfg)                                                        \
{                                                                             \
  register uint32 saveInt = GetInterruptMask();                               \
  DisableInterrupts();                                                        \
  WDOG_WriteUnlockSeq();                                                      \
  WDOG_PRESC  = cfg.PRESC;                                                    \
  WDOG_TOVALH = cfg.TOVALH;                                                   \
  WDOG_TOVALL = cfg.TOVALL;                                                   \
  WDOG_WINH   = cfg.WINH;                                                     \
  WDOG_WINL   = cfg.WINL;                                                     \
  WDOG_STCTRLH= cfg.STCTRLH|(1u << 8);                                        \
  SetInterruptMask(saveInt);                                                  \
}
/*! @} End of wdog_macro                                                      */

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void wdog_isr (void);

#endif /* __WDOG_H */
