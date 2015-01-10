/**
  ******************************************************************************
  * @file    spi.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   超核K60固件库 SPI模块驱动
  ******************************************************************************
  */
#include "spi.h"

/***********************************************************************************************
 功能：SPI 初始化
 形参：SPI_InitStruct SPI 初始化结构
 返回：0
 详解：0
************************************************************************************************/
void SPI_Init(SPI_InitTypeDef* SPI_InitStruct)
{
	uint8_t i;
  SPI_Type *SPIx = NULL;
  PeripheralMapTypeDef *pSPI_DataMap = (PeripheralMapTypeDef*)&(SPI_InitStruct->SPIxMap);
 //  Open SPI gate clock  
  switch(pSPI_DataMap->m_ModuleIndex)
  {
    case 0:
      SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;  
      SPIx = SPI0;
      break;
    case 1:
      SIM->SCGC4 |= SIM_SCGC4_SPI1_MASK;  
      SPIx = SPI1;
      break;
    default:break;     
  }
  //  config buadrate     
  SPIx->BR = (SPI_BR_SPR(SPI_InitStruct->SPI_BaudRatePrescaler)|SPI_BR_SPPR(1));
  //  config master or slave mode 
  (SPI_InitStruct->SPI_Mode == SPI_Mode_Master)?(SPIx->C1  |= SPI_C1_MSTR_MASK):(SPIx->C1  &= ~SPI_C1_MSTR_MASK);
  //  config CPHA                 
  (SPI_InitStruct->SPI_CPHA == SPI_CPHA_1Edge)?(SPIx->C1  |= SPI_C1_CPHA_MASK):(SPIx->C1  &= ~SPI_C1_CPHA_MASK);
  //  config CPOL                 
  (SPI_InitStruct->SPI_CPOL == SPI_CPOL_High)?(SPIx->C1  |= SPI_C1_CPOL_MASK):(SPIx->C1  &= ~SPI_C1_CPOL_MASK);
  //  config MSB or LSB           
  (SPI_InitStruct->SPI_FirstBit == SPI_FirstBit_LSB)?(SPIx->C1  |= SPI_C1_LSBFE_MASK):(SPIx->C1  &= ~SPI_C1_LSBFE_MASK);
  // config SS as PCS0 output    
  SPIx->C2 |= SPI_C2_MODFEN_MASK;
  SPIx->C1 |= SPI_C1_SSOE_MASK;
  //  enable spi moudle        
  SPIx->C1 |= SPI_C1_SPE_MASK; 
	//  config PinMux
	for(i=0;i<pSPI_DataMap->m_PinCntIndex;i++)
	{
		PinMuxConfig(pSPI_DataMap->m_PortIndex,pSPI_DataMap->m_PinBaseIndex+i,pSPI_DataMap->m_MuxIndex);
	}
}


uint16_t SPI_ReadWriteByte(SPI_Type *SPIx, uint16_t Data)
{
  uint8_t temp;
  while(!(SPIx->S & SPI_S_SPTEF_MASK)); /* write finish? */
	#ifdef MKL46Z4_H_
	SPIx->DL = Data;
	#endif
	#ifdef MKL25Z4_H_
	SPIx->D = Data;
	#endif
  
  while(!(SPIx->S & SPI_S_SPRF_MASK)); /* read finish? */
	#ifdef MKL46Z4_H_
	temp = SPIx->DL;
	#endif
	#ifdef MKL25Z4_H_
	temp = SPIx->D;
	#endif
  
  return temp;
}


//Start or stop SPI engine
void SPI_Cmd(SPI_Type *SPIx, FunctionalState NewState)
{
  if(NewState == ENABLE)
  {
    SPIx->C1 |= SPI_C1_SPE_MASK; 
  }
  else
  {
    SPIx->C1 &= ~SPI_C1_SPE_MASK;
  }
}

//SPI DMA enable config
void SPI_DMACmd(SPI_Type *SPIx, uint16_t SPI_DMAReq, FunctionalState NewState)
{
  switch(SPI_DMAReq)
  {
    case SPI_DMAReq_Tx:
      (ENABLE == NewState)?(SPIx->C2 |= SPI_C2_TXDMAE_MASK):(SPIx->C2 &= ~SPI_C2_RXDMAE_MASK);
    break;
    case SPI_DMAReq_Rx:
      (ENABLE == NewState)?(SPIx->C2 |= SPI_C2_RXDMAE_MASK):(SPIx->C2 &= ~SPI_C2_RXDMAE_MASK);
    break;
    default:break;
  }
}

/*
static const PeripheralMapTypeDef I2C_Check_Maps[] = 
{ 
    {0, 2, 2,  4, 4}, //SPI0_CS_PC04_SCK_PC05_MOSI_PC06_MISO_PC07
    {0, 3, 2,  0, 4}, //SPI0_CS_PD00_SCK_PD01_MOSI_PD02_MISO_PD03
    {1, 3, 2,  4, 4}, //SPI1_CS_PD04_SCK_PD05_MOSI_PD06_MISO_PD07
    {1, 4, 2,  1, 4}, //SPI1_CS_PE04_SCK_PE02_MOSI_PE01_MISO_PE03
    {0, 4, 2, 16, 4}, //SPI0_CS_PE16_SCK_PE17_MOSI_PE18_MISO_PE19
    {0, 0, 2, 14, 4}, //SPI0_CS_PA14_SCK_PA15_MOSI_PA16_MISO_PA17
    {0, 0, 0,  0, 0}, //SPI0_USER_DEFINE
    {1, 0, 0,  0, 0}, //SPI1_USER_DEFINE

};

void SPI_CalDataConstValue(void)
{
	uint8_t i =0;
	uint32_t value = 0;
	for(i=0;i<sizeof(I2C_Check_Maps)/sizeof(PeripheralMapTypeDef);i++)
	{
		value =   I2C_Check_Maps[i].m_ModuleIndex<<0;
		value |=  I2C_Check_Maps[i].m_PortIndex <<3;
		value |=  I2C_Check_Maps[i].m_MuxIndex<<6;
		value |=  I2C_Check_Maps[i].m_PinBaseIndex<<9;
		value |=  I2C_Check_Maps[i].m_PinCntIndex<<14;
		UART_printf("(0x%xU)\r\n",value);
	}
}
*/


