/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      fll.h
 * @version   1.0.5.0
 * @date      Jan-05-2014
 * @brief     Frequency-Locked Loop (FLL) driver header file.
 ******************************************************************************/
#ifndef __FLL_H
#define __FLL_H

#if !defined(MCU_MKM34ZA5)
  #error "The fll.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 C1, C2, C4, C6, SC, C7, C8; } tFLL;

/******************************************************************************
* FLL Fast IRC clock divider definitions. Note: Changing the divider when the
* Fast IRC is enabled is not supported
*
*//*! @addtogroup firc_div_list
* @{
*******************************************************************************/
#define FIRC_DIV1      (uint8)0x00    ///< Divide factor is 1
#define FIRC_DIV2      (uint8)0x01    ///< Divide factor is 2 (default)
#define FIRC_DIV4      (uint8)0x02    ///< Divide factor is 4
#define FIRC_DIV8      (uint8)0x03    ///< Divide factor is 8
#define FIRC_DIV16     (uint8)0x04    ///< Divide factor is 16
#define FIRC_DIV32     (uint8)0x05    ///< Divide factor is 32
#define FIRC_DIV64     (uint8)0x06    ///< Divide factor is 64
#define FIRC_DIV128    (uint8)0x07    ///< Divide factor is 128
/*! @} End of firc_div_list                                                   */

/******************************************************************************
* FLL External Reference Divider.
*
*//*! @addtogroup fref_div_list
* @{
*******************************************************************************/
#define FREF_DIV1      (uint8)0x00    ///< Divide factor is 1
#define FREF_DIV2      (uint8)0x01    ///< Divide factor is 2
#define FREF_DIV4      (uint8)0x02    ///< Divide factor is 4
#define FREF_DIV8      (uint8)0x03    ///< Divide factor is 8
#define FREF_DIV16     (uint8)0x04    ///< Divide factor is 16
#define FREF_DIV32     (uint8)0x05    ///< Divide factor is 32
#define FREF_DIV64     (uint8)0x06    ///< Divide factor is 64
#define FREF_DIV128    (uint8)0x07    ///< Divide factor is 128
#define FREF_DIV256    (uint8)0x13    ///< Divide factor is 256
#define FREF_DIV512    (uint8)0x14    ///< Divide factor is 512
#define FREF_DIV1024   (uint8)0x15    ///< Divide factor is 1024
#define FREF_DIV1280   (uint8)0x16    ///< Divide factor is 1280
#define FREF_DIV1536   (uint8)0x17    ///< Divide factor is 1536
/*! @} End of fref_div_list                                                   */

/******************************************************************************
* Clock source definition for IRC.
*
*//*! @addtogroup irc_src_list
* @{
*******************************************************************************/
#define SLOWCLK_SRC    (uint8)0x00    ///< slow clock (32 KHz IRC)
#define FASTCLK_SRC    (uint8)0x01    ///< fast clock (4MHz IRC); use
                                      ///  @ref FLL_SetFastClkDiv macro to scale
                                      ///  down 4MHz IRC frequency.
/*! @} End of irc_src_list                                                    */

