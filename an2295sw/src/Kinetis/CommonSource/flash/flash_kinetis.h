/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      flash_kinetis.h
 * @author    R20253
 * @version   1.0.8.0
 * @date      Dec-13-2012
 * @brief     Flash programming driver header file
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/
#ifndef _FLASH_KINETIS_H
#define _FLASH_KINETIS_H

//  Flash hardware algorithm operation commands 
#define FLASH_PROGRAM_LONGWORD    0x06
#define FLASH_PROGRAM_PHRASE      0x07
#define FLASH_ERASE_SECTOR        0x09

#define FCCOB_REGS  12
#define FLASH_OK     0
#define FLASH_FAIL   1

#define FLASH_BURST_RAM_ADDR (LWord*)0x14000000
#define FLASH_BURST_RAM_SIZE	64


#define ERASE_BLOCK_INDEX       4
#define PROGRAM_LONGWORD_INDEX  8
#define PROGRAM_PHRASE_INDEX    12

#if defined(KINETIS_E)
/******************************************************************************
* Flash and EEPROM commands
*
*//*! @addtogroup flash_command_list
* @{
*******************************************************************************/
#define FTMRH_CMD_ERASE_VERIFY_ALL				0x01			/*!< FTMRH erase verify all command */
#define FTMRH_CMD_ERASE_VERIFY_BLOCK			0x02			/*!< FTMRH erase verify block command */
#define FTMRH_CMD_ERASE_ALL								0x08			/*!< FTMRH erase all command */
#define FTMRH_CMD_ERASE_BLOCK							0x09			/*!< FTMRH erase blockcommand */
#define FTMRH_CMD_UNSECURE								0x0B			/*!< FTMRH unsecure command */
#define FTMRH_CMD_SET_USER_MARGIN					0x0D			/*!< FTMRH set usermargin command */

#define FLASH_CMD_ERASE_VERIFY_SECTION		0x03			/*!< FTMRH erase verify section command */
#define FLASH_CMD_READONCE								0x04			/*!< FTMRH read once command */
#define FLASH_CMD_PROGRAM									0x06			/*!< FTMRH program command */
#define FLASH_CMD_PROGRAMONCE							0x07			/*!< FTMRH program once command */
#define FLASH_CMD_ERASE_SECTOR						0x0A			/*!< FTMRH erase sector command */
#define FLASH_CMD_BACKDOOR_ACCESS					0x0C			/*!< FTMRH backdoor key access command */
#define FLASH_CMD_SET_USER_MARGIN_LEVEL		0x0D			/*!< FTMRH set user margin level command */

#define EEPROM_CMD_ERASE_VERIFY_SECTION		0x10			/*!< EEPROM erase berify section command */
#define EEPROM_CMD_PROGRAM								0x11			/*!< EEPROM program command */
#define EEPROM_CMD_ERASE_SECTOR 					0x12			/*!< EEPROM erase sector command */

#endif

//  FCOOB register structure
typedef union 
{
  Byte all[FCCOB_REGS];
  struct
  {
    Byte fccob3;
    Byte fccob2;
    Byte fccob1;
    Byte fccob0;
    Byte fccob7;
    Byte fccob6;
    Byte fccob5;
    Byte fccob4;
    Byte fccobB;
    Byte fccobA;
    Byte fccob9;
    Byte fccob8;
  }regs;
  
  struct
  {
    LWord fccob3210;
    LWord fccob7654;
    LWord fccobBA98;
  }regsLong;
}FCC0B_STR;

//  API FUNCTION FOR KINETIS FLASH DRIVER
void  FLASH_Initialization(void);
LWord FLASH_EraseSector(LWord destination);
LWord FLASH_ProgramLongWord(LWord destination, LWord data);
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b);
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size);
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size);
LWord FLASH_MassErase(void);


#endif



