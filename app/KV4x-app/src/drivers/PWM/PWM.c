#include "common.h"    // Common Kinetis defines
#include "PWM.h"
#include "main.h"

/*PWM SM0 init in comp mode*/
void pwm_init_sm0_comp(void)
{
  //Pin 93 - PortD0-FlexPWM_A0
  //Pin 94 - PortD1-FlexPWM_B0
  
  PORTD_PCR0 = PORT_PCR_MUX(6); //enables PWMA0 on D0 port
  PORTD_PCR1 = PORT_PCR_MUX(6); //enables PWMB0 on D1 port
  SIM_SCGC4 |= SIM_SCGC4_eFlexPWM0_MASK; //enable PWM clock
  
  /* Complementary PWM
   * Initialization Local Sync
   * Local force signal
   * Force enabled - force initializes the counter
   * Clock IP Bus
   * Local Reload */
  PWMA_SM0CTRL2 	= PWMA_CTRL2_FRCEN_MASK;

  PWMA_SM0CTRL 	|= PWMA_CTRL_LDFQ_MASK; //reload every 16 opportunity
  
  /*Defining Period*/
  PWMA_SM0INIT = -pwm_mod; //Since fast peripheral clock is 96Mhz (set in sysinit.c), if PWM_MOD=1000, PWMfreq=96M/2000=48KHz
  PWMA_SM0VAL0 = 0;	
  PWMA_SM0VAL1 = pwm_mod-1;  
          
  PWMA_SM0VAL2 = -step;
  PWMA_SM0VAL3 = -PWMA_SM0VAL2;
  
  /* dead time = 1us */
  PWMA_SM0DTCNT0 = pwm_mod*0.01;
  PWMA_SM0DTCNT1 = pwm_mod*0.01;
  
  /* disable all faults - if you want one of the FAULT0..7 pins disables the PWM0 A,B or C - set it accordingly  */
  PWMA_SM0DISMAP0 = 0;
 
  /*Enables Reload interrupt*/
  PWMA_SM0INTEN=PWMA_INTEN_RIE_MASK; 
  
  /* Enable output on PWMA_A0*/
  PWMA_OUTEN |= PWMA_OUTEN_PWMA_EN(1);
  
  /* Enable output on PWMA_B0*/
  PWMA_OUTEN |= PWMA_OUTEN_PWMB_EN(1);

  PWMA_MCTRL |= PWMA_MCTRL_CLDOK(1); /* Clear LDOK bits */ 

  PWMA_MCTRL |= PWMA_MCTRL_LDOK(1);  /* LDOK */
  PWMA_MCTRL |= PWMA_MCTRL_RUN(1);   /* Enable clock */ 
  
}

void pwm_init_sm1_push_pull(void)
{
  //Pin 93 - PortD2-FlexPWM_A1
  //Pin 94 - PortD3-FlexPWM_B1
  
  PORTD_PCR2 = PORT_PCR_MUX(6); //enables PWMA1 on D2 port
  PORTD_PCR3 = PORT_PCR_MUX(6); //enables PWMB1 on D3 port
  SIM_SCGC4 |= SIM_SCGC4_eFlexPWM1_MASK; //enable PWM clock
  
  /* independent PWM
   * Initialization Local Sync
   * Local force signal
   * Force enabled - force initializes the counter
   * Clock IP Bus
   * Local Reload */
  PWMA_SM1CTRL2 = PWMA_CTRL2_INDEP_MASK| PWMA_CTRL2_FRCEN_MASK;
  
  PWMA_SM1CTRL 	|= PWMA_CTRL_LDFQ_MASK; //reload every 16 opportunity

  /*Defining Period*/
  PWMA_SM1INIT = -pwm_mod; //Since fast peripheral clock is 96Mhz (set in sysinit.c),if PWM_MOD=1000, PWMfreq=96M/2000=48KHz
  PWMA_SM1VAL0 = 0;	
  PWMA_SM1VAL1 = pwm_mod-1;  
          
  PWMA_SM1VAL2 = -step;
  PWMA_SM1VAL3 = -PWMA_SM1VAL2; 
  
  PWMA_SM1VAL4 = pwm_mod+PWMA_SM1VAL2; 
  PWMA_SM1VAL5 = -PWMA_SM1VAL4; 
  
  /* dead time = 1us */
  PWMA_SM1DTCNT0 = pwm_mod*0.01;
  PWMA_SM1DTCNT1 = pwm_mod*0.01;
  
  /* disable all faults - if you want one of the FAULT0..7 pins disables the PWM0 A,B or C - set it accordingly  */
  PWMA_SM1DISMAP0 = 0;
 
  /*Enables Reload interrupt*/
  PWMA_SM1INTEN=PWMA_INTEN_RIE_MASK; 
    
  /* Enable output on PWMA_A1*/
  PWMA_OUTEN |= PWMA_OUTEN_PWMA_EN(2);
  
  /* Enable output on PWMA_B1*/
  PWMA_OUTEN |= PWMA_OUTEN_PWMB_EN(2);

  PWMA_MCTRL |= PWMA_MCTRL_CLDOK(2); /* Clear LDOK bits */ 

  PWMA_MCTRL |= PWMA_MCTRL_LDOK(2);  /* LDOK */
  PWMA_MCTRL |= PWMA_MCTRL_RUN(2);   /* Enable clock */ 
  
}