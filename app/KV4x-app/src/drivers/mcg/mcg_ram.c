/*
 * All software, source code, included documentation, and any implied know-how
 * are property of Freescale Semiconductor and therefore considered
 * CONFIDENTIAL INFORMATION.
 * This confidential information is disclosed FOR DEMONSTRATION PURPOSES ONLY.
 *
 * All Confidential Information remains the property of Freescale Semiconductor
 * and will not be copied or reproduced without the express written permission
 * of the Discloser, except for copies that are absolutely necessary in order
 * to fulfill the Purpose.
 *
 * Services performed by FREESCALE in this matter are performed AS IS and
 * without any warranty.
 * CUSTOMER retains the final decision relative to the total design and
 * functionality of the end product.
 * FREESCALE neither guarantees nor will be held liable by CUSTOMER for the
 * success of this project.
 *
 * FREESCALE disclaims all warranties, express, implied or statutory
 * including, but not limited to, implied warranty of merchantability or
 * fitness for a particular purpose on any hardware, software ore advise
 * supplied to the project by FREESCALE, and or any product resulting from
 * FREESCALE services.
 * In no event shall FREESCALE be liable for incidental or consequential
 * damages arising out of this agreement. CUSTOMER agrees to hold FREESCALE
 * harmless against any and all claims demands or actions by anyone on account
 * of any damage,or injury, whether commercial, contractual, or tortuous,
 * rising directly or indirectly as a result of the advise or assistance
 * supplied CUSTOMER in connectionwith product, services or goods supplied
 * under this Agreement.
 */

/*
 * File:	mcg_ram.c
 * Purpose:	function copied to RAM at runtime
 *
 * Notes:
 * Assumes the MCG mode is in the default FEI mode out of reset
 * One of 4 clocking options can be selected.
 * One of 16 crystal values can be used
 */

#include "common.h"
#include "mcg_ram.h"

#if (defined(IAR))
__ramfunc void set_sys_dividers
#elif (defined(CW))
__relocate_code__ void set_sys_dividers
#elif (defined(GNU))
void __attribute((section(".relocate_code"))) set_sys_dividers
#else		/*MULTI and KEIL */
void set_sys_dividers
#endif
 (uint32 outdiv1, uint32 outdiv2, uint32 outdiv3, uint32 outdiv4)
{
	/*
	 * This routine must be placed in RAM. It is a workaround for errata e2448.
	 * Flash prefetch must be disabled when the flash clock divider is changed.
	 * This cannot be performed while executing out of flash.
	 * There must be a short delay after the clock dividers are changed before
	 * prefetch can be re-enabled.
	 */
	uint32 temp_reg;
	uint8 i;

	temp_reg = FMC_PFAPR;		/* store present value of FMC_PFAPR */

	/* set M0PFD through M7PFD to 1 to disable prefetch */
	FMC_PFAPR |= FMC_PFAPR_M3PFD_MASK | FMC_PFAPR_M2PFD_MASK |
				 FMC_PFAPR_M1PFD_MASK | FMC_PFAPR_M0PFD_MASK;

	/* set clock dividers to desired value */
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(outdiv1) |
				  SIM_CLKDIV1_OUTDIV2(outdiv2) |
				  /*SIM_CLKDIV1_OUTDIV3(outdiv3) | */
				  SIM_CLKDIV1_OUTDIV4(outdiv4);

	/* wait for dividers to change */
	for (i = 0; i < outdiv4; i++) {
	}

	FMC_PFAPR = temp_reg;		/* re-store original value of FMC_PFAPR */

	return;
}		/* set_sys_dividers */
