/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      i2c.h
 * @version   1.0.4.0
 * @date      Feb-02-2015
 * @brief     I2C bus comtroller (I2C) driver header file.
 ******************************************************************************/
#ifndef __I2C_H
#define __I2C_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint8 A1, F, C1, C2, FLT, RA, SMB, A2, SLTH, SLTL; } tI2C;

/******************************************************************************
* I2C default configurations used by I2C_init() function
*
*//*! @addtogroup i2c_config
* @{
*
*******************************************************************************/
/***************************************************************************//*!
 * @brief   I2C configured to operate in pooling mode.
 * @details Module is enabled after initialization, master mode, IRQ disabled.\
 * @param   icr  clock rate (see also "I2C divider and hold values" table in RD).
 * @note I2C baud rates selector:
 * |<c>Baud rate [kBps]</c>|<c>Bus clock [MHz]</c>|<c>icr (clock rate)</c>    |
 * |:----------------------|:---------------------|:--------------------------|
 * |<c>50 kBps </c>        |<c>24 MHz</c>         |<c>0x27                </c>|
 * |<c>50 kBps </c>        |<c>12 MHz</c>         |<c>0x1f                </c>|
 * |<c>50 kBps </c>        |<c> 6 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>100 kBps</c>        |<c>24 MHz</c>         |<c>0x1f                </c>|
 * |<c>100 kBps</c>        |<c>12 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>100 kBps</c>        |<c> 6 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>200 kBps</c>        |<c>24 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>200 kBps</c>        |<c>12 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>200 kBps</c>        |<c> 6 MHz</c>         |<c>0x05                </c>|
 * |<c>400 kBps</c>        |<c>24 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>400 kBps</c>        |<c>12 MHz</c>         |<c>0x05                </c>|
 * @showinitializer
 ******************************************************************************/
#define I2C_MODULE_IRQ_DI_CONFIG(icr)                                         \
(tI2C){                                                                       \
/* A1   */  CLR(I2C_A1_AD(0)),                                                \
/* F    */  SET(I2C_F_MULT(0))|SET(I2C_F_ICR(icr)),                           \
/* C1   */  SET(I2C_C1_IICEN_MASK)|CLR(I2C_C1_IICIE_MASK)|                    \
/* .... */  CLR(I2C_C1_MST_MASK)|CLR(I2C_C1_TX_MASK)|                         \
/* .... */  CLR(I2C_C1_TXAK_MASK)|CLR(I2C_C1_RSTA_MASK)|                      \
/* .... */  CLR(I2C_C1_WUEN_MASK)|CLR(I2C_C1_DMAEN_MASK),                     \
/* C2   */  CLR(I2C_C2_GCAEN_MASK)|CLR(I2C_C2_ADEXT_MASK)|                    \
/* .... */  CLR(I2C_C2_HDRS_MASK)|CLR(I2C_C2_SBRC_MASK)|                      \
/* .... */  CLR(I2C_C2_RMEN_MASK)|CLR(I2C_C2_AD(0)),                          \
/* FLT  */  CLR(I2C_FLT_FLT(0)),                                              \
/* RA   */  CLR(I2C_RA_RAD(0)),                                               \
/* SMB  */  CLR(I2C_SMB_FACK_MASK)|CLR(I2C_SMB_ALERTEN_MASK)|                 \
/* .... */  CLR(I2C_SMB_SIICAEN_MASK)|CLR(I2C_SMB_TCKSEL_MASK)|               \
/* .... */  CLR(I2C_SMB_SLTF_MASK)|CLR(I2C_SMB_SHTF2_MASK)|                   \
/* .... */  CLR(I2C_SMB_SHTF2IE_MASK),                                        \
/* A2   */  CLR(I2C_A2_SAD(0)),                                               \
/* SLTH */  CLR(I2C_SLTH_SSLT(0)),                                            \
/* SLTL */  CLR(I2C_SLTL_SSLT(0))                                             \
}

