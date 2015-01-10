/**
  ******************************************************************************
  * @file    spi.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   超核K60固件库 SPI模块驱动
  ******************************************************************************
  */
#ifndef __SPI_H_
#define	__SPI_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "sys.h"

	 
#define SPI0_CS_PC04_SCK_PC05_MOSI_PC06_MISO_PC07   (0x10890U)  
#define SPI0_CS_PD00_SCK_PD01_MOSI_PD02_MISO_PD03   (0x10098U)  
#define SPI1_CS_PD04_SCK_PD05_MOSI_PD06_MISO_PD07   (0x10899U)
#define SPI1_CS_PE04_SCK_PE02_MOSI_PE01_MISO_PE03   (0x102A1U)  
#define SPI0_CS_PA14_SCK_PA15_MOSI_PA16_MISO_PA17   (0x11C80U) 
#define SPI0_USER_DEFINE                            (0x0U)
#define SPI1_USER_DEFINE                            (0x1U)

	 
#define SPI_BaudRatePrescaler_2         ((uint16_t)0x0000)
#define SPI_BaudRatePrescaler_4         ((uint16_t)0x0001)
#define SPI_BaudRatePrescaler_8         ((uint16_t)0x0002)
#define SPI_BaudRatePrescaler_16        ((uint16_t)0x0003)
#define SPI_BaudRatePrescaler_32        ((uint16_t)0x0004)
#define SPI_BaudRatePrescaler_64        ((uint16_t)0x0005)
#define SPI_BaudRatePrescaler_128       ((uint16_t)0x0006)
#define SPI_BaudRatePrescaler_256       ((uint16_t)0x0007)
#define SPI_BaudRatePrescaler_512       ((uint16_t)0x0008)
#define SPI_BaudRatePrescaler_1024      ((uint16_t)0x0009)
#define SPI_BaudRatePrescaler_2048      ((uint16_t)0x000A)

#define SPI_Mode_Master                 ((uint16_t)0x0001)
#define SPI_Mode_Slave                  ((uint16_t)0x0002)
//CPHA
#define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
#define SPI_CPHA_2Edge                  ((uint16_t)0x0001)
//CPOL
#define SPI_CPOL_Low                    ((uint16_t)0x0000)
#define SPI_CPOL_High                   ((uint16_t)0x0002)

#define SPI_PCS_Asserted                ((uint16_t)0x0000)
#define SPI_PCS_Inactive                ((uint16_t)0x0001)

//MSB OR LSB
#define SPI_FirstBit_MSB                ((uint16_t)0x0000)
#define SPI_FirstBit_LSB                ((uint16_t)0x0001)
	 
#define SPI_DMAReq_Tx  (uint16_t)(0)
#define SPI_DMAReq_Rx  (uint16_t)(1)

typedef struct
{
  uint32_t SPIxMap;                       //数据端口      
  uint8_t  SPI_DataSize;                  //数据长度
  uint8_t  SPI_CPOL;                      //片选极性
  uint8_t  SPI_Mode;                      //主模式还是从模式
  uint8_t  SPI_CPHA;                      //时钟相位
  uint16_t SPI_BaudRatePrescaler;         //分频数
  uint16_t SPI_FirstBit;                  //MSB or LSB
}SPI_InitTypeDef;

//本构件实现的接口函数列表
void SPI_Init(SPI_InitTypeDef* SPI_InitStruct);
void SPI_DMACmd(SPI_Type *SPIx, uint16_t SPI_DMAReq, FunctionalState NewState);
void SPI_Cmd(SPI_Type *SPIx, FunctionalState NewState);
uint16_t SPI_ReadWriteByte(SPI_Type *SPIx, uint16_t Data);


#ifdef __cplusplus
}
#endif

#endif
