/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      sim.h
 * @version   1.0.5.0
 * @date      Apr-20-2015
 * @brief     System Integration Module (SIM) driver header file.
 ******************************************************************************/
#ifndef __SIM_H
#define __SIM_H

#if !defined(MCU_MKM34ZA5)
  #error "The sim.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct
{
  uint32 SOPT1, SOPT1_CFG, CTRL_REG, SCGC4, SCGC5, SCGC6, SCGC7, CLKDIV1, FCCFG1,
         MISC_CTL;
} tSIM;

/******************************************************************************
* SIM OSC32KSEL clock definitions. Selects the 32 KHz clock source for LPTMR,
* CLKOUT, LCD, EWM, WDOG. This bit is reset only on POR/LVD.
*
*//*! @addtogroup osc32k_clk_src
* @{
*******************************************************************************/
#define SIM_OSC32K_SRC1 (uint8)0x00   ///< OSC32KCLK (default)
#define SIM_OSC32K_SRC2 (uint8)0x01   ///< ERCLK32K
#define SIM_OSC32K_SRC3 (uint8)0x02   ///< MCGIRCLK
#define SIM_OSC32K_SRC4 (uint8)0x03   ///< LPO
/*! @} End of osc32k_clk_src                                                  */

/******************************************************************************
* SIM clkout clock source definitions used by SIM_SelClkout() function
*
*//*! @addtogroup clkout_src
* @{
*******************************************************************************/
#define CLKOUT_DISABLED (uint32)0x00  ///< Disabled
#define CLKOUT_SRC1     (uint32)0x01  ///< Gated core clock
#define CLKOUT_SRC2     (uint32)0x02  ///< Bus clock
#define CLKOUT_SRC3     (uint32)0x03  ///< LPO clock from PMC
#define CLKOUT_SRC4     (uint32)0x04  ///< IRC clock from MCG
#define CLKOUT_SRC5     (uint32)0x05  ///< Source selected in SIM_SOPT1[OSC32KSEL];
                                      ///  refer to @ref SIM_SelOsc32kClk
#define CLKOUT_SRC6     (uint32)0x06  ///< OSCERCLK external reference clock
#define CLKOUT_SRC7     (uint32)0x07  ///< PLL clock output from MCG
/*! @} End of clkout_src                                                      */
/******************************************************************************
* SAR ADC Trigger clock definitions. Selects the clock used to generate the
* ADC triggers.
*
*//*! @addtogroup adc_trg_clk_src
* @{
* @note During low power modes such as stop, the Bus clock is not available for
* conversion and should not be selected in case a conversion needs to be performed.
*******************************************************************************/
#define SIM_ADCTRGCLK_SRC1 (uint8)0x00  ///< Bus clock (default)
#define SIM_ADCTRGCLK_SRC2 (uint8)0x01  ///< ADC asynchronous clock (ADACK)
#define SIM_ADCTRGCLK_SRC3 (uint8)0x02  ///< Source selected in SIM_SOPT1[OSC32KSEL];
                                        ///  refer to @ref SIM_SelOsc32kClk
#define SIM_ADCTRGCLK_SRC4 (uint8)0x03  ///< OSCCLK
/*! @} End of adc_trg_clk_src                                                 */

/******************************************************************************
* SIM system clock divider definitions used by SIM_SetClkDiv() function
*
*//*! @addtogroup sim_sysdiv
* @{
*******************************************************************************/
#define SYSCLK_DIV1      (uint32)0x00  ///< divide by 01
#define SYSCLK_DIV2      (uint32)0x01  ///< divide by 02
#define SYSCLK_DIV3      (uint32)0x02  ///< divide by 03
#define SYSCLK_DIV4      (uint32)0x03  ///< divide by 04
#define SYSCLK_DIV5      (uint32)0x04  ///< divide by 05
#define SYSCLK_DIV6      (uint32)0x05  ///< divide by 06
#define SYSCLK_DIV7      (uint32)0x06  ///< divide by 07
#define SYSCLK_DIV8      (uint32)0x07  ///< divide by 08
#define SYSCLK_DIV9      (uint32)0x08  ///< divide by 09
#define SYSCLK_DIV10     (uint32)0x09  ///< divide by 10
#define SYSCLK_DIV11     (uint32)0x0a  ///< divide by 11
#define SYSCLK_DIV12     (uint32)0x0b  ///< divide by 12
#define SYSCLK_DIV13     (uint32)0x0c  ///< divide by 13
#define SYSCLK_DIV14     (uint32)0x0d  ///< divide by 14
#define SYSCLK_DIV15     (uint32)0x0e  ///< divide by 15
#define SYSCLK_DIV16     (uint32)0x0f  ///< divide by 16
/*! @} End of sim_sysdiv                                                      */

/******************************************************************************
* SIM system clock mode definitions used by SIM_SetClkMode() function
*
*//*! @addtogroup sim_sysmode
* @{
* @warning Clock limitations:
* |<c> Clock name</c> |<c>Run mode clock frequency</c>|<c>VLPR mode clock frequency</c>|
* |-------------------|:-----------------------------:|:------------------------------:|
* |<c>System clock</c>|<c>       Up to 50 MHz</c>     |<c>        Up to 2 MHz</c>      |
* |<c>Bus clock   </c>|<c>       Up to 25 MHz</c>     |<c>        Up to 1 MHz</c>      |
* |<c>Flash clock </c>|<c>       Up to 25 MHz</c>     |<c>        Up to 1 MHz</c>      |
*******************************************************************************/
#define SYSCLK_MODE0    (uint32)0x00  ///< SYSCLK:BUSCLK:FLASHCLK = 1:1:1
#define SYSCLK_MODE1    (uint32)0x01  ///< SYSCLK:BUSCLK:FLASHCLK = 2:1:1
/*! @} End of sim_sysmode                                                     */

/******************************************************************************
* SIM Clock Source Select for the AFE. Selects between PLL, FLL and OSC clock
* as the source for the PLL clock branch for AFE Clock. Definition used by
* SIM_SelAfePllClk() function.
*
*//*! @addtogroup afe_clk_src
* @{
*******************************************************************************/
#define SIM_MCG_PLL_CLK (uint32)0x00  ///< MCG's PLL clock
#define SIM_MCG_FLL_CLK (uint32)0x01  ///< MCG's FLL clock
#define SIM_OSC_CLK     (uint32)0x02  ///< OSCCLK external reference clock
/*! @} End of afe_clk_src                                                     */

