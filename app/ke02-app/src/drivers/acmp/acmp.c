/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file acmp.c
*
* @author Freescale
*
* @version 0.0.1
*
* @date Apr 19, 2013
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MKE02, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/
#include "common.h"
#include "acmp.h"

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/


/******************************************************************************
* Global functions
******************************************************************************/
/*FUNCTION****************************************************************
* 
* Function Name    : ACMP_ControlStatus 
* Returned Value   : none
* Comments         :
*   ACMP ControlStatus register configuration
*
*END*********************************************************************/
void ACMP_ControlStatus (uint8 channel,uint8 ACMPx_CS)
{
    if (channel == 0)
    {
        ACMP0_CS = ACMPx_CS;
    }
    else
    {
        ACMP1_CS = ACMPx_CS;
    }
}


/*FUNCTION****************************************************************
* 
* Function Name    : ACMP_InputSelect 
* Returned Value   : none
* Comments         :
*    ACMP input channel select configuration
*
*END*********************************************************************/
void ACMP_InputSelelect (uint8 channel,uint8 ACMPx_C0)
{
    if (channel == 0)
    {
        ACMP0_C0 = ACMPx_C0;
    }
    else
    {
        ACMP1_C0 = ACMPx_C0;
    }
}


/*FUNCTION****************************************************************
* 
* Function Name    : ACMP_DACInit 
* Returned Value   : none
* Comments         :
*    brief initialize RTC with specified options.
*
*END*********************************************************************/
void ACMP_DACInit (uint8 channel,uint8 ACMPx_C1)
{
    if (channel == 0)
    {
        ACMP0_C1 = ACMPx_C1;
    }
    else
    {
        ACMP1_C1 = ACMPx_C1;
    }
}


/*FUNCTION****************************************************************
* 
* Function Name    : ACMP_InputEnable 
* Returned Value   : none
* Comments         :
*    ACMP input enable
*
*END*********************************************************************/
void ACMP_InputEnable (uint8 channel,uint8 ACMPx_C2)
{
    if (channel == 0)
    {
        ACMP0_C2 = ACMPx_C2;
    }
    else
    {
        ACMP1_C2 = ACMPx_C2;
    }
}

/*FUNCTION****************************************************************
* 
* Function Name    : ACMP_Init 
* Returned Value   : none
* Comments         :
*    ACMP initialization function
*
*END*********************************************************************/
void ACMP_Init (uint8 channel) 
{    
    if (channel == 0)
    {
        ACMP_InputSelelect(0,ACNSEL_DACO|ACPSEL_EXT0);                             /*ACMP Negative Input Select DAC output, ACMP Positive Input Select external reference 0*/
        ACMP_DACInit(0,DACVAL_HALF|DACREF_VDDA|DACEN_EN);                          /*DAC refrence voltage is VDDA, DAC output is 1/2 VDDA */
        ACMP_InputEnable(0,ACIPE_ACMPIN0_EN);                                      /*ACMP0 input is allowed */
        ACMP_ControlStatus(0,ACMOD_RISING_EDGE|ACOPE_EN|ACIE_EN|HYST_20mV|ACE_EN); /*ACMP is enabled, Enable the ACMP Interrupt,ACMP interrupt on rising edge */ 
    }
    else if(channel == 1)
    { 
        ACMP_InputSelelect(1,ACNSEL_DACO|ACPSEL_EXT0);
        ACMP_DACInit(1,DACVAL_HALF|DACREF_BANDGAP|DACEN_EN);
        ACMP_InputEnable(1,ACIPE_ACMPIN0_EN);
        ACMP_ControlStatus(1,ACMOD_RISING_EDGE|ACOPE_EN|ACIE_EN|HYST_20mV|ACE_EN);  
    }   
}

/*FUNCTION****************************************************************
* 
* Function Name    : ACMP0_ISR
* Returned Value   : none
* Comments         :
*    ACMP0 interrupt service routine.
*
*END*********************************************************************/
void ACMP0_ISR (uint8 Channel)
{  
    ACMP0_CS &= 0xDF;                                                   /* clear interrupt flag;  write 0 to clear interrupt flag ,not 1*/
   // ACMP0_CS &= ~ACIE_EN;
    printf("\nACMP0 ISR Happened.\n");
}

/*FUNCTION****************************************************************
* 
* Function Name    : ACMP1_ISR
* Returned Value   : none
* Comments         :
*    ACMP0 interrupt service routine.
*
*END*********************************************************************/
void ACMP1_ISR (uint8 Channel)
{
    ACMP1_CS &= 0xDF;                                                  /* clear interrupt flag;  write 0 to clear interrupt flag ,not 1*/
    //ACMP1_CS &= ~ACIE_EN;
    printf("\nACMP1 ISR Happened.\n");
}





