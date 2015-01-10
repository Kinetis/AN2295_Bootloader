/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       adc_test.c
\brief      configure the adc for single end mode, and software trigger. PDB enabled for ADC triggering
\author     FSL
\version    1.0
\date       Sep 29 2011
*/


#include "common.h"
#include "adc16.h"
#include "adc_test.h"
#include "global.h"

#define MAX_SAMPLES   128u

#define ADC_POT_CHANNEL 18  //ADC0_DM3  single


#define BITS32    2
#define BITS16    1
#define BITS8     0



/******************************************************************************* 
*  Global variables
*******************************************************************************/

int intnum, channel_no;
char buffer_adc;   //If buffer_adc = 0x80 flag of data ready  bit0 for buffer_adc selection
char adc_reading_channel;
char last_adc_channel;


unsigned char foobar=0x00;    // ".data" variable example
int isr_flag, dma_error = 0;


//globle variables
tADC_Config Master_Adc_Config;  
tADC_Cal_Blk CalibrationStore[2];
uint16 adc_sample0;
uint16 adc_sample1;  
uint16 DMA_errorCount;
uint16 dmaIsrCount;

uint32 adc_buffer_adc[256];



// Prototypes
void adc_init(void);


/**   adc_init
 * \brief    initialize and calibrate ADC0 module
 * \brief    48MHz IPBus clock; ADC clock = 48M/2/8 = 3MHz
 * \brief    Total conversion time: 56N+4ADCK
 * \brief    given sampling rate Fs = 6.4K, 156us/sample,  156*3= 468 ADCK
 * \author   FSL
 * \param    none
 * \return   none
 * \warning  assumes 48MHz IPBus clock
 */ 
void adc_init(void)
{
  
   uint8_t cal_ok;
 
   SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
#ifdef CMSIS
   NVIC_EnableIRQ(ADC0_IRQn);
#else
   enable_irq(INT_ADC0 - 16);
#endif
     
  /* 48MHz IPBus clock
   * ADC clock = 48M/2/8 = 3MHz
   * Total conversion time: 56N+4ADCK
   * Given sampling rate Fs = 6.4K, 156us/sample,  156*3= 468 ADCK
   * the maximum h/w average number = 8
   * use h/w average number = 4
   * Total conversion time: 56*4+4 = 228 ADC clocks,76us
   * There are 468-228 = 240 ADC clocks (ie. 80us) free for post processing
   */


 // Initialize ADC0
  // Do calibration first with 32 h/w averages
  Master_Adc_Config.CONFIG1  = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_8) | ADLSMP_LONG | ADC_CFG1_MODE(MODE_16)
                              | ADC_CFG1_ADICLK(ADICLK_BUS_2);  
  Master_Adc_Config.CONFIG2  = MUXSEL_ADCA | ADACKEN_ENABLED | ADHSC_HISPEED | ADC_CFG2_ADLSTS(ADLSTS_20) ;
  Master_Adc_Config.COMPARE1 = 0x1234u ; 
  Master_Adc_Config.COMPARE2 = 0x5678u ;
  Master_Adc_Config.STATUS2  = ADTRG_SW | ACFE_DISABLED | ACFGT_GREATER | ACREN_ENABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT);
  Master_Adc_Config.STATUS3  = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_32);
 // Master_Adc_Config.PGA      = PGAEN_DISABLED | PGACHP_NOCHOP | PGALP_NORMAL | ADC_PGA_PGAG(PGAG_64);
  Master_Adc_Config.STATUS1A = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31);       
  Master_Adc_Config.STATUS1B = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31);  
  
  ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // config ADC
  cal_ok = ADC_Cal(ADC0_BASE_PTR);                    // do the calibration
  if (cal_ok != 0) printf("ADC calibration error");
  ADC_Read_Cal(ADC0_BASE_PTR,&CalibrationStore[1]);   // store the cal
  
  // Now do normal ADC configuration with 4 h/w averages and h/w trigger from PDB
  Master_Adc_Config.CONFIG1  = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_8) | ADLSMP_LONG | ADC_CFG1_MODE(MODE_12)
                              | ADC_CFG1_ADICLK(ADICLK_BUS_2);  
  Master_Adc_Config.CONFIG2  = MUXSEL_ADCB | ADACKEN_ENABLED | ADHSC_HISPEED | ADC_CFG2_ADLSTS(ADLSTS_20) ;
  Master_Adc_Config.COMPARE1 = 0x1234u ; 
  Master_Adc_Config.COMPARE2 = 0x5678u ;
  Master_Adc_Config.STATUS2  = !ADTRG_HW | ACFE_DISABLED | ACFGT_GREATER | ACREN_DISABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT);
  Master_Adc_Config.STATUS3  = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_4);
//  Master_Adc_Config.PGA      = PGAEN_DISABLED | PGACHP_NOCHOP | PGALP_NORMAL | ADC_PGA_PGAG(PGAG_64);

  Master_Adc_Config.STATUS1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(31);                                                               
  Master_Adc_Config.STATUS1B = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(31);    

  ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // config the ADC again to default conditions    
 
}

uint16 adc_read(uint8 channel)
{
  
   ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(channel) ;     // start conversion
   while((ADC0_SC1A & ADC_SC1_COCO_MASK)!= 0){};
   return ADC0_RA;
}


/**   adc0_isr,
 * \brief    reads the results of the Adc conversion
 * \brief    values is stored in a global variable  adc_sample0, adc_sample1
 * \author   FSL
 * \param    none
 * \return   none
 * \warning  
 */ 
void adc0_isrv(void){


  if((ADC0_SC1A & ADC_SC1_COCO_MASK)!= 0){
    adc_sample0 = ADC0_RA;
  }
 
  if((ADC0_SC1B & ADC_SC1_COCO_MASK)!= 0){
    adc_sample = ADC0_RB;
  }
     
}


