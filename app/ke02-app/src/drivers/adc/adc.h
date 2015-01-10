/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file adc.c
*
* @author B37811
*
* @version 0.0.1
*
* @date Aug 16, 2013
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide ADC driver
******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/******************************************************************************
* Macros
******************************************************************************/

#define CLOCK_SOURCE_BUS_CLOCK							0x00
#define CLOCK_SOURCE_BUS_CLOCK_DIVIDE_2					0x01
#define CLOCK_SOURCE_ALTCLK								0x02
#define CLOCK_SOURCE_ADACK								0x03

#define ADC_ADIV_DIVIDE_1								0x00
#define ADC_ADIV_DIVIDE_2								0x01
#define ADC_ADIV_DIVIDE_4								0x02
#define ADC_ADIV_DIVIDE_8								0x03

#define ADC_MODE_8BIT									0x00
#define ADC_MODE_10BIT									0x01
#define ADC_MODE_12BIT									0x02

#define ADC_CHANNEL_AD18_VSS                            0x12  
#define ADC_CHANNEL_AD22_TEMPSENSOR                     0x16
#define ADC_CHANNEL_AD23_BANDGAP                        0x17  
#define ADC_CHANNEL_AD29_VREFH                          0x1D  
#define ADC_CHANNEL_AD30_VREFL                          0x1E  

#define ADC_TRIGGER_RTC                                 0x00            
#define ADC_TRIGGER_PIT                                 0x01   
#define ADC_TRIGGER_FTM2INIT                            0x10   
#define ADC_TRIGGER_FTM2MATCH                           0x11  
  
#define ADC_COMPARE_LESS                                0x00
#define ADC_COMPARE_GREATER                             0x01

/******************************************************************************
* Global function
******************************************************************************/
extern void ADC_Init(ADC_MemMapPtr AdcNumber, unsigned char channel, unsigned char GreaterOrLess, unsigned int CompareValue);
extern void ADC_FIFO_Init(ADC_MemMapPtr AdcNumber);
extern unsigned int ADC_GetResult(ADC_MemMapPtr AdcNumber, unsigned char channel);
#endif /* ADC_H_ */