/******************************************************************************
* SIM AFE Modulator Output Select for XBAR (driving XBAR_IN[3]). Definition used
* by SIM_SelXbarAfeModOut() function.
*
*//*! @addtogroup afe_modout_src
* @{
*******************************************************************************/
#define SIM_MOD_AFE_CH0 (uint32)0x00  ///< AFE channel 0 sigma delta modulator output
#define SIM_MOD_AFE_CH1 (uint32)0x01  ///< AFE channel 1 sigma delta modulator output
#define SIM_MOD_AFE_CH2 (uint32)0x02  ///< AFE channel 2 sigma delta modulator output
#define SIM_MOD_AFE_CH3 (uint32)0x03  ///< AFE channel 3 sigma delta modulator output
/*! @} End of afe_modout_src                                                  */

/******************************************************************************
* RTC Clock definitions. Selects between 32KIRC and OSC32K clocks for RTC
* operation.
*
*//*! @addtogroup rtc_clk_src
* @{
*******************************************************************************/
#define SIM_RTCCLK_SRC1 (uint8)0x00   ///< OSC32KCLK (default)
#define SIM_RTCCLK_SRC2 (uint8)0x01   ///< MCG32KIRCLK
/*! @} End of rtc_clk_src                                                     */

/******************************************************************************
* SIM quad timer channel primary count source definitions used by
* SIM_SelTmrPcs() function
*
*//*! @addtogroup tmr_pcs
* @{
*******************************************************************************/
#define SIM_TMR_PCS1    (uint32)0x00  ///< Bus Clock (default)
#define SIM_TMR_PCS2    (uint32)0x01  ///< XBAR_OUT[9]
#define SIM_TMR_PCS3    (uint32)0x02  ///< XBAR_OUT[10]
#define SIM_TMR_PCS4    (uint32)0x03  ///< Disabled
/*! @} End of tmr_pcs                                                         */

/******************************************************************************
* SIM XBAR PIT Output select (driving XBAR_IN[16]). Definition used
* by SIM_SelXbarPitOut() function.
*
*//*! @addtogroup pit_out_src
* @{
*******************************************************************************/
#define SIM_PIT0_CH0    (uint32)0x00  ///< PIT0[0] (default)
#define SIM_PIT0_CH1    (uint32)0x01  ///< PIT0[1]
#define SIM_PIT1_CH0    (uint32)0x02  ///< PIT1[0]
#define SIM_PIT1_CH1    (uint32)0x03  ///< PIT1[1]
/*! @} End of pit_out_src                                                     */

/******************************************************************************
* SIM external watchdog monitor input select. Selects between PTE2 or PTE4
* as selected from pinmux control or XBAR_OUT[32].
* Definition used by SIM_SelEwmInput() function.
*
*//*! @addtogroup ewm_inp_src
* @{
*******************************************************************************/
#define SIM_PORT_PIN    (uint8)0x00  ///< Routed from PTE2 or PTE4 port pin.
#define SIM_XBAR_OUT    (uint8)0x01  ///< Routed from XBAR_OUT[32] internal signal.
/*! @} End of ewm_inp_src                                                     */

/******************************************************************************
* SIM default configurations used by SIM_init() function
*
*//*! @addtogroup sim_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Full configuration.
 * @details Configures System Integration Module to operate with the following
 *          characteristics:
 *  - All peripherals and ports clocked.
 *  - SYSCLK:BUSCLK:FLASHCLK = 2:1:1 clock mode.
 *  - Selects 32 KHz clock source for LPTMR, CLKOUT, LCD, EWM and WDOG.
 *  - Bitline precharge of system SRAM disabled during VLPR and VLPW modes.
 *  - Source bias of System SRAM enabled during VLPR and VLPW modes.
 *  - CMP[1] output selected as LPTMR input[0].
 *  - LP Timer channel3 sourced from PTD5.
 *  - LP Timer channel2 sourced from PTD6.
 *  - LP Timer channel1 sourced from PTE4.
 *  - Clock out select disabled.
 *  - BUSCLK is used as SAR ADC Trigger clock.
 *  - PTC2 High Drive disabled.
 *  - PLL disabled in VLP mode.
 *  - NMI Disabled (enabled after POR)
 *  - Self-time adjust for System RAM enabled.
 *  - All peripherals and ports clocked.
 *  - Vref buffer power down (when enabled it drives SAR, DAC and output PAD)).
 *  - Internal reference selected as vref buffer input.
 *  - Vref buffer does not drive PAD.
 *  - RTC OSC_32K clock selected as the RTC clock source.
 *  - Bus Clock selected as Timer Channel3 Primary Count Source.
 *  - Bus Clock selected as Timer Channel2 Primary Count Source.
 *  - Bus Clock selected as Timer Channel1 Primary Count Source.
 *  - Bus Clock selected as Timer Channel0 Primary Count Source.
 *  - Pad PTE5 or PTD1 drives Timer Channel3 Secondary Count Source.
 *  - Pad PTF7 or PTF0 drives Timer Channel2 Secondary Count Source.
 *  - Pad PTG0 or PTC6 drives Timer Channel1 Secondary Count Source.
 *  - Pad PTF1 or PTD5 drives Timer Channel0 Secondary Count Source.
 *  - Bus Clock selected as source for the Timer CH0.
 *  - External watchdog monitor input sourced from PTE2 or PTE4
 *  - PIT0[0] drives XBAR_IN[16].
 *  - IR modulation disabled on all UARTs.
 *  - TypeA (OR'ed) modulation selected for IRDA.
 *  - AFE CLK PAD is input.
 *  - AFE clocked from MCG PLL Clock Source.
 *  - DMA Done flag driven by DMA0.
 *  - Sigma Delta Modulator 0 data signal drives XBAR_IN[3].
 * @showinitializer
 *****************************************************************************/
