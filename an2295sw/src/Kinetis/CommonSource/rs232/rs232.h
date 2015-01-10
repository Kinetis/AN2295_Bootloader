/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      rs232.h
 * @author    R20253
 * @version   1.0.9.0
 * @date      Dec-11-2012
 * @brief     RS232 driver header file
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/
#ifndef _RS232_H
	#define _RS232_H

	#include "kinetis_params.h"

	#define UART_SBR  (unsigned char)(BOOT_BUS_CLOCK / (16*BOOT_UART_BAUD_RATE))
	#define UART_BRFA (unsigned char)((((BOOT_BUS_CLOCK/(16*BOOT_UART_BAUD_RATE))- \
                          UART_SBR)*32.0)+0.5)

	//  API
	void UART_Initialization(void);
	#define UART_Deinitialization() UART_C2_REG(BOOT_UART_BASE) = 0
	void UART_PutChar(unsigned char data);
	unsigned char UART_GetChar(void);
	#define UART_IsChar() (UART_S1_REG(BOOT_UART_BASE) & UART_S1_RDRF_MASK)
#endif