/***************************************************************************//*!
 * @brief   I2C configured to operate in interrupt mode.
 * @details Module is enabled after initialization, master mode, IRQ enabled.\
 * @param   icr  clock rate (see also "I2C divider and hold values" table in RD).
 * @note I2C baud rates selector:
 * |<c>Baud rate [kBps]</c>|<c>Bus clock [MHz]</c>|<c>icr (clock rate)</c>    |
 * |:----------------------|:---------------------|:--------------------------|
 * |<c>50 kBps </c>        |<c>24 MHz</c>         |<c>0x27                </c>|
 * |<c>50 kBps </c>        |<c>12 MHz</c>         |<c>0x1f                </c>|
 * |<c>50 kBps </c>        |<c> 6 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>100 kBps</c>        |<c>24 MHz</c>         |<c>0x1f                </c>|
 * |<c>100 kBps</c>        |<c>12 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>100 kBps</c>        |<c> 6 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>200 kBps</c>        |<c>24 MHz</c>         |<c>0x17 or 0x1b        </c>|
 * |<c>200 kBps</c>        |<c>12 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>200 kBps</c>        |<c> 6 MHz</c>         |<c>0x05                </c>|
 * |<c>400 kBps</c>        |<c>24 MHz</c>         |<c>0x0e or 0x11 or 0x12</c>|
 * |<c>400 kBps</c>        |<c>12 MHz</c>         |<c>0x05                </c>|
 * @showinitializer
 ******************************************************************************/
#define I2C_MODULE_IRQ_EN_CONFIG(icr)                                         \
(tI2C){                                                                       \
/* A1   */  CLR(I2C_A1_AD(0)),                                                \
/* F    */  SET(I2C_F_MULT(0))|SET(I2C_F_ICR(icr)),                           \
/* C1   */  SET(I2C_C1_IICEN_MASK)|SET(I2C_C1_IICIE_MASK)|                    \
/* .... */  CLR(I2C_C1_MST_MASK)|CLR(I2C_C1_TX_MASK)|                         \
/* .... */  CLR(I2C_C1_TXAK_MASK)|CLR(I2C_C1_RSTA_MASK)|                      \
/* .... */  CLR(I2C_C1_WUEN_MASK)|CLR(I2C_C1_DMAEN_MASK),                     \
/* C2   */  CLR(I2C_C2_GCAEN_MASK)|CLR(I2C_C2_ADEXT_MASK)|                    \
/* .... */  CLR(I2C_C2_HDRS_MASK)|CLR(I2C_C2_SBRC_MASK)|                      \
/* .... */  CLR(I2C_C2_RMEN_MASK)|CLR(I2C_C2_AD(0)),                          \
/* FLT  */  CLR(I2C_FLT_FLT(0)),                                              \
/* RA   */  CLR(I2C_RA_RAD(0)),                                               \
/* SMB  */  CLR(I2C_SMB_FACK_MASK)|CLR(I2C_SMB_ALERTEN_MASK)|                 \
/* .... */  CLR(I2C_SMB_SIICAEN_MASK)|CLR(I2C_SMB_TCKSEL_MASK)|               \
/* .... */  CLR(I2C_SMB_SLTF_MASK)|CLR(I2C_SMB_SHTF2_MASK)|                   \
/* .... */  CLR(I2C_SMB_SHTF2IE_MASK),                                        \
/* A2   */  CLR(I2C_A2_SAD(0)),                                               \
/* SLTH */  CLR(I2C_SLTH_SSLT(0)),                                            \
/* SLTL */  CLR(I2C_SLTL_SSLT(0))                                             \
}
/*! @} End of i2c_config                                                      */

/******************************************************************************
* I2C callback registered by I2C_InstallCallback() function
*
*//*! @addtogroup i2c_callback
* @{
*******************************************************************************/
/*! @brief I2C_CALLBACK type declaration                                      */
typedef enum
{
  I2C0_CALLBACK         =  1, ///< I2C0 interrupt
  I2C1_CALLBACK         =  2, ///< I2C1 interrupt
} I2C_CALLBACK_SRC;