#define SIM_MODULE_ALL_PERIPH_ON_CONFIG                                         \
(tSIM){                                                                         \
/* SOPT1    */ SET(SIM_SOPT1_OSC32KSEL(0)),                                     \
/* SOPT1_CFG*/ CLR(SIM_SOPT1_CFG_RAMBPEN_MASK)|CLR(SIM_SOPT1_CFG_RAMSBDIS_MASK)|\
/* .........*/ CLR(SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK)|                           \
/* .........*/ SET(SIM_SOPT1_CFG_LPTMR3SEL(0))|SET(SIM_SOPT1_CFG_LPTMR2SEL(0))| \
/* .........*/ SET(SIM_SOPT1_CFG_LPTMR1SEL(0)),                                 \
/* CTRL_REG */ SET(SIM_CTRL_REG_CLKOUTSEL(0))|                                  \
/* ........ */ SET(SIM_CTRL_REG_SAR_TRG_CLK_SEL(0))|                            \
/* ........ */ CLR(SIM_CTRL_REG_PTC2_HD_EN_MASK)|                               \
/* ........ */ CLR(SIM_CTRL_REG_PLL_VLP_EN_MASK)|SET(SIM_CTRL_REG_NMIDIS_MASK), \
/* SCGC4    */ SET(SIM_SCGC4_SPI1_MASK)|SET(SIM_SCGC4_SPI0_MASK)|               \
/* .....    */ SET(SIM_SCGC4_CMP1_MASK)|SET(SIM_SCGC4_CMP0_MASK)|               \
/* .....    */ SET(SIM_SCGC4_VREF_MASK)|SET(SIM_SCGC4_UART3_MASK)|              \
/* .....    */ SET(SIM_SCGC4_UART2_MASK)|SET(SIM_SCGC4_UART1_MASK)|             \
/* .....    */ SET(SIM_SCGC4_UART0_MASK)|SET(SIM_SCGC4_I2C1_MASK)|              \
/* .....    */ SET(SIM_SCGC4_I2C0_MASK)|SET(SIM_SCGC4_OSC_MASK)|                \
/* .....    */ SET(SIM_SCGC4_MCG_MASK)|SET(SIM_SCGC4_EWM_MASK),                 \
/* SCGC5    */ SET(SIM_SCGC5_TMR3_MASK)|SET(SIM_SCGC5_TMR2_MASK)|               \
/* .....    */ SET(SIM_SCGC5_TMR1_MASK)|SET(SIM_SCGC5_TMR0_MASK)|               \
/* .....    */ SET(SIM_SCGC5_XBAR_MASK)|SET(SIM_SCGC5_WDOG_MASK)|               \
/* .....    */ SET(SIM_SCGC5_IRTCREGFILE_MASK)|SET(SIM_SCGC5_IRTC_MASK)|        \
/* .....    */ SET(SIM_SCGC5_PORTI_MASK)|SET(SIM_SCGC5_PORTH_MASK)|             \
/* .....    */ SET(SIM_SCGC5_PORTG_MASK)|SET(SIM_SCGC5_PORTF_MASK)|             \
/* .....    */ SET(SIM_SCGC5_PORTE_MASK)|SET(SIM_SCGC5_PORTD_MASK)|             \
/* .....    */ SET(SIM_SCGC5_PORTC_MASK)|SET(SIM_SCGC5_PORTB_MASK)|             \
/* .....    */ SET(SIM_SCGC5_PORTA_MASK)|SET(SIM_SCGC5_SLCD_MASK),              \
/* SCGC6    */ SET(SIM_SCGC6_SIM_LP_MASK)|                                      \
/* .....    */ SET(SIM_SCGC6_LPTMR_MASK)|SET(SIM_SCGC6_CRC_MASK)|               \
/* .....    */ SET(SIM_SCGC6_AFE_MASK)|SET(SIM_SCGC6_PIT1_MASK)|                \
/* .....    */ SET(SIM_SCGC6_PIT0_MASK)|SET(SIM_SCGC6_ADC_MASK)|                \
/* .....    */ SET(SIM_SCGC6_RNGA_MASK)|SET(SIM_SCGC6_DMAMUX3_MASK)|            \
/* .....    */ SET(SIM_SCGC6_DMAMUX2_MASK)|SET(SIM_SCGC6_DMAMUX1_MASK)|         \
/* .....    */ SET(SIM_SCGC6_DMAMUX0_MASK)|SET(SIM_SCGC6_FTFA_MASK),            \
/* SCGC7    */ SET(SIM_SCGC7_DMA_MASK)|SET(SIM_SCGC7_MPU_MASK),                 \
/* CLKDIV1  */ SET(SIM_CLKDIV1_SYSDIV(SYSCLK_DIV1))|                            \
/* .......  */ SET(SIM_CLKDIV1_SYSCLKMODE_MASK),                                \
/* FCCFG1   */ CLR(SIM_FCFG1_FLASHDOZE_MASK)|CLR(SIM_FCFG1_FLASHDIS_MASK),      \
/* MISC_CTL */ CLR(SIM_MISC_CTL_VREFBUFPD_MASK)|                                \
/* ........ */ CLR(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                             \
/* ........ */ CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK)|                             \
/* ........ */ CLR(SIM_MISC_CTL_RTCCLKSEL_MASK)|                                \
/* ........ */ SET(SIM_MISC_CTL_TMR3PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR2PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR1PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR0PCSSEL(0))|                                 \
/* ........ */ CLR(SIM_MISC_CTL_TMR3SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR2SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR1SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR0SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR0PLLCLKSEL_MASK)|                            \
/* ........ */ CLR(SIM_MISC_CTL_EWMINSEL_MASK)|                                 \
/* ........ */ SET(SIM_MISC_CTL_XBARPITOUTSEL(0))|                              \
/* ........ */ CLR(SIM_MISC_CTL_UART3IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART2IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART1IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART0IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UARTMODTYPE_MASK)|                              \
/* ........ */ CLR(SIM_MISC_CTL_AFECLKPADDIR_MASK)|                             \
/* ........ */ SET(SIM_MISC_CTL_AFECLKSEL(0))|                                  \
/* ........ */ SET(SIM_MISC_CTL_DMADONESEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_XBARAFEMODOUTSEL(0)),                           \
}

