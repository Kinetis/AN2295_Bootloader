/*
 * File:        lptmr.c
 * Purpose:     Provide common low power timer functions
 *
 * Notes:       Right now only function provided is used
 *              to generate a delay in ms. This driver
 *              could be expanded to include more functions
 *              in the future.
 *              
 */


#include "common.h"
#include "lptmr.h"

/********************************************************************/
/*
 * Initialize the low power time to provide a delay measured in ms.
 *
 *
 * Parameters:
 *  count_val   number of ms to delay
 *
 * Returns:
 * None
 */
void time_delay_ms(uint32 count_val)
{
  /* Make sure the clock to the LPTMR is enabled */
  SIM_SCGC5|=SIM_SCGC5_LPTIMER_MASK; 
  
  /* Set the compare value to the number of ms to delay */
  LPTMR0_CMR = count_val; 
  
  /* Set up LPTMR to use 1kHz LPO with no prescaler as its clock source */
  LPTMR0_PSR = LPTMR_PSR_PCS(1)|LPTMR_PSR_PBYP_MASK; 
  
  /* Start the timer */
  LPTMR0_CSR |= LPTMR_CSR_TEN_MASK; 

  /* Wait for counter to reach compare value */
  while (!(LPTMR0_CSR & LPTMR_CSR_TCF_MASK));
  
  /* Clear Timer Compare Flag */
  LPTMR0_CSR &= ~LPTMR_CSR_TEN_MASK;
  
  return;
}