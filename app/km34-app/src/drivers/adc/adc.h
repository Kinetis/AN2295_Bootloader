/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      adc.h
 * @version   1.0.4.0
 * @date      Apr-21-2015
 * @brief     Analog-to-Digital Converter (ADC) driver header file.
 ******************************************************************************/
#ifndef __ADC_H
#define __ADC_H

#if !defined(MCU_MKM34ZA5)
  #error "The adc.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * ADC calibration data structure definition                                  *
 ******************************************************************************/
typedef struct { uint32 OFS, PG, MG, CLPD, CLPS, CLP[5]; } tADC_CALIB;

/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint32 CFG1, CFG2, CV1, CV2, SC2, SC3, PGA; } tADC;
typedef struct { uint32 SC1; } tADC_CH;

/******************************************************************************
* ADC hardware averaging factors definition
*
*//*! @addtogroup adc_avg_list
* @{
*******************************************************************************/
#define HWAVG_OFF   (uint8)0xff ///< hardware averaging disabled.
#define HWAVG_4     (uint8)0x00 ///<  4 samples averaged.
#define HWAVG_8     (uint8)0x01 ///<  8 samples averaged.
#define HWAVG_16    (uint8)0x02 ///< 16 samples averaged.
#define HWAVG_32    (uint8)0x03 ///< 32 samples averaged.
/*! @} End of adc_avg_list                                                    */

/******************************************************************************
* ADC input channels selected by ADC_CFG2_MUXSEL = 0 (MUXA).
*
*//*! @addtogroup adc_chan_muxa
* @{
*******************************************************************************/
#define AD3           (uint8)0    ///< Single ended input from pin
#define AD6           (uint8)1    ///< Single ended input from pin
#define AD8           (uint8)2    ///< Single ended input from pin
#define AD9           (uint8)3    ///< Single ended input from pin
#define VLL1          (uint8)4    ///< LCD VLL1 Voltage
#define VCAP1         (uint8)5    ///< LCD VCAP1 Voltage
#define AD0           (uint8)6    ///< Single ended input from pin
#define AD1           (uint8)7    ///< Single ended input from pin
#define VLL2          (uint8)8    ///< LCD VLL2 Voltage
#define VCAP2         (uint8)9    ///< LCD VCAP2 Voltage
#define AD2           (uint8)10   ///< Single ended input from pin
#define AD4           (uint8)11   ///< Single ended input from pin
#define PMC_VDD       (uint8)12   ///< VDD supply from PMC
#define PMC_VDD_SW    (uint8)13   ///< Switched VDD supply from PMC
#define SAR_VDDA      (uint8)14   ///< VDDA supply for SAR
#define AD5           (uint8)15   ///< Single ended input from pin
#define AD7           (uint8)16   ///< Single ended input from pin
#define CMP0_DAC_OUT  (uint8)17   ///< CMP0 DAC output voltage
#define CMP1_DAC_OUT  (uint8)18   ///< CMP1 DAC output voltage
#define AD10          (uint8)19   ///< Single ended input from pin
#define AD11          (uint8)20   ///< Single ended input from pin
#define TEMP_SENSOR   (uint8)26   ///< Temperature sensor
#define PMC_1V_BG_OUT (uint8)27   ///< PMC 1 V bandgap Buffer
#define AD_OFF        (uint8)31   ///< channel disabled
/*! @} End of adc_chan_muxa                                                   */

