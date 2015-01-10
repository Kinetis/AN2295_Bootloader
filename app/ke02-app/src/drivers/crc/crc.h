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

#ifndef __CRC_H
#define __CRC_H

/*Type definitions*/

/*Error code definition*/
#define CRC_ERR_SUCCESS       0  
#define CRC_ERR_CODE_BASE    (0x2000)
#define CRC_ERR_TOT_VAL      (CRC_ERR_CODE_BASE+1)
#define CRC_ERR_TOTR_VAL     (CRC_ERR_CODE_BASE+2)
#define CRC_ERR_FXOR_VAL     (CRC_ERR_CODE_BASE+3)
#define CRC_ERR_TCRC_VAL     (CRC_ERR_CODE_BASE+4)

/*Prototypes*/
int CRC_Config(uint32 poly,uint32 tot,uint32 totr,uint32 fxor,uint32 tcrc);
uint32 CRC_Cal_16(uint32 seed,uint8 *msg, uint32 sizeBytes);
uint32 CRC_Cal_32(uint32 seed,uint8 *msg, uint32 sizeBytes);
#endif