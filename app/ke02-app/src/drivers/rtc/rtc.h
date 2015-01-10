/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file rtc.h
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

#ifndef RTC_H_
#define RTC_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/
#define RTC_CLKSRC_EXTERNAL		0
#define RTC_CLKSRC_1KHZ			1
#define RTC_CLKSRC_BUS_X1		2
#define RTC_CLKSRC_BUS_X128		3
#define RTC_CLK_PRESCALER_128           1
#define RTC_CLK_PRESCALER_256           2
#define RTC_CLK_PRESCALER_512           3
#define RTC_CLK_PRESCALER_1024          4
#define RTC_CLK_PRESCALER_2048          5
#define RTC_CLK_PRESCALER_100           6
#define RTC_CLK_PRESCALER_1000          7
#define _PTR_      *

/******************************************************************************
* Types
******************************************************************************/
typedef void (*T_RTC_Callback)(void);
typedef struct rtc_time_struct
{
    uint8      seconds;
    uint8      minutes;
    uint8      hours;
    uint16     days;
} RTC_TIME_STRUCT, _PTR_ RTC_TIME_STRUCT_PTR;

/******************************************************************************
* Global variables
******************************************************************************/
extern RTC_TIME_STRUCT real_time;
extern RTC_TIME_STRUCT alarm_time;
extern uint8 RTC_AlarmFlag, RTC_TickFlag, RTC_Trigger_Flag;

/******************************************************************************
* Global functions
******************************************************************************/
void RTC_Isr(void);
void RTC_Init(uint8 clkSrc,uint16 modulo, uint8 prescaler);
void RTC_SetupTimerCallback(T_RTC_Callback pfnCallback);
void RTC_SetTime(RTC_TIME_STRUCT_PTR time);
void RTC_SetAlarm(RTC_TIME_STRUCT_PTR time);
void RTC_ConfigADCTriggering(void);

#endif /* RTC_H_ */
