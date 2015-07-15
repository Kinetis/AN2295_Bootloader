/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      startup.c
 * @version   1.0.1.0
 * @date      May-18-2012
 * @brief     Generic Kinetis startup code.
 ******************************************************************************/
#include "startup.h"

#pragma section = ".data"
#pragma section = ".data_init"
#pragma section = ".bss"
#pragma section = "CodeRelocate"
#pragma section = "CodeRelocateRam"

/******************************************************************************
 * Startup function definition                                                *
 ******************************************************************************/
void startup(void)
{
    /* Declare a counter we'll use in all of the copy loops                   */
    unsigned int n;

    /* Get the addresses for the .data section (initialized data section)     */
    unsigned char* data_ram = __section_begin(".data");
    unsigned char* data_rom = __section_begin(".data_init");
    unsigned char* data_rom_end = __section_end(".data_init");

    /* Copy initialized data from ROM to RAM                                  */
    n = data_rom_end - data_rom;
    while (n--)
      *data_ram++ = *data_rom++;

    /* Get the addresses for the .bss section (zero-initialized data)         */
    unsigned char* bss_start = __section_begin(".bss");
    unsigned char* bss_end = __section_end(".bss");

    /* Clear the zero-initialized data section                                */
    n = bss_end - bss_start;
    while(n--)
      *bss_start++ = 0;

    /* Get addresses for any code sections that need to be copied from ROM to RAM.
     * The IAR tools have a predefined keyword that can be used to mark individual
     * functions for execution from RAM. Add "__ramfunc" before the return type in
     * the function prototype for any routines you need to execute from RAM instead
     * of ROM. ex: __ramfunc void foo(void);
     */
    unsigned char* code_relocate_ram = __section_begin("CodeRelocateRam");
    unsigned char* code_relocate = __section_begin("CodeRelocate");
    unsigned char* code_relocate_end = __section_end("CodeRelocate");

    /* Copy functions from ROM to RAM                                         */
    n = code_relocate_end - code_relocate;
    while (n--)
      *code_relocate_ram++ = *code_relocate++;
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
