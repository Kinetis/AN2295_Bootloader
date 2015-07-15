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
* @brief  FreeMASTER driver default configuration
*
*******************************************************************************/

#ifndef __FREEMASTER_DEFCFG_H
#define __FREEMASTER_DEFCFG_H

/* Read user configuration */
#include "freemaster_cfg.h"

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


#if FMSTR_SHORT_INTR
    /* default short-interrupt FIFO size */
    #ifndef FMSTR_COMM_RQUEUE_SIZE
    #define FMSTR_COMM_RQUEUE_SIZE 32
    #endif

    #if !FMSTR_COMM_RQUEUE_SIZE
    #undef  FMSTR_COMM_RQUEUE_SIZE
    #define FMSTR_COMM_RQUEUE_SIZE 32
    #endif
#endif

/* select JTAG, SCI or CAN interface */
/* one of these is typically already enabled in freemaster_cfg.h */
#ifndef FMSTR_USE_ESCI
#define FMSTR_USE_ESCI 0
#endif

#ifndef FMSTR_USE_LPUART
#define FMSTR_USE_LPUART 0
#endif

#ifndef FMSTR_USE_JTAG
#define FMSTR_USE_JTAG 0
#endif

#ifndef FMSTR_USE_MSCAN
    #define FMSTR_USE_MSCAN 0
#endif

#ifndef FMSTR_USE_FLEXCAN
    #define FMSTR_USE_FLEXCAN 0
#endif

#ifndef FMSTR_USE_FLEXCAN32
    #define FMSTR_USE_FLEXCAN32 0
#endif

#ifndef FMSTR_USE_CAN
    #if ((FMSTR_USE_MSCAN) || (FMSTR_USE_FLEXCAN)  || (FMSTR_USE_FLEXCAN32))
    #define FMSTR_USE_CAN 1
    #else
    #define FMSTR_USE_CAN 0
    #endif
#endif

#ifndef FMSTR_USE_MQX_IO
    #define FMSTR_USE_MQX_IO 0
#endif

#ifndef FMSTR_USE_USB_CDC
    #define FMSTR_USE_USB_CDC 0
#endif

#ifndef FMSTR_USE_PDBDM
    #define FMSTR_USE_PDBDM 0
#endif

#ifndef FMSTR_DISABLE
    #define FMSTR_DISABLE 0
#endif

/* SCI used by default if BASE address is provided */
#ifndef FMSTR_USE_SCI
    #if defined(FMSTR_SCI_BASE) && !FMSTR_USE_ESCI && !FMSTR_USE_LPUART && !FMSTR_USE_JTAG && !FMSTR_USE_CAN && !FMSTR_USE_MQX_IO && !FMSTR_USE_USB_CDC && !FMSTR_DISABLE && !FMSTR_USE_PDBDM
    #define FMSTR_USE_SCI 1
    #else
    #define FMSTR_USE_SCI 0
    #endif
#endif

/* SCI does not have a transmission double buffer (kind of queue) */
/* (if not specified differently in platform-dependent header file) */
#if (FMSTR_USE_SCI) || (FMSTR_USE_ESCI)|| (FMSTR_USE_LPUART)
    #ifndef FMSTR_SCI_HAS_TXQUEUE
    #define FMSTR_SCI_HAS_TXQUEUE 0
    #endif
#endif

/* CAN is MSCAN or FLEXCAN */
#if FMSTR_USE_CAN

    /* CAN-related constants */
    #ifdef FMSTR_CAN_EXTID
        #if FMSTR_CAN_EXTID != 0x80000000U
            #error FMSTR_CAN_EXTID must be defined as 0x80000000
            #undef FMSTR_CAN_EXTID
        #endif
    #endif

    #ifndef FMSTR_CAN_EXTID
        #define FMSTR_CAN_EXTID 0x80000000U
    #endif

    /* flexcan needs to know the transmit and receive MB number */
    #if ((FMSTR_USE_FLEXCAN) || (FMSTR_USE_FLEXCAN32))
        /* Flexcan TX message buffer must be defined */
        #ifndef FMSTR_FLEXCAN_TXMB
        //#error FlexCAN transmit buffer needs to be specified (use FMSTR_FLEXCAN_TXMB)
        #warning "FlexCAN Message Buffer 0 is used for transmitting messages"
        #define FMSTR_FLEXCAN_TXMB 0
        #endif
        /* Flexcan RX message buffer must be defined */
        #ifndef FMSTR_FLEXCAN_RXMB
        //#error FlexCAN receive buffer needs to be specified (use FMSTR_FLEXCAN_RXMB)
        #warning "FlexCAN Message Buffer 1 is used for receiving messages"
        #define FMSTR_FLEXCAN_RXMB 1
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

#if FMSTR_USE_USB_CDC
    #ifndef FMSTR_USB_CDC_ID
    #define  FMSTR_USB_CDC_ID      (0)   /* ID to identify USB CONTROLLER used by FreeMASTER */
    #endif
