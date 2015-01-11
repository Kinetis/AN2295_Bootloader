/*
 * File:        sysinit.c
 * Purpose:     Kinetis Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 */

#include "common.h"
#include "sysinit.h"
#include "mcg.h"

/********************************************************************/
#define PLL_INIT 1             //1 if PLL needs to be initialized, external oscillator required

unsigned char mode;

void blpe();
void pee();


void sysinit (void)
{      
  
#if PLL_INIT        
    /* 
    pll_init(int crystal_val, unsigned char hgo_val, unsigned char erefs_val, signed char prdiv_val, 
              signed char vdiv_val, unsigned char mcgout_select)
    
    Parameters: crystal_val - 8MHz --external clock frequency in Hz either from a crystal or square
    *                           wave clock source
    *             hgo_val     - 1 -- High Gain mode - selects whether low power or high gain mode is selected
    *                           for the crystal oscillator. This has no meaning if an
    *                           external clock is used.
    *             erefs_val   - 1 -- selects external clock (=0) or crystal osc (=1)
    *             prdiv_val   - 1 -- value to divide the external clock source by to create the desired
    *                           PLL reference clock frequency
    *             vdiv_val    - 18 -- value to multiply the PLL reference clock frequency by 18
    *             mcgout_select  - 1 -- 0 if the PLL is just to be enabled, non-zero if the PLL is used
    *                              to provide the MCGOUT clock for the system.
   */
  //system/core clock = 144M, fast peripheral clock = 72M, bus/flash clock = 12M
  //SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1)|SIM_CLKDIV1_OUTDIV2(1)|SIM_CLKDIV1_OUTDIV4(3);
    
  //mode = pll_init(8000000,0,1,1,24,1);        //generating clock of 144MHz
  
  pee();
  //blpe();
  
 
 
#else
    //CLKS = 0b00 -- output of FLL or PLL selected
    //FRDIV = 0b000 -- external ref divisor
    //IREFS = 0b1 -- The slow internal reference clock is selected as the the reference clock source for the FLL.
    MCG_C1|= MCG_C1_IREFS_MASK;
    
    //DMX32 = 1 -- DCO is fine-tuned for maximum frequency with 32.768 kHz reference.
    //DRST_DRS = 0b11 -- DCO Range Select - High Range
    //FCTRIM, SCFTRIM -- trim values not overwritten
    MCG_C4|=MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS_MASK;
    
    //system/core clock = 96M, fast peripheral clock = 96M, bus/flash clock = 24M
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0)|SIM_CLKDIV1_OUTDIV2(0)|SIM_CLKDIV1_OUTDIV4(3); 
#endif  
    
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
}

void blpe()
{
  /* System clock initialization */
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=1,OUTDIV3=3,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |
                SIM_CLKDIV1_OUTDIV2(0x01) |
                SIM_CLKDIV1_OUTDIV4(0x03); /* Set the system prescalers to safe value */
  /* SIM_SCGC5: PORTE=1,PORTA=1 */
  SIM_SCGC5 |= (SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTA_MASK); /* Enable clock gate for ports to enable pin routing */
  if ((PMC_REGSC & PMC_REGSC_ACKISO_MASK) != 0x0U) {
    /* PMC_REGSC: ACKISO=1 */
    PMC_REGSC |= PMC_REGSC_ACKISO_MASK; /* Release IO pads after wakeup from VLLS mode. */
  }
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=0,OUTDIV4=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |
                SIM_CLKDIV1_OUTDIV2(0x00) |
                SIM_CLKDIV1_OUTDIV4(0x00); /* Update system prescalers */
  /* SIM_SOPT2: PLLFLLSEL=0 */
  //SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); /* Select FLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=3 */
  SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03); /* LPO 1kHz oscillator drives 32 kHz clock for various peripherals */
  /* PORTA_PCR18: ISF=0,MUX=0 */
  PORTA_PCR18 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTA_PCR19: ISF=0,MUX=0 */
  PORTA_PCR19 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* Switch to FBE Mode */
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
  MCG_C2 = (MCG_C2_RANGE(0x02) | MCG_C2_EREFS_MASK);
  /* OSC_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC_CR = OSC_CR_ERCLKEN_MASK;
  /* MCG_C7: OSCSEL=0 */
  //MCG_C7 &= (uint8_t)~(uint8_t)(MCG_C7_OSCSEL_MASK);
  /* MCG_C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x02) | MCG_C1_FRDIV(0x03) | MCG_C1_IRCLKEN_MASK);
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));
  /* MCG_C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  MCG_C5 = MCG_C5_PRDIV(0x00);
  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  MCG_C6 = MCG_C6_VDIV(0x00);
  while((MCG_S & MCG_S_OSCINIT0_MASK) == 0x00U) { /* Check that the oscillator is running */
  }
  while((MCG_S & MCG_S_IREFST_MASK) != 0x00U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to BLPE Mode */
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=1,LP=1,IRCS=0 */
  MCG_C2 = (MCG_C2_RANGE(0x02) | MCG_C2_EREFS_MASK | MCG_C2_LP_MASK);
  while((MCG_S & MCG_S_OSCINIT0_MASK) == 0x00U) { /* Check that the oscillator is running */
  }
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }

}

