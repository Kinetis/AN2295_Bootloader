/******************** (C) COPYRIGHT 2013 Freescale ********************
* File Name          : Readme.txt
* Author             : Freescale
* Date First Issued  : 04/17/2013 : Version 1.0
* Description        : Description of the UART Example.
********************************************************************************
* History:
* 04/17/2013 : Version 1.0
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, FREESCALE SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

Example description
===================
This example provides a description of how  to use the UART with hardware flow control
and communicate with the Hyperterminal.

The UART1 sends the "Running the Uart_demo project" with polling mode.
and then enter the interrupt mode.
	First, the UART1 sends the string "hello world" to the hyperterminal;
	Second, the UART1 will send the character to Hyperterminal which you entered, 
		and RED led will flicker.


The UART1 is configured as follow:
  - Word Length = 8 Bits
  - One Stop Bit
  - No parity
  - BaudRate = 9600 baud
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled


Directory contents
==================
drivers/uart.h  Library Configuration file
drivers/uart.c  Interrupt handlers
projects/Uart_demo.c      Main program


Hardware environment
====================
 - Board: freedom FRDM-KE02Z, revA
	
 - Connect board and PC with usb cable.

 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = 9600 baud
    - flow control: None 
  
  
How to use it
=============
In order to make the program work, you must do the following :
- Run the example


************************END OF FILE********************************************
