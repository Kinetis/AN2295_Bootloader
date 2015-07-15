/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      i2c.c
 * @version   1.0.4.0
 * @date      Apr-20-2014
 * @brief     I2C bus controller (I2C) driver source code.
******************************************************************************/
#include "common.h"
#include "i2c.h"

#if !defined(MCU_MKM34ZA5)
  #error "The i2c.c module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static I2C_CALLBACK pCallbackI2Cx;

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void I2C_InstallCallback (uint8 ip, I2C_CALLBACK pCallback)
{
  if (pCallback) { pCallbackI2Cx = pCallback; NVIC_SetIsr(INT_I2C0_I2C1,ip); }
}

void I2C0_Init (tI2C i2c)
{
  I2C0_A1    = i2c.A1;
  I2C0_F     = i2c.F;
  I2C0_C1    = i2c.C1;
  I2C0_C2    = i2c.C2;
  I2C0_FLT   = i2c.FLT;
  I2C0_RA    = i2c.RA;
  I2C0_SMB   = i2c.SMB;
  I2C0_A2    = i2c.A2;
  I2C0_SLTH  = i2c.SLTH;
  I2C0_SLTL  = i2c.SLTL;
}

void I2C1_Init (tI2C i2c)
{
  I2C1_A1    = i2c.A1;
  I2C1_F     = i2c.F;
  I2C1_C1    = i2c.C1;
  I2C1_C2    = i2c.C2;
  I2C1_FLT   = i2c.FLT;
  I2C1_RA    = i2c.RA;
  I2C1_SMB   = i2c.SMB;
  I2C1_A2    = i2c.A2;
  I2C1_SLTH  = i2c.SLTH;
  I2C1_SLTL  = i2c.SLTL;
}

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
weak void i2cx_isr (void)
{
  register uint8 arbitration_lost = FALSE;

  /* process I2C0 interrupt                                                   */
  if (SIM_SCGC4 & SIM_SCGC4_I2C0_MASK)
  {
    if (I2C_GetIsrFlag(I2C0) && (I2C0_C1 & I2C_C1_IICIE_MASK))
    {
      /* Arbitration testing                                                  */
      if (I2C0_S & I2C_S_ARBL_MASK) { arbitration_lost = TRUE; }

      I2C_ClrIsrFlag(I2C0);

      /* Master part                                                          */
      if ( (I2C0_C1 & I2C_C1_TX_MASK) && (I2C0_C1 & I2C_C1_MST_MASK))
      {
         pCallbackI2Cx (I2C0_CALLBACK, I2C_MTX_CALLBACK);
      }
      if (!(I2C0_C1 & I2C_C1_TX_MASK) && (I2C0_C1 & I2C_C1_MST_MASK))
      {
         pCallbackI2Cx (I2C0_CALLBACK, I2C_MRX_CALLBACK);
      }

      /* Slave part                                                           */
      if (I2C0_S & I2C_S_IAAS_MASK)   /* if addressed as a slave              */
      {
        if (I2C0_S & I2C_S_SRW_MASK)
        {
          pCallbackI2Cx (I2C0_CALLBACK, I2C_SIAAS_TX_CALLBACK);
        }
        else
        {
          pCallbackI2Cx (I2C0_CALLBACK, I2C_SIAAS_RX_CALLBACK);
        }
      }
      else
      {
        if (arbitration_lost == FALSE)/* if master didn't lost arbitration    */
        {
          if (!(I2C0_C1 & I2C_C1_MST_MASK) &&  (I2C0_C1 & I2C_C1_TX_MASK))
          {
             pCallbackI2Cx (I2C0_CALLBACK, I2C_STX_CALLBACK);
          }
          if (!(I2C0_C1 & I2C_C1_MST_MASK) && !(I2C0_C1 & I2C_C1_TX_MASK))
          {
             pCallbackI2Cx (I2C0_CALLBACK, I2C_SRX_CALLBACK);
          }
        }
      }
    }
  }

  /* process I2C1 interrupt                                                   */
  if (SIM_SCGC4 & SIM_SCGC4_I2C1_MASK)
  {
    if (I2C_GetIsrFlag(I2C1) && (I2C1_C1 & I2C_C1_IICIE_MASK))
    {
      /* Arbitration testing                                                  */
      if (I2C1_S & I2C_S_ARBL_MASK) { arbitration_lost = TRUE; }

      I2C_ClrIsrFlag(I2C1);

      /* Master part                                                          */
      if ( (I2C1_C1 & I2C_C1_TX_MASK) && (I2C1_C1 & I2C_C1_MST_MASK))
      {
         pCallbackI2Cx (I2C1_CALLBACK, I2C_MTX_CALLBACK);
      }
      if (!(I2C1_C1 & I2C_C1_TX_MASK) && (I2C1_C1 & I2C_C1_MST_MASK))
      {
         pCallbackI2Cx (I2C1_CALLBACK, I2C_MRX_CALLBACK);
      }

      /* Slave part                                                           */
      if (I2C1_S & I2C_S_IAAS_MASK)   /* if addressed as a slave              */
      {
        if (I2C1_S & I2C_S_SRW_MASK)
        {
          pCallbackI2Cx (I2C1_CALLBACK, I2C_SIAAS_TX_CALLBACK);
        }
        else
        {
          pCallbackI2Cx (I2C1_CALLBACK, I2C_SIAAS_RX_CALLBACK);
        }
      }
      else
      {
        if (arbitration_lost == FALSE)/* if master didn't lost arbitration    */
        {
          if (!(I2C1_C1 & I2C_C1_MST_MASK) &&  (I2C1_C1 & I2C_C1_TX_MASK))
          {
             pCallbackI2Cx (I2C1_CALLBACK, I2C_STX_CALLBACK);
          }
          if (!(I2C1_C1 & I2C_C1_MST_MASK) && !(I2C1_C1 & I2C_C1_TX_MASK))
          {
             pCallbackI2Cx (I2C1_CALLBACK, I2C_SRX_CALLBACK);
          }
        }
      }
    }
  }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/