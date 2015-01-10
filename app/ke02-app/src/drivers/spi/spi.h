/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file SPI.h
*
* @author Freescale
*
* @version 0.0.1
*
* @date Apr. 16, 2013
*
* @brief application entry point which performs application specific tasks. 
*
******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

/******************************************************************************
* Enum type
******************************************************************************/
enum SPI_INDEX {
	SPI_INDEX0 = 0,
	SPI_INDEX1
};

/******************************************************************************
* Macros
******************************************************************************/
#define SPI_MASTER

/* SPI related */
#define SPISR_SPTEF(base) ((SPI_S_REG(base) & SPI_S_SPTEF_MASK))
#define SPISR_SPRF(base)  ((SPI_S_REG(base) & SPI_S_SPRF_MASK))


#define LED4_MASK (0x20 << 16)

#define LED4_Init()			( GPIOA_PDDR |= LED4_MASK )
#define LED4_Toggle()		( GPIOA_PTOR = LED4_MASK )
#define LED4_On()			( GPIOA_PCOR = LED4_MASK )
#define LED4_Off()		    ( GPIOA_PSOR = LED4_MASK )


/* PTE3 used for SPI0 */
#define CS0_PIN_MASK ( 1 << 3)
#define CS0_PIN_INPUT() (GPIOB_PDDR &= ~CS0_PIN_MASK)
#define CS0_PIN_Init()	{GPIOB_PDDR |=  CS0_PIN_MASK; GPIOB_PSOR = CS0_PIN_MASK;}
#define CS0_HIGH()		(GPIOB_PSOR = CS0_PIN_MASK)
#define CS0_LOW()		(GPIOB_PCOR = CS0_PIN_MASK)

/* PTD3 used for SPI1 */
#define CS1_PIN_MASK ( 1 << 27)
#define CS1_PIN_INPUT() (GPIOA_PDDR &= ~CS1_PIN_MASK)
#define CS1_PIN_Init()	{GPIOA_PDDR |=  CS1_PIN_MASK; GPIOA_PSOR = CS1_PIN_MASK;}
#define CS1_HIGH()		(GPIOA_PSOR = CS1_PIN_MASK)
#define CS1_LOW()		(GPIOA_PCOR = CS1_PIN_MASK)

/******************************************************************************
* Global functions
******************************************************************************/

void SPI_Init( enum SPI_INDEX index,  uint8 master);

void SPI_Write(SPI_MemMapPtr base, uint8 u8Write);
uint8 SPI_Read(SPI_MemMapPtr base);

#define SPI0_Write(data) (SPI_Write(SPI0_BASE_PTR, data))
#define SPI1_Write(data) (SPI_Write(SPI1_BASE_PTR, data))

#define SPI0_Read() (SPI_Read(SPI0_BASE_PTR))
#define SPI1_Read() (SPI_Read(SPI1_BASE_PTR))


unsigned char Test_SPI( void );

#endif /* SPI_H_ */
