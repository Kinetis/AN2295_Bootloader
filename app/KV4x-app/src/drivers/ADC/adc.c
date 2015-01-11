#include "common.h"
#include "adc.h"

/*ADC init in differential mode - software triggered - parallel Simultaneous*/
void InitADC()
{
  SIM_SCGC5 |= SIM_SCGC5_ADC_MASK;
  
  ADC_CLIST1 = ADC_CLIST1_SAMPLE0(4)|ADC_CLIST1_SAMPLE1(6);
  ADC_CLIST3 = ADC_CLIST1_SAMPLE0(12)|ADC_CLIST1_SAMPLE1(14);
   
  ADC_SDIS = 0xFCFC;
  
  /* ADC_CTRL1: DMAEN0=0,STOP0=1,START0=0,SYNC0=0,EOSIE0=1,ZCIE=0,LLMTIE=0,HLMTIE=0,CHNCFG_L=0,??=0,SMODE=1 */
  ADC_CTRL1 = ADC_CTRL1_STOP0_MASK|ADC_CTRL1_EOSIE0_MASK|ADC_CTRL1_SMODE(1);
  
  /* ADC_CTRL2: DMAEN1=0,STOP1=1,START1=0,SYNC1=0,EOSIE1=0,CHNCFG_H=0b1111,SIMULT=1,DIV0=5 */
  ADC_CTRL2 = ADC_CTRL2_STOP1_MASK|ADC_CTRL2_SIMULT_MASK|ADC_CTRL2_CHNCFG_H_MASK|ADC_CTRL2_DIV0(0x30);
  
  /* ADC_PWR: ASB=0,??=0,??=0,??=0,PSTS1=0,PSTS0=0,PUDELAY=0x0D,APD=0,??=0,PD1=0,PD0=0 */
  ADC_PWR = ADC_PWR_PUDELAY(0x0D);
  
 /* ADC_ZXSTAT: ZCS=0xFFFF */
  ADC_ZXSTAT = ADC_ZXSTAT_ZCS(0xFFFF); /* Clear zero crossing status flags */
  
  /* ADC_LOLIMSTAT: LLS=0xFFFF */
  ADC_LOLIMSTAT = ADC_LOLIMSTAT_LLS(0xFFFF); /* Clear low limit status */
  
  /* ADC_HILIMSTAT: HLS=0xFFFF */
  ADC_HILIMSTAT = ADC_HILIMSTAT_HLS(0xFFFF); /* Clear high limit status */
  
  /* ADC_STAT: CIP0=0,CIP1=0,??=0,EOSI1=1,EOSI0=1,ZCI=0,LLMTI=0,HLMTI=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  ADC_STAT = ADC_STAT_EOSI1_MASK | ADC_STAT_EOSI0_MASK; /* Clear EOSI and EOSI1 flags */
  
  /* ADC_PWR2: ??=0,??=0,DIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  ADC_PWR2 = ADC_PWR2_DIV1(0x00); /* Set Power 2 */ 
  
  /* wait for ADC to power up */
  while(ADC_PWR & (ADC_PWR_PSTS0_MASK|ADC_PWR_PSTS1_MASK)){};
  
  ADC_CTRL1 &= ~ADC_CTRL1_STOP0_MASK;
  ADC_CTRL1 |= ADC_CTRL1_START0_MASK;
}

/***********************************************************************************
ADC init in single ended parallel mode (2 channels per module), software triggered
***********************************************************************************/
void adc_init_single_parallel()
{
    SIM_SCGC5 |= SIM_SCGC5_ADC_MASK;      //ADC clk enable
    
    ADC_CLIST1 = ADC_CLIST1_SAMPLE0(0)
               | ADC_CLIST1_SAMPLE1(1)
               | ADC_CLIST1_SAMPLE2(2)
               | ADC_CLIST1_SAMPLE3(3);

                 
     ADC_CLIST2 = ADC_CLIST2_SAMPLE4(4)
               | ADC_CLIST2_SAMPLE5(5)
               | ADC_CLIST2_SAMPLE6(6)
               | ADC_CLIST2_SAMPLE7(7);

                 
    ADC_CLIST3 = ADC_CLIST3_SAMPLE8(8)
               | ADC_CLIST3_SAMPLE9(9)
               | ADC_CLIST3_SAMPLE10(10)
               | ADC_CLIST3_SAMPLE11(11);
    ADC_CLIST4 = ADC_CLIST4_SAMPLE12(12)
               | ADC_CLIST4_SAMPLE13(13)
               | ADC_CLIST4_SAMPLE14(14)
               | ADC_CLIST4_SAMPLE15(15);

    
    ADC_SDIS = 0x0000;    //enable  samples
    

    ADC_CTRL1 = ADC_CTRL1_STOP0_MASK|ADC_CTRL1_EOSIE0_MASK|ADC_CTRL1_SMODE(1);
   

    ADC_CTRL2 = ADC_CTRL2_STOP1_MASK|ADC_CTRL2_SIMULT_MASK|ADC_CTRL2_DIV0(0);

    ADC_PWR = ADC_PWR_PUDELAY(0x0D) ;//| ADC_PWR_APD_MASK;
    
    ADC_ZXSTAT = ADC_ZXSTAT_ZCS(0xFFFF); /* Clear zero crossing status flags */
    
    /* ADC_LOLIMSTAT: LLS=0xFFFF */
    ADC_LOLIMSTAT = ADC_LOLIMSTAT_LLS(0xFFFF); /* Clear low limit status */
  
    /* ADC_HILIMSTAT: HLS=0xFFFF */
    ADC_HILIMSTAT = ADC_HILIMSTAT_HLS(0xFFFF); /* Clear high limit status */
    
//    SIM_ADCOPT &= ~(0x02000000);                /*ADC clock use the fast peripherial clock*/
//    SIM_ADCOPT &= ~(0x01000000);                /*disable the low current mode*/
//    SIM_ADCOPT &= ~(0x00007000);                /*Select the ADCB7_A*/
//    SIM_ADCOPT &= ~(0x00000700);                /*Select the ADCB6_A*/
//    
//    SIM_ADCOPT &= ~(0x00000070);                /*Select the ADCA7_A*/
//    SIM_ADCOPT &= ~(0x00000007);                /*Select the ADCA6_A*/
    
  
    /* ADC_STAT: CIP0=0,CIP1=0,??=0,EOSI1=1,EOSI0=1,ZCI=0,LLMTI=0,HLMTI=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    ADC_STAT = ADC_STAT_EOSI1_MASK | ADC_STAT_EOSI0_MASK; /* Clear EOSI and EOSI1 flags */
    
  
    ADC_PWR2 = ADC_PWR2_DIV1(0x50)|ADC_PWR2_SPEEDA(0)|ADC_PWR2_SPEEDB(0); /* Set Power 2 */ 
    /* wait for ADC to power up */
    while(ADC_PWR & (ADC_PWR_PSTS0_MASK|ADC_PWR_PSTS1_MASK)){};
  
    ADC_CTRL1 &= ~ADC_CTRL1_STOP0_MASK; //clearing ADC stop bit
    
    ADC_CTRL1 |= ADC_CTRL1_START0_MASK;//start ADC

}

