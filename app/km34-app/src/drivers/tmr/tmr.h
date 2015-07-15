/******************************************************************************
 * (c) Copyright 2010-2014, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      tmr.h
 * @version   1.0.6.0
 * @date      May-05-2015
 * @brief     Quad Timer (TMR) driver header file.
 ******************************************************************************/
#ifndef __TMR_H
#define __TMR_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint16 CTRL, SCTRL, CSCTRL, ENBL; } tTMR_CH;

/******************************************************************************
* Possible values for primary count source used by @ref TMR_Init() function
*
*//*! @addtogroup tmr_prm_src
* @{
* Any @ref BUS_CLK_DIV1 .. @ref BUS_CLK_DIV128 sources represents primary clock
* source configured by the @ref SIM_SelTmrPcs macro.
*******************************************************************************/
#define PRM_CNTR0_INP        0    ///< Counter 0 input pin
#define PRM_CNTR1_INP        1    ///< Counter 1 input pin
#define PRM_CNTR2_INP        2    ///< Counter 2 input pin
#define PRM_CNTR3_INP        3    ///< Counter 3 input pin
#define PRM_CNTR0_OUT        4    ///< Counter 0 output
#define PRM_CNTR1_OUT        5    ///< Counter 1 output
#define PRM_CNTR2_OUT        6    ///< Counter 2 output
#define PRM_CNTR3_OUT        7    ///< Counter 3 output
#define BUS_CLK_DIV1         8    ///< IP bus clock divide by 1 prescaler
#define BUS_CLK_DIV2         9    ///< IP bus clock divide by 2 prescaler
#define BUS_CLK_DIV4        10    ///< IP bus clock divide by 4 prescaler
#define BUS_CLK_DIV8        11    ///< IP bus clock divide by 8 prescaler
#define BUS_CLK_DIV16       12    ///< IP bus clock divide by 16 prescaler
#define BUS_CLK_DIV32       13    ///< IP bus clock divide by 32 prescaler
#define BUS_CLK_DIV64       14    ///< IP bus clock divide by 64 prescaler
#define BUS_CLK_DIV128      15    ///< IP bus clock divide by 128 prescaler
/*! @} End of tmr_prm_src                                                     */

/******************************************************************************
* Possible values of the count mode used by @ref TMR_Init() and
* @ref TMR_SetCountMode()functions
*
*//*! @addtogroup tmr_count_mode
* @{
*******************************************************************************/
#define COUNT_DISABLED        0   ///< No operation
#define COUNT_POSEDGE         1   ///< Count rising edges of primary source
#define COUNT_ANYEDGE         2   ///< Count rising and falling edges of primary
                                  ///  source
#define COUNT_POSEDGE_GATED   3   ///< Count rising edges of primary source
                                  ///  while secondary input high active
#define COUNT_QUADRATURE      4   ///< Quadrature count mode, uses primary
                                  ///  and secondary sources
#define COUNT_POSEDGE_DIRECT  5   ///< Count rising edges of primary source
                                  ///  secondary source specifies direction
#define COUNT_TRIGGERED       6   ///< Edge of secondary source triggers
                                  ///  primary count until compare
#define COUNT_CASCADED        7   ///< Cascaded counter mode (up/down)
/*! @} End of tmr_count_mode                                                  */

/******************************************************************************
* Possible values for output mode used by @ref TMR_Init() function
*
*//*! @addtogroup tmr_out_mode
* @{
*******************************************************************************/
#define ASSERT_ON_CNTR_ACTIVE       0 ///< Asserted while counter is active
#define CLR_ON_COMP                 1 ///< Clear OFLAG output on successful compare
#define SET_ON_COMP                 2 ///< Set OFLAG output on successful compare
#define TGL_ON_COMP                 3 ///< Toggle OFLAG output on successful
                                      ///  compare
#define TGL_ON_ALT_COMP             4 ///< Toggle OFLAG output using alternating
                                      ///  compare registers
#define SET_ON_COMP_CLR_ON_SEC_EDGE 5 ///< Set on compare, cleared on secondary
                                      ///  source input edge
#define SET_ON_COMP_CLR_ON_ROLLOVER 6 ///< Set on compare, cleared on counter
                                      ///  rollover
#define ENABLE_GATED_CLK            7 ///< Enable gated clock output while
                                      ///  counter is active
/*! @} End of tmr_out_mode                                                    */

