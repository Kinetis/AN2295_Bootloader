/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      arch_delay.h
 * @version   1.0.1.0
 * @date      Aug-10-2012
 * @brief     Header file.
 ******************************************************************************/
#ifndef __ARCH_DELAY_H
#define __ARCH_DELAY_H

/******************************************************************************
* Cortex-M0+ function and macro definitions
*
*//*! @addtogroup cm0plus_macros
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Delays software execution by number of core clock cycles.
 * @details This function delays software execution by specified number of core
 *          clock cycles.
 * @param   ticks   @ref uint32 number of core clock cycles.
 * @note    Implemented as a function call.
 ******************************************************************************/
extern void arch_delay (long ticks);
/*! @} End of cm0plus_macros                                                  */

#endif /* __ARCH_DELAY_H */
