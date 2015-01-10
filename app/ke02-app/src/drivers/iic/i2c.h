/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file I2C.h
*
* @author
*
* @version 0.0.1
*
* @date Aug 4, 2011
*
* @brief appliu16Cation entry point which performs appliu16Cation specific tasks. 
*
*******************************************************************************
*
******************************************************************************/
#ifndef _I2C_H__
#define _I2C_H__

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/
#define I2C_READ  1
#define I2C_WRITE 0

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
void I2C_set_tx_mode(I2C_MemMapPtr p);
void I2C_set_rx_mode(I2C_MemMapPtr p);
void I2C_set_slave_mode(I2C_MemMapPtr p);
void I2C_set_master_mode(I2C_MemMapPtr p);
void I2C_give_nack(I2C_MemMapPtr p);
void I2C_give_ack(I2C_MemMapPtr p);
void I2C_repeated_start(I2C_MemMapPtr p);
void I2C_write_byte(I2C_MemMapPtr p, uint8 data);
uint8 I2C_read_byte(I2C_MemMapPtr p);
void I2C_start(I2C_MemMapPtr p);
void I2C_stop(I2C_MemMapPtr p);
void I2C_wait(I2C_MemMapPtr p);
uint16 I2C_get_ack(I2C_MemMapPtr p);
void hal_I2C_init(I2C_MemMapPtr p);
void I2C_Deinit(I2C_MemMapPtr p);

#endif //

