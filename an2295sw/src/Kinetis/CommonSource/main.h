/******************************************************************************
* 
* Copyright (c) 2012 Freescale Semiconductor;
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
* @file      main.h
*
* @author    b01119
* 
* @version   0.0.7.0
* 
* @date      Dec-19-2012
* 
* @brief     Main header file for SCI bootloader
*
******************************************************************************/
#ifndef MAIN_H
#define MAIN_H

#if defined(__ARMCC_VERSION)
  //#pragma push
  #pragma anon_unions
#endif

#if KINETIS_MODEL == K10_50MHz
  #include "MK10D5.h"
#elif KINETIS_MODEL == K11_50MHz
  #include "MK10D5.h"
#elif KINETIS_MODEL == K12_50MHz
  #include "MK10D5.h"
#elif KINETIS_MODEL == K10_72MHz 
  #include "MK10DZ10.h"
#elif KINETIS_MODEL == K10_100MHz
  #include "MK10DZ10.h"
#elif KINETIS_MODEL == K10_120MHz
  #include "MK10F12.h"
#elif KINETIS_MODEL == K20_50MHz
  #include "MK20D5.h"
#elif KINETIS_MODEL == K21_50MHz
  #include "MK20D5.h"
#elif KINETIS_MODEL == K22_50MHz 
  #include "MK20D5.h"
#elif KINETIS_MODEL == K20_72MHz 
  #include "MK20DZ10.h"
#elif KINETIS_MODEL == K20_100MHz
  #include "MK20DZ10.h"
#elif KINETIS_MODEL == K22_100MHz
  #include "MK22F10.h"
#elif KINETIS_MODEL == K20_120MHz
  #include "MK20F12.h"
#elif KINETIS_MODEL == K30_72MHz 
  #include "MK30DZ10.h"
#elif KINETIS_MODEL == K30_100MHz
  #include "MK30DZ10.h"
#elif KINETIS_MODEL == K40_72MHz 
  #include "MK40DZ10.h"
#elif KINETIS_MODEL == K40_100MHz
  #include "MK40DZ10.h"
#elif KINETIS_MODEL == K50_72MHz
  #include "MK50DZ10.h"
#elif KINETIS_MODEL == K51_72MHz
  #include "MK51DZ10.h"
#elif KINETIS_MODEL == K50_100MHz
  #include "MK50DZ10.h"
#elif KINETIS_MODEL == K60_100MHz
  #include "MK60DZ10.h"
#elif KINETIS_MODEL == K60D_100MHz
  #include "MK60D10.h"
#elif KINETIS_MODEL == K60_120MHz
  #include "MK60F12.h"
#elif KINETIS_MODEL == K70_120MHz
  #include "MK70F12.h"
#elif KINETIS_MODEL == KL0_48MHz
  #include "MKL05Z32LF4.h"
#elif KINETIS_MODEL == KL1_48MHz
  #include "MKL25Z128LK4.h"
#elif KINETIS_MODEL == KL2_48MHz
  #include "MKL25Z128LK4.h"
#elif KINETIS_MODEL == KL25_48MHz
  #include "MKL25Z128LK4.h"
#elif KINETIS_MODEL == KL26_48MHz
  #include "MKL26Z4.h"
#elif KINETIS_MODEL == KL46_48MHz
  #include "MKL46Z4.h"
#elif KINETIS_MODEL == KE02_20MHz
  #include "MKE02Z2.h"
#elif IS_KMx_FAMILY
  #include "MKM34Z5.h"
#else
  #error Not supported MCU type!.
#endif

// typedef definitions
typedef unsigned char Byte;
typedef unsigned long LWord;
typedef unsigned short Word;

#endif // MAIN_H
