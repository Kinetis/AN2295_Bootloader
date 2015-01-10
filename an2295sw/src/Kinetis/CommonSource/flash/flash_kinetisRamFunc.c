/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      flash_kinetisRamFunc.c
 * @author    R20253
 * @version   1.0.1.0
 * @date      Sep-17-2012
 * @brief     Flash programming driver
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/

#include "kinetis_params.h"
#include "flash_kinetis.h"

extern FCC0B_STR CommandObj;
  
//  internal driver function
/********************************************************
* Function for executing of the flash command
*
********************************************************/
#if defined(KINETIS_E)

Byte readreg = 0;

LWord FLASH_FlashCommandSequenceStart(Byte index)
{
	Byte* ptrCommandObj = (Byte*)&CommandObj;

#if     defined(FLASH_ENABLE_STALLING_FLASH_CONTROLLER)
     MCM_PLACR |= MCM_PLACR_ESFC_MASK;          /* enable stalling flash controller when flash is busy */
#endif

	/* wait till CCIF bit is set */
  	while(!(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK)){};
  	/* clear RDCOLERR & ACCERR & FPVIOL flag in flash status register */
  	FTMRH_FSTAT = FTMRH_FSTAT_ACCERR_MASK | FTMRH_FSTAT_FPVIOL_MASK; 

	if(index == ERASE_BLOCK_INDEX)
	{
		// Write index to specify the command code to be loaded
		FTMRH->FCCOBIX = 0x0;
		// Write command code and memory address bits[23:16]	
		FTMRH->FCCOBHI = FLASH_CMD_ERASE_SECTOR;// EEPROM FLASH command
		FTMRH->FCCOBLO = CommandObj.regs.fccob1;// memory address bits[23:16]
		// Write index to specify the lower byte memory address bits[15:0] to be loaded
		FTMRH->FCCOBIX = 0x1;
		// Write the lower byte memory address bits[15:0]
		FTMRH->FCCOBLO = CommandObj.regs.fccob3;
		FTMRH->FCCOBHI = CommandObj.regs.fccob2;

	}
	else if(index == PROGRAM_LONGWORD_INDEX)
	{
		// Write index to specify the command code to be loaded
		FTMRH->FCCOBIX = 0x0;
		// Write command code and memory address bits[23:16]	
		FTMRH->FCCOBHI = FLASH_CMD_PROGRAM;// program FLASH command
		FTMRH->FCCOBLO = CommandObj.regs.fccob1;// memory address bits[23:16]
		// Write index to specify the lower byte memory address bits[15:0] to be loaded
		FTMRH->FCCOBIX = 0x1;
		// Write the lower byte memory address bits[15:0]
		FTMRH->FCCOBLO = CommandObj.regs.fccob3;
		FTMRH->FCCOBHI = CommandObj.regs.fccob2;
		// Write index to specify the word0 (MSB word) to be programmed
		FTMRH->FCCOBIX = 0x2;
     
		FTMRH->FCCOBHI = CommandObj.regs.fccob6;	
		FTMRH->FCCOBLO = CommandObj.regs.fccob7;	
      
		// Write index to specify the word1 (LSB word) to be programmed
		FTMRH->FCCOBIX = 0x3;
		// Write the word1 

		FTMRH->FCCOBHI = CommandObj.regs.fccob4;
		FTMRH->FCCOBLO = CommandObj.regs.fccob5;
     

	}
	

    //FTMRH->FSTAT |= FTMRH_FSTAT_CCIF_MASK;    
        FTMRH_FSTAT = 0x80; 
    
    if(index != 0)
    {
      // Wait till command is completed
      //while (!(FTMRH->FSTAT & FTMRH_FSTAT_CCIF_MASK));   
#if 0
      while(1)
      {
        Byte i = 0;
        readreg = FTMRH->FSTAT;
        if(readreg & FTMRH_FSTAT_CCIF_MASK)
        {
            break;
        }
        
        for(i = 0; i< 200 ;i++)
        {
            ;
        }
      }
#endif
    }


    return (FTMRH_FSTAT & (FTMRH_FSTAT_ACCERR_MASK | FTMRH_FSTAT_FPVIOL_MASK)); 

}


#else

LWord FLASH_FlashCommandSequenceStart(Byte index)
{
  Byte* ptrFccobReg = (Byte*)&FLASH_BASE_PTR->FCCOB3;
  Byte* ptrCommandObj = (Byte*)&CommandObj;

  /* wait till CCIF bit is set */
  while(!(FLASH_FSTAT & FLASH_FSTAT_CCIF_MASK)){};
  /* clear RDCOLERR & ACCERR & FPVIOL flag in flash status register */
  FLASH_FSTAT = FLASH_FSTAT_ACCERR_MASK | FLASH_FSTAT_FPVIOL_MASK | FLASH_FSTAT_RDCOLERR_MASK;  
  
  /* load FCCOB registers */  
  while(index--)
    *ptrFccobReg++ = *ptrCommandObj++;
  
  //  launch a command 
  FLASH_FSTAT |= FLASH_FSTAT_CCIF_MASK; 
  //  waiting for the finishing of the command
  while(!(FLASH_FSTAT & FLASH_FSTAT_CCIF_MASK)){};
  
   /* Check error bits */
  /* Get flash status register value */
  return (FLASH_FSTAT & (FLASH_FSTAT_ACCERR_MASK | FLASH_FSTAT_FPVIOL_MASK | FLASH_FSTAT_MGSTAT0_MASK));  
} 

#endif




