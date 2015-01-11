/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster_private.h
*
* @brief  FreeMASTER driver private declarations, used internally by the driver
*
* @version 1.0.1.0
* 
* @date Jan-21-2013
* 
*******************************************************************************/

#ifndef __FREEMASTER_PRIVATE_H
#define __FREEMASTER_PRIVATE_H

#ifndef __FREEMASTER_H
#error Please include the freemaster.h master header file before the freemaster_private.h
#endif

#include "freemaster_cfg.h"

#ifdef FMSTR_USE_MQX_IO
  #if FMSTR_USE_MQX_IO
    /* include MQX headers */
    #include <mqx.h>
    #include <bsp.h>
  #endif
#endif

/******************************************************************************
* Platform-dependent types, macros and functions
******************************************************************************/

#undef FMSTR_PLATFORM

/* platform macro FMSTR_PLATFORM_xxxxxxx should be defined  */
/* as "non-zero" in the "freemaster.h" file */

#if defined(FMSTR_PLATFORM_56F8xx)
    #if FMSTR_PLATFORM_56F8xx
    #include "freemaster_56F8xx.h"
    #define FMSTR_PLATFORM 56F8xx
    #else
    #undef FMSTR_PLATFORM_56F8xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_56F8xxx)
    #if FMSTR_PLATFORM_56F8xxx
    #include "freemaster_56F8xxx.h"
    #define FMSTR_PLATFORM 56F8xxx
    #else
    #undef FMSTR_PLATFORM_56F8xxx
    #endif
#endif

#if defined(FMSTR_PLATFORM_HC12)
    #if FMSTR_PLATFORM_HC12
    #include "freemaster_HC12.h"
    #define FMSTR_PLATFORM HC12
    #else
    #undef FMSTR_PLATFORM_HC12
    #endif
#endif

#if defined(FMSTR_PLATFORM_HC08)
    #if FMSTR_PLATFORM_HC08
    #include "freemaster_HC08.h"
    #define FMSTR_PLATFORM HC08
    #else
    #undef FMSTR_PLATFORM_HC08
    #endif
#endif

#if defined(FMSTR_PLATFORM_MPC55xx)
    #if FMSTR_PLATFORM_MPC55xx
    #include "freemaster_MPC55xx.h"
    #define FMSTR_PLATFORM MPC55xx
    #else
    #undef FMSTR_PLATFORM_MPC55xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_MPC5xx)
    #if FMSTR_PLATFORM_MPC5xx
    #include "freemaster_MPC5xx.h"
    #define FMSTR_PLATFORM MPC5xx
    #else
    #undef FMSTR_PLATFORM_MPC5xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_MCF51xx)
    #if FMSTR_PLATFORM_MCF51xx
    #include "freemaster_MCF51xx.h"
    #define FMSTR_PLATFORM MCF51xx
    #else
    #undef FMSTR_PLATFORM_MCF51xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_MCF52xx)
    #if FMSTR_PLATFORM_MCF52xx
    #include "freemaster_MCF52xx.h"
    #define FMSTR_PLATFORM MCF52xx
    #else
    #undef FMSTR_PLATFORM_MCF52xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_MPC56xx)
    #if FMSTR_PLATFORM_MPC56xx
    #include "freemaster_MPC56xx.h"
    #define FMSTR_PLATFORM MPC56xx
    #else
    #undef FMSTR_PLATFORM_MPC56xx
    #endif
#endif

#if defined(FMSTR_PLATFORM_MQX)
    #if FMSTR_PLATFORM_MQX
    #include "freemaster_MQX.h"
    #define FMSTR_PLATFORM MQX
    #else
    #undef FMSTR_PLATFORM_MQX
    #endif
#endif

#if defined(FMSTR_PLATFORM_KXX)
    #if FMSTR_PLATFORM_KXX
    #include "freemaster_Kxx.h"
    #define FMSTR_PLATFORM KXX
    #else
    #undef FMSTR_PLATFORM_KXX
    #endif
#endif

#ifndef FMSTR_PLATFORM
#error Unknown FreeMASTER driver platform
#endif

/******************************************************************************
* NULL needed
******************************************************************************/

#ifndef NULL
#define NULL ((void *) 0)
#endif

/******************************************************************************
* Boolean values
******************************************************************************/

#ifndef FMSTR_TRUE
#define FMSTR_TRUE (1U)
#endif

