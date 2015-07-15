/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      lptmr.h
 * @version   1.0.4.0
 * @date      Jan-16-2015
 * @brief     Low-Power Timer (LPTMR) driver header file.
 ******************************************************************************/
#ifndef __LPTMR_H
#define __LPTMR_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint32 CSR, PSR; } tLPTMR;

/******************************************************************************
* LPTMR clock sources definitions used by configuration structures of LPTMR_Init()
* function
*
*//*! @addtogroup lptmr_clocks
* @{
*******************************************************************************/
#define LPTMR_MCGIRCLK  (uint32)0x00  ///< MCGIRCLK internal reference clock (not
                                      ///  available in low leakage power modes)
#define LPTMR_LPOCLK    (uint32)0x01  ///< Internal 1 KHz LPO clock.
#define LPTMR_OSCCLK32K (uint32)0x02  ///< Source selected in SIM_SOPT1[OSC32KSEL];
                                      ///  refer to @ref SIM_SelOsc32kClk
#define LPTMR_OSCERCLK  (uint32)0x03  ///< External clock (ERCLK) from the
                                      ///  Crystal Oscillator (XOSC)
/*! @} End of lptmr_clocks                                                    */

/******************************************************************************
* LPTMR default configurations used by LPTMR_Init() function
*
*//*! @addtogroup lptmr_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Timer mode selected and Timer operation is disabled after
 *          @ref LPTMR_Init() function call. Timer counts until TCF flag is set
 *          then counter is reset and counting starts again.
 * @details Timer mode selected and Timer operation is disabled after
 *          @ref LPTMR_Init() function call. Timer counts until TCF flag is set
 *          then counter is reset and counting starts again.
 * @param   presc     Input clock divider value in range from 0 up 15.
 *                    It divides Timer clock by factor \f$2^{(presc+1)}\f$.
 * @param   clksrc    Select one of the @ref lptmr_clocks.
 * @showinitializer
 ******************************************************************************/
#define LPTMR_MODULE_TMR_CNT_RST_ONTCF_MODE_CONFIG(presc,clksrc)              \
(tLPTMR){                                                                     \
/* CSR    */ SET(LPTMR_CSR_TIE_MASK)|SET(LPTMR_CSR_TPS(0))|                   \
/* ...    */ CLR(LPTMR_CSR_TPP_MASK)|CLR(LPTMR_CSR_TFC_MASK)|                 \
/* ...    */ CLR(LPTMR_CSR_TMS_MASK)|CLR(LPTMR_CSR_TEN_MASK),                 \
/* PSR    */ SET(LPTMR_PSR_PCS(clksrc))|SET(LPTMR_PSR_PRESCALE(presc))|       \
/* ...    */ CLR(LPTMR_PSR_PBYP_MASK)                                         \
}
/***************************************************************************//*!
 * @brief   Timer mode selected and Timer operation is disabled after
 *          @ref LPTMR_Init() function call. Timer counts in free running mode.
 * @details Timer mode selected and Timer operation is disabled after
 *          @ref LPTMR_Init() function call. Timer counts in free running mode.
 * @param   presc     Input clock divider value in range from 0 up 15.
 *                    It divides Timer clock by factor \f$2^{(presc+1)}\f$.
 * @param   clksrc    Select one of the @ref lptmr_clocks.
 * @showinitializer
 ******************************************************************************/
#define LPTMR_MODULE_TMR_FREERUN_MODE_CONFIG(presc,clksrc)                    \
(tLPTMR){                                                                     \
/* CSR    */ SET(LPTMR_CSR_TIE_MASK)|SET(LPTMR_CSR_TPS(0))|                   \
/* ...    */ CLR(LPTMR_CSR_TPP_MASK)|SET(LPTMR_CSR_TFC_MASK)|                 \
/* ...    */ CLR(LPTMR_CSR_TMS_MASK)|CLR(LPTMR_CSR_TEN_MASK),                 \
/* PSR    */ SET(LPTMR_PSR_PCS(clksrc))|SET(LPTMR_PSR_PRESCALE(presc))|       \
/* ...    */ CLR(LPTMR_PSR_PBYP_MASK)                                         \
}
/*! @} End of lptmr_config                                                    */

