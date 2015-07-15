/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      xbar.h
 * @version   1.0.3.0
 * @date      Apr-20-2015
 * @brief     Inter-Peripheral Crossbar Switch (XBAR) driver header file.
 ******************************************************************************/
#ifndef __XBAR_H
#define __XBAR_H

#if !defined(MCU_MKM34ZA5)
  #error "The xbar.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * definition configuration structures                                        *
 ******************************************************************************/
typedef struct { uint16 CTRL0;  } tXBAR;

/******************************************************************************
* XBAR input channel definition used by XBAR_SetMux() function
*
*//*! @addtogroup xbar_inputs
* @{
*******************************************************************************/
#define XBAR_LOGIC1     (uint8)0      ///< Logic 1 (VDD)
#define XBAR_LOGIC0     (uint8)1      ///< Logic 0 (VSS)
#define XBAR_AFEMCLK    (uint8)2      ///< AFE Master Clock Output
#define XBAR_AFEMDAT    (uint8)3      ///< AFE Modulator Data Output
#define XBAR_LPTMR      (uint8)4      ///< LPTimer Output
#define XBAR_CLKOUT     (uint8)5      ///< Clock Output
#define XBAR_TMR0       (uint8)6      ///< Quad Timer channel 0 output
#define XBAR_TMR1       (uint8)7      ///< Quad Timer channel 1 output
#define XBAR_TMR2       (uint8)8      ///< Quad Timer channel 2 output
#define XBAR_TMR3       (uint8)9      ///< Quad Timer channel 3 output
#define XBAR_RTCCLKOUT  (uint8)10     ///< RTC Clock Output
#define XBAR_CMP0OUT    (uint8)11     ///< CMP0 Output
#define XBAR_CMP1OUT    (uint8)12     ///< CMP1 Output
#define XBAR_IRTCALARM  (uint8)13     ///< iRTC Alarm Output
#define XBAR_UARTMODTX  (uint8)14     ///< UART TX Output (after modulation)
#define XBAR_EWMOUT     (uint8)15     ///< EWM Output (/EWM_OUT)
#define XBAR_PIT        (uint8)16     ///< PIT Output
#define XBAR_IN0        (uint8)17     ///< XBAR Input pin 0
#define XBAR_IN1        (uint8)18     ///< XBAR Input pin 1
#define XBAR_IN2        (uint8)19     ///< XBAR Input pin 2
#define XBAR_IN3        (uint8)20     ///< XBAR Input pin 3
#define XBAR_IN4        (uint8)21     ///< XBAR Input pin 4
#define XBAR_IN5        (uint8)22     ///< XBAR Input pin 5
#define XBAR_IN6        (uint8)23     ///< XBAR Input pin 6
#define XBAR_IN7        (uint8)24     ///< XBAR Input pin 7
#define XBAR_IN8        (uint8)25     ///< XBAR Input pin 8
#define XBAR_ADCCOC     (uint8)26     ///< ADC conversion complete flag
#define XBAR_AFEALLCOC  (uint8)27     ///< OR'ed conversion complete flag for all AFE channels
#define XBAR_AFE0COC    (uint8)28     ///< AFE channel 0 conversion complete flag
#define XBAR_AFE1COC    (uint8)29     ///< AFE channel 1 conversion complete flag
#define XBAR_AFE2COC    (uint8)30     ///< AFE channel 2 conversion complete flag
#define XBAR_AFE3COC    (uint8)31     ///< AFE channel 3 conversion complete flag
#define XBAR_DMADONE    (uint8)32     ///< AFE DMA Done Signal
/*! @} End of xbar_inputs                                                     */