/******************************************************************************
* ADC module default configurations used by ADC_Init() function.
*
*//*! @addtogroup adc_module_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Selects 16-bit software triggered mode with internal voltage reference.
 * @details Selects 16-bit software triggered mode with internal voltage
 * reference. It initializes ADC module to convert @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_MODULE_16B_SWTRG_IREF_CONFIG                                      \
(tADC){                                                                       \
/* CFG1   */  CLR(ADC_CFG1_ADLPC_MASK)|SET(ADC_CFG1_ADIV(3))|                 \
/* ....   */  SET(ADC_CFG1_ADLSMP_MASK)|SET(ADC_CFG1_MODE(3))|                \
/* ....   */  SET(ADC_CFG1_ADICLK(0)),                                        \
/* CFG2   */  CLR(ADC_CFG2_MUXSEL_MASK)|CLR(ADC_CFG2_ADACKEN_MASK)|           \
/* ....   */  SET(ADC_CFG2_ADHSC_MASK)|SET(ADC_CFG2_ADLSTS(0)),               \
/* CV1    */  0l,                                                             \
/* CV2    */  0l,                                                             \
/* SC2    */  CLR(ADC_SC2_ADTRG_MASK)|CLR(ADC_SC2_ACFE_MASK)|                 \
/* ...    */  CLR(ADC_SC2_ACFGT_MASK)|CLR(ADC_SC2_ACREN_MASK)|                \
/* ...    */  CLR(ADC_SC2_DMAEN_MASK)|SET(ADC_SC2_REFSEL(1)),                 \
/* SC3    */  CLR(ADC_SC3_CAL_MASK)|CLR(ADC_SC3_ADCO_MASK)|                   \
/* ...    */  CLR(ADC_SC3_AVGE_MASK)|SET(ADC_SC3_AVGS(0)),                    \
}
/***************************************************************************//*!
 * @brief Selects 16-bit software triggered mode with external voltage reference.
 * @details Selects 16-bit software triggered mode with external voltage
 * reference. It initializes ADC module to convert @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_MODULE_16B_SWTRG_XREF_CONFIG                                      \
(tADC){                                                                       \
/* CFG1   */  CLR(ADC_CFG1_ADLPC_MASK)|SET(ADC_CFG1_ADIV(3))|                 \
/* ....   */  SET(ADC_CFG1_ADLSMP_MASK)|SET(ADC_CFG1_MODE(3))|                \
/* ....   */  SET(ADC_CFG1_ADICLK(0)),                                        \
/* CFG2   */  CLR(ADC_CFG2_MUXSEL_MASK)|CLR(ADC_CFG2_ADACKEN_MASK)|           \
/* ....   */  SET(ADC_CFG2_ADHSC_MASK)|SET(ADC_CFG2_ADLSTS(0)),               \
/* CV1    */  0l,                                                             \
/* CV2    */  0l,                                                             \
/* SC2    */  CLR(ADC_SC2_ADTRG_MASK)|CLR(ADC_SC2_ACFE_MASK)|                 \
/* ...    */  CLR(ADC_SC2_ACFGT_MASK)|CLR(ADC_SC2_ACREN_MASK)|                \
/* ...    */  CLR(ADC_SC2_DMAEN_MASK)|SET(ADC_SC2_REFSEL(0)),                 \
/* SC3    */  CLR(ADC_SC3_CAL_MASK)|CLR(ADC_SC3_ADCO_MASK)|                   \
/* ...    */  CLR(ADC_SC3_AVGE_MASK)|SET(ADC_SC3_AVGS(0)),                    \
}
/***************************************************************************//*!
 * @brief Selects 16-bit hardware triggered mode with internal voltage reference.
 * @details Selects 16-bit hardware triggered mode with internal voltage
 * reference. It initializes ADC module to convert @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_MODULE_16B_HWTRG_IREF_CONFIG                                      \
(tADC){                                                                       \
/* CFG1   */  CLR(ADC_CFG1_ADLPC_MASK)|SET(ADC_CFG1_ADIV(3))|                 \
/* ....   */  SET(ADC_CFG1_ADLSMP_MASK)|SET(ADC_CFG1_MODE(3))|                \
/* ....   */  SET(ADC_CFG1_ADICLK(0)),                                        \
/* CFG2   */  CLR(ADC_CFG2_MUXSEL_MASK)|CLR(ADC_CFG2_ADACKEN_MASK)|           \
/* ....   */  SET(ADC_CFG2_ADHSC_MASK)|SET(ADC_CFG2_ADLSTS(0)),               \
/* CV1    */  0l,                                                             \
/* CV2    */  0l,                                                             \
/* SC2    */  SET(ADC_SC2_ADTRG_MASK)|CLR(ADC_SC2_ACFE_MASK)|                 \
/* ...    */  CLR(ADC_SC2_ACFGT_MASK)|CLR(ADC_SC2_ACREN_MASK)|                \
/* ...    */  CLR(ADC_SC2_DMAEN_MASK)|SET(ADC_SC2_REFSEL(1)),                 \
/* SC3    */  CLR(ADC_SC3_CAL_MASK)|CLR(ADC_SC3_ADCO_MASK)|                   \
/* ...    */  CLR(ADC_SC3_AVGE_MASK)|SET(ADC_SC3_AVGS(0)),                    \
}
/***************************************************************************//*!
 * @brief Selects 16-bit hardware triggered mode with external voltage reference.
 * @details Selects 16-bit hardware triggered mode with external voltage
 * reference. It initializes ADC module to convert @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_MODULE_16B_HWTRG_XREF_CONFIG                                      \
(tADC){                                                                       \
/* CFG1   */  CLR(ADC_CFG1_ADLPC_MASK)|SET(ADC_CFG1_ADIV(3))|                 \
/* ....   */  SET(ADC_CFG1_ADLSMP_MASK)|SET(ADC_CFG1_MODE(3))|                \
/* ....   */  SET(ADC_CFG1_ADICLK(0)),                                        \
/* CFG2   */  CLR(ADC_CFG2_MUXSEL_MASK)|CLR(ADC_CFG2_ADACKEN_MASK)|           \
/* ....   */  SET(ADC_CFG2_ADHSC_MASK)|SET(ADC_CFG2_ADLSTS(0)),               \
/* CV1    */  0l,                                                             \
/* CV2    */  0l,                                                             \
/* SC2    */  SET(ADC_SC2_ADTRG_MASK)|CLR(ADC_SC2_ACFE_MASK)|                 \
/* ...    */  CLR(ADC_SC2_ACFGT_MASK)|CLR(ADC_SC2_ACREN_MASK)|                \
/* ...    */  CLR(ADC_SC2_DMAEN_MASK)|SET(ADC_SC2_REFSEL(0)),                 \
/* SC3    */  CLR(ADC_SC3_CAL_MASK)|CLR(ADC_SC3_ADCO_MASK)|                   \
/* ...    */  CLR(ADC_SC3_AVGE_MASK)|SET(ADC_SC3_AVGS(0)),                    \
}
/*! @} End of adc_module_config                                               */