#ifndef FMSTR_FALSE
#define FMSTR_FALSE (0U)
#endif

/******************************************************************************
* CAN-related constants
******************************************************************************/

#ifdef FMSTR_CAN_EXTID 
#if FMSTR_CAN_EXTID != 0x80000000U
#error FMSTR_CAN_EXTID must be defined as 0x80000000
#undef FMSTR_CAN_EXTID 
#endif
#endif

#ifndef FMSTR_CAN_EXTID
#define FMSTR_CAN_EXTID 0x80000000U
#endif

/******************************************************************************
* inline functions 
******************************************************************************/

/* we do not assume the inline is always supported by compiler
  rather each platform header defines its FMSTR_INLINE */
#ifndef FMSTR_INLINE
#define FMSTR_INLINE static
#endif

/* building macro-based inline code */
#define FMSTR_MACROCODE_BEGIN()     do{
#define FMSTR_MACROCODE_END()       }while(0)

/******************************************************************************
* Global non-API functions (used internally in FreeMASTER driver)
******************************************************************************/

void FMSTR_InitSerial(void);
FMSTR_BOOL FMSTR_InitMQX(void);
void FMSTR_SendResponse(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nLength);
void FMSTR_ProcessSCI(void);
void FMSTR_ProcessJTAG(void);

