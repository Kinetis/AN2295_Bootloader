/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      rcm.h
 * @version   1.0.3.0
 * @date      Jun-11-2015
 * @brief     Reset Control Module (RCM) driver header file.
 ******************************************************************************/
#ifndef __RCM_H
#define __RCM_H

#if !defined(MCU_MKM34ZA5)
  #error "The rcm.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 RPFC, RPFW; } tRCM;

/******************************************************************************
* RCM sources of the most recent reset. The reset sources are returned by
* RTC_GetResetSrc macro.
*
*//*! @addtogroup rcm_rst_sources
* @{
*******************************************************************************/
#define RCM_SACKERR (uint16)(1u<<13) ///< Reset has been caused by a failure of
                                     ///  one or more peripherals to acknowledge
                                     ///  within approximately one second to enter
                                     ///  stop mode after an attempt to enter Stop
                                     ///  mode.
#define RCM_MDM_AP  (uint16)(1u<<11) ///< Reset has been caused by the host
                                     ///  debugger system setting of the System
                                     ///  Reset Request bit in the MDM-AP Control
                                     ///  Register.
#define RCM_SW      (uint16)(1u<<10) ///< Reset has been caused by software
                                     ///  setting of SYSRESETREQ bit in
                                     ///  Application Interrupt and Reset Control
                                     ///  Register in the ARM core.
#define RCM_LOCKUP  (uint16)(1u<< 9) ///< Reset has been caused by the ARM core
                                     ///  indication of a LOCKUP event.
#define RCM_POR     (uint16)(1u<< 7) ///< Reset has been caused by the power-on
                                     ///  detection logic. Because the internal
                                     ///  supply voltage was ramping up at the
                                     ///  time, the low-voltage reset (LVD) status
                                     ///  bit is also set to indicate that the
                                     ///  reset occurred while the internal supply
                                     ///  was below the LVD threshold.
#define RCM_PIN     (uint16)(1u<< 6) ///< Reset has been caused by an active-low
                                     ///  level on the external /RESET pin.
#define RCM_WDOG    (uint16)(1u<< 5) ///< Reset has been caused by the watchdog
                                     ///  timer timing out. This reset source can
                                     ///  be blocked by disabling the watchdog.
#define RCM_LOL     (uint16)(1u<< 3) ///< Reset has been caused by a loss of lock
                                     ///  in the MCG PLL.
#define RCM_LOC     (uint16)(1u<< 2) ///< Reset has been caused by a loss of
                                     ///  external clock. The MCG clock monitor
                                     ///  must be enabled for a loss of clock to
                                     ///  be detected.
#define RCM_LVD     (uint16)(1u<< 1) ///< If the LVDRE bit is set and the supply
                                     ///  drops below the LVD trip voltage, an LVD
                                     ///  reset occurs. This bit is also set by POR.
#define RCM_WAKEUP  (uint16)(1u<< 0) ///< Reset has been caused by an enabled
                                     ///  wakeup source while the chip was in a low
                                     ///  leakage mode. Any enabled wakeup source
                                     ///  in a VLLSx mode causes a reset. This bit
                                     ///  is cleared by any reset except WAKEUP.
/*! @} End of rcm_rst_sources                                                 */

/******************************************************************************
* RCM default configurations used by RCM_Init() macro.
*
*//*! @addtogroup rcm_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Reset pin filter disabled in all modes (default).
 * @details Configuration structure disables reset pin filter in Run, Wait, Stop,
 *          VLPS and VLLSx modes (default).
 * @showinitializer
 ******************************************************************************/
#define RCM_MODULE_FILT_DI_IN_ALL_MODES_CONFIG                                 \
(tRCM){                                                                        \
/* RPFC */ CLR(RCM_RPFC_RSTFLTSS_MASK)|SET(RCM_RPFC_RSTFLTSRW(0)),             \
/* RPFW */ SET(RCM_RPFW_RSTFLTSEL(0))                                          \
}

/***************************************************************************//*!
 * @brief   Reset pin filter enabled and clocked by LPO in Stop modes.
 * @details Configuration structure enables reset pin filter in Stop modes
 *          In Run/Wait modes All filtering is disabled
 * @warning LPO filter has a fixed filter value of 3. Due to a synchronizer on
 *          the input data, there is also some associated latency (2 cycles)
 *          As a result, 5 cycles are required to complete a transition from low
 *          to high or high to low.
 * @showinitializer
 ******************************************************************************/
