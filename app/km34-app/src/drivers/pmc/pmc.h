/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pmc.h
 * @version   1.0.4.0
 * @date      Jan-27-2015
 * @brief     Power Management Controller (PMC) driver header file.
 ******************************************************************************/
#ifndef __PMC_H
#define __PMC_H

/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint8 LVDSC1, LVDSC2; } tLVD;
typedef struct { uint8 REGSC; } tREG;

/***************************************************************************//*!
 *//*! @addtogroup pmc_lvdv
 * @{
 ******************************************************************************/
#define PMC_LVDL (uint8)0 ///< Falling low-voltage detect low range (1.6 V).
#define PMC_LVDH (uint8)1 ///< Falling low-voltage detect high range (2.56 V).
/*! @} End of pmc_lvdv                                                        */

/***************************************************************************//*!
 *//*! @addtogroup pmc_lvwv
 * @{
 ******************************************************************************/
#define PMC_LVW1 (uint8)0 ///< Low trip point is 2.7 V if PMC_LVDH (low-voltage
                          ///  detect high range) selected otherwise it is 1.8 V.
#define PMC_LVW2 (uint8)1 ///< Mid1 trip point is 2.8 V if PMC_LVDH (low-voltage
                          ///  detect high range) selected otherwise it is 1.9 V.
#define PMC_LVW3 (uint8)2 ///< Mid2 trip point is 2.9 V if PMC_LVDH (low-voltage
                          ///  detect high range) selected otherwise it is 2.0 V.
#define PMC_LVW4 (uint8)3 ///< High trip point is 3.0 V if PMC_LVDH (low-voltage
                          ///  detect high range) selected otherwise it is 2.1 V.
/*! @} End of pmc_lvwv                                                        */

/******************************************************************************
* PMC configuration used by PMC_init() function
*
*//*! @addtogroup pmc_module_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Configures PMC with LVDRE, LVDINT, and LVWINT disabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Disabled (use polling).
 *  - Low-Voltage Detect Reset Disabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Disabled (use polling).
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_OFF_LVDINT_OFF_LVWINT_OFF_CONFIG(lvdv,lvwv)          \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|CLR(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  CLR(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|CLR(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}

/***************************************************************************//*!
 * @brief Configures PMC with LVDRE and LVDINT disabled but LVWINT enabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Disabled (use polling).
 *  - Low-Voltage Detect Reset Disabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Enabled.
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_OFF_LVDINT_OFF_LVWINT_ON_CONFIG(lvdv,lvwv)           \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|CLR(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  CLR(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|SET(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}

/***************************************************************************//*!
 * @brief Configures PMC with LVDRE and LVWINT disabled but LVDINT enabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Enabled.
 *  - Low-Voltage Detect Reset Disabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Disabled (use polling).
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_OFF_LVDINT_ON_LVWINT_OFF_CONFIG(lvdv,lvwv)           \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|SET(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  CLR(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|CLR(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}

/***************************************************************************//*!
 * @brief Configures PMC with LVDRE disabled but LVDINT and LVWINT enabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Enabled.
 *  - Low-Voltage Detect Reset Disabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Enabled.
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_OFF_LVDINT_ON_LVWINT_ON_CONFIG(lvdv,lvwv)            \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|SET(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  CLR(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|SET(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}

/***************************************************************************//*!
 * @brief Configures PMC with LVDRE enabled but LVDINT and LVWINT disabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Disabled (use polling).
 *  - Low-Voltage Detect Reset Enabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Disabled (use polling).
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_ON_LVDINT_OFF_LVWINT_OFF_CONFIG(lvdv,lvwv)           \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|CLR(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|CLR(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}

/***************************************************************************//*!
 * @brief Configures PMC with LVDRE and LVWINT enabled but LVDINT disabled.
 * @details Configures PMC block to operate with the following characteristics:
 *  - Low-Voltage Detect Interrupt Disabled (use polling).
 *  - Low-Voltage Detect Reset Enabled.
 *  - Low-Voltage Detect Voltage Selected by <c>lvdv</c> input argument.
 *  - Low-Voltage Warning Interrupt Enabled.
 *  - Low-Voltage Warning Voltage Selected by <c>lvwv</c> input argument.
 * @param   lvdv  Select one of the @ref pmc_lvdv.
 * @param   lvwv  Select one of the @ref pmc_lvwv.
 * @showinitializer
 ******************************************************************************/
