/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      gpio.c
 * @version   1.0.6.0
 * @date      Jun-11-2015
 * @brief     General-Purpose Input/Output (GPIO) driver source code.
 ******************************************************************************/
#include "common.h"
#include "gpio.h"

#if !defined(MCU_MKM34ZA5)
  #error "The gpio.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static PORT_CALLBACK pCallbackPTx;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void PORT_InstallCallback (uint8 ip, PORT_CALLBACK pCallback)
{
  if (pCallback) { pCallbackPTx = pCallback; NVIC_SetIsr(INT_PTx,ip); }
}

void PORTA_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTA_BASE_PTR->PCR[i] = port.PCR; }
  PORTA_ISFR = pin_mask;
}

void PORTB_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTB_BASE_PTR->PCR[i] = port.PCR; }
  PORTB_ISFR = pin_mask;
}

void PORTC_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTC_BASE_PTR->PCR[i] = port.PCR; }
  PORTC_ISFR = pin_mask;
}

void PORTD_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTD_BASE_PTR->PCR[i] = port.PCR; }
  PORTD_ISFR = pin_mask;
}

void PORTE_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTE_BASE_PTR->PCR[i] = port.PCR; }
  PORTE_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */
  PORTE_ISFR  = pin_mask;
}

void PORTF_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTF_BASE_PTR->PCR[i] = port.PCR; }
  PORTF_ISFR = pin_mask;
}

void PORTG_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTG_BASE_PTR->PCR[i] = port.PCR; }
  PORTG_ISFR = pin_mask;
}

void PORTH_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTH_BASE_PTR->PCR[i] = port.PCR; }
  PORTH_ISFR = pin_mask;
}

void PORTI_Init (tPORT port, uint8 pin_mask)
{
  register uint16 i;

  for (i=0; i<8; i++)
    if(pin_mask & (uint8)(1u << i)) { PORTI_BASE_PTR->PCR[i] = port.PCR; }
  PORTI_ISFR = pin_mask;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void portx_isr (void)
{
  register uint8 tmp;

  /* process interrupt callback function for PORTA                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTA_MASK)
  {
    PORTA_ISFR = tmp = (uint8)PORTA_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTA_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTB                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTB_MASK)
  {
    PORTB_ISFR = tmp = (uint8)PORTB_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTB_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTC                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTC_MASK)
  {
    PORTC_ISFR = tmp = (uint8)PORTC_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTC_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTD                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTD_MASK)
  {
    PORTD_ISFR = tmp = (uint8)PORTD_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTD_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTE                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTE_MASK)
  {
    PORTE_ISFR = tmp = (uint8)PORTE_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTE_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTF                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTF_MASK)
  {
    PORTF_ISFR = tmp = (uint8)PORTF_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTF_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTG                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTG_MASK)
  {
    PORTG_ISFR = tmp = (uint8)PORTG_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTG_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTH                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTH_MASK)
  {
    PORTH_ISFR = tmp = (uint8)PORTH_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTH_CALLBACK, tmp); }
  }

  /* process interrupt callback function for PORTI                            */
  if (SIM_SCGC5 & SIM_SCGC5_PORTI_MASK)
  {
    PORTI_ISFR = tmp = (uint8)PORTI_ISFR; /* read and clear interrupt flags   */
    if (tmp != 0) { pCallbackPTx (PORTI_CALLBACK, tmp); }
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/