/***************************************************************************//*!
 * @brief   Minimum configuration.
 * @details Configures System Integration Module to operate with the following
 *          characteristics:
 *  - Only peripherals that are necessary for device operation are clocked.
 *  - SYSCLK:BUSCLK:FLASHCLK = 2:1:1 clock mode.
 *  - Selects 32 KHz clock source for LPTMR, CLKOUT, LCD, EWM and WDOG.
 *  - Bitline precharge of system SRAM disabled during VLPR and VLPW modes.
 *  - Source bias of System SRAM enabled during VLPR and VLPW modes.
 *  - CMP[1] output selected as LPTMR input[0].
 *  - LP Timer channel3 sourced from PTD5.
 *  - LP Timer channel2 sourced from PTD6.
 *  - LP Timer channel1 sourced from PTE4.
 *  - Clock out select disabled.
 *  - BUSCLK is used as SAR ADC Trigger clock.
 *  - PTC2 High Drive disabled.
 *  - PLL disabled in VLP mode.
 *  - NMI Disabled (enabled after POR).
 *  - Self-time adjust for System RAM enabled.
 *  - Vref buffer powered down.
 *  - Vref buffer powered down (when enabled it drives SAR, DAC and output PAD)).
 *  - Internal reference selected as vref buffer input.
 *  - Vref buffer does not drive PAD.
 *  - RTC OSC_32K clock selected as the RTC clock source.
 *  - Bus Clock selected as Timer Channel3 Primary Count Source.
 *  - Bus Clock selected as Timer Channel2 Primary Count Source.
 *  - Bus Clock selected as Timer Channel1 Primary Count Source.
 *  - Bus Clock selected as Timer Channel0 Primary Count Source.
 *  - Pad PTE5 or PTD1 drives Timer Channel3 Secondary Count Source.
 *  - Pad PTF7 or PTF0 drives Timer Channel2 Secondary Count Source.
 *  - Pad PTG0 or PTC6 drives Timer Channel1 Secondary Count Source.
 *  - Pad PTF1 or PTD5 drives Timer Channel0 Secondary Count Source.
 *  - Bus Clock selected as source for the Timer CH0.
 *  - External watchdog monitor input sourced from PTE2 or PTE4
 *  - PIT0[0] drives XBAR_IN[16].
 *  - IR modulation disabled on all UARTs.
 *  - TypeA (OR'ed) modulation selected for IRDA.
 *  - AFE CLK PAD is input.
 *  - AFE clocked from MCG PLL Clock Source.
 *  - DMA Done flag driven by DMA0.
 *  - Sigma Delta Modulator 0 data signal drives XBAR_IN[3].
 * @showinitializer
 *****************************************************************************/
#define SIM_MODULE_ALL_PERIPH_OFF_CONFIG                                        \
(tSIM){                                                                         \
/* SOPT1    */ SET(SIM_SOPT1_OSC32KSEL(0)),                                     \
/* SOPT1_CFG*/ CLR(SIM_SOPT1_CFG_RAMBPEN_MASK)|CLR(SIM_SOPT1_CFG_RAMSBDIS_MASK)|\
/* .........*/ CLR(SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK)|                           \
/* .........*/ SET(SIM_SOPT1_CFG_LPTMR3SEL(0))|SET(SIM_SOPT1_CFG_LPTMR2SEL(0))| \
/* .........*/ SET(SIM_SOPT1_CFG_LPTMR1SEL(0)),                                 \
/* CTRL_REG */ SET(SIM_CTRL_REG_CLKOUTSEL(0))|                                  \
/* ........ */ SET(SIM_CTRL_REG_SAR_TRG_CLK_SEL(0))|                            \
/* ........ */ CLR(SIM_CTRL_REG_PTC2_HD_EN_MASK)|                               \
/* ........ */ CLR(SIM_CTRL_REG_PLL_VLP_EN_MASK)|SET(SIM_CTRL_REG_NMIDIS_MASK), \
/* SCGC4    */ CLR(SIM_SCGC4_SPI1_MASK)|CLR(SIM_SCGC4_SPI0_MASK)|               \
/* .....    */ CLR(SIM_SCGC4_CMP1_MASK)|CLR(SIM_SCGC4_CMP0_MASK)|               \
/* .....    */ CLR(SIM_SCGC4_VREF_MASK)|CLR(SIM_SCGC4_UART3_MASK)|              \
/* .....    */ CLR(SIM_SCGC4_UART2_MASK)|CLR(SIM_SCGC4_UART1_MASK)|             \
/* .....    */ CLR(SIM_SCGC4_UART0_MASK)|CLR(SIM_SCGC4_I2C1_MASK)|              \
/* .....    */ CLR(SIM_SCGC4_I2C0_MASK)|CLR(SIM_SCGC4_OSC_MASK)|                \
/* .....    */ CLR(SIM_SCGC4_MCG_MASK)|CLR(SIM_SCGC4_EWM_MASK),                 \
/* SCGC5    */ CLR(SIM_SCGC5_TMR3_MASK)|CLR(SIM_SCGC5_TMR2_MASK)|               \
/* .....    */ CLR(SIM_SCGC5_TMR1_MASK)|CLR(SIM_SCGC5_TMR0_MASK)|               \
/* .....    */ CLR(SIM_SCGC5_XBAR_MASK)|CLR(SIM_SCGC5_WDOG_MASK)|               \
/* .....    */ SET(SIM_SCGC5_IRTCREGFILE_MASK)|SET(SIM_SCGC5_IRTC_MASK)|        \
/* .....    */ CLR(SIM_SCGC5_PORTI_MASK)|CLR(SIM_SCGC5_PORTH_MASK)|             \
/* .....    */ CLR(SIM_SCGC5_PORTG_MASK)|CLR(SIM_SCGC5_PORTF_MASK)|             \
/* .....    */ CLR(SIM_SCGC5_PORTE_MASK)|CLR(SIM_SCGC5_PORTD_MASK)|             \
/* .....    */ CLR(SIM_SCGC5_PORTC_MASK)|CLR(SIM_SCGC5_PORTB_MASK)|             \
/* .....    */ CLR(SIM_SCGC5_PORTA_MASK)|CLR(SIM_SCGC5_SLCD_MASK),              \
/* SCGC6    */ SET(SIM_SCGC6_SIM_LP_MASK)|                                      \
/* .....    */ CLR(SIM_SCGC6_LPTMR_MASK)|CLR(SIM_SCGC6_CRC_MASK)|               \
/* .....    */ CLR(SIM_SCGC6_AFE_MASK)|CLR(SIM_SCGC6_PIT1_MASK)|                \
/* .....    */ CLR(SIM_SCGC6_PIT0_MASK)|CLR(SIM_SCGC6_ADC_MASK)|                \
/* .....    */ CLR(SIM_SCGC6_RNGA_MASK)|CLR(SIM_SCGC6_DMAMUX3_MASK)|            \
/* .....    */ CLR(SIM_SCGC6_DMAMUX2_MASK)|CLR(SIM_SCGC6_DMAMUX1_MASK)|         \
/* .....    */ CLR(SIM_SCGC6_DMAMUX0_MASK)|SET(SIM_SCGC6_FTFA_MASK),            \
/* SCGC7    */ CLR(SIM_SCGC7_DMA_MASK)|CLR(SIM_SCGC7_MPU_MASK),                 \
/* CLKDIV1  */ SET(SIM_CLKDIV1_SYSDIV(SYSCLK_DIV1))|                            \
/* .......  */ SET(SIM_CLKDIV1_SYSCLKMODE_MASK),                                \
/* FCCFG1   */ CLR(SIM_FCFG1_FLASHDOZE_MASK)|CLR(SIM_FCFG1_FLASHDIS_MASK),      \
/* MISC_CTL */ SET(SIM_MISC_CTL_VREFBUFPD_MASK)|                                \
/* ........ */ CLR(SIM_MISC_CTL_VREFBUFINSEL_MASK)|                             \
/* ........ */ CLR(SIM_MISC_CTL_VREFBUFOUTEN_MASK)|                             \
/* ........ */ CLR(SIM_MISC_CTL_RTCCLKSEL_MASK)|                                \
/* ........ */ SET(SIM_MISC_CTL_TMR3PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR2PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR1PCSSEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_TMR0PCSSEL(0))|                                 \
/* ........ */ CLR(SIM_MISC_CTL_TMR3SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR2SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR1SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR0SCSSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_TMR0PLLCLKSEL_MASK)|                            \
/* ........ */ CLR(SIM_MISC_CTL_EWMINSEL_MASK)|                                 \
/* ........ */ SET(SIM_MISC_CTL_XBARPITOUTSEL(0))|                              \
/* ........ */ CLR(SIM_MISC_CTL_UART3IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART2IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART1IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UART0IRSEL_MASK)|                               \
/* ........ */ CLR(SIM_MISC_CTL_UARTMODTYPE_MASK)|                              \
/* ........ */ CLR(SIM_MISC_CTL_AFECLKPADDIR_MASK)|                             \
/* ........ */ SET(SIM_MISC_CTL_AFECLKSEL(0))|                                  \
/* ........ */ SET(SIM_MISC_CTL_DMADONESEL(0))|                                 \
/* ........ */ SET(SIM_MISC_CTL_XBARAFEMODOUTSEL(0)),                           \
}
/*! @} End of sim_config                                                      */