/******************************************************************************
* Possible values for the secondary count sorce used by @ref TMR_Init() function
*
*//*! @addtogroup tmr_sec_src
* @{
* Any @ref SEC_CNTR0_INP .. @ref SEC_CNTR3_INP sources represents secondary clock
* source configured by the @ref SIM_SelTmrScs macro.
*******************************************************************************/
#define SEC_CNTR0_INP     0     ///< Counter 0 input pin for secondary source
#define SEC_CNTR1_INP     1     ///< Counter 1 input pin for secondary source
#define SEC_CNTR2_INP     2     ///< Counter 2 input pin for secondary source
#define SEC_CNTR3_INP     3     ///< Counter 3 input pin for secondary source
/*! @} End of tmr_sec_src                                                     */

/******************************************************************************
* Possible alues for the Input Capture Mode used by @ref TMR_Init() function
*
*//*! @addtogroup tmr_capt_mode
* @{
*******************************************************************************/
#define CAPTURE_DISABLED  0     ///< Capture function is disabled
#define LOAD_POSEDGE      1     ///< Load capture register on rising edge
                                ///  (when IPS=0) or falling edge (when IPS=1)
                                ///  of input
#define LOAD_NEGEDGE      2     ///< Load capture register on falling edge
                                ///  (when IPS=0) or rising edge (when IPS=1)
                                ///  of input
#define LOAD_ANYEDGE      3     ///< Load capture register on both edges of
                                ///  input
/*! @} End of tmr_capt_mode                                                   */

/******************************************************************************
* TMR default configurations used by TMR_CH_init() function
*
*//*! @addtogroup tmr_ch_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Configures Timer/Counter Mode - Rollover.
 * @details Configures Timer/Counter Mode - Rollover. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is
 * "Count Rising Edge of Primary Source". The Timer is configured in Counter
 * Mode with following the characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_DI_CONFIG1(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Timer/Counter Mode - Rollover.
 * @details Enables Timer/Counter Mode - Rollover. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is
 * "Count Rising Edge of Primary Source". The Timer is configured in Counter
 * Mode with following the characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_EN_CONFIG1(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Timer/Counter Mode - One Shot.
 * @details Configures Timer/Counter Mode - One Shot. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode enabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_DI_CONFIG2(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  SET(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Timer/Counter Mode - One Shot.
 * @details Enables Timer/Counter Mode - One Shot. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode enabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_EN_CONFIG2(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  SET(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Simple Timer/Counter Mode.
 * @details Configures Simple Timer/Counter Mode. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize
 * - One shot Timer mode enabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_DI_CONFIG3(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  SET(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Simple Timer/Counter Mode.
 * @details Enables Simple Timer/Counter Mode. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize
 * - One shot Timer mode enabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_EN_CONFIG3(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  SET(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Simple Timer/Counter Mode.
 * @details Configures Simple Timer/Counter Mode. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_DI_CONFIG4(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Simple Timer/Counter Mode.
 * @details Enables Simple Timer/Counter Mode. Output mode is set to
 * "Asserted while counter is active", Input Clock source selected is "Count
 * Rising Edge of Primary Source". The timer is configured in Counter Mode with
 * the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CNTR_EN_CONFIG4(prm_clk_src,sec_clk_src)                       \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Input Capture Mode.
 * @details Configures Input Capture Mode. The timer operates in Input Capture
 * Mode. Default Primary Clock source rising edge is selected. Output mode is
 * also fixed at "asserted while counter is active". Other characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt disabled
 * - Input capture interrupt enabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   input_mode      Select one of the @ref tmr_capt_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CAPT_DI_CONFIG1(prm_clk_src,sec_clk_src,input_mode)            \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  CLR(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  SET(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(input_mode))|                      \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Input Capture Mode.
 * @details Enables Input Capture Mode. The timer operates in Input Capture
 * Mode. Default Primary Clock source rising edge is selected. Output mode is
 * also fixed at "asserted while counter is active". Other characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt disabled
 * - Input capture interrupt enabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   input_mode      Select one of the @ref tmr_capt_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CAPT_EN_CONFIG1(prm_clk_src,sec_clk_src,input_mode)            \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  CLR(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  SET(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(input_mode))|                      \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Input Capture Mode.
 * @details Configures Input Capture Mode. The timer operates in Input Capture
 * Mode. Default Primary Clock source rising edge is selected. Output mode is
 * also fixed at "asserted while counter is active". Other characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt enabled
 * - Co-channel initialization disabled
 * - Compare interrupt disabled
 * - Input capture interrupt enabled
 * - Input signal polarity not inverted
 * - Timer channel is disabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   input_mode      Select one of the @ref tmr_capt_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CAPT_DI_CONFIG2(prm_clk_src,sec_clk_src,input_mode)            \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  CLR(TMR_SCTRL_TCFIE_MASK)|SET(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  SET(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(input_mode))|                      \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                        \
}

/***************************************************************************//*!
 * @brief   Enables Input Capture Mode.
 * @details Enables Input Capture Mode. The timer operates in Input Capture
 * Mode. Default Primary Clock source rising edge is selected. Output mode is
 * also fixed at "asserted while counter is active". Other characteristics:
 * - Counts up
 * - Rollover enabled
 * - One shot Timer mode disabled
 * - Overflow interrupt enabled
 * - Co-channel initialization disabled
 * - Compare interrupt disabled
 * - Input capture interrupt enabled
 * - Input signal polarity not inverted
 * - Timer channel is enabled
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   input_mode      Select one of the @ref tmr_capt_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_CAPT_EN_CONFIG2(prm_clk_src,sec_clk_src,input_mode)            \
(tTMR_CH){                                                                    \
/* CTRL     */  SET(TMR_CTRL_CM(COUNT_POSEDGE))|                              \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|\
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|CLR(TMR_CTRL_LENGTH_MASK)|             \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|            \
/* ......   */  SET(TMR_CTRL_OUTMODE(ASSERT_ON_CNTR_ACTIVE)),                 \
/* SCTRL    */  CLR(TMR_SCTRL_TCFIE_MASK)|SET(TMR_SCTRL_TOFIE_MASK)|          \
/* ......   */  SET(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|            \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(input_mode))|                      \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),              \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|       \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|           \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                       \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                       \
}

