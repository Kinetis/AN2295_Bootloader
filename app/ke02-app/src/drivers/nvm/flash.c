/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file flash.c
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
#include "flash.h"
/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/


/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_CopyInRAM
*
* @brief This section of the code is the one that copies the routine into RAM. 
* It is following the steps  documented in Technical Note 228
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

#define FLASH_ENABLE_STALLING_FLASH_CONTROLLER


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_Init
*
* @brief initialize flash driver
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

uint16_t Flash_Init(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	uint8_t clkDIV = BUS_CLK_HZ/1000000L - 1;
	
	if(!(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK))
	{
		err |= FLASH_ERR_INIT_CCIF;
		return err;
	}
	/* initialize the flash clock to be within spec 1MHz 
	 * 
	 */
	if(!(FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLCK_MASK))
	{
		/* FCLKDIV register is not locked */
		if((FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLD_MASK) && 
                  ((FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIV_MASK) != FTMRH_FCLKDIV_FDIV(clkDIV)))
		{
			/* flash clock prescaler is loaded but with wrong value */
			err |= FLASH_ERR_INIT_FDIV;
			return (err);
		}
		FTMRH_FCLKDIV = (FTMRH_FCLKDIV & ~(FTMRH_FCLKDIV_FDIV_MASK)) | FTMRH_FCLKDIV_FDIV(clkDIV);
                
#if 0
		FTMRH_FCLKDIV  |= FTMRH_FCLKDIV_FDIVLCK_MASK; /* lock the prescaler */
#endif
	}
	else
	{
		/* FCLKDIV register is locked */
		if((FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIV_MASK) != FTMRH_FCLKDIV_FDIV(clkDIV))
		{
			/* flash clock prescaler is wrong */
			err |= FLASH_ERR_INIT_FDIV;
		}
	}
	return (err);	
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FlashProgram
*
* @brief program flash routine, each program operation supports up to 2 longwords
* 		 programming
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

uint16_t Flash_Program(uint32_t wNVMTargetAddress, uint8_t *pData, uint16_t sizeBytes)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	uint16_t w2LongWordCount = sizeBytes>>3;
	uint8_t  wLeftBytes = (sizeBytes & 0x07);
	uint16_t wLeftLongWords = wLeftBytes>>2;
	uint32_t wTargetAddress = wNVMTargetAddress;
	uint32_t dwData0,dwData1;
	uint32_t *pdwData = (uint32_t*)pData;
	int  i;
	
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Loop for the two longwords (8 bytes) programming
	for(i = 0; i < w2LongWordCount; i++)
	{
		dwData0 = *pdwData++;
		dwData1 = *pdwData++;
		err = Flash_Program2LongWords(wTargetAddress, dwData0, dwData1);
		if(err)
		{
			goto EndP;
			//break;
		}
		wTargetAddress += 8;
	}
	// Loop for the single longword (4 bytes) programming
	for(i = 0; i < wLeftLongWords; i++)
	{
		dwData0 = *pdwData++;
		err = Flash_Program1LongWord(wTargetAddress, dwData0);
		if(err)
		{			
			goto EndP;
			//break;
		}
		wTargetAddress += 4;
	}
	wLeftBytes = (wLeftBytes-(wLeftLongWords<<2));	// calculate the # of bytes that are not programmed
	if(!wLeftBytes){
		return (err);
	}
        
#if     defined(BIG_ENDIAN)                
	dwData0 = 0;
	pData = (uint8_t*)pdwData;	// pointer to the left bytes
	for(i = wLeftBytes; i >0; i--)
	{
		dwData0 <<= 8;
		dwData0 |= *pData++;	// MSB byte first
	}
	// Calculate how many bytes need to be filled with 0xFFs
	// in order to form a single longword for the left bytes of data
	wLeftBytes = 4 - wLeftBytes;	
	//  
	for(i = wLeftBytes; i >0; i--)
	{
		dwData0 <<= 8;
		dwData0 |= 0xFF;	// MSB byte first
	}
#else
	dwData0 = 0xFFFFFFFFL;        
	pData = (uint8_t*)pdwData+wLeftBytes-1;	// pointer to the left bytes
	for(i = wLeftBytes; i >0; i--)
	{
		dwData0 <<= 8;
		dwData0 |= *pData--;	// MSB byte first
	}
#endif	
	// Now program the last longword
	err = Flash_Program1LongWord(wTargetAddress, dwData0);	
EndP:	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: EEPROM_Program
*
* @brief program EEPROM routine, each program operation supports up to 4 bytes
* 		 programming
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

uint16_t EEPROM_Program(uint32_t wNVMTargetAddress, uint8_t *pData, uint16_t sizeBytes)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	uint8_t  wLeftBytes = (sizeBytes & 0x3);
	uint16_t wLeftLongWords = sizeBytes>>2;
	uint32_t wTargetAddress = wNVMTargetAddress;
	int  i;
	

	// Loop for 4 bytes programming
	for(i = 0; i < wLeftLongWords; i++)
	{
		err = EEPROM_ProgramUpto4Bytes(wTargetAddress, pData, 4);
		if(err)
		{
			goto EndP;
			//break;
		}
		wTargetAddress += 4;
		pData += 4;
	}
	if(wLeftBytes>0)
	{
		err = EEPROM_ProgramUpto4Bytes(wTargetAddress, pData, wLeftBytes);	
	}
EndP:	
	return (err);
}



