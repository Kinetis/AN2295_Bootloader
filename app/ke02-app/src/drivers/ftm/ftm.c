/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ftm.c
*
* @author a13984
*
* @version 0.0.1
*
* @date Aug 4, 2011
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MA64, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/
#include "common.h"
#include "ftm.h"

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


/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_PWM_Init
   *
   * @brief general configuration to FTM_No to high ture EPWM mode, clock soure is the 
   *        system clock, MOD, CnV are the initial value
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    PWMModeSelect         select CPWM , EPWM  or combine pwm mode
   *    PWMEdgeSelect         select high true or low true pulse
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_PWM_Init(FTM_MemMapPtr FTM_No, unsigned char PWMModeSelect, unsigned char PWMEdgeSelect)
{
    uint8_t channels, i;
    
    /* open the clock gate */
	if (FTM0_BASE_PTR == FTM_No)
    {
        channels = 2;
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM0_MASK;
    }
    else if(FTM1_BASE_PTR == FTM_No)
    {
        channels = 2;
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM1_MASK;
    }        
    else if (FTM2_BASE_PTR == FTM_No)
    {
        channels = 6;
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
    }
    else
        return FALSE;  /* error in FTM address or channel */
    
    FTM_SC_REG(FTM_No)  = 0x0; /* diable counter */  
	FTM_MOD_REG(FTM_No) = FTM_MOD_INIT; 
    

    if(FTM_PWMMODE_CENTERALLIGNED == PWMModeSelect) /* enable CPWM */
    {
        FTM_SC_REG(FTM_No) |= FTM_SC_CPWMS_MASK; 
    }
    else if(FTM_PWMMODE_COMBINE == PWMModeSelect)  /* enable combine pwm mode */
    {
        if(FTM2_BASE_PTR == FTM_No)
        {
            FTM_MODE_REG(FTM_No) |= FTM_MODE_FTMEN_MASK;
            FTM_COMBINE_REG(FTM_No) = FTM_COMBINE_COMBINE0_MASK | FTM_COMBINE_COMP0_MASK | FTM_COMBINE_SYNCEN0_MASK | FTM_COMBINE_DTEN0_MASK |
                                      FTM_COMBINE_COMBINE1_MASK | FTM_COMBINE_COMP1_MASK | FTM_COMBINE_SYNCEN1_MASK | FTM_COMBINE_DTEN1_MASK |
                                      FTM_COMBINE_COMBINE2_MASK | FTM_COMBINE_COMP2_MASK | FTM_COMBINE_SYNCEN2_MASK | FTM_COMBINE_DTEN2_MASK ;                               
        }
        else 
            return FALSE;  /* error, only FTM2 has the combine mode */
    }
    if(FTM_PWM_HIGHTRUEPULSE == PWMEdgeSelect)
    {
        /* Configure timers PWM High True Pulses */
        for(i=0; i<channels; i++)
        {
            FTM_CnSC_REG(FTM_No,i) = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;  
            FTM_CnV_REG(FTM_No,i)  = FTM_C0V_INIT + i*100; 
        }
    }
    else if(FTM_PWM_LOWTRUEPULSE == PWMEdgeSelect)
    {
        /* Configure timers for PWM Low True Pulses */
        for(i=0; i<channels; i++) 
        {
            FTM_CnSC_REG(FTM_No,i) = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSA_MASK; 
            FTM_CnV_REG(FTM_No,i)  = FTM_C0V_INIT + i*100 ; 
        }
    }
    FTM_SC_REG(FTM_No) |= FTM_SC_CLKS(FTM_CLOCK_SYSTEMCLOCK);  /* system clock */
    //FTM_PWMLOAD_REG(FTM_No) |= FTM_PWMLOAD_LDOK_MASK | 0x3F; 
    
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_InputCapture_Init
   *
   * @brief general configuration to FTM_No to input capture mode
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               channel number to be configured
   *    CaptureMode           select capture edge: rising, falling or both
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_InputCapture_Init(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char CaptureMode)
{ 
    /* open the clock gate */
	if ((FTM0_BASE_PTR == FTM_No) && (Channel < 2))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM0_MASK;
        enable_irq(INT_FTM0 - 16);
    }
    else if((FTM1_BASE_PTR == FTM_No)  && (Channel < 2))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM1_MASK;
        enable_irq(INT_FTM1 - 16);
    }        
    else if ((FTM2_BASE_PTR == FTM_No)  && (Channel < 6))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        enable_irq(INT_FTM2 - 16);
    }
    else 
        return FALSE; /* error in FTM address or channel */
    
    FTM_SC_REG(FTM_No)  = 0x0; /* diable counter */ 
    FTM_MOD_REG(FTM_No) = 0xFFFF;
    
    if(FTM_INPUTCAPTURE_RISINGEDGE == CaptureMode)  /* enable interrupt, Capture on rising edge */
    {
        FTM_CnSC_REG(FTM_No,Channel) = FTM_CnSC_CHIE_MASK | FTM_CnSC_ELSA_MASK;
    }
    else if(FTM_INPUTCAPTURE_FALLINGEDGE == CaptureMode)  /* Capture on falling edge */
    {
        FTM_CnSC_REG(FTM_No,Channel) = FTM_CnSC_CHIE_MASK | FTM_CnSC_ELSB_MASK;
    }
    else if(FTM_INPUTCAPTURE_BOTHEDGE == CaptureMode)    /* Capture on rising or falling edge */
    {
        FTM_CnSC_REG(FTM_No,Channel) = FTM_CnSC_CHIE_MASK | FTM_CnSC_ELSA_MASK | FTM_CnSC_ELSB_MASK;       
    }
    else 
        return FALSE;
    FTM_SC_REG(FTM_No) |= FTM_SC_CLKS(FTM_CLOCK_SYSTEMCLOCK);  /* system clock */
    
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_DualEdgeCapture_Init
   *
   * @brief general configuration to FTM_No to Dual Edge Capture mode to measure the
   *        width or the period  of a pulse
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               ChannelPair number to be configured: 0, 2, 4
   *    CaptureMode           select capture edge: one shot and continuous mode
   *    Channel_N_Edge        channel N detect edge
   *    Channel_Np1_Edge      channel N+1 detect edge
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_DualEdgeCapture_Init(FTM_MemMapPtr FTM_No, unsigned char ChannelPair, unsigned char CaptureMode, 
                               unsigned char Channel_N_Edge, unsigned char Channel_Np1_Edge)
{ 
    if ((FTM2_BASE_PTR == FTM_No)  && (ChannelPair < 6))
    {
        if(ChannelPair%2 == 0)
        {
            SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
            enable_irq(INT_FTM2 - 16);
            if(ChannelPair == 0 || ChannelPair == 2)
            {
                /* channel filter is active */
            }
        }
        else
            return FALSE;  /* only channel pair 0,2,4 are available */
    }
    else
        return FALSE;  /* only FTM2 has the function */
    
    FTM_SC_REG(FTM_No)    = 0x0; /* diable counter */ 
    FTM_MODE_REG(FTM_No) |= FTM_MODE_FTMEN_MASK;  /* FTMEN = 1 */  
    
    FTM_CnSC_REG(FTM_No,ChannelPair) &= ~FTM_CnSC_CHF_MASK;  /* CH(n)F and CH(n+1)F bits must be cleared first */
    FTM_CnSC_REG(FTM_No,(ChannelPair+1)) &= ~FTM_CnSC_CHF_MASK;
    
    if(FTM_INPUTCAPTURE_DUALEDGE_ONESHOT == CaptureMode) /* oneshot mode */
    {
        FTM_CnSC_REG(FTM_No,ChannelPair) &= ~FTM_CnSC_MSA_MASK;
    }
    else if(FTM_INPUTCAPTURE_DUALEDGE_CONTINUOUS == CaptureMode) /* continuouse mode */
    {
        FTM_CnSC_REG(FTM_No,ChannelPair) |= FTM_CnSC_MSA_MASK;
    }
    
    FTM_CnSC_REG(FTM_No,ChannelPair) |= Channel_N_Edge << 2;   /* select detec edge */
    FTM_CnSC_REG(FTM_No,(ChannelPair +1)) |= Channel_Np1_Edge << 2;
    
    FTM_SC_REG(FTM_No) |= FTM_SC_CLKS(FTM_CLOCK_SYSTEMCLOCK);  /* system clock */
    
    FTM_COMBINE_REG(FTM_No) |=  (FTM_COMBINE_DECAP0_MASK | FTM_COMBINE_DECAPEN0_MASK) << (ChannelPair * 4); /* DECAPEN = 1,  ChannelPair/2 * 8 */
    
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_OutputCompare_Init
   *
   * @brief general configuration to FTM_No to input capture mode
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               channel number to be configured
   *    CompareMode           select compare edge: toggle, set and clear
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_OutputCompare_Init(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char CompareMode)
{
    /* open the clock gate */
	if ((FTM0_BASE_PTR == FTM_No) && (Channel < 2))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM0_MASK;
    }
    else if((FTM1_BASE_PTR == FTM_No)  && (Channel < 2))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM1_MASK;
    }        
    else if ((FTM2_BASE_PTR == FTM_No)  && (Channel < 6))
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
    }
    else 
        return FALSE; /* error in FTM address or channel */
    
    FTM_SC_REG(FTM_No)    = 0x0; /* diable counter */
    FTM_MOD_REG(FTM_No) = FTM_MOD_INIT; 
    FTM_CnSC_REG(FTM_No,Channel) = (FTM_CnSC_MSA_MASK | (CompareMode << 2));   /* select detec edge */
    FTM_CnV_REG(FTM_No,Channel)  = FTM_C0V_INIT;
    
    FTM_SC_REG(FTM_No) |= FTM_SC_CLKS(FTM_CLOCK_SYSTEMCLOCK);  /* system clock */
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_SYNC_Software
   *
   * @brief general configuration to FTM_No to start software synchronization
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_SYNC_Software(FTM_MemMapPtr FTM_No)
{
    if (FTM2_BASE_PTR == FTM_No)
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        FTM_SYNCONF_REG(FTM_No) |= FTM_SYNCONF_SYNCMODE_MASK;   /* recommend enhanced sync mode */
        FTM_SYNC_REG(FTM_No) |= FTM_SYNC_SWSYNC_MASK;
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_SYNC_Hardware
   *
   * @brief general configuration to FTM_No to start software synchronization
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    TriggerN              select the hardware trigger source
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_SYNC_Hardware(FTM_MemMapPtr FTM_No, unsigned char TriggerN)
{
    if (FTM2_BASE_PTR == FTM_No)
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        FTM_SYNCONF_REG(FTM_No) |= FTM_SYNCONF_SYNCMODE_MASK;   /* recommend enhanced sync mode */
        switch(TriggerN)
        {
        case FTM_SYNC_TRIGGER_TRIGGER2: SIM_SOPT_REG(SIM_BASE_PTR) |= SIM_SOPT_FTMSYNC_MASK; break;  
        case FTM_SYNC_TRIGGER_TRIGGER1:  break;  /* need configure FTM0CH0 */
        case FTM_SYNC_TRIGGER_TRIGGER0:  break;  /* need configure CMP0 */
        default: break;
        }
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_PWM_Deadtime_Set
   *
   * @brief general configuration to FTM_No to start software synchronization
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    PrescalerValue        system clock divide value, 0 to 3
   *    DeadtimeValue         n count clock is inserted, 0 to 63
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_PWM_Deadtime_Set(FTM_MemMapPtr FTM_No, unsigned char PrescalerValue, unsigned char DeadtimeValue)
{
    if (FTM2_BASE_PTR == FTM_No)
    {
        //FTM_PWM_Init(FTM_No, FTM_PWMMODE_COMBINE, FTM_PWM_HIGHTRUEPULSE);   /* dead time insertion should be used in combine mode */
        if(!(FTM_MODE_REG(FTM_No) & FTM_MODE_WPDIS_MASK))  /* if write protection is enabled */
        {
            FTM_MODE_REG(FTM_No) |= FTM_MODE_WPDIS_MASK; /* disable the write protection */
            FTM_DEADTIME_REG(FTM_No) = FTM_DEADTIME_DTVAL(DeadtimeValue) | FTM_DEADTIME_DTPS(PrescalerValue);
            FTM_MODE_REG(FTM_No) &= ~FTM_MODE_WPDIS_MASK; /* enable the write protection */       
        }
        else /* if no protection */
        {
            FTM_DEADTIME_REG(FTM_No) = FTM_DEADTIME_DTVAL(DeadtimeValue) | FTM_DEADTIME_DTPS(PrescalerValue);
        }
        FTM_SYNC_REG(FTM_No) |= FTM_SYNC_SWSYNC_MASK; /* software sync */
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}    

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_OutputMask_Set
   *
   * @brief general configuration to FTM_No to start software synchronization
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               pwm channel needed to be masked
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_OutputMask_Set(FTM_MemMapPtr FTM_No, unsigned char Channel)
{
    if (FTM2_BASE_PTR == FTM_No && Channel < 6)
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        FTM_OUTMASK_REG(FTM_No) |= 1 << Channel;
        if(FTM_SYNC_REG(FTM_No) & FTM_SYNC_SYNCHOM_MASK) /* if PWM sync is needed */
        {
            if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_SWOM_MASK) /* if software sync is needed*/
                FTM_SYNC_Software(FTM_No);  /* software sync */ 
            else if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_HWOM_MASK) /* if hardware sync is needed*/
                FTM_SYNC_Hardware(FTM_No, FTM_SYNC_TRIGGER_TRIGGER2);  /* hardware sync */ 
        }
        else  /* no need to sync, update on the next rising edge of system clock  */
        {
        }
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_SWOutputControl_Set
   *
   * @brief general configuration to FTM_No to start software synchronization
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               pwm channel needed to be controlled by software
   *    ChannelValue          the value to be set,  0 or 1
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_SWOutputControl_Set(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char ChannelValue)
{
    if (FTM2_BASE_PTR == FTM_No && Channel < 6)
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        if(FTM_SWOCTRL_HIGH == ChannelValue)
        {
            FTM_SWOCTRL_REG(FTM_No) |= 0x0101 << Channel;
        }
        else if(FTM_SWOCTRL_LOW == ChannelValue)
        {
            FTM_SWOCTRL_REG(FTM_No) |= 1 << Channel;
            FTM_SWOCTRL_REG(FTM_No) &= ~(0x100 << Channel);
        }
        if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_SWOC_MASK) /* if PWM sync is needed */
        {
            if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_SWSOC_MASK) /* if software sync is needed*/
                FTM_SYNC_Software(FTM_No);  /* software sync */ 
            else if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_HWSOC_MASK) /* if hardware sync is needed*/
                FTM_SYNC_Hardware(FTM_No, FTM_SYNC_TRIGGER_TRIGGER2);  /* hardware sync */ 
        }
        else  /* no need to sync, update on the next rising edge of system clock  */
        {
        }
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}


