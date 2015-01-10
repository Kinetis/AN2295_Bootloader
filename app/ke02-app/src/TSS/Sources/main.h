/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: main.h$
* $Version : 3.6.1.0$
* $Date    : Jul-30-2012$
*
* Comments:
*
*   This file contains the source for the TSS example program.
*
*END************************************************************************/
#ifndef MAIN_H
#define MAIN_H

#include "derivative.h"

 /* Serial Port Info */
#define FMSTR_UART_PORT              UART0_BASE_PTR
#define FMSTR_UART_VECTOR            28
#define FMSTR_UART_PORT_NUM          0
#define FMSTR_UART_BAUD              115200
#define CORE_CLK_KHZ                 48000



/* Multiplexing Macros */

#define MUX_ALT0     0 /* Signal */
#define MUX_ALT1     1 /* GPIO */
#define MUX_ALT2     2
#define MUX_ALT3     3

/* Low Power Types */

#define LP_TYPE_LLS      0x03
#define LP_TYPE_VLPS     0x02
#define LP_TYPE_VLLSX    0x04
#define LOW_POWER_MODE   LP_TYPE_LLS

/* Application Constants */

#define ALWAYS                         1     /* ~1ms  period of TSI measurement */
#define SW                             2     
#define AUTO                           3     

/* Application Setup */

#define APP_TSS_USE_DCTRACKER          1
#define APP_TSS_USE_TRIGGER_MODE       ALWAYS


//#define OUT_LIBRARY


/********************************************************************/

#endif