uint16_t Flash_Program1LongWord(uint32_t wNVMTargetAddress, uint32_t dwData)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_PROGRAM;// program FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	// Write index to specify the word0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x2;
#if     defined(BIG_ENDIAN)        
	// Write the word  0
	FTMRH_FCCOBHI = (dwData>>16)>>8;
	FTMRH_FCCOBLO = (dwData>>16);
#else        
	FTMRH_FCCOBHI = (dwData) >>8;	
	FTMRH_FCCOBLO = (dwData);	
#endif        
	// Write index to specify the word1 (LSB word) to be programmed
	FTMRH_FCCOBIX = 0x3;
	// Write the word1 
#if     defined(BIG_ENDIAN)        
	FTMRH_FCCOBHI = (dwData) >>8;	
	FTMRH_FCCOBLO = (dwData);	
#else
	FTMRH_FCCOBHI = (dwData>>16)>>8;
	FTMRH_FCCOBLO = (dwData>>16);
#endif        
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
	
	return (err);
}


uint16_t Flash_Program2LongWords(uint32_t wNVMTargetAddress, uint32_t dwData0, uint32_t dwData1)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_PROGRAM;// program FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
        
	// Write index to specify the word0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x2;
	// Write the word 0
#if     defined(BIG_ENDIAN)                
	//FTMRH_FCCOB = (dwData0>>16) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData0>>16)>>8;
	FTMRH_FCCOBLO = (dwData0>>16);
        
	// Write index to specify the word1 (LSB word) to be programmed
	FTMRH_FCCOBIX = 0x3;
	// Write word 1
	//FTMRH_FCCOB = (dwData0) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData0) >>8;
	FTMRH_FCCOBLO = (dwData0);
	
	// Write index to specify the word0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x4;
	// Write the word2
	//FTMRH_FCCOB = (dwData1>>16) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData1>>16)>>8;
	FTMRH_FCCOBLO = (dwData1>>16);
        
	// Write index to specify the word1 (LSB word) to be programmed
	FTMRH_FCCOBIX = 0x5;
	// Write word 3
	//FTMRH_FCCOB = (dwData1) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData1) >>8;
	FTMRH_FCCOBLO = (dwData1);
#else
	//FTMRH_FCCOB = (dwData0) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData0) >>8;
	FTMRH_FCCOBLO = (dwData0);
        
	// Write index to specify the word1 (LSB word) to be programmed
	FTMRH_FCCOBIX = 0x3;
	// Write word 1
	FTMRH_FCCOBHI = (dwData0>>16)>>8;
	FTMRH_FCCOBLO = (dwData0>>16);
	
	// Write index to specify the word0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x4;
	// Write the word2
	//FTMRH_FCCOB = (dwData1) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData1) >>8;
	FTMRH_FCCOBLO = (dwData1);        
        
	// Write index to specify the word1 (LSB word) to be programmed
	FTMRH_FCCOBIX = 0x5;
	// Write word 3
	//FTMRH_FCCOB = (dwData1>>16) & 0xFFFF;
	FTMRH_FCCOBHI = (dwData1>>16)>>8;
	FTMRH_FCCOBLO = (dwData1>>16);