/***************************************************************************//*!
 * @brief   Configures Output Compare Mode.
 * @details Configures Output Compare Mode. The timer operates in Output Compare
 * Mode with the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize.
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Master operation disabled
 * - External OFLAG force disabled.
 * - Polarity of OFLAG output signal not inverted.
 * - Output not forced to external pin
 * - Timer channel is disabled
 * @param   count_mode      Select one of the @ref tmr_count_mode.
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   output_mode     Select one of the @ref tmr_out_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_OUTCMP_DI_CONFIG(count_mode,prm_clk_src,sec_clk_src,output_mode) \
(tTMR_CH){                                                                      \
/* CTRL     */  SET(TMR_CTRL_CM(count_mode))|                                   \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|  \
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|               \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|              \
/* ......   */  SET(TMR_CTRL_OUTMODE(output_mode)),                             \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|              \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                  \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|                \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),                \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|           \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|           \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|             \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                         \
/* ENBL     */  SET(TMR_ENBL_ENBL(0)),                                          \
}

/***************************************************************************//*!
 * @brief   Enables Output Compare Mode.
 * @details Enables Output Compare Mode. The timer operates in Output Compare
 * Mode with the following characteristics:
 * - Counts up
 * - Count until compare then re-initialize.
 * - One shot Timer mode disabled
 * - Overflow interrupt disabled
 * - Co-channel initialization disabled
 * - Compare interrupt enabled
 * - Input capture interrupt disabled
 * - Input signal polarity not inverted
 * - Master operation disabled
 * - External OFLAG force disabled.
 * - Polarity of OFLAG output signal not inverted.
 * - Output not forced to external pin
 * - Timer channel is enabled
 * @param   count_mode      Select one of the @ref tmr_count_mode.
 * @param   prm_clk_src     Select one of the @ref tmr_prm_src.
 * @param   sec_clk_src     Select one of the @ref tmr_sec_src.
 * @param   output_mode     Select one of the @ref tmr_out_mode.
 * @showinitializer
 ******************************************************************************/
