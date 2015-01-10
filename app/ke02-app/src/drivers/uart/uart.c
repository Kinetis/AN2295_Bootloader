/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file uart.c
*
* @author Freescale
*
* @version 0.0.1
*
* @date Apr-16-2013
*
* @brief providing common UART routines. 
*
*******************************************************************************
*
* provide APIs for access SCIs. more APIs to be added.
******************************************************************************/
#include "uart.h"

void UART_enable_irq(UART_MemMapPtr uartch);

/******************************************************************************
* Global variables
******************************************************************************/
T_UartTx_Callback tx_handler = NULL;
T_UartRx_Callback rx_handler = NULL;

#define SEND_BUF_L (SEND_BUF_LEN - 1)
int8 send_buf[SEND_BUF_LEN];
int8 send_buf_pos = 0;

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_PutChar0
*
* @brief print a char via SCI0
*        
* @param  send	a char to print 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void TERMIO_PutChar0(char send)
{
    vuint8 dummy;
    
    while((UART0_S1 & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK);
    dummy = UART0_S1;
    UART0_D  = send;
}//end SCI_PutChar

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_GetChar0
*
* @brief receives a char via SCI0
*        
* @param  none 
*
* @return a char received
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

char TERMIO_GetChar0(void)
{
    vuint8 dummy;
    
    while(( UART0_S1 & UART_S1_RDRF_MASK) != UART_S1_RDRF_MASK);
    dummy = UART0_S1;
    dummy = UART0_D;
    return dummy;
} //end SCI_GetChar



/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Init_SCI0
*
* @brief initializes SCI0 baud rate, enable both tx and rx
*        
* @param   
*     dword busCLKHz   : bus clock in Hz
*     dword bitRate    : baud rate
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void Init_SCI0(dword busCLKHz, dword bitRate)
{	  
    uint16 baud_bd;
    
    baud_bd = ((busCLKHz>>4) + (bitRate>>1))/bitRate;
    
    UART0_BDH = baud_bd >> 8;
    UART0_BDL = baud_bd & 0x00ff;
    UART0_C1  = 0;     // 8bit mode, 1 stop bit, no parity
    UART0_C2  = 0x0C;  // enable TX , enable RX
}//end Init_UART0_

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_PutChar1
*
* @brief sends a char via SCI1
*        
* @param  send  a char to be sent
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void TERMIO_PutChar1(char send)
{
    volatile char dummy;
    
    while(( UART1_S1 & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK);
    dummy = UART1_S1;
    UART1_D  = send;
}//end SCI_PutChar

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_GetChar1
*
* @brief receive a char from SCI1
*        
* @param  none 
*
* @return a char received
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

char TERMIO_GetChar1(void)
{
    char dummy;
    
    while(( UART1_S1 & UART_S1_RDRF_MASK) !=UART_S1_RDRF_MASK);
    dummy = UART1_S1;
    dummy = UART1_D;
    return dummy;
} //end SCI_GetChar

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Init_SCI1
*
* @brief initializes SCI1 baud rate, enable both tx and rx
*        
* @param   
*     dword busCLKHz   : bus clock in Hz
*     dword bitRate    : baud rate
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void Init_SCI1(dword busCLKHz, dword bitRate)
{
    uint16_t baud_bd;
    
    baud_bd = ((busCLKHz>>4) + (bitRate>>1))/bitRate;
    
    UART1_BDH = baud_bd >> 8;
    UART1_BDL = baud_bd & 0x00ff;
    UART1_C1  = 0;     // 8bit mode, 1 stop bit, no parity
    UART1_C2  = 0x0C;  // enable TX , enable RX
}//end Init_UART0_


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_PutChar2
*
* @brief send a char thru SCI2
*        
* @param  send, a char to be sent
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void TERMIO_PutChar2(char send)
{
    volatile char dummy;
    
    while(( UART2_S1 & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK);
    dummy = UART2_S1;
    UART2_D  = send;
}//end SCI_PutChar

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_GetChar2
*
* @brief receives a char from SCI2
*        
* @param  none
*
* @return a char received
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

char TERMIO_GetChar2(void)
{
    char dummy;
    
    while(( UART2_S1 & UART_S1_RDRF_MASK) !=UART_S1_RDRF_MASK);
    dummy = UART2_S1;
    dummy = UART2_D;
    return dummy;
} //end SCI_GetChar

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Init_SCI2
*
* @brief initializes SCI baud rate, enable both tx and rx
*        
* @param   
*     dword busCLKHz   : bus clock in Hz
*     dword bitRate    : baud rate
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void Init_SCI2(dword busCLKHz, dword bitRate)
{
    uint16_t baud_bd;
    
    baud_bd = ((busCLKHz>>4) + (bitRate>>1))/bitRate;
    
    UART2_BDH = baud_bd >> 8;
    UART2_BDL = baud_bd & 0x00ff;
    UART2_C1  = 0;     // 8bit mode, 1 stop bit, no parity
    UART2_C2  = 0x0C;  // enable TX , enable RX
}//end Init_UART0_



/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: wait_sci_tx_empty
*
* @brief loops to wait for the SCI tx empty
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void wait_sci_tx_empty(void){
    
    while((UART_S1_REG(TERM_PORT) & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: wait_sci_tx_complete
*
* @brief loops to wait for the SCI tx complete
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void wait_sci_tx_complete(void)
{
    
    while((UART_S1_REG(TERM_PORT) & UART_S1_TC_MASK) != UART_S1_TC_MASK);
    
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: TERMIO_is_char_present
*
* @brief check if any char is keyed.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

char TERMIO_is_char_present(void)
{
    
    if((UART_S1_REG(TERM_PORT) & UART_S1_RDRF_MASK) != UART_S1_RDRF_MASK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: UART_InitPrint
*
* @brief initialize UART for print on port defined by TERM_PORT.
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void UART_InitPrint(void)
{
    UART_init (TERM_PORT, BUS_CLK_HZ/1000, UART_PRINT_BITRATE);
}

/********************************************************************/
/*
* Initialize the UART for 8N1 operation, interrupts disabled, and
* no hardware flow-control
*
* NOTE: Since the UARTs are pinned out in multiple locations on most
*       Kinetis devices, this driver does not enable UART pin functions.
*       The desired pins should be enabled before calling this init function.
*
* Parameters:
*  UART_base      UART channel to initialize
*  sysclk      UART module Clock in kHz(used to calculate baud)
*  baud        UART baud rate
*/
void UART_init (UART_MemMapPtr UART_base, int sysclk, int baud)
{
    register uint16 sbr;
    uint8 temp;
    
	/* Enable the clock to the selected UART */    
    if(UART_base == UART0_BASE_PTR)
	{
		SIM_SCGC |= SIM_SCGC_UART0_MASK;
	}
    else
	{
    	if (UART_base == UART1_BASE_PTR)
			SIM_SCGC |= SIM_SCGC_UART1_MASK;
    	else
    	    if (UART_base == UART2_BASE_PTR)
    			SIM_SCGC |= SIM_SCGC_UART2_MASK;
    		else
                SIM_SCGC |= SIM_SCGC_UART0_MASK;        // if no, error
	}
    
    /* Make sure that the transmitter and receiver are disabled while we 
    * change settings.
    */
    UART_C2_REG(UART_base) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );
    
    /* Configure the UART for 8-bit mode, no parity */
    UART_C1_REG(UART_base) = 0;
    
    /* Calculate baud settings */
    sbr = (((sysclk*1000)>>4) + (baud>>1))/baud;
    
    /* Save off the current value of the UARTx_BDH except for the SBR field */
    temp = UART_BDH_REG(UART_base) & ~(UART_BDH_SBR_MASK);
    
    UART_BDH_REG(UART_base) = temp |  UART_BDH_SBR(sbr >> 8);
    UART_BDL_REG(UART_base) = (uint8)(sbr & UART_BDL_SBR_MASK);

    /* Enable receiver and transmitter */
    UART_C2_REG(UART_base) |= (UART_C2_TE_MASK | UART_C2_RE_MASK );
}
/********************************************************************/
/*
* Wait for a character to be received on the specified UART
*
* Parameters:
*  channel      UART channel to read from
*
* Return Values:
*  the received character
*/
char UART_getchar (UART_MemMapPtr channel)
{
    /* Wait until character has been received */
    while (!(UART_S1_REG(channel) & UART_S1_RDRF_MASK));
    
    /* Return the 8-bit data from the receiver */
    return UART_D_REG(channel);
}
/********************************************************************/
/*
* Wait for space in the UART Tx FIFO and then send a character
*
* Parameters:
*  channel      UART channel to send to
*  ch			 character to send
*/ 
void UART_putchar (UART_MemMapPtr channel, char ch)
{
    /* Wait until space is available in the FIFO */
    while(!(UART_S1_REG(channel) & UART_S1_TDRE_MASK));
    
    /* Send the character */
    UART_D_REG(channel) = (uint8)ch;
}
/********************************************************************/
/*
* Check to see if a character has been received
*
* Parameters:
*  channel      UART channel to check for a character
*
* Return values:
*  0			No character received
*  no-zero      Character has been received
*/
int UART_getchar_present (UART_MemMapPtr channel)
{
    return (UART_S1_REG(channel) & UART_S1_RDRF_MASK);
}

/*FUNCTION****************************************************************
* 
* Function Name    : UART_enable_irq
* Returned Value   : none
* Comments         :
*    brief enable UART interrupt.
*
**********************************************************************/
void UART_enable_irq(UART_MemMapPtr UART_base)
{
	/* disable receiver and transmitter */
	UART_C2_REG(UART_base) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

	if(UART_base == UART0_BASE_PTR)
		enable_irq(12);
	else if(UART_base == UART1_BASE_PTR)
		enable_irq(13);
	else /* error */
		return;

	/* Enable error interrupts */
	UART_C3_REG(UART_base) = 0x0FU; 

	/* Enable TIE and RIE
	 * Transmit Interrupt Enable for TDRE and 
	 * Receiver Interrupt Enable for RDRF
	 * */
	UART_C2_REG(UART_base) |= (UART_C2_RIE_MASK | UART_C2_TIE_MASK);

	/* Enable receiver and transmitter */
	UART_C2_REG(UART_base) |= (UART_C2_TE_MASK | UART_C2_RE_MASK );
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: UART_set_tx_handler
*
* @brief set transmit handler called by ISR when transmit finished.
*        
* @param   
*     T_UartTx_Callback tx   : callback function for transmit
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void UART_set_tx_handler(T_UartTx_Callback tx)
{
	tx_handler = tx;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: UART_set_rx_handler
*
* @brief set recv handler called by ISR when recv finished.
*        
* @param   
*     T_UartRx_Callback rx   : callback function for receiver
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void UART_set_rx_handler(T_UartRx_Callback rx)
{
	rx_handler = rx;
}


/*FUNCTION****************************************************************
* 
* Function Name    : SCI_Isr
* Returned Value   : none
* Comments         :
*    brief  Uart interrupt service routine.
*
*END*********************************************************************/
void SCI_Isr(UART_MemMapPtr base, uint8 irq)
{
	uint8 data;
	uint8 stat;
	
	stat = UART_S1_REG(base);
	/* Dummy read of data register - clear error bits */
	data = UART_D_REG(base);

	if (stat & 0x0F)
	{
		/* some error happened */
		return;
	}

	/* Disable interrupt */
	disable_irq(irq);

	/* handle transmit */
	if (stat & UART_S1_TDRE_MASK)
	{
		if (send_buf[send_buf_pos])
		{
			UART_D_REG(base) = send_buf[send_buf_pos];
			send_buf_pos++;
		}
		else
		{
			/* clear the send_buf */
			send_buf[0] = 0;
			send_buf_pos = 0;
		}

		if (tx_handler)
			tx_handler();
	}

	/* handle Receive */
	if (stat & UART_S1_RDRF_MASK)
	{
		if (rx_handler)
			rx_handler((int8)data);
	}

	/* Enable interrupt */
	enable_irq(irq);
}

void SCI0_Isr(void)
{
	SCI_Isr(UART0_BASE_PTR, 12);
}

void SCI1_Isr(void)
{
	SCI_Isr(UART1_BASE_PTR, 13);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: UART_set_rx_handler
*
* @brief print a string by interrupt mode.
*        This is only for demo usage.
*        for real case, user will write 'send' buffer, and
*        interrupt routine will read 'send' buffer, so need
*        read and write pointer and some protection.
*
* @param   
*     int8* str   : string to be printed
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
void printf_int(int8* str)
{
	uint8 len = 0;

	while(*str)
	{
		send_buf[len++] = *str;
		str++;
		if (len >= SEND_BUF_L)
		{
			send_buf[SEND_BUF_L] = 0;
			break;
		}
	}

	send_buf_pos = 0;
}