/******************************************************************************
* XBAR output channel definition used by XBAR_SetMux() function
*
*//*! @addtogroup xbar_outputs
* @{
*******************************************************************************/
#define XBAR_DMA        (int64)(1ll<< 0)  ///< XBAR DMA request or Interrupt
#define XBAR_AFE0MDAT   (int64)(1ll<< 1)  ///< AFE channel 0 external modulator data input
#define XBAR_AFE1MDAT   (int64)(1ll<< 2)  ///< AFE channel 1 external modulator data input
#define XBAR_AFE2MDAT   (int64)(1ll<< 3)  ///< AFE channel 2 external modulator data input
#define XBAR_AFE3MDAT   (int64)(1ll<< 4)  ///< AFE channel 3 external modulator data input
#define XBAR_TMR0SEC    (int64)(1ll<< 5)  ///< Quad Timer channel 0 secondary input
#define XBAR_TMR1SEC    (int64)(1ll<< 6)  ///< Quad Timer channel 1 secondary input
#define XBAR_TMR2SEC    (int64)(1ll<< 7)  ///< Quad Timer channel 2 secondary input
#define XBAR_TMR3SEC    (int64)(1ll<< 8)  ///< Quad Timer channel 3 secondary input
#define XBAR_TMRPRI1    (int64)(1ll<< 9)  ///< Quad Timer primary clock input 1
#define XBAR_TMRPRI2    (int64)(1ll<<10)  ///< Quad Timer primary clock input 2
#define XBAR_CMP0INP    (int64)(1ll<<11)  ///< CMP0 Sample Window input
#define XBAR_CMP1INP    (int64)(1ll<<12)  ///< CMP1 Sample Window input
#define XBAR_UARTRXINP  (int64)(1ll<<13)  ///< UART Rx Input
#define XBAR_UARTTXMOD  (int64)(1ll<<14)  ///< UART Tx Modulation Output
#define XBAR_ADCTRGCHA  (int64)(1ll<<15)  ///< ADC trigger select A pulse
#define XBAR_ADCTRGCHB  (int64)(1ll<<16)  ///< ADC trigger select B pulse
#define XBAR_OUT0       (int64)(1ll<<17)  ///< XBAR Output pin 0
#define XBAR_OUT1       (int64)(1ll<<18)  ///< XBAR Output pin 1
#define XBAR_OUT2       (int64)(1ll<<19)  ///< XBAR Output pin 2
#define XBAR_OUT3       (int64)(1ll<<20)  ///< XBAR Output pin 3
#define XBAR_OUT4       (int64)(1ll<<21)  ///< XBAR Output pin 4
#define XBAR_OUT5       (int64)(1ll<<22)  ///< XBAR Output pin 5
#define XBAR_OUT6       (int64)(1ll<<23)  ///< XBAR Output pin 6
#define XBAR_OUT7       (int64)(1ll<<24)  ///< XBAR Output pin 7
#define XBAR_OUT8       (int64)(1ll<<25)  ///< XBAR Output pin 8
#define XBAR_ADCTRGCHC  (int64)(1ll<<26)  ///< ADC trigger select C pulse
#define XBAR_ADCTRGCHD  (int64)(1ll<<27)  ///< ADC trigger select D pulse
#define XBAR_AFE0TRG    (int64)(1ll<<28)  ///< AFE Channel 0 Trigger
#define XBAR_AFE1TRG    (int64)(1ll<<29)  ///< AFE Channel 1 Trigger
#define XBAR_AFE2TRG    (int64)(1ll<<30)  ///< AFE Channel 2 Trigger
#define XBAR_AFE3TRG    (int64)(1ll<<31)  ///< AFE Channel 3 Trigger
#define XBAR_EWMIN      (int64)(1ll<<32)  ///< EWM input (EWM_IN)
/*! @} End of xbar_outputs                                                    */

/******************************************************************************
* XBAR default configurations used by XBAR_Init() function
*
*//*! @addtogroup xbar_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Edge detection on the @ref XBAR_DMA output channel disabled.
 *          Interrupt and DMA disabled on the peripheral level.
 * @details Edge detection on the @ref XBAR_DMA output channel disabled.
 *          Interrupt and DMA disabled on the peripheral level.
 * @showinitializer
 *****************************************************************************/
#define XBAR_MODULE_NO_EDGE_DETECT_CONFIG                                     \
(tXBAR){                                                                      \
/* CTRL0  */  SET(XBAR_CTRL0_EDGE0(0x00))|CLR(XBAR_CTRL0_IEN0_MASK)|          \
/* .....  */  CLR(XBAR_CTRL0_DEN0_MASK),                                      \
}
/***************************************************************************//*!
 * @brief   Enabled rising edge detection on the @ref XBAR_DMA output channel.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @details Enabled rising edge detection on the @ref XBAR_DMA output channel.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @showinitializer
 ******************************************************************************/
#define XBAR_MODULE_POSEDGE_DETECT_CONFIG                                     \
(tXBAR){                                                                      \
/* CTRL0  */  SET(XBAR_CTRL0_EDGE0(0x01))|SET(XBAR_CTRL0_IEN0_MASK)|          \
/* .....  */  CLR(XBAR_CTRL0_DEN0_MASK),                                      \
}
/***************************************************************************//*!
 * @brief   Enabled falling edge detection on the @ref XBAR_DMA output channel.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @details Enabled falling edge detection on the @ref XBAR_DMA output channel.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @showinitializer
 ******************************************************************************/