#define PMC_MODULE_LVDRE_ON_LVDINT_OFF_LVWINT_ON_CONFIG(lvdv,lvwv)            \
(tLVD){                                                                       \
/* LVDSC1 */  SET(PMC_LVDSC1_LVDACK_MASK)|CLR(PMC_LVDSC1_LVDIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC1_LVDRE_MASK)|SET(PMC_LVDSC1_LVDV(lvdv)),          \
/* LVDSC2 */  SET(PMC_LVDSC2_LVWACK_MASK)|SET(PMC_LVDSC2_LVWIE_MASK)|         \
/* ...... */  SET(PMC_LVDSC2_LVWV(lvwv))                                      \
}
/*! @} End of pmc_module_config                                               */

/******************************************************************************
* PMC's internal regulator configuration used by PMC_init() function
*
*//*! @addtogroup pmc_intreg_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Bandgap voltage reference is disabled in VLPx and VLLSx modes.
 * Bandgap buffer is disabled.
 * @details Configures internal regulator of the PMC block to operate with:
 *  - Bandgap voltage reference is disabled in VLPx and VLLSx modes.
 *  - Bandgap buffer disabled.
 *  - ACKISO flag cleared (use @ref PMC_SetACKISO macro to release I/O held state).
 * @showinitializer
 ******************************************************************************/
#define PMC_INTREG_BGEN_OFF_BGBE_OFF_CONFIG                                   \
(tREG){                                                                       \
/* REGSC  */  CLR(PMC_REGSC_BGEN_MASK)|CLR(PMC_REGSC_ACKISO_MASK)|            \
/* .....  */  CLR(PMC_REGSC_BGBE_MASK)                                        \
}

/***************************************************************************//*!
 * @brief Bandgap voltage reference is enabled in VLPx and VLLSx modes.
 * Bandgap buffer is disabled.
 * @details Configures internal regulator of the PMC block to operate with:
 *  - Bandgap voltage reference is enabled in VLPx and VLLSx modes.
 *  - Bandgap buffer disabled.
 *  - ACKISO flag cleared (use @ref PMC_SetACKISO macro to release I/O held state).
 * @showinitializer
 ******************************************************************************/
#define PMC_INTREG_BGEN_ON_BGBE_OFF_CONFIG                                    \
(tREG){                                                                       \
/* REGSC  */  SET(PMC_REGSC_BGEN_MASK)|CLR(PMC_REGSC_ACKISO_MASK)|            \
/* .....  */  CLR(PMC_REGSC_BGBE_MASK)                                        \
}

/***************************************************************************//*!
 * @brief Bandgap voltage reference is enabled in VLPx and VLLSx modes.
 * @details Configures internal regulator of the PMC block to operate with:
 *  - Bandgap voltage reference is enabled in VLPx and VLLSx modes.
 *  - Bandgap buffer enabled.
 *  - ACKISO flag cleared (use @ref PMC_SetACKISO macro to release I/O held state).
 * @showinitializer
 ******************************************************************************/
#define PMC_INTREG_BGEN_ON_BGBE_ON_CONFIG                                     \
(tREG){                                                                       \
/* REGSC  */  SET(PMC_REGSC_BGEN_MASK)|CLR(PMC_REGSC_ACKISO_MASK)|            \
/* .....  */  SET(PMC_REGSC_BGBE_MASK)                                        \
}
/*! @} End of pmc_intreg_config                                               */

/******************************************************************************
* PMC callback registered by PMC_Init() function
*
*//*! @addtogroup pmc_callback
* @{
*******************************************************************************/
/*! @brief PMC_CALLBACK type declaration                                      */
typedef enum
{
  LVD_CALLBACK = 1,       ///< LVD interrupt
  LVW_CALLBACK = 2        ///< LVW interrupt
} PMC_CALLBACK_TYPE;

/*! @brief PMC_CALLBACK function declaration                                  */
typedef void (*PMC_CALLBACK)(PMC_CALLBACK_TYPE type);
/*! @} End of pmc_callback                                                    */

