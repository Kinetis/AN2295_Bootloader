#include "common.h"    // Common Kinetis defines
#include "FTM.h"

/*FTM init function*/
void ftm_init(void)
{
  
    // enable the clock for FTM0 
    SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;

    FTM0_MODE |= FTM_MODE_WPDIS_MASK; // Disable write protection for certain registers
    FTM0_MODE |= FTM_MODE_FTMEN_MASK; // all registers are available
     
    // Set PWM frequency;
    FTM0_MOD = 10000;
    FTM0_CNTIN = 0;

    // for center aligned PWM using combine mode:

    /* COMBINE = 1 - combine mode set
    COMP = 1 - complementary PWM set*/
    FTM0_COMBINE =    FTM_COMBINE_COMP0_MASK    | FTM_COMBINE_COMBINE0_MASK| FTM_COMBINE_DTEN0_MASK
                | FTM_COMBINE_COMP1_MASK    | FTM_COMBINE_COMBINE1_MASK| FTM_COMBINE_DTEN1_MASK
                | FTM_COMBINE_COMP2_MASK   | FTM_COMBINE_COMBINE2_MASK| FTM_COMBINE_DTEN2_MASK
                  | FTM_COMBINE_COMP3_MASK   | FTM_COMBINE_COMBINE3_MASK| FTM_COMBINE_DTEN3_MASK;

    // Dead time
    FTM0_DEADTIME = 63;
    
    // Initial setting of value registers to 50 % of duty cycle 
    FTM0_C0V = 2500; 
    FTM0_C1V = 7500 ;
    FTM0_C2V = 2500;
    FTM0_C3V = 7500 ;
    FTM0_C4V = 2500;
    FTM0_C5V = 7500 ;
    FTM0_C6V = 2500;
    FTM0_C7V =  7500 ;

    FTM0_C0SC |= FTM_CnSC_ELSB_MASK ; //high true pulses
    FTM0_C1SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C2SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C3SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C4SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C5SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C6SC |= FTM_CnSC_ELSB_MASK ;
    FTM0_C7SC |= FTM_CnSC_ELSB_MASK ;

    FTM0_PWMLOAD = FTM_PWMLOAD_LDOK_MASK ;  //LDOK bit set to apply changes in FTM registers

    FTM0_MODE |= FTM_MODE_INIT_MASK; //channels output is initialized

    // Set system clock as source for FTM0 (CLKS[1:0] = 01) 
    FTM0_SC |= FTM_SC_CLKS(1);  

    //PORT for FTM0 initialization   
    // Note: Clock for Port C anc D enabled already 

    PORTD_PCR0 = PORT_PCR_MUX(5); // FTM0 CH0,PTD0
    PORTD_PCR1 = PORT_PCR_MUX(5); // FTM0 CH1,PTD1
    PORTD_PCR2 = PORT_PCR_MUX(5); // FTM0 CH2,PTD2
    PORTD_PCR3 = PORT_PCR_MUX(5); // FTM0 CH3,PTD3
    PORTD_PCR4 = PORT_PCR_MUX(4); // FTM0 CH4,PTD4
    PORTD_PCR5 = PORT_PCR_MUX(4); // FTM0 CH5,PTD5
    PORTD_PCR6 = PORT_PCR_MUX(4); // FTM0 CH6,PTD6
    PORTD_PCR7 = PORT_PCR_MUX(4); // FTM0 CH7,PTD7
}