/******************************************************************************
* AFE callback registered by LPTMR_Init() function
*
*//*! @addtogroup lptmr_callback
* @{
*******************************************************************************/
/*! LPTMR_CALLBACK type declaration                                           */
typedef void (*LPTMR_CALLBACK)(void);
/*! @} End of lptmr_callback                                                  */

/******************************************************************************
* LPTMR function and macro definitions
*
*//*! @addtogroup lptmr_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Resumes Timer operation.
 * @details This macro enables operation of the Low-Power Timer (LPTMR) block.
 * @note    Implemented as an inline macro.
 * @see     @ref LPTMR_Disable
 ******************************************************************************/
#define LPTMR_Enable()          iosetw (LPTMR_CSR,LPTMR_CSR_TEN_MASK)

/***************************************************************************//*!
 * @brief   Stops Timer operation.
 * @details This macro terminates operation of the Low-Power Timer (LPTMR) block.
 * @note    Implemented as an inline macro.
 * @see     @ref LPTMR_Enable
 ******************************************************************************/
#define LPTMR_Disable()         ioclrw (LPTMR_CSR,LPTMR_CSR_TEN_MASK)

/***************************************************************************//*!
 * @brief   Resets counter of the running Timer.
 * @details This macro resets counter of the running Timer. After counter reset
 *          Timer continue in operation.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define LPTMR_Reset()          { LPTMR_Disable(); LPTMR_Enable();             }

/***************************************************************************//*!
 * @brief   Returns Timer counter value.
 * @details This macro returns current value of the LPTMR counter.
 * @return  @ref uint32 counter register value.
 * @note    Implemented as an inline function.
 * @warning When reading the CNR, the bus clock must be at least two times faster
 * than the rate at which the LPTMR counter is incrementing, otherwise incorrect
 * data may be returned.
 ******************************************************************************/
static inline uint16 LPTMR_ReadCnt (void) { LPTMR_CNR = 0; return(uint16)LPTMR_CNR; }

/***************************************************************************//*!
 * @brief   Returns Timer compare flag.
 * @details This macro returns Timer compare flag when Timer increments.
 * @return  true (non-zero) value of counter is equal to compare value,
 * @return  false           value of counter is not equal to compare value.
 * @note    Implemented as an inline macro.
 * @see     @ref LPTMR_ClrCmpFlag
 ******************************************************************************/
#define LPTMR_GetCmpFlag()      (LPTMR_CSR&LPTMR_CSR_TCF_MASK)

/***************************************************************************//*!
 * @brief   Clears Timer compare flag.
 * @details This macro clears Timer compare flag.
 * @note    Implemented as an inline macro.
 * @see     @ref LPTMR_GetCmpFlag
 ******************************************************************************/
#define LPTMR_ClrCmpFlag()      iosetw (LPTMR_CSR,LPTMR_CSR_TCF_MASK)

/***************************************************************************//*!
 * @brief   Sets compare register.
 * @details This macro sets new value into compare register.
 * @param   val       16-bit integer value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define LPTRM_SetCmpVal(val)    LPTMR_CMR = val

/***************************************************************************//*!
 * @brief   Installs callback function for LPTMR interrupt vector 46.
 * @details This function installs callback function for LPTMR interrupt vector 46.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref lptmr_callback.
 * @note    Implemented as a function call.
 * @see     @ref LPTMR_Init
 ******************************************************************************/
#define LPTMR_InstallCallback(ip,callback) LPTMR_InstallCallback(ip,callback)

/***************************************************************************//*!
 * @brief   LPTMR initialization.
 * @details This function initializes Low-Power Timer (LPTRM) block. Call
 *          @ref LPTMR_InstallCallback function to install callback function
 *          for LPTMR interrupt vector 46.
 * @param   cfg       Select one of the of @ref lptmr_config.
 * @param   val       16-bit integer compare register value (defines period of
 *                    the interrupt generation).
 * @note    Implemented as a function call.
 * @see     @ref LPTMR_InstallCallback
 ******************************************************************************/
#define LPTMR_Init(cfg,val)              LPTMR_Init(cfg,val)
/*! @} End of lptmr_macro                                                     */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void LPTMR_InstallCallback (uint8 ip, LPTMR_CALLBACK pCallback);
extern void LPTMR_Init  (tLPTMR lptmr, uint16 val);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void lptmr_isr (void);

#endif /* __LPTMR_H */