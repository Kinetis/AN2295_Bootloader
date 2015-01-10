/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: app_init.c$
* $Version : 3.6.1.0$
* $Date    : Jul-30-2012$
*
* Comments:
*
*   This file contains the init functions.
*
*END************************************************************************/

#include "TSS_API.h"
#include "wdog.h"
#include "uart.h"
#include "main.h"
#include "common.h"
#include "app_init.h"

/***************************** Local Types *********************************/

extern UINT16 u16LPcounter;

/****************************** Prototypes *********************************/


/***************************************************************************
* InitPorts
* --------------------------------------------------------------------------
* Global init of the board ports
****************************************************************************/

void InitPorts(void)
{
    /* Disable WatchDog */
    wdog_disable();
}

/****************************************************************************************************
* TSS_Init_ASlider
* ---------------------------------------------------------------------------------------------------
* Inits TSS for Analog Slider module
*****************************************************************************************************/

void TSS_Init_ASlider(void)
{
    GPIOA_PIDR = 0x3FFFFFFF;  /* GPIOA_PIDR must be set as 0, or the GPIO can't be set as input mode */
  #if (TSS_USE_AUTO_SENS_CALIBRATION == 0)  
    UINT8 lcv;
  #endif    
  /* Initializes the TSS */
  (void)TSS_Init(); 

  /* Set Number of Samples */
  (void)TSS_SetSystemConfig(System_NSamples_Register, 0x08);  

  #if (TSS_USE_AUTO_SENS_CALIBRATION == 0)    
    /* Sets the Sensitivity value for each electrode */
    for (lcv =0; lcv < TSS_N_ELECTRODES; lcv++) 
    {
      (void)TSS_SetSystemConfig(System_Sensitivity_Register + lcv, 0x1A); 
    }
  #endif    

  /* Enablers Settings */
  (void)TSS_SetSystemConfig(System_ElectrodeEnablers_Register + 0u, 0x03);

  /* Auto Trigger Config */
  #if (APP_TSS_USE_TRIGGER_MODE == AUTO)
    (void) TSS_SetSystemConfig(System_SystemTrigger_Register, TSS_TRIGGER_MODE_AUTO);   /* TSS_TRIGGER_MODE_AUTO/TSS_TRIGGER_MODE_ALWAYS/TSS_TRIGGER_MODE_SW */
  #elif (APP_TSS_USE_TRIGGER_MODE == ALWAYS)
    (void) TSS_SetSystemConfig(System_SystemTrigger_Register, TSS_TRIGGER_MODE_ALWAYS); /* TSS_TRIGGER_MODE_AUTO/TSS_TRIGGER_MODE_ALWAYS/TSS_TRIGGER_MODE_SW */
  #elif (APP_TSS_USE_TRIGGER_MODE == SW)
    (void) TSS_SetSystemConfig(System_SystemTrigger_Register, TSS_TRIGGER_MODE_SW);   /* TSS_TRIGGER_MODE_AUTO/TSS_TRIGGER_MODE_ALWAYS/TSS_TRIGGER_MODE_SW */
  #endif

  /* Configure Control 1 */
  /* Configure the range */
  (void)TSS_SetASliderConfig(cASlider1.ControlId,ASlider_Range_Register, 200);
  /* Configure the TSS to report the touch, release and movement events */
  (void)TSS_SetASliderConfig(cASlider1.ControlId,ASlider_Events_Register,(TSS_ASLIDER_MOVEMENT_EVENT_EN_MASK));// | TSS_ASLIDER_INITIAL_TOUCH_EVENT_EN_MASK));
  /* Enables Callback function. Enables the control */
  (void)TSS_SetASliderConfig(cASlider1.ControlId,ASlider_ControlConfig_Register,(TSS_ASLIDER_CONTROL_EN_MASK|TSS_ASLIDER_CALLBACK_EN_MASK));

  #if APP_TSS_USE_DCTRACKER
    /* Enables the TSS. Enables the DC Tracking feature. Default DC Tracking value is 0x64 */
    (void)TSS_SetSystemConfig(System_SystemConfig_Register,(TSS_SYSTEM_EN_MASK | TSS_DC_TRACKER_EN_MASK));
  #else
    /* Enables the TSS */
    (void)TSS_SetSystemConfig(System_SystemConfig_Register,(TSS_SYSTEM_EN_MASK));
  #endif

}

/***************************************************************************
* DelayMS
* --------------------------------------------------------------------------
* Common Delay function in ms units
****************************************************************************/

void DelayMS(UINT16 u16delay)
{
  int i = 5000;
	while(i--);
}
