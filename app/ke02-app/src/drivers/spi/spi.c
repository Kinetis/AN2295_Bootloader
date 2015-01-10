
/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file SPI.c
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
#include "common.h"
#include "spi.h"



/******************************************************************************
* Local variables
******************************************************************************/

static uint8 u8SPI0_TxChar;
static uint8 u8SPI1_RxChar;

static uint8 u8SPI0_RxChar;
static uint8 u8SPI1_TxChar;

/******************************************************************************
* Local functions
*****************************************************************************/
void SPI0_RdWrByte( uint8 u8Write,uint8* pRead);

/******************************************************************************
* Local function prototypes
******************************************************************************/

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: SPI_Init
   *
   * @brief implement SPI module init
   *        
   * @param
   *			base     -- SPI index  
   *			master   -- if master, set 1; else set 0     
   *         
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void SPI_Init( enum SPI_INDEX index,  uint8 master)
{
	vint8 dummy;
	SPI_MemMapPtr base;

	/* SPI0 SPSCK0, MOSI0, MISO0, and SS0 are mapped on 
	 * PTE0, PTE1, PTE2, and PTE3 
	 * It is already done in the system init.
	 * Please define macro SPI0_PINREMAP
	 */
	//SIM_PINSEL  |= SIM_PINSEL_SPI0PS_MASK;     
	
	if (index == SPI_INDEX0)
		base = SPI0_BASE_PTR;
	else
		base = SPI1_BASE_PTR;
	
	if (master)
	{
		if (index == SPI_INDEX0)
		{
			CS0_PIN_Init();
		}
		else
		{
			CS1_PIN_Init();
		}

		SPI_C1_REG(base) |= SPI_C1_MSTR_MASK; // master, MSTR = 1
		SPI_BR_REG(base) = 0x34;
	}
	else
	{
		SPI_C1_REG(base) &= ~SPI_C1_MSTR_MASK; // slave
		if (index == SPI_INDEX0)
			CS0_PIN_INPUT();
		else
			CS1_PIN_INPUT();
	}

	dummy = SPI_D_REG(base);
	SPI_C1_REG(base) |= SPI_C1_SPE_MASK; // enable SPI
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: SPI_Write
   *
   * @brief implement write data by SPI
   *        
   * @param
   *			base      -- SPI register base address  
   *			u8Write   -- write data    
   *         
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void SPI_Write(SPI_MemMapPtr base, uint8 u8Write)
{
	while (!SPISR_SPTEF(base));   /* sending finish? */
	SPI_D_REG(base) = u8Write;
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: SPI_Read
   *
   * @brief implement read data from SPI
   *        
   * @param
   *			base      -- SPI register base address  
   *         
   *
   * @return  read data
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
uint8 SPI_Read(SPI_MemMapPtr base)
{
	while(!SPISR_SPRF(base)); /* read finish? */
	return SPI_D_REG(base);
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: Test_SPI
   *
   * @brief implement SPI test, SPI0 as master, SPI1 as slave
   *        SPI0 write a frame data  to SPI1, verify if correct
   *        SPI0 read a frame data from SPI1,verify if correct
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: return test status
   *                        0x01 --- write fail
   *                        0x02 --- read fail
   *                        0x03 --- read and write fail
   *                        0x00 --- test success
   *****************************************************************************/
uint8 Test_SPI( void )
{
	uint8 bTestResult = 0;
	u8SPI0_TxChar = 0;
    
#ifdef SPI_MASTER
	SPI_Init(SPI_INDEX0, 1);
#else
	SPI_Init(SPI_INDEX0, 0);
#endif

#ifdef SPI_MASTER
	CS0_LOW();
	
	while(u8SPI0_TxChar < 255)
	{
		SPI0_Write(u8SPI0_TxChar);
		u8SPI0_TxChar++;	
	}
#else
	while(u8SPI0_TxChar < 255)
	{
		u8SPI0_RxChar = SPI0_Read();
		if (u8SPI0_TxChar != u8SPI0_RxChar)
		{
			//printf("%d,%d\n",u8SPI0_TxChar,u8SPI0_RxChar);
			bTestResult = 2;
			break;
		}
		u8SPI0_TxChar++;
	}
#endif
	

#if 0
	/* SPI1 write data to SPI0 */
	SPI_Init(SPI_INDEX0, 0);
	SPI_Init(SPI_INDEX1, 1);

	u8SPI1_TxChar = 8;
	CS1_LOW();
	SPI1_Write(u8SPI1_TxChar);
	u8SPI0_RxChar = SPI0_Read();
	if( u8SPI1_TxChar != u8SPI0_RxChar )
	{
		bTestResult |= 0x02;
	}
	CS1_HIGH();
#endif

#ifndef SPI_MASTER

	switch( bTestResult )
	{
		case 0x01:
		{
#if     defined(DEBUG_PRINT)
			printf("Error: SPI0 failed to write data to SPI1!\n ");
#endif                        
		}
		break;
		case 0x02:
		{
#if     defined(DEBUG_PRINT)                
			printf("Error: SPI1 failed to write data!\n ");
#endif                        
		}
		break;
	
		case 0x00:
		default:
		{
#if     defined(DEBUG_PRINT)                  
			printf("SPI communication is success!\n");
#endif					
			LED4_Toggle();
		}
		break;
	}
#endif

	return bTestResult;
}
