/******************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      appconfig.h
 * @author
 * @version
 * @date
 * @brief     Application configuration and interrupt vector definitions.
 ******************************************************************************/
#ifndef __APPCONFIG_H
#define __APPCONFIG_H

/***************************************************************************//*!
 * @brief   Reserve trace buffer in RAM for Micro Trace Buffer (MTB) trace
 *          capabilities.
 * @param   MTB_RAM_RESERVE - this define reserves trace buffer in RAM for use
 *          by Micro Trace Buffer (MTB). The trace buffer starts at 0x1FFFF000
 *          and it has size of 64-bytes. You can modify size of the trace buffer
 *          for example to 256-bytes by the following definition:
 *          #define MTB_RAM_SIZE 0x100
 * @note    Tracing capabilities reduces performance of the application.
 ******************************************************************************/
//#define MTB_RAM_RESERVE

/***************************************************************************//*!
 * @brief   Modify default boot options. The boot options allows the MCU to
 *          modify default operations from NVM at reset.
 *          Supported options:
 * @param   BOOT_FLASH_SECURE - MCU Secured (MCU is unsecured by default; secure
 *                              command is blocked in IAR 6.40.2 flash loader)
 * @param   BOOT_DIV_CLK_BY_8 - Divide clock by 8 (MCU boots up with system clock
 *                              divide by 1 by default).
 * @param   BOOT_NMI_DISABLE  - Disable NMI (NMI is enabled by default)
 * @param   BOOT_EXT_CLK      - Device uses external slower clock for flash
 *                              calibration after reset. Internal 25 MHz flash
 *                              clock is disabled.
 * @param   BOOT_HWVLPR_MODE  - Device boots in VLPR mode starting next VDD power
 *                              cycle provided VBAT power is retained (forced by HW).
 * @param   BOOT_SWVLPR_MODE  - Device boots in RUN mode however device enters
 *                              VLPR by first software instructions of the device
 *                              startup (forced by SW).
 * @note    If neither BOOT_EXE_MODE, BOOT_VLPR_MODE nor BOOT_EXT_FLASH_CLK
 *          constants are defined then device boots in default mode which is RUN
 *          mode with internal 25 MHz clock enabled and used for flash calibration.
 ******************************************************************************/
#define BOOT_NMI_DISABLE

/***************************************************************************//*!
 * @brief   Define specific peripheral configuration structures.
 * @example
 *          #define PIT_CH_CONFIG                                              \
 *          (tPIT_CH){                                                         \
 *            SET(PIT_TCTRL_TIE_MASK)|SET(PIT_TCTRL_TEN_MASK),                 \
 *          }
 ******************************************************************************/

/******************************************************************************/
#endif /* __APPCONFIG_ */
