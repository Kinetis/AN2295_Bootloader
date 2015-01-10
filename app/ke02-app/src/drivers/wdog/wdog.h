
/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file wdog.h
*
* @author a13984
*
* @version 0.0.2
*
* @date Jul 17, 2011
*
* @brief provide commond watch dog utilities. 
*
* @history:
* 	Jul.20, 2011	modified the watch dog unlock sequence and disable sequence
*******************************************************************************
*
* provide APIs for accessing watch dog
******************************************************************************/

#ifndef __WDOG_H__
#define __WDOG_H__

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/
/* wdog_unlock sequence must be performed within 16 bus clock cycles without
 * any interrupt 
 */
#undef  WDOG_CNT
#undef  WDOG_TOVAL
#undef  WDOG_WIN

#define WDOG_CNT          *((volatile uint16*)&WDOG_CNTH)
#define WDOG_TOVAL        *((volatile uint16*)&WDOG_TOVALH)
#define WDOG_WIN          *((volatile uint16*)&WDOG_WINH)

#define wdog_unlock()     WDOG_CNT = 0x20C5; WDOG_CNT = 0x28D9  // NOTE: can not use 16-bit access
//#define wdog_unlock()   WDOG_CNTL = 0x20U;WDOG_CNTH = 0xC5U; WDOG_CNTL = 0x28U;WDOG_CNTH = 0xD9U

   
/* WDOG clock sources option */
#define WDOG_CLK_BUS										0
#define WDOG_CLK_INTERNAL_32KHZ	        2
#define WDOG_CLK_INTERNAL_1KHZ	        1
#define WDOG_CLK_EXTERNAL								3

/* WDOG clock source selection */
#define WDOG_CLK  (WDOG_CLK_INTERNAL_1KHZ)
//#define WDOG_CLK  (WDOG_CLK_EXTERNAL)
/******************************************************************************
* Types
******************************************************************************/
typedef struct {	
	uint16_t interruptEnable: 1;
	uint16_t dbgEnable: 1;
	uint16_t waitEnable: 1;
	uint16_t stopEnable: 1;
	uint16_t windowModeEnable: 1;
	uint16_t clkSrc;
}TWatchdogConfig, *PTWatchdogConfig;
/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void wdog_disable(void);
/*void wdog_unlock(void);*/
void wdog_enable(PTWatchdogConfig pDogConfig);

/********************************************************************/
#endif /* __WDOG_H__ */