/******************************************************************************
* FLL module default configurations used by FLL_Init() function.
*
*//*! @addtogroup fll_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   FLL Engaged Internal (DCO Range: 20-25 MHz). FLL clocked by
 *          32 KHz Internal Reference Clock.
 * @details FLL Engaged Internal (DCO Range: 20-25 MHz). FLL clocked by
 *          32 KHz Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEI_20_25MHZ_CONFIG                                        \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Engaged Internal (DCO Range: 40-50 MHz). FLL clocked by
 *          32 KHz Internal Reference Clock.
 * @details FLL Engaged Internal (DCO Range: 40-50 MHz). FLL clocked by
 *          32 KHz Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEI_40_50MHZ_CONFIG                                        \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x01)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}


/***************************************************************************//*!
 * @brief   FLL Engaged External (DCO Range: 24 MHz). FLL clocked by 32 KHz RTC
 *          Oscillator Clock Source (32.768KHz external crystal).
 * @details FLL Engaged External (DCO Range: 24 MHz). FLL clocked by 32 KHz RTC
 *          Oscillator Clock Source (32.768KHz external crystal).
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEE_24MHZ_CONFIG                                           \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ SET(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|SET(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Engaged External (DCO Range: 48 MHz). FLL clocked by 32 KHz RTC
 *          Oscillator Clock Source (32.768KHz external crystal).
 * @details FLL Engaged External (DCO Range: 48 MHz). FLL clocked by 32 KHz RTC
 *          Oscillator Clock Source (32.768KHz external crystal).
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEE_48MHZ_CONFIG                                           \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ SET(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x01)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|SET(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}


/***************************************************************************//*!
 * @brief   FLL Bypassed Internal (32KHz). Clocked by Slow Internal Reference Clock.
 * @details FLL Bypassed Internal (32KHz). Clocked by Slow Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FBI_32KHZ_CONFIG                                           \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Internal (2MHz). Clocked by Fast Internal Reference Clock.
 * @details FLL Bypassed Internal (2MHz). Clocked by Fast Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FBI_2MHZ_CONFIG                                            \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Internal (4MHz). Clocked by Fast Internal Reference Clock.
 * @details FLL Bypassed Internal (4MHz). Clocked by Fast Internal Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FBI_4MHZ_CONFIG                                            \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed External (32.768KHz). Clocked by Slow External Reference
 *          Clock from OSC32K Oscillator.
 * @details FLL Bypassed External (32.768KHz). Clocked by Slow External Reference
 *          Clock from OSC32K Oscillator.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FBE_OSC32K_CONFIG                                          \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x02))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|SET(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed External (8.0MHz Crystal). Clocked by System Oscillator
 *          External Reference Clock.
 * @details FLL Bypassed External (8.0MHz Crystal). Clocked by System Oscillator
 *          External Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FBE_8MHZ_OSC_CONFIG                                        \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x02))|SET(MCG_C1_FRDIV(0x03))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|SET(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Low Power Internal (32KHz). Clocked by Slow Internal
 *          Reference Clock.
 * @details FLL Bypassed Low Power Internal (32KHz). Clocked by Slow Internal
 *          Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_BLPI_32KHZ_CONFIG                                          \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|SET(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Low Power Internal (2MHz). Clocked by Fast Internal
 *          Reference Clock.
 * @details FLL Bypassed Low Power Internal (2MHz). Clocked by Fast Internal
 *          Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_BLPI_2MHZ_CONFIG                                           \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|SET(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Low Power Internal (4MHz). Clocked by Fast Internal
 *          Reference Clock.
 * @details FLL Bypassed Low Power Internal (4MHz). Clocked by Fast Internal
 *          Reference Clock.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_BLPI_4MHZ_CONFIG                                           \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x01))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ SET(MCG_C1_IREFS_MASK)|SET(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ SET(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|SET(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x00)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Low Power External (32.768KHz). Clocked by Slow External
 *          Reference Clock from OSC32K Oscillator.
 * @details FLL Bypassed Low Power External (32.768KHz). Clocked by Slow External
 *          Reference Clock from OSC32K Oscillator.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_BLPE_OSC32K_CONFIG                                         \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x02))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x00))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ CLR(MCG_C2_EREFS0_MASK)|SET(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|SET(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Bypassed Low Power External. Clocked by System Oscillator External
 *          Reference Clock with Frequency Range 1.0 - 50 MHz.
 * @details FLL Bypassed Low Power External. Clocked by System Oscillator External
 *          Reference Clock with Frequency Range 1.0 - 50 MHz.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_BLPE_OSC_CONFIG                                            \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x02))|SET(MCG_C1_FRDIV(0x00))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|CLR(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|SET(MCG_C2_LP_MASK)|CLR(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Engaged External (DCO Range: 20 - 25 MHz). Clocked by System
 *          Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @details FLL Engaged External (DCO Range: 20 - 25 MHz). Clocked by System
 *          Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEE_20_25MHZ_DIV256_OSC_CONFIG                             \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x03))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|SET(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x00)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/***************************************************************************//*!
 * @brief   FLL Engaged External (DCO Range: 40 - 50 MHz). Clocked by System
 *          Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @details FLL Engaged External (DCO Range: 40 - 50 MHz). Clocked by System
 *          Oscillator Clock with Frequency Range 8.0 - 10.0 MHz.
 * @showinitializer
 ******************************************************************************/
