/**HEADER********************************************************************
* 
* Copyright (c) 2008-2011 Freescale Semiconductor;
* All Rights Reserved                       
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: app_init.c$
* $Version : 3.6.1.0$
* $Date    : Jan-21-2013$
*
* Comments:
*
*   This file contains the init functions for some peripherals.
*
*END************************************************************************/

#include "common.h"
#include "wdog.h"
#include "uart.h"
#include "mcg.h"

#include "app_init.h"

/***************************** Local Types *********************************/

/*************************** Global Variables *******************************/

volatile unsigned int mcgfreq;
/*************************** Local Variables *******************************/

static volatile unsigned int mcgfreq;

/***************************************************************************
* InitPorts
* --------------------------------------------------------------------------
* Global init of the board ports
****************************************************************************/


void InitPorts(void)
{
     /* PORT clock enablement */
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /* PORTA clock enablement */
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* PORTB clock enablement */
    SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; /* PORTC clock enablement */ 
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; /* PORTD clock enablement */     
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; /* PORTE clock enablement */ 
}

/**************************************************************************//*!
* FreeMASTER_Init
* --------------------------------------------------------------------------
* Initialize FreeMASTER resources
******************************************************************************/

void InitFreemaster(void)
{
    /* UART0 and UART1 are clocked from the core clock, but all other UARTs are
    * clocked from the peripheral clock. So we have to determine which clock
    * to send to the uart_init function.
    */
#if 0 
  if ((FMSTR_UART_PORT == UART0_BASE_PTR) | (FMSTR_UART_PORT == UART1_BASE_PTR))
      /* Fmstr UART Init */
      uart_init (FMSTR_UART_PORT, CORE_CLK_KHZ, FMSTR_UART_BAUD);
    else
      /* Fmstr UART Init */
      uart_init (FMSTR_UART_PORT, CORE_CLK_KHZ / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> 24)+ 1), FMSTR_UART_BAUD);

    /* Enable UART Isr */    
    ISR_ENABLE_VECT(FMSTR_UART_VECTOR);
#endif
    /* Initialize FMSTR stack */
    FMSTR_Init();
}


/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