/******************************************************************************
* SIM function and macro definitions
*
*//*! @addtogroup sim_macro
* @{
*******************************************************************************/
/* System Clock Gating Control register bits definition for use with          */
/* SIM_EnablePeripheral() and SIM_DisablePeripheral() macros                  */
#define SCGC_SPI0        {(long *)&SIM_SCGC4, SIM_SCGC4_SPI0_MASK       }
#define SCGC_SPI1        {(long *)&SIM_SCGC4, SIM_SCGC4_SPI1_MASK       }
#define SCGC_CMP1        {(long *)&SIM_SCGC4, SIM_SCGC4_CMP1_MASK       }
#define SCGC_CMP0        {(long *)&SIM_SCGC4, SIM_SCGC4_CMP0_MASK       }
#define SCGC_VREF        {(long *)&SIM_SCGC4, SIM_SCGC4_VREF_MASK       }
#define SCGC_UART3       {(long *)&SIM_SCGC4, SIM_SCGC4_UART3_MASK      }
#define SCGC_UART2       {(long *)&SIM_SCGC4, SIM_SCGC4_UART2_MASK      }
#define SCGC_UART1       {(long *)&SIM_SCGC4, SIM_SCGC4_UART1_MASK      }
#define SCGC_UART0       {(long *)&SIM_SCGC4, SIM_SCGC4_UART0_MASK      }
#define SCGC_I2C1        {(long *)&SIM_SCGC4, SIM_SCGC4_I2C1_MASK       }
#define SCGC_I2C0        {(long *)&SIM_SCGC4, SIM_SCGC4_I2C0_MASK       }
#define SCGC_OSC         {(long *)&SIM_SCGC4, SIM_SCGC4_OSC_MASK        }
#define SCGC_MCG         {(long *)&SIM_SCGC4, SIM_SCGC4_MCG_MASK        }
#define SCGC_EWM         {(long *)&SIM_SCGC4, SIM_SCGC4_EWM_MASK        }

#define SCGC_TMR3        {(long *)&SIM_SCGC5, SIM_SCGC5_TMR3_MASK       }
#define SCGC_TMR2        {(long *)&SIM_SCGC5, SIM_SCGC5_TMR2_MASK       }
#define SCGC_TMR1        {(long *)&SIM_SCGC5, SIM_SCGC5_TMR1_MASK       }
#define SCGC_TMR0        {(long *)&SIM_SCGC5, SIM_SCGC5_TMR0_MASK       }
#define SCGC_XBAR        {(long *)&SIM_SCGC5, SIM_SCGC5_XBAR_MASK       }
#define SCGC_WDOG        {(long *)&SIM_SCGC5, SIM_SCGC5_WDOG_MASK       }
#define SCGC_IRTCREGFILE {(long *)&SIM_SCGC5, SIM_SCGC5_IRTCREGFILE_MASK}
#define SCGC_IRTC        {(long *)&SIM_SCGC5, SIM_SCGC5_IRTC_MASK       }
#define SCGC_PORTI       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTI_MASK      }
#define SCGC_PORTH       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTH_MASK      }
#define SCGC_PORTG       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTG_MASK      }
#define SCGC_PORTF       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTF_MASK      }
#define SCGC_PORTE       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTE_MASK      }
#define SCGC_PORTD       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTD_MASK      }
#define SCGC_PORTC       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTC_MASK      }
#define SCGC_PORTB       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTB_MASK      }
#define SCGC_PORTA       {(long *)&SIM_SCGC5, SIM_SCGC5_PORTA_MASK      }
#define SCGC_SLCD        {(long *)&SIM_SCGC5, SIM_SCGC5_SLCD_MASK       }

