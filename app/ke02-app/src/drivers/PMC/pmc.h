/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file pmc.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Jul 17, 2011
*
* @brief PMC utilities. 
*
*******************************************************************************
*
* provide APIs for accessing power management controller (PMC)
******************************************************************************/

#ifndef PMC_H_
#define PMC_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/
// PMC control parameters
const enum {
  PMC_LVW_INT_DISABLE = 0,
  PMC_LVD_RESET_DISABLE = 0,
  PMC_LVD_STOP_DISABLE = 0, 
  PMC_LVD_DISABLE = 0,
  PMC_BANDGAP_DISABLE = 0,
  PMC_BANDGAP_DRIVE_LOW = 0,
  PMC_LVD_TRIP_LOW = 0,
  PMC_LVD_WARN_TRIP = 0,
  PMC_STOP4 = 0,
  // bit mask definition
  PMC_LVW_INT_ENABLE = 1,
  PMC_LVD_RESET_ENABLE = 2,
  PMC_LVD_STOP_ENABLE = 4, 
  PMC_LVD_ENABLE = 8,
  PMC_BANDGAP_ENABLE = 16,
  PMC_BANDGAP_DRIVE_HIGH = 32,
  PMC_LVD_TRIP_HIGH = 64,
  PMC_LVD_WARN_TRIP_MIDDLE1 = 128,
  PMC_LVD_WARN_TRIP_MIDDLE2 = 256,
  PMC_LVD_WARN_TRIP_HIGH = 512,
  PMC_STOP3 = 1024,
};

/******************************************************************************
* Macros
******************************************************************************/


/******************************************************************************
* Types
******************************************************************************/



/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void PMC_Configure(uint32 PMC_Control);

#endif /* PMC_H_ */
