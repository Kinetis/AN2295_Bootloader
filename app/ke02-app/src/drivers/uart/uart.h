/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file UART.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Jul 17, 2011
*
* @brief provide commond UART utilities. 
*
*******************************************************************************
*
* provide APIs for accessing UART. more APIs to be added.
******************************************************************************/
#ifndef _UART_H_
#define _UART_H_
#include "common.h"

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

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

#define UART_INT

void Init_SCI0(dword busCLKHz, dword bitRate);
void Init_SCI1(dword busCLKHz, dword bitRate);
void Init_SCI2(dword busCLKHz, dword bitRate);


char TERMIO_GetChar0(void);
char TERMIO_GetChar1(void);
char TERMIO_GetChar2(void);

void TERMIO_PutChar0(char send);
void TERMIO_PutChar1(char send);
void TERMIO_PutChar2(char send);
void wait_sci_tx_empty(void);
char TERMIO_is_char_present(void);
void wait_sci_tx_complete(void);
void UART_InitPrint(void);

/* Kinetis style */
void UART_init (UART_MemMapPtr, int, int);
char UART_getchar (UART_MemMapPtr);
void UART_putchar (UART_MemMapPtr, char);
int UART_getchar_present (UART_MemMapPtr);

/* interrupt handler */
#define SEND_BUF_LEN 20

void UART_enable_irq(UART_MemMapPtr UART_base);
#define enable_UART0_int() { UART_enable_irq(UART0_BASE_PTR); }
#define enable_UART1_int() { UART_enable_irq(UART1_BASE_PTR); }

#define UART0_send_byte(ch) { UART_D_REG(UART0_BASE_PTR) = ch; }
#define UART1_send_byte(ch) { UART_D_REG(UART1_BASE_PTR) = ch; }

typedef void (*T_UartTx_Callback)(void);
typedef void (*T_UartRx_Callback)(int8);

void UART_set_tx_handler(T_UartTx_Callback tx);
void UART_set_rx_handler(T_UartRx_Callback rx);
void printf_int(int8* str);

#endif /* #ifndef _UART_H_ */
