#ifndef __SPIFLASH_H__
#define __SPIFLASH_H__

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "gpio.h"
#include "spi.h"
#include "delay.h"
	 
#define SPIFLASH_CS_PORT  PTD
#define SPIFLASH_CS_PIN   GPIO_Pin_4
	 
#define SPIFLASH_SPI_DATA_MAP   SPI1_USER_DEFINE
#define SPIFLASH_SPI_DATA_PORT  SPI1
	 
#define SPIFLASH_ReadWriteByte(data) \
	 (SPI_ReadWriteByte(SPIFLASH_SPI_DATA_PORT, data))

#define SPIFLASH_CSEnable() \
	 GPIO_WriteBit(SPIFLASH_CS_PORT, SPIFLASH_CS_PIN, Bit_RESET)
#define SPIFLASH_CSDisable() \
	 GPIO_WriteBit(SPIFLASH_CS_PORT, SPIFLASH_CS_PIN, Bit_SET)
	 
#define SPIFLASH_DelayMs(ms) \
	 DelayMs(ms)
	 
	 
//W25Q80 ID  0XEF13  //8Mbit  /1M   Byte
//W25Q16 ID  0XEF14  //16Mbit /2M   Byte
//W25Q32 ID  0XEF15  //32Mbit /4M   Byte
//W25Q64 ID  0XEF16	 //64Mbit /8M   Byte
//W25W10 ID  0XEF10  //1M bit /128K Byte
//W25W20 ID  0XEF11  //2M bit /256K Byte
//W25W40 ID  0XEF12  //4M bit /512K Byte
//W25W80 ID  0XEF13  //8M bit /1M   Byte
#define MX25L6406 (0xC216)
#define W25Q80    (0XEF13)	
#define W25Q16 	  (0XEF14)
#define W25Q32 	  (0XEF15)
#define W25Q64 	  (0XEF16)
#define W25X10    (0XEF10)
#define W25X20    (0XEF11)
#define W25X40    (0XEF12)
#define W25X80    (0XEF13)


//W25X CMD Table
#define W25X_CMD_WRITE_ENABLE                   (0x06) 
#define W25X_CMD_WRITE_DISABLE		        (0x04)  
#define W25X_CMD_READ_STATUS_REGISTER	       	(0x05)  
#define W25X_CMD_WRITE_STATUS_REGISTER	        (0x01)  
#define W25X_CMD_READ			        (0x03)  
#define W25X_CMD_FAST_READ	  	        (0x0B)  
#define W25X_CMD_FAST_READ_DUAL		        (0x3B)  
#define W25X_CMD_PAGE_PROGRAM		        (0x02)  
#define W25X_CMD_BLOCK_ERASE	      	        (0xD8)  
#define W25X_CMD_SECTOR_ERASE 	  	        (0x20)  
#define W25X_CMD_CHIP_ERASE		        (0xC7)  
#define W25X_CMD_POWER_DOWN		        (0xB9)  
#define W25X_CMD_RELEASE_POWER_DOWN	        (0xAB)  
#define W25X_CMD_READ_DEVICE_ID		        (0xAB)  
#define W25X_CMD_READ_MANUFACT_ID	        (0x90)   
	 
	 
	 
	 
//API functions
uint8_t SPIFLASH_Init(void);
uint32_t SPIFLASH_GetCapacity(void);
uint16_t SPIFLASH_ReadID(void);
void SPIFLASH_EraseSector(uint32_t Dst_Addr);
void SPIFLASH_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead);
void SPIFLASH_WritePage(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
void SPIFLASH_Write(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
	 
#ifdef __cplusplus
}
#endif



#endif
