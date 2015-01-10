/*
 * File:	start.c
 * Purpose:	Kinetis start up routines. 
 *
 * Notes:		
 */

#include "start.h"
#include "common.h"
#include "wdog.h"
#include "sysinit.h"

void start(void);
void SystemInit( void );
/********************************************************************/
/*!
 * \brief   Kinetis Start
 * \return  None
 *
 * This function calls all of the needed starup routines and then 
 * branches to the main process.
 */
void start(void)
{ 
	/* Disable the watchdog timer */
    wdog_disable();

#ifndef __GNUC__ 
#ifndef KEIL
	/* Copy any vector or data sections that need to be in RAM */
	common_startup();
#endif
#endif

	/* Perform processor initialization */
	sysinit();
	
	/* Jump to main process */
	main();

	/* No actions to perform after this so wait forever */
	while(1);
}
/********************************************************************/
/*!
 * \brief   Kinetis Identify
 * \return  None
 *
 * This is primarly a reporting function that displays information
 * about the specific CPU to the default terminal including:
 * - Kinetis family
 * - package
 * - die revision
 * - P-flash size
 * - Ram size
 */
void cpu_identify (void)
{

}
/********************************************************************/
/*!
 * \brief   flash Identify
 * \return  None
 *
 * This is primarly a reporting function that displays information
 * about the specific flash parameters and flash version ID for 
 * the current device. These parameters are obtained using a special
 * flash command call "read resource." The first four bytes returned
 * are the flash parameter revision, and the second four bytes are
 * the flash version ID.
 */
void flash_identify (void)
{
    /* Get the flash parameter version */
}
/********************************************************************/
/********************************************************************/
/*!
 * \brief   flash SystemInit
 * \return  None
 *
 * this is a system initialization function which dediu16Cated in Keil 
 * others complier don't use it.
 * it is similar to start function
 */
void SystemInit( void )
{
	/* Disable the watchdog timer */
    wdog_disable();
	/* Perform processor initialization */
	sysinit();
	
}



