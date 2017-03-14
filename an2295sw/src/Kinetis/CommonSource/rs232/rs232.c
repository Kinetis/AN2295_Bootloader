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

#ifdef LPUART_USED
 
/**************************************************************//*!
* UART Initialization  
******************************************************************/
void UART_Initialization(void)
{
  
  LPUART_CTRL_REG(BOOT_UART_BASE) &= ~LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK;
  
  LPUART_BAUD_REG(BOOT_UART_BASE) |= LPUART_BAUD_SBR(LPUART_SBR);
  
  
  LPUART_CTRL_REG(BOOT_UART_BASE) |= LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK;

  if(UART_IsChar())
  {
      (void)UART_GetChar();
  }

    
}   




/**************************************************************//*!
* Function for sending one character   
******************************************************************/
void UART_PutChar(unsigned char data)
{
  
  while(!(LPUART_STAT_REG(BOOT_UART_BASE) & LPUART_STAT_TDRE_MASK))
  {
    ;
  }
  LPUART_DATA_REG(BOOT_UART_BASE) = data;
 
}



/**************************************************************//*!
* Function for receiving of one character  
******************************************************************/
unsigned char UART_GetChar(void)
{
  unsigned char ret = 0;
  while(UART_IsChar() == 0){

#if BOOTLOADER_INT_WATCHDOG == 1
    WDG_Refresh(); /* feeds the dog */
#endif
		
};
  ret = LPUART_DATA_REG(BOOT_UART_BASE);
  return ret;
}



#else  
   
/**************************************************************//*!
* UART Initialization  
******************************************************************/
void UART_Initialization(void)
{
  UART_BDH_REG(BOOT_UART_BASE)     = ((UART_SBR>>8)&0x1f);
  UART_BDL_REG(BOOT_UART_BASE)     = (UART_SBR&0xff);
  
#if (defined(KINETIS_K) || defined(KINETIS_V))
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
  unsigned char ret = 0;
  while(UART_IsChar() == 0){

#if BOOTLOADER_INT_WATCHDOG == 1
    WDG_Refresh(); /* feeds the dog */
#endif
		
};
  ret = UART_D_REG(BOOT_UART_BASE);
  return ret;
}

#endif