FMSTR_BOOL FMSTR_ProtocolDecoder(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetBoardInfo(FMSTR_BPTR pMessageIO);

FMSTR_BPTR FMSTR_ReadMem(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_ReadVar(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize);
FMSTR_BPTR FMSTR_WriteMem(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_WriteVar(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize);
FMSTR_BPTR FMSTR_WriteVarMask(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize);
FMSTR_BPTR FMSTR_WriteMemMask(FMSTR_BPTR pMessageIO);

void FMSTR_InitAppCmds(void);
FMSTR_BPTR FMSTR_StoreAppCmd(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetAppCmdStatus(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetAppCmdRespData(FMSTR_BPTR pMessageIO);

void FMSTR_InitScope(void);
FMSTR_BPTR FMSTR_SetUpScope(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_ReadScope(FMSTR_BPTR pMessageIO);

void FMSTR_InitRec(void);
FMSTR_BPTR FMSTR_SetUpRec(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_StartRec(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_StopRec(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetRecStatus(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetRecBuff(FMSTR_BPTR pMessageIO);
FMSTR_BOOL FMSTR_IsInRecBuffer(FMSTR_ADDR nAddr, FMSTR_SIZE8 nSize);
FMSTR_SIZE FMSTR_GetRecBuffSize(void);

void FMSTR_InitTsa(void);
FMSTR_BPTR FMSTR_GetTsaInfo(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_GetStringLen(FMSTR_BPTR pMessageIO);
FMSTR_BOOL FMSTR_CheckTsaSpace(FMSTR_ADDR nAddr, FMSTR_SIZE8 nSize, FMSTR_BOOL bWriteAccess);
FMSTR_U16  FMSTR_StrLen(FMSTR_ADDR nAddr);

void FMSTR_InitSfio(void);
FMSTR_BPTR FMSTR_SfioFrame(FMSTR_BPTR pMessageIO);
FMSTR_BPTR FMSTR_SfioGetResp(FMSTR_BPTR pMessageIO);

void FMSTR_InitPipes(void);
FMSTR_BPTR FMSTR_PipeFrame(FMSTR_BPTR pMessageIO);

void FMSTR_InitCan(void);
void FMSTR_SetCanCmdID(FMSTR_U32 canID);
void FMSTR_SetCanRespID(FMSTR_U32 canID);
FMSTR_BOOL FMSTR_TxCan(void);
FMSTR_BOOL FMSTR_RxCan(void);
void FMSTR_ProcessCanRx(void);
void FMSTR_ProcessCanTx(void);

/****************************************************************************************
* Potentialy unused variable declaration
*****************************************************************************************/

#ifdef  _lint
#define FMSTR_UNUSED(sym) /*lint -esym(715,sym) -esym(818,sym) -esym(529,sym) -e{960} */
#else
#define FMSTR_UNUSED(sym) ((sym),0)
#endif

/******************************************************************************
* Configuration check 
******************************************************************************/

/* polling mode as default when nothing selected */
#if !defined(FMSTR_POLL_DRIVEN) && !defined(FMSTR_LONG_INTR) && !defined(FMSTR_SHORT_INTR)
    #define FMSTR_LONG_INTR   0
    #define FMSTR_SHORT_INTR  0
    #define FMSTR_POLL_DRIVEN 1
#endif

/* otherwise, "undefined" means false for all three options */
#ifndef FMSTR_POLL_DRIVEN
#define FMSTR_POLL_DRIVEN 0
#endif
#ifndef FMSTR_LONG_INTR
#define FMSTR_LONG_INTR 0
#endif
#ifndef FMSTR_SHORT_INTR
#define FMSTR_SHORT_INTR 0
#endif

#if (FMSTR_LONG_INTR && (FMSTR_SHORT_INTR || FMSTR_POLL_DRIVEN)) || \
    (FMSTR_SHORT_INTR && (FMSTR_LONG_INTR || FMSTR_POLL_DRIVEN)) || \
    (FMSTR_POLL_DRIVEN && (FMSTR_LONG_INTR || FMSTR_SHORT_INTR)) || \
    !(FMSTR_POLL_DRIVEN || FMSTR_LONG_INTR || FMSTR_SHORT_INTR)
    /* mismatch in interrupt modes, only one can be selected */
    #error You have to enable exctly one of FMSTR_LONG_INTR or FMSTR_SHORT_INTR or FMSTR_POLL_DRIVEN
#endif

#if FMSTR_SHORT_INTR
    /* default short-interrupt FIFO size */
    #ifndef FMSTR_COMM_RQUEUE_SIZE
    #define FMSTR_COMM_RQUEUE_SIZE 32
    #endif

    #if !FMSTR_COMM_RQUEUE_SIZE
    #undef  FMSTR_COMM_RQUEUE_SIZE
    #define FMSTR_COMM_RQUEUE_SIZE 32
    #endif
    
    #if FMSTR_COMM_RQUEUE_SIZE < 1
    #error Error in FMSTR_COMM_RQUEUE_SIZE value.
    #endif
#endif

/* select JTAG, SCI or CAN interface */
/* one of these is typically already enabled in freemaster_cfg.h */
#ifndef FMSTR_USE_JTAG
#define FMSTR_USE_JTAG 0
#endif

#ifndef FMSTR_USE_MSCAN
    #define FMSTR_USE_MSCAN 0
#endif

#ifndef FMSTR_USE_FLEXCAN
    #define FMSTR_USE_FLEXCAN 0
#endif

#ifndef FMSTR_USE_CAN
    #if ((FMSTR_USE_MSCAN) || (FMSTR_USE_FLEXCAN))
    #define FMSTR_USE_CAN 1
    #else
    #define FMSTR_USE_CAN 0
    #endif
#endif

#ifndef FMSTR_USE_MQX_IO
    #define FMSTR_USE_MQX_IO 0
#endif
#ifndef FMSTR_PLATFORM_MQX
    #define FMSTR_PLATFORM_MQX 0
#endif

/* SCI used by default if BASE address is provided */
#ifndef FMSTR_USE_SCI
    #if defined(FMSTR_SCI_BASE) && !FMSTR_USE_JTAG && !FMSTR_USE_CAN && !FMSTR_USE_MQX_IO
    #define FMSTR_USE_SCI 1
    #else
    #define FMSTR_USE_SCI 0
    #endif
#endif

/* only one communication link may be selected */
#if ((((FMSTR_USE_SCI)?1:0) + ((FMSTR_USE_JTAG)?1:0) + ((FMSTR_USE_CAN)?1:0)) > 1)
#error More than one communication interface selected for FreeMASTER driver
#endif

/* SCI does not have a transmission double buffer (kind of queue) */
/* (if not specified differently in platform-dependent header file) */
#if FMSTR_USE_SCI
    #ifndef FMSTR_SCI_BASE
    #error FMSTR_SCI_BASE must be defined when using SCI interface
    #endif

    #ifndef FMSTR_SCI_HAS_TXQUEUE
    #define FMSTR_SCI_HAS_TXQUEUE 0
    #endif
    
    #ifndef FMSTR_SCI_TE_RE
    #define FMSTR_SCI_TE_RE() do {FMSTR_SCI_TE(); FMSTR_SCI_RE();} while(0)
    #endif

#endif

/* CAN is MSCAN or FLEXCAN */
#if FMSTR_USE_CAN
   
    /* if CANHW is not specified in freemaster.h, the platform is not yet tested with CAN */
    #if (!defined(FMSTR_CANHW_MSCAN)) && FMSTR_USE_MSCAN
    #warning MSCAN support not yet fully tested on this platform
    #endif

    /* if CANHW is not specified in freemaster.h, the platform is not yet tested with CAN */
    #if (!defined(FMSTR_CANHW_FLEXCAN)) && FMSTR_USE_FLEXCAN
    #warning FlexCAN support not yet fully tested on this platform
    #endif

   
    #ifndef FMSTR_CAN_BASE
    #error FMSTR_CAN_BASE must be defined when is using CAN interface
    #endif
    
    /* can't be both*/
    #if (FMSTR_USE_MSCAN) && (FMSTR_USE_FLEXCAN)
    #error Can not configure FreeMASTER to use both MSCAN and FlexCAN
    #endif
    
    /* should be at least one */
    #if !(FMSTR_USE_MSCAN) && !(FMSTR_USE_FLEXCAN)
    #error Please select if MSCAN or FlexCAN will be used
    #endif

    /* flexcan needs to know the transmit and receive MB number */
    #if FMSTR_USE_FLEXCAN
        /* Flexcan TX message buffer must be defined */
        #ifndef FMSTR_FLEXCAN_TXMB
        //#error FlexCAN transmit buffer needs to be specified (use FMSTR_FLEXCAN_TXMB)
        #warning "FlexCAN Message Buffer 0 is used for transmit messages"
        #define FMSTR_FLEXCAN_TXMB 0
        #endif
        /* Flexcan RX message buffer must be defined */
        #ifndef FMSTR_FLEXCAN_RXMB
        //#error FlexCAN receive buffer needs to be specified (use FMSTR_FLEXCAN_RXMB)
        #warning "FlexCAN Message Buffer 1 is used for receive messages"
        #define FMSTR_FLEXCAN_RXMB 1
        #endif

        #if FMSTR_FLEXCAN_TXMB == FMSTR_FLEXCAN_RXMB
            #warning FCAN RX and FCAN TX are using same Message Buffer. FreeMASTER CAN driver doesnt support this configuration. Please change number of Message Buffer in FMSTR_FLEXCAN_TXMB or FMSTR_FLEXCAN_RXMB macros.
        #endif
    #endif

  
    /* incoming (command) CAN message ID */
    #ifndef FMSTR_CAN_CMDID
    #define FMSTR_CAN_CMDID 0x7aa
    #endif

    /* command ID can be changed in runtime (before FMSTR_Init) */
    #ifndef FMSTR_CAN_CMDID_DYNAMIC
    #define FMSTR_CAN_CMDID_DYNAMIC 0  /* disabled by default */
    #endif
    
    /* response CAN message ID, may be the same as command ID */
    #ifndef FMSTR_CAN_RESPID
    #define FMSTR_CAN_RESPID 0x7aa
    #endif
    
    /* response ID can be changed in runtime (before FMSTR_Init) */
    #ifndef FMSTR_CAN_RESPID_DYNAMIC
    #define FMSTR_CAN_RESPID_DYNAMIC 0  /* disabled by default */
    #endif

#endif

/* MQX communication interface warnings and errors */
#if FMSTR_USE_MQX_IO
    
    /* define FreeMASTER IO Channel */
    #ifndef FMSTR_MQX_IO_CHANNEL
        #warning MQX IO Channel is not defined by FMSTR_MQX_IO_CHANNEL macro, FreeMASTER use "ttya:" IO Channel
        #define FMSTR_MQX_IO_CHANNEL "ttya:"
    #endif
   
    /* configure the FreeMASTER communication channel to non blocking mode */
    #ifndef FMSTR_MQX_IO_BLOCKING
        #warning FMSTR_MQX_IO_BLOCKING macro is not defined, the MQX IO Channel will be open in non blocking mode
        #define FMSTR_MQX_IO_BLOCKING 0
    #endif
    
    /* MQX open port paramters */
    #if FMSTR_MQX_IO_BLOCKING
         #define FMSTR_MQX_IO_PARAMETER 0
    #else
         #define FMSTR_MQX_IO_PARAMETER IO_SERIAL_NON_BLOCKING
    #endif

    /* MQX doesn't supports Long interrupt and Short interrupt */
    #if FMSTR_LONG_INTR
         #warning "MQX target driver doesn't supports the Long Interrupt routines"
    #elif FMSTR_SHORT_INTR
         #warning "MQX target driver doesn't supports the normal Short Interrupt routines, please open your MQX communication interface in Interrupt mode"
    #endif
    

#endif

#if FMSTR_PLATFORM_MQX
    #if FMSTR_USE_SCI
    #error "MQX target driver doesn't supports the SCI module as communication interface"
    #elif FMSTR_USE_CAN
    #error "MQX target driver doesn't supports the CAN module as communication interface"
    #elif FMSTR_USE_JTAG
    #error "MQX target driver doesn't supports the JTAG module as communication interface"
    #endif
#endif

/* read memory commands are ENABLED by default */
#ifndef FMSTR_USE_READMEM
#define FMSTR_USE_READMEM 1
#endif
#ifndef FMSTR_USE_WRITEMEM
#define FMSTR_USE_WRITEMEM 1
#endif
#ifndef FMSTR_USE_WRITEMEMMASK 
#define FMSTR_USE_WRITEMEMMASK 1
#endif

/* read variable commands are DISABLED by default */
#ifndef FMSTR_USE_READVAR
#define FMSTR_USE_READVAR 0
#endif
#ifndef FMSTR_USE_WRITEVAR
#define FMSTR_USE_WRITEVAR 0
#endif
#ifndef FMSTR_USE_WRITEVARMASK 
#define FMSTR_USE_WRITEVARMASK 0
#endif

/* default scope settings */
#ifndef FMSTR_USE_SCOPE
#define FMSTR_USE_SCOPE 1
#endif

#ifndef FMSTR_MAX_SCOPE_VARS
#define FMSTR_MAX_SCOPE_VARS 8
#endif

/* check scope settings */
#if FMSTR_USE_SCOPE
    #if FMSTR_MAX_SCOPE_VARS > 8 || FMSTR_MAX_SCOPE_VARS < 2
        #error Error in FMSTR_MAX_SCOPE_VARS value. Use a value in range 2..8
    #endif
#endif  

/* default recorder settings */
#ifndef FMSTR_USE_RECORDER
#define FMSTR_USE_RECORDER 1
#endif

#ifndef FMSTR_MAX_REC_VARS
#define FMSTR_MAX_REC_VARS 8
#endif

#ifndef FMSTR_REC_FARBUFF
#define FMSTR_REC_FARBUFF 0
#endif

#ifndef FMSTR_REC_OWNBUFF
#define FMSTR_REC_OWNBUFF 0
#endif

#ifndef FMSTR_USE_FASTREC
#define FMSTR_USE_FASTREC 0
#endif

/* Enable code size optimalization */
#ifndef FMSTR_LIGHT_VERSION
#define FMSTR_LIGHT_VERSION 1
#endif

/* Always report sigle error code from recorder routines  */
#ifndef FMSTR_REC_COMMON_ERR_CODES
#define FMSTR_REC_COMMON_ERR_CODES FMSTR_LIGHT_VERSION
#endif

/* Remove code for single wire communication */
#ifndef FMSTR_SCI_TWOWIRE_ONLY
#define FMSTR_SCI_TWOWIRE_ONLY FMSTR_LIGHT_VERSION
#endif

/* Number of recorder post-trigger samples is by default controlled by PC */
#ifndef FMSTR_REC_STATIC_POSTTRIG
#define FMSTR_REC_STATIC_POSTTRIG 0
#endif

/* Recorder divisor is by default controlled by PC */
#ifndef FMSTR_REC_STATIC_DIVISOR
#define FMSTR_REC_STATIC_DIVISOR 0
#endif

/* check recorder settings */
#if FMSTR_USE_RECORDER || FMSTR_USE_FASTREC
    #if FMSTR_MAX_REC_VARS > 8 || FMSTR_MAX_REC_VARS < 2
        #error Error in FMSTR_MAX_REC_VARS value. Use a value in range 2..8
    #endif
    
    /* 0 means recorder time base is "unknown" */
    #ifndef FMSTR_REC_TIMEBASE
    #define FMSTR_REC_TIMEBASE 0 
    #endif
    
    /* default recorder buffer size is 256 */
    #ifndef FMSTR_REC_BUFF_SIZE
    #define FMSTR_REC_BUFF_SIZE 256
    #endif

    #if !FMSTR_USE_READMEM
    #error Recorder needs the FMSTR_USE_READMEM feature
    #endif
#endif  

/* fast recorder requires its own allocation of recorder buffer */
#if FMSTR_USE_FASTREC
    #if FMSTR_REC_OWNBUFF
        #error Fast recorder requires its own buffer allocation
    #endif
#endif

/* default app.cmds settings */
#ifndef FMSTR_USE_APPCMD
#define FMSTR_USE_APPCMD 0
#endif

#ifndef FMSTR_APPCMD_BUFF_SIZE
#define FMSTR_APPCMD_BUFF_SIZE 16
#endif

#ifndef FMSTR_MAX_APPCMD_CALLS
#define FMSTR_MAX_APPCMD_CALLS 0
#endif

/* TSA configuration check */
#ifndef FMSTR_USE_TSA
#define FMSTR_USE_TSA 0
#endif

#ifndef FMSTR_USE_TSA_SAFETY
#define FMSTR_USE_TSA_SAFETY 0
#endif

#if FMSTR_USE_TSA
    #if !FMSTR_USE_READMEM
        #error TSA needs the FMSTR_USE_READMEM feature
    #endif
#endif

/* SFIO not used by default */
#ifndef FMSTR_USE_SFIO
#define FMSTR_USE_SFIO 0
#endif

/* check SFIO settings */
#if FMSTR_USE_SFIO

    /* The SFIO configuration files (sfio.h and optionally also the sfio_cfg.h) exist 
       in project to define SFIO parameters. */
    #include "sfio.h"
    
    #ifndef SFIO_MAX_INPUT_DATA_LENGTH
    #error  SFIO_MAX_INPUT_DATA_LENGTH was not defined in sfio_cfg.h
    #endif
    #ifndef SFIO_MAX_OUTPUT_DATA_LENGTH
    #error  SFIO_MAX_OUTPUT_DATA_LENGTH was not defined in sfio_cfg.h
    #endif
    
#endif    

/* use transport "pipe" functionality */
#ifndef FMSTR_USE_PIPES
#define FMSTR_USE_PIPES 0
#endif

/* "pipe" putstring formatting (enabled by default) */
#ifndef FMSTR_USE_PIPE_PRINTF
#define FMSTR_USE_PIPE_PRINTF 1
#endif

/* "pipe" variable-argument printf (enabled by default) */
#ifndef FMSTR_USE_PIPE_PRINTF_VARG
#define FMSTR_USE_PIPE_PRINTF_VARG FMSTR_USE_PIPE_PRINTF
#endif

#if FMSTR_USE_PIPES

    #ifdef FMSTR_PIPES_EXPERIMENTAL
    #warning The "pipes" feature is now in experimental code phase. Not yet tested on this platform.
    #endif        

    /* one pipe by default */    
    #ifndef FMSTR_MAX_PIPES_COUNT
    #define FMSTR_MAX_PIPES_COUNT 1
    #endif

    /* must enable printf for vararg printf */
    #if !(FMSTR_USE_PIPE_PRINTF) && (FMSTR_USE_PIPE_PRINTF_VARG)
    #error You must enable pipe printf for vararg printf (see FMSTR_USE_PIPE_PRINTF)
    #endif
    
    /* pipe printf buffer */    
    #ifndef FMSTR_PIPES_PRINTF_BUFF_SIZE
    #define FMSTR_PIPES_PRINTF_BUFF_SIZE 48
    #endif

    /* at least one */
    #if FMSTR_MAX_PIPES_COUNT < 1
    #warning No sense to allocate zero-count pipes. Disabling pipes.
    #undef  FMSTR_USE_PIPES
    #define FMSTR_USE_PIPES 0
    #endif

    /* printf buffer should accept one integer printed */    
    #if FMSTR_PIPES_PRINTF_BUFF_SIZE < 8
    #error Pipe printf buffer should be at least 8 (see FMSTR_PIPES_PRINTF_BUFF_SIZE)
    #endif
    #if FMSTR_PIPES_PRINTF_BUFF_SIZE > 255
    #error Pipe printf buffer should not exceed 255 (see FMSTR_PIPES_PRINTF_BUFF_SIZE)
    #endif
    
#endif

/* what kind of board information structure will be sent? */
#ifndef FMSTR_USE_BRIEFINFO
    #if FMSTR_USE_RECORDER
        /* recorder requires full info */
        #define FMSTR_USE_BRIEFINFO 0
    #else
        /* otherwise no brief info is enough */
        #define FMSTR_USE_BRIEFINFO 1
    #endif
#endif

/* check what kind of board info is sent */
#if FMSTR_USE_BRIEFINFO
    #if FMSTR_USE_RECORDER
        #warning The full information structure must be used when recorder is to be used
        #undef  FMSTR_USE_BRIEFINFO
        #define FMSTR_USE_BRIEFINFO 1
    #endif
#endif

/* automatic buffer size by default */
#ifndef FMSTR_COMM_BUFFER_SIZE
#define FMSTR_COMM_BUFFER_SIZE 0
#endif

/* check minimal buffer size required for all enabled features */
#if FMSTR_COMM_BUFFER_SIZE
    
    /* basic commands (getinfobrief, write/read memory etc.) */
    #if FMSTR_USE_BRIEFINFO && FMSTR_COMM_BUFFER_SIZE < 11 
    #error FMSTR_COMM_BUFFER_SIZE set too small for basic FreeMASTER commands (11 bytes)
    #endif

    /* full info required */
    #if !(FMSTR_USE_BRIEFINFO) && FMSTR_COMM_BUFFER_SIZE < 35
    #error FMSTR_COMM_BUFFER_SIZE set too small for GETINFO command (size 35)
    #endif

    /* application commands */
    #if FMSTR_USE_APPCMD && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_APPCMD_BUFF_SIZE)+1)
    #error FMSTR_COMM_BUFFER_SIZE set too small for SENDAPPCMD command (size FMSTR_APPCMD_BUFF_SIZE+1)
    #endif

    /* configuring scope (EX) */
    #if FMSTR_USE_SCOPE && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_MAX_SCOPE_VARS)*5+1)
    #error FMSTR_COMM_BUFFER_SIZE set too small for SETUPSCOPEEX command (size FMSTR_MAX_SCOPE_VARS*5+1)
    #endif

    /* configuring recorder (EX) */
    #if FMSTR_USE_RECORDER && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_MAX_REC_VARS)*5+18)
    #error FMSTR_COMM_BUFFER_SIZE set too small for SETUPRECEX command (size FMSTR_MAX_REC_VARS*5+18)
    #endif
    
    /* SFIO encapsulation */
    #if FMSTR_USE_SFIO
    #if (FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_INPUT_DATA_LENGTH)+1)) || \
        (FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_OUTPUT_DATA_LENGTH)+1))
    #error FMSTR_COMM_BUFFER_SIZE set too small for SFIO encapsulation (see SFIO_MAX_xxx_DATA_LENGTH)
    #endif
    #endif

/* automatic: determine required buffer size based on features enabled */
#else
    /* smallest for basic commands (getinfobrief, write/read memory etc.) */
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE 11

    /* full info required */
    #if !(FMSTR_USE_BRIEFINFO) && FMSTR_COMM_BUFFER_SIZE < 35
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE 35
    #endif

    /* using application commands (must accomodate maximal app.cmd data length) */
    #if FMSTR_USE_APPCMD && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_APPCMD_BUFF_SIZE)+1)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((FMSTR_APPCMD_BUFF_SIZE)+1)
    #endif

    /* configuring scope (EX) */
    #if FMSTR_USE_SCOPE && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_MAX_SCOPE_VARS)*5+1)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((FMSTR_MAX_SCOPE_VARS)*5+1)
    #endif

    /* configuring recorder (EX) */
    #if FMSTR_USE_RECORDER && FMSTR_COMM_BUFFER_SIZE < ((FMSTR_MAX_REC_VARS)*5+18)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((FMSTR_MAX_REC_VARS)*5+18)
    #endif

    /* SFIO encapsulation (in buffer) */
    #if FMSTR_USE_SFIO
    #if FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_INPUT_DATA_LENGTH)+1)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((SFIO_MAX_INPUT_DATA_LENGTH)+1)
    #endif
    #endif
    
    /* SFIO encapsulation (out buffer) */
    #if FMSTR_USE_SFIO
    #if FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_OUTPUT_DATA_LENGTH)+1)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((SFIO_MAX_OUTPUT_DATA_LENGTH)+1)
    #endif
    #endif
    
#endif

#endif /* __FREEMASTER_PRIVATE_H */

