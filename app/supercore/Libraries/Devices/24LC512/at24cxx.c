#include "at24cxx.h"
#include "delay.h"

//Init EEPORM
void AT24Cxx_Init(void)
{
  I2C_InitTypeDef I2C_InitStruct1;
  I2C_InitStruct1.I2CxMAP = AT24CXX_I2C_PORT;
  I2C_InitStruct1.I2C_ClockSpeed = AT24CXX_I2C_SPEED;
  I2C_Init(&I2C_InitStruct1);
}


//write a single bytes
void AT24Cxx_WriteByte(uint16_t WriteAddr, uint8_t Register)
{
  I2C_GenerateSTART(AT24CXX_I2C_BASE_PTR);
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_WRITE);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,((WriteAddr>>8)&0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,(WriteAddr & 0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);

  I2C_SendData(AT24CXX_I2C_BASE_PTR, Register);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
	
  I2C_GenerateSTOP(AT24CXX_I2C_BASE_PTR);
  while(I2C_IsLineBusy(AT24CXX_I2C_BASE_PTR) == TRUE);
}

//Page program
void AT24Cxx_WritePage(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
	uint16_t i = 0;
  I2C_GenerateSTART(AT24CXX_I2C_BASE_PTR);
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_WRITE);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
	
  I2C_SendData(AT24CXX_I2C_BASE_PTR,((WriteAddr>>8)&0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,(WriteAddr & 0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
	
	for(i=0;i<NumByteToWrite;i++)
	{
		I2C_SendData(AT24CXX_I2C_BASE_PTR, *pBuffer);
		I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
		pBuffer++;
		
	}
  I2C_GenerateSTOP(AT24CXX_I2C_BASE_PTR);
  while(I2C_IsLineBusy(AT24CXX_I2C_BASE_PTR) == TRUE);
}

//user API 
void AT24Cxx_Write(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
	uint32_t secpos;
	uint32_t secoff;
	uint16_t Byteremian;
	uint32_t pageremain;
	secpos = WriteAddr/AT24CXX_PAGE_SIZE;
	secoff = WriteAddr%AT24CXX_PAGE_SIZE;
	pageremain = AT24CXX_PAGE_SIZE-secoff;
	AT24Cxx_WritePage(pBuffer, WriteAddr, pageremain);
	DelayMs(5);
	pBuffer+=pageremain;
	secpos++;
	Byteremian = NumByteToWrite-pageremain;
	while(Byteremian != 0)
	{
		if(Byteremian <= AT24CXX_PAGE_SIZE)
		{
			 pageremain = Byteremian;
		}
		else
		{
			pageremain = AT24CXX_PAGE_SIZE;
		}
		AT24Cxx_WritePage(pBuffer, secpos*AT24CXX_PAGE_SIZE, pageremain);
		DelayMs(5);
		secpos++;
		pBuffer+=pageremain;
		Byteremian-=pageremain;
	}
}

//Read a single bytes
uint8_t AT24Cxx_ReadByte(uint16_t ReadAddr)
{
	uint8_t result; 
  I2C_GenerateSTART(AT24CXX_I2C_BASE_PTR);
  
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_WRITE);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,((ReadAddr>>8)&0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,(ReadAddr & 0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_GenerateRESTART(AT24CXX_I2C_BASE_PTR);
  
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_READ);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  I2C_SetMasterMode(AT24CXX_I2C_BASE_PTR,I2C_MASTER_READ);
  
  result = I2C_ReadData(AT24CXX_I2C_BASE_PTR);
  I2C_GenerateNAck(AT24CXX_I2C_BASE_PTR);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  I2C_GenerateSTOP(AT24CXX_I2C_BASE_PTR);
  result =  I2C_ReadData(AT24CXX_I2C_BASE_PTR);
  while(I2C_IsLineBusy(AT24CXX_I2C_BASE_PTR) == TRUE);
  return result;
}

//MutiBytes Read
uint8_t AT24Cxx_Read(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
	
	uint16_t i = 0;
  I2C_GenerateSTART(AT24CXX_I2C_BASE_PTR);
  
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_WRITE);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,((ReadAddr>>8)&0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_SendData(AT24CXX_I2C_BASE_PTR,(ReadAddr & 0xFF));
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  
  I2C_GenerateRESTART(AT24CXX_I2C_BASE_PTR);
  
  I2C_Send7bitAddress(AT24CXX_I2C_BASE_PTR,AT24CXX_SLAVE_I2C_ADDR,I2C_MASTER_READ);
  I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  I2C_SetMasterMode(AT24CXX_I2C_BASE_PTR,I2C_MASTER_READ);
  
	I2C_ReadData(AT24CXX_I2C_BASE_PTR); //dummy read
	I2C_GenerateAck(AT24CXX_I2C_BASE_PTR);
	I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
	for(i=0;i<NumByteToRead-1;i++)
	{
		*pBuffer = I2C_ReadData(AT24CXX_I2C_BASE_PTR);
		I2C_GenerateAck(AT24CXX_I2C_BASE_PTR);
    I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
		pBuffer++;
	}
	*pBuffer = I2C_ReadData(AT24CXX_I2C_BASE_PTR);
	I2C_GenerateNAck(AT24CXX_I2C_BASE_PTR);
	I2C_WaitAck(AT24CXX_I2C_BASE_PTR);
  I2C_GenerateSTOP(AT24CXX_I2C_BASE_PTR);
	for(i=0;i<400;i++);
  return 0;
}




