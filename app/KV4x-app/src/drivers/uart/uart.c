/*
 * File:        uart.c
 * Purpose:     Provide common UART routines for serial IO
 *
 * Notes:       
 *              
 */

#include "common.h"
#include "uart.h"

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
 *  uartch      UART channel to initialize
 *  sysclk      UART module Clock in kHz(used to calculate baud)
 *  baud        UART baud rate
 */
void uart_init (UART_MemMapPtr uartch, int sysclk, int baud)
{
    register uint16 sbr, brfa;
    uint8 temp;
    
	/* Enable the clock to the selected UART */    
    if(uartch == UART0_BASE_PTR)
		SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
    else
    	if (uartch == UART1_BASE_PTR)
			SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;
//    	else
//    		if (uartch == UART2_BASE_PTR)
//    			SIM_SCGC4 |= SIM_SCGC4_UART2_MASK;
//    		else
//    			if(uartch == UART3_BASE_PTR)
//    				SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;
//    			else
//    				if(uartch == UART4_BASE_PTR)
//    					SIM_SCGC1 |= SIM_SCGC1_UART4_MASK;
//    				else
//    					SIM_SCGC1 |= SIM_SCGC1_UART5_MASK;
                                
    /* Make sure that the transmitter and receiver are disabled while we 
     * change settings.
     */
    UART_C2_REG(uartch) &= ~(UART_C2_TE_MASK
				| UART_C2_RE_MASK );

    /* Configure the UART for 8-bit mode, no parity */
    UART_C1_REG(uartch) = 0;	/* We need all default settings, so entire register is cleared */
    
    /* Calculate baud settings */
    sbr = (uint16)((sysclk*1000)/(baud * 16));
        
    /* Save off the current value of the UARTx_BDH except for the SBR field */
    temp = UART_BDH_REG(uartch) & ~(UART_BDH_SBR(0x1F));
    
    UART_BDH_REG(uartch) = temp |  UART_BDH_SBR(((sbr & 0x1F00) >> 8));
    UART_BDL_REG(uartch) = (uint8)(sbr & UART_BDL_SBR_MASK);
    
    /* Determine if a fractional divider is needed to get closer to the baud rate */
    brfa = (((sysclk*32000)/(baud * 16)) - (sbr * 32));
    
    /* Save off the current value of the UARTx_C4 register except for the BRFA field */
    temp = UART_C4_REG(uartch) & ~(UART_C4_BRFA(0x1F));
    
    UART_C4_REG(uartch) = temp |  UART_C4_BRFA(brfa);    

    /* Enable receiver and transmitter */
	UART_C2_REG(uartch) |= (UART_C2_TE_MASK
				| UART_C2_RE_MASK );
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
char uart_getchar (UART_MemMapPtr channel)
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
void uart_putchar (UART_MemMapPtr channel, char ch)
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
 *  0       No character received
 *  1       Character has been received
 */
int uart_getchar_present (UART_MemMapPtr channel)
{
    return (UART_S1_REG(channel) & UART_S1_RDRF_MASK);
}
/********************************************************************/

void UART1_Init(void)
{
   /* SIM_SCGC4: UART1=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;
  /* UART1_C2: TE=0,RE=0 */
  UART1_C2 &= (uint8_t)~(uint8_t)((UART_C2_TE_MASK | UART_C2_RE_MASK));
  /* UART1_BDH: LBKDIE=0,RXEDGIE=0,??=0,SBR=1 */
  UART1_BDH = UART_BDH_SBR(0x01);
  /* UART1_BDL: SBR=0x38 */
  UART1_BDL = UART_BDL_SBR(0x38);
  /* UART1_MA1: MA=0 */
  UART1_MA1 = UART_MA1_MA(0x00);
  /* UART1_MA2: MA=0 */
  UART1_MA2 = UART_MA2_MA(0x00);
  /* UART1_C4: MAEN1=0,MAEN2=0,M10=0,BRFA=0x10 */
  UART1_C4 = UART_C4_BRFA(0x10);
  /* UART1_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART1_C1 = 0x00U;
  /* UART1_S2: LBKDIF=1,RXEDGIF=1,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART1_S2 = (UART_S2_LBKDIF_MASK | UART_S2_RXEDGIF_MASK);
  /* UART1_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART1_MODEM = 0x00U;
  /* UART1_IR: ??=0,??=0,??=0,??=0,??=0,IREN=0,TNP=0 */
  //UART1_IR = UART_IR_TNP(0x00);
  /* UART1_TWFIFO: TXWATER=0 */
  UART1_TWFIFO = UART_TWFIFO_TXWATER(0x00);
  /* UART1_RWFIFO: RXWATER=1 */
  UART1_RWFIFO = UART_RWFIFO_RXWATER(0x01);
  /* UART1_SFIFO: TXEMPT=1,RXEMPT=1,??=0,??=0,??=0,RXOF=1,TXOF=1,RXUF=1 */
  UART1_SFIFO = UART_SFIFO_TXEMPT_MASK |
                UART_SFIFO_RXEMPT_MASK |
                UART_SFIFO_RXOF_MASK |
                UART_SFIFO_TXOF_MASK |
                UART_SFIFO_RXUF_MASK;
  /* UART1_CFIFO: TXFLUSH=1,RXFLUSH=1,??=0,??=0,??=0,RXOFE=0,TXOFE=0,RXUFE=0 */
  UART1_CFIFO = (UART_CFIFO_TXFLUSH_MASK | UART_CFIFO_RXFLUSH_MASK);
  /* UART1_PFIFO: TXFE=0,RXFE=0 */
  UART1_PFIFO &= (uint8_t)~(uint8_t)(
                  UART_PFIFO_TXFE_MASK |
                  UART_PFIFO_RXFE_MASK
                 );
    (void) UART1_S1;                   /* Dummy read of the UART1_S1 register to clear flags */
    (void) UART1_D;                    /* Dummy read of the UART1_D register to clear flags */
  /* UART1_C5: TDMAS=0,??=0,RDMAS=0,??=0,??=0,??=0,??=0 */
  UART1_C5 &= (uint8_t)~(uint8_t)(
               UART_C5_TDMAS_MASK |
               UART_C5_RDMAS_MASK |
               0x4FU
              );
  /* UART1_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART1_C3 = 0x00U;
  /* UART1_C2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  UART1_C2 = 0x00U;
  
  
      /* Enable receiver and transmitter */
	UART_C2_REG(UART1_BASE_PTR) |= (UART_C2_TE_MASK
				| UART_C2_RE_MASK );
}

void UART1_Init_blpe(void)
{
  /* SIM_SCGC4: UART1=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;
  /* UART1_C2: TE=0,RE=0 */
  UART1_C2 &= (uint8_t)~(uint8_t)((UART_C2_TE_MASK | UART_C2_RE_MASK));
  /* UART1_BDH: LBKDIE=0,RXEDGIE=0,??=0,SBR=0 */
  UART1_BDH = UART_BDH_SBR(0x00);
  /* UART1_BDL: SBR=0x34 */
  UART1_BDL = UART_BDL_SBR(0x34);
  /* UART1_MA1: MA=0 */
  UART1_MA1 = UART_MA1_MA(0x00);
  /* UART1_MA2: MA=0 */
  UART1_MA2 = UART_MA2_MA(0x00);
  /* UART1_C4: MAEN1=0,MAEN2=0,M10=0,BRFA=3 */
  UART1_C4 = UART_C4_BRFA(0x03);
  /* UART1_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART1_C1 = 0x00U;
  /* UART1_S2: LBKDIF=1,RXEDGIF=1,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART1_S2 = (UART_S2_LBKDIF_MASK | UART_S2_RXEDGIF_MASK);
  /* UART1_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART1_MODEM = 0x00U;
  /* UART1_IR: ??=0,??=0,??=0,??=0,??=0,IREN=0,TNP=0 */
  //UART1_IR = UART_IR_TNP(0x00);
  /* UART1_TWFIFO: TXWATER=0 */
  UART1_TWFIFO = UART_TWFIFO_TXWATER(0x00);
  /* UART1_RWFIFO: RXWATER=1 */
  UART1_RWFIFO = UART_RWFIFO_RXWATER(0x01);
  /* UART1_SFIFO: TXEMPT=1,RXEMPT=1,??=0,??=0,??=0,RXOF=1,TXOF=1,RXUF=1 */
  UART1_SFIFO = UART_SFIFO_TXEMPT_MASK |
                UART_SFIFO_RXEMPT_MASK |
                UART_SFIFO_RXOF_MASK |
                UART_SFIFO_TXOF_MASK |
                UART_SFIFO_RXUF_MASK;
  /* UART1_CFIFO: TXFLUSH=1,RXFLUSH=1,??=0,??=0,??=0,RXOFE=0,TXOFE=0,RXUFE=0 */
  UART1_CFIFO = (UART_CFIFO_TXFLUSH_MASK | UART_CFIFO_RXFLUSH_MASK);
  /* UART1_PFIFO: TXFE=0,RXFE=0 */
  UART1_PFIFO &= (uint8_t)~(uint8_t)(
                  UART_PFIFO_TXFE_MASK |
                  UART_PFIFO_RXFE_MASK
                 );
    (void) UART1_S1;                   /* Dummy read of the UART1_S1 register to clear flags */
    (void) UART1_D;                    /* Dummy read of the UART1_D register to clear flags */
  /* UART1_C5: TDMAS=0,??=0,RDMAS=0,??=0,??=0,??=0,??=0 */
  UART1_C5 &= (uint8_t)~(uint8_t)(
               UART_C5_TDMAS_MASK |
               UART_C5_RDMAS_MASK |
               0x4FU
              );
  /* UART1_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART1_C3 = 0x00U;
  /* UART1_C2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  UART1_C2 = 0x00U;
  
      /* Enable receiver and transmitter */
	UART_C2_REG(UART1_BASE_PTR) |= (UART_C2_TE_MASK
				| UART_C2_RE_MASK );
}

    
