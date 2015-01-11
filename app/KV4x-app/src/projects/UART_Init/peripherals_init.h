/**HEADER********************************************************************
* 
* Copyright (c) 2011 Freescale Semiconductor;
* All Rights Reserved                       
*
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
* $FileName: peripherals_init.h$
* $Version : 1.0.1.0$
* $Date    : Jan-21-2013$
*
* Comments:
*
*   This file contains the peripherals initialization.
*
*END************************************************************************/

#ifndef __Peripherals_Init_H
#define __Peripherals_Init_H


/***************************** Prototypes **********************************/

void InitSPI0(void);
/***************************************************************************
* InitSPI
* --------------------------------------------------------------------------
* Initialization of the SPI module
****************************************************************************/

void InitFTM0(void);
/***************************************************************************
* InitFTM2
* --------------------------------------------------------------------------
* Initialization of the FTM2 module for quadrature decoder function
****************************************************************************/

void InitADC(void);
/***************************************************************************
* InitADC
* --------------------------------------------------------------------------
* Initialization of the A/D converter for current and voltage sensing
* 
****************************************************************************/



#endif /* __Peripherals_Init_H  */