#define TMR_CH_OUTCMP_EN_CONFIG(count_mode,prm_clk_src,sec_clk_src,output_mode) \
(tTMR_CH){                                                                      \
/* CTRL     */  SET(TMR_CTRL_CM(count_mode))|                                   \
/* ......   */  SET(TMR_CTRL_PCS(prm_clk_src))|SET(TMR_CTRL_SCS(sec_clk_src))|  \
/* ......   */  CLR(TMR_CTRL_DIR_MASK)|SET(TMR_CTRL_LENGTH_MASK)|               \
/* ......   */  CLR(TMR_CTRL_ONCE_MASK)|CLR(TMR_CTRL_COINIT_MASK)|              \
/* ......   */  SET(TMR_CTRL_OUTMODE(output_mode)),                             \
/* SCTRL    */  SET(TMR_SCTRL_TCFIE_MASK)|CLR(TMR_SCTRL_TOFIE_MASK)|            \
/* ......   */  CLR(TMR_SCTRL_IEFIE_MASK)|CLR(TMR_SCTRL_IPS_MASK)|              \
/* ......   */  SET(TMR_SCTRL_CAPTURE_MODE(CAPTURE_DISABLED))|                  \
/* ......   */  CLR(TMR_SCTRL_MSTR_MASK)|CLR(TMR_SCTRL_EEOF_MASK)|              \
/* ......   */  CLR(TMR_SCTRL_VAL_MASK)|CLR(TMR_SCTRL_TOF_MASK)|                \
/* ......   */  CLR(TMR_SCTRL_OPS_MASK)|CLR(TMR_SCTRL_OEN_MASK),                \
/* CSCTRL   */  SET(TMR_CSCTRL_DBG_EN(0))|CLR(TMR_CSCTRL_FAULT_MASK)|           \
/* ......   */  CLR(TMR_CSCTRL_ALT_LOAD_MASK)|CLR(TMR_CSCTRL_ROC_MASK)|         \
/* ......   */  CLR(TMR_CSCTRL_TCI_MASK)|CLR(TMR_CSCTRL_TCF2EN_MASK)|           \
/* ......   */  CLR(TMR_CSCTRL_TCF1EN_MASK)|SET(TMR_CSCTRL_CL2(0))|             \
/* ......   */  SET(TMR_CSCTRL_CL1(0)),                                         \
/* ENBL     */  SET(TMR_ENBL_ENBL(15)),                                         \
}
/*! @} End of tmr_ch_config                                                   */

/******************************************************************************
* TMR callback registered by TMR_CH_Init() function
*
*//*! @addtogroup tmr_ch_callback
* @{
*******************************************************************************/
/*! TMR_CH_CALLBACK type declaration                                          */
typedef enum
{
  ROLLOVER_CALLBACK=1,  ///< Counter roll over occurred either at 0xffff or at 0x0000
  COMPARE_CALLBACK =2,  ///< Counter value matched COMP1 or COMP2 value
  CAPTURE_CALLBACK =4   ///< Input capture event detected
} TMR_CH_CALLBACK_TYPE;

/*! @brief TMR_CH_CALLBACK function declaration                               */
typedef void (*TMR_CH_CALLBACK)(TMR_CH_CALLBACK_TYPE type, int32 result);
/*! @} End of tmr_ch_callback                                                 */

/******************************************************************************
* TMR function and macro definitions
*
*//*! @addtogroup tmr_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Disables operation of the selected Timer channel(s).
 * @details This macro disables operation of the selected Timer channel(s).
 * @param   mask        Select one or more OR'ed @ref channel_mask.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_Enable, @ref TMR_Init
 ******************************************************************************/
#define TMR_Disable(mask)                                                     \
{                                                                             \
  register uint16 tmp = 0;                                                    \
  if ((mask) & CH0) { tmp |= TMR_ENBL_ENBL(1); }                              \
  if ((mask) & CH1) { tmp |= TMR_ENBL_ENBL(2); }                              \
  if ((mask) & CH2) { tmp |= TMR_ENBL_ENBL(4); }                              \
  if ((mask) & CH3) { tmp |= TMR_ENBL_ENBL(8); }                              \
  ioclrh(TMR0_ENBL, tmp);                                                     \
}

/***************************************************************************//*!
 * @brief   Enables operation of the selected Timer channel(s).
 * @details This macro enables operation of the selected Timer channel(s).
 * @param   mask        Select one or more OR'ed @ref channel_mask.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_Disable, @ref TMR_Init
 ******************************************************************************/
#define TMR_Enable(mask)                                                      \
{                                                                             \
  register uint16 tmp = 0;                                                    \
  if ((mask) & CH0) { tmp |= TMR_ENBL_ENBL(1); }                              \
  if ((mask) & CH1) { tmp |= TMR_ENBL_ENBL(2); }                              \
  if ((mask) & CH2) { tmp |= TMR_ENBL_ENBL(4); }                              \
  if ((mask) & CH3) { tmp |= TMR_ENBL_ENBL(8); }                              \
  ioseth(TMR0_ENBL, tmp);                                                     \
}

#define TMRCH0_SetCmp1Val(val)    TMR0_COMP1=(val)
#define TMRCH1_SetCmp1Val(val)    TMR1_COMP1=(val)
#define TMRCH2_SetCmp1Val(val)    TMR2_COMP1=(val)
#define TMRCH3_SetCmp1Val(val)    TMR3_COMP1=(val)
/***************************************************************************//*!
 * @brief   Sets COMP1 register.
 * @details This macro sets COMP1 register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 COMP1 register value.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_SetCmp2Val
 ******************************************************************************/
#define TMR_SetCmp1Val(ch,val)    TMR##ch##_SetCmp1Val(val)

