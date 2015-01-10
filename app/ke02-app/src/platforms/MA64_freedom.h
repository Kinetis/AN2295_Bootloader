/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file MA64_EVB.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Aug 23, 2011
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MA64, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/


#ifndef _MA64_EVB_H_
#define _MA64_EVB_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/
#define CPU_MA64

#define SPI0_PINREMAP


//#define BUS2CORE_CLOCK_1_2

/* define print system log */
/* NOTE: for RAM version, comment it */
/* #define PRINT_SYS_LOG */
#ifdef  BOOT_LOADER
#else
#define PRINT_SYS_LOG   1
#endif
/* define output bus clock */
#define OUTPUT_BUSCLK

#define ICS_TRIM_VALUE          0x54 //


/* define what clock mode at startup 
 * if USE_FEE is not defined by commenting out the following line, 
 * then it will use FEI mode which is default mode 
 * after reset  
 */
#define USE_FEE		/* FEE clock mode */	
//#define USE_FEE_OSC
//#define USE_FEI

/* define external crystal frequency */
//#define EXT_CLK_CRYST	32	/* in KHz, PT60 tower board includes 8MHz crystal*/
//#define EXT_CLK_CRYST	4000	/* in KHz, PT60 tower board includes 8MHz crystal*/
//#define EXT_CLK_CRYST	8000	/* in KHz, PT60 tower board includes 10MHz crystal*/
#define EXT_CLK_CRYST	10000	/* in KHz, PT60 tower board includes 10MHz crystal*/

/* define BUS clock in HZ */
#if	defined(USE_FEI)
	#define  BUS_CLK_HZ		10000000L
#elif  (EXT_CLK_CRYST == 20000)
   	#define  BUS_CLK_HZ		20000000L
#else   
	#define  BUS_CLK_HZ		20000000L
#endif

#ifdef BOOT_LOADER
/* define UART baud rate */
#define UART_PRINT_BITRATE              115200
#else
/* define UART baud rate */
#define UART_PRINT_BITRATE              115200//9600
#endif
/* define SCI port # to be used */
#define TERM_PORT	                UART1_BASE_PTR				/* SCI0 is used on MA64 EVB board */

/* USER LED definitions */
/* LED maps 
 * code		    MA64
 * RED   <----> PTH1
 * GREEN <----> PTH2
 * BLUE  <----> PTE7
 *  
 */
#define LED0_Init()				GPIOB_PDDR |= (2<<24)					// RED Light
#define LED0_Toggle()		    GPIOB_PTOR = (2<<24)
#define LED0_On()		        GPIOB_PCOR = (2<<24)
#define LED0_Off()		        GPIOB_PSOR = (2<<24)

#define LED1_Init()				GPIOB_PDDR |= (4<<24)					// Green
#define LED1_Toggle()		    GPIOB_PTOR = (4<<24)
#define LED1_On()		        GPIOB_PCOR = (4<<24)
#define LED1_Off()		        GPIOB_PSOR = (4<<24)

#define LED2_Init()				GPIOB_PDDR |= (0x01<<7)
#define LED2_Toggle()		    GPIOB_PTOR = (0x01<<7)
#define LED2_On()		        GPIOB_PCOR = (0x01<<7)
#define LED2_Off()		        GPIOB_PSOR = (0x01<<7)

typedef struct{

unsigned long OnTime;
unsigned long OffTime;
}LED_CONTROL;




#define RED_Set()    			LED0_Off()
#define RED_Clear()				LED0_On()
#define RED_Toggle()			LED0_Toggle()

#define GREEN_Set()             LED1_Off()
#define GREEN_Clear()			LED1_On()
#define GREEN_Toggle()			LED1_Toggle()

#define BLUE_Set()              LED2_Off()
#define BLUE_Clear()			LED2_On()
#define BLUE_Toggle()			LED2_Toggle()



#define FTM_Cn_MODE  (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSA_MASK)
#define FTM_MODULE    1000
#define FTM_INIT_VAL    25
#define SET_LED_GREEN(x)   FTM1_C0V = (x)
#define SET_LED_RED(x)     //FTM2_C1V = (x)
#define SET_LED_BLUE(x)    FTM1_C1V = (x)

#define false				0
#define true 				1


/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
extern void LED_DriveByFtm( void );
extern void LED_CallBack ( void );
extern void LED_BlueControl(unsigned long OnTime,unsigned long OffTime);
extern void LED_GreenControl(unsigned long OnTime,unsigned long OffTime);
extern void LED_RedControl(unsigned long OnTime,unsigned long OffTime);

#endif /* _MA64_FREEDOM_H_ */