void pee()
{
   /* System clock initialization */
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=1,OUTDIV3=3,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |
                SIM_CLKDIV1_OUTDIV2(0x01) |
                SIM_CLKDIV1_OUTDIV4(0x03); /* Set the system prescalers to safe value */
  /* SIM_SCGC5: PORTA=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
  if ((PMC_REGSC & PMC_REGSC_ACKISO_MASK) != 0x0U) {
    /* PMC_REGSC: ACKISO=1 */
    PMC_REGSC |= PMC_REGSC_ACKISO_MASK; /* Release IO pads after wakeup from VLLS mode. */
  }
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=1,OUTDIV3=1,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |     //core clk = 96M
                SIM_CLKDIV1_OUTDIV2(0x01) |     //peripheral clk = 48M
                SIM_CLKDIV1_OUTDIV4(0x0F);      //flash and bus clk = 6M
  /* Update system prescalers */
  /* SIM_SOPT2: PLLFLLSEL=0 */
  //SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); /* Select FLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=3 */
  SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03); /* LPO 1kHz oscillator drives 32 kHz clock for various peripherals */
  /* PORTA_PCR18: ISF=0,MUX=0 */
  PORTA_PCR18 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTA_PCR19: ISF=0,MUX=0 */
  PORTA_PCR19 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* Switch to FBE Mode */
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
  MCG_C2 = (MCG_C2_RANGE(0x02) | MCG_C2_EREFS_MASK);
  /* OSC_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC_CR = OSC_CR_ERCLKEN_MASK;
  /* MCG_C7: OSCSEL=0 */
  //MCG_C7 &= (uint8_t)~(uint8_t)(MCG_C7_OSCSEL_MASK);
  /* MCG_C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x02) | MCG_C1_FRDIV(0x03) | MCG_C1_IRCLKEN_MASK);
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  //MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));
  /* MCG_C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=1 */
  //PLL output 8M
  MCG_C5 = MCG_C5_PRDIV(0x00);
  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=1 */
  MCG_C6 = MCG_C6_VDIV(0x01);
  while((MCG_S & MCG_S_OSCINIT0_MASK) == 0x00U) { /* Check that the oscillator is running */
  }
  while((MCG_S & MCG_S_IREFST_MASK) != 0x00U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to PBE Mode */
  /* MCG_C6: LOLIE0=0,PLLS=1,CME0=0,VDIV0=1 */
  //MCGPLLOUT = (8* VDIV)/2; 
  //VDIV = 0, MCGPLLOUT = 64M 
  //VDIV = 8, MCGPLLOUT = 96M 
  MCG_C6 = (MCG_C6_PLLS_MASK | MCG_C6_VDIV(0x08));
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  while((MCG_S & MCG_S_LOCK0_MASK) == 0x00U) { /* Wait until locked */
  }
  /* Switch to PEE Mode */
  /* MCG_C1: CLKS=0,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x00) | MCG_C1_FRDIV(0x03) | MCG_C1_IRCLKEN_MASK);
  while((MCG_S & 0x0CU) != 0x0CU) {    /* Wait until output of the PLL is selected */
  }
  
}

/********************************************************************/
void clkout_init(void)
{        
    /* Enable port C clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

    /* Select the flash clock output option for the CLKOUT pin */
    SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0x2);

    /* Enable the CLKOUT function on PTC3 (alt5 function) */
    PORTC_PCR3 = ( PORT_PCR_MUX(0x5)| PORT_PCR_DSE_MASK);
}
/********************************************************************/