#define TMRCH0_SetCmp2Val(val)    TMR0_COMP2=(val)
#define TMRCH1_SetCmp2Val(val)    TMR1_COMP2=(val)
#define TMRCH2_SetCmp2Val(val)    TMR2_COMP2=(val)
#define TMRCH3_SetCmp2Val(val)    TMR3_COMP2=(val)
/***************************************************************************//*!
 * @brief   Sets COMP2 register.
 * @details This macro sets COMP2 register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 COMP2 register value.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_SetCmp1Val
 ******************************************************************************/
#define TMR_SetCmp2Val(ch,val)    TMR##ch##_SetCmp2Val(val)

#define TMRCH0_SetCountMode(mode) iobfih(TMR0_CTRL,TMR_CTRL_CM_SHIFT,3,mode)
#define TMRCH1_SetCountMode(mode) iobfih(TMR1_CTRL,TMR_CTRL_CM_SHIFT,3,mode)
#define TMRCH2_SetCountMode(mode) iobfih(TMR2_CTRL,TMR_CTRL_CM_SHIFT,3,mode)
#define TMRCH3_SetCountMode(mode) iobfih(TMR3_CTRL,TMR_CTRL_CM_SHIFT,3,mode)
/***************************************************************************//*!
 * @brief   Sets count mode.
 * @details This macro sets count mode.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   mode      Select one of the @ref tmr_count_mode.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetCountMode(ch,mode) TMR##ch##_SetCountMode(mode)

#define TMRCH0_SetOutMode(mode) iobfih(TMR0_CTRL,TMR_CTRL_OUTMODE_SHIFT,3,mode)
#define TMRCH1_SetOutMode(mode) iobfih(TMR1_CTRL,TMR_CTRL_OUTMODE_SHIFT,3,mode)
#define TMRCH2_SetOutMode(mode) iobfih(TMR2_CTRL,TMR_CTRL_OUTMODE_SHIFT,3,mode)
#define TMRCH3_SetOutMode(mode) iobfih(TMR3_CTRL,TMR_CTRL_OUTMODE_SHIFT,3,mode)
/***************************************************************************//*!
 * @brief   Determines the mode of operation for the OFLAG output signal.
 * @details This macro determines the mode of operation for the OFLAG output
 *          signal.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   mode      Select one of the @ref tmr_out_mode.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_GetOutMode
 ******************************************************************************/
#define TMR_SetOutMode(ch,mode)   TMR##ch##_SetOutMode(mode)

#define TMRCH0_GetOutMode         iobfxh(TMR0_CTRL,TMR_CTRL_OUTMODE_SHIFT,3)
#define TMRCH1_GetOutMode         iobfxh(TMR1_CTRL,TMR_CTRL_OUTMODE_SHIFT,3)
#define TMRCH2_GetOutMode         iobfxh(TMR2_CTRL,TMR_CTRL_OUTMODE_SHIFT,3)
#define TMRCH3_GetOutMode         iobfxh(TMR3_CTRL,TMR_CTRL_OUTMODE_SHIFT,3)
/***************************************************************************//*!
 * @brief   Returns the mode of operation for the OFLAG output signal.
 * @details This macro returns the mode of operation for the OFLAG output
 *          signal.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @return  @ref tmr_out_mode.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_SetOutMode
 ******************************************************************************/
#define TMR_GetOutMode(ch)        TMR##ch##_GetOutMode

#define TMRCH0_ForceOFLAG(val)                                                \
{                                                                             \
  iobfih(TMR0_SCTRL,TMR_SCTRL_VAL_SHIFT,1,val);                               \
  ioseth(TMR0_SCTRL,TMR_SCTRL_FORCE_MASK);                                    \
}
#define TMRCH1_ForceOFLAG(val)                                                \
{                                                                             \
  iobfih(TMR1_SCTRL,TMR_SCTRL_VAL_SHIFT,1,val);                               \
  ioseth(TMR1_SCTRL,TMR_SCTRL_FORCE_MASK);                                    \
}
#define TMRCH2_ForceOFLAG(val)                                                \
{                                                                             \
  iobfih(TMR2_SCTRL,TMR_SCTRL_VAL_SHIFT,1,val);                               \
  ioseth(TMR2_SCTRL,TMR_SCTRL_FORCE_MASK);                                    \
}
#define TMRCH3_ForceOFLAG(val)                                                \
{                                                                             \
  iobfih(TMR3_SCTRL,TMR_SCTRL_VAL_SHIFT,1,val);                               \
  ioseth(TMR3_SCTRL,TMR_SCTRL_FORCE_MASK);                                    \
}
/***************************************************************************//*!
 * @brief   Forces value passed by input argument to OFLAG output signal.
 * @details This macro forces value passed by input argument to OFLAG output
 *          signal by asserting TMRx_SCTRL[FORCE]=1. When the FORCE bit is
 *          written with a 1, then the VAL bit value will be placed on the OFLAG.
 *          The FORCE command can be written at any time. The OFLAG is not held
 *          at the value of the VAL bit. The FORCE bit is write only and only
 *          transfers the value of the VAL bit to OFLAG in the cycle when the
 *          FORCE bit is written to.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       1 (logic one)\n
 *                    0 (logic zero)
 * @note    Implemented as an inline macro.
 * @warning The Timer hardware has control over the OFLAG bit at all times.
 *          If the Timer hardware attempts to change OFLAG during the same clock
 *          cycle that the FORCE bit is written with a 1, then the FORCE bit wins
 *          out over the Timer hardware.
 ******************************************************************************/
