/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      syst.h
 * @version   1.0.3.0
 * @date      Apr-22-2015
 * @brief     System Timer (SYST) driver header file.
 ******************************************************************************/
#ifndef __SYST_H
#define __SYST_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint32 CSR, RVR; } tSYST;

/******************************************************************************
* SYSTICK default configuration used by SYST_Init() function
*
*//*! @addtogroup syst_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Enables System Timer operation. The System Timer operates in a
 *          freerun 24-bit Timer mode. Timer is clocked by the system clock.
 * @details Enables System Timer operation. The System Timer operates in a
 *          freerun 24-bit Timer mode. Timer is clocked by the system clock.
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_FREERUN_TMR_DIV1_EN_CONFIG                                \
(tSYST){                                                                      \
/* CSR  */ SET(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ SET(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD(0x00FFFFFF)),                               \
}

/***************************************************************************//*!
 * @brief   Enables System Timer operation. The System Timer operates in a freerun
 *          24-bit Timer mode. Timer is clocked by the system clock divided by 16.
 * @details Enables System Timer operation. The System Timer operates in a freerun
 *          24-bit Timer mode. Timer is clocked by the system clock divided by 16.
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_FREERUN_TMR_DIV16_EN_CONFIG                               \
(tSYST){                                                                      \
/* CSR  */ SET(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ CLR(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD(0x00FFFFFF)),                               \
}

/***************************************************************************//*!
 * @brief   Enables System Timer operation. The System Timer operates in a reload
 *          mode. Timer is clocked by the system clock.
 * @details Enables System Timer operation. The System Timer operates in a reload
 *          mode. Timer is clocked by the system clock.
 * @param reload  Reload value in the range 0x00000001 to 0x00FFFFFF (24-bit).
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_RELOAD_TMR_DIV1_EN_CONFIG(reload)                         \
(tSYST){                                                                      \
/* CSR  */ SET(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ SET(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD((reload-1)&0x00FFFFFF)),                    \
}

/***************************************************************************//*!
 * @brief   Enables System Timer operation. The System Timer operates in a
 *          reload mode. Timer is clocked by the system clock divided by 16.
 * @details Enables System Timer operation. The System Timer operates in a
 *          reload mode. Timer is clocked by the system clock divided by 16.
 * @param reload  Reload value in the range 0x00000001 to 0x00FFFFFF (24-bit).
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_RELOAD_TMR_DIV16_EN_CONFIG(reload)                        \
(tSYST){                                                                      \
/* CSR  */ SET(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ CLR(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD((reload-1)&0x00FFFFFF)),                    \
}

/***************************************************************************//*!
 * @brief   Configures System Timer operation. The System Timer is configured in
 *          a freerun 24-bit Timer mode. Timer is clocked by the system clock.
 * @details Configures System Timer operation. The System Timer is configured in
 *          a freerun 24-bit Timer mode. Timer is clocked by the system clock.
 *          Call @ref SYST_Enable macro to enable System Timer operation.
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_FREERUN_TMR_DIV1_DI_CONFIG                                \
(tSYST){                                                                      \
/* CSR  */ CLR(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ SET(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD(0x00FFFFFF)),                               \
}

/***************************************************************************//*!
 * @brief   Configures System Timer operation. The System Timer is configured in
 *          a freerun 24-bit Timer mode. Timer is clocked by the system clock
 *          divided by 16.
 * @details Configures System Timer operation. The System Timer is configured in
 *          a freerun 24-bit Timer mode. Timer is clocked by the system clock
 *          divided by 16. Call @ref SYST_Enable macro to enable System Timer
 *          operation.
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_FREERUN_TMR_DIV16_DI_CONFIG                               \
(tSYST){                                                                      \
/* CSR  */ CLR(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ CLR(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD(0x00FFFFFF)),                               \
}

