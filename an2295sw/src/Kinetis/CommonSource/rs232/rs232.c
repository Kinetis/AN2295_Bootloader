/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      rs232.c
 * @author    R20253
 * @version   1.0.8.0
 * @date      Dec-11-2012
 * @brief     RS232 driver
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/

#include "kinetis_params.h"
#include "wdg.h"
#include "rs232.h"

/**************************************************************//*!
* UART Initialization  
******************************************************************/
void UART_Initialization(void)
{
  UART_BDH_REG(BOOT_UART_BASE)     = ((UART_SBR>>8)&0x1f);
  UART_BDL_REG(BOOT_UART_BASE)     = (UART_SBR&0xff);
#if IS_Kxx_FAMILY  
  UART_C4_REG(BOOT_UART_BASE)      = (UART_BRFA&0x1f);  
#endif
  UART_C2_REG(BOOT_UART_BASE)      = UART_C2_TE_MASK|UART_C2_RE_MASK;

  while(UART_IsChar())
    (void)UART_GetChar();
}

/**************************************************************//*!
* Function for sending one character   
******************************************************************/
void UART_PutChar(unsigned char data)
{
  while((UART_S1_REG(BOOT_UART_BASE)&UART_S1_TC_MASK) == 0){};
  UART_D_REG(BOOT_UART_BASE) = data;
}

/**************************************************************//*!
* Function for receiving of one character  
******************************************************************/
unsigned char UART_GetChar(void)
{
  while(UART_IsChar() == 0){

#if BOOTLOADER_INT_WATCHDOG == 1
    WDG_Refresh(); /* feeds the dog */
#endif
		
};
  
  return UART_D_REG(BOOT_UART_BASE);
}
