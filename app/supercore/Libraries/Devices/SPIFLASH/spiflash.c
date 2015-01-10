
#include "spiflash.h"

//SPIFlash Power up
static void SPIFLASH_PowerUp(void)   
{  
  SPIFLASH_CSEnable();                       
  SPIFLASH_ReadWriteByte(W25X_CMD_RELEASE_POWER_DOWN);      
  SPIFLASH_CSDisable();
  SPIFLASH_DelayMs(3);   
}   

//SPI Flash Read status register
static uint8_t SPIFLASH_ReadSR(void)   
{  
  uint8_t byte=0;   
  SPIFLASH_CSEnable();                 
  SPIFLASH_ReadWriteByte(W25X_CMD_READ_STATUS_REGISTER);  
  byte = SPIFLASH_ReadWriteByte(0XFF);  
  SPIFLASH_CSDisable();      
  return byte;   
} 

//SPI Flash Write status register
static void SPIFLASH_WriteSR(uint8_t sr)   
{   
  SPIFLASH_CSEnable();      
  SPIFLASH_ReadWriteByte(W25X_CMD_WRITE_STATUS_REGISTER);   
  SPIFLASH_ReadWriteByte(sr);              
  SPIFLASH_CSDisable();    	      
}   

uint8_t SPIFLASH_Init(void)
{
  SPI_InitTypeDef SPI_InitStruct1;
  GPIO_InitTypeDef GPIO_InitStruct1;
  //config SPI ingine  
  SPI_InitStruct1.SPI_DataSize = 8; 
  SPI_InitStruct1.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
  SPI_InitStruct1.SPI_Mode = SPI_Mode_Master;
  SPI_InitStruct1.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStruct1.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStruct1.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct1.SPIxMap = SPIFLASH_SPI_DATA_MAP;
  SPI_Init(&SPI_InitStruct1);
  //use userdefine SPI, config pinmux
	PinMuxConfig(3, 4, 2);
	PinMuxConfig(3, 5, 2);
	PinMuxConfig(1,16, 2);
	PinMuxConfig(1,17, 2);
  // since we use a gpio to simualte pcs ,so config the pcs pin  
  GPIO_InitStruct1.GPIO_Pin = SPIFLASH_CS_PIN;
  GPIO_InitStruct1.GPIO_InitState = Bit_SET;
  GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
  GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
  GPIO_InitStruct1.GPIOx = SPIFLASH_CS_PORT;
  GPIO_Init(&GPIO_InitStruct1);
  SPIFLASH_PowerUp();                                //Power up
  if(SPIFLASH_GetCapacity() != 0)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

//spi flash read ID
uint16_t SPIFLASH_ReadID(void)
{
  uint16_t Temp = 0;	  
  SPIFLASH_CSEnable(); 				    
  SPIFLASH_ReadWriteByte(W25X_CMD_READ_MANUFACT_ID);
  SPIFLASH_ReadWriteByte(0x00); 	    
  SPIFLASH_ReadWriteByte(0x00); 	    
  SPIFLASH_ReadWriteByte(0x00); 	 			   
  Temp |= SPIFLASH_ReadWriteByte(0xFF)<<8;  
  Temp |= SPIFLASH_ReadWriteByte(0xFF);	 
  SPIFLASH_CSDisable();				    
  return Temp;
}   

//SPI Flash Get Capacity
 uint32_t SPIFLASH_GetCapacity(void)
{
  uint16_t id;
  id = SPIFLASH_ReadID();
  switch (id)
  {
    case W25Q80 : return (1024*1024*1);
    case W25Q16 : return (1024*1024*2);
    case W25Q32 : return (1024*1024*4);
    case W25Q64 : return (1024*1024*8);
    case W25X10 : return (1024*128);
    case W25X20 : return (1024*256);
    case W25X40 : return (1024*512);
    case MX25L6406: return (1024*1024*8);
    default     : return 0;
  }
}

void SPIFLASH_WaitBusy(void)   
{   
  while((SPIFLASH_ReadSR()&0x01) == 0x01);   
}  


void SPIFLASH_WriteEnable(void)   
{
  SPIFLASH_CSEnable(); 
  SPIFLASH_ReadWriteByte(W25X_CMD_WRITE_ENABLE);      
  SPIFLASH_CSDisable();                          
} 

void SPIFLASH_WriteDisable(void)   
{  
  SPIFLASH_CSEnable(); 
  SPIFLASH_ReadWriteByte(W25X_CMD_WRITE_DISABLE);     
  SPIFLASH_CSDisable();                      	      
} 	

//SPI Flash Read without DMA support
void SPIFLASH_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead)   
{ 
  uint16_t i;   										    
  SPIFLASH_CSEnable();                             
  SPIFLASH_ReadWriteByte(W25X_CMD_READ);  
  //send address
  SPIFLASH_ReadWriteByte((uint8_t)((ReadAddr)>>16));  
  SPIFLASH_ReadWriteByte((uint8_t)((ReadAddr)>>8));   
  SPIFLASH_ReadWriteByte((uint8_t)ReadAddr);   
  //send data
  for(i=0;i<NumByteToRead;i++)
  { 
    pBuffer[i]=SPIFLASH_ReadWriteByte(0XFF);   
  }
  SPIFLASH_CSDisable();  				    	      
}