/*adc init for single module, hardware triggered, 4 channels, scan halt after 2 channels*/
void adc_init_single_scanhalt()
{
   SIM_SCGC5 |= SIM_SCGC5_ADC_MASK;//ADC clk enable
  
  /* Configuring ANA0, ANA1, ANA2 and ANA3 for ADCA*/
  ADC_CLIST1 = ADC_CLIST1_SAMPLE0(0)|ADC_CLIST1_SAMPLE1(1)|ADC_CLIST1_SAMPLE2(2)|ADC_CLIST1_SAMPLE3(3);
   
  ADC_SDIS = 0xFFF0;    //enable 4 samples
  
  /* ADC_CTRL1: DMAEN0=0,STOP0=1,START0=0,SYNC0=1,EOSIE0=1,ZCIE=0,LLMTIE=0,HLMTIE=0,CHNCFG_L=0,??=0,SMODE=4 */
 ADC_CTRL1 = ADC_CTRL1_STOP0_MASK|ADC_CTRL1_SYNC0_MASK|ADC_CTRL1_EOSIE0_MASK|ADC_CTRL1_SMODE(4);
  
  /* ADC_CTRL2: DMAEN1=0,STOP1=1,START1=0,SYNC1=0,EOSIE1=0,CHNCFG_H=0,SIMULT=0,DIV0=0x30 */
  ADC_CTRL2 = ADC_CTRL2_STOP1_MASK|ADC_CTRL2_DIV0(0x9);
  
  /* ADC_PWR: ASB=0,??=0,??=0,??=0,PSTS1=0,PSTS0=0,PUDELAY=0x0D,APD=0,??=0,PD1=0,PD0=0 */
  ADC_PWR = ADC_PWR_PUDELAY(0x0D);
  
 /* ADC_ZXSTAT: ZCS=0xFFFF */
  ADC_ZXSTAT = ADC_ZXSTAT_ZCS(0xFFFF); /* Clear zero crossing status flags */
  
  /* ADC_LOLIMSTAT: LLS=0xFFFF */
  ADC_LOLIMSTAT = ADC_LOLIMSTAT_LLS(0xFFFF); /* Clear low limit status */
  
  /* ADC_HILIMSTAT: HLS=0xFFFF */
  ADC_HILIMSTAT = ADC_HILIMSTAT_HLS(0xFFFF); /* Clear high limit status */
  
  /* ADC_STAT: CIP0=0,CIP1=0,??=0,EOSI1=1,EOSI0=1,ZCI=0,LLMTI=0,HLMTI=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  ADC_STAT = ADC_STAT_EOSI1_MASK | ADC_STAT_EOSI0_MASK; /* Clear EOSI and EOSI1 flags */
  
    /* ADC_PWR2: ??=0,??=0,DIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  ADC_PWR2 = ADC_PWR2_DIV1(0x00);           /* Set Power 2 */ 
  
  ADC_SCTRL = ADC_SCTRL_SC(0x4);          //pausing scan on sample 3, to wait for next sync input
  
  ADC_SCHLTEN = ADC_SCHLTEN_SCHLTEN(0x2);          //taking interrupt after completion of second sample

  /* wait for ADC to power up */
  while(ADC_PWR & (ADC_PWR_PSTS0_MASK|ADC_PWR_PSTS1_MASK)){};

  ADC_CTRL1 &= ~ADC_CTRL1_STOP0_MASK;           //clearing ADC stop bit
}