#define TMR_ForceOFLAG(ch,val)      TMR##ch##_ForceOFLAG(val)

#define TMRCH0_SetPrmClkSrc(src)    iobfih(TMR0_CTRL,TMR_CTRL_PCS_SHIFT,4,src)
#define TMRCH1_SetPrmClkSrc(src)    iobfih(TMR1_CTRL,TMR_CTRL_PCS_SHIFT,4,src)
#define TMRCH2_SetPrmClkSrc(src)    iobfih(TMR2_CTRL,TMR_CTRL_PCS_SHIFT,4,src)
#define TMRCH3_SetPrmClkSrc(src)    iobfih(TMR3_CTRL,TMR_CTRL_PCS_SHIFT,4,src)
/***************************************************************************//*!
 * @brief   Sets primary clock source.
 * @details This macro sets primary clock source.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   src       Select one of the @ref tmr_prm_src.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelTmrPcs, @ref SIM_SelTmrScs
 ******************************************************************************/
#define TMR_SetPrmClkSrc(ch,src)    TMR##ch##_SetPrmClkSrc(src)

#define TMRCH0_SetLoadVal(val)      TMR0_LOAD=(val)
#define TMRCH1_SetLoadVal(val)      TMR1_LOAD=(val)
#define TMRCH2_SetLoadVal(val)      TMR2_LOAD=(val)
#define TMRCH3_SetLoadVal(val)      TMR3_LOAD=(val)
/***************************************************************************//*!
 * @brief   Sets LOAD register.
 * @details This macro sets LOAD register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 LOAD register value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetLoadVal(ch,val)      TMR##ch##_SetLoadVal(val)

#define TMRCH0_SetHoldVal(val)      TMR0_HOLD=(val)
#define TMRCH1_SetHoldVal(val)      TMR1_HOLD=(val)
#define TMRCH2_SetHoldVal(val)      TMR2_HOLD=(val)
#define TMRCH3_SetHoldVal(val)      TMR3_HOLD=(val)
/***************************************************************************//*!
 * @brief   Sets HOLD register.
 * @details This macro sets HOLD register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 HOLD register value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetHoldVal(ch,val)      TMR##ch##_SetHoldVal(val)

#define TMRCH0_SetCntrVal(val)      TMR0_CNTR=(val)
#define TMRCH1_SetCntrVal(val)      TMR1_CNTR=(val)
#define TMRCH2_SetCntrVal(val)      TMR2_CNTR=(val)
#define TMRCH3_SetCntrVal(val)      TMR3_CNTR=(val)
/***************************************************************************//*!
 * @brief   Sets CNTR register.
 * @details This macro sets CNTR register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 CNTR register value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetCntrVal(ch,val)      TMR##ch##_SetCntrVal(val)

#define TMRCH0_SetCmpld1Val(val)    TMR0_CMPLD1=(val)
#define TMRCH1_SetCmpld1Val(val)    TMR1_CMPLD1=(val)
#define TMRCH2_SetCmpld1Val(val)    TMR2_CMPLD1=(val)
#define TMRCH3_SetCmpld1Val(val)    TMR3_CMPLD1=(val)
/***************************************************************************//*!
 * @brief   Sets CMPLD1 register.
 * @details This macro sets CMPLD1 register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 CMPLD1 register value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetCmpLoad1Val(ch,val)  TMR##ch##_SetCmpld1Val(val)

#define TMRCH0_SetCmpld2Val(val)    TMR0_CMPLD2=(val)
#define TMRCH1_SetCmpld2Val(val)    TMR1_CMPLD2=(val)
#define TMRCH2_SetCmpld2Val(val)    TMR2_CMPLD2=(val)
#define TMRCH3_SetCmpld2Val(val)    TMR3_CMPLD2=(val)
/***************************************************************************//*!
 * @brief   Sets CMPLD2 register.
 * @details This macro sets CMPLD2 register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   val       @ref uint16 CMPLD2 register value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_SetCmpLoad2Val(ch,val)  TMR##ch##_SetCmpld2Val(val)

#define TMRCH0_GetCaptVal           (uint16)TMR0_CAPT
#define TMRCH1_GetCaptVal           (uint16)TMR1_CAPT
#define TMRCH2_GetCaptVal           (uint16)TMR2_CAPT
#define TMRCH3_GetCaptVal           (uint16)TMR3_CAPT
/***************************************************************************//*!
 * @brief   Returns val of the CAPTURE register.
 * @details This macro returns value of the CAPTURE register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @return  @ref uint16.
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_ReadClrCaptReg
 ******************************************************************************/
