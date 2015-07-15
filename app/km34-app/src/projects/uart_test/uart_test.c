/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ******************************************************************************
 * uart_test.c
 ******************************************************************************/
#include "drivers.h"

void main (void)
{
  char c;

  SIM_Init  (SIM_MODULE_ALL_PERIPH_ON_CONFIG);

  /* route core clock to PTF7                                                 */
  SIM_SelClkout (CLKOUT_SRC2);
  PORT_Init (PORTF,PORT_MODULE_ALT3_MODE,PIN7);

  /* clock mode 1:1:1, 24MHz                                                  */
  SIM_SetClkMode (SYSCLK_MODE0);
  SIM_SetClkDiv  (SYSCLK_DIV1);
  FLL_Init  (FLL_MODULE_FEI_20_25MHZ_CONFIG);

  /* UART1 init 9600bd                                                        */
  PORT_Init (PORTI, PORT_MODULE_ALT2_MODE, PIN0|PIN1);
  UART_Init (UART1, UART_MODULE_POLLMODE_CONFIG(9600,20e6));

  UART_PutStr (UART1,"\n\rCharacters will be echoed on the screen:\n");

  while(1)
  {
    /* read and echo character                                                */
    while (!UART_RxFull(UART1));
    c = UART_GetChar (UART1);
    while (!UART_TxIdle(UART1));
    UART_PutChar (UART1,c);
  }
}