#endif
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
	
	return (err);
}





/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_EraseSector
*
* @brief erase flash sector, each flash sector is of 512 bytes long,
* global address [1:0] = 00.
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t Flash_EraseSector(uint32_t wNVMTargetAddress)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_ERASE_SECTOR;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_Unsecure
*
* @brief unsecure device with unsecure command,
* 
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

uint16_t FTMRH_Unsecure(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_UNSECURE;// EEPROM FLASH command
	FTMRH_FCCOBLO = 0;// memory address bits[23:16]
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
	
	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_EraseBlock
*
* @brief erase flash/EEPROM block.
*        
* @param  
*	wNVMTargetAddress: target address in NVM
*	bIsEEPROM:		specify the target address is within EEPROM, 
*					1 if in EEPROM block, 0 if in FLASH block 
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
#if (defined(IAR))
__ramfunc uint16_t FTMRH_EraseBlock(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM)
#else
uint16_t FTMRH_EraseBlock(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM)
#endif
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_BLOCK;// erase FLASH block command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	if(bIsEEPROM)
	{
		FTMRH_FCCOBLO |= 0x80;	// bit 23 = 1 for EEPROM block
	}
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
	
	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_EraseVerifyBlock
*
* @brief erase verify flash/EEPROM block.
*        
* @param  
*	wNVMTargetAddress: target address in NVM
*	bIsEEPROM:		specify the target address is within EEPROM, 
*					1 if in EEPROM block, 0 if in FLASH block 
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t FTMRH_EraseVerifyBlock(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_VERIFY_BLOCK;// erase FLASH block command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	if(bIsEEPROM)
	{
		FTMRH_FCCOBLO |= 0x80;	// bit 23 = 1 for EEPROM block
	}
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_EraseVerifySection
*
* @brief erase verify flash section.
*        
* @param  
*	wNVMTargetAddress: target address in NVM, must be longword aligned
*	uiLongWordCount:   # of longwords to be verified
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t Flash_EraseVerifySection(uint32_t wNVMTargetAddress, uint16_t uiLongWordCount)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_ERASE_VERIFY_SECTION;// erase verify FLASH section command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;

	// Write index to specify the # of longwords to be verified
	FTMRH_FCCOBIX = 0x2;
	// Write the # of longwords 
	FTMRH_FCCOBLO = uiLongWordCount;
	FTMRH_FCCOBHI = uiLongWordCount>>8;
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#if 0	
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: NVM_EraseVerifyBlock
*
* @brief erase verify flash block.
*        
* @param  
*	wNVMTargetAddress: target address in NVM, must be longword aligned
*	uiLongWordCount:   # of longwords to be verified
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t NVM_EraseVerifyBlock(uint32_t wNVMTargetAddress,uint8_t bIsEEPROM)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_VERIFY_BLOCK;// erase verify FLASH section command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	if(bIsEEPROM)
	{
		FTMRH_FCCOBLO |= 0x80;	// bit 23 = 1 for EEPROM block
	}
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;

	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#if 0	
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_EraseVerifyAll
*
* @brief erase verify all flash and EEPROM blocks.
*        
* @param  
*	
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t FTMRH_EraseVerifyAll(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_VERIFY_ALL;// erase verify all flash & EEPROM blocks
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}

	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_EraseAll
*
* @brief erase all flash and EEPROM blocks.
*        
* @param  
*	
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t FTMRH_EraseAll(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_ALL;// erase  all flash & EEPROM blocks
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#endif	

	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	
	return (err);
}


uint16_t Flash_ProgramOnce(uint8_t bPhraseIndex, uint8_t *pData8Bytes)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	int i;
	
	// Check the phrase index to if it is out of boundary
	if(bPhraseIndex > 7)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[17:16]	
	FTMRH_FCCOBHI = FLASH_CMD_PROGRAMONCE;// command
	FTMRH_FCCOBLO = 0;// memory address bits[17:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the phrase index
	FTMRH_FCCOBLO = bPhraseIndex;
	FTMRH_FCCOBHI = bPhraseIndex>>8;
	
	// Write 4 words
	for(i = 0; i < 4; i++)
	{
		// Write index to specify the word (MSB word) to be programmed
		FTMRH_FCCOBIX = 0x2+i;
		// Write the word 0
		FTMRH_FCCOBHI = ((uint16_t)pData8Bytes[(i<<1)+1]);
                FTMRH_FCCOBLO = pData8Bytes[(i<<1)];
	}
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
	
	return (err);
}

uint16_t Flash_ReadOnce(uint8_t bPhraseIndex, uint8_t *pData8Bytes)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	int i;
	
	// Check the phrase index to if it is out of boundary
	if(bPhraseIndex > 7)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[17:16]	
	FTMRH_FCCOBHI = FLASH_CMD_READONCE;// command
	FTMRH_FCCOBLO = 0;// memory address bits[17:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the phrase index
	FTMRH_FCCOBLO = bPhraseIndex;	
	FTMRH_FCCOBHI = bPhraseIndex >>8;	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	// Read 4 words
	for(i = 0; i < 4; i++)
	{
		// Read the word (MSB word) indexed by FCCOBIX 
		FTMRH_FCCOBIX = 0x2+i;
		pData8Bytes[i<<1] = FTMRH_FCCOBLO; 
		pData8Bytes[(i<<1)+1] = FTMRH_FCCOBHI; 
	}	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}

	return (err);
}



