/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      smc.h
 * @version   1.0.5.0
 * @date      Jun-11-2015
 * @brief     System Mode Controller (SMC) driver header file.
 ******************************************************************************/
#ifndef __SMC_H
#define __SMC_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct  { uint8 PMPROT; } tSMC;

/******************************************************************************
* Operation modes definition returned by SMC_GetMode() macro
*
*//*! @addtogroup smc_modes
* @{
*******************************************************************************/
#define SMC_MODE_RUN    (uint8)(1u<<0) ///< Current power mode is RUN
#define SMC_MODE_STOP   (uint8)(1u<<1) ///< Current power mode is STOP
#define SMC_MODE_VLPR   (uint8)(1u<<2) ///< Current power mode is VLPR
#define SMC_MODE_VLPW   (uint8)(1u<<3) ///< Current power mode is VLPW
#define SMC_MODE_VLPS   (uint8)(1u<<4) ///< Current power mode is VLPS
#define SMC_MODE_VLLS   (uint8)(1u<<6) ///< Current power mode is VLLS
/*! @} End of smc_modes                                                       */

/******************************************************************************
* SMC default configurations used by SMC_init() function
*
*//*! @addtogroup smc_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Both Very-Low-Power (VLPS) and Very-Low-Leakage (VLLS) modes enabled.
 * @details Both Very-Low-Power (VLPS) and Very-Low-Leakage (VLLS) modes enabled.
 * @showinitializer
 ******************************************************************************/
#define SMC_MODULE_VLPS_ON_VLLS_ON_CONFIG                                     \
(tSMC){                                                                       \
/* PMPROT*/ SET(SMC_PMPROT_AVLP_MASK)|SET(SMC_PMPROT_AVLLS_MASK),             \
}

/***************************************************************************//*!
 * @brief Only Very-Low-Power (VLPS) mode enabled.
 * @details Only Very-Low-Power (VLPS) mode enabled.
 * @showinitializer
 ******************************************************************************/
#define SMC_MODULE_VLPS_ON_VLLS_OFF_CONFIG                                    \
(tSMC){                                                                       \
/* PMPROT*/ SET(SMC_PMPROT_AVLP_MASK)|CLR(SMC_PMPROT_AVLLS_MASK),             \
}

/***************************************************************************//*!
 * @brief Only Very-Low-Leakage (VLPS) mode enabled.
 * @details Only Very-Low-Leakage (VLPS) mode enabled.
 * @showinitializer
 ******************************************************************************/
#define SMC_MODULE_VLPS_OFF_VLLS_ON_CONFIG                                    \
(tSMC){                                                                       \
/* PMPROT*/ CLR(SMC_PMPROT_AVLP_MASK)|SET(SMC_PMPROT_AVLLS_MASK),             \
}

/***************************************************************************//*!
 * @brief Both Very-Low-Leakage (VLPS) and Very-Low-Power (VLLS) modes disabled.
 * @details Both Very-Low-Leakage (VLPS) and Very-Low-Power (VLLS) modes disabled.
 * @showinitializer
 ******************************************************************************/
#define SMC_MODULE_VLPS_OFF_VLLS_OFF_CONFIG                                   \
(tSMC){                                                                       \
/* PMPROT*/ CLR(SMC_PMPROT_AVLP_MASK)|CLR(SMC_PMPROT_AVLLS_MASK),             \
}
/*! @} End of smc_config                                                      */

/******************************************************************************
* SMC function and macro definitions
*
*//*! @addtogroup smc_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns current power mode of the device.
 * @details This macro returns current power mode of the device (SMC_PMSTAT
 *          register).
 * @return  @ref uint8   mask indicating current power mode of the device
 *          (refer to @ref smc_modes).
 * @note    Implemented as an inline macro.
 * @see     @ref SMC_SetMode
 ******************************************************************************/
#define SMC_GetMode()     (uint8)SMC_PMSTAT