#define FLL_MODULE_FEE_40_50MHZ_DIV256_OSC_CONFIG                             \
(tFLL){                                                                       \
/* C1 */ SET(MCG_C1_CLKS(0x00))|SET(MCG_C1_FRDIV(0x03))|                      \
/* .. */ CLR(MCG_C1_IREFS_MASK)|CLR(MCG_C1_IRCLKEN_MASK)|                     \
/* .. */ CLR(MCG_C1_IREFSTEN_MASK),                                           \
/* C2 */ SET(MCG_C2_LOCRE0_MASK)|SET(MCG_C2_RANGE0(0x02))|SET(MCG_C2_HGO0_MASK)|\
/* .. */ SET(MCG_C2_EREFS0_MASK)|CLR(MCG_C2_LP_MASK)|SET(MCG_C2_IRCS_MASK),   \
/* C4 */ CLR(MCG_C4_DMX32_MASK)|SET(MCG_C4_DRST_DRS(0x01)),                   \
/* C6 */ CLR(MCG_C6_LOLIE0_MASK)|CLR(MCG_C6_PLLS_MASK)|CLR(MCG_C6_CME0_MASK)| \
/* .. */ SET(MCG_C6_CHGPMP_BIAS(0x08)),                                       \
/* SC */ CLR(MCG_SC_ATME_MASK)|CLR(MCG_SC_ATMS_MASK)|                         \
/* .. */ CLR(MCG_SC_FLTPRSRV_MASK)|SET(MCG_SC_FCRDIV(0x01)),                  \
/* C7 */ SET(MCG_C7_PLL32KREFSEL(0))|CLR(MCG_C7_OSCSEL_MASK),                 \
/* C8 */ SET(MCG_C8_LOCRE1_MASK)|CLR(MCG_C8_LOLRE_MASK)|CLR(MCG_C8_CME1_MASK)|\
/* .. */ CLR(MCG_C8_COARSE_LOLIE_MASK),                                       \
}

/*! @} End of fll_config                                                      */

/******************************************************************************
* FLL function and macro definitions
*
*//*! @addtogroup fll_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Sets slow clock trim value (SCTRIM and SCFTRIM bits).
 * @details This macro sets slow clock trim value (SCTRIM and SCFTRIM bits).
 *          Increasing the trim value increases the period, and decreasing
 *          the value decreases the period. Upon reset this value is loaded with
 *          a factory trim value.
 * @param   x   9-bit trim value in range from 0 to 511.
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_GetSlowClkTrimVal
 ******************************************************************************/
#define FLL_SetSlowClkTrimVal(x)                                              \
{                                                                             \
  MCG_C3 = (0xff & (x>>1));                                                   \
  iobfib (MCG_C4,MCG_C4_SCFTRIM_SHIFT,1,x);                                   \
}

/***************************************************************************//*!
 * @brief   Returns slow clock trim value (SCTRIM and SCFTRIM bits).
 * @details This macro returns slow clock trim value (SCTRIM and SCFTRIM bits).
 * @return  9-bit trim value in range from 0 to 511.
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_SetSlowClkTrimVal
 ******************************************************************************/
#define FLL_GetSlowClkTrimVal()     ((((uint16)MCG_C3)<<1)|(uint16)(MCG_C4&0x01))

/***************************************************************************//*!
 * @brief   Sets fast clock trim value (FCTRIM bits).
 * @details This macro sets slow fast clock trim value (FCTRIM bits). Increasing
 *          the trim value increases the period, and decreasing the value decreases
 *          the period. Upon reset this value is loaded with a factory trim value.
 * @param   x   4-bit trim value in range from 0 to 15.
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_GetFastClkTrimVal
 ******************************************************************************/
#define FLL_SetFastClkTrimVal(x)    iobfib (MCG_C4,MCG_C4_FCTRIM_SHIFT,4,x)

/***************************************************************************//*!
 * @brief   Returns fast clock trim value (FCTRIM bits).
 * @details This macro returns fast clock trim value (FCTRIM bits).
 * @return  4-bit trim value in range from 0 to 15.
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_SetFastClkTrimVal
 ******************************************************************************/
#define FLL_GetFastClkTrimVal()                                               \
                              ((MCG_C4&MCG_C4_FCTRIM_MASK)>>MCG_C4_FCTRIM_SHIFT)

/***************************************************************************//*!
 * @brief   Selects fast clock internal reference divider.
 * @details This macros select fast clock internal reference divider (FCRDIV).
 * @param   x   Select one of the @ref firc_div_list.
 * @note    Implemented as an inline macro.
 * @warning Fast clock internal reference divider must be selected before fast
 *          IRC is enabled.
 ******************************************************************************/
#define FLL_SetFastClkDiv(x)    iobfib (MCG_SC,MCG_SC_FCRDIV_SHIFT,3,x)

