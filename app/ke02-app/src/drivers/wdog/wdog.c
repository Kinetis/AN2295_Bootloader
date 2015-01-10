
/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file wdog.c
*
* @author a13984
*
* @version 0.0.2
*
* @date Jul-15-2011
*
* @brief Provide common watchdog module routines. 
*
* @history:
* 	Jul.20, 2011	modified the watch dog unlock sequence and disable sequence
*******************************************************************************
* NOTE: Need to add more functionality. Right now it
* 				is just a disable routine since we know almost
* 				all projects will need that.    
******************************************************************************/
#include "common.h"
#include "wdog.h"
 
/******************************************************************************
* Global variables
******************************************************************************/

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

/******************************************************************************
* Local functions
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: wdog_disable
*
* @brief Watchdog timer disable routine
*        
* @param  send	a char to print 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void wdog_disable(void)
{
	/* First unlock the watchdog so that we can write to registers */
#if 1
  wdog_unlock();	

	/* Write all 6 registers once within 128 bus cycles after unlocking */
	WDOG_CS2 = 0;
	WDOG_TOVAL = 0xFFFF;
	WDOG_WIN = 0;
	WDOG_CS1 = 0x20; /* WDOGA = 1 to allow reconfigure watchdog at any time by executing an unlock sequence */        
#else
	WDOG_CS1 = 0x20; 
	WDOG_TOVALH = 0xFF;
	WDOG_TOVALL = 0xFF;        
	WDOG_WINH = 0xFF;
	WDOG_WINL = 0xFF;       
        WDOG_CS2 = 0x20;
#endif        
}



/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: wdog_enable
*
* @brief Watchdog timer enable routine
*        
* @param  send	a char to print 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void wdog_enable(PTWatchdogConfig pDogConfig)
{
	/* First unlock the watchdog so that we can write to registers */
	 wdog_unlock();	

	/* NOTE: the following write sequence must be completed within 128 buc clocks
	 * 
	 */
	 /* enable watchdog */

	#if	(WDOG_CLK == WDOG_CLK_INTERNAL_32KHZ)	
		WDOG_CS2 = 2;	/* use internal reference clock (32K) as clock source */
	#elif (WDOG_CLK == WDOG_CLK_INTERNAL_1KHZ)
		WDOG_CS2 = 1;	/* use internal 1K clock as clock source */	
	#elif (WDOG_CLK == WDOG_CLK_EXTERNAL)
		WDOG_CS2 = 3;	/* use internal 1K clock as clock source */	
	#elif (WDOG_CLK == WDOG_CLK_BUS)
		WDOG_CS2 = 0;	/* use internal 1K clock as clock source */	
	#else
	#error "not supported WDOG clock source\n";
	#endif
	WDOG_TOVALH = 0x00;
	WDOG_TOVALL = 0xFF;        
	WDOG_CS1 = 0x20 | WDOG_CS1_EN_MASK | WDOG_CS1_INT_MASK 
	           | WDOG_CS1_STOP_MASK | WDOG_CS1_WAIT_MASK
	          // | WDOG_CS1_DBG_MASK 		// debug enable
	           ;
}

/********************************************************************/