/*! @brief I2C_CALLBACK type declaration                                      */
typedef enum
{
  I2C_MTX_CALLBACK      =  1, ///< Master (MST=1), data transmitted (TX=1)
  I2C_MRX_CALLBACK      =  2, ///< Master (MST=1), data received (TX=0)
  I2C_STX_CALLBACK      =  4, ///< Slave (MST=0), data transmitted (TX=1)
  I2C_SRX_CALLBACK      =  8, ///< Slave (MST=0), data received (TX=0)
  I2C_SIAAS_RX_CALLBACK = 16, ///< Addressed as a slave (IAAS), master writes (SRW=0)
  I2C_SIAAS_TX_CALLBACK = 32  ///< Addressed as a slave (IAAS), master reads (SRW=1)
} I2C_CALLBACK_TYPE;

/*! @brief I2C_CALLBACK function declaration                                  */
typedef void (*I2C_CALLBACK)(I2C_CALLBACK_SRC module, I2C_CALLBACK_TYPE type);
/*! @} End of i2c_callback                                                    */

/******************************************************************************
* I2C function and macro definitions
*
*//*! @addtogroup i2c_macro
* @{
*******************************************************************************/
#define I2C0_StartSignal          iosetb (I2C0_C1,I2C_C1_MST_MASK)
#define I2C1_StartSignal          iosetb (I2C1_C1,I2C_C1_MST_MASK)
/***************************************************************************//*!
 * @brief   Asserts Start condition on the bus.
 * @details This macro asserts Start condition on the bus.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_StopSignal, @ref I2C_RepeatStartSignal
 ******************************************************************************/
#define I2C_StartSignal(module)           module##_StartSignal

#define I2C0_StopSignal           ioclrb (I2C0_C1,I2C_C1_MST_MASK)
#define I2C1_StopSignal           ioclrb (I2C1_C1,I2C_C1_MST_MASK)
/***************************************************************************//*!
 * @brief   Asserts Stop condition on the bus.
 * @details This macro asserts Stop condition on the bus.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_StartSignal
 ******************************************************************************/
#define I2C_StopSignal(module)            module##_StopSignal

#define I2C0_RepeatStartSignal    iosetb (I2C0_C1,I2C_C1_RSTA_MASK)
#define I2C1_RepeatStartSignal    iosetb (I2C1_C1,I2C_C1_RSTA_MASK)
/***************************************************************************//*!
 * @brief   Asserts Repeat Start condition on the bus.
 * @details This macro asserts Repeat Start condition on the bus.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_StartSignal
 ******************************************************************************/
#define I2C_RepeatStartSignal(module)     module##_RepeatStartSignal

#define I2C0_WrData(data)         (I2C0_D = data)
#define I2C1_WrData(data)         (I2C1_D = data)
/***************************************************************************//*!
 * @brief   Writes data for transfer.
 * @details This macro writes data to Data register for transfer start.
 * @param   module    I2C0,I2C1.
 * @param   data      @ref uint8 load register value.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_RdData
 ******************************************************************************/
#define I2C_WrData(module,data)           module##_WrData(data)

#define I2C0_RdData             (uint8)I2C0_D
#define I2C1_RdData             (uint8)I2C1_D
/***************************************************************************//*!
 * @brief   Returns data from last transfer.
 * @details This macro returns last received data from Data register.
 * @param   module    I2C0,I2C1
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_WrData
 ******************************************************************************/
#define I2C_RdData(module)                module##_RdData

#define I2C0_GetTcFlag         (I2C0_S & I2C_S_TCF_MASK)
#define I2C1_GetTcFlag         (I2C1_S & I2C_S_TCF_MASK)
/***************************************************************************//*!
 * @brief   Returns transfer complete flag.
 * @details This macro returns state of the transfer complete flag.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) transfer complete,
 * @return  false           transfer in progress.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetTcFlag(module)            module##_GetTcFlag

#define I2C0_GetIsrFlag         (I2C0_S & I2C_S_IICIF_MASK)
#define I2C1_GetIsrFlag         (I2C1_S & I2C_S_IICIF_MASK)
/***************************************************************************//*!
 * @brief   Returns state of the interrupt flag.
 * @details This macro returns state of the interrupt flag.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) interrupt pending,
 * @return  false           no interrupt pending.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_ClrIsrFlag
 ******************************************************************************/
