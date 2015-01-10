#ifndef __24LC512_H__
#define __24LC512_H__

#include "i2C.h"

/* Interface define  */
#define AT24CXX_I2C_BASE_PTR      I2C0
#define AT24CXX_I2C_PORT          I2C0_SCL_PE24_SDA_PE25
#define AT24CXX_I2C_SPEED         I2C_CLOCK_SPEED_300KHZ


/*  MAG3110 hardware Param Define   */
#define AT24CXX_SLAVE_I2C_ADDR      (uint8_t)(0xA0)

#define AT24CXX_PAGE_SIZE           (uint8_t)(128)

void AT24Cxx_Init(void);
uint8_t AT24Cxx_Read(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint8_t AT24Cxx_ReadByte(uint16_t ReadAddr);
void AT24Cxx_WriteByte(uint16_t WriteAddr, uint8_t Register);
void AT24Cxx_WritePage(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void AT24Cxx_Write(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
#endif