#define RCM_MODULE_FILT_EN_IN_STOP_MODES_CONFIG                                \
(tRCM){                                                                        \
/* RPFC */ SET(RCM_RPFC_RSTFLTSS_MASK)|SET(RCM_RPFC_RSTFLTSRW(0x0)),           \
/* RPFW */ SET(RCM_RPFW_RSTFLTSEL(0x0))                                        \
}

/***************************************************************************//*!
 * @brief   Reset pin filter enabled and clocked by BUS clock in run/wait modes
 * @details Configuration structure enables reset pin filter in Run/Wait modes
 *          In Stop modes All filtering is disabled
 * @param count - 1 - 32 bus clock filter counts.
 * @showinitializer
 ******************************************************************************/
#define RCM_MODULE_FILT_CLOCKED_BY_BUS_EN_IN_RUNWAIT_MODES_CONFIG(count)       \
(tRCM){                                                                        \
/* RPFC */ CLR(RCM_RPFC_RSTFLTSS_MASK)|SET(RCM_RPFC_RSTFLTSRW(0x1)),           \
/* RPFW */ SET(RCM_RPFW_RSTFLTSEL(count))                                      \
}

/***************************************************************************//*!
 * @brief   Reset pin filter enabled and clocked by LPO in run/wait modes
 * @details Configuration structure enables reset pin filter in Run/Wait modes
 *          In Stop modes All filtering is disabled
 * @warning LPO filter has a fixed filter value of 3. Due to a synchronizer on
 *          the input data, there is also some associated latency (2 cycles)
 *          As a result, 5 cycles are required to complete a transition from low
 *          to high or high to low.
 * @showinitializer
 ******************************************************************************/
#define RCM_MODULE_FILT_CLOCKED_BY_LPO_EN_IN_RUNWAIT_MODES_CONFIG              \
(tRCM){                                                                        \
/* RPFC */ CLR(RCM_RPFC_RSTFLTSS_MASK)|SET(RCM_RPFC_RSTFLTSRW(0x2)),           \
/* RPFW */ SET(RCM_RPFW_RSTFLTSEL(0x0))                                        \
}

/***************************************************************************//*!
 * @brief   Reset pin filter enabled and clocked by LPO in all modes.
 * @details Configuration structure enables reset pin filter in Run, Wait, Stop,
 *          VLPS and VLLSx modes (except VLLS0). Filter is clocked by LPO.
 * @warning LPO filter has a fixed filter value of 3. Due to a synchronizer on
 *          the input data, there is also some associated latency (2 cycles).
 *          As a result, 5 cycles are required to complete a transition from low
 *          to high or high to low.
 * @showinitializer
 ******************************************************************************/
#define RCM_MODULE_FILT_CLOCKED_BY_LPO_EN_IN_ALL_MODES_CONFIG                  \
(tRCM){                                                                        \
/* RPFC */ SET(RCM_RPFC_RSTFLTSS_MASK)|SET(RCM_RPFC_RSTFLTSRW(2)),             \
/* RPFW */ SET(RCM_RPFW_RSTFLTSEL(0))                                          \
}
/*! @} End of rcm_config                                                      */

/******************************************************************************
* RCM function and macro definitions
*
*//*! @addtogroup rcm_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns status flags indicating the source of reset.
 * @details This macro returns status flags indicating the source of the most
 *          recent reset.
 * @return  @ref rcm_rst_sources.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define RCM_GetResetSrc()         ((uint16)RCM_SRS0|(((uint16)RCM_SRS1)<<8))

/***************************************************************************//*!
 * @brief   Clears status flags indicating the source of reset.
 * @details This macro clears status flags indicating the source of the most
 *          recent reset.
 * @param   mask    Select one of the @ref rcm_rst_sources.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define RCM_ClrResetFlags(mask)  ((uint8)RCM_SRS0 = ((mask) & 0xff);           \
                                 ((uint8)RCM_SRS1 = ((mask)>>8) & 0xff);

/***************************************************************************//*!
 * @brief   RCM initialization.
 * @details This function initializes reset pin filter.
 * @param   cfg   Select one of the @ref rcm_config.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define RCM_Init(cfg)             RCM_RPFC = cfg.RPFC; RCM_RPFW = cfg.RPFW
/*! @} End of rcm_macro                                                       */

#endif /* __RCM_H */ 