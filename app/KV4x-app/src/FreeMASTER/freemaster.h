/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster.h
*
* @brief  FreeMASTER Driver main API header file, Kxx(40/60) platform
*
* @version 1.0.1.0
* 
* @date Jan-21-2013
* 
*******************************************************************************
*
* This is the only header file needed to be included by the user application
* to implement the FreeMASTER interface. In addition, user has to write her 
* "freemaster_cfg.h" configuration file and put it anywhere on the #include path
*
*******************************************************************************/

#ifndef __FREEMASTER_H
#define __FREEMASTER_H

/* identify our current platform */
#define FMSTR_PLATFORM_KXX 1

/* user configuration */
#include "freemaster_cfg.h"

/*****************************************************************************
* Global types
******************************************************************************/

typedef unsigned char* FMSTR_ADDR;   /* CPU address type (4bytes) */
typedef unsigned short FMSTR_SIZE;   /* general size type (at least 16 bits) */
typedef unsigned char FMSTR_BOOL;    /* general boolean type  */

/* application command-specific types */
typedef unsigned char FMSTR_APPCMD_CODE;
typedef unsigned char FMSTR_APPCMD_DATA, *FMSTR_APPCMD_PDATA;
typedef unsigned char FMSTR_APPCMD_RESULT;

/* pointer to application command callback handler */
typedef FMSTR_APPCMD_RESULT (*FMSTR_PAPPCMDFUNC)(FMSTR_APPCMD_CODE,FMSTR_APPCMD_PDATA,FMSTR_SIZE);

/*****************************************************************************
* TSA-related user types and macros
******************************************************************************/

#include "freemaster_tsa.h"

/*****************************************************************************
* Constants
******************************************************************************/

/* application command status information  */
#define FMSTR_APPCMDRESULT_NOCMD      0xff
#define FMSTR_APPCMDRESULT_RUNNING    0xfe
#define MFSTR_APPCMDRESULT_LASTVALID  0xf7  /* F8-FF are reserved  */

/* recorder time base declaration helpers */
#define FMSTR_REC_BASE_SECONDS(x)  ((x) & 0x3fff)
#define FMSTR_REC_BASE_MILLISEC(x) (((x) & 0x3fff) | 0x4000)
#define FMSTR_REC_BASE_MICROSEC(x) (((x) & 0x3fff) | 0x8000)
#define FMSTR_REC_BASE_NANOSEC(x)  (((x) & 0x3fff) | 0xc000)

/*****************************************************************************
* Global functions 
******************************************************************************/

/* FreeMASTER serial communication API */
FMSTR_BOOL FMSTR_Init(void);    /* general initiazlation */
void FMSTR_Poll(void);    /* polling call, use in SHORT_INTR and POLL_DRIVEN modes */

void FMSTR_Isr(void);     /* interrupt handler for LONG_INTR and SHORT_INTR modes */
void FMSTR_Isr2(void);    /* the second interrupt handler (when RX,TX vecotrs separate) */

/* Recorder API */
void FMSTR_Recorder(void);
void FMSTR_TriggerRec(void);
void FMSTR_SetUpRecBuff(FMSTR_ADDR nBuffAddr, FMSTR_SIZE nBuffSize);

/* Application commands API */
FMSTR_APPCMD_CODE  FMSTR_GetAppCmd(void);
FMSTR_APPCMD_PDATA FMSTR_GetAppCmdData(FMSTR_SIZE* pDataLen);
FMSTR_BOOL         FMSTR_RegisterAppCmdCall(FMSTR_APPCMD_CODE nAppCmdCode, FMSTR_PAPPCMDFUNC pCallbackFunc);

void FMSTR_AppCmdAck(FMSTR_APPCMD_RESULT nResultCode);
void FMSTR_AppCmdSetResponseData(FMSTR_ADDR nResultDataAddr, FMSTR_SIZE nResultDataLen);

#endif /* __FREEMASTER_H */

