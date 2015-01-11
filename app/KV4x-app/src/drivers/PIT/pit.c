#include "common.h"
#include "pit.h"

void pit_init()
{
  SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;              //enabling PIT clock
    
  PIT_MCR &= ~PIT_MCR_MDIS_MASK;                //Enabling the standard timers
  
  PIT_LDVAL0 = 0xFF;                          //Timer Start Value
  
  PIT_TCTRL0 = PIT_TCTRL_TIE_MASK;              //Timer Interrupt Enable
  PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;             //Timer Enable

}

