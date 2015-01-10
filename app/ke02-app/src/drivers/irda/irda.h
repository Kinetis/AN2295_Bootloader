/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ir.h
*
* @author B37531
*
* @version 0.0.1
*
* @date Aug 23, 2011
*
* @brief IRDA header file
*
******************************************************************************/
#ifndef IRDA_H_
#define IRDA_H_

/******************************************************************************
* Macros
******************************************************************************/
// define IR work mode
#define IR_MODE_RX			1
#define IR_MODE_TEST		2
#define IR_MODE				IR_MODE_TEST

// define FTM0 initialization parameter
#define IR_FREQUENCY		38000  //hz
#define FTM0_CLOCK			BUS_CLK_HZ
#define FTM0_MOD_VALUE		FTM0_CLOCK/IR_FREQUENCY
#define FTM0_C0V_VALUE		FTM0_MOD_VALUE/2

/******************************************************************************
* Global functions
******************************************************************************/
extern void IrDA_Init( void );
extern uint8_t IrDA_Test( void );
#endif /* IR_H_ */
