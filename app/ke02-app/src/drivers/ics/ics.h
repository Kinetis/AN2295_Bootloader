/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ics.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Jul 17, 2011
*
* @brief Internal Clock Source utilities. 
*
*******************************************************************************
*
* provide APIs for accessing internal clock source (ICS)
******************************************************************************/

#ifndef ICS_H_
#define ICS_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/

/******************************************************************************
* Types
******************************************************************************/
typedef unsigned char byte;

typedef struct{
	byte range: 1;		/* 1: high range, 0: low range */
	byte gain:	1;		/* 1: high gain, 0: low gain */
	byte enable: 1;		/* 1: enable XOSC, 0: disable XOSC */
	byte stopEnable: 1;	/* 1: stop enable, 0: stop disable */
	byte oscOut: 1;		/* 1: oscillator output, 0: clock output */
	byte waitInit: 1; 	/* 1: wait till XOSC init done, 0: no wait */
} TXOSC_Control, *PTXOSC_Control;

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void FEI_to_FEE(void);
void FEI_to_FBI(void);
void FEI_to_FBE(void);
void FEE_to_FBI(void);
void FEE_to_FEI(void);
void FEE_to_FBE(void);
void FBE_to_FEE(void);
void FBE_to_FEI(void);
void FBE_to_FBI(void);
void FBE_to_FBELP(void);
void FBI_to_FEI(void);
void FBI_to_FBE(void);
void FBI_to_FEE(void);
void FBI_to_FBILP(void);
void FBILP_to_FBI(void);
void FBELP_to_FBE(void);
void XOSC_Init(TXOSC_Control *pOSCCtrl);
void FEI_to_FBE_OSC(void);
void FEI_to_FEE_OSC(void);
void ICS_Init(void);

#endif /* ICS_H_ */