#define SCGC_SIM_LP      {(long *)&SIM_SCGC6, SIM_SCGC6_SIM_LP_MASK     }
#define SCGC_LPTMR       {(long *)&SIM_SCGC6, SIM_SCGC6_LPTMR_MASK      }
#define SCGC_CRC         {(long *)&SIM_SCGC6, SIM_SCGC6_CRC_MASK        }
#define SCGC_AFE         {(long *)&SIM_SCGC6, SIM_SCGC6_AFE_MASK        }
#define SCGC_PIT1        {(long *)&SIM_SCGC6, SIM_SCGC6_PIT1_MASK       }
#define SCGC_PIT0        {(long *)&SIM_SCGC6, SIM_SCGC6_PIT0_MASK       }
#define SCGC_ADC         {(long *)&SIM_SCGC6, SIM_SCGC6_ADC_MASK        }
#define SCGC_RNGA        {(long *)&SIM_SCGC6, SIM_SCGC6_RNGA_MASK       }
#define SCGC_DMAMUX3     {(long *)&SIM_SCGC6, SIM_SCGC6_DMAMUX3_MASK    }
#define SCGC_DMAMUX2     {(long *)&SIM_SCGC6, SIM_SCGC6_DMAMUX2_MASK    }
#define SCGC_DMAMUX1     {(long *)&SIM_SCGC6, SIM_SCGC6_DMAMUX1_MASK    }
#define SCGC_DMAMUX0     {(long *)&SIM_SCGC6, SIM_SCGC6_DMAMUX0_MASK    }
#define SCGC_FTFA        {(long *)&SIM_SCGC6, SIM_SCGC6_FTFA_MASK       }

#define SCGC_DMA         {(long *)&SIM_SCGC7, SIM_SCGC7_DMA_MASK        }
#define SCGC_MPU         {(long *)&SIM_SCGC7, SIM_SCGC7_MPU_MASK        }
/***************************************************************************//*!
 * @brief   Enables clock to selected on-chip module.
 * @details This macro enables clock to selected on-chip module.
 * @param   mask  Select peripheral: SPI0,SPI1,CMP1,CMP0,VREF,UART3,UART2,UART1,
 *                UART0,I2C1,I2C0,OSC,MCG,EWM,TMR3,TMR2,TMR1,TMR0,XBAR,WDOG,
 *                IRTCREGFILE,IRTC,PORTI,PORTH,PORTG,PORTF,PORTE,PORTD,PORTC,
 *                PORTB,PORTA,SLCD,SIM_LP,LPTMR,CRC,AFE,PIT1,PIT0,ADC,RNGA,
 *                DMAMUX3,DMAMUX2,DMAMUX1,DMAMUX0,FTFA,DMA,MPU.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_DisableModule
 ******************************************************************************/
#define SIM_EnableModule(mask)                                                \
{                                                                             \
  register struct SCGC {long *ptr; long mask;} scgc = SCGC_##mask;            \
  iosetw  (*(scgc.ptr), scgc.mask);                                           \
}

/***************************************************************************//*!
 * @brief   Disables clock to selected on-chip peripheral.
 * @details This macro disables clock to selected on-chip peripheral.
 * @param   mask  Select peripheral: SPI0,SPI1,CMP1,CMP0,VREF,UART3,UART2,UART1,
 *                UART0,I2C1,I2C0,OSC,MCG,EWM,TMR3,TMR2,TMR1,TMR0,XBAR,WDOG,
 *                IRTCREGFILE,IRTC,PORTI,PORTH,PORTG,PORTF,PORTE,PORTD,PORTC,
 *                PORTB,PORTA,SLCD,SIM_LP,LPTMR,CRC,AFE,PIT1,PIT0,ADC,RNGA,
 *                DMAMUX3,DMAMUX2,DMAMUX1,DMAMUX0,FTFA,DMA,MPU.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_EnableModule
 ******************************************************************************/
#define SIM_DisableModule(mask)                                               \
{                                                                             \
  register struct SCGC {long *ptr; long mask;} scgc = SCGC_##mask;            \
  ioclrw (*(scgc.ptr), scgc.mask);                                            \
}
/***************************************************************************//*!
 * @brief   Selects the 32 KHz clock source for LPTMR, CLKOUT, LCD, EWM and WDOG.
 * @details This macro selects the 32 KHz clock source for LPTMR, CLKOUT, LCD,
 *          EWM and WDOG.
 * @param   src   Select one of the @ref osc32k_clk_src.
 * @note    Implemented as an inline macro.
 * @warning This bit is reset only on POR/LVD.
 ******************************************************************************/
#define SIM_SelOsc32kClk(src)                                                 \
                    iobfiw (SIM_SOPT1,SIM_SOPT1_OSC32KSEL_SHIFT,2,src)

/***************************************************************************//*!
 * @brief   Selects clock source for CLKOUT port pins.
 * @details This macro selects clock source for CLKOUT port pins.
 * @param   src   Select one of the @ref clkout_src.
 * @note    Implemented as an inline macro.
 * @see     @ref IRTC_SelRtcClkout
 ******************************************************************************/
#define SIM_SelClkout(src)                                                    \
                    iobfiw (SIM_CTRL_REG,SIM_CTRL_REG_CLKOUTSEL_SHIFT,3,src)

/***************************************************************************//*!
 * @brief   Selects clock source used to generate the SAR ADC triggers.
 * @details This macro selects clock source used to generate the triggers for
 *          SAR ADC.
 * @param   src   Select one of the @ref adc_trg_clk_src.
 * @note    Implemented as an inline macro
 * @warning Default option @ref SIM_ADCTRGCLK_SRC1 (Bus clock) is not available
 *          for conversion and should not be selected in case a conversion needs
 *          to be performed while in STOP or VLPS modes.
 ******************************************************************************/
#define SIM_SelAdcTrgClk(src)                                                 \
                    iobfiw (SIM_CTRL_REG,SIM_CTRL_REG_ADCTRGSEL_SHIFT,2,src)

/***************************************************************************//*!
 * @brief   Enable/disable PLL operation in VLPR/PSTOP1 mode.
 * @details This macro enables/disables PLL operation in VLPR/PSTOP1 mode.
 * @param   x   TRUE  PLL operation is enabled in VLPR/PSTOP1 mode\n
 *              FALSE PLL operation is disabled in VLPR/PSTOP1 mode (default).
 * @note    Implemented as an inline macro.
 * @see     @ref PLL_Enable, @ref PLL_Init, @ref PLL_CtrlPLLSTEN
 ******************************************************************************/
