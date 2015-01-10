/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file pt60_tower.c
*
* @author a13984
*
* @version 0.0.1
*
* @date Aug 23, 2011
*
* @brief application entry point which performs application specific tasks. 
* 
* User buttons: 
* SW1 :  PTA4/BKGD/MS
* SW2 :  PTD5/KBI1P5
* SW3 :  PTD4/KBI1P4
*
*******************************************************************************
*
* provide a demo for how to initialize the PT60, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/

#include "common.h"
#include "ftm.h"
/******************************************************************************
* External objects
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/


/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/
static LED_CONTROL sGreenLedControl;
static LED_CONTROL sCurrentGreenLedControlValue;
static LED_CONTROL sBlueLedControl;
static LED_CONTROL sCurrentBlueLedControlValue;
static LED_CONTROL sRedLedControl;
static LED_CONTROL sCurrentRedLedControlValue;


/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void LED_DriveByFtm( void );


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Button_Init
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void LED_DriveByFtm( void )
{

	SIM_SCGC |= SIM_SCGC_FTM2_MASK | SIM_SCGC_FTM1_MASK;

	SIM_PINSEL |= SIM_PINSEL_FTM1PS0_MASK|
					SIM_PINSEL_FTM1PS1_MASK|
					SIM_PINSEL_FTM2PS1_MASK;

#if(0)
	//FTM2_PWMLOAD |= FTM_PWMLOAD_CH1SEL_MASK;
	FTM2_MOD  = FTM_MODULE;  /* 0x0063 / 25MHz = 4uS PWM period */
	FTM2_C1SC = FTM_Cn_MODE;   /* No Interrupts; High True pulses on Edge Aligned PWM */
	FTM2_C1V  = FTM_INIT_VAL;  /* 90% pulse width */
	FTM2_SC   = FTM_SC_CLKS(1) | FTM_SC_PS(0);     /* Edge Aligned PWM running from BUSCLK / 1 */
#endif
	//FTM1_PWMLOAD |= FTM_PWMLOAD_CH1SEL_MASK|
	//                FTM_PWMLOAD_CH0SEL_MASK;
	FTM1_MOD  = FTM_MODULE;  /* 0x0063 / 25MHz = 4uS PWM period */
	FTM1_C1SC = FTM_Cn_MODE;   /* No Interrupts; High True pulses on Edge Aligned PWM */
	FTM1_C0SC = FTM_Cn_MODE;   /* No Interrupts; High True pulses on Edge Aligned PWM */
	FTM1_C1V  = FTM_INIT_VAL;  /* 90% pulse width */
	FTM1_C0V  = FTM_INIT_VAL;  /* 90% pulse width */
	FTM1_SC   = FTM_SC_CLKS(1) | FTM_SC_PS(0);     /* Edge Aligned PWM running from BUSCLK / 1 */
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: GREEN Control
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void LED_GreenControl(unsigned long OnTime,unsigned long OffTime)
{
	sGreenLedControl.OffTime = OffTime;
	sGreenLedControl.OnTime = OnTime;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: BLUE Control
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void LED_BlueControl(unsigned long OnTime,unsigned long OffTime)
{
	sBlueLedControl.OffTime = OffTime;
	sBlueLedControl.OnTime = OnTime;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: RED Control
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void LED_RedControl(unsigned long OnTime,unsigned long OffTime)
{
	sRedLedControl.OffTime = OffTime;
	sRedLedControl.OnTime = OnTime;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: CheckLEDStatus
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: return the light status 0 -- Light 0ff
*                                                               1 -- Light On
*****************************************************************************/
uint8_t CheckLEDStatus(LED_CONTROL * pCurrentState,LED_CONTROL OriginalState)
{
	if( pCurrentState->OnTime )
	{
		pCurrentState->OnTime --;
		return 1;
	}
	else if( pCurrentState->OffTime )
	{
		pCurrentState->OffTime --;
		return 0;
	}
	else
	{
		*pCurrentState = OriginalState;
	}
    
    return 0;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: LED_CallBack
*
* @brief initialize button switches.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: return the light status 0 -- Light 0ff
*                                                               1 -- Light On
*****************************************************************************/

void LED_CallBack ( void )
{
	/* check green light */
	if(CheckLEDStatus(&sCurrentGreenLedControlValue,sGreenLedControl))
	{
		SET_LED_GREEN(300);
	}
	else
	{
		SET_LED_GREEN(0);
	}
	
	/* check blue light */
	if(CheckLEDStatus(&sCurrentBlueLedControlValue,sBlueLedControl))
	{
		SET_LED_BLUE(300);
	}
	else
	{
		SET_LED_BLUE(0);
	}
	/* check green light */
	if(CheckLEDStatus(&sCurrentRedLedControlValue,sRedLedControl))
	{
		SET_LED_RED(300);
	}
	else
	{
		SET_LED_RED(0);
	}

}



