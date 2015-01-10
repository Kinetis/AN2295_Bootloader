/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file pit.h
*
* @author B37531
*
* @version 0.0.1
*
* @date Aug 23, 2011
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
*
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: PIT_Init
*
* @brief 
*		 
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/


#ifndef PIT_H_
#define PIT_H_

#define PIT_TIMERS			10 //mS
#define PIT_MODULO			(BUS_CLK_HZ/1000)*PIT_TIMERS

typedef void (*T_PIT_Callback)(void);

void PIT0_Isr( void );
void PIT1_Isr( void );
void PIT_Init( unsigned char cChannel, unsigned int PitModulo );

extern void PIT_SetupCallBack( T_PIT_Callback CallBack );
extern uint32_t g_ulCurrentTimeCount;
extern void Pit0CallBack(void);

#endif /* PIT_H_ */