#define SIM_CtrlPLLVLP(x)                                                     \
                    iobfiw (SIM_CTRL_REG,SIM_CTRL_REG_PLLVLPEN_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Disables Non-Maskable Interrupt (NMI) temporarily.
 * @details This macro disables Non-Maskable Interrupt (NMI) temporarily.
 * @note    Implemented as an inline macro.
 * @warning Disable NMI functionality on the pin whenever it is used as the GPIO
 *          or in any alternate assignment.
 * @see     @ref SIM_EnableNMI
 ******************************************************************************/
#define SIM_DisableNMI()        iosetw (SIM_CTRL_REG,SIM_CTRL_REG_NMIDIS_MASK)

/***************************************************************************//*!
 * @brief   Enables Non-Maskable Interrupt (NMI) temporarily.
 * @details This macro enables Non-Maskable Interrupt (NMI) temporarily.
 * @note    Implemented as an inline macro.
 * @warning Do Not enable NMI functionality on the pin unless it is assigned to
 *          NMI.
 * @see     @ref SIM_DisableNMI
 ******************************************************************************/
#define SIM_EnableNMI()         ioclrw (SIM_CTRL_REG,SIM_CTRL_REG_NMIDIS_MASK)

/***************************************************************************//*!
 * @brief   Sets system clock divider mode.
 * @details This macro sets system clock divider.
 * @param   div   Select one of the @ref sim_sysdiv.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SetClkMode
 ******************************************************************************/
#define SIM_SetClkDiv(div)                                                    \
                    iobfiw (SIM_CLKDIV1,SIM_CLKDIV1_SYSDIV_SHIFT,4,div)

/***************************************************************************//*!
 * @brief   Sets system clock mode.
 * @details This macro sets system clock mode ratio: SYSCLK : BUSCLK : FLASHCLK.
 * @param   mode  Select one of the @ref sim_sysmode.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SetClkDiv
 ******************************************************************************/
#define SIM_SetClkMode(mode)                                                  \
                    iobfiw (SIM_CLKDIV1,SIM_CLKDIV1_SYSCLKMODE_SHIFT,1,mode)

/***************************************************************************//*!
 * @brief   Enables Flash Doze in Wait mode.
 * @details This macro enables Flash Doze in Wait mode. Flash memory will be
 *          disabled for the duration of Wait mode. An attempt by the DMA or
 *          other bus master to access the Flash when the Flash is disabled will
 *          result in a bus error. The wakeup time from Wait mode is extended
 *          when this bit is set.
 * @note    Implemented as an inline macro.
 * @warning This bit should be clear during VLP modes.
 * @warning The Flash will be automatically enabled again at the end of Wait
 *          mode so interrupt vectors do not need to be relocated out of Flash
 *          memory.
 * @see     @ref SIM_DisableFlashDoze
 ******************************************************************************/
#define SIM_EnableFlashDoze()   iosetw (SIM_FCFG1,SIM_FCFG1_FLASHDOZE_MASK)

/***************************************************************************//*!
 * @brief   Disable Flash Doze in Wait mode.
 * @details This macro disables Flash Doze in Wait mode.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_EnableFlashDoze
 ******************************************************************************/
#define SIM_DisableFlashDoze()  ioclrw (SIM_FCFG1,SIM_FCFG1_FLASHDOZE_MASK)

/***************************************************************************//*!
 * @brief   Enables flash accesses.
 * @details This macro enables flash accesses.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_DisableFlash
 ******************************************************************************/
#define SIM_EnableFlash()       ioclrw (SIM_FCFG1,SIM_FCFG1_FLASHDIS_MASK)

/***************************************************************************//*!
 * @brief   Disables flash accesses and places flash memory in low power state.
 * @details This macro disables flash accesses and places flash memory in low
 *          power state.
 * @note    Implemented as an inline macro.
 * @warning This macro should not be called during VLP modes. Relocate the
 *          interrupt vectors out of flash memory before calling this macro.
 * @see     @ref SIM_EnableFlash
 ******************************************************************************/
#define SIM_DisableFlash()      iosetw (SIM_FCFG1,SIM_FCFG1_FLASHDIS_MASK)

/***************************************************************************//*!
 * @brief   Selects between 32KIRC and OSC32K clock sources for RTC operation.
 * @details This macro selects between 32KIRC and OSC32K clock sources for RTC
 *          operation.
 * @param   src   Select one of the @ref rtc_clk_src.
 * @note    Implemented as an inline macro.
 * @warning This bit is reset only on POR/LVD.
 ******************************************************************************/
#define SIM_SelRtcClk(src)                                                    \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_RTCCLKSEL_SHIFT,1,src)

/***************************************************************************//*!
 * @brief   Selects AFE_CLK pin direction.
 * @details This macro selects direction of the AFE_CLK pin.
 * @param   dir   TRUE  AFE CLK PAD is output\n
 *                FALSE AFE CLK PAD is input (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelAfeClkPadDir(dir)                                              \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_AFECLKPADDIR_SHIFT,1,dir)

/***************************************************************************//*!
 * @brief   Selects AFE Modulator Output to drive XBAR_IN[3].
 * @details This macro selects field selects modulator data output of the
 *          respective AFE channel to drive XBAR_IN[3].
 * @param   src   Select one of the @ref afe_modout_src.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelXbarAfeModOut(src)                                             \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT,2,src)

/***************************************************************************//*!
 * @brief   Selects PIT Timer and Timer channel to drive XBAR_IN[16].
 * @details This macro selects PIT Timer and Timer channel to drive XBAR_IN[16].
 * @param   src   Select one of the @ref pit_out_src.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelXbarPitOut(src)                                                \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_XBARPITOUTSEL_SHIFT,2,src)

#define SIMCH0_SelTmrPcs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR0PCSSEL_SHIFT,2,src)
#define SIMCH1_SelTmrPcs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR1PCSSEL_SHIFT,2,src)
#define SIMCH2_SelTmrPcs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR2PCSSEL_SHIFT,2,src)
#define SIMCH3_SelTmrPcs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR3PCSSEL_SHIFT,2,src)
/***************************************************************************//*!
 * @brief   Selects quad timer channel primary count source.
 * @details This macro selects quad timer channel primary count source.
 * @param   ch    CH0,CH1,CH2,CH3.
 * @param   src   Select one of the @ref tmr_pcs.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelTmrScs, @ref TMR_Init, @ref XBAR_Path
 ******************************************************************************/
#define SIM_SelTmrPcs(ch,src)   SIM##ch##_SelTmrPcs(src)

#define SIMCH0_SelTmrScs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR0SCSEL_SHIFT,1,src)
#define SIMCH1_SelTmrScs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR1SCSEL_SHIFT,1,src)
#define SIMCH2_SelTmrScs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR2SCSEL_SHIFT,1,src)
#define SIMCH3_SelTmrScs(src)                                                 \
                      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR3SCSEL_SHIFT,1,src)
