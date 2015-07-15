/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      cmp.h
 * @version   1.0.4.0
 * @date      Apr-21-2015
 * @brief     Analog comparator (CMP) driver header file.
 ******************************************************************************/
#ifndef __CMP_H
#define __CMP_H

#if !defined(MCU_MKM34ZA5)
  #error "The cmp.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 CR0, CR1, FPR, SCR, DACCR; } tCMP;

/******************************************************************************
* Analog channels definition for CMP for use with CMP_Init() macro.
*
*//*! @addtogroup cmp_channel
* @{
*******************************************************************************/
#define IN0          (uint8)0   ///< Channel 0
#define IN1          (uint8)1   ///< Channel 1
#define IN2          (uint8)2   ///< Channel 2
#define IN3          (uint8)3   ///< Channel 3
#define IN4          (uint8)4   ///< Channel 4
#define IN5          (uint8)5   ///< Channel 5
#define IN6          (uint8)6   ///< Channel 6 (Reserved for Test)
#define IN7_DAC      (uint8)7   ///< Channel 7 DAC
#define IN2_SDADP2   (uint8)2   ///< CMP1 channel 2 inter-connects to SDADP2
#define IN3_SDADM2   (uint8)3   ///< CMP1 channel 3 inter-connects to SDADM2
#define IN4_SDADP3   (uint8)4   ///< CMP1 channel 4 inter-connects to SDADP3
#define IN5_SDADM3   (uint8)5   ///< CMP1 channel 5 inter-connects to SDADM3
/*! @} End of cmp_channel                                                     */

/******************************************************************************
* Comparator default configurations used by CMP_init() function
*
*//*! @addtogroup cmp_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Comparator setting:
 * @details Comparator setting:
 * - module enable after initialization,
 * - filter enable 7 counts,
 * - hi speed mode,
 * - IRQ will be generated on rising edge if interrupt callback is installed
 *   using @ref CMP_InstallCallback function,
 * - DAC disable
 * @showinitializer
 ******************************************************************************/
#define CMP_MODULE_EN_FILTER7_SAMPLE_PER_255_DAC_DI_CONFIG                    \
(tCMP){                                                                       \
/* CR0    */  SET(CMP_CR0_FILTER_CNT(7)) |SET(CMP_CR0_HYSTCTR(0)),            \
/* CR1    */  CLR(CMP_CR1_SE_MASK)       |CLR(CMP_CR1_WE_MASK)|               \
/* ...    */  CLR(CMP_CR1_TRIGM_MASK)    |SET(CMP_CR1_PMODE_MASK)|            \
/* ...    */  CLR(CMP_CR1_INV_MASK)      |CLR(CMP_CR1_COS_MASK)|              \
/* ...    */  CLR(CMP_CR1_OPE_MASK)      |SET(CMP_CR1_EN_MASK),               \
/* FPR    */  SET(CMP_FPR_FILT_PER(0xFF)),                                    \
/* SCR    */  CLR(CMP_SCR_DMAEN_MASK)    |SET(CMP_SCR_IER_MASK)|              \
/* ...    */  CLR(CMP_SCR_IEF_MASK),                                          \
/* DACCR  */  CLR(CMP_DACCR_DACEN_MASK)  |CLR(CMP_DACCR_VRSEL_MASK)           \
}

/***************************************************************************//*!
 * @brief Comparator setting:
 * @details Comparator setting:
 * - module enable after initialization,
 * - filter enable 7 counts,
 * - hi speed mode,
 * - IRQ will be generated on rising edge if interrupt callback is installed
 *   using @ref CMP_InstallCallback function,
 * - DAC enable
 * @param   dac       DAC output voltage select from 0 to 63.
 * @showinitializer
 ******************************************************************************/
#define CMP_MODULE_EN_FILTER7_SAMPLE_PER_255_DAC_EN_CONFIG(dac)               \
(tCMP){                                                                       \
/* CR0    */  SET(CMP_CR0_FILTER_CNT(7)) |SET(CMP_CR0_HYSTCTR(0)),            \
/* CR1    */  CLR(CMP_CR1_SE_MASK)       |CLR(CMP_CR1_WE_MASK)|               \
/* ...    */  CLR(CMP_CR1_TRIGM_MASK)    |SET(CMP_CR1_PMODE_MASK)|            \
/* ...    */  CLR(CMP_CR1_INV_MASK)      |CLR(CMP_CR1_COS_MASK)|              \
/* ...    */  CLR(CMP_CR1_OPE_MASK)      |SET(CMP_CR1_EN_MASK),               \
/* FPR    */  SET(CMP_FPR_FILT_PER(0xFF)),                                    \
/* SCR    */  CLR(CMP_SCR_DMAEN_MASK)    |SET(CMP_SCR_IER_MASK)|              \
/* ...    */  CLR(CMP_SCR_IEF_MASK),                                          \
/* DACCR  */  SET(CMP_DACCR_DACEN_MASK)  |CLR(CMP_DACCR_VRSEL_MASK)|dac       \
}
/*! @} End of cmp_config                                                      */

