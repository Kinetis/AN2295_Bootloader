#include "common.h"
#include "dac.h"

void dac_init()
{
  SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;
  
  //PTE30--DAC0_OUT
  PORTE_PCR30 = PORT_PCR_MUX(0);
  
  DAC_DAT0L = 0xFF;
  DAC_DAT0H = 0x7;

  DAC_C0 = DAC_C0_DACSWTRG_MASK;
  DAC_C1 = 0;
  DAC_C2 =0x0;

  DAC_C0 = DAC_C0_DACEN_MASK;
}

void dac_buffer_normal_init()
{
  SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;
  
  //PTE30--DAC0_OUT
  PORTE_PCR30 = PORT_PCR_MUX(0);
  
  DAC_DAT0L = 0xFF;
  DAC_DAT0H = 0x1;
  DAC_DAT1H = 0x2;
  DAC_DAT2H = 0x3;
  DAC_DAT3H = 0x4;
  DAC_DAT4H = 0x5;
  DAC_DAT5H = 0x6;
  DAC_DAT6H = 0x7;
  DAC_DAT7H = 0x8;
  DAC_DAT8H = 0x9;
  DAC_DAT9H = 0xa;
  DAC_DAT10H = 0xb;
  DAC_DAT11H = 0xc;
  DAC_DAT12H = 0xd;
  DAC_DAT13H = 0xe;
  DAC_DAT14H = 0xf;
  DAC_DAT15H = 0;
  
  DAC_C0 = DAC_C0_DACTRGSEL_MASK;               //software trigger selected
  DAC_C1 = DAC_C1_DACBFEN_MASK;                 //DAC Buffer Enable
  DAC_SR &= ~DAC_SR_DACBFRPTF_MASK;             //DAC Buffer Read Pointer Top Position Flag
  DAC_C2 =0x0F;

  DAC_C0 |= DAC_C0_DACEN_MASK;                  //DAC Enable
}