/******************************************************************************
* PMC function and macro definitions
*
*//*! @addtogroup pmc_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns LVDF status.
 * @details This macro returns LVDF status.
 * @return  true (non-zero) internal supply voltage falls below the selected
 *                          internal monitor trip point (VLVD),
 * @return  false           normal operation.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define PMC_GetLVDF()       (PMC_LVDSC1 & PMC_LVDSC1_LVDF_MASK)

/***************************************************************************//*!
 * @brief   Returns LVWF status.
 * @details This macro returns LVWF status.
 * @return  true (non-zero) internal supply voltage falls below the selected
 *                          internal monitor trip point (VLVW),
 * @return  false           normal operation.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define PMC_GetLVWF()       (PMC_LVDSC2 & PMC_LVDSC2_LVWF_MASK)

/***************************************************************************//*!
 * @brief   Returns regulator status.
 * @details This macro returns regulator status (PMC_REGSC_REGSON).
 * @return  true (non-zero) regulator is in stop regulation or in transition
 *                          to/from it,
 * @return  false           regulator is in run regulation.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define PMC_GetREGONS()     (PMC_REGSC & PMC_REGSC_REGONS_MASK)

/***************************************************************************//*!
 * @brief   Returns state indicating whether certain peripherals and the
 *          I/O pads are in a latched state.
 * @details This macro returns state indicating whether certain peripherals and
 *          the I/O pads are in a latched state as a result of having been in a
 *          VLLS mode. Writing one to this bit when it is set releases the
 *          I/O pads and certain peripherals to their normal run mode state.
 * @return  true (non-zero) peripherals and I/O pads are in an isolated and
 *                          latched state,
 * @return  false           peripherals and I/O pads are in normal run state.
 * @note    Implemented as an inline macro.
 * @see     @ref PMC_SetACKISO
 ******************************************************************************/
#define PMC_GetACKISO()      (PMC_REGSC & PMC_REGSC_ACKISO_MASK)

/***************************************************************************//*!
 * @brief   Releases I/O held state.
 * @details This macro releases I/O held state (the I/O states are held on a
 *          wakeup event until the wakeup has been acknowledged via a write to
 *          ACKISO bit).
 * @note    Implemented as an inline macro.
 * @see     @ref PMC_GetACKISO
 ******************************************************************************/
#define PMC_SetACKISO()       iosetb (PMC_REGSC,PMC_REGSC_ACKISO_MASK)

/***************************************************************************//*!
 * @brief   Enables bandgap reference in VLPx and VLLSx modes.
 * @details This macro enables bandgap reference in VLPx and VLLSx modes.
 * @note    Implemented as an inline macro.
 * @see     @ref PMC_ClrBGEN
 ******************************************************************************/
#define PMC_SetBGEN()         iosetb (PMC_REGSC,PMC_REGSC_BGEN_MASK)

/***************************************************************************//*!
 * @brief   Disables bandgap reference in VLPx and VLLSx modes.
 * @details This macro disables bandgap reference in VLPx and VLLSx modes.
 * @note    Implemented as an inline macro.
 * @see     @ref PMC_SetBGEN
 ******************************************************************************/
#define PMC_ClrBGEN()         ioclrb (PMC_REGSC,PMC_REGSC_BGEN_MASK)

/***************************************************************************//*!
 * @brief   Enables bandgap buffer.
 * @details This macro enables bandgap buffer.
 * @note    Implemented as an inline macro.
 * @warning Enable bandgap buffer if you want to measure bandgap voltage by ADC
 *          or using 1.0V Internal bandgap as the ADC reference.
 * @see     @ref PMC_ClrBGBE
 ******************************************************************************/
#define PMC_SetBGBE()         iosetb (PMC_REGSC,PMC_REGSC_BGBE_MASK)

/***************************************************************************//*!
 * @brief   Disables bandgap buffer.
 * @details This macro disables bandgap buffer.
 * @note    Implemented as an inline macro. This function also switches bandgap
 *          buffer to low drive mode.
 * @see     @ref PMC_SetBGBE
 ******************************************************************************/
#define PMC_ClrBGBE()         ioclrb (PMC_REGSC,PMC_REGSC_BGBE_MASK)

/***************************************************************************//*!
 * @brief   PMC initialization.
 * @details This function initializes Power Management Controller (PMC) block.
 *          Function installs callback function for interrupt vector 22 (PMC).
 * @param   cfg1      Select one of the @ref pmc_module_config.
 * @param   cfg2      Select one of the @ref pmc_intreg_config.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref pmc_callback.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define PMC_Init(cfg1,cfg2,ip,callback)   PMC_Init(cfg1,cfg2,ip,callback)
/*! @} End of pmc_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void PMC_Init (tLVD lvd, tREG reg, uint8 ip, PMC_CALLBACK pCallback);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void pmc_isr (void);

#endif /* __PMC_H */