#define I2C_GetIsrFlag(module)          module##_GetIsrFlag

#define I2C0_ClrIsrFlag (I2C0_S = (I2C0_S | I2C_S_IICIF_MASK) & ~I2C_S_ARBL_MASK)
#define I2C1_ClrIsrFlag (I2C1_S = (I2C1_S | I2C_S_IICIF_MASK) & ~I2C_S_ARBL_MASK)
/***************************************************************************//*!
 * @brief   Clears interrupt flag.
 * @details This macro clears interrupt flag.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_GetIsrFlag
 ******************************************************************************/
#define I2C_ClrIsrFlag(module)          module##_ClrIsrFlag

#define I2C0_SetRxMode            ioclrb (I2C0_C1,I2C_C1_TX_MASK)
#define I2C1_SetRxMode            ioclrb (I2C1_C1,I2C_C1_TX_MASK)
/***************************************************************************//*!
 * @brief   Sets RX mode.
 * @details This macro sets RX mode.
 * @param   module    I2C0,I2C1
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_SetTxMode
 ******************************************************************************/
#define I2C_SetRxMode(module)           module##_SetRxMode

#define I2C0_SetTxMode            iosetb (I2C0_C1,I2C_C1_TX_MASK)
#define I2C1_SetTxMode            iosetb (I2C1_C1,I2C_C1_TX_MASK)
/***************************************************************************//*!
 * @brief   Sets TX mode.
 * @details This macro sets TX mode.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 * @see     @ref I2C_SetRxMode
 ******************************************************************************/
#define I2C_SetTxMode(module)           module##_SetTxMode

