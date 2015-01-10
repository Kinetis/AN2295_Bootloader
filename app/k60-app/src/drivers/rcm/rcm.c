/*
 * File:        rcm.c
 * Purpose:     Provides routines for the reset controller module
 *              
 */

#include "common.h"
#include "rcm.h"

/* OutSRS routine - checks the value in the SRS registers and sends
 * messages to the terminal announcing the status at the start of the 
 * code.
 */
void outSRS(void){                         //[outSRS]

  
	if (RCM_SRS1 & RCM_SRS1_SACKERR_MASK)
		printf("Stop Mode Acknowledge Error Reset\n");
	if (RCM_SRS1 & RCM_SRS1_EZPT_MASK)
		printf("EzPort Reset\n");
	if (RCM_SRS1 & RCM_SRS1_MDM_AP_MASK)
		printf("MDM-AP Reset\n");
	if (RCM_SRS1 & RCM_SRS1_SW_MASK)
		printf("Software Reset\n");
	if (RCM_SRS1 & RCM_SRS1_LOCKUP_MASK)
		printf("Core Lockup Event Reset\n");
	if (RCM_SRS1 & RCM_SRS1_JTAG_MASK)
		printf("JTAG Reset\n");
	
	if (RCM_SRS0 & RCM_SRS0_POR_MASK)
		printf("Power-on Reset\n");
	if (RCM_SRS0 & RCM_SRS0_PIN_MASK)
		printf("External Pin Reset\n");
	if (RCM_SRS0 & RCM_SRS0_WDOG_MASK)
		printf("Watchdog(COP) Reset\n");
	if (RCM_SRS0 & RCM_SRS0_LOC_MASK)
		printf("Loss of Clock Reset\n");
	if (RCM_SRS0 & RCM_SRS0_LVD_MASK)
		printf("Low-voltage Detect Reset\n");
	if (RCM_SRS0 & RCM_SRS0_WAKEUP_MASK)
        {
          printf("[outSRS]Wakeup bit set from low power mode exit\n");
          printf("[outSRS]SMC_PMPROT   = %#02X \r\n", (SMC_PMPROT))  ;
          printf("[outSRS]SMC_PMCTRL   = %#02X \r\n", (SMC_PMCTRL))  ;
          printf("[outSRS]SMC_VLLSCTRL   = %#02X \r\n", (SMC_VLLSCTRL))  ;
          printf("[outSRS]SMC_PMSTAT   = %#02X \r\n", (SMC_PMSTAT))  ;

          if ((SMC_PMCTRL & SMC_PMCTRL_STOPM_MASK)== 3)
            printf("[outSRS] LLS exit \n") ;
          if (((SMC_PMCTRL & SMC_PMCTRL_STOPM_MASK)== 4) && ((SMC_VLLSCTRL & SMC_VLLSCTRL_VLLSM_MASK)== 1))
            printf("[outSRS] VLLS1 exit \n") ;
          if (((SMC_PMCTRL & SMC_PMCTRL_STOPM_MASK)== 4) && ((SMC_VLLSCTRL & SMC_VLLSCTRL_VLLSM_MASK)== 2))
            printf("[outSRS] VLLS2 exit \n") ;
          if (((SMC_PMCTRL & SMC_PMCTRL_STOPM_MASK)== 4) && ((SMC_VLLSCTRL & SMC_VLLSCTRL_VLLSM_MASK)== 3))
            printf("[outSRS] VLLS3 exit \n") ; 
	}

        if ((RCM_SRS0 == 0) && (RCM_SRS1 == 0)) 
        {
	       printf("[outSRS]RCM_SRS0 is ZERO   = %#02X \r\n", (RCM_SRS0))  ;
	       printf("[outSRS]RCM_SRS1 is ZERO   = %#02X \r\n", (RCM_SRS1))  ;	 
        }
  }