/******************************************************************************
* ADC module default configurations used by ADC_Init() function.
*
*//*! @addtogroup adc_chan_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Single ended conversion, interrupt enabled.
 * @details Single ended conversion, interrupt enabled.
 * @param   ch        Select one of the @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_CH_SE_IRQ_CONFIG(ch)                                              \
(tADC_CH){                                                                    \
/* SC1    */ SET(ADC_SC1_AIEN_MASK)|ch,                                       \
}
/***************************************************************************//*!
 * @brief Single ended conversion, polling mode (interrupt disabled).
 * @details Single ended conversion, polling mode (interrupt disabled).
 * @param   ch        Select one of the @ref adc_chan_muxa.
 * @showinitializer
 ******************************************************************************/
#define ADC_CH_SE_POLL_CONFIG(ch)                                             \
(tADC_CH){                                                                    \
/* SC1    */ CLR(ADC_SC1_AIEN_MASK)|ch,                                       \
}
/***************************************************************************//*!
 * @brief ADC module is disabled.
 * @details ADC module is disabled.
 * @note Use either @ref ADC_CH_SE_POLL_CONFIG or @ref ADC_CH_SE_IRQ_CONFIG to
 * perform ADC conversion on given channel.
 * @showinitializer
 ******************************************************************************/
#define ADC_CH_DISABLE_CONFIG                                                 \
(tADC_CH){                                                                    \
/* SC1    */ CLR(ADC_SC1_AIEN_MASK)|AD_OFF,                                   \
}
/*! @} End of adc_chan_config                                                 */

/******************************************************************************
* ADC callback registered by ADC_Init() function
*
*//*! @addtogroup adc_callback
* @{
*******************************************************************************/
/*! ADC_CALLBACK type declaration                                             */
typedef enum
{
  CHA_CALLBACK=1,     ///< Status and Control Register A Conversion Complete
  CHB_CALLBACK=2,     ///< Status and Control Register B Conversion Complete
  CHC_CALLBACK=4,     ///< Status and Control Register C Conversion Complete
  CHD_CALLBACK=8      ///< Status and Control Register D Conversion Complete
} ADC_CALLBACK_TYPE;

/*! @brief ADC_CALLBACK function declaration                                  */
typedef void (*ADC_CALLBACK)(ADC_CALLBACK_TYPE type, register int16 result);
/*! @} End of adc_callback                                                    */