#define XBAR_MODULE_NEGEDGE_DETECT_CONFIG                                     \
(tXBAR){                                                                      \
/* CTRL0  */  SET(XBAR_CTRL0_EDGE0(0x02))|SET(XBAR_CTRL0_IEN0_MASK)|          \
/* .....  */  CLR(XBAR_CTRL0_DEN0_MASK),                                      \
}
/***************************************************************************//*!
 * @brief   Enabled rising and falling edge detection on the @ref XBAR_DMA output.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @details Enabled rising and falling edge detection on the @ref XBAR_DMA output.
 *          Interrupt enabled but DMA disabled on the peripheral level.
 * @showinitializer
 ******************************************************************************/
#define XBAR_MODULE_ANYEDGE_DETECT_CONFIG                                     \
(tXBAR){                                                                      \
/* CTRL0  */  SET(XBAR_CTRL0_EDGE0(0x03))|SET(XBAR_CTRL0_IEN0_MASK)|          \
/* .....  */  CLR(XBAR_CTRL0_DEN0_MASK),                                      \
}
/*! @} End of xbar_config                                                     */

/******************************************************************************
* XBAR callback registered by XBAR_Init() function
*
*//*! @addtogroup xbar_callback
* @{
*******************************************************************************/
/*! @brief XBAR_CALLBACK function declaration                                 */
typedef void (*XBAR_CALLBACK)(void);
/*! @} End of xbar_callback                                                   */

