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
* @file      crc.h
*
* @author    b01119
* 
* @version   0.0.3.0
* 
* @date      Nov-30-2012
* 
* @brief     CRC simple driver for MCF51AG128 ColdFire MCU
*
******************************************************************************/
#ifndef   _CRC_H
#define   _CRC_H

#define CRC_CCITT16_SEED 0xFFFF

  #if IS_Kxx_FAMILY
    // Kinetis - Peripheral
    #define CRC_AddByte(x) CRC_CRCLL = (x);
    #define CRC_AddLong(x) CRC_CRC = (x);
    #define CRC_Init()  CRC_CTRL = 0;
    #define CRC_Reset()  CRC_CTRL |= CRC_CTRL_WAS_MASK; CRC_CRCL = CRC_CCITT16_SEED; CRC_CTRL &= ~CRC_CTRL_WAS_MASK;
    #define CRC_GetResult() CRC_CRCL
    #define CRC_GetResultHigh() CRC_CRCLU
    #define CRC_GetResultLow()  CRC_CRCLL
  
#elif IS_KMx_FAMILY
    // Kinetis M - Peripheral
    #define CRC_AddByte(x) CRC_DATALL = (x);
    #define CRC_AddLong(x) CRC_DATA = (x);
    #define CRC_Init()  CRC_CTRL = 0;
    #define CRC_Reset()  CRC_CTRL |= CRC_CTRL_WAS_MASK; CRC_DATAL = CRC_CCITT16_SEED; CRC_CTRL &= ~CRC_CTRL_WAS_MASK;
    #define CRC_GetResult() CRC_DATAL
    #define CRC_GetResultHigh() CRC_DATALU
    #define CRC_GetResultLow()  CRC_DATALL  
#else
    extern Word crc;

    #define  CRC_Init()
    #define CRC_Reset() crc = CRC_CCITT16_SEED
    void CRC_AddByte(Byte data);
    void CRC_AddLong(LWord data32);
    #define CRC_GetResult() crc
    #define CRC_GetResultHigh() (Byte)(crc >> 8)
    #define CRC_GetResultLow() (Byte)crc
  #endif
#endif