#define SMC_SetModeRUN                                                        \
                    {                                                         \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_RUNM_SHIFT      ,2,0x00); \
                      while((PMC_REGSC & PMC_REGSC_REGONS_MASK)!=0x04);       \
                    }
#define SMC_SetModeVLPR                                                       \
                    {                                                         \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_RUNM_SHIFT      ,2,0x02); \
                      while((PMC_REGSC & PMC_REGSC_REGONS_MASK)==0x04);       \
                    }
#define SMC_SetModeWAIT                                                       \
                    {                                                         \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x00); \
                      wait();                                                 \
                    }
#define SMC_SetModeSTOP                                                       \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_PSTOPO_SHIFT,2,0x00); \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x00); \
                      stop();                                                 \
                    }
#define SMC_SetModePSTOP1                                                     \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_PSTOPO_SHIFT,2,0x01); \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x00); \
                      stop();                                                 \
                    }
#define SMC_SetModePSTOP2                                                     \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_PSTOPO_SHIFT,2,0x02); \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x00); \
                      stop();                                                 \
                    }
#define SMC_SetModeVLPS_PSTOP1                                                \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_PSTOPO_SHIFT,2,0x01); \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x02); \
                      stop();                                                 \
                    }
#define SMC_SetModeVLPS_PSTOP2                                                \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_PSTOPO_SHIFT,2,0x02); \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT     ,3,0x02); \
                      stop();                                                 \
                    }
#define SMC_SetModeVLPW                                                       \
                    {                                                         \
                      SMC_SetModeVLPR;                                        \
                      wait();                                                 \
                    }
#define SMC_SetModeVLPS                                                       \
                    {                                                         \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x02);  \
                      stop();                                                 \
                    }
#define SMC_SetModeVLLS3                                                      \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_VLLSM_SHIFT,3,0x03);  \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x04);  \
                      stop();                                                 \
                    }
#define SMC_SetModeVLLS2                                                      \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_VLLSM_SHIFT,3,0x02);  \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x04);  \
                      stop();                                                 \
                    }
#define SMC_SetModeVLLS1                                                      \
                    {                                                         \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_VLLSM_SHIFT,3,0x01);  \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x04);  \
                      stop();                                                 \
                    }
#define SMC_SetModeVLLS0_POR_ON                                               \
                    {                                                         \
                      ioclrb (SMC_STOPCTRL,SMC_STOPCTRL_PORPO_MASK);          \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_VLLSM_SHIFT,3,0x00);  \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x04);  \
                      stop();                                                 \
                    }
#define SMC_SetModeVLLS0_POR_OFF                                              \
                    {                                                         \
                      iosetb (SMC_STOPCTRL,SMC_STOPCTRL_PORPO_MASK);          \
                      iobfib (SMC_STOPCTRL,SMC_STOPCTRL_VLLSM_SHIFT,3,0x00);  \
                      iobfib (SMC_PMCTRL,SMC_PMCTRL_STOPM_SHIFT    ,3,0x04);  \
                      stop();                                                 \
                    }
/***************************************************************************//*!
 * @brief   Sets device operating mode.
 * @details This macro sets device operating mode.
 * @param   mode      Select an operating mode:
 *                    RUN,VLPR,STOP,PSTOP1,PSTOP2,VLPS_PSTOP1,VLPS_PSTOP2,WAIT,
 *                    VLPS,VLPW,VLLS3,VLLS2,VLLS1,VLLS0_POR_ON,VLLS0_POR_OFF.
 * @note    Implemented as an inline macro.
 * @see     @ref SMC_GetMode
 ******************************************************************************/
#define SMC_SetMode(mode) SMC_SetMode##mode

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
/***************************************************************************//*!
 * @brief   SMC initialization.
 * @details This macro function initializes System Mode Controller (SMC).
 * @param   cfg       Select one of the @ref smc_config.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SMC_Init(cfg)     SMC_PMPROT = cfg.PMPROT
/*! @} End of smc_macro                                                       */

#endif /* __SMC_H */ 