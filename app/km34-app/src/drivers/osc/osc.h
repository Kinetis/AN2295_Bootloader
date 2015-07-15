/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      osc.h
 * @version   1.0.1.0
 * @date      May-14-2012
 * @brief     System Oscillator (OSC) driver header file.
 ******************************************************************************/
#ifndef __OSC_H
#define __OSC_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 CR; } tOSC;

/******************************************************************************
* OSC load capacitors definitions used by OSC_Init() function
*
*//*! @addtogroup osc_load_caps
* @{
*******************************************************************************/
#define OSC_SC16P (uint8)0x01   ///< Add 16 pF capacitor to the oscillator load
#define OSC_SC8P  (uint8)0x02   ///< Add 08 pF capacitor to the oscillator load
#define OSC_SC4P  (uint8)0x04   ///< Add 04 pF capacitor to the oscillator load
#define OSC_SC2P  (uint8)0x08   ///< Add 02 pF capacitor to the oscillator load
#define OSC_SC0P  (uint8)0x00   ///< No internal load capacitor applied
/*! @} End of osc_load_caps                                                   */

/******************************************************************************
* OSC default configurations used by OSC_Init() function
*
*//*! @addtogroup osc_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Disables external reference clock (OSCERCLK).
 * @details Disables external reference clock (OSCERCLK). Configuration options:
 * - External reference (OSCERCLK) clock is inactive.
 * - External reference (OSCERCLK) is disabled in Stop mode.
 * - No load capacitors applied.
 * @showinitializer
 ******************************************************************************/
#define OSC_MODULE_OSCERCLK_OFF_STOPMODE_OFF_CONFIG                           \
(tOSC){                                                                       \
/* CR */ CLR(OSC_CR_ERCLKEN_MASK)|CLR(OSC_CR_EREFSTEN_MASK)                   \
}

/***************************************************************************//*!
 * @brief   Enables external reference clock (OSCERCLK). The OSCERCLK is
 *          disabled in STOP mode.
 * @details Enables external reference clock (OSCERCLK). The OSCERCLK is
 *          disabled in STOP mode. Configuration options:
 * - External reference (OSCERCLK) clock is active.
 * - External reference (OSCERCLK) is disabled in Stop mode.
 * @param   caps  Select one or more OR'ed @ref osc_load_caps.
 * @showinitializer
 ******************************************************************************/
#define OSC_MODULE_OSCERCLK_ON_STOPMODE_OFF_CONFIG(caps)                      \
(tOSC){                                                                       \
/* CR */ SET(OSC_CR_ERCLKEN_MASK)|CLR(OSC_CR_EREFSTEN_MASK)|(caps)            \
}

/***************************************************************************//*!
 * @brief   Enables external reference clock (OSCERCLK). The OSCERCLK is enabled
 *          in STOP mode.
 * @details Enables external reference clock (OSCERCLK). The OSCERCLK is enabled
 *          in STOP mode. Configuration options:
 * - External reference (OSCERCLK) clock is active.
 * - External reference (OSCERCLK) is enabled in Stop mode.
 * @param   caps  Select one or more OR'ed @ref osc_load_caps.
 * @showinitializer
 ******************************************************************************/
#define OSC_MODULE_OSCERCLK_ON_STOPMODE_ON_CONFIG(caps)                       \
(tOSC){                                                                       \
/* CR */ SET(OSC_CR_ERCLKEN_MASK)|SET(OSC_CR_EREFSTEN_MASK)|(caps)            \
}
/*! @} End of osc_config                                                      */

/******************************************************************************
*OSC function and macro definitions
*
*//*! @addtogroup osc_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   System oscillator initialization.
 * @details This macro initializes system oscillator (OSC) module.
 * @param   cfg   Select one of the @ref osc_config.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
 #define OSC_Init(cfg)          OSC_CR = cfg.CR
/*! @} End of osc_macro                                                       */

#endif /* __OSC_H */