#endif

/* Enables or disables byte access to communication buffer */
#ifndef FMSTR_BYTE_BUFFER_ACCESS
#define FMSTR_BYTE_BUFFER_ACCESS 1
#endif

/* Disable call of User callback function */
//#ifndef FMSTR_ISR_CALLBACK
//#define FMSTR_ISR_CALLBACK 0
//#endif

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
#define FMSTR_USE_SCOPE 0
#endif

#ifndef FMSTR_MAX_SCOPE_VARS
#define FMSTR_MAX_SCOPE_VARS 8
#endif
/* default recorder settings */
#ifndef FMSTR_USE_RECORDER
#define FMSTR_USE_RECORDER 0
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
#define FMSTR_LIGHT_VERSION 0
#endif

/* Always report single error code from recorder routines  */
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

/* Enable Floating point support in Recorder triggering */
#ifndef FMSTR_REC_FLOAT_TRIG
#define FMSTR_REC_FLOAT_TRIG 0
#endif

/* Enable larger mode of recorder */
#ifndef FMSTR_REC_LARGE_MODE
#define  FMSTR_REC_LARGE_MODE 0
#endif

#if FMSTR_REC_LARGE_MODE
#define FMSTR_CFG_REC_LARGE_MODE FMSTR_CFGFLAG_REC_LARGE_MODE
#else
#define FMSTR_CFG_REC_LARGE_MODE 0
#endif

/* check recorder settings */
#if FMSTR_USE_RECORDER || FMSTR_USE_FASTREC

    /* 0 means recorder time base is "unknown" */
    #ifndef FMSTR_REC_TIMEBASE
    #define FMSTR_REC_TIMEBASE 0
    #endif

    /* default recorder buffer size is 256 */
    #ifndef FMSTR_REC_BUFF_SIZE
    #define FMSTR_REC_BUFF_SIZE 256
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

/* TSA table allocation modifier */
#ifndef FMSTR_USE_TSA_INROM
#define FMSTR_USE_TSA_INROM 0
#endif

#if FMSTR_USE_TSA_INROM
#define FMSTR_TSA_CDECL const
#else
#define FMSTR_TSA_CDECL
#endif

/* SFIO not used by default */
#ifndef FMSTR_USE_SFIO
#define FMSTR_USE_SFIO 0
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
    /* one pipe by default */
    #ifndef FMSTR_MAX_PIPES_COUNT
    #define FMSTR_MAX_PIPES_COUNT 1
    #endif

    /* pipe printf buffer */
    #ifndef FMSTR_PIPES_PRINTF_BUFF_SIZE
    #define FMSTR_PIPES_PRINTF_BUFF_SIZE 48
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

/* automatic buffer size by default */
#ifndef FMSTR_COMM_BUFFER_SIZE
#define FMSTR_COMM_BUFFER_SIZE 0
#endif

/* automatic: determine required buffer size based on features enabled */
#if !FMSTR_COMM_BUFFER_SIZE
    /* smallest for basic commands (getinfobrief, write/read memory etc.) */
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE 11

    /* full info required */
    #if !(FMSTR_USE_BRIEFINFO) && (FMSTR_COMM_BUFFER_SIZE < (35+1))
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE (35+1)
    #endif

    /* using application commands (must accommodate maximal app.cmd data length) */
    #if FMSTR_USE_APPCMD && (FMSTR_COMM_BUFFER_SIZE < ((FMSTR_APPCMD_BUFF_SIZE)+1))
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((FMSTR_APPCMD_BUFF_SIZE)+1)
    #endif

    /* configuring scope (EX) */
    #if FMSTR_USE_SCOPE && (FMSTR_COMM_BUFFER_SIZE < (((FMSTR_MAX_SCOPE_VARS)*5)+1+2))
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE (((FMSTR_MAX_SCOPE_VARS)*5)+1+2)
    #endif

    /* configuring recorder (EX) */
    #if FMSTR_USE_RECORDER && (FMSTR_COMM_BUFFER_SIZE < (((FMSTR_MAX_REC_VARS)*5)+18+2))
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE (((FMSTR_MAX_REC_VARS)*5)+18+2)
    #endif

    /* SFIO encapsulation (in buffer) */
    #if FMSTR_USE_SFIO
    #if FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_INPUT_DATA_LENGTH)+1+2)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((SFIO_MAX_INPUT_DATA_LENGTH)+1+2)
    #endif
    #endif

    /* SFIO encapsulation (out buffer) */
    #if FMSTR_USE_SFIO
    #if FMSTR_COMM_BUFFER_SIZE < ((SFIO_MAX_OUTPUT_DATA_LENGTH)+1+2)
    #undef  FMSTR_COMM_BUFFER_SIZE
    #define FMSTR_COMM_BUFFER_SIZE ((SFIO_MAX_OUTPUT_DATA_LENGTH)+1+2)
    #endif
    #endif

#endif

#endif /* __FREEMASTER_DEF_CFG_H */
