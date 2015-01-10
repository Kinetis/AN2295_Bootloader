/*
 * File:		io.c
 * Purpose:		Serial Input/Output routines
 *
 * Notes:       TERMINAL_PORT defined in <board>.h
 */

#include "common.h"
#include "uart.h"
#include "stdio.h"

//********************************************************************/
char
in_char (void)
{
	return UART_getchar(TERM_PORT);
}
/********************************************************************/
void
out_char (char ch)
{
	UART_putchar(TERM_PORT, ch);
}
/********************************************************************/
int
char_present (void)
{
	return UART_getchar_present(TERM_PORT);
}

#ifdef KEIL
/********************************************************************/
int fputc(int ch, FILE *f)
{
	out_char((char)ch);
	return 1;
}
#endif


/********************************************************************/