/***************************************************************************//*!
 * @brief   Selects FLL's external reference divider.
 * @details This macro select FLL's external reference divider (FRDIV) and
 *          frequency range select (RANGE0).
 * @param   x   Select one of the @ref fref_div_list.
 * @note    Implemented as an inline macro.
 * @warning Fast clock internal reference divider must be selected before fast
 *          IRC is enabled.
 ******************************************************************************/
#define FLL_SetExtRefDiv(x)                                                   \
{                                                                             \
  iobfib (MCG_C2,MCG_C2_RANGE0_SHIFT,2,(x>>4));                               \
  iobfib (MCG_C1,MCG_C1_FRDIV_SHIFT ,3,x);                                    \
}

/***************************************************************************//*!
 * @brief   Enables/disables internal reference clock for use as MCGIRCLK.
 * @details This macro enables/disables internal reference clock for use as
 *          MCGIRCLK.
 * @param   x   TRUE  (MCGIRCLK active)\n
 *              FALSE (MCGIRCLK inactive).
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_CtrlIREFSTEN
 ******************************************************************************/
#define FLL_CtrlIRCLKEN(x)        iobfib (MCG_C1,MCG_C1_IRCLKEN_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Enables/disables internal reference clock activity when the MCG
 *          enters Stop mode.
 * @details This macro enables/disables internal reference clock activity when
 *          the MCG enters Stop mode.
 * @param   x   TRUE  (Internal reference clock is enabled in Stop mode if IRCLKEN
 *                     is set or if MCG is in FEI, FBI, or BLPI modes before
 *                     entering Stop mode),
 *              FALSE (Internal reference clock is disabled in Stop mode).
 * @note    Implemented as an inline macro.
 * @see     @ref FLL_CtrlIRCLKEN
 ******************************************************************************/
#define FLL_CtrlIREFSTEN(x)       iobfib (MCG_C1,MCG_C1_IREFSTEN_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Enables/disables FLL activity in BLPI and BLPE modes.
 * @details This macro enables/disables FLL activity in BLPI and BLPE modes.
 * @param   x   TRUE  (FLL is disabled in bypass modes),
 *              FALSE (FLL is enabled in bypass modes).
 * @note    Implemented as an inline macro.
 * @warning In FBE or PBE modes, calling setting LP bit to 1 will transition
 *          the MCG into BLPE mode; in FBI mode, setting this bit to 1 will
 *          transition the MCG into BLPI mode. In any other MCG mode, LP bit has
 *          no affect.
 ******************************************************************************/
#define FLL_CtrlLP(x)             iobfib (MCG_C2,MCG_C2_LP_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Enables/disables external clock monitor.
 * @details This macros Enables/disables external clock monitor.
 * @param   x   TRUE (External clock monitor is disabled and generate a reset
 *                    request on loss of external clock),
 *              FALSE (External clock monitor is disabled).
 * @note    Implemented as an inline macro.
 * @warning The CME bit should only be set to a logic 1 when either the MCG is
 *          in an operational mode that uses the external clock (FEE, FBE, PEE,
 *          PBE, or BLPE) or the external reference is enabled. Whenever the
 *          CME bit is set to a logic 1, the value of the RANGE bits in the C2
 *          register should not be changed. CME bit should be set to a logic 0
 *          before the MCG enters Stop mode. Otherwise, a reset request may occur
 *          while in Stop mode. CME should also be set to a logic 0 before
 *          entering VLPR or VLPW power modes if the MCG is in BLPE mode.
 ******************************************************************************/
#define FLL_CtrlCME(x)            iobfib (MCG_C6,MCG_C6_CME0_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Selects IRCSCLK clock source.
 * @details This macro selects IRCSCLK clock source.
 * @param   x   Select one of the @ref irc_src_list.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define FLL_SelIRCSCLK(x)                                                     \
{                                                                             \
  iobfib (MCG_C2,MCG_C2_IRCS_SHIFT,1,x);                                      \
  while ((MCG_S & MCG_S_IRCST_MASK) != x);                                    \
}

/***************************************************************************//*!
 * @brief   FLL initialization.
 * @details This function initializes Frequency-locked Loop (FLL).
 * @param   cfg Select one of the @ref fll_config.
 * @note    Implemented as a function call.
 * @see     @ref PLL_Init
 ******************************************************************************/
#define FLL_Init(cfg)             FLL_Init(cfg)
/*! @} End of fll_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void FLL_Init (tFLL fll);

#endif /* __FLL_H */ 