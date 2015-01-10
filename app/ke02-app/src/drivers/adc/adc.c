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
* provide ADC driver,complete potentiometer test 
******************************************************************************/
#include "common.h"
#include "io.h"
#include "adc.h"
/******************************************************************************
* Local function
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/
//unsigned int m_uiADC_ResultBuff[8];
/******************************************************************************
* Local function prototypes
******************************************************************************/
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: ADC_Init
   *
   * @brief initialize ADC as 12 bit mode, software trigger, without FIFO
   *        
   * @param  AdcNumber       pointer to the ADC module 
             channel         ADC channel
             CompareValue    0 disable compare function, others compare value
             GreaterOrLess   0 less than compare value, 1 greater or equal to compare value            
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void ADC_Init(ADC_MemMapPtr AdcNumber, unsigned char channel, unsigned char GreaterOrLess, unsigned int CompareValue)
{
    if(ADC_BASE_PTR == AdcNumber)
    {
        SIM_SCGC |= SIM_SCGC_ADC_MASK;
        
        if(CompareValue != 0x0)
        {
            if(GreaterOrLess > 0)
                GreaterOrLess = ADC_COMPARE_GREATER;
            else 
                GreaterOrLess = ADC_COMPARE_LESS;
            ADC_SC2_REG(AdcNumber) = ADC_SC2_ACFE_MASK  |
                                     GreaterOrLess;
            ADC_CV_REG(AdcNumber)  = CompareValue;                                            
        }
        ADC_SC3_REG(AdcNumber) = ADC_SC3_ADLPC_MASK  | 
                                 ADC_SC3_ADLSMP_MASK | 
                                 ADC_SC3_MODE(ADC_MODE_12BIT) | 
                                 ADC_SC3_ADICLK(CLOCK_SOURCE_BUS_CLOCK_DIVIDE_2);
        if(ADC_CHANNEL_AD23_BANDGAP == channel)
        {  
            PMC_SPMSC1 |= PMC_SPMSC1_BGBE_MASK;    /* enable the Bandgap buffer */
        }
        ADC_APCTL1_REG(AdcNumber) = 1 << channel;
        //ADC_SC1_REG(AdcNumber) = channel;
    }
    else
    {
        // other ADC module
    }
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: ADC_GetResult
   *
   * @brief start a conversion and get conversion result
   *        
   * @param  none 
   *
   * @return ADC register value
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
unsigned int ADC_GetResult(ADC_MemMapPtr AdcNumber, unsigned char channel)
{
	ADC_SC1_REG(AdcNumber) = channel;
	while(!(ADC_SC1_REG(AdcNumber) & ADC_SC1_COCO_MASK));
	return (ADC_R_REG(AdcNumber) & 0x0FFF);
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: ADC_FIFO_Init
   *
   * @brief initial ADC module, enable the FIFO fucntion
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void ADC_FIFO_Init(ADC_MemMapPtr AdcNumber)
{
    if(ADC_BASE_PTR == AdcNumber)
    {
        SIM_SCGC |= SIM_SCGC_ADC_MASK;
        
        ADC_SC3_REG(AdcNumber) = ADC_SC3_ADLPC_MASK           | 
                                 ADC_SC3_ADLSMP_MASK          | 
                                 ADC_SC3_MODE(ADC_MODE_12BIT) | 
                                 ADC_SC3_ADICLK(CLOCK_SOURCE_BUS_CLOCK_DIVIDE_2);
        /* 3-level FIFO */
        ADC_SC4_REG(AdcNumber) = ADC_SC4_AFDEP(2);
        /* enable the Bandgap buffer */  
        PMC_SPMSC1 |= PMC_SPMSC1_BGBE_MASK;  
        ADC_APCTL1_REG(AdcNumber) = (1 << ADC_CHANNEL_AD22_TEMPSENSOR) | 
                                    (1 << ADC_CHANNEL_AD23_BANDGAP)    | 
                                    (1 << ADC_CHANNEL_AD29_VREFH);
        /* change the channels if you want */
        ADC_SC1_REG(AdcNumber) = ADC_CHANNEL_AD22_TEMPSENSOR;
        ADC_SC1_REG(AdcNumber) = ADC_CHANNEL_AD23_BANDGAP;
        ADC_SC1_REG(AdcNumber) = ADC_SC1_AIEN_MASK | ADC_CHANNEL_AD29_VREFH;
        enable_irq (INT_ADC0 - 16);
    }
    else
    {
        // other ADC module
    }
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: ADC_Isr
   *
   * @brief return the FIFO value data
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void ADC_Isr(void)
{
    unsigned int m_uiADC_ResultBuff[3];
    m_uiADC_ResultBuff[0] = ADC_R_REG(ADC_BASE_PTR);  /* read channel ADC_CHANNEL_AD22_TEMPSENSOR */
    m_uiADC_ResultBuff[1] = ADC_R_REG(ADC_BASE_PTR);  /* read channel ADC_CHANNEL_AD23_BANDGAP */
    m_uiADC_ResultBuff[2] = ADC_R_REG(ADC_BASE_PTR);  /* read channel ADC_CHANNEL_AD29_VREFH */
    printf("\n Temperature value: %d", m_uiADC_ResultBuff[0]);
    printf("\n Bandgap value: %d", m_uiADC_ResultBuff[1]);
    printf("\n Vref value: %d\n", m_uiADC_ResultBuff[2]);
}

