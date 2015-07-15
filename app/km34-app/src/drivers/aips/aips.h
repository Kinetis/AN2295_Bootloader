/******************************************************************************
 * (c) Copyright 2010-2013, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      aips.h
 * @version   1.0.2.0
 * @date      May-14-2012
 * @brief     Peripheral Bridge (AIPS-Lite) driver header file.
 ******************************************************************************/
#ifndef __AIPS_H
#define __AIPS_H

#if !defined(MCU_MKM34ZA5)
  #error "The aips.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/***************************************************************************//*!
 *//*! @addtogroup aips_slot
 * @{
 ******************************************************************************/
#define AIPS_AIPS_SLOT    (int64)(1ll<< 0)  ///< Slot 0: Peripheral Bridge (AIPS Lite)
#define AIPS_DMA_SLOT     (int64)(1ll<< 1)  ///< Slot 8: DMA Controller Module (DMA)
#define AIPS_MPU_SLOT     (int64)(1ll<< 2)  ///< Slot 10: Memory Protection Unit (MPU)
#define AIPS_FLASH_SLOT   (int64)(1ll<< 3)  ///< Slot 32: Flash Registers (FTFA)
#define AIPS_DMUX0_SLOT   (int64)(1ll<< 4)  ///< Slot 33: DMA Memory Access Multiplexer 0 (DMAMUX0)
#define AIPS_DMUX1_SLOT   (int64)(1ll<< 5)  ///< Slot 34: DMA Memory Access Multiplexer 1 (DMAMUX1)
#define AIPS_DMUX2_SLOT   (int64)(1ll<< 6)  ///< Slot 35: DMA Memory Access Multiplexer 2 (DMAMUX2)
#define AIPS_DMUX3_SLOT   (int64)(1ll<< 7)  ///< Slot 36: DMA Memory Access Multiplexer 3 (DMAMUX3)
#define AIPS_RNGA_SLOT    (int64)(1ll<< 8)  ///< Slot 41: Random Number Generator Accelerator (RNGA)
#define AIPS_ADC_SLOT     (int64)(1ll<< 9)  ///< Slot 43: SAR Analog-to-Digital Converter (ADC)
#define AIPS_PIT0_SLOT    (int64)(1ll<<10)  ///< Slot 45: Periodic Interrupt Timer 0 (PIT0)
#define AIPS_PIT1_SLOT    (int64)(1ll<<11)  ///< Slot 46: Periodic Interrupt Timer 1 (PIT1)
#define AIPS_AFE_SLOT     (int64)(1ll<<12)  ///< Slot 48: Analog Front End (AFE)
#define AIPS_CRC_SLOT     (int64)(1ll<<13)  ///< Slot 52: Programmable CRC (CRC)
#define AIPS_LPTMR_SLOT   (int64)(1ll<<14)  ///< Slot 60: Low Power Timer (LPTMR)
#define AIPS_SIMLP_SLOT   (int64)(1ll<<15)  ///< Slot 62: SIM Low Power Logic (SIMLP)
#define AIPS_SIMHP_SLOT   (int64)(1ll<<16)  ///< Slot 63: SIM High Power Logic (SIMHP)
#define AIPS_SLCD_SLOT    (int64)(1ll<<17)  ///< Slot 67: Segment LCD (SLCD)
#define AIPS_PORTA_SLOT   (int64)(1ll<<18)  ///< Slot 70: Port A Pin Mux Control (PORTA)
#define AIPS_PORTB_SLOT   (int64)(1ll<<19)  ///< Slot 71: Port B Pin Mux Control (PORTB)
#define AIPS_PORTC_SLOT   (int64)(1ll<<20)  ///< Slot 72: Port C Pin Mux Control (PORTC)
#define AIPS_PORTD_SLOT   (int64)(1ll<<21)  ///< Slot 73: Port D Pin Mux Control (PORTD)
#define AIPS_PORTE_SLOT   (int64)(1ll<<22)  ///< Slot 74: Port E Pin Mux Control (PORTE)
#define AIPS_PORTF_SLOT   (int64)(1ll<<23)  ///< Slot 75: Port F Pin Mux Control (PORTF)
#define AIPS_PORTG_SLOT   (int64)(1ll<<24)  ///< Slot 76: Port G Pin Mux Control (PORTG)
#define AIPS_PORTH_SLOT   (int64)(1ll<<25)  ///< Slot 77: Port H Pin Mux Control (PORTH)
#define AIPS_PORTI_SLOT   (int64)(1ll<<26)  ///< Slot 78: Port I Pin Mux Control (PORTI)
#define AIPS_IRTC_SLOT    (int64)(1ll<<27)  ///< Slot 80: Independent Real Time Clock (IRTC)
#define AIPS_IRTCRAM_SLOT (int64)(1ll<<28)  ///< Slot 81: IRTC's 32 Byte Standby RAM (IRTCRAM)
#define AIPS_WDOG_SLOT    (int64)(1ll<<28)  ///< Slot 83: Watchdog Timer (WDOG)
#define AIPS_XBAR_SLOT    (int64)(1ll<<29)  ///< Slot 85: Peripheral Crossbar (XBAR)
#define AIPS_TMR0_SLOT    (int64)(1ll<<30)  ///< Slot 87: Quad Timer Channel 0 (TMR0)
#define AIPS_TMR1_SLOT    (int64)(1ll<<31)  ///< Slot 88: Quad Timer Channel 1 (TMR1)
#define AIPS_TMR2_SLOT    (int64)(1ll<<32)  ///< Slot 89: Quad Timer Channel 2 (TMR2)
#define AIPS_TMR3_SLOT    (int64)(1ll<<33)  ///< Slot 90: Quad Timer Channel 3 (TMR3)
#define AIPS_EWM_SLOT     (int64)(1ll<<34)  ///< Slot 97: External Watchdog Monitor (EWM)
#define AIPS_MCG_SLOT     (int64)(1ll<<35)  ///< Slot 100: Multipurpose Clock Generator (MCG)
#define AIPS_OSC_SLOT     (int64)(1ll<<36)  ///< Slot 102: Oscillator (OSC)
#define AIPS_I2C0_SLOT    (int64)(1ll<<37)  ///< Slot 103: Inter-Integrated Circuit 0 (I2C0)
#define AIPS_I2C1_SLOT    (int64)(1ll<<38)  ///< Slot 104: Inter-Integrated Circuit 1 (I2C1)
#define AIPS_UART0_SLOT   (int64)(1ll<<39)  ///< Slot 106: Universal Asynchronous Receiver/Transmitter 0 (UART0)
#define AIPS_UART1_SLOT   (int64)(1ll<<40)  ///< Slot 107: Universal Asynchronous Receiver/Transmitter 1 (UART1)
#define AIPS_UART2_SLOT   (int64)(1ll<<41)  ///< Slot 108: Universal Asynchronous Receiver/Transmitter 2 (UART2)
#define AIPS_UART3_SLOT   (int64)(1ll<<42)  ///< Slot 109: Universal Asynchronous Receiver/Transmitter 3 (UART3)
#define AIPS_VREF_SLOT    (int64)(1ll<<43)  ///< Slot 111: Voltage Reference (VREF)
#define AIPS_CMP_SLOT     (int64)(1ll<<44)  ///< Slot 114: Comparator (CMP)
#define AIPS_SPI0_SLOT    (int64)(1ll<<45)  ///< Slot 117: Serial Peripheral Interface 0 (SPI0)
#define AIPS_SPI1_SLOT    (int64)(1ll<<46)  ///< Slot 118: Serial Peripheral Interface 1 (SPI1)
#define AIPS_RCM_SLOT     (int64)(1ll<<47)  ///< Slot 123: Reset Control Module (RCM)
#define AIPS_LLWU_SLOT    (int64)(1ll<<48)  ///< Slot 124: Low Leakage Wakeup Unit (LLWU)
#define AIPS_PMC_SLOT     (int64)(1ll<<49)  ///< Slot 125: Power Management Controller (PMC)
#define AIPS_SMC_SLOT     (int64)(1ll<<50)  ///< Slot 126: System Mode Controller (SMC)
#define AIPS_ALL_SLOTS    0xffffffffffffff  ///< Selects all slots
/*! @} End of aips_slot                                                       */

/***************************************************************************//*!
 *//*! @addtogroup aips_slot_attr
 * @{
 ******************************************************************************/
#define AIPS_SLOT_RW_RW_RW  0 ///< User nonsecure=Read/Write, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_RO_RW_RW  1 ///< User nonsecure=Read Only, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_NO_RW_RW  2 ///< User nonsecure=None, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_RO_R0_RW  3 ///< User nonsecure=Read Only, User secure=Read Only,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_NO_R0_RW  4 ///< User nonsecure=None, User secure=Read Only,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_NO_NO_RW  5 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=Read/Write
#define AIPS_SLOT_NO_NO_RO  6 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=Read Only
#define AIPS_SLOT_NO_NO_NO  7 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=None
/*! @} End of aips_slot_attr                                                  */

/******************************************************************************
* AIPS function and macro definitions
*
*//*! @addtogroup aips_macro
* @{
*******************************************************************************/
#define _AIPS_SET_ATTR(pacr_def,attr,lock)                                    \
{                                                                             \
  register struct PACR_REC {uint32 *ptr; uint8 shift;} _pacr = pacr_def;      \
  register uint32 tmp = *_pacr.ptr;                                           \
  tmp &=~((uint32)0x0f<<_pacr.shift);                                         \
  tmp |= ((uint32)attr<<_pacr.shift);                                         \
  tmp |= ((uint32)lock<<(3+_pacr.shift));                                     \
  *(_pacr.ptr)=tmp;                                                           \
}

#define _AIPS_LOCK(pacr_def)                                                  \
{                                                                             \
  register struct PACR_REC {uint32 *ptr; uint8 shift;} _pacr = pacr_def;      \
  (*(_pacr.ptr)) |= ((uint32)0x01<<(3+_pacr.shift));                          \
}
/******************************************************************************
 * platform peripherals
 ******************************************************************************/
#define PACR_AIPS_SLOT    {(uint32*)&AIPS_PACRA,AIPS_PACRM_AC0_SHIFT}/* PACR  0 */

#define PACR_DMA_SLOT     {(uint32*)&AIPS_PACRB,AIPS_PACRM_AC0_SHIFT}/* PACR  8 */
#define PACR_MPU_SLOT     {(uint32*)&AIPS_PACRB,AIPS_PACRM_AC2_SHIFT}/* PACR 10 */

/******************************************************************************
 * off-platform peripherals
 ******************************************************************************/
#define PACR_FLASH_SLOT   {(uint32*)&AIPS_PACRE,AIPS_PACRM_AC0_SHIFT}/* PACR 32 */
#define PACR_DMUX0_SLOT   {(uint32*)&AIPS_PACRE,AIPS_PACRM_AC1_SHIFT}/* PACR 33 */
#define PACR_DMUX1_SLOT   {(uint32*)&AIPS_PACRE,AIPS_PACRM_AC2_SHIFT}/* PACR 34 */
#define PACR_DMUX2_SLOT   {(uint32*)&AIPS_PACRE,AIPS_PACRM_AC3_SHIFT}/* PACR 35 */
#define PACR_DMUX3_SLOT   {(uint32*)&AIPS_PACRE,AIPS_PACRM_AC4_SHIFT}/* PACR 36 */

#define PACR_RNGA_SLOT    {(uint32*)&AIPS_PACRF,AIPS_PACRM_AC1_SHIFT}/* PACR 41 */
#define PACR_ADC_SLOT     {(uint32*)&AIPS_PACRF,AIPS_PACRM_AC3_SHIFT}/* PACR 43 */
#define PACR_PIT0_SLOT    {(uint32*)&AIPS_PACRF,AIPS_PACRM_AC5_SHIFT}/* PACR 45 */
#define PACR_PIT1_SLOT    {(uint32*)&AIPS_PACRF,AIPS_PACRM_AC6_SHIFT}/* PACR 46 */

#define PACR_AFE_SLOT     {(uint32*)&AIPS_PACRG,AIPS_PACRM_AC0_SHIFT}/* PACR 48 */
#define PACR_CRC_SLOT     {(uint32*)&AIPS_PACRG,AIPS_PACRM_AC4_SHIFT}/* PACR 52 */

#define PACR_LPTMR_SLOT   {(uint32*)&AIPS_PACRH,AIPS_PACRM_AC4_SHIFT}/* PACR 60 */
#define PACR_SIMLP_SLOT   {(uint32*)&AIPS_PACRH,AIPS_PACRM_AC6_SHIFT}/* PACR 62 */
#define PACR_SIMHP_SLOT   {(uint32*)&AIPS_PACRH,AIPS_PACRM_AC7_SHIFT}/* PACR 63 */

#define PACR_SLCD_SLOT    {(uint32*)&AIPS_PACRI,AIPS_PACRM_AC3_SHIFT}/* PACR 67 */
#define PACR_PORTA_SLOT   {(uint32*)&AIPS_PACRI,AIPS_PACRM_AC6_SHIFT}/* PACR 70 */
#define PACR_PORTB_SLOT   {(uint32*)&AIPS_PACRI,AIPS_PACRM_AC7_SHIFT}/* PACR 71 */

#define PACR_PORTC_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC0_SHIFT}/* PACR 72 */
#define PACR_PORTD_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC1_SHIFT}/* PACR 73 */
#define PACR_PORTE_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC2_SHIFT}/* PACR 74 */
#define PACR_PORTF_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC3_SHIFT}/* PACR 75 */
#define PACR_PORTG_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC4_SHIFT}/* PACR 76 */
#define PACR_PORTH_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC5_SHIFT}/* PACR 77 */
#define PACR_PORTI_SLOT   {(uint32*)&AIPS_PACRJ,AIPS_PACRM_AC6_SHIFT}/* PACR 78 */

#define PACR_IRTC_SLOT    {(uint32*)&AIPS_PACRK,AIPS_PACRM_AC0_SHIFT}/* PACR 80 */
#define PACR_IRTCRAM_SLOT {(uint32*)&AIPS_PACRK,AIPS_PACRM_AC1_SHIFT}/* PACR 81 */
#define PACR_WDOG_SLOT    {(uint32*)&AIPS_PACRK,AIPS_PACRM_AC3_SHIFT}/* PACR 83 */
#define PACR_XBAR_SLOT    {(uint32*)&AIPS_PACRK,AIPS_PACRM_AC5_SHIFT}/* PACR 85 */
#define PACR_TMR0_SLOT    {(uint32*)&AIPS_PACRK,AIPS_PACRM_AC7_SHIFT}/* PACR 87 */

#define PACR_TMR1_SLOT    {(uint32*)&AIPS_PACRL,AIPS_PACRM_AC0_SHIFT}/* PACR 88 */
#define PACR_TMR2_SLOT    {(uint32*)&AIPS_PACRL,AIPS_PACRM_AC1_SHIFT}/* PACR 89 */
#define PACR_TMR3_SLOT    {(uint32*)&AIPS_PACRL,AIPS_PACRM_AC2_SHIFT}/* PACR 90 */

#define PACR_EWM_SLOT     {(uint32*)&AIPS_PACRM,AIPS_PACRM_AC1_SHIFT}/* PACR 97 */
#define PACR_MCG_SLOT     {(uint32*)&AIPS_PACRM,AIPS_PACRM_AC4_SHIFT}/* PACR100 */
#define PACR_OSC_SLOT     {(uint32*)&AIPS_PACRM,AIPS_PACRM_AC6_SHIFT}/* PACR102 */
#define PACR_I2C0_SLOT    {(uint32*)&AIPS_PACRM,AIPS_PACRM_AC7_SHIFT}/* PACR103 */

#define PACR_I2C1_SLOT    {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC0_SHIFT}/* PACR104 */
#define PACR_UART0_SLOT   {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC2_SHIFT}/* PACR106 */
#define PACR_UART1_SLOT   {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC3_SHIFT}/* PACR107 */
#define PACR_UART2_SLOT   {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC4_SHIFT}/* PACR108 */
#define PACR_UART3_SLOT   {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC5_SHIFT}/* PACR109 */
#define PACR_VREF_SLOT    {(uint32*)&AIPS_PACRN,AIPS_PACRM_AC7_SHIFT}/* PACR111 */

#define PACR_CMP_SLOT     {(uint32*)&AIPS_PACRO,AIPS_PACRM_AC2_SHIFT}/* PACR114 */
#define PACR_SPI0_SLOT    {(uint32*)&AIPS_PACRO,AIPS_PACRM_AC5_SHIFT}/* PACR117 */
#define PACR_SPI1_SLOT    {(uint32*)&AIPS_PACRO,AIPS_PACRM_AC6_SHIFT}/* PACR118 */

#define PACR_RCM_SLOT     {(uint32*)&AIPS_PACRP,AIPS_PACRM_AC3_SHIFT}/* PACR123 */
#define PACR_LLWU_SLOT    {(uint32*)&AIPS_PACRP,AIPS_PACRM_AC4_SHIFT}/* PACR124 */
#define PACR_PMC_SLOT     {(uint32*)&AIPS_PACRP,AIPS_PACRM_AC5_SHIFT}/* PACR125 */
#define PACR_SMC_SLOT     {(uint32*)&AIPS_PACRP,AIPS_PACRM_AC6_SHIFT}/* PACR126 */

/***************************************************************************//*!
 * @brief   Configures and locks access to peripheral(s) attributes.
 * @details This macro configures access attributes for selected peripheral(s)
 *          and controls access into configuration attributes.
 * @param   mask   Select one or more OR'ed @ref aips_slot.
 * @param   attr   Select one of the @ref aips_slot_attr (will be applied to
 *                 selected peripherals).
 * @param   lock   TRUE  (configuration locked until next power on reset),
 *                 FALSE (configuration left opened for further changes).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define AIPS_SetSlotAttr(mask,attr,lock)                                      \
{                                                                             \
  if ((mask) & AIPS_AIPS_SLOT   ) _AIPS_SET_ATTR(PACR_AIPS_SLOT   , attr, lock); \
  if ((mask) & AIPS_DMA_SLOT    ) _AIPS_SET_ATTR(PACR_DMA_SLOT    , attr, lock); \
  if ((mask) & AIPS_MPU_SLOT    ) _AIPS_SET_ATTR(PACR_MPU_SLOT    , attr, lock); \
  if ((mask) & AIPS_FLASH_SLOT  ) _AIPS_SET_ATTR(PACR_FLASH_SLOT  , attr, lock); \
  if ((mask) & AIPS_DMUX0_SLOT  ) _AIPS_SET_ATTR(PACR_DMUX0_SLOT  , attr, lock); \
  if ((mask) & AIPS_DMUX1_SLOT  ) _AIPS_SET_ATTR(PACR_DMUX1_SLOT  , attr, lock); \
  if ((mask) & AIPS_DMUX2_SLOT  ) _AIPS_SET_ATTR(PACR_DMUX2_SLOT  , attr, lock); \
  if ((mask) & AIPS_DMUX3_SLOT  ) _AIPS_SET_ATTR(PACR_DMUX3_SLOT  , attr, lock); \
  if ((mask) & AIPS_RNGA_SLOT   ) _AIPS_SET_ATTR(PACR_RNGA_SLOT   , attr, lock); \
  if ((mask) & AIPS_ADC_SLOT    ) _AIPS_SET_ATTR(PACR_ADC_SLOT    , attr, lock); \
  if ((mask) & AIPS_PIT0_SLOT   ) _AIPS_SET_ATTR(PACR_PIT0_SLOT   , attr, lock); \
  if ((mask) & AIPS_PIT1_SLOT   ) _AIPS_SET_ATTR(PACR_PIT1_SLOT   , attr, lock); \
  if ((mask) & AIPS_AFE_SLOT    ) _AIPS_SET_ATTR(PACR_AFE_SLOT    , attr, lock); \
  if ((mask) & AIPS_CRC_SLOT    ) _AIPS_SET_ATTR(PACR_CRC_SLOT    , attr, lock); \
  if ((mask) & AIPS_LPTMR_SLOT  ) _AIPS_SET_ATTR(PACR_LPTMR_SLOT  , attr, lock); \
  if ((mask) & AIPS_SIMLP_SLOT  ) _AIPS_SET_ATTR(PACR_SIMLP_SLOT  , attr, lock); \
  if ((mask) & AIPS_SIMHP_SLOT  ) _AIPS_SET_ATTR(PACR_SIMHP_SLOT  , attr, lock); \
  if ((mask) & AIPS_SLCD_SLOT   ) _AIPS_SET_ATTR(PACR_SLCD_SLOT   , attr, lock); \
  if ((mask) & AIPS_PORTA_SLOT  ) _AIPS_SET_ATTR(PACR_PORTA_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTB_SLOT  ) _AIPS_SET_ATTR(PACR_PORTB_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTC_SLOT  ) _AIPS_SET_ATTR(PACR_PORTC_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTD_SLOT  ) _AIPS_SET_ATTR(PACR_PORTD_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTE_SLOT  ) _AIPS_SET_ATTR(PACR_PORTE_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTF_SLOT  ) _AIPS_SET_ATTR(PACR_PORTF_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTG_SLOT  ) _AIPS_SET_ATTR(PACR_PORTG_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTH_SLOT  ) _AIPS_SET_ATTR(PACR_PORTH_SLOT  , attr, lock); \
  if ((mask) & AIPS_PORTI_SLOT  ) _AIPS_SET_ATTR(PACR_PORTI_SLOT  , attr, lock); \
  if ((mask) & AIPS_IRTC_SLOT   ) _AIPS_SET_ATTR(PACR_IRTC_SLOT   , attr, lock); \
  if ((mask) & AIPS_IRTCRAM_SLOT) _AIPS_SET_ATTR(PACR_IRTCRAM_SLOT, attr, lock); \
  if ((mask) & AIPS_WDOG_SLOT   ) _AIPS_SET_ATTR(PACR_WDOG_SLOT   , attr, lock); \
  if ((mask) & AIPS_XBAR_SLOT   ) _AIPS_SET_ATTR(PACR_XBAR_SLOT   , attr, lock); \
  if ((mask) & AIPS_TMR0_SLOT   ) _AIPS_SET_ATTR(PACR_TMR0_SLOT   , attr, lock); \
  if ((mask) & AIPS_TMR1_SLOT   ) _AIPS_SET_ATTR(PACR_TMR1_SLOT   , attr, lock); \
  if ((mask) & AIPS_TMR2_SLOT   ) _AIPS_SET_ATTR(PACR_TMR2_SLOT   , attr, lock); \
  if ((mask) & AIPS_TMR3_SLOT   ) _AIPS_SET_ATTR(PACR_TMR3_SLOT   , attr, lock); \
  if ((mask) & AIPS_EWM_SLOT    ) _AIPS_SET_ATTR(PACR_EWM_SLOT    , attr, lock); \
  if ((mask) & AIPS_MCG_SLOT    ) _AIPS_SET_ATTR(PACR_MCG_SLOT    , attr, lock); \
  if ((mask) & AIPS_OSC_SLOT    ) _AIPS_SET_ATTR(PACR_OSC_SLOT    , attr, lock); \
  if ((mask) & AIPS_I2C0_SLOT   ) _AIPS_SET_ATTR(PACR_I2C0_SLOT   , attr, lock); \
  if ((mask) & AIPS_I2C1_SLOT   ) _AIPS_SET_ATTR(PACR_I2C1_SLOT   , attr, lock); \
  if ((mask) & AIPS_UART0_SLOT  ) _AIPS_SET_ATTR(PACR_UART0_SLOT  , attr, lock); \
  if ((mask) & AIPS_UART1_SLOT  ) _AIPS_SET_ATTR(PACR_UART1_SLOT  , attr, lock); \
  if ((mask) & AIPS_UART2_SLOT  ) _AIPS_SET_ATTR(PACR_UART2_SLOT  , attr, lock); \
  if ((mask) & AIPS_UART3_SLOT  ) _AIPS_SET_ATTR(PACR_UART3_SLOT  , attr, lock); \
  if ((mask) & AIPS_VREF_SLOT   ) _AIPS_SET_ATTR(PACR_VREF_SLOT   , attr, lock); \
  if ((mask) & AIPS_CMP_SLOT    ) _AIPS_SET_ATTR(PACR_CMP_SLOT    , attr, lock); \
  if ((mask) & AIPS_SPI0_SLOT   ) _AIPS_SET_ATTR(PACR_SPI0_SLOT   , attr, lock); \
  if ((mask) & AIPS_SPI1_SLOT   ) _AIPS_SET_ATTR(PACR_SPI1_SLOT   , attr, lock); \
  if ((mask) & AIPS_RCM_SLOT    ) _AIPS_SET_ATTR(PACR_RCM_SLOT    , attr, lock); \
  if ((mask) & AIPS_LLWU_SLOT   ) _AIPS_SET_ATTR(PACR_LLWU_SLOT   , attr, lock); \
  if ((mask) & AIPS_PMC_SLOT    ) _AIPS_SET_ATTR(PACR_PMC_SLOT    , attr, lock); \
  if ((mask) & AIPS_SMC_SLOT    ) _AIPS_SET_ATTR(PACR_SMC_SLOT    , attr, lock); \
}
/***************************************************************************//*!
 * @brief   Lock access to all peripheral slot's attributes.
 * @details This macro locks access to Lock access to all peripheral slot's
 * attributes. Once locked, any attempts to change peripheral access attributes
 * are ignored until the next system reset.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define AIPS_LockAllSlots()                                                      \
{                                                                                \
  _AIPS_LOCK(PACR_AIPS_SLOT   );                                                 \
  _AIPS_LOCK(PACR_DMA_SLOT    );                                                 \
  _AIPS_LOCK(PACR_MPU_SLOT    );                                                 \
  _AIPS_LOCK(PACR_FLASH_SLOT  );                                                 \
  _AIPS_LOCK(PACR_DMUX0_SLOT  );                                                 \
  _AIPS_LOCK(PACR_DMUX1_SLOT  );                                                 \
  _AIPS_LOCK(PACR_DMUX2_SLOT  );                                                 \
  _AIPS_LOCK(PACR_DMUX3_SLOT  );                                                 \
  _AIPS_LOCK(PACR_RNGA_SLOT   );                                                 \
  _AIPS_LOCK(PACR_ADC_SLOT    );                                                 \
  _AIPS_LOCK(PACR_PIT0_SLOT   );                                                 \
  _AIPS_LOCK(PACR_PIT1_SLOT   );                                                 \
  _AIPS_LOCK(PACR_AFE_SLOT    );                                                 \
  _AIPS_LOCK(PACR_CRC_SLOT    );                                                 \
  _AIPS_LOCK(PACR_LPTMR_SLOT  );                                                 \
  _AIPS_LOCK(PACR_SIMLP_SLOT  );                                                 \
  _AIPS_LOCK(PACR_SIMHP_SLOT  );                                                 \
  _AIPS_LOCK(PACR_SLCD_SLOT   );                                                 \
  _AIPS_LOCK(PACR_PORTA_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTB_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTC_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTD_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTE_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTF_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTG_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTH_SLOT  );                                                 \
  _AIPS_LOCK(PACR_PORTI_SLOT  );                                                 \
  _AIPS_LOCK(PACR_IRTC_SLOT   );                                                 \
  _AIPS_LOCK(PACR_IRTCRAM_SLOT);                                                 \
  _AIPS_LOCK(PACR_WDOG_SLOT   );                                                 \
  _AIPS_LOCK(PACR_XBAR_SLOT   );                                                 \
  _AIPS_LOCK(PACR_TMR0_SLOT   );                                                 \
  _AIPS_LOCK(PACR_TMR1_SLOT   );                                                 \
  _AIPS_LOCK(PACR_TMR2_SLOT   );                                                 \
  _AIPS_LOCK(PACR_TMR3_SLOT   );                                                 \
  _AIPS_LOCK(PACR_EWM_SLOT    );                                                 \
  _AIPS_LOCK(PACR_MCG_SLOT    );                                                 \
  _AIPS_LOCK(PACR_OSC_SLOT    );                                                 \
  _AIPS_LOCK(PACR_I2C0_SLOT   );                                                 \
  _AIPS_LOCK(PACR_I2C1_SLOT   );                                                 \
  _AIPS_LOCK(PACR_UART0_SLOT  );                                                 \
  _AIPS_LOCK(PACR_UART1_SLOT  );                                                 \
  _AIPS_LOCK(PACR_UART2_SLOT  );                                                 \
  _AIPS_LOCK(PACR_UART3_SLOT  );                                                 \
  _AIPS_LOCK(PACR_VREF_SLOT   );                                                 \
  _AIPS_LOCK(PACR_CMP_SLOT    );                                                 \
  _AIPS_LOCK(PACR_SPI0_SLOT   );                                                 \
  _AIPS_LOCK(PACR_SPI1_SLOT   );                                                 \
  _AIPS_LOCK(PACR_RCM_SLOT    );                                                 \
  _AIPS_LOCK(PACR_LLWU_SLOT   );                                                 \
  _AIPS_LOCK(PACR_PMC_SLOT    );                                                 \
  _AIPS_LOCK(PACR_SMC_SLOT    );                                                 \
}
/*! @} End of aips_macro                                                      */

#endif /* __AIPS_H */ 