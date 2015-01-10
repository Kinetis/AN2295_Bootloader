/** ###################################################################
**     Filename  : Events.c
**     Project   : ProcessorExpert
**     Processor : MKXX
**     Component : Events
**     Version   : Driver 01.00
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2011-02-10, 13:20, # CodeGen: 0
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**
** ###################################################################*/

#include "TSS_API.h"
#include "main.h"
#include "app_init.h"
#include "common.h"
#include "events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  TSS1_fCallBack4 (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         Callback definition for Control 1. This event is enabled
**         only if Control 3 is enabled.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8ControlId     - Valid unique Identifier of
**                           the Control which generated the CallBack
**                           function. This Id can be used for finding
**                           of Callback's source Control.
**     Returns     : Nothing
** ===================================================================
*/
#ifndef OUT_LIBRARY
void TSS1_fCallBack1(TSS_CONTROL_ID u8ControlId)
{
  // Set LED brightness 
  SET_LED_RED(cASlider1.Position);
  SET_LED_GREEN(cASlider1.Position);  
  SET_LED_BLUE(cASlider1.Position);

  (void) u8ControlId;
  
  return;
}


/*
** ===================================================================
**     Event       :  TSS1_fOnFault (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is called by TSS after Fault
**         occurence. This event is enabled always and depends on
**         selection 'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  : UINT8
**     Returns     : Nothing
** ===================================================================
*/
void TSS_fOnFault(UINT8 electrode_number)
{
    if(tss_CSSys.Faults.ChargeTimeout || tss_CSSys.Faults.SmallCapacitor) /* If large or small capacitor fault  */
    {
      (void) TSS_SetSystemConfig(System_Faults_Register, 0x00);           /* Clear the fault flag */
    }

    if(tss_CSSys.Faults.SmallTriggerPeriod)
    {
      (void) TSS_SetSystemConfig(System_Faults_Register, 0x00);           /* Clear the fault flag */

    #if APP_TSS_USE_DCTRACKER
        /* Enables the TSS. Enables the DC Tracking feature. Default DC Tracking value is 0x64 */
        (void)TSS_SetSystemConfig(System_SystemConfig_Register,(TSS_SYSTEM_EN_MASK | TSS_DC_TRACKER_EN_MASK));
    #else
        /* Enables the TSS */
        (void)TSS_SetSystemConfig(System_SystemConfig_Register,(TSS_SYSTEM_EN_MASK));
    #endif
    }
}
#endif
/*
** ===================================================================
**     Event       :  TSS1_fOnInit (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is called after whole TSS Init. This
**         event is enabled always and depends on selection 'generate
**         code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TSS_fOnInit(void)
{
    #ifndef OUT_LIBRARY
    /* HW Timer clock must be opened here, or enter hard fault */
    SIM_SCGC |= SIM_SCGC_FTM0_MASK;   
    #else
    SIM_SCGC |= SIM_SCGC_FTM2_MASK;  
    #endif
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.00 [04.48]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