/******************************************************************************
* XBAR function and macro definitions
*
*//*! @addtogroup xbar_macro
* @{
*******************************************************************************/
#define _XBAR_Path(inp,mask)                                                  \
{                                                                             \
  if (mask & XBAR_DMA      ) iobfih (XBAR_SEL0 ,XBAR_SEL0_SEL0_SHIFT  ,6,inp);\
  if (mask & XBAR_AFE0MDAT ) iobfih (XBAR_SEL0 ,XBAR_SEL0_SEL1_SHIFT  ,6,inp);\
  if (mask & XBAR_AFE1MDAT ) iobfih (XBAR_SEL1 ,XBAR_SEL1_SEL2_SHIFT  ,6,inp);\
  if (mask & XBAR_AFE2MDAT ) iobfih (XBAR_SEL1 ,XBAR_SEL1_SEL3_SHIFT  ,6,inp);\
  if (mask & XBAR_AFE3MDAT ) iobfih (XBAR_SEL2 ,XBAR_SEL2_SEL4_SHIFT  ,6,inp);\
  if (mask & XBAR_TMR0SEC  ) iobfih (XBAR_SEL2 ,XBAR_SEL2_SEL5_SHIFT  ,6,inp);\
  if (mask & XBAR_TMR1SEC  ) iobfih (XBAR_SEL3 ,XBAR_SEL3_SEL6_SHIFT  ,6,inp);\
  if (mask & XBAR_TMR2SEC  ) iobfih (XBAR_SEL3 ,XBAR_SEL3_SEL7_SHIFT  ,6,inp);\
  if (mask & XBAR_TMR3SEC  ) iobfih (XBAR_SEL4 ,XBAR_SEL4_SEL8_SHIFT  ,6,inp);\
  if (mask & XBAR_TMRPRI1  ) iobfih (XBAR_SEL4 ,XBAR_SEL4_SEL9_SHIFT  ,6,inp);\
  if (mask & XBAR_TMRPRI2  ) iobfih (XBAR_SEL5 ,XBAR_SEL5_SEL10_SHIFT ,6,inp);\
  if (mask & XBAR_CMP0INP  ) iobfih (XBAR_SEL5 ,XBAR_SEL5_SEL11_SHIFT ,6,inp);\
  if (mask & XBAR_CMP1INP  ) iobfih (XBAR_SEL6 ,XBAR_SEL6_SEL12_SHIFT ,6,inp);\
  if (mask & XBAR_UARTRXINP) iobfih (XBAR_SEL6 ,XBAR_SEL6_SEL13_SHIFT ,6,inp);\
  if (mask & XBAR_UARTTXMOD) iobfih (XBAR_SEL7 ,XBAR_SEL7_SEL14_SHIFT ,6,inp);\
  if (mask & XBAR_ADCTRGCHA) iobfih (XBAR_SEL7 ,XBAR_SEL7_SEL15_SHIFT ,6,inp);\
  if (mask & XBAR_ADCTRGCHB) iobfih (XBAR_SEL8 ,XBAR_SEL8_SEL16_SHIFT ,6,inp);\
  if (mask & XBAR_OUT0     ) iobfih (XBAR_SEL8 ,XBAR_SEL8_SEL17_SHIFT ,6,inp);\
  if (mask & XBAR_OUT1     ) iobfih (XBAR_SEL9 ,XBAR_SEL9_SEL18_SHIFT ,6,inp);\
  if (mask & XBAR_OUT2     ) iobfih (XBAR_SEL9 ,XBAR_SEL9_SEL19_SHIFT ,6,inp);\
  if (mask & XBAR_OUT3     ) iobfih (XBAR_SEL10,XBAR_SEL10_SEL20_SHIFT,6,inp);\
  if (mask & XBAR_OUT4     ) iobfih (XBAR_SEL10,XBAR_SEL10_SEL21_SHIFT,6,inp);\
  if (mask & XBAR_OUT5     ) iobfih (XBAR_SEL11,XBAR_SEL11_SEL22_SHIFT,6,inp);\
  if (mask & XBAR_OUT6     ) iobfih (XBAR_SEL11,XBAR_SEL11_SEL23_SHIFT,6,inp);\
  if (mask & XBAR_OUT7     ) iobfih (XBAR_SEL12,XBAR_SEL12_SEL24_SHIFT,6,inp);\
  if (mask & XBAR_OUT8     ) iobfih (XBAR_SEL12,XBAR_SEL12_SEL25_SHIFT,6,inp);\
  if (mask & XBAR_ADCTRGCHC) iobfih (XBAR_SEL13,XBAR_SEL13_SEL26_SHIFT,6,inp);\
  if (mask & XBAR_ADCTRGCHD) iobfih (XBAR_SEL13,XBAR_SEL13_SEL27_SHIFT,6,inp);\
  if (mask & XBAR_AFE0TRG  ) iobfih (XBAR_SEL14,XBAR_SEL14_SEL28_SHIFT,6,inp);\
  if (mask & XBAR_AFE1TRG  ) iobfih (XBAR_SEL14,XBAR_SEL14_SEL29_SHIFT,6,inp);\
  if (mask & XBAR_AFE2TRG  ) iobfih (XBAR_SEL15,XBAR_SEL15_SEL30_SHIFT,6,inp);\
  if (mask & XBAR_AFE3TRG  ) iobfih (XBAR_SEL15,XBAR_SEL15_SEL31_SHIFT,6,inp);\
  if (mask & XBAR_EWMIN    ) iobfih (XBAR_SEL16,XBAR_SEL16_SEL32_SHIFT,6,inp);\
}
/***************************************************************************//*!
 * @brief   Sets XBAR output channels.
 * @details This macro routes one of the following input channels @ref xbar_inputs
 *          to one or more the following @ref xbar_outputs.
 * @param   inp      Select one of the @ref xbar_inputs.
 * @param   outmask  Select one or more OR'ed @ref xbar_outputs.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define XBAR_Path(inp,outmask)  _XBAR_Path(inp,(outmask))

/***************************************************************************//*!
 * @brief   Enables DMA for XBAR_DMA output.
 * @details This macro enables the DMA function for XBAR_DMAX output.
 *          Macros sets DEN0 (DMA enable bit) and clears IEN0 (interrupt
 *          enable bit).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define XBAR_EnableDMA()        {                                             \
                                  ioclrh (XBAR_CTRL0,XBAR_CTRL0_IEN0_MASK);   \
                                  ioseth (XBAR_CTRL0,XBAR_CTRL0_DEN0_MASK);   \
                                }

/***************************************************************************//*!
 * @brief   XBAR initialization.
 * @details This function initializes Inter-Peripheral Crossbar Switch (XBAR)
 *          block. It also installs callback function for interrupt vector 47.
 * @param   cfg      Select one of the @ref xbar_config.
 * @param   ip       Select one of the @ref cm0plus_prilvl.
 * @param   callback Pointer to the @ref xbar_callback.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define XBAR_Init(cfg,ip,callback)    XBAR_Init(cfg,ip,callback)
/*! @} End of xbar_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void XBAR_Init (tXBAR xbar, uint16 ip, XBAR_CALLBACK pCallback);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void xbar_isr (void);

#endif /* __XBAR_H */ 