/******************************************************************************
* ADC function and macro definitions
*
*//*! @addtogroup adc_macro
* @{
*******************************************************************************/
#define ADC_CHA_Start(inp)      iobfiw(ADC_SC1A,ADC_SC1_ADCH_SHIFT,5,inp)
/***************************************************************************//*!
 * @brief   Starts conversion by software.
 * @details This macro triggers conversion by software. Note that only conversion
 *          upon SC1A register (CHA) can be triggered by both software and hardware.
 *          The conversions upon SC1B (CHB),SC1C (CHC) and SC1D (CHD) registers can
 *          only be triggered by HW trigger source.
 * @param   ch        CHA.
 * @param   inp       Select one of the @ref adc_chan_muxa.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ADC_Start(ch,inp)       ADC_##ch##_Start(inp)

#define ADC_CHA_Ready           (ADC_SC1A & ADC_SC1_COCO_MASK)
#define ADC_CHB_Ready           (ADC_SC1B & ADC_SC1_COCO_MASK)
#define ADC_CHC_Ready           (ADC_SC1C & ADC_SC1_COCO_MASK)
#define ADC_CHD_Ready           (ADC_SC1D & ADC_SC1_COCO_MASK)
/***************************************************************************//*!
 * @brief   Returns nonzero value when conversion completed.
 * @details This macro returns nonzero value when conversion completed and
 *          new value converted by the ADC resides in the result register.
 *          Read value from the respective result register by <c>ADC_Read()</c>.
 * @param   ch        CHA,CHB,CHC,CHD.
 * @return  true (non-zero) conversion completed (COCO flag is asserted),
 * @return  false           conversion pending (COCO flag is deasserted).
 * @note    Implemented as an inline macro.
 * @see     @ref ADC_Read
 ******************************************************************************/
#define ADC_Ready(ch)           ADC_##ch##_Ready

#define ADC_CHA_Read            (int16)ADC_RA
#define ADC_CHB_Read            (int16)ADC_RB
#define ADC_CHC_Read            (int16)ADC_RC
#define ADC_CHD_Read            (int16)ADC_RD
/***************************************************************************//*!
 * @brief   Returns value from the result register.
 * @details This macro returns value from the respective result register.
 * @param   ch        CHA,CHB,CHC,CHD.
 * @return  @ref int16 right-justified value converted by the ADC. The number of
 *          effective bits depends on the conversion mode.
 * @note    Implemented as an inline macro.
 * @see     @ref ADC_Ready
 ******************************************************************************/
#define ADC_Read(ch)            ADC_##ch##_Read

/***************************************************************************//*!
 * @brief   ADC channel initialization.
 * @details This function initializes Analogue Digital Converter (ADC). It also
 *          installs callback function for interrupt vector 32.
 * @param   cfg       Select one of the @ref adc_module_config.
 * @param   avg       Select one of the @ref adc_avg_list.
 * @param   CHA       Select one of the @ref adc_chan_config (Channel A).
 * @param   CHB       Select one of the @ref adc_chan_config (Channel B).
 * @param   CHC       Select one of the @ref adc_chan_config (Channel C).
 * @param   CHD       Select one of the @ref adc_chan_config (Channel D).
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref adc_callback.
 * @note    Implemented as a function call.
 * @warning Note that only conversion upon SC1A register (CHA) can be triggered by
 *          both software and hardware. The conversions upon SC1B (CHB),SC1C (CHC)
 *          and SC1D (CHD) registers can only be triggered by HW trigger source.
 ******************************************************************************/
#define ADC_Init(cfg,avg,CHA,CHB,CHC,CHD,ip,callback)                           \
                                    ADC_Init(cfg,avg,CHA,CHB,CHC,CHD,ip,callback)

/***************************************************************************//*!
 * @brief   ADC calibration function.
 * @details This function runs calibration procedure and updates calibration
 *          registers of the ADC module.
 * @param   cfg       Select configuration structure:\n
 *                    @ref ADC_MODULE_16B_SWTRG_IREF_CONFIG,
 *                    @ref ADC_MODULE_16B_SWTRG_XREF_CONFIG.
 * @param   calib     Pointer to tADC_CALIB structure.
 * @return  true (non-zero) error occurred during calibration,
 * @return  false           calibration successful.
 * @note    Implemented as a function call.
 * @see     @ref ADC_SaveCalib
 ******************************************************************************/
#define ADC_ExecCalib(cfg,calib)    ADC_ExecCalib(cfg,calib)

/***************************************************************************//*!
 * @brief   Updates ADC registers by calibration values.
 * @details This function updates register of the ADC by calibration values from
 *          the structure passed by pointer.
 * @param   calib     Pointer to tADC_CALIB structure.
 * @note    Implemented as a function call.
 * @see     @ref ADC_ExecCalib
 ******************************************************************************/
#define ADC_SaveCalib(calib)        ADC_SaveCalib(calib)
/*! @} End of adc_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern int  ADC_ExecCalib (tADC adc, tADC_CALIB *pCALIB);
extern void ADC_SaveCalib (tADC_CALIB *pCALIB);
extern void ADC_Init      (tADC adc, uint8 avg, tADC_CH CHA, tADC_CH CHB, tADC_CH CHC,
                           tADC_CH CHD, uint8 ip, ADC_CALLBACK pCallback);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void adc_isr (void);

#endif /* __ADC_H */ 