/******************************************************************************
* CMP callback registered by CMP_InstallCallback() function
*
*//*! @addtogroup cmp_callback
* @{
*******************************************************************************/
/*! @brief CMP_CALLBACK type declaration                                      */
typedef enum
{
  CMP0_CALLBACK = 1,          ///< passed to notify CMP0 interrupt request
  CMP1_CALLBACK = 2,          ///< passed to notify CMP1 interrupt request
} CMP_CALLBACK_SRC;

/*! @brief CMP_CALLBACK type declaration                                      */
typedef enum
{
  CMP_NEGEDGE_CALLBACK  =  1, ///< Negative edge on COUT detected
  CMP_POSEDGE_CALLBACK  =  2, ///< Positive edge on COUT detected
} CMP_CALLBACK_TYPE;

/*! CMP_CALLBACK function declaration                                         */
typedef void (*CMP_CALLBACK)(CMP_CALLBACK_SRC module, CMP_CALLBACK_TYPE type);
/*! @} End of cmp_callback                                                    */

/******************************************************************************
* CMP function and macro definitions
*
*//*! @addtogroup cmp_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Enables specified comparator module.
 * @details This macro enables specified comparator module.
 * @param   module    CMP0,CMP1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define CMP_Enable(module)    iosetb (module##_CR1,CMP_CR1_EN_MASK)

/***************************************************************************//*!
 * @brief   Disables specified comparator module.
 * @details This macro disables specified comparator module.
 * @param   module    CMP0,CMP1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define CMP_Disable(module)   ioclrb (module##_CR1,CMP_CR1_EN_MASK)

/***************************************************************************//*!
 * @brief   Controls plus and minus multiplexer inputs.
 * @details This macro controls plus and minus multiplexer inputs. It determines
 *          which analogue signals are interconnected to the plus and minus
 *          inputs of the specified comparator module.
 * @param   module    CMP0,CMP1.
 * @param   psel      Plus input mux control select @ref cmp_channel.
 * @param   msel      Minus input mux control select @ref cmp_channel.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define CMP_MuxCtrl(module,psel,msel)                                         \
{                                                                             \
    iobfib (module##_MUXCR,CMP_MUXCR_PSEL_SHIFT,3,psel);                      \
    iobfib (module##_MUXCR,CMP_MUXCR_MSEL_SHIFT,3,msel);                      \
}

/***************************************************************************//*!
 * @brief   Returns the current value of the analog comparator output.
 * @details This macro returns the current value of the analog comparator output.
 * @param   module    CMP0,CMP1.
 * @return  true (non-zero) comparator output asserted (logic 1),
 * @return  false           comparator output de-asserted (logic 0).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define CMP_GetOutput(module)     (module##_SCR&CMP_SCR_COUT_MASK)

/***************************************************************************//*!
 * @brief   Installs callback function for CMP0 and CMP1 interrupt vector 30.
 * @details This function installs callback function for CMP0 and CMP1 interrupt
 *          vector 30.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref cmp_callback.
 * @note    Implemented as a function call.
 * @warning CMP0 and CMP1 interrupt sources are OR'ed into single interrupt vector.
 * @see     @ref CMP_Init
 ******************************************************************************/
#define CMP_InstallCallback(ip,callback) CMP_InstallCallback(ip,callback)

/***************************************************************************//*!
 * @brief   CMP initialization.
 * @details This function initializes selected comparator module
 * @param   module    CMP0,CMP1.
 * @param   cfg       Select one of the @ref cmp_config.
 * @param   psel      Plus input mux control select @ref cmp_channel.
 * @param   msel      Minus input mux control select @ref cmp_channel.
 * @note    Implemented as a function call.
 * @see     @ref CMP_InstallCallback
 ******************************************************************************/
#define CMP_Init(module,cfg,psel,msel)  module##_Init(cfg,psel,msel)
/*! @} End of cmp_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void CMP_InstallCallback (uint8 ip, CMP_CALLBACK pCallback);
extern void CMP0_Init (tCMP cmp, uint8 psel, uint8 msel);
extern void CMP1_Init (tCMP cmp, uint8 psel, uint8 msel);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void cmpx_isr (void);

#endif /* __CMP_H */