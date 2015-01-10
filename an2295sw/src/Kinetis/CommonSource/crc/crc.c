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
* @file      crc.c
*
* @author    b01119
* 
* @version   0.0.2.0
* 
* @date      Nov-30-2012
* 
* @brief     CRC CCITT16 simple sw driver
*
******************************************************************************/

#if !IS_Kxx_FAMILY && !IS_KMxx_FAMILY
  
#include "bootloader.h"

  Word crc;

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_Init
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function initialize CRC calculation
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     none
  //----------------------------------------------------------------------------
//  void CRC_Init(void)
//  {
//    
//  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_Reset
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function resets the CRC calculation
  //              
  // PARAMETERS:  seed - 16 bit seed for CRC calculation
  //              
  // RETURNS:     none
  //----------------------------------------------------------------------------
//  void CRC_Reset(Word seed)
//  {
//    crc = seed;
//  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_AddByte
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function add new byte to CRC calculation
  //              
  // PARAMETERS:  data - 8 bit input data to crc calculation
  //              
  // RETURNS:     none
  //----------------------------------------------------------------------------
  void CRC_AddByte(Byte data)
  {
    unsigned int x;

    crc ^= data << 8;                               /* XOR hi-byte of CRC w/dat    */
    for (x = 8; x; --x)                             /* Then, for 8 bit shifts...   */
          if (crc & 0x8000)                        /* Test hi order bit of CRC    */
                 crc = crc << 1 ^ 0x1021;          /* if set, shift & XOR w/$1021 */
          else
                 crc <<= 1;                        /* Else, just shift left once. */
  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_AddLong
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function add new 4 bytes to CRC calculation
  //              
  // PARAMETERS:  data32 - 32 bit input data to crc calculation
  //              
  // RETURNS:     none
  //----------------------------------------------------------------------------
  void CRC_AddLong(LWord data32)
  {
    CRC_AddByte(data32 >> 24);
    CRC_AddByte(data32 >> 16);
    CRC_AddByte(data32 >> 8);
    CRC_AddByte(data32);    
  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_GetResult
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function returns result of CRC calculation
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     16-bit result of CRC calculation
  //----------------------------------------------------------------------------
//  Word CRC_GetResult(void)
//  {
//    return crc;
//  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_GetResultHigh
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function returns high byte of result of CRC calculation
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     high 8-bit result of CRC calculation
  //----------------------------------------------------------------------------
//  Byte CRC_GetResultHigh(void)
//  {
//    return (Byte)(crc >> 8);
//  }

  //----------------------------------------------------------------------------
  // FUNCTION:    CRC_GetResultLow
  // SCOPE:       CRC CCITT_16 sw function
  // DESCRIPTION: The function returns low byte of result of CRC calculation
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     low 8-bit result of CRC calculation
  //----------------------------------------------------------------------------
//  Byte CRC_GetResultLow(void)
//  {
//    return (Byte)crc;
//  }

#endif