/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: EEPROM_EraseVerifySection
*
* @brief erase verify flash section.
*        
* @param  
*	wNVMTargetAddress: target address in NVM, must be longword aligned
*	uiLongWordCount:   # of bytes to be verified
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t EEPROM_EraseVerifySection(uint32_t wNVMTargetAddress, uint16_t uiByteCount)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	// Check address to see if it is aligned to 4 bytes
	// Global address [1:0] must be 00.
	if(wNVMTargetAddress & 0x03)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_ERASE_VERIFY_SECTION;// erase verify FLASH section command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;
	// Write index to specify the # of longwords to be verified
	FTMRH_FCCOBIX = 0x2;
	// Write the # of longwords 
	FTMRH_FCCOBLO = uiByteCount;
	FTMRH_FCCOBHI = uiByteCount>>8;
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}	
	
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}

uint16_t EEPROM_Program1Byte(uint32_t wNVMTargetAddress, uint8_t bData)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_PROGRAM;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;
	// Write index to specify the byte0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x2;
	// Write the byte 0
	FTMRH_FCCOBLO = bData;
	// Launch the command
	FTMRH_LaunchCMD(TRUE);

	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#endif	
	
	return (err);
}


uint16_t EEPROM_ProgramUpto4Bytes(uint32_t wNVMTargetAddress, uint8_t *pbData, uint8_t bByteCount)
{
	int i;
	uint16_t err = FLASH_ERR_SUCCESS;
	if(bByteCount >4 || bByteCount == 0)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);		
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_PROGRAM;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;
	
	for (i = 0; i < bByteCount; i++)
	{
		// Write index to specify the byte0 (MSB word) to be programmed
		FTMRH_FCCOBIX = 0x2+i;
		// Write the byte 0
		FTMRH_FCCOBLO = *pbData++;
	}
	// Launch the command
	FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#endif	
	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: EEPROM_EraseSector
*
* @brief erase EEPROM sector, each EEPROM sector is of 2 bytes long
* 		 
*        
* @param  
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t EEPROM_EraseSector(uint32_t wNVMTargetAddress)
{
	uint16_t err = FLASH_ERR_SUCCESS;

	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_ERASE_SECTOR;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;        
	
	// Launch the command
        FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#endif	
	return (err);
}


uint16_t EEPROM_Program1Byte_NoWait(uint32_t wNVMTargetAddress, uint8_t bData)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_PROGRAM;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;
	// Write index to specify the byte0 (MSB word) to be programmed
	FTMRH_FCCOBIX = 0x2;
	// Write the byte 0
	FTMRH_FCCOBLO = bData;
	// Launch the command
	FTMRH_FSTAT = 0x80;

