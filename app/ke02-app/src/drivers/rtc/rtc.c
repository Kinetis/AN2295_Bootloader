/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file rtc.c
*
* @author Freescale
*
* @version 0.0.1
*
* @date Apr 19, 2013
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MKE02, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/
#include "common.h"
#include "rtc.h"

/******************************************************************************
* Global variables
******************************************************************************/
RTC_TIME_STRUCT real_time = {0};
RTC_TIME_STRUCT alarm_time = {0};
uint8 RTC_Trigger_Flag;
uint8 RTC_AlarmFlag, RTC_TickFlag;
/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/
T_RTC_Callback RTC_Callback[1] = {(T_RTC_Callback)NULL};

/******************************************************************************
* Local functions
******************************************************************************/


/******************************************************************************
* Global functions
******************************************************************************/

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_Init
* Returned Value   : none
* Comments         :
*    brief initialize RTC with specified options.
*
*END*********************************************************************/
void RTC_Init(uint8 clkSrc,uint16 modulo, uint8 prescaler)
{
    SIM_SCGC |= SIM_SCGC_RTC_MASK;                     /*enable clock to RTC*/
    RTC_MOD= modulo;                                   /*NOTE: RTC_MOD must be written after RTC_SC*/
    RTC_SC =  0 | RTC_SC_RTIE_MASK | RTC_SC_RTCO_MASK ;       
    RTC_SC |= ((clkSrc & 0x3) << 14) | ((prescaler & 0x07)<<8);
    /*enable interrupt*/
    enable_irq(20);
}

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_Isr
* Returned Value   : none
* Comments         :
*    brief  RTC interrupt service routine.
*
*END*********************************************************************/
void RTC_Isr(void) 
{
    RTC_TickFlag = 1;
    RTC_SC |= RTC_SC_RTIF_MASK;	         /* clear the flag */
    //LED0_Toggle();
    real_time.seconds++;
    if (real_time.seconds > 59)          /* minute boundary */
    {
        real_time.seconds = 0;      
        real_time.minutes++;
        if (real_time.minutes > 59)      /* hour boundary */
        {
            real_time.minutes = 0;
            real_time.hours++;
            if (real_time.hours > 23)    /* days boundary */
            {
                real_time.hours = 0;            
                real_time.days++;
            }    
        }    
    }
    /* alarm checking */
    if ((real_time.seconds == alarm_time.seconds) && (real_time.minutes == alarm_time.minutes) && (real_time.hours == alarm_time.hours) && (real_time.days == alarm_time.days))
    {
        RTC_AlarmFlag = 1;
    }  
    /* printf("\nRTC ISR Happened.\n");*/
    
    if(RTC_Callback[0])
    {    
        RTC_Callback[0]();     
    }
}

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_SetupTimerCallback
* Returned Value   : none
* Comments         :
*    This function sets the callback function.
*
*END*********************************************************************/
void RTC_SetupTimerCallback(T_RTC_Callback pfnCallback)
{
    RTC_Callback[0] = pfnCallback;
}

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_Set_Time
* Returned Value   : none
* Comments         :
*    This function sets the RTC time according to given time struct.
*
*END*********************************************************************/
void RTC_SetTime (RTC_TIME_STRUCT_PTR time)
{       
    real_time = *time;                                    
    if (real_time.seconds > 59) real_time.seconds = 59;   
    if (real_time.minutes > 59) real_time.minutes = 59;
    if (real_time.hours > 23) real_time.hours = 23;   
}

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_Set_Alarm
* Returned Value   : none
* Comments         :
*    This function sets RTC alarm time according to given time struct.
*    Alarm happens immediately after match.
*
*END*********************************************************************/
void RTC_SetAlarm ( RTC_TIME_STRUCT_PTR time)
{   
    alarm_time = *time;
    if (alarm_time.seconds > 59) alarm_time.seconds = 59;
    if (alarm_time.minutes > 59) alarm_time.minutes = 59;
    if (alarm_time.hours > 23) alarm_time.hours = 23; 
}

/*FUNCTION****************************************************************
* 
* Function Name    : RTC_InitADCTriggering
* Returned Value   : none
* Comments         :
*    This function initiate RTC overflow to trigger ADC.
*
*END*********************************************************************/
void RTC_ConfigADCTriggering (void)
{     
    SIM_SCGC |= SIM_SCGC_ADC_MASK ;
    ADC_APCTL1 = 0x01;
    SIM_SOPT &= 0xFFFFFCFF;                          /*select RTC overflow as the ADC trigger resource, ADHWT='00b'*/     
    ADC_SC1 = 0x00;
    ADC_SC2 |= ADC_SC2_ADTRG_MASK;                   /*select ADC hardware trigger*/       
    //RTC_Trigger_Flag  = 1;   
}