/***************************************************************************//*!
 * @brief   Selects quad timer channel secondary count source.
 * @details This macro selects quad timer channel secondary count source.
 * @param   ch  CH0,CH1,CH2,CH3.
 * @param   src Refer to the following table:
 * |<c>Channel</c>|<c>src=TRUE</c>   |<c>src=FALSE (default)</c>|<c>Secondary count source</c>|
 * |:------------:|:----------------:|:------------------------:|:---------------------------:|
 * |<c>CH0</c>    |<c>XBAR_OUT[5]</c>|<c> PTF1 or PTD5</c>      |<c>@ref SEC_CNTR0_INP</c>    |
 * |<c>CH1</c>    |<c>XBAR_OUT[6]</c>|<c> PTG0 or PTC6</c>      |<c>@ref SEC_CNTR1_INP</c>    |
 * |<c>CH2</c>    |<c>XBAR_OUT[7]</c>|<c> PTF7 or PTF0</c>      |<c>@ref SEC_CNTR2_INP</c>    |
 * |<c>CH3</c>    |<c>XBAR_OUT[8]</c>|<c> PTE5 or PTD1</c>      |<c>@ref SEC_CNTR3_INP</c>    |
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelTmrPcs, @ref TMR_Init, @ref XBAR_Path
 ******************************************************************************/
#define SIM_SelTmrScs(ch,src)   SIM##ch##_SelTmrScs(src)

/***************************************************************************//*!
 * @brief   Selects Timer CH0 clock source.
 * @details This macro selects either Bus Clock or PLL AFE clock as the source
 *          for Timer CH0. The Timer CH0 output can be used as the AFE clock
 *          source.
 * @param   src TRUE  Selects the PLL_AFE clock as the source for Timer CH0\n
 *              FALSE Selects Bus Clock as source for the Timer CH0 (default).
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelAfePllClk
 ******************************************************************************/
#define SIM_SelTmrCh0Clk(src)                                                 \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_TMR0PLLSEL_SHIFT,1,src)
#define SIMUART0_SelUartIR(src)                                               \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_UART0IRSEL_SHIFT,1,src)
#define SIMUART1_SelUartIR(src)                                               \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_UART1IRSEL_SHIFT,1,src)
#define SIMUART2_SelUartIR(src)                                               \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_UART2IRSEL_SHIFT,1,src)
#define SIMUART3_SelUartIR(src)                                               \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_UART3IRSEL_SHIFT,1,src)
/***************************************************************************//*!
 * @brief   Selects uart source for driving IR communication.
 * @details This macro selects uart source for driving IR communication.
 * @param   ch  UART0,UART1,UART2,UART3.
 * @param   src Refer to the following table:
 * |<c>Channel</c>|<c>src=FALSE (default)</c>  |<c>src=TRUE</c>                                                   |
 * |:------------:|:---------------------------|:-----------------------------------------------------------------|
 * |<c>UART0</c>  |<c>RX=PTD0, PTF3 or PTK3</c>|<c>RX=>XBAR_OUT[13],TX modulated by XBAR_OUT[14]=>XBAR_INP[14]</c>|
 * |<c>UART1</c>  |<c>RX=PTD2, PTI0 or PTK5</c>|<c>RX=>XBAR_OUT[13],TX modulated by XBAR_OUT[14]=>XBAR_INP[14]</c>|
 * |<c>UART2</c>  |<c>RX=PTI6 or PTE6      </c>|<c>RX=>XBAR_OUT[13],TX modulated by XBAR_OUT[14]=>XBAR_INP[14]</c>|
 * |<c>UART3</c>  |<c>RX=PTD7 or PTC3      </c>|<c>RX=>XBAR_OUT[13],TX modulated by XBAR_INP[14]=>XBAR_INP[14]</c>|
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelUartIR(ch,src)    SIM##ch##_SelUartIR(src)

/***************************************************************************//*!
 * @brief   Selects modulation type for IR communication.
 * @details This macro selects modulation type for IR communication.
 * @param   x   TRUE  TypeB (ANDed) Modulation selected for IRDA\n
 *              FALSE TypeA (ORed) Modulation selected for IRDA (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelModTypeIR(x)      iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_UARTMODTYPE_SHIFT,1,x)

/***************************************************************************//*!
 * @brief   Selects AFE_CLK pin direction.
 * @details This macro selects direction of the AFE_CLK pin.
 * @param   dir   TRUE  AFE CLK PAD is output\n
 *                FALSE AFE CLK PAD is input (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelAfeClkPadDir(dir)                                              \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_AFECLKPADDIR_SHIFT,1,dir)

/***************************************************************************//*!
 * @brief   Selects between PLL, FLL and OSC clocks as the source for the PLL
 *          clock branch for AFE Clock.
 * @details This macro selects between PLL, FLL and OSC clocks as the source for
 *          the PLL clock branch for AFE Clock.
 * @param   src   Select one of the @ref afe_clk_src.
 * @note    Implemented as an inline macro.
 * @see     @ref SIM_SelTmrCh0Clk
 ******************************************************************************/
#define SIM_SelAfePllClk(src)                                                 \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_AFECLKSEL_SHIFT,2,src)

/***************************************************************************//*!
 * @brief   Selects external watchdog monitor input source.
 * @details This macro selects external watchdog monitor input source.
 * @param   src   Select one of the @ref ewm_inp_src.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_SelEwmInput(src)                                                  \
                    iobfiw (SIM_MISC_CTL,SIM_MISC_CTL_EWMINSEL_SHIFT,1,src)

/***************************************************************************//*!
 * @brief   SIM initialization.
 * @details This macro initializes System Integration Module (SIM).
 * @param   cfg   Select one of the @ref sim_config.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define SIM_Init(cfg)                                                         \
{                                                                             \
  SIM_SOPT1     = cfg.SOPT1;                                                  \
  SIM_SOPT1_CFG = cfg.SOPT1_CFG;                                              \
  SIM_CTRL_REG  = cfg.CTRL_REG;                                               \
  SIM_SCGC4     = cfg.SCGC4 | (0x1ul << 5) | (0xful << 27);                   \
  SIM_SCGC5     = cfg.SCGC5;                                                  \
  SIM_SCGC6     = cfg.SCGC6 | (0x1ul << 31);                                  \
  SIM_SCGC7     = cfg.SCGC7;                                                  \
  SIM_CLKDIV1   = cfg.CLKDIV1;                                                \
  SIM_FCFG1     = cfg.FCCFG1;                                                 \
  SIM_MISC_CTL  = cfg.MISC_CTL;                                               \
}
/*! @} End of sim_macro                                                       */

#endif /* __SIM_H */