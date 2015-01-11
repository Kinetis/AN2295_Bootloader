/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster_rec.h
*
* @brief  FreeMASTER Recorder implementation.
*
* @version 1.0.1.0
* 
* @date Jan-21-2013
* 
*******************************************************************************/

#ifndef __FREEMASTER_REC_H
#define __FREEMASTER_REC_H

#ifndef __FREEMASTER_H
#error Please include freemaster_rec.h after freemaster.h main header file.
#endif

#include "freemaster.h"
#include "freemaster_private.h"

/***********************************
*  global recorder types
***********************************/

/* recorder runtime flags */
typedef volatile union 
{
    FMSTR_FLAGS all;
    
    struct 
    {
        unsigned bIsConfigured : 1;     /* recorder is configured */
        unsigned bIsRunning : 1;        /* recorder is running */
        unsigned bIsStopping : 1;       /* trigger activated, sample countdown */
        unsigned bInvirginCycle : 1;    /* virgin cycle of the circular buffer in-progress */
        unsigned bTrgCrossActive : 1;   /* trigger trheshold was crossed */
    } flg;
    
} FMSTR_REC_FLAGS;

/* the same flags for optimized asm access (see fast recorder) */
#if defined(FMSTR_PLATFORM_56F8xxx) /* flag allocation tested on 56f8xxx only */
#define FMSTR_REC_FLAG_bIsConfigured   0x01
#define FMSTR_REC_FLAG_bIsRunning      0x02
#define FMSTR_REC_FLAG_bIsStopping     0x04
#define FMSTR_REC_FLAG_bInvirginCycle  0x08
#define FMSTR_REC_FLAG_bTrgCrossActive 0x10
#endif

/***********************************
*  global recorder variables 
***********************************/

/* configuration variables */
extern FMSTR_U16  pcm_wRecTotalSmps;        /* number of samples to measure */
extern FMSTR_U16  pcm_wRecPostTrigger;      /* number of post-trigger samples to keep */
extern FMSTR_U8   pcm_nRecTriggerMode;      /* triger mode (0 = disabled, 1 = _/, 2 = \_) */
extern FMSTR_U16  pcm_wRecTimeDiv;          /* divisor of recorder "clock" */

extern FMSTR_U8    pcm_nRecVarCount;        /* number of active recorder variables */
extern FMSTR_ADDR  pcm_pRecVarAddr[FMSTR_MAX_SCOPE_VARS]; /* addresses of recorded variables */
extern FMSTR_SIZE8 pcm_pRecVarSize[FMSTR_MAX_SCOPE_VARS]; /* sizes of recorded variables */

/* runtime variables  */
extern FMSTR_U16  pcm_wRecBuffStartIx;      /* first sample index */

extern FMSTR_ADDR pcm_dwRecWritePtr;        /* write pointer in recorder buffer */
extern FMSTR_ADDR pcm_dwRecEndBuffPtr;      /* pointer to end of active recorder buffer */
extern FMSTR_U16  pcm_wRecTimeDivCtr;       /* recorder "clock" divisor counter */
extern FMSTR_U16  pcm_wStoprecCountDown;    /* post-trigger countdown counter */

extern FMSTR_REC_FLAGS pcm_wRecFlags;


#endif /* __FREEMASTER_REC_H */
