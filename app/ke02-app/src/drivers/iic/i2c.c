/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ftm.c
*
* @author 
*
* @version 0.0.1
*
* @date Arp 4, 2013
*
* @brief appliu16Cation entry point which performs appliu16Cation specific tasks. 
*
*******************************************************************************
*
******************************************************************************/
#include "common.h"
#include "i2c.h"

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/



/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_set_tx_mode
   *
   * @brief set to Tx mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/

void I2C_set_tx_mode(I2C_MemMapPtr p)
{
    p->C1 |= I2C_C1_TX_MASK;

}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_set_rx_mode
   *
   * @brief set to Rx mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/
void I2C_set_rx_mode(I2C_MemMapPtr p)
{
    p->C1 &= ~I2C_C1_TX_MASK;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_set_slave_mode
   *
   * @brief set to slave mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_set_slave_mode(I2C_MemMapPtr p)
{
    p->C1  &= ~I2C_C1_MST_MASK;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_set_master_mode
   *
   * @brief set master mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_set_master_mode(I2C_MemMapPtr p)
{
    p->C1  |=  I2C_C1_MST_MASK;
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_give_nack
   *
   * @brief send out NACK signals
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/


void I2C_give_nack(I2C_MemMapPtr p)
{
    p->C1 |= I2C_C1_TXAK_MASK;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_give_ack
   *
   * @brief send out ack
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_give_ack(I2C_MemMapPtr p)
{
    p->C1 &= ~I2C_C1_TXAK_MASK;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_repeated_start
   *
   * @brief send a repeat start signal
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_repeated_start(I2C_MemMapPtr p)
{
    p->C1|= 0x04;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_write_byte
   *
   * @brief write a byte
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_write_byte(I2C_MemMapPtr p, uint8 data)
{
    p->D = data;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_read_byte
   *
   * @brief read a byte 
   *        
   * @param  P -- I2C base addressI2C_read_byte
   *
   * @return none
   *
   * @ Pass/ Fail criteria:  read data
*****************************************************************************/

uint8 I2C_read_byte(I2C_MemMapPtr p)
{
    return p->D;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_start
   *
   * @brief send a start signal
   *        
   * @param  P -- I2C base address
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_start(I2C_MemMapPtr p)
{
    I2C_set_master_mode(p);
    I2C_set_tx_mode(p);
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_stop
   *
   * @brief Implement stop 
   *        
   * @param  P -- I2C base address
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_stop(I2C_MemMapPtr p)
{
    I2C_set_slave_mode(p);
    I2C_set_rx_mode(p);
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_wait
   *
   * @brief wait IICIF flag
   *        
   * @param  P -- I2C base address
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_wait(I2C_MemMapPtr p)
{
    // wait flag
    while((p->S & I2C_S_IICIF_MASK)==0)
        ;
    // clear flag
    p->S |= I2C_S_IICIF_MASK;
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_get_ack
   *
   * @brief get ack
   *        
   * @param  P -- I2C base address
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

uint16 I2C_get_ack(I2C_MemMapPtr p)
{
    if((p->S & I2C_S_RXAK_MASK) == 0)
        return TRUE;
    else
        return FALSE;
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_Init
   *
   * @brief Initialize I2C module
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/

void I2C_Init(I2C_MemMapPtr p)
{
   SIM_SCGC |= SIM_SCGC_IIC_MASK;
    
   // configure GPIO for I2C function
    p->F  = 0x14; // baudrate
    p->C1 = 0x80; // enable IIC
}
/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: I2C_Deinit
   *
   * @brief deinit I2C module
   *        
   * @param  I2C base address
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
*****************************************************************************/
void I2C_Deinit(I2C_MemMapPtr p)
{
    p->C1 = 0x00;
    
    SIM_SCGC &= ~SIM_SCGC_IIC_MASK;
}



