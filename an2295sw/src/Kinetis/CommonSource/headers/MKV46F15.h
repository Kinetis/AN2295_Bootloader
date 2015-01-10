/*
** ###################################################################
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MKV4xRM Rev.1 06/2014
**     Version:             rev. 1.0, 2014-01-24
**     Build:               b140729
**
**     Abstract:
**         This header file implements peripheral memory map for MKV46F15
**         processor.
**
**     Copyright (c) 1997 - 2014 Freescale Semiconductor, Inc.
**     All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2014-01-24)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MKV46F15.h
 * @version 1.0
 * @date 2014-01-24
 * @brief Peripheral memory map for MKV46F15
 *
 * This header file implements peripheral memory map for MKV46F15 processor.
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MCU_MKV46F15)  /* Check if memory map has not been already included */
#define MCU_MKV46F15

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error MKV46F15 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000u

/**
 * @brief Macro to calculate address of an aliased word in the peripheral
 *        bitband area for a peripheral register and bit (bit band region 0x40000000 to
 *        0x400FFFFF).
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return  Address of the aliased word in the peripheral bitband area.
 */
#define BITBAND_REGADDR(Reg,Bit) (0x42000000u + (32u*((uint32_t)&(Reg) - (uint32_t)0x40000000u)) + (4u*((uint32_t)(Bit))))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 32bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG32(Reg,Bit) (*((uint32_t volatile*)(BITBAND_REGADDR(Reg,Bit))))
#define BITBAND_REG(Reg,Bit) (BITBAND_REG32(Reg,Bit))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 16bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG16(Reg,Bit) (*((uint16_t volatile*)(BITBAND_REGADDR(Reg,Bit))))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 8bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG8(Reg,Bit) (*((uint8_t volatile*)(BITBAND_REGADDR(Reg,Bit))))

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                /**< Initial Stack Pointer */
  INT_Initial_Program_Counter  = 1,                /**< Initial Program Counter */
  INT_NMI                      = 2,                /**< Non-maskable Interrupt (NMI) */
  INT_Hard_Fault               = 3,                /**< Hard Fault */
  INT_Mem_Manage_Fault         = 4,                /**< MemManage Fault */
  INT_Bus_Fault                = 5,                /**< Bus Fault */
  INT_Usage_Fault              = 6,                /**< Usage Fault */
  INT_Reserved7                = 7,                /**< Reserved interrupt */
  INT_Reserved8                = 8,                /**< Reserved interrupt */
  INT_Reserved9                = 9,                /**< Reserved interrupt */
  INT_Reserved10               = 10,               /**< Reserved interrupt */
  INT_SVCall                   = 11,               /**< Supervisor call (SVCall) */
  INT_DebugMonitor             = 12,               /**< Debug Monitor */
  INT_Reserved13               = 13,               /**< Reserved interrupt */
  INT_PendableSrvReq           = 14,               /**< Pendable request for system service (PendableSrvReq) */
  INT_SysTick                  = 15,               /**< System tick timer (SysTick) */
  INT_DMA0                     = 16,               /**< DMA channel 0, 16 transfer complete */
  INT_DMA1                     = 17,               /**< DMA channel 1, 17 transfer complete */
  INT_DMA2                     = 18,               /**< DMA channel 2, 18 transfer complete */
  INT_DMA3                     = 19,               /**< DMA channel 3, 19 transfer complete */
  INT_DMA4                     = 20,               /**< DMA channel 4, 20 transfer complete */
  INT_DMA5                     = 21,               /**< DMA channel 5, 21 transfer complete */
  INT_DMA6                     = 22,               /**< DMA channel 6, 22 transfer complete */
  INT_DMA7                     = 23,               /**< DMA channel 7, 23 transfer complete */
  INT_DMA8                     = 24,               /**< DMA channel 8, 24 transfer complete */
  INT_DMA9                     = 25,               /**< DMA channel 9, 25 transfer complete */
  INT_DMA10                    = 26,               /**< DMA channel 10, 26 transfer complete */
  INT_DMA11                    = 27,               /**< DMA channel 11, 27 transfer complete */
  INT_DMA12                    = 28,               /**< DMA channel 12, 28 transfer complete */
  INT_DMA13                    = 29,               /**< DMA channel 13, 29 transfer complete */
  INT_DMA14                    = 30,               /**< DMA channel 14, 30 transfer complete */
  INT_DMA15                    = 31,               /**< DMA channel 15, 31 transfer complete */
  INT_DMA_Error                = 32,               /**< DMA error interrupt channels 0-1531 */
  INT_MCM                      = 33,               /**< MCM interrupt */
  INT_FTFA                     = 34,               /**< Command complete */
  INT_FTFA_Collision           = 35,               /**< Read collision */
  INT_PMC                      = 36,               /**< Low-voltage detect, low-voltage warning */
  INT_LLWU                     = 37,               /**< Low Leakage Wakeup */
  INT_WDOG_EWM                 = 38,               /**< Both watchdog modules share this interrupt */
  INT_Reserved39               = 39,               /**< Reserved interrupt */
  INT_I2C                      = 40,               /**< I2C */
  INT_Reserved41               = 41,               /**< Reserved interrupt */
  INT_SPI                      = 42,               /**< SPI */
  INT_Reserved43               = 43,               /**< Reserved interrupt */
  INT_Reserved44               = 44,               /**< Reserved interrupt */
  INT_Reserved45               = 45,               /**< Reserved interrupt */
  INT_Reserved46               = 46,               /**< Reserved interrupt */
  INT_UART0_RX_TX              = 47,               /**< UART0 status sources */
  INT_UART0_ERR                = 48,               /**< UART0 error sources */
  INT_UART1_RX_TX              = 49,               /**< UART1 status sources */
  INT_UART1_ERR                = 50,               /**< UART1 error sources */
  INT_Reserved51               = 51,               /**< Reserved interrupt */
  INT_Reserved52               = 52,               /**< Reserved interrupt */
  INT_Reserved53               = 53,               /**< Reserved interrupt */
  INT_ADC_ERR                  = 54,               /**< ADC_ERR A and B ( zero cross, high/low limit) */
  INT_ADCA                     = 55,               /**< ADCA Scan complete */
  INT_CMP0                     = 56,               /**< CMP0 */
  INT_CMP1                     = 57,               /**< CMP1 */
  INT_FTM0                     = 58,               /**< FTM0 8 channels */
  INT_FTM1                     = 59,               /**< FTM1 2 channels */
  INT_Reserved60               = 60,               /**< Reserved interrupt */
  INT_Reserved61               = 61,               /**< Reserved interrupt */
  INT_Reserved62               = 62,               /**< Reserved interrupt */
  INT_Reserved63               = 63,               /**< Reserved interrupt */
  INT_PIT0                     = 64,               /**< PIT Channel 0 */
  INT_PIT1                     = 65,               /**< PIT Channel 1 */
  INT_PIT2                     = 66,               /**< PIT Channel 2 */
  INT_PIT3                     = 67,               /**< PIT Channel 3 */
  INT_PDB0                     = 68,               /**< PDB0 */
  INT_Reserved69               = 69,               /**< Reserved interrupt */
  INT_XBARA                    = 70,               /**< XBARA */
  INT_PDB1                     = 71,               /**< PDB1 */
  INT_DAC                      = 72,               /**< DAC */
  INT_MCG                      = 73,               /**< MCG */
  INT_LPTMR                    = 74,               /**< LPTMR */
  INT_PORTA                    = 75,               /**< Pin detect (Port A) */
  INT_PORTB                    = 76,               /**< Pin detect (Port B) */
  INT_PORTC                    = 77,               /**< Pin detect (Port C) */
  INT_PORTD                    = 78,               /**< Pin detect (Port D) */
  INT_PORTE                    = 79,               /**< Pin detect (Port E) */
  INT_SWI                      = 80,               /**< Software */
  INT_Reserved81               = 81,               /**< Reserved interrupt */
  INT_ENC_COMPARE              = 82,               /**< ENC Compare */
  INT_ENC_HOME                 = 83,               /**< ENC Home */
  INT_ENC_WDOG_SAB             = 84,               /**< ENC Watchdog/Simultaneous A and B change */
  INT_ENC_INDEX                = 85,               /**< ENC Index/Roll over/Roll Under */
  INT_CMP2                     = 86,               /**< CMP2 */
  INT_FTM3                     = 87,               /**< FTM3 8 channels */
  INT_Reserved88               = 88,               /**< Reserved interrupt */
  INT_ADCB                     = 89,               /**< ADCB Scan complete */
  INT_Reserved90               = 90,               /**< Reserved interrupt */
  INT_CAN0_ORed_Message_buffer = 91,               /**< FLexCAN0 OR'ed Message buffer (0-15) */
  INT_CAN0_Bus_Off             = 92,               /**< FLexCAN0 Bus Off */
  INT_CAN0_Error               = 93,               /**< FLexCAN0 Error */
  INT_CAN0_Tx_Warning          = 94,               /**< FLexCAN0 Transmit Warning */
  INT_CAN0_Rx_Warning          = 95,               /**< FLexCAN0 Receive Warning */
  INT_CAN0_Wake_Up             = 96,               /**< FLexCAN0 Wake Up */
  INT_PWMA_CMP0                = 97,               /**< eFlexPWM submodule 0 Compare */
  INT_PWMA_RELOAD0             = 98,               /**< eFlexPWM submodule 0 Reload */
  INT_PWMA_CMP1                = 99,               /**< eFlexPWM submodule 1 Compare */
  INT_PWMA_RELOAD1             = 100,              /**< eFlexPWM submodule 1 Reload */
  INT_PWMA_CMP2                = 101,              /**< eFlexPWM submodule 2 Compare */
  INT_PWMA_RELOAD2             = 102,              /**< eFlexPWM submodule 2 Reload */
  INT_PWMA_CMP3                = 103,              /**< eFlexPWM submodule 3 Compare */
  INT_PWMA_RELOAD3             = 104,              /**< eFlexPWM submodule 3 Reload */
  INT_PWMA_CAP                 = 105,              /**< eFlexPWM all input captures */
  INT_PWMA_RERR                = 106,              /**< eFlexPWM reload error */
  INT_PWMA_FAULT               = 107,              /**< eFlexPWM Fault */
  INT_CMP3                     = 108,              /**< CMP3 */
  INT_Reserved109              = 109,              /**< Reserved interrupt */
  INT_CAN1_ORed_Message_buffer = 110,              /**< FLexCAN1 OR'ed Message buffer (0-15) */
  INT_CAN1_Bus_Off             = 111,              /**< FLexCAN1 Bus Off */
  INT_CAN1_Error               = 112,              /**< FLexCAN1 Error */
  INT_CAN1_Tx_Warning          = 113,              /**< FLexCAN1 Transmit Warning */
  INT_CAN1_Rx_Warning          = 114,              /**< FLexCAN1 Receive Warning */
  INT_CAN1_Wake_Up             = 115               /**< FLexCAN1 Wake Up */
} IRQInterruptIndex;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Peripheral type defines
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_defines Peripheral type defines
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral ADC
 * @{
 */

/** ADC - Peripheral register structure */
typedef struct ADC_MemMap {
  uint16_t CTRL1;                                  /**< ADC Control Register 1, offset: 0x0 */
  uint16_t CTRL2;                                  /**< ADC Control Register 2, offset: 0x2 */
  uint16_t ZXCTRL1;                                /**< ADC Zero Crossing Control 1 Register, offset: 0x4 */
  uint16_t ZXCTRL2;                                /**< ADC Zero Crossing Control 2 Register, offset: 0x6 */
  uint16_t CLIST1;                                 /**< ADC Channel List Register 1, offset: 0x8 */
  uint16_t CLIST2;                                 /**< ADC Channel List Register 2, offset: 0xA */
  uint16_t CLIST3;                                 /**< ADC Channel List Register 3, offset: 0xC */
  uint16_t CLIST4;                                 /**< ADC Channel List Register 4, offset: 0xE */
  uint16_t SDIS;                                   /**< ADC Sample Disable Register, offset: 0x10 */
  uint16_t STAT;                                   /**< ADC Status Register, offset: 0x12 */
  uint16_t RDY;                                    /**< ADC Ready Register, offset: 0x14 */
  uint16_t LOLIMSTAT;                              /**< ADC Low Limit Status Register, offset: 0x16 */
  uint16_t HILIMSTAT;                              /**< ADC High Limit Status Register, offset: 0x18 */
  uint16_t ZXSTAT;                                 /**< ADC Zero Crossing Status Register, offset: 0x1A */
  uint16_t RSLT[16];                               /**< ADC Result Registers with sign extension, array offset: 0x1C, array step: 0x2 */
  uint16_t LOLIM[16];                              /**< ADC Low Limit Registers, array offset: 0x3C, array step: 0x2 */
  uint16_t HILIM[16];                              /**< ADC High Limit Registers, array offset: 0x5C, array step: 0x2 */
  uint16_t OFFST[16];                              /**< ADC Offset Registers, array offset: 0x7C, array step: 0x2 */
  uint16_t PWR;                                    /**< ADC Power Control Register, offset: 0x9C */
  uint16_t CAL;                                    /**< ADC Calibration Register, offset: 0x9E */
  uint16_t GC1;                                    /**< Gain Control 1 Register, offset: 0xA0 */
  uint16_t GC2;                                    /**< Gain Control 2 Register, offset: 0xA2 */
  uint16_t SCTRL;                                  /**< ADC Scan Control Register, offset: 0xA4 */
  uint16_t PWR2;                                   /**< ADC Power Control Register, offset: 0xA6 */
  uint16_t CTRL3;                                  /**< ADC Control Register 3, offset: 0xA8 */
  uint16_t SCHLTEN;                                /**< ADC Scan Interrupt Enable Register, offset: 0xAA */
} volatile *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register accessors */
#define ADC_CTRL1_REG(base)                      ((base)->CTRL1)
#define ADC_CTRL2_REG(base)                      ((base)->CTRL2)
#define ADC_ZXCTRL1_REG(base)                    ((base)->ZXCTRL1)
#define ADC_ZXCTRL2_REG(base)                    ((base)->ZXCTRL2)
#define ADC_CLIST1_REG(base)                     ((base)->CLIST1)
#define ADC_CLIST2_REG(base)                     ((base)->CLIST2)
#define ADC_CLIST3_REG(base)                     ((base)->CLIST3)
#define ADC_CLIST4_REG(base)                     ((base)->CLIST4)
#define ADC_SDIS_REG(base)                       ((base)->SDIS)
#define ADC_STAT_REG(base)                       ((base)->STAT)
#define ADC_RDY_REG(base)                        ((base)->RDY)
#define ADC_LOLIMSTAT_REG(base)                  ((base)->LOLIMSTAT)
#define ADC_HILIMSTAT_REG(base)                  ((base)->HILIMSTAT)
#define ADC_ZXSTAT_REG(base)                     ((base)->ZXSTAT)
#define ADC_RSLT_REG(base,index)                 ((base)->RSLT[index])
#define ADC_LOLIM_REG(base,index)                ((base)->LOLIM[index])
#define ADC_HILIM_REG(base,index)                ((base)->HILIM[index])
#define ADC_OFFST_REG(base,index)                ((base)->OFFST[index])
#define ADC_PWR_REG(base)                        ((base)->PWR)
#define ADC_CAL_REG(base)                        ((base)->CAL)
#define ADC_GC1_REG(base)                        ((base)->GC1)
#define ADC_GC2_REG(base)                        ((base)->GC2)
#define ADC_SCTRL_REG(base)                      ((base)->SCTRL)
#define ADC_PWR2_REG(base)                       ((base)->PWR2)
#define ADC_CTRL3_REG(base)                      ((base)->CTRL3)
#define ADC_SCHLTEN_REG(base)                    ((base)->SCHLTEN)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* CTRL1 Bit Fields */
#define ADC_CTRL1_SMODE_MASK                     0x7u
#define ADC_CTRL1_SMODE_SHIFT                    0
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_SMODE_SHIFT))&ADC_CTRL1_SMODE_MASK)
#define ADC_CTRL1_CHNCFG_L_MASK                  0xF0u
#define ADC_CTRL1_CHNCFG_L_SHIFT                 4
#define ADC_CTRL1_CHNCFG_L(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG_L_SHIFT))&ADC_CTRL1_CHNCFG_L_MASK)
#define ADC_CTRL1_HLMTIE_MASK                    0x100u
#define ADC_CTRL1_HLMTIE_SHIFT                   8
#define ADC_CTRL1_LLMTIE_MASK                    0x200u
#define ADC_CTRL1_LLMTIE_SHIFT                   9
#define ADC_CTRL1_ZCIE_MASK                      0x400u
#define ADC_CTRL1_ZCIE_SHIFT                     10
#define ADC_CTRL1_EOSIE0_MASK                    0x800u
#define ADC_CTRL1_EOSIE0_SHIFT                   11
#define ADC_CTRL1_SYNC0_MASK                     0x1000u
#define ADC_CTRL1_SYNC0_SHIFT                    12
#define ADC_CTRL1_START0_MASK                    0x2000u
#define ADC_CTRL1_START0_SHIFT                   13
#define ADC_CTRL1_STOP0_MASK                     0x4000u
#define ADC_CTRL1_STOP0_SHIFT                    14
#define ADC_CTRL1_DMAEN0_MASK                    0x8000u
#define ADC_CTRL1_DMAEN0_SHIFT                   15
/* CTRL2 Bit Fields */
#define ADC_CTRL2_DIV0_MASK                      0x3Fu
#define ADC_CTRL2_DIV0_SHIFT                     0
#define ADC_CTRL2_DIV0(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_DIV0_SHIFT))&ADC_CTRL2_DIV0_MASK)
#define ADC_CTRL2_SIMULT_MASK                    0x40u
#define ADC_CTRL2_SIMULT_SHIFT                   6
#define ADC_CTRL2_CHNCFG_H_MASK                  0x780u
#define ADC_CTRL2_CHNCFG_H_SHIFT                 7
#define ADC_CTRL2_CHNCFG_H(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_CHNCFG_H_SHIFT))&ADC_CTRL2_CHNCFG_H_MASK)
#define ADC_CTRL2_EOSIE1_MASK                    0x800u
#define ADC_CTRL2_EOSIE1_SHIFT                   11
#define ADC_CTRL2_SYNC1_MASK                     0x1000u
#define ADC_CTRL2_SYNC1_SHIFT                    12
#define ADC_CTRL2_START1_MASK                    0x2000u
#define ADC_CTRL2_START1_SHIFT                   13
#define ADC_CTRL2_STOP1_MASK                     0x4000u
#define ADC_CTRL2_STOP1_SHIFT                    14
#define ADC_CTRL2_DMAEN1_MASK                    0x8000u
#define ADC_CTRL2_DMAEN1_SHIFT                   15
/* ZXCTRL1 Bit Fields */
#define ADC_ZXCTRL1_ZCE0_MASK                    0x3u
#define ADC_ZXCTRL1_ZCE0_SHIFT                   0
#define ADC_ZXCTRL1_ZCE0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE0_SHIFT))&ADC_ZXCTRL1_ZCE0_MASK)
#define ADC_ZXCTRL1_ZCE1_MASK                    0xCu
#define ADC_ZXCTRL1_ZCE1_SHIFT                   2
#define ADC_ZXCTRL1_ZCE1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE1_SHIFT))&ADC_ZXCTRL1_ZCE1_MASK)
#define ADC_ZXCTRL1_ZCE2_MASK                    0x30u
#define ADC_ZXCTRL1_ZCE2_SHIFT                   4
#define ADC_ZXCTRL1_ZCE2(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE2_SHIFT))&ADC_ZXCTRL1_ZCE2_MASK)
#define ADC_ZXCTRL1_ZCE3_MASK                    0xC0u
#define ADC_ZXCTRL1_ZCE3_SHIFT                   6
#define ADC_ZXCTRL1_ZCE3(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE3_SHIFT))&ADC_ZXCTRL1_ZCE3_MASK)
#define ADC_ZXCTRL1_ZCE4_MASK                    0x300u
#define ADC_ZXCTRL1_ZCE4_SHIFT                   8
#define ADC_ZXCTRL1_ZCE4(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE4_SHIFT))&ADC_ZXCTRL1_ZCE4_MASK)
#define ADC_ZXCTRL1_ZCE5_MASK                    0xC00u
#define ADC_ZXCTRL1_ZCE5_SHIFT                   10
#define ADC_ZXCTRL1_ZCE5(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE5_SHIFT))&ADC_ZXCTRL1_ZCE5_MASK)
#define ADC_ZXCTRL1_ZCE6_MASK                    0x3000u
#define ADC_ZXCTRL1_ZCE6_SHIFT                   12
#define ADC_ZXCTRL1_ZCE6(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE6_SHIFT))&ADC_ZXCTRL1_ZCE6_MASK)
#define ADC_ZXCTRL1_ZCE7_MASK                    0xC000u
#define ADC_ZXCTRL1_ZCE7_SHIFT                   14
#define ADC_ZXCTRL1_ZCE7(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE7_SHIFT))&ADC_ZXCTRL1_ZCE7_MASK)
/* ZXCTRL2 Bit Fields */
#define ADC_ZXCTRL2_ZCE8_MASK                    0x3u
#define ADC_ZXCTRL2_ZCE8_SHIFT                   0
#define ADC_ZXCTRL2_ZCE8(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE8_SHIFT))&ADC_ZXCTRL2_ZCE8_MASK)
#define ADC_ZXCTRL2_ZCE9_MASK                    0xCu
#define ADC_ZXCTRL2_ZCE9_SHIFT                   2
#define ADC_ZXCTRL2_ZCE9(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE9_SHIFT))&ADC_ZXCTRL2_ZCE9_MASK)
#define ADC_ZXCTRL2_ZCE10_MASK                   0x30u
#define ADC_ZXCTRL2_ZCE10_SHIFT                  4
#define ADC_ZXCTRL2_ZCE10(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE10_SHIFT))&ADC_ZXCTRL2_ZCE10_MASK)
#define ADC_ZXCTRL2_ZCE11_MASK                   0xC0u
#define ADC_ZXCTRL2_ZCE11_SHIFT                  6
#define ADC_ZXCTRL2_ZCE11(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE11_SHIFT))&ADC_ZXCTRL2_ZCE11_MASK)
#define ADC_ZXCTRL2_ZCE12_MASK                   0x300u
#define ADC_ZXCTRL2_ZCE12_SHIFT                  8
#define ADC_ZXCTRL2_ZCE12(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE12_SHIFT))&ADC_ZXCTRL2_ZCE12_MASK)
#define ADC_ZXCTRL2_ZCE13_MASK                   0xC00u
#define ADC_ZXCTRL2_ZCE13_SHIFT                  10
#define ADC_ZXCTRL2_ZCE13(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE13_SHIFT))&ADC_ZXCTRL2_ZCE13_MASK)
#define ADC_ZXCTRL2_ZCE14_MASK                   0x3000u
#define ADC_ZXCTRL2_ZCE14_SHIFT                  12
#define ADC_ZXCTRL2_ZCE14(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE14_SHIFT))&ADC_ZXCTRL2_ZCE14_MASK)
#define ADC_ZXCTRL2_ZCE15_MASK                   0xC000u
#define ADC_ZXCTRL2_ZCE15_SHIFT                  14
#define ADC_ZXCTRL2_ZCE15(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE15_SHIFT))&ADC_ZXCTRL2_ZCE15_MASK)
/* CLIST1 Bit Fields */
#define ADC_CLIST1_SAMPLE0_MASK                  0xFu
#define ADC_CLIST1_SAMPLE0_SHIFT                 0
#define ADC_CLIST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE0_SHIFT))&ADC_CLIST1_SAMPLE0_MASK)
#define ADC_CLIST1_SAMPLE1_MASK                  0xF0u
#define ADC_CLIST1_SAMPLE1_SHIFT                 4
#define ADC_CLIST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE1_SHIFT))&ADC_CLIST1_SAMPLE1_MASK)
#define ADC_CLIST1_SAMPLE2_MASK                  0xF00u
#define ADC_CLIST1_SAMPLE2_SHIFT                 8
#define ADC_CLIST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE2_SHIFT))&ADC_CLIST1_SAMPLE2_MASK)
#define ADC_CLIST1_SAMPLE3_MASK                  0xF000u
#define ADC_CLIST1_SAMPLE3_SHIFT                 12
#define ADC_CLIST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE3_SHIFT))&ADC_CLIST1_SAMPLE3_MASK)
/* CLIST2 Bit Fields */
#define ADC_CLIST2_SAMPLE4_MASK                  0xFu
#define ADC_CLIST2_SAMPLE4_SHIFT                 0
#define ADC_CLIST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE4_SHIFT))&ADC_CLIST2_SAMPLE4_MASK)
#define ADC_CLIST2_SAMPLE5_MASK                  0xF0u
#define ADC_CLIST2_SAMPLE5_SHIFT                 4
#define ADC_CLIST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE5_SHIFT))&ADC_CLIST2_SAMPLE5_MASK)
#define ADC_CLIST2_SAMPLE6_MASK                  0xF00u
#define ADC_CLIST2_SAMPLE6_SHIFT                 8
#define ADC_CLIST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE6_SHIFT))&ADC_CLIST2_SAMPLE6_MASK)
#define ADC_CLIST2_SAMPLE7_MASK                  0xF000u
#define ADC_CLIST2_SAMPLE7_SHIFT                 12
#define ADC_CLIST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE7_SHIFT))&ADC_CLIST2_SAMPLE7_MASK)
/* CLIST3 Bit Fields */
#define ADC_CLIST3_SAMPLE8_MASK                  0xFu
#define ADC_CLIST3_SAMPLE8_SHIFT                 0
#define ADC_CLIST3_SAMPLE8(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE8_SHIFT))&ADC_CLIST3_SAMPLE8_MASK)
#define ADC_CLIST3_SAMPLE9_MASK                  0xF0u
#define ADC_CLIST3_SAMPLE9_SHIFT                 4
#define ADC_CLIST3_SAMPLE9(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE9_SHIFT))&ADC_CLIST3_SAMPLE9_MASK)
#define ADC_CLIST3_SAMPLE10_MASK                 0xF00u
#define ADC_CLIST3_SAMPLE10_SHIFT                8
#define ADC_CLIST3_SAMPLE10(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE10_SHIFT))&ADC_CLIST3_SAMPLE10_MASK)
#define ADC_CLIST3_SAMPLE11_MASK                 0xF000u
#define ADC_CLIST3_SAMPLE11_SHIFT                12
#define ADC_CLIST3_SAMPLE11(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE11_SHIFT))&ADC_CLIST3_SAMPLE11_MASK)
/* CLIST4 Bit Fields */
#define ADC_CLIST4_SAMPLE12_MASK                 0xFu
#define ADC_CLIST4_SAMPLE12_SHIFT                0
#define ADC_CLIST4_SAMPLE12(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE12_SHIFT))&ADC_CLIST4_SAMPLE12_MASK)
#define ADC_CLIST4_SAMPLE13_MASK                 0xF0u
#define ADC_CLIST4_SAMPLE13_SHIFT                4
#define ADC_CLIST4_SAMPLE13(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE13_SHIFT))&ADC_CLIST4_SAMPLE13_MASK)
#define ADC_CLIST4_SAMPLE14_MASK                 0xF00u
#define ADC_CLIST4_SAMPLE14_SHIFT                8
#define ADC_CLIST4_SAMPLE14(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE14_SHIFT))&ADC_CLIST4_SAMPLE14_MASK)
#define ADC_CLIST4_SAMPLE15_MASK                 0xF000u
#define ADC_CLIST4_SAMPLE15_SHIFT                12
#define ADC_CLIST4_SAMPLE15(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE15_SHIFT))&ADC_CLIST4_SAMPLE15_MASK)
/* SDIS Bit Fields */
#define ADC_SDIS_DS_MASK                         0xFFFFu
#define ADC_SDIS_DS_SHIFT                        0
#define ADC_SDIS_DS(x)                           (((uint16_t)(((uint16_t)(x))<<ADC_SDIS_DS_SHIFT))&ADC_SDIS_DS_MASK)
/* STAT Bit Fields */
#define ADC_STAT_UNDEFINED_MASK                  0xFFu
#define ADC_STAT_UNDEFINED_SHIFT                 0
#define ADC_STAT_UNDEFINED(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_STAT_UNDEFINED_SHIFT))&ADC_STAT_UNDEFINED_MASK)
#define ADC_STAT_HLMTI_MASK                      0x100u
#define ADC_STAT_HLMTI_SHIFT                     8
#define ADC_STAT_LLMTI_MASK                      0x200u
#define ADC_STAT_LLMTI_SHIFT                     9
#define ADC_STAT_ZCI_MASK                        0x400u
#define ADC_STAT_ZCI_SHIFT                       10
#define ADC_STAT_EOSI0_MASK                      0x800u
#define ADC_STAT_EOSI0_SHIFT                     11
#define ADC_STAT_EOSI1_MASK                      0x1000u
#define ADC_STAT_EOSI1_SHIFT                     12
#define ADC_STAT_CIP1_MASK                       0x4000u
#define ADC_STAT_CIP1_SHIFT                      14
#define ADC_STAT_CIP0_MASK                       0x8000u
#define ADC_STAT_CIP0_SHIFT                      15
/* RDY Bit Fields */
#define ADC_RDY_RDY_MASK                         0xFFFFu
#define ADC_RDY_RDY_SHIFT                        0
#define ADC_RDY_RDY(x)                           (((uint16_t)(((uint16_t)(x))<<ADC_RDY_RDY_SHIFT))&ADC_RDY_RDY_MASK)
/* LOLIMSTAT Bit Fields */
#define ADC_LOLIMSTAT_LLS_MASK                   0xFFFFu
#define ADC_LOLIMSTAT_LLS_SHIFT                  0
#define ADC_LOLIMSTAT_LLS(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_LOLIMSTAT_LLS_SHIFT))&ADC_LOLIMSTAT_LLS_MASK)
/* HILIMSTAT Bit Fields */
#define ADC_HILIMSTAT_HLS_MASK                   0xFFFFu
#define ADC_HILIMSTAT_HLS_SHIFT                  0
#define ADC_HILIMSTAT_HLS(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_HILIMSTAT_HLS_SHIFT))&ADC_HILIMSTAT_HLS_MASK)
/* ZXSTAT Bit Fields */
#define ADC_ZXSTAT_ZCS_MASK                      0xFFFFu
#define ADC_ZXSTAT_ZCS_SHIFT                     0
#define ADC_ZXSTAT_ZCS(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ZXSTAT_ZCS_SHIFT))&ADC_ZXSTAT_ZCS_MASK)
/* RSLT Bit Fields */
#define ADC_RSLT_RSLT_MASK                       0x7FF8u
#define ADC_RSLT_RSLT_SHIFT                      3
#define ADC_RSLT_RSLT(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_RSLT_RSLT_SHIFT))&ADC_RSLT_RSLT_MASK)
#define ADC_RSLT_SEXT_MASK                       0x8000u
#define ADC_RSLT_SEXT_SHIFT                      15
/* LOLIM Bit Fields */
#define ADC_LOLIM_LLMT_MASK                      0x7FF8u
#define ADC_LOLIM_LLMT_SHIFT                     3
#define ADC_LOLIM_LLMT(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_LOLIM_LLMT_SHIFT))&ADC_LOLIM_LLMT_MASK)
/* HILIM Bit Fields */
#define ADC_HILIM_HLMT_MASK                      0x7FF8u
#define ADC_HILIM_HLMT_SHIFT                     3
#define ADC_HILIM_HLMT(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_HILIM_HLMT_SHIFT))&ADC_HILIM_HLMT_MASK)
/* OFFST Bit Fields */
#define ADC_OFFST_OFFSET_MASK                    0x7FF8u
#define ADC_OFFST_OFFSET_SHIFT                   3
#define ADC_OFFST_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_OFFST_OFFSET_SHIFT))&ADC_OFFST_OFFSET_MASK)
/* PWR Bit Fields */
#define ADC_PWR_PD0_MASK                         0x1u
#define ADC_PWR_PD0_SHIFT                        0
#define ADC_PWR_PD1_MASK                         0x2u
#define ADC_PWR_PD1_SHIFT                        1
#define ADC_PWR_APD_MASK                         0x8u
#define ADC_PWR_APD_SHIFT                        3
#define ADC_PWR_PUDELAY_MASK                     0x3F0u
#define ADC_PWR_PUDELAY_SHIFT                    4
#define ADC_PWR_PUDELAY(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR_PUDELAY_SHIFT))&ADC_PWR_PUDELAY_MASK)
#define ADC_PWR_PSTS0_MASK                       0x400u
#define ADC_PWR_PSTS0_SHIFT                      10
#define ADC_PWR_PSTS1_MASK                       0x800u
#define ADC_PWR_PSTS1_SHIFT                      11
#define ADC_PWR_ASB_MASK                         0x8000u
#define ADC_PWR_ASB_SHIFT                        15
/* CAL Bit Fields */
#define ADC_CAL_SEL_VREFLO_A_MASK                0x1000u
#define ADC_CAL_SEL_VREFLO_A_SHIFT               12
#define ADC_CAL_SEL_VREFH_A_MASK                 0x2000u
#define ADC_CAL_SEL_VREFH_A_SHIFT                13
#define ADC_CAL_SEL_VREFLO_B_MASK                0x4000u
#define ADC_CAL_SEL_VREFLO_B_SHIFT               14
#define ADC_CAL_SEL_VREFH_B_MASK                 0x8000u
#define ADC_CAL_SEL_VREFH_B_SHIFT                15
/* GC1 Bit Fields */
#define ADC_GC1_GAIN0_MASK                       0x3u
#define ADC_GC1_GAIN0_SHIFT                      0
#define ADC_GC1_GAIN0(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN0_SHIFT))&ADC_GC1_GAIN0_MASK)
#define ADC_GC1_GAIN1_MASK                       0xCu
#define ADC_GC1_GAIN1_SHIFT                      2
#define ADC_GC1_GAIN1(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN1_SHIFT))&ADC_GC1_GAIN1_MASK)
#define ADC_GC1_GAIN2_MASK                       0x30u
#define ADC_GC1_GAIN2_SHIFT                      4
#define ADC_GC1_GAIN2(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN2_SHIFT))&ADC_GC1_GAIN2_MASK)
#define ADC_GC1_GAIN3_MASK                       0xC0u
#define ADC_GC1_GAIN3_SHIFT                      6
#define ADC_GC1_GAIN3(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN3_SHIFT))&ADC_GC1_GAIN3_MASK)
#define ADC_GC1_GAIN4_MASK                       0x300u
#define ADC_GC1_GAIN4_SHIFT                      8
#define ADC_GC1_GAIN4(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN4_SHIFT))&ADC_GC1_GAIN4_MASK)
#define ADC_GC1_GAIN5_MASK                       0xC00u
#define ADC_GC1_GAIN5_SHIFT                      10
#define ADC_GC1_GAIN5(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN5_SHIFT))&ADC_GC1_GAIN5_MASK)
#define ADC_GC1_GAIN6_MASK                       0x3000u
#define ADC_GC1_GAIN6_SHIFT                      12
#define ADC_GC1_GAIN6(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN6_SHIFT))&ADC_GC1_GAIN6_MASK)
#define ADC_GC1_GAIN7_MASK                       0xC000u
#define ADC_GC1_GAIN7_SHIFT                      14
#define ADC_GC1_GAIN7(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN7_SHIFT))&ADC_GC1_GAIN7_MASK)
/* GC2 Bit Fields */
#define ADC_GC2_GAIN8_MASK                       0x3u
#define ADC_GC2_GAIN8_SHIFT                      0
#define ADC_GC2_GAIN8(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN8_SHIFT))&ADC_GC2_GAIN8_MASK)
#define ADC_GC2_GAIN9_MASK                       0xCu
#define ADC_GC2_GAIN9_SHIFT                      2
#define ADC_GC2_GAIN9(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN9_SHIFT))&ADC_GC2_GAIN9_MASK)
#define ADC_GC2_GAIN10_MASK                      0x30u
#define ADC_GC2_GAIN10_SHIFT                     4
#define ADC_GC2_GAIN10(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN10_SHIFT))&ADC_GC2_GAIN10_MASK)
#define ADC_GC2_GAIN11_MASK                      0xC0u
#define ADC_GC2_GAIN11_SHIFT                     6
#define ADC_GC2_GAIN11(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN11_SHIFT))&ADC_GC2_GAIN11_MASK)
#define ADC_GC2_GAIN12_MASK                      0x300u
#define ADC_GC2_GAIN12_SHIFT                     8
#define ADC_GC2_GAIN12(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN12_SHIFT))&ADC_GC2_GAIN12_MASK)
#define ADC_GC2_GAIN13_MASK                      0xC00u
#define ADC_GC2_GAIN13_SHIFT                     10
#define ADC_GC2_GAIN13(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN13_SHIFT))&ADC_GC2_GAIN13_MASK)
#define ADC_GC2_GAIN14_MASK                      0x3000u
#define ADC_GC2_GAIN14_SHIFT                     12
#define ADC_GC2_GAIN14(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN14_SHIFT))&ADC_GC2_GAIN14_MASK)
#define ADC_GC2_GAIN15_MASK                      0xC000u
#define ADC_GC2_GAIN15_SHIFT                     14
#define ADC_GC2_GAIN15(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN15_SHIFT))&ADC_GC2_GAIN15_MASK)
/* SCTRL Bit Fields */
#define ADC_SCTRL_SC_MASK                        0xFFFFu
#define ADC_SCTRL_SC_SHIFT                       0
#define ADC_SCTRL_SC(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SCTRL_SC_SHIFT))&ADC_SCTRL_SC_MASK)
/* PWR2 Bit Fields */
#define ADC_PWR2_SPEEDA_MASK                     0x3u
#define ADC_PWR2_SPEEDA_SHIFT                    0
#define ADC_PWR2_SPEEDA(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_SPEEDA_SHIFT))&ADC_PWR2_SPEEDA_MASK)
#define ADC_PWR2_SPEEDB_MASK                     0xCu
#define ADC_PWR2_SPEEDB_SHIFT                    2
#define ADC_PWR2_SPEEDB(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_SPEEDB_SHIFT))&ADC_PWR2_SPEEDB_MASK)
#define ADC_PWR2_DIV1_MASK                       0x3F00u
#define ADC_PWR2_DIV1_SHIFT                      8
#define ADC_PWR2_DIV1(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_DIV1_SHIFT))&ADC_PWR2_DIV1_MASK)
/* CTRL3 Bit Fields */
#define ADC_CTRL3_SCNT0_MASK                     0x7u
#define ADC_CTRL3_SCNT0_SHIFT                    0
#define ADC_CTRL3_SCNT0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL3_SCNT0_SHIFT))&ADC_CTRL3_SCNT0_MASK)
#define ADC_CTRL3_SCNT1_MASK                     0x38u
#define ADC_CTRL3_SCNT1_SHIFT                    3
#define ADC_CTRL3_SCNT1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL3_SCNT1_SHIFT))&ADC_CTRL3_SCNT1_MASK)
#define ADC_CTRL3_DMASRC_MASK                    0x40u
#define ADC_CTRL3_DMASRC_SHIFT                   6
/* SCHLTEN Bit Fields */
#define ADC_SCHLTEN_SCHLTEN_MASK                 0xFFFFu
#define ADC_SCHLTEN_SCHLTEN_SHIFT                0
#define ADC_SCHLTEN_SCHLTEN(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_SCHLTEN_SCHLTEN_SHIFT))&ADC_SCHLTEN_SCHLTEN_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base pointer */
#define ADC_BASE_PTR                             ((ADC_MemMapPtr)0x4005C000u)
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC */
#define ADC_CTRL1                                ADC_CTRL1_REG(ADC_BASE_PTR)
#define ADC_CTRL2                                ADC_CTRL2_REG(ADC_BASE_PTR)
#define ADC_ZXCTRL1                              ADC_ZXCTRL1_REG(ADC_BASE_PTR)
#define ADC_ZXCTRL2                              ADC_ZXCTRL2_REG(ADC_BASE_PTR)
#define ADC_CLIST1                               ADC_CLIST1_REG(ADC_BASE_PTR)
#define ADC_CLIST2                               ADC_CLIST2_REG(ADC_BASE_PTR)
#define ADC_CLIST3                               ADC_CLIST3_REG(ADC_BASE_PTR)
#define ADC_CLIST4                               ADC_CLIST4_REG(ADC_BASE_PTR)
#define ADC_SDIS                                 ADC_SDIS_REG(ADC_BASE_PTR)
#define ADC_STAT                                 ADC_STAT_REG(ADC_BASE_PTR)
#define ADC_RDY                                  ADC_RDY_REG(ADC_BASE_PTR)
#define ADC_LOLIMSTAT                            ADC_LOLIMSTAT_REG(ADC_BASE_PTR)
#define ADC_HILIMSTAT                            ADC_HILIMSTAT_REG(ADC_BASE_PTR)
#define ADC_ZXSTAT                               ADC_ZXSTAT_REG(ADC_BASE_PTR)
#define ADC_RSLT0                                ADC_RSLT_REG(ADC_BASE_PTR,0)
#define ADC_RSLT1                                ADC_RSLT_REG(ADC_BASE_PTR,1)
#define ADC_RSLT2                                ADC_RSLT_REG(ADC_BASE_PTR,2)
#define ADC_RSLT3                                ADC_RSLT_REG(ADC_BASE_PTR,3)
#define ADC_RSLT4                                ADC_RSLT_REG(ADC_BASE_PTR,4)
#define ADC_RSLT5                                ADC_RSLT_REG(ADC_BASE_PTR,5)
#define ADC_RSLT6                                ADC_RSLT_REG(ADC_BASE_PTR,6)
#define ADC_RSLT7                                ADC_RSLT_REG(ADC_BASE_PTR,7)
#define ADC_RSLT8                                ADC_RSLT_REG(ADC_BASE_PTR,8)
#define ADC_RSLT9                                ADC_RSLT_REG(ADC_BASE_PTR,9)
#define ADC_RSLT10                               ADC_RSLT_REG(ADC_BASE_PTR,10)
#define ADC_RSLT11                               ADC_RSLT_REG(ADC_BASE_PTR,11)
#define ADC_RSLT12                               ADC_RSLT_REG(ADC_BASE_PTR,12)
#define ADC_RSLT13                               ADC_RSLT_REG(ADC_BASE_PTR,13)
#define ADC_RSLT14                               ADC_RSLT_REG(ADC_BASE_PTR,14)
#define ADC_RSLT15                               ADC_RSLT_REG(ADC_BASE_PTR,15)
#define ADC_LOLIM0                               ADC_LOLIM_REG(ADC_BASE_PTR,0)
#define ADC_LOLIM1                               ADC_LOLIM_REG(ADC_BASE_PTR,1)
#define ADC_LOLIM2                               ADC_LOLIM_REG(ADC_BASE_PTR,2)
#define ADC_LOLIM3                               ADC_LOLIM_REG(ADC_BASE_PTR,3)
#define ADC_LOLIM4                               ADC_LOLIM_REG(ADC_BASE_PTR,4)
#define ADC_LOLIM5                               ADC_LOLIM_REG(ADC_BASE_PTR,5)
#define ADC_LOLIM6                               ADC_LOLIM_REG(ADC_BASE_PTR,6)
#define ADC_LOLIM7                               ADC_LOLIM_REG(ADC_BASE_PTR,7)
#define ADC_LOLIM8                               ADC_LOLIM_REG(ADC_BASE_PTR,8)
#define ADC_LOLIM9                               ADC_LOLIM_REG(ADC_BASE_PTR,9)
#define ADC_LOLIM10                              ADC_LOLIM_REG(ADC_BASE_PTR,10)
#define ADC_LOLIM11                              ADC_LOLIM_REG(ADC_BASE_PTR,11)
#define ADC_LOLIM12                              ADC_LOLIM_REG(ADC_BASE_PTR,12)
#define ADC_LOLIM13                              ADC_LOLIM_REG(ADC_BASE_PTR,13)
#define ADC_LOLIM14                              ADC_LOLIM_REG(ADC_BASE_PTR,14)
#define ADC_LOLIM15                              ADC_LOLIM_REG(ADC_BASE_PTR,15)
#define ADC_HILIM0                               ADC_HILIM_REG(ADC_BASE_PTR,0)
#define ADC_HILIM1                               ADC_HILIM_REG(ADC_BASE_PTR,1)
#define ADC_HILIM2                               ADC_HILIM_REG(ADC_BASE_PTR,2)
#define ADC_HILIM3                               ADC_HILIM_REG(ADC_BASE_PTR,3)
#define ADC_HILIM4                               ADC_HILIM_REG(ADC_BASE_PTR,4)
#define ADC_HILIM5                               ADC_HILIM_REG(ADC_BASE_PTR,5)
#define ADC_HILIM6                               ADC_HILIM_REG(ADC_BASE_PTR,6)
#define ADC_HILIM7                               ADC_HILIM_REG(ADC_BASE_PTR,7)
#define ADC_HILIM8                               ADC_HILIM_REG(ADC_BASE_PTR,8)
#define ADC_HILIM9                               ADC_HILIM_REG(ADC_BASE_PTR,9)
#define ADC_HILIM10                              ADC_HILIM_REG(ADC_BASE_PTR,10)
#define ADC_HILIM11                              ADC_HILIM_REG(ADC_BASE_PTR,11)
#define ADC_HILIM12                              ADC_HILIM_REG(ADC_BASE_PTR,12)
#define ADC_HILIM13                              ADC_HILIM_REG(ADC_BASE_PTR,13)
#define ADC_HILIM14                              ADC_HILIM_REG(ADC_BASE_PTR,14)
#define ADC_HILIM15                              ADC_HILIM_REG(ADC_BASE_PTR,15)
#define ADC_OFFST0                               ADC_OFFST_REG(ADC_BASE_PTR,0)
#define ADC_OFFST1                               ADC_OFFST_REG(ADC_BASE_PTR,1)
#define ADC_OFFST2                               ADC_OFFST_REG(ADC_BASE_PTR,2)
#define ADC_OFFST3                               ADC_OFFST_REG(ADC_BASE_PTR,3)
#define ADC_OFFST4                               ADC_OFFST_REG(ADC_BASE_PTR,4)
#define ADC_OFFST5                               ADC_OFFST_REG(ADC_BASE_PTR,5)
#define ADC_OFFST6                               ADC_OFFST_REG(ADC_BASE_PTR,6)
#define ADC_OFFST7                               ADC_OFFST_REG(ADC_BASE_PTR,7)
#define ADC_OFFST8                               ADC_OFFST_REG(ADC_BASE_PTR,8)
#define ADC_OFFST9                               ADC_OFFST_REG(ADC_BASE_PTR,9)
#define ADC_OFFST10                              ADC_OFFST_REG(ADC_BASE_PTR,10)
#define ADC_OFFST11                              ADC_OFFST_REG(ADC_BASE_PTR,11)
#define ADC_OFFST12                              ADC_OFFST_REG(ADC_BASE_PTR,12)
#define ADC_OFFST13                              ADC_OFFST_REG(ADC_BASE_PTR,13)
#define ADC_OFFST14                              ADC_OFFST_REG(ADC_BASE_PTR,14)
#define ADC_OFFST15                              ADC_OFFST_REG(ADC_BASE_PTR,15)
#define ADC_PWR                                  ADC_PWR_REG(ADC_BASE_PTR)
#define ADC_CAL                                  ADC_CAL_REG(ADC_BASE_PTR)
#define ADC_GC1                                  ADC_GC1_REG(ADC_BASE_PTR)
#define ADC_GC2                                  ADC_GC2_REG(ADC_BASE_PTR)
#define ADC_SCTRL                                ADC_SCTRL_REG(ADC_BASE_PTR)
#define ADC_PWR2                                 ADC_PWR2_REG(ADC_BASE_PTR)
#define ADC_CTRL3                                ADC_CTRL3_REG(ADC_BASE_PTR)
#define ADC_SCHLTEN                              ADC_SCHLTEN_REG(ADC_BASE_PTR)

/* ADC - Register array accessors */
#define ADC_RSLT(index)                          ADC_RSLT_REG(ADC_BASE_PTR,index)
#define ADC_LOLIM(index)                         ADC_LOLIM_REG(ADC_BASE_PTR,index)
#define ADC_HILIM(index)                         ADC_HILIM_REG(ADC_BASE_PTR,index)
#define ADC_OFFST(index)                         ADC_OFFST_REG(ADC_BASE_PTR,index)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ADC_Peripheral */


/* ----------------------------------------------------------------------------
   -- AOI
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Peripheral AOI
 * @{
 */

/** AOI - Peripheral register structure */
typedef struct AOI_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x4 */
    uint16_t BFCRT01;                                /**< Boolean Function Term 0 and 1 Configuration Register for EVENTn, array offset: 0x0, array step: 0x4 */
    uint16_t BFCRT23;                                /**< Boolean Function Term 2 and 3 Configuration Register for EVENTn, array offset: 0x2, array step: 0x4 */
  } BFCRT[4];
} volatile *AOI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AOI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Register_Accessor_Macros AOI - Register accessor macros
 * @{
 */


/* AOI - Register accessors */
#define AOI_BFCRT01_REG(base,index)              ((base)->BFCRT[index].BFCRT01)
#define AOI_BFCRT23_REG(base,index)              ((base)->BFCRT[index].BFCRT23)

/*!
 * @}
 */ /* end of group AOI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AOI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Register_Masks AOI Register Masks
 * @{
 */

/* BFCRT01 Bit Fields */
#define AOI_BFCRT01_PT1_DC_MASK                  0x3u
#define AOI_BFCRT01_PT1_DC_SHIFT                 0
#define AOI_BFCRT01_PT1_DC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT1_DC_SHIFT))&AOI_BFCRT01_PT1_DC_MASK)
#define AOI_BFCRT01_PT1_CC_MASK                  0xCu
#define AOI_BFCRT01_PT1_CC_SHIFT                 2
#define AOI_BFCRT01_PT1_CC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT1_CC_SHIFT))&AOI_BFCRT01_PT1_CC_MASK)
#define AOI_BFCRT01_PT1_BC_MASK                  0x30u
#define AOI_BFCRT01_PT1_BC_SHIFT                 4
#define AOI_BFCRT01_PT1_BC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT1_BC_SHIFT))&AOI_BFCRT01_PT1_BC_MASK)
#define AOI_BFCRT01_PT1_AC_MASK                  0xC0u
#define AOI_BFCRT01_PT1_AC_SHIFT                 6
#define AOI_BFCRT01_PT1_AC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT1_AC_SHIFT))&AOI_BFCRT01_PT1_AC_MASK)
#define AOI_BFCRT01_PT0_DC_MASK                  0x300u
#define AOI_BFCRT01_PT0_DC_SHIFT                 8
#define AOI_BFCRT01_PT0_DC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT0_DC_SHIFT))&AOI_BFCRT01_PT0_DC_MASK)
#define AOI_BFCRT01_PT0_CC_MASK                  0xC00u
#define AOI_BFCRT01_PT0_CC_SHIFT                 10
#define AOI_BFCRT01_PT0_CC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT0_CC_SHIFT))&AOI_BFCRT01_PT0_CC_MASK)
#define AOI_BFCRT01_PT0_BC_MASK                  0x3000u
#define AOI_BFCRT01_PT0_BC_SHIFT                 12
#define AOI_BFCRT01_PT0_BC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT0_BC_SHIFT))&AOI_BFCRT01_PT0_BC_MASK)
#define AOI_BFCRT01_PT0_AC_MASK                  0xC000u
#define AOI_BFCRT01_PT0_AC_SHIFT                 14
#define AOI_BFCRT01_PT0_AC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT01_PT0_AC_SHIFT))&AOI_BFCRT01_PT0_AC_MASK)
/* BFCRT23 Bit Fields */
#define AOI_BFCRT23_PT3_DC_MASK                  0x3u
#define AOI_BFCRT23_PT3_DC_SHIFT                 0
#define AOI_BFCRT23_PT3_DC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT3_DC_SHIFT))&AOI_BFCRT23_PT3_DC_MASK)
#define AOI_BFCRT23_PT3_CC_MASK                  0xCu
#define AOI_BFCRT23_PT3_CC_SHIFT                 2
#define AOI_BFCRT23_PT3_CC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT3_CC_SHIFT))&AOI_BFCRT23_PT3_CC_MASK)
#define AOI_BFCRT23_PT3_BC_MASK                  0x30u
#define AOI_BFCRT23_PT3_BC_SHIFT                 4
#define AOI_BFCRT23_PT3_BC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT3_BC_SHIFT))&AOI_BFCRT23_PT3_BC_MASK)
#define AOI_BFCRT23_PT3_AC_MASK                  0xC0u
#define AOI_BFCRT23_PT3_AC_SHIFT                 6
#define AOI_BFCRT23_PT3_AC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT3_AC_SHIFT))&AOI_BFCRT23_PT3_AC_MASK)
#define AOI_BFCRT23_PT2_DC_MASK                  0x300u
#define AOI_BFCRT23_PT2_DC_SHIFT                 8
#define AOI_BFCRT23_PT2_DC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT2_DC_SHIFT))&AOI_BFCRT23_PT2_DC_MASK)
#define AOI_BFCRT23_PT2_CC_MASK                  0xC00u
#define AOI_BFCRT23_PT2_CC_SHIFT                 10
#define AOI_BFCRT23_PT2_CC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT2_CC_SHIFT))&AOI_BFCRT23_PT2_CC_MASK)
#define AOI_BFCRT23_PT2_BC_MASK                  0x3000u
#define AOI_BFCRT23_PT2_BC_SHIFT                 12
#define AOI_BFCRT23_PT2_BC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT2_BC_SHIFT))&AOI_BFCRT23_PT2_BC_MASK)
#define AOI_BFCRT23_PT2_AC_MASK                  0xC000u
#define AOI_BFCRT23_PT2_AC_SHIFT                 14
#define AOI_BFCRT23_PT2_AC(x)                    (((uint16_t)(((uint16_t)(x))<<AOI_BFCRT23_PT2_AC_SHIFT))&AOI_BFCRT23_PT2_AC_MASK)

/*!
 * @}
 */ /* end of group AOI_Register_Masks */


/* AOI - Peripheral instance base addresses */
/** Peripheral AOI base pointer */
#define AOI_BASE_PTR                             ((AOI_MemMapPtr)0x4005B000u)
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- AOI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Register_Accessor_Macros AOI - Register accessor macros
 * @{
 */


/* AOI - Register instance definitions */
/* AOI */
#define AOI_BFCRT010                             AOI_BFCRT01_REG(AOI_BASE_PTR,0)
#define AOI_BFCRT230                             AOI_BFCRT23_REG(AOI_BASE_PTR,0)
#define AOI_BFCRT011                             AOI_BFCRT01_REG(AOI_BASE_PTR,1)
#define AOI_BFCRT231                             AOI_BFCRT23_REG(AOI_BASE_PTR,1)
#define AOI_BFCRT012                             AOI_BFCRT01_REG(AOI_BASE_PTR,2)
#define AOI_BFCRT232                             AOI_BFCRT23_REG(AOI_BASE_PTR,2)
#define AOI_BFCRT013                             AOI_BFCRT01_REG(AOI_BASE_PTR,3)
#define AOI_BFCRT233                             AOI_BFCRT23_REG(AOI_BASE_PTR,3)

/* AOI - Register array accessors */
#define AOI_BFCRT01(index)                       AOI_BFCRT01_REG(AOI_BASE_PTR,index)
#define AOI_BFCRT23(index)                       AOI_BFCRT23_REG(AOI_BASE_PTR,index)

/*!
 * @}
 */ /* end of group AOI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group AOI_Peripheral */


/* ----------------------------------------------------------------------------
   -- CAN
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral CAN
 * @{
 */

/** CAN - Peripheral register structure */
typedef struct CAN_MemMap {
  uint32_t MCR;                                    /**< Module Configuration Register, offset: 0x0 */
  uint32_t CTRL1;                                  /**< Control 1 register, offset: 0x4 */
  uint32_t TIMER;                                  /**< Free Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t RXMGMASK;                               /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  uint32_t RX14MASK;                               /**< Rx 14 Mask register, offset: 0x14 */
  uint32_t RX15MASK;                               /**< Rx 15 Mask register, offset: 0x18 */
  uint32_t ECR;                                    /**< Error Counter, offset: 0x1C */
  uint32_t ESR1;                                   /**< Error and Status 1 register, offset: 0x20 */
  uint8_t RESERVED_1[4];
  uint32_t IMASK1;                                 /**< Interrupt Masks 1 register, offset: 0x28 */
  uint8_t RESERVED_2[4];
  uint32_t IFLAG1;                                 /**< Interrupt Flags 1 register, offset: 0x30 */
  uint32_t CTRL2;                                  /**< Control 2 register, offset: 0x34 */
  uint32_t ESR2;                                   /**< Error and Status 2 register, offset: 0x38 */
  uint8_t RESERVED_3[8];
  uint32_t CRCR;                                   /**< CRC Register, offset: 0x44 */
  uint32_t RXFGMASK;                               /**< Rx FIFO Global Mask register, offset: 0x48 */
  uint32_t RXFIR;                                  /**< Rx FIFO Information Register, offset: 0x4C */
  uint32_t CBT;                                    /**< CAN Bit Timing Register, offset: 0x50 */
  uint8_t RESERVED_4[44];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    uint32_t CS;                                     /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
    uint32_t ID;                                     /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
    uint32_t WORD0;                                  /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
    uint32_t WORD1;                                  /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
  } MB[16];
  uint8_t RESERVED_5[1792];
  uint32_t RXIMR[16];                              /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} volatile *CAN_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register accessors */
#define CAN_MCR_REG(base)                        ((base)->MCR)
#define CAN_CTRL1_REG(base)                      ((base)->CTRL1)
#define CAN_TIMER_REG(base)                      ((base)->TIMER)
#define CAN_RXMGMASK_REG(base)                   ((base)->RXMGMASK)
#define CAN_RX14MASK_REG(base)                   ((base)->RX14MASK)
#define CAN_RX15MASK_REG(base)                   ((base)->RX15MASK)
#define CAN_ECR_REG(base)                        ((base)->ECR)
#define CAN_ESR1_REG(base)                       ((base)->ESR1)
#define CAN_IMASK1_REG(base)                     ((base)->IMASK1)
#define CAN_IFLAG1_REG(base)                     ((base)->IFLAG1)
#define CAN_CTRL2_REG(base)                      ((base)->CTRL2)
#define CAN_ESR2_REG(base)                       ((base)->ESR2)
#define CAN_CRCR_REG(base)                       ((base)->CRCR)
#define CAN_RXFGMASK_REG(base)                   ((base)->RXFGMASK)
#define CAN_RXFIR_REG(base)                      ((base)->RXFIR)
#define CAN_CBT_REG(base)                        ((base)->CBT)
#define CAN_CS_REG(base,index)                   ((base)->MB[index].CS)
#define CAN_ID_REG(base,index)                   ((base)->MB[index].ID)
#define CAN_WORD0_REG(base,index)                ((base)->MB[index].WORD0)
#define CAN_WORD1_REG(base,index)                ((base)->MB[index].WORD1)
#define CAN_RXIMR_REG(base,index)                ((base)->RXIMR[index])

/*!
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/* MCR Bit Fields */
#define CAN_MCR_MAXMB_MASK                       0x7Fu
#define CAN_MCR_MAXMB_SHIFT                      0
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MAXMB_SHIFT))&CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        0x300u
#define CAN_MCR_IDAM_SHIFT                       8
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IDAM_SHIFT))&CAN_MCR_IDAM_MASK)
#define CAN_MCR_AEN_MASK                         0x1000u
#define CAN_MCR_AEN_SHIFT                        12
#define CAN_MCR_LPRIOEN_MASK                     0x2000u
#define CAN_MCR_LPRIOEN_SHIFT                    13
#define CAN_MCR_DMA_MASK                         0x8000u
#define CAN_MCR_DMA_SHIFT                        15
#define CAN_MCR_IRMQ_MASK                        0x10000u
#define CAN_MCR_IRMQ_SHIFT                       16
#define CAN_MCR_SRXDIS_MASK                      0x20000u
#define CAN_MCR_SRXDIS_SHIFT                     17
#define CAN_MCR_DOZE_MASK                        0x40000u
#define CAN_MCR_DOZE_SHIFT                       18
#define CAN_MCR_WAKSRC_MASK                      0x80000u
#define CAN_MCR_WAKSRC_SHIFT                     19
#define CAN_MCR_LPMACK_MASK                      0x100000u
#define CAN_MCR_LPMACK_SHIFT                     20
#define CAN_MCR_WRNEN_MASK                       0x200000u
#define CAN_MCR_WRNEN_SHIFT                      21
#define CAN_MCR_SLFWAK_MASK                      0x400000u
#define CAN_MCR_SLFWAK_SHIFT                     22
#define CAN_MCR_SUPV_MASK                        0x800000u
#define CAN_MCR_SUPV_SHIFT                       23
#define CAN_MCR_FRZACK_MASK                      0x1000000u
#define CAN_MCR_FRZACK_SHIFT                     24
#define CAN_MCR_SOFTRST_MASK                     0x2000000u
#define CAN_MCR_SOFTRST_SHIFT                    25
#define CAN_MCR_WAKMSK_MASK                      0x4000000u
#define CAN_MCR_WAKMSK_SHIFT                     26
#define CAN_MCR_NOTRDY_MASK                      0x8000000u
#define CAN_MCR_NOTRDY_SHIFT                     27
#define CAN_MCR_HALT_MASK                        0x10000000u
#define CAN_MCR_HALT_SHIFT                       28
#define CAN_MCR_RFEN_MASK                        0x20000000u
#define CAN_MCR_RFEN_SHIFT                       29
#define CAN_MCR_FRZ_MASK                         0x40000000u
#define CAN_MCR_FRZ_SHIFT                        30
#define CAN_MCR_MDIS_MASK                        0x80000000u
#define CAN_MCR_MDIS_SHIFT                       31
/* CTRL1 Bit Fields */
#define CAN_CTRL1_PROPSEG_MASK                   0x7u
#define CAN_CTRL1_PROPSEG_SHIFT                  0
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PROPSEG_SHIFT))&CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       0x8u
#define CAN_CTRL1_LOM_SHIFT                      3
#define CAN_CTRL1_LBUF_MASK                      0x10u
#define CAN_CTRL1_LBUF_SHIFT                     4
#define CAN_CTRL1_TSYN_MASK                      0x20u
#define CAN_CTRL1_TSYN_SHIFT                     5
#define CAN_CTRL1_BOFFREC_MASK                   0x40u
#define CAN_CTRL1_BOFFREC_SHIFT                  6
#define CAN_CTRL1_SMP_MASK                       0x80u
#define CAN_CTRL1_SMP_SHIFT                      7
#define CAN_CTRL1_RWRNMSK_MASK                   0x400u
#define CAN_CTRL1_RWRNMSK_SHIFT                  10
#define CAN_CTRL1_TWRNMSK_MASK                   0x800u
#define CAN_CTRL1_TWRNMSK_SHIFT                  11
#define CAN_CTRL1_LPB_MASK                       0x1000u
#define CAN_CTRL1_LPB_SHIFT                      12
#define CAN_CTRL1_CLKSRC_MASK                    0x2000u
#define CAN_CTRL1_CLKSRC_SHIFT                   13
#define CAN_CTRL1_ERRMSK_MASK                    0x4000u
#define CAN_CTRL1_ERRMSK_SHIFT                   14
#define CAN_CTRL1_BOFFMSK_MASK                   0x8000u
#define CAN_CTRL1_BOFFMSK_SHIFT                  15
#define CAN_CTRL1_PSEG2_MASK                     0x70000u
#define CAN_CTRL1_PSEG2_SHIFT                    16
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG2_SHIFT))&CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     0x380000u
#define CAN_CTRL1_PSEG1_SHIFT                    19
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG1_SHIFT))&CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       0xC00000u
#define CAN_CTRL1_RJW_SHIFT                      22
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RJW_SHIFT))&CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   0xFF000000u
#define CAN_CTRL1_PRESDIV_SHIFT                  24
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PRESDIV_SHIFT))&CAN_CTRL1_PRESDIV_MASK)
/* TIMER Bit Fields */
#define CAN_TIMER_TIMER_MASK                     0xFFFFu
#define CAN_TIMER_TIMER_SHIFT                    0
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_TIMER_TIMER_SHIFT))&CAN_TIMER_TIMER_MASK)
/* RXMGMASK Bit Fields */
#define CAN_RXMGMASK_MG_MASK                     0xFFFFFFFFu
#define CAN_RXMGMASK_MG_SHIFT                    0
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXMGMASK_MG_SHIFT))&CAN_RXMGMASK_MG_MASK)
/* RX14MASK Bit Fields */
#define CAN_RX14MASK_RX14M_MASK                  0xFFFFFFFFu
#define CAN_RX14MASK_RX14M_SHIFT                 0
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX14MASK_RX14M_SHIFT))&CAN_RX14MASK_RX14M_MASK)
/* RX15MASK Bit Fields */
#define CAN_RX15MASK_RX15M_MASK                  0xFFFFFFFFu
#define CAN_RX15MASK_RX15M_SHIFT                 0
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX15MASK_RX15M_SHIFT))&CAN_RX15MASK_RX15M_MASK)
/* ECR Bit Fields */
#define CAN_ECR_TXERRCNT_MASK                    0xFFu
#define CAN_ECR_TXERRCNT_SHIFT                   0
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_TXERRCNT_SHIFT))&CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    0xFF00u
#define CAN_ECR_RXERRCNT_SHIFT                   8
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_RXERRCNT_SHIFT))&CAN_ECR_RXERRCNT_MASK)
/* ESR1 Bit Fields */
#define CAN_ESR1_WAKINT_MASK                     0x1u
#define CAN_ESR1_WAKINT_SHIFT                    0
#define CAN_ESR1_ERRINT_MASK                     0x2u
#define CAN_ESR1_ERRINT_SHIFT                    1
#define CAN_ESR1_BOFFINT_MASK                    0x4u
#define CAN_ESR1_BOFFINT_SHIFT                   2
#define CAN_ESR1_RX_MASK                         0x8u
#define CAN_ESR1_RX_SHIFT                        3
#define CAN_ESR1_FLTCONF_MASK                    0x30u
#define CAN_ESR1_FLTCONF_SHIFT                   4
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FLTCONF_SHIFT))&CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         0x40u
#define CAN_ESR1_TX_SHIFT                        6
#define CAN_ESR1_IDLE_MASK                       0x80u
#define CAN_ESR1_IDLE_SHIFT                      7
#define CAN_ESR1_RXWRN_MASK                      0x100u
#define CAN_ESR1_RXWRN_SHIFT                     8
#define CAN_ESR1_TXWRN_MASK                      0x200u
#define CAN_ESR1_TXWRN_SHIFT                     9
#define CAN_ESR1_STFERR_MASK                     0x400u
#define CAN_ESR1_STFERR_SHIFT                    10
#define CAN_ESR1_FRMERR_MASK                     0x800u
#define CAN_ESR1_FRMERR_SHIFT                    11
#define CAN_ESR1_CRCERR_MASK                     0x1000u
#define CAN_ESR1_CRCERR_SHIFT                    12
#define CAN_ESR1_ACKERR_MASK                     0x2000u
#define CAN_ESR1_ACKERR_SHIFT                    13
#define CAN_ESR1_BIT0ERR_MASK                    0x4000u
#define CAN_ESR1_BIT0ERR_SHIFT                   14
#define CAN_ESR1_BIT1ERR_MASK                    0x8000u
#define CAN_ESR1_BIT1ERR_SHIFT                   15
#define CAN_ESR1_RWRNINT_MASK                    0x10000u
#define CAN_ESR1_RWRNINT_SHIFT                   16
#define CAN_ESR1_TWRNINT_MASK                    0x20000u
#define CAN_ESR1_TWRNINT_SHIFT                   17
#define CAN_ESR1_SYNCH_MASK                      0x40000u
#define CAN_ESR1_SYNCH_SHIFT                     18
#define CAN_ESR1_BOFFDONEINT_MASK                0x80000u
#define CAN_ESR1_BOFFDONEINT_SHIFT               19
#define CAN_ESR1_ERROVR_MASK                     0x200000u
#define CAN_ESR1_ERROVR_SHIFT                    21
/* IMASK1 Bit Fields */
#define CAN_IMASK1_BUF31TO0M_MASK                0xFFFFFFFFu
#define CAN_IMASK1_BUF31TO0M_SHIFT               0
#define CAN_IMASK1_BUF31TO0M(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IMASK1_BUF31TO0M_SHIFT))&CAN_IMASK1_BUF31TO0M_MASK)
/* IFLAG1 Bit Fields */
#define CAN_IFLAG1_BUF0I_MASK                    0x1u
#define CAN_IFLAG1_BUF0I_SHIFT                   0
#define CAN_IFLAG1_BUF4TO1I_MASK                 0x1Eu
#define CAN_IFLAG1_BUF4TO1I_SHIFT                1
#define CAN_IFLAG1_BUF4TO1I(x)                   (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF4TO1I_SHIFT))&CAN_IFLAG1_BUF4TO1I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    0x20u
#define CAN_IFLAG1_BUF5I_SHIFT                   5
#define CAN_IFLAG1_BUF6I_MASK                    0x40u
#define CAN_IFLAG1_BUF6I_SHIFT                   6
#define CAN_IFLAG1_BUF7I_MASK                    0x80u
#define CAN_IFLAG1_BUF7I_SHIFT                   7
#define CAN_IFLAG1_BUF31TO8I_MASK                0xFFFFFF00u
#define CAN_IFLAG1_BUF31TO8I_SHIFT               8
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF31TO8I_SHIFT))&CAN_IFLAG1_BUF31TO8I_MASK)
/* CTRL2 Bit Fields */
#define CAN_CTRL2_EACEN_MASK                     0x10000u
#define CAN_CTRL2_EACEN_SHIFT                    16
#define CAN_CTRL2_RRS_MASK                       0x20000u
#define CAN_CTRL2_RRS_SHIFT                      17
#define CAN_CTRL2_MRP_MASK                       0x40000u
#define CAN_CTRL2_MRP_SHIFT                      18
#define CAN_CTRL2_TASD_MASK                      0xF80000u
#define CAN_CTRL2_TASD_SHIFT                     19
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_TASD_SHIFT))&CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      0xF000000u
#define CAN_CTRL2_RFFN_SHIFT                     24
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RFFN_SHIFT))&CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_BOFFDONEMSK_MASK               0x40000000u
#define CAN_CTRL2_BOFFDONEMSK_SHIFT              30
/* ESR2 Bit Fields */
#define CAN_ESR2_IMB_MASK                        0x2000u
#define CAN_ESR2_IMB_SHIFT                       13
#define CAN_ESR2_VPS_MASK                        0x4000u
#define CAN_ESR2_VPS_SHIFT                       14
#define CAN_ESR2_LPTM_MASK                       0x7F0000u
#define CAN_ESR2_LPTM_SHIFT                      16
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_LPTM_SHIFT))&CAN_ESR2_LPTM_MASK)
/* CRCR Bit Fields */
#define CAN_CRCR_TXCRC_MASK                      0x7FFFu
#define CAN_CRCR_TXCRC_SHIFT                     0
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_TXCRC_SHIFT))&CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      0x7F0000u
#define CAN_CRCR_MBCRC_SHIFT                     16
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_MBCRC_SHIFT))&CAN_CRCR_MBCRC_MASK)
/* RXFGMASK Bit Fields */
#define CAN_RXFGMASK_FGM_MASK                    0xFFFFFFFFu
#define CAN_RXFGMASK_FGM_SHIFT                   0
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_RXFGMASK_FGM_SHIFT))&CAN_RXFGMASK_FGM_MASK)
/* RXFIR Bit Fields */
#define CAN_RXFIR_IDHIT_MASK                     0x1FFu
#define CAN_RXFIR_IDHIT_SHIFT                    0
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXFIR_IDHIT_SHIFT))&CAN_RXFIR_IDHIT_MASK)
/* CBT Bit Fields */
#define CAN_CBT_EPSEG2_MASK                      0x1Fu
#define CAN_CBT_EPSEG2_SHIFT                     0
#define CAN_CBT_EPSEG2(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPSEG2_SHIFT))&CAN_CBT_EPSEG2_MASK)
#define CAN_CBT_EPSEG1_MASK                      0x3E0u
#define CAN_CBT_EPSEG1_SHIFT                     5
#define CAN_CBT_EPSEG1(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPSEG1_SHIFT))&CAN_CBT_EPSEG1_MASK)
#define CAN_CBT_EPROPSEG_MASK                    0xFC00u
#define CAN_CBT_EPROPSEG_SHIFT                   10
#define CAN_CBT_EPROPSEG(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPROPSEG_SHIFT))&CAN_CBT_EPROPSEG_MASK)
#define CAN_CBT_ERJW_MASK                        0xF0000u
#define CAN_CBT_ERJW_SHIFT                       16
#define CAN_CBT_ERJW(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_CBT_ERJW_SHIFT))&CAN_CBT_ERJW_MASK)
#define CAN_CBT_EPRESDIV_MASK                    0x7FE00000u
#define CAN_CBT_EPRESDIV_SHIFT                   21
#define CAN_CBT_EPRESDIV(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPRESDIV_SHIFT))&CAN_CBT_EPRESDIV_MASK)
#define CAN_CBT_BTF_MASK                         0x80000000u
#define CAN_CBT_BTF_SHIFT                        31
/* CS Bit Fields */
#define CAN_CS_TIME_STAMP_MASK                   0xFFFFu
#define CAN_CS_TIME_STAMP_SHIFT                  0
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CS_TIME_STAMP_SHIFT))&CAN_CS_TIME_STAMP_MASK)
#define CAN_CS_DLC_MASK                          0xF0000u
#define CAN_CS_DLC_SHIFT                         16
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_DLC_SHIFT))&CAN_CS_DLC_MASK)
#define CAN_CS_RTR_MASK                          0x100000u
#define CAN_CS_RTR_SHIFT                         20
#define CAN_CS_IDE_MASK                          0x200000u
#define CAN_CS_IDE_SHIFT                         21
#define CAN_CS_SRR_MASK                          0x400000u
#define CAN_CS_SRR_SHIFT                         22
#define CAN_CS_CODE_MASK                         0xF000000u
#define CAN_CS_CODE_SHIFT                        24
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_CS_CODE_SHIFT))&CAN_CS_CODE_MASK)
#define CAN_CS_ESI_MASK                          0x20000000u
#define CAN_CS_ESI_SHIFT                         29
#define CAN_CS_BRS_MASK                          0x40000000u
#define CAN_CS_BRS_SHIFT                         30
#define CAN_CS_EDL_MASK                          0x80000000u
#define CAN_CS_EDL_SHIFT                         31
/* ID Bit Fields */
#define CAN_ID_EXT_MASK                          0x3FFFFu
#define CAN_ID_EXT_SHIFT                         0
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_EXT_SHIFT))&CAN_ID_EXT_MASK)
#define CAN_ID_STD_MASK                          0x1FFC0000u
#define CAN_ID_STD_SHIFT                         18
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_STD_SHIFT))&CAN_ID_STD_MASK)
#define CAN_ID_PRIO_MASK                         0xE0000000u
#define CAN_ID_PRIO_SHIFT                        29
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ID_PRIO_SHIFT))&CAN_ID_PRIO_MASK)
/* WORD0 Bit Fields */
#define CAN_WORD0_DATA_BYTE_3_MASK               0xFFu
#define CAN_WORD0_DATA_BYTE_3_SHIFT              0
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_3_SHIFT))&CAN_WORD0_DATA_BYTE_3_MASK)
#define CAN_WORD0_DATA_BYTE_2_MASK               0xFF00u
#define CAN_WORD0_DATA_BYTE_2_SHIFT              8
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_2_SHIFT))&CAN_WORD0_DATA_BYTE_2_MASK)
#define CAN_WORD0_DATA_BYTE_1_MASK               0xFF0000u
#define CAN_WORD0_DATA_BYTE_1_SHIFT              16
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_1_SHIFT))&CAN_WORD0_DATA_BYTE_1_MASK)
#define CAN_WORD0_DATA_BYTE_0_MASK               0xFF000000u
#define CAN_WORD0_DATA_BYTE_0_SHIFT              24
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_0_SHIFT))&CAN_WORD0_DATA_BYTE_0_MASK)
/* WORD1 Bit Fields */
#define CAN_WORD1_DATA_BYTE_7_MASK               0xFFu
#define CAN_WORD1_DATA_BYTE_7_SHIFT              0
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_7_SHIFT))&CAN_WORD1_DATA_BYTE_7_MASK)
#define CAN_WORD1_DATA_BYTE_6_MASK               0xFF00u
#define CAN_WORD1_DATA_BYTE_6_SHIFT              8
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_6_SHIFT))&CAN_WORD1_DATA_BYTE_6_MASK)
#define CAN_WORD1_DATA_BYTE_5_MASK               0xFF0000u
#define CAN_WORD1_DATA_BYTE_5_SHIFT              16
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_5_SHIFT))&CAN_WORD1_DATA_BYTE_5_MASK)
#define CAN_WORD1_DATA_BYTE_4_MASK               0xFF000000u
#define CAN_WORD1_DATA_BYTE_4_SHIFT              24
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_4_SHIFT))&CAN_WORD1_DATA_BYTE_4_MASK)
/* RXIMR Bit Fields */
#define CAN_RXIMR_MI_MASK                        0xFFFFFFFFu
#define CAN_RXIMR_MI_SHIFT                       0
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_RXIMR_MI_SHIFT))&CAN_RXIMR_MI_MASK)

/*!
 * @}
 */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base pointer */
#define CAN0_BASE_PTR                            ((CAN_MemMapPtr)0x40024000u)
/** Peripheral CAN1 base pointer */
#define CAN1_BASE_PTR                            ((CAN_MemMapPtr)0x40025000u)
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0_BASE_PTR, CAN1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register instance definitions */
/* CAN0 */
#define CAN0_MCR                                 CAN_MCR_REG(CAN0_BASE_PTR)
#define CAN0_CTRL1                               CAN_CTRL1_REG(CAN0_BASE_PTR)
#define CAN0_TIMER                               CAN_TIMER_REG(CAN0_BASE_PTR)
#define CAN0_RXMGMASK                            CAN_RXMGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RX14MASK                            CAN_RX14MASK_REG(CAN0_BASE_PTR)
#define CAN0_RX15MASK                            CAN_RX15MASK_REG(CAN0_BASE_PTR)
#define CAN0_ECR                                 CAN_ECR_REG(CAN0_BASE_PTR)
#define CAN0_ESR1                                CAN_ESR1_REG(CAN0_BASE_PTR)
#define CAN0_IMASK1                              CAN_IMASK1_REG(CAN0_BASE_PTR)
#define CAN0_IFLAG1                              CAN_IFLAG1_REG(CAN0_BASE_PTR)
#define CAN0_CTRL2                               CAN_CTRL2_REG(CAN0_BASE_PTR)
#define CAN0_ESR2                                CAN_ESR2_REG(CAN0_BASE_PTR)
#define CAN0_CRCR                                CAN_CRCR_REG(CAN0_BASE_PTR)
#define CAN0_RXFGMASK                            CAN_RXFGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RXFIR                               CAN_RXFIR_REG(CAN0_BASE_PTR)
#define CAN0_CBT                                 CAN_CBT_REG(CAN0_BASE_PTR)
#define CAN0_CS0                                 CAN_CS_REG(CAN0_BASE_PTR,0)
#define CAN0_ID0                                 CAN_ID_REG(CAN0_BASE_PTR,0)
#define CAN0_WORD00                              CAN_WORD0_REG(CAN0_BASE_PTR,0)
#define CAN0_WORD10                              CAN_WORD1_REG(CAN0_BASE_PTR,0)
#define CAN0_CS1                                 CAN_CS_REG(CAN0_BASE_PTR,1)
#define CAN0_ID1                                 CAN_ID_REG(CAN0_BASE_PTR,1)
#define CAN0_WORD01                              CAN_WORD0_REG(CAN0_BASE_PTR,1)
#define CAN0_WORD11                              CAN_WORD1_REG(CAN0_BASE_PTR,1)
#define CAN0_CS2                                 CAN_CS_REG(CAN0_BASE_PTR,2)
#define CAN0_ID2                                 CAN_ID_REG(CAN0_BASE_PTR,2)
#define CAN0_WORD02                              CAN_WORD0_REG(CAN0_BASE_PTR,2)
#define CAN0_WORD12                              CAN_WORD1_REG(CAN0_BASE_PTR,2)
#define CAN0_CS3                                 CAN_CS_REG(CAN0_BASE_PTR,3)
#define CAN0_ID3                                 CAN_ID_REG(CAN0_BASE_PTR,3)
#define CAN0_WORD03                              CAN_WORD0_REG(CAN0_BASE_PTR,3)
#define CAN0_WORD13                              CAN_WORD1_REG(CAN0_BASE_PTR,3)
#define CAN0_CS4                                 CAN_CS_REG(CAN0_BASE_PTR,4)
#define CAN0_ID4                                 CAN_ID_REG(CAN0_BASE_PTR,4)
#define CAN0_WORD04                              CAN_WORD0_REG(CAN0_BASE_PTR,4)
#define CAN0_WORD14                              CAN_WORD1_REG(CAN0_BASE_PTR,4)
#define CAN0_CS5                                 CAN_CS_REG(CAN0_BASE_PTR,5)
#define CAN0_ID5                                 CAN_ID_REG(CAN0_BASE_PTR,5)
#define CAN0_WORD05                              CAN_WORD0_REG(CAN0_BASE_PTR,5)
#define CAN0_WORD15                              CAN_WORD1_REG(CAN0_BASE_PTR,5)
#define CAN0_CS6                                 CAN_CS_REG(CAN0_BASE_PTR,6)
#define CAN0_ID6                                 CAN_ID_REG(CAN0_BASE_PTR,6)
#define CAN0_WORD06                              CAN_WORD0_REG(CAN0_BASE_PTR,6)
#define CAN0_WORD16                              CAN_WORD1_REG(CAN0_BASE_PTR,6)
#define CAN0_CS7                                 CAN_CS_REG(CAN0_BASE_PTR,7)
#define CAN0_ID7                                 CAN_ID_REG(CAN0_BASE_PTR,7)
#define CAN0_WORD07                              CAN_WORD0_REG(CAN0_BASE_PTR,7)
#define CAN0_WORD17                              CAN_WORD1_REG(CAN0_BASE_PTR,7)
#define CAN0_CS8                                 CAN_CS_REG(CAN0_BASE_PTR,8)
#define CAN0_ID8                                 CAN_ID_REG(CAN0_BASE_PTR,8)
#define CAN0_WORD08                              CAN_WORD0_REG(CAN0_BASE_PTR,8)
#define CAN0_WORD18                              CAN_WORD1_REG(CAN0_BASE_PTR,8)
#define CAN0_CS9                                 CAN_CS_REG(CAN0_BASE_PTR,9)
#define CAN0_ID9                                 CAN_ID_REG(CAN0_BASE_PTR,9)
#define CAN0_WORD09                              CAN_WORD0_REG(CAN0_BASE_PTR,9)
#define CAN0_WORD19                              CAN_WORD1_REG(CAN0_BASE_PTR,9)
#define CAN0_CS10                                CAN_CS_REG(CAN0_BASE_PTR,10)
#define CAN0_ID10                                CAN_ID_REG(CAN0_BASE_PTR,10)
#define CAN0_WORD010                             CAN_WORD0_REG(CAN0_BASE_PTR,10)
#define CAN0_WORD110                             CAN_WORD1_REG(CAN0_BASE_PTR,10)
#define CAN0_CS11                                CAN_CS_REG(CAN0_BASE_PTR,11)
#define CAN0_ID11                                CAN_ID_REG(CAN0_BASE_PTR,11)
#define CAN0_WORD011                             CAN_WORD0_REG(CAN0_BASE_PTR,11)
#define CAN0_WORD111                             CAN_WORD1_REG(CAN0_BASE_PTR,11)
#define CAN0_CS12                                CAN_CS_REG(CAN0_BASE_PTR,12)
#define CAN0_ID12                                CAN_ID_REG(CAN0_BASE_PTR,12)
#define CAN0_WORD012                             CAN_WORD0_REG(CAN0_BASE_PTR,12)
#define CAN0_WORD112                             CAN_WORD1_REG(CAN0_BASE_PTR,12)
#define CAN0_CS13                                CAN_CS_REG(CAN0_BASE_PTR,13)
#define CAN0_ID13                                CAN_ID_REG(CAN0_BASE_PTR,13)
#define CAN0_WORD013                             CAN_WORD0_REG(CAN0_BASE_PTR,13)
#define CAN0_WORD113                             CAN_WORD1_REG(CAN0_BASE_PTR,13)
#define CAN0_CS14                                CAN_CS_REG(CAN0_BASE_PTR,14)
#define CAN0_ID14                                CAN_ID_REG(CAN0_BASE_PTR,14)
#define CAN0_WORD014                             CAN_WORD0_REG(CAN0_BASE_PTR,14)
#define CAN0_WORD114                             CAN_WORD1_REG(CAN0_BASE_PTR,14)
#define CAN0_CS15                                CAN_CS_REG(CAN0_BASE_PTR,15)
#define CAN0_ID15                                CAN_ID_REG(CAN0_BASE_PTR,15)
#define CAN0_WORD015                             CAN_WORD0_REG(CAN0_BASE_PTR,15)
#define CAN0_WORD115                             CAN_WORD1_REG(CAN0_BASE_PTR,15)
#define CAN0_RXIMR0                              CAN_RXIMR_REG(CAN0_BASE_PTR,0)
#define CAN0_RXIMR1                              CAN_RXIMR_REG(CAN0_BASE_PTR,1)
#define CAN0_RXIMR2                              CAN_RXIMR_REG(CAN0_BASE_PTR,2)
#define CAN0_RXIMR3                              CAN_RXIMR_REG(CAN0_BASE_PTR,3)
#define CAN0_RXIMR4                              CAN_RXIMR_REG(CAN0_BASE_PTR,4)
#define CAN0_RXIMR5                              CAN_RXIMR_REG(CAN0_BASE_PTR,5)
#define CAN0_RXIMR6                              CAN_RXIMR_REG(CAN0_BASE_PTR,6)
#define CAN0_RXIMR7                              CAN_RXIMR_REG(CAN0_BASE_PTR,7)
#define CAN0_RXIMR8                              CAN_RXIMR_REG(CAN0_BASE_PTR,8)
#define CAN0_RXIMR9                              CAN_RXIMR_REG(CAN0_BASE_PTR,9)
#define CAN0_RXIMR10                             CAN_RXIMR_REG(CAN0_BASE_PTR,10)
#define CAN0_RXIMR11                             CAN_RXIMR_REG(CAN0_BASE_PTR,11)
#define CAN0_RXIMR12                             CAN_RXIMR_REG(CAN0_BASE_PTR,12)
#define CAN0_RXIMR13                             CAN_RXIMR_REG(CAN0_BASE_PTR,13)
#define CAN0_RXIMR14                             CAN_RXIMR_REG(CAN0_BASE_PTR,14)
#define CAN0_RXIMR15                             CAN_RXIMR_REG(CAN0_BASE_PTR,15)
/* CAN1 */
#define CAN1_MCR                                 CAN_MCR_REG(CAN1_BASE_PTR)
#define CAN1_CTRL1                               CAN_CTRL1_REG(CAN1_BASE_PTR)
#define CAN1_TIMER                               CAN_TIMER_REG(CAN1_BASE_PTR)
#define CAN1_RXMGMASK                            CAN_RXMGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RX14MASK                            CAN_RX14MASK_REG(CAN1_BASE_PTR)
#define CAN1_RX15MASK                            CAN_RX15MASK_REG(CAN1_BASE_PTR)
#define CAN1_ECR                                 CAN_ECR_REG(CAN1_BASE_PTR)
#define CAN1_ESR1                                CAN_ESR1_REG(CAN1_BASE_PTR)
#define CAN1_IMASK1                              CAN_IMASK1_REG(CAN1_BASE_PTR)
#define CAN1_IFLAG1                              CAN_IFLAG1_REG(CAN1_BASE_PTR)
#define CAN1_CTRL2                               CAN_CTRL2_REG(CAN1_BASE_PTR)
#define CAN1_ESR2                                CAN_ESR2_REG(CAN1_BASE_PTR)
#define CAN1_CRCR                                CAN_CRCR_REG(CAN1_BASE_PTR)
#define CAN1_RXFGMASK                            CAN_RXFGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RXFIR                               CAN_RXFIR_REG(CAN1_BASE_PTR)
#define CAN1_CBT                                 CAN_CBT_REG(CAN1_BASE_PTR)
#define CAN1_CS0                                 CAN_CS_REG(CAN1_BASE_PTR,0)
#define CAN1_ID0                                 CAN_ID_REG(CAN1_BASE_PTR,0)
#define CAN1_WORD00                              CAN_WORD0_REG(CAN1_BASE_PTR,0)
#define CAN1_WORD10                              CAN_WORD1_REG(CAN1_BASE_PTR,0)
#define CAN1_CS1                                 CAN_CS_REG(CAN1_BASE_PTR,1)
#define CAN1_ID1                                 CAN_ID_REG(CAN1_BASE_PTR,1)
#define CAN1_WORD01                              CAN_WORD0_REG(CAN1_BASE_PTR,1)
#define CAN1_WORD11                              CAN_WORD1_REG(CAN1_BASE_PTR,1)
#define CAN1_CS2                                 CAN_CS_REG(CAN1_BASE_PTR,2)
#define CAN1_ID2                                 CAN_ID_REG(CAN1_BASE_PTR,2)
#define CAN1_WORD02                              CAN_WORD0_REG(CAN1_BASE_PTR,2)
#define CAN1_WORD12                              CAN_WORD1_REG(CAN1_BASE_PTR,2)
#define CAN1_CS3                                 CAN_CS_REG(CAN1_BASE_PTR,3)
#define CAN1_ID3                                 CAN_ID_REG(CAN1_BASE_PTR,3)
#define CAN1_WORD03                              CAN_WORD0_REG(CAN1_BASE_PTR,3)
#define CAN1_WORD13                              CAN_WORD1_REG(CAN1_BASE_PTR,3)
#define CAN1_CS4                                 CAN_CS_REG(CAN1_BASE_PTR,4)
#define CAN1_ID4                                 CAN_ID_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD04                              CAN_WORD0_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD14                              CAN_WORD1_REG(CAN1_BASE_PTR,4)
#define CAN1_CS5                                 CAN_CS_REG(CAN1_BASE_PTR,5)
#define CAN1_ID5                                 CAN_ID_REG(CAN1_BASE_PTR,5)
#define CAN1_WORD05                              CAN_WORD0_REG(CAN1_BASE_PTR,5)
#define CAN1_WORD15                              CAN_WORD1_REG(CAN1_BASE_PTR,5)
#define CAN1_CS6                                 CAN_CS_REG(CAN1_BASE_PTR,6)
#define CAN1_ID6                                 CAN_ID_REG(CAN1_BASE_PTR,6)
#define CAN1_WORD06                              CAN_WORD0_REG(CAN1_BASE_PTR,6)
#define CAN1_WORD16                              CAN_WORD1_REG(CAN1_BASE_PTR,6)
#define CAN1_CS7                                 CAN_CS_REG(CAN1_BASE_PTR,7)
#define CAN1_ID7                                 CAN_ID_REG(CAN1_BASE_PTR,7)
#define CAN1_WORD07                              CAN_WORD0_REG(CAN1_BASE_PTR,7)
#define CAN1_WORD17                              CAN_WORD1_REG(CAN1_BASE_PTR,7)
#define CAN1_CS8                                 CAN_CS_REG(CAN1_BASE_PTR,8)
#define CAN1_ID8                                 CAN_ID_REG(CAN1_BASE_PTR,8)
#define CAN1_WORD08                              CAN_WORD0_REG(CAN1_BASE_PTR,8)
#define CAN1_WORD18                              CAN_WORD1_REG(CAN1_BASE_PTR,8)
#define CAN1_CS9                                 CAN_CS_REG(CAN1_BASE_PTR,9)
#define CAN1_ID9                                 CAN_ID_REG(CAN1_BASE_PTR,9)
#define CAN1_WORD09                              CAN_WORD0_REG(CAN1_BASE_PTR,9)
#define CAN1_WORD19                              CAN_WORD1_REG(CAN1_BASE_PTR,9)
#define CAN1_CS10                                CAN_CS_REG(CAN1_BASE_PTR,10)
#define CAN1_ID10                                CAN_ID_REG(CAN1_BASE_PTR,10)
#define CAN1_WORD010                             CAN_WORD0_REG(CAN1_BASE_PTR,10)
#define CAN1_WORD110                             CAN_WORD1_REG(CAN1_BASE_PTR,10)
#define CAN1_CS11                                CAN_CS_REG(CAN1_BASE_PTR,11)
#define CAN1_ID11                                CAN_ID_REG(CAN1_BASE_PTR,11)
#define CAN1_WORD011                             CAN_WORD0_REG(CAN1_BASE_PTR,11)
#define CAN1_WORD111                             CAN_WORD1_REG(CAN1_BASE_PTR,11)
#define CAN1_CS12                                CAN_CS_REG(CAN1_BASE_PTR,12)
#define CAN1_ID12                                CAN_ID_REG(CAN1_BASE_PTR,12)
#define CAN1_WORD012                             CAN_WORD0_REG(CAN1_BASE_PTR,12)
#define CAN1_WORD112                             CAN_WORD1_REG(CAN1_BASE_PTR,12)
#define CAN1_CS13                                CAN_CS_REG(CAN1_BASE_PTR,13)
#define CAN1_ID13                                CAN_ID_REG(CAN1_BASE_PTR,13)
#define CAN1_WORD013                             CAN_WORD0_REG(CAN1_BASE_PTR,13)
#define CAN1_WORD113                             CAN_WORD1_REG(CAN1_BASE_PTR,13)
#define CAN1_CS14                                CAN_CS_REG(CAN1_BASE_PTR,14)
#define CAN1_ID14                                CAN_ID_REG(CAN1_BASE_PTR,14)
#define CAN1_WORD014                             CAN_WORD0_REG(CAN1_BASE_PTR,14)
#define CAN1_WORD114                             CAN_WORD1_REG(CAN1_BASE_PTR,14)
#define CAN1_CS15                                CAN_CS_REG(CAN1_BASE_PTR,15)
#define CAN1_ID15                                CAN_ID_REG(CAN1_BASE_PTR,15)
#define CAN1_WORD015                             CAN_WORD0_REG(CAN1_BASE_PTR,15)
#define CAN1_WORD115                             CAN_WORD1_REG(CAN1_BASE_PTR,15)
#define CAN1_RXIMR0                              CAN_RXIMR_REG(CAN1_BASE_PTR,0)
#define CAN1_RXIMR1                              CAN_RXIMR_REG(CAN1_BASE_PTR,1)
#define CAN1_RXIMR2                              CAN_RXIMR_REG(CAN1_BASE_PTR,2)
#define CAN1_RXIMR3                              CAN_RXIMR_REG(CAN1_BASE_PTR,3)
#define CAN1_RXIMR4                              CAN_RXIMR_REG(CAN1_BASE_PTR,4)
#define CAN1_RXIMR5                              CAN_RXIMR_REG(CAN1_BASE_PTR,5)
#define CAN1_RXIMR6                              CAN_RXIMR_REG(CAN1_BASE_PTR,6)
#define CAN1_RXIMR7                              CAN_RXIMR_REG(CAN1_BASE_PTR,7)
#define CAN1_RXIMR8                              CAN_RXIMR_REG(CAN1_BASE_PTR,8)
#define CAN1_RXIMR9                              CAN_RXIMR_REG(CAN1_BASE_PTR,9)
#define CAN1_RXIMR10                             CAN_RXIMR_REG(CAN1_BASE_PTR,10)
#define CAN1_RXIMR11                             CAN_RXIMR_REG(CAN1_BASE_PTR,11)
#define CAN1_RXIMR12                             CAN_RXIMR_REG(CAN1_BASE_PTR,12)
#define CAN1_RXIMR13                             CAN_RXIMR_REG(CAN1_BASE_PTR,13)
#define CAN1_RXIMR14                             CAN_RXIMR_REG(CAN1_BASE_PTR,14)
#define CAN1_RXIMR15                             CAN_RXIMR_REG(CAN1_BASE_PTR,15)

/* CAN - Register array accessors */
#define CAN0_CS(index)                           CAN_CS_REG(CAN0_BASE_PTR,index)
#define CAN1_CS(index)                           CAN_CS_REG(CAN1_BASE_PTR,index)
#define CAN0_ID(index)                           CAN_ID_REG(CAN0_BASE_PTR,index)
#define CAN1_ID(index)                           CAN_ID_REG(CAN1_BASE_PTR,index)
#define CAN0_WORD0(index)                        CAN_WORD0_REG(CAN0_BASE_PTR,index)
#define CAN1_WORD0(index)                        CAN_WORD0_REG(CAN1_BASE_PTR,index)
#define CAN0_WORD1(index)                        CAN_WORD1_REG(CAN0_BASE_PTR,index)
#define CAN1_WORD1(index)                        CAN_WORD1_REG(CAN1_BASE_PTR,index)
#define CAN0_RXIMR(index)                        CAN_RXIMR_REG(CAN0_BASE_PTR,index)
#define CAN1_RXIMR(index)                        CAN_RXIMR_REG(CAN1_BASE_PTR,index)

/*!
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CAN_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMP
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Peripheral CMP
 * @{
 */

/** CMP - Peripheral register structure */
typedef struct CMP_MemMap {
  uint8_t CR0;                                     /**< CMP Control Register 0, offset: 0x0 */
  uint8_t CR1;                                     /**< CMP Control Register 1, offset: 0x1 */
  uint8_t FPR;                                     /**< CMP Filter Period Register, offset: 0x2 */
  uint8_t SCR;                                     /**< CMP Status and Control Register, offset: 0x3 */
  uint8_t DACCR;                                   /**< DAC Control Register, offset: 0x4 */
  uint8_t MUXCR;                                   /**< MUX Control Register, offset: 0x5 */
} volatile *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register accessors */
#define CMP_CR0_REG(base)                        ((base)->CR0)
#define CMP_CR1_REG(base)                        ((base)->CR1)
#define CMP_FPR_REG(base)                        ((base)->FPR)
#define CMP_SCR_REG(base)                        ((base)->SCR)
#define CMP_DACCR_REG(base)                      ((base)->DACCR)
#define CMP_MUXCR_REG(base)                      ((base)->MUXCR)

/*!
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/* CR0 Bit Fields */
#define CMP_CR0_HYSTCTR_MASK                     0x3u
#define CMP_CR0_HYSTCTR_SHIFT                    0
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_TRIGM_MASK                       0x20u
#define CMP_CR1_TRIGM_SHIFT                      5
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK)

/*!
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base pointer */
#define CMP0_BASE_PTR                            ((CMP_MemMapPtr)0x40073000u)
/** Peripheral CMP1 base pointer */
#define CMP1_BASE_PTR                            ((CMP_MemMapPtr)0x40073008u)
/** Peripheral CMP2 base pointer */
#define CMP2_BASE_PTR                            ((CMP_MemMapPtr)0x40073010u)
/** Peripheral CMP3 base pointer */
#define CMP3_BASE_PTR                            ((CMP_MemMapPtr)0x40073018u)
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0_BASE_PTR, CMP1_BASE_PTR, CMP2_BASE_PTR, CMP3_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register instance definitions */
/* CMP0 */
#define CMP0_CR0                                 CMP_CR0_REG(CMP0_BASE_PTR)
#define CMP0_CR1                                 CMP_CR1_REG(CMP0_BASE_PTR)
#define CMP0_FPR                                 CMP_FPR_REG(CMP0_BASE_PTR)
#define CMP0_SCR                                 CMP_SCR_REG(CMP0_BASE_PTR)
#define CMP0_DACCR                               CMP_DACCR_REG(CMP0_BASE_PTR)
#define CMP0_MUXCR                               CMP_MUXCR_REG(CMP0_BASE_PTR)
/* CMP1 */
#define CMP1_CR0                                 CMP_CR0_REG(CMP1_BASE_PTR)
#define CMP1_CR1                                 CMP_CR1_REG(CMP1_BASE_PTR)
#define CMP1_FPR                                 CMP_FPR_REG(CMP1_BASE_PTR)
#define CMP1_SCR                                 CMP_SCR_REG(CMP1_BASE_PTR)
#define CMP1_DACCR                               CMP_DACCR_REG(CMP1_BASE_PTR)
#define CMP1_MUXCR                               CMP_MUXCR_REG(CMP1_BASE_PTR)
/* CMP2 */
#define CMP2_CR0                                 CMP_CR0_REG(CMP2_BASE_PTR)
#define CMP2_CR1                                 CMP_CR1_REG(CMP2_BASE_PTR)
#define CMP2_FPR                                 CMP_FPR_REG(CMP2_BASE_PTR)
#define CMP2_SCR                                 CMP_SCR_REG(CMP2_BASE_PTR)
#define CMP2_DACCR                               CMP_DACCR_REG(CMP2_BASE_PTR)
#define CMP2_MUXCR                               CMP_MUXCR_REG(CMP2_BASE_PTR)
/* CMP3 */
#define CMP3_CR0                                 CMP_CR0_REG(CMP3_BASE_PTR)
#define CMP3_CR1                                 CMP_CR1_REG(CMP3_BASE_PTR)
#define CMP3_FPR                                 CMP_FPR_REG(CMP3_BASE_PTR)
#define CMP3_SCR                                 CMP_SCR_REG(CMP3_BASE_PTR)
#define CMP3_DACCR                               CMP_DACCR_REG(CMP3_BASE_PTR)
#define CMP3_MUXCR                               CMP_MUXCR_REG(CMP3_BASE_PTR)

/*!
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CMP_Peripheral */


/* ----------------------------------------------------------------------------
   -- CRC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral CRC
 * @{
 */

/** CRC - Peripheral register structure */
typedef struct CRC_MemMap {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint16_t DATAL;                                  /**< CRC_DATAL register., offset: 0x0 */
      uint16_t DATAH;                                  /**< CRC_DATAH register., offset: 0x2 */
    } ACCESS16BIT;
    uint32_t DATA;                                   /**< CRC Data register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint8_t DATALL;                                  /**< CRC_DATALL register., offset: 0x0 */
      uint8_t DATALU;                                  /**< CRC_DATALU register., offset: 0x1 */
      uint8_t DATAHL;                                  /**< CRC_DATAHL register., offset: 0x2 */
      uint8_t DATAHU;                                  /**< CRC_DATAHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint16_t GPOLYL;                                 /**< CRC_GPOLYL register., offset: 0x4 */
      uint16_t GPOLYH;                                 /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    uint32_t GPOLY;                                  /**< CRC Polynomial register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint8_t GPOLYLL;                                 /**< CRC_GPOLYLL register., offset: 0x4 */
      uint8_t GPOLYLU;                                 /**< CRC_GPOLYLU register., offset: 0x5 */
      uint8_t GPOLYHL;                                 /**< CRC_GPOLYHL register., offset: 0x6 */
      uint8_t GPOLYHU;                                 /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    uint32_t CTRL;                                   /**< CRC Control register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
      uint8_t RESERVED_0[3];
      uint8_t CTRLHU;                                  /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} volatile *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register accessors */
#define CRC_DATAL_REG(base)                      ((base)->ACCESS16BIT.DATAL)
#define CRC_DATAH_REG(base)                      ((base)->ACCESS16BIT.DATAH)
#define CRC_DATA_REG(base)                       ((base)->DATA)
#define CRC_DATALL_REG(base)                     ((base)->ACCESS8BIT.DATALL)
#define CRC_DATALU_REG(base)                     ((base)->ACCESS8BIT.DATALU)
#define CRC_DATAHL_REG(base)                     ((base)->ACCESS8BIT.DATAHL)
#define CRC_DATAHU_REG(base)                     ((base)->ACCESS8BIT.DATAHU)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYL)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYH)
#define CRC_GPOLY_REG(base)                      ((base)->GPOLY)
#define CRC_GPOLYLL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLL)
#define CRC_GPOLYLU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLU)
#define CRC_GPOLYHL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHL)
#define CRC_GPOLYHU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHU)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)
#define CRC_CTRLHU_REG(base)                     ((base)->CTRL_ACCESS8BIT.CTRLHU)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/* DATAL Bit Fields */
#define CRC_DATAL_DATAL_MASK                     0xFFFFu
#define CRC_DATAL_DATAL_SHIFT                    0
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK)
/* DATAH Bit Fields */
#define CRC_DATAH_DATAH_MASK                     0xFFFFu
#define CRC_DATAH_DATAH_SHIFT                    0
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK)
/* DATA Bit Fields */
#define CRC_DATA_LL_MASK                         0xFFu
#define CRC_DATA_LL_SHIFT                        0
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         0xFF00u
#define CRC_DATA_LU_SHIFT                        8
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         0xFF0000u
#define CRC_DATA_HL_SHIFT                        16
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         0xFF000000u
#define CRC_DATA_HU_SHIFT                        24
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK)
/* DATALL Bit Fields */
#define CRC_DATALL_DATALL_MASK                   0xFFu
#define CRC_DATALL_DATALL_SHIFT                  0
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK)
/* DATALU Bit Fields */
#define CRC_DATALU_DATALU_MASK                   0xFFu
#define CRC_DATALU_DATALU_SHIFT                  0
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK)
/* DATAHL Bit Fields */
#define CRC_DATAHL_DATAHL_MASK                   0xFFu
#define CRC_DATAHL_DATAHL_SHIFT                  0
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK)
/* DATAHU Bit Fields */
#define CRC_DATAHU_DATAHU_MASK                   0xFFu
#define CRC_DATAHU_DATAHU_SHIFT                  0
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x1000000u
#define CRC_CTRL_TCRC_SHIFT                      24
#define CRC_CTRL_WAS_MASK                        0x2000000u
#define CRC_CTRL_WAS_SHIFT                       25
#define CRC_CTRL_FXOR_MASK                       0x4000000u
#define CRC_CTRL_FXOR_SHIFT                      26
#define CRC_CTRL_TOTR_MASK                       0x30000000u
#define CRC_CTRL_TOTR_SHIFT                      28
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0000000u
#define CRC_CTRL_TOT_SHIFT                       30
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base pointer */
#define CRC_BASE_PTR                             ((CRC_MemMapPtr)0x40032000u)
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_DATA                                 CRC_DATA_REG(CRC_BASE_PTR)
#define CRC_DATAL                                CRC_DATAL_REG(CRC_BASE_PTR)
#define CRC_DATALL                               CRC_DATALL_REG(CRC_BASE_PTR)
#define CRC_DATALU                               CRC_DATALU_REG(CRC_BASE_PTR)
#define CRC_DATAH                                CRC_DATAH_REG(CRC_BASE_PTR)
#define CRC_DATAHL                               CRC_DATAHL_REG(CRC_BASE_PTR)
#define CRC_DATAHU                               CRC_DATAHU_REG(CRC_BASE_PTR)
#define CRC_GPOLY                                CRC_GPOLY_REG(CRC_BASE_PTR)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC_BASE_PTR)
#define CRC_GPOLYLL                              CRC_GPOLYLL_REG(CRC_BASE_PTR)
#define CRC_GPOLYLU                              CRC_GPOLYLU_REG(CRC_BASE_PTR)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC_BASE_PTR)
#define CRC_GPOLYHL                              CRC_GPOLYHL_REG(CRC_BASE_PTR)
#define CRC_GPOLYHU                              CRC_GPOLYHU_REG(CRC_BASE_PTR)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC_BASE_PTR)
#define CRC_CTRLHU                               CRC_CTRLHU_REG(CRC_BASE_PTR)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CRC_Peripheral */


/* ----------------------------------------------------------------------------
   -- CoreDebug
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CoreDebug_Peripheral CoreDebug
 * @{
 */

/** CoreDebug - Peripheral register structure */
typedef struct CoreDebug_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t base_DHCSR_Read;                        /**< Debug Halting Control and Status Register, offset: 0x0 */
    uint32_t base_DHCSR_Write;                       /**< Debug Halting Control and Status Register, offset: 0x0 */
  };
  uint32_t base_DCRSR;                             /**< Debug Core Register Selector Register, offset: 0x4 */
  uint32_t base_DCRDR;                             /**< Debug Core Register Data Register, offset: 0x8 */
  uint32_t base_DEMCR;                             /**< Debug Exception and Monitor Control Register, offset: 0xC */
} volatile *CoreDebug_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register accessors */
#define CoreDebug_base_DHCSR_Read_REG(base)      ((base)->base_DHCSR_Read)
#define CoreDebug_base_DHCSR_Write_REG(base)     ((base)->base_DHCSR_Write)
#define CoreDebug_base_DCRSR_REG(base)           ((base)->base_DCRSR)
#define CoreDebug_base_DCRDR_REG(base)           ((base)->base_DCRDR)
#define CoreDebug_base_DEMCR_REG(base)           ((base)->base_DEMCR)

/*!
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CoreDebug Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CoreDebug_Register_Masks CoreDebug Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group CoreDebug_Register_Masks */


/* CoreDebug - Peripheral instance base addresses */
/** Peripheral CoreDebug base pointer */
#define CoreDebug_BASE_PTR                       ((CoreDebug_MemMapPtr)0xE000EDF0u)
/** Array initializer of CoreDebug peripheral base pointers */
#define CoreDebug_BASE_PTRS                      { CoreDebug_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register instance definitions */
/* CoreDebug */
#define DHCSR_Read                               CoreDebug_base_DHCSR_Read_REG(CoreDebug_BASE_PTR)
#define DHCSR_Write                              CoreDebug_base_DHCSR_Write_REG(CoreDebug_BASE_PTR)
#define DCRSR                                    CoreDebug_base_DCRSR_REG(CoreDebug_BASE_PTR)
#define DCRDR                                    CoreDebug_base_DCRDR_REG(CoreDebug_BASE_PTR)
#define DEMCR                                    CoreDebug_base_DEMCR_REG(CoreDebug_BASE_PTR)

/*!
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CoreDebug_Peripheral */


/* ----------------------------------------------------------------------------
   -- DAC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral DAC
 * @{
 */

/** DAC - Peripheral register structure */
typedef struct DAC_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    uint8_t DATL;                                    /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    uint8_t DATH;                                    /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  uint8_t SR;                                      /**< DAC Status Register, offset: 0x20 */
  uint8_t C0;                                      /**< DAC Control Register, offset: 0x21 */
  uint8_t C1;                                      /**< DAC Control Register 1, offset: 0x22 */
  uint8_t C2;                                      /**< DAC Control Register 2, offset: 0x23 */
} volatile *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register accessors */
#define DAC_DATL_REG(base,index)                 ((base)->DAT[index].DATL)
#define DAC_DATH_REG(base,index)                 ((base)->DAT[index].DATH)
#define DAC_SR_REG(base)                         ((base)->SR)
#define DAC_C0_REG(base)                         ((base)->C0)
#define DAC_C1_REG(base)                         ((base)->C1)
#define DAC_C2_REG(base)                         ((base)->C2)

/*!
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/* DATL Bit Fields */
#define DAC_DATL_DATA0_MASK                      0xFFu
#define DAC_DATL_DATA0_SHIFT                     0
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA0_SHIFT))&DAC_DATL_DATA0_MASK)
/* DATH Bit Fields */
#define DAC_DATH_DATA1_MASK                      0xFu
#define DAC_DATH_DATA1_SHIFT                     0
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA1_SHIFT))&DAC_DATH_DATA1_MASK)
/* SR Bit Fields */
#define DAC_SR_DACBFRPBF_MASK                    0x1u
#define DAC_SR_DACBFRPBF_SHIFT                   0
#define DAC_SR_DACBFRPTF_MASK                    0x2u
#define DAC_SR_DACBFRPTF_SHIFT                   1
#define DAC_SR_DACBFWMF_MASK                     0x4u
#define DAC_SR_DACBFWMF_SHIFT                    2
/* C0 Bit Fields */
#define DAC_C0_DACBBIEN_MASK                     0x1u
#define DAC_C0_DACBBIEN_SHIFT                    0
#define DAC_C0_DACBTIEN_MASK                     0x2u
#define DAC_C0_DACBTIEN_SHIFT                    1
#define DAC_C0_DACBWIEN_MASK                     0x4u
#define DAC_C0_DACBWIEN_SHIFT                    2
#define DAC_C0_LPEN_MASK                         0x8u
#define DAC_C0_LPEN_SHIFT                        3
#define DAC_C0_DACSWTRG_MASK                     0x10u
#define DAC_C0_DACSWTRG_SHIFT                    4
#define DAC_C0_DACTRGSEL_MASK                    0x20u
#define DAC_C0_DACTRGSEL_SHIFT                   5
#define DAC_C0_DACRFS_MASK                       0x40u
#define DAC_C0_DACRFS_SHIFT                      6
#define DAC_C0_DACEN_MASK                        0x80u
#define DAC_C0_DACEN_SHIFT                       7
/* C1 Bit Fields */
#define DAC_C1_DACBFEN_MASK                      0x1u
#define DAC_C1_DACBFEN_SHIFT                     0
#define DAC_C1_DACBFMD_MASK                      0x6u
#define DAC_C1_DACBFMD_SHIFT                     1
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      0x18u
#define DAC_C1_DACBFWM_SHIFT                     3
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        0x80u
#define DAC_C1_DMAEN_SHIFT                       7
/* C2 Bit Fields */
#define DAC_C2_DACBFUP_MASK                      0xFu
#define DAC_C2_DACBFUP_SHIFT                     0
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      0xF0u
#define DAC_C2_DACBFRP_SHIFT                     4
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK)

/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC base pointer */
#define DAC_BASE_PTR                             ((DAC_MemMapPtr)0x4003F000u)
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register instance definitions */
/* DAC */
#define DAC_DAT0L                                DAC_DATL_REG(DAC_BASE_PTR,0)
#define DAC_DAT0H                                DAC_DATH_REG(DAC_BASE_PTR,0)
#define DAC_DAT1L                                DAC_DATL_REG(DAC_BASE_PTR,1)
#define DAC_DAT1H                                DAC_DATH_REG(DAC_BASE_PTR,1)
#define DAC_DAT2L                                DAC_DATL_REG(DAC_BASE_PTR,2)
#define DAC_DAT2H                                DAC_DATH_REG(DAC_BASE_PTR,2)
#define DAC_DAT3L                                DAC_DATL_REG(DAC_BASE_PTR,3)
#define DAC_DAT3H                                DAC_DATH_REG(DAC_BASE_PTR,3)
#define DAC_DAT4L                                DAC_DATL_REG(DAC_BASE_PTR,4)
#define DAC_DAT4H                                DAC_DATH_REG(DAC_BASE_PTR,4)
#define DAC_DAT5L                                DAC_DATL_REG(DAC_BASE_PTR,5)
#define DAC_DAT5H                                DAC_DATH_REG(DAC_BASE_PTR,5)
#define DAC_DAT6L                                DAC_DATL_REG(DAC_BASE_PTR,6)
#define DAC_DAT6H                                DAC_DATH_REG(DAC_BASE_PTR,6)
#define DAC_DAT7L                                DAC_DATL_REG(DAC_BASE_PTR,7)
#define DAC_DAT7H                                DAC_DATH_REG(DAC_BASE_PTR,7)
#define DAC_DAT8L                                DAC_DATL_REG(DAC_BASE_PTR,8)
#define DAC_DAT8H                                DAC_DATH_REG(DAC_BASE_PTR,8)
#define DAC_DAT9L                                DAC_DATL_REG(DAC_BASE_PTR,9)
#define DAC_DAT9H                                DAC_DATH_REG(DAC_BASE_PTR,9)
#define DAC_DAT10L                               DAC_DATL_REG(DAC_BASE_PTR,10)
#define DAC_DAT10H                               DAC_DATH_REG(DAC_BASE_PTR,10)
#define DAC_DAT11L                               DAC_DATL_REG(DAC_BASE_PTR,11)
#define DAC_DAT11H                               DAC_DATH_REG(DAC_BASE_PTR,11)
#define DAC_DAT12L                               DAC_DATL_REG(DAC_BASE_PTR,12)
#define DAC_DAT12H                               DAC_DATH_REG(DAC_BASE_PTR,12)
#define DAC_DAT13L                               DAC_DATL_REG(DAC_BASE_PTR,13)
#define DAC_DAT13H                               DAC_DATH_REG(DAC_BASE_PTR,13)
#define DAC_DAT14L                               DAC_DATL_REG(DAC_BASE_PTR,14)
#define DAC_DAT14H                               DAC_DATH_REG(DAC_BASE_PTR,14)
#define DAC_DAT15L                               DAC_DATL_REG(DAC_BASE_PTR,15)
#define DAC_DAT15H                               DAC_DATH_REG(DAC_BASE_PTR,15)
#define DAC_SR                                   DAC_SR_REG(DAC_BASE_PTR)
#define DAC_C0                                   DAC_C0_REG(DAC_BASE_PTR)
#define DAC_C1                                   DAC_C1_REG(DAC_BASE_PTR)
#define DAC_C2                                   DAC_C2_REG(DAC_BASE_PTR)

/* DAC - Register array accessors */
#define DAC_DATL(index)                          DAC_DATL_REG(DAC_BASE_PTR,index)
#define DAC_DATH(index)                          DAC_DATH_REG(DAC_BASE_PTR,index)

/*!
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DAC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMA
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral DMA
 * @{
 */

/** DMA - Peripheral register structure */
typedef struct DMA_MemMap {
  uint32_t CR;                                     /**< Control Register, offset: 0x0 */
  uint32_t ES;                                     /**< Error Status Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  uint32_t ERQ;                                    /**< Enable Request Register, offset: 0xC */
  uint8_t RESERVED_1[4];
  uint32_t EEI;                                    /**< Enable Error Interrupt Register, offset: 0x14 */
  uint8_t CEEI;                                    /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  uint8_t SEEI;                                    /**< Set Enable Error Interrupt Register, offset: 0x19 */
  uint8_t CERQ;                                    /**< Clear Enable Request Register, offset: 0x1A */
  uint8_t SERQ;                                    /**< Set Enable Request Register, offset: 0x1B */
  uint8_t CDNE;                                    /**< Clear DONE Status Bit Register, offset: 0x1C */
  uint8_t SSRT;                                    /**< Set START Bit Register, offset: 0x1D */
  uint8_t CERR;                                    /**< Clear Error Register, offset: 0x1E */
  uint8_t CINT;                                    /**< Clear Interrupt Request Register, offset: 0x1F */
  uint8_t RESERVED_2[4];
  uint32_t INT;                                    /**< Interrupt Request Register, offset: 0x24 */
  uint8_t RESERVED_3[4];
  uint32_t ERR;                                    /**< Error Register, offset: 0x2C */
  uint8_t RESERVED_4[4];
  uint32_t HRS;                                    /**< Hardware Request Status Register, offset: 0x34 */
  uint8_t RESERVED_5[12];
  uint32_t EARS;                                   /**< Enable Asynchronous Request in Stop Register, offset: 0x44 */
  uint8_t RESERVED_6[184];
  uint8_t DCHPRI3;                                 /**< Channel n Priority Register, offset: 0x100 */
  uint8_t DCHPRI2;                                 /**< Channel n Priority Register, offset: 0x101 */
  uint8_t DCHPRI1;                                 /**< Channel n Priority Register, offset: 0x102 */
  uint8_t DCHPRI0;                                 /**< Channel n Priority Register, offset: 0x103 */
  uint8_t DCHPRI7;                                 /**< Channel n Priority Register, offset: 0x104 */
  uint8_t DCHPRI6;                                 /**< Channel n Priority Register, offset: 0x105 */
  uint8_t DCHPRI5;                                 /**< Channel n Priority Register, offset: 0x106 */
  uint8_t DCHPRI4;                                 /**< Channel n Priority Register, offset: 0x107 */
  uint8_t DCHPRI11;                                /**< Channel n Priority Register, offset: 0x108 */
  uint8_t DCHPRI10;                                /**< Channel n Priority Register, offset: 0x109 */
  uint8_t DCHPRI9;                                 /**< Channel n Priority Register, offset: 0x10A */
  uint8_t DCHPRI8;                                 /**< Channel n Priority Register, offset: 0x10B */
  uint8_t DCHPRI15;                                /**< Channel n Priority Register, offset: 0x10C */
  uint8_t DCHPRI14;                                /**< Channel n Priority Register, offset: 0x10D */
  uint8_t DCHPRI13;                                /**< Channel n Priority Register, offset: 0x10E */
  uint8_t DCHPRI12;                                /**< Channel n Priority Register, offset: 0x10F */
  uint8_t RESERVED_7[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    uint32_t SADDR;                                  /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    uint16_t SOFF;                                   /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    uint16_t ATTR;                                   /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLNO;                            /**< TCD Minor Byte Count (Minor Loop Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFNO;                         /**< TCD Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFYES;                        /**< TCD Signed Minor Loop Offset (Minor Loop and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    uint32_t SLAST;                                  /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    uint32_t DADDR;                                  /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    uint16_t DOFF;                                   /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKNO;                          /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKYES;                         /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    uint32_t DLAST_SGA;                              /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    uint16_t CSR;                                    /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKNO;                          /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKYES;                         /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} volatile *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register accessors */
#define DMA_CR_REG(base)                         ((base)->CR)
#define DMA_ES_REG(base)                         ((base)->ES)
#define DMA_ERQ_REG(base)                        ((base)->ERQ)
#define DMA_EEI_REG(base)                        ((base)->EEI)
#define DMA_CEEI_REG(base)                       ((base)->CEEI)
#define DMA_SEEI_REG(base)                       ((base)->SEEI)
#define DMA_CERQ_REG(base)                       ((base)->CERQ)
#define DMA_SERQ_REG(base)                       ((base)->SERQ)
#define DMA_CDNE_REG(base)                       ((base)->CDNE)
#define DMA_SSRT_REG(base)                       ((base)->SSRT)
#define DMA_CERR_REG(base)                       ((base)->CERR)
#define DMA_CINT_REG(base)                       ((base)->CINT)
#define DMA_INT_REG(base)                        ((base)->INT)
#define DMA_ERR_REG(base)                        ((base)->ERR)
#define DMA_HRS_REG(base)                        ((base)->HRS)
#define DMA_EARS_REG(base)                       ((base)->EARS)
#define DMA_DCHPRI3_REG(base)                    ((base)->DCHPRI3)
#define DMA_DCHPRI2_REG(base)                    ((base)->DCHPRI2)
#define DMA_DCHPRI1_REG(base)                    ((base)->DCHPRI1)
#define DMA_DCHPRI0_REG(base)                    ((base)->DCHPRI0)
#define DMA_DCHPRI7_REG(base)                    ((base)->DCHPRI7)
#define DMA_DCHPRI6_REG(base)                    ((base)->DCHPRI6)
#define DMA_DCHPRI5_REG(base)                    ((base)->DCHPRI5)
#define DMA_DCHPRI4_REG(base)                    ((base)->DCHPRI4)
#define DMA_DCHPRI11_REG(base)                   ((base)->DCHPRI11)
#define DMA_DCHPRI10_REG(base)                   ((base)->DCHPRI10)
#define DMA_DCHPRI9_REG(base)                    ((base)->DCHPRI9)
#define DMA_DCHPRI8_REG(base)                    ((base)->DCHPRI8)
#define DMA_DCHPRI15_REG(base)                   ((base)->DCHPRI15)
#define DMA_DCHPRI14_REG(base)                   ((base)->DCHPRI14)
#define DMA_DCHPRI13_REG(base)                   ((base)->DCHPRI13)
#define DMA_DCHPRI12_REG(base)                   ((base)->DCHPRI12)
#define DMA_SADDR_REG(base,index)                ((base)->TCD[index].SADDR)
#define DMA_SOFF_REG(base,index)                 ((base)->TCD[index].SOFF)
#define DMA_ATTR_REG(base,index)                 ((base)->TCD[index].ATTR)
#define DMA_NBYTES_MLNO_REG(base,index)          ((base)->TCD[index].NBYTES_MLNO)
#define DMA_NBYTES_MLOFFNO_REG(base,index)       ((base)->TCD[index].NBYTES_MLOFFNO)
#define DMA_NBYTES_MLOFFYES_REG(base,index)      ((base)->TCD[index].NBYTES_MLOFFYES)
#define DMA_SLAST_REG(base,index)                ((base)->TCD[index].SLAST)
#define DMA_DADDR_REG(base,index)                ((base)->TCD[index].DADDR)
#define DMA_DOFF_REG(base,index)                 ((base)->TCD[index].DOFF)
#define DMA_CITER_ELINKNO_REG(base,index)        ((base)->TCD[index].CITER_ELINKNO)
#define DMA_CITER_ELINKYES_REG(base,index)       ((base)->TCD[index].CITER_ELINKYES)
#define DMA_DLAST_SGA_REG(base,index)            ((base)->TCD[index].DLAST_SGA)
#define DMA_CSR_REG(base,index)                  ((base)->TCD[index].CSR)
#define DMA_BITER_ELINKNO_REG(base,index)        ((base)->TCD[index].BITER_ELINKNO)
#define DMA_BITER_ELINKYES_REG(base,index)       ((base)->TCD[index].BITER_ELINKYES)

/*!
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* CR Bit Fields */
#define DMA_CR_EDBG_MASK                         0x2u
#define DMA_CR_EDBG_SHIFT                        1
#define DMA_CR_ERCA_MASK                         0x4u
#define DMA_CR_ERCA_SHIFT                        2
#define DMA_CR_HOE_MASK                          0x10u
#define DMA_CR_HOE_SHIFT                         4
#define DMA_CR_HALT_MASK                         0x20u
#define DMA_CR_HALT_SHIFT                        5
#define DMA_CR_CLM_MASK                          0x40u
#define DMA_CR_CLM_SHIFT                         6
#define DMA_CR_EMLM_MASK                         0x80u
#define DMA_CR_EMLM_SHIFT                        7
#define DMA_CR_ECX_MASK                          0x10000u
#define DMA_CR_ECX_SHIFT                         16
#define DMA_CR_CX_MASK                           0x20000u
#define DMA_CR_CX_SHIFT                          17
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                          0x1u
#define DMA_ES_DBE_SHIFT                         0
#define DMA_ES_SBE_MASK                          0x2u
#define DMA_ES_SBE_SHIFT                         1
#define DMA_ES_SGE_MASK                          0x4u
#define DMA_ES_SGE_SHIFT                         2
#define DMA_ES_NCE_MASK                          0x8u
#define DMA_ES_NCE_SHIFT                         3
#define DMA_ES_DOE_MASK                          0x10u
#define DMA_ES_DOE_SHIFT                         4
#define DMA_ES_DAE_MASK                          0x20u
#define DMA_ES_DAE_SHIFT                         5
#define DMA_ES_SOE_MASK                          0x40u
#define DMA_ES_SOE_SHIFT                         6
#define DMA_ES_SAE_MASK                          0x80u
#define DMA_ES_SAE_SHIFT                         7
#define DMA_ES_ERRCHN_MASK                       0xF00u
#define DMA_ES_ERRCHN_SHIFT                      8
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          0x4000u
#define DMA_ES_CPE_SHIFT                         14
#define DMA_ES_ECX_MASK                          0x10000u
#define DMA_ES_ECX_SHIFT                         16
#define DMA_ES_VLD_MASK                          0x80000000u
#define DMA_ES_VLD_SHIFT                         31
/* ERQ Bit Fields */
#define DMA_ERQ_ERQ0_MASK                        0x1u
#define DMA_ERQ_ERQ0_SHIFT                       0
#define DMA_ERQ_ERQ1_MASK                        0x2u
#define DMA_ERQ_ERQ1_SHIFT                       1
#define DMA_ERQ_ERQ2_MASK                        0x4u
#define DMA_ERQ_ERQ2_SHIFT                       2
#define DMA_ERQ_ERQ3_MASK                        0x8u
#define DMA_ERQ_ERQ3_SHIFT                       3
#define DMA_ERQ_ERQ4_MASK                        0x10u
#define DMA_ERQ_ERQ4_SHIFT                       4
#define DMA_ERQ_ERQ5_MASK                        0x20u
#define DMA_ERQ_ERQ5_SHIFT                       5
#define DMA_ERQ_ERQ6_MASK                        0x40u
#define DMA_ERQ_ERQ6_SHIFT                       6
#define DMA_ERQ_ERQ7_MASK                        0x80u
#define DMA_ERQ_ERQ7_SHIFT                       7
#define DMA_ERQ_ERQ8_MASK                        0x100u
#define DMA_ERQ_ERQ8_SHIFT                       8
#define DMA_ERQ_ERQ9_MASK                        0x200u
#define DMA_ERQ_ERQ9_SHIFT                       9
#define DMA_ERQ_ERQ10_MASK                       0x400u
#define DMA_ERQ_ERQ10_SHIFT                      10
#define DMA_ERQ_ERQ11_MASK                       0x800u
#define DMA_ERQ_ERQ11_SHIFT                      11
#define DMA_ERQ_ERQ12_MASK                       0x1000u
#define DMA_ERQ_ERQ12_SHIFT                      12
#define DMA_ERQ_ERQ13_MASK                       0x2000u
#define DMA_ERQ_ERQ13_SHIFT                      13
#define DMA_ERQ_ERQ14_MASK                       0x4000u
#define DMA_ERQ_ERQ14_SHIFT                      14
#define DMA_ERQ_ERQ15_MASK                       0x8000u
#define DMA_ERQ_ERQ15_SHIFT                      15
/* EEI Bit Fields */
#define DMA_EEI_EEI0_MASK                        0x1u
#define DMA_EEI_EEI0_SHIFT                       0
#define DMA_EEI_EEI1_MASK                        0x2u
#define DMA_EEI_EEI1_SHIFT                       1
#define DMA_EEI_EEI2_MASK                        0x4u
#define DMA_EEI_EEI2_SHIFT                       2
#define DMA_EEI_EEI3_MASK                        0x8u
#define DMA_EEI_EEI3_SHIFT                       3
#define DMA_EEI_EEI4_MASK                        0x10u
#define DMA_EEI_EEI4_SHIFT                       4
#define DMA_EEI_EEI5_MASK                        0x20u
#define DMA_EEI_EEI5_SHIFT                       5
#define DMA_EEI_EEI6_MASK                        0x40u
#define DMA_EEI_EEI6_SHIFT                       6
#define DMA_EEI_EEI7_MASK                        0x80u
#define DMA_EEI_EEI7_SHIFT                       7
#define DMA_EEI_EEI8_MASK                        0x100u
#define DMA_EEI_EEI8_SHIFT                       8
#define DMA_EEI_EEI9_MASK                        0x200u
#define DMA_EEI_EEI9_SHIFT                       9
#define DMA_EEI_EEI10_MASK                       0x400u
#define DMA_EEI_EEI10_SHIFT                      10
#define DMA_EEI_EEI11_MASK                       0x800u
#define DMA_EEI_EEI11_SHIFT                      11
#define DMA_EEI_EEI12_MASK                       0x1000u
#define DMA_EEI_EEI12_SHIFT                      12
#define DMA_EEI_EEI13_MASK                       0x2000u
#define DMA_EEI_EEI13_SHIFT                      13
#define DMA_EEI_EEI14_MASK                       0x4000u
#define DMA_EEI_EEI14_SHIFT                      14
#define DMA_EEI_EEI15_MASK                       0x8000u
#define DMA_EEI_EEI15_SHIFT                      15
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                       0xFu
#define DMA_CEEI_CEEI_SHIFT                      0
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       0x40u
#define DMA_CEEI_CAEE_SHIFT                      6
#define DMA_CEEI_NOP_MASK                        0x80u
#define DMA_CEEI_NOP_SHIFT                       7
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                       0xFu
#define DMA_SEEI_SEEI_SHIFT                      0
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       0x40u
#define DMA_SEEI_SAEE_SHIFT                      6
#define DMA_SEEI_NOP_MASK                        0x80u
#define DMA_SEEI_NOP_SHIFT                       7
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                       0xFu
#define DMA_CERQ_CERQ_SHIFT                      0
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       0x40u
#define DMA_CERQ_CAER_SHIFT                      6
#define DMA_CERQ_NOP_MASK                        0x80u
#define DMA_CERQ_NOP_SHIFT                       7
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                       0xFu
#define DMA_SERQ_SERQ_SHIFT                      0
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       0x40u
#define DMA_SERQ_SAER_SHIFT                      6
#define DMA_SERQ_NOP_MASK                        0x80u
#define DMA_SERQ_NOP_SHIFT                       7
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                       0xFu
#define DMA_CDNE_CDNE_SHIFT                      0
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       0x40u
#define DMA_CDNE_CADN_SHIFT                      6
#define DMA_CDNE_NOP_MASK                        0x80u
#define DMA_CDNE_NOP_SHIFT                       7
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                       0xFu
#define DMA_SSRT_SSRT_SHIFT                      0
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       0x40u
#define DMA_SSRT_SAST_SHIFT                      6
#define DMA_SSRT_NOP_MASK                        0x80u
#define DMA_SSRT_NOP_SHIFT                       7
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                       0xFu
#define DMA_CERR_CERR_SHIFT                      0
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       0x40u
#define DMA_CERR_CAEI_SHIFT                      6
#define DMA_CERR_NOP_MASK                        0x80u
#define DMA_CERR_NOP_SHIFT                       7
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                       0xFu
#define DMA_CINT_CINT_SHIFT                      0
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       0x40u
#define DMA_CINT_CAIR_SHIFT                      6
#define DMA_CINT_NOP_MASK                        0x80u
#define DMA_CINT_NOP_SHIFT                       7
/* INT Bit Fields */
#define DMA_INT_INT0_MASK                        0x1u
#define DMA_INT_INT0_SHIFT                       0
#define DMA_INT_INT1_MASK                        0x2u
#define DMA_INT_INT1_SHIFT                       1
#define DMA_INT_INT2_MASK                        0x4u
#define DMA_INT_INT2_SHIFT                       2
#define DMA_INT_INT3_MASK                        0x8u
#define DMA_INT_INT3_SHIFT                       3
#define DMA_INT_INT4_MASK                        0x10u
#define DMA_INT_INT4_SHIFT                       4
#define DMA_INT_INT5_MASK                        0x20u
#define DMA_INT_INT5_SHIFT                       5
#define DMA_INT_INT6_MASK                        0x40u
#define DMA_INT_INT6_SHIFT                       6
#define DMA_INT_INT7_MASK                        0x80u
#define DMA_INT_INT7_SHIFT                       7
#define DMA_INT_INT8_MASK                        0x100u
#define DMA_INT_INT8_SHIFT                       8
#define DMA_INT_INT9_MASK                        0x200u
#define DMA_INT_INT9_SHIFT                       9
#define DMA_INT_INT10_MASK                       0x400u
#define DMA_INT_INT10_SHIFT                      10
#define DMA_INT_INT11_MASK                       0x800u
#define DMA_INT_INT11_SHIFT                      11
#define DMA_INT_INT12_MASK                       0x1000u
#define DMA_INT_INT12_SHIFT                      12
#define DMA_INT_INT13_MASK                       0x2000u
#define DMA_INT_INT13_SHIFT                      13
#define DMA_INT_INT14_MASK                       0x4000u
#define DMA_INT_INT14_SHIFT                      14
#define DMA_INT_INT15_MASK                       0x8000u
#define DMA_INT_INT15_SHIFT                      15
/* ERR Bit Fields */
#define DMA_ERR_ERR0_MASK                        0x1u
#define DMA_ERR_ERR0_SHIFT                       0
#define DMA_ERR_ERR1_MASK                        0x2u
#define DMA_ERR_ERR1_SHIFT                       1
#define DMA_ERR_ERR2_MASK                        0x4u
#define DMA_ERR_ERR2_SHIFT                       2
#define DMA_ERR_ERR3_MASK                        0x8u
#define DMA_ERR_ERR3_SHIFT                       3
#define DMA_ERR_ERR4_MASK                        0x10u
#define DMA_ERR_ERR4_SHIFT                       4
#define DMA_ERR_ERR5_MASK                        0x20u
#define DMA_ERR_ERR5_SHIFT                       5
#define DMA_ERR_ERR6_MASK                        0x40u
#define DMA_ERR_ERR6_SHIFT                       6
#define DMA_ERR_ERR7_MASK                        0x80u
#define DMA_ERR_ERR7_SHIFT                       7
#define DMA_ERR_ERR8_MASK                        0x100u
#define DMA_ERR_ERR8_SHIFT                       8
#define DMA_ERR_ERR9_MASK                        0x200u
#define DMA_ERR_ERR9_SHIFT                       9
#define DMA_ERR_ERR10_MASK                       0x400u
#define DMA_ERR_ERR10_SHIFT                      10
#define DMA_ERR_ERR11_MASK                       0x800u
#define DMA_ERR_ERR11_SHIFT                      11
#define DMA_ERR_ERR12_MASK                       0x1000u
#define DMA_ERR_ERR12_SHIFT                      12
#define DMA_ERR_ERR13_MASK                       0x2000u
#define DMA_ERR_ERR13_SHIFT                      13
#define DMA_ERR_ERR14_MASK                       0x4000u
#define DMA_ERR_ERR14_SHIFT                      14
#define DMA_ERR_ERR15_MASK                       0x8000u
#define DMA_ERR_ERR15_SHIFT                      15
/* HRS Bit Fields */
#define DMA_HRS_HRS0_MASK                        0x1u
#define DMA_HRS_HRS0_SHIFT                       0
#define DMA_HRS_HRS1_MASK                        0x2u
#define DMA_HRS_HRS1_SHIFT                       1
#define DMA_HRS_HRS2_MASK                        0x4u
#define DMA_HRS_HRS2_SHIFT                       2
#define DMA_HRS_HRS3_MASK                        0x8u
#define DMA_HRS_HRS3_SHIFT                       3
#define DMA_HRS_HRS4_MASK                        0x10u
#define DMA_HRS_HRS4_SHIFT                       4
#define DMA_HRS_HRS5_MASK                        0x20u
#define DMA_HRS_HRS5_SHIFT                       5
#define DMA_HRS_HRS6_MASK                        0x40u
#define DMA_HRS_HRS6_SHIFT                       6
#define DMA_HRS_HRS7_MASK                        0x80u
#define DMA_HRS_HRS7_SHIFT                       7
#define DMA_HRS_HRS8_MASK                        0x100u
#define DMA_HRS_HRS8_SHIFT                       8
#define DMA_HRS_HRS9_MASK                        0x200u
#define DMA_HRS_HRS9_SHIFT                       9
#define DMA_HRS_HRS10_MASK                       0x400u
#define DMA_HRS_HRS10_SHIFT                      10
#define DMA_HRS_HRS11_MASK                       0x800u
#define DMA_HRS_HRS11_SHIFT                      11
#define DMA_HRS_HRS12_MASK                       0x1000u
#define DMA_HRS_HRS12_SHIFT                      12
#define DMA_HRS_HRS13_MASK                       0x2000u
#define DMA_HRS_HRS13_SHIFT                      13
#define DMA_HRS_HRS14_MASK                       0x4000u
#define DMA_HRS_HRS14_SHIFT                      14
#define DMA_HRS_HRS15_MASK                       0x8000u
#define DMA_HRS_HRS15_SHIFT                      15
/* EARS Bit Fields */
#define DMA_EARS_EDREQ_0_MASK                    0x1u
#define DMA_EARS_EDREQ_0_SHIFT                   0
#define DMA_EARS_EDREQ_1_MASK                    0x2u
#define DMA_EARS_EDREQ_1_SHIFT                   1
#define DMA_EARS_EDREQ_2_MASK                    0x4u
#define DMA_EARS_EDREQ_2_SHIFT                   2
#define DMA_EARS_EDREQ_3_MASK                    0x8u
#define DMA_EARS_EDREQ_3_SHIFT                   3
#define DMA_EARS_EDREQ_4_MASK                    0x10u
#define DMA_EARS_EDREQ_4_SHIFT                   4
#define DMA_EARS_EDREQ_5_MASK                    0x20u
#define DMA_EARS_EDREQ_5_SHIFT                   5
#define DMA_EARS_EDREQ_6_MASK                    0x40u
#define DMA_EARS_EDREQ_6_SHIFT                   6
#define DMA_EARS_EDREQ_7_MASK                    0x80u
#define DMA_EARS_EDREQ_7_SHIFT                   7
#define DMA_EARS_EDREQ_8_MASK                    0x100u
#define DMA_EARS_EDREQ_8_SHIFT                   8
#define DMA_EARS_EDREQ_9_MASK                    0x200u
#define DMA_EARS_EDREQ_9_SHIFT                   9
#define DMA_EARS_EDREQ_10_MASK                   0x400u
#define DMA_EARS_EDREQ_10_SHIFT                  10
#define DMA_EARS_EDREQ_11_MASK                   0x800u
#define DMA_EARS_EDREQ_11_SHIFT                  11
#define DMA_EARS_EDREQ_12_MASK                   0x1000u
#define DMA_EARS_EDREQ_12_SHIFT                  12
#define DMA_EARS_EDREQ_13_MASK                   0x2000u
#define DMA_EARS_EDREQ_13_SHIFT                  13
#define DMA_EARS_EDREQ_14_MASK                   0x4000u
#define DMA_EARS_EDREQ_14_SHIFT                  14
#define DMA_EARS_EDREQ_15_MASK                   0x8000u
#define DMA_EARS_EDREQ_15_SHIFT                  15
/* DCHPRI3 Bit Fields */
#define DMA_DCHPRI3_CHPRI_MASK                   0xFu
#define DMA_DCHPRI3_CHPRI_SHIFT                  0
#define DMA_DCHPRI3_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_CHPRI_SHIFT))&DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     0x40u
#define DMA_DCHPRI3_DPA_SHIFT                    6
#define DMA_DCHPRI3_ECP_MASK                     0x80u
#define DMA_DCHPRI3_ECP_SHIFT                    7
/* DCHPRI2 Bit Fields */
#define DMA_DCHPRI2_CHPRI_MASK                   0xFu
#define DMA_DCHPRI2_CHPRI_SHIFT                  0
#define DMA_DCHPRI2_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_CHPRI_SHIFT))&DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     0x40u
#define DMA_DCHPRI2_DPA_SHIFT                    6
#define DMA_DCHPRI2_ECP_MASK                     0x80u
#define DMA_DCHPRI2_ECP_SHIFT                    7
/* DCHPRI1 Bit Fields */
#define DMA_DCHPRI1_CHPRI_MASK                   0xFu
#define DMA_DCHPRI1_CHPRI_SHIFT                  0
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_CHPRI_SHIFT))&DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     0x40u
#define DMA_DCHPRI1_DPA_SHIFT                    6
#define DMA_DCHPRI1_ECP_MASK                     0x80u
#define DMA_DCHPRI1_ECP_SHIFT                    7
/* DCHPRI0 Bit Fields */
#define DMA_DCHPRI0_CHPRI_MASK                   0xFu
#define DMA_DCHPRI0_CHPRI_SHIFT                  0
#define DMA_DCHPRI0_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_CHPRI_SHIFT))&DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     0x40u
#define DMA_DCHPRI0_DPA_SHIFT                    6
#define DMA_DCHPRI0_ECP_MASK                     0x80u
#define DMA_DCHPRI0_ECP_SHIFT                    7
/* DCHPRI7 Bit Fields */
#define DMA_DCHPRI7_CHPRI_MASK                   0xFu
#define DMA_DCHPRI7_CHPRI_SHIFT                  0
#define DMA_DCHPRI7_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_CHPRI_SHIFT))&DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     0x40u
#define DMA_DCHPRI7_DPA_SHIFT                    6
#define DMA_DCHPRI7_ECP_MASK                     0x80u
#define DMA_DCHPRI7_ECP_SHIFT                    7
/* DCHPRI6 Bit Fields */
#define DMA_DCHPRI6_CHPRI_MASK                   0xFu
#define DMA_DCHPRI6_CHPRI_SHIFT                  0
#define DMA_DCHPRI6_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_CHPRI_SHIFT))&DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     0x40u
#define DMA_DCHPRI6_DPA_SHIFT                    6
#define DMA_DCHPRI6_ECP_MASK                     0x80u
#define DMA_DCHPRI6_ECP_SHIFT                    7
/* DCHPRI5 Bit Fields */
#define DMA_DCHPRI5_CHPRI_MASK                   0xFu
#define DMA_DCHPRI5_CHPRI_SHIFT                  0
#define DMA_DCHPRI5_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_CHPRI_SHIFT))&DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     0x40u
#define DMA_DCHPRI5_DPA_SHIFT                    6
#define DMA_DCHPRI5_ECP_MASK                     0x80u
#define DMA_DCHPRI5_ECP_SHIFT                    7
/* DCHPRI4 Bit Fields */
#define DMA_DCHPRI4_CHPRI_MASK                   0xFu
#define DMA_DCHPRI4_CHPRI_SHIFT                  0
#define DMA_DCHPRI4_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_CHPRI_SHIFT))&DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     0x40u
#define DMA_DCHPRI4_DPA_SHIFT                    6
#define DMA_DCHPRI4_ECP_MASK                     0x80u
#define DMA_DCHPRI4_ECP_SHIFT                    7
/* DCHPRI11 Bit Fields */
#define DMA_DCHPRI11_CHPRI_MASK                  0xFu
#define DMA_DCHPRI11_CHPRI_SHIFT                 0
#define DMA_DCHPRI11_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI11_CHPRI_SHIFT))&DMA_DCHPRI11_CHPRI_MASK)
#define DMA_DCHPRI11_DPA_MASK                    0x40u
#define DMA_DCHPRI11_DPA_SHIFT                   6
#define DMA_DCHPRI11_ECP_MASK                    0x80u
#define DMA_DCHPRI11_ECP_SHIFT                   7
/* DCHPRI10 Bit Fields */
#define DMA_DCHPRI10_CHPRI_MASK                  0xFu
#define DMA_DCHPRI10_CHPRI_SHIFT                 0
#define DMA_DCHPRI10_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI10_CHPRI_SHIFT))&DMA_DCHPRI10_CHPRI_MASK)
#define DMA_DCHPRI10_DPA_MASK                    0x40u
#define DMA_DCHPRI10_DPA_SHIFT                   6
#define DMA_DCHPRI10_ECP_MASK                    0x80u
#define DMA_DCHPRI10_ECP_SHIFT                   7
/* DCHPRI9 Bit Fields */
#define DMA_DCHPRI9_CHPRI_MASK                   0xFu
#define DMA_DCHPRI9_CHPRI_SHIFT                  0
#define DMA_DCHPRI9_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI9_CHPRI_SHIFT))&DMA_DCHPRI9_CHPRI_MASK)
#define DMA_DCHPRI9_DPA_MASK                     0x40u
#define DMA_DCHPRI9_DPA_SHIFT                    6
#define DMA_DCHPRI9_ECP_MASK                     0x80u
#define DMA_DCHPRI9_ECP_SHIFT                    7
/* DCHPRI8 Bit Fields */
#define DMA_DCHPRI8_CHPRI_MASK                   0xFu
#define DMA_DCHPRI8_CHPRI_SHIFT                  0
#define DMA_DCHPRI8_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI8_CHPRI_SHIFT))&DMA_DCHPRI8_CHPRI_MASK)
#define DMA_DCHPRI8_DPA_MASK                     0x40u
#define DMA_DCHPRI8_DPA_SHIFT                    6
#define DMA_DCHPRI8_ECP_MASK                     0x80u
#define DMA_DCHPRI8_ECP_SHIFT                    7
/* DCHPRI15 Bit Fields */
#define DMA_DCHPRI15_CHPRI_MASK                  0xFu
#define DMA_DCHPRI15_CHPRI_SHIFT                 0
#define DMA_DCHPRI15_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI15_CHPRI_SHIFT))&DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DCHPRI15_DPA_MASK                    0x40u
#define DMA_DCHPRI15_DPA_SHIFT                   6
#define DMA_DCHPRI15_ECP_MASK                    0x80u
#define DMA_DCHPRI15_ECP_SHIFT                   7
/* DCHPRI14 Bit Fields */
#define DMA_DCHPRI14_CHPRI_MASK                  0xFu
#define DMA_DCHPRI14_CHPRI_SHIFT                 0
#define DMA_DCHPRI14_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI14_CHPRI_SHIFT))&DMA_DCHPRI14_CHPRI_MASK)
#define DMA_DCHPRI14_DPA_MASK                    0x40u
#define DMA_DCHPRI14_DPA_SHIFT                   6
#define DMA_DCHPRI14_ECP_MASK                    0x80u
#define DMA_DCHPRI14_ECP_SHIFT                   7
/* DCHPRI13 Bit Fields */
#define DMA_DCHPRI13_CHPRI_MASK                  0xFu
#define DMA_DCHPRI13_CHPRI_SHIFT                 0
#define DMA_DCHPRI13_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI13_CHPRI_SHIFT))&DMA_DCHPRI13_CHPRI_MASK)
#define DMA_DCHPRI13_DPA_MASK                    0x40u
#define DMA_DCHPRI13_DPA_SHIFT                   6
#define DMA_DCHPRI13_ECP_MASK                    0x80u
#define DMA_DCHPRI13_ECP_SHIFT                   7
/* DCHPRI12 Bit Fields */
#define DMA_DCHPRI12_CHPRI_MASK                  0xFu
#define DMA_DCHPRI12_CHPRI_SHIFT                 0
#define DMA_DCHPRI12_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI12_CHPRI_SHIFT))&DMA_DCHPRI12_CHPRI_MASK)
#define DMA_DCHPRI12_DPA_MASK                    0x40u
#define DMA_DCHPRI12_DPA_SHIFT                   6
#define DMA_DCHPRI12_ECP_MASK                    0x80u
#define DMA_DCHPRI12_ECP_SHIFT                   7
/* SADDR Bit Fields */
#define DMA_SADDR_SADDR_MASK                     0xFFFFFFFFu
#define DMA_SADDR_SADDR_SHIFT                    0
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK)
/* SOFF Bit Fields */
#define DMA_SOFF_SOFF_MASK                       0xFFFFu
#define DMA_SOFF_SOFF_SHIFT                      0
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK)
/* ATTR Bit Fields */
#define DMA_ATTR_DSIZE_MASK                      0x7u
#define DMA_ATTR_DSIZE_SHIFT                     0
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       0xF8u
#define DMA_ATTR_DMOD_SHIFT                      3
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      0x700u
#define DMA_ATTR_SSIZE_SHIFT                     8
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       0xF800u
#define DMA_ATTR_SMOD_SHIFT                      11
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK)
/* NBYTES_MLNO Bit Fields */
#define DMA_NBYTES_MLNO_NBYTES_MASK              0xFFFFFFFFu
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK)
/* NBYTES_MLOFFNO Bit Fields */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           0x3FFFFFFFu
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          0
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            0x40000000u
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            0x80000000u
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31
/* NBYTES_MLOFFYES Bit Fields */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          0x3FFu
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         0
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           0x3FFFFC00u
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           0x40000000u
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           0x80000000u
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31
/* SLAST Bit Fields */
#define DMA_SLAST_SLAST_MASK                     0xFFFFFFFFu
#define DMA_SLAST_SLAST_SHIFT                    0
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK)
/* DADDR Bit Fields */
#define DMA_DADDR_DADDR_MASK                     0xFFFFFFFFu
#define DMA_DADDR_DADDR_SHIFT                    0
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK)
/* DOFF Bit Fields */
#define DMA_DOFF_DOFF_MASK                       0xFFFFu
#define DMA_DOFF_DOFF_SHIFT                      0
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK)
/* CITER_ELINKNO Bit Fields */
#define DMA_CITER_ELINKNO_CITER_MASK             0x7FFFu
#define DMA_CITER_ELINKNO_CITER_SHIFT            0
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15
/* CITER_ELINKYES Bit Fields */
#define DMA_CITER_ELINKYES_CITER_MASK            0x1FFu
#define DMA_CITER_ELINKYES_CITER_SHIFT           0
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15
/* DLAST_SGA Bit Fields */
#define DMA_DLAST_SGA_DLASTSGA_MASK              0xFFFFFFFFu
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             0
#define DMA_DLAST_SGA_DLASTSGA(x)                (((uint32_t)(((uint32_t)(x))<<DMA_DLAST_SGA_DLASTSGA_SHIFT))&DMA_DLAST_SGA_DLASTSGA_MASK)
/* CSR Bit Fields */
#define DMA_CSR_START_MASK                       0x1u
#define DMA_CSR_START_SHIFT                      0
#define DMA_CSR_INTMAJOR_MASK                    0x2u
#define DMA_CSR_INTMAJOR_SHIFT                   1
#define DMA_CSR_INTHALF_MASK                     0x4u
#define DMA_CSR_INTHALF_SHIFT                    2
#define DMA_CSR_DREQ_MASK                        0x8u
#define DMA_CSR_DREQ_SHIFT                       3
#define DMA_CSR_ESG_MASK                         0x10u
#define DMA_CSR_ESG_SHIFT                        4
#define DMA_CSR_MAJORELINK_MASK                  0x20u
#define DMA_CSR_MAJORELINK_SHIFT                 5
#define DMA_CSR_ACTIVE_MASK                      0x40u
#define DMA_CSR_ACTIVE_SHIFT                     6
#define DMA_CSR_DONE_MASK                        0x80u
#define DMA_CSR_DONE_SHIFT                       7
#define DMA_CSR_MAJORLINKCH_MASK                 0xF00u
#define DMA_CSR_MAJORLINKCH_SHIFT                8
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         0xC000u
#define DMA_CSR_BWC_SHIFT                        14
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK)
/* BITER_ELINKNO Bit Fields */
#define DMA_BITER_ELINKNO_BITER_MASK             0x7FFFu
#define DMA_BITER_ELINKNO_BITER_SHIFT            0
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15
/* BITER_ELINKYES Bit Fields */
#define DMA_BITER_ELINKYES_BITER_MASK            0x1FFu
#define DMA_BITER_ELINKYES_BITER_SHIFT           0
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15

/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base pointer */
#define DMA_BASE_PTR                             ((DMA_MemMapPtr)0x40008000u)
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register instance definitions */
/* DMA */
#define DMA_CR                                   DMA_CR_REG(DMA_BASE_PTR)
#define DMA_ES                                   DMA_ES_REG(DMA_BASE_PTR)
#define DMA_ERQ                                  DMA_ERQ_REG(DMA_BASE_PTR)
#define DMA_EEI                                  DMA_EEI_REG(DMA_BASE_PTR)
#define DMA_CEEI                                 DMA_CEEI_REG(DMA_BASE_PTR)
#define DMA_SEEI                                 DMA_SEEI_REG(DMA_BASE_PTR)
#define DMA_CERQ                                 DMA_CERQ_REG(DMA_BASE_PTR)
#define DMA_SERQ                                 DMA_SERQ_REG(DMA_BASE_PTR)
#define DMA_CDNE                                 DMA_CDNE_REG(DMA_BASE_PTR)
#define DMA_SSRT                                 DMA_SSRT_REG(DMA_BASE_PTR)
#define DMA_CERR                                 DMA_CERR_REG(DMA_BASE_PTR)
#define DMA_CINT                                 DMA_CINT_REG(DMA_BASE_PTR)
#define DMA_INT                                  DMA_INT_REG(DMA_BASE_PTR)
#define DMA_ERR                                  DMA_ERR_REG(DMA_BASE_PTR)
#define DMA_HRS                                  DMA_HRS_REG(DMA_BASE_PTR)
#define DMA_EARS                                 DMA_EARS_REG(DMA_BASE_PTR)
#define DMA_DCHPRI3                              DMA_DCHPRI3_REG(DMA_BASE_PTR)
#define DMA_DCHPRI2                              DMA_DCHPRI2_REG(DMA_BASE_PTR)
#define DMA_DCHPRI1                              DMA_DCHPRI1_REG(DMA_BASE_PTR)
#define DMA_DCHPRI0                              DMA_DCHPRI0_REG(DMA_BASE_PTR)
#define DMA_DCHPRI7                              DMA_DCHPRI7_REG(DMA_BASE_PTR)
#define DMA_DCHPRI6                              DMA_DCHPRI6_REG(DMA_BASE_PTR)
#define DMA_DCHPRI5                              DMA_DCHPRI5_REG(DMA_BASE_PTR)
#define DMA_DCHPRI4                              DMA_DCHPRI4_REG(DMA_BASE_PTR)
#define DMA_DCHPRI11                             DMA_DCHPRI11_REG(DMA_BASE_PTR)
#define DMA_DCHPRI10                             DMA_DCHPRI10_REG(DMA_BASE_PTR)
#define DMA_DCHPRI9                              DMA_DCHPRI9_REG(DMA_BASE_PTR)
#define DMA_DCHPRI8                              DMA_DCHPRI8_REG(DMA_BASE_PTR)
#define DMA_DCHPRI15                             DMA_DCHPRI15_REG(DMA_BASE_PTR)
#define DMA_DCHPRI14                             DMA_DCHPRI14_REG(DMA_BASE_PTR)
#define DMA_DCHPRI13                             DMA_DCHPRI13_REG(DMA_BASE_PTR)
#define DMA_DCHPRI12                             DMA_DCHPRI12_REG(DMA_BASE_PTR)
#define DMA_TCD0_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CSR                             DMA_CSR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD1_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CSR                             DMA_CSR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD2_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CSR                             DMA_CSR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD3_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CSR                             DMA_CSR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD4_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CSR                             DMA_CSR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD5_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CSR                             DMA_CSR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD6_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CSR                             DMA_CSR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD7_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CSR                             DMA_CSR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD8_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CSR                             DMA_CSR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD9_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CSR                             DMA_CSR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD10_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CSR                            DMA_CSR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD11_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CSR                            DMA_CSR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD12_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CSR                            DMA_CSR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD13_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CSR                            DMA_CSR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD14_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CSR                            DMA_CSR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD15_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CSR                            DMA_CSR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,15)

/* DMA - Register array accessors */
#define DMA_SADDR(index)                         DMA_SADDR_REG(DMA_BASE_PTR,index)
#define DMA_SOFF(index)                          DMA_SOFF_REG(DMA_BASE_PTR,index)
#define DMA_ATTR(index)                          DMA_ATTR_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLNO(index)                   DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLOFFNO(index)                DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLOFFYES(index)               DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,index)
#define DMA_SLAST(index)                         DMA_SLAST_REG(DMA_BASE_PTR,index)
#define DMA_DADDR(index)                         DMA_DADDR_REG(DMA_BASE_PTR,index)
#define DMA_DOFF(index)                          DMA_DOFF_REG(DMA_BASE_PTR,index)
#define DMA_CITER_ELINKNO(index)                 DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,index)
#define DMA_CITER_ELINKYES(index)                DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,index)
#define DMA_DLAST_SGA(index)                     DMA_DLAST_SGA_REG(DMA_BASE_PTR,index)
#define DMA_CSR(index)                           DMA_CSR_REG(DMA_BASE_PTR,index)
#define DMA_BITER_ELINKNO(index)                 DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,index)
#define DMA_BITER_ELINKYES(index)                DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,index)

/*!
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DMA_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMAMUX
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral DMAMUX
 * @{
 */

/** DMAMUX - Peripheral register structure */
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[16];                               /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} volatile *DMAMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register accessors */
#define DMAMUX_CHCFG_REG(base,index)             ((base)->CHCFG[index])

/*!
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/* CHCFG Bit Fields */
#define DMAMUX_CHCFG_SOURCE_MASK                 0x3Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT                0
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7

/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base pointer */
#define DMAMUX_BASE_PTR                          ((DMAMUX_MemMapPtr)0x40021000u)
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register instance definitions */
/* DMAMUX */
#define DMAMUX_CHCFG0                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,0)
#define DMAMUX_CHCFG1                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,1)
#define DMAMUX_CHCFG2                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,2)
#define DMAMUX_CHCFG3                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,3)
#define DMAMUX_CHCFG4                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,4)
#define DMAMUX_CHCFG5                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,5)
#define DMAMUX_CHCFG6                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,6)
#define DMAMUX_CHCFG7                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,7)
#define DMAMUX_CHCFG8                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,8)
#define DMAMUX_CHCFG9                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,9)
#define DMAMUX_CHCFG10                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,10)
#define DMAMUX_CHCFG11                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,11)
#define DMAMUX_CHCFG12                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,12)
#define DMAMUX_CHCFG13                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,13)
#define DMAMUX_CHCFG14                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,14)
#define DMAMUX_CHCFG15                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,15)

/* DMAMUX - Register array accessors */
#define DMAMUX_CHCFG(index)                      DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,index)

/*!
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DMAMUX_Peripheral */


/* ----------------------------------------------------------------------------
   -- DWT
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWT_Peripheral DWT
 * @{
 */

/** DWT - Peripheral register structure */
typedef struct DWT_MemMap {
  uint32_t CTRL;                                   /**< Control Register, offset: 0x0 */
  uint32_t CYCCNT;                                 /**< Cycle Count Register, offset: 0x4 */
  uint32_t CPICNT;                                 /**< CPI Count Register, offset: 0x8 */
  uint32_t EXCCNT;                                 /**< Exception Overhead Count Register, offset: 0xC */
  uint32_t SLEEPCNT;                               /**< Sleep Count Register, offset: 0x10 */
  uint32_t LSUCNT;                                 /**< LSU Count Register, offset: 0x14 */
  uint32_t FOLDCNT;                                /**< Folded-instruction Count Register, offset: 0x18 */
  uint32_t PCSR;                                   /**< Program Counter Sample Register, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x10 */
    uint32_t COMP;                                   /**< Comparator Register 0..Comparator Register 3, array offset: 0x20, array step: 0x10 */
    uint32_t MASK;                                   /**< Mask Register 0..Mask Register 3, array offset: 0x24, array step: 0x10 */
    uint32_t FUNCTION;                               /**< Function Register 0..Function Register 3, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } COMPARATOR[4];
  uint8_t RESERVED_0[3952];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *DWT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register accessors */
#define DWT_CTRL_REG(base)                       ((base)->CTRL)
#define DWT_CYCCNT_REG(base)                     ((base)->CYCCNT)
#define DWT_CPICNT_REG(base)                     ((base)->CPICNT)
#define DWT_EXCCNT_REG(base)                     ((base)->EXCCNT)
#define DWT_SLEEPCNT_REG(base)                   ((base)->SLEEPCNT)
#define DWT_LSUCNT_REG(base)                     ((base)->LSUCNT)
#define DWT_FOLDCNT_REG(base)                    ((base)->FOLDCNT)
#define DWT_PCSR_REG(base)                       ((base)->PCSR)
#define DWT_COMP_REG(base,index)                 ((base)->COMPARATOR[index].COMP)
#define DWT_MASK_REG(base,index)                 ((base)->COMPARATOR[index].MASK)
#define DWT_FUNCTION_REG(base,index)             ((base)->COMPARATOR[index].FUNCTION)
#define DWT_PID4_REG(base)                       ((base)->PID4)
#define DWT_PID5_REG(base)                       ((base)->PID5)
#define DWT_PID6_REG(base)                       ((base)->PID6)
#define DWT_PID7_REG(base)                       ((base)->PID7)
#define DWT_PID0_REG(base)                       ((base)->PID0)
#define DWT_PID1_REG(base)                       ((base)->PID1)
#define DWT_PID2_REG(base)                       ((base)->PID2)
#define DWT_PID3_REG(base)                       ((base)->PID3)
#define DWT_CID0_REG(base)                       ((base)->CID0)
#define DWT_CID1_REG(base)                       ((base)->CID1)
#define DWT_CID2_REG(base)                       ((base)->CID2)
#define DWT_CID3_REG(base)                       ((base)->CID3)

/*!
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWT_Register_Masks DWT Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group DWT_Register_Masks */


/* DWT - Peripheral instance base addresses */
/** Peripheral DWT base pointer */
#define DWT_BASE_PTR                             ((DWT_MemMapPtr)0xE0001000u)
/** Array initializer of DWT peripheral base pointers */
#define DWT_BASE_PTRS                            { DWT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register instance definitions */
/* DWT */
#define DWT_CTRL                                 DWT_CTRL_REG(DWT_BASE_PTR)
#define DWT_CYCCNT                               DWT_CYCCNT_REG(DWT_BASE_PTR)
#define DWT_CPICNT                               DWT_CPICNT_REG(DWT_BASE_PTR)
#define DWT_EXCCNT                               DWT_EXCCNT_REG(DWT_BASE_PTR)
#define DWT_SLEEPCNT                             DWT_SLEEPCNT_REG(DWT_BASE_PTR)
#define DWT_LSUCNT                               DWT_LSUCNT_REG(DWT_BASE_PTR)
#define DWT_FOLDCNT                              DWT_FOLDCNT_REG(DWT_BASE_PTR)
#define DWT_PCSR                                 DWT_PCSR_REG(DWT_BASE_PTR)
#define DWT_COMP0                                DWT_COMP_REG(DWT_BASE_PTR,0)
#define DWT_MASK0                                DWT_MASK_REG(DWT_BASE_PTR,0)
#define DWT_FUNCTION0                            DWT_FUNCTION_REG(DWT_BASE_PTR,0)
#define DWT_COMP1                                DWT_COMP_REG(DWT_BASE_PTR,1)
#define DWT_MASK1                                DWT_MASK_REG(DWT_BASE_PTR,1)
#define DWT_FUNCTION1                            DWT_FUNCTION_REG(DWT_BASE_PTR,1)
#define DWT_COMP2                                DWT_COMP_REG(DWT_BASE_PTR,2)
#define DWT_MASK2                                DWT_MASK_REG(DWT_BASE_PTR,2)
#define DWT_FUNCTION2                            DWT_FUNCTION_REG(DWT_BASE_PTR,2)
#define DWT_COMP3                                DWT_COMP_REG(DWT_BASE_PTR,3)
#define DWT_MASK3                                DWT_MASK_REG(DWT_BASE_PTR,3)
#define DWT_FUNCTION3                            DWT_FUNCTION_REG(DWT_BASE_PTR,3)
#define DWT_PID4                                 DWT_PID4_REG(DWT_BASE_PTR)
#define DWT_PID5                                 DWT_PID5_REG(DWT_BASE_PTR)
#define DWT_PID6                                 DWT_PID6_REG(DWT_BASE_PTR)
#define DWT_PID7                                 DWT_PID7_REG(DWT_BASE_PTR)
#define DWT_PID0                                 DWT_PID0_REG(DWT_BASE_PTR)
#define DWT_PID1                                 DWT_PID1_REG(DWT_BASE_PTR)
#define DWT_PID2                                 DWT_PID2_REG(DWT_BASE_PTR)
#define DWT_PID3                                 DWT_PID3_REG(DWT_BASE_PTR)
#define DWT_CID0                                 DWT_CID0_REG(DWT_BASE_PTR)
#define DWT_CID1                                 DWT_CID1_REG(DWT_BASE_PTR)
#define DWT_CID2                                 DWT_CID2_REG(DWT_BASE_PTR)
#define DWT_CID3                                 DWT_CID3_REG(DWT_BASE_PTR)

/* DWT - Register array accessors */
#define DWT_COMP(index)                          DWT_COMP_REG(DWT_BASE_PTR,index)
#define DWT_MASK(index)                          DWT_MASK_REG(DWT_BASE_PTR,index)
#define DWT_FUNCTION(index)                      DWT_FUNCTION_REG(DWT_BASE_PTR,index)

/*!
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DWT_Peripheral */


/* ----------------------------------------------------------------------------
   -- ENC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENC_Peripheral ENC
 * @{
 */

/** ENC - Peripheral register structure */
typedef struct ENC_MemMap {
  uint16_t CTRL;                                   /**< Control Register, offset: 0x0 */
  uint16_t FILT;                                   /**< Input Filter Register, offset: 0x2 */
  uint16_t WTR;                                    /**< Watchdog Timeout Register, offset: 0x4 */
  uint16_t POSD;                                   /**< Position Difference Counter Register, offset: 0x6 */
  uint16_t POSDH;                                  /**< Position Difference Hold Register, offset: 0x8 */
  uint16_t REV;                                    /**< Revolution Counter Register, offset: 0xA */
  uint16_t REVH;                                   /**< Revolution Hold Register, offset: 0xC */
  uint16_t UPOS;                                   /**< Upper Position Counter Register, offset: 0xE */
  uint16_t LPOS;                                   /**< Lower Position Counter Register, offset: 0x10 */
  uint16_t UPOSH;                                  /**< Upper Position Hold Register, offset: 0x12 */
  uint16_t LPOSH;                                  /**< Lower Position Hold Register, offset: 0x14 */
  uint16_t UINIT;                                  /**< Upper Initialization Register, offset: 0x16 */
  uint16_t LINIT;                                  /**< Lower Initialization Register, offset: 0x18 */
  uint16_t IMR;                                    /**< Input Monitor Register, offset: 0x1A */
  uint16_t TST;                                    /**< Test Register, offset: 0x1C */
  uint16_t CTRL2;                                  /**< Control 2 Register, offset: 0x1E */
  uint16_t UMOD;                                   /**< Upper Modulus Register, offset: 0x20 */
  uint16_t LMOD;                                   /**< Lower Modulus Register, offset: 0x22 */
  uint16_t UCOMP;                                  /**< Upper Position Compare Register, offset: 0x24 */
  uint16_t LCOMP;                                  /**< Lower Position Compare Register, offset: 0x26 */
} volatile *ENC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ENC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENC_Register_Accessor_Macros ENC - Register accessor macros
 * @{
 */


/* ENC - Register accessors */
#define ENC_CTRL_REG(base)                       ((base)->CTRL)
#define ENC_FILT_REG(base)                       ((base)->FILT)
#define ENC_WTR_REG(base)                        ((base)->WTR)
#define ENC_POSD_REG(base)                       ((base)->POSD)
#define ENC_POSDH_REG(base)                      ((base)->POSDH)
#define ENC_REV_REG(base)                        ((base)->REV)
#define ENC_REVH_REG(base)                       ((base)->REVH)
#define ENC_UPOS_REG(base)                       ((base)->UPOS)
#define ENC_LPOS_REG(base)                       ((base)->LPOS)
#define ENC_UPOSH_REG(base)                      ((base)->UPOSH)
#define ENC_LPOSH_REG(base)                      ((base)->LPOSH)
#define ENC_UINIT_REG(base)                      ((base)->UINIT)
#define ENC_LINIT_REG(base)                      ((base)->LINIT)
#define ENC_IMR_REG(base)                        ((base)->IMR)
#define ENC_TST_REG(base)                        ((base)->TST)
#define ENC_CTRL2_REG(base)                      ((base)->CTRL2)
#define ENC_UMOD_REG(base)                       ((base)->UMOD)
#define ENC_LMOD_REG(base)                       ((base)->LMOD)
#define ENC_UCOMP_REG(base)                      ((base)->UCOMP)
#define ENC_LCOMP_REG(base)                      ((base)->LCOMP)

/*!
 * @}
 */ /* end of group ENC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ENC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENC_Register_Masks ENC Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define ENC_CTRL_CMPIE_MASK                      0x1u
#define ENC_CTRL_CMPIE_SHIFT                     0
#define ENC_CTRL_CMPIRQ_MASK                     0x2u
#define ENC_CTRL_CMPIRQ_SHIFT                    1
#define ENC_CTRL_WDE_MASK                        0x4u
#define ENC_CTRL_WDE_SHIFT                       2
#define ENC_CTRL_DIE_MASK                        0x8u
#define ENC_CTRL_DIE_SHIFT                       3
#define ENC_CTRL_DIRQ_MASK                       0x10u
#define ENC_CTRL_DIRQ_SHIFT                      4
#define ENC_CTRL_XNE_MASK                        0x20u
#define ENC_CTRL_XNE_SHIFT                       5
#define ENC_CTRL_XIP_MASK                        0x40u
#define ENC_CTRL_XIP_SHIFT                       6
#define ENC_CTRL_XIE_MASK                        0x80u
#define ENC_CTRL_XIE_SHIFT                       7
#define ENC_CTRL_XIRQ_MASK                       0x100u
#define ENC_CTRL_XIRQ_SHIFT                      8
#define ENC_CTRL_PH1_MASK                        0x200u
#define ENC_CTRL_PH1_SHIFT                       9
#define ENC_CTRL_REV_MASK                        0x400u
#define ENC_CTRL_REV_SHIFT                       10
#define ENC_CTRL_SWIP_MASK                       0x800u
#define ENC_CTRL_SWIP_SHIFT                      11
#define ENC_CTRL_HNE_MASK                        0x1000u
#define ENC_CTRL_HNE_SHIFT                       12
#define ENC_CTRL_HIP_MASK                        0x2000u
#define ENC_CTRL_HIP_SHIFT                       13
#define ENC_CTRL_HIE_MASK                        0x4000u
#define ENC_CTRL_HIE_SHIFT                       14
#define ENC_CTRL_HIRQ_MASK                       0x8000u
#define ENC_CTRL_HIRQ_SHIFT                      15
/* FILT Bit Fields */
#define ENC_FILT_FILT_PER_MASK                   0xFFu
#define ENC_FILT_FILT_PER_SHIFT                  0
#define ENC_FILT_FILT_PER(x)                     (((uint16_t)(((uint16_t)(x))<<ENC_FILT_FILT_PER_SHIFT))&ENC_FILT_FILT_PER_MASK)
#define ENC_FILT_FILT_CNT_MASK                   0x700u
#define ENC_FILT_FILT_CNT_SHIFT                  8
#define ENC_FILT_FILT_CNT(x)                     (((uint16_t)(((uint16_t)(x))<<ENC_FILT_FILT_CNT_SHIFT))&ENC_FILT_FILT_CNT_MASK)
/* WTR Bit Fields */
#define ENC_WTR_WDOG_MASK                        0xFFFFu
#define ENC_WTR_WDOG_SHIFT                       0
#define ENC_WTR_WDOG(x)                          (((uint16_t)(((uint16_t)(x))<<ENC_WTR_WDOG_SHIFT))&ENC_WTR_WDOG_MASK)
/* POSD Bit Fields */
#define ENC_POSD_POSD_MASK                       0xFFFFu
#define ENC_POSD_POSD_SHIFT                      0
#define ENC_POSD_POSD(x)                         (((uint16_t)(((uint16_t)(x))<<ENC_POSD_POSD_SHIFT))&ENC_POSD_POSD_MASK)
/* POSDH Bit Fields */
#define ENC_POSDH_POSDH_MASK                     0xFFFFu
#define ENC_POSDH_POSDH_SHIFT                    0
#define ENC_POSDH_POSDH(x)                       (((uint16_t)(((uint16_t)(x))<<ENC_POSDH_POSDH_SHIFT))&ENC_POSDH_POSDH_MASK)
/* REV Bit Fields */
#define ENC_REV_REV_MASK                         0xFFFFu
#define ENC_REV_REV_SHIFT                        0
#define ENC_REV_REV(x)                           (((uint16_t)(((uint16_t)(x))<<ENC_REV_REV_SHIFT))&ENC_REV_REV_MASK)
/* REVH Bit Fields */
#define ENC_REVH_REVH_MASK                       0xFFFFu
#define ENC_REVH_REVH_SHIFT                      0
#define ENC_REVH_REVH(x)                         (((uint16_t)(((uint16_t)(x))<<ENC_REVH_REVH_SHIFT))&ENC_REVH_REVH_MASK)
/* UPOS Bit Fields */
#define ENC_UPOS_POS_MASK                        0xFFFFu
#define ENC_UPOS_POS_SHIFT                       0
#define ENC_UPOS_POS(x)                          (((uint16_t)(((uint16_t)(x))<<ENC_UPOS_POS_SHIFT))&ENC_UPOS_POS_MASK)
/* LPOS Bit Fields */
#define ENC_LPOS_POS_MASK                        0xFFFFu
#define ENC_LPOS_POS_SHIFT                       0
#define ENC_LPOS_POS(x)                          (((uint16_t)(((uint16_t)(x))<<ENC_LPOS_POS_SHIFT))&ENC_LPOS_POS_MASK)
/* UPOSH Bit Fields */
#define ENC_UPOSH_POSH_MASK                      0xFFFFu
#define ENC_UPOSH_POSH_SHIFT                     0
#define ENC_UPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_UPOSH_POSH_SHIFT))&ENC_UPOSH_POSH_MASK)
/* LPOSH Bit Fields */
#define ENC_LPOSH_POSH_MASK                      0xFFFFu
#define ENC_LPOSH_POSH_SHIFT                     0
#define ENC_LPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_LPOSH_POSH_SHIFT))&ENC_LPOSH_POSH_MASK)
/* UINIT Bit Fields */
#define ENC_UINIT_INIT_MASK                      0xFFFFu
#define ENC_UINIT_INIT_SHIFT                     0
#define ENC_UINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_UINIT_INIT_SHIFT))&ENC_UINIT_INIT_MASK)
/* LINIT Bit Fields */
#define ENC_LINIT_INIT_MASK                      0xFFFFu
#define ENC_LINIT_INIT_SHIFT                     0
#define ENC_LINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_LINIT_INIT_SHIFT))&ENC_LINIT_INIT_MASK)
/* IMR Bit Fields */
#define ENC_IMR_HOME_MASK                        0x1u
#define ENC_IMR_HOME_SHIFT                       0
#define ENC_IMR_INDEX_MASK                       0x2u
#define ENC_IMR_INDEX_SHIFT                      1
#define ENC_IMR_PHB_MASK                         0x4u
#define ENC_IMR_PHB_SHIFT                        2
#define ENC_IMR_PHA_MASK                         0x8u
#define ENC_IMR_PHA_SHIFT                        3
#define ENC_IMR_FHOM_MASK                        0x10u
#define ENC_IMR_FHOM_SHIFT                       4
#define ENC_IMR_FIND_MASK                        0x20u
#define ENC_IMR_FIND_SHIFT                       5
#define ENC_IMR_FPHB_MASK                        0x40u
#define ENC_IMR_FPHB_SHIFT                       6
#define ENC_IMR_FPHA_MASK                        0x80u
#define ENC_IMR_FPHA_SHIFT                       7
/* TST Bit Fields */
#define ENC_TST_TEST_COUNT_MASK                  0xFFu
#define ENC_TST_TEST_COUNT_SHIFT                 0
#define ENC_TST_TEST_COUNT(x)                    (((uint16_t)(((uint16_t)(x))<<ENC_TST_TEST_COUNT_SHIFT))&ENC_TST_TEST_COUNT_MASK)
#define ENC_TST_TEST_PERIOD_MASK                 0x1F00u
#define ENC_TST_TEST_PERIOD_SHIFT                8
#define ENC_TST_TEST_PERIOD(x)                   (((uint16_t)(((uint16_t)(x))<<ENC_TST_TEST_PERIOD_SHIFT))&ENC_TST_TEST_PERIOD_MASK)
#define ENC_TST_QDN_MASK                         0x2000u
#define ENC_TST_QDN_SHIFT                        13
#define ENC_TST_TCE_MASK                         0x4000u
#define ENC_TST_TCE_SHIFT                        14
#define ENC_TST_TEN_MASK                         0x8000u
#define ENC_TST_TEN_SHIFT                        15
/* CTRL2 Bit Fields */
#define ENC_CTRL2_UPDHLD_MASK                    0x1u
#define ENC_CTRL2_UPDHLD_SHIFT                   0
#define ENC_CTRL2_UPDPOS_MASK                    0x2u
#define ENC_CTRL2_UPDPOS_SHIFT                   1
#define ENC_CTRL2_MOD_MASK                       0x4u
#define ENC_CTRL2_MOD_SHIFT                      2
#define ENC_CTRL2_DIR_MASK                       0x8u
#define ENC_CTRL2_DIR_SHIFT                      3
#define ENC_CTRL2_RUIE_MASK                      0x10u
#define ENC_CTRL2_RUIE_SHIFT                     4
#define ENC_CTRL2_RUIRQ_MASK                     0x20u
#define ENC_CTRL2_RUIRQ_SHIFT                    5
#define ENC_CTRL2_ROIE_MASK                      0x40u
#define ENC_CTRL2_ROIE_SHIFT                     6
#define ENC_CTRL2_ROIRQ_MASK                     0x80u
#define ENC_CTRL2_ROIRQ_SHIFT                    7
#define ENC_CTRL2_REVMOD_MASK                    0x100u
#define ENC_CTRL2_REVMOD_SHIFT                   8
#define ENC_CTRL2_OUTCTL_MASK                    0x200u
#define ENC_CTRL2_OUTCTL_SHIFT                   9
#define ENC_CTRL2_SABIE_MASK                     0x400u
#define ENC_CTRL2_SABIE_SHIFT                    10
#define ENC_CTRL2_SABIRQ_MASK                    0x800u
#define ENC_CTRL2_SABIRQ_SHIFT                   11
/* UMOD Bit Fields */
#define ENC_UMOD_MOD_MASK                        0xFFFFu
#define ENC_UMOD_MOD_SHIFT                       0
#define ENC_UMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x))<<ENC_UMOD_MOD_SHIFT))&ENC_UMOD_MOD_MASK)
/* LMOD Bit Fields */
#define ENC_LMOD_MOD_MASK                        0xFFFFu
#define ENC_LMOD_MOD_SHIFT                       0
#define ENC_LMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x))<<ENC_LMOD_MOD_SHIFT))&ENC_LMOD_MOD_MASK)
/* UCOMP Bit Fields */
#define ENC_UCOMP_COMP_MASK                      0xFFFFu
#define ENC_UCOMP_COMP_SHIFT                     0
#define ENC_UCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_UCOMP_COMP_SHIFT))&ENC_UCOMP_COMP_MASK)
/* LCOMP Bit Fields */
#define ENC_LCOMP_COMP_MASK                      0xFFFFu
#define ENC_LCOMP_COMP_SHIFT                     0
#define ENC_LCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x))<<ENC_LCOMP_COMP_SHIFT))&ENC_LCOMP_COMP_MASK)

/*!
 * @}
 */ /* end of group ENC_Register_Masks */


/* ENC - Peripheral instance base addresses */
/** Peripheral ENC base pointer */
#define ENC_BASE_PTR                             ((ENC_MemMapPtr)0x40055000u)
/** Array initializer of ENC peripheral base pointers */
#define ENC_BASE_PTRS                            { ENC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ENC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENC_Register_Accessor_Macros ENC - Register accessor macros
 * @{
 */


/* ENC - Register instance definitions */
/* ENC */
#define ENC_CTRL                                 ENC_CTRL_REG(ENC_BASE_PTR)
#define ENC_FILT                                 ENC_FILT_REG(ENC_BASE_PTR)
#define ENC_WTR                                  ENC_WTR_REG(ENC_BASE_PTR)
#define ENC_POSD                                 ENC_POSD_REG(ENC_BASE_PTR)
#define ENC_POSDH                                ENC_POSDH_REG(ENC_BASE_PTR)
#define ENC_REV                                  ENC_REV_REG(ENC_BASE_PTR)
#define ENC_REVH                                 ENC_REVH_REG(ENC_BASE_PTR)
#define ENC_UPOS                                 ENC_UPOS_REG(ENC_BASE_PTR)
#define ENC_LPOS                                 ENC_LPOS_REG(ENC_BASE_PTR)
#define ENC_UPOSH                                ENC_UPOSH_REG(ENC_BASE_PTR)
#define ENC_LPOSH                                ENC_LPOSH_REG(ENC_BASE_PTR)
#define ENC_UINIT                                ENC_UINIT_REG(ENC_BASE_PTR)
#define ENC_LINIT                                ENC_LINIT_REG(ENC_BASE_PTR)
#define ENC_IMR                                  ENC_IMR_REG(ENC_BASE_PTR)
#define ENC_TST                                  ENC_TST_REG(ENC_BASE_PTR)
#define ENC_CTRL2                                ENC_CTRL2_REG(ENC_BASE_PTR)
#define ENC_UMOD                                 ENC_UMOD_REG(ENC_BASE_PTR)
#define ENC_LMOD                                 ENC_LMOD_REG(ENC_BASE_PTR)
#define ENC_UCOMP                                ENC_UCOMP_REG(ENC_BASE_PTR)
#define ENC_LCOMP                                ENC_LCOMP_REG(ENC_BASE_PTR)

/*!
 * @}
 */ /* end of group ENC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ENC_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETB
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETB_Peripheral ETB
 * @{
 */

/** ETB - Peripheral register structure */
typedef struct ETB_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t RDP;                                    /**< RAM Depth Register, offset: 0x4 */
  uint8_t RESERVED_1[4];
  uint32_t STS;                                    /**< Status Register, offset: 0xC */
  uint32_t RRD;                                    /**< RAM Read Data Register, offset: 0x10 */
  uint32_t RRP;                                    /**< RAM Read Pointer Register, offset: 0x14 */
  uint32_t RWP;                                    /**< RAM Write Pointer Register, offset: 0x18 */
  uint32_t TRG;                                    /**< Trigger Counter Register, offset: 0x1C */
  uint32_t CTL;                                    /**< Control Register, offset: 0x20 */
  uint32_t RWD;                                    /**< RAM Write Data Register, offset: 0x24 */
  uint8_t RESERVED_2[728];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint8_t RESERVED_3[3032];
  uint32_t ITMISCOP0;                              /**< Integration Register, ITMISCOP0, offset: 0xEE0 */
  uint32_t ITTRFLINACK;                            /**< Integration Register, ITTRFLINACK, offset: 0xEE4 */
  uint32_t ITTRFLIN;                               /**< Integration Register, ITTRFLIN, offset: 0xEE8 */
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_4[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_7[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register accessors */
#define ETB_RDP_REG(base)                        ((base)->RDP)
#define ETB_STS_REG(base)                        ((base)->STS)
#define ETB_RRD_REG(base)                        ((base)->RRD)
#define ETB_RRP_REG(base)                        ((base)->RRP)
#define ETB_RWP_REG(base)                        ((base)->RWP)
#define ETB_TRG_REG(base)                        ((base)->TRG)
#define ETB_CTL_REG(base)                        ((base)->CTL)
#define ETB_RWD_REG(base)                        ((base)->RWD)
#define ETB_FFSR_REG(base)                       ((base)->FFSR)
#define ETB_FFCR_REG(base)                       ((base)->FFCR)
#define ETB_ITMISCOP0_REG(base)                  ((base)->ITMISCOP0)
#define ETB_ITTRFLINACK_REG(base)                ((base)->ITTRFLINACK)
#define ETB_ITTRFLIN_REG(base)                   ((base)->ITTRFLIN)
#define ETB_ITATBDATA0_REG(base)                 ((base)->ITATBDATA0)
#define ETB_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETB_ITATBCTR1_REG(base)                  ((base)->ITATBCTR1)
#define ETB_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETB_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETB_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETB_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETB_LAR_REG(base)                        ((base)->LAR)
#define ETB_LSR_REG(base)                        ((base)->LSR)
#define ETB_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETB_DEVID_REG(base)                      ((base)->DEVID)
#define ETB_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETB_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETB_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETB_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETB_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETB_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETB_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETB_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETB_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETB_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETB_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETB_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETB_CIDR3_REG(base)                      ((base)->CIDR3)

/*!
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETB_Register_Masks ETB Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group ETB_Register_Masks */


/* ETB - Peripheral instance base addresses */
/** Peripheral ETB base pointer */
#define ETB_BASE_PTR                             ((ETB_MemMapPtr)0xE0042000u)
/** Array initializer of ETB peripheral base pointers */
#define ETB_BASE_PTRS                            { ETB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register instance definitions */
/* ETB */
#define ETB_RDP                                  ETB_RDP_REG(ETB_BASE_PTR)
#define ETB_STS                                  ETB_STS_REG(ETB_BASE_PTR)
#define ETB_RRD                                  ETB_RRD_REG(ETB_BASE_PTR)
#define ETB_RRP                                  ETB_RRP_REG(ETB_BASE_PTR)
#define ETB_RWP                                  ETB_RWP_REG(ETB_BASE_PTR)
#define ETB_TRG                                  ETB_TRG_REG(ETB_BASE_PTR)
#define ETB_CTL                                  ETB_CTL_REG(ETB_BASE_PTR)
#define ETB_RWD                                  ETB_RWD_REG(ETB_BASE_PTR)
#define ETB_FFSR                                 ETB_FFSR_REG(ETB_BASE_PTR)
#define ETB_FFCR                                 ETB_FFCR_REG(ETB_BASE_PTR)
#define ETB_ITMISCOP0                            ETB_ITMISCOP0_REG(ETB_BASE_PTR)
#define ETB_ITTRFLINACK                          ETB_ITTRFLINACK_REG(ETB_BASE_PTR)
#define ETB_ITTRFLIN                             ETB_ITTRFLIN_REG(ETB_BASE_PTR)
#define ETB_ITATBDATA0                           ETB_ITATBDATA0_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR2                            ETB_ITATBCTR2_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR1                            ETB_ITATBCTR1_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR0                            ETB_ITATBCTR0_REG(ETB_BASE_PTR)
#define ETB_ITCTRL                               ETB_ITCTRL_REG(ETB_BASE_PTR)
#define ETB_CLAIMSET                             ETB_CLAIMSET_REG(ETB_BASE_PTR)
#define ETB_CLAIMCLR                             ETB_CLAIMCLR_REG(ETB_BASE_PTR)
#define ETB_LAR                                  ETB_LAR_REG(ETB_BASE_PTR)
#define ETB_LSR                                  ETB_LSR_REG(ETB_BASE_PTR)
#define ETB_AUTHSTATUS                           ETB_AUTHSTATUS_REG(ETB_BASE_PTR)
#define ETB_DEVID                                ETB_DEVID_REG(ETB_BASE_PTR)
#define ETB_DEVTYPE                              ETB_DEVTYPE_REG(ETB_BASE_PTR)
#define ETB_PIDR4                                ETB_PIDR4_REG(ETB_BASE_PTR)
#define ETB_PIDR5                                ETB_PIDR5_REG(ETB_BASE_PTR)
#define ETB_PIDR6                                ETB_PIDR6_REG(ETB_BASE_PTR)
#define ETB_PIDR7                                ETB_PIDR7_REG(ETB_BASE_PTR)
#define ETB_PIDR0                                ETB_PIDR0_REG(ETB_BASE_PTR)
#define ETB_PIDR1                                ETB_PIDR1_REG(ETB_BASE_PTR)
#define ETB_PIDR2                                ETB_PIDR2_REG(ETB_BASE_PTR)
#define ETB_PIDR3                                ETB_PIDR3_REG(ETB_BASE_PTR)
#define ETB_CIDR0                                ETB_CIDR0_REG(ETB_BASE_PTR)
#define ETB_CIDR1                                ETB_CIDR1_REG(ETB_BASE_PTR)
#define ETB_CIDR2                                ETB_CIDR2_REG(ETB_BASE_PTR)
#define ETB_CIDR3                                ETB_CIDR3_REG(ETB_BASE_PTR)

/*!
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ETB_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETF
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETF_Peripheral ETF
 * @{
 */

/** ETF - Peripheral register structure */
typedef struct ETF_MemMap {
  uint32_t FCR;                                    /**< Funnel Control Register, offset: 0x0 */
  uint32_t PCR;                                    /**< Priority Control Register, offset: 0x4 */
  uint8_t RESERVED_0[3812];
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_1[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_2[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_3[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_4[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register accessors */
#define ETF_FCR_REG(base)                        ((base)->FCR)
#define ETF_PCR_REG(base)                        ((base)->PCR)
#define ETF_ITATBDATA0_REG(base)                 ((base)->ITATBDATA0)
#define ETF_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETF_ITATBCTR1_REG(base)                  ((base)->ITATBCTR1)
#define ETF_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETF_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETF_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETF_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETF_LAR_REG(base)                        ((base)->LAR)
#define ETF_LSR_REG(base)                        ((base)->LSR)
#define ETF_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETF_DEVID_REG(base)                      ((base)->DEVID)
#define ETF_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETF_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETF_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETF_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETF_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETF_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETF_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETF_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETF_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETF_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETF_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETF_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETF_CIDR3_REG(base)                      ((base)->CIDR3)

/*!
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETF_Register_Masks ETF Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group ETF_Register_Masks */


/* ETF - Peripheral instance base addresses */
/** Peripheral ETF base pointer */
#define ETF_BASE_PTR                             ((ETF_MemMapPtr)0xE0043000u)
/** Array initializer of ETF peripheral base pointers */
#define ETF_BASE_PTRS                            { ETF_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register instance definitions */
/* ETF */
#define ETF_FCR                                  ETF_FCR_REG(ETF_BASE_PTR)
#define ETF_PCR                                  ETF_PCR_REG(ETF_BASE_PTR)
#define ETF_ITATBDATA0                           ETF_ITATBDATA0_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR2                            ETF_ITATBCTR2_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR1                            ETF_ITATBCTR1_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR0                            ETF_ITATBCTR0_REG(ETF_BASE_PTR)
#define ETF_ITCTRL                               ETF_ITCTRL_REG(ETF_BASE_PTR)
#define ETF_CLAIMSET                             ETF_CLAIMSET_REG(ETF_BASE_PTR)
#define ETF_CLAIMCLR                             ETF_CLAIMCLR_REG(ETF_BASE_PTR)
#define ETF_LAR                                  ETF_LAR_REG(ETF_BASE_PTR)
#define ETF_LSR                                  ETF_LSR_REG(ETF_BASE_PTR)
#define ETF_AUTHSTATUS                           ETF_AUTHSTATUS_REG(ETF_BASE_PTR)
#define ETF_DEVID                                ETF_DEVID_REG(ETF_BASE_PTR)
#define ETF_DEVTYPE                              ETF_DEVTYPE_REG(ETF_BASE_PTR)
#define ETF_PIDR4                                ETF_PIDR4_REG(ETF_BASE_PTR)
#define ETF_PIDR5                                ETF_PIDR5_REG(ETF_BASE_PTR)
#define ETF_PIDR6                                ETF_PIDR6_REG(ETF_BASE_PTR)
#define ETF_PIDR7                                ETF_PIDR7_REG(ETF_BASE_PTR)
#define ETF_PIDR0                                ETF_PIDR0_REG(ETF_BASE_PTR)
#define ETF_PIDR1                                ETF_PIDR1_REG(ETF_BASE_PTR)
#define ETF_PIDR2                                ETF_PIDR2_REG(ETF_BASE_PTR)
#define ETF_PIDR3                                ETF_PIDR3_REG(ETF_BASE_PTR)
#define ETF_CIDR0                                ETF_CIDR0_REG(ETF_BASE_PTR)
#define ETF_CIDR1                                ETF_CIDR1_REG(ETF_BASE_PTR)
#define ETF_CIDR2                                ETF_CIDR2_REG(ETF_BASE_PTR)
#define ETF_CIDR3                                ETF_CIDR3_REG(ETF_BASE_PTR)

/*!
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ETF_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETM_Peripheral ETM
 * @{
 */

/** ETM - Peripheral register structure */
typedef struct ETM_MemMap {
  uint32_t CR;                                     /**< Main Control Register, offset: 0x0 */
  uint32_t CCR;                                    /**< Configuration Code Register, offset: 0x4 */
  uint32_t TRIGGER;                                /**< Trigger Event Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t SR;                                     /**< ETM Status Register, offset: 0x10 */
  uint32_t SCR;                                    /**< System Configuration Register, offset: 0x14 */
  uint8_t RESERVED_1[8];
  uint32_t EEVR;                                   /**< Trace Enable Event Register, offset: 0x20 */
  uint32_t TECR1;                                  /**< Trace Enable Control 1 Register, offset: 0x24 */
  uint32_t FFLR;                                   /**< FIFOFULL Level Register, offset: 0x28 */
  uint8_t RESERVED_2[276];
  uint32_t CNTRLDVR1;                              /**< Free-running counter reload value, offset: 0x140 */
  uint8_t RESERVED_3[156];
  uint32_t SYNCFR;                                 /**< Synchronization Frequency Register, offset: 0x1E0 */
  uint32_t IDR;                                    /**< ID Register, offset: 0x1E4 */
  uint32_t CCER;                                   /**< Configuration Code Extension Register, offset: 0x1E8 */
  uint8_t RESERVED_4[4];
  uint32_t TESSEICR;                               /**< TraceEnable Start/Stop EmbeddedICE Control Register, offset: 0x1F0 */
  uint8_t RESERVED_5[4];
  uint32_t TSEVR;                                  /**< Timestamp Event Register, offset: 0x1F8 */
  uint8_t RESERVED_6[4];
  uint32_t TRACEIDR;                               /**< CoreSight Trace ID Register, offset: 0x200 */
  uint8_t RESERVED_7[4];
  uint32_t IDR2;                                   /**< ETM ID Register 2, offset: 0x208 */
  uint8_t RESERVED_8[264];
  uint32_t PDSR;                                   /**< Device Power-Down Status Register, offset: 0x314 */
  uint8_t RESERVED_9[3016];
  uint32_t ITMISCIN;                               /**< Integration Test Miscelaneous Inputs Register, offset: 0xEE0 */
  uint8_t RESERVED_10[4];
  uint32_t ITTRIGOUT;                              /**< Integration Test Trigger Out Register, offset: 0xEE8 */
  uint8_t RESERVED_11[4];
  uint32_t ITATBCTR2;                              /**< ETM Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_12[4];
  uint32_t ITATBCTR0;                              /**< ETM Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint8_t RESERVED_13[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_14[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_15[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_16[16];
  uint32_t DEVTYPE;                                /**< CoreSight Device Type Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register accessors */
#define ETM_CR_REG(base)                         ((base)->CR)
#define ETM_CCR_REG(base)                        ((base)->CCR)
#define ETM_TRIGGER_REG(base)                    ((base)->TRIGGER)
#define ETM_SR_REG(base)                         ((base)->SR)
#define ETM_SCR_REG(base)                        ((base)->SCR)
#define ETM_EEVR_REG(base)                       ((base)->EEVR)
#define ETM_TECR1_REG(base)                      ((base)->TECR1)
#define ETM_FFLR_REG(base)                       ((base)->FFLR)
#define ETM_CNTRLDVR1_REG(base)                  ((base)->CNTRLDVR1)
#define ETM_SYNCFR_REG(base)                     ((base)->SYNCFR)
#define ETM_IDR_REG(base)                        ((base)->IDR)
#define ETM_CCER_REG(base)                       ((base)->CCER)
#define ETM_TESSEICR_REG(base)                   ((base)->TESSEICR)
#define ETM_TSEVR_REG(base)                      ((base)->TSEVR)
#define ETM_TRACEIDR_REG(base)                   ((base)->TRACEIDR)
#define ETM_IDR2_REG(base)                       ((base)->IDR2)
#define ETM_PDSR_REG(base)                       ((base)->PDSR)
#define ETM_ITMISCIN_REG(base)                   ((base)->ITMISCIN)
#define ETM_ITTRIGOUT_REG(base)                  ((base)->ITTRIGOUT)
#define ETM_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETM_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETM_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETM_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETM_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETM_LAR_REG(base)                        ((base)->LAR)
#define ETM_LSR_REG(base)                        ((base)->LSR)
#define ETM_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETM_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETM_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETM_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETM_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETM_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETM_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETM_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETM_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETM_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETM_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETM_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETM_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETM_CIDR3_REG(base)                      ((base)->CIDR3)

/*!
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETM_Register_Masks ETM Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group ETM_Register_Masks */


/* ETM - Peripheral instance base addresses */
/** Peripheral ETM base pointer */
#define ETM_BASE_PTR                             ((ETM_MemMapPtr)0xE0041000u)
/** Array initializer of ETM peripheral base pointers */
#define ETM_BASE_PTRS                            { ETM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register instance definitions */
/* ETM */
#define ETMCR                                    ETM_CR_REG(ETM_BASE_PTR)
#define ETMCCR                                   ETM_CCR_REG(ETM_BASE_PTR)
#define ETMTRIGGER                               ETM_TRIGGER_REG(ETM_BASE_PTR)
#define ETMSR                                    ETM_SR_REG(ETM_BASE_PTR)
#define ETMSCR                                   ETM_SCR_REG(ETM_BASE_PTR)
#define ETMEEVR                                  ETM_EEVR_REG(ETM_BASE_PTR)
#define ETMTECR1                                 ETM_TECR1_REG(ETM_BASE_PTR)
#define ETMFFLR                                  ETM_FFLR_REG(ETM_BASE_PTR)
#define ETMCNTRLDVR1                             ETM_CNTRLDVR1_REG(ETM_BASE_PTR)
#define ETMSYNCFR                                ETM_SYNCFR_REG(ETM_BASE_PTR)
#define ETMIDR                                   ETM_IDR_REG(ETM_BASE_PTR)
#define ETMCCER                                  ETM_CCER_REG(ETM_BASE_PTR)
#define ETMTESSEICR                              ETM_TESSEICR_REG(ETM_BASE_PTR)
#define ETMTSEVR                                 ETM_TSEVR_REG(ETM_BASE_PTR)
#define ETMTRACEIDR                              ETM_TRACEIDR_REG(ETM_BASE_PTR)
#define ETMIDR2                                  ETM_IDR2_REG(ETM_BASE_PTR)
#define ETMPDSR                                  ETM_PDSR_REG(ETM_BASE_PTR)
#define ETM_ITMISCIN                             ETM_ITMISCIN_REG(ETM_BASE_PTR)
#define ETM_ITTRIGOUT                            ETM_ITTRIGOUT_REG(ETM_BASE_PTR)
#define ETM_ITATBCTR2                            ETM_ITATBCTR2_REG(ETM_BASE_PTR)
#define ETM_ITATBCTR0                            ETM_ITATBCTR0_REG(ETM_BASE_PTR)
#define ETMITCTRL                                ETM_ITCTRL_REG(ETM_BASE_PTR)
#define ETMCLAIMSET                              ETM_CLAIMSET_REG(ETM_BASE_PTR)
#define ETMCLAIMCLR                              ETM_CLAIMCLR_REG(ETM_BASE_PTR)
#define ETMLAR                                   ETM_LAR_REG(ETM_BASE_PTR)
#define ETMLSR                                   ETM_LSR_REG(ETM_BASE_PTR)
#define ETMAUTHSTATUS                            ETM_AUTHSTATUS_REG(ETM_BASE_PTR)
#define ETMDEVTYPE                               ETM_DEVTYPE_REG(ETM_BASE_PTR)
#define ETMPIDR4                                 ETM_PIDR4_REG(ETM_BASE_PTR)
#define ETMPIDR5                                 ETM_PIDR5_REG(ETM_BASE_PTR)
#define ETMPIDR6                                 ETM_PIDR6_REG(ETM_BASE_PTR)
#define ETMPIDR7                                 ETM_PIDR7_REG(ETM_BASE_PTR)
#define ETMPIDR0                                 ETM_PIDR0_REG(ETM_BASE_PTR)
#define ETMPIDR1                                 ETM_PIDR1_REG(ETM_BASE_PTR)
#define ETMPIDR2                                 ETM_PIDR2_REG(ETM_BASE_PTR)
#define ETMPIDR3                                 ETM_PIDR3_REG(ETM_BASE_PTR)
#define ETMCIDR0                                 ETM_CIDR0_REG(ETM_BASE_PTR)
#define ETMCIDR1                                 ETM_CIDR1_REG(ETM_BASE_PTR)
#define ETMCIDR2                                 ETM_CIDR2_REG(ETM_BASE_PTR)
#define ETMCIDR3                                 ETM_CIDR3_REG(ETM_BASE_PTR)

/*!
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ETM_Peripheral */


/* ----------------------------------------------------------------------------
   -- EWM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral EWM
 * @{
 */

/** EWM - Peripheral register structure */
typedef struct EWM_MemMap {
  uint8_t CTRL;                                    /**< Control Register, offset: 0x0 */
  uint8_t SERV;                                    /**< Service Register, offset: 0x1 */
  uint8_t CMPL;                                    /**< Compare Low Register, offset: 0x2 */
  uint8_t CMPH;                                    /**< Compare High Register, offset: 0x3 */
} volatile *EWM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register accessors */
#define EWM_CTRL_REG(base)                       ((base)->CTRL)
#define EWM_SERV_REG(base)                       ((base)->SERV)
#define EWM_CMPL_REG(base)                       ((base)->CMPL)
#define EWM_CMPH_REG(base)                       ((base)->CMPH)

/*!
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define EWM_CTRL_EWMEN_MASK                      0x1u
#define EWM_CTRL_EWMEN_SHIFT                     0
#define EWM_CTRL_ASSIN_MASK                      0x2u
#define EWM_CTRL_ASSIN_SHIFT                     1
#define EWM_CTRL_INEN_MASK                       0x4u
#define EWM_CTRL_INEN_SHIFT                      2
#define EWM_CTRL_INTEN_MASK                      0x8u
#define EWM_CTRL_INTEN_SHIFT                     3
/* SERV Bit Fields */
#define EWM_SERV_SERVICE_MASK                    0xFFu
#define EWM_SERV_SERVICE_SHIFT                   0
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK)
/* CMPL Bit Fields */
#define EWM_CMPL_COMPAREL_MASK                   0xFFu
#define EWM_CMPL_COMPAREL_SHIFT                  0
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK)
/* CMPH Bit Fields */
#define EWM_CMPH_COMPAREH_MASK                   0xFFu
#define EWM_CMPH_COMPAREH_SHIFT                  0
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK)

/*!
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base pointer */
#define EWM_BASE_PTR                             ((EWM_MemMapPtr)0x40061000u)
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register instance definitions */
/* EWM */
#define EWM_CTRL                                 EWM_CTRL_REG(EWM_BASE_PTR)
#define EWM_SERV                                 EWM_SERV_REG(EWM_BASE_PTR)
#define EWM_CMPL                                 EWM_CMPL_REG(EWM_BASE_PTR)
#define EWM_CMPH                                 EWM_CMPH_REG(EWM_BASE_PTR)

/*!
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group EWM_Peripheral */


/* ----------------------------------------------------------------------------
   -- FMC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral FMC
 * @{
 */

/** FMC - Peripheral register structure */
typedef struct FMC_MemMap {
  uint32_t PFAPR;                                  /**< Flash Access Protection Register, offset: 0x0 */
  uint32_t PFB0CR;                                 /**< Flash Bank 0 Control Register, offset: 0x4 */
  uint32_t PFB1CR;                                 /**< Flash Bank 1 Control Register, offset: 0x8 */
  uint8_t RESERVED_0[244];
  uint32_t TAGVDW0S[2];                            /**< Cache Tag Storage, array offset: 0x100, array step: 0x4 */
  uint32_t TAGVDW1S[2];                            /**< Cache Tag Storage, array offset: 0x108, array step: 0x4 */
  uint32_t TAGVDW2S[2];                            /**< Cache Tag Storage, array offset: 0x110, array step: 0x4 */
  uint32_t TAGVDW3S[2];                            /**< Cache Tag Storage, array offset: 0x118, array step: 0x4 */
  uint8_t RESERVED_1[224];
  struct {                                         /* offset: 0x200, array step: 0x40 */
    struct {                                         /* offset: 0x200, array step: index*0x40, index2*0x10 */
      uint32_t DATA_UM;                                /**< Cache Data Storage (uppermost word), array offset: 0x200, array step: index*0x40, index2*0x10 */
      uint32_t DATA_MU;                                /**< Cache Data Storage (mid-upper word), array offset: 0x204, array step: index*0x40, index2*0x10 */
      uint32_t DATA_ML;                                /**< Cache Data Storage (mid-lower word), array offset: 0x208, array step: index*0x40, index2*0x10 */
      uint32_t DATA_LM;                                /**< Cache Data Storage (lowermost word), array offset: 0x20C, array step: index*0x40, index2*0x10 */
    } SET[2];
    uint8_t RESERVED_0[32];
  } WAY[4];
} volatile *FMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register accessors */
#define FMC_PFAPR_REG(base)                      ((base)->PFAPR)
#define FMC_PFB0CR_REG(base)                     ((base)->PFB0CR)
#define FMC_PFB1CR_REG(base)                     ((base)->PFB1CR)
#define FMC_TAGVDW0S_REG(base,index)             ((base)->TAGVDW0S[index])
#define FMC_TAGVDW1S_REG(base,index)             ((base)->TAGVDW1S[index])
#define FMC_TAGVDW2S_REG(base,index)             ((base)->TAGVDW2S[index])
#define FMC_TAGVDW3S_REG(base,index)             ((base)->TAGVDW3S[index])
#define FMC_DATA_UM_REG(base,index,index2)       ((base)->WAY[index].SET[index2].DATA_UM)
#define FMC_DATA_MU_REG(base,index,index2)       ((base)->WAY[index].SET[index2].DATA_MU)
#define FMC_DATA_ML_REG(base,index,index2)       ((base)->WAY[index].SET[index2].DATA_ML)
#define FMC_DATA_LM_REG(base,index,index2)       ((base)->WAY[index].SET[index2].DATA_LM)

/*!
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/* PFAPR Bit Fields */
#define FMC_PFAPR_M0AP_MASK                      0x3u
#define FMC_PFAPR_M0AP_SHIFT                     0
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0AP_SHIFT))&FMC_PFAPR_M0AP_MASK)
#define FMC_PFAPR_M1AP_MASK                      0xCu
#define FMC_PFAPR_M1AP_SHIFT                     2
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1AP_SHIFT))&FMC_PFAPR_M1AP_MASK)
#define FMC_PFAPR_M2AP_MASK                      0x30u
#define FMC_PFAPR_M2AP_SHIFT                     4
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2AP_SHIFT))&FMC_PFAPR_M2AP_MASK)
#define FMC_PFAPR_M0PFD_MASK                     0x10000u
#define FMC_PFAPR_M0PFD_SHIFT                    16
#define FMC_PFAPR_M1PFD_MASK                     0x20000u
#define FMC_PFAPR_M1PFD_SHIFT                    17
#define FMC_PFAPR_M2PFD_MASK                     0x40000u
#define FMC_PFAPR_M2PFD_SHIFT                    18
/* PFB0CR Bit Fields */
#define FMC_PFB0CR_B0SEBE_MASK                   0x1u
#define FMC_PFB0CR_B0SEBE_SHIFT                  0
#define FMC_PFB0CR_B0IPE_MASK                    0x2u
#define FMC_PFB0CR_B0IPE_SHIFT                   1
#define FMC_PFB0CR_B0DPE_MASK                    0x4u
#define FMC_PFB0CR_B0DPE_SHIFT                   2
#define FMC_PFB0CR_B0ICE_MASK                    0x8u
#define FMC_PFB0CR_B0ICE_SHIFT                   3
#define FMC_PFB0CR_B0DCE_MASK                    0x10u
#define FMC_PFB0CR_B0DCE_SHIFT                   4
#define FMC_PFB0CR_CRC_MASK                      0xE0u
#define FMC_PFB0CR_CRC_SHIFT                     5
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK)
#define FMC_PFB0CR_B0MW_MASK                     0x60000u
#define FMC_PFB0CR_B0MW_SHIFT                    17
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0MW_SHIFT))&FMC_PFB0CR_B0MW_MASK)
#define FMC_PFB0CR_S_B_INV_MASK                  0x80000u
#define FMC_PFB0CR_S_B_INV_SHIFT                 19
#define FMC_PFB0CR_CINV_WAY_MASK                 0xF00000u
#define FMC_PFB0CR_CINV_WAY_SHIFT                20
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CINV_WAY_SHIFT))&FMC_PFB0CR_CINV_WAY_MASK)
#define FMC_PFB0CR_CLCK_WAY_MASK                 0xF000000u
#define FMC_PFB0CR_CLCK_WAY_SHIFT                24
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CLCK_WAY_SHIFT))&FMC_PFB0CR_CLCK_WAY_MASK)
#define FMC_PFB0CR_B0RWSC_MASK                   0xF0000000u
#define FMC_PFB0CR_B0RWSC_SHIFT                  28
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0RWSC_SHIFT))&FMC_PFB0CR_B0RWSC_MASK)
/* TAGVDW0S Bit Fields */
#define FMC_TAGVDW0S_valid_MASK                  0x1u
#define FMC_TAGVDW0S_valid_SHIFT                 0
#define FMC_TAGVDW0S_cache_tag_MASK              0xFFFE0u
#define FMC_TAGVDW0S_cache_tag_SHIFT             5
#define FMC_TAGVDW0S_cache_tag(x)                (((uint32_t)(((uint32_t)(x))<<FMC_TAGVDW0S_cache_tag_SHIFT))&FMC_TAGVDW0S_cache_tag_MASK)
/* TAGVDW1S Bit Fields */
#define FMC_TAGVDW1S_valid_MASK                  0x1u
#define FMC_TAGVDW1S_valid_SHIFT                 0
#define FMC_TAGVDW1S_cache_tag_MASK              0xFFFE0u
#define FMC_TAGVDW1S_cache_tag_SHIFT             5
#define FMC_TAGVDW1S_cache_tag(x)                (((uint32_t)(((uint32_t)(x))<<FMC_TAGVDW1S_cache_tag_SHIFT))&FMC_TAGVDW1S_cache_tag_MASK)
/* TAGVDW2S Bit Fields */
#define FMC_TAGVDW2S_valid_MASK                  0x1u
#define FMC_TAGVDW2S_valid_SHIFT                 0
#define FMC_TAGVDW2S_cache_tag_MASK              0xFFFE0u
#define FMC_TAGVDW2S_cache_tag_SHIFT             5
#define FMC_TAGVDW2S_cache_tag(x)                (((uint32_t)(((uint32_t)(x))<<FMC_TAGVDW2S_cache_tag_SHIFT))&FMC_TAGVDW2S_cache_tag_MASK)
/* TAGVDW3S Bit Fields */
#define FMC_TAGVDW3S_valid_MASK                  0x1u
#define FMC_TAGVDW3S_valid_SHIFT                 0
#define FMC_TAGVDW3S_cache_tag_MASK              0xFFFE0u
#define FMC_TAGVDW3S_cache_tag_SHIFT             5
#define FMC_TAGVDW3S_cache_tag(x)                (((uint32_t)(((uint32_t)(x))<<FMC_TAGVDW3S_cache_tag_SHIFT))&FMC_TAGVDW3S_cache_tag_MASK)
/* DATA_UM Bit Fields */
#define FMC_DATA_UM_data_MASK                    0xFFFFFFFFu
#define FMC_DATA_UM_data_SHIFT                   0
#define FMC_DATA_UM_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATA_UM_data_SHIFT))&FMC_DATA_UM_data_MASK)
/* DATA_MU Bit Fields */
#define FMC_DATA_MU_data_MASK                    0xFFFFFFFFu
#define FMC_DATA_MU_data_SHIFT                   0
#define FMC_DATA_MU_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATA_MU_data_SHIFT))&FMC_DATA_MU_data_MASK)
/* DATA_ML Bit Fields */
#define FMC_DATA_ML_data_MASK                    0xFFFFFFFFu
#define FMC_DATA_ML_data_SHIFT                   0
#define FMC_DATA_ML_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATA_ML_data_SHIFT))&FMC_DATA_ML_data_MASK)
/* DATA_LM Bit Fields */
#define FMC_DATA_LM_data_MASK                    0xFFFFFFFFu
#define FMC_DATA_LM_data_SHIFT                   0
#define FMC_DATA_LM_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATA_LM_data_SHIFT))&FMC_DATA_LM_data_MASK)

/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC base pointer */
#define FMC_BASE_PTR                             ((FMC_MemMapPtr)0x4001F000u)
/** Array initializer of FMC peripheral base pointers */
#define FMC_BASE_PTRS                            { FMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register instance definitions */
/* FMC */
#define FMC_PFAPR                                FMC_PFAPR_REG(FMC_BASE_PTR)
#define FMC_PFB0CR                               FMC_PFB0CR_REG(FMC_BASE_PTR)
#define FMC_PFB1CR                               FMC_PFB1CR_REG(FMC_BASE_PTR)
#define FMC_TAGVDW0S0                            FMC_TAGVDW0S_REG(FMC_BASE_PTR,0)
#define FMC_TAGVDW0S1                            FMC_TAGVDW0S_REG(FMC_BASE_PTR,1)
#define FMC_TAGVDW1S0                            FMC_TAGVDW1S_REG(FMC_BASE_PTR,0)
#define FMC_TAGVDW1S1                            FMC_TAGVDW1S_REG(FMC_BASE_PTR,1)
#define FMC_TAGVDW2S0                            FMC_TAGVDW2S_REG(FMC_BASE_PTR,0)
#define FMC_TAGVDW2S1                            FMC_TAGVDW2S_REG(FMC_BASE_PTR,1)
#define FMC_TAGVDW3S0                            FMC_TAGVDW3S_REG(FMC_BASE_PTR,0)
#define FMC_TAGVDW3S1                            FMC_TAGVDW3S_REG(FMC_BASE_PTR,1)
#define FMC_DATAW0S0UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S0MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S0ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S0LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S1UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S1MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S1ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S1LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW1S0UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S0MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S0ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S0LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S1UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S1MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S1ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S1LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW2S0UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S0MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S0ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S0LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S1UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S1MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S1ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S1LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW3S0UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S0MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S0ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S0LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S1UM                           FMC_DATA_UM_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1MU                           FMC_DATA_MU_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1ML                           FMC_DATA_ML_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1LM                           FMC_DATA_LM_REG(FMC_BASE_PTR,3,1)

/* FMC - Register array accessors */
#define FMC_TAGVDW0S(index)                      FMC_TAGVDW0S_REG(FMC_BASE_PTR,index)
#define FMC_TAGVDW1S(index)                      FMC_TAGVDW1S_REG(FMC_BASE_PTR,index)
#define FMC_TAGVDW2S(index)                      FMC_TAGVDW2S_REG(FMC_BASE_PTR,index)
#define FMC_TAGVDW3S(index)                      FMC_TAGVDW3S_REG(FMC_BASE_PTR,index)
#define FMC_DATA_UM(index,index2)                FMC_DATA_UM_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_MU(index,index2)                FMC_DATA_MU_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_ML(index,index2)                FMC_DATA_ML_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_LM(index,index2)                FMC_DATA_LM_REG(FMC_BASE_PTR,index,index2)

/*!
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- FPB
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FPB_Peripheral FPB
 * @{
 */

/** FPB - Peripheral register structure */
typedef struct FPB_MemMap {
  uint32_t CTRL;                                   /**< FlashPatch Control Register, offset: 0x0 */
  uint32_t REMAP;                                  /**< FlashPatch Remap Register, offset: 0x4 */
  uint32_t COMP[8];                                /**< FlashPatch Comparator Register 0..FlashPatch Comparator Register 7, array offset: 0x8, array step: 0x4 */
  uint8_t RESERVED_0[4008];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *FPB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register accessors */
#define FPB_CTRL_REG(base)                       ((base)->CTRL)
#define FPB_REMAP_REG(base)                      ((base)->REMAP)
#define FPB_COMP_REG(base,index)                 ((base)->COMP[index])
#define FPB_PID4_REG(base)                       ((base)->PID4)
#define FPB_PID5_REG(base)                       ((base)->PID5)
#define FPB_PID6_REG(base)                       ((base)->PID6)
#define FPB_PID7_REG(base)                       ((base)->PID7)
#define FPB_PID0_REG(base)                       ((base)->PID0)
#define FPB_PID1_REG(base)                       ((base)->PID1)
#define FPB_PID2_REG(base)                       ((base)->PID2)
#define FPB_PID3_REG(base)                       ((base)->PID3)
#define FPB_CID0_REG(base)                       ((base)->CID0)
#define FPB_CID1_REG(base)                       ((base)->CID1)
#define FPB_CID2_REG(base)                       ((base)->CID2)
#define FPB_CID3_REG(base)                       ((base)->CID3)

/*!
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FPB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FPB_Register_Masks FPB Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group FPB_Register_Masks */


/* FPB - Peripheral instance base addresses */
/** Peripheral FPB base pointer */
#define FPB_BASE_PTR                             ((FPB_MemMapPtr)0xE0002000u)
/** Array initializer of FPB peripheral base pointers */
#define FPB_BASE_PTRS                            { FPB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register instance definitions */
/* FPB */
#define FP_CTRL                                  FPB_CTRL_REG(FPB_BASE_PTR)
#define FP_REMAP                                 FPB_REMAP_REG(FPB_BASE_PTR)
#define FP_COMP0                                 FPB_COMP_REG(FPB_BASE_PTR,0)
#define FP_COMP1                                 FPB_COMP_REG(FPB_BASE_PTR,1)
#define FP_COMP2                                 FPB_COMP_REG(FPB_BASE_PTR,2)
#define FP_COMP3                                 FPB_COMP_REG(FPB_BASE_PTR,3)
#define FP_COMP4                                 FPB_COMP_REG(FPB_BASE_PTR,4)
#define FP_COMP5                                 FPB_COMP_REG(FPB_BASE_PTR,5)
#define FP_COMP6                                 FPB_COMP_REG(FPB_BASE_PTR,6)
#define FP_COMP7                                 FPB_COMP_REG(FPB_BASE_PTR,7)
#define FP_PID4                                  FPB_PID4_REG(FPB_BASE_PTR)
#define FP_PID5                                  FPB_PID5_REG(FPB_BASE_PTR)
#define FP_PID6                                  FPB_PID6_REG(FPB_BASE_PTR)
#define FP_PID7                                  FPB_PID7_REG(FPB_BASE_PTR)
#define FP_PID0                                  FPB_PID0_REG(FPB_BASE_PTR)
#define FP_PID1                                  FPB_PID1_REG(FPB_BASE_PTR)
#define FP_PID2                                  FPB_PID2_REG(FPB_BASE_PTR)
#define FP_PID3                                  FPB_PID3_REG(FPB_BASE_PTR)
#define FP_CID0                                  FPB_CID0_REG(FPB_BASE_PTR)
#define FP_CID1                                  FPB_CID1_REG(FPB_BASE_PTR)
#define FP_CID2                                  FPB_CID2_REG(FPB_BASE_PTR)
#define FP_CID3                                  FPB_CID3_REG(FPB_BASE_PTR)

/* FPB - Register array accessors */
#define FPB_COMP(index)                          FPB_COMP_REG(FPB_BASE_PTR,index)

/*!
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FPB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTFA
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Peripheral FTFA
 * @{
 */

/** FTFA - Peripheral register structure */
typedef struct FTFA_MemMap {
  uint8_t FSTAT;                                   /**< Flash Status Register, offset: 0x0 */
  uint8_t FCNFG;                                   /**< Flash Configuration Register, offset: 0x1 */
  uint8_t FSEC;                                    /**< Flash Security Register, offset: 0x2 */
  uint8_t FOPT;                                    /**< Flash Option Register, offset: 0x3 */
  uint8_t FCCOB3;                                  /**< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB2;                                  /**< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB1;                                  /**< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB0;                                  /**< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB7;                                  /**< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB6;                                  /**< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB5;                                  /**< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB4;                                  /**< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOBB;                                  /**< Flash Common Command Object Registers, offset: 0xC */
  uint8_t FCCOBA;                                  /**< Flash Common Command Object Registers, offset: 0xD */
  uint8_t FCCOB9;                                  /**< Flash Common Command Object Registers, offset: 0xE */
  uint8_t FCCOB8;                                  /**< Flash Common Command Object Registers, offset: 0xF */
  uint8_t FPROT3;                                  /**< Program Flash Protection Registers, offset: 0x10 */
  uint8_t FPROT2;                                  /**< Program Flash Protection Registers, offset: 0x11 */
  uint8_t FPROT1;                                  /**< Program Flash Protection Registers, offset: 0x12 */
  uint8_t FPROT0;                                  /**< Program Flash Protection Registers, offset: 0x13 */
  uint8_t RESERVED_0[4];
  uint8_t XACCH3;                                  /**< Execute-only Access Registers, offset: 0x18 */
  uint8_t XACCH2;                                  /**< Execute-only Access Registers, offset: 0x19 */
  uint8_t XACCH1;                                  /**< Execute-only Access Registers, offset: 0x1A */
  uint8_t XACCH0;                                  /**< Execute-only Access Registers, offset: 0x1B */
  uint8_t XACCL3;                                  /**< Execute-only Access Registers, offset: 0x1C */
  uint8_t XACCL2;                                  /**< Execute-only Access Registers, offset: 0x1D */
  uint8_t XACCL1;                                  /**< Execute-only Access Registers, offset: 0x1E */
  uint8_t XACCL0;                                  /**< Execute-only Access Registers, offset: 0x1F */
  uint8_t SACCH3;                                  /**< Supervisor-only Access Registers, offset: 0x20 */
  uint8_t SACCH2;                                  /**< Supervisor-only Access Registers, offset: 0x21 */
  uint8_t SACCH1;                                  /**< Supervisor-only Access Registers, offset: 0x22 */
  uint8_t SACCH0;                                  /**< Supervisor-only Access Registers, offset: 0x23 */
  uint8_t SACCL3;                                  /**< Supervisor-only Access Registers, offset: 0x24 */
  uint8_t SACCL2;                                  /**< Supervisor-only Access Registers, offset: 0x25 */
  uint8_t SACCL1;                                  /**< Supervisor-only Access Registers, offset: 0x26 */
  uint8_t SACCL0;                                  /**< Supervisor-only Access Registers, offset: 0x27 */
  uint8_t FACSS;                                   /**< Flash Access Segment Size Register, offset: 0x28 */
  uint8_t RESERVED_1[2];
  uint8_t FACSN;                                   /**< Flash Access Segment Number Register, offset: 0x2B */
} volatile *FTFA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Accessor_Macros FTFA - Register accessor macros
 * @{
 */


/* FTFA - Register accessors */
#define FTFA_FSTAT_REG(base)                     ((base)->FSTAT)
#define FTFA_FCNFG_REG(base)                     ((base)->FCNFG)
#define FTFA_FSEC_REG(base)                      ((base)->FSEC)
#define FTFA_FOPT_REG(base)                      ((base)->FOPT)
#define FTFA_FCCOB3_REG(base)                    ((base)->FCCOB3)
#define FTFA_FCCOB2_REG(base)                    ((base)->FCCOB2)
#define FTFA_FCCOB1_REG(base)                    ((base)->FCCOB1)
#define FTFA_FCCOB0_REG(base)                    ((base)->FCCOB0)
#define FTFA_FCCOB7_REG(base)                    ((base)->FCCOB7)
#define FTFA_FCCOB6_REG(base)                    ((base)->FCCOB6)
#define FTFA_FCCOB5_REG(base)                    ((base)->FCCOB5)
#define FTFA_FCCOB4_REG(base)                    ((base)->FCCOB4)
#define FTFA_FCCOBB_REG(base)                    ((base)->FCCOBB)
#define FTFA_FCCOBA_REG(base)                    ((base)->FCCOBA)
#define FTFA_FCCOB9_REG(base)                    ((base)->FCCOB9)
#define FTFA_FCCOB8_REG(base)                    ((base)->FCCOB8)
#define FTFA_FPROT3_REG(base)                    ((base)->FPROT3)
#define FTFA_FPROT2_REG(base)                    ((base)->FPROT2)
#define FTFA_FPROT1_REG(base)                    ((base)->FPROT1)
#define FTFA_FPROT0_REG(base)                    ((base)->FPROT0)
#define FTFA_XACCH3_REG(base)                    ((base)->XACCH3)
#define FTFA_XACCH2_REG(base)                    ((base)->XACCH2)
#define FTFA_XACCH1_REG(base)                    ((base)->XACCH1)
#define FTFA_XACCH0_REG(base)                    ((base)->XACCH0)
#define FTFA_XACCL3_REG(base)                    ((base)->XACCL3)
#define FTFA_XACCL2_REG(base)                    ((base)->XACCL2)
#define FTFA_XACCL1_REG(base)                    ((base)->XACCL1)
#define FTFA_XACCL0_REG(base)                    ((base)->XACCL0)
#define FTFA_SACCH3_REG(base)                    ((base)->SACCH3)
#define FTFA_SACCH2_REG(base)                    ((base)->SACCH2)
#define FTFA_SACCH1_REG(base)                    ((base)->SACCH1)
#define FTFA_SACCH0_REG(base)                    ((base)->SACCH0)
#define FTFA_SACCL3_REG(base)                    ((base)->SACCL3)
#define FTFA_SACCL2_REG(base)                    ((base)->SACCL2)
#define FTFA_SACCL1_REG(base)                    ((base)->SACCL1)
#define FTFA_SACCL0_REG(base)                    ((base)->SACCL0)
#define FTFA_FACSS_REG(base)                     ((base)->FACSS)
#define FTFA_FACSN_REG(base)                     ((base)->FACSN)

/*!
 * @}
 */ /* end of group FTFA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Masks FTFA Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#define FTFA_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFA_FSTAT_MGSTAT0_SHIFT                 0
#define FTFA_FSTAT_FPVIOL_MASK                   0x10u
#define FTFA_FSTAT_FPVIOL_SHIFT                  4
#define FTFA_FSTAT_ACCERR_MASK                   0x20u
#define FTFA_FSTAT_ACCERR_SHIFT                  5
#define FTFA_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFA_FSTAT_RDCOLERR_SHIFT                6
#define FTFA_FSTAT_CCIF_MASK                     0x80u
#define FTFA_FSTAT_CCIF_SHIFT                    7
/* FCNFG Bit Fields */
#define FTFA_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFA_FCNFG_ERSSUSP_SHIFT                 4
#define FTFA_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFA_FCNFG_ERSAREQ_SHIFT                 5
#define FTFA_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFA_FCNFG_RDCOLLIE_SHIFT                6
#define FTFA_FCNFG_CCIE_MASK                     0x80u
#define FTFA_FCNFG_CCIE_SHIFT                    7
/* FSEC Bit Fields */
#define FTFA_FSEC_SEC_MASK                       0x3u
#define FTFA_FSEC_SEC_SHIFT                      0
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK)
#define FTFA_FSEC_FSLACC_MASK                    0xCu
#define FTFA_FSEC_FSLACC_SHIFT                   2
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK)
#define FTFA_FSEC_MEEN_MASK                      0x30u
#define FTFA_FSEC_MEEN_SHIFT                     4
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK)
#define FTFA_FSEC_KEYEN_MASK                     0xC0u
#define FTFA_FSEC_KEYEN_SHIFT                    6
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFA_FOPT_OPT_MASK                       0xFFu
#define FTFA_FOPT_OPT_SHIFT                      0
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK)
/* FCCOB3 Bit Fields */
#define FTFA_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB3_CCOBn_SHIFT                  0
#define FTFA_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB3_CCOBn_SHIFT))&FTFA_FCCOB3_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFA_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB2_CCOBn_SHIFT                  0
#define FTFA_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB2_CCOBn_SHIFT))&FTFA_FCCOB2_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFA_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB1_CCOBn_SHIFT                  0
#define FTFA_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB1_CCOBn_SHIFT))&FTFA_FCCOB1_CCOBn_MASK)
/* FCCOB0 Bit Fields */
#define FTFA_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB0_CCOBn_SHIFT                  0
#define FTFA_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB0_CCOBn_SHIFT))&FTFA_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFA_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB7_CCOBn_SHIFT                  0
#define FTFA_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB7_CCOBn_SHIFT))&FTFA_FCCOB7_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFA_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB6_CCOBn_SHIFT                  0
#define FTFA_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB6_CCOBn_SHIFT))&FTFA_FCCOB6_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFA_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB5_CCOBn_SHIFT                  0
#define FTFA_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB5_CCOBn_SHIFT))&FTFA_FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFA_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB4_CCOBn_SHIFT                  0
#define FTFA_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB4_CCOBn_SHIFT))&FTFA_FCCOB4_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFA_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBB_CCOBn_SHIFT                  0
#define FTFA_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBB_CCOBn_SHIFT))&FTFA_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFA_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBA_CCOBn_SHIFT                  0
#define FTFA_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBA_CCOBn_SHIFT))&FTFA_FCCOBA_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFA_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB9_CCOBn_SHIFT                  0
#define FTFA_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB9_CCOBn_SHIFT))&FTFA_FCCOB9_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFA_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB8_CCOBn_SHIFT                  0
#define FTFA_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB8_CCOBn_SHIFT))&FTFA_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFA_FPROT3_PROT_MASK                    0xFFu
#define FTFA_FPROT3_PROT_SHIFT                   0
#define FTFA_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT3_PROT_SHIFT))&FTFA_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFA_FPROT2_PROT_MASK                    0xFFu
#define FTFA_FPROT2_PROT_SHIFT                   0
#define FTFA_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT2_PROT_SHIFT))&FTFA_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFA_FPROT1_PROT_MASK                    0xFFu
#define FTFA_FPROT1_PROT_SHIFT                   0
#define FTFA_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT1_PROT_SHIFT))&FTFA_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFA_FPROT0_PROT_MASK                    0xFFu
#define FTFA_FPROT0_PROT_SHIFT                   0
#define FTFA_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT0_PROT_SHIFT))&FTFA_FPROT0_PROT_MASK)
/* XACCH3 Bit Fields */
#define FTFA_XACCH3_XA_MASK                      0xFFu
#define FTFA_XACCH3_XA_SHIFT                     0
#define FTFA_XACCH3_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH3_XA_SHIFT))&FTFA_XACCH3_XA_MASK)
/* XACCH2 Bit Fields */
#define FTFA_XACCH2_XA_MASK                      0xFFu
#define FTFA_XACCH2_XA_SHIFT                     0
#define FTFA_XACCH2_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH2_XA_SHIFT))&FTFA_XACCH2_XA_MASK)
/* XACCH1 Bit Fields */
#define FTFA_XACCH1_XA_MASK                      0xFFu
#define FTFA_XACCH1_XA_SHIFT                     0
#define FTFA_XACCH1_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH1_XA_SHIFT))&FTFA_XACCH1_XA_MASK)
/* XACCH0 Bit Fields */
#define FTFA_XACCH0_XA_MASK                      0xFFu
#define FTFA_XACCH0_XA_SHIFT                     0
#define FTFA_XACCH0_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH0_XA_SHIFT))&FTFA_XACCH0_XA_MASK)
/* XACCL3 Bit Fields */
#define FTFA_XACCL3_XA_MASK                      0xFFu
#define FTFA_XACCL3_XA_SHIFT                     0
#define FTFA_XACCL3_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL3_XA_SHIFT))&FTFA_XACCL3_XA_MASK)
/* XACCL2 Bit Fields */
#define FTFA_XACCL2_XA_MASK                      0xFFu
#define FTFA_XACCL2_XA_SHIFT                     0
#define FTFA_XACCL2_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL2_XA_SHIFT))&FTFA_XACCL2_XA_MASK)
/* XACCL1 Bit Fields */
#define FTFA_XACCL1_XA_MASK                      0xFFu
#define FTFA_XACCL1_XA_SHIFT                     0
#define FTFA_XACCL1_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL1_XA_SHIFT))&FTFA_XACCL1_XA_MASK)
/* XACCL0 Bit Fields */
#define FTFA_XACCL0_XA_MASK                      0xFFu
#define FTFA_XACCL0_XA_SHIFT                     0
#define FTFA_XACCL0_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL0_XA_SHIFT))&FTFA_XACCL0_XA_MASK)
/* SACCH3 Bit Fields */
#define FTFA_SACCH3_SA_MASK                      0xFFu
#define FTFA_SACCH3_SA_SHIFT                     0
#define FTFA_SACCH3_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH3_SA_SHIFT))&FTFA_SACCH3_SA_MASK)
/* SACCH2 Bit Fields */
#define FTFA_SACCH2_SA_MASK                      0xFFu
#define FTFA_SACCH2_SA_SHIFT                     0
#define FTFA_SACCH2_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH2_SA_SHIFT))&FTFA_SACCH2_SA_MASK)
/* SACCH1 Bit Fields */
#define FTFA_SACCH1_SA_MASK                      0xFFu
#define FTFA_SACCH1_SA_SHIFT                     0
#define FTFA_SACCH1_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH1_SA_SHIFT))&FTFA_SACCH1_SA_MASK)
/* SACCH0 Bit Fields */
#define FTFA_SACCH0_SA_MASK                      0xFFu
#define FTFA_SACCH0_SA_SHIFT                     0
#define FTFA_SACCH0_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH0_SA_SHIFT))&FTFA_SACCH0_SA_MASK)
/* SACCL3 Bit Fields */
#define FTFA_SACCL3_SA_MASK                      0xFFu
#define FTFA_SACCL3_SA_SHIFT                     0
#define FTFA_SACCL3_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL3_SA_SHIFT))&FTFA_SACCL3_SA_MASK)
/* SACCL2 Bit Fields */
#define FTFA_SACCL2_SA_MASK                      0xFFu
#define FTFA_SACCL2_SA_SHIFT                     0
#define FTFA_SACCL2_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL2_SA_SHIFT))&FTFA_SACCL2_SA_MASK)
/* SACCL1 Bit Fields */
#define FTFA_SACCL1_SA_MASK                      0xFFu
#define FTFA_SACCL1_SA_SHIFT                     0
#define FTFA_SACCL1_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL1_SA_SHIFT))&FTFA_SACCL1_SA_MASK)
/* SACCL0 Bit Fields */
#define FTFA_SACCL0_SA_MASK                      0xFFu
#define FTFA_SACCL0_SA_SHIFT                     0
#define FTFA_SACCL0_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL0_SA_SHIFT))&FTFA_SACCL0_SA_MASK)
/* FACSS Bit Fields */
#define FTFA_FACSS_SGSIZE_MASK                   0xFFu
#define FTFA_FACSS_SGSIZE_SHIFT                  0
#define FTFA_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FACSS_SGSIZE_SHIFT))&FTFA_FACSS_SGSIZE_MASK)
/* FACSN Bit Fields */
#define FTFA_FACSN_NUMSG_MASK                    0xFFu
#define FTFA_FACSN_NUMSG_SHIFT                   0
#define FTFA_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FACSN_NUMSG_SHIFT))&FTFA_FACSN_NUMSG_MASK)

/*!
 * @}
 */ /* end of group FTFA_Register_Masks */


/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base pointer */
#define FTFA_BASE_PTR                            ((FTFA_MemMapPtr)0x40020000u)
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASE_PTRS                           { FTFA_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FTFA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Accessor_Macros FTFA - Register accessor macros
 * @{
 */


/* FTFA - Register instance definitions */
/* FTFA */
#define FTFA_FSTAT                               FTFA_FSTAT_REG(FTFA_BASE_PTR)
#define FTFA_FCNFG                               FTFA_FCNFG_REG(FTFA_BASE_PTR)
#define FTFA_FSEC                                FTFA_FSEC_REG(FTFA_BASE_PTR)
#define FTFA_FOPT                                FTFA_FOPT_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB3                              FTFA_FCCOB3_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB2                              FTFA_FCCOB2_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB1                              FTFA_FCCOB1_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB0                              FTFA_FCCOB0_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB7                              FTFA_FCCOB7_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB6                              FTFA_FCCOB6_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB5                              FTFA_FCCOB5_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB4                              FTFA_FCCOB4_REG(FTFA_BASE_PTR)
#define FTFA_FCCOBB                              FTFA_FCCOBB_REG(FTFA_BASE_PTR)
#define FTFA_FCCOBA                              FTFA_FCCOBA_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB9                              FTFA_FCCOB9_REG(FTFA_BASE_PTR)
#define FTFA_FCCOB8                              FTFA_FCCOB8_REG(FTFA_BASE_PTR)
#define FTFA_FPROT3                              FTFA_FPROT3_REG(FTFA_BASE_PTR)
#define FTFA_FPROT2                              FTFA_FPROT2_REG(FTFA_BASE_PTR)
#define FTFA_FPROT1                              FTFA_FPROT1_REG(FTFA_BASE_PTR)
#define FTFA_FPROT0                              FTFA_FPROT0_REG(FTFA_BASE_PTR)
#define FTFA_XACCH3                              FTFA_XACCH3_REG(FTFA_BASE_PTR)
#define FTFA_XACCH2                              FTFA_XACCH2_REG(FTFA_BASE_PTR)
#define FTFA_XACCH1                              FTFA_XACCH1_REG(FTFA_BASE_PTR)
#define FTFA_XACCH0                              FTFA_XACCH0_REG(FTFA_BASE_PTR)
#define FTFA_XACCL3                              FTFA_XACCL3_REG(FTFA_BASE_PTR)
#define FTFA_XACCL2                              FTFA_XACCL2_REG(FTFA_BASE_PTR)
#define FTFA_XACCL1                              FTFA_XACCL1_REG(FTFA_BASE_PTR)
#define FTFA_XACCL0                              FTFA_XACCL0_REG(FTFA_BASE_PTR)
#define FTFA_SACCH3                              FTFA_SACCH3_REG(FTFA_BASE_PTR)
#define FTFA_SACCH2                              FTFA_SACCH2_REG(FTFA_BASE_PTR)
#define FTFA_SACCH1                              FTFA_SACCH1_REG(FTFA_BASE_PTR)
#define FTFA_SACCH0                              FTFA_SACCH0_REG(FTFA_BASE_PTR)
#define FTFA_SACCL3                              FTFA_SACCL3_REG(FTFA_BASE_PTR)
#define FTFA_SACCL2                              FTFA_SACCL2_REG(FTFA_BASE_PTR)
#define FTFA_SACCL1                              FTFA_SACCL1_REG(FTFA_BASE_PTR)
#define FTFA_SACCL0                              FTFA_SACCL0_REG(FTFA_BASE_PTR)
#define FTFA_FACSS                               FTFA_FACSS_REG(FTFA_BASE_PTR)
#define FTFA_FACSN                               FTFA_FACSN_REG(FTFA_BASE_PTR)

/*!
 * @}
 */ /* end of group FTFA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTFA_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral FTM
 * @{
 */

/** FTM - Peripheral register structure */
typedef struct FTM_MemMap {
  uint32_t SC;                                     /**< Status And Control, offset: 0x0 */
  uint32_t CNT;                                    /**< Counter, offset: 0x4 */
  uint32_t MOD;                                    /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    uint32_t CnSC;                                   /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    uint32_t CnV;                                    /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[8];
  uint32_t CNTIN;                                  /**< Counter Initial Value, offset: 0x4C */
  uint32_t STATUS;                                 /**< Capture And Compare Status, offset: 0x50 */
  uint32_t MODE;                                   /**< Features Mode Selection, offset: 0x54 */
  uint32_t SYNC;                                   /**< Synchronization, offset: 0x58 */
  uint32_t OUTINIT;                                /**< Initial State For Channels Output, offset: 0x5C */
  uint32_t OUTMASK;                                /**< Output Mask, offset: 0x60 */
  uint32_t COMBINE;                                /**< Function For Linked Channels, offset: 0x64 */
  uint32_t DEADTIME;                               /**< Deadtime Insertion Control, offset: 0x68 */
  uint32_t EXTTRIG;                                /**< FTM External Trigger, offset: 0x6C */
  uint32_t POL;                                    /**< Channels Polarity, offset: 0x70 */
  uint32_t FMS;                                    /**< Fault Mode Status, offset: 0x74 */
  uint32_t FILTER;                                 /**< Input Capture Filter Control, offset: 0x78 */
  uint32_t FLTCTRL;                                /**< Fault Control, offset: 0x7C */
  uint32_t QDCTRL;                                 /**< Quadrature Decoder Control And Status, offset: 0x80 */
  uint32_t CONF;                                   /**< Configuration, offset: 0x84 */
  uint32_t FLTPOL;                                 /**< FTM Fault Input Polarity, offset: 0x88 */
  uint32_t SYNCONF;                                /**< Synchronization Configuration, offset: 0x8C */
  uint32_t INVCTRL;                                /**< FTM Inverting Control, offset: 0x90 */
  uint32_t SWOCTRL;                                /**< FTM Software Output Control, offset: 0x94 */
  uint32_t PWMLOAD;                                /**< FTM PWM Load, offset: 0x98 */
} volatile *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define FTM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define FTM_CNTIN_REG(base)                      ((base)->CNTIN)
#define FTM_STATUS_REG(base)                     ((base)->STATUS)
#define FTM_MODE_REG(base)                       ((base)->MODE)
#define FTM_SYNC_REG(base)                       ((base)->SYNC)
#define FTM_OUTINIT_REG(base)                    ((base)->OUTINIT)
#define FTM_OUTMASK_REG(base)                    ((base)->OUTMASK)
#define FTM_COMBINE_REG(base)                    ((base)->COMBINE)
#define FTM_DEADTIME_REG(base)                   ((base)->DEADTIME)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)
#define FTM_POL_REG(base)                        ((base)->POL)
#define FTM_FMS_REG(base)                        ((base)->FMS)
#define FTM_FILTER_REG(base)                     ((base)->FILTER)
#define FTM_FLTCTRL_REG(base)                    ((base)->FLTCTRL)
#define FTM_QDCTRL_REG(base)                     ((base)->QDCTRL)
#define FTM_CONF_REG(base)                       ((base)->CONF)
#define FTM_FLTPOL_REG(base)                     ((base)->FLTPOL)
#define FTM_SYNCONF_REG(base)                    ((base)->SYNCONF)
#define FTM_INVCTRL_REG(base)                    ((base)->INVCTRL)
#define FTM_SWOCTRL_REG(base)                    ((base)->SWOCTRL)
#define FTM_PWMLOAD_REG(base)                    ((base)->PWMLOAD)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0
#define FTM_CnSC_ICRST_MASK                      0x2u
#define FTM_CnSC_ICRST_SHIFT                     1
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK)
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7
/* CONF Bit Fields */
#define FTM_CONF_NUMTOF_MASK                     0x1Fu
#define FTM_CONF_NUMTOF_SHIFT                    0
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3
/* SWOCTRL Bit Fields */
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9

/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base pointer */
#define FTM0_BASE_PTR                            ((FTM_MemMapPtr)0x40038000u)
/** Peripheral FTM1 base pointer */
#define FTM1_BASE_PTR                            ((FTM_MemMapPtr)0x40039000u)
/** Peripheral FTM3 base pointer */
#define FTM3_BASE_PTR                            ((FTM_MemMapPtr)0x40026000u)
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0_BASE_PTR, FTM1_BASE_PTR, FTM3_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0_BASE_PTR)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0_BASE_PTR)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0_BASE_PTR)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0_BASE_PTR,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0_BASE_PTR,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0_BASE_PTR,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0_BASE_PTR,1)
#define FTM0_C2SC                                FTM_CnSC_REG(FTM0_BASE_PTR,2)
#define FTM0_C2V                                 FTM_CnV_REG(FTM0_BASE_PTR,2)
#define FTM0_C3SC                                FTM_CnSC_REG(FTM0_BASE_PTR,3)
#define FTM0_C3V                                 FTM_CnV_REG(FTM0_BASE_PTR,3)
#define FTM0_C4SC                                FTM_CnSC_REG(FTM0_BASE_PTR,4)
#define FTM0_C4V                                 FTM_CnV_REG(FTM0_BASE_PTR,4)
#define FTM0_C5SC                                FTM_CnSC_REG(FTM0_BASE_PTR,5)
#define FTM0_C5V                                 FTM_CnV_REG(FTM0_BASE_PTR,5)
#define FTM0_C6SC                                FTM_CnSC_REG(FTM0_BASE_PTR,6)
#define FTM0_C6V                                 FTM_CnV_REG(FTM0_BASE_PTR,6)
#define FTM0_C7SC                                FTM_CnSC_REG(FTM0_BASE_PTR,7)
#define FTM0_C7V                                 FTM_CnV_REG(FTM0_BASE_PTR,7)
#define FTM0_CNTIN                               FTM_CNTIN_REG(FTM0_BASE_PTR)
#define FTM0_STATUS                              FTM_STATUS_REG(FTM0_BASE_PTR)
#define FTM0_MODE                                FTM_MODE_REG(FTM0_BASE_PTR)
#define FTM0_SYNC                                FTM_SYNC_REG(FTM0_BASE_PTR)
#define FTM0_OUTINIT                             FTM_OUTINIT_REG(FTM0_BASE_PTR)
#define FTM0_OUTMASK                             FTM_OUTMASK_REG(FTM0_BASE_PTR)
#define FTM0_COMBINE                             FTM_COMBINE_REG(FTM0_BASE_PTR)
#define FTM0_DEADTIME                            FTM_DEADTIME_REG(FTM0_BASE_PTR)
#define FTM0_EXTTRIG                             FTM_EXTTRIG_REG(FTM0_BASE_PTR)
#define FTM0_POL                                 FTM_POL_REG(FTM0_BASE_PTR)
#define FTM0_FMS                                 FTM_FMS_REG(FTM0_BASE_PTR)
#define FTM0_FILTER                              FTM_FILTER_REG(FTM0_BASE_PTR)
#define FTM0_FLTCTRL                             FTM_FLTCTRL_REG(FTM0_BASE_PTR)
#define FTM0_QDCTRL                              FTM_QDCTRL_REG(FTM0_BASE_PTR)
#define FTM0_CONF                                FTM_CONF_REG(FTM0_BASE_PTR)
#define FTM0_FLTPOL                              FTM_FLTPOL_REG(FTM0_BASE_PTR)
#define FTM0_SYNCONF                             FTM_SYNCONF_REG(FTM0_BASE_PTR)
#define FTM0_INVCTRL                             FTM_INVCTRL_REG(FTM0_BASE_PTR)
#define FTM0_SWOCTRL                             FTM_SWOCTRL_REG(FTM0_BASE_PTR)
#define FTM0_PWMLOAD                             FTM_PWMLOAD_REG(FTM0_BASE_PTR)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1_BASE_PTR)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1_BASE_PTR)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1_BASE_PTR)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1_BASE_PTR,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1_BASE_PTR,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1_BASE_PTR,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1_BASE_PTR,1)
#define FTM1_CNTIN                               FTM_CNTIN_REG(FTM1_BASE_PTR)
#define FTM1_STATUS                              FTM_STATUS_REG(FTM1_BASE_PTR)
#define FTM1_MODE                                FTM_MODE_REG(FTM1_BASE_PTR)
#define FTM1_SYNC                                FTM_SYNC_REG(FTM1_BASE_PTR)
#define FTM1_OUTINIT                             FTM_OUTINIT_REG(FTM1_BASE_PTR)
#define FTM1_OUTMASK                             FTM_OUTMASK_REG(FTM1_BASE_PTR)
#define FTM1_COMBINE                             FTM_COMBINE_REG(FTM1_BASE_PTR)
#define FTM1_DEADTIME                            FTM_DEADTIME_REG(FTM1_BASE_PTR)
#define FTM1_EXTTRIG                             FTM_EXTTRIG_REG(FTM1_BASE_PTR)
#define FTM1_POL                                 FTM_POL_REG(FTM1_BASE_PTR)
#define FTM1_FMS                                 FTM_FMS_REG(FTM1_BASE_PTR)
#define FTM1_FILTER                              FTM_FILTER_REG(FTM1_BASE_PTR)
#define FTM1_FLTCTRL                             FTM_FLTCTRL_REG(FTM1_BASE_PTR)
#define FTM1_QDCTRL                              FTM_QDCTRL_REG(FTM1_BASE_PTR)
#define FTM1_CONF                                FTM_CONF_REG(FTM1_BASE_PTR)
#define FTM1_FLTPOL                              FTM_FLTPOL_REG(FTM1_BASE_PTR)
#define FTM1_SYNCONF                             FTM_SYNCONF_REG(FTM1_BASE_PTR)
#define FTM1_INVCTRL                             FTM_INVCTRL_REG(FTM1_BASE_PTR)
#define FTM1_SWOCTRL                             FTM_SWOCTRL_REG(FTM1_BASE_PTR)
#define FTM1_PWMLOAD                             FTM_PWMLOAD_REG(FTM1_BASE_PTR)
/* FTM3 */
#define FTM3_SC                                  FTM_SC_REG(FTM3_BASE_PTR)
#define FTM3_CNT                                 FTM_CNT_REG(FTM3_BASE_PTR)
#define FTM3_MOD                                 FTM_MOD_REG(FTM3_BASE_PTR)
#define FTM3_C0SC                                FTM_CnSC_REG(FTM3_BASE_PTR,0)
#define FTM3_C0V                                 FTM_CnV_REG(FTM3_BASE_PTR,0)
#define FTM3_C1SC                                FTM_CnSC_REG(FTM3_BASE_PTR,1)
#define FTM3_C1V                                 FTM_CnV_REG(FTM3_BASE_PTR,1)
#define FTM3_C2SC                                FTM_CnSC_REG(FTM3_BASE_PTR,2)
#define FTM3_C2V                                 FTM_CnV_REG(FTM3_BASE_PTR,2)
#define FTM3_C3SC                                FTM_CnSC_REG(FTM3_BASE_PTR,3)
#define FTM3_C3V                                 FTM_CnV_REG(FTM3_BASE_PTR,3)
#define FTM3_C4SC                                FTM_CnSC_REG(FTM3_BASE_PTR,4)
#define FTM3_C4V                                 FTM_CnV_REG(FTM3_BASE_PTR,4)
#define FTM3_C5SC                                FTM_CnSC_REG(FTM3_BASE_PTR,5)
#define FTM3_C5V                                 FTM_CnV_REG(FTM3_BASE_PTR,5)
#define FTM3_C6SC                                FTM_CnSC_REG(FTM3_BASE_PTR,6)
#define FTM3_C6V                                 FTM_CnV_REG(FTM3_BASE_PTR,6)
#define FTM3_C7SC                                FTM_CnSC_REG(FTM3_BASE_PTR,7)
#define FTM3_C7V                                 FTM_CnV_REG(FTM3_BASE_PTR,7)
#define FTM3_CNTIN                               FTM_CNTIN_REG(FTM3_BASE_PTR)
#define FTM3_STATUS                              FTM_STATUS_REG(FTM3_BASE_PTR)
#define FTM3_MODE                                FTM_MODE_REG(FTM3_BASE_PTR)
#define FTM3_SYNC                                FTM_SYNC_REG(FTM3_BASE_PTR)
#define FTM3_OUTINIT                             FTM_OUTINIT_REG(FTM3_BASE_PTR)
#define FTM3_OUTMASK                             FTM_OUTMASK_REG(FTM3_BASE_PTR)
#define FTM3_COMBINE                             FTM_COMBINE_REG(FTM3_BASE_PTR)
#define FTM3_DEADTIME                            FTM_DEADTIME_REG(FTM3_BASE_PTR)
#define FTM3_EXTTRIG                             FTM_EXTTRIG_REG(FTM3_BASE_PTR)
#define FTM3_POL                                 FTM_POL_REG(FTM3_BASE_PTR)
#define FTM3_FMS                                 FTM_FMS_REG(FTM3_BASE_PTR)
#define FTM3_FILTER                              FTM_FILTER_REG(FTM3_BASE_PTR)
#define FTM3_FLTCTRL                             FTM_FLTCTRL_REG(FTM3_BASE_PTR)
#define FTM3_QDCTRL                              FTM_QDCTRL_REG(FTM3_BASE_PTR)
#define FTM3_CONF                                FTM_CONF_REG(FTM3_BASE_PTR)
#define FTM3_FLTPOL                              FTM_FLTPOL_REG(FTM3_BASE_PTR)
#define FTM3_SYNCONF                             FTM_SYNCONF_REG(FTM3_BASE_PTR)
#define FTM3_INVCTRL                             FTM_INVCTRL_REG(FTM3_BASE_PTR)
#define FTM3_SWOCTRL                             FTM_SWOCTRL_REG(FTM3_BASE_PTR)
#define FTM3_PWMLOAD                             FTM_PWMLOAD_REG(FTM3_BASE_PTR)

/* FTM - Register array accessors */
#define FTM0_CnSC(index)                         FTM_CnSC_REG(FTM0_BASE_PTR,index)
#define FTM1_CnSC(index)                         FTM_CnSC_REG(FTM1_BASE_PTR,index)
#define FTM3_CnSC(index)                         FTM_CnSC_REG(FTM3_BASE_PTR,index)
#define FTM0_CnV(index)                          FTM_CnV_REG(FTM0_BASE_PTR,index)
#define FTM1_CnV(index)                          FTM_CnV_REG(FTM1_BASE_PTR,index)
#define FTM3_CnV(index)                          FTM_CnV_REG(FTM3_BASE_PTR,index)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTM_Peripheral */


/* ----------------------------------------------------------------------------
   -- GPIO
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral GPIO
 * @{
 */

/** GPIO - Peripheral register structure */
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                   /**< Port Data Output Register, offset: 0x0 */
  uint32_t PSOR;                                   /**< Port Set Output Register, offset: 0x4 */
  uint32_t PCOR;                                   /**< Port Clear Output Register, offset: 0x8 */
  uint32_t PTOR;                                   /**< Port Toggle Output Register, offset: 0xC */
  uint32_t PDIR;                                   /**< Port Data Input Register, offset: 0x10 */
  uint32_t PDDR;                                   /**< Port Data Direction Register, offset: 0x14 */
} volatile *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register accessors */
#define GPIO_PDOR_REG(base)                      ((base)->PDOR)
#define GPIO_PSOR_REG(base)                      ((base)->PSOR)
#define GPIO_PCOR_REG(base)                      ((base)->PCOR)
#define GPIO_PTOR_REG(base)                      ((base)->PTOR)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_PDDR_REG(base)                      ((base)->PDDR)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base pointer */
#define GPIOA_BASE_PTR                           ((GPIO_MemMapPtr)0x400FF000u)
/** Peripheral GPIOB base pointer */
#define GPIOB_BASE_PTR                           ((GPIO_MemMapPtr)0x400FF040u)
/** Peripheral GPIOC base pointer */
#define GPIOC_BASE_PTR                           ((GPIO_MemMapPtr)0x400FF080u)
/** Peripheral GPIOD base pointer */
#define GPIOD_BASE_PTR                           ((GPIO_MemMapPtr)0x400FF0C0u)
/** Peripheral GPIOE base pointer */
#define GPIOE_BASE_PTR                           ((GPIO_MemMapPtr)0x400FF100u)
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA_BASE_PTR, GPIOB_BASE_PTR, GPIOC_BASE_PTR, GPIOD_BASE_PTR, GPIOE_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* GPIOA */
#define GPIOA_PDOR                               GPIO_PDOR_REG(GPIOA_BASE_PTR)
#define GPIOA_PSOR                               GPIO_PSOR_REG(GPIOA_BASE_PTR)
#define GPIOA_PCOR                               GPIO_PCOR_REG(GPIOA_BASE_PTR)
#define GPIOA_PTOR                               GPIO_PTOR_REG(GPIOA_BASE_PTR)
#define GPIOA_PDIR                               GPIO_PDIR_REG(GPIOA_BASE_PTR)
#define GPIOA_PDDR                               GPIO_PDDR_REG(GPIOA_BASE_PTR)
/* GPIOB */
#define GPIOB_PDOR                               GPIO_PDOR_REG(GPIOB_BASE_PTR)
#define GPIOB_PSOR                               GPIO_PSOR_REG(GPIOB_BASE_PTR)
#define GPIOB_PCOR                               GPIO_PCOR_REG(GPIOB_BASE_PTR)
#define GPIOB_PTOR                               GPIO_PTOR_REG(GPIOB_BASE_PTR)
#define GPIOB_PDIR                               GPIO_PDIR_REG(GPIOB_BASE_PTR)
#define GPIOB_PDDR                               GPIO_PDDR_REG(GPIOB_BASE_PTR)
/* GPIOC */
#define GPIOC_PDOR                               GPIO_PDOR_REG(GPIOC_BASE_PTR)
#define GPIOC_PSOR                               GPIO_PSOR_REG(GPIOC_BASE_PTR)
#define GPIOC_PCOR                               GPIO_PCOR_REG(GPIOC_BASE_PTR)
#define GPIOC_PTOR                               GPIO_PTOR_REG(GPIOC_BASE_PTR)
#define GPIOC_PDIR                               GPIO_PDIR_REG(GPIOC_BASE_PTR)
#define GPIOC_PDDR                               GPIO_PDDR_REG(GPIOC_BASE_PTR)
/* GPIOD */
#define GPIOD_PDOR                               GPIO_PDOR_REG(GPIOD_BASE_PTR)
#define GPIOD_PSOR                               GPIO_PSOR_REG(GPIOD_BASE_PTR)
#define GPIOD_PCOR                               GPIO_PCOR_REG(GPIOD_BASE_PTR)
#define GPIOD_PTOR                               GPIO_PTOR_REG(GPIOD_BASE_PTR)
#define GPIOD_PDIR                               GPIO_PDIR_REG(GPIOD_BASE_PTR)
#define GPIOD_PDDR                               GPIO_PDDR_REG(GPIOD_BASE_PTR)
/* GPIOE */
#define GPIOE_PDOR                               GPIO_PDOR_REG(GPIOE_BASE_PTR)
#define GPIOE_PSOR                               GPIO_PSOR_REG(GPIOE_BASE_PTR)
#define GPIOE_PCOR                               GPIO_PCOR_REG(GPIOE_BASE_PTR)
#define GPIOE_PTOR                               GPIO_PTOR_REG(GPIOE_BASE_PTR)
#define GPIOE_PDIR                               GPIO_PDIR_REG(GPIOE_BASE_PTR)
#define GPIOE_PDDR                               GPIO_PDDR_REG(GPIOE_BASE_PTR)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group GPIO_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral I2C
 * @{
 */

/** I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8_t A1;                                      /**< I2C Address Register 1, offset: 0x0 */
  uint8_t F;                                       /**< I2C Frequency Divider register, offset: 0x1 */
  uint8_t C1;                                      /**< I2C Control Register 1, offset: 0x2 */
  uint8_t S;                                       /**< I2C Status register, offset: 0x3 */
  uint8_t D;                                       /**< I2C Data I/O register, offset: 0x4 */
  uint8_t C2;                                      /**< I2C Control Register 2, offset: 0x5 */
  uint8_t FLT;                                     /**< I2C Programmable Input Glitch Filter Register, offset: 0x6 */
  uint8_t RA;                                      /**< I2C Range Address register, offset: 0x7 */
  uint8_t SMB;                                     /**< I2C SMBus Control and Status register, offset: 0x8 */
  uint8_t A2;                                      /**< I2C Address Register 2, offset: 0x9 */
  uint8_t SLTH;                                    /**< I2C SCL Low Timeout Register High, offset: 0xA */
  uint8_t SLTL;                                    /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_DMAEN_MASK                        0x1u
#define I2C_C1_DMAEN_SHIFT                       0
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_HDRS_MASK                         0x20u
#define I2C_C2_HDRS_SHIFT                        5
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0x1Fu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK)
#define I2C_FLT_STOPIE_MASK                      0x20u
#define I2C_FLT_STOPIE_SHIFT                     5
#define I2C_FLT_STOPF_MASK                       0x40u
#define I2C_FLT_STOPF_SHIFT                      6
#define I2C_FLT_SHEN_MASK                        0x80u
#define I2C_FLT_SHEN_SHIFT                       7
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK)

/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C base pointer */
#define I2C_BASE_PTR                             ((I2C_MemMapPtr)0x40066000u)
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C */
#define I2C_A1                                   I2C_A1_REG(I2C_BASE_PTR)
#define I2C_F                                    I2C_F_REG(I2C_BASE_PTR)
#define I2C_C1                                   I2C_C1_REG(I2C_BASE_PTR)
#define I2C_S                                    I2C_S_REG(I2C_BASE_PTR)
#define I2C_D                                    I2C_D_REG(I2C_BASE_PTR)
#define I2C_C2                                   I2C_C2_REG(I2C_BASE_PTR)
#define I2C_FLT                                  I2C_FLT_REG(I2C_BASE_PTR)
#define I2C_RA                                   I2C_RA_REG(I2C_BASE_PTR)
#define I2C_SMB                                  I2C_SMB_REG(I2C_BASE_PTR)
#define I2C_A2                                   I2C_A2_REG(I2C_BASE_PTR)
#define I2C_SLTH                                 I2C_SLTH_REG(I2C_BASE_PTR)
#define I2C_SLTL                                 I2C_SLTL_REG(I2C_BASE_PTR)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- ITM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITM_Peripheral ITM
 * @{
 */

/** ITM - Peripheral register structure */
typedef struct ITM_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t STIM_READ[32];                          /**< Stimulus Port Register 0 (for reading)..Stimulus Port Register 31 (for reading), array offset: 0x0, array step: 0x4 */
    uint32_t STIM_WRITE[32];                         /**< Stimulus Port Register 0 (for writing)..Stimulus Port Register 31 (for writing), array offset: 0x0, array step: 0x4 */
  };
  uint8_t RESERVED_0[3456];
  uint32_t TER;                                    /**< Trace Enable Register, offset: 0xE00 */
  uint8_t RESERVED_1[60];
  uint32_t TPR;                                    /**< Trace Privilege Register, offset: 0xE40 */
  uint8_t RESERVED_2[60];
  uint32_t TCR;                                    /**< Trace Control Register, offset: 0xE80 */
  uint8_t RESERVED_3[300];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint8_t RESERVED_4[24];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *ITM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register accessors */
#define ITM_STIM_READ_REG(base,index2)           ((base)->STIM_READ[index2])
#define ITM_STIM_WRITE_REG(base,index2)          ((base)->STIM_WRITE[index2])
#define ITM_TER_REG(base)                        ((base)->TER)
#define ITM_TPR_REG(base)                        ((base)->TPR)
#define ITM_TCR_REG(base)                        ((base)->TCR)
#define ITM_LAR_REG(base)                        ((base)->LAR)
#define ITM_LSR_REG(base)                        ((base)->LSR)
#define ITM_PID4_REG(base)                       ((base)->PID4)
#define ITM_PID5_REG(base)                       ((base)->PID5)
#define ITM_PID6_REG(base)                       ((base)->PID6)
#define ITM_PID7_REG(base)                       ((base)->PID7)
#define ITM_PID0_REG(base)                       ((base)->PID0)
#define ITM_PID1_REG(base)                       ((base)->PID1)
#define ITM_PID2_REG(base)                       ((base)->PID2)
#define ITM_PID3_REG(base)                       ((base)->PID3)
#define ITM_CID0_REG(base)                       ((base)->CID0)
#define ITM_CID1_REG(base)                       ((base)->CID1)
#define ITM_CID2_REG(base)                       ((base)->CID2)
#define ITM_CID3_REG(base)                       ((base)->CID3)

/*!
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ITM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITM_Register_Masks ITM Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group ITM_Register_Masks */


/* ITM - Peripheral instance base addresses */
/** Peripheral ITM base pointer */
#define ITM_BASE_PTR                             ((ITM_MemMapPtr)0xE0000000u)
/** Array initializer of ITM peripheral base pointers */
#define ITM_BASE_PTRS                            { ITM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register instance definitions */
/* ITM */
#define ITM_STIM0_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,0)
#define ITM_STIM0_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,0)
#define ITM_STIM1_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,1)
#define ITM_STIM1_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,1)
#define ITM_STIM2_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,2)
#define ITM_STIM2_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,2)
#define ITM_STIM3_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,3)
#define ITM_STIM3_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,3)
#define ITM_STIM4_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,4)
#define ITM_STIM4_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,4)
#define ITM_STIM5_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,5)
#define ITM_STIM5_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,5)
#define ITM_STIM6_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,6)
#define ITM_STIM6_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,6)
#define ITM_STIM7_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,7)
#define ITM_STIM7_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,7)
#define ITM_STIM8_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,8)
#define ITM_STIM8_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,8)
#define ITM_STIM9_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,9)
#define ITM_STIM9_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,9)
#define ITM_STIM10_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,10)
#define ITM_STIM10_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,10)
#define ITM_STIM11_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,11)
#define ITM_STIM11_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,11)
#define ITM_STIM12_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,12)
#define ITM_STIM12_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,12)
#define ITM_STIM13_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,13)
#define ITM_STIM13_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,13)
#define ITM_STIM14_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,14)
#define ITM_STIM14_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,14)
#define ITM_STIM15_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,15)
#define ITM_STIM15_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,15)
#define ITM_STIM16_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,16)
#define ITM_STIM16_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,16)
#define ITM_STIM17_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,17)
#define ITM_STIM17_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,17)
#define ITM_STIM18_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,18)
#define ITM_STIM18_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,18)
#define ITM_STIM19_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,19)
#define ITM_STIM19_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,19)
#define ITM_STIM20_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,20)
#define ITM_STIM20_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,20)
#define ITM_STIM21_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,21)
#define ITM_STIM21_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,21)
#define ITM_STIM22_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,22)
#define ITM_STIM22_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,22)
#define ITM_STIM23_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,23)
#define ITM_STIM23_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,23)
#define ITM_STIM24_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,24)
#define ITM_STIM24_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,24)
#define ITM_STIM25_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,25)
#define ITM_STIM25_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,25)
#define ITM_STIM26_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,26)
#define ITM_STIM26_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,26)
#define ITM_STIM27_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,27)
#define ITM_STIM27_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,27)
#define ITM_STIM28_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,28)
#define ITM_STIM28_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,28)
#define ITM_STIM29_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,29)
#define ITM_STIM29_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,29)
#define ITM_STIM30_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,30)
#define ITM_STIM30_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,30)
#define ITM_STIM31_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,31)
#define ITM_STIM31_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,31)
#define ITM_TER                                  ITM_TER_REG(ITM_BASE_PTR)
#define ITM_TPR                                  ITM_TPR_REG(ITM_BASE_PTR)
#define ITM_TCR                                  ITM_TCR_REG(ITM_BASE_PTR)
#define ITM_LAR                                  ITM_LAR_REG(ITM_BASE_PTR)
#define ITM_LSR                                  ITM_LSR_REG(ITM_BASE_PTR)
#define ITM_PID4                                 ITM_PID4_REG(ITM_BASE_PTR)
#define ITM_PID5                                 ITM_PID5_REG(ITM_BASE_PTR)
#define ITM_PID6                                 ITM_PID6_REG(ITM_BASE_PTR)
#define ITM_PID7                                 ITM_PID7_REG(ITM_BASE_PTR)
#define ITM_PID0                                 ITM_PID0_REG(ITM_BASE_PTR)
#define ITM_PID1                                 ITM_PID1_REG(ITM_BASE_PTR)
#define ITM_PID2                                 ITM_PID2_REG(ITM_BASE_PTR)
#define ITM_PID3                                 ITM_PID3_REG(ITM_BASE_PTR)
#define ITM_CID0                                 ITM_CID0_REG(ITM_BASE_PTR)
#define ITM_CID1                                 ITM_CID1_REG(ITM_BASE_PTR)
#define ITM_CID2                                 ITM_CID2_REG(ITM_BASE_PTR)
#define ITM_CID3                                 ITM_CID3_REG(ITM_BASE_PTR)

/* ITM - Register array accessors */
#define ITM_STIM_READ(index2)                    ITM_STIM_READ_REG(ITM_BASE_PTR,index2)
#define ITM_STIM_WRITE(index2)                   ITM_STIM_WRITE_REG(ITM_BASE_PTR,index2)

/*!
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ITM_Peripheral */


/* ----------------------------------------------------------------------------
   -- LLWU
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Peripheral LLWU
 * @{
 */

/** LLWU - Peripheral register structure */
typedef struct LLWU_MemMap {
  uint8_t PE1;                                     /**< LLWU Pin Enable 1 register, offset: 0x0 */
  uint8_t PE2;                                     /**< LLWU Pin Enable 2 register, offset: 0x1 */
  uint8_t PE3;                                     /**< LLWU Pin Enable 3 register, offset: 0x2 */
  uint8_t PE4;                                     /**< LLWU Pin Enable 4 register, offset: 0x3 */
  uint8_t PE5;                                     /**< LLWU Pin Enable 5 register, offset: 0x4 */
  uint8_t PE6;                                     /**< LLWU Pin Enable 6 register, offset: 0x5 */
  uint8_t PE7;                                     /**< LLWU Pin Enable 7 register, offset: 0x6 */
  uint8_t PE8;                                     /**< LLWU Pin Enable 8 register, offset: 0x7 */
  uint8_t ME;                                      /**< LLWU Module Enable register, offset: 0x8 */
  uint8_t PF1;                                     /**< LLWU Pin Flag 1 register, offset: 0x9 */
  uint8_t PF2;                                     /**< LLWU Pin Flag 2 register, offset: 0xA */
  uint8_t PF3;                                     /**< LLWU Pin Flag 3 register, offset: 0xB */
  uint8_t PF4;                                     /**< LLWU Pin Flag 4 register, offset: 0xC */
  uint8_t MF5;                                     /**< LLWU Module Flag 5 register, offset: 0xD */
  uint8_t FILT1;                                   /**< LLWU Pin Filter 1 register, offset: 0xE */
  uint8_t FILT2;                                   /**< LLWU Pin Filter 2 register, offset: 0xF */
} volatile *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register accessors */
#define LLWU_PE1_REG(base)                       ((base)->PE1)
#define LLWU_PE2_REG(base)                       ((base)->PE2)
#define LLWU_PE3_REG(base)                       ((base)->PE3)
#define LLWU_PE4_REG(base)                       ((base)->PE4)
#define LLWU_PE5_REG(base)                       ((base)->PE5)
#define LLWU_PE6_REG(base)                       ((base)->PE6)
#define LLWU_PE7_REG(base)                       ((base)->PE7)
#define LLWU_PE8_REG(base)                       ((base)->PE8)
#define LLWU_ME_REG(base)                        ((base)->ME)
#define LLWU_PF1_REG(base)                       ((base)->PF1)
#define LLWU_PF2_REG(base)                       ((base)->PF2)
#define LLWU_PF3_REG(base)                       ((base)->PF3)
#define LLWU_PF4_REG(base)                       ((base)->PF4)
#define LLWU_MF5_REG(base)                       ((base)->MF5)
#define LLWU_FILT1_REG(base)                     ((base)->FILT1)
#define LLWU_FILT2_REG(base)                     ((base)->FILT2)

/*!
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE4_MASK                      0x3u
#define LLWU_PE2_WUPE4_SHIFT                     0
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      0xCu
#define LLWU_PE2_WUPE5_SHIFT                     2
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      0xC0u
#define LLWU_PE2_WUPE7_SHIFT                     6
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK)
/* PE3 Bit Fields */
#define LLWU_PE3_WUPE8_MASK                      0x3u
#define LLWU_PE3_WUPE8_SHIFT                     0
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      0xCu
#define LLWU_PE3_WUPE9_SHIFT                     2
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     0x30u
#define LLWU_PE3_WUPE10_SHIFT                    4
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     0xC0u
#define LLWU_PE3_WUPE11_SHIFT                    6
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK)
/* PE4 Bit Fields */
#define LLWU_PE4_WUPE12_MASK                     0x3u
#define LLWU_PE4_WUPE12_SHIFT                    0
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     0xCu
#define LLWU_PE4_WUPE13_SHIFT                    2
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT                    4
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     0xC0u
#define LLWU_PE4_WUPE15_SHIFT                    6
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK)
/* PE5 Bit Fields */
#define LLWU_PE5_WUPE16_MASK                     0x3u
#define LLWU_PE5_WUPE16_SHIFT                    0
#define LLWU_PE5_WUPE16(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE5_WUPE16_SHIFT))&LLWU_PE5_WUPE16_MASK)
#define LLWU_PE5_WUPE17_MASK                     0xCu
#define LLWU_PE5_WUPE17_SHIFT                    2
#define LLWU_PE5_WUPE17(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE5_WUPE17_SHIFT))&LLWU_PE5_WUPE17_MASK)
#define LLWU_PE5_WUPE18_MASK                     0x30u
#define LLWU_PE5_WUPE18_SHIFT                    4
#define LLWU_PE5_WUPE18(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE5_WUPE18_SHIFT))&LLWU_PE5_WUPE18_MASK)
#define LLWU_PE5_WUPE19_MASK                     0xC0u
#define LLWU_PE5_WUPE19_SHIFT                    6
#define LLWU_PE5_WUPE19(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE5_WUPE19_SHIFT))&LLWU_PE5_WUPE19_MASK)
/* PE6 Bit Fields */
#define LLWU_PE6_WUPE20_MASK                     0x3u
#define LLWU_PE6_WUPE20_SHIFT                    0
#define LLWU_PE6_WUPE20(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE6_WUPE20_SHIFT))&LLWU_PE6_WUPE20_MASK)
#define LLWU_PE6_WUPE21_MASK                     0xCu
#define LLWU_PE6_WUPE21_SHIFT                    2
#define LLWU_PE6_WUPE21(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE6_WUPE21_SHIFT))&LLWU_PE6_WUPE21_MASK)
#define LLWU_PE6_WUPE22_MASK                     0x30u
#define LLWU_PE6_WUPE22_SHIFT                    4
#define LLWU_PE6_WUPE22(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE6_WUPE22_SHIFT))&LLWU_PE6_WUPE22_MASK)
#define LLWU_PE6_WUPE23_MASK                     0xC0u
#define LLWU_PE6_WUPE23_SHIFT                    6
#define LLWU_PE6_WUPE23(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE6_WUPE23_SHIFT))&LLWU_PE6_WUPE23_MASK)
/* PE7 Bit Fields */
#define LLWU_PE7_WUPE24_MASK                     0x3u
#define LLWU_PE7_WUPE24_SHIFT                    0
#define LLWU_PE7_WUPE24(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE7_WUPE24_SHIFT))&LLWU_PE7_WUPE24_MASK)
#define LLWU_PE7_WUPE25_MASK                     0xCu
#define LLWU_PE7_WUPE25_SHIFT                    2
#define LLWU_PE7_WUPE25(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE7_WUPE25_SHIFT))&LLWU_PE7_WUPE25_MASK)
#define LLWU_PE7_WUPE26_MASK                     0x30u
#define LLWU_PE7_WUPE26_SHIFT                    4
#define LLWU_PE7_WUPE26(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE7_WUPE26_SHIFT))&LLWU_PE7_WUPE26_MASK)
#define LLWU_PE7_WUPE27_MASK                     0xC0u
#define LLWU_PE7_WUPE27_SHIFT                    6
#define LLWU_PE7_WUPE27(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE7_WUPE27_SHIFT))&LLWU_PE7_WUPE27_MASK)
/* PE8 Bit Fields */
#define LLWU_PE8_WUPE28_MASK                     0x3u
#define LLWU_PE8_WUPE28_SHIFT                    0
#define LLWU_PE8_WUPE28(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE8_WUPE28_SHIFT))&LLWU_PE8_WUPE28_MASK)
#define LLWU_PE8_WUPE29_MASK                     0xCu
#define LLWU_PE8_WUPE29_SHIFT                    2
#define LLWU_PE8_WUPE29(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE8_WUPE29_SHIFT))&LLWU_PE8_WUPE29_MASK)
#define LLWU_PE8_WUPE30_MASK                     0x30u
#define LLWU_PE8_WUPE30_SHIFT                    4
#define LLWU_PE8_WUPE30(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE8_WUPE30_SHIFT))&LLWU_PE8_WUPE30_MASK)
#define LLWU_PE8_WUPE31_MASK                     0xC0u
#define LLWU_PE8_WUPE31_SHIFT                    6
#define LLWU_PE8_WUPE31(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE8_WUPE31_SHIFT))&LLWU_PE8_WUPE31_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
/* PF1 Bit Fields */
#define LLWU_PF1_WUF0_MASK                       0x1u
#define LLWU_PF1_WUF0_SHIFT                      0
#define LLWU_PF1_WUF1_MASK                       0x2u
#define LLWU_PF1_WUF1_SHIFT                      1
#define LLWU_PF1_WUF2_MASK                       0x4u
#define LLWU_PF1_WUF2_SHIFT                      2
#define LLWU_PF1_WUF3_MASK                       0x8u
#define LLWU_PF1_WUF3_SHIFT                      3
#define LLWU_PF1_WUF4_MASK                       0x10u
#define LLWU_PF1_WUF4_SHIFT                      4
#define LLWU_PF1_WUF5_MASK                       0x20u
#define LLWU_PF1_WUF5_SHIFT                      5
#define LLWU_PF1_WUF6_MASK                       0x40u
#define LLWU_PF1_WUF6_SHIFT                      6
#define LLWU_PF1_WUF7_MASK                       0x80u
#define LLWU_PF1_WUF7_SHIFT                      7
/* PF2 Bit Fields */
#define LLWU_PF2_WUF8_MASK                       0x1u
#define LLWU_PF2_WUF8_SHIFT                      0
#define LLWU_PF2_WUF9_MASK                       0x2u
#define LLWU_PF2_WUF9_SHIFT                      1
#define LLWU_PF2_WUF10_MASK                      0x4u
#define LLWU_PF2_WUF10_SHIFT                     2
#define LLWU_PF2_WUF11_MASK                      0x8u
#define LLWU_PF2_WUF11_SHIFT                     3
#define LLWU_PF2_WUF12_MASK                      0x10u
#define LLWU_PF2_WUF12_SHIFT                     4
#define LLWU_PF2_WUF13_MASK                      0x20u
#define LLWU_PF2_WUF13_SHIFT                     5
#define LLWU_PF2_WUF14_MASK                      0x40u
#define LLWU_PF2_WUF14_SHIFT                     6
#define LLWU_PF2_WUF15_MASK                      0x80u
#define LLWU_PF2_WUF15_SHIFT                     7
/* PF3 Bit Fields */
#define LLWU_PF3_WUF16_MASK                      0x1u
#define LLWU_PF3_WUF16_SHIFT                     0
#define LLWU_PF3_WUF17_MASK                      0x2u
#define LLWU_PF3_WUF17_SHIFT                     1
#define LLWU_PF3_WUF18_MASK                      0x4u
#define LLWU_PF3_WUF18_SHIFT                     2
#define LLWU_PF3_WUF19_MASK                      0x8u
#define LLWU_PF3_WUF19_SHIFT                     3
#define LLWU_PF3_WUF20_MASK                      0x10u
#define LLWU_PF3_WUF20_SHIFT                     4
#define LLWU_PF3_WUF21_MASK                      0x20u
#define LLWU_PF3_WUF21_SHIFT                     5
#define LLWU_PF3_WUF22_MASK                      0x40u
#define LLWU_PF3_WUF22_SHIFT                     6
#define LLWU_PF3_WUF23_MASK                      0x80u
#define LLWU_PF3_WUF23_SHIFT                     7
/* PF4 Bit Fields */
#define LLWU_PF4_WUF24_MASK                      0x1u
#define LLWU_PF4_WUF24_SHIFT                     0
#define LLWU_PF4_WUF25_MASK                      0x2u
#define LLWU_PF4_WUF25_SHIFT                     1
#define LLWU_PF4_WUF26_MASK                      0x4u
#define LLWU_PF4_WUF26_SHIFT                     2
#define LLWU_PF4_WUF27_MASK                      0x8u
#define LLWU_PF4_WUF27_SHIFT                     3
#define LLWU_PF4_WUF28_MASK                      0x10u
#define LLWU_PF4_WUF28_SHIFT                     4
#define LLWU_PF4_WUF29_MASK                      0x20u
#define LLWU_PF4_WUF29_SHIFT                     5
#define LLWU_PF4_WUF30_MASK                      0x40u
#define LLWU_PF4_WUF30_SHIFT                     6
#define LLWU_PF4_WUF31_MASK                      0x80u
#define LLWU_PF4_WUF31_SHIFT                     7
/* MF5 Bit Fields */
#define LLWU_MF5_MWUF0_MASK                      0x1u
#define LLWU_MF5_MWUF0_SHIFT                     0
#define LLWU_MF5_MWUF1_MASK                      0x2u
#define LLWU_MF5_MWUF1_SHIFT                     1
#define LLWU_MF5_MWUF2_MASK                      0x4u
#define LLWU_MF5_MWUF2_SHIFT                     2
#define LLWU_MF5_MWUF3_MASK                      0x8u
#define LLWU_MF5_MWUF3_SHIFT                     3
#define LLWU_MF5_MWUF4_MASK                      0x10u
#define LLWU_MF5_MWUF4_SHIFT                     4
#define LLWU_MF5_MWUF5_MASK                      0x20u
#define LLWU_MF5_MWUF5_SHIFT                     5
#define LLWU_MF5_MWUF6_MASK                      0x40u
#define LLWU_MF5_MWUF6_SHIFT                     6
#define LLWU_MF5_MWUF7_MASK                      0x80u
#define LLWU_MF5_MWUF7_SHIFT                     7
/* FILT1 Bit Fields */
#define LLWU_FILT1_FILTSEL_MASK                  0x1Fu
#define LLWU_FILT1_FILTSEL_SHIFT                 0
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK)
#define LLWU_FILT1_FILTE_MASK                    0x60u
#define LLWU_FILT1_FILTE_SHIFT                   5
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK)
#define LLWU_FILT1_FILTF_MASK                    0x80u
#define LLWU_FILT1_FILTF_SHIFT                   7
/* FILT2 Bit Fields */
#define LLWU_FILT2_FILTSEL_MASK                  0x1Fu
#define LLWU_FILT2_FILTSEL_SHIFT                 0
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK)
#define LLWU_FILT2_FILTE_MASK                    0x60u
#define LLWU_FILT2_FILTE_SHIFT                   5
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK)
#define LLWU_FILT2_FILTF_MASK                    0x80u
#define LLWU_FILT2_FILTF_SHIFT                   7

/*!
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base pointer */
#define LLWU_BASE_PTR                            ((LLWU_MemMapPtr)0x4007C000u)
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register instance definitions */
/* LLWU */
#define LLWU_PE1                                 LLWU_PE1_REG(LLWU_BASE_PTR)
#define LLWU_PE2                                 LLWU_PE2_REG(LLWU_BASE_PTR)
#define LLWU_PE3                                 LLWU_PE3_REG(LLWU_BASE_PTR)
#define LLWU_PE4                                 LLWU_PE4_REG(LLWU_BASE_PTR)
#define LLWU_PE5                                 LLWU_PE5_REG(LLWU_BASE_PTR)
#define LLWU_PE6                                 LLWU_PE6_REG(LLWU_BASE_PTR)
#define LLWU_PE7                                 LLWU_PE7_REG(LLWU_BASE_PTR)
#define LLWU_PE8                                 LLWU_PE8_REG(LLWU_BASE_PTR)
#define LLWU_ME                                  LLWU_ME_REG(LLWU_BASE_PTR)
#define LLWU_PF1                                 LLWU_PF1_REG(LLWU_BASE_PTR)
#define LLWU_PF2                                 LLWU_PF2_REG(LLWU_BASE_PTR)
#define LLWU_PF3                                 LLWU_PF3_REG(LLWU_BASE_PTR)
#define LLWU_PF4                                 LLWU_PF4_REG(LLWU_BASE_PTR)
#define LLWU_MF5                                 LLWU_MF5_REG(LLWU_BASE_PTR)
#define LLWU_FILT1                               LLWU_FILT1_REG(LLWU_BASE_PTR)
#define LLWU_FILT2                               LLWU_FILT2_REG(LLWU_BASE_PTR)

/*!
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LLWU_Peripheral */


/* ----------------------------------------------------------------------------
   -- LPTMR
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Peripheral LPTMR
 * @{
 */

/** LPTMR - Peripheral register structure */
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                    /**< Low Power Timer Control Status Register, offset: 0x0 */
  uint32_t PSR;                                    /**< Low Power Timer Prescale Register, offset: 0x4 */
  uint32_t CMR;                                    /**< Low Power Timer Compare Register, offset: 0x8 */
  uint32_t CNR;                                    /**< Low Power Timer Counter Register, offset: 0xC */
} volatile *LPTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register accessors */
#define LPTMR_CSR_REG(base)                      ((base)->CSR)
#define LPTMR_PSR_REG(base)                      ((base)->PSR)
#define LPTMR_CMR_REG(base)                      ((base)->CMR)
#define LPTMR_CNR_REG(base)                      ((base)->CNR)

/*!
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR base pointer */
#define LPTMR_BASE_PTR                           ((LPTMR_MemMapPtr)0x40040000u)
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register instance definitions */
/* LPTMR */
#define LPTMR_CSR                                LPTMR_CSR_REG(LPTMR_BASE_PTR)
#define LPTMR_PSR                                LPTMR_PSR_REG(LPTMR_BASE_PTR)
#define LPTMR_CMR                                LPTMR_CMR_REG(LPTMR_BASE_PTR)
#define LPTMR_CNR                                LPTMR_CNR_REG(LPTMR_BASE_PTR)

/*!
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPTMR_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCG
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral MCG
 * @{
 */

/** MCG - Peripheral register structure */
typedef struct MCG_MemMap {
  uint8_t C1;                                      /**< MCG Control 1 Register, offset: 0x0 */
  uint8_t C2;                                      /**< MCG Control 2 Register, offset: 0x1 */
  uint8_t C3;                                      /**< MCG Control 3 Register, offset: 0x2 */
  uint8_t C4;                                      /**< MCG Control 4 Register, offset: 0x3 */
  uint8_t C5;                                      /**< MCG Control 5 Register, offset: 0x4 */
  uint8_t C6;                                      /**< MCG Control 6 Register, offset: 0x5 */
  uint8_t S;                                       /**< MCG Status Register, offset: 0x6 */
  uint8_t RESERVED_0[1];
  uint8_t SC;                                      /**< MCG Status and Control Register, offset: 0x8 */
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                   /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  uint8_t ATCVL;                                   /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  uint8_t RESERVED_2[1];
  uint8_t C8;                                      /**< MCG Control 8 Register, offset: 0xD */
} volatile *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register accessors */
#define MCG_C1_REG(base)                         ((base)->C1)
#define MCG_C2_REG(base)                         ((base)->C2)
#define MCG_C3_REG(base)                         ((base)->C3)
#define MCG_C4_REG(base)                         ((base)->C4)
#define MCG_C5_REG(base)                         ((base)->C5)
#define MCG_C6_REG(base)                         ((base)->C6)
#define MCG_S_REG(base)                          ((base)->S)
#define MCG_SC_REG(base)                         ((base)->SC)
#define MCG_ATCVH_REG(base)                      ((base)->ATCVH)
#define MCG_ATCVL_REG(base)                      ((base)->ATCVL)
#define MCG_C8_REG(base)                         ((base)->C8)

/*!
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_EREFS_MASK                        0x4u
#define MCG_C2_EREFS_SHIFT                       2
#define MCG_C2_HGO_MASK                          0x8u
#define MCG_C2_HGO_SHIFT                         3
#define MCG_C2_RANGE_MASK                        0x30u
#define MCG_C2_RANGE_SHIFT                       4
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE_SHIFT))&MCG_C2_RANGE_MASK)
#define MCG_C2_FCFTRIM_MASK                      0x40u
#define MCG_C2_FCFTRIM_SHIFT                     6
#define MCG_C2_LOCRE0_MASK                       0x80u
#define MCG_C2_LOCRE0_SHIFT                      7
/* C3 Bit Fields */
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
/* C5 Bit Fields */
#define MCG_C5_PRDIV_MASK                        0x7u
#define MCG_C5_PRDIV_SHIFT                       0
#define MCG_C5_PRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV_SHIFT))&MCG_C5_PRDIV_MASK)
#define MCG_C5_PLLSTEN_MASK                      0x20u
#define MCG_C5_PLLSTEN_SHIFT                     5
#define MCG_C5_PLLCLKEN_MASK                     0x40u
#define MCG_C5_PLLCLKEN_SHIFT                    6
/* C6 Bit Fields */
#define MCG_C6_VDIV_MASK                         0x1Fu
#define MCG_C6_VDIV_SHIFT                        0
#define MCG_C6_VDIV(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV_SHIFT))&MCG_C6_VDIV_MASK)
#define MCG_C6_CME0_MASK                         0x20u
#define MCG_C6_CME0_SHIFT                        5
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_LOLIE0_MASK                       0x80u
#define MCG_C6_LOLIE0_SHIFT                      7
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_OSCINIT0_MASK                      0x2u
#define MCG_S_OSCINIT0_SHIFT                     1
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_LOCK0_MASK                         0x40u
#define MCG_S_LOCK0_SHIFT                        6
#define MCG_S_LOLS0_MASK                         0x80u
#define MCG_S_LOLS0_SHIFT                        7
/* SC Bit Fields */
#define MCG_SC_LOCS0_MASK                        0x1u
#define MCG_SC_LOCS0_SHIFT                       0
#define MCG_SC_FCRDIV_MASK                       0xEu
#define MCG_SC_FCRDIV_SHIFT                      1
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     0x10u
#define MCG_SC_FLTPRSRV_SHIFT                    4
#define MCG_SC_ATMF_MASK                         0x20u
#define MCG_SC_ATMF_SHIFT                        5
#define MCG_SC_ATMS_MASK                         0x40u
#define MCG_SC_ATMS_SHIFT                        6
#define MCG_SC_ATME_MASK                         0x80u
#define MCG_SC_ATME_SHIFT                        7
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)
/* C8 Bit Fields */
#define MCG_C8_LOLRE_MASK                        0x40u
#define MCG_C8_LOLRE_SHIFT                       6

/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base pointer */
#define MCG_BASE_PTR                             ((MCG_MemMapPtr)0x40064000u)
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register instance definitions */
/* MCG */
#define MCG_C1                                   MCG_C1_REG(MCG_BASE_PTR)
#define MCG_C2                                   MCG_C2_REG(MCG_BASE_PTR)
#define MCG_C3                                   MCG_C3_REG(MCG_BASE_PTR)
#define MCG_C4                                   MCG_C4_REG(MCG_BASE_PTR)
#define MCG_C5                                   MCG_C5_REG(MCG_BASE_PTR)
#define MCG_C6                                   MCG_C6_REG(MCG_BASE_PTR)
#define MCG_S                                    MCG_S_REG(MCG_BASE_PTR)
#define MCG_SC                                   MCG_SC_REG(MCG_BASE_PTR)
#define MCG_ATCVH                                MCG_ATCVH_REG(MCG_BASE_PTR)
#define MCG_ATCVL                                MCG_ATCVL_REG(MCG_BASE_PTR)
#define MCG_C8                                   MCG_C8_REG(MCG_BASE_PTR)

/*!
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCG_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral MCM
 * @{
 */

/** MCM - Peripheral register structure */
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                  /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  uint16_t PLAMC;                                  /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  uint32_t CR;                                     /**< Control Register, offset: 0xC */
  uint32_t ISR;                                    /**< Interrupt Status Register, offset: 0x10 */
  uint8_t RESERVED_1[44];
  uint32_t CPO;                                    /**< Compute Operation Control Register, offset: 0x40 */
} volatile *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register accessors */
#define MCM_PLASC_REG(base)                      ((base)->PLASC)
#define MCM_PLAMC_REG(base)                      ((base)->PLAMC)
#define MCM_CR_REG(base)                         ((base)->CR)
#define MCM_ISR_REG(base)                        ((base)->ISR)
#define MCM_CPO_REG(base)                        ((base)->CPO)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* CR Bit Fields */
#define MCM_CR_SRAMUAP_MASK                      0x3000000u
#define MCM_CR_SRAMUAP_SHIFT                     24
#define MCM_CR_SRAMUAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUAP_SHIFT))&MCM_CR_SRAMUAP_MASK)
#define MCM_CR_SRAMUWP_MASK                      0x4000000u
#define MCM_CR_SRAMUWP_SHIFT                     26
#define MCM_CR_SRAMLAP_MASK                      0x30000000u
#define MCM_CR_SRAMLAP_SHIFT                     28
#define MCM_CR_SRAMLAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLAP_SHIFT))&MCM_CR_SRAMLAP_MASK)
#define MCM_CR_SRAMLWP_MASK                      0x40000000u
#define MCM_CR_SRAMLWP_SHIFT                     30
/* ISR Bit Fields */
#define MCM_ISR_FIOC_MASK                        0x100u
#define MCM_ISR_FIOC_SHIFT                       8
#define MCM_ISR_FDZC_MASK                        0x200u
#define MCM_ISR_FDZC_SHIFT                       9
#define MCM_ISR_FOFC_MASK                        0x400u
#define MCM_ISR_FOFC_SHIFT                       10
#define MCM_ISR_FUFC_MASK                        0x800u
#define MCM_ISR_FUFC_SHIFT                       11
#define MCM_ISR_FIXC_MASK                        0x1000u
#define MCM_ISR_FIXC_SHIFT                       12
#define MCM_ISR_FIDC_MASK                        0x8000u
#define MCM_ISR_FIDC_SHIFT                       15
#define MCM_ISR_FIOCE_MASK                       0x1000000u
#define MCM_ISR_FIOCE_SHIFT                      24
#define MCM_ISR_FDZCE_MASK                       0x2000000u
#define MCM_ISR_FDZCE_SHIFT                      25
#define MCM_ISR_FOFCE_MASK                       0x4000000u
#define MCM_ISR_FOFCE_SHIFT                      26
#define MCM_ISR_FUFCE_MASK                       0x8000000u
#define MCM_ISR_FUFCE_SHIFT                      27
#define MCM_ISR_FIXCE_MASK                       0x10000000u
#define MCM_ISR_FIXCE_SHIFT                      28
#define MCM_ISR_FIDCE_MASK                       0x80000000u
#define MCM_ISR_FIDCE_SHIFT                      31
/* CPO Bit Fields */
#define MCM_CPO_CPOREQ_MASK                      0x1u
#define MCM_CPO_CPOREQ_SHIFT                     0
#define MCM_CPO_CPOACK_MASK                      0x2u
#define MCM_CPO_CPOACK_SHIFT                     1
#define MCM_CPO_CPOWOI_MASK                      0x4u
#define MCM_CPO_CPOWOI_SHIFT                     2

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base pointer */
#define MCM_BASE_PTR                             ((MCM_MemMapPtr)0xE0080000u)
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM */
#define MCM_PLASC                                MCM_PLASC_REG(MCM_BASE_PTR)
#define MCM_PLAMC                                MCM_PLAMC_REG(MCM_BASE_PTR)
#define MCM_CR                                   MCM_CR_REG(MCM_BASE_PTR)
#define MCM_ISR                                  MCM_ISR_REG(MCM_BASE_PTR)
#define MCM_CPO                                  MCM_CPO_REG(MCM_BASE_PTR)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral NV
 * @{
 */

/** NV - Peripheral register structure */
typedef struct NV_MemMap {
  uint8_t BACKKEY3;                                /**< Backdoor Comparison Key 3., offset: 0x0 */
  uint8_t BACKKEY2;                                /**< Backdoor Comparison Key 2., offset: 0x1 */
  uint8_t BACKKEY1;                                /**< Backdoor Comparison Key 1., offset: 0x2 */
  uint8_t BACKKEY0;                                /**< Backdoor Comparison Key 0., offset: 0x3 */
  uint8_t BACKKEY7;                                /**< Backdoor Comparison Key 7., offset: 0x4 */
  uint8_t BACKKEY6;                                /**< Backdoor Comparison Key 6., offset: 0x5 */
  uint8_t BACKKEY5;                                /**< Backdoor Comparison Key 5., offset: 0x6 */
  uint8_t BACKKEY4;                                /**< Backdoor Comparison Key 4., offset: 0x7 */
  uint8_t FPROT3;                                  /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  uint8_t FPROT2;                                  /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  uint8_t FPROT1;                                  /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  uint8_t FPROT0;                                  /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  uint8_t FSEC;                                    /**< Non-volatile Flash Security Register, offset: 0xC */
  uint8_t FOPT;                                    /**< Non-volatile Flash Option Register, offset: 0xD */
  uint8_t FEPROT;                                  /**< Non-volatile EERAM Protection Register, offset: 0xE */
  uint8_t FDPROT;                                  /**< Non-volatile D-Flash Protection Register, offset: 0xF */
} volatile *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_FPROT3_REG(base)                      ((base)->FPROT3)
#define NV_FPROT2_REG(base)                      ((base)->FPROT2)
#define NV_FPROT1_REG(base)                      ((base)->FPROT1)
#define NV_FPROT0_REG(base)                      ((base)->FPROT0)
#define NV_FSEC_REG(base)                        ((base)->FSEC)
#define NV_FOPT_REG(base)                        ((base)->FOPT)
#define NV_FEPROT_REG(base)                      ((base)->FEPROT)
#define NV_FDPROT_REG(base)                      ((base)->FDPROT)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* FPROT3 Bit Fields */
#define NV_FPROT3_PROT_MASK                      0xFFu
#define NV_FPROT3_PROT_SHIFT                     0
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define NV_FPROT2_PROT_MASK                      0xFFu
#define NV_FPROT2_PROT_SHIFT                     0
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define NV_FPROT1_PROT_MASK                      0xFFu
#define NV_FPROT1_PROT_SHIFT                     0
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define NV_FPROT0_PROT_MASK                      0xFFu
#define NV_FPROT0_PROT_SHIFT                     0
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      0xCu
#define NV_FSEC_FSLACC_SHIFT                     2
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        0x30u
#define NV_FSEC_MEEN_SHIFT                       4
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define NV_FOPT_LPBOOT_MASK                      0x1u
#define NV_FOPT_LPBOOT_SHIFT                     0
#define NV_FOPT_NMI_DIS_MASK                     0x4u
#define NV_FOPT_NMI_DIS_SHIFT                    2
#define NV_FOPT_FAST_INIT_MASK                   0x20u
#define NV_FOPT_FAST_INIT_SHIFT                  5
/* FEPROT Bit Fields */
#define NV_FEPROT_EPROT_MASK                     0xFFu
#define NV_FEPROT_EPROT_SHIFT                    0
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FEPROT_EPROT_SHIFT))&NV_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define NV_FDPROT_DPROT_MASK                     0xFFu
#define NV_FDPROT_DPROT_SHIFT                    0
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FDPROT_DPROT_SHIFT))&NV_FDPROT_DPROT_MASK)

/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFL_FlashConfig base pointer */
#define FTFL_FlashConfig_BASE_PTR                ((NV_MemMapPtr)0x400u)
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFL_FlashConfig_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTFL_FlashConfig */
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT3                                NV_FPROT3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT2                                NV_FPROT2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT1                                NV_FPROT1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT0                                NV_FPROT0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FSEC                                  NV_FSEC_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FOPT                                  NV_FOPT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FEPROT                                NV_FEPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FDPROT                                NV_FDPROT_REG(FTFL_FlashConfig_BASE_PTR)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group NV_Peripheral */


/* ----------------------------------------------------------------------------
   -- NVIC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NVIC_Peripheral NVIC
 * @{
 */

/** NVIC - Peripheral register structure */
typedef struct NVIC_MemMap {
  uint32_t ISER[4];                                /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[112];
  uint32_t ICER[4];                                /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_1[112];
  uint32_t ISPR[4];                                /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_2[112];
  uint32_t ICPR[4];                                /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_3[112];
  uint32_t IABR[4];                                /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[240];
  uint8_t IP[106];                                 /**< Interrupt Priority Register 0..Interrupt Priority Register 105, array offset: 0x300, array step: 0x1 */
  uint8_t RESERVED_5[2710];
  uint32_t STIR[1];                                /**< Software Trigger Interrupt Register, array offset: 0xE00, array step: 0x4 */
} volatile *NVIC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register accessors */
#define NVIC_ISER_REG(base,index)                ((base)->ISER[index])
#define NVIC_ICER_REG(base,index)                ((base)->ICER[index])
#define NVIC_ISPR_REG(base,index)                ((base)->ISPR[index])
#define NVIC_ICPR_REG(base,index)                ((base)->ICPR[index])
#define NVIC_IABR_REG(base,index)                ((base)->IABR[index])
#define NVIC_IP_REG(base,index)                  ((base)->IP[index])
#define NVIC_STIR_REG(base,index)                ((base)->STIR[index])

/*!
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NVIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NVIC_Register_Masks NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */
#define NVIC_ISER_SETENA_MASK                    0xFFFFFFFFu
#define NVIC_ISER_SETENA_SHIFT                   0
#define NVIC_ISER_SETENA(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_ISER_SETENA_SHIFT))&NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define NVIC_ICER_CLRENA_MASK                    0xFFFFFFFFu
#define NVIC_ICER_CLRENA_SHIFT                   0
#define NVIC_ICER_CLRENA(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_ICER_CLRENA_SHIFT))&NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define NVIC_ISPR_SETPEND_MASK                   0xFFFFFFFFu
#define NVIC_ISPR_SETPEND_SHIFT                  0
#define NVIC_ISPR_SETPEND(x)                     (((uint32_t)(((uint32_t)(x))<<NVIC_ISPR_SETPEND_SHIFT))&NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define NVIC_ICPR_CLRPEND_MASK                   0xFFFFFFFFu
#define NVIC_ICPR_CLRPEND_SHIFT                  0
#define NVIC_ICPR_CLRPEND(x)                     (((uint32_t)(((uint32_t)(x))<<NVIC_ICPR_CLRPEND_SHIFT))&NVIC_ICPR_CLRPEND_MASK)
/* IABR Bit Fields */
#define NVIC_IABR_ACTIVE_MASK                    0xFFFFFFFFu
#define NVIC_IABR_ACTIVE_SHIFT                   0
#define NVIC_IABR_ACTIVE(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_IABR_ACTIVE_SHIFT))&NVIC_IABR_ACTIVE_MASK)
/* IP Bit Fields */
#define NVIC_IP_PRI0_MASK                        0xF0u
#define NVIC_IP_PRI0_SHIFT                       4
#define NVIC_IP_PRI0(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI0_SHIFT))&NVIC_IP_PRI0_MASK)
#define NVIC_IP_PRI1_MASK                        0xF0u
#define NVIC_IP_PRI1_SHIFT                       4
#define NVIC_IP_PRI1(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI1_SHIFT))&NVIC_IP_PRI1_MASK)
#define NVIC_IP_PRI2_MASK                        0xF0u
#define NVIC_IP_PRI2_SHIFT                       4
#define NVIC_IP_PRI2(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI2_SHIFT))&NVIC_IP_PRI2_MASK)
#define NVIC_IP_PRI3_MASK                        0xF0u
#define NVIC_IP_PRI3_SHIFT                       4
#define NVIC_IP_PRI3(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI3_SHIFT))&NVIC_IP_PRI3_MASK)
#define NVIC_IP_PRI4_MASK                        0xF0u
#define NVIC_IP_PRI4_SHIFT                       4
#define NVIC_IP_PRI4(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI4_SHIFT))&NVIC_IP_PRI4_MASK)
#define NVIC_IP_PRI5_MASK                        0xF0u
#define NVIC_IP_PRI5_SHIFT                       4
#define NVIC_IP_PRI5(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI5_SHIFT))&NVIC_IP_PRI5_MASK)
#define NVIC_IP_PRI6_MASK                        0xF0u
#define NVIC_IP_PRI6_SHIFT                       4
#define NVIC_IP_PRI6(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI6_SHIFT))&NVIC_IP_PRI6_MASK)
#define NVIC_IP_PRI7_MASK                        0xF0u
#define NVIC_IP_PRI7_SHIFT                       4
#define NVIC_IP_PRI7(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI7_SHIFT))&NVIC_IP_PRI7_MASK)
#define NVIC_IP_PRI8_MASK                        0xF0u
#define NVIC_IP_PRI8_SHIFT                       4
#define NVIC_IP_PRI8(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI8_SHIFT))&NVIC_IP_PRI8_MASK)
#define NVIC_IP_PRI9_MASK                        0xF0u
#define NVIC_IP_PRI9_SHIFT                       4
#define NVIC_IP_PRI9(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI9_SHIFT))&NVIC_IP_PRI9_MASK)
#define NVIC_IP_PRI10_MASK                       0xF0u
#define NVIC_IP_PRI10_SHIFT                      4
#define NVIC_IP_PRI10(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI10_SHIFT))&NVIC_IP_PRI10_MASK)
#define NVIC_IP_PRI11_MASK                       0xF0u
#define NVIC_IP_PRI11_SHIFT                      4
#define NVIC_IP_PRI11(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI11_SHIFT))&NVIC_IP_PRI11_MASK)
#define NVIC_IP_PRI12_MASK                       0xF0u
#define NVIC_IP_PRI12_SHIFT                      4
#define NVIC_IP_PRI12(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI12_SHIFT))&NVIC_IP_PRI12_MASK)
#define NVIC_IP_PRI13_MASK                       0xF0u
#define NVIC_IP_PRI13_SHIFT                      4
#define NVIC_IP_PRI13(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI13_SHIFT))&NVIC_IP_PRI13_MASK)
#define NVIC_IP_PRI14_MASK                       0xF0u
#define NVIC_IP_PRI14_SHIFT                      4
#define NVIC_IP_PRI14(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI14_SHIFT))&NVIC_IP_PRI14_MASK)
#define NVIC_IP_PRI15_MASK                       0xF0u
#define NVIC_IP_PRI15_SHIFT                      4
#define NVIC_IP_PRI15(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI15_SHIFT))&NVIC_IP_PRI15_MASK)
#define NVIC_IP_PRI16_MASK                       0xF0u
#define NVIC_IP_PRI16_SHIFT                      4
#define NVIC_IP_PRI16(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI16_SHIFT))&NVIC_IP_PRI16_MASK)
#define NVIC_IP_PRI17_MASK                       0xF0u
#define NVIC_IP_PRI17_SHIFT                      4
#define NVIC_IP_PRI17(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI17_SHIFT))&NVIC_IP_PRI17_MASK)
#define NVIC_IP_PRI18_MASK                       0xF0u
#define NVIC_IP_PRI18_SHIFT                      4
#define NVIC_IP_PRI18(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI18_SHIFT))&NVIC_IP_PRI18_MASK)
#define NVIC_IP_PRI19_MASK                       0xF0u
#define NVIC_IP_PRI19_SHIFT                      4
#define NVIC_IP_PRI19(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI19_SHIFT))&NVIC_IP_PRI19_MASK)
#define NVIC_IP_PRI20_MASK                       0xF0u
#define NVIC_IP_PRI20_SHIFT                      4
#define NVIC_IP_PRI20(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI20_SHIFT))&NVIC_IP_PRI20_MASK)
#define NVIC_IP_PRI21_MASK                       0xF0u
#define NVIC_IP_PRI21_SHIFT                      4
#define NVIC_IP_PRI21(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI21_SHIFT))&NVIC_IP_PRI21_MASK)
#define NVIC_IP_PRI22_MASK                       0xF0u
#define NVIC_IP_PRI22_SHIFT                      4
#define NVIC_IP_PRI22(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI22_SHIFT))&NVIC_IP_PRI22_MASK)
#define NVIC_IP_PRI23_MASK                       0xF0u
#define NVIC_IP_PRI23_SHIFT                      4
#define NVIC_IP_PRI23(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI23_SHIFT))&NVIC_IP_PRI23_MASK)
#define NVIC_IP_PRI24_MASK                       0xF0u
#define NVIC_IP_PRI24_SHIFT                      4
#define NVIC_IP_PRI24(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI24_SHIFT))&NVIC_IP_PRI24_MASK)
#define NVIC_IP_PRI25_MASK                       0xF0u
#define NVIC_IP_PRI25_SHIFT                      4
#define NVIC_IP_PRI25(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI25_SHIFT))&NVIC_IP_PRI25_MASK)
#define NVIC_IP_PRI26_MASK                       0xF0u
#define NVIC_IP_PRI26_SHIFT                      4
#define NVIC_IP_PRI26(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI26_SHIFT))&NVIC_IP_PRI26_MASK)
#define NVIC_IP_PRI27_MASK                       0xF0u
#define NVIC_IP_PRI27_SHIFT                      4
#define NVIC_IP_PRI27(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI27_SHIFT))&NVIC_IP_PRI27_MASK)
#define NVIC_IP_PRI28_MASK                       0xF0u
#define NVIC_IP_PRI28_SHIFT                      4
#define NVIC_IP_PRI28(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI28_SHIFT))&NVIC_IP_PRI28_MASK)
#define NVIC_IP_PRI29_MASK                       0xF0u
#define NVIC_IP_PRI29_SHIFT                      4
#define NVIC_IP_PRI29(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI29_SHIFT))&NVIC_IP_PRI29_MASK)
#define NVIC_IP_PRI30_MASK                       0xF0u
#define NVIC_IP_PRI30_SHIFT                      4
#define NVIC_IP_PRI30(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI30_SHIFT))&NVIC_IP_PRI30_MASK)
#define NVIC_IP_PRI31_MASK                       0xF0u
#define NVIC_IP_PRI31_SHIFT                      4
#define NVIC_IP_PRI31(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI31_SHIFT))&NVIC_IP_PRI31_MASK)
#define NVIC_IP_PRI32_MASK                       0xF0u
#define NVIC_IP_PRI32_SHIFT                      4
#define NVIC_IP_PRI32(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI32_SHIFT))&NVIC_IP_PRI32_MASK)
#define NVIC_IP_PRI33_MASK                       0xF0u
#define NVIC_IP_PRI33_SHIFT                      4
#define NVIC_IP_PRI33(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI33_SHIFT))&NVIC_IP_PRI33_MASK)
#define NVIC_IP_PRI34_MASK                       0xF0u
#define NVIC_IP_PRI34_SHIFT                      4
#define NVIC_IP_PRI34(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI34_SHIFT))&NVIC_IP_PRI34_MASK)
#define NVIC_IP_PRI35_MASK                       0xF0u
#define NVIC_IP_PRI35_SHIFT                      4
#define NVIC_IP_PRI35(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI35_SHIFT))&NVIC_IP_PRI35_MASK)
#define NVIC_IP_PRI36_MASK                       0xF0u
#define NVIC_IP_PRI36_SHIFT                      4
#define NVIC_IP_PRI36(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI36_SHIFT))&NVIC_IP_PRI36_MASK)
#define NVIC_IP_PRI37_MASK                       0xF0u
#define NVIC_IP_PRI37_SHIFT                      4
#define NVIC_IP_PRI37(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI37_SHIFT))&NVIC_IP_PRI37_MASK)
#define NVIC_IP_PRI38_MASK                       0xF0u
#define NVIC_IP_PRI38_SHIFT                      4
#define NVIC_IP_PRI38(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI38_SHIFT))&NVIC_IP_PRI38_MASK)
#define NVIC_IP_PRI39_MASK                       0xF0u
#define NVIC_IP_PRI39_SHIFT                      4
#define NVIC_IP_PRI39(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI39_SHIFT))&NVIC_IP_PRI39_MASK)
#define NVIC_IP_PRI40_MASK                       0xF0u
#define NVIC_IP_PRI40_SHIFT                      4
#define NVIC_IP_PRI40(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI40_SHIFT))&NVIC_IP_PRI40_MASK)
#define NVIC_IP_PRI41_MASK                       0xF0u
#define NVIC_IP_PRI41_SHIFT                      4
#define NVIC_IP_PRI41(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI41_SHIFT))&NVIC_IP_PRI41_MASK)
#define NVIC_IP_PRI42_MASK                       0xF0u
#define NVIC_IP_PRI42_SHIFT                      4
#define NVIC_IP_PRI42(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI42_SHIFT))&NVIC_IP_PRI42_MASK)
#define NVIC_IP_PRI43_MASK                       0xF0u
#define NVIC_IP_PRI43_SHIFT                      4
#define NVIC_IP_PRI43(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI43_SHIFT))&NVIC_IP_PRI43_MASK)
#define NVIC_IP_PRI44_MASK                       0xF0u
#define NVIC_IP_PRI44_SHIFT                      4
#define NVIC_IP_PRI44(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI44_SHIFT))&NVIC_IP_PRI44_MASK)
#define NVIC_IP_PRI45_MASK                       0xF0u
#define NVIC_IP_PRI45_SHIFT                      4
#define NVIC_IP_PRI45(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI45_SHIFT))&NVIC_IP_PRI45_MASK)
#define NVIC_IP_PRI46_MASK                       0xF0u
#define NVIC_IP_PRI46_SHIFT                      4
#define NVIC_IP_PRI46(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI46_SHIFT))&NVIC_IP_PRI46_MASK)
#define NVIC_IP_PRI47_MASK                       0xF0u
#define NVIC_IP_PRI47_SHIFT                      4
#define NVIC_IP_PRI47(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI47_SHIFT))&NVIC_IP_PRI47_MASK)
#define NVIC_IP_PRI48_MASK                       0xF0u
#define NVIC_IP_PRI48_SHIFT                      4
#define NVIC_IP_PRI48(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI48_SHIFT))&NVIC_IP_PRI48_MASK)
#define NVIC_IP_PRI49_MASK                       0xF0u
#define NVIC_IP_PRI49_SHIFT                      4
#define NVIC_IP_PRI49(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI49_SHIFT))&NVIC_IP_PRI49_MASK)
#define NVIC_IP_PRI50_MASK                       0xF0u
#define NVIC_IP_PRI50_SHIFT                      4
#define NVIC_IP_PRI50(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI50_SHIFT))&NVIC_IP_PRI50_MASK)
#define NVIC_IP_PRI51_MASK                       0xF0u
#define NVIC_IP_PRI51_SHIFT                      4
#define NVIC_IP_PRI51(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI51_SHIFT))&NVIC_IP_PRI51_MASK)
#define NVIC_IP_PRI52_MASK                       0xF0u
#define NVIC_IP_PRI52_SHIFT                      4
#define NVIC_IP_PRI52(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI52_SHIFT))&NVIC_IP_PRI52_MASK)
#define NVIC_IP_PRI53_MASK                       0xF0u
#define NVIC_IP_PRI53_SHIFT                      4
#define NVIC_IP_PRI53(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI53_SHIFT))&NVIC_IP_PRI53_MASK)
#define NVIC_IP_PRI54_MASK                       0xF0u
#define NVIC_IP_PRI54_SHIFT                      4
#define NVIC_IP_PRI54(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI54_SHIFT))&NVIC_IP_PRI54_MASK)
#define NVIC_IP_PRI55_MASK                       0xF0u
#define NVIC_IP_PRI55_SHIFT                      4
#define NVIC_IP_PRI55(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI55_SHIFT))&NVIC_IP_PRI55_MASK)
#define NVIC_IP_PRI56_MASK                       0xF0u
#define NVIC_IP_PRI56_SHIFT                      4
#define NVIC_IP_PRI56(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI56_SHIFT))&NVIC_IP_PRI56_MASK)
#define NVIC_IP_PRI57_MASK                       0xF0u
#define NVIC_IP_PRI57_SHIFT                      4
#define NVIC_IP_PRI57(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI57_SHIFT))&NVIC_IP_PRI57_MASK)
#define NVIC_IP_PRI58_MASK                       0xF0u
#define NVIC_IP_PRI58_SHIFT                      4
#define NVIC_IP_PRI58(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI58_SHIFT))&NVIC_IP_PRI58_MASK)
#define NVIC_IP_PRI59_MASK                       0xF0u
#define NVIC_IP_PRI59_SHIFT                      4
#define NVIC_IP_PRI59(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI59_SHIFT))&NVIC_IP_PRI59_MASK)
#define NVIC_IP_PRI60_MASK                       0xF0u
#define NVIC_IP_PRI60_SHIFT                      4
#define NVIC_IP_PRI60(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI60_SHIFT))&NVIC_IP_PRI60_MASK)
#define NVIC_IP_PRI61_MASK                       0xF0u
#define NVIC_IP_PRI61_SHIFT                      4
#define NVIC_IP_PRI61(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI61_SHIFT))&NVIC_IP_PRI61_MASK)
#define NVIC_IP_PRI62_MASK                       0xF0u
#define NVIC_IP_PRI62_SHIFT                      4
#define NVIC_IP_PRI62(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI62_SHIFT))&NVIC_IP_PRI62_MASK)
#define NVIC_IP_PRI63_MASK                       0xF0u
#define NVIC_IP_PRI63_SHIFT                      4
#define NVIC_IP_PRI63(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI63_SHIFT))&NVIC_IP_PRI63_MASK)
#define NVIC_IP_PRI64_MASK                       0xF0u
#define NVIC_IP_PRI64_SHIFT                      4
#define NVIC_IP_PRI64(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI64_SHIFT))&NVIC_IP_PRI64_MASK)
#define NVIC_IP_PRI65_MASK                       0xF0u
#define NVIC_IP_PRI65_SHIFT                      4
#define NVIC_IP_PRI65(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI65_SHIFT))&NVIC_IP_PRI65_MASK)
#define NVIC_IP_PRI66_MASK                       0xF0u
#define NVIC_IP_PRI66_SHIFT                      4
#define NVIC_IP_PRI66(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI66_SHIFT))&NVIC_IP_PRI66_MASK)
#define NVIC_IP_PRI67_MASK                       0xF0u
#define NVIC_IP_PRI67_SHIFT                      4
#define NVIC_IP_PRI67(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI67_SHIFT))&NVIC_IP_PRI67_MASK)
#define NVIC_IP_PRI68_MASK                       0xF0u
#define NVIC_IP_PRI68_SHIFT                      4
#define NVIC_IP_PRI68(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI68_SHIFT))&NVIC_IP_PRI68_MASK)
#define NVIC_IP_PRI69_MASK                       0xF0u
#define NVIC_IP_PRI69_SHIFT                      4
#define NVIC_IP_PRI69(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI69_SHIFT))&NVIC_IP_PRI69_MASK)
#define NVIC_IP_PRI70_MASK                       0xF0u
#define NVIC_IP_PRI70_SHIFT                      4
#define NVIC_IP_PRI70(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI70_SHIFT))&NVIC_IP_PRI70_MASK)
#define NVIC_IP_PRI71_MASK                       0xF0u
#define NVIC_IP_PRI71_SHIFT                      4
#define NVIC_IP_PRI71(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI71_SHIFT))&NVIC_IP_PRI71_MASK)
#define NVIC_IP_PRI72_MASK                       0xF0u
#define NVIC_IP_PRI72_SHIFT                      4
#define NVIC_IP_PRI72(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI72_SHIFT))&NVIC_IP_PRI72_MASK)
#define NVIC_IP_PRI73_MASK                       0xF0u
#define NVIC_IP_PRI73_SHIFT                      4
#define NVIC_IP_PRI73(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI73_SHIFT))&NVIC_IP_PRI73_MASK)
#define NVIC_IP_PRI74_MASK                       0xF0u
#define NVIC_IP_PRI74_SHIFT                      4
#define NVIC_IP_PRI74(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI74_SHIFT))&NVIC_IP_PRI74_MASK)
#define NVIC_IP_PRI75_MASK                       0xF0u
#define NVIC_IP_PRI75_SHIFT                      4
#define NVIC_IP_PRI75(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI75_SHIFT))&NVIC_IP_PRI75_MASK)
#define NVIC_IP_PRI76_MASK                       0xF0u
#define NVIC_IP_PRI76_SHIFT                      4
#define NVIC_IP_PRI76(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI76_SHIFT))&NVIC_IP_PRI76_MASK)
#define NVIC_IP_PRI77_MASK                       0xF0u
#define NVIC_IP_PRI77_SHIFT                      4
#define NVIC_IP_PRI77(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI77_SHIFT))&NVIC_IP_PRI77_MASK)
#define NVIC_IP_PRI78_MASK                       0xF0u
#define NVIC_IP_PRI78_SHIFT                      4
#define NVIC_IP_PRI78(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI78_SHIFT))&NVIC_IP_PRI78_MASK)
#define NVIC_IP_PRI79_MASK                       0xF0u
#define NVIC_IP_PRI79_SHIFT                      4
#define NVIC_IP_PRI79(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI79_SHIFT))&NVIC_IP_PRI79_MASK)
#define NVIC_IP_PRI80_MASK                       0xF0u
#define NVIC_IP_PRI80_SHIFT                      4
#define NVIC_IP_PRI80(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI80_SHIFT))&NVIC_IP_PRI80_MASK)
#define NVIC_IP_PRI81_MASK                       0xF0u
#define NVIC_IP_PRI81_SHIFT                      4
#define NVIC_IP_PRI81(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI81_SHIFT))&NVIC_IP_PRI81_MASK)
#define NVIC_IP_PRI82_MASK                       0xF0u
#define NVIC_IP_PRI82_SHIFT                      4
#define NVIC_IP_PRI82(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI82_SHIFT))&NVIC_IP_PRI82_MASK)
#define NVIC_IP_PRI83_MASK                       0xF0u
#define NVIC_IP_PRI83_SHIFT                      4
#define NVIC_IP_PRI83(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI83_SHIFT))&NVIC_IP_PRI83_MASK)
#define NVIC_IP_PRI84_MASK                       0xF0u
#define NVIC_IP_PRI84_SHIFT                      4
#define NVIC_IP_PRI84(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI84_SHIFT))&NVIC_IP_PRI84_MASK)
#define NVIC_IP_PRI85_MASK                       0xF0u
#define NVIC_IP_PRI85_SHIFT                      4
#define NVIC_IP_PRI85(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI85_SHIFT))&NVIC_IP_PRI85_MASK)
#define NVIC_IP_PRI86_MASK                       0xF0u
#define NVIC_IP_PRI86_SHIFT                      4
#define NVIC_IP_PRI86(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI86_SHIFT))&NVIC_IP_PRI86_MASK)
#define NVIC_IP_PRI87_MASK                       0xF0u
#define NVIC_IP_PRI87_SHIFT                      4
#define NVIC_IP_PRI87(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI87_SHIFT))&NVIC_IP_PRI87_MASK)
#define NVIC_IP_PRI88_MASK                       0xF0u
#define NVIC_IP_PRI88_SHIFT                      4
#define NVIC_IP_PRI88(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI88_SHIFT))&NVIC_IP_PRI88_MASK)
#define NVIC_IP_PRI89_MASK                       0xF0u
#define NVIC_IP_PRI89_SHIFT                      4
#define NVIC_IP_PRI89(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI89_SHIFT))&NVIC_IP_PRI89_MASK)
#define NVIC_IP_PRI90_MASK                       0xF0u
#define NVIC_IP_PRI90_SHIFT                      4
#define NVIC_IP_PRI90(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI90_SHIFT))&NVIC_IP_PRI90_MASK)
#define NVIC_IP_PRI91_MASK                       0xF0u
#define NVIC_IP_PRI91_SHIFT                      4
#define NVIC_IP_PRI91(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI91_SHIFT))&NVIC_IP_PRI91_MASK)
#define NVIC_IP_PRI92_MASK                       0xF0u
#define NVIC_IP_PRI92_SHIFT                      4
#define NVIC_IP_PRI92(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI92_SHIFT))&NVIC_IP_PRI92_MASK)
#define NVIC_IP_PRI93_MASK                       0xF0u
#define NVIC_IP_PRI93_SHIFT                      4
#define NVIC_IP_PRI93(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI93_SHIFT))&NVIC_IP_PRI93_MASK)
#define NVIC_IP_PRI94_MASK                       0xF0u
#define NVIC_IP_PRI94_SHIFT                      4
#define NVIC_IP_PRI94(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI94_SHIFT))&NVIC_IP_PRI94_MASK)
#define NVIC_IP_PRI95_MASK                       0xF0u
#define NVIC_IP_PRI95_SHIFT                      4
#define NVIC_IP_PRI95(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI95_SHIFT))&NVIC_IP_PRI95_MASK)
#define NVIC_IP_PRI96_MASK                       0xF0u
#define NVIC_IP_PRI96_SHIFT                      4
#define NVIC_IP_PRI96(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI96_SHIFT))&NVIC_IP_PRI96_MASK)
#define NVIC_IP_PRI97_MASK                       0xF0u
#define NVIC_IP_PRI97_SHIFT                      4
#define NVIC_IP_PRI97(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI97_SHIFT))&NVIC_IP_PRI97_MASK)
#define NVIC_IP_PRI98_MASK                       0xF0u
#define NVIC_IP_PRI98_SHIFT                      4
#define NVIC_IP_PRI98(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI98_SHIFT))&NVIC_IP_PRI98_MASK)
#define NVIC_IP_PRI99_MASK                       0xF0u
#define NVIC_IP_PRI99_SHIFT                      4
#define NVIC_IP_PRI99(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI99_SHIFT))&NVIC_IP_PRI99_MASK)
#define NVIC_IP_PRI100_MASK                      0xF0u
#define NVIC_IP_PRI100_SHIFT                     4
#define NVIC_IP_PRI100(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI100_SHIFT))&NVIC_IP_PRI100_MASK)
#define NVIC_IP_PRI101_MASK                      0xF0u
#define NVIC_IP_PRI101_SHIFT                     4
#define NVIC_IP_PRI101(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI101_SHIFT))&NVIC_IP_PRI101_MASK)
#define NVIC_IP_PRI102_MASK                      0xF0u
#define NVIC_IP_PRI102_SHIFT                     4
#define NVIC_IP_PRI102(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI102_SHIFT))&NVIC_IP_PRI102_MASK)
#define NVIC_IP_PRI103_MASK                      0xF0u
#define NVIC_IP_PRI103_SHIFT                     4
#define NVIC_IP_PRI103(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI103_SHIFT))&NVIC_IP_PRI103_MASK)
#define NVIC_IP_PRI104_MASK                      0xF0u
#define NVIC_IP_PRI104_SHIFT                     4
#define NVIC_IP_PRI104(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI104_SHIFT))&NVIC_IP_PRI104_MASK)
#define NVIC_IP_PRI105_MASK                      0xF0u
#define NVIC_IP_PRI105_SHIFT                     4
#define NVIC_IP_PRI105(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI105_SHIFT))&NVIC_IP_PRI105_MASK)
/* STIR Bit Fields */
#define NVIC_STIR_INTID_MASK                     0x1FFu
#define NVIC_STIR_INTID_SHIFT                    0
#define NVIC_STIR_INTID(x)                       (((uint32_t)(((uint32_t)(x))<<NVIC_STIR_INTID_SHIFT))&NVIC_STIR_INTID_MASK)

/*!
 * @}
 */ /* end of group NVIC_Register_Masks */


/* NVIC - Peripheral instance base addresses */
/** Peripheral NVIC base pointer */
#define NVIC_BASE_PTR                            ((NVIC_MemMapPtr)0xE000E100u)
/** Array initializer of NVIC peripheral base pointers */
#define NVIC_BASE_PTRS                           { NVIC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register instance definitions */
/* NVIC */
#define NVICISER0                                NVIC_ISER_REG(NVIC_BASE_PTR,0)
#define NVICISER1                                NVIC_ISER_REG(NVIC_BASE_PTR,1)
#define NVICISER2                                NVIC_ISER_REG(NVIC_BASE_PTR,2)
#define NVICISER3                                NVIC_ISER_REG(NVIC_BASE_PTR,3)
#define NVICICER0                                NVIC_ICER_REG(NVIC_BASE_PTR,0)
#define NVICICER1                                NVIC_ICER_REG(NVIC_BASE_PTR,1)
#define NVICICER2                                NVIC_ICER_REG(NVIC_BASE_PTR,2)
#define NVICICER3                                NVIC_ICER_REG(NVIC_BASE_PTR,3)
#define NVICISPR0                                NVIC_ISPR_REG(NVIC_BASE_PTR,0)
#define NVICISPR1                                NVIC_ISPR_REG(NVIC_BASE_PTR,1)
#define NVICISPR2                                NVIC_ISPR_REG(NVIC_BASE_PTR,2)
#define NVICISPR3                                NVIC_ISPR_REG(NVIC_BASE_PTR,3)
#define NVICICPR0                                NVIC_ICPR_REG(NVIC_BASE_PTR,0)
#define NVICICPR1                                NVIC_ICPR_REG(NVIC_BASE_PTR,1)
#define NVICICPR2                                NVIC_ICPR_REG(NVIC_BASE_PTR,2)
#define NVICICPR3                                NVIC_ICPR_REG(NVIC_BASE_PTR,3)
#define NVICIABR0                                NVIC_IABR_REG(NVIC_BASE_PTR,0)
#define NVICIABR1                                NVIC_IABR_REG(NVIC_BASE_PTR,1)
#define NVICIABR2                                NVIC_IABR_REG(NVIC_BASE_PTR,2)
#define NVICIABR3                                NVIC_IABR_REG(NVIC_BASE_PTR,3)
#define NVICIP0                                  NVIC_IP_REG(NVIC_BASE_PTR,0)
#define NVICIP1                                  NVIC_IP_REG(NVIC_BASE_PTR,1)
#define NVICIP2                                  NVIC_IP_REG(NVIC_BASE_PTR,2)
#define NVICIP3                                  NVIC_IP_REG(NVIC_BASE_PTR,3)
#define NVICIP4                                  NVIC_IP_REG(NVIC_BASE_PTR,4)
#define NVICIP5                                  NVIC_IP_REG(NVIC_BASE_PTR,5)
#define NVICIP6                                  NVIC_IP_REG(NVIC_BASE_PTR,6)
#define NVICIP7                                  NVIC_IP_REG(NVIC_BASE_PTR,7)
#define NVICIP8                                  NVIC_IP_REG(NVIC_BASE_PTR,8)
#define NVICIP9                                  NVIC_IP_REG(NVIC_BASE_PTR,9)
#define NVICIP10                                 NVIC_IP_REG(NVIC_BASE_PTR,10)
#define NVICIP11                                 NVIC_IP_REG(NVIC_BASE_PTR,11)
#define NVICIP12                                 NVIC_IP_REG(NVIC_BASE_PTR,12)
#define NVICIP13                                 NVIC_IP_REG(NVIC_BASE_PTR,13)
#define NVICIP14                                 NVIC_IP_REG(NVIC_BASE_PTR,14)
#define NVICIP15                                 NVIC_IP_REG(NVIC_BASE_PTR,15)
#define NVICIP16                                 NVIC_IP_REG(NVIC_BASE_PTR,16)
#define NVICIP17                                 NVIC_IP_REG(NVIC_BASE_PTR,17)
#define NVICIP18                                 NVIC_IP_REG(NVIC_BASE_PTR,18)
#define NVICIP19                                 NVIC_IP_REG(NVIC_BASE_PTR,19)
#define NVICIP20                                 NVIC_IP_REG(NVIC_BASE_PTR,20)
#define NVICIP21                                 NVIC_IP_REG(NVIC_BASE_PTR,21)
#define NVICIP22                                 NVIC_IP_REG(NVIC_BASE_PTR,22)
#define NVICIP23                                 NVIC_IP_REG(NVIC_BASE_PTR,23)
#define NVICIP24                                 NVIC_IP_REG(NVIC_BASE_PTR,24)
#define NVICIP25                                 NVIC_IP_REG(NVIC_BASE_PTR,25)
#define NVICIP26                                 NVIC_IP_REG(NVIC_BASE_PTR,26)
#define NVICIP27                                 NVIC_IP_REG(NVIC_BASE_PTR,27)
#define NVICIP28                                 NVIC_IP_REG(NVIC_BASE_PTR,28)
#define NVICIP29                                 NVIC_IP_REG(NVIC_BASE_PTR,29)
#define NVICIP30                                 NVIC_IP_REG(NVIC_BASE_PTR,30)
#define NVICIP31                                 NVIC_IP_REG(NVIC_BASE_PTR,31)
#define NVICIP32                                 NVIC_IP_REG(NVIC_BASE_PTR,32)
#define NVICIP33                                 NVIC_IP_REG(NVIC_BASE_PTR,33)
#define NVICIP34                                 NVIC_IP_REG(NVIC_BASE_PTR,34)
#define NVICIP35                                 NVIC_IP_REG(NVIC_BASE_PTR,35)
#define NVICIP36                                 NVIC_IP_REG(NVIC_BASE_PTR,36)
#define NVICIP37                                 NVIC_IP_REG(NVIC_BASE_PTR,37)
#define NVICIP38                                 NVIC_IP_REG(NVIC_BASE_PTR,38)
#define NVICIP39                                 NVIC_IP_REG(NVIC_BASE_PTR,39)
#define NVICIP40                                 NVIC_IP_REG(NVIC_BASE_PTR,40)
#define NVICIP41                                 NVIC_IP_REG(NVIC_BASE_PTR,41)
#define NVICIP42                                 NVIC_IP_REG(NVIC_BASE_PTR,42)
#define NVICIP43                                 NVIC_IP_REG(NVIC_BASE_PTR,43)
#define NVICIP44                                 NVIC_IP_REG(NVIC_BASE_PTR,44)
#define NVICIP45                                 NVIC_IP_REG(NVIC_BASE_PTR,45)
#define NVICIP46                                 NVIC_IP_REG(NVIC_BASE_PTR,46)
#define NVICIP47                                 NVIC_IP_REG(NVIC_BASE_PTR,47)
#define NVICIP48                                 NVIC_IP_REG(NVIC_BASE_PTR,48)
#define NVICIP49                                 NVIC_IP_REG(NVIC_BASE_PTR,49)
#define NVICIP50                                 NVIC_IP_REG(NVIC_BASE_PTR,50)
#define NVICIP51                                 NVIC_IP_REG(NVIC_BASE_PTR,51)
#define NVICIP52                                 NVIC_IP_REG(NVIC_BASE_PTR,52)
#define NVICIP53                                 NVIC_IP_REG(NVIC_BASE_PTR,53)
#define NVICIP54                                 NVIC_IP_REG(NVIC_BASE_PTR,54)
#define NVICIP55                                 NVIC_IP_REG(NVIC_BASE_PTR,55)
#define NVICIP56                                 NVIC_IP_REG(NVIC_BASE_PTR,56)
#define NVICIP57                                 NVIC_IP_REG(NVIC_BASE_PTR,57)
#define NVICIP58                                 NVIC_IP_REG(NVIC_BASE_PTR,58)
#define NVICIP59                                 NVIC_IP_REG(NVIC_BASE_PTR,59)
#define NVICIP60                                 NVIC_IP_REG(NVIC_BASE_PTR,60)
#define NVICIP61                                 NVIC_IP_REG(NVIC_BASE_PTR,61)
#define NVICIP62                                 NVIC_IP_REG(NVIC_BASE_PTR,62)
#define NVICIP63                                 NVIC_IP_REG(NVIC_BASE_PTR,63)
#define NVICIP64                                 NVIC_IP_REG(NVIC_BASE_PTR,64)
#define NVICIP65                                 NVIC_IP_REG(NVIC_BASE_PTR,65)
#define NVICIP66                                 NVIC_IP_REG(NVIC_BASE_PTR,66)
#define NVICIP67                                 NVIC_IP_REG(NVIC_BASE_PTR,67)
#define NVICIP68                                 NVIC_IP_REG(NVIC_BASE_PTR,68)
#define NVICIP69                                 NVIC_IP_REG(NVIC_BASE_PTR,69)
#define NVICIP70                                 NVIC_IP_REG(NVIC_BASE_PTR,70)
#define NVICIP71                                 NVIC_IP_REG(NVIC_BASE_PTR,71)
#define NVICIP72                                 NVIC_IP_REG(NVIC_BASE_PTR,72)
#define NVICIP73                                 NVIC_IP_REG(NVIC_BASE_PTR,73)
#define NVICIP74                                 NVIC_IP_REG(NVIC_BASE_PTR,74)
#define NVICIP75                                 NVIC_IP_REG(NVIC_BASE_PTR,75)
#define NVICIP76                                 NVIC_IP_REG(NVIC_BASE_PTR,76)
#define NVICIP77                                 NVIC_IP_REG(NVIC_BASE_PTR,77)
#define NVICIP78                                 NVIC_IP_REG(NVIC_BASE_PTR,78)
#define NVICIP79                                 NVIC_IP_REG(NVIC_BASE_PTR,79)
#define NVICIP80                                 NVIC_IP_REG(NVIC_BASE_PTR,80)
#define NVICIP81                                 NVIC_IP_REG(NVIC_BASE_PTR,81)
#define NVICIP82                                 NVIC_IP_REG(NVIC_BASE_PTR,82)
#define NVICIP83                                 NVIC_IP_REG(NVIC_BASE_PTR,83)
#define NVICIP84                                 NVIC_IP_REG(NVIC_BASE_PTR,84)
#define NVICIP85                                 NVIC_IP_REG(NVIC_BASE_PTR,85)
#define NVICIP86                                 NVIC_IP_REG(NVIC_BASE_PTR,86)
#define NVICIP87                                 NVIC_IP_REG(NVIC_BASE_PTR,87)
#define NVICIP88                                 NVIC_IP_REG(NVIC_BASE_PTR,88)
#define NVICIP89                                 NVIC_IP_REG(NVIC_BASE_PTR,89)
#define NVICIP90                                 NVIC_IP_REG(NVIC_BASE_PTR,90)
#define NVICIP91                                 NVIC_IP_REG(NVIC_BASE_PTR,91)
#define NVICIP92                                 NVIC_IP_REG(NVIC_BASE_PTR,92)
#define NVICIP93                                 NVIC_IP_REG(NVIC_BASE_PTR,93)
#define NVICIP94                                 NVIC_IP_REG(NVIC_BASE_PTR,94)
#define NVICIP95                                 NVIC_IP_REG(NVIC_BASE_PTR,95)
#define NVICIP96                                 NVIC_IP_REG(NVIC_BASE_PTR,96)
#define NVICIP97                                 NVIC_IP_REG(NVIC_BASE_PTR,97)
#define NVICIP98                                 NVIC_IP_REG(NVIC_BASE_PTR,98)
#define NVICIP99                                 NVIC_IP_REG(NVIC_BASE_PTR,99)
#define NVICIP100                                NVIC_IP_REG(NVIC_BASE_PTR,100)
#define NVICIP101                                NVIC_IP_REG(NVIC_BASE_PTR,101)
#define NVICIP102                                NVIC_IP_REG(NVIC_BASE_PTR,102)
#define NVICIP103                                NVIC_IP_REG(NVIC_BASE_PTR,103)
#define NVICIP104                                NVIC_IP_REG(NVIC_BASE_PTR,104)
#define NVICIP105                                NVIC_IP_REG(NVIC_BASE_PTR,105)
#define NVICSTIR                                 NVIC_STIR_REG(NVIC_BASE_PTR,0)

/* NVIC - Register array accessors */
#define NVIC_ISER(index)                         NVIC_ISER_REG(NVIC_BASE_PTR,index)
#define NVIC_ICER(index)                         NVIC_ICER_REG(NVIC_BASE_PTR,index)
#define NVIC_ISPR(index)                         NVIC_ISPR_REG(NVIC_BASE_PTR,index)
#define NVIC_ICPR(index)                         NVIC_ICPR_REG(NVIC_BASE_PTR,index)
#define NVIC_IABR(index)                         NVIC_IABR_REG(NVIC_BASE_PTR,index)
#define NVIC_IP(index)                           NVIC_IP_REG(NVIC_BASE_PTR,index)
#define NVIC_STIR(index)                         NVIC_STIR_REG(NVIC_BASE_PTR,index)

/*!
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group NVIC_Peripheral */


/* ----------------------------------------------------------------------------
   -- OSC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral OSC
 * @{
 */

/** OSC - Peripheral register structure */
typedef struct OSC_MemMap {
  uint8_t CR;                                      /**< OSC Control Register, offset: 0x0 */
  uint8_t RESERVED_0[1];
  uint8_t DIV;                                     /**< OSC_DIV, offset: 0x2 */
} volatile *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)
#define OSC_DIV_REG(base)                        ((base)->DIV)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#define OSC_CR_SC16P_MASK                        0x1u
#define OSC_CR_SC16P_SHIFT                       0
#define OSC_CR_SC8P_MASK                         0x2u
#define OSC_CR_SC8P_SHIFT                        1
#define OSC_CR_SC4P_MASK                         0x4u
#define OSC_CR_SC4P_SHIFT                        2
#define OSC_CR_SC2P_MASK                         0x8u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSTEN_MASK                     0x20u
#define OSC_CR_EREFSTEN_SHIFT                    5
#define OSC_CR_ERCLKEN_MASK                      0x80u
#define OSC_CR_ERCLKEN_SHIFT                     7
/* DIV Bit Fields */
#define OSC_DIV_ERPS_MASK                        0xC0u
#define OSC_DIV_ERPS_SHIFT                       6
#define OSC_DIV_ERPS(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_DIV_ERPS_SHIFT))&OSC_DIV_ERPS_MASK)

/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base pointer */
#define OSC_BASE_PTR                             ((OSC_MemMapPtr)0x40065000u)
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register instance definitions */
/* OSC */
#define OSC_CR                                   OSC_CR_REG(OSC_BASE_PTR)
#define OSC_DIV                                  OSC_DIV_REG(OSC_BASE_PTR)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group OSC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PDB
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral PDB
 * @{
 */

/** PDB - Peripheral register structure */
typedef struct PDB_MemMap {
  uint32_t SC;                                     /**< Status and Control register, offset: 0x0 */
  uint32_t MOD;                                    /**< Modulus register, offset: 0x4 */
  uint32_t CNT;                                    /**< Counter register, offset: 0x8 */
  uint32_t IDLY;                                   /**< Interrupt Delay register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x10 */
    uint32_t C1;                                     /**< Channel n Control register 1, array offset: 0x10, array step: 0x10 */
    uint32_t S;                                      /**< Channel n Status register, array offset: 0x14, array step: 0x10 */
    uint32_t DLY[2];                                 /**< Channel n Delay 0 register..Channel n Delay 1 register, array offset: 0x18, array step: index*0x10, index2*0x4 */
  } CH[1];
  uint32_t CHDLY2[1];                              /**< Channel n Delay 2 register, array offset: 0x20, array step: 0x4 */
  uint32_t CHDLY3[1];                              /**< Channel n Delay 3 register, array offset: 0x24, array step: 0x4 */
  uint8_t RESERVED_0[296];
  struct {                                         /* offset: 0x150, array step: 0x8 */
    uint32_t INTC;                                   /**< DAC Interval Trigger n Control register, array offset: 0x150, array step: 0x8 */
    uint32_t INT;                                    /**< DAC Interval n register, array offset: 0x154, array step: 0x8 */
  } DAC_INT[1];
  uint8_t RESERVED_1[56];
  uint32_t POEN;                                   /**< Pulse-Out n Enable register, offset: 0x190 */
  uint32_t PODLY[4];                               /**< Pulse-Out n Delay register, array offset: 0x194, array step: 0x4 */
} volatile *PDB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register accessors */
#define PDB_SC_REG(base)                         ((base)->SC)
#define PDB_MOD_REG(base)                        ((base)->MOD)
#define PDB_CNT_REG(base)                        ((base)->CNT)
#define PDB_IDLY_REG(base)                       ((base)->IDLY)
#define PDB_C1_REG(base,index)                   ((base)->CH[index].C1)
#define PDB_S_REG(base,index)                    ((base)->CH[index].S)
#define PDB_DLY_REG(base,index,index2)           ((base)->CH[index].DLY[index2])
#define PDB_CHDLY2_REG(base,index)               ((base)->CHDLY2[index])
#define PDB_CHDLY3_REG(base,index)               ((base)->CHDLY3[index])
#define PDB_INTC_REG(base,index)                 ((base)->DAC_INT[index].INTC)
#define PDB_INT_REG(base,index)                  ((base)->DAC_INT[index].INT)
#define PDB_POEN_REG(base)                       ((base)->POEN)
#define PDB_PODLY_REG(base,index)                ((base)->PODLY[index])

/*!
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK)
/* C1 Bit Fields */
#define PDB_C1_EN_MASK                           0xFFu
#define PDB_C1_EN_SHIFT                          0
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          0xFF00u
#define PDB_C1_TOS_SHIFT                         8
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           0xFF0000u
#define PDB_C1_BB_SHIFT                          16
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK)
/* S Bit Fields */
#define PDB_S_ERR_MASK                           0xFFu
#define PDB_S_ERR_SHIFT                          0
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            0xFF0000u
#define PDB_S_CF_SHIFT                           16
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK)
/* DLY Bit Fields */
#define PDB_DLY_DLY_MASK                         0xFFFFu
#define PDB_DLY_DLY_SHIFT                        0
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK)
/* CHDLY2 Bit Fields */
#define PDB_CHDLY2_DLY_MASK                      0xFFFFu
#define PDB_CHDLY2_DLY_SHIFT                     0
#define PDB_CHDLY2_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_CHDLY2_DLY_SHIFT))&PDB_CHDLY2_DLY_MASK)
/* CHDLY3 Bit Fields */
#define PDB_CHDLY3_DLY_MASK                      0xFFFFu
#define PDB_CHDLY3_DLY_SHIFT                     0
#define PDB_CHDLY3_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_CHDLY3_DLY_SHIFT))&PDB_CHDLY3_DLY_MASK)
/* INTC Bit Fields */
#define PDB_INTC_TOE_MASK                        0x1u
#define PDB_INTC_TOE_SHIFT                       0
#define PDB_INTC_EXT_MASK                        0x2u
#define PDB_INTC_EXT_SHIFT                       1
/* INT Bit Fields */
#define PDB_INT_INT_MASK                         0xFFFFu
#define PDB_INT_INT_SHIFT                        0
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK)
/* POEN Bit Fields */
#define PDB_POEN_POEN_MASK                       0xFFu
#define PDB_POEN_POEN_SHIFT                      0
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK)
/* PODLY Bit Fields */
#define PDB_PODLY_DLY2_MASK                      0xFFFFu
#define PDB_PODLY_DLY2_SHIFT                     0
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK)
#define PDB_PODLY_DLY1_MASK                      0xFFFF0000u
#define PDB_PODLY_DLY1_SHIFT                     16
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK)

/*!
 * @}
 */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base pointer */
#define PDB0_BASE_PTR                            ((PDB_MemMapPtr)0x40036000u)
/** Peripheral PDB1 base pointer */
#define PDB1_BASE_PTR                            ((PDB_MemMapPtr)0x40031000u)
/** Array initializer of PDB peripheral base pointers */
#define PDB_BASE_PTRS                            { PDB0_BASE_PTR, PDB1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register instance definitions */
/* PDB0 */
#define PDB0_SC                                  PDB_SC_REG(PDB0_BASE_PTR)
#define PDB0_MOD                                 PDB_MOD_REG(PDB0_BASE_PTR)
#define PDB0_CNT                                 PDB_CNT_REG(PDB0_BASE_PTR)
#define PDB0_IDLY                                PDB_IDLY_REG(PDB0_BASE_PTR)
#define PDB0_CH0C1                               PDB_C1_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0S                                PDB_S_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0DLY0                             PDB_DLY_REG(PDB0_BASE_PTR,0,0)
#define PDB0_CH0DLY1                             PDB_DLY_REG(PDB0_BASE_PTR,0,1)
#define PDB0_CH0DLY2                             PDB_CHDLY2_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0DLY3                             PDB_CHDLY3_REG(PDB0_BASE_PTR,0)
#define PDB0_DACINTC0                            PDB_INTC_REG(PDB0_BASE_PTR,0)
#define PDB0_DACINT0                             PDB_INT_REG(PDB0_BASE_PTR,0)
#define PDB0_POEN                                PDB_POEN_REG(PDB0_BASE_PTR)
#define PDB0_PO0DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,0)
#define PDB0_PO1DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,1)
#define PDB0_PO2DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,2)
#define PDB0_PO3DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,3)
/* PDB1 */
#define PDB1_SC                                  PDB_SC_REG(PDB1_BASE_PTR)
#define PDB1_MOD                                 PDB_MOD_REG(PDB1_BASE_PTR)
#define PDB1_CNT                                 PDB_CNT_REG(PDB1_BASE_PTR)
#define PDB1_IDLY                                PDB_IDLY_REG(PDB1_BASE_PTR)
#define PDB1_CH0C1                               PDB_C1_REG(PDB1_BASE_PTR,0)
#define PDB1_CH0S                                PDB_S_REG(PDB1_BASE_PTR,0)
#define PDB1_CH0DLY0                             PDB_DLY_REG(PDB1_BASE_PTR,0,0)
#define PDB1_CH0DLY1                             PDB_DLY_REG(PDB1_BASE_PTR,0,1)
#define PDB1_CH0DLY2                             PDB_CHDLY2_REG(PDB1_BASE_PTR,0)
#define PDB1_CH0DLY3                             PDB_CHDLY3_REG(PDB1_BASE_PTR,0)
#define PDB1_DACINTC0                            PDB_INTC_REG(PDB1_BASE_PTR,0)
#define PDB1_DACINT0                             PDB_INT_REG(PDB1_BASE_PTR,0)
#define PDB1_POEN                                PDB_POEN_REG(PDB1_BASE_PTR)
#define PDB1_PO0DLY                              PDB_PODLY_REG(PDB1_BASE_PTR,0)
#define PDB1_PO1DLY                              PDB_PODLY_REG(PDB1_BASE_PTR,1)
#define PDB1_PO2DLY                              PDB_PODLY_REG(PDB1_BASE_PTR,2)
#define PDB1_PO3DLY                              PDB_PODLY_REG(PDB1_BASE_PTR,3)

/* PDB - Register array accessors */
#define PDB0_C1(index)                           PDB_C1_REG(PDB0_BASE_PTR,index)
#define PDB1_C1(index)                           PDB_C1_REG(PDB1_BASE_PTR,index)
#define PDB0_S(index)                            PDB_S_REG(PDB0_BASE_PTR,index)
#define PDB1_S(index)                            PDB_S_REG(PDB1_BASE_PTR,index)
#define PDB0_DLY(index,index2)                   PDB_DLY_REG(PDB0_BASE_PTR,index,index2)
#define PDB1_DLY(index,index2)                   PDB_DLY_REG(PDB1_BASE_PTR,index,index2)
#define PDB0_CHDLY2(index)                       PDB_CHDLY2_REG(PDB0_BASE_PTR,index)
#define PDB1_CHDLY2(index)                       PDB_CHDLY2_REG(PDB1_BASE_PTR,index)
#define PDB0_CHDLY3(index)                       PDB_CHDLY3_REG(PDB0_BASE_PTR,index)
#define PDB1_CHDLY3(index)                       PDB_CHDLY3_REG(PDB1_BASE_PTR,index)
#define PDB0_INTC(index)                         PDB_INTC_REG(PDB0_BASE_PTR,index)
#define PDB1_INTC(index)                         PDB_INTC_REG(PDB1_BASE_PTR,index)
#define PDB0_INT(index)                          PDB_INT_REG(PDB0_BASE_PTR,index)
#define PDB1_INT(index)                          PDB_INT_REG(PDB1_BASE_PTR,index)
#define PDB0_PODLY(index)                        PDB_PODLY_REG(PDB0_BASE_PTR,index)
#define PDB1_PODLY(index)                        PDB_PODLY_REG(PDB1_BASE_PTR,index)

/*!
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PDB_Peripheral */


/* ----------------------------------------------------------------------------
   -- PIT
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral PIT
 * @{
 */

/** PIT - Peripheral register structure */
typedef struct PIT_MemMap {
  uint32_t MCR;                                    /**< PIT Module Control Register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    uint32_t LDVAL;                                  /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    uint32_t CVAL;                                   /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    uint32_t TCTRL;                                  /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    uint32_t TFLG;                                   /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register accessors */
#define PIT_MCR_REG(base)                        ((base)->MCR)
#define PIT_LDVAL_REG(base,index)                ((base)->CHANNEL[index].LDVAL)
#define PIT_CVAL_REG(base,index)                 ((base)->CHANNEL[index].CVAL)
#define PIT_TCTRL_REG(base,index)                ((base)->CHANNEL[index].TCTRL)
#define PIT_TFLG_REG(base,index)                 ((base)->CHANNEL[index].TFLG)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/* MCR Bit Fields */
#define PIT_MCR_FRZ_MASK                         0x1u
#define PIT_MCR_FRZ_SHIFT                        0
#define PIT_MCR_MDIS_MASK                        0x2u
#define PIT_MCR_MDIS_SHIFT                       1
/* LDVAL Bit Fields */
#define PIT_LDVAL_TSV_MASK                       0xFFFFFFFFu
#define PIT_LDVAL_TSV_SHIFT                      0
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK)
/* CVAL Bit Fields */
#define PIT_CVAL_TVL_MASK                        0xFFFFFFFFu
#define PIT_CVAL_TVL_SHIFT                       0
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK)
/* TCTRL Bit Fields */
#define PIT_TCTRL_TEN_MASK                       0x1u
#define PIT_TCTRL_TEN_SHIFT                      0
#define PIT_TCTRL_TIE_MASK                       0x2u
#define PIT_TCTRL_TIE_SHIFT                      1
#define PIT_TCTRL_CHN_MASK                       0x4u
#define PIT_TCTRL_CHN_SHIFT                      2
/* TFLG Bit Fields */
#define PIT_TFLG_TIF_MASK                        0x1u
#define PIT_TFLG_TIF_SHIFT                       0

/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base pointer */
#define PIT_BASE_PTR                             ((PIT_MemMapPtr)0x40037000u)
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register instance definitions */
/* PIT */
#define PIT_MCR                                  PIT_MCR_REG(PIT_BASE_PTR)
#define PIT_LDVAL0                               PIT_LDVAL_REG(PIT_BASE_PTR,0)
#define PIT_CVAL0                                PIT_CVAL_REG(PIT_BASE_PTR,0)
#define PIT_TCTRL0                               PIT_TCTRL_REG(PIT_BASE_PTR,0)
#define PIT_TFLG0                                PIT_TFLG_REG(PIT_BASE_PTR,0)
#define PIT_LDVAL1                               PIT_LDVAL_REG(PIT_BASE_PTR,1)
#define PIT_CVAL1                                PIT_CVAL_REG(PIT_BASE_PTR,1)
#define PIT_TCTRL1                               PIT_TCTRL_REG(PIT_BASE_PTR,1)
#define PIT_TFLG1                                PIT_TFLG_REG(PIT_BASE_PTR,1)
#define PIT_LDVAL2                               PIT_LDVAL_REG(PIT_BASE_PTR,2)
#define PIT_CVAL2                                PIT_CVAL_REG(PIT_BASE_PTR,2)
#define PIT_TCTRL2                               PIT_TCTRL_REG(PIT_BASE_PTR,2)
#define PIT_TFLG2                                PIT_TFLG_REG(PIT_BASE_PTR,2)
#define PIT_LDVAL3                               PIT_LDVAL_REG(PIT_BASE_PTR,3)
#define PIT_CVAL3                                PIT_CVAL_REG(PIT_BASE_PTR,3)
#define PIT_TCTRL3                               PIT_TCTRL_REG(PIT_BASE_PTR,3)
#define PIT_TFLG3                                PIT_TFLG_REG(PIT_BASE_PTR,3)

/* PIT - Register array accessors */
#define PIT_LDVAL(index)                         PIT_LDVAL_REG(PIT_BASE_PTR,index)
#define PIT_CVAL(index)                          PIT_CVAL_REG(PIT_BASE_PTR,index)
#define PIT_TCTRL(index)                         PIT_TCTRL_REG(PIT_BASE_PTR,index)
#define PIT_TFLG(index)                          PIT_TFLG_REG(PIT_BASE_PTR,index)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PIT_Peripheral */


/* ----------------------------------------------------------------------------
   -- PMC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral PMC
 * @{
 */

/** PMC - Peripheral register structure */
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                  /**< Low Voltage Detect Status And Control 1 register, offset: 0x0 */
  uint8_t LVDSC2;                                  /**< Low Voltage Detect Status And Control 2 register, offset: 0x1 */
  uint8_t REGSC;                                   /**< Regulator Status And Control register, offset: 0x2 */
} volatile *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */
#define PMC_LVDSC1_REG(base)                     ((base)->LVDSC1)
#define PMC_LVDSC2_REG(base)                     ((base)->LVDSC2)
#define PMC_REGSC_REG(base)                      ((base)->REGSC)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_BGBDS_MASK                     0x2u
#define PMC_REGSC_BGBDS_SHIFT                    1
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_ACKISO_MASK                    0x8u
#define PMC_REGSC_ACKISO_SHIFT                   3
#define PMC_REGSC_BGEN_MASK                      0x10u
#define PMC_REGSC_BGEN_SHIFT                     4

/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base pointer */
#define PMC_BASE_PTR                             ((PMC_MemMapPtr)0x4007D000u)
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_LVDSC1                               PMC_LVDSC1_REG(PMC_BASE_PTR)
#define PMC_LVDSC2                               PMC_LVDSC2_REG(PMC_BASE_PTR)
#define PMC_REGSC                                PMC_REGSC_REG(PMC_BASE_PTR)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PORT
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral PORT
 * @{
 */

/** PORT - Peripheral register structure */
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  uint32_t GPCLR;                                  /**< Global Pin Control Low Register, offset: 0x80 */
  uint32_t GPCHR;                                  /**< Global Pin Control High Register, offset: 0x84 */
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                   /**< Interrupt Status Flag Register, offset: 0xA0 */
  uint8_t RESERVED_1[28];
  uint32_t DFER;                                   /**< Digital Filter Enable Register, offset: 0xC0 */
  uint32_t DFCR;                                   /**< Digital Filter Clock Register, offset: 0xC4 */
  uint32_t DFWR;                                   /**< Digital Filter Width Register, offset: 0xC8 */
} volatile *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#define PORT_PCR_REG(base,index)                 ((base)->PCR[index])
#define PORT_GPCLR_REG(base)                     ((base)->GPCLR)
#define PORT_GPCHR_REG(base)                     ((base)->GPCHR)
#define PORT_ISFR_REG(base)                      ((base)->ISFR)
#define PORT_DFER_REG(base)                      ((base)->DFER)
#define PORT_DFCR_REG(base)                      ((base)->DFCR)
#define PORT_DFWR_REG(base)                      ((base)->DFWR)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1
#define PORT_PCR_SRE_MASK                        0x4u
#define PORT_PCR_SRE_SHIFT                       2
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4
#define PORT_PCR_ODE_MASK                        0x20u
#define PORT_PCR_ODE_SHIFT                       5
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base pointer */
#define PORTA_BASE_PTR                           ((PORT_MemMapPtr)0x40049000u)
/** Peripheral PORTB base pointer */
#define PORTB_BASE_PTR                           ((PORT_MemMapPtr)0x4004A000u)
/** Peripheral PORTC base pointer */
#define PORTC_BASE_PTR                           ((PORT_MemMapPtr)0x4004B000u)
/** Peripheral PORTD base pointer */
#define PORTD_BASE_PTR                           ((PORT_MemMapPtr)0x4004C000u)
/** Peripheral PORTE base pointer */
#define PORTE_BASE_PTR                           ((PORT_MemMapPtr)0x4004D000u)
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORTA */
#define PORTA_PCR0                               PORT_PCR_REG(PORTA_BASE_PTR,0)
#define PORTA_PCR1                               PORT_PCR_REG(PORTA_BASE_PTR,1)
#define PORTA_PCR2                               PORT_PCR_REG(PORTA_BASE_PTR,2)
#define PORTA_PCR3                               PORT_PCR_REG(PORTA_BASE_PTR,3)
#define PORTA_PCR4                               PORT_PCR_REG(PORTA_BASE_PTR,4)
#define PORTA_PCR5                               PORT_PCR_REG(PORTA_BASE_PTR,5)
#define PORTA_PCR6                               PORT_PCR_REG(PORTA_BASE_PTR,6)
#define PORTA_PCR7                               PORT_PCR_REG(PORTA_BASE_PTR,7)
#define PORTA_PCR8                               PORT_PCR_REG(PORTA_BASE_PTR,8)
#define PORTA_PCR9                               PORT_PCR_REG(PORTA_BASE_PTR,9)
#define PORTA_PCR10                              PORT_PCR_REG(PORTA_BASE_PTR,10)
#define PORTA_PCR11                              PORT_PCR_REG(PORTA_BASE_PTR,11)
#define PORTA_PCR12                              PORT_PCR_REG(PORTA_BASE_PTR,12)
#define PORTA_PCR13                              PORT_PCR_REG(PORTA_BASE_PTR,13)
#define PORTA_PCR14                              PORT_PCR_REG(PORTA_BASE_PTR,14)
#define PORTA_PCR15                              PORT_PCR_REG(PORTA_BASE_PTR,15)
#define PORTA_PCR16                              PORT_PCR_REG(PORTA_BASE_PTR,16)
#define PORTA_PCR17                              PORT_PCR_REG(PORTA_BASE_PTR,17)
#define PORTA_PCR18                              PORT_PCR_REG(PORTA_BASE_PTR,18)
#define PORTA_PCR19                              PORT_PCR_REG(PORTA_BASE_PTR,19)
#define PORTA_PCR20                              PORT_PCR_REG(PORTA_BASE_PTR,20)
#define PORTA_PCR21                              PORT_PCR_REG(PORTA_BASE_PTR,21)
#define PORTA_PCR22                              PORT_PCR_REG(PORTA_BASE_PTR,22)
#define PORTA_PCR23                              PORT_PCR_REG(PORTA_BASE_PTR,23)
#define PORTA_PCR24                              PORT_PCR_REG(PORTA_BASE_PTR,24)
#define PORTA_PCR25                              PORT_PCR_REG(PORTA_BASE_PTR,25)
#define PORTA_PCR26                              PORT_PCR_REG(PORTA_BASE_PTR,26)
#define PORTA_PCR27                              PORT_PCR_REG(PORTA_BASE_PTR,27)
#define PORTA_PCR28                              PORT_PCR_REG(PORTA_BASE_PTR,28)
#define PORTA_PCR29                              PORT_PCR_REG(PORTA_BASE_PTR,29)
#define PORTA_PCR30                              PORT_PCR_REG(PORTA_BASE_PTR,30)
#define PORTA_PCR31                              PORT_PCR_REG(PORTA_BASE_PTR,31)
#define PORTA_GPCLR                              PORT_GPCLR_REG(PORTA_BASE_PTR)
#define PORTA_GPCHR                              PORT_GPCHR_REG(PORTA_BASE_PTR)
#define PORTA_ISFR                               PORT_ISFR_REG(PORTA_BASE_PTR)
/* PORTB */
#define PORTB_PCR0                               PORT_PCR_REG(PORTB_BASE_PTR,0)
#define PORTB_PCR1                               PORT_PCR_REG(PORTB_BASE_PTR,1)
#define PORTB_PCR2                               PORT_PCR_REG(PORTB_BASE_PTR,2)
#define PORTB_PCR3                               PORT_PCR_REG(PORTB_BASE_PTR,3)
#define PORTB_PCR4                               PORT_PCR_REG(PORTB_BASE_PTR,4)
#define PORTB_PCR5                               PORT_PCR_REG(PORTB_BASE_PTR,5)
#define PORTB_PCR6                               PORT_PCR_REG(PORTB_BASE_PTR,6)
#define PORTB_PCR7                               PORT_PCR_REG(PORTB_BASE_PTR,7)
#define PORTB_PCR8                               PORT_PCR_REG(PORTB_BASE_PTR,8)
#define PORTB_PCR9                               PORT_PCR_REG(PORTB_BASE_PTR,9)
#define PORTB_PCR10                              PORT_PCR_REG(PORTB_BASE_PTR,10)
#define PORTB_PCR11                              PORT_PCR_REG(PORTB_BASE_PTR,11)
#define PORTB_PCR12                              PORT_PCR_REG(PORTB_BASE_PTR,12)
#define PORTB_PCR13                              PORT_PCR_REG(PORTB_BASE_PTR,13)
#define PORTB_PCR14                              PORT_PCR_REG(PORTB_BASE_PTR,14)
#define PORTB_PCR15                              PORT_PCR_REG(PORTB_BASE_PTR,15)
#define PORTB_PCR16                              PORT_PCR_REG(PORTB_BASE_PTR,16)
#define PORTB_PCR17                              PORT_PCR_REG(PORTB_BASE_PTR,17)
#define PORTB_PCR18                              PORT_PCR_REG(PORTB_BASE_PTR,18)
#define PORTB_PCR19                              PORT_PCR_REG(PORTB_BASE_PTR,19)
#define PORTB_PCR20                              PORT_PCR_REG(PORTB_BASE_PTR,20)
#define PORTB_PCR21                              PORT_PCR_REG(PORTB_BASE_PTR,21)
#define PORTB_PCR22                              PORT_PCR_REG(PORTB_BASE_PTR,22)
#define PORTB_PCR23                              PORT_PCR_REG(PORTB_BASE_PTR,23)
#define PORTB_PCR24                              PORT_PCR_REG(PORTB_BASE_PTR,24)
#define PORTB_PCR25                              PORT_PCR_REG(PORTB_BASE_PTR,25)
#define PORTB_PCR26                              PORT_PCR_REG(PORTB_BASE_PTR,26)
#define PORTB_PCR27                              PORT_PCR_REG(PORTB_BASE_PTR,27)
#define PORTB_PCR28                              PORT_PCR_REG(PORTB_BASE_PTR,28)
#define PORTB_PCR29                              PORT_PCR_REG(PORTB_BASE_PTR,29)
#define PORTB_PCR30                              PORT_PCR_REG(PORTB_BASE_PTR,30)
#define PORTB_PCR31                              PORT_PCR_REG(PORTB_BASE_PTR,31)
#define PORTB_GPCLR                              PORT_GPCLR_REG(PORTB_BASE_PTR)
#define PORTB_GPCHR                              PORT_GPCHR_REG(PORTB_BASE_PTR)
#define PORTB_ISFR                               PORT_ISFR_REG(PORTB_BASE_PTR)
/* PORTC */
#define PORTC_PCR0                               PORT_PCR_REG(PORTC_BASE_PTR,0)
#define PORTC_PCR1                               PORT_PCR_REG(PORTC_BASE_PTR,1)
#define PORTC_PCR2                               PORT_PCR_REG(PORTC_BASE_PTR,2)
#define PORTC_PCR3                               PORT_PCR_REG(PORTC_BASE_PTR,3)
#define PORTC_PCR4                               PORT_PCR_REG(PORTC_BASE_PTR,4)
#define PORTC_PCR5                               PORT_PCR_REG(PORTC_BASE_PTR,5)
#define PORTC_PCR6                               PORT_PCR_REG(PORTC_BASE_PTR,6)
#define PORTC_PCR7                               PORT_PCR_REG(PORTC_BASE_PTR,7)
#define PORTC_PCR8                               PORT_PCR_REG(PORTC_BASE_PTR,8)
#define PORTC_PCR9                               PORT_PCR_REG(PORTC_BASE_PTR,9)
#define PORTC_PCR10                              PORT_PCR_REG(PORTC_BASE_PTR,10)
#define PORTC_PCR11                              PORT_PCR_REG(PORTC_BASE_PTR,11)
#define PORTC_PCR12                              PORT_PCR_REG(PORTC_BASE_PTR,12)
#define PORTC_PCR13                              PORT_PCR_REG(PORTC_BASE_PTR,13)
#define PORTC_PCR14                              PORT_PCR_REG(PORTC_BASE_PTR,14)
#define PORTC_PCR15                              PORT_PCR_REG(PORTC_BASE_PTR,15)
#define PORTC_PCR16                              PORT_PCR_REG(PORTC_BASE_PTR,16)
#define PORTC_PCR17                              PORT_PCR_REG(PORTC_BASE_PTR,17)
#define PORTC_PCR18                              PORT_PCR_REG(PORTC_BASE_PTR,18)
#define PORTC_PCR19                              PORT_PCR_REG(PORTC_BASE_PTR,19)
#define PORTC_PCR20                              PORT_PCR_REG(PORTC_BASE_PTR,20)
#define PORTC_PCR21                              PORT_PCR_REG(PORTC_BASE_PTR,21)
#define PORTC_PCR22                              PORT_PCR_REG(PORTC_BASE_PTR,22)
#define PORTC_PCR23                              PORT_PCR_REG(PORTC_BASE_PTR,23)
#define PORTC_PCR24                              PORT_PCR_REG(PORTC_BASE_PTR,24)
#define PORTC_PCR25                              PORT_PCR_REG(PORTC_BASE_PTR,25)
#define PORTC_PCR26                              PORT_PCR_REG(PORTC_BASE_PTR,26)
#define PORTC_PCR27                              PORT_PCR_REG(PORTC_BASE_PTR,27)
#define PORTC_PCR28                              PORT_PCR_REG(PORTC_BASE_PTR,28)
#define PORTC_PCR29                              PORT_PCR_REG(PORTC_BASE_PTR,29)
#define PORTC_PCR30                              PORT_PCR_REG(PORTC_BASE_PTR,30)
#define PORTC_PCR31                              PORT_PCR_REG(PORTC_BASE_PTR,31)
#define PORTC_GPCLR                              PORT_GPCLR_REG(PORTC_BASE_PTR)
#define PORTC_GPCHR                              PORT_GPCHR_REG(PORTC_BASE_PTR)
#define PORTC_ISFR                               PORT_ISFR_REG(PORTC_BASE_PTR)
/* PORTD */
#define PORTD_PCR0                               PORT_PCR_REG(PORTD_BASE_PTR,0)
#define PORTD_PCR1                               PORT_PCR_REG(PORTD_BASE_PTR,1)
#define PORTD_PCR2                               PORT_PCR_REG(PORTD_BASE_PTR,2)
#define PORTD_PCR3                               PORT_PCR_REG(PORTD_BASE_PTR,3)
#define PORTD_PCR4                               PORT_PCR_REG(PORTD_BASE_PTR,4)
#define PORTD_PCR5                               PORT_PCR_REG(PORTD_BASE_PTR,5)
#define PORTD_PCR6                               PORT_PCR_REG(PORTD_BASE_PTR,6)
#define PORTD_PCR7                               PORT_PCR_REG(PORTD_BASE_PTR,7)
#define PORTD_PCR8                               PORT_PCR_REG(PORTD_BASE_PTR,8)
#define PORTD_PCR9                               PORT_PCR_REG(PORTD_BASE_PTR,9)
#define PORTD_PCR10                              PORT_PCR_REG(PORTD_BASE_PTR,10)
#define PORTD_PCR11                              PORT_PCR_REG(PORTD_BASE_PTR,11)
#define PORTD_PCR12                              PORT_PCR_REG(PORTD_BASE_PTR,12)
#define PORTD_PCR13                              PORT_PCR_REG(PORTD_BASE_PTR,13)
#define PORTD_PCR14                              PORT_PCR_REG(PORTD_BASE_PTR,14)
#define PORTD_PCR15                              PORT_PCR_REG(PORTD_BASE_PTR,15)
#define PORTD_PCR16                              PORT_PCR_REG(PORTD_BASE_PTR,16)
#define PORTD_PCR17                              PORT_PCR_REG(PORTD_BASE_PTR,17)
#define PORTD_PCR18                              PORT_PCR_REG(PORTD_BASE_PTR,18)
#define PORTD_PCR19                              PORT_PCR_REG(PORTD_BASE_PTR,19)
#define PORTD_PCR20                              PORT_PCR_REG(PORTD_BASE_PTR,20)
#define PORTD_PCR21                              PORT_PCR_REG(PORTD_BASE_PTR,21)
#define PORTD_PCR22                              PORT_PCR_REG(PORTD_BASE_PTR,22)
#define PORTD_PCR23                              PORT_PCR_REG(PORTD_BASE_PTR,23)
#define PORTD_PCR24                              PORT_PCR_REG(PORTD_BASE_PTR,24)
#define PORTD_PCR25                              PORT_PCR_REG(PORTD_BASE_PTR,25)
#define PORTD_PCR26                              PORT_PCR_REG(PORTD_BASE_PTR,26)
#define PORTD_PCR27                              PORT_PCR_REG(PORTD_BASE_PTR,27)
#define PORTD_PCR28                              PORT_PCR_REG(PORTD_BASE_PTR,28)
#define PORTD_PCR29                              PORT_PCR_REG(PORTD_BASE_PTR,29)
#define PORTD_PCR30                              PORT_PCR_REG(PORTD_BASE_PTR,30)
#define PORTD_PCR31                              PORT_PCR_REG(PORTD_BASE_PTR,31)
#define PORTD_GPCLR                              PORT_GPCLR_REG(PORTD_BASE_PTR)
#define PORTD_GPCHR                              PORT_GPCHR_REG(PORTD_BASE_PTR)
#define PORTD_ISFR                               PORT_ISFR_REG(PORTD_BASE_PTR)
#define PORTD_DFER                               PORT_DFER_REG(PORTD_BASE_PTR)
#define PORTD_DFCR                               PORT_DFCR_REG(PORTD_BASE_PTR)
#define PORTD_DFWR                               PORT_DFWR_REG(PORTD_BASE_PTR)
/* PORTE */
#define PORTE_PCR0                               PORT_PCR_REG(PORTE_BASE_PTR,0)
#define PORTE_PCR1                               PORT_PCR_REG(PORTE_BASE_PTR,1)
#define PORTE_PCR2                               PORT_PCR_REG(PORTE_BASE_PTR,2)
#define PORTE_PCR3                               PORT_PCR_REG(PORTE_BASE_PTR,3)
#define PORTE_PCR4                               PORT_PCR_REG(PORTE_BASE_PTR,4)
#define PORTE_PCR5                               PORT_PCR_REG(PORTE_BASE_PTR,5)
#define PORTE_PCR6                               PORT_PCR_REG(PORTE_BASE_PTR,6)
#define PORTE_PCR7                               PORT_PCR_REG(PORTE_BASE_PTR,7)
#define PORTE_PCR8                               PORT_PCR_REG(PORTE_BASE_PTR,8)
#define PORTE_PCR9                               PORT_PCR_REG(PORTE_BASE_PTR,9)
#define PORTE_PCR10                              PORT_PCR_REG(PORTE_BASE_PTR,10)
#define PORTE_PCR11                              PORT_PCR_REG(PORTE_BASE_PTR,11)
#define PORTE_PCR12                              PORT_PCR_REG(PORTE_BASE_PTR,12)
#define PORTE_PCR13                              PORT_PCR_REG(PORTE_BASE_PTR,13)
#define PORTE_PCR14                              PORT_PCR_REG(PORTE_BASE_PTR,14)
#define PORTE_PCR15                              PORT_PCR_REG(PORTE_BASE_PTR,15)
#define PORTE_PCR16                              PORT_PCR_REG(PORTE_BASE_PTR,16)
#define PORTE_PCR17                              PORT_PCR_REG(PORTE_BASE_PTR,17)
#define PORTE_PCR18                              PORT_PCR_REG(PORTE_BASE_PTR,18)
#define PORTE_PCR19                              PORT_PCR_REG(PORTE_BASE_PTR,19)
#define PORTE_PCR20                              PORT_PCR_REG(PORTE_BASE_PTR,20)
#define PORTE_PCR21                              PORT_PCR_REG(PORTE_BASE_PTR,21)
#define PORTE_PCR22                              PORT_PCR_REG(PORTE_BASE_PTR,22)
#define PORTE_PCR23                              PORT_PCR_REG(PORTE_BASE_PTR,23)
#define PORTE_PCR24                              PORT_PCR_REG(PORTE_BASE_PTR,24)
#define PORTE_PCR25                              PORT_PCR_REG(PORTE_BASE_PTR,25)
#define PORTE_PCR26                              PORT_PCR_REG(PORTE_BASE_PTR,26)
#define PORTE_PCR27                              PORT_PCR_REG(PORTE_BASE_PTR,27)
#define PORTE_PCR28                              PORT_PCR_REG(PORTE_BASE_PTR,28)
#define PORTE_PCR29                              PORT_PCR_REG(PORTE_BASE_PTR,29)
#define PORTE_PCR30                              PORT_PCR_REG(PORTE_BASE_PTR,30)
#define PORTE_PCR31                              PORT_PCR_REG(PORTE_BASE_PTR,31)
#define PORTE_GPCLR                              PORT_GPCLR_REG(PORTE_BASE_PTR)
#define PORTE_GPCHR                              PORT_GPCHR_REG(PORTE_BASE_PTR)
#define PORTE_ISFR                               PORT_ISFR_REG(PORTE_BASE_PTR)

/* PORT - Register array accessors */
#define PORTA_PCR(index)                         PORT_PCR_REG(PORTA_BASE_PTR,index)
#define PORTB_PCR(index)                         PORT_PCR_REG(PORTB_BASE_PTR,index)
#define PORTC_PCR(index)                         PORT_PCR_REG(PORTC_BASE_PTR,index)
#define PORTD_PCR(index)                         PORT_PCR_REG(PORTD_BASE_PTR,index)
#define PORTE_PCR(index)                         PORT_PCR_REG(PORTE_BASE_PTR,index)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PORT_Peripheral */


/* ----------------------------------------------------------------------------
   -- PWM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Peripheral PWM
 * @{
 */

/** PWM - Peripheral register structure */
typedef struct PWM_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x60 */
    uint16_t CNT;                                    /**< Counter Register, array offset: 0x0, array step: 0x60 */
    uint16_t INIT;                                   /**< Initial Count Register, array offset: 0x2, array step: 0x60 */
    uint16_t CTRL2;                                  /**< Control 2 Register, array offset: 0x4, array step: 0x60 */
    uint16_t CTRL;                                   /**< Control Register, array offset: 0x6, array step: 0x60 */
    uint8_t RESERVED_0[2];
    uint16_t VAL0;                                   /**< Value Register 0, array offset: 0xA, array step: 0x60 */
    uint16_t FRACVAL1;                               /**< Fractional Value Register 1, array offset: 0xC, array step: 0x60 */
    uint16_t VAL1;                                   /**< Value Register 1, array offset: 0xE, array step: 0x60 */
    uint16_t FRACVAL2;                               /**< Fractional Value Register 2, array offset: 0x10, array step: 0x60 */
    uint16_t VAL2;                                   /**< Value Register 2, array offset: 0x12, array step: 0x60 */
    uint16_t FRACVAL3;                               /**< Fractional Value Register 3, array offset: 0x14, array step: 0x60 */
    uint16_t VAL3;                                   /**< Value Register 3, array offset: 0x16, array step: 0x60 */
    uint16_t FRACVAL4;                               /**< Fractional Value Register 4, array offset: 0x18, array step: 0x60 */
    uint16_t VAL4;                                   /**< Value Register 4, array offset: 0x1A, array step: 0x60 */
    uint16_t FRACVAL5;                               /**< Fractional Value Register 5, array offset: 0x1C, array step: 0x60 */
    uint16_t VAL5;                                   /**< Value Register 5, array offset: 0x1E, array step: 0x60 */
    uint16_t FRCTRL;                                 /**< Fractional Control Register, array offset: 0x20, array step: 0x60 */
    uint16_t OCTRL;                                  /**< Output Control Register, array offset: 0x22, array step: 0x60 */
    uint16_t STS;                                    /**< Status Register, array offset: 0x24, array step: 0x60 */
    uint16_t INTEN;                                  /**< Interrupt Enable Register, array offset: 0x26, array step: 0x60 */
    uint16_t DMAEN;                                  /**< DMA Enable Register, array offset: 0x28, array step: 0x60 */
    uint16_t TCTRL;                                  /**< Output Trigger Control Register, array offset: 0x2A, array step: 0x60 */
    uint16_t DISMAP[1];                              /**< Fault Disable Mapping Register 0, array offset: 0x2C, array step: index*0x60, index2*0x2 */
    uint8_t RESERVED_1[2];
    uint16_t DTCNT0;                                 /**< Deadtime Count Register 0, array offset: 0x30, array step: 0x60 */
    uint16_t DTCNT1;                                 /**< Deadtime Count Register 1, array offset: 0x32, array step: 0x60 */
    uint16_t CAPTCTRLA;                              /**< Capture Control A Register, array offset: 0x34, array step: 0x60 */
    uint16_t CAPTCOMPA;                              /**< Capture Compare A Register, array offset: 0x36, array step: 0x60 */
    uint16_t CAPTCTRLB;                              /**< Capture Control B Register, array offset: 0x38, array step: 0x60 */
    uint16_t CAPTCOMPB;                              /**< Capture Compare B Register, array offset: 0x3A, array step: 0x60 */
    uint16_t CAPTCTRLX;                              /**< Capture Control X Register, array offset: 0x3C, array step: 0x60 */
    uint16_t CAPTCOMPX;                              /**< Capture Compare X Register, array offset: 0x3E, array step: 0x60 */
    uint16_t CVAL0;                                  /**< Capture Value 0 Register, array offset: 0x40, array step: 0x60 */
    uint16_t CVAL0CYC;                               /**< Capture Value 0 Cycle Register, array offset: 0x42, array step: 0x60 */
    uint16_t CVAL1;                                  /**< Capture Value 1 Register, array offset: 0x44, array step: 0x60 */
    uint16_t CVAL1CYC;                               /**< Capture Value 1 Cycle Register, array offset: 0x46, array step: 0x60 */
    uint16_t CVAL2;                                  /**< Capture Value 2 Register, array offset: 0x48, array step: 0x60 */
    uint16_t CVAL2CYC;                               /**< Capture Value 2 Cycle Register, array offset: 0x4A, array step: 0x60 */
    uint16_t CVAL3;                                  /**< Capture Value 3 Register, array offset: 0x4C, array step: 0x60 */
    uint16_t CVAL3CYC;                               /**< Capture Value 3 Cycle Register, array offset: 0x4E, array step: 0x60 */
    uint16_t CVAL4;                                  /**< Capture Value 4 Register, array offset: 0x50, array step: 0x60 */
    uint16_t CVAL4CYC;                               /**< Capture Value 4 Cycle Register, array offset: 0x52, array step: 0x60 */
    uint16_t CVAL5;                                  /**< Capture Value 5 Register, array offset: 0x54, array step: 0x60 */
    uint16_t CVAL5CYC;                               /**< Capture Value 5 Cycle Register, array offset: 0x56, array step: 0x60 */
    uint8_t RESERVED_2[8];
  } SM[4];
  uint16_t OUTEN;                                  /**< Output Enable Register, offset: 0x180 */
  uint16_t MASK;                                   /**< Mask Register, offset: 0x182 */
  uint16_t SWCOUT;                                 /**< Software Controlled Output Register, offset: 0x184 */
  uint16_t DTSRCSEL;                               /**< PWM Source Select Register, offset: 0x186 */
  uint16_t MCTRL;                                  /**< Master Control Register, offset: 0x188 */
  uint16_t MCTRL2;                                 /**< Master Control 2 Register, offset: 0x18A */
  uint16_t FCTRL;                                  /**< Fault Control Register, offset: 0x18C */
  uint16_t FSTS;                                   /**< Fault Status Register, offset: 0x18E */
  uint16_t FFILT;                                  /**< Fault Filter Register, offset: 0x190 */
  uint16_t FTST;                                   /**< Fault Test Register, offset: 0x192 */
  uint16_t FCTRL2;                                 /**< Fault Control 2 Register, offset: 0x194 */
} volatile *PWM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Register_Accessor_Macros PWM - Register accessor macros
 * @{
 */


/* PWM - Register accessors */
#define PWM_CNT_REG(base,index)                  ((base)->SM[index].CNT)
#define PWM_INIT_REG(base,index)                 ((base)->SM[index].INIT)
#define PWM_CTRL2_REG(base,index)                ((base)->SM[index].CTRL2)
#define PWM_CTRL_REG(base,index)                 ((base)->SM[index].CTRL)
#define PWM_VAL0_REG(base,index)                 ((base)->SM[index].VAL0)
#define PWM_FRACVAL1_REG(base,index)             ((base)->SM[index].FRACVAL1)
#define PWM_VAL1_REG(base,index)                 ((base)->SM[index].VAL1)
#define PWM_FRACVAL2_REG(base,index)             ((base)->SM[index].FRACVAL2)
#define PWM_VAL2_REG(base,index)                 ((base)->SM[index].VAL2)
#define PWM_FRACVAL3_REG(base,index)             ((base)->SM[index].FRACVAL3)
#define PWM_VAL3_REG(base,index)                 ((base)->SM[index].VAL3)
#define PWM_FRACVAL4_REG(base,index)             ((base)->SM[index].FRACVAL4)
#define PWM_VAL4_REG(base,index)                 ((base)->SM[index].VAL4)
#define PWM_FRACVAL5_REG(base,index)             ((base)->SM[index].FRACVAL5)
#define PWM_VAL5_REG(base,index)                 ((base)->SM[index].VAL5)
#define PWM_FRCTRL_REG(base,index)               ((base)->SM[index].FRCTRL)
#define PWM_OCTRL_REG(base,index)                ((base)->SM[index].OCTRL)
#define PWM_STS_REG(base,index)                  ((base)->SM[index].STS)
#define PWM_INTEN_REG(base,index)                ((base)->SM[index].INTEN)
#define PWM_DMAEN_REG(base,index)                ((base)->SM[index].DMAEN)
#define PWM_TCTRL_REG(base,index)                ((base)->SM[index].TCTRL)
#define PWM_DISMAP_REG(base,index,index2)        ((base)->SM[index].DISMAP[index2])
#define PWM_DTCNT0_REG(base,index)               ((base)->SM[index].DTCNT0)
#define PWM_DTCNT1_REG(base,index)               ((base)->SM[index].DTCNT1)
#define PWM_CAPTCTRLA_REG(base,index)            ((base)->SM[index].CAPTCTRLA)
#define PWM_CAPTCOMPA_REG(base,index)            ((base)->SM[index].CAPTCOMPA)
#define PWM_CAPTCTRLB_REG(base,index)            ((base)->SM[index].CAPTCTRLB)
#define PWM_CAPTCOMPB_REG(base,index)            ((base)->SM[index].CAPTCOMPB)
#define PWM_CAPTCTRLX_REG(base,index)            ((base)->SM[index].CAPTCTRLX)
#define PWM_CAPTCOMPX_REG(base,index)            ((base)->SM[index].CAPTCOMPX)
#define PWM_CVAL0_REG(base,index)                ((base)->SM[index].CVAL0)
#define PWM_CVAL0CYC_REG(base,index)             ((base)->SM[index].CVAL0CYC)
#define PWM_CVAL1_REG(base,index)                ((base)->SM[index].CVAL1)
#define PWM_CVAL1CYC_REG(base,index)             ((base)->SM[index].CVAL1CYC)
#define PWM_CVAL2_REG(base,index)                ((base)->SM[index].CVAL2)
#define PWM_CVAL2CYC_REG(base,index)             ((base)->SM[index].CVAL2CYC)
#define PWM_CVAL3_REG(base,index)                ((base)->SM[index].CVAL3)
#define PWM_CVAL3CYC_REG(base,index)             ((base)->SM[index].CVAL3CYC)
#define PWM_CVAL4_REG(base,index)                ((base)->SM[index].CVAL4)
#define PWM_CVAL4CYC_REG(base,index)             ((base)->SM[index].CVAL4CYC)
#define PWM_CVAL5_REG(base,index)                ((base)->SM[index].CVAL5)
#define PWM_CVAL5CYC_REG(base,index)             ((base)->SM[index].CVAL5CYC)
#define PWM_OUTEN_REG(base)                      ((base)->OUTEN)
#define PWM_MASK_REG(base)                       ((base)->MASK)
#define PWM_SWCOUT_REG(base)                     ((base)->SWCOUT)
#define PWM_DTSRCSEL_REG(base)                   ((base)->DTSRCSEL)
#define PWM_MCTRL_REG(base)                      ((base)->MCTRL)
#define PWM_MCTRL2_REG(base)                     ((base)->MCTRL2)
#define PWM_FCTRL_REG(base)                      ((base)->FCTRL)
#define PWM_FSTS_REG(base)                       ((base)->FSTS)
#define PWM_FFILT_REG(base)                      ((base)->FFILT)
#define PWM_FTST_REG(base)                       ((base)->FTST)
#define PWM_FCTRL2_REG(base)                     ((base)->FCTRL2)

/*!
 * @}
 */ /* end of group PWM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Register_Masks PWM Register Masks
 * @{
 */

/* CNT Bit Fields */
#define PWM_CNT_CNT_MASK                         0xFFFFu
#define PWM_CNT_CNT_SHIFT                        0
#define PWM_CNT_CNT(x)                           (((uint16_t)(((uint16_t)(x))<<PWM_CNT_CNT_SHIFT))&PWM_CNT_CNT_MASK)
/* INIT Bit Fields */
#define PWM_INIT_INIT_MASK                       0xFFFFu
#define PWM_INIT_INIT_SHIFT                      0
#define PWM_INIT_INIT(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_INIT_INIT_SHIFT))&PWM_INIT_INIT_MASK)
/* CTRL2 Bit Fields */
#define PWM_CTRL2_CLK_SEL_MASK                   0x3u
#define PWM_CTRL2_CLK_SEL_SHIFT                  0
#define PWM_CTRL2_CLK_SEL(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_CTRL2_CLK_SEL_SHIFT))&PWM_CTRL2_CLK_SEL_MASK)
#define PWM_CTRL2_RELOAD_SEL_MASK                0x4u
#define PWM_CTRL2_RELOAD_SEL_SHIFT               2
#define PWM_CTRL2_FORCE_SEL_MASK                 0x38u
#define PWM_CTRL2_FORCE_SEL_SHIFT                3
#define PWM_CTRL2_FORCE_SEL(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CTRL2_FORCE_SEL_SHIFT))&PWM_CTRL2_FORCE_SEL_MASK)
#define PWM_CTRL2_FORCE_MASK                     0x40u
#define PWM_CTRL2_FORCE_SHIFT                    6
#define PWM_CTRL2_FRCEN_MASK                     0x80u
#define PWM_CTRL2_FRCEN_SHIFT                    7
#define PWM_CTRL2_INIT_SEL_MASK                  0x300u
#define PWM_CTRL2_INIT_SEL_SHIFT                 8
#define PWM_CTRL2_INIT_SEL(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CTRL2_INIT_SEL_SHIFT))&PWM_CTRL2_INIT_SEL_MASK)
#define PWM_CTRL2_PWMX_INIT_MASK                 0x400u
#define PWM_CTRL2_PWMX_INIT_SHIFT                10
#define PWM_CTRL2_PWM45_INIT_MASK                0x800u
#define PWM_CTRL2_PWM45_INIT_SHIFT               11
#define PWM_CTRL2_PWM23_INIT_MASK                0x1000u
#define PWM_CTRL2_PWM23_INIT_SHIFT               12
#define PWM_CTRL2_INDEP_MASK                     0x2000u
#define PWM_CTRL2_INDEP_SHIFT                    13
#define PWM_CTRL2_WAITEN_MASK                    0x4000u
#define PWM_CTRL2_WAITEN_SHIFT                   14
#define PWM_CTRL2_DBGEN_MASK                     0x8000u
#define PWM_CTRL2_DBGEN_SHIFT                    15
/* CTRL Bit Fields */
#define PWM_CTRL_DBLEN_MASK                      0x1u
#define PWM_CTRL_DBLEN_SHIFT                     0
#define PWM_CTRL_DBLX_MASK                       0x2u
#define PWM_CTRL_DBLX_SHIFT                      1
#define PWM_CTRL_LDMOD_MASK                      0x4u
#define PWM_CTRL_LDMOD_SHIFT                     2
#define PWM_CTRL_PRSC_MASK                       0x70u
#define PWM_CTRL_PRSC_SHIFT                      4
#define PWM_CTRL_PRSC(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_CTRL_PRSC_SHIFT))&PWM_CTRL_PRSC_MASK)
#define PWM_CTRL_DT_MASK                         0x300u
#define PWM_CTRL_DT_SHIFT                        8
#define PWM_CTRL_DT(x)                           (((uint16_t)(((uint16_t)(x))<<PWM_CTRL_DT_SHIFT))&PWM_CTRL_DT_MASK)
#define PWM_CTRL_FULL_MASK                       0x400u
#define PWM_CTRL_FULL_SHIFT                      10
#define PWM_CTRL_HALF_MASK                       0x800u
#define PWM_CTRL_HALF_SHIFT                      11
#define PWM_CTRL_LDFQ_MASK                       0xF000u
#define PWM_CTRL_LDFQ_SHIFT                      12
#define PWM_CTRL_LDFQ(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_CTRL_LDFQ_SHIFT))&PWM_CTRL_LDFQ_MASK)
/* VAL0 Bit Fields */
#define PWM_VAL0_VAL0_MASK                       0xFFFFu
#define PWM_VAL0_VAL0_SHIFT                      0
#define PWM_VAL0_VAL0(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL0_VAL0_SHIFT))&PWM_VAL0_VAL0_MASK)
/* FRACVAL1 Bit Fields */
#define PWM_FRACVAL1_FRACVAL1_MASK               0xF800u
#define PWM_FRACVAL1_FRACVAL1_SHIFT              11
#define PWM_FRACVAL1_FRACVAL1(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_FRACVAL1_FRACVAL1_SHIFT))&PWM_FRACVAL1_FRACVAL1_MASK)
/* VAL1 Bit Fields */
#define PWM_VAL1_VAL1_MASK                       0xFFFFu
#define PWM_VAL1_VAL1_SHIFT                      0
#define PWM_VAL1_VAL1(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL1_VAL1_SHIFT))&PWM_VAL1_VAL1_MASK)
/* FRACVAL2 Bit Fields */
#define PWM_FRACVAL2_FRACVAL2_MASK               0xF800u
#define PWM_FRACVAL2_FRACVAL2_SHIFT              11
#define PWM_FRACVAL2_FRACVAL2(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_FRACVAL2_FRACVAL2_SHIFT))&PWM_FRACVAL2_FRACVAL2_MASK)
/* VAL2 Bit Fields */
#define PWM_VAL2_VAL2_MASK                       0xFFFFu
#define PWM_VAL2_VAL2_SHIFT                      0
#define PWM_VAL2_VAL2(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL2_VAL2_SHIFT))&PWM_VAL2_VAL2_MASK)
/* FRACVAL3 Bit Fields */
#define PWM_FRACVAL3_FRACVAL3_MASK               0xF800u
#define PWM_FRACVAL3_FRACVAL3_SHIFT              11
#define PWM_FRACVAL3_FRACVAL3(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_FRACVAL3_FRACVAL3_SHIFT))&PWM_FRACVAL3_FRACVAL3_MASK)
/* VAL3 Bit Fields */
#define PWM_VAL3_VAL3_MASK                       0xFFFFu
#define PWM_VAL3_VAL3_SHIFT                      0
#define PWM_VAL3_VAL3(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL3_VAL3_SHIFT))&PWM_VAL3_VAL3_MASK)
/* FRACVAL4 Bit Fields */
#define PWM_FRACVAL4_FRACVAL4_MASK               0xF800u
#define PWM_FRACVAL4_FRACVAL4_SHIFT              11
#define PWM_FRACVAL4_FRACVAL4(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_FRACVAL4_FRACVAL4_SHIFT))&PWM_FRACVAL4_FRACVAL4_MASK)
/* VAL4 Bit Fields */
#define PWM_VAL4_VAL4_MASK                       0xFFFFu
#define PWM_VAL4_VAL4_SHIFT                      0
#define PWM_VAL4_VAL4(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL4_VAL4_SHIFT))&PWM_VAL4_VAL4_MASK)
/* FRACVAL5 Bit Fields */
#define PWM_FRACVAL5_FRACVAL5_MASK               0xF800u
#define PWM_FRACVAL5_FRACVAL5_SHIFT              11
#define PWM_FRACVAL5_FRACVAL5(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_FRACVAL5_FRACVAL5_SHIFT))&PWM_FRACVAL5_FRACVAL5_MASK)
/* VAL5 Bit Fields */
#define PWM_VAL5_VAL5_MASK                       0xFFFFu
#define PWM_VAL5_VAL5_SHIFT                      0
#define PWM_VAL5_VAL5(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_VAL5_VAL5_SHIFT))&PWM_VAL5_VAL5_MASK)
/* FRCTRL Bit Fields */
#define PWM_FRCTRL_FRAC1_EN_MASK                 0x2u
#define PWM_FRCTRL_FRAC1_EN_SHIFT                1
#define PWM_FRCTRL_FRAC23_EN_MASK                0x4u
#define PWM_FRCTRL_FRAC23_EN_SHIFT               2
#define PWM_FRCTRL_FRAC45_EN_MASK                0x10u
#define PWM_FRCTRL_FRAC45_EN_SHIFT               4
#define PWM_FRCTRL_FRAC_PU_MASK                  0x100u
#define PWM_FRCTRL_FRAC_PU_SHIFT                 8
#define PWM_FRCTRL_TEST_MASK                     0x8000u
#define PWM_FRCTRL_TEST_SHIFT                    15
/* OCTRL Bit Fields */
#define PWM_OCTRL_PWMXFS_MASK                    0x3u
#define PWM_OCTRL_PWMXFS_SHIFT                   0
#define PWM_OCTRL_PWMXFS(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_OCTRL_PWMXFS_SHIFT))&PWM_OCTRL_PWMXFS_MASK)
#define PWM_OCTRL_PWMBFS_MASK                    0xCu
#define PWM_OCTRL_PWMBFS_SHIFT                   2
#define PWM_OCTRL_PWMBFS(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_OCTRL_PWMBFS_SHIFT))&PWM_OCTRL_PWMBFS_MASK)
#define PWM_OCTRL_PWMAFS_MASK                    0x30u
#define PWM_OCTRL_PWMAFS_SHIFT                   4
#define PWM_OCTRL_PWMAFS(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_OCTRL_PWMAFS_SHIFT))&PWM_OCTRL_PWMAFS_MASK)
#define PWM_OCTRL_POLX_MASK                      0x100u
#define PWM_OCTRL_POLX_SHIFT                     8
#define PWM_OCTRL_POLB_MASK                      0x200u
#define PWM_OCTRL_POLB_SHIFT                     9
#define PWM_OCTRL_POLA_MASK                      0x400u
#define PWM_OCTRL_POLA_SHIFT                     10
#define PWM_OCTRL_PWMX_IN_MASK                   0x2000u
#define PWM_OCTRL_PWMX_IN_SHIFT                  13
#define PWM_OCTRL_PWMB_IN_MASK                   0x4000u
#define PWM_OCTRL_PWMB_IN_SHIFT                  14
#define PWM_OCTRL_PWMA_IN_MASK                   0x8000u
#define PWM_OCTRL_PWMA_IN_SHIFT                  15
/* STS Bit Fields */
#define PWM_STS_CMPF_MASK                        0x3Fu
#define PWM_STS_CMPF_SHIFT                       0
#define PWM_STS_CMPF(x)                          (((uint16_t)(((uint16_t)(x))<<PWM_STS_CMPF_SHIFT))&PWM_STS_CMPF_MASK)
#define PWM_STS_CFX0_MASK                        0x40u
#define PWM_STS_CFX0_SHIFT                       6
#define PWM_STS_CFX1_MASK                        0x80u
#define PWM_STS_CFX1_SHIFT                       7
#define PWM_STS_CFB0_MASK                        0x100u
#define PWM_STS_CFB0_SHIFT                       8
#define PWM_STS_CFB1_MASK                        0x200u
#define PWM_STS_CFB1_SHIFT                       9
#define PWM_STS_CFA0_MASK                        0x400u
#define PWM_STS_CFA0_SHIFT                       10
#define PWM_STS_CFA1_MASK                        0x800u
#define PWM_STS_CFA1_SHIFT                       11
#define PWM_STS_RF_MASK                          0x1000u
#define PWM_STS_RF_SHIFT                         12
#define PWM_STS_REF_MASK                         0x2000u
#define PWM_STS_REF_SHIFT                        13
#define PWM_STS_RUF_MASK                         0x4000u
#define PWM_STS_RUF_SHIFT                        14
/* INTEN Bit Fields */
#define PWM_INTEN_CMPIE_MASK                     0x3Fu
#define PWM_INTEN_CMPIE_SHIFT                    0
#define PWM_INTEN_CMPIE(x)                       (((uint16_t)(((uint16_t)(x))<<PWM_INTEN_CMPIE_SHIFT))&PWM_INTEN_CMPIE_MASK)
#define PWM_INTEN_CX0IE_MASK                     0x40u
#define PWM_INTEN_CX0IE_SHIFT                    6
#define PWM_INTEN_CX1IE_MASK                     0x80u
#define PWM_INTEN_CX1IE_SHIFT                    7
#define PWM_INTEN_CB0IE_MASK                     0x100u
#define PWM_INTEN_CB0IE_SHIFT                    8
#define PWM_INTEN_CB1IE_MASK                     0x200u
#define PWM_INTEN_CB1IE_SHIFT                    9
#define PWM_INTEN_CA0IE_MASK                     0x400u
#define PWM_INTEN_CA0IE_SHIFT                    10
#define PWM_INTEN_CA1IE_MASK                     0x800u
#define PWM_INTEN_CA1IE_SHIFT                    11
#define PWM_INTEN_RIE_MASK                       0x1000u
#define PWM_INTEN_RIE_SHIFT                      12
#define PWM_INTEN_REIE_MASK                      0x2000u
#define PWM_INTEN_REIE_SHIFT                     13
/* DMAEN Bit Fields */
#define PWM_DMAEN_CX0DE_MASK                     0x1u
#define PWM_DMAEN_CX0DE_SHIFT                    0
#define PWM_DMAEN_CX1DE_MASK                     0x2u
#define PWM_DMAEN_CX1DE_SHIFT                    1
#define PWM_DMAEN_CB0DE_MASK                     0x4u
#define PWM_DMAEN_CB0DE_SHIFT                    2
#define PWM_DMAEN_CB1DE_MASK                     0x8u
#define PWM_DMAEN_CB1DE_SHIFT                    3
#define PWM_DMAEN_CA0DE_MASK                     0x10u
#define PWM_DMAEN_CA0DE_SHIFT                    4
#define PWM_DMAEN_CA1DE_MASK                     0x20u
#define PWM_DMAEN_CA1DE_SHIFT                    5
#define PWM_DMAEN_CAPTDE_MASK                    0xC0u
#define PWM_DMAEN_CAPTDE_SHIFT                   6
#define PWM_DMAEN_CAPTDE(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_DMAEN_CAPTDE_SHIFT))&PWM_DMAEN_CAPTDE_MASK)
#define PWM_DMAEN_FAND_MASK                      0x100u
#define PWM_DMAEN_FAND_SHIFT                     8
#define PWM_DMAEN_VALDE_MASK                     0x200u
#define PWM_DMAEN_VALDE_SHIFT                    9
/* TCTRL Bit Fields */
#define PWM_TCTRL_OUT_TRIG_EN_MASK               0x3Fu
#define PWM_TCTRL_OUT_TRIG_EN_SHIFT              0
#define PWM_TCTRL_OUT_TRIG_EN(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_TCTRL_OUT_TRIG_EN_SHIFT))&PWM_TCTRL_OUT_TRIG_EN_MASK)
#define PWM_TCTRL_PWBOT1_MASK                    0x4000u
#define PWM_TCTRL_PWBOT1_SHIFT                   14
#define PWM_TCTRL_PWAOT0_MASK                    0x8000u
#define PWM_TCTRL_PWAOT0_SHIFT                   15
/* DISMAP Bit Fields */
#define PWM_DISMAP_DIS0A_MASK                    0xFu
#define PWM_DISMAP_DIS0A_SHIFT                   0
#define PWM_DISMAP_DIS0A(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_DISMAP_DIS0A_SHIFT))&PWM_DISMAP_DIS0A_MASK)
#define PWM_DISMAP_DIS0B_MASK                    0xF0u
#define PWM_DISMAP_DIS0B_SHIFT                   4
#define PWM_DISMAP_DIS0B(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_DISMAP_DIS0B_SHIFT))&PWM_DISMAP_DIS0B_MASK)
#define PWM_DISMAP_DIS0X_MASK                    0xF00u
#define PWM_DISMAP_DIS0X_SHIFT                   8
#define PWM_DISMAP_DIS0X(x)                      (((uint16_t)(((uint16_t)(x))<<PWM_DISMAP_DIS0X_SHIFT))&PWM_DISMAP_DIS0X_MASK)
/* DTCNT0 Bit Fields */
#define PWM_DTCNT0_DTCNT0_MASK                   0x7FFu
#define PWM_DTCNT0_DTCNT0_SHIFT                  0
#define PWM_DTCNT0_DTCNT0(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_DTCNT0_DTCNT0_SHIFT))&PWM_DTCNT0_DTCNT0_MASK)
/* DTCNT1 Bit Fields */
#define PWM_DTCNT1_DTCNT1_MASK                   0x7FFu
#define PWM_DTCNT1_DTCNT1_SHIFT                  0
#define PWM_DTCNT1_DTCNT1(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_DTCNT1_DTCNT1_SHIFT))&PWM_DTCNT1_DTCNT1_MASK)
/* CAPTCTRLA Bit Fields */
#define PWM_CAPTCTRLA_ARMA_MASK                  0x1u
#define PWM_CAPTCTRLA_ARMA_SHIFT                 0
#define PWM_CAPTCTRLA_ONESHOTA_MASK              0x2u
#define PWM_CAPTCTRLA_ONESHOTA_SHIFT             1
#define PWM_CAPTCTRLA_EDGA0_MASK                 0xCu
#define PWM_CAPTCTRLA_EDGA0_SHIFT                2
#define PWM_CAPTCTRLA_EDGA0(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLA_EDGA0_SHIFT))&PWM_CAPTCTRLA_EDGA0_MASK)
#define PWM_CAPTCTRLA_EDGA1_MASK                 0x30u
#define PWM_CAPTCTRLA_EDGA1_SHIFT                4
#define PWM_CAPTCTRLA_EDGA1(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLA_EDGA1_SHIFT))&PWM_CAPTCTRLA_EDGA1_MASK)
#define PWM_CAPTCTRLA_INP_SELA_MASK              0x40u
#define PWM_CAPTCTRLA_INP_SELA_SHIFT             6
#define PWM_CAPTCTRLA_EDGCNTA_EN_MASK            0x80u
#define PWM_CAPTCTRLA_EDGCNTA_EN_SHIFT           7
#define PWM_CAPTCTRLA_CFAWM_MASK                 0x300u
#define PWM_CAPTCTRLA_CFAWM_SHIFT                8
#define PWM_CAPTCTRLA_CFAWM(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLA_CFAWM_SHIFT))&PWM_CAPTCTRLA_CFAWM_MASK)
#define PWM_CAPTCTRLA_CA0CNT_MASK                0x1C00u
#define PWM_CAPTCTRLA_CA0CNT_SHIFT               10
#define PWM_CAPTCTRLA_CA0CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLA_CA0CNT_SHIFT))&PWM_CAPTCTRLA_CA0CNT_MASK)
#define PWM_CAPTCTRLA_CA1CNT_MASK                0xE000u
#define PWM_CAPTCTRLA_CA1CNT_SHIFT               13
#define PWM_CAPTCTRLA_CA1CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLA_CA1CNT_SHIFT))&PWM_CAPTCTRLA_CA1CNT_MASK)
/* CAPTCOMPA Bit Fields */
#define PWM_CAPTCOMPA_EDGCMPA_MASK               0xFFu
#define PWM_CAPTCOMPA_EDGCMPA_SHIFT              0
#define PWM_CAPTCOMPA_EDGCMPA(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPA_EDGCMPA_SHIFT))&PWM_CAPTCOMPA_EDGCMPA_MASK)
#define PWM_CAPTCOMPA_EDGCNTA_MASK               0xFF00u
#define PWM_CAPTCOMPA_EDGCNTA_SHIFT              8
#define PWM_CAPTCOMPA_EDGCNTA(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPA_EDGCNTA_SHIFT))&PWM_CAPTCOMPA_EDGCNTA_MASK)
/* CAPTCTRLB Bit Fields */
#define PWM_CAPTCTRLB_ARMB_MASK                  0x1u
#define PWM_CAPTCTRLB_ARMB_SHIFT                 0
#define PWM_CAPTCTRLB_ONESHOTB_MASK              0x2u
#define PWM_CAPTCTRLB_ONESHOTB_SHIFT             1
#define PWM_CAPTCTRLB_EDGB0_MASK                 0xCu
#define PWM_CAPTCTRLB_EDGB0_SHIFT                2
#define PWM_CAPTCTRLB_EDGB0(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLB_EDGB0_SHIFT))&PWM_CAPTCTRLB_EDGB0_MASK)
#define PWM_CAPTCTRLB_EDGB1_MASK                 0x30u
#define PWM_CAPTCTRLB_EDGB1_SHIFT                4
#define PWM_CAPTCTRLB_EDGB1(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLB_EDGB1_SHIFT))&PWM_CAPTCTRLB_EDGB1_MASK)
#define PWM_CAPTCTRLB_INP_SELB_MASK              0x40u
#define PWM_CAPTCTRLB_INP_SELB_SHIFT             6
#define PWM_CAPTCTRLB_EDGCNTB_EN_MASK            0x80u
#define PWM_CAPTCTRLB_EDGCNTB_EN_SHIFT           7
#define PWM_CAPTCTRLB_CFBWM_MASK                 0x300u
#define PWM_CAPTCTRLB_CFBWM_SHIFT                8
#define PWM_CAPTCTRLB_CFBWM(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLB_CFBWM_SHIFT))&PWM_CAPTCTRLB_CFBWM_MASK)
#define PWM_CAPTCTRLB_CB0CNT_MASK                0x1C00u
#define PWM_CAPTCTRLB_CB0CNT_SHIFT               10
#define PWM_CAPTCTRLB_CB0CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLB_CB0CNT_SHIFT))&PWM_CAPTCTRLB_CB0CNT_MASK)
#define PWM_CAPTCTRLB_CB1CNT_MASK                0xE000u
#define PWM_CAPTCTRLB_CB1CNT_SHIFT               13
#define PWM_CAPTCTRLB_CB1CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLB_CB1CNT_SHIFT))&PWM_CAPTCTRLB_CB1CNT_MASK)
/* CAPTCOMPB Bit Fields */
#define PWM_CAPTCOMPB_EDGCMPB_MASK               0xFFu
#define PWM_CAPTCOMPB_EDGCMPB_SHIFT              0
#define PWM_CAPTCOMPB_EDGCMPB(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPB_EDGCMPB_SHIFT))&PWM_CAPTCOMPB_EDGCMPB_MASK)
#define PWM_CAPTCOMPB_EDGCNTB_MASK               0xFF00u
#define PWM_CAPTCOMPB_EDGCNTB_SHIFT              8
#define PWM_CAPTCOMPB_EDGCNTB(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPB_EDGCNTB_SHIFT))&PWM_CAPTCOMPB_EDGCNTB_MASK)
/* CAPTCTRLX Bit Fields */
#define PWM_CAPTCTRLX_ARMX_MASK                  0x1u
#define PWM_CAPTCTRLX_ARMX_SHIFT                 0
#define PWM_CAPTCTRLX_ONESHOTX_MASK              0x2u
#define PWM_CAPTCTRLX_ONESHOTX_SHIFT             1
#define PWM_CAPTCTRLX_EDGX0_MASK                 0xCu
#define PWM_CAPTCTRLX_EDGX0_SHIFT                2
#define PWM_CAPTCTRLX_EDGX0(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLX_EDGX0_SHIFT))&PWM_CAPTCTRLX_EDGX0_MASK)
#define PWM_CAPTCTRLX_EDGX1_MASK                 0x30u
#define PWM_CAPTCTRLX_EDGX1_SHIFT                4
#define PWM_CAPTCTRLX_EDGX1(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLX_EDGX1_SHIFT))&PWM_CAPTCTRLX_EDGX1_MASK)
#define PWM_CAPTCTRLX_INP_SELX_MASK              0x40u
#define PWM_CAPTCTRLX_INP_SELX_SHIFT             6
#define PWM_CAPTCTRLX_EDGCNTX_EN_MASK            0x80u
#define PWM_CAPTCTRLX_EDGCNTX_EN_SHIFT           7
#define PWM_CAPTCTRLX_CFXWM_MASK                 0x300u
#define PWM_CAPTCTRLX_CFXWM_SHIFT                8
#define PWM_CAPTCTRLX_CFXWM(x)                   (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLX_CFXWM_SHIFT))&PWM_CAPTCTRLX_CFXWM_MASK)
#define PWM_CAPTCTRLX_CX0CNT_MASK                0x1C00u
#define PWM_CAPTCTRLX_CX0CNT_SHIFT               10
#define PWM_CAPTCTRLX_CX0CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLX_CX0CNT_SHIFT))&PWM_CAPTCTRLX_CX0CNT_MASK)
#define PWM_CAPTCTRLX_CX1CNT_MASK                0xE000u
#define PWM_CAPTCTRLX_CX1CNT_SHIFT               13
#define PWM_CAPTCTRLX_CX1CNT(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCTRLX_CX1CNT_SHIFT))&PWM_CAPTCTRLX_CX1CNT_MASK)
/* CAPTCOMPX Bit Fields */
#define PWM_CAPTCOMPX_EDGCMPX_MASK               0xFFu
#define PWM_CAPTCOMPX_EDGCMPX_SHIFT              0
#define PWM_CAPTCOMPX_EDGCMPX(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPX_EDGCMPX_SHIFT))&PWM_CAPTCOMPX_EDGCMPX_MASK)
#define PWM_CAPTCOMPX_EDGCNTX_MASK               0xFF00u
#define PWM_CAPTCOMPX_EDGCNTX_SHIFT              8
#define PWM_CAPTCOMPX_EDGCNTX(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CAPTCOMPX_EDGCNTX_SHIFT))&PWM_CAPTCOMPX_EDGCNTX_MASK)
/* CVAL0 Bit Fields */
#define PWM_CVAL0_CAPTVAL0_MASK                  0xFFFFu
#define PWM_CVAL0_CAPTVAL0_SHIFT                 0
#define PWM_CVAL0_CAPTVAL0(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL0_CAPTVAL0_SHIFT))&PWM_CVAL0_CAPTVAL0_MASK)
/* CVAL0CYC Bit Fields */
#define PWM_CVAL0CYC_CVAL0CYC_MASK               0xFu
#define PWM_CVAL0CYC_CVAL0CYC_SHIFT              0
#define PWM_CVAL0CYC_CVAL0CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL0CYC_CVAL0CYC_SHIFT))&PWM_CVAL0CYC_CVAL0CYC_MASK)
/* CVAL1 Bit Fields */
#define PWM_CVAL1_CAPTVAL1_MASK                  0xFFFFu
#define PWM_CVAL1_CAPTVAL1_SHIFT                 0
#define PWM_CVAL1_CAPTVAL1(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL1_CAPTVAL1_SHIFT))&PWM_CVAL1_CAPTVAL1_MASK)
/* CVAL1CYC Bit Fields */
#define PWM_CVAL1CYC_CVAL1CYC_MASK               0xFu
#define PWM_CVAL1CYC_CVAL1CYC_SHIFT              0
#define PWM_CVAL1CYC_CVAL1CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL1CYC_CVAL1CYC_SHIFT))&PWM_CVAL1CYC_CVAL1CYC_MASK)
/* CVAL2 Bit Fields */
#define PWM_CVAL2_CAPTVAL2_MASK                  0xFFFFu
#define PWM_CVAL2_CAPTVAL2_SHIFT                 0
#define PWM_CVAL2_CAPTVAL2(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL2_CAPTVAL2_SHIFT))&PWM_CVAL2_CAPTVAL2_MASK)
/* CVAL2CYC Bit Fields */
#define PWM_CVAL2CYC_CVAL2CYC_MASK               0xFu
#define PWM_CVAL2CYC_CVAL2CYC_SHIFT              0
#define PWM_CVAL2CYC_CVAL2CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL2CYC_CVAL2CYC_SHIFT))&PWM_CVAL2CYC_CVAL2CYC_MASK)
/* CVAL3 Bit Fields */
#define PWM_CVAL3_CAPTVAL3_MASK                  0xFFFFu
#define PWM_CVAL3_CAPTVAL3_SHIFT                 0
#define PWM_CVAL3_CAPTVAL3(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL3_CAPTVAL3_SHIFT))&PWM_CVAL3_CAPTVAL3_MASK)
/* CVAL3CYC Bit Fields */
#define PWM_CVAL3CYC_CVAL3CYC_MASK               0xFu
#define PWM_CVAL3CYC_CVAL3CYC_SHIFT              0
#define PWM_CVAL3CYC_CVAL3CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL3CYC_CVAL3CYC_SHIFT))&PWM_CVAL3CYC_CVAL3CYC_MASK)
/* CVAL4 Bit Fields */
#define PWM_CVAL4_CAPTVAL4_MASK                  0xFFFFu
#define PWM_CVAL4_CAPTVAL4_SHIFT                 0
#define PWM_CVAL4_CAPTVAL4(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL4_CAPTVAL4_SHIFT))&PWM_CVAL4_CAPTVAL4_MASK)
/* CVAL4CYC Bit Fields */
#define PWM_CVAL4CYC_CVAL4CYC_MASK               0xFu
#define PWM_CVAL4CYC_CVAL4CYC_SHIFT              0
#define PWM_CVAL4CYC_CVAL4CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL4CYC_CVAL4CYC_SHIFT))&PWM_CVAL4CYC_CVAL4CYC_MASK)
/* CVAL5 Bit Fields */
#define PWM_CVAL5_CAPTVAL5_MASK                  0xFFFFu
#define PWM_CVAL5_CAPTVAL5_SHIFT                 0
#define PWM_CVAL5_CAPTVAL5(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_CVAL5_CAPTVAL5_SHIFT))&PWM_CVAL5_CAPTVAL5_MASK)
/* CVAL5CYC Bit Fields */
#define PWM_CVAL5CYC_CVAL5CYC_MASK               0xFu
#define PWM_CVAL5CYC_CVAL5CYC_SHIFT              0
#define PWM_CVAL5CYC_CVAL5CYC(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_CVAL5CYC_CVAL5CYC_SHIFT))&PWM_CVAL5CYC_CVAL5CYC_MASK)
/* OUTEN Bit Fields */
#define PWM_OUTEN_PWMX_EN_MASK                   0xFu
#define PWM_OUTEN_PWMX_EN_SHIFT                  0
#define PWM_OUTEN_PWMX_EN(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_OUTEN_PWMX_EN_SHIFT))&PWM_OUTEN_PWMX_EN_MASK)
#define PWM_OUTEN_PWMB_EN_MASK                   0xF0u
#define PWM_OUTEN_PWMB_EN_SHIFT                  4
#define PWM_OUTEN_PWMB_EN(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_OUTEN_PWMB_EN_SHIFT))&PWM_OUTEN_PWMB_EN_MASK)
#define PWM_OUTEN_PWMA_EN_MASK                   0xF00u
#define PWM_OUTEN_PWMA_EN_SHIFT                  8
#define PWM_OUTEN_PWMA_EN(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_OUTEN_PWMA_EN_SHIFT))&PWM_OUTEN_PWMA_EN_MASK)
/* MASK Bit Fields */
#define PWM_MASK_MASKX_MASK                      0xFu
#define PWM_MASK_MASKX_SHIFT                     0
#define PWM_MASK_MASKX(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_MASK_MASKX_SHIFT))&PWM_MASK_MASKX_MASK)
#define PWM_MASK_MASKB_MASK                      0xF0u
#define PWM_MASK_MASKB_SHIFT                     4
#define PWM_MASK_MASKB(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_MASK_MASKB_SHIFT))&PWM_MASK_MASKB_MASK)
#define PWM_MASK_MASKA_MASK                      0xF00u
#define PWM_MASK_MASKA_SHIFT                     8
#define PWM_MASK_MASKA(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_MASK_MASKA_SHIFT))&PWM_MASK_MASKA_MASK)
#define PWM_MASK_UPDATE_MASK_MASK                0xF000u
#define PWM_MASK_UPDATE_MASK_SHIFT               12
#define PWM_MASK_UPDATE_MASK(x)                  (((uint16_t)(((uint16_t)(x))<<PWM_MASK_UPDATE_MASK_SHIFT))&PWM_MASK_UPDATE_MASK_MASK)
/* SWCOUT Bit Fields */
#define PWM_SWCOUT_SM0OUT45_MASK                 0x1u
#define PWM_SWCOUT_SM0OUT45_SHIFT                0
#define PWM_SWCOUT_SM0OUT23_MASK                 0x2u
#define PWM_SWCOUT_SM0OUT23_SHIFT                1
#define PWM_SWCOUT_SM1OUT45_MASK                 0x4u
#define PWM_SWCOUT_SM1OUT45_SHIFT                2
#define PWM_SWCOUT_SM1OUT23_MASK                 0x8u
#define PWM_SWCOUT_SM1OUT23_SHIFT                3
#define PWM_SWCOUT_SM2OUT45_MASK                 0x10u
#define PWM_SWCOUT_SM2OUT45_SHIFT                4
#define PWM_SWCOUT_SM2OUT23_MASK                 0x20u
#define PWM_SWCOUT_SM2OUT23_SHIFT                5
#define PWM_SWCOUT_SM3OUT45_MASK                 0x40u
#define PWM_SWCOUT_SM3OUT45_SHIFT                6
#define PWM_SWCOUT_SM3OUT23_MASK                 0x80u
#define PWM_SWCOUT_SM3OUT23_SHIFT                7
/* DTSRCSEL Bit Fields */
#define PWM_DTSRCSEL_SM0SEL45_MASK               0x3u
#define PWM_DTSRCSEL_SM0SEL45_SHIFT              0
#define PWM_DTSRCSEL_SM0SEL45(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM0SEL45_SHIFT))&PWM_DTSRCSEL_SM0SEL45_MASK)
#define PWM_DTSRCSEL_SM0SEL23_MASK               0xCu
#define PWM_DTSRCSEL_SM0SEL23_SHIFT              2
#define PWM_DTSRCSEL_SM0SEL23(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM0SEL23_SHIFT))&PWM_DTSRCSEL_SM0SEL23_MASK)
#define PWM_DTSRCSEL_SM1SEL45_MASK               0x30u
#define PWM_DTSRCSEL_SM1SEL45_SHIFT              4
#define PWM_DTSRCSEL_SM1SEL45(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM1SEL45_SHIFT))&PWM_DTSRCSEL_SM1SEL45_MASK)
#define PWM_DTSRCSEL_SM1SEL23_MASK               0xC0u
#define PWM_DTSRCSEL_SM1SEL23_SHIFT              6
#define PWM_DTSRCSEL_SM1SEL23(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM1SEL23_SHIFT))&PWM_DTSRCSEL_SM1SEL23_MASK)
#define PWM_DTSRCSEL_SM2SEL45_MASK               0x300u
#define PWM_DTSRCSEL_SM2SEL45_SHIFT              8
#define PWM_DTSRCSEL_SM2SEL45(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM2SEL45_SHIFT))&PWM_DTSRCSEL_SM2SEL45_MASK)
#define PWM_DTSRCSEL_SM2SEL23_MASK               0xC00u
#define PWM_DTSRCSEL_SM2SEL23_SHIFT              10
#define PWM_DTSRCSEL_SM2SEL23(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM2SEL23_SHIFT))&PWM_DTSRCSEL_SM2SEL23_MASK)
#define PWM_DTSRCSEL_SM3SEL45_MASK               0x3000u
#define PWM_DTSRCSEL_SM3SEL45_SHIFT              12
#define PWM_DTSRCSEL_SM3SEL45(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM3SEL45_SHIFT))&PWM_DTSRCSEL_SM3SEL45_MASK)
#define PWM_DTSRCSEL_SM3SEL23_MASK               0xC000u
#define PWM_DTSRCSEL_SM3SEL23_SHIFT              14
#define PWM_DTSRCSEL_SM3SEL23(x)                 (((uint16_t)(((uint16_t)(x))<<PWM_DTSRCSEL_SM3SEL23_SHIFT))&PWM_DTSRCSEL_SM3SEL23_MASK)
/* MCTRL Bit Fields */
#define PWM_MCTRL_LDOK_MASK                      0xFu
#define PWM_MCTRL_LDOK_SHIFT                     0
#define PWM_MCTRL_LDOK(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_MCTRL_LDOK_SHIFT))&PWM_MCTRL_LDOK_MASK)
#define PWM_MCTRL_CLDOK_MASK                     0xF0u
#define PWM_MCTRL_CLDOK_SHIFT                    4
#define PWM_MCTRL_CLDOK(x)                       (((uint16_t)(((uint16_t)(x))<<PWM_MCTRL_CLDOK_SHIFT))&PWM_MCTRL_CLDOK_MASK)
#define PWM_MCTRL_RUN_MASK                       0xF00u
#define PWM_MCTRL_RUN_SHIFT                      8
#define PWM_MCTRL_RUN(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_MCTRL_RUN_SHIFT))&PWM_MCTRL_RUN_MASK)
#define PWM_MCTRL_IPOL_MASK                      0xF000u
#define PWM_MCTRL_IPOL_SHIFT                     12
#define PWM_MCTRL_IPOL(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_MCTRL_IPOL_SHIFT))&PWM_MCTRL_IPOL_MASK)
/* MCTRL2 Bit Fields */
#define PWM_MCTRL2_MONPLL_MASK                   0x3u
#define PWM_MCTRL2_MONPLL_SHIFT                  0
#define PWM_MCTRL2_MONPLL(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_MCTRL2_MONPLL_SHIFT))&PWM_MCTRL2_MONPLL_MASK)
/* FCTRL Bit Fields */
#define PWM_FCTRL_FIE_MASK                       0xFu
#define PWM_FCTRL_FIE_SHIFT                      0
#define PWM_FCTRL_FIE(x)                         (((uint16_t)(((uint16_t)(x))<<PWM_FCTRL_FIE_SHIFT))&PWM_FCTRL_FIE_MASK)
#define PWM_FCTRL_FSAFE_MASK                     0xF0u
#define PWM_FCTRL_FSAFE_SHIFT                    4
#define PWM_FCTRL_FSAFE(x)                       (((uint16_t)(((uint16_t)(x))<<PWM_FCTRL_FSAFE_SHIFT))&PWM_FCTRL_FSAFE_MASK)
#define PWM_FCTRL_FAUTO_MASK                     0xF00u
#define PWM_FCTRL_FAUTO_SHIFT                    8
#define PWM_FCTRL_FAUTO(x)                       (((uint16_t)(((uint16_t)(x))<<PWM_FCTRL_FAUTO_SHIFT))&PWM_FCTRL_FAUTO_MASK)
#define PWM_FCTRL_FLVL_MASK                      0xF000u
#define PWM_FCTRL_FLVL_SHIFT                     12
#define PWM_FCTRL_FLVL(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_FCTRL_FLVL_SHIFT))&PWM_FCTRL_FLVL_MASK)
/* FSTS Bit Fields */
#define PWM_FSTS_FFLAG_MASK                      0xFu
#define PWM_FSTS_FFLAG_SHIFT                     0
#define PWM_FSTS_FFLAG(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_FSTS_FFLAG_SHIFT))&PWM_FSTS_FFLAG_MASK)
#define PWM_FSTS_FFULL_MASK                      0xF0u
#define PWM_FSTS_FFULL_SHIFT                     4
#define PWM_FSTS_FFULL(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_FSTS_FFULL_SHIFT))&PWM_FSTS_FFULL_MASK)
#define PWM_FSTS_FFPIN_MASK                      0xF00u
#define PWM_FSTS_FFPIN_SHIFT                     8
#define PWM_FSTS_FFPIN(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_FSTS_FFPIN_SHIFT))&PWM_FSTS_FFPIN_MASK)
#define PWM_FSTS_FHALF_MASK                      0xF000u
#define PWM_FSTS_FHALF_SHIFT                     12
#define PWM_FSTS_FHALF(x)                        (((uint16_t)(((uint16_t)(x))<<PWM_FSTS_FHALF_SHIFT))&PWM_FSTS_FHALF_MASK)
/* FFILT Bit Fields */
#define PWM_FFILT_FILT_PER_MASK                  0xFFu
#define PWM_FFILT_FILT_PER_SHIFT                 0
#define PWM_FFILT_FILT_PER(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_FFILT_FILT_PER_SHIFT))&PWM_FFILT_FILT_PER_MASK)
#define PWM_FFILT_FILT_CNT_MASK                  0x700u
#define PWM_FFILT_FILT_CNT_SHIFT                 8
#define PWM_FFILT_FILT_CNT(x)                    (((uint16_t)(((uint16_t)(x))<<PWM_FFILT_FILT_CNT_SHIFT))&PWM_FFILT_FILT_CNT_MASK)
#define PWM_FFILT_GSTR_MASK                      0x8000u
#define PWM_FFILT_GSTR_SHIFT                     15
/* FTST Bit Fields */
#define PWM_FTST_FTEST_MASK                      0x1u
#define PWM_FTST_FTEST_SHIFT                     0
/* FCTRL2 Bit Fields */
#define PWM_FCTRL2_NOCOMB_MASK                   0xFu
#define PWM_FCTRL2_NOCOMB_SHIFT                  0
#define PWM_FCTRL2_NOCOMB(x)                     (((uint16_t)(((uint16_t)(x))<<PWM_FCTRL2_NOCOMB_SHIFT))&PWM_FCTRL2_NOCOMB_MASK)

/*!
 * @}
 */ /* end of group PWM_Register_Masks */


/* PWM - Peripheral instance base addresses */
/** Peripheral PWMA base pointer */
#define PWMA_BASE_PTR                            ((PWM_MemMapPtr)0x40033000u)
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { PWMA_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Register_Accessor_Macros PWM - Register accessor macros
 * @{
 */


/* PWM - Register instance definitions */
/* PWMA */
#define PWMA_SM0CNT                              PWM_CNT_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0INIT                             PWM_INIT_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CTRL2                            PWM_CTRL2_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CTRL                             PWM_CTRL_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL0                             PWM_VAL0_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRACVAL1                         PWM_FRACVAL1_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL1                             PWM_VAL1_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRACVAL2                         PWM_FRACVAL2_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL2                             PWM_VAL2_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRACVAL3                         PWM_FRACVAL3_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL3                             PWM_VAL3_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRACVAL4                         PWM_FRACVAL4_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL4                             PWM_VAL4_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRACVAL5                         PWM_FRACVAL5_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0VAL5                             PWM_VAL5_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0FRCTRL                           PWM_FRCTRL_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0OCTRL                            PWM_OCTRL_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0STS                              PWM_STS_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0INTEN                            PWM_INTEN_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0DMAEN                            PWM_DMAEN_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0TCTRL                            PWM_TCTRL_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0DISMAP0                          PWM_DISMAP_REG(PWMA_BASE_PTR,0,0)
#define PWMA_SM0DTCNT0                           PWM_DTCNT0_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0DTCNT1                           PWM_DTCNT1_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCTRLA                        PWM_CAPTCTRLA_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCOMPA                        PWM_CAPTCOMPA_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCTRLB                        PWM_CAPTCTRLB_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCOMPB                        PWM_CAPTCOMPB_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCTRLX                        PWM_CAPTCTRLX_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CAPTCOMPX                        PWM_CAPTCOMPX_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL0                            PWM_CVAL0_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL0CYC                         PWM_CVAL0CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL1                            PWM_CVAL1_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL1CYC                         PWM_CVAL1CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL2                            PWM_CVAL2_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL2CYC                         PWM_CVAL2CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL3                            PWM_CVAL3_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL3CYC                         PWM_CVAL3CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL4                            PWM_CVAL4_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL4CYC                         PWM_CVAL4CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL5                            PWM_CVAL5_REG(PWMA_BASE_PTR,0)
#define PWMA_SM0CVAL5CYC                         PWM_CVAL5CYC_REG(PWMA_BASE_PTR,0)
#define PWMA_SM1CNT                              PWM_CNT_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1INIT                             PWM_INIT_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CTRL2                            PWM_CTRL2_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CTRL                             PWM_CTRL_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL0                             PWM_VAL0_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRACVAL1                         PWM_FRACVAL1_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL1                             PWM_VAL1_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRACVAL2                         PWM_FRACVAL2_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL2                             PWM_VAL2_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRACVAL3                         PWM_FRACVAL3_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL3                             PWM_VAL3_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRACVAL4                         PWM_FRACVAL4_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL4                             PWM_VAL4_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRACVAL5                         PWM_FRACVAL5_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1VAL5                             PWM_VAL5_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1FRCTRL                           PWM_FRCTRL_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1OCTRL                            PWM_OCTRL_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1STS                              PWM_STS_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1INTEN                            PWM_INTEN_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1DMAEN                            PWM_DMAEN_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1TCTRL                            PWM_TCTRL_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1DISMAP0                          PWM_DISMAP_REG(PWMA_BASE_PTR,1,0)
#define PWMA_SM1DTCNT0                           PWM_DTCNT0_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1DTCNT1                           PWM_DTCNT1_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCTRLA                        PWM_CAPTCTRLA_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCOMPA                        PWM_CAPTCOMPA_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCTRLB                        PWM_CAPTCTRLB_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCOMPB                        PWM_CAPTCOMPB_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCTRLX                        PWM_CAPTCTRLX_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CAPTCOMPX                        PWM_CAPTCOMPX_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL0                            PWM_CVAL0_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL0CYC                         PWM_CVAL0CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL1                            PWM_CVAL1_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL1CYC                         PWM_CVAL1CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL2                            PWM_CVAL2_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL2CYC                         PWM_CVAL2CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL3                            PWM_CVAL3_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL3CYC                         PWM_CVAL3CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL4                            PWM_CVAL4_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL4CYC                         PWM_CVAL4CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL5                            PWM_CVAL5_REG(PWMA_BASE_PTR,1)
#define PWMA_SM1CVAL5CYC                         PWM_CVAL5CYC_REG(PWMA_BASE_PTR,1)
#define PWMA_SM2CNT                              PWM_CNT_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2INIT                             PWM_INIT_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CTRL2                            PWM_CTRL2_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CTRL                             PWM_CTRL_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL0                             PWM_VAL0_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRACVAL1                         PWM_FRACVAL1_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL1                             PWM_VAL1_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRACVAL2                         PWM_FRACVAL2_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL2                             PWM_VAL2_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRACVAL3                         PWM_FRACVAL3_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL3                             PWM_VAL3_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRACVAL4                         PWM_FRACVAL4_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL4                             PWM_VAL4_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRACVAL5                         PWM_FRACVAL5_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2VAL5                             PWM_VAL5_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2FRCTRL                           PWM_FRCTRL_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2OCTRL                            PWM_OCTRL_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2STS                              PWM_STS_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2INTEN                            PWM_INTEN_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2DMAEN                            PWM_DMAEN_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2TCTRL                            PWM_TCTRL_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2DISMAP0                          PWM_DISMAP_REG(PWMA_BASE_PTR,2,0)
#define PWMA_SM2DTCNT0                           PWM_DTCNT0_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2DTCNT1                           PWM_DTCNT1_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCTRLA                        PWM_CAPTCTRLA_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCOMPA                        PWM_CAPTCOMPA_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCTRLB                        PWM_CAPTCTRLB_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCOMPB                        PWM_CAPTCOMPB_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCTRLX                        PWM_CAPTCTRLX_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CAPTCOMPX                        PWM_CAPTCOMPX_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL0                            PWM_CVAL0_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL0CYC                         PWM_CVAL0CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL1                            PWM_CVAL1_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL1CYC                         PWM_CVAL1CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL2                            PWM_CVAL2_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL2CYC                         PWM_CVAL2CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL3                            PWM_CVAL3_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL3CYC                         PWM_CVAL3CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL4                            PWM_CVAL4_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL4CYC                         PWM_CVAL4CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL5                            PWM_CVAL5_REG(PWMA_BASE_PTR,2)
#define PWMA_SM2CVAL5CYC                         PWM_CVAL5CYC_REG(PWMA_BASE_PTR,2)
#define PWMA_SM3CNT                              PWM_CNT_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3INIT                             PWM_INIT_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CTRL2                            PWM_CTRL2_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CTRL                             PWM_CTRL_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL0                             PWM_VAL0_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRACVAL1                         PWM_FRACVAL1_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL1                             PWM_VAL1_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRACVAL2                         PWM_FRACVAL2_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL2                             PWM_VAL2_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRACVAL3                         PWM_FRACVAL3_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL3                             PWM_VAL3_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRACVAL4                         PWM_FRACVAL4_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL4                             PWM_VAL4_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRACVAL5                         PWM_FRACVAL5_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3VAL5                             PWM_VAL5_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3FRCTRL                           PWM_FRCTRL_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3OCTRL                            PWM_OCTRL_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3STS                              PWM_STS_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3INTEN                            PWM_INTEN_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3DMAEN                            PWM_DMAEN_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3TCTRL                            PWM_TCTRL_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3DISMAP0                          PWM_DISMAP_REG(PWMA_BASE_PTR,3,0)
#define PWMA_SM3DTCNT0                           PWM_DTCNT0_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3DTCNT1                           PWM_DTCNT1_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCTRLA                        PWM_CAPTCTRLA_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCOMPA                        PWM_CAPTCOMPA_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCTRLB                        PWM_CAPTCTRLB_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCOMPB                        PWM_CAPTCOMPB_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCTRLX                        PWM_CAPTCTRLX_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CAPTCOMPX                        PWM_CAPTCOMPX_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL0                            PWM_CVAL0_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL0CYC                         PWM_CVAL0CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL1                            PWM_CVAL1_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL1CYC                         PWM_CVAL1CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL2                            PWM_CVAL2_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL2CYC                         PWM_CVAL2CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL3                            PWM_CVAL3_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL3CYC                         PWM_CVAL3CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL4                            PWM_CVAL4_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL4CYC                         PWM_CVAL4CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL5                            PWM_CVAL5_REG(PWMA_BASE_PTR,3)
#define PWMA_SM3CVAL5CYC                         PWM_CVAL5CYC_REG(PWMA_BASE_PTR,3)
#define PWMA_OUTEN                               PWM_OUTEN_REG(PWMA_BASE_PTR)
#define PWMA_MASK                                PWM_MASK_REG(PWMA_BASE_PTR)
#define PWMA_SWCOUT                              PWM_SWCOUT_REG(PWMA_BASE_PTR)
#define PWMA_DTSRCSEL                            PWM_DTSRCSEL_REG(PWMA_BASE_PTR)
#define PWMA_MCTRL                               PWM_MCTRL_REG(PWMA_BASE_PTR)
#define PWMA_MCTRL2                              PWM_MCTRL2_REG(PWMA_BASE_PTR)
#define PWMA_FCTRL                               PWM_FCTRL_REG(PWMA_BASE_PTR)
#define PWMA_FSTS                                PWM_FSTS_REG(PWMA_BASE_PTR)
#define PWMA_FFILT                               PWM_FFILT_REG(PWMA_BASE_PTR)
#define PWMA_FTST                                PWM_FTST_REG(PWMA_BASE_PTR)
#define PWMA_FCTRL2                              PWM_FCTRL2_REG(PWMA_BASE_PTR)

/* PWM - Register array accessors */
#define PWMA_CNT(index)                          PWM_CNT_REG(PWMA_BASE_PTR,index)
#define PWMA_INIT(index)                         PWM_INIT_REG(PWMA_BASE_PTR,index)
#define PWMA_CTRL2(index)                        PWM_CTRL2_REG(PWMA_BASE_PTR,index)
#define PWMA_CTRL(index)                         PWM_CTRL_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL0(index)                         PWM_VAL0_REG(PWMA_BASE_PTR,index)
#define PWMA_FRACVAL1(index)                     PWM_FRACVAL1_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL1(index)                         PWM_VAL1_REG(PWMA_BASE_PTR,index)
#define PWMA_FRACVAL2(index)                     PWM_FRACVAL2_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL2(index)                         PWM_VAL2_REG(PWMA_BASE_PTR,index)
#define PWMA_FRACVAL3(index)                     PWM_FRACVAL3_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL3(index)                         PWM_VAL3_REG(PWMA_BASE_PTR,index)
#define PWMA_FRACVAL4(index)                     PWM_FRACVAL4_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL4(index)                         PWM_VAL4_REG(PWMA_BASE_PTR,index)
#define PWMA_FRACVAL5(index)                     PWM_FRACVAL5_REG(PWMA_BASE_PTR,index)
#define PWMA_VAL5(index)                         PWM_VAL5_REG(PWMA_BASE_PTR,index)
#define PWMA_FRCTRL(index)                       PWM_FRCTRL_REG(PWMA_BASE_PTR,index)
#define PWMA_OCTRL(index)                        PWM_OCTRL_REG(PWMA_BASE_PTR,index)
#define PWMA_STS(index)                          PWM_STS_REG(PWMA_BASE_PTR,index)
#define PWMA_INTEN(index)                        PWM_INTEN_REG(PWMA_BASE_PTR,index)
#define PWMA_DMAEN(index)                        PWM_DMAEN_REG(PWMA_BASE_PTR,index)
#define PWMA_TCTRL(index)                        PWM_TCTRL_REG(PWMA_BASE_PTR,index)
#define PWMA_DISMAP(index,index2)                PWM_DISMAP_REG(PWMA_BASE_PTR,index,index2)
#define PWMA_DTCNT0(index)                       PWM_DTCNT0_REG(PWMA_BASE_PTR,index)
#define PWMA_DTCNT1(index)                       PWM_DTCNT1_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCTRLA(index)                    PWM_CAPTCTRLA_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCOMPA(index)                    PWM_CAPTCOMPA_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCTRLB(index)                    PWM_CAPTCTRLB_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCOMPB(index)                    PWM_CAPTCOMPB_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCTRLX(index)                    PWM_CAPTCTRLX_REG(PWMA_BASE_PTR,index)
#define PWMA_CAPTCOMPX(index)                    PWM_CAPTCOMPX_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL0(index)                        PWM_CVAL0_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL0CYC(index)                     PWM_CVAL0CYC_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL1(index)                        PWM_CVAL1_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL1CYC(index)                     PWM_CVAL1CYC_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL2(index)                        PWM_CVAL2_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL2CYC(index)                     PWM_CVAL2CYC_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL3(index)                        PWM_CVAL3_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL3CYC(index)                     PWM_CVAL3CYC_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL4(index)                        PWM_CVAL4_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL4CYC(index)                     PWM_CVAL4CYC_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL5(index)                        PWM_CVAL5_REG(PWMA_BASE_PTR,index)
#define PWMA_CVAL5CYC(index)                     PWM_CVAL5CYC_REG(PWMA_BASE_PTR,index)

/*!
 * @}
 */ /* end of group PWM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PWM_Peripheral */


/* ----------------------------------------------------------------------------
   -- RCM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral RCM
 * @{
 */

/** RCM - Peripheral register structure */
typedef struct RCM_MemMap {
  uint8_t SRS0;                                    /**< System Reset Status Register 0, offset: 0x0 */
  uint8_t SRS1;                                    /**< System Reset Status Register 1, offset: 0x1 */
  uint8_t RESERVED_0[2];
  uint8_t RPFC;                                    /**< Reset Pin Filter Control register, offset: 0x4 */
  uint8_t RPFW;                                    /**< Reset Pin Filter Width register, offset: 0x5 */
  uint8_t RESERVED_1[2];
  uint8_t SSRS0;                                   /**< Sticky System Reset Status Register 0, offset: 0x8 */
  uint8_t SSRS1;                                   /**< Sticky System Reset Status Register 1, offset: 0x9 */
} volatile *RCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register accessors */
#define RCM_SRS0_REG(base)                       ((base)->SRS0)
#define RCM_SRS1_REG(base)                       ((base)->SRS1)
#define RCM_RPFC_REG(base)                       ((base)->RPFC)
#define RCM_RPFW_REG(base)                       ((base)->RPFW)
#define RCM_SSRS0_REG(base)                      ((base)->SSRS0)
#define RCM_SSRS1_REG(base)                      ((base)->SSRS1)

/*!
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* SRS0 Bit Fields */
#define RCM_SRS0_WAKEUP_MASK                     0x1u
#define RCM_SRS0_WAKEUP_SHIFT                    0
#define RCM_SRS0_LVD_MASK                        0x2u
#define RCM_SRS0_LVD_SHIFT                       1
#define RCM_SRS0_LOC_MASK                        0x4u
#define RCM_SRS0_LOC_SHIFT                       2
#define RCM_SRS0_LOL_MASK                        0x8u
#define RCM_SRS0_LOL_SHIFT                       3
#define RCM_SRS0_WDOG_MASK                       0x20u
#define RCM_SRS0_WDOG_SHIFT                      5
#define RCM_SRS0_PIN_MASK                        0x40u
#define RCM_SRS0_PIN_SHIFT                       6
#define RCM_SRS0_POR_MASK                        0x80u
#define RCM_SRS0_POR_SHIFT                       7
/* SRS1 Bit Fields */
#define RCM_SRS1_LOCKUP_MASK                     0x2u
#define RCM_SRS1_LOCKUP_SHIFT                    1
#define RCM_SRS1_SW_MASK                         0x4u
#define RCM_SRS1_SW_SHIFT                        2
#define RCM_SRS1_MDM_AP_MASK                     0x8u
#define RCM_SRS1_MDM_AP_SHIFT                    3
#define RCM_SRS1_SACKERR_MASK                    0x20u
#define RCM_SRS1_SACKERR_SHIFT                   5
/* RPFC Bit Fields */
#define RCM_RPFC_RSTFLTSRW_MASK                  0x3u
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK)
#define RCM_RPFC_RSTFLTSS_MASK                   0x4u
#define RCM_RPFC_RSTFLTSS_SHIFT                  2
/* RPFW Bit Fields */
#define RCM_RPFW_RSTFLTSEL_MASK                  0x1Fu
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK)
/* SSRS0 Bit Fields */
#define RCM_SSRS0_SWAKEUP_MASK                   0x1u
#define RCM_SSRS0_SWAKEUP_SHIFT                  0
#define RCM_SSRS0_SLVD_MASK                      0x2u
#define RCM_SSRS0_SLVD_SHIFT                     1
#define RCM_SSRS0_SLOC_MASK                      0x4u
#define RCM_SSRS0_SLOC_SHIFT                     2
#define RCM_SSRS0_SLOL_MASK                      0x8u
#define RCM_SSRS0_SLOL_SHIFT                     3
#define RCM_SSRS0_SWDOG_MASK                     0x20u
#define RCM_SSRS0_SWDOG_SHIFT                    5
#define RCM_SSRS0_SPIN_MASK                      0x40u
#define RCM_SSRS0_SPIN_SHIFT                     6
#define RCM_SSRS0_SPOR_MASK                      0x80u
#define RCM_SSRS0_SPOR_SHIFT                     7
/* SSRS1 Bit Fields */
#define RCM_SSRS1_SLOCKUP_MASK                   0x2u
#define RCM_SSRS1_SLOCKUP_SHIFT                  1
#define RCM_SSRS1_SSW_MASK                       0x4u
#define RCM_SSRS1_SSW_SHIFT                      2
#define RCM_SSRS1_SMDM_AP_MASK                   0x8u
#define RCM_SSRS1_SMDM_AP_SHIFT                  3
#define RCM_SSRS1_SSACKERR_MASK                  0x20u
#define RCM_SSRS1_SSACKERR_SHIFT                 5

/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base pointer */
#define RCM_BASE_PTR                             ((RCM_MemMapPtr)0x4007F000u)
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register instance definitions */
/* RCM */
#define RCM_SRS0                                 RCM_SRS0_REG(RCM_BASE_PTR)
#define RCM_SRS1                                 RCM_SRS1_REG(RCM_BASE_PTR)
#define RCM_RPFC                                 RCM_RPFC_REG(RCM_BASE_PTR)
#define RCM_RPFW                                 RCM_RPFW_REG(RCM_BASE_PTR)
#define RCM_SSRS0                                RCM_SSRS0_REG(RCM_BASE_PTR)
#define RCM_SSRS1                                RCM_SSRS1_REG(RCM_BASE_PTR)

/*!
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group RCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- SCB
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCB_Peripheral SCB
 * @{
 */

/** SCB - Peripheral register structure */
typedef struct SCB_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t ACTLR;                                  /**< Auxiliary Control Register,, offset: 0x8 */
  uint8_t RESERVED_1[3316];
  uint32_t CPUID;                                  /**< CPUID Base Register, offset: 0xD00 */
  uint32_t ICSR;                                   /**< Interrupt Control and State Register, offset: 0xD04 */
  uint32_t VTOR;                                   /**< Vector Table Offset Register, offset: 0xD08 */
  uint32_t AIRCR;                                  /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  uint32_t SCR;                                    /**< System Control Register, offset: 0xD10 */
  uint32_t CCR;                                    /**< Configuration and Control Register, offset: 0xD14 */
  uint32_t SHPR1;                                  /**< System Handler Priority Register 1, offset: 0xD18 */
  uint32_t SHPR2;                                  /**< System Handler Priority Register 2, offset: 0xD1C */
  uint32_t SHPR3;                                  /**< System Handler Priority Register 3, offset: 0xD20 */
  uint32_t SHCSR;                                  /**< System Handler Control and State Register, offset: 0xD24 */
  uint32_t CFSR;                                   /**< Configurable Fault Status Registers, offset: 0xD28 */
  uint32_t HFSR;                                   /**< HardFault Status register, offset: 0xD2C */
  uint32_t DFSR;                                   /**< Debug Fault Status Register, offset: 0xD30 */
  uint32_t MMFAR;                                  /**< MemManage Address Register, offset: 0xD34 */
  uint32_t BFAR;                                   /**< BusFault Address Register, offset: 0xD38 */
  uint32_t AFSR;                                   /**< Auxiliary Fault Status Register, offset: 0xD3C */
  uint8_t RESERVED_2[72];
  uint32_t CPACR;                                  /**< Debug Fault Status Register, offset: 0xD88 */
} volatile *SCB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register accessors */
#define SCB_ACTLR_REG(base)                      ((base)->ACTLR)
#define SCB_CPUID_REG(base)                      ((base)->CPUID)
#define SCB_ICSR_REG(base)                       ((base)->ICSR)
#define SCB_VTOR_REG(base)                       ((base)->VTOR)
#define SCB_AIRCR_REG(base)                      ((base)->AIRCR)
#define SCB_SCR_REG(base)                        ((base)->SCR)
#define SCB_CCR_REG(base)                        ((base)->CCR)
#define SCB_SHPR1_REG(base)                      ((base)->SHPR1)
#define SCB_SHPR2_REG(base)                      ((base)->SHPR2)
#define SCB_SHPR3_REG(base)                      ((base)->SHPR3)
#define SCB_SHCSR_REG(base)                      ((base)->SHCSR)
#define SCB_CFSR_REG(base)                       ((base)->CFSR)
#define SCB_HFSR_REG(base)                       ((base)->HFSR)
#define SCB_DFSR_REG(base)                       ((base)->DFSR)
#define SCB_MMFAR_REG(base)                      ((base)->MMFAR)
#define SCB_BFAR_REG(base)                       ((base)->BFAR)
#define SCB_AFSR_REG(base)                       ((base)->AFSR)
#define SCB_CPACR_REG(base)                      ((base)->CPACR)

/*!
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SCB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCB_Register_Masks SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define SCB_ACTLR_DISMCYCINT_MASK                0x1u
#define SCB_ACTLR_DISMCYCINT_SHIFT               0
#define SCB_ACTLR_DISDEFWBUF_MASK                0x2u
#define SCB_ACTLR_DISDEFWBUF_SHIFT               1
#define SCB_ACTLR_DISFOLD_MASK                   0x4u
#define SCB_ACTLR_DISFOLD_SHIFT                  2
/* CPUID Bit Fields */
#define SCB_CPUID_REVISION_MASK                  0xFu
#define SCB_CPUID_REVISION_SHIFT                 0
#define SCB_CPUID_REVISION(x)                    (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_REVISION_SHIFT))&SCB_CPUID_REVISION_MASK)
#define SCB_CPUID_PARTNO_MASK                    0xFFF0u
#define SCB_CPUID_PARTNO_SHIFT                   4
#define SCB_CPUID_PARTNO(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_PARTNO_SHIFT))&SCB_CPUID_PARTNO_MASK)
#define SCB_CPUID_VARIANT_MASK                   0xF00000u
#define SCB_CPUID_VARIANT_SHIFT                  20
#define SCB_CPUID_VARIANT(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_VARIANT_SHIFT))&SCB_CPUID_VARIANT_MASK)
#define SCB_CPUID_IMPLEMENTER_MASK               0xFF000000u
#define SCB_CPUID_IMPLEMENTER_SHIFT              24
#define SCB_CPUID_IMPLEMENTER(x)                 (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_IMPLEMENTER_SHIFT))&SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define SCB_ICSR_VECTACTIVE_MASK                 0x1FFu
#define SCB_ICSR_VECTACTIVE_SHIFT                0
#define SCB_ICSR_VECTACTIVE(x)                   (((uint32_t)(((uint32_t)(x))<<SCB_ICSR_VECTACTIVE_SHIFT))&SCB_ICSR_VECTACTIVE_MASK)
#define SCB_ICSR_RETTOBASE_MASK                  0x800u
#define SCB_ICSR_RETTOBASE_SHIFT                 11
#define SCB_ICSR_VECTPENDING_MASK                0x3F000u
#define SCB_ICSR_VECTPENDING_SHIFT               12
#define SCB_ICSR_VECTPENDING(x)                  (((uint32_t)(((uint32_t)(x))<<SCB_ICSR_VECTPENDING_SHIFT))&SCB_ICSR_VECTPENDING_MASK)
#define SCB_ICSR_ISRPENDING_MASK                 0x400000u
#define SCB_ICSR_ISRPENDING_SHIFT                22
#define SCB_ICSR_ISRPREEMPT_MASK                 0x800000u
#define SCB_ICSR_ISRPREEMPT_SHIFT                23
#define SCB_ICSR_PENDSTCLR_MASK                  0x2000000u
#define SCB_ICSR_PENDSTCLR_SHIFT                 25
#define SCB_ICSR_PENDSTSET_MASK                  0x4000000u
#define SCB_ICSR_PENDSTSET_SHIFT                 26
#define SCB_ICSR_PENDSVCLR_MASK                  0x8000000u
#define SCB_ICSR_PENDSVCLR_SHIFT                 27
#define SCB_ICSR_PENDSVSET_MASK                  0x10000000u
#define SCB_ICSR_PENDSVSET_SHIFT                 28
#define SCB_ICSR_NMIPENDSET_MASK                 0x80000000u
#define SCB_ICSR_NMIPENDSET_SHIFT                31
/* VTOR Bit Fields */
#define SCB_VTOR_TBLOFF_MASK                     0xFFFFFF80u
#define SCB_VTOR_TBLOFF_SHIFT                    7
#define SCB_VTOR_TBLOFF(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_VTOR_TBLOFF_SHIFT))&SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define SCB_AIRCR_VECTRESET_MASK                 0x1u
#define SCB_AIRCR_VECTRESET_SHIFT                0
#define SCB_AIRCR_VECTCLRACTIVE_MASK             0x2u
#define SCB_AIRCR_VECTCLRACTIVE_SHIFT            1
#define SCB_AIRCR_SYSRESETREQ_MASK               0x4u
#define SCB_AIRCR_SYSRESETREQ_SHIFT              2
#define SCB_AIRCR_PRIGROUP_MASK                  0x700u
#define SCB_AIRCR_PRIGROUP_SHIFT                 8
#define SCB_AIRCR_PRIGROUP(x)                    (((uint32_t)(((uint32_t)(x))<<SCB_AIRCR_PRIGROUP_SHIFT))&SCB_AIRCR_PRIGROUP_MASK)
#define SCB_AIRCR_ENDIANNESS_MASK                0x8000u
#define SCB_AIRCR_ENDIANNESS_SHIFT               15
#define SCB_AIRCR_VECTKEY_MASK                   0xFFFF0000u
#define SCB_AIRCR_VECTKEY_SHIFT                  16
#define SCB_AIRCR_VECTKEY(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_AIRCR_VECTKEY_SHIFT))&SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define SCB_SCR_SLEEPONEXIT_MASK                 0x2u
#define SCB_SCR_SLEEPONEXIT_SHIFT                1
#define SCB_SCR_SLEEPDEEP_MASK                   0x4u
#define SCB_SCR_SLEEPDEEP_SHIFT                  2
#define SCB_SCR_SEVONPEND_MASK                   0x10u
#define SCB_SCR_SEVONPEND_SHIFT                  4
/* CCR Bit Fields */
#define SCB_CCR_NONBASETHRDENA_MASK              0x1u
#define SCB_CCR_NONBASETHRDENA_SHIFT             0
#define SCB_CCR_USERSETMPEND_MASK                0x2u
#define SCB_CCR_USERSETMPEND_SHIFT               1
#define SCB_CCR_UNALIGN_TRP_MASK                 0x8u
#define SCB_CCR_UNALIGN_TRP_SHIFT                3
#define SCB_CCR_DIV_0_TRP_MASK                   0x10u
#define SCB_CCR_DIV_0_TRP_SHIFT                  4
#define SCB_CCR_BFHFNMIGN_MASK                   0x100u
#define SCB_CCR_BFHFNMIGN_SHIFT                  8
#define SCB_CCR_STKALIGN_MASK                    0x200u
#define SCB_CCR_STKALIGN_SHIFT                   9
/* SHPR1 Bit Fields */
#define SCB_SHPR1_PRI_4_MASK                     0xFFu
#define SCB_SHPR1_PRI_4_SHIFT                    0
#define SCB_SHPR1_PRI_4(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_4_SHIFT))&SCB_SHPR1_PRI_4_MASK)
#define SCB_SHPR1_PRI_5_MASK                     0xFF00u
#define SCB_SHPR1_PRI_5_SHIFT                    8
#define SCB_SHPR1_PRI_5(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_5_SHIFT))&SCB_SHPR1_PRI_5_MASK)
#define SCB_SHPR1_PRI_6_MASK                     0xFF0000u
#define SCB_SHPR1_PRI_6_SHIFT                    16
#define SCB_SHPR1_PRI_6(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_6_SHIFT))&SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define SCB_SHPR2_PRI_11_MASK                    0xFF000000u
#define SCB_SHPR2_PRI_11_SHIFT                   24
#define SCB_SHPR2_PRI_11(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR2_PRI_11_SHIFT))&SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define SCB_SHPR3_PRI_14_MASK                    0xFF0000u
#define SCB_SHPR3_PRI_14_SHIFT                   16
#define SCB_SHPR3_PRI_14(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR3_PRI_14_SHIFT))&SCB_SHPR3_PRI_14_MASK)
#define SCB_SHPR3_PRI_15_MASK                    0xFF000000u
#define SCB_SHPR3_PRI_15_SHIFT                   24
#define SCB_SHPR3_PRI_15(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR3_PRI_15_SHIFT))&SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define SCB_SHCSR_MEMFAULTACT_MASK               0x1u
#define SCB_SHCSR_MEMFAULTACT_SHIFT              0
#define SCB_SHCSR_BUSFAULTACT_MASK               0x2u
#define SCB_SHCSR_BUSFAULTACT_SHIFT              1
#define SCB_SHCSR_USGFAULTACT_MASK               0x8u
#define SCB_SHCSR_USGFAULTACT_SHIFT              3
#define SCB_SHCSR_SVCALLACT_MASK                 0x80u
#define SCB_SHCSR_SVCALLACT_SHIFT                7
#define SCB_SHCSR_MONITORACT_MASK                0x100u
#define SCB_SHCSR_MONITORACT_SHIFT               8
#define SCB_SHCSR_PENDSVACT_MASK                 0x400u
#define SCB_SHCSR_PENDSVACT_SHIFT                10
#define SCB_SHCSR_SYSTICKACT_MASK                0x800u
#define SCB_SHCSR_SYSTICKACT_SHIFT               11
#define SCB_SHCSR_USGFAULTPENDED_MASK            0x1000u
#define SCB_SHCSR_USGFAULTPENDED_SHIFT           12
#define SCB_SHCSR_MEMFAULTPENDED_MASK            0x2000u
#define SCB_SHCSR_MEMFAULTPENDED_SHIFT           13
#define SCB_SHCSR_BUSFAULTPENDED_MASK            0x4000u
#define SCB_SHCSR_BUSFAULTPENDED_SHIFT           14
#define SCB_SHCSR_SVCALLPENDED_MASK              0x8000u
#define SCB_SHCSR_SVCALLPENDED_SHIFT             15
#define SCB_SHCSR_MEMFAULTENA_MASK               0x10000u
#define SCB_SHCSR_MEMFAULTENA_SHIFT              16
#define SCB_SHCSR_BUSFAULTENA_MASK               0x20000u
#define SCB_SHCSR_BUSFAULTENA_SHIFT              17
#define SCB_SHCSR_USGFAULTENA_MASK               0x40000u
#define SCB_SHCSR_USGFAULTENA_SHIFT              18
/* CFSR Bit Fields */
#define SCB_CFSR_IACCVIOL_MASK                   0x1u
#define SCB_CFSR_IACCVIOL_SHIFT                  0
#define SCB_CFSR_DACCVIOL_MASK                   0x2u
#define SCB_CFSR_DACCVIOL_SHIFT                  1
#define SCB_CFSR_MUNSTKERR_MASK                  0x8u
#define SCB_CFSR_MUNSTKERR_SHIFT                 3
#define SCB_CFSR_MSTKERR_MASK                    0x10u
#define SCB_CFSR_MSTKERR_SHIFT                   4
#define SCB_CFSR_MLSPERR_MASK                    0x20u
#define SCB_CFSR_MLSPERR_SHIFT                   5
#define SCB_CFSR_MMARVALID_MASK                  0x80u
#define SCB_CFSR_MMARVALID_SHIFT                 7
#define SCB_CFSR_IBUSERR_MASK                    0x100u
#define SCB_CFSR_IBUSERR_SHIFT                   8
#define SCB_CFSR_PRECISERR_MASK                  0x200u
#define SCB_CFSR_PRECISERR_SHIFT                 9
#define SCB_CFSR_IMPRECISERR_MASK                0x400u
#define SCB_CFSR_IMPRECISERR_SHIFT               10
#define SCB_CFSR_UNSTKERR_MASK                   0x800u
#define SCB_CFSR_UNSTKERR_SHIFT                  11
#define SCB_CFSR_STKERR_MASK                     0x1000u
#define SCB_CFSR_STKERR_SHIFT                    12
#define SCB_CFSR_LSPERR_MASK                     0x2000u
#define SCB_CFSR_LSPERR_SHIFT                    13
#define SCB_CFSR_BFARVALID_MASK                  0x8000u
#define SCB_CFSR_BFARVALID_SHIFT                 15
#define SCB_CFSR_UNDEFINSTR_MASK                 0x10000u
#define SCB_CFSR_UNDEFINSTR_SHIFT                16
#define SCB_CFSR_INVSTATE_MASK                   0x20000u
#define SCB_CFSR_INVSTATE_SHIFT                  17
#define SCB_CFSR_INVPC_MASK                      0x40000u
#define SCB_CFSR_INVPC_SHIFT                     18
#define SCB_CFSR_NOCP_MASK                       0x80000u
#define SCB_CFSR_NOCP_SHIFT                      19
#define SCB_CFSR_UNALIGNED_MASK                  0x1000000u
#define SCB_CFSR_UNALIGNED_SHIFT                 24
#define SCB_CFSR_DIVBYZERO_MASK                  0x2000000u
#define SCB_CFSR_DIVBYZERO_SHIFT                 25
/* HFSR Bit Fields */
#define SCB_HFSR_VECTTBL_MASK                    0x2u
#define SCB_HFSR_VECTTBL_SHIFT                   1
#define SCB_HFSR_FORCED_MASK                     0x40000000u
#define SCB_HFSR_FORCED_SHIFT                    30
#define SCB_HFSR_DEBUGEVT_MASK                   0x80000000u
#define SCB_HFSR_DEBUGEVT_SHIFT                  31
/* DFSR Bit Fields */
#define SCB_DFSR_HALTED_MASK                     0x1u
#define SCB_DFSR_HALTED_SHIFT                    0
#define SCB_DFSR_BKPT_MASK                       0x2u
#define SCB_DFSR_BKPT_SHIFT                      1
#define SCB_DFSR_DWTTRAP_MASK                    0x4u
#define SCB_DFSR_DWTTRAP_SHIFT                   2
#define SCB_DFSR_VCATCH_MASK                     0x8u
#define SCB_DFSR_VCATCH_SHIFT                    3
#define SCB_DFSR_EXTERNAL_MASK                   0x10u
#define SCB_DFSR_EXTERNAL_SHIFT                  4
/* MMFAR Bit Fields */
#define SCB_MMFAR_ADDRESS_MASK                   0xFFFFFFFFu
#define SCB_MMFAR_ADDRESS_SHIFT                  0
#define SCB_MMFAR_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_MMFAR_ADDRESS_SHIFT))&SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define SCB_BFAR_ADDRESS_MASK                    0xFFFFFFFFu
#define SCB_BFAR_ADDRESS_SHIFT                   0
#define SCB_BFAR_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_BFAR_ADDRESS_SHIFT))&SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define SCB_AFSR_AUXFAULT_MASK                   0xFFFFFFFFu
#define SCB_AFSR_AUXFAULT_SHIFT                  0
#define SCB_AFSR_AUXFAULT(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_AFSR_AUXFAULT_SHIFT))&SCB_AFSR_AUXFAULT_MASK)
/* CPACR Bit Fields */
#define SCB_CPACR_CP10_MASK                      0x300000u
#define SCB_CPACR_CP10_SHIFT                     20
#define SCB_CPACR_CP10(x)                        (((uint32_t)(((uint32_t)(x))<<SCB_CPACR_CP10_SHIFT))&SCB_CPACR_CP10_MASK)
#define SCB_CPACR_CP11_MASK                      0xC00000u
#define SCB_CPACR_CP11_SHIFT                     22
#define SCB_CPACR_CP11(x)                        (((uint32_t)(((uint32_t)(x))<<SCB_CPACR_CP11_SHIFT))&SCB_CPACR_CP11_MASK)

/*!
 * @}
 */ /* end of group SCB_Register_Masks */


/* SCB - Peripheral instance base addresses */
/** Peripheral SystemControl base pointer */
#define SystemControl_BASE_PTR                   ((SCB_MemMapPtr)0xE000E000u)
/** Array initializer of SCB peripheral base pointers */
#define SCB_BASE_PTRS                            { SystemControl_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register instance definitions */
/* SystemControl */
#define SCB_ACTLR                                SCB_ACTLR_REG(SystemControl_BASE_PTR)
#define SCB_CPUID                                SCB_CPUID_REG(SystemControl_BASE_PTR)
#define SCB_ICSR                                 SCB_ICSR_REG(SystemControl_BASE_PTR)
#define SCB_VTOR                                 SCB_VTOR_REG(SystemControl_BASE_PTR)
#define SCB_AIRCR                                SCB_AIRCR_REG(SystemControl_BASE_PTR)
#define SCB_SCR                                  SCB_SCR_REG(SystemControl_BASE_PTR)
#define SCB_CCR                                  SCB_CCR_REG(SystemControl_BASE_PTR)
#define SCB_SHPR1                                SCB_SHPR1_REG(SystemControl_BASE_PTR)
#define SCB_SHPR2                                SCB_SHPR2_REG(SystemControl_BASE_PTR)
#define SCB_SHPR3                                SCB_SHPR3_REG(SystemControl_BASE_PTR)
#define SCB_SHCSR                                SCB_SHCSR_REG(SystemControl_BASE_PTR)
#define SCB_CFSR                                 SCB_CFSR_REG(SystemControl_BASE_PTR)
#define SCB_HFSR                                 SCB_HFSR_REG(SystemControl_BASE_PTR)
#define SCB_DFSR                                 SCB_DFSR_REG(SystemControl_BASE_PTR)
#define SCB_MMFAR                                SCB_MMFAR_REG(SystemControl_BASE_PTR)
#define SCB_BFAR                                 SCB_BFAR_REG(SystemControl_BASE_PTR)
#define SCB_AFSR                                 SCB_AFSR_REG(SystemControl_BASE_PTR)
#define SCB_CPACR                                SCB_CPACR_REG(SystemControl_BASE_PTR)

/*!
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SCB_Peripheral */


/* ----------------------------------------------------------------------------
   -- SIM
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral SIM
 * @{
 */

/** SIM - Peripheral register structure */
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                  /**< System Options Register 1, offset: 0x0 */
  uint8_t RESERVED_0[4096];
  uint32_t SOPT2;                                  /**< System Options Register 2, offset: 0x1004 */
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                  /**< System Options Register 4, offset: 0x100C */
  uint32_t SOPT5;                                  /**< System Options Register 5, offset: 0x1010 */
  uint8_t RESERVED_2[4];
  uint32_t SOPT7;                                  /**< System Options Register 7, offset: 0x1018 */
  uint32_t SOPT8;                                  /**< System Options Register 8, offset: 0x101C */
  uint32_t SOPT9;                                  /**< System Options Register 9, offset: 0x1020 */
  uint32_t SDID;                                   /**< System Device Identification Register, offset: 0x1024 */
  uint8_t RESERVED_3[12];
  uint32_t SCGC4;                                  /**< System Clock Gating Control Register 4, offset: 0x1034 */
  uint32_t SCGC5;                                  /**< System Clock Gating Control Register 5, offset: 0x1038 */
  uint32_t SCGC6;                                  /**< System Clock Gating Control Register 6, offset: 0x103C */
  uint32_t SCGC7;                                  /**< System Clock Gating Control Register 7, offset: 0x1040 */
  uint32_t CLKDIV1;                                /**< System Clock Divider Register 1, offset: 0x1044 */
  uint8_t RESERVED_4[4];
  uint32_t FCFG1;                                  /**< Flash Configuration Register 1, offset: 0x104C */
  uint32_t FCFG2;                                  /**< Flash Configuration Register 2, offset: 0x1050 */
  uint32_t UIDH;                                   /**< Unique Identification Register High, offset: 0x1054 */
  uint32_t UIDMH;                                  /**< Unique Identification Register Mid-High, offset: 0x1058 */
  uint32_t UIDML;                                  /**< Unique Identification Register Mid Low, offset: 0x105C */
  uint32_t UIDL;                                   /**< Unique Identification Register Low, offset: 0x1060 */
  uint8_t RESERVED_5[4];
  uint32_t CLKDIV4;                                /**< System Clock Divider Register 4, offset: 0x1068 */
  uint32_t MISCTRL;                                /**< Miscellaneous Control Register, offset: 0x106C */
  uint32_t MISCTRL2;                               /**< Miscellaneous Control Register 2, offset: 0x1070 */
  uint8_t RESERVED_6[140];
  uint32_t WDOGC;                                  /**< WDOG Control Register, offset: 0x1100 */
  uint32_t PWRC;                                   /**< Power Control Register, offset: 0x1104 */
  uint32_t ADCOPT;                                 /**< ADC Channel 6/7 Mux Control Register, offset: 0x1108 */
} volatile *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#define SIM_SOPT1_REG(base)                      ((base)->SOPT1)
#define SIM_SOPT2_REG(base)                      ((base)->SOPT2)
#define SIM_SOPT4_REG(base)                      ((base)->SOPT4)
#define SIM_SOPT5_REG(base)                      ((base)->SOPT5)
#define SIM_SOPT7_REG(base)                      ((base)->SOPT7)
#define SIM_SOPT8_REG(base)                      ((base)->SOPT8)
#define SIM_SOPT9_REG(base)                      ((base)->SOPT9)
#define SIM_SDID_REG(base)                       ((base)->SDID)
#define SIM_SCGC4_REG(base)                      ((base)->SCGC4)
#define SIM_SCGC5_REG(base)                      ((base)->SCGC5)
#define SIM_SCGC6_REG(base)                      ((base)->SCGC6)
#define SIM_SCGC7_REG(base)                      ((base)->SCGC7)
#define SIM_CLKDIV1_REG(base)                    ((base)->CLKDIV1)
#define SIM_FCFG1_REG(base)                      ((base)->FCFG1)
#define SIM_FCFG2_REG(base)                      ((base)->FCFG2)
#define SIM_UIDH_REG(base)                       ((base)->UIDH)
#define SIM_UIDMH_REG(base)                      ((base)->UIDMH)
#define SIM_UIDML_REG(base)                      ((base)->UIDML)
#define SIM_UIDL_REG(base)                       ((base)->UIDL)
#define SIM_CLKDIV4_REG(base)                    ((base)->CLKDIV4)
#define SIM_MISCTRL_REG(base)                    ((base)->MISCTRL)
#define SIM_MISCTRL2_REG(base)                   ((base)->MISCTRL2)
#define SIM_WDOGC_REG(base)                      ((base)->WDOGC)
#define SIM_PWRC_REG(base)                       ((base)->PWRC)
#define SIM_ADCOPT_REG(base)                     ((base)->ADCOPT)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_RAMSIZE_MASK                   0xF000u
#define SIM_SOPT1_RAMSIZE_SHIFT                  12
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_RAMSIZE_SHIFT))&SIM_SOPT1_RAMSIZE_MASK)
#define SIM_SOPT1_OSC32KSEL_MASK                 0xC0000u
#define SIM_SOPT1_OSC32KSEL_SHIFT                18
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK)
/* SOPT2 Bit Fields */
#define SIM_SOPT2_CLKOUTSEL_MASK                 0xE0u
#define SIM_SOPT2_CLKOUTSEL_SHIFT                5
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK)
#define SIM_SOPT2_TRACECLKSEL_MASK               0x1000u
#define SIM_SOPT2_TRACECLKSEL_SHIFT              12
#define SIM_SOPT2_NANOEDGECLK2XSEL_MASK          0x80000000u
#define SIM_SOPT2_NANOEDGECLK2XSEL_SHIFT         31
/* SOPT4 Bit Fields */
#define SIM_SOPT4_FTM0FLT0_MASK                  0x1u
#define SIM_SOPT4_FTM0FLT0_SHIFT                 0
#define SIM_SOPT4_FTM0FLT1_MASK                  0x2u
#define SIM_SOPT4_FTM0FLT1_SHIFT                 1
#define SIM_SOPT4_FTM0FLT2_MASK                  0x4u
#define SIM_SOPT4_FTM0FLT2_SHIFT                 2
#define SIM_SOPT4_FTM0FLT3_MASK                  0x8u
#define SIM_SOPT4_FTM0FLT3_SHIFT                 3
#define SIM_SOPT4_FTM1FLT0_MASK                  0x10u
#define SIM_SOPT4_FTM1FLT0_SHIFT                 4
#define SIM_SOPT4_FTM3FLT0_MASK                  0x1000u
#define SIM_SOPT4_FTM3FLT0_SHIFT                 12
#define SIM_SOPT4_FTM0TRG0SRC_MASK               0x10000u
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              16
#define SIM_SOPT4_FTM0TRG1SRC_MASK               0x20000u
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              17
#define SIM_SOPT4_FTM0TRG2SRC_MASK               0x40000u
#define SIM_SOPT4_FTM0TRG2SRC_SHIFT              18
#define SIM_SOPT4_FTM1TRG0SRC_MASK               0x100000u
#define SIM_SOPT4_FTM1TRG0SRC_SHIFT              20
#define SIM_SOPT4_FTM1TRG2SRC_MASK               0x400000u
#define SIM_SOPT4_FTM1TRG2SRC_SHIFT              22
#define SIM_SOPT4_FTM3TRG0SRC_MASK               0x10000000u
#define SIM_SOPT4_FTM3TRG0SRC_SHIFT              28
#define SIM_SOPT4_FTM3TRG1SRC_MASK               0x20000000u
#define SIM_SOPT4_FTM3TRG1SRC_SHIFT              29
#define SIM_SOPT4_FTM3TRG2SRC_MASK               0x40000000u
#define SIM_SOPT4_FTM3TRG2SRC_SHIFT              30
/* SOPT5 Bit Fields */
#define SIM_SOPT5_UART0TXSRC_MASK                0x1u
#define SIM_SOPT5_UART0TXSRC_SHIFT               0
#define SIM_SOPT5_UART0RXSRC_MASK                0xCu
#define SIM_SOPT5_UART0RXSRC_SHIFT               2
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UART1TXSRC_MASK                0x10u
#define SIM_SOPT5_UART1TXSRC_SHIFT               4
#define SIM_SOPT5_UART1RXSRC_MASK                0xC0u
#define SIM_SOPT5_UART1RXSRC_SHIFT               6
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK)
/* SOPT7 Bit Fields */
#define SIM_SOPT7_ADCATRGSEL_MASK                0xFu
#define SIM_SOPT7_ADCATRGSEL_SHIFT               0
#define SIM_SOPT7_ADCATRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADCATRGSEL_SHIFT))&SIM_SOPT7_ADCATRGSEL_MASK)
#define SIM_SOPT7_ADCAALTTRGEN_MASK              0xC0u
#define SIM_SOPT7_ADCAALTTRGEN_SHIFT             6
#define SIM_SOPT7_ADCAALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADCAALTTRGEN_SHIFT))&SIM_SOPT7_ADCAALTTRGEN_MASK)
#define SIM_SOPT7_ADCBTRGSEL_MASK                0xF00u
#define SIM_SOPT7_ADCBTRGSEL_SHIFT               8
#define SIM_SOPT7_ADCBTRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADCBTRGSEL_SHIFT))&SIM_SOPT7_ADCBTRGSEL_MASK)
#define SIM_SOPT7_ADCBALTTRGEN_MASK              0xC000u
#define SIM_SOPT7_ADCBALTTRGEN_SHIFT             14
#define SIM_SOPT7_ADCBALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADCBALTTRGEN_SHIFT))&SIM_SOPT7_ADCBALTTRGEN_MASK)
/* SOPT8 Bit Fields */
#define SIM_SOPT8_FTM0SYNCBIT_MASK               0x1u
#define SIM_SOPT8_FTM0SYNCBIT_SHIFT              0
#define SIM_SOPT8_FTM1SYNCBIT_MASK               0x2u
#define SIM_SOPT8_FTM1SYNCBIT_SHIFT              1
#define SIM_SOPT8_FTM3SYNCBIT_MASK               0x8u
#define SIM_SOPT8_FTM3SYNCBIT_SHIFT              3
#define SIM_SOPT8_FTM0CFSEL_MASK                 0x100u
#define SIM_SOPT8_FTM0CFSEL_SHIFT                8
#define SIM_SOPT8_FTM3CFSEL_MASK                 0x200u
#define SIM_SOPT8_FTM3CFSEL_SHIFT                9
#define SIM_SOPT8_FTM0OCH0SRC_MASK               0x10000u
#define SIM_SOPT8_FTM0OCH0SRC_SHIFT              16
#define SIM_SOPT8_FTM0OCH1SRC_MASK               0x20000u
#define SIM_SOPT8_FTM0OCH1SRC_SHIFT              17
#define SIM_SOPT8_FTM0OCH2SRC_MASK               0x40000u
#define SIM_SOPT8_FTM0OCH2SRC_SHIFT              18
#define SIM_SOPT8_FTM0OCH3SRC_MASK               0x80000u
#define SIM_SOPT8_FTM0OCH3SRC_SHIFT              19
#define SIM_SOPT8_FTM0OCH4SRC_MASK               0x100000u
#define SIM_SOPT8_FTM0OCH4SRC_SHIFT              20
#define SIM_SOPT8_FTM0OCH5SRC_MASK               0x200000u
#define SIM_SOPT8_FTM0OCH5SRC_SHIFT              21
#define SIM_SOPT8_FTM0OCH6SRC_MASK               0x400000u
#define SIM_SOPT8_FTM0OCH6SRC_SHIFT              22
#define SIM_SOPT8_FTM0OCH7SRC_MASK               0x800000u
#define SIM_SOPT8_FTM0OCH7SRC_SHIFT              23
#define SIM_SOPT8_FTM3OCH0SRC_MASK               0x1000000u
#define SIM_SOPT8_FTM3OCH0SRC_SHIFT              24
#define SIM_SOPT8_FTM3OCH1SRC_MASK               0x2000000u
#define SIM_SOPT8_FTM3OCH1SRC_SHIFT              25
#define SIM_SOPT8_FTM3OCH2SRC_MASK               0x4000000u
#define SIM_SOPT8_FTM3OCH2SRC_SHIFT              26
#define SIM_SOPT8_FTM3OCH3SRC_MASK               0x8000000u
#define SIM_SOPT8_FTM3OCH3SRC_SHIFT              27
#define SIM_SOPT8_FTM3OCH4SRC_MASK               0x10000000u
#define SIM_SOPT8_FTM3OCH4SRC_SHIFT              28
#define SIM_SOPT8_FTM3OCH5SRC_MASK               0x20000000u
#define SIM_SOPT8_FTM3OCH5SRC_SHIFT              29
#define SIM_SOPT8_FTM3OCH6SRC_MASK               0x40000000u
#define SIM_SOPT8_FTM3OCH6SRC_SHIFT              30
#define SIM_SOPT8_FTM3OCH7SRC_MASK               0x80000000u
#define SIM_SOPT8_FTM3OCH7SRC_SHIFT              31
/* SOPT9 Bit Fields */
#define SIM_SOPT9_FTM1ICH0SRC_MASK               0x30u
#define SIM_SOPT9_FTM1ICH0SRC_SHIFT              4
#define SIM_SOPT9_FTM1ICH0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT9_FTM1ICH0SRC_SHIFT))&SIM_SOPT9_FTM1ICH0SRC_MASK)
#define SIM_SOPT9_FTM1ICH1SRC_MASK               0x40u
#define SIM_SOPT9_FTM1ICH1SRC_SHIFT              6
#define SIM_SOPT9_FTM0CLKSEL_MASK                0x3000000u
#define SIM_SOPT9_FTM0CLKSEL_SHIFT               24
#define SIM_SOPT9_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT9_FTM0CLKSEL_SHIFT))&SIM_SOPT9_FTM0CLKSEL_MASK)
#define SIM_SOPT9_FTM1CLKSEL_MASK                0xC000000u
#define SIM_SOPT9_FTM1CLKSEL_SHIFT               26
#define SIM_SOPT9_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT9_FTM1CLKSEL_SHIFT))&SIM_SOPT9_FTM1CLKSEL_MASK)
#define SIM_SOPT9_FTM3CLKSEL_MASK                0xC0000000u
#define SIM_SOPT9_FTM3CLKSEL_SHIFT               30
#define SIM_SOPT9_FTM3CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT9_FTM3CLKSEL_SHIFT))&SIM_SOPT9_FTM3CLKSEL_MASK)
/* SDID Bit Fields */
#define SIM_SDID_PINID_MASK                      0xFu
#define SIM_SDID_PINID_SHIFT                     0
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK)
#define SIM_SDID_DIEID_MASK                      0xF80u
#define SIM_SDID_DIEID_SHIFT                     7
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK                      0xF000u
#define SIM_SDID_REVID_SHIFT                     12
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
#define SIM_SDID_SERIESID_MASK                   0xF00000u
#define SIM_SDID_SERIESID_SHIFT                  20
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK                   0xF000000u
#define SIM_SDID_SUBFAMID_SHIFT                  24
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMILYID_MASK                   0xF0000000u
#define SIM_SDID_FAMILYID_SHIFT                  28
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMILYID_SHIFT))&SIM_SDID_FAMILYID_MASK)
/* SCGC4 Bit Fields */
#define SIM_SCGC4_EWM_MASK                       0x2u
#define SIM_SCGC4_EWM_SHIFT                      1
#define SIM_SCGC4_I2C0_MASK                      0x40u
#define SIM_SCGC4_I2C0_SHIFT                     6
#define SIM_SCGC4_UART0_MASK                     0x400u
#define SIM_SCGC4_UART0_SHIFT                    10
#define SIM_SCGC4_UART1_MASK                     0x800u
#define SIM_SCGC4_UART1_SHIFT                    11
#define SIM_SCGC4_CMP_MASK                       0x80000u
#define SIM_SCGC4_CMP_SHIFT                      19
#define SIM_SCGC4_eFlexPWM0_MASK                 0x1000000u
#define SIM_SCGC4_eFlexPWM0_SHIFT                24
#define SIM_SCGC4_eFlexPWM1_MASK                 0x2000000u
#define SIM_SCGC4_eFlexPWM1_SHIFT                25
#define SIM_SCGC4_eFlexPWM2_MASK                 0x4000000u
#define SIM_SCGC4_eFlexPWM2_SHIFT                26
#define SIM_SCGC4_eFlexPWM3_MASK                 0x8000000u
#define SIM_SCGC4_eFlexPWM3_SHIFT                27
/* SCGC5 Bit Fields */
#define SIM_SCGC5_LPTMR_MASK                     0x1u
#define SIM_SCGC5_LPTMR_SHIFT                    0
#define SIM_SCGC5_PORTA_MASK                     0x200u
#define SIM_SCGC5_PORTA_SHIFT                    9
#define SIM_SCGC5_PORTB_MASK                     0x400u
#define SIM_SCGC5_PORTB_SHIFT                    10
#define SIM_SCGC5_PORTC_MASK                     0x800u
#define SIM_SCGC5_PORTC_SHIFT                    11
#define SIM_SCGC5_PORTD_MASK                     0x1000u
#define SIM_SCGC5_PORTD_SHIFT                    12
#define SIM_SCGC5_PORTE_MASK                     0x2000u
#define SIM_SCGC5_PORTE_SHIFT                    13
#define SIM_SCGC5_ENC_MASK                       0x200000u
#define SIM_SCGC5_ENC_SHIFT                      21
#define SIM_SCGC5_XBARA_MASK                     0x2000000u
#define SIM_SCGC5_XBARA_SHIFT                    25
#define SIM_SCGC5_XBARB_MASK                     0x4000000u
#define SIM_SCGC5_XBARB_SHIFT                    26
#define SIM_SCGC5_AOI_MASK                       0x8000000u
#define SIM_SCGC5_AOI_SHIFT                      27
#define SIM_SCGC5_ADC_MASK                       0x10000000u
#define SIM_SCGC5_ADC_SHIFT                      28
/* SCGC6 Bit Fields */
#define SIM_SCGC6_FTF_MASK                       0x1u
#define SIM_SCGC6_FTF_SHIFT                      0
#define SIM_SCGC6_DMAMUX_MASK                    0x2u
#define SIM_SCGC6_DMAMUX_SHIFT                   1
#define SIM_SCGC6_FLEXCAN0_MASK                  0x10u
#define SIM_SCGC6_FLEXCAN0_SHIFT                 4
#define SIM_SCGC6_FLEXCAN1_MASK                  0x20u
#define SIM_SCGC6_FLEXCAN1_SHIFT                 5
#define SIM_SCGC6_FTM3_MASK                      0x40u
#define SIM_SCGC6_FTM3_SHIFT                     6
#define SIM_SCGC6_SPI0_MASK                      0x1000u
#define SIM_SCGC6_SPI0_SHIFT                     12
#define SIM_SCGC6_PDB1_MASK                      0x20000u
#define SIM_SCGC6_PDB1_SHIFT                     17
#define SIM_SCGC6_CRC_MASK                       0x40000u
#define SIM_SCGC6_CRC_SHIFT                      18
#define SIM_SCGC6_PDB0_MASK                      0x400000u
#define SIM_SCGC6_PDB0_SHIFT                     22
#define SIM_SCGC6_PIT_MASK                       0x800000u
#define SIM_SCGC6_PIT_SHIFT                      23
#define SIM_SCGC6_FTM0_MASK                      0x1000000u
#define SIM_SCGC6_FTM0_SHIFT                     24
#define SIM_SCGC6_FTM1_MASK                      0x2000000u
#define SIM_SCGC6_FTM1_SHIFT                     25
#define SIM_SCGC6_DAC0_MASK                      0x80000000u
#define SIM_SCGC6_DAC0_SHIFT                     31
/* SCGC7 Bit Fields */
#define SIM_SCGC7_DMA_MASK                       0x100u
#define SIM_SCGC7_DMA_SHIFT                      8
/* CLKDIV1 Bit Fields */
#define SIM_CLKDIV1_OUTDIV4_MASK                 0xF0000u
#define SIM_CLKDIV1_OUTDIV4_SHIFT                16
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV2_MASK                 0xF000000u
#define SIM_CLKDIV1_OUTDIV2_SHIFT                24
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV2_SHIFT))&SIM_CLKDIV1_OUTDIV2_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 0xF0000000u
#define SIM_CLKDIV1_OUTDIV1_SHIFT                28
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_FLASHDIS_MASK                  0x1u
#define SIM_FCFG1_FLASHDIS_SHIFT                 0
#define SIM_FCFG1_FLASHDOZE_MASK                 0x2u
#define SIM_FCFG1_FLASHDOZE_SHIFT                1
#define SIM_FCFG1_PFSIZE_MASK                    0xF000000u
#define SIM_FCFG1_PFSIZE_SHIFT                   24
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK)
/* FCFG2 Bit Fields */
#define SIM_FCFG2_MAXADDR0_MASK                  0x7F000000u
#define SIM_FCFG2_MAXADDR0_SHIFT                 24
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK)
/* UIDH Bit Fields */
#define SIM_UIDH_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDH_UID_SHIFT                       0
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDH_UID_SHIFT))&SIM_UIDH_UID_MASK)
/* UIDMH Bit Fields */
#define SIM_UIDMH_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDMH_UID_SHIFT                      0
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK)
/* UIDML Bit Fields */
#define SIM_UIDML_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDML_UID_SHIFT                      0
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK)
/* UIDL Bit Fields */
#define SIM_UIDL_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDL_UID_SHIFT                       0
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK)
/* CLKDIV4 Bit Fields */
#define SIM_CLKDIV4_TRACEFRAC_MASK               0x1u
#define SIM_CLKDIV4_TRACEFRAC_SHIFT              0
#define SIM_CLKDIV4_TRACEDIV_MASK                0xEu
#define SIM_CLKDIV4_TRACEDIV_SHIFT               1
#define SIM_CLKDIV4_TRACEDIV(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV4_TRACEDIV_SHIFT))&SIM_CLKDIV4_TRACEDIV_MASK)
#define SIM_CLKDIV4_TRACEDIVEN_MASK              0x10000000u
#define SIM_CLKDIV4_TRACEDIVEN_SHIFT             28
/* MISCTRL Bit Fields */
#define SIM_MISCTRL_CMPWIN0SRC_MASK              0x300u
#define SIM_MISCTRL_CMPWIN0SRC_SHIFT             8
#define SIM_MISCTRL_CMPWIN0SRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISCTRL_CMPWIN0SRC_SHIFT))&SIM_MISCTRL_CMPWIN0SRC_MASK)
#define SIM_MISCTRL_CMPWIN1SRC_MASK              0xC00u
#define SIM_MISCTRL_CMPWIN1SRC_SHIFT             10
#define SIM_MISCTRL_CMPWIN1SRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISCTRL_CMPWIN1SRC_SHIFT))&SIM_MISCTRL_CMPWIN1SRC_MASK)
#define SIM_MISCTRL_CMPWIN2SRC_MASK              0x3000u
#define SIM_MISCTRL_CMPWIN2SRC_SHIFT             12
#define SIM_MISCTRL_CMPWIN2SRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISCTRL_CMPWIN2SRC_SHIFT))&SIM_MISCTRL_CMPWIN2SRC_MASK)
#define SIM_MISCTRL_CMPWIN3SRC_MASK              0xC000u
#define SIM_MISCTRL_CMPWIN3SRC_SHIFT             14
#define SIM_MISCTRL_CMPWIN3SRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISCTRL_CMPWIN3SRC_SHIFT))&SIM_MISCTRL_CMPWIN3SRC_MASK)
#define SIM_MISCTRL_EWMINSRC_MASK                0x10000u
#define SIM_MISCTRL_EWMINSRC_SHIFT               16
#define SIM_MISCTRL_DACTRIGSRC_MASK              0xC0000u
#define SIM_MISCTRL_DACTRIGSRC_SHIFT             18
#define SIM_MISCTRL_DACTRIGSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISCTRL_DACTRIGSRC_SHIFT))&SIM_MISCTRL_DACTRIGSRC_MASK)
/* MISCTRL2 Bit Fields */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG0_MASK      0x100u
#define SIM_MISCTRL2_SYNCXBARAPITTRIG0_SHIFT     8
#define SIM_MISCTRL2_SYNCXBARAPITTRIG1_MASK      0x200u
#define SIM_MISCTRL2_SYNCXBARAPITTRIG1_SHIFT     9
#define SIM_MISCTRL2_SYNCXBARAPITTRIG2_MASK      0x400u
#define SIM_MISCTRL2_SYNCXBARAPITTRIG2_SHIFT     10
#define SIM_MISCTRL2_SYNCXBARAPITTRIG3_MASK      0x800u
#define SIM_MISCTRL2_SYNCXBARAPITTRIG3_SHIFT     11
#define SIM_MISCTRL2_SYNCXBARBPITTRIG0_MASK      0x1000u
#define SIM_MISCTRL2_SYNCXBARBPITTRIG0_SHIFT     12
#define SIM_MISCTRL2_SYNCXBARBPITTRIG1_MASK      0x2000u
#define SIM_MISCTRL2_SYNCXBARBPITTRIG1_SHIFT     13
#define SIM_MISCTRL2_SYNCDACHWTRIG_MASK          0x10000u
#define SIM_MISCTRL2_SYNCDACHWTRIG_SHIFT         16
#define SIM_MISCTRL2_SYNCEWMIN_MASK              0x20000u
#define SIM_MISCTRL2_SYNCEWMIN_SHIFT             17
#define SIM_MISCTRL2_SYNCCMP0SAMPLEWIN_MASK      0x100000u
#define SIM_MISCTRL2_SYNCCMP0SAMPLEWIN_SHIFT     20
#define SIM_MISCTRL2_SYNCCMP1SAMPLEWIN_MASK      0x200000u
#define SIM_MISCTRL2_SYNCCMP1SAMPLEWIN_SHIFT     21
#define SIM_MISCTRL2_SYNCCMP2SAMPLEWIN_MASK      0x400000u
#define SIM_MISCTRL2_SYNCCMP2SAMPLEWIN_SHIFT     22
#define SIM_MISCTRL2_SYNCCMP3SAMPLEWIN_MASK      0x800000u
#define SIM_MISCTRL2_SYNCCMP3SAMPLEWIN_SHIFT     23
/* WDOGC Bit Fields */
#define SIM_WDOGC_WDOGCLKS_MASK                  0x2u
#define SIM_WDOGC_WDOGCLKS_SHIFT                 1
/* PWRC Bit Fields */
#define SIM_PWRC_SRPDN_MASK                      0x3u
#define SIM_PWRC_SRPDN_SHIFT                     0
#define SIM_PWRC_SRPDN(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_PWRC_SRPDN_SHIFT))&SIM_PWRC_SRPDN_MASK)
#define SIM_PWRC_SR27STDBY_MASK                  0xCu
#define SIM_PWRC_SR27STDBY_SHIFT                 2
#define SIM_PWRC_SR27STDBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PWRC_SR27STDBY_SHIFT))&SIM_PWRC_SR27STDBY_MASK)
#define SIM_PWRC_SR12STDBY_MASK                  0xC0u
#define SIM_PWRC_SR12STDBY_SHIFT                 6
#define SIM_PWRC_SR12STDBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PWRC_SR12STDBY_SHIFT))&SIM_PWRC_SR12STDBY_MASK)
#define SIM_PWRC_SRPWRDETEN_MASK                 0x100u
#define SIM_PWRC_SRPWRDETEN_SHIFT                8
#define SIM_PWRC_SRPWRRDY_MASK                   0x200u
#define SIM_PWRC_SRPWRRDY_SHIFT                  9
#define SIM_PWRC_SRPWROK_MASK                    0x10000u
#define SIM_PWRC_SRPWROK_SHIFT                   16
/* ADCOPT Bit Fields */
#define SIM_ADCOPT_ADCACH6SEL_MASK               0x7u
#define SIM_ADCOPT_ADCACH6SEL_SHIFT              0
#define SIM_ADCOPT_ADCACH6SEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_ADCOPT_ADCACH6SEL_SHIFT))&SIM_ADCOPT_ADCACH6SEL_MASK)
#define SIM_ADCOPT_ADCACH7SEL_MASK               0x70u
#define SIM_ADCOPT_ADCACH7SEL_SHIFT              4
#define SIM_ADCOPT_ADCACH7SEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_ADCOPT_ADCACH7SEL_SHIFT))&SIM_ADCOPT_ADCACH7SEL_MASK)
#define SIM_ADCOPT_ADCBCH6SEL_MASK               0x700u
#define SIM_ADCOPT_ADCBCH6SEL_SHIFT              8
#define SIM_ADCOPT_ADCBCH6SEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_ADCOPT_ADCBCH6SEL_SHIFT))&SIM_ADCOPT_ADCBCH6SEL_MASK)
#define SIM_ADCOPT_ADCBCH7SEL_MASK               0x7000u
#define SIM_ADCOPT_ADCBCH7SEL_SHIFT              12
#define SIM_ADCOPT_ADCBCH7SEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_ADCOPT_ADCBCH7SEL_SHIFT))&SIM_ADCOPT_ADCBCH7SEL_MASK)
#define SIM_ADCOPT_ROSB_MASK                     0x1000000u
#define SIM_ADCOPT_ROSB_SHIFT                    24
#define SIM_ADCOPT_ADCIRCLK_MASK                 0x2000000u
#define SIM_ADCOPT_ADCIRCLK_SHIFT                25

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base pointer */
#define SIM_BASE_PTR                             ((SIM_MemMapPtr)0x40047000u)
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SOPT1                                SIM_SOPT1_REG(SIM_BASE_PTR)
#define SIM_SOPT2                                SIM_SOPT2_REG(SIM_BASE_PTR)
#define SIM_SOPT4                                SIM_SOPT4_REG(SIM_BASE_PTR)
#define SIM_SOPT5                                SIM_SOPT5_REG(SIM_BASE_PTR)
#define SIM_SOPT7                                SIM_SOPT7_REG(SIM_BASE_PTR)
#define SIM_SOPT8                                SIM_SOPT8_REG(SIM_BASE_PTR)
#define SIM_SOPT9                                SIM_SOPT9_REG(SIM_BASE_PTR)
#define SIM_SDID                                 SIM_SDID_REG(SIM_BASE_PTR)
#define SIM_SCGC4                                SIM_SCGC4_REG(SIM_BASE_PTR)
#define SIM_SCGC5                                SIM_SCGC5_REG(SIM_BASE_PTR)
#define SIM_SCGC6                                SIM_SCGC6_REG(SIM_BASE_PTR)
#define SIM_SCGC7                                SIM_SCGC7_REG(SIM_BASE_PTR)
#define SIM_CLKDIV1                              SIM_CLKDIV1_REG(SIM_BASE_PTR)
#define SIM_FCFG1                                SIM_FCFG1_REG(SIM_BASE_PTR)
#define SIM_FCFG2                                SIM_FCFG2_REG(SIM_BASE_PTR)
#define SIM_UIDH                                 SIM_UIDH_REG(SIM_BASE_PTR)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM_BASE_PTR)
#define SIM_UIDML                                SIM_UIDML_REG(SIM_BASE_PTR)
#define SIM_UIDL                                 SIM_UIDL_REG(SIM_BASE_PTR)
#define SIM_CLKDIV4                              SIM_CLKDIV4_REG(SIM_BASE_PTR)
#define SIM_MISCTRL                              SIM_MISCTRL_REG(SIM_BASE_PTR)
#define SIM_MISCTRL2                             SIM_MISCTRL2_REG(SIM_BASE_PTR)
#define SIM_WDOGC                                SIM_WDOGC_REG(SIM_BASE_PTR)
#define SIM_PWRC                                 SIM_PWRC_REG(SIM_BASE_PTR)
#define SIM_ADCOPT                               SIM_ADCOPT_REG(SIM_BASE_PTR)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- SMC
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral SMC
 * @{
 */

/** SMC - Peripheral register structure */
typedef struct SMC_MemMap {
  uint8_t PMPROT;                                  /**< Power Mode Protection register, offset: 0x0 */
  uint8_t PMCTRL;                                  /**< Power Mode Control register, offset: 0x1 */
  uint8_t STOPCTRL;                                /**< Stop Control Register, offset: 0x2 */
  uint8_t PMSTAT;                                  /**< Power Mode Status register, offset: 0x3 */
} volatile *SMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register accessors */
#define SMC_PMPROT_REG(base)                     ((base)->PMPROT)
#define SMC_PMCTRL_REG(base)                     ((base)->PMCTRL)
#define SMC_STOPCTRL_REG(base)                   ((base)->STOPCTRL)
#define SMC_PMSTAT_REG(base)                     ((base)->PMSTAT)

/*!
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLLS_MASK                    0x2u
#define SMC_PMPROT_AVLLS_SHIFT                   1
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5
#define SMC_PMPROT_AHSRUN_MASK                   0x80u
#define SMC_PMPROT_AHSRUN_SHIFT                  7
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    0x8u
#define SMC_PMCTRL_STOPA_SHIFT                   3
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
/* STOPCTRL Bit Fields */
#define SMC_STOPCTRL_VLLSM_MASK                  0x7u
#define SMC_STOPCTRL_VLLSM_SHIFT                 0
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK)
#define SMC_STOPCTRL_LPOPO_MASK                  0x8u
#define SMC_STOPCTRL_LPOPO_SHIFT                 3
#define SMC_STOPCTRL_RAM2PO_MASK                 0x10u
#define SMC_STOPCTRL_RAM2PO_SHIFT                4
#define SMC_STOPCTRL_PORPO_MASK                  0x20u
#define SMC_STOPCTRL_PORPO_SHIFT                 5
#define SMC_STOPCTRL_PSTOPO_MASK                 0xC0u
#define SMC_STOPCTRL_PSTOPO_SHIFT                6
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK)
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0xFFu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base pointer */
#define SMC_BASE_PTR                             ((SMC_MemMapPtr)0x4007E000u)
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register instance definitions */
/* SMC */
#define SMC_PMPROT                               SMC_PMPROT_REG(SMC_BASE_PTR)
#define SMC_PMCTRL                               SMC_PMCTRL_REG(SMC_BASE_PTR)
#define SMC_STOPCTRL                             SMC_STOPCTRL_REG(SMC_BASE_PTR)
#define SMC_PMSTAT                               SMC_PMSTAT_REG(SMC_BASE_PTR)

/*!
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SPI
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral SPI
 * @{
 */

/** SPI - Peripheral register structure */
typedef struct SPI_MemMap {
  uint32_t MCR;                                    /**< Module Configuration Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  uint32_t TCR;                                    /**< Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    uint32_t CTAR[2];                                /**< Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    uint32_t CTAR_SLAVE[1];                          /**< Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
  uint8_t RESERVED_1[24];
  uint32_t SR;                                     /**< Status Register, offset: 0x2C */
  uint32_t RSER;                                   /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    uint32_t PUSHR;                                  /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    uint32_t PUSHR_SLAVE;                            /**< PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  uint32_t POPR;                                   /**< POP RX FIFO Register, offset: 0x38 */
  uint32_t TXFR0;                                  /**< Transmit FIFO Registers, offset: 0x3C */
  uint32_t TXFR1;                                  /**< Transmit FIFO Registers, offset: 0x40 */
  uint32_t TXFR2;                                  /**< Transmit FIFO Registers, offset: 0x44 */
  uint32_t TXFR3;                                  /**< Transmit FIFO Registers, offset: 0x48 */
  uint8_t RESERVED_2[48];
  uint32_t RXFR0;                                  /**< Receive FIFO Registers, offset: 0x7C */
  uint32_t RXFR1;                                  /**< Receive FIFO Registers, offset: 0x80 */
  uint32_t RXFR2;                                  /**< Receive FIFO Registers, offset: 0x84 */
  uint32_t RXFR3;                                  /**< Receive FIFO Registers, offset: 0x88 */
  uint8_t RESERVED_3[176];
  uint32_t SREX;                                   /**< Status Register Extended, offset: 0x13C */
} volatile *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register accessors */
#define SPI_MCR_REG(base)                        ((base)->MCR)
#define SPI_TCR_REG(base)                        ((base)->TCR)
#define SPI_CTAR_REG(base,index2)                ((base)->CTAR[index2])
#define SPI_CTAR_SLAVE_REG(base,index2)          ((base)->CTAR_SLAVE[index2])
#define SPI_SR_REG(base)                         ((base)->SR)
#define SPI_RSER_REG(base)                       ((base)->RSER)
#define SPI_PUSHR_REG(base)                      ((base)->PUSHR)
#define SPI_PUSHR_SLAVE_REG(base)                ((base)->PUSHR_SLAVE)
#define SPI_POPR_REG(base)                       ((base)->POPR)
#define SPI_TXFR0_REG(base)                      ((base)->TXFR0)
#define SPI_TXFR1_REG(base)                      ((base)->TXFR1)
#define SPI_TXFR2_REG(base)                      ((base)->TXFR2)
#define SPI_TXFR3_REG(base)                      ((base)->TXFR3)
#define SPI_RXFR0_REG(base)                      ((base)->RXFR0)
#define SPI_RXFR1_REG(base)                      ((base)->RXFR1)
#define SPI_RXFR2_REG(base)                      ((base)->RXFR2)
#define SPI_RXFR3_REG(base)                      ((base)->RXFR3)
#define SPI_SREX_REG(base)                       ((base)->SREX)

/*!
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* MCR Bit Fields */
#define SPI_MCR_HALT_MASK                        0x1u
#define SPI_MCR_HALT_SHIFT                       0
#define SPI_MCR_SMPL_PT_MASK                     0x300u
#define SPI_MCR_SMPL_PT_SHIFT                    8
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_SMPL_PT_SHIFT))&SPI_MCR_SMPL_PT_MASK)
#define SPI_MCR_CLR_RXF_MASK                     0x400u
#define SPI_MCR_CLR_RXF_SHIFT                    10
#define SPI_MCR_CLR_TXF_MASK                     0x800u
#define SPI_MCR_CLR_TXF_SHIFT                    11
#define SPI_MCR_DIS_RXF_MASK                     0x1000u
#define SPI_MCR_DIS_RXF_SHIFT                    12
#define SPI_MCR_DIS_TXF_MASK                     0x2000u
#define SPI_MCR_DIS_TXF_SHIFT                    13
#define SPI_MCR_MDIS_MASK                        0x4000u
#define SPI_MCR_MDIS_SHIFT                       14
#define SPI_MCR_DOZE_MASK                        0x8000u
#define SPI_MCR_DOZE_SHIFT                       15
#define SPI_MCR_PCSIS_MASK                       0x3F0000u
#define SPI_MCR_PCSIS_SHIFT                      16
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_PCSIS_SHIFT))&SPI_MCR_PCSIS_MASK)
#define SPI_MCR_ROOE_MASK                        0x1000000u
#define SPI_MCR_ROOE_SHIFT                       24
#define SPI_MCR_PCSSE_MASK                       0x2000000u
#define SPI_MCR_PCSSE_SHIFT                      25
#define SPI_MCR_MTFE_MASK                        0x4000000u
#define SPI_MCR_MTFE_SHIFT                       26
#define SPI_MCR_FRZ_MASK                         0x8000000u
#define SPI_MCR_FRZ_SHIFT                        27
#define SPI_MCR_DCONF_MASK                       0x30000000u
#define SPI_MCR_DCONF_SHIFT                      28
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DCONF_SHIFT))&SPI_MCR_DCONF_MASK)
#define SPI_MCR_CONT_SCKE_MASK                   0x40000000u
#define SPI_MCR_CONT_SCKE_SHIFT                  30
#define SPI_MCR_MSTR_MASK                        0x80000000u
#define SPI_MCR_MSTR_SHIFT                       31
/* TCR Bit Fields */
#define SPI_TCR_SPI_TCNT_MASK                    0xFFFF0000u
#define SPI_TCR_SPI_TCNT_SHIFT                   16
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TCR_SPI_TCNT_SHIFT))&SPI_TCR_SPI_TCNT_MASK)
/* CTAR Bit Fields */
#define SPI_CTAR_BR_MASK                         0xFu
#define SPI_CTAR_BR_SHIFT                        0
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_BR_SHIFT))&SPI_CTAR_BR_MASK)
#define SPI_CTAR_DT_MASK                         0xF0u
#define SPI_CTAR_DT_SHIFT                        4
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DT_SHIFT))&SPI_CTAR_DT_MASK)
#define SPI_CTAR_ASC_MASK                        0xF00u
#define SPI_CTAR_ASC_SHIFT                       8
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_ASC_SHIFT))&SPI_CTAR_ASC_MASK)
#define SPI_CTAR_CSSCK_MASK                      0xF000u
#define SPI_CTAR_CSSCK_SHIFT                     12
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CSSCK_SHIFT))&SPI_CTAR_CSSCK_MASK)
#define SPI_CTAR_PBR_MASK                        0x30000u
#define SPI_CTAR_PBR_SHIFT                       16
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PBR_SHIFT))&SPI_CTAR_PBR_MASK)
#define SPI_CTAR_PDT_MASK                        0xC0000u
#define SPI_CTAR_PDT_SHIFT                       18
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PDT_SHIFT))&SPI_CTAR_PDT_MASK)
#define SPI_CTAR_PASC_MASK                       0x300000u
#define SPI_CTAR_PASC_SHIFT                      20
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PASC_SHIFT))&SPI_CTAR_PASC_MASK)
#define SPI_CTAR_PCSSCK_MASK                     0xC00000u
#define SPI_CTAR_PCSSCK_SHIFT                    22
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PCSSCK_SHIFT))&SPI_CTAR_PCSSCK_MASK)
#define SPI_CTAR_LSBFE_MASK                      0x1000000u
#define SPI_CTAR_LSBFE_SHIFT                     24
#define SPI_CTAR_CPHA_MASK                       0x2000000u
#define SPI_CTAR_CPHA_SHIFT                      25
#define SPI_CTAR_CPOL_MASK                       0x4000000u
#define SPI_CTAR_CPOL_SHIFT                      26
#define SPI_CTAR_FMSZ_MASK                       0x78000000u
#define SPI_CTAR_FMSZ_SHIFT                      27
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_FMSZ_SHIFT))&SPI_CTAR_FMSZ_MASK)
#define SPI_CTAR_DBR_MASK                        0x80000000u
#define SPI_CTAR_DBR_SHIFT                       31
/* CTAR_SLAVE Bit Fields */
#define SPI_CTAR_SLAVE_CPHA_MASK                 0x2000000u
#define SPI_CTAR_SLAVE_CPHA_SHIFT                25
#define SPI_CTAR_SLAVE_CPOL_MASK                 0x4000000u
#define SPI_CTAR_SLAVE_CPOL_SHIFT                26
#define SPI_CTAR_SLAVE_FMSZ_MASK                 0xF8000000u
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                27
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_FMSZ_SHIFT))&SPI_CTAR_SLAVE_FMSZ_MASK)
/* SR Bit Fields */
#define SPI_SR_POPNXTPTR_MASK                    0xFu
#define SPI_SR_POPNXTPTR_SHIFT                   0
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_SR_POPNXTPTR_SHIFT))&SPI_SR_POPNXTPTR_MASK)
#define SPI_SR_RXCTR_MASK                        0xF0u
#define SPI_SR_RXCTR_SHIFT                       4
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_RXCTR_SHIFT))&SPI_SR_RXCTR_MASK)
#define SPI_SR_TXNXTPTR_MASK                     0xF00u
#define SPI_SR_TXNXTPTR_SHIFT                    8
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXNXTPTR_SHIFT))&SPI_SR_TXNXTPTR_MASK)
#define SPI_SR_TXCTR_MASK                        0xF000u
#define SPI_SR_TXCTR_SHIFT                       12
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXCTR_SHIFT))&SPI_SR_TXCTR_MASK)
#define SPI_SR_RFDF_MASK                         0x20000u
#define SPI_SR_RFDF_SHIFT                        17
#define SPI_SR_RFOF_MASK                         0x80000u
#define SPI_SR_RFOF_SHIFT                        19
#define SPI_SR_TFFF_MASK                         0x2000000u
#define SPI_SR_TFFF_SHIFT                        25
#define SPI_SR_TFUF_MASK                         0x8000000u
#define SPI_SR_TFUF_SHIFT                        27
#define SPI_SR_EOQF_MASK                         0x10000000u
#define SPI_SR_EOQF_SHIFT                        28
#define SPI_SR_TXRXS_MASK                        0x40000000u
#define SPI_SR_TXRXS_SHIFT                       30
#define SPI_SR_TCF_MASK                          0x80000000u
#define SPI_SR_TCF_SHIFT                         31
/* RSER Bit Fields */
#define SPI_RSER_RFDF_DIRS_MASK                  0x10000u
#define SPI_RSER_RFDF_DIRS_SHIFT                 16
#define SPI_RSER_RFDF_RE_MASK                    0x20000u
#define SPI_RSER_RFDF_RE_SHIFT                   17
#define SPI_RSER_RFOF_RE_MASK                    0x80000u
#define SPI_RSER_RFOF_RE_SHIFT                   19
#define SPI_RSER_TFFF_DIRS_MASK                  0x1000000u
#define SPI_RSER_TFFF_DIRS_SHIFT                 24
#define SPI_RSER_TFFF_RE_MASK                    0x2000000u
#define SPI_RSER_TFFF_RE_SHIFT                   25
#define SPI_RSER_TFUF_RE_MASK                    0x8000000u
#define SPI_RSER_TFUF_RE_SHIFT                   27
#define SPI_RSER_EOQF_RE_MASK                    0x10000000u
#define SPI_RSER_EOQF_RE_SHIFT                   28
#define SPI_RSER_TCF_RE_MASK                     0x80000000u
#define SPI_RSER_TCF_RE_SHIFT                    31
/* PUSHR Bit Fields */
#define SPI_PUSHR_TXDATA_MASK                    0xFFFFu
#define SPI_PUSHR_TXDATA_SHIFT                   0
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_TXDATA_SHIFT))&SPI_PUSHR_TXDATA_MASK)
#define SPI_PUSHR_PCS_MASK                       0x3F0000u
#define SPI_PUSHR_PCS_SHIFT                      16
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_PCS_SHIFT))&SPI_PUSHR_PCS_MASK)
#define SPI_PUSHR_CTCNT_MASK                     0x4000000u
#define SPI_PUSHR_CTCNT_SHIFT                    26
#define SPI_PUSHR_EOQ_MASK                       0x8000000u
#define SPI_PUSHR_EOQ_SHIFT                      27
#define SPI_PUSHR_CTAS_MASK                      0x70000000u
#define SPI_PUSHR_CTAS_SHIFT                     28
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTAS_SHIFT))&SPI_PUSHR_CTAS_MASK)
#define SPI_PUSHR_CONT_MASK                      0x80000000u
#define SPI_PUSHR_CONT_SHIFT                     31
/* PUSHR_SLAVE Bit Fields */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              0xFFFFu
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             0
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_SLAVE_TXDATA_SHIFT))&SPI_PUSHR_SLAVE_TXDATA_MASK)
/* POPR Bit Fields */
#define SPI_POPR_RXDATA_MASK                     0xFFFFFFFFu
#define SPI_POPR_RXDATA_SHIFT                    0
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_POPR_RXDATA_SHIFT))&SPI_POPR_RXDATA_MASK)
/* TXFR0 Bit Fields */
#define SPI_TXFR0_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR0_TXDATA_SHIFT                   0
#define SPI_TXFR0_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR0_TXDATA_SHIFT))&SPI_TXFR0_TXDATA_MASK)
#define SPI_TXFR0_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR0_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR0_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR0_TXCMD_TXDATA_SHIFT))&SPI_TXFR0_TXCMD_TXDATA_MASK)
/* TXFR1 Bit Fields */
#define SPI_TXFR1_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR1_TXDATA_SHIFT                   0
#define SPI_TXFR1_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR1_TXDATA_SHIFT))&SPI_TXFR1_TXDATA_MASK)
#define SPI_TXFR1_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR1_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR1_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR1_TXCMD_TXDATA_SHIFT))&SPI_TXFR1_TXCMD_TXDATA_MASK)
/* TXFR2 Bit Fields */
#define SPI_TXFR2_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR2_TXDATA_SHIFT                   0
#define SPI_TXFR2_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR2_TXDATA_SHIFT))&SPI_TXFR2_TXDATA_MASK)
#define SPI_TXFR2_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR2_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR2_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR2_TXCMD_TXDATA_SHIFT))&SPI_TXFR2_TXCMD_TXDATA_MASK)
/* TXFR3 Bit Fields */
#define SPI_TXFR3_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR3_TXDATA_SHIFT                   0
#define SPI_TXFR3_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR3_TXDATA_SHIFT))&SPI_TXFR3_TXDATA_MASK)
#define SPI_TXFR3_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR3_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR3_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR3_TXCMD_TXDATA_SHIFT))&SPI_TXFR3_TXCMD_TXDATA_MASK)
/* RXFR0 Bit Fields */
#define SPI_RXFR0_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR0_RXDATA_SHIFT                   0
#define SPI_RXFR0_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR0_RXDATA_SHIFT))&SPI_RXFR0_RXDATA_MASK)
/* RXFR1 Bit Fields */
#define SPI_RXFR1_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR1_RXDATA_SHIFT                   0
#define SPI_RXFR1_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR1_RXDATA_SHIFT))&SPI_RXFR1_RXDATA_MASK)
/* RXFR2 Bit Fields */
#define SPI_RXFR2_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR2_RXDATA_SHIFT                   0
#define SPI_RXFR2_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR2_RXDATA_SHIFT))&SPI_RXFR2_RXDATA_MASK)
/* RXFR3 Bit Fields */
#define SPI_RXFR3_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR3_RXDATA_SHIFT                   0
#define SPI_RXFR3_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR3_RXDATA_SHIFT))&SPI_RXFR3_RXDATA_MASK)
/* SREX Bit Fields */
#define SPI_SREX_CMDNXTPTR_MASK                  0xFu
#define SPI_SREX_CMDNXTPTR_SHIFT                 0
#define SPI_SREX_CMDNXTPTR(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_SREX_CMDNXTPTR_SHIFT))&SPI_SREX_CMDNXTPTR_MASK)
#define SPI_SREX_CMDCTR_MASK                     0x1F0u
#define SPI_SREX_CMDCTR_SHIFT                    4
#define SPI_SREX_CMDCTR(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_SREX_CMDCTR_SHIFT))&SPI_SREX_CMDCTR_MASK)
#define SPI_SREX_TXCTR4_MASK                     0x800u
#define SPI_SREX_TXCTR4_SHIFT                    11
#define SPI_SREX_RXCTR4_MASK                     0x4000u
#define SPI_SREX_RXCTR4_SHIFT                    14

/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI base pointer */
#define SPI_BASE_PTR                             ((SPI_MemMapPtr)0x4002C000u)
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register instance definitions */
/* SPI */
#define SPI_MCR                                  SPI_MCR_REG(SPI_BASE_PTR)
#define SPI_TCR                                  SPI_TCR_REG(SPI_BASE_PTR)
#define SPI_CTAR0                                SPI_CTAR_REG(SPI_BASE_PTR,0)
#define SPI_CTAR0_SLAVE                          SPI_CTAR_SLAVE_REG(SPI_BASE_PTR,0)
#define SPI_CTAR1                                SPI_CTAR_REG(SPI_BASE_PTR,1)
#define SPI_SR                                   SPI_SR_REG(SPI_BASE_PTR)
#define SPI_RSER                                 SPI_RSER_REG(SPI_BASE_PTR)
#define SPI_PUSHR                                SPI_PUSHR_REG(SPI_BASE_PTR)
#define SPI_PUSHR_SLAVE                          SPI_PUSHR_SLAVE_REG(SPI_BASE_PTR)
#define SPI_POPR                                 SPI_POPR_REG(SPI_BASE_PTR)
#define SPI_TXFR0                                SPI_TXFR0_REG(SPI_BASE_PTR)
#define SPI_TXFR1                                SPI_TXFR1_REG(SPI_BASE_PTR)
#define SPI_TXFR2                                SPI_TXFR2_REG(SPI_BASE_PTR)
#define SPI_TXFR3                                SPI_TXFR3_REG(SPI_BASE_PTR)
#define SPI_RXFR0                                SPI_RXFR0_REG(SPI_BASE_PTR)
#define SPI_RXFR1                                SPI_RXFR1_REG(SPI_BASE_PTR)
#define SPI_RXFR2                                SPI_RXFR2_REG(SPI_BASE_PTR)
#define SPI_RXFR3                                SPI_RXFR3_REG(SPI_BASE_PTR)
#define SPI_SREX                                 SPI_SREX_REG(SPI_BASE_PTR)

/* SPI - Register array accessors */
#define SPI_CTAR(index2)                         SPI_CTAR_REG(SPI_BASE_PTR,index2)
#define SPI_CTAR_SLAVE(index2)                   SPI_CTAR_SLAVE_REG(SPI_BASE_PTR,index2)

/*!
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SPI_Peripheral */


/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Peripheral SysTick
 * @{
 */

/** SysTick - Peripheral register structure */
typedef struct SysTick_MemMap {
  uint32_t CSR;                                    /**< SysTick Control and Status Register, offset: 0x0 */
  uint32_t RVR;                                    /**< SysTick Reload Value Register, offset: 0x4 */
  uint32_t CVR;                                    /**< SysTick Current Value Register, offset: 0x8 */
  uint32_t CALIB;                                  /**< SysTick Calibration Value Register, offset: 0xC */
} volatile *SysTick_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register accessors */
#define SysTick_CSR_REG(base)                    ((base)->CSR)
#define SysTick_RVR_REG(base)                    ((base)->RVR)
#define SysTick_CVR_REG(base)                    ((base)->CVR)
#define SysTick_CALIB_REG(base)                  ((base)->CALIB)

/*!
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SysTick Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Masks SysTick Register Masks
 * @{
 */

/* CSR Bit Fields */
#define SysTick_CSR_ENABLE_MASK                  0x1u
#define SysTick_CSR_ENABLE_SHIFT                 0
#define SysTick_CSR_TICKINT_MASK                 0x2u
#define SysTick_CSR_TICKINT_SHIFT                1
#define SysTick_CSR_CLKSOURCE_MASK               0x4u
#define SysTick_CSR_CLKSOURCE_SHIFT              2
#define SysTick_CSR_COUNTFLAG_MASK               0x10000u
#define SysTick_CSR_COUNTFLAG_SHIFT              16
/* RVR Bit Fields */
#define SysTick_RVR_RELOAD_MASK                  0xFFFFFFu
#define SysTick_RVR_RELOAD_SHIFT                 0
#define SysTick_RVR_RELOAD(x)                    (((uint32_t)(((uint32_t)(x))<<SysTick_RVR_RELOAD_SHIFT))&SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define SysTick_CVR_CURRENT_MASK                 0xFFFFFFu
#define SysTick_CVR_CURRENT_SHIFT                0
#define SysTick_CVR_CURRENT(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CVR_CURRENT_SHIFT))&SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define SysTick_CALIB_TENMS_MASK                 0xFFFFFFu
#define SysTick_CALIB_TENMS_SHIFT                0
#define SysTick_CALIB_TENMS(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_TENMS_SHIFT))&SysTick_CALIB_TENMS_MASK)
#define SysTick_CALIB_SKEW_MASK                  0x40000000u
#define SysTick_CALIB_SKEW_SHIFT                 30
#define SysTick_CALIB_NOREF_MASK                 0x80000000u
#define SysTick_CALIB_NOREF_SHIFT                31

/*!
 * @}
 */ /* end of group SysTick_Register_Masks */


/* SysTick - Peripheral instance base addresses */
/** Peripheral SysTick base pointer */
#define SysTick_BASE_PTR                         ((SysTick_MemMapPtr)0xE000E010u)
/** Array initializer of SysTick peripheral base pointers */
#define SysTick_BASE_PTRS                        { SysTick_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register instance definitions */
/* SysTick */
#define SYST_CSR                                 SysTick_CSR_REG(SysTick_BASE_PTR)
#define SYST_RVR                                 SysTick_RVR_REG(SysTick_BASE_PTR)
#define SYST_CVR                                 SysTick_CVR_REG(SysTick_BASE_PTR)
#define SYST_CALIB                               SysTick_CALIB_REG(SysTick_BASE_PTR)

/*!
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SysTick_Peripheral */


/* ----------------------------------------------------------------------------
   -- TPIU
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPIU_Peripheral TPIU
 * @{
 */

/** TPIU - Peripheral register structure */
typedef struct TPIU_MemMap {
  uint32_t SSPSR;                                  /**< Supported Parallel Port Size Register, offset: 0x0 */
  uint32_t CSPSR;                                  /**< Current Parallel Port Size Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  uint32_t ACPR;                                   /**< Asynchronous Clock Prescaler Register, offset: 0x10 */
  uint8_t RESERVED_1[220];
  uint32_t SPPR;                                   /**< Selected Pin Protocol Register, offset: 0xF0 */
  uint8_t RESERVED_2[524];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint32_t FSCR;                                   /**< Formatter Synchronization Counter Register, offset: 0x308 */
  uint8_t RESERVED_3[3036];
  uint32_t TRIGGER;                                /**< Trigger Register, offset: 0xEE8 */
  uint32_t FIFODATA0;                              /**< FIFODATA0 Register, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_4[4];
  uint32_t ITATBCTR0;                              /**< Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint32_t FIFODATA1;                              /**< FIFODATA1 Register, offset: 0xEFC */
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[32];
  uint32_t DEVID;                                  /**< TPIU_DEVID Register, offset: 0xFC8 */
  uint8_t RESERVED_7[4];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID4;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *TPIU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register accessors */
#define TPIU_SSPSR_REG(base)                     ((base)->SSPSR)
#define TPIU_CSPSR_REG(base)                     ((base)->CSPSR)
#define TPIU_ACPR_REG(base)                      ((base)->ACPR)
#define TPIU_SPPR_REG(base)                      ((base)->SPPR)
#define TPIU_FFSR_REG(base)                      ((base)->FFSR)
#define TPIU_FFCR_REG(base)                      ((base)->FFCR)
#define TPIU_FSCR_REG(base)                      ((base)->FSCR)
#define TPIU_TRIGGER_REG(base)                   ((base)->TRIGGER)
#define TPIU_FIFODATA0_REG(base)                 ((base)->FIFODATA0)
#define TPIU_ITATBCTR2_REG(base)                 ((base)->ITATBCTR2)
#define TPIU_ITATBCTR0_REG(base)                 ((base)->ITATBCTR0)
#define TPIU_FIFODATA1_REG(base)                 ((base)->FIFODATA1)
#define TPIU_ITCTRL_REG(base)                    ((base)->ITCTRL)
#define TPIU_CLAIMSET_REG(base)                  ((base)->CLAIMSET)
#define TPIU_CLAIMCLR_REG(base)                  ((base)->CLAIMCLR)
#define TPIU_DEVID_REG(base)                     ((base)->DEVID)
#define TPIU_PID4_REG(base)                      ((base)->PID4)
#define TPIU_PID5_REG(base)                      ((base)->PID5)
#define TPIU_PID6_REG(base)                      ((base)->PID6)
#define TPIU_PID7_REG(base)                      ((base)->PID7)
#define TPIU_PID0_REG(base)                      ((base)->PID0)
#define TPIU_PID1_REG(base)                      ((base)->PID1)
#define TPIU_PID2_REG(base)                      ((base)->PID2)
#define TPIU_PID3_REG(base)                      ((base)->PID3)
#define TPIU_CID0_REG(base)                      ((base)->CID0)
#define TPIU_CID1_REG(base)                      ((base)->CID1)
#define TPIU_CID2_REG(base)                      ((base)->CID2)
#define TPIU_CID4_REG(base)                      ((base)->CID4)

/*!
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TPIU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPIU_Register_Masks TPIU Register Masks
 * @{
 */


/*!
 * @}
 */ /* end of group TPIU_Register_Masks */


/* TPIU - Peripheral instance base addresses */
/** Peripheral TPIU base pointer */
#define TPIU_BASE_PTR                            ((TPIU_MemMapPtr)0xE0040000u)
/** Array initializer of TPIU peripheral base pointers */
#define TPIU_BASE_PTRS                           { TPIU_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register instance definitions */
/* TPIU */
#define TPIU_SSPSR                               TPIU_SSPSR_REG(TPIU_BASE_PTR)
#define TPIU_CSPSR                               TPIU_CSPSR_REG(TPIU_BASE_PTR)
#define TPIU_ACPR                                TPIU_ACPR_REG(TPIU_BASE_PTR)
#define TPIU_SPPR                                TPIU_SPPR_REG(TPIU_BASE_PTR)
#define TPIU_FFSR                                TPIU_FFSR_REG(TPIU_BASE_PTR)
#define TPIU_FFCR                                TPIU_FFCR_REG(TPIU_BASE_PTR)
#define TPIU_FSCR                                TPIU_FSCR_REG(TPIU_BASE_PTR)
#define TPIU_TRIGGER                             TPIU_TRIGGER_REG(TPIU_BASE_PTR)
#define TPIU_FIFODATA0                           TPIU_FIFODATA0_REG(TPIU_BASE_PTR)
#define TPIU_ITATBCTR2                           TPIU_ITATBCTR2_REG(TPIU_BASE_PTR)
#define TPIU_ITATBCTR0                           TPIU_ITATBCTR0_REG(TPIU_BASE_PTR)
#define TPIU_FIFODATA1                           TPIU_FIFODATA1_REG(TPIU_BASE_PTR)
#define TPIU_ITCTRL                              TPIU_ITCTRL_REG(TPIU_BASE_PTR)
#define TPIU_CLAIMSET                            TPIU_CLAIMSET_REG(TPIU_BASE_PTR)
#define TPIU_CLAIMCLR                            TPIU_CLAIMCLR_REG(TPIU_BASE_PTR)
#define TPIU_DEVID                               TPIU_DEVID_REG(TPIU_BASE_PTR)
#define TPIU_PID4                                TPIU_PID4_REG(TPIU_BASE_PTR)
#define TPIU_PID5                                TPIU_PID5_REG(TPIU_BASE_PTR)
#define TPIU_PID6                                TPIU_PID6_REG(TPIU_BASE_PTR)
#define TPIU_PID7                                TPIU_PID7_REG(TPIU_BASE_PTR)
#define TPIU_PID0                                TPIU_PID0_REG(TPIU_BASE_PTR)
#define TPIU_PID1                                TPIU_PID1_REG(TPIU_BASE_PTR)
#define TPIU_PID2                                TPIU_PID2_REG(TPIU_BASE_PTR)
#define TPIU_PID3                                TPIU_PID3_REG(TPIU_BASE_PTR)
#define TPIU_CID0                                TPIU_CID0_REG(TPIU_BASE_PTR)
#define TPIU_CID1                                TPIU_CID1_REG(TPIU_BASE_PTR)
#define TPIU_CID2                                TPIU_CID2_REG(TPIU_BASE_PTR)
#define TPIU_CID3                                TPIU_CID4_REG(TPIU_BASE_PTR)

/*!
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TPIU_Peripheral */


/* ----------------------------------------------------------------------------
   -- UART
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral UART
 * @{
 */

/** UART - Peripheral register structure */
typedef struct UART_MemMap {
  uint8_t BDH;                                     /**< UART Baud Rate Registers: High, offset: 0x0 */
  uint8_t BDL;                                     /**< UART Baud Rate Registers: Low, offset: 0x1 */
  uint8_t C1;                                      /**< UART Control Register 1, offset: 0x2 */
  uint8_t C2;                                      /**< UART Control Register 2, offset: 0x3 */
  uint8_t S1;                                      /**< UART Status Register 1, offset: 0x4 */
  uint8_t S2;                                      /**< UART Status Register 2, offset: 0x5 */
  uint8_t C3;                                      /**< UART Control Register 3, offset: 0x6 */
  uint8_t D;                                       /**< UART Data Register, offset: 0x7 */
  uint8_t MA1;                                     /**< UART Match Address Registers 1, offset: 0x8 */
  uint8_t MA2;                                     /**< UART Match Address Registers 2, offset: 0x9 */
  uint8_t C4;                                      /**< UART Control Register 4, offset: 0xA */
  uint8_t C5;                                      /**< UART Control Register 5, offset: 0xB */
  uint8_t ED;                                      /**< UART Extended Data Register, offset: 0xC */
  uint8_t MODEM;                                   /**< UART Modem Register, offset: 0xD */
  uint8_t RESERVED_0[2];
  uint8_t PFIFO;                                   /**< UART FIFO Parameters, offset: 0x10 */
  uint8_t CFIFO;                                   /**< UART FIFO Control Register, offset: 0x11 */
  uint8_t SFIFO;                                   /**< UART FIFO Status Register, offset: 0x12 */
  uint8_t TWFIFO;                                  /**< UART FIFO Transmit Watermark, offset: 0x13 */
  uint8_t TCFIFO;                                  /**< UART FIFO Transmit Count, offset: 0x14 */
  uint8_t RWFIFO;                                  /**< UART FIFO Receive Watermark, offset: 0x15 */
  uint8_t RCFIFO;                                  /**< UART FIFO Receive Count, offset: 0x16 */
} volatile *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)
#define UART_MA1_REG(base)                       ((base)->MA1)
#define UART_MA2_REG(base)                       ((base)->MA2)
#define UART_C4_REG(base)                        ((base)->C4)
#define UART_C5_REG(base)                        ((base)->C5)
#define UART_ED_REG(base)                        ((base)->ED)
#define UART_MODEM_REG(base)                     ((base)->MODEM)
#define UART_PFIFO_REG(base)                     ((base)->PFIFO)
#define UART_CFIFO_REG(base)                     ((base)->CFIFO)
#define UART_SFIFO_REG(base)                     ((base)->SFIFO)
#define UART_TWFIFO_REG(base)                    ((base)->TWFIFO)
#define UART_TCFIFO_REG(base)                    ((base)->TCFIFO)
#define UART_RWFIFO_REG(base)                    ((base)->RWFIFO)
#define UART_RCFIFO_REG(base)                    ((base)->RCFIFO)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK                       0x20u
#define UART_BDH_SBNS_SHIFT                      5
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA1_MA_SHIFT))&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA2_MA_SHIFT))&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_LBKDDMAS_MASK                    0x8u
#define UART_C5_LBKDDMAS_SHIFT                   3
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXOFE_MASK                    0x4u
#define UART_CFIFO_RXOFE_SHIFT                   2
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXOF_MASK                     0x4u
#define UART_SFIFO_RXOF_SHIFT                    2
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK)

/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base pointer */
#define UART0_BASE_PTR                           ((UART_MemMapPtr)0x4006A000u)
/** Peripheral UART1 base pointer */
#define UART1_BASE_PTR                           ((UART_MemMapPtr)0x4006B000u)
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0_BASE_PTR, UART1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0_BASE_PTR)
#define UART0_BDL                                UART_BDL_REG(UART0_BASE_PTR)
#define UART0_C1                                 UART_C1_REG(UART0_BASE_PTR)
#define UART0_C2                                 UART_C2_REG(UART0_BASE_PTR)
#define UART0_S1                                 UART_S1_REG(UART0_BASE_PTR)
#define UART0_S2                                 UART_S2_REG(UART0_BASE_PTR)
#define UART0_C3                                 UART_C3_REG(UART0_BASE_PTR)
#define UART0_D                                  UART_D_REG(UART0_BASE_PTR)
#define UART0_MA1                                UART_MA1_REG(UART0_BASE_PTR)
#define UART0_MA2                                UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4                                 UART_C4_REG(UART0_BASE_PTR)
#define UART0_C5                                 UART_C5_REG(UART0_BASE_PTR)
#define UART0_ED                                 UART_ED_REG(UART0_BASE_PTR)
#define UART0_MODEM                              UART_MODEM_REG(UART0_BASE_PTR)
#define UART0_PFIFO                              UART_PFIFO_REG(UART0_BASE_PTR)
#define UART0_CFIFO                              UART_CFIFO_REG(UART0_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_REG(UART0_BASE_PTR)
#define UART0_TWFIFO                             UART_TWFIFO_REG(UART0_BASE_PTR)
#define UART0_TCFIFO                             UART_TCFIFO_REG(UART0_BASE_PTR)
#define UART0_RWFIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO                             UART_RCFIFO_REG(UART0_BASE_PTR)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1_BASE_PTR)
#define UART1_BDL                                UART_BDL_REG(UART1_BASE_PTR)
#define UART1_C1                                 UART_C1_REG(UART1_BASE_PTR)
#define UART1_C2                                 UART_C2_REG(UART1_BASE_PTR)
#define UART1_S1                                 UART_S1_REG(UART1_BASE_PTR)
#define UART1_S2                                 UART_S2_REG(UART1_BASE_PTR)
#define UART1_C3                                 UART_C3_REG(UART1_BASE_PTR)
#define UART1_D                                  UART_D_REG(UART1_BASE_PTR)
#define UART1_MA1                                UART_MA1_REG(UART1_BASE_PTR)
#define UART1_MA2                                UART_MA2_REG(UART1_BASE_PTR)
#define UART1_C4                                 UART_C4_REG(UART1_BASE_PTR)
#define UART1_C5                                 UART_C5_REG(UART1_BASE_PTR)
#define UART1_ED                                 UART_ED_REG(UART1_BASE_PTR)
#define UART1_MODEM                              UART_MODEM_REG(UART1_BASE_PTR)
#define UART1_PFIFO                              UART_PFIFO_REG(UART1_BASE_PTR)
#define UART1_CFIFO                              UART_CFIFO_REG(UART1_BASE_PTR)
#define UART1_SFIFO                              UART_SFIFO_REG(UART1_BASE_PTR)
#define UART1_TWFIFO                             UART_TWFIFO_REG(UART1_BASE_PTR)
#define UART1_TCFIFO                             UART_TCFIFO_REG(UART1_BASE_PTR)
#define UART1_RWFIFO                             UART_RWFIFO_REG(UART1_BASE_PTR)
#define UART1_RCFIFO                             UART_RCFIFO_REG(UART1_BASE_PTR)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group UART_Peripheral */


/* ----------------------------------------------------------------------------
   -- WDOG
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral WDOG
 * @{
 */

/** WDOG - Peripheral register structure */
typedef struct WDOG_MemMap {
  uint16_t STCTRLH;                                /**< Watchdog Status and Control Register High, offset: 0x0 */
  uint16_t STCTRLL;                                /**< Watchdog Status and Control Register Low, offset: 0x2 */
  uint16_t TOVALH;                                 /**< Watchdog Time-out Value Register High, offset: 0x4 */
  uint16_t TOVALL;                                 /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  uint16_t WINH;                                   /**< Watchdog Window Register High, offset: 0x8 */
  uint16_t WINL;                                   /**< Watchdog Window Register Low, offset: 0xA */
  uint16_t REFRESH;                                /**< Watchdog Refresh register, offset: 0xC */
  uint16_t UNLOCK;                                 /**< Watchdog Unlock register, offset: 0xE */
  uint16_t TMROUTH;                                /**< Watchdog Timer Output Register High, offset: 0x10 */
  uint16_t TMROUTL;                                /**< Watchdog Timer Output Register Low, offset: 0x12 */
  uint16_t RSTCNT;                                 /**< Watchdog Reset Count register, offset: 0x14 */
  uint16_t PRESC;                                  /**< Watchdog Prescaler register, offset: 0x16 */
} volatile *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#define WDOG_STCTRLH_REG(base)                   ((base)->STCTRLH)
#define WDOG_STCTRLL_REG(base)                   ((base)->STCTRLL)
#define WDOG_TOVALH_REG(base)                    ((base)->TOVALH)
#define WDOG_TOVALL_REG(base)                    ((base)->TOVALL)
#define WDOG_WINH_REG(base)                      ((base)->WINH)
#define WDOG_WINL_REG(base)                      ((base)->WINL)
#define WDOG_REFRESH_REG(base)                   ((base)->REFRESH)
#define WDOG_UNLOCK_REG(base)                    ((base)->UNLOCK)
#define WDOG_TMROUTH_REG(base)                   ((base)->TMROUTH)
#define WDOG_TMROUTL_REG(base)                   ((base)->TMROUTL)
#define WDOG_RSTCNT_REG(base)                    ((base)->RSTCNT)
#define WDOG_PRESC_REG(base)                     ((base)->PRESC)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* STCTRLH Bit Fields */
#define WDOG_STCTRLH_WDOGEN_MASK                 0x1u
#define WDOG_STCTRLH_WDOGEN_SHIFT                0
#define WDOG_STCTRLH_CLKSRC_MASK                 0x2u
#define WDOG_STCTRLH_CLKSRC_SHIFT                1
#define WDOG_STCTRLH_IRQRSTEN_MASK               0x4u
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2
#define WDOG_STCTRLH_WINEN_MASK                  0x8u
#define WDOG_STCTRLH_WINEN_SHIFT                 3
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            0x10u
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4
#define WDOG_STCTRLH_DBGEN_MASK                  0x20u
#define WDOG_STCTRLH_DBGEN_SHIFT                 5
#define WDOG_STCTRLH_STOPEN_MASK                 0x40u
#define WDOG_STCTRLH_STOPEN_SHIFT                6
#define WDOG_STCTRLH_WAITEN_MASK                 0x80u
#define WDOG_STCTRLH_WAITEN_SHIFT                7
#define WDOG_STCTRLH_TESTWDOG_MASK               0x400u
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10
#define WDOG_STCTRLH_TESTSEL_MASK                0x800u
#define WDOG_STCTRLH_TESTSEL_SHIFT               11
#define WDOG_STCTRLH_BYTESEL_MASK                0x3000u
#define WDOG_STCTRLH_BYTESEL_SHIFT               12
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK)
#define WDOG_STCTRLH_DISTESTWDOG_MASK            0x4000u
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14
/* STCTRLL Bit Fields */
#define WDOG_STCTRLL_INTFLG_MASK                 0x8000u
#define WDOG_STCTRLL_INTFLG_SHIFT                15
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK)
/* REFRESH Bit Fields */
#define WDOG_REFRESH_WDOGREFRESH_MASK            0xFFFFu
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK)
/* UNLOCK Bit Fields */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              0xFFFFu
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK)
/* TMROUTH Bit Fields */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           0xFFFFu
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK)
/* TMROUTL Bit Fields */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            0xFFFFu
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK)
/* RSTCNT Bit Fields */
#define WDOG_RSTCNT_RSTCNT_MASK                  0xFFFFu
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK)
/* PRESC Bit Fields */
#define WDOG_PRESC_PRESCVAL_MASK                 0x700u
#define WDOG_PRESC_PRESCVAL_SHIFT                8
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base pointer */
#define WDOG_BASE_PTR                            ((WDOG_MemMapPtr)0x40052000u)
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG */
#define WDOG_STCTRLH                             WDOG_STCTRLH_REG(WDOG_BASE_PTR)
#define WDOG_STCTRLL                             WDOG_STCTRLL_REG(WDOG_BASE_PTR)
#define WDOG_TOVALH                              WDOG_TOVALH_REG(WDOG_BASE_PTR)
#define WDOG_TOVALL                              WDOG_TOVALL_REG(WDOG_BASE_PTR)
#define WDOG_WINH                                WDOG_WINH_REG(WDOG_BASE_PTR)
#define WDOG_WINL                                WDOG_WINL_REG(WDOG_BASE_PTR)
#define WDOG_REFRESH                             WDOG_REFRESH_REG(WDOG_BASE_PTR)
#define WDOG_UNLOCK                              WDOG_UNLOCK_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTH                             WDOG_TMROUTH_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTL                             WDOG_TMROUTL_REG(WDOG_BASE_PTR)
#define WDOG_RSTCNT                              WDOG_RSTCNT_REG(WDOG_BASE_PTR)
#define WDOG_PRESC                               WDOG_PRESC_REG(WDOG_BASE_PTR)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group WDOG_Peripheral */


/* ----------------------------------------------------------------------------
   -- XBARA
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Peripheral XBARA
 * @{
 */

/** XBARA - Peripheral register structure */
typedef struct XBARA_MemMap {
  uint16_t SEL0;                                   /**< Crossbar A Select Register 0, offset: 0x0 */
  uint16_t SEL1;                                   /**< Crossbar A Select Register 1, offset: 0x2 */
  uint16_t SEL2;                                   /**< Crossbar A Select Register 2, offset: 0x4 */
  uint16_t SEL3;                                   /**< Crossbar A Select Register 3, offset: 0x6 */
  uint16_t SEL4;                                   /**< Crossbar A Select Register 4, offset: 0x8 */
  uint16_t SEL5;                                   /**< Crossbar A Select Register 5, offset: 0xA */
  uint16_t SEL6;                                   /**< Crossbar A Select Register 6, offset: 0xC */
  uint16_t SEL7;                                   /**< Crossbar A Select Register 7, offset: 0xE */
  uint16_t SEL8;                                   /**< Crossbar A Select Register 8, offset: 0x10 */
  uint16_t SEL9;                                   /**< Crossbar A Select Register 9, offset: 0x12 */
  uint16_t SEL10;                                  /**< Crossbar A Select Register 10, offset: 0x14 */
  uint16_t SEL11;                                  /**< Crossbar A Select Register 11, offset: 0x16 */
  uint16_t SEL12;                                  /**< Crossbar A Select Register 12, offset: 0x18 */
  uint16_t SEL13;                                  /**< Crossbar A Select Register 13, offset: 0x1A */
  uint16_t SEL14;                                  /**< Crossbar A Select Register 14, offset: 0x1C */
  uint16_t SEL15;                                  /**< Crossbar A Select Register 15, offset: 0x1E */
  uint16_t SEL16;                                  /**< Crossbar A Select Register 16, offset: 0x20 */
  uint16_t SEL17;                                  /**< Crossbar A Select Register 17, offset: 0x22 */
  uint16_t SEL18;                                  /**< Crossbar A Select Register 18, offset: 0x24 */
  uint16_t SEL19;                                  /**< Crossbar A Select Register 19, offset: 0x26 */
  uint16_t SEL20;                                  /**< Crossbar A Select Register 20, offset: 0x28 */
  uint16_t SEL21;                                  /**< Crossbar A Select Register 21, offset: 0x2A */
  uint16_t SEL22;                                  /**< Crossbar A Select Register 22, offset: 0x2C */
  uint16_t SEL23;                                  /**< Crossbar A Select Register 23, offset: 0x2E */
  uint16_t SEL24;                                  /**< Crossbar A Select Register 24, offset: 0x30 */
  uint16_t SEL25;                                  /**< Crossbar A Select Register 25, offset: 0x32 */
  uint16_t SEL26;                                  /**< Crossbar A Select Register 26, offset: 0x34 */
  uint16_t SEL27;                                  /**< Crossbar A Select Register 27, offset: 0x36 */
  uint16_t SEL28;                                  /**< Crossbar A Select Register 28, offset: 0x38 */
  uint16_t SEL29;                                  /**< Crossbar A Select Register 29, offset: 0x3A */
  uint16_t CTRL0;                                  /**< Crossbar A Control Register 0, offset: 0x3C */
  uint16_t CTRL1;                                  /**< Crossbar A Control Register 1, offset: 0x3E */
} volatile *XBARA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- XBARA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Register_Accessor_Macros XBARA - Register accessor macros
 * @{
 */


/* XBARA - Register accessors */
#define XBARA_SEL0_REG(base)                     ((base)->SEL0)
#define XBARA_SEL1_REG(base)                     ((base)->SEL1)
#define XBARA_SEL2_REG(base)                     ((base)->SEL2)
#define XBARA_SEL3_REG(base)                     ((base)->SEL3)
#define XBARA_SEL4_REG(base)                     ((base)->SEL4)
#define XBARA_SEL5_REG(base)                     ((base)->SEL5)
#define XBARA_SEL6_REG(base)                     ((base)->SEL6)
#define XBARA_SEL7_REG(base)                     ((base)->SEL7)
#define XBARA_SEL8_REG(base)                     ((base)->SEL8)
#define XBARA_SEL9_REG(base)                     ((base)->SEL9)
#define XBARA_SEL10_REG(base)                    ((base)->SEL10)
#define XBARA_SEL11_REG(base)                    ((base)->SEL11)
#define XBARA_SEL12_REG(base)                    ((base)->SEL12)
#define XBARA_SEL13_REG(base)                    ((base)->SEL13)
#define XBARA_SEL14_REG(base)                    ((base)->SEL14)
#define XBARA_SEL15_REG(base)                    ((base)->SEL15)
#define XBARA_SEL16_REG(base)                    ((base)->SEL16)
#define XBARA_SEL17_REG(base)                    ((base)->SEL17)
#define XBARA_SEL18_REG(base)                    ((base)->SEL18)
#define XBARA_SEL19_REG(base)                    ((base)->SEL19)
#define XBARA_SEL20_REG(base)                    ((base)->SEL20)
#define XBARA_SEL21_REG(base)                    ((base)->SEL21)
#define XBARA_SEL22_REG(base)                    ((base)->SEL22)
#define XBARA_SEL23_REG(base)                    ((base)->SEL23)
#define XBARA_SEL24_REG(base)                    ((base)->SEL24)
#define XBARA_SEL25_REG(base)                    ((base)->SEL25)
#define XBARA_SEL26_REG(base)                    ((base)->SEL26)
#define XBARA_SEL27_REG(base)                    ((base)->SEL27)
#define XBARA_SEL28_REG(base)                    ((base)->SEL28)
#define XBARA_SEL29_REG(base)                    ((base)->SEL29)
#define XBARA_CTRL0_REG(base)                    ((base)->CTRL0)
#define XBARA_CTRL1_REG(base)                    ((base)->CTRL1)

/*!
 * @}
 */ /* end of group XBARA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- XBARA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Register_Masks XBARA Register Masks
 * @{
 */

/* SEL0 Bit Fields */
#define XBARA_SEL0_SEL0_MASK                     0x3Fu
#define XBARA_SEL0_SEL0_SHIFT                    0
#define XBARA_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL0_SEL0_SHIFT))&XBARA_SEL0_SEL0_MASK)
#define XBARA_SEL0_SEL1_MASK                     0x3F00u
#define XBARA_SEL0_SEL1_SHIFT                    8
#define XBARA_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL0_SEL1_SHIFT))&XBARA_SEL0_SEL1_MASK)
/* SEL1 Bit Fields */
#define XBARA_SEL1_SEL2_MASK                     0x3Fu
#define XBARA_SEL1_SEL2_SHIFT                    0
#define XBARA_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL1_SEL2_SHIFT))&XBARA_SEL1_SEL2_MASK)
#define XBARA_SEL1_SEL3_MASK                     0x3F00u
#define XBARA_SEL1_SEL3_SHIFT                    8
#define XBARA_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL1_SEL3_SHIFT))&XBARA_SEL1_SEL3_MASK)
/* SEL2 Bit Fields */
#define XBARA_SEL2_SEL4_MASK                     0x3Fu
#define XBARA_SEL2_SEL4_SHIFT                    0
#define XBARA_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL2_SEL4_SHIFT))&XBARA_SEL2_SEL4_MASK)
#define XBARA_SEL2_SEL5_MASK                     0x3F00u
#define XBARA_SEL2_SEL5_SHIFT                    8
#define XBARA_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL2_SEL5_SHIFT))&XBARA_SEL2_SEL5_MASK)
/* SEL3 Bit Fields */
#define XBARA_SEL3_SEL6_MASK                     0x3Fu
#define XBARA_SEL3_SEL6_SHIFT                    0
#define XBARA_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL3_SEL6_SHIFT))&XBARA_SEL3_SEL6_MASK)
#define XBARA_SEL3_SEL7_MASK                     0x3F00u
#define XBARA_SEL3_SEL7_SHIFT                    8
#define XBARA_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL3_SEL7_SHIFT))&XBARA_SEL3_SEL7_MASK)
/* SEL4 Bit Fields */
#define XBARA_SEL4_SEL8_MASK                     0x3Fu
#define XBARA_SEL4_SEL8_SHIFT                    0
#define XBARA_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL4_SEL8_SHIFT))&XBARA_SEL4_SEL8_MASK)
#define XBARA_SEL4_SEL9_MASK                     0x3F00u
#define XBARA_SEL4_SEL9_SHIFT                    8
#define XBARA_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x))<<XBARA_SEL4_SEL9_SHIFT))&XBARA_SEL4_SEL9_MASK)
/* SEL5 Bit Fields */
#define XBARA_SEL5_SEL10_MASK                    0x3Fu
#define XBARA_SEL5_SEL10_SHIFT                   0
#define XBARA_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL5_SEL10_SHIFT))&XBARA_SEL5_SEL10_MASK)
#define XBARA_SEL5_SEL11_MASK                    0x3F00u
#define XBARA_SEL5_SEL11_SHIFT                   8
#define XBARA_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL5_SEL11_SHIFT))&XBARA_SEL5_SEL11_MASK)
/* SEL6 Bit Fields */
#define XBARA_SEL6_SEL12_MASK                    0x3Fu
#define XBARA_SEL6_SEL12_SHIFT                   0
#define XBARA_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL6_SEL12_SHIFT))&XBARA_SEL6_SEL12_MASK)
#define XBARA_SEL6_SEL13_MASK                    0x3F00u
#define XBARA_SEL6_SEL13_SHIFT                   8
#define XBARA_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL6_SEL13_SHIFT))&XBARA_SEL6_SEL13_MASK)
/* SEL7 Bit Fields */
#define XBARA_SEL7_SEL14_MASK                    0x3Fu
#define XBARA_SEL7_SEL14_SHIFT                   0
#define XBARA_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL7_SEL14_SHIFT))&XBARA_SEL7_SEL14_MASK)
#define XBARA_SEL7_SEL15_MASK                    0x3F00u
#define XBARA_SEL7_SEL15_SHIFT                   8
#define XBARA_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL7_SEL15_SHIFT))&XBARA_SEL7_SEL15_MASK)
/* SEL8 Bit Fields */
#define XBARA_SEL8_SEL16_MASK                    0x3Fu
#define XBARA_SEL8_SEL16_SHIFT                   0
#define XBARA_SEL8_SEL16(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL8_SEL16_SHIFT))&XBARA_SEL8_SEL16_MASK)
#define XBARA_SEL8_SEL17_MASK                    0x3F00u
#define XBARA_SEL8_SEL17_SHIFT                   8
#define XBARA_SEL8_SEL17(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL8_SEL17_SHIFT))&XBARA_SEL8_SEL17_MASK)
/* SEL9 Bit Fields */
#define XBARA_SEL9_SEL18_MASK                    0x3Fu
#define XBARA_SEL9_SEL18_SHIFT                   0
#define XBARA_SEL9_SEL18(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL9_SEL18_SHIFT))&XBARA_SEL9_SEL18_MASK)
#define XBARA_SEL9_SEL19_MASK                    0x3F00u
#define XBARA_SEL9_SEL19_SHIFT                   8
#define XBARA_SEL9_SEL19(x)                      (((uint16_t)(((uint16_t)(x))<<XBARA_SEL9_SEL19_SHIFT))&XBARA_SEL9_SEL19_MASK)
/* SEL10 Bit Fields */
#define XBARA_SEL10_SEL20_MASK                   0x3Fu
#define XBARA_SEL10_SEL20_SHIFT                  0
#define XBARA_SEL10_SEL20(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL10_SEL20_SHIFT))&XBARA_SEL10_SEL20_MASK)
#define XBARA_SEL10_SEL21_MASK                   0x3F00u
#define XBARA_SEL10_SEL21_SHIFT                  8
#define XBARA_SEL10_SEL21(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL10_SEL21_SHIFT))&XBARA_SEL10_SEL21_MASK)
/* SEL11 Bit Fields */
#define XBARA_SEL11_SEL22_MASK                   0x3Fu
#define XBARA_SEL11_SEL22_SHIFT                  0
#define XBARA_SEL11_SEL22(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL11_SEL22_SHIFT))&XBARA_SEL11_SEL22_MASK)
#define XBARA_SEL11_SEL23_MASK                   0x3F00u
#define XBARA_SEL11_SEL23_SHIFT                  8
#define XBARA_SEL11_SEL23(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL11_SEL23_SHIFT))&XBARA_SEL11_SEL23_MASK)
/* SEL12 Bit Fields */
#define XBARA_SEL12_SEL24_MASK                   0x3Fu
#define XBARA_SEL12_SEL24_SHIFT                  0
#define XBARA_SEL12_SEL24(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL12_SEL24_SHIFT))&XBARA_SEL12_SEL24_MASK)
#define XBARA_SEL12_SEL25_MASK                   0x3F00u
#define XBARA_SEL12_SEL25_SHIFT                  8
#define XBARA_SEL12_SEL25(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL12_SEL25_SHIFT))&XBARA_SEL12_SEL25_MASK)
/* SEL13 Bit Fields */
#define XBARA_SEL13_SEL26_MASK                   0x3Fu
#define XBARA_SEL13_SEL26_SHIFT                  0
#define XBARA_SEL13_SEL26(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL13_SEL26_SHIFT))&XBARA_SEL13_SEL26_MASK)
#define XBARA_SEL13_SEL27_MASK                   0x3F00u
#define XBARA_SEL13_SEL27_SHIFT                  8
#define XBARA_SEL13_SEL27(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL13_SEL27_SHIFT))&XBARA_SEL13_SEL27_MASK)
/* SEL14 Bit Fields */
#define XBARA_SEL14_SEL28_MASK                   0x3Fu
#define XBARA_SEL14_SEL28_SHIFT                  0
#define XBARA_SEL14_SEL28(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL14_SEL28_SHIFT))&XBARA_SEL14_SEL28_MASK)
#define XBARA_SEL14_SEL29_MASK                   0x3F00u
#define XBARA_SEL14_SEL29_SHIFT                  8
#define XBARA_SEL14_SEL29(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL14_SEL29_SHIFT))&XBARA_SEL14_SEL29_MASK)
/* SEL15 Bit Fields */
#define XBARA_SEL15_SEL30_MASK                   0x3Fu
#define XBARA_SEL15_SEL30_SHIFT                  0
#define XBARA_SEL15_SEL30(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL15_SEL30_SHIFT))&XBARA_SEL15_SEL30_MASK)
#define XBARA_SEL15_SEL31_MASK                   0x3F00u
#define XBARA_SEL15_SEL31_SHIFT                  8
#define XBARA_SEL15_SEL31(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL15_SEL31_SHIFT))&XBARA_SEL15_SEL31_MASK)
/* SEL16 Bit Fields */
#define XBARA_SEL16_SEL32_MASK                   0x3Fu
#define XBARA_SEL16_SEL32_SHIFT                  0
#define XBARA_SEL16_SEL32(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL16_SEL32_SHIFT))&XBARA_SEL16_SEL32_MASK)
#define XBARA_SEL16_SEL33_MASK                   0x3F00u
#define XBARA_SEL16_SEL33_SHIFT                  8
#define XBARA_SEL16_SEL33(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL16_SEL33_SHIFT))&XBARA_SEL16_SEL33_MASK)
/* SEL17 Bit Fields */
#define XBARA_SEL17_SEL34_MASK                   0x3Fu
#define XBARA_SEL17_SEL34_SHIFT                  0
#define XBARA_SEL17_SEL34(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL17_SEL34_SHIFT))&XBARA_SEL17_SEL34_MASK)
#define XBARA_SEL17_SEL35_MASK                   0x3F00u
#define XBARA_SEL17_SEL35_SHIFT                  8
#define XBARA_SEL17_SEL35(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL17_SEL35_SHIFT))&XBARA_SEL17_SEL35_MASK)
/* SEL18 Bit Fields */
#define XBARA_SEL18_SEL36_MASK                   0x3Fu
#define XBARA_SEL18_SEL36_SHIFT                  0
#define XBARA_SEL18_SEL36(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL18_SEL36_SHIFT))&XBARA_SEL18_SEL36_MASK)
#define XBARA_SEL18_SEL37_MASK                   0x3F00u
#define XBARA_SEL18_SEL37_SHIFT                  8
#define XBARA_SEL18_SEL37(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL18_SEL37_SHIFT))&XBARA_SEL18_SEL37_MASK)
/* SEL19 Bit Fields */
#define XBARA_SEL19_SEL38_MASK                   0x3Fu
#define XBARA_SEL19_SEL38_SHIFT                  0
#define XBARA_SEL19_SEL38(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL19_SEL38_SHIFT))&XBARA_SEL19_SEL38_MASK)
#define XBARA_SEL19_SEL39_MASK                   0x3F00u
#define XBARA_SEL19_SEL39_SHIFT                  8
#define XBARA_SEL19_SEL39(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL19_SEL39_SHIFT))&XBARA_SEL19_SEL39_MASK)
/* SEL20 Bit Fields */
#define XBARA_SEL20_SEL40_MASK                   0x3Fu
#define XBARA_SEL20_SEL40_SHIFT                  0
#define XBARA_SEL20_SEL40(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL20_SEL40_SHIFT))&XBARA_SEL20_SEL40_MASK)
#define XBARA_SEL20_SEL41_MASK                   0x3F00u
#define XBARA_SEL20_SEL41_SHIFT                  8
#define XBARA_SEL20_SEL41(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL20_SEL41_SHIFT))&XBARA_SEL20_SEL41_MASK)
/* SEL21 Bit Fields */
#define XBARA_SEL21_SEL42_MASK                   0x3Fu
#define XBARA_SEL21_SEL42_SHIFT                  0
#define XBARA_SEL21_SEL42(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL21_SEL42_SHIFT))&XBARA_SEL21_SEL42_MASK)
#define XBARA_SEL21_SEL43_MASK                   0x3F00u
#define XBARA_SEL21_SEL43_SHIFT                  8
#define XBARA_SEL21_SEL43(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL21_SEL43_SHIFT))&XBARA_SEL21_SEL43_MASK)
/* SEL22 Bit Fields */
#define XBARA_SEL22_SEL44_MASK                   0x3Fu
#define XBARA_SEL22_SEL44_SHIFT                  0
#define XBARA_SEL22_SEL44(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL22_SEL44_SHIFT))&XBARA_SEL22_SEL44_MASK)
#define XBARA_SEL22_SEL45_MASK                   0x3F00u
#define XBARA_SEL22_SEL45_SHIFT                  8
#define XBARA_SEL22_SEL45(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL22_SEL45_SHIFT))&XBARA_SEL22_SEL45_MASK)
/* SEL23 Bit Fields */
#define XBARA_SEL23_SEL46_MASK                   0x3Fu
#define XBARA_SEL23_SEL46_SHIFT                  0
#define XBARA_SEL23_SEL46(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL23_SEL46_SHIFT))&XBARA_SEL23_SEL46_MASK)
#define XBARA_SEL23_SEL47_MASK                   0x3F00u
#define XBARA_SEL23_SEL47_SHIFT                  8
#define XBARA_SEL23_SEL47(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL23_SEL47_SHIFT))&XBARA_SEL23_SEL47_MASK)
/* SEL24 Bit Fields */
#define XBARA_SEL24_SEL48_MASK                   0x3Fu
#define XBARA_SEL24_SEL48_SHIFT                  0
#define XBARA_SEL24_SEL48(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL24_SEL48_SHIFT))&XBARA_SEL24_SEL48_MASK)
#define XBARA_SEL24_SEL49_MASK                   0x3F00u
#define XBARA_SEL24_SEL49_SHIFT                  8
#define XBARA_SEL24_SEL49(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL24_SEL49_SHIFT))&XBARA_SEL24_SEL49_MASK)
/* SEL25 Bit Fields */
#define XBARA_SEL25_SEL50_MASK                   0x3Fu
#define XBARA_SEL25_SEL50_SHIFT                  0
#define XBARA_SEL25_SEL50(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL25_SEL50_SHIFT))&XBARA_SEL25_SEL50_MASK)
#define XBARA_SEL25_SEL51_MASK                   0x3F00u
#define XBARA_SEL25_SEL51_SHIFT                  8
#define XBARA_SEL25_SEL51(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL25_SEL51_SHIFT))&XBARA_SEL25_SEL51_MASK)
/* SEL26 Bit Fields */
#define XBARA_SEL26_SEL52_MASK                   0x3Fu
#define XBARA_SEL26_SEL52_SHIFT                  0
#define XBARA_SEL26_SEL52(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL26_SEL52_SHIFT))&XBARA_SEL26_SEL52_MASK)
#define XBARA_SEL26_SEL53_MASK                   0x3F00u
#define XBARA_SEL26_SEL53_SHIFT                  8
#define XBARA_SEL26_SEL53(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL26_SEL53_SHIFT))&XBARA_SEL26_SEL53_MASK)
/* SEL27 Bit Fields */
#define XBARA_SEL27_SEL54_MASK                   0x3Fu
#define XBARA_SEL27_SEL54_SHIFT                  0
#define XBARA_SEL27_SEL54(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL27_SEL54_SHIFT))&XBARA_SEL27_SEL54_MASK)
#define XBARA_SEL27_SEL55_MASK                   0x3F00u
#define XBARA_SEL27_SEL55_SHIFT                  8
#define XBARA_SEL27_SEL55(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL27_SEL55_SHIFT))&XBARA_SEL27_SEL55_MASK)
/* SEL28 Bit Fields */
#define XBARA_SEL28_SEL56_MASK                   0x3Fu
#define XBARA_SEL28_SEL56_SHIFT                  0
#define XBARA_SEL28_SEL56(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL28_SEL56_SHIFT))&XBARA_SEL28_SEL56_MASK)
#define XBARA_SEL28_SEL57_MASK                   0x3F00u
#define XBARA_SEL28_SEL57_SHIFT                  8
#define XBARA_SEL28_SEL57(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL28_SEL57_SHIFT))&XBARA_SEL28_SEL57_MASK)
/* SEL29 Bit Fields */
#define XBARA_SEL29_SEL58_MASK                   0x3Fu
#define XBARA_SEL29_SEL58_SHIFT                  0
#define XBARA_SEL29_SEL58(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_SEL29_SEL58_SHIFT))&XBARA_SEL29_SEL58_MASK)
/* CTRL0 Bit Fields */
#define XBARA_CTRL0_DEN0_MASK                    0x1u
#define XBARA_CTRL0_DEN0_SHIFT                   0
#define XBARA_CTRL0_IEN0_MASK                    0x2u
#define XBARA_CTRL0_IEN0_SHIFT                   1
#define XBARA_CTRL0_EDGE0_MASK                   0xCu
#define XBARA_CTRL0_EDGE0_SHIFT                  2
#define XBARA_CTRL0_EDGE0(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_CTRL0_EDGE0_SHIFT))&XBARA_CTRL0_EDGE0_MASK)
#define XBARA_CTRL0_STS0_MASK                    0x10u
#define XBARA_CTRL0_STS0_SHIFT                   4
#define XBARA_CTRL0_DEN1_MASK                    0x100u
#define XBARA_CTRL0_DEN1_SHIFT                   8
#define XBARA_CTRL0_IEN1_MASK                    0x200u
#define XBARA_CTRL0_IEN1_SHIFT                   9
#define XBARA_CTRL0_EDGE1_MASK                   0xC00u
#define XBARA_CTRL0_EDGE1_SHIFT                  10
#define XBARA_CTRL0_EDGE1(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_CTRL0_EDGE1_SHIFT))&XBARA_CTRL0_EDGE1_MASK)
#define XBARA_CTRL0_STS1_MASK                    0x1000u
#define XBARA_CTRL0_STS1_SHIFT                   12
/* CTRL1 Bit Fields */
#define XBARA_CTRL1_DEN2_MASK                    0x1u
#define XBARA_CTRL1_DEN2_SHIFT                   0
#define XBARA_CTRL1_IEN2_MASK                    0x2u
#define XBARA_CTRL1_IEN2_SHIFT                   1
#define XBARA_CTRL1_EDGE2_MASK                   0xCu
#define XBARA_CTRL1_EDGE2_SHIFT                  2
#define XBARA_CTRL1_EDGE2(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_CTRL1_EDGE2_SHIFT))&XBARA_CTRL1_EDGE2_MASK)
#define XBARA_CTRL1_STS2_MASK                    0x10u
#define XBARA_CTRL1_STS2_SHIFT                   4
#define XBARA_CTRL1_DEN3_MASK                    0x100u
#define XBARA_CTRL1_DEN3_SHIFT                   8
#define XBARA_CTRL1_IEN3_MASK                    0x200u
#define XBARA_CTRL1_IEN3_SHIFT                   9
#define XBARA_CTRL1_EDGE3_MASK                   0xC00u
#define XBARA_CTRL1_EDGE3_SHIFT                  10
#define XBARA_CTRL1_EDGE3(x)                     (((uint16_t)(((uint16_t)(x))<<XBARA_CTRL1_EDGE3_SHIFT))&XBARA_CTRL1_EDGE3_MASK)
#define XBARA_CTRL1_STS3_MASK                    0x1000u
#define XBARA_CTRL1_STS3_SHIFT                   12

/*!
 * @}
 */ /* end of group XBARA_Register_Masks */


/* XBARA - Peripheral instance base addresses */
/** Peripheral XBARA base pointer */
#define XBARA_BASE_PTR                           ((XBARA_MemMapPtr)0x40059000u)
/** Array initializer of XBARA peripheral base pointers */
#define XBARA_BASE_PTRS                          { XBARA_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- XBARA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Register_Accessor_Macros XBARA - Register accessor macros
 * @{
 */


/* XBARA - Register instance definitions */
/* XBARA */
#define XBARA_SEL0                               XBARA_SEL0_REG(XBARA_BASE_PTR)
#define XBARA_SEL1                               XBARA_SEL1_REG(XBARA_BASE_PTR)
#define XBARA_SEL2                               XBARA_SEL2_REG(XBARA_BASE_PTR)
#define XBARA_SEL3                               XBARA_SEL3_REG(XBARA_BASE_PTR)
#define XBARA_SEL4                               XBARA_SEL4_REG(XBARA_BASE_PTR)
#define XBARA_SEL5                               XBARA_SEL5_REG(XBARA_BASE_PTR)
#define XBARA_SEL6                               XBARA_SEL6_REG(XBARA_BASE_PTR)
#define XBARA_SEL7                               XBARA_SEL7_REG(XBARA_BASE_PTR)
#define XBARA_SEL8                               XBARA_SEL8_REG(XBARA_BASE_PTR)
#define XBARA_SEL9                               XBARA_SEL9_REG(XBARA_BASE_PTR)
#define XBARA_SEL10                              XBARA_SEL10_REG(XBARA_BASE_PTR)
#define XBARA_SEL11                              XBARA_SEL11_REG(XBARA_BASE_PTR)
#define XBARA_SEL12                              XBARA_SEL12_REG(XBARA_BASE_PTR)
#define XBARA_SEL13                              XBARA_SEL13_REG(XBARA_BASE_PTR)
#define XBARA_SEL14                              XBARA_SEL14_REG(XBARA_BASE_PTR)
#define XBARA_SEL15                              XBARA_SEL15_REG(XBARA_BASE_PTR)
#define XBARA_SEL16                              XBARA_SEL16_REG(XBARA_BASE_PTR)
#define XBARA_SEL17                              XBARA_SEL17_REG(XBARA_BASE_PTR)
#define XBARA_SEL18                              XBARA_SEL18_REG(XBARA_BASE_PTR)
#define XBARA_SEL19                              XBARA_SEL19_REG(XBARA_BASE_PTR)
#define XBARA_SEL20                              XBARA_SEL20_REG(XBARA_BASE_PTR)
#define XBARA_SEL21                              XBARA_SEL21_REG(XBARA_BASE_PTR)
#define XBARA_SEL22                              XBARA_SEL22_REG(XBARA_BASE_PTR)
#define XBARA_SEL23                              XBARA_SEL23_REG(XBARA_BASE_PTR)
#define XBARA_SEL24                              XBARA_SEL24_REG(XBARA_BASE_PTR)
#define XBARA_SEL25                              XBARA_SEL25_REG(XBARA_BASE_PTR)
#define XBARA_SEL26                              XBARA_SEL26_REG(XBARA_BASE_PTR)
#define XBARA_SEL27                              XBARA_SEL27_REG(XBARA_BASE_PTR)
#define XBARA_SEL28                              XBARA_SEL28_REG(XBARA_BASE_PTR)
#define XBARA_SEL29                              XBARA_SEL29_REG(XBARA_BASE_PTR)
#define XBARA_CTRL0                              XBARA_CTRL0_REG(XBARA_BASE_PTR)
#define XBARA_CTRL1                              XBARA_CTRL1_REG(XBARA_BASE_PTR)

/*!
 * @}
 */ /* end of group XBARA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group XBARA_Peripheral */


/* ----------------------------------------------------------------------------
   -- XBARB
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Peripheral XBARB
 * @{
 */

/** XBARB - Peripheral register structure */
typedef struct XBARB_MemMap {
  uint16_t SEL0;                                   /**< Crossbar B Select Register 0, offset: 0x0 */
  uint16_t SEL1;                                   /**< Crossbar B Select Register 1, offset: 0x2 */
  uint16_t SEL2;                                   /**< Crossbar B Select Register 2, offset: 0x4 */
  uint16_t SEL3;                                   /**< Crossbar B Select Register 3, offset: 0x6 */
  uint16_t SEL4;                                   /**< Crossbar B Select Register 4, offset: 0x8 */
  uint16_t SEL5;                                   /**< Crossbar B Select Register 5, offset: 0xA */
  uint16_t SEL6;                                   /**< Crossbar B Select Register 6, offset: 0xC */
  uint16_t SEL7;                                   /**< Crossbar B Select Register 7, offset: 0xE */
} volatile *XBARB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- XBARB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Register_Accessor_Macros XBARB - Register accessor macros
 * @{
 */


/* XBARB - Register accessors */
#define XBARB_SEL0_REG(base)                     ((base)->SEL0)
#define XBARB_SEL1_REG(base)                     ((base)->SEL1)
#define XBARB_SEL2_REG(base)                     ((base)->SEL2)
#define XBARB_SEL3_REG(base)                     ((base)->SEL3)
#define XBARB_SEL4_REG(base)                     ((base)->SEL4)
#define XBARB_SEL5_REG(base)                     ((base)->SEL5)
#define XBARB_SEL6_REG(base)                     ((base)->SEL6)
#define XBARB_SEL7_REG(base)                     ((base)->SEL7)

/*!
 * @}
 */ /* end of group XBARB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- XBARB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Register_Masks XBARB Register Masks
 * @{
 */

/* SEL0 Bit Fields */
#define XBARB_SEL0_SEL0_MASK                     0x1Fu
#define XBARB_SEL0_SEL0_SHIFT                    0
#define XBARB_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL0_SEL0_SHIFT))&XBARB_SEL0_SEL0_MASK)
#define XBARB_SEL0_SEL1_MASK                     0x1F00u
#define XBARB_SEL0_SEL1_SHIFT                    8
#define XBARB_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL0_SEL1_SHIFT))&XBARB_SEL0_SEL1_MASK)
/* SEL1 Bit Fields */
#define XBARB_SEL1_SEL2_MASK                     0x1Fu
#define XBARB_SEL1_SEL2_SHIFT                    0
#define XBARB_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL1_SEL2_SHIFT))&XBARB_SEL1_SEL2_MASK)
#define XBARB_SEL1_SEL3_MASK                     0x1F00u
#define XBARB_SEL1_SEL3_SHIFT                    8
#define XBARB_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL1_SEL3_SHIFT))&XBARB_SEL1_SEL3_MASK)
/* SEL2 Bit Fields */
#define XBARB_SEL2_SEL4_MASK                     0x1Fu
#define XBARB_SEL2_SEL4_SHIFT                    0
#define XBARB_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL2_SEL4_SHIFT))&XBARB_SEL2_SEL4_MASK)
#define XBARB_SEL2_SEL5_MASK                     0x1F00u
#define XBARB_SEL2_SEL5_SHIFT                    8
#define XBARB_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL2_SEL5_SHIFT))&XBARB_SEL2_SEL5_MASK)
/* SEL3 Bit Fields */
#define XBARB_SEL3_SEL6_MASK                     0x1Fu
#define XBARB_SEL3_SEL6_SHIFT                    0
#define XBARB_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL3_SEL6_SHIFT))&XBARB_SEL3_SEL6_MASK)
#define XBARB_SEL3_SEL7_MASK                     0x1F00u
#define XBARB_SEL3_SEL7_SHIFT                    8
#define XBARB_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL3_SEL7_SHIFT))&XBARB_SEL3_SEL7_MASK)
/* SEL4 Bit Fields */
#define XBARB_SEL4_SEL8_MASK                     0x1Fu
#define XBARB_SEL4_SEL8_SHIFT                    0
#define XBARB_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL4_SEL8_SHIFT))&XBARB_SEL4_SEL8_MASK)
#define XBARB_SEL4_SEL9_MASK                     0x1F00u
#define XBARB_SEL4_SEL9_SHIFT                    8
#define XBARB_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x))<<XBARB_SEL4_SEL9_SHIFT))&XBARB_SEL4_SEL9_MASK)
/* SEL5 Bit Fields */
#define XBARB_SEL5_SEL10_MASK                    0x1Fu
#define XBARB_SEL5_SEL10_SHIFT                   0
#define XBARB_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL5_SEL10_SHIFT))&XBARB_SEL5_SEL10_MASK)
#define XBARB_SEL5_SEL11_MASK                    0x1F00u
#define XBARB_SEL5_SEL11_SHIFT                   8
#define XBARB_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL5_SEL11_SHIFT))&XBARB_SEL5_SEL11_MASK)
/* SEL6 Bit Fields */
#define XBARB_SEL6_SEL12_MASK                    0x1Fu
#define XBARB_SEL6_SEL12_SHIFT                   0
#define XBARB_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL6_SEL12_SHIFT))&XBARB_SEL6_SEL12_MASK)
#define XBARB_SEL6_SEL13_MASK                    0x1F00u
#define XBARB_SEL6_SEL13_SHIFT                   8
#define XBARB_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL6_SEL13_SHIFT))&XBARB_SEL6_SEL13_MASK)
/* SEL7 Bit Fields */
#define XBARB_SEL7_SEL14_MASK                    0x1Fu
#define XBARB_SEL7_SEL14_SHIFT                   0
#define XBARB_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL7_SEL14_SHIFT))&XBARB_SEL7_SEL14_MASK)
#define XBARB_SEL7_SEL15_MASK                    0x1F00u
#define XBARB_SEL7_SEL15_SHIFT                   8
#define XBARB_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x))<<XBARB_SEL7_SEL15_SHIFT))&XBARB_SEL7_SEL15_MASK)

/*!
 * @}
 */ /* end of group XBARB_Register_Masks */


/* XBARB - Peripheral instance base addresses */
/** Peripheral XBARB base pointer */
#define XBARB_BASE_PTR                           ((XBARB_MemMapPtr)0x4005A000u)
/** Array initializer of XBARB peripheral base pointers */
#define XBARB_BASE_PTRS                          { XBARB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- XBARB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Register_Accessor_Macros XBARB - Register accessor macros
 * @{
 */


/* XBARB - Register instance definitions */
/* XBARB */
#define XBARB_SEL0                               XBARB_SEL0_REG(XBARB_BASE_PTR)
#define XBARB_SEL1                               XBARB_SEL1_REG(XBARB_BASE_PTR)
#define XBARB_SEL2                               XBARB_SEL2_REG(XBARB_BASE_PTR)
#define XBARB_SEL3                               XBARB_SEL3_REG(XBARB_BASE_PTR)
#define XBARB_SEL4                               XBARB_SEL4_REG(XBARB_BASE_PTR)
#define XBARB_SEL5                               XBARB_SEL5_REG(XBARB_BASE_PTR)
#define XBARB_SEL6                               XBARB_SEL6_REG(XBARB_BASE_PTR)
#define XBARB_SEL7                               XBARB_SEL7_REG(XBARB_BASE_PTR)

/*!
 * @}
 */ /* end of group XBARB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group XBARB_Peripheral */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_defines */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Backward_Compatibility_Symbols Backward Compatibility
 * @{
 */

/* No backward compatibility issues. */

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#else /* #if !defined(MCU_MKV46F15) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MCU_MKV46F15) */

/* MKV46F15.h, eof. */
