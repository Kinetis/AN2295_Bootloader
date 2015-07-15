/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      crc.h
 * @version   1.0.4.0
 * @date      Apr-15-2015
 * @brief     Cyclic Redundancy Check (CRC) driver header file.
 ******************************************************************************/
#ifndef __CRC_H
#define __CRC_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint32 DATA, GPOLY, CTRL; } tCRC;

/******************************************************************************
* CRC default configurations used by CRC_Calc() and CRC_Init() function
*
*//*! @addtogroup crc_module_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Initializes CRC module for CRC32 computation.
 * @details Initializes CRC module for CRC32 computation.
 * @showinitializer
 ******************************************************************************/
#define CRC_MODULE_CRC32_CONFIG                                               \
(tCRC){                                                                       \
/* DATA   */ 0xFFFFFFFF,                                                      \
/* GPOLY  */ 0x04C11DB7,                                                      \
/* CTRL   */ SET(CRC_CTRL_TOT(3))|SET(CRC_CTRL_TOTR(0))|                      \
/* ....   */ CLR(CRC_CTRL_FXOR_MASK)|CLR(CRC_CTRL_WAS_MASK)|                  \
/* ....   */ SET(CRC_CTRL_TCRC_MASK)                                          \
}

/***************************************************************************//*!
 * @brief Initializes CRC module for CRC16 DNP computation.
 * @details Initializes CRC module for CRC16 DNP computation.
 * @showinitializer
 ******************************************************************************/
#define CRC_MODULE_CRC16_DNP_CONFIG                                           \
(tCRC){                                                                       \
/* DATA   */ 0xFFFF,                                                          \
/* GPOLY  */ 0x3D65,                                                          \
/* CTRL   */ SET(CRC_CTRL_TOT(3))|SET(CRC_CTRL_TOTR(0))|                      \
/* ....   */ CLR(CRC_CTRL_FXOR_MASK)|CLR(CRC_CTRL_WAS_MASK)|                  \
/* ....   */ CLR(CRC_CTRL_TCRC_MASK)                                          \
}

/***************************************************************************//*!
 * @brief Initializes CRC module for CRC16 CCIT computation.
 * @details Initializes CRC module for CRC16 CCIT computation.
 * @showinitializer
 ******************************************************************************/
#define CRC_MODULE_CRC16_CCIT_CONFIG                                          \
(tCRC){                                                                       \
/* DATA   */ 0xFFFF,                                                          \
/* GPOLY  */ 0x1021,                                                          \
/* CTRL   */ SET(CRC_CTRL_TOT(3))|SET(CRC_CTRL_TOTR(0))|                      \
/* ....   */ CLR(CRC_CTRL_FXOR_MASK)|CLR(CRC_CTRL_WAS_MASK)|                  \
/* ....   */ CLR(CRC_CTRL_TCRC_MASK)                                          \
}

/***************************************************************************//*!
 * @brief Initializes CRC module for CRC16 ANSI computation.
 * @details Initializes CRC module for CRC16 ANSI computation.
 * @showinitializer
 ******************************************************************************/
#define CRC_MODULE_CRC16_ANSI_CONFIG                                          \
(tCRC){                                                                       \
/* DATA   */ 0xFFFF,                                                          \
/* GPOLY  */ 0x8005,                                                          \
/* CTRL   */ SET(CRC_CTRL_TOT(3))|SET(CRC_CTRL_TOTR(0))|                      \
/* ....   */ CLR(CRC_CTRL_FXOR_MASK)|CLR(CRC_CTRL_WAS_MASK)|                  \
/* ....   */ CLR(CRC_CTRL_TCRC_MASK)                                          \
}
/*! @} End of crc_module_config                                               */

/******************************************************************************
* CRC function and macro definitions
*
*//*! @addtogroup crc_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Reads and returns calculated CRC code.
 * @details This macro reads and returns calculated CRC code.
 * @return  @ref uint32 CRC number.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define CRC_Read() CRC_DATA&((CRC_CTRL&CRC_CTRL_TCRC_MASK)?0xFFFFFFFF:0x0000FFFF)

/***************************************************************************//*!
 * @brief   Calculates CRC of the data array of bytes (8-bits) and returns
 *          calculated CRC code.
 * @details This function calculates CRC of the data array of bytes (8-bits)
 *          and returns calculated CRC code. The algorithm for CRC calculation
 *          has been defined by the preceding @ref CRC_Init function.
 * @param   ptr   Pointer to data array of bytes (8-bits).
 * @param   len   Number of data bytes
 * @return  @ref uint32 CRC number.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define CRC_Calc8(ptr,len)    CRC_CALC8  ((const uint8 *)ptr, len)

/***************************************************************************//*!
 * @brief   Calculates CRC of the data array of half-words (16-bits) and returns
 *          calculated CRC code.
 * @details This function calculates CRC of the data array of half-words (16-bits)
 *          and returns calculated CRC code. The algorithm for CRC calculation
 *          has been defined by the preceding @ref CRC_Init function.
 * @param   ptr   Pointer to data array of half-words (16-bits).
 * @param   len   Number of data half-words.
 * @return  @ref uint32 CRC number.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define CRC_Calc16(ptr,len)   CRC_CALC16 ((const uint16 *)ptr, len)

/***************************************************************************//*!
 * @brief   Calculates CRC of the data array of words (32-bits) and returns
 *          calculated CRC code.
 * @details This function calculates CRC of the data array of words (32-bits)
 *          and returns calculated CRC code. The algorithm for CRC calculation
 *          has been defined by the preceding @ref CRC_Init function.
 * @param   ptr   Pointer to data array of words (32-bits).
 * @param   len   Number of data words.
 * @return  @ref uint32 CRC number.
 * @note    Implemented as a function call.
 ******************************************************************************/
#define CRC_Calc32(ptr,len)   CRC_CALC32 ((const uint32 *)ptr, len)

/***************************************************************************//*!
 * @brief   Initializes CRC calculation.
 * @details This function initializes CRC calculation and allows user to select
 *          preferred calculation algorithm.
 * @param   crc   Select one of the @ref crc_module_config.
 * @return  void* pointer to CRC_DATA register.
 * @note    Implemented as a function call. Information about various CRC specs
 *          available from http://en.wikipedia.org/wiki/Cyclic_redundancy_check
 ******************************************************************************/
#define CRC_Init(crc)         CRC_INIT (crc)
/*! @} End of crc_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void*  CRC_INIT   (tCRC crc);
extern uint32 CRC_CALC8  (const uint8  *ptr, uint32 len);
extern uint32 CRC_CALC16 (const uint16 *ptr, uint32 len);
extern uint32 CRC_CALC32 (const uint32 *ptr, uint32 len);

#endif /* __CRC_H */ 