/***************************************************************************//*!
 * @brief   Configures System Timer operation. The System Timer is configured in
 *          a reload mode. Timer is clocked by the system clock.
 * @details Configures System Timer operation. The System Timer is configured in
 *          a reload mode. Timer is clocked by the system clock.
 *          Call @ref SYST_Enable macro to enable System Timer operation.
 * @param reload  Reload value in the range 0x00000001 to 0x00FFFFFF (24-bit).
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_RELOAD_TMR_DIV1_DI_CONFIG(reload)                         \
(tSYST){                                                                      \
/* CSR  */ CLR(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ SET(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD((reload-1)&0x00FFFFFF)),                    \
}

/***************************************************************************//*!
 * @brief   Configures System Timer operation. The System Timer is configured in
 *          a reload mode. Timer is clocked by the system clock divided by 16.
 * @details Configures System Timer operation. The System Timer is configured in
 *          a reload mode. Timer is clocked by the system clock divided by 16.
 *          Call @ref SYST_Enable macro to enable System Timer operation.
 * @param reload  Reload value in the range 0x00000001 to 0x00FFFFFF (24-bit).
 * @showinitializer
 ******************************************************************************/
#define SYST_MODULE_RELOAD_TMR_DIV16_DI_CONFIG(reload)                        \
(tSYST){                                                                      \
/* CSR  */ CLR(SysTick_CSR_ENABLE_MASK)|CLR(SysTick_CSR_TICKINT_MASK)|        \
/* ...  */ CLR(SysTick_CSR_CLKSOURCE_MASK),                                   \
/* RVR  */ SET(SysTick_RVR_RELOAD((reload-1)&0x00FFFFFF)),                    \
}
/*! @} End of syst_config                                                     */

/******************************************************************************
* SYST callback registered by SYST_Init() function
*
*//*! @addtogroup syst_callback
* @{
*******************************************************************************/
/*! @brief SYST_CALLBACK function declaration.
    @details This callback is called by the System Timer module counts down to
             zero.
*/
typedef void (*SYST_CALLBACK)(void);
/*! @} End of syst_callback                                                   */

/******************************************************************************
* SYSTICK function and macro definitions
*
*//*! @addtogroup syst_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns inverse value of the 24-bit System Timer counter.
 * @details This macro returns inverse value of the 24-bit System Timer counter.
 *          The value equals to number of system clock ticks elapsed since Timer
 *          operation resumes after clearing.
 * @return  @ref uint32 24-bit Timer current value.
 * @note    Implemented as an inline macro.
 * @see     @ref SYST_ClrCntrVal
 ******************************************************************************/
#define SYST_GetCntrVal()   (uint32)~(SYST_CVR|0xff000000)

/***************************************************************************//*!
 * @brief   Clears 24-bit System Timer current counter value.
 * @details This macro clears 24-bit System Timer current counter value.
 * @note    Implemented as an inline macro.
 * @see     @ref SYST_GetCntrVal
 ******************************************************************************/
#define SYST_ClrCntrVal()   SYST_CVR=0l

/***************************************************************************//*!
 * @brief   Enables operation of the System Timer.
 * @details This macro enables operation of the System Timer.
 * @note    Implemented as an inline macro.
 * @see     @ref SYST_Disable
 ******************************************************************************/
#define SYST_Enable()       SYST_CSR|=SysTick_CSR_ENABLE_MASK

/***************************************************************************//*!
 * @brief   Disables operation of the System Timer.
 * @details This macro disables operation of the System Timer.
 * @note    Implemented as an inline macro.
 * @see     @ref SYST_Enable
 ******************************************************************************/
#define SYST_Disable()      SYST_CSR&=~SysTick_CSR_ENABLE_MASK

/***************************************************************************//*!
 * @brief   System Timer initialization.
 * @details This function initializes System Timer module. Function also installs
 *          callback function for interrupt vector 15 (SysTick).
 * @param   cfg       Select one of @ref syst_config
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref syst_callback.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define SYST_Init(cfg,ip,callback)   SYST_Init(cfg,ip,callback)
/*! @} End of syst_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void SYST_Init (tSYST syst, uint8 ip, SYST_CALLBACK pCallback);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void syst_isr (void);

#endif /* __SYST_H */ 