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
* @file      bootloader.h
*
* @author    b01119
* 
* @version   0.0.13.0
* 
* @date      Dec-11-2012
* 
* @brief     Bootloader state machine file header file
*
******************************************************************************/
#ifndef   _BOOTLOADER_H
#define   _BOOTLOADER_H


/******************************************************************************
* Includes
******************************************************************************/
#include "kinetis_params.h"

/******************************************************************************
* Constants
******************************************************************************/

/** Enumeration of all AN2295 bootloader protocols */ 
#define VERSION_HC08        1
#define VERSION_HC08_LARGE  3
#define VERSION_HCS08       2 
#define VERSION_HCS08_LONG  6
#define VERSION_HCS08_LARGE 10
#define VERSION_CV       4
#define VERSION_KINETIS  8

/** Bootloader commands */
#define BOOT_CMD_IDENT 'I'
#define BOOT_CMD_WRITE 'W'
#define BOOT_CMD_ERASE 'E'
#define BOOT_CMD_ACK  0xFC
#define BOOT_CMD_NACK 0x03
#define BOOT_CMD_QUIT 'Q'
#define BOOT_CMD_READ 'R'


/** Bootloader protocol version */
#define BOOTLOADER_PROTOCOL_VERSION VERSION_KINETIS

#ifndef BOOT_WAITING_TIMEOUT
  #define BOOT_WAITING_TIMEOUT 100        
#endif

#ifndef FLASH_BLOCK_CNT
  #define FLASH_BLOCK_CNT 1
  #warning There is missing define of flash blocks count. It sets to default: '1' !
#endif
  
//  ident macros setting values
#ifndef RELOCATED_VECTORS
  #define RELOCATED_VECTORS 0x0800
  #warning There is missing define of flash start of relocated vectors. It sets to default: '0x0800'!
#endif

#ifndef INTERRUPT_VECTORS
  #define INTERRUPT_VECTORS 0x0000
  #warning There is missing define of flash start of relocated vectors. It sets to default: '0x0000'!
#endif

#ifndef USER_FLASH_START
  #define USER_FLASH_START RELOCATED_VECTORS + 1024 
  #warning There is missing define of flash start of relocated vectors. It sets to default: 'RELOCATED_VECTORS + 1024'!
#endif

#ifndef USER_FLASH_END
  #define USER_FLASH_END 0x0007FFFF
  #warning There is missing define of flash start of relocated vectors. It sets to default: '0x0007FFFF'!
#endif

#ifndef FLASH_WRITE_PAGE
  #define FLASH_WRITE_PAGE 128
  #warning There is missing define of flash start of relocated vectors. It sets to default: '128'!
#endif

#ifndef FLASH_ERASE_PAGE
  #define FLASH_ERASE_PAGE 2048
  #warning There is missing define of flash start of relocated vectors. It sets to default '2048'!
#endif

#ifndef BOOTLOADER_AUTO_TRIMMING
  #define BOOTLOADER_AUTO_TRIMMING 1
  #warning There are missing define of auto trimming. It sets to default 1
#elif BOOTLOADER_AUTO_TRIMMING == 0 
  #warning Set the correct trimm value of internal oscillator !     
#endif 

#if FLASH_BLOCK_CNT == 2
  #if !defined(USER_FLASH_START_2) || !defined(USER_FLASH_END_2)
    #error The USER_FLASH_START_2 and USER_FLASH_END_2 must be defined if the two flash banks are used.
  #endif
#elif FLASH_BLOCK_CNT > 2
  #error The current version of bootloader sw doesn't support more than two flash blocks.
#endif

// generate the bootloader protocol id with modification flags
#if (BOOTLOADER_ENABLE_READ_CMD != 0) && (BOOTLOADER_CRC_ENABLE != 0)
  #define _BOOTLOADER_PROTOCOL_VERSION BOOTLOADER_PROTOCOL_VERSION | 0xc0
#elif (BOOTLOADER_ENABLE_READ_CMD != 0)
  #define _BOOTLOADER_PROTOCOL_VERSION BOOTLOADER_PROTOCOL_VERSION | 0x80
#elif (BOOTLOADER_CRC_ENABLE != 0)
  #define _BOOTLOADER_PROTOCOL_VERSION BOOTLOADER_PROTOCOL_VERSION | 0x40
#else
  #define _BOOTLOADER_PROTOCOL_VERSION BOOTLOADER_PROTOCOL_VERSION
#endif


/******************************************************************************
* Types
******************************************************************************/

  typedef unsigned long addrType;
 
  typedef unsigned char BootloaderProtocolType;
  
  typedef union Address 
  {
    unsigned long complete;
    struct
    {
      unsigned short low;
      unsigned short high;        
    }Words;
    struct
    {
      unsigned char ll;
      unsigned char lh;
      unsigned char hl;
      unsigned char hh;
    }Bytes;
  }AddressType;
  
  #pragma pack(1)
  #pragma pack(push)
  
  /** Flash block start and end address */
  
  typedef struct FlashBlocksDesc
  {
    addrType startAddr;
    addrType endAddr; 
  }FlashBlocksDescType;
  
   
  /** Bootloader ident structure used for bootloader protocol */
  typedef struct BootloaderIdent
  {
          /** version */
          BootloaderProtocolType version;
          /** Sd Id */
          unsigned short sdid;
          /** count of flash blocks */
          addrType blocksCnt;
          /** flash blocks descritor */
          FlashBlocksDescType blockDesc[FLASH_BLOCK_CNT];
          /** Relocated interrupts vestor table */
          addrType relocatedVectors;
          /** Interrupts vestor table */
          addrType interruptsVectors;
          /** Erase Block Size */
          addrType eraseBlockSize;
          /** Write Block Size */
          addrType writeBlockSize;
          /** Id string */
          unsigned char idString[sizeof(KINETIS_MODEL_STR)];      
  }BootloaderIdentType;
	
	/** Bootloader code optimized ident structure used for bootloader protocol */
  typedef struct BootloaderIdentOptimType
  {
          /** count of flash blocks */
          addrType blocksCnt;
          /** flash blocks descritor */
          FlashBlocksDescType blockDesc[FLASH_BLOCK_CNT];
          /** Relocated interrupts vestor table */
          addrType relocatedVectors;
          /** Interrupts vestor table */
          addrType interruptsVectors;
          /** Erase Block Size */
          addrType eraseBlockSize;
          /** Write Block Size */
          addrType writeBlockSize;
          /** Id string */
          unsigned char idString[sizeof(KINETIS_MODEL_STR)];      
  }BootloaderIdentOptimType;
	
  #pragma pack(pop) 
  
#define LITTLE2BIG(x) ((unsigned long)(((unsigned long)((unsigned char)(x)<<24) & 0xff000000) | (unsigned long)(((unsigned short)(x)<<8) & 0x00ff0000) | (unsigned long)(((x)>>8) & 0x0000ff00) | (unsigned long)(((x)>>24) & 0x00000000ff)))
	
typedef void (*vector_entry)(void);
typedef void pointer(void);
/******************************************************************************
* Macros 
******************************************************************************/
  
/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void Boot_ResetMCU(void);
void Bootloader(void);
#define Boot_ProtocolReset() Boot_ResetMCU(1)
 

#endif