//SPI Write Page (polling)
void SPIFLASH_WritePage(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)
{
  uint16_t i;  
  SPIFLASH_WriteEnable();                  
  SPIFLASH_CSEnable();                            
  SPIFLASH_ReadWriteByte(W25X_CMD_PAGE_PROGRAM);  
  //send address
  SPIFLASH_ReadWriteByte((uint8_t)((WriteAddr)>>16)); 
  SPIFLASH_ReadWriteByte((uint8_t)((WriteAddr)>>8));   
  SPIFLASH_ReadWriteByte((uint8_t)WriteAddr);   
  for(i=0;i<NumByteToWrite;i++)
  {
    SPIFLASH_ReadWriteByte(pBuffer[i]);
  }
  SPIFLASH_CSDisable();  	
  SPIFLASH_WaitBusy();	
} 




void SPIFLASH_EraseSector(uint32_t Dst_Addr)   
{  
	Dst_Addr*=4096;
	SPIFLASH_WriteEnable();                   
	SPIFLASH_WaitBusy();   
	SPIFLASH_CSEnable(); 
	SPIFLASH_ReadWriteByte(W25X_CMD_SECTOR_ERASE);     
	SPIFLASH_ReadWriteByte((uint8_t)((Dst_Addr)>>16));  
	SPIFLASH_ReadWriteByte((uint8_t)((Dst_Addr)>>8));   
	SPIFLASH_ReadWriteByte((uint8_t)Dst_Addr);  
	SPIFLASH_CSDisable();    	      
	SPIFLASH_WaitBusy();   				   
}  

static void SPIFLASH_WriteNoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{ 			 		 
	uint16_t pageremain;	   
	pageremain=256-WriteAddr%256; 	 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;
	while(1)
	{	   
		SPIFLASH_WritePage(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			 
			if(NumByteToWrite>256)pageremain=256; 
			else pageremain=NumByteToWrite; 	
		}
	}    
} 


//user API SPI_Flahsh_Write
uint8_t SPI_FLASH_BUFFER[4096];		 
void SPIFLASH_Write(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{ 
  uint32_t secpos;
  uint16_t secoff;
  uint16_t secremain;	   
  uint16_t i;    
  uint8_t * SPI_FLASH_BUF;	  
  SPI_FLASH_BUF=SPI_FLASH_BUFFER;	     
  secpos=WriteAddr/4096;
  secoff=WriteAddr%4096;
  secremain=4096-secoff;

  if(NumByteToWrite<=secremain)secremain=NumByteToWrite;
  while(1) 
  {	
    SPIFLASH_Read(SPI_FLASH_BUF,secpos*4096,4096);
    for(i=0;i<secremain;i++)
    {
      if(SPI_FLASH_BUF[secoff+i]!=0XFF)break; 
    }
    if(i<secremain)
    {
      SPIFLASH_EraseSector(secpos);
      for(i=0;i<secremain;i++)	  
      {
        SPI_FLASH_BUF[i+secoff]=pBuffer[i];	  
      }
    SPIFLASH_WriteNoCheck(SPI_FLASH_BUF,secpos*4096,4096);
    }else SPIFLASH_WriteNoCheck(pBuffer,WriteAddr,secremain);				   
    if(NumByteToWrite==secremain)break;
    else
    {
      secpos++;
      secoff=0;
      pBuffer+=secremain;  
      WriteAddr+=secremain;	   
      NumByteToWrite-=secremain;				
      if(NumByteToWrite>4096)secremain=4096;	
      else secremain=NumByteToWrite;			
    }	 
   }	 
}


//SPI Flash Self test
#define SPI_FLASH_SELF_TEST_ADDR       8192
#define SPI_FLASH_SELF_TEST_DATA_LONG  64

uint8_t SPI_FLASH_SelfTest(void)
{
  uint8_t i;
  uint8_t TempData[SPI_FLASH_SELF_TEST_DATA_LONG];
  uint8_t TestBuffer[SPI_FLASH_SELF_TEST_DATA_LONG];
  
  SPIFLASH_Read(TempData,SPI_FLASH_SELF_TEST_ADDR,SPI_FLASH_SELF_TEST_DATA_LONG);
  // data sample
  for(i=0;i<SPI_FLASH_SELF_TEST_DATA_LONG;i++)
  {
    TestBuffer[i] = i;
  }
  //write
  SPIFLASH_Write(TestBuffer,SPI_FLASH_SELF_TEST_ADDR,SPI_FLASH_SELF_TEST_DATA_LONG);
  for(i=0;i<SPI_FLASH_SELF_TEST_DATA_LONG;i++)
  {
    TestBuffer[i] = 0;
  }
  //read
  SPIFLASH_Read(TestBuffer,SPI_FLASH_SELF_TEST_ADDR,SPI_FLASH_SELF_TEST_DATA_LONG);
  //compare
  for(i=0;i<SPI_FLASH_SELF_TEST_DATA_LONG;i++)
  {
    if(TestBuffer[i] != i)
    {
      SPIFLASH_Write(TempData,SPI_FLASH_SELF_TEST_ADDR,SPI_FLASH_SELF_TEST_DATA_LONG);
      return FALSE;
    }
  }
  //restore regioal data
  SPIFLASH_Write(TempData,SPI_FLASH_SELF_TEST_ADDR,SPI_FLASH_SELF_TEST_DATA_LONG);
  return TRUE;
}

