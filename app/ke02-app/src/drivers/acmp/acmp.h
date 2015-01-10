/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file acmp.h
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


#ifndef ACMP_H_
#define ACMP_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/
//ACMP Control and Status Register
#define	ACMOD_FALLING_EDGE			0x00
#define	ACMOD_RISING_EDGE			0x01
#define	ACMOD_BOTH_EDGE			    0x03  
#define ACOPE_EN                    0x04
#define ACOPE_DIS                   0x00
#define ACIE_EN                     0x10
#define ACIE_DIS                    0x00
#define HYST_30mV                   0x40
#define HYST_20mV                   0x00
#define ACE_EN                      0x80
#define ACE_DIS                     0x00

//ACMP Control Register 0
#define	ACNSEL_EXT0		        	0x00
#define	ACNSEL_EXT1		        	0x01
#define	ACNSEL_EXT2 			    0x02
#define ACNSEL_DACO                 0x03
#define ACPSEL_EXT0                 0x00
#define ACPSEL_EXT1                 0x10
#define ACPSEL_EXT2                 0x20
#define ACPSEL_DACO                 0x30

//ACMP Control Register 1
#define DACVAL_HALF                 0x1F
#define	DACREF_BANDGAP 			    0x00
#define DACREF_VDDA                 0x40
#define DACEN_EN                    0x80
#define DACEN_DIS                   0x00


//ACMP Control Register 2
#define	ACIPE_ACMPIN0_EN		    0x01
#define	ACIPE_ACMPIN0_DIS		    0x00
#define	ACIPE_ACMPIN1_EN		    0x02
#define	ACIPE_ACMPIN1_DIS		    0x00
#define	ACIPE_ACMPIN2_EN		    0x04
#define	ACIPE_ACMPIN2_DIS		    0x00


/******************************************************************************
* Types
******************************************************************************/


/******************************************************************************
* Global variables
******************************************************************************/


/******************************************************************************
* Global functions
******************************************************************************/

void ACMP_InputSelelect (uint8 channel,uint8 ACMPx_CS);
void ACMP_DACInit (uint8 channel,uint8 ACMPx_C1);
void ACMP_InputEnable (uint8 channel,uint8 ACMPx_C2);
void ACMP_Init(uint8 Channel);
void ACMP0_ISR (uint8 Channel);
void ACMP1_ISR (uint8 Channel);

#endif /* RTC_H_ */
