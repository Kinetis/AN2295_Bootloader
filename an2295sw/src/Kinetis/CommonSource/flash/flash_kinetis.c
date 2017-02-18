/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      flash_kinetis.c
 * @author    R20253
 * @version   1.0.17.0
 * @date      Feb-15-2013
 * @brief     Flash programming driver
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/

#include "kinetis_params.h"
#include "flash_kinetis.h"

#if defined(__IAR_SYSTEMS_ICC__)
  #pragma section = "codeRam"
  #pragma location = "codeRam"
  Byte buffer[128];

  #pragma section = "default"
  #pragma location = "default"
#elif defined(__ARMCC_VERSION)
  __attribute__((section(".codeRam"))) Byte buffer[128];
#elif defined(__CWCC__)
  #pragma define_section programbuff ".programbuff" far_abs RW
  __declspec(programbuff) Byte buffer[128];
#endif

  
FCC0B_STR CommandObj;

#define FLASH_FlashCommandSequence ((LWord (*)(Byte))&buffer[1])

//  internal driver function
extern LWord FLASH_FlashCommandSequenceStart(Byte index);

/********************************************************
* Init Function 
*
********************************************************/
void FLASH_Initialization(void)
{
  LWord i;
  volatile Byte* ptr_FlashCommandSequenceStart;
  
  ptr_FlashCommandSequenceStart = ((Byte*)FLASH_FlashCommandSequenceStart - 1);
  
  //  initialize pointer to ram function 
  //  copy function from ROM to RAM
  for(i=0;i<128;i++)
    buffer[i] =	*ptr_FlashCommandSequenceStart++;
  
  //  inititalization of flash clock module 
   FLASH_INIT_FLASH_CLOCK; // done in main function
}


/********************************************************
* Function for Programming of one Long Word 
*
********************************************************/
LWord FLASH_ProgramLongWord(LWord destination, LWord data32b)
{
  /* preparing passing parameter to program the flash block */
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = FLASH_PROGRAM_LONGWORD;
  CommandObj.regsLong.fccob7654 = data32b; 

#if defined(KINETIS_E)
	return FLASH_FlashCommandSequenceStart(PROGRAM_LONGWORD_INDEX);
#else
	return FLASH_FlashCommandSequence(PROGRAM_LONGWORD_INDEX);
#endif

  
}

/********************************************************
* Function for Programming of one Long Word 
*
********************************************************/
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b)
{
  /* preparing passing parameter to program the flash block */
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = FLASH_PROGRAM_PHRASE;
  CommandObj.regsLong.fccob7654 = data64b[0];
  CommandObj.regsLong.fccobBA98 = data64b[1];
  
  return FLASH_FlashCommandSequence(PROGRAM_PHRASE_INDEX);
}

/********************************************************
* Function for Programming of section by simple longs
*
********************************************************/
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size)
{ 
  while(size--)
  {
    if(FLASH_ProgramLongWord(destination, *pSource++) != FLASH_OK)
      return FLASH_FAIL;
    destination += 4;
  }
  return FLASH_OK;
}

/********************************************************
* Function for Programming of one section (maximum is 2048 Bytes) 
*
********************************************************/
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size)
{
  LWord my_size;
  
  // check the size of memory 
  if(size >= FLASH_BURST_RAM_SIZE - 2)
    return FLASH_FAIL;
  
  if(destination & 0x00000003)
    return FLASH_FAIL;
  
  // it's neccessary alligment on start of buffer?
  if(destination & 0x00000004)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = 0xFFFFFFFF;    
    tmp_buff[1] = *(pSource++);
    
    //  call flash phrase
    if(FLASH_ProgramPhrase((destination & 0xFFFFFFF8), tmp_buff))
      return FLASH_FAIL;
    
    destination += 4;    
  }
  
  my_size = size & 0xFFFFFFFE;
 
  if(my_size)
  {
    //  flash all phrases
    while(my_size)
    {
      //  call flash phrase
      if(FLASH_ProgramPhrase(destination, pSource))
        return FLASH_FAIL;
    
      pSource += 2;
      destination += 8;
      my_size -= 2;      
    }
  }
  
  // it's neccessary alligment on end of buffer?
  if(size & 0x00000001)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = *pSource;    
    tmp_buff[1] = 0xFFFFFFFF;
    
    //  call flash phrase
    if(FLASH_ProgramPhrase(destination, tmp_buff))
      return FLASH_FAIL;           
  }
  return FLASH_OK;
}

/********************************************************
* Function for erasing of flash memory sector (0x800)
*
********************************************************/
LWord FLASH_EraseSector(LWord destination)
{  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = FLASH_ERASE_SECTOR;

  #if defined(KINETIS_E)
		return FLASH_FlashCommandSequenceStart(ERASE_BLOCK_INDEX);
  #else
		return FLASH_FlashCommandSequence(ERASE_BLOCK_INDEX);
  #endif
  
  
}