#if 0	
        // Wait till command is completed
	//while (!(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK));
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	
#if 0	
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#endif	
#endif	
	return (err);
}


uint16_t EEPROM_ProgramUpto4Bytes_NoWait(uint32_t wNVMTargetAddress, uint8_t *pbData, uint8_t bByteCount)
{
	int i;
	uint16_t err = FLASH_ERR_SUCCESS;
	if(bByteCount >4 || bByteCount == 0)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);		
	}
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_PROGRAM;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;
	
	for (i = 0; i < bByteCount; i++)
	{
		// Write index to specify the byte0 (MSB word) to be programmed
		FTMRH_FCCOBIX = 0x2+i;
		// Write the byte 0
		FTMRH_FCCOBLO = *pbData++;
	}
	// Launch the command
	FTMRH_FSTAT = 0x80;
      
	// Wait till command is completed
	//while (!(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK));
	

	return (err);
}

uint16_t EEPROM_EraseSector_NoWait(uint32_t wNVMTargetAddress)
{
	uint16_t err = FLASH_ERR_SUCCESS;

	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = EEPROM_CMD_ERASE_SECTOR;// EEPROM FLASH command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16]
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	FTMRH_FCCOBLO = wNVMTargetAddress;        
	
	// Launch the command
	FTMRH_FSTAT = 0x80;
	
	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_EraseBlock
*
* @brief erase flash/EEPROM block.
*        
* @param  
*	wNVMTargetAddress: target address in NVM
*	bIsEEPROM:		specify the target address is within EEPROM, 
*					1 if in EEPROM block, 0 if in FLASH block 
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t FTMRH_EraseBlock_NoWait(uint32_t wNVMTargetAddress, uint8_t bIsEEPROM)
{
	uint16_t err = FLASH_ERR_SUCCESS;
	
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_BLOCK;// erase FLASH block command
	FTMRH_FCCOBLO = wNVMTargetAddress>>16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block
	if(bIsEEPROM)
	{
		FTMRH_FCCOBLO |= 0x80;	// bit 23 = 1 for EEPROM block
	}
	// Write index to specify the lower byte memory address bits[15:0] to be loaded
	FTMRH_FCCOBIX = 0x1;
	// Write the lower byte memory address bits[15:0]
	FTMRH_FCCOBLO = wNVMTargetAddress;
	FTMRH_FCCOBHI = wNVMTargetAddress>>8;
	
	// Launch the command
	FTMRH_FSTAT = 0x80;

	return (err);
}


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_VerifyBackdoorKey
*
* @brief verify backdoor key. NOTE: this routine must be running from RAM or EEPROM
*        
* @param  
*	wNVMTargetAddress: target address in NVM, must be longword aligned
*	pbKey:   pointer to 8-byte key
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
 
uint16_t Flash_VerifyBackdoorKey(uint8_t *pbKey)
{
	uint16_t err = FLASH_ERR_SUCCESS;
        int i;
        
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_BACKDOOR_ACCESS;// erase verify FLASH section command
	FTMRH_FCCOBLO = 0;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block	
        // Write index to specify the lower byte memory address bits[15:0] to be loaded
 
        for(i = 0; i < 4; i++)
        {
            FTMRH_FCCOBIX = 0x1+i;
            FTMRH_FCCOBLO = *pbKey++;
            FTMRH_FCCOBHI = *pbKey++;      
        }
	
	// Launch the command
	FTMRH_LaunchCMD(TRUE);

	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#if 0	
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: NVM_EraseAll
*
* @brief erase all block,both flash and EEPROM
*        
* @param  
*	
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t NVM_EraseAll(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;

	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_ERASE_ALL;// EEPROM FLASH command
    
	
	// Launch the command
    FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	

    return err;
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: NVM_Unsecure
*
* @brief unsecure 
*        
* @param  
*	
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
uint16_t NVM_Unsecure(void)
{
	uint16_t err = FLASH_ERR_SUCCESS;

	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FTMRH_CMD_UNSECURE;// EEPROM FLASH command
    
	
	// Launch the command
    FTMRH_LaunchCMD(TRUE);
	
	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}	

    return err;
}
/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: Flash_SetUserMarginLevel
*
* @brief set user margin level
*        
* @param  
*	wNVMTargetAddress: target address in NVM, must be longword aligned
*	wMarginLevel:   user margin level
*       bIsEEPROM:      true if EEPROM address, false if flash address
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
 
uint16_t Flash_SetUserMarginLevel(uint32_t wNVMTargetAddress, uint16_t wMarginLevel, uint8_t bIsEEPROM)
{
	uint16_t err = FLASH_ERR_SUCCESS;
 	if(wMarginLevel > 2)
	{
		err = FLASH_ERR_INVALID_PARAM;
		return (err);		
	}
       
	// Clear error flags
	FTMRH_FSTAT = 0x30;
	
	// Write index to specify the command code to be loaded
	FTMRH_FCCOBIX = 0x0;
	// Write command code and memory address bits[23:16]	
	FTMRH_FCCOBHI = FLASH_CMD_SET_USER_MARGIN_LEVEL;// erase verify FLASH section command
	FTMRH_FCCOBLO = wNVMTargetAddress >> 16;// memory address bits[23:16] with bit23 = 0 for Flash block, 1 for EEPROM block	
	if(bIsEEPROM)
	{
		FTMRH_FCCOBLO |= 0x80;	// bit 23 = 1 for EEPROM block
	}
	FTMRH_FCCOBIX = 0x1;
	FTMRH_FCCOBHI = wNVMTargetAddress >> 8;// 
	FTMRH_FCCOBLO = wNVMTargetAddress;	

        FTMRH_FCCOBIX = 0x2;
	FTMRH_FCCOBHI = wMarginLevel >> 8;// 
	FTMRH_FCCOBLO = wMarginLevel;	

	// Launch the command
	FTMRH_LaunchCMD(TRUE);

	// Check error status
	if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
	{
		err |= FLASH_ERR_ACCESS;
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
	{
		err |= FLASH_ERR_MGSTAT0;		
	}
	if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
	{
		err |= FLASH_ERR_MGSTAT1;		
	}		
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_SFDIF_MASK))
	{
		err |= EEPROM_ERR_SINGLE_BIT_FAULT;
	}
	if(FTMRH_FERSTAT & (FTMRH_FERSTAT_DFDIF_MASK))
	{
		err |= EEPROM_ERR_DOUBLE_BIT_FAULT;
	}
#if 0	
	if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
	{
		err |= FLASH_ERR_PROTECTION;		
	}
#endif	
	return (err);
}

uint16_t FTMRH_CheckErrStatus(void)
{
    uint16_t err = FLASH_ERR_SUCCESS;  
    if(FTMRH_FSTAT & FTMRH_FSTAT_ACCERR_MASK)
    {
            err |= FLASH_ERR_ACCESS;
    }
    if(FTMRH_FSTAT & FTMRH_FSTAT_FPVIOL_MASK)
    {
            err |= FLASH_ERR_PROTECTION;		
    }
    if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT0_MASK)
    {
            err |= FLASH_ERR_MGSTAT0;		
    }
    if(FTMRH_FSTAT & FTMRH_FSTAT_MGSTAT1_MASK)
    {
            err |= FLASH_ERR_MGSTAT1;		
    }
    return (err);
}

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: FTMRH_LaunchCMD
*
* @brief launch NVM command. if bWaitComplete is true, then wait till command
*        is completed. It should be placed in RAM for some commands like
*        verify backdoor key if enabling flash controller bit is cleared. Otherwise,
*       it can be executed in flash.
*        
* @param  
*	bWaitComplete:  true if need wait till command completed before return
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
#if (defined(IAR))
__ramfunc  void FTMRH_LaunchCMD(uint8_t bWaitComplete)
#else
void FTMRH_LaunchCMD(uint8_t bWaitComplete)
#endif
{
#if     defined(FLASH_ENABLE_STALLING_FLASH_CONTROLLER)
     MCM_PLACR |= MCM_PLACR_ESFC_MASK;          /* enable stalling flash controller when flash is busy */
#endif
    FTMRH_FSTAT = 0x80;    
    if(bWaitComplete)
    {
      // Wait till command is completed
      while (!(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK));
    }
}