/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_Polarity_Set
   *
* @brief general configuration to PWM polarity
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    Channel               pwm channel needed to be controlled by software
   *    ActiveValue           the value to be set,  0 or 1
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_Polarity_Set(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char ActiveValue)
{
    if (FTM2_BASE_PTR == FTM_No && Channel < 6)
    {
        SIM_SCGC_REG(SIM_BASE_PTR) |= SIM_SCGC_FTM2_MASK;
        if(FTM_POLARITY_HIGHACTIVE == ActiveValue)
        {
            FTM_POL_REG(FTM_No) &=  ~(1 << Channel);
        }
        else if(FTM_POLARITY_LOWACTIVE == ActiveValue)
        {
            FTM_POL_REG(FTM_No) |=  (1 << Channel);
        }
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}

/************************************************************************************
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_InvertingCTRL_Set
   *
   * @brief swap the output of CH(n) and CH(n+1)
   *        
   * @param  
   *    FTM_No                  pointer to one of three FTM base register address
   *    ChannelPair           the pair to be swapped, 0,1,2
   *    
   *
   * @return TRUE or FALSE
   *
   * @ Pass/ Fail criteria: none
   *********************************************************************************/
uint8 FTM_InvertingCTRL_Set(FTM_MemMapPtr FTM_No, unsigned char ChannelPair)
{
    if ((FTM2_BASE_PTR == FTM_No)  && ChannelPair <= 2)
    {
        //FTM_PWM_Init(FTM_No, FTM_PWMMODE_COMBINE, FTM_PWM_HIGHTRUEPULSE);   /* inverting control should be used in combine mode */
        FTM_INVCTRL_REG(FTM_No) |= 1<<ChannelPair;
        if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_INVC_MASK) /* if PWM sync is needed */
        {
            if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_SWINVC_MASK) /* if software sync is needed*/
                FTM_SYNC_Software(FTM_No);  /* software sync */ 
            else if(FTM_SYNCONF_REG(FTM_No) & FTM_SYNCONF_HWINVC_MASK) /* if hardware sync is needed*/
                FTM_SYNC_Hardware(FTM_No, FTM_SYNC_TRIGGER_TRIGGER2);  /* hardware sync */ 
        }
        else  /* no need to sync, update on the next rising edge of system clock  */
        {
        }
    }
    else
       return FALSE;  /* only FTM2 has this register */ 
    return TRUE;
}  

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_Init
   *
   * @brief configure the FTM as specified control parameters
   *        
   * @param  
   *    FTM_No          pointer to one of three FTM base register address
   *    pFTM_Params     pointer to FTM general parameters
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FTM_Init(FTM_MemMapPtr FTM_No, TFTM_Params *pFTM_Params)
{
        if(FTM_No == FTM0_BASE_PTR)
        {
            SIM_SCGC |= SIM_SCGC_FTM0_MASK;
        }else if(FTM_No == FTM1_BASE_PTR)
        {
            SIM_SCGC |= SIM_SCGC_FTM1_MASK;
        }else{
            SIM_SCGC |= SIM_SCGC_FTM2_MASK;
        }
        
        // diable counter
    FTM_SC_REG(FTM_No) = 0; 
 	FTM_MODE_REG(FTM_No) = pFTM_Params->mode;       
	FTM_MOD_REG(FTM_No) = pFTM_Params->modulo;
	FTM_CNT_REG(FTM_No) = pFTM_Params->cnt;
        
        if(   FTM_MODE_REG(FTM_No)  & FTM_MODE_FTMEN_MASK  ) 
        {
          // when FTMEN = 1, all other registers can be written
          FTM_COMBINE_REG(FTM_No) = pFTM_Params->combine;      
          FTM_CNTIN_REG(FTM_No) = pFTM_Params->cntin;      
          FTM_SYNC_REG(FTM_No) = pFTM_Params->sync;      
          FTM_OUTINIT_REG(FTM_No) = pFTM_Params->outinit;      
          FTM_OUTMASK_REG(FTM_No) = pFTM_Params->outmask;      
          FTM_DEADTIME_REG(FTM_No) = pFTM_Params->deadtime;      
          FTM_EXTTRIG_REG(FTM_No) = pFTM_Params->exttrig;      
          FTM_POL_REG(FTM_No) = pFTM_Params->pol;      
          FTM_FMS_REG(FTM_No) = pFTM_Params->fms;      
          FTM_FILTER_REG(FTM_No) = pFTM_Params->filter;      
          FTM_FLTCTRL_REG(FTM_No) = pFTM_Params->fltctrl;    // fault control  
          FTM_FLTPOL_REG(FTM_No) = pFTM_Params->fltpol;      
          FTM_CONF_REG(FTM_No) = pFTM_Params->conf;      
          FTM_SYNCONF_REG(FTM_No) = pFTM_Params->synconf;      
          FTM_SWOCTRL_REG(FTM_No) = pFTM_Params->swoctrl;      
          FTM_PWMLOAD_REG(FTM_No) = pFTM_Params->pwmload;      
          
        }
        // write SC to enable clock
        FTM_SC_REG(FTM_No) = pFTM_Params->sc;
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FTM_Set_DutyCycle_Combine
   *
   * @brief set the FTM channel value register per duty cycle and modulo for combine mode
   *        odd channel no must be provided and even channel value register is not changed.
   * @param  
   *    FTM_No          pointer to one of three FTM base register address
   *    FTM_Channel     odd channel no
   *    dutyCycle       duty cycle in percentage. e.g. 10, means 10%
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void  FTM_Set_DutyCycle_Combine(FTM_MemMapPtr FTM_No, uint8 FTM_Channel, uint16 dutyCycle)
{
    uint16 cnv = FTM_CnV_REG(FTM_No,FTM_Channel-1);
    uint16 modulo = FTM_MOD_REG(FTM_No); 
    
    cnv += dutyCycle * modulo  / 100;
    if(cnv > modulo)
        cnv = modulo - 1;
    FTM_CnV_REG(FTM_No,FTM_Channel) = cnv ;    
    
    FTM_PWMLOAD_REG(FTM_No) |= FTM_PWMLOAD_LDOK_MASK | (1<<FTM_Channel);     /* enable channel match compare */
}
