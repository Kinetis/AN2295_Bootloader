/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      vref.h
 * @version   1.0.6.0
 * @date      Apr-20-2015
 * @brief     Voltage Reference (VREF) driver header file.
 ******************************************************************************/
#ifndef __VREF_H
#define __VREF_H

/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint8 VREFH_TRM, VREFH_SC, VREFL_TRM; } tVREF;
typedef struct { uint32 SIM_MISC_CTL_S; uint8 VREFL_TRM_S; } tVREF_S;

/******************************************************************************
* VREF default configurations used by VREF_init() function
*
*//*! @addtogroup vref_module_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator disable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - Bandgap on only mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_OFF_1V75_0V4_BGAP_CONFIG                              \
(tVREF){                                                                       \
/* VERFH_TRM */  CLR(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(0)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator disable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - High power buffer mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_OFF_1V75_0V4_HPWR_CONFIG                              \
(tVREF){                                                                       \
/* VERFH_TRM */  CLR(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(1)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator disable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - Low power buffer mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_OFF_1V75_0V4_LPWR_CONFIG                              \
(tVREF){                                                                       \
/* VERFH_TRM */  CLR(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(2)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator enable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - Bandgap on only mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_ON_1V75_0V4_BGAP_CONFIG                               \
(tVREF){                                                                       \
/* VERFH_TRM */  SET(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(0)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator enable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - High power buffer mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_ON_1V75_0V4_HPWR_CONFIG                               \
(tVREF){                                                                       \
/* VERFH_TRM */  SET(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(1)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference setting.
 * @details Configures voltage reference module with following characteristics:
 *          - Chop oscillator enable,
 *          - Internal 1,75 V regulator enable,
 *          - Second order curvature compensation enable,
 *          - Low power buffer mode,
 *          - Internal reference select,
 *          - Internal 0,4 V reference enable
 * @note    The second order curvature compensation can be enabled on new
 *          MKMxxZxxACxx5 devices only. The older MKMxxZxxCxx5 devices don't
 *          support this compensation.
 * @showinitializer
 ******************************************************************************/
#define VREF_MODULE_CHOP_ON_1V75_0V4_LPWR_CONFIG                               \
(tVREF){                                                                       \
/* VERFH_TRM */  SET(VREF_VREFH_TRM_CHOPEN_MASK),                              \
/* VERFH_SC  */  SET(VREF_VREFH_SC_VREFEN_MASK)|SET(VREF_VREFH_SC_REGEN_MASK)| \
/* ........  */  SET(VREF_VREFH_SC_ICOMPEN_MASK)|SET(VREF_VREFH_SC_MODE_LV(2)),\
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_EN_MASK)|                            \
/* ......... */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}
/*! @} End of vref_module_config                                              */

/******************************************************************************
* VREF default configurations used by VREF_init() function
*
*//*! @addtogroup vref_switch_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer enable,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - Internal reference select,     S2 = L,
 *          - AFE Internal reference select, S3 = L,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_L_S3_L_BUFF_ON                                     \
(tVREF_S){                                                                     \
/* SIM_MISC  */  CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer enable,
 *          - Buffer drive voltage on PAD,   S1 = H,
 *          - Internal reference select,     S2 = L,
 *          - AFE Internal reference select, S3 = L,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_H_S2_L_S3_L_BUFF_ON                                     \
(tVREF_S){                                                                     \
/* SIM_MISC  */  CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  SET(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer enable,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - External reference select,     S2 = H,
 *          - AFE Internal reference select, S3 = L,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_H_S3_L_BUFF_ON                                     \
(tVREF_S){                                                                     \
/* SIM_MISC  */  CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  SET(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer enable,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - External reference select,     S2 = H,
 *          - AFE External reference select, S3 = H,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_H_S3_H_BUFF_ON                                     \
(tVREF_S){                                                                     \
/* SIM_MISC  */  CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  SET(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer disabled,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - Internal reference select,     S2 = L,
 *          - AFE Internal reference select, S3 = L,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_L_S3_L_BUFF_OFF                                    \
(tVREF_S){                                                                     \
/* SIM_MISC  */  SET(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer disabled,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - External reference select,     S2 = H,
 *          - AFE Internal reference select, S3 = L,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_H_S3_L_BUFF_OFF                                    \
(tVREF_S){                                                                     \
/* SIM_MISC  */  CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  SET(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  CLR(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/***************************************************************************//*!
 * @brief   Voltage reference switch setting.
 * @details Configures voltage reference switches:
 *          - Buffer disabled,
 *          - Buffer does not drive PAD,     S1 = L,
 *          - External reference select,     S2 = H,
 *          - AFE External reference select, S3 = H,
 * @showinitializer
 ******************************************************************************/
#define VREF_SWITCH_S1_L_S2_H_S3_H_BUFF_OFF                                    \
(tVREF_S){                                                                     \
/* SIM_MISC  */  SET(SIM_MISC_CTL_VREFBUFPD_MASK)|                             \
/* ......... */  SET(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                          \
/* ......... */  CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK),                          \
/* VERFL_TRM */  SET(VREF_VREFL_TRM_VREFL_SEL_MASK),                           \
}

/*! @} End of vref_switch_config                                              */

/******************************************************************************
* VREF function and macro definitions
*
*//*! @addtogroup vref_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Disable voltage reference.
 * @details This macro disables voltage reference.
 * @note    Implemented as an inline macro.
 * @warning Call this function prior entering low power mode.
 * @see     @ref VREF_Init
 ******************************************************************************/
#define VREF_Disable()                                                        \
{                                                                             \
  ioclrb (VREF_VREFH_SC, VREF_VREFH_SC_VREFEN_MASK);                          \
  iosetb (SIM_MISC_CTL,SIM_MISC_CTL_VREFBUFPD_MASK);                          \
}

/***************************************************************************//*!
 * @brief   Enable/disable second order curvature compensation.
 * @details This macro enables/disables second order curvature compensation.
 * @param   x   TRUE  (enabled - default for MKMxxZxxACxx5 devices)\n
 *              FALSE (disabled - exclusively for MKMxxZxxCxx5 devices).
 * @note    The second order curvature compensation must be enabled to achieve
 *          the best temperature drift across full temperature range. This
 *          compensation is enabled by default on new MKMxxZxxACxx5 devices.
 *          Older MKMxxZxxCxx5 devices don't support this compensation.
 * @see     @ref VREF_Init
 ******************************************************************************/
#define VREF_CtrlICOMPEN(x)                                                    \
                    iobfib (VREF_VREFH_SC,VREF_VREFH_SC_ICOMPEN_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Higher reference voltage Trim value change.
 * @details Change higher reference voltage without change other parameters.
 *          VREFH reference output can be trimmed with a resolution of 0.5 mV.
 * @param   trim   6-bit trim value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define VREFH_Trim(trim) {                                                     \
                           register uint8 tmp;                                 \
                                                                               \
                           tmp            = (                                  \
                                             VREF_VREFH_TRM &                  \
                                             VREF_VREFH_TRM_CHOPEN_MASK        \
                                            );                                 \
                           VREF_VREFH_TRM = (trim | tmp);                      \
                         }

/***************************************************************************//*!
 * @brief   Lower reference voltage Trim value change.
 * @details Change lower reference voltage without change other parameters.
 *          VREFL reference output can be trimmed with a resolution of 10 mV.
 * @param   trim   3-bit trim value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define VREFL_Trim(trim) {                                                     \
                           register uint8 tmp;                                 \
                                                                               \
                           tmp            = (                                  \
                                              VREF_VREFL_TRM &                 \
                                             (VREF_VREFL_TRM_VREFL_EN_MASK|    \
                                              VREF_VREFL_TRM_VREFL_SEL_MASK)   \
                                            );                                 \
                           VREF_VREFL_TRM = (trim | tmp);                      \
                         }

/***************************************************************************//*!
 * @brief   Voltage reference initialization.
 * @details This function initializes Voltage reference.
 * @param   cfg       Select one of the @ref vref_module_config.
 * @param   cfg_s     Select one of the @ref vref_switch_config.
 * @note    Implemented as a function call.
 * @warning Call this function after @ref SIM_Init function call.
 *          Buffer Enable is controlled via SIM module SIM_MISC_CTL[VREFBUFPD],
 *          S1 is controlled via SIM module SIM_MISC_CTL[VREFBUFOUTEN],
 *          S2 is controlled via SIM module SIM_MISC_CTL[VREFBUFINSEL] and
 *          S3 is controlled via VREF module VREF_VREFL_TRM[VREFL_SEL].
 * @see     @ref VREF_Disable
 ******************************************************************************/
#define VREF_Init(cfg, cfg_s)   VREF_Init(cfg, cfg_s)
/*! @} End of vref_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void VREF_Init  (tVREF vref, tVREF_S vref_s);

#endif /* __VREF_H */ 