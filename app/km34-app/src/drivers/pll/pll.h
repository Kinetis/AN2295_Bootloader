/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pll.h
 * @version   1.0.2.0
 * @date      Feb-24-2013
 * @brief     Phase-Locked Loop (PLL) driver header file.
 ******************************************************************************/
#ifndef __PLL_H
#define __PLL_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 C1, C2, C5, C6, SC, C7, C8; } tPLL;

/******************************************************************************
* PLL 32KHz Reference Clock Sources.
*
*//*! @addtogroup pll_src_list
* @{
*******************************************************************************/
#define PLL32KREF_SRC1      (uint8)0x00    ///< Selects 32 KHz RTC Oscillator.
#define PLL32KREF_SRC2      (uint8)0x01    ///< Selects 32 KHz IRC.
#define PLL32KREF_SRC3      (uint8)0x02    ///< Selects FLL FRDIV clock.
/*! @} End of pll_src_list                                                    */

/******************************************************************************
* PLL module default configurations used by PLL_Init() function.
*
*//*! @addtogroup pll_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief PLL Engaged Internal. PLL clocked by 32 KHz Internal Reference Clock.
 * @details PLL Engaged Internal. PLL clocked by 32 KHz Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEI_12MHZ_CONFIG                                           \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x01)),                                      \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External. PLL clocked by 32 KHz RTC Oscillator Clock
 * Source (32.768KHz external crystal).
 * @details PLL Engaged External. PLL clocked by 32 KHz RTC Oscillator Clock
 * Source (32.768KHz external crystal).
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_12_288MHZ_CONFIG                                       \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x00)),                                      \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 1.0 - 1.25 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 1.0 - 1.25 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV32_OSC_CONFIG                                       \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 2.0 - 2.5 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 2.0 - 2.5 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV64_OSC_CONFIG                                       \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x01))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 4.0 - 5.0 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 4.0 - 5.0 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV128_OSC_CONFIG                                      \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x02))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV256_OSC_CONFIG                                      \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x03))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 16.0 - 20.0 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 - 14.64 MHz). Clocked by
 * System Oscillator Clock with Frequency Range 16.0 - 20.0 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV512_OSC_CONFIG                                      \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x04))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief PLL Engaged External (VCO Range: 11.71 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 32 MHz.
 * @details PLL Engaged External (VCO Range: 11.71 MHz). Clocked by System
 * Oscillator Clock with Frequency Range 32 MHz.
 * @showinitializer
 ******************************************************************************/
#define PLL_MODULE_PEE_DIV1024_OSC_CONFIG                                     \
(tPLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x05))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C5 */ SET(MCG_C5_PLLCLKEN0_MASK)|SET(MCG_C5_PLLSTEN0_MASK),                \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|SET(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0x02))|CLR(MCG_C7_OSCSEL_MASK),              \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}
/*! @} End of pll_config                                                      */

/******************************************************************************
* PLL function and macro definitions
*
*//*! @addtogroup pll_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Selects PLL 32KHz reference clock and enables PLL module.
 * @details This macro selects PLL 32KHz reference clock and enables PLL module.
 *          PLL is enabled by setting PLLCLKEN0 bit.
 * @param   clk   Select one of the @ref pll_src_list.
 * @note    Implemented as an inline macro.
 * @warning FLL or PLL is enabled by this macro (LP bit is deasserted). The
 *          MCGPLLCLK is prevented from coming out of the MCG until it is
 *          enabled and S[LOCK0] is set.
 * @see     @ref PLL_Disable, @ref SIM_CtrlPLLVLP, @ref PLL_CtrlPLLSTEN
 ******************************************************************************/
#define PLL_Enable(clk)                                                       \
{                                                                             \
  ioclrb (MCG_C2,MCG_C2_LP_MASK);                                             \
  iobfib (MCG_C7,MCG_C7_PLL32KREFSEL_SHIFT,2,clk );                           \
  iosetb (MCG_C5,MCG_C5_PLLCLKEN0_MASK);                                      \
  while (!(MCG_S & MCG_S_LOCK0_MASK));    /* wait until S[LOCK0] is set */    \
}

/***************************************************************************//*!
 * @brief   Macro disables PLL module.
 * @details This macro disables PLL module by clearing PLLCLKEN0 bit.
 * @note    Implemented as an inline macro.
 * @see     @ref PLL_Enable
 ******************************************************************************/
#define PLL_Disable()         ioclrb (MCG_C5,MCG_C5_PLLCLKEN0_MASK)

/***************************************************************************//*!
 * @brief   Enable/disable PLL operation in normal Stop mode.
 * @details This macro enables/disables PLL operation during normal stop mode by
 *          setting/clearing PLLSTEN0 bit, respectively.
 * @param   x   TRUE  (MCGPLLCLK is enabled if system is in normal Stop mode)\n
 *              FALSE (MCGPLLCLK is disabled in any of the Stop modes).
 * @note    Implemented as an inline macro.
 * @warning In Low Power Stop mode, the PLL clock gets disabled even if PLL
 *          operation was enabled using this macro. In all other power modes
 *          PLLSTEN0 bit has no affect and does not enable the PLL operation.
 * @see     @ref PLL_Enable, @ref PLL_Init, @ref SIM_CtrlPLLVLP
 ******************************************************************************/
#define PLL_CtrlPLLSTEN(x)    iobfib (MCG_C5,MCG_C5_PLLSTEN0_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   PLL initialization.
 * @details This function initializes Phase-Locked Loop (PLL).
 * @param   cfg   Select one of the @ref pll_config.
 * @note    Implemented as a function call.
 * @see     @ref FLL_Init, @ref PLL_CtrlPLLSTEN, @ref SIM_CtrlPLLVLP
 ******************************************************************************/
#define PLL_Init(cfg)         PLL_Init(cfg)
/*! @} End of pll_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void PLL_Init (tPLL pll);

#endif /* __PLL_H */ 