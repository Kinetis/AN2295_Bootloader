/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      common.h
 * @version   1.0.2.0
 * @date      May-05-2015
 * @brief     Header file.
 ******************************************************************************/
#ifndef __COMMON_H
#define __COMMON_H

/******************************************************************************
 * List of the basic configuration structure macros
 *
 *//*! @addtogroup config_struct_macros
 * @{
 ******************************************************************************/
/***************************************************************************//*!
 * @brief   Sets register field in peripheral configuration structure.
 * @details This macro sets register field <c>mask</c> in the peripheral
 *          configuration structure.
 * @param   mask  Register field to be set.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SET(mask)   (mask)

/***************************************************************************//*!
 * @brief   Clears register field in peripheral configuration structure.
 * @details This macro clears register field <c>mask</c> in the peripheral
 *          configuration structure.
 * @param   mask  Register field to be cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define CLR(mask)   0
/*! @} End of config_struct_macros                                            */

/******************************************************************************
 * channel mask definition used by various drivers.
 *
 *//*! @addtogroup channel_mask
 * @{
 ******************************************************************************/
#define CH0   (1 << 0)  ///< Channel 0
#define CH1   (1 << 1)  ///< Channel 1
#define CH2   (1 << 2)  ///< Channel 2
#define CH3   (1 << 3)  ///< Channel 3
/*! @} End of channel_mask                                                    */

/******************************************************************************
 * Definition of common aliases                                               *
 ******************************************************************************/
#if defined(__ICCARM__) || defined(__CC_ARM)
  #define weak  __weak
#elif defined(__GNUC__)
  #define weak  __attribute__((weak))
#endif

/******************************************************************************
 * Toolchain check                                                            *
 ******************************************************************************/
#if !defined(__ICCARM__) && !defined(__GNUC__) && !defined(__CC_ARM)
  #error "Toolchain is not supported."
#endif

/******************************************************************************
 * Include common header file                                                 *
 ******************************************************************************/
#include "types.h"              /* Basic data types and conversion macros     */
#include "appconfig.h"          /* User configuration structures              */
#include "headers/MKM34ZA5.h"   /* Device header file                         */
#include "arm_cm0.h"            /* ARM CM0+ macros and definitions            */
#include "iohw.h"               /* Bit Manipulation Engine (BME) macros       */
#include "startup.h"            /* startup() function prototype               */
#include "arch_delay.h"         /* arch_delay() function prototype            */

#endif /* __COMMON_H */