#define TMR_GetCaptVal(ch)          TMR##ch##_GetCaptVal

static inline uint8 TMRCH0_ReadClrCaptReg (uint16 *ptr)
{
  if (TMR0_SCTRL & TMR_SCTRL_IEF_MASK)
  {
    *ptr = TMR0_CAPT; ioclrh(TMR0_SCTRL,TMR_SCTRL_IEF_MASK);  return  TRUE;
  }
  else                                                        return FALSE;
}
static inline uint8 TMRCH1_ReadClrCaptReg (uint16 *ptr)
{
  if (TMR1_SCTRL & TMR_SCTRL_IEF_MASK)
  {
    *ptr = TMR1_CAPT; ioclrh(TMR1_SCTRL,TMR_SCTRL_IEF_MASK);  return  TRUE;
  }
  else                                                        return FALSE;
}
static inline uint8 TMRCH2_ReadClrCaptReg (uint16 *ptr)
{
  if (TMR2_SCTRL & TMR_SCTRL_IEF_MASK)
  {
    *ptr = TMR2_CAPT; ioclrh(TMR2_SCTRL,TMR_SCTRL_IEF_MASK);  return  TRUE;
  }
  else                                                        return FALSE;
}
static inline uint8 TMRCH3_ReadClrCaptReg (uint16 *ptr)
{
  if (TMR3_SCTRL & TMR_SCTRL_IEF_MASK)
  {
    *ptr = TMR3_CAPT; ioclrh(TMR3_SCTRL,TMR_SCTRL_IEF_MASK);  return  TRUE;
  }
  else                                                        return FALSE;
}
/***************************************************************************//*!
 * @brief   Reads value of the CAPTURE register if input edge flag was set
 *          and clears input edge flag.
 * @details This inline function reads value of the CAPTURE register if input
 *          edge flag was set. It also clears input edge flag after successful
 *          read.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   ptr       Pointer to the @ref uint16 value.
 * @return  true (non-zero) input edge flag was set (*ptr is written by value
 *                          from of capture register),
 * @return  false           input edge flag not set (*ptr is not modified).
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_GetCaptVal
 ******************************************************************************/
#define TMR_ReadClrCaptReg(ch,ptr)  TMR##ch##_ReadClrCaptReg(ptr)

#define TMRCH0_GetCntrVal           (uint16)TMR0_CNTR
#define TMRCH1_GetCntrVal           (uint16)TMR1_CNTR
#define TMRCH2_GetCntrVal           (uint16)TMR2_CNTR
#define TMRCH3_GetCntrVal           (uint16)TMR3_CNTR
/***************************************************************************//*!
 * @brief   Returns value of the COUNTER register.
 * @details This macro returns value of the COUNTER register.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @return  @ref uint16.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define TMR_GetCntrVal(ch)          TMR##ch##_GetCntrVal

#define TMRCH0_GetINPUT             (TMR0_SCTRL & TMR_SCTRL_INPUT_MASK)
#define TMRCH1_GetINPUT             (TMR1_SCTRL & TMR_SCTRL_INPUT_MASK)
#define TMRCH2_GetINPUT             (TMR2_SCTRL & TMR_SCTRL_INPUT_MASK)
#define TMRCH3_GetINPUT             (TMR3_SCTRL & TMR_SCTRL_INPUT_MASK)
/***************************************************************************//*!
 * @brief   Returns current state of the external input pin.
 * @details This macro returns current state of the external input pin selected
 *          via the secondary count source after application of IPS and filtering.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @return  true (non-zero) external input pin asserted (logic 1),
 * @return  false           external input pin de-asserted (logic 0).
 * @note    Implemented as an inline macro. .
 ******************************************************************************/
#define TMR_GetINPUT(ch)            TMR##ch##_GetINPUT

