/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file pit.c
*
* @author b38368
*
* @version 0.0.1
*
* @date Apr 25, 2013
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide TSI driver,complete electrode scan and processing,support stop mode
******************************************************************************/
#include "common.h"
#include "pit.h"
#include "sysinit.h"

/******************************************************************************
* Local variables
******************************************************************************/
static uint8_t m_ucTimerCount = 0;
T_PIT_Callback PIT_Callback[1] = {(T_PIT_Callback)NULL};
/******************************************************************************
* Global variables
******************************************************************************/
uint32_t g_ulCurrentTimeCount;
/*****************************************************************************//*!*/

/******************************************************************************
* Global function
******************************************************************************/



/******************************************************************************
+FUNCTION----------------------------------------------------------------
* @function name: PIT_Init
*
* @brief  Initiate PIT timer0 overflow value, enable PIT timer0
*		 
* @param  PIT timer number, overflow load value 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void PIT_Init( unsigned char cChannel, unsigned int PitModulo )
{
	SIM_SCGC |= SIM_SCGC_PIT_MASK;
    if( cChannel == 0 )
    {
      enable_irq(22);
    }
    else
    {
      enable_irq(23);
    }
	PIT_MCR = 0x02;
	PIT_LDVAL_REG(PIT_BASE_PTR,cChannel) = PitModulo;
	PIT_TCTRL_REG(PIT_BASE_PTR,cChannel) = 
						PIT_TCTRL_TEN_MASK
						|PIT_TCTRL_TIE_MASK
						;
    PIT_MCR = 0x00;
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: PIT_Isr
*
* @brief PIT timer0 overflow interrupt service routine
*		 
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void PIT0_Isr( void )
{
	if( PIT_TFLG0 )
	{
        /* clear timer interrupt flag by writing 1*/
		PIT_TFLG0 = 0x01;
		
		if( PIT_Callback[0] )
		{
				PIT_Callback[0]();
		}
	}
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: PIT_Isr
*
* @brief 
*		 
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void PIT1_Isr( void )
{
	if( PIT_TFLG1 )
	{
		PIT_TFLG1 = 0x01;
	}
    if( m_ucTimerCount < 5 )
    {
        m_ucTimerCount ++;
    }
    else
    {
        m_ucTimerCount = 0;
        g_ulCurrentTimeCount ++;
    }
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: PIT_SetupCallBack
*
* @brief 
*		 
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void PIT_SetupCallBack( T_PIT_Callback CallBack )
{
	PIT_Callback[0] = CallBack;
}