#define I2C0_SetNackMode          iosetb (I2C0_C1,I2C_C1_TXAK_MASK)
#define I2C1_SetNackMode          iosetb (I2C1_C1,I2C_C1_TXAK_MASK)
/***************************************************************************//*!
 * @brief   Sets NACK mode.
 * @details This macro sets NACK mode.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_SetNackMode(module)         module##_SetNackMode

#define I2C0_ClrNackMode          ioclrb (I2C0_C1,I2C_C1_TXAK_MASK)
#define I2C1_ClrNackMode          ioclrb (I2C1_C1,I2C_C1_TXAK_MASK)
/***************************************************************************//*!
 * @brief   Clear NACK mode.
 * @details This macro clear NACK mode.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_ClrNackMode(module)         module##_ClrNackMode

#define I2C0_SetADDR(addr)      (I2C0_A1 = addr)
#define I2C1_SetADDR(addr)      (I2C1_A1 = addr)
/***************************************************************************//*!
 * @brief   Sets 7-bit I2C address.
 * @details This macro sets 7-bit I2C address.
 * @param   module    I2C0,I2C1.
 * @param   addr      7-bit address.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_SetADDR(module,addr)        module##_SetADDR(addr)

#define I2C0_GetRxakFlag        (I2C0_S & I2C_S_RXAK_MASK)
#define I2C1_GetRxakFlag        (I2C1_S & I2C_S_RXAK_MASK)
/***************************************************************************//*!
 * @brief   Returns RXAK flag.
 * @details This macro returns state of the RXAK flag of the Status register.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetRxakFlag(module)           module##_GetRxakFlag

#define I2C0_GetBusyFlag        (I2C0_S & I2C_S_BUSY_MASK)
#define I2C1_GetBusyFlag        (I2C1_S & I2C_S_BUSY_MASK)
/***************************************************************************//*!
 * @brief   Returns BUSY flag.
 * @details This macro returns state of the BUSY flag of the Status register.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetBusyFlag(module)           module##_GetBusyFlag

#define I2C0_Reset              (I2C0_C1 = I2C_C1_IICEN_MASK)
#define I2C1_Reset              (I2C1_C1 = I2C_C1_IICEN_MASK)
/***************************************************************************//*!
 * @brief   Resets C1 register, but specified I2C module is still enabled.
 * @details This macro resets the specified I2C module while keeping it enabled.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_Reset(module)                 module##_Reset

#define I2C0_GetStopfFlag         (I2C0_FLT & I2C_FLT_STOPF_MASK)
#define I2C1_GetStopfFlag         (I2C1_FLT & I2C_FLT_STOPF_MASK)
/***************************************************************************//*!
 * @brief   Returns bus stop detect flag.
 * @details This macro returns bus stop detect flag.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetStopfFlag(module)          module##_GetStopfFlag

#define I2C0_ClrStopfFlag         iosetb(I2C0_FLT, I2C_FLT_STOPF_MASK)
#define I2C1_ClrStopfFlag         iosetb(I2C1_FLT, I2C_FLT_STOPF_MASK)
/***************************************************************************//*!
 * @brief   Clears bus stop detect flag.
 * @details This macro clears bus stop detect flag.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_ClrStopfFlag(module)          module##_ClrStopfFlag

#define I2C0_GetStartfFlag         (I2C0_FLT & I2C_FLT_STARTF_MASK)
#define I2C1_GetStartfFlag         (I2C1_FLT & I2C_FLT_STARTF_MASK)
/***************************************************************************//*!
 * @brief   Returns bus start detect flag.
 * @details this macro returns bus start detect flag.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetStartfFlag(module)         module##_GetStartfFlag

#define I2C0_ClrStartfFlag        iosetb(I2C0_FLT, I2C_FLT_STARTF_MASK)
#define I2C1_ClrStartfFlag        iosetb(I2C1_FLT, I2C_FLT_STARTF_MASK)
/***************************************************************************//*!
 * @brief   Clears bus start detect flag.
 * @details This macro clears bus start detect flag.
 * @param   module    I2C0,I2C1.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_ClrStartfFlag(module)         module##_ClrStartfFlag

#define I2C0_GetErrorFlag         (I2C0_S2 & I2C_S2_ERROR_MASK)
#define I2C1_GetErrorFlag         (I2C1_S2 & I2C_S2_ERROR_MASK)
/***************************************************************************//*!
 * @brief   Returns ERROR flag.
 * @details This macro returns state of the ERROR flag of the Status 2 register.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetErrorFlag(module)          module##_GetErrorFlag

#define I2C0_GetEmptyFlag       (I2C0_S2 & I2C_S2_EMPTY_MASK)
#define I2C1_GetEmptyFlag       (I2C1_S2 & I2C_S2_EMPTY_MASK)
/***************************************************************************//*!
 * @brief   Returns EMPTY flag.
 * @details This macro returns state of the EMPTY flag of the Status 2 register.
 * @param   module    I2C0,I2C1.
 * @return  true (non-zero) flag asserted,
 * @return  false           flag cleared.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define I2C_GetEmptyFlag(module)          module##_GetEmptyFlag

/* Function redefinition                                                      */
/***************************************************************************//*!
 * @brief   Installs callback function for vector 42.
 * @details This function installs callback function for interrupt vector 42.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref i2c_callback.
 * @note    Implemented as a function call.
 * @warning I2C0 and I2C1 interrupt sources are OR'ed into single interrupt vector.
 * @see     @ref I2C_Init
 ******************************************************************************/
#define I2C_InstallCallback(ip,callback)  I2C_InstallCallback (ip,callback)

/***************************************************************************//*!
 * @brief   I2C initialization.
 * @details This function initializes I2C module.
 * @param   module    I2C0,I2C1.
 * @param   cfg       Select one of the @ref i2c_config.
 * @note    Implemented as a function call.
 * @see     @ref I2C_InstallCallback
 ******************************************************************************/
#define I2C_Init(module,cfg)              module##_Init(cfg)
/*! @} End of i2c_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void I2C_InstallCallback (uint8 ip, I2C_CALLBACK pCallback);
extern void I2C0_Init (tI2C i2c);
extern void I2C1_Init (tI2C i2c);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void i2cx_isr (void);

#endif /* __I2C_H */