#define TMRCH0_CtrlOEN(x)           iobfih(TMR0_SCTRL,TMR_SCTRL_OEN_SHIFT,1,x)
#define TMRCH1_CtrlOEN(x)           iobfih(TMR1_SCTRL,TMR_SCTRL_OEN_SHIFT,1,x)
#define TMRCH2_CtrlOEN(x)           iobfih(TMR2_SCTRL,TMR_SCTRL_OEN_SHIFT,1,x)
#define TMRCH3_CtrlOEN(x)           iobfih(TMR3_SCTRL,TMR_SCTRL_OEN_SHIFT,1,x)
/***************************************************************************//*!
 * @brief   Configures the direction of the external pin.
 * @details This macro configures the direction of the external pin.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   x   TRUE  The OFLAG output signal is driven on the external pin. The
 *                    other timer groups using this external pin as their input
 *                    see the driven value\n
 *              FALSE The external pin is configured as an input (default).
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_CtrlOPS
 ******************************************************************************/
#define TMR_CtrlOEN(ch,x)           TMR##ch##_CtrlOEN(x)

#define TMRCH0_CtrlOPS(x)           iobfih(TMR0_SCTRL,TMR_SCTRL_OPS_SHIFT,1,x)
#define TMRCH1_CtrlOPS(x)           iobfih(TMR1_SCTRL,TMR_SCTRL_OPS_SHIFT,1,x)
#define TMRCH2_CtrlOPS(x)           iobfih(TMR2_SCTRL,TMR_SCTRL_OPS_SHIFT,1,x)
#define TMRCH3_CtrlOPS(x)           iobfih(TMR3_SCTRL,TMR_SCTRL_OPS_SHIFT,1,x)
/***************************************************************************//*!
 * @brief   Configures the polarity of the OFLAG output signal.
 * @details This macro configures the polarity of the OFLAG output signal.
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   x   TRUE  Inverted polarity\n
 *              FALSE True polarity (default).
 * @note    Implemented as an inline macro.
 * @see     @ref TMR_CtrlOEN
 ******************************************************************************/
#define TMR_CtrlOPS(ch,x)           TMR##ch##_CtrlOPS(x)

/***************************************************************************//*!
 * @brief   TMR channel initialization.
 * @details This function initializes channel of the TMR Timer
 *          selected by the input argument. It also installs callback function
 *          for interrupt vector associated with the initialized TMR channel:
 *          vector 23(CH0), vector 24(CH1), vector 25(CH2) and vector 26(CH3).
 * @param   ch        CH0,CH1,CH2,CH3.
 * @param   cfg       Select one of the @ref tmr_ch_config.
 * @param   comp1     @ref uint16 compare register 1 value.
 * @param   comp2     @ref uint16 compare register 2 value.
 * @param   load      @ref uint16 load register value.
 * @param   cmpld1    @ref uint16 comparator load register 1 value.
 * @param   cmpld2    @ref uint16 comparator load register 1 value.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref tmr_ch_callback.
 * @note    Implemented as a function call.
 * @see     @ref TMR_Enable,  @ref SIM_SelTmrPcs, @ref SIM_SelTmrScs
 ******************************************************************************/
#define TMR_Init(ch,cfg,comp1,comp2,load,cmpld1,cmpld2,ip,callback)           \
                TMR_##ch##_Init(cfg,comp1,comp2,load,cmpld1,cmpld2,ip,callback)
/*! @} End of tmr_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void TMR_CH0_Init (tTMR_CH ch, uint16 comp1, uint16 comp2, uint16 load,
                          uint16 cmpld1, uint16 cmpld2, uint8 ip,
                          TMR_CH_CALLBACK pCallback);
extern void TMR_CH1_Init (tTMR_CH ch, uint16 comp1, uint16 comp2, uint16 load,
                          uint16 cmpld1, uint16 cmpld2, uint8 ip,
                          TMR_CH_CALLBACK pCallback);
extern void TMR_CH2_Init (tTMR_CH ch, uint16 comp1, uint16 comp2, uint16 load,
                          uint16 cmpld1, uint16 cmpld2, uint8 ip,
                          TMR_CH_CALLBACK pCallback);
extern void TMR_CH3_Init (tTMR_CH ch, uint16 comp1, uint16 comp2, uint16 load,
                          uint16 cmpld1, uint16 cmpld2, uint8 ip,
                          TMR_CH_CALLBACK pCallback);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void tmr0_isr (void);
extern void tmr1_isr (void);
extern void tmr2_isr (void);
extern void tmr3_isr (void);

#endif  /* __TMR_H */