/*

 *
 */


#include "common.h"    // Common Kinetis defines

/******************************************************************************
* Global variables
******************************************************************************/


/********************************************************************/
void main (void)
{
  InitPorts();
  
  //clkout_init();
  PORTE_PCR0 = PORT_PCR_MUX(3) ;        // select UART1_TX
  PORTE_PCR1 = PORT_PCR_MUX(3) ;        // select UART1_RX  
  //参数2是系统时钟
  uart_init(TERM_PORT,48000,TERMINAL_BAUD);
  //UART1_Init();
  out_char('S');
  out_char('C');
  out_char('I');
  out_char(' ');
  out_char('D');
  out_char('E');
  out_char('M');
  out_char('O');
  out_char('\n');
  while(1)
  {
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
  }
}