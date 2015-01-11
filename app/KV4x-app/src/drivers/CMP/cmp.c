#include "cmp.h"
#include "common.h"

void cmp0_init()
{
  SIM_SCGC4 |= SIM_SCGC4_CMP_MASK;
  
  PORTB_PCR20 = PORT_PCR_MUX(6) ;               //configuring PTB20 as CMP0_OUT
  
  CMP0_CR0 = CMP_CR0_FILTER_CNT(4);             //Filter Sample Count -- 4 consecutive samples must agree
  CMP0_CR1 = CMP_CR1_OPE_MASK;                  //Comparator Output Pin Enable, Sample Enable
  CMP0_DACCR = CMP_DACCR_VOSEL(3);             //DACO = (V in /64) * (VOSEL[5:0] + 1) -- vin/2  = 3.3/2 = 1.65V.
  CMP0_DACCR |= CMP_DACCR_DACEN_MASK;
  CMP0_MUXCR = CMP_MUXCR_PSEL(5);               //CMMP0_IN5 -- PTE29 taken as Positive input
  CMP0_MUXCR|= CMP_MUXCR_MSEL(7);               //6-bit DAC taken as negative input
  
  CMP0_CR1 |= CMP_CR1_EN_MASK;                  
}