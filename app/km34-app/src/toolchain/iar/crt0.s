/******************************************************************************
 * (c) Copyright 2010-2014, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      crt0.s
 * @version   1.0.2.0
 * @date      Feb-23-2014
 * @brief     Startup function (low level part).
 ******************************************************************************/
    PUBLIC  __iar_program_start
    EXTERN  start
    SECTION .text:CODE
    THUMB
__iar_program_start:
    EORS    r0,r0                           ; clear r0
    EORS    r1,r1                           ; clear r1
    EORS    r2,r2                           ; clear r2
    EORS    r3,r3                           ; clear r3
    EORS    r4,r4                           ; clear r4
    EORS    r5,r5                           ; clear r5
    EORS    r6,r6                           ; clear r6
    EORS    r7,r7                           ; clear r7
    CPSID   i                               ; disable interrupts
    BL      start                           ; call the C code
__done
    B       __done                          ; stay in the loop
    END
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
