/*******************************************************************************
*
* Copyright 2004-2014 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale FreeMASTER License
* distributed with this Material.
* See the license file distributed for more details.
*
****************************************************************************//*!
*
* @brief  FreeMASTER Driver main API header file, Kxx(40/60) platform
*
* This is the only header file needed to be included by the user application
* to implement the FreeMASTER interface. In addition, user has to write the
* "freemaster_cfg.h" configuration file and put it anywhere on the #include path
*
*******************************************************************************/

#ifndef __FREEMASTER_H
#define __FREEMASTER_H

/* identify our current platform */
#define FMSTR_PLATFORM_KXX 1

/* FreeMASTER configuration */
#include "freemaster_defcfg.h"

/*****************************************************************************
* Global types
******************************************************************************/

typedef unsigned char * FMSTR_ADDR;             /* CPU address type (4bytes) */
typedef unsigned short FMSTR_SIZE;              /* general size type (at least 16 bits) */
typedef unsigned char FMSTR_BOOL;               /* general boolean type  */
#if FMSTR_RECORDER_LARGE_MODE
typedef unsigned long FMSTR_SIZE_RECBUFF;
#else
typedef unsigned short FMSTR_SIZE_RECBUFF;
#endif


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

/******************************************************************************
* NULL needed
******************************************************************************/

#ifndef NULL
#ifdef __cplusplus
#define NULL (0)
#else
#define NULL ((void *) 0)
#endif
#endif

/*****************************************************************************
* Global functions
******************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/* FreeMASTER serial communication API */
FMSTR_BOOL FMSTR_Init(void);    /* general initialization */
void FMSTR_Poll(void);          /* polling call, use in SHORT_INTR and POLL_DRIVEN modes */
void FMSTR_Isr(void);           /* SCI interrupt handler for LONG_INTR and SHORT_INTR modes */

/* Recorder API */
void FMSTR_Recorder(void);
void FMSTR_TriggerRec(void);
void FMSTR_SetUpRecBuff(FMSTR_ADDR nBuffAddr, FMSTR_SIZE_RECBUFF nBuffSize);

/* Application commands API */
FMSTR_APPCMD_CODE  FMSTR_GetAppCmd(void);
FMSTR_APPCMD_PDATA FMSTR_GetAppCmdData(FMSTR_SIZE* pDataLen);
FMSTR_BOOL         FMSTR_RegisterAppCmdCall(FMSTR_APPCMD_CODE nAppCmdCode, FMSTR_PAPPCMDFUNC pCallbackFunc);

void FMSTR_AppCmdAck(FMSTR_APPCMD_RESULT nResultCode);
void FMSTR_AppCmdSetResponseData(FMSTR_ADDR nResultDataAddr, FMSTR_SIZE nResultDataLen);

#ifdef __cplusplus
  }
#endif

#endif /* __FREEMASTER_H */

