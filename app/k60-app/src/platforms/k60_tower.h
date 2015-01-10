/*
 * File:        k60_tower.h
 * Purpose:     Definitions for the Kinetis K60 tower card
 *
 * Notes:
 */

#ifndef __K60_TOWER_H__
#define __K60_TOWER_H__

#include "mcg.h"

/********************************************************************/

/* Global defines to use for all boards */
#define DEBUG_PRINT
/* 
 * Select the serial port that is being used below. Only one of the 
 * options should be uncommented at any time.
 */
//#define SERIAL_CARD     // use this option for serial port on TWR-SER
#define OSJTAG         // use this option for serial port over the OS-JTAG circuit

/* Define for the CPU on the K60 board */
#define CPU_MK60DN512VMD10

  /*
   * Input Clock Info
   */
  #define CLK0_FREQ_HZ        50000000
  #define CLK0_TYPE           CANNED_OSC

  /*
   * PLL Configuration Info
   */
//  #define NO_PLL_INIT  // define this to skip PLL initilaization and stay in default FEI mode

/* The expected PLL output frequency is:
 * PLL out = (((CLKIN/PRDIV) x VDIV) / 2)
 * where the CLKIN is CLK0_FREQ_HZ.
 * 
 * For more info on PLL initialization refer to the mcg driver files.
 */

  #define PLL0_PRDIV      25       // divider eference by 25 = 2 MHz
  #define PLL0_VDIV       50      // multiply reference by 50 = 100 MHz

  /* Serial Port Info */
  #if (defined(SERIAL_CARD))
    #define TERM_PORT           UART3_BASE_PTR
  #elif (defined(OSJTAG))
    #define TERM_PORT           UART5_BASE_PTR
  #else
    #error "No valid serial port defined"
  #endif

  #define TERMINAL_BAUD       115200
  #undef  HW_FLOW_CONTROL
#else
  #error "No valid tower CPU card defined"
#endif /* __K60_TOWER_H__ */
