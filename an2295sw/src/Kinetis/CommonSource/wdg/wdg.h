/******************************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
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
***************************************************************************//*!
*
* @file      wdg.h
*
* @author    b01119
* 
* @version   0.0.4.0
* 
* @date      Nov-30-2012
* 
* @brief     Watch dog simple driver header file
*
******************************************************************************/
#ifndef   _WDG_H
#define   _WDG_H


#if IS_Kxx_FAMILY || IS_KMx_FAMILY
  #define WDG_ResetMCU()        WDOG_UNLOCK = 0xd928;  WDOG_UNLOCK = 0xc520;

 // #define WDG_Disable()         WDOG_UNLOCK = 0xC520;  WDOG_UNLOCK = 0xD928; WDOG_STCTRLH = WDOG_STCTRLH_ALLOWUPDATE_MASK;               /* Disable watchdog */ 
    #define WDG_Disable()         WDOG_UNLOCK = 0xC520;  WDOG_UNLOCK = 0xD928; WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;               /* Disable watchdog */ 
  #define WDG_Enable()          //WDOG_UNLOCK = 0xC520;  WDOG_UNLOCK = 0xD928; WDOG_STCTRLH |= WDOG_STCTRLH_WDOGEN_MASK;               /* Enable watchdog Already enabled*/ 
  #define WDG_Refresh()         WDOG_REFRESH = 0xA602; WDOG_REFRESH = 0xB480;
#elif IS_KLx_FAMILY
  #define WDG_ResetMCU();       SIM_SRVCOP = 0xAA; SIM_SRVCOP = 0x55;
  #define WDG_Disable();        SIM_COPC = 0;               /* Disable watchdog */ 
  #define WDG_Enable();         SIM_COPC = (0x0000000F & (1<<3));               /* Enable watchdog */ 
  #define WDG_Refresh();        SIM_SRVCOP = 0x55; SIM_SRVCOP = 0xAA;
#elif IS_KEx_FAMILY

  #define WDG_Disable();		WDOG_CS1 = 0x20;WDOG_CS2 = 0;WDOG_TOVALH = 0xFF; WDOG_TOVALL = 0xFF; WDOG_WINH = 0xFF; WDOG_WINL = 0xFF; WDOG_CS2 = 0x20;
  #define WDG_Enable(); 

#endif

#endif





