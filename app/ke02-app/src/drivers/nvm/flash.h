/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file flash.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Sep 24, 2011
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the PT60, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/



#ifndef FLASH_H_
#define FLASH_H_

/******************************************************************************
* Includes
******************************************************************************/
#include "common.h"
/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/
/* Uncomment the following line to support programming flash while running code from flash */
// #define FLASH_ENABLE_STALLING_FLASH_CONTROLLER

#define FTMRH_FSTAT_MGSTAT0_MASK  (1)
#define FTMRH_FSTAT_MGSTAT1_MASK  (1<<1)

#define FLASH_SECTOR_SIZE	512		// in bytes

/* Flash driver errors */
#define FLASH_ERR_BASE				0x3000
#define FLASH_ERR_SUCCESS			0
#define FLASH_ERR_INVALID_PARAM		(FLASH_ERR_BASE+1)	// invalid parameter error code
#define EEPROM_ERR_SINGLE_BIT_FAULT	(FLASH_ERR_BASE+2)	// EEPROM single bit fault error code
#define EEPROM_ERR_DOUBLE_BIT_FAULT	(FLASH_ERR_BASE+4)	// EEPROM double bits fault error code
#define FLASH_ERR_ACCESS			(FLASH_ERR_BASE+8)	// flash access error code
#define FLASH_ERR_PROTECTION		(FLASH_ERR_BASE+0x10)	// flash protection error code
#define FLASH_ERR_MGSTAT0			(FLASH_ERR_BASE+0x11)	// flash verification error code
#define FLASH_ERR_MGSTAT1			(FLASH_ERR_BASE+0x12)	// flash non-correctable error code
#define FLASH_ERR_INIT_CCIF			(FLASH_ERR_BASE+0x14)	// flash driver init error with CCIF = 1
#define FLASH_ERR_INIT_FDIV			(FLASH_ERR_BASE+0x18)	// flash driver init error with wrong FDIV 

/* Flash and EEPROM commands */
#define FTMRH_CMD_ERASE_VERIFY_ALL	0x01
#define FTMRH_CMD_ERASE_VERIFY_BLOCK	0x02
#define FTMRH_CMD_ERASE_ALL			0x08
#define FTMRH_CMD_ERASE_BLOCK			0x09
#define FTMRH_CMD_UNSECURE			0x0B
#define FTMRH_CMD_SET_USER_MARGIN		0x0D

#define FLASH_CMD_ERASE_VERIFY_SECTION	0x03
#define FLASH_CMD_READONCE			0x04
#define FLASH_CMD_PROGRAM			0x06
#define FLASH_CMD_PROGRAMONCE		0x07
#define FLASH_CMD_ERASE_SECTOR		0x0A
#define FLASH_CMD_BACKDOOR_ACCESS	0x0C
#define FLASH_CMD_SET_USER_MARGIN_LEVEL	0x0D

#define EEPROM_CMD_ERASE_VERIFY_SECTION	0x10
#define EEPROM_CMD_PROGRAM			0x11
#define EEPROM_CMD_ERASE_SECTOR 	0x12

/******************************************************************************
* Types
******************************************************************************/
typedef  uint16_t (*TFlash_Fun1)(uint32_t wNVMTargetAddress, uint8_t *pbData, uint8_t bByteCount);
typedef  uint16_t (*TFlash_Fun2)(uint32_t wNVMTargetAddress, uint32_t dwData0, uint32_t dwData1);
typedef  uint16_t (*TFlash_Fun3)(uint32_t wNVMTargetAddress, uint32_t dwData);

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
uint16_t Flash_Program(uint32_t wNVMTargetAddress, uint8_t *pData, uint16_t sizeBytes);
uint16_t Flash_Program1LongWord(uint32_t wNVMTargetAddress, uint32_t dwData);
uint16_t Flash_Program2LongWords(uint32_t wNVMTargetAddress, uint32_t dwData0, uint32_t dwData1);
uint16_t Flash_ProgramOnce(uint8_t bPhraseIndex, uint8_t *pData8Bytes);
uint16_t Flash_ReadOnce(uint8_t bPhraseIndex, uint8_t *pData8Bytes);
uint16_t Flash_EraseSector(uint32_t wNVMTargetAddress);
uint16_t Flash_EraseVerifySection(uint32_t wNVMTargetAddress, uint16_t uiLongWordCount);
uint16_t Flash_VerifyBackdoorKey(uint8_t *pbKey);
uint16_t Flash_SetUserMarginLevel(uint32_t wNVMTargetAddress, uint16_t wMarginLevel, uint8_t bIsEEPROM);

uint16_t FTMRH_EraseBlock(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM);
uint16_t NVM_EraseVerifyBlock(uint32_t wNVMTargetAddress,uint8_t bIsEEPROM);
uint16_t NVM_EraseAll(void);
uint16_t FTMRH_EraseVerifyAll(void);
uint16_t NVM_Unsecure(void);
uint16_t NVM_EraseBlock_NoWait(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM);
uint16_t NVM_CheckErrStatus(void);

#if (defined(IAR))
__ramfunc void FTMRH_LaunchCMD(uint8_t bWaitComplete);
#else
void FTMRH_LaunchCMD(uint8_t bWaitComplete);
#endif

void FTMRH_LaunchCMD(uint8_t bWaitComplete);

uint16_t EEPROM_Program1Byte(uint32_t wNVMTargetAddress, uint8_t bData);
uint16_t EEPROM_ProgramUpto4Bytes(uint32_t wNVMTargetAddress, uint8_t *pbData, uint8_t bByteCount);
uint16_t EEPROM_Program(uint32_t wNVMTargetAddress, uint8_t *pData, uint16_t sizeBytes);
uint16_t EEPROM_EraseVerifySection(uint32_t wNVMTargetAddress, uint16_t uiByteCount);
uint16_t EEPROM_Program1Byte_NoWait(uint32_t wNVMTargetAddress, uint8_t bData);
uint16_t EEPROM_ProgramUpto4Bytes_NoWait(uint32_t wNVMTargetAddress, uint8_t *pbData, uint8_t bByteCount);
uint16_t EEPROM_EraseSector_NoWait(uint32_t wNVMTargetAddress);
uint16_t EEPROM_EraseSector(uint32_t wNVMTargetAddress);

uint16_t Flash_Init(void);
void	Flash_CopyInRAM(void);
void	Flash_CopyRouinte2RAM(char *func, uint16_t sizeFunc);
/********************************************************************/

#endif /* FLASH_H_ */
