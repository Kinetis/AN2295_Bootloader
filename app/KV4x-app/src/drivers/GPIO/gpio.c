#include "common.h"
#include "gpio.h"

void gpio_set_as_input(void)
{
  PORTE_PCR29 = PORT_PCR_MUX(1) ;      
  PORTE_DFER = 0x20000000;
  
  GPIOE_PCOR |= 0x20000000;              // initial out low 
  GPIOE_PDDR &= ~0x20000000;              // output enable   
}

void gpio_set_as_output(void)
{
  PORTE_PCR30 = PORT_PCR_MUX(1) ;   
  PORTE_PCR24 = PORT_PCR_MUX(1) ;  
  
  PORTE_PCR20 = PORT_PCR_MUX(1) ; 
  PORTE_PCR26 = PORT_PCR_MUX(1) ; 
  
  GPIOE_PCOR |= 0x61000000;              // initial out low 
  GPIOE_PDOR = 0;
  GPIOE_PDDR |= 0x41000000;              // GE24 and GE30 output enable 
  
  PORTC_PCR18 = PORT_PCR_MUX(1) ;       //GC18 set as GPIO 
  PORTC_PCR17 = PORT_PCR_MUX(1) ;       //GC17 set as GPIO 
  GPIOC_PCOR |= 0x000000;              // initial out low 
  GPIOC_PDDR |= 0x060000;              // GC18 output enable
                
}