/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file pmc.c
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

/******************************************************************************
* Includes
******************************************************************************/
#include "common.h"
#include "pmc.h"

/******************************************************************************
* Constants
******************************************************************************/
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


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: PMC_Configure
   *
   * @brief  configure PMC with given parameters
   * 
   * @param  PMC_Control 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/

void PMC_Configure(uint32 PMC_Control)
{
  if(PMC_Control & PMC_STOP3)
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_LVDE_MASK | PMC_SPMSC1_LVDRE_MASK | PMC_SPMSC1_LVDSE_MASK);	// disable LVD in stop mode		    
  }
  else
  {
      // stop4
      PMC_SPMSC1 |= (PMC_SPMSC1_LVDE_MASK | PMC_SPMSC1_LVDSE_MASK);	// enable LVD in stop mode		       
  }

  if(PMC_Control & PMC_LVW_INT_ENABLE)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_LVWIE_MASK);	// ENABLE LVW interrupt	    
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_LVWIE_MASK);	// disable LVW interrupt	    
  }
  
  if(PMC_Control & PMC_LVD_RESET_ENABLE)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_LVDRE_MASK);	 
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_LVDRE_MASK);		    
  }
  if(PMC_Control & PMC_LVD_STOP_ENABLE)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_LVDSE_MASK);	 
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_LVDSE_MASK);		    
  }  
  if(PMC_Control & PMC_LVD_ENABLE)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_LVDE_MASK);	 
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_LVDE_MASK);		    
  }  
  if(PMC_Control & PMC_BANDGAP_ENABLE)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_BGBE_MASK);	 
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_BGBE_MASK);		    
  }  
  if(PMC_Control & PMC_BANDGAP_DRIVE_HIGH)
  {
      PMC_SPMSC1 |= (PMC_SPMSC1_BGBDS_MASK);	 
  }
  else
  {
      PMC_SPMSC1 &= ~(PMC_SPMSC1_BGBDS_MASK);		    
  }  
  if(PMC_Control & PMC_LVD_TRIP_HIGH)
  {
      PMC_SPMSC2 |= (PMC_SPMSC2_LVDV_MASK);	 
  }
  else
  {
      PMC_SPMSC2 &= ~(PMC_SPMSC2_LVDV_MASK);		    
  }   
  if(PMC_Control & PMC_LVD_WARN_TRIP_MIDDLE1)
  {
      PMC_SPMSC2 &= ~(PMC_SPMSC2_LVWV_MASK);	 
      PMC_SPMSC2 |= (PMC_SPMSC2_LVWV(1));	 
  }
 
  if(PMC_Control & PMC_LVD_WARN_TRIP_MIDDLE2)
  {
      PMC_SPMSC2 &= ~(PMC_SPMSC2_LVWV_MASK);	 
      PMC_SPMSC2 |= (PMC_SPMSC2_LVWV(2));	 
  }

  if(PMC_Control & PMC_LVD_WARN_TRIP_HIGH)
  {
      PMC_SPMSC2 &= ~(PMC_SPMSC2_LVWV_MASK);	 
      PMC_SPMSC2 |= (PMC_SPMSC2_LVWV(3));	 
  }  
}


