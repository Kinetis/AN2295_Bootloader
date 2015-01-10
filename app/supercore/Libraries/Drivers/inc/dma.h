
	/*****************************************************************************
 * (c) Copyright 2010-2013, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      dma.h
 * @version   1.0.3.0
 * @date      Feb-24-2013
 * @brief     Direct Memory Access (DMA) driver header file.
 *
 * Revision History:
 *  1.	27/08/2012   B41066   Initially written
 *  2.	04/01/2013   R55013   Optimized for fixed assignment to peripherals.
 *  3.	02/24/2012   R55013   Macros optimized using Basic I/O library
 ******************************************************************************/
#ifndef __DMA_H
#define __DMA_H

#include "sys.h"

//=====================================
//      DMA request sources Number
//=====================================
#define UART0_REV_DMAREQ  2
#define UART0_TRAN_DMAREQ 3
#define UART1_REV_DMAREQ  4
#define UART1_TRAN_DMAREQ 5
#define UART2_REV_DMAREQ  6
#define UART2_TRAN_DMAREQ 7
#define UART3_REV_DMAREQ  8
#define UART3_TRAN_DMAREQ 9
#define UART4_REV_DMAREQ  10
#define UART4_TRAN_DMAREQ 11
#define UART5_REV_DMAREQ  12
#define UART5_TRAN_DMAREQ 13
#define I2S0_REV_DMAREQ   14
#define I2S0_TRAN_DMAREQ  15
#define SPI0_REV_DMAREQ   16
#define SPI0_TRAN_DMAREQ  17
#define SPI1_REV_DMAREQ   18
#define SPI1_TRAN_DMAREQ  19
#define I2C0_DMAREQ       22
#define I2C1_DMAREQ       23
#define FTM0_CH0_DMAREQ   24
#define FTM0_CH1_DMAREQ   25
#define FTM0_CH2_DMAREQ   26
#define FTM0_CH3_DMAREQ   27
#define FTM0_CH4_DMAREQ   28
#define FTM0_CH5_DMAREQ   29
#define FTM0_CH6_DMAREQ   30
#define FTM0_CH7_DMAREQ   31
#define FTM1_CH0_DMAREQ   32
#define FTM1_CH1_DMAREQ   33
#define FTM2_CH0_DMAREQ   34
#define FTM2_CH1_DMAREQ   35
#define FTM3_CH0_DMAREQ   36
#define FTM3_CH1_DMAREQ   37
#define FTM3_CH2_DMAREQ   38
#define FTM1_CH3_DMAREQ   39  
#define ADC0_DMAREQ       40
#define ADC1_DMAREQ       41
#define CMP0_DMAREQ       42
#define CMP1_DMAREQ       43
#define CMP2_DMAREQ       44
#define DAC0_DMAREQ       45
#define DAC1_DMAREQ       46
#define CMT_DMAREQ        47
#define PDB_DMAREQ        48
#define PORTA_DMAREQ      49
#define PORTB_DMAREQ      50
#define PORTC_DMAREQ      51
#define PORTD_DMAREQ      52
#define PORTE_DMAREQ      53
#define FTM3_CH4_DMAREQ   54
#define FTM3_CH5_DMAREQ   55
#define FTM3_CH6_DMAREQ   56
#define FTM3_CH7_DMAREQ   57
   
#define DMA_MUX0          60
#define DMA_MUX1          61
#define DMA_MUX2          62
#define DMA_MUX3          63
#define DMA_SOFTWARE_TRIGGER   80
// Souce Size
#define DMA_SRC_8BIT   (1)
#define DMA_SRC_16BIT  (2)
#define DMA_SRC_32BIT  (0)

//Dest Size
#define DMA_DST_8BIT   (1)
#define DMA_DST_16BIT  (2)
#define DMA_DST_32BIT  (0)

   
#define  DMA_CH0    (uint8_t)(0)
#define  DMA_CH1    (uint8_t)(1)
#define  DMA_CH2    (uint8_t)(2)
#define  DMA_CH3    (uint8_t)(3)   
   
	 
//DMA IT source
#define DMA_IT_MAJOR     (uint16_t)(1)
//   DMA Init struct 
typedef struct 
{
	  //dma param
    uint8_t  Channelx;           //DMA Chl
    uint8_t  PeripheralDMAReq;   //DMA Req Source
    uint32_t BytesToTransfer;     
    FunctionalState EnableState; 
    FunctionalState PeriodicModeState; //if use periodic trigger mode ()
    FunctionalState CycleStealState;
    // src param
    uint32_t SourceBaseAddr ;    
    uint16_t SourceDataSize ;    
    FunctionalState  SourceInc;     
    // dest param
    uint32_t DestBaseAddr ;         
    uint16_t DestDataSize ;         
    FunctionalState  DestInc;  
}DMA_InitTypeDef;

/*    API functions   */
void DMA_Init(DMA_InitTypeDef *DMA_InitStruct);
uint8_t DMA_IsComplete(uint8_t DMAChl);
void DMA_ITConfig(uint16_t DMA_IT, uint8_t DMA_CH, FunctionalState NewState);
void DMA_ClearITPendingBit(uint16_t DMA_IT, uint8_t DMA_CH);

#ifdef __cplusplus
}
#endif

#endif


