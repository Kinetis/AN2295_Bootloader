//////////////////////////////////////////////////////////////////////////////////////
// File: MKL05Z32LF4.h
// Purpose: Define the peripheral registers.
// This file has been automatically generated from the APIF knowledgebase
//
// Revisions:
// - rev. 1.0 (2011-06-01)
//     Initial public version.
// - rev. 1.1 (2012-03-13)
//     Bit/group constants related to 32-bit registers typecasted to uint32_t.
//
//////////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
//
//////////////////////////////////////////////////////////////////////////////////////
// Generic Bit Definitions Used Elsewhere in this File
//
// Peripheral Base Address Defines in Alphabetical Order
//
#define  ADC0_BASE_PTR               ((uint8_t *) (0x4003B000u))

#define  CMP0_BASE_PTR               ((uint8_t *) (0x40073000u))

#define  DAC_BASE_PTR                ((uint8_t *) (0x4003F000u))

#define  DMA_BASE_PTR                ((uint8_t *) (0x40008000u))

#define  DMAMUX0_BASE_PTR            ((uint8_t *) (0x40021000u))

#define  FTFA_BASE_PTR               ((uint8_t *) (0x40020000u))

#define  GPIOA_BASE_PTR              ((uint8_t *) (0x400FF000u))

#define  GPIOB_BASE_PTR              ((uint8_t *) (0x400FF040u))

#define  I2C0_BASE_PTR               ((uint8_t *) (0x40066000u))

#define  LLWU_BASE_PTR               ((uint8_t *) (0x4007C000u))

#define  LPSCI0_BASE_PTR             ((uint8_t *) (0x4006A000u))

#define  LPTMR0_BASE_PTR             ((uint32_t *) (0x40040000u))

#define  LPTPM0_BASE_PTR             ((uint32_t *) (0x40038000u))

#define  LPTPM1_BASE_PTR             ((uint32_t *) (0x40039000u))

#define  MCG_BASE_PTR                ((uint8_t *) (0x40064000u))

#define  OSC0_BASE_PTR               ((uint8_t *) (0x40065000u))

#define  PIT_BASE_PTR                ((uint32_t *) (0x40037000u))

#define  PMC_BASE_PTR                ((uint8_t *) (0x4007D000u))

#define  PORTA_BASE_PTR              ((uint8_t *) (0x40049000u))

#define  PORTB_BASE_PTR              ((uint8_t *) (0x4004A000u))

#define  RCM_BASE_PTR                ((uint8_t *) (0x4007F000u))

#define  RTC_BASE_PTR                ((uint8_t *) (0x4003D000u))

#define  SIM_BASE_PTR                ((uint8_t *) (0x40047000u))

#define  SMC_BASE_PTR                ((uint8_t *) (0x4007E000u))

#define  SPI0_BASE_PTR               ((uint8_t *) (0x40076000u))

#define  TSI0_BASE_PTR               ((uint8_t *) (0x40045000u))


//////////////////////////////////////////////////////////////////////////////////////
// The following section defines the IO register locations.
//////////////////////////////////////////////////////////////////////////////////////

#define  ADC0_SC1A                   (*(uint32_t *) (0x4003B000))

#define  ADC0_SC1B                   (*(uint32_t *) (0x4003B004))

#define  ADC0_CFG1                   (*(uint32_t *) (0x4003B008))

#define  ADC0_CFG2                   (*(uint32_t *) (0x4003B00C))

#define  ADC0_RA                     (*(uint32_t *) (0x4003B010))

#define  ADC0_RB                     (*(uint32_t *) (0x4003B014))

#define  ADC0_CV1                    (*(uint32_t *) (0x4003B018))

#define  ADC0_CV2                    (*(uint32_t *) (0x4003B01C))

#define  ADC0_SC2                    (*(uint32_t *) (0x4003B020))

#define  ADC0_SC3                    (*(uint32_t *) (0x4003B024))

#define  ADC0_OFS                    (*(uint32_t *) (0x4003B028))

#define  ADC0_PG                     (*(uint32_t *) (0x4003B02C))

#define  ADC0_CLPD                   (*(uint32_t *) (0x4003B034))

#define  ADC0_CLPS                   (*(uint32_t *) (0x4003B038))

#define  ADC0_CLP4                   (*(uint32_t *) (0x4003B03C))

#define  ADC0_CLP3                   (*(uint32_t *) (0x4003B040))

#define  ADC0_CLP2                   (*(uint32_t *) (0x4003B044))

#define  ADC0_CLP1                   (*(uint32_t *) (0x4003B048))

#define  ADC0_CLP0                   (*(uint32_t *) (0x4003B04C))

#define  CMP0_CR0                    (*(uint8_t *) (0x40073000))

#define  CMP0_CR1                    (*(uint8_t *) (0x40073001))

#define  CMP0_FPR                    (*(uint8_t *) (0x40073002))

#define  CMP0_SCR                    (*(uint8_t *) (0x40073003))

#define  CMP0_DACCR                  (*(uint8_t *) (0x40073004))

#define  CMP0_MUXCR                  (*(uint8_t *) (0x40073005))

#define  DAC_DAT0L                   (*(uint8_t *) (0x4003F000))

#define  DAC_DAT0H                   (*(uint8_t *) (0x4003F001))

#define  DAC_DAT1L                   (*(uint8_t *) (0x4003F002))

#define  DAC_DAT1H                   (*(uint8_t *) (0x4003F003))

#define  DAC_DAT2L                   (*(uint8_t *) (0x4003F004))

#define  DAC_DAT2H                   (*(uint8_t *) (0x4003F005))

#define  DAC_DAT3L                   (*(uint8_t *) (0x4003F006))

#define  DAC_DAT3H                   (*(uint8_t *) (0x4003F007))

#define  DAC_DAT4L                   (*(uint8_t *) (0x4003F008))

#define  DAC_DAT4H                   (*(uint8_t *) (0x4003F009))

#define  DAC_DAT5L                   (*(uint8_t *) (0x4003F00A))

#define  DAC_DAT5H                   (*(uint8_t *) (0x4003F00B))

#define  DAC_DAT6L                   (*(uint8_t *) (0x4003F00C))

#define  DAC_DAT6H                   (*(uint8_t *) (0x4003F00D))

#define  DAC_DAT7L                   (*(uint8_t *) (0x4003F00E))

#define  DAC_DAT7H                   (*(uint8_t *) (0x4003F00F))

#define  DAC_DAT8L                   (*(uint8_t *) (0x4003F010))

#define  DAC_DAT8H                   (*(uint8_t *) (0x4003F011))

#define  DAC_DAT9L                   (*(uint8_t *) (0x4003F012))

#define  DAC_DAT9H                   (*(uint8_t *) (0x4003F013))

#define  DAC_DAT10L                  (*(uint8_t *) (0x4003F014))

#define  DAC_DAT10H                  (*(uint8_t *) (0x4003F015))

#define  DAC_DAT11L                  (*(uint8_t *) (0x4003F016))

#define  DAC_DAT11H                  (*(uint8_t *) (0x4003F017))

#define  DAC_DAT12L                  (*(uint8_t *) (0x4003F018))

#define  DAC_DAT12H                  (*(uint8_t *) (0x4003F019))

#define  DAC_DAT13L                  (*(uint8_t *) (0x4003F01A))

#define  DAC_DAT13H                  (*(uint8_t *) (0x4003F01B))

#define  DAC_DAT14L                  (*(uint8_t *) (0x4003F01C))

#define  DAC_DAT14H                  (*(uint8_t *) (0x4003F01D))

#define  DAC_DAT15L                  (*(uint8_t *) (0x4003F01E))

#define  DAC_DAT15H                  (*(uint8_t *) (0x4003F01F))

#define  DAC_SR                      (*(uint8_t *) (0x4003F020))

#define  DAC_C0                      (*(uint8_t *) (0x4003F021))

#define  DAC_C1                      (*(uint8_t *) (0x4003F022))

#define  DAC_C2                      (*(uint8_t *) (0x4003F023))

#define  DMA_SAR0                    (*(uint32_t *) (0x40008100))

#define  DMA_DAR0                    (*(uint32_t *) (0x40008104))

#define  DMA_DSR_BCR0                (*(uint32_t *) (0x40008108))

#define  DMA_DCR0                    (*(uint32_t *) (0x4000810C))

#define  DMA_SAR1                    (*(uint32_t *) (0x40008110))

#define  DMA_DAR1                    (*(uint32_t *) (0x40008114))

#define  DMA_DSR_BCR1                (*(uint32_t *) (0x40008118))

#define  DMA_DCR1                    (*(uint32_t *) (0x4000811C))

#define  DMA_SAR2                    (*(uint32_t *) (0x40008120))

#define  DMA_DAR2                    (*(uint32_t *) (0x40008124))

#define  DMA_DSR_BCR2                (*(uint32_t *) (0x40008128))

#define  DMA_DCR2                    (*(uint32_t *) (0x4000812C))

#define  DMA_SAR3                    (*(uint32_t *) (0x40008130))

#define  DMA_DAR3                    (*(uint32_t *) (0x40008134))

#define  DMA_DSR_BCR3                (*(uint32_t *) (0x40008138))

#define  DMA_DCR3                    (*(uint32_t *) (0x4000813C))

#define  DMAMUX0_CHCFG0              (*(uint8_t *) (0x40021000))

#define  DMAMUX0_CHCFG1              (*(uint8_t *) (0x40021001))

#define  DMAMUX0_CHCFG2              (*(uint8_t *) (0x40021002))

#define  DMAMUX0_CHCFG3              (*(uint8_t *) (0x40021003))

#define  DMAMUX0_CHCFG4              (*(uint8_t *) (0x40021004))

#define  DMAMUX0_CHCFG5              (*(uint8_t *) (0x40021005))

#define  DMAMUX0_CHCFG6              (*(uint8_t *) (0x40021006))

#define  DMAMUX0_CHCFG7              (*(uint8_t *) (0x40021007))

#define  DMAMUX0_CHCFG8              (*(uint8_t *) (0x40021008))

#define  DMAMUX0_CHCFG9              (*(uint8_t *) (0x40021009))

#define  DMAMUX0_CHCFG10             (*(uint8_t *) (0x4002100A))

#define  DMAMUX0_CHCFG11             (*(uint8_t *) (0x4002100B))

#define  DMAMUX0_CHCFG12             (*(uint8_t *) (0x4002100C))

#define  DMAMUX0_CHCFG13             (*(uint8_t *) (0x4002100D))

#define  DMAMUX0_CHCFG14             (*(uint8_t *) (0x4002100E))

#define  DMAMUX0_CHCFG15             (*(uint8_t *) (0x4002100F))

#define  FTFA_FSTAT                  (*(uint8_t *) (0x40020000))

#define  FTFA_FCNFG                  (*(uint8_t *) (0x40020001))

#define  FTFA_FSEC                   (*(uint8_t *) (0x40020002))

#define  FTFA_FOPT                   (*(uint8_t *) (0x40020003))

#define  FTFA_FCCOB3                 (*(uint8_t *) (0x40020004))

#define  FTFA_FCCOB2                 (*(uint8_t *) (0x40020005))

#define  FTFA_FCCOB1                 (*(uint8_t *) (0x40020006))

#define  FTFA_FCCOB0                 (*(uint8_t *) (0x40020007))

#define  FTFA_FCCOB7                 (*(uint8_t *) (0x40020008))

#define  FTFA_FCCOB6                 (*(uint8_t *) (0x40020009))

#define  FTFA_FCCOB5                 (*(uint8_t *) (0x4002000A))

#define  FTFA_FCCOB4                 (*(uint8_t *) (0x4002000B))

#define  FTFA_FCCOBB                 (*(uint8_t *) (0x4002000C))

#define  FTFA_FCCOBA                 (*(uint8_t *) (0x4002000D))

#define  FTFA_FCCOB9                 (*(uint8_t *) (0x4002000E))

#define  FTFA_FCCOB8                 (*(uint8_t *) (0x4002000F))

#define  FTFA_FPROT3                 (*(uint8_t *) (0x40020010))

#define  FTFA_FPROT2                 (*(uint8_t *) (0x40020011))

#define  FTFA_FPROT1                 (*(uint8_t *) (0x40020012))

#define  FTFA_FPROT0                 (*(uint8_t *) (0x40020013))

#define  GPIOA_PDOR                  (*(uint32_t *) (0x400FF000))

#define  GPIOA_PSOR                  (*(uint32_t *) (0x400FF004))

#define  GPIOA_PCOR                  (*(uint32_t *) (0x400FF008))

#define  GPIOA_PTOR                  (*(uint32_t *) (0x400FF00C))

#define  GPIOA_PDIR                  (*(uint32_t *) (0x400FF010))

#define  GPIOA_PDDR                  (*(uint32_t *) (0x400FF014))

#define  GPIOB_PDOR                  (*(uint32_t *) (0x400FF040))

#define  GPIOB_PSOR                  (*(uint32_t *) (0x400FF044))

#define  GPIOB_PCOR                  (*(uint32_t *) (0x400FF048))

#define  GPIOB_PTOR                  (*(uint32_t *) (0x400FF04C))

#define  GPIOB_PDIR                  (*(uint32_t *) (0x400FF050))

#define  GPIOB_PDDR                  (*(uint32_t *) (0x400FF054))

#define  I2C0_A1                     (*(uint8_t *) (0x40066000))

#define  I2C0_F                      (*(uint8_t *) (0x40066001))

#define  I2C0_C1                     (*(uint8_t *) (0x40066002))

#define  I2C0_S                      (*(uint8_t *) (0x40066003))

#define  I2C0_D                      (*(uint8_t *) (0x40066004))

#define  I2C0_C2                     (*(uint8_t *) (0x40066005))

#define  I2C0_FLT                    (*(uint8_t *) (0x40066006))

#define  I2C0_RA                     (*(uint8_t *) (0x40066007))

#define  I2C0_SMB                    (*(uint8_t *) (0x40066008))

#define  I2C0_A2                     (*(uint8_t *) (0x40066009))

#define  I2C0_SLTH                   (*(uint8_t *) (0x4006600A))

#define  I2C0_SLTL                   (*(uint8_t *) (0x4006600B))

#define  LLWU_PE1                    (*(uint8_t *) (0x4007C000))

#define  LLWU_PE2                    (*(uint8_t *) (0x4007C001))

#define  LLWU_PE3                    (*(uint8_t *) (0x4007C002))

#define  LLWU_PE4                    (*(uint8_t *) (0x4007C003))

#define  LLWU_ME                     (*(uint8_t *) (0x4007C004))

#define  LLWU_F1                     (*(uint8_t *) (0x4007C005))

#define  LLWU_F2                     (*(uint8_t *) (0x4007C006))

#define  LLWU_F3                     (*(uint8_t *) (0x4007C007))

#define  LLWU_FILT1                  (*(uint8_t *) (0x4007C008))

#define  LLWU_FILT2                  (*(uint8_t *) (0x4007C009))

#define  LPSCI0_BDH                  (*(uint8_t *) (0x4006A000))

#define  LPSCI0_BDL                  (*(uint8_t *) (0x4006A001))

#define  LPSCI0_C1                   (*(uint8_t *) (0x4006A002))

#define  LPSCI0_C2                   (*(uint8_t *) (0x4006A003))

#define  LPSCI0_S1                   (*(uint8_t *) (0x4006A004))

#define  LPSCI0_S2                   (*(uint8_t *) (0x4006A005))

#define  LPSCI0_C3                   (*(uint8_t *) (0x4006A006))

#define  LPSCI0_D                    (*(uint8_t *) (0x4006A007))

#define  LPSCI0_MA1                  (*(uint8_t *) (0x4006A008))

#define  LPSCI0_MA2                  (*(uint8_t *) (0x4006A009))

#define  LPSCI0_C4                   (*(uint8_t *) (0x4006A00A))

#define  LPSCI0_C5                   (*(uint8_t *) (0x4006A00B))

#define  LPTMR0_CSR                  (*(uint32_t *) (0x40040000))

#define  LPTMR0_PSR                  (*(uint32_t *) (0x40040004))

#define  LPTMR0_CMR                  (*(uint32_t *) (0x40040008))

#define  LPTMR0_CNR                  (*(uint32_t *) (0x4004000C))

#define  LPTPM0_SC                   (*(uint32_t *) (0x40038000))

#define  LPTPM0_CNT                  (*(uint32_t *) (0x40038004))

#define  LPTPM0_MOD                  (*(uint32_t *) (0x40038008))

#define  LPTPM0_C0SC                 (*(uint32_t *) (0x4003800C))

#define  LPTPM0_C0V                  (*(uint32_t *) (0x40038010))

#define  LPTPM0_C1SC                 (*(uint32_t *) (0x40038014))

#define  LPTPM0_C1V                  (*(uint32_t *) (0x40038018))

#define  LPTPM0_C2SC                 (*(uint32_t *) (0x4003801C))

#define  LPTPM0_C2V                  (*(uint32_t *) (0x40038020))

#define  LPTPM0_C3SC                 (*(uint32_t *) (0x40038024))

#define  LPTPM0_C3V                  (*(uint32_t *) (0x40038028))

#define  LPTPM0_C4SC                 (*(uint32_t *) (0x4003802C))

#define  LPTPM0_C4V                  (*(uint32_t *) (0x40038030))

#define  LPTPM0_C5SC                 (*(uint32_t *) (0x40038034))

#define  LPTPM0_C5V                  (*(uint32_t *) (0x40038038))

#define  LPTPM0_STATUS               (*(uint32_t *) (0x40038050))

#define  LPTPM0_CONF                 (*(uint32_t *) (0x40038084))

#define  LPTPM1_SC                   (*(uint32_t *) (0x40039000))

#define  LPTPM1_CNT                  (*(uint32_t *) (0x40039004))

#define  LPTPM1_MOD                  (*(uint32_t *) (0x40039008))

#define  LPTPM1_C0SC                 (*(uint32_t *) (0x4003900C))

#define  LPTPM1_C0V                  (*(uint32_t *) (0x40039010))

#define  LPTPM1_C1SC                 (*(uint32_t *) (0x40039014))

#define  LPTPM1_C1V                  (*(uint32_t *) (0x40039018))

#define  LPTPM1_C2SC                 (*(uint32_t *) (0x4003901C))

#define  LPTPM1_C2V                  (*(uint32_t *) (0x40039020))

#define  LPTPM1_C3SC                 (*(uint32_t *) (0x40039024))

#define  LPTPM1_C3V                  (*(uint32_t *) (0x40039028))

#define  LPTPM1_C4SC                 (*(uint32_t *) (0x4003902C))

#define  LPTPM1_C4V                  (*(uint32_t *) (0x40039030))

#define  LPTPM1_C5SC                 (*(uint32_t *) (0x40039034))

#define  LPTPM1_C5V                  (*(uint32_t *) (0x40039038))

#define  LPTPM1_STATUS               (*(uint32_t *) (0x40039050))

#define  LPTPM1_CONF                 (*(uint32_t *) (0x40039084))

#define  MCG_C1                      (*(uint8_t *) (0x40064000))

#define  MCG_C2                      (*(uint8_t *) (0x40064001))

#define  MCG_C3                      (*(uint8_t *) (0x40064002))

#define  MCG_C4                      (*(uint8_t *) (0x40064003))

#define  MCG_C5                      (*(uint8_t *) (0x40064004))

#define  MCG_C6                      (*(uint8_t *) (0x40064005))

#define  MCG_S                       (*(uint8_t *) (0x40064006))

#define  MCG_SC                      (*(uint8_t *) (0x40064008))

#define  MCG_ATCVH                   (*(uint8_t *) (0x4006400A))

#define  MCG_ATCVL                   (*(uint8_t *) (0x4006400B))

#define  MCG_C7                      (*(uint8_t *) (0x4006400C))

#define  MCG_C8                      (*(uint8_t *) (0x4006400D))

#define  OSC0_CR                     (*(uint8_t *) (0x40065000))

#define  PIT_MCR                     (*(uint32_t *) (0x40037000))

#define  PIT_LTMR64H                 (*(uint32_t *) (0x400370E0))

#define  PIT_LTMR64L                 (*(uint32_t *) (0x400370E4))

#define  PIT_LDVAL0                  (*(uint32_t *) (0x40037100))

#define  PIT_CVAL0                   (*(uint32_t *) (0x40037104))

#define  PIT_TCTRL0                  (*(uint32_t *) (0x40037108))

#define  PIT_TFLG0                   (*(uint32_t *) (0x4003710C))

#define  PIT_LDVAL1                  (*(uint32_t *) (0x40037110))

#define  PIT_CVAL1                   (*(uint32_t *) (0x40037114))

#define  PIT_TCTRL1                  (*(uint32_t *) (0x40037118))

#define  PIT_TFLG1                   (*(uint32_t *) (0x4003711C))

#define  PIT_LDVAL2                  (*(uint32_t *) (0x40037120))

#define  PIT_CVAL2                   (*(uint32_t *) (0x40037124))

#define  PIT_TCTRL2                  (*(uint32_t *) (0x40037128))

#define  PIT_TFLG2                   (*(uint32_t *) (0x4003712C))

#define  PIT_LDVAL3                  (*(uint32_t *) (0x40037130))

#define  PIT_CVAL3                   (*(uint32_t *) (0x40037134))

#define  PIT_TCTRL3                  (*(uint32_t *) (0x40037138))

#define  PIT_TFLG3                   (*(uint32_t *) (0x4003713C))

#define  PMC_LVDSC1                  (*(uint8_t *) (0x4007D000))

#define  PMC_LVDSC2                  (*(uint8_t *) (0x4007D001))

#define  PMC_REGSC                   (*(uint8_t *) (0x4007D002))

#define  PORTA_PCR0                  (*(uint32_t *) (0x40049000))

#define  PORTA_PCR1                  (*(uint32_t *) (0x40049004))

#define  PORTA_PCR2                  (*(uint32_t *) (0x40049008))

#define  PORTA_PCR3                  (*(uint32_t *) (0x4004900C))

#define  PORTA_PCR4                  (*(uint32_t *) (0x40049010))

#define  PORTA_PCR5                  (*(uint32_t *) (0x40049014))

#define  PORTA_PCR6                  (*(uint32_t *) (0x40049018))

#define  PORTA_PCR7                  (*(uint32_t *) (0x4004901C))

#define  PORTA_PCR8                  (*(uint32_t *) (0x40049020))

#define  PORTA_PCR9                  (*(uint32_t *) (0x40049024))

#define  PORTA_PCR10                 (*(uint32_t *) (0x40049028))

#define  PORTA_PCR11                 (*(uint32_t *) (0x4004902C))

#define  PORTA_PCR12                 (*(uint32_t *) (0x40049030))

#define  PORTA_PCR13                 (*(uint32_t *) (0x40049034))

#define  PORTA_PCR14                 (*(uint32_t *) (0x40049038))

#define  PORTA_PCR15                 (*(uint32_t *) (0x4004903C))

#define  PORTA_PCR16                 (*(uint32_t *) (0x40049040))

#define  PORTA_PCR17                 (*(uint32_t *) (0x40049044))

#define  PORTA_PCR18                 (*(uint32_t *) (0x40049048))

#define  PORTA_PCR19                 (*(uint32_t *) (0x4004904C))

#define  PORTA_PCR20                 (*(uint32_t *) (0x40049050))

#define  PORTA_PCR21                 (*(uint32_t *) (0x40049054))

#define  PORTA_PCR22                 (*(uint32_t *) (0x40049058))

#define  PORTA_PCR23                 (*(uint32_t *) (0x4004905C))

#define  PORTA_PCR24                 (*(uint32_t *) (0x40049060))

#define  PORTA_PCR25                 (*(uint32_t *) (0x40049064))

#define  PORTA_PCR26                 (*(uint32_t *) (0x40049068))

#define  PORTA_PCR27                 (*(uint32_t *) (0x4004906C))

#define  PORTA_PCR28                 (*(uint32_t *) (0x40049070))

#define  PORTA_PCR29                 (*(uint32_t *) (0x40049074))

#define  PORTA_PCR30                 (*(uint32_t *) (0x40049078))

#define  PORTA_PCR31                 (*(uint32_t *) (0x4004907C))

#define  PORTA_GPCLR                 (*(uint32_t *) (0x40049080))

#define  PORTA_GPCHR                 (*(uint32_t *) (0x40049084))

#define  PORTA_ISFR                  (*(uint32_t *) (0x400490A0))

#define  PORTB_PCR0                  (*(uint32_t *) (0x4004A000))

#define  PORTB_PCR1                  (*(uint32_t *) (0x4004A004))

#define  PORTB_PCR2                  (*(uint32_t *) (0x4004A008))

#define  PORTB_PCR3                  (*(uint32_t *) (0x4004A00C))

#define  PORTB_PCR4                  (*(uint32_t *) (0x4004A010))

#define  PORTB_PCR5                  (*(uint32_t *) (0x4004A014))

#define  PORTB_PCR6                  (*(uint32_t *) (0x4004A018))

#define  PORTB_PCR7                  (*(uint32_t *) (0x4004A01C))

#define  PORTB_PCR8                  (*(uint32_t *) (0x4004A020))

#define  PORTB_PCR9                  (*(uint32_t *) (0x4004A024))

#define  PORTB_PCR10                 (*(uint32_t *) (0x4004A028))

#define  PORTB_PCR11                 (*(uint32_t *) (0x4004A02C))

#define  PORTB_PCR12                 (*(uint32_t *) (0x4004A030))

#define  PORTB_PCR13                 (*(uint32_t *) (0x4004A034))

#define  PORTB_PCR14                 (*(uint32_t *) (0x4004A038))

#define  PORTB_PCR15                 (*(uint32_t *) (0x4004A03C))

#define  PORTB_PCR16                 (*(uint32_t *) (0x4004A040))

#define  PORTB_PCR17                 (*(uint32_t *) (0x4004A044))

#define  PORTB_PCR18                 (*(uint32_t *) (0x4004A048))

#define  PORTB_PCR19                 (*(uint32_t *) (0x4004A04C))

#define  PORTB_PCR20                 (*(uint32_t *) (0x4004A050))

#define  PORTB_PCR21                 (*(uint32_t *) (0x4004A054))

#define  PORTB_PCR22                 (*(uint32_t *) (0x4004A058))

#define  PORTB_PCR23                 (*(uint32_t *) (0x4004A05C))

#define  PORTB_PCR24                 (*(uint32_t *) (0x4004A060))

#define  PORTB_PCR25                 (*(uint32_t *) (0x4004A064))

#define  PORTB_PCR26                 (*(uint32_t *) (0x4004A068))

#define  PORTB_PCR27                 (*(uint32_t *) (0x4004A06C))

#define  PORTB_PCR28                 (*(uint32_t *) (0x4004A070))

#define  PORTB_PCR29                 (*(uint32_t *) (0x4004A074))

#define  PORTB_PCR30                 (*(uint32_t *) (0x4004A078))

#define  PORTB_PCR31                 (*(uint32_t *) (0x4004A07C))

#define  PORTB_GPCLR                 (*(uint32_t *) (0x4004A080))

#define  PORTB_GPCHR                 (*(uint32_t *) (0x4004A084))

#define  PORTB_ISFR                  (*(uint32_t *) (0x4004A0A0))

#define  RCM_SRS0                    (*(uint8_t *) (0x4007F000))

#define  RCM_SRS1                    (*(uint8_t *) (0x4007F001))

#define  RCM_RPFC                    (*(uint8_t *) (0x4007F004))

#define  RCM_RPFW                    (*(uint8_t *) (0x4007F005))

#define  RTC_TSR                     (*(uint32_t *) (0x4003D000))

#define  RTC_TPR                     (*(uint32_t *) (0x4003D004))

#define  RTC_TAR                     (*(uint32_t *) (0x4003D008))

#define  RTC_TCR                     (*(uint32_t *) (0x4003D00C))

#define  RTC_CR                      (*(uint32_t *) (0x4003D010))

#define  RTC_SR                      (*(uint32_t *) (0x4003D014))

#define  RTC_LR                      (*(uint32_t *) (0x4003D018))

#define  RTC_IER                     (*(uint32_t *) (0x4003D01C))

#define  SIM_SOPT1                   (*(uint32_t *) (0x40047000))

#define  SIM_SOPT1CFG                (*(uint32_t *) (0x40047004))

#define  SIM_SOPT2                   (*(uint32_t *) (0x40048004))

#define  SIM_SOPT4                   (*(uint32_t *) (0x4004800C))

#define  SIM_SOPT5                   (*(uint32_t *) (0x40048010))

#define  SIM_SOPT7                   (*(uint32_t *) (0x40048018))

#define  SIM_SDID                    (*(uint32_t *) (0x40048024))

#define  SIM_SCGC4                   (*(uint32_t *) (0x40048034))

#define  SIM_SCGC5                   (*(uint32_t *) (0x40048038))

#define  SIM_SCGC6                   (*(uint32_t *) (0x4004803C))

#define  SIM_SCGC7                   (*(uint32_t *) (0x40048040))

#define  SIM_CLKDIV1                 (*(uint32_t *) (0x40048044))

#define  SIM_FCFG1                   (*(uint32_t *) (0x4004804C))

#define  SIM_FCFG2                   (*(uint32_t *) (0x40048050))

#define  SIM_UIDMH                   (*(uint32_t *) (0x40048058))

#define  SIM_UIDML                   (*(uint32_t *) (0x4004805C))

#define  SIM_UIDL                    (*(uint32_t *) (0x40048060))

#define  SIM_COPC                    (*(uint32_t *) (0x40048100))

#define  SIM_SRVCOP                  (*(uint32_t *) (0x40048104))

#define  SMC_PMPROT                  (*(uint8_t *) (0x4007E000))

#define  SMC_PMCTRL                  (*(uint8_t *) (0x4007E001))

#define  SMC_STOPCTRL                (*(uint8_t *) (0x4007E002))

#define  SMC_PMSTAT                  (*(uint8_t *) (0x4007E003))

#define  SPI0_C1                     (*(uint8_t *) (0x40076000))

#define  SPI0_C2                     (*(uint8_t *) (0x40076001))

#define  SPI0_BR                     (*(uint8_t *) (0x40076002))

#define  SPI0_S                      (*(uint8_t *) (0x40076003))

#define  SPI0_D                      (*(uint8_t *) (0x40076005))

#define  SPI0_M                      (*(uint8_t *) (0x40076007))

#define  TSI0_GENCS                  (*(uint32_t *) (0x40045000))

#define  TSI0_DATA                   (*(uint32_t *) (0x40045004))

#define  TSI0_TSHD                   (*(uint32_t *) (0x40045008))

//////////////////////////////////////////////////////////////////////////////////////
// The following section defines the IO register bitfield locations and includes some commentary on the meaning of some settings.
//////////////////////////////////////////////////////////////////////////////////////

#define  ADC0_SC1A_ADCH_MASK         0x5u
#define  ADC0_SC1A_ADCH_SHIFT        0
#define  ADC0_SC1A_ADCH(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_SC1A_ADCH_SHIFT))&ADC0_SC1A_ADCH_MASK)
//   Input channel select
//     0b00000 ==> AD0 is selected as input.
//     0b00001 ==> AD1 is selected as input.
//     0b00010 ==> AD2 is selected as input.
//     0b00011 ==> AD3 is selected as input.
//     0b00100 ==> AD4 is selected as input.
//     0b00101 ==> AD5 is selected as input.
//     0b00110 ==> AD6 is selected as input.
//     0b00111 ==> AD7 is selected as input.
//     0b01000 ==> AD8 is selected as input.
//     0b01001 ==> AD9 is selected as input.
//     0b01010 ==> AD10 is selected as input.
//     0b01011 ==> AD11 is selected as input.
//     0b01100 ==> AD12 is selected as input.
//     0b01101 ==> AD13 is selected as input.
//     0b01110 ==> AD14 is selected as input.
//     0b01111 ==> AD15 is selected as input.
//     0b10000 ==> AD16 is selected as input.
//     0b10001 ==> AD17 is selected as input.
//     0b10010 ==> AD18 is selected as input.
//     0b10011 ==> AD19 is selected as input.
//     0b10100 ==> AD20 is selected as input.
//     0b10101 ==> AD21 is selected as input.
//     0b10110 ==> AD22 is selected as input.
//     0b10111 ==> AD23 is selected as input.
//     0b11000 ==> Reserved.
//     0b11001 ==> Reserved.
//     0b11010 ==> Temp sensor (single-ended) is selected as input.
//     0b11011 ==> Bandgap (single-ended) is selected as input.
//     0b11100 ==> Reserved.
//     0b11101 ==> VREFSH is selected as input. Voltage reference selected is determined by the REFSEL bits in the SC2 register.
//     0b11110 ==> VREFSL is selected as input. Voltage reference selected is determined by the REFSEL bits in the SC2 register.
//     0b11111 ==> Module disabled.

#define  ADC0_SC1A_AIEN_MASK         0x40u
#define  ADC0_SC1A_AIEN_SHIFT        6
//   Interrupt enable
//     0b0 ==> Conversion complete interrupt disabled.
//     0b1 ==> Conversion complete interrupt enabled.

#define  ADC0_SC1A_COCO_MASK         0x80u
#define  ADC0_SC1A_COCO_SHIFT        7
//   Conversion complete flag
//     0b0 ==> Conversion not completed.
//     0b1 ==> Conversion completed.

#define  ADC0_SC1B_ADCH_MASK         0x5u
#define  ADC0_SC1B_ADCH_SHIFT        0
#define  ADC0_SC1B_ADCH(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_SC1B_ADCH_SHIFT))&ADC0_SC1B_ADCH_MASK)
//   Input channel select
//     0b00000 ==> AD0 is selected as input.
//     0b00001 ==> AD1 is selected as input.
//     0b00010 ==> AD2 is selected as input.
//     0b00011 ==> AD3 is selected as input.
//     0b00100 ==> AD4 is selected as input.
//     0b00101 ==> AD5 is selected as input.
//     0b00110 ==> AD6 is selected as input.
//     0b00111 ==> AD7 is selected as input.
//     0b01000 ==> AD8 is selected as input.
//     0b01001 ==> AD9 is selected as input.
//     0b01010 ==> AD10 is selected as input.
//     0b01011 ==> AD11 is selected as input.
//     0b01100 ==> AD12 is selected as input.
//     0b01101 ==> AD13 is selected as input.
//     0b01110 ==> AD14 is selected as input.
//     0b01111 ==> AD15 is selected as input.
//     0b10000 ==> AD16 is selected as input.
//     0b10001 ==> AD17 is selected as input.
//     0b10010 ==> AD18 is selected as input.
//     0b10011 ==> AD19 is selected as input.
//     0b10100 ==> AD20 is selected as input.
//     0b10101 ==> AD21 is selected as input.
//     0b10110 ==> AD22 is selected as input.
//     0b10111 ==> AD23 is selected as input.
//     0b11000 ==> Reserved.
//     0b11001 ==> Reserved.
//     0b11010 ==> Temp sensor (single-ended) is selected as input.
//     0b11011 ==> Bandgap (single-ended) is selected as input.
//     0b11100 ==> Reserved.
//     0b11101 ==> VREFSH is selected as input. Voltage reference selected is determined by the REFSEL bits in the SC2 register.
//     0b11110 ==> VREFSL is selected as input. Voltage reference selected is determined by the REFSEL bits in the SC2 register.
//     0b11111 ==> Module disabled.

#define  ADC0_SC1B_AIEN_MASK         0x40u
#define  ADC0_SC1B_AIEN_SHIFT        6
//   Interrupt enable
//     0b0 ==> Conversion complete interrupt disabled.
//     0b1 ==> Conversion complete interrupt enabled.

#define  ADC0_SC1B_COCO_MASK         0x80u
#define  ADC0_SC1B_COCO_SHIFT        7
//   Conversion complete flag
//     0b0 ==> Conversion not completed.
//     0b1 ==> Conversion completed.

#define  ADC0_CFG1_ADICLK_MASK       0x2u
#define  ADC0_CFG1_ADICLK_SHIFT      0
#define  ADC0_CFG1_ADICLK(x)         (((uint32_t)(((uint32_t)(x))<<ADC0_CFG1_ADICLK_SHIFT))&ADC0_CFG1_ADICLK_MASK)
//   Input clock select
//     0b00 ==> Bus clock.
//     0b01 ==> Bus clock divided by 2.
//     0b10 ==> Alternate clock (ALTCLK).
//     0b11 ==> Asynchronous clock (ADACK).

#define  ADC0_CFG1_MODE_MASK         0x8u
#define  ADC0_CFG1_MODE_SHIFT        2
#define  ADC0_CFG1_MODE(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CFG1_MODE_SHIFT))&ADC0_CFG1_MODE_MASK)
//   Conversion mode selection
//     0b00 ==> It is single-ended 8-bit conversion.
//     0b01 ==> It is single-ended 12-bit conversion.
//     0b10 ==> It is single-ended 10-bit conversion.
//     0b11 ==> It is single-ended 16-bit conversion.

#define  ADC0_CFG1_ADLSMP_MASK       0x10u
#define  ADC0_CFG1_ADLSMP_SHIFT      4
//   Sample time configuration
//     0b0 ==> Short sample time.
//     0b1 ==> Long sample time.

#define  ADC0_CFG1_ADIV_MASK         0x40u
#define  ADC0_CFG1_ADIV_SHIFT        5
#define  ADC0_CFG1_ADIV(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CFG1_ADIV_SHIFT))&ADC0_CFG1_ADIV_MASK)
//   Clock divide select
//     0b00 ==> The divide ratio is 1 and the clock rate is input clock.
//     0b01 ==> The divide ratio is 2 and the clock rate is (input clock)/2.
//     0b10 ==> The divide ratio is 4 and the clock rate is (input clock)/4.
//     0b11 ==> The divide ratio is 8 and the clock rate is (input clock)/8.

#define  ADC0_CFG1_ADLPC_MASK        0x80u
#define  ADC0_CFG1_ADLPC_SHIFT       7
//   Low-power configuration
//     0b0 ==> Normal power configuration.
//     0b1 ==> Low power configuration. The power is reduced at the expense of maximum clock speed.

#define  ADC0_CFG2_ADLSTS_MASK       0x2u
#define  ADC0_CFG2_ADLSTS_SHIFT      0
#define  ADC0_CFG2_ADLSTS(x)         (((uint32_t)(((uint32_t)(x))<<ADC0_CFG2_ADLSTS_SHIFT))&ADC0_CFG2_ADLSTS_MASK)
//   Long sample time select
//     0b00 ==> Default longest sample time (20 extra ADCK cycles; 24 ADCK cycles total).
//     0b01 ==> 12 extra ADCK cycles; 16 ADCK cycles total sample time.
//     0b10 ==> 6 extra ADCK cycles; 10 ADCK cycles total sample time.
//     0b11 ==> 2 extra ADCK cycles; 6 ADCK cycles total sample time.

#define  ADC0_CFG2_ADHSC_MASK        0x4u
#define  ADC0_CFG2_ADHSC_SHIFT       2
//   High speed configuration
//     0b0 ==> Normal conversion sequence selected.
//     0b1 ==> High speed conversion sequence selected (2 additional ADCK cycles to total conversion time).

#define  ADC0_CFG2_ADACKEN_MASK      0x8u
#define  ADC0_CFG2_ADACKEN_SHIFT     3
//   Asynchronous clock output enable
//     0b0 ==> Asynchronous clock output disabled; Asynchronous clock only enabled if selected by ADICLK and a conversion is active.
//     0b1 ==> Asynchronous clock and clock output enabled regardless of the state of the ADC.

#define  ADC0_CFG2_MUXSEL_MASK       0x10u
#define  ADC0_CFG2_MUXSEL_SHIFT      4
//   ADC Mux select
//     0b0 ==> ADxxa channels are selected.
//     0b1 ==> ADxxb channels are selected.

#define  ADC0_RA_D_MASK              0x10u
#define  ADC0_RA_D_SHIFT             0
#define  ADC0_RA_D(x)                (((uint32_t)(((uint32_t)(x))<<ADC0_RA_D_SHIFT))&ADC0_RA_D_MASK)
//   Data result

#define  ADC0_RB_D_MASK              0x10u
#define  ADC0_RB_D_SHIFT             0
#define  ADC0_RB_D(x)                (((uint32_t)(((uint32_t)(x))<<ADC0_RB_D_SHIFT))&ADC0_RB_D_MASK)
//   Data result

#define  ADC0_CV1_CV_MASK            0x10u
#define  ADC0_CV1_CV_SHIFT           0
#define  ADC0_CV1_CV(x)              (((uint32_t)(((uint32_t)(x))<<ADC0_CV1_CV_SHIFT))&ADC0_CV1_CV_MASK)
//   Compare value

#define  ADC0_CV2_CV_MASK            0x10u
#define  ADC0_CV2_CV_SHIFT           0
#define  ADC0_CV2_CV(x)              (((uint32_t)(((uint32_t)(x))<<ADC0_CV2_CV_SHIFT))&ADC0_CV2_CV_MASK)
//   Compare value

#define  ADC0_SC2_REFSEL_MASK        0x2u
#define  ADC0_SC2_REFSEL_SHIFT       0
#define  ADC0_SC2_REFSEL(x)          (((uint32_t)(((uint32_t)(x))<<ADC0_SC2_REFSEL_SHIFT))&ADC0_SC2_REFSEL_MASK)
//   Voltage reference selection
//     0b00 ==> Default voltage reference pin pair (external pins VREFH and VREFL)
//     0b01 ==> Alternate reference pair (VALTH and VALTL). This pair may be additional external pins or internal sources depending on MCU configuration. Consult the Chip Configuration information for details specific to this MCU.
//     0b10 ==> Internal bandgap reference and associated ground reference (VBGH and VBGL). Consult the Chip Configuration information for details specific to this MCU.
//     0b11 ==> Reserved

#define  ADC0_SC2_DMAEN_MASK         0x4u
#define  ADC0_SC2_DMAEN_SHIFT        2
//   DMA enable
//     0b0 ==> DMA is disabled.
//     0b1 ==> DMA is enabled and will assert the ADC DMA request during a ADC conversion complete event noted by the assertion of any of the ADC COCO flags.

#define  ADC0_SC2_ACREN_MASK         0x8u
#define  ADC0_SC2_ACREN_SHIFT        3
//   Compare function range enable
//     0b0 ==> Range function disabled. Only the compare value 1 register (CV1) is compared.
//     0b1 ==> Range function enabled. Both compare value registers (CV1 and CV2) are compared.

#define  ADC0_SC2_ACFGT_MASK         0x10u
#define  ADC0_SC2_ACFGT_SHIFT        4
//   Compare function greater than enable
//     0b0 ==> Configures less than threshold, outside range not inclusive and inside range not inclusive functionality based on the values placed in the CV1 and CV2 registers.
//     0b1 ==> Configures greater than or equal to threshold, outside range inclusive and inside range inclusive functionality based on the values placed in the CV1 and CV2 registers.

#define  ADC0_SC2_ACFE_MASK          0x20u
#define  ADC0_SC2_ACFE_SHIFT         5
//   Compare function enable
//     0b0 ==> Compare function disabled.
//     0b1 ==> Compare function enabled.

#define  ADC0_SC2_ADTRG_MASK         0x40u
#define  ADC0_SC2_ADTRG_SHIFT        6
//   Conversion trigger select
//     0b0 ==> Software trigger selected.
//     0b1 ==> Hardware trigger selected.

#define  ADC0_SC2_ADACT_MASK         0x80u
#define  ADC0_SC2_ADACT_SHIFT        7
//   Conversion active
//     0b0 ==> Conversion not in progress.
//     0b1 ==> Conversion in progress.

#define  ADC0_SC3_AVGS_MASK          0x2u
#define  ADC0_SC3_AVGS_SHIFT         0
#define  ADC0_SC3_AVGS(x)            (((uint32_t)(((uint32_t)(x))<<ADC0_SC3_AVGS_SHIFT))&ADC0_SC3_AVGS_MASK)
//   Hardware average select
//     0b00 ==> 4 samples averaged.
//     0b01 ==> 8 samples averaged.
//     0b10 ==> 16 samples averaged.
//     0b11 ==> 32 samples averaged.

#define  ADC0_SC3_AVGE_MASK          0x4u
#define  ADC0_SC3_AVGE_SHIFT         2
//   Hardware average enable
//     0b0 ==> Hardware average function disabled.
//     0b1 ==> Hardware average function enabled.

#define  ADC0_SC3_ADCO_MASK          0x8u
#define  ADC0_SC3_ADCO_SHIFT         3
//   Continuous conversion enable
//     0b0 ==> One conversion or one set of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
//     0b1 ==> Continuous conversions or sets of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.

#define  ADC0_SC3_CALF_MASK          0x40u
#define  ADC0_SC3_CALF_SHIFT         6
//   Calibration failed flag
//     0b0 ==> Calibration completed normally.
//     0b1 ==> Calibration failed. ADC accuracy specifications are not guaranteed.

#define  ADC0_SC3_CAL_MASK           0x80u
#define  ADC0_SC3_CAL_SHIFT          7
//   Calibration

#define  ADC0_OFS_OFS_MASK           0x10u
#define  ADC0_OFS_OFS_SHIFT          0
#define  ADC0_OFS_OFS(x)             (((uint32_t)(((uint32_t)(x))<<ADC0_OFS_OFS_SHIFT))&ADC0_OFS_OFS_MASK)
//   Offset error correction value

#define  ADC0_PG_PG_MASK             0x10u
#define  ADC0_PG_PG_SHIFT            0
#define  ADC0_PG_PG(x)               (((uint32_t)(((uint32_t)(x))<<ADC0_PG_PG_SHIFT))&ADC0_PG_PG_MASK)
//   Plus-side gain

#define  ADC0_CLPD_CLPD_MASK         0x6u
#define  ADC0_CLPD_CLPD_SHIFT        0
#define  ADC0_CLPD_CLPD(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLPD_CLPD_SHIFT))&ADC0_CLPD_CLPD_MASK)

#define  ADC0_CLPS_CLPS_MASK         0x6u
#define  ADC0_CLPS_CLPS_SHIFT        0
#define  ADC0_CLPS_CLPS(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLPS_CLPS_SHIFT))&ADC0_CLPS_CLPS_MASK)

#define  ADC0_CLP4_CLP4_MASK         0xAu
#define  ADC0_CLP4_CLP4_SHIFT        0
#define  ADC0_CLP4_CLP4(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLP4_CLP4_SHIFT))&ADC0_CLP4_CLP4_MASK)

#define  ADC0_CLP3_CLP3_MASK         0x9u
#define  ADC0_CLP3_CLP3_SHIFT        0
#define  ADC0_CLP3_CLP3(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLP3_CLP3_SHIFT))&ADC0_CLP3_CLP3_MASK)

#define  ADC0_CLP2_CLP2_MASK         0x8u
#define  ADC0_CLP2_CLP2_SHIFT        0
#define  ADC0_CLP2_CLP2(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLP2_CLP2_SHIFT))&ADC0_CLP2_CLP2_MASK)

#define  ADC0_CLP1_CLP1_MASK         0x7u
#define  ADC0_CLP1_CLP1_SHIFT        0
#define  ADC0_CLP1_CLP1(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLP1_CLP1_SHIFT))&ADC0_CLP1_CLP1_MASK)

#define  ADC0_CLP0_CLP0_MASK         0x6u
#define  ADC0_CLP0_CLP0_SHIFT        0
#define  ADC0_CLP0_CLP0(x)           (((uint32_t)(((uint32_t)(x))<<ADC0_CLP0_CLP0_SHIFT))&ADC0_CLP0_CLP0_MASK)

#define  CMP0_CR0_HYSTCTR_MASK       0x2u
#define  CMP0_CR0_HYSTCTR_SHIFT      0
#define  CMP0_CR0_HYSTCTR(x)         (((uint8_t)(((uint8_t)(x))<<CMP0_CR0_HYSTCTR_SHIFT))&CMP0_CR0_HYSTCTR_MASK)
//   Comparator hard block hysteresis control
//     0b00 ==> Level 0
//     0b01 ==> Level 1
//     0b10 ==> Level 2
//     0b11 ==> Level 3

#define  CMP0_CR0_FILTER_CNT_MASK    0x30u
#define  CMP0_CR0_FILTER_CNT_SHIFT   4
#define  CMP0_CR0_FILTER_CNT(x)      (((uint8_t)(((uint8_t)(x))<<CMP0_CR0_FILTER_CNT_SHIFT))&CMP0_CR0_FILTER_CNT_MASK)
//   Filter Sample Count
//     0b000 ==> Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
//     0b001 ==> One sample must agree. The comparator output is simply sampled.
//     0b010 ==> 2 consecutive samples must agree.
//     0b011 ==> 3 consecutive samples must agree.
//     0b100 ==> 4 consecutive samples must agree.
//     0b101 ==> 5 consecutive samples must agree.
//     0b110 ==> 6 consecutive samples must agree.
//     0b111 ==> 7 consecutive samples must agree.

#define  CMP0_CR1_EN_MASK            0x1u
#define  CMP0_CR1_EN_SHIFT           0
//   Comparator Module Enable
//     0b0 ==> Analog Comparator is disabled.
//     0b1 ==> Analog Comparator is enabled.

#define  CMP0_CR1_OPE_MASK           0x2u
#define  CMP0_CR1_OPE_SHIFT          1
//   Comparator Output Pin Enable
//     0b0 ==> CMPO is not available on the associated CMPO output pin. Instead, INV is driven if the comparator owns the pin, which is usually a result of properly setting pin mux controls at the SoC level. If the comparator does not own the pin, this field has no effect.
//     0b1 ==> CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this bit has no effect.

#define  CMP0_CR1_COS_MASK           0x4u
#define  CMP0_CR1_COS_SHIFT          2
//   Comparator Output Select
//     0b0 ==> Set the filtered comparator output (CMPO) to equal COUT.
//     0b1 ==> Set the unfiltered comparator output (CMPO) to equal COUTA.

#define  CMP0_CR1_INV_MASK           0x8u
#define  CMP0_CR1_INV_SHIFT          3
//   Comparator INVERT
//     0b0 ==> Does not invert the comparator output.
//     0b1 ==> Inverts the comparator output.

#define  CMP0_CR1_PMODE_MASK         0x10u
#define  CMP0_CR1_PMODE_SHIFT        4
//   Power Mode Select
//     0b0 ==> Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
//     0b1 ==> High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.

#define  CMP0_CR1_WE_MASK            0x40u
#define  CMP0_CR1_WE_SHIFT           6
//   Windowing Enable
//     0b0 ==> Windowing mode is not selected.
//     0b1 ==> Windowing mode is selected.

#define  CMP0_CR1_SE_MASK            0x80u
#define  CMP0_CR1_SE_SHIFT           7
//   Sample Enable
//     0b0 ==> Sampling mode is not selected.
//     0b1 ==> Sampling mode is selected.

#define  CMP0_FPR_FILT_PER_MASK      0x8u
#define  CMP0_FPR_FILT_PER_SHIFT     0
#define  CMP0_FPR_FILT_PER(x)        (((uint8_t)(((uint8_t)(x))<<CMP0_FPR_FILT_PER_SHIFT))&CMP0_FPR_FILT_PER_MASK)
//   Filter Sample Period

#define  CMP0_SCR_COUT_MASK          0x1u
#define  CMP0_SCR_COUT_SHIFT         0
//   Analog Comparator Output

#define  CMP0_SCR_CFF_MASK           0x2u
#define  CMP0_SCR_CFF_SHIFT          1
//   Analog Comparator Flag Falling
//     0b0 ==> Falling-edge on COUT has not been detected.
//     0b1 ==> Falling-edge on COUT has occurred.

#define  CMP0_SCR_CFR_MASK           0x4u
#define  CMP0_SCR_CFR_SHIFT          2
//   Analog Comparator Flag Rising
//     0b0 ==> Rising-edge on COUT has not been detected.
//     0b1 ==> Rising-edge on COUT has occurred.

#define  CMP0_SCR_IEF_MASK           0x8u
#define  CMP0_SCR_IEF_SHIFT          3
//   Comparator Interrupt Enable Falling
//     0b0 ==> Interrupt is disabled.
//     0b1 ==> Interrupt is enabled.

#define  CMP0_SCR_IER_MASK           0x10u
#define  CMP0_SCR_IER_SHIFT          4
//   Comparator Interrupt Enable Rising
//     0b0 ==> Interrupt is disabled.
//     0b1 ==> Interrupt is enabled.

#define  CMP0_SCR_DMAEN_MASK         0x40u
#define  CMP0_SCR_DMAEN_SHIFT        6
//   DMA Enable Control
//     0b0 ==> DMA is disabled.
//     0b1 ==> DMA is enabled.

#define  CMP0_DACCR_VOSEL_MASK       0x6u
#define  CMP0_DACCR_VOSEL_SHIFT      0
#define  CMP0_DACCR_VOSEL(x)         (((uint8_t)(((uint8_t)(x))<<CMP0_DACCR_VOSEL_SHIFT))&CMP0_DACCR_VOSEL_MASK)
//   DAC Output Voltage Select

#define  CMP0_DACCR_VRSEL_MASK       0x40u
#define  CMP0_DACCR_VRSEL_SHIFT      6
//   Supply Voltage Reference Source Select
//     0b0 ==> V is selected as resistor ladder network supply reference V. in1 in
//     0b1 ==> V is selected as resistor ladder network supply reference V. in2 in

#define  CMP0_DACCR_DACEN_MASK       0x80u
#define  CMP0_DACCR_DACEN_SHIFT      7
//   DAC Enable
//     0b0 ==> DAC is disabled.
//     0b1 ==> DAC is enabled.

#define  CMP0_MUXCR_MSEL_MASK        0x3u
#define  CMP0_MUXCR_MSEL_SHIFT       0
#define  CMP0_MUXCR_MSEL(x)          (((uint8_t)(((uint8_t)(x))<<CMP0_MUXCR_MSEL_SHIFT))&CMP0_MUXCR_MSEL_MASK)
//   Minus Input Mux Control
//     0b000 ==> IN0
//     0b001 ==> IN1
//     0b010 ==> IN2
//     0b011 ==> IN3
//     0b100 ==> IN4
//     0b101 ==> IN5
//     0b110 ==> IN6
//     0b111 ==> IN7

#define  CMP0_MUXCR_PSEL_MASK        0x18u
#define  CMP0_MUXCR_PSEL_SHIFT       3
#define  CMP0_MUXCR_PSEL(x)          (((uint8_t)(((uint8_t)(x))<<CMP0_MUXCR_PSEL_SHIFT))&CMP0_MUXCR_PSEL_MASK)
//   Plus Input Mux Control
//     0b000 ==> IN0
//     0b001 ==> IN1
//     0b010 ==> IN2
//     0b011 ==> IN3
//     0b100 ==> IN4
//     0b101 ==> IN5
//     0b110 ==> IN6
//     0b111 ==> IN7

#define  CMP0_MUXCR_PSTM_MASK        0x40u
#define  CMP0_MUXCR_PSTM_SHIFT       6
//   Pass Through Mode Enable
//     0b0 ==> Pass Through Mode is disabled.
//     0b1 ==> Pass Through Mode is enabled.

#define  DAC_DAT0L_DATA_MASK         0x8u
#define  DAC_DAT0L_DATA_SHIFT        0
#define  DAC_DAT0L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT0L_DATA_SHIFT))&DAC_DAT0L_DATA_MASK)

#define  DAC_DAT0H_DATA_MASK         0x4u
#define  DAC_DAT0H_DATA_SHIFT        0
#define  DAC_DAT0H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT0H_DATA_SHIFT))&DAC_DAT0H_DATA_MASK)

#define  DAC_DAT1L_DATA_MASK         0x8u
#define  DAC_DAT1L_DATA_SHIFT        0
#define  DAC_DAT1L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT1L_DATA_SHIFT))&DAC_DAT1L_DATA_MASK)

#define  DAC_DAT1H_DATA_MASK         0x4u
#define  DAC_DAT1H_DATA_SHIFT        0
#define  DAC_DAT1H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT1H_DATA_SHIFT))&DAC_DAT1H_DATA_MASK)

#define  DAC_DAT2L_DATA_MASK         0x8u
#define  DAC_DAT2L_DATA_SHIFT        0
#define  DAC_DAT2L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT2L_DATA_SHIFT))&DAC_DAT2L_DATA_MASK)

#define  DAC_DAT2H_DATA_MASK         0x4u
#define  DAC_DAT2H_DATA_SHIFT        0
#define  DAC_DAT2H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT2H_DATA_SHIFT))&DAC_DAT2H_DATA_MASK)

#define  DAC_DAT3L_DATA_MASK         0x8u
#define  DAC_DAT3L_DATA_SHIFT        0
#define  DAC_DAT3L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT3L_DATA_SHIFT))&DAC_DAT3L_DATA_MASK)

#define  DAC_DAT3H_DATA_MASK         0x4u
#define  DAC_DAT3H_DATA_SHIFT        0
#define  DAC_DAT3H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT3H_DATA_SHIFT))&DAC_DAT3H_DATA_MASK)

#define  DAC_DAT4L_DATA_MASK         0x8u
#define  DAC_DAT4L_DATA_SHIFT        0
#define  DAC_DAT4L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT4L_DATA_SHIFT))&DAC_DAT4L_DATA_MASK)

#define  DAC_DAT4H_DATA_MASK         0x4u
#define  DAC_DAT4H_DATA_SHIFT        0
#define  DAC_DAT4H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT4H_DATA_SHIFT))&DAC_DAT4H_DATA_MASK)

#define  DAC_DAT5L_DATA_MASK         0x8u
#define  DAC_DAT5L_DATA_SHIFT        0
#define  DAC_DAT5L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT5L_DATA_SHIFT))&DAC_DAT5L_DATA_MASK)

#define  DAC_DAT5H_DATA_MASK         0x4u
#define  DAC_DAT5H_DATA_SHIFT        0
#define  DAC_DAT5H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT5H_DATA_SHIFT))&DAC_DAT5H_DATA_MASK)

#define  DAC_DAT6L_DATA_MASK         0x8u
#define  DAC_DAT6L_DATA_SHIFT        0
#define  DAC_DAT6L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT6L_DATA_SHIFT))&DAC_DAT6L_DATA_MASK)

#define  DAC_DAT6H_DATA_MASK         0x4u
#define  DAC_DAT6H_DATA_SHIFT        0
#define  DAC_DAT6H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT6H_DATA_SHIFT))&DAC_DAT6H_DATA_MASK)

#define  DAC_DAT7L_DATA_MASK         0x8u
#define  DAC_DAT7L_DATA_SHIFT        0
#define  DAC_DAT7L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT7L_DATA_SHIFT))&DAC_DAT7L_DATA_MASK)

#define  DAC_DAT7H_DATA_MASK         0x4u
#define  DAC_DAT7H_DATA_SHIFT        0
#define  DAC_DAT7H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT7H_DATA_SHIFT))&DAC_DAT7H_DATA_MASK)

#define  DAC_DAT8L_DATA_MASK         0x8u
#define  DAC_DAT8L_DATA_SHIFT        0
#define  DAC_DAT8L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT8L_DATA_SHIFT))&DAC_DAT8L_DATA_MASK)

#define  DAC_DAT8H_DATA_MASK         0x4u
#define  DAC_DAT8H_DATA_SHIFT        0
#define  DAC_DAT8H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT8H_DATA_SHIFT))&DAC_DAT8H_DATA_MASK)

#define  DAC_DAT9L_DATA_MASK         0x8u
#define  DAC_DAT9L_DATA_SHIFT        0
#define  DAC_DAT9L_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT9L_DATA_SHIFT))&DAC_DAT9L_DATA_MASK)

#define  DAC_DAT9H_DATA_MASK         0x4u
#define  DAC_DAT9H_DATA_SHIFT        0
#define  DAC_DAT9H_DATA(x)           (((uint8_t)(((uint8_t)(x))<<DAC_DAT9H_DATA_SHIFT))&DAC_DAT9H_DATA_MASK)

#define  DAC_DAT10L_DATA_MASK        0x8u
#define  DAC_DAT10L_DATA_SHIFT       0
#define  DAC_DAT10L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT10L_DATA_SHIFT))&DAC_DAT10L_DATA_MASK)

#define  DAC_DAT10H_DATA_MASK        0x4u
#define  DAC_DAT10H_DATA_SHIFT       0
#define  DAC_DAT10H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT10H_DATA_SHIFT))&DAC_DAT10H_DATA_MASK)

#define  DAC_DAT11L_DATA_MASK        0x8u
#define  DAC_DAT11L_DATA_SHIFT       0
#define  DAC_DAT11L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT11L_DATA_SHIFT))&DAC_DAT11L_DATA_MASK)

#define  DAC_DAT11H_DATA_MASK        0x4u
#define  DAC_DAT11H_DATA_SHIFT       0
#define  DAC_DAT11H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT11H_DATA_SHIFT))&DAC_DAT11H_DATA_MASK)

#define  DAC_DAT12L_DATA_MASK        0x8u
#define  DAC_DAT12L_DATA_SHIFT       0
#define  DAC_DAT12L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT12L_DATA_SHIFT))&DAC_DAT12L_DATA_MASK)

#define  DAC_DAT12H_DATA_MASK        0x4u
#define  DAC_DAT12H_DATA_SHIFT       0
#define  DAC_DAT12H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT12H_DATA_SHIFT))&DAC_DAT12H_DATA_MASK)

#define  DAC_DAT13L_DATA_MASK        0x8u
#define  DAC_DAT13L_DATA_SHIFT       0
#define  DAC_DAT13L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT13L_DATA_SHIFT))&DAC_DAT13L_DATA_MASK)

#define  DAC_DAT13H_DATA_MASK        0x4u
#define  DAC_DAT13H_DATA_SHIFT       0
#define  DAC_DAT13H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT13H_DATA_SHIFT))&DAC_DAT13H_DATA_MASK)

#define  DAC_DAT14L_DATA_MASK        0x8u
#define  DAC_DAT14L_DATA_SHIFT       0
#define  DAC_DAT14L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT14L_DATA_SHIFT))&DAC_DAT14L_DATA_MASK)

#define  DAC_DAT14H_DATA_MASK        0x4u
#define  DAC_DAT14H_DATA_SHIFT       0
#define  DAC_DAT14H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT14H_DATA_SHIFT))&DAC_DAT14H_DATA_MASK)

#define  DAC_DAT15L_DATA_MASK        0x8u
#define  DAC_DAT15L_DATA_SHIFT       0
#define  DAC_DAT15L_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT15L_DATA_SHIFT))&DAC_DAT15L_DATA_MASK)

#define  DAC_DAT15H_DATA_MASK        0x4u
#define  DAC_DAT15H_DATA_SHIFT       0
#define  DAC_DAT15H_DATA(x)          (((uint8_t)(((uint8_t)(x))<<DAC_DAT15H_DATA_SHIFT))&DAC_DAT15H_DATA_MASK)

#define  DAC_SR_DACBFRPBF_MASK       0x1u
#define  DAC_SR_DACBFRPBF_SHIFT      0
//   DAC Buffer Read Pointer Bottom Position Flag
//     0b0 ==> The DAC buffer read pointer is not equal to C2[DACBFUP].
//     0b1 ==> The DAC buffer read pointer is equal to C2[DACBFUP].

#define  DAC_SR_DACBFRPTF_MASK       0x2u
#define  DAC_SR_DACBFRPTF_SHIFT      1
//   DAC Buffer Read Pointer Top Position Flag
//     0b0 ==> The DAC buffer read pointer is not zero.
//     0b1 ==> The DAC buffer read pointer is zero.

#define  DAC_SR_DACBFWMF_MASK        0x4u
#define  DAC_SR_DACBFWMF_SHIFT       2
//   DAC Buffer Watermark Flag
//     0b0 ==> The DAC buffer read pointer has not reached the watermark level.
//     0b1 ==> The DAC buffer read pointer has reached the watermark level.

#define  DAC_C0_DACBBIEN_MASK        0x1u
#define  DAC_C0_DACBBIEN_SHIFT       0
//   DAC Buffer Read Pointer Bottom Flag Interrupt Enable
//     0b0 ==> The DAC buffer read pointer bottom flag interrupt is disabled.
//     0b1 ==> The DAC buffer read pointer bottom flag interrupt is enabled.

#define  DAC_C0_DACBTIEN_MASK        0x2u
#define  DAC_C0_DACBTIEN_SHIFT       1
//   DAC Buffer Read Pointer Top Flag Interrupt Enable
//     0b0 ==> The DAC buffer read pointer top flag interrupt is disabled.
//     0b1 ==> The DAC buffer read pointer top flag interrupt is enabled.

#define  DAC_C0_DACBWIEN_MASK        0x4u
#define  DAC_C0_DACBWIEN_SHIFT       2
//   DAC Buffer Watermark Interrupt Enable
//     0b0 ==> The DAC buffer watermark interrupt is disabled.
//     0b1 ==> The DAC buffer watermark interrupt is enabled.

#define  DAC_C0_LPEN_MASK            0x8u
#define  DAC_C0_LPEN_SHIFT           3
//   DAC Low Power Control
//     0b0 ==> High-Power mode
//     0b1 ==> Low-Power mode

#define  DAC_C0_DACSWTRG_MASK        0x10u
#define  DAC_C0_DACSWTRG_SHIFT       4
//   DAC Software Trigger
//     0b0 ==> The DAC soft trigger is not valid.
//     0b1 ==> The DAC soft trigger is valid.

#define  DAC_C0_DACTRGSEL_MASK       0x20u
#define  DAC_C0_DACTRGSEL_SHIFT      5
//   DAC Trigger Select
//     0b0 ==> The DAC hardware trigger is selected.
//     0b1 ==> The DAC software trigger is selected.

#define  DAC_C0_DACRFS_MASK          0x40u
#define  DAC_C0_DACRFS_SHIFT         6
//   DAC Reference Select
//     0b0 ==> The DAC selects DACREF_1 as the reference voltage.
//     0b1 ==> The DAC selects DACREF_2 as the reference voltage.

#define  DAC_C0_DACEN_MASK           0x80u
#define  DAC_C0_DACEN_SHIFT          7
//   DAC Enable
//     0b0 ==> The DAC system is disabled.
//     0b1 ==> The DAC system is enabled.

#define  DAC_C1_DACBFEN_MASK         0x1u
#define  DAC_C1_DACBFEN_SHIFT        0
//   DAC Buffer Enable
//     0b0 ==> Buffer read pointer is disabled. The converted data is always the first word of the buffer.
//     0b1 ==> Buffer read pointer is enabled. The converted data is the word that the read pointer points to. It means converted data can be from any word of the buffer.

#define  DAC_C1_DACBFMD_MASK         0x4u
#define  DAC_C1_DACBFMD_SHIFT        1
#define  DAC_C1_DACBFMD(x)           (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK)
//   DAC Buffer Work Mode Select
//     0b00 ==> Normal mode
//     0b01 ==> Swing mode
//     0b10 ==> One-Time Scan mode
//     0b11 ==> Reserved

#define  DAC_C1_DACBFWM_MASK         0x10u
#define  DAC_C1_DACBFWM_SHIFT        3
#define  DAC_C1_DACBFWM(x)           (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK)
//   DAC Buffer Watermark Select
//     0b00 ==> 1 word
//     0b01 ==> 2 words
//     0b10 ==> 3 words
//     0b11 ==> 4 words

#define  DAC_C1_DMAEN_MASK           0x80u
#define  DAC_C1_DMAEN_SHIFT          7
//   DMA Enable Select
//     0b0 ==> DMA is disabled.
//     0b1 ==> DMA is enabled. When DMA is enabled, the DMA request will be generated by original interrupts. The interrupts will not be presented on this module at the same time.

#define  DAC_C2_DACBFUP_MASK         0x4u
#define  DAC_C2_DACBFUP_SHIFT        0
#define  DAC_C2_DACBFUP(x)           (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK)
//   DAC Buffer Upper Limit

#define  DAC_C2_DACBFRP_MASK         0x40u
#define  DAC_C2_DACBFRP_SHIFT        4
#define  DAC_C2_DACBFRP(x)           (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK)
//   DAC Buffer Read Pointer

#define  DMA_SAR0_SAR_MASK           0x20u
#define  DMA_SAR0_SAR_SHIFT          0
#define  DMA_SAR0_SAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_SAR0_SAR_SHIFT))&DMA_SAR0_SAR_MASK)

#define  DMA_DAR0_DAR_MASK           0x20u
#define  DMA_DAR0_DAR_SHIFT          0
#define  DMA_DAR0_DAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_DAR0_DAR_SHIFT))&DMA_DAR0_DAR_MASK)

#define  DMA_DSR_BCR0_BCR_MASK       0x18u
#define  DMA_DSR_BCR0_BCR_SHIFT      0
#define  DMA_DSR_BCR0_BCR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR0_BCR_SHIFT))&DMA_DSR_BCR0_BCR_MASK)

#define  DMA_DSR_BCR0_DONE_MASK      0x1000000u
#define  DMA_DSR_BCR0_DONE_SHIFT     24
//   Transactions done
//     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
//     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

#define  DMA_DSR_BCR0_BSY_MASK       0x2000000u
#define  DMA_DSR_BCR0_BSY_SHIFT      25
//   Busy
//     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
//     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

#define  DMA_DSR_BCR0_REQ_MASK       0x4000000u
#define  DMA_DSR_BCR0_REQ_SHIFT      26
//   Request
//     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
//     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

#define  DMA_DSR_BCR0_BED_MASK       0x10000000u
#define  DMA_DSR_BCR0_BED_SHIFT      28
//   Bus error on destination
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

#define  DMA_DSR_BCR0_BES_MASK       0x20000000u
#define  DMA_DSR_BCR0_BES_SHIFT      29
//   Bus error on source
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

#define  DMA_DSR_BCR0_CE_MASK        0x40000000u
#define  DMA_DSR_BCR0_CE_SHIFT       30
//   Configuration error
//     0b0 ==> No configuration error exists.
//     0b1 ==> A configuration error has occurred.

#define  DMA_DCR0_LCH2_MASK          0x2u
#define  DMA_DCR0_LCH2_SHIFT         0
#define  DMA_DCR0_LCH2(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_LCH2_SHIFT))&DMA_DCR0_LCH2_MASK)
//   Link channel 2
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR0_LCH1_MASK          0x8u
#define  DMA_DCR0_LCH1_SHIFT         2
#define  DMA_DCR0_LCH1(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_LCH1_SHIFT))&DMA_DCR0_LCH1_MASK)
//   Link channel 1
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR0_LINKCC_MASK        0x20u
#define  DMA_DCR0_LINKCC_SHIFT       4
#define  DMA_DCR0_LINKCC(x)          (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_LINKCC_SHIFT))&DMA_DCR0_LINKCC_MASK)
//   Link channel control
//     0b00 ==> No channel-to-channel linking
//     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
//     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
//     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero

#define  DMA_DCR0_D_REQ_MASK         0x80u
#define  DMA_DCR0_D_REQ_SHIFT        7
//   Disable request
//     0b0 ==> ERQ bit is not affected.
//     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

#define  DMA_DCR0_DMOD_MASK          0x400u
#define  DMA_DCR0_DMOD_SHIFT         8
#define  DMA_DCR0_DMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_DMOD_SHIFT))&DMA_DCR0_DMOD_MASK)
//   Destination address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR0_SMOD_MASK          0x4000u
#define  DMA_DCR0_SMOD_SHIFT         12
#define  DMA_DCR0_SMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_SMOD_SHIFT))&DMA_DCR0_SMOD_MASK)
//   Source address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR0_START_MASK         0x10000u
#define  DMA_DCR0_START_SHIFT        16
//   Start transfer
//     0b0 ==> DMA inactive
//     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

#define  DMA_DCR0_DSIZE_MASK         0x40000u
#define  DMA_DCR0_DSIZE_SHIFT        17
#define  DMA_DCR0_DSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_DSIZE_SHIFT))&DMA_DCR0_DSIZE_MASK)
//   Destination size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR0_DINC_MASK          0x80000u
#define  DMA_DCR0_DINC_SHIFT         19
//   Destination increment
//     0b0 ==> No change to the DAR after a successful transfer.
//     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

#define  DMA_DCR0_SSIZE_MASK         0x200000u
#define  DMA_DCR0_SSIZE_SHIFT        20
#define  DMA_DCR0_SSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR0_SSIZE_SHIFT))&DMA_DCR0_SSIZE_MASK)
//   Source size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR0_SINC_MASK          0x400000u
#define  DMA_DCR0_SINC_SHIFT         22
//   Source increment
//     0b0 ==> No change to SAR after a successful transfer.
//     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

#define  DMA_DCR0_AA_MASK            0x10000000u
#define  DMA_DCR0_AA_SHIFT           28
//   Auto-align
//     0b0 ==> Auto-align disabled
//     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

#define  DMA_DCR0_CS_MASK            0x20000000u
#define  DMA_DCR0_CS_SHIFT           29
//   Cycle steal
//     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
//     0b1 ==> Forces a single read/write transfer per request.

#define  DMA_DCR0_ERQ_MASK           0x40000000u
#define  DMA_DCR0_ERQ_SHIFT          30
//   Enable peripheral request
//     0b0 ==> Peripheral request is ignored.
//     0b1 ==> Enables peripheral request to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

#define  DMA_DCR0_EINT_MASK          0x80000000u
#define  DMA_DCR0_EINT_SHIFT         31
//   Enable interrupt on completion of transfer
//     0b0 ==> No interrupt is generated.
//     0b1 ==> Interrupt signal is enabled.

#define  DMA_SAR1_SAR_MASK           0x20u
#define  DMA_SAR1_SAR_SHIFT          0
#define  DMA_SAR1_SAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_SAR1_SAR_SHIFT))&DMA_SAR1_SAR_MASK)

#define  DMA_DAR1_DAR_MASK           0x20u
#define  DMA_DAR1_DAR_SHIFT          0
#define  DMA_DAR1_DAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_DAR1_DAR_SHIFT))&DMA_DAR1_DAR_MASK)

#define  DMA_DSR_BCR1_BCR_MASK       0x18u
#define  DMA_DSR_BCR1_BCR_SHIFT      0
#define  DMA_DSR_BCR1_BCR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR1_BCR_SHIFT))&DMA_DSR_BCR1_BCR_MASK)

#define  DMA_DSR_BCR1_DONE_MASK      0x1000000u
#define  DMA_DSR_BCR1_DONE_SHIFT     24
//   Transactions done
//     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
//     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

#define  DMA_DSR_BCR1_BSY_MASK       0x2000000u
#define  DMA_DSR_BCR1_BSY_SHIFT      25
//   Busy
//     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
//     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

#define  DMA_DSR_BCR1_REQ_MASK       0x4000000u
#define  DMA_DSR_BCR1_REQ_SHIFT      26
//   Request
//     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
//     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

#define  DMA_DSR_BCR1_BED_MASK       0x10000000u
#define  DMA_DSR_BCR1_BED_SHIFT      28
//   Bus error on destination
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

#define  DMA_DSR_BCR1_BES_MASK       0x20000000u
#define  DMA_DSR_BCR1_BES_SHIFT      29
//   Bus error on source
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

#define  DMA_DSR_BCR1_CE_MASK        0x40000000u
#define  DMA_DSR_BCR1_CE_SHIFT       30
//   Configuration error
//     0b0 ==> No configuration error exists.
//     0b1 ==> A configuration error has occurred.

#define  DMA_DCR1_LCH2_MASK          0x2u
#define  DMA_DCR1_LCH2_SHIFT         0
#define  DMA_DCR1_LCH2(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_LCH2_SHIFT))&DMA_DCR1_LCH2_MASK)
//   Link channel 2
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR1_LCH1_MASK          0x8u
#define  DMA_DCR1_LCH1_SHIFT         2
#define  DMA_DCR1_LCH1(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_LCH1_SHIFT))&DMA_DCR1_LCH1_MASK)
//   Link channel 1
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR1_LINKCC_MASK        0x20u
#define  DMA_DCR1_LINKCC_SHIFT       4
#define  DMA_DCR1_LINKCC(x)          (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_LINKCC_SHIFT))&DMA_DCR1_LINKCC_MASK)
//   Link channel control
//     0b00 ==> No channel-to-channel linking
//     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
//     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
//     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero

#define  DMA_DCR1_D_REQ_MASK         0x80u
#define  DMA_DCR1_D_REQ_SHIFT        7
//   Disable request
//     0b0 ==> ERQ bit is not affected.
//     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

#define  DMA_DCR1_DMOD_MASK          0x400u
#define  DMA_DCR1_DMOD_SHIFT         8
#define  DMA_DCR1_DMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_DMOD_SHIFT))&DMA_DCR1_DMOD_MASK)
//   Destination address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR1_SMOD_MASK          0x4000u
#define  DMA_DCR1_SMOD_SHIFT         12
#define  DMA_DCR1_SMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_SMOD_SHIFT))&DMA_DCR1_SMOD_MASK)
//   Source address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR1_START_MASK         0x10000u
#define  DMA_DCR1_START_SHIFT        16
//   Start transfer
//     0b0 ==> DMA inactive
//     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

#define  DMA_DCR1_DSIZE_MASK         0x40000u
#define  DMA_DCR1_DSIZE_SHIFT        17
#define  DMA_DCR1_DSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_DSIZE_SHIFT))&DMA_DCR1_DSIZE_MASK)
//   Destination size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR1_DINC_MASK          0x80000u
#define  DMA_DCR1_DINC_SHIFT         19
//   Destination increment
//     0b0 ==> No change to the DAR after a successful transfer.
//     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

#define  DMA_DCR1_SSIZE_MASK         0x200000u
#define  DMA_DCR1_SSIZE_SHIFT        20
#define  DMA_DCR1_SSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR1_SSIZE_SHIFT))&DMA_DCR1_SSIZE_MASK)
//   Source size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR1_SINC_MASK          0x400000u
#define  DMA_DCR1_SINC_SHIFT         22
//   Source increment
//     0b0 ==> No change to SAR after a successful transfer.
//     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

#define  DMA_DCR1_AA_MASK            0x10000000u
#define  DMA_DCR1_AA_SHIFT           28
//   Auto-align
//     0b0 ==> Auto-align disabled
//     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

#define  DMA_DCR1_CS_MASK            0x20000000u
#define  DMA_DCR1_CS_SHIFT           29
//   Cycle steal
//     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
//     0b1 ==> Forces a single read/write transfer per request.

#define  DMA_DCR1_ERQ_MASK           0x40000000u
#define  DMA_DCR1_ERQ_SHIFT          30
//   Enable peripheral request
//     0b0 ==> Peripheral request is ignored.
//     0b1 ==> Enables peripheral request to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

#define  DMA_DCR1_EINT_MASK          0x80000000u
#define  DMA_DCR1_EINT_SHIFT         31
//   Enable interrupt on completion of transfer
//     0b0 ==> No interrupt is generated.
//     0b1 ==> Interrupt signal is enabled.

#define  DMA_SAR2_SAR_MASK           0x20u
#define  DMA_SAR2_SAR_SHIFT          0
#define  DMA_SAR2_SAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_SAR2_SAR_SHIFT))&DMA_SAR2_SAR_MASK)

#define  DMA_DAR2_DAR_MASK           0x20u
#define  DMA_DAR2_DAR_SHIFT          0
#define  DMA_DAR2_DAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_DAR2_DAR_SHIFT))&DMA_DAR2_DAR_MASK)

#define  DMA_DSR_BCR2_BCR_MASK       0x18u
#define  DMA_DSR_BCR2_BCR_SHIFT      0
#define  DMA_DSR_BCR2_BCR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR2_BCR_SHIFT))&DMA_DSR_BCR2_BCR_MASK)

#define  DMA_DSR_BCR2_DONE_MASK      0x1000000u
#define  DMA_DSR_BCR2_DONE_SHIFT     24
//   Transactions done
//     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
//     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

#define  DMA_DSR_BCR2_BSY_MASK       0x2000000u
#define  DMA_DSR_BCR2_BSY_SHIFT      25
//   Busy
//     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
//     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

#define  DMA_DSR_BCR2_REQ_MASK       0x4000000u
#define  DMA_DSR_BCR2_REQ_SHIFT      26
//   Request
//     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
//     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

#define  DMA_DSR_BCR2_BED_MASK       0x10000000u
#define  DMA_DSR_BCR2_BED_SHIFT      28
//   Bus error on destination
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

#define  DMA_DSR_BCR2_BES_MASK       0x20000000u
#define  DMA_DSR_BCR2_BES_SHIFT      29
//   Bus error on source
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

#define  DMA_DSR_BCR2_CE_MASK        0x40000000u
#define  DMA_DSR_BCR2_CE_SHIFT       30
//   Configuration error
//     0b0 ==> No configuration error exists.
//     0b1 ==> A configuration error has occurred.

#define  DMA_DCR2_LCH2_MASK          0x2u
#define  DMA_DCR2_LCH2_SHIFT         0
#define  DMA_DCR2_LCH2(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_LCH2_SHIFT))&DMA_DCR2_LCH2_MASK)
//   Link channel 2
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR2_LCH1_MASK          0x8u
#define  DMA_DCR2_LCH1_SHIFT         2
#define  DMA_DCR2_LCH1(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_LCH1_SHIFT))&DMA_DCR2_LCH1_MASK)
//   Link channel 1
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR2_LINKCC_MASK        0x20u
#define  DMA_DCR2_LINKCC_SHIFT       4
#define  DMA_DCR2_LINKCC(x)          (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_LINKCC_SHIFT))&DMA_DCR2_LINKCC_MASK)
//   Link channel control
//     0b00 ==> No channel-to-channel linking
//     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
//     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
//     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero

#define  DMA_DCR2_D_REQ_MASK         0x80u
#define  DMA_DCR2_D_REQ_SHIFT        7
//   Disable request
//     0b0 ==> ERQ bit is not affected.
//     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

#define  DMA_DCR2_DMOD_MASK          0x400u
#define  DMA_DCR2_DMOD_SHIFT         8
#define  DMA_DCR2_DMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_DMOD_SHIFT))&DMA_DCR2_DMOD_MASK)
//   Destination address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR2_SMOD_MASK          0x4000u
#define  DMA_DCR2_SMOD_SHIFT         12
#define  DMA_DCR2_SMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_SMOD_SHIFT))&DMA_DCR2_SMOD_MASK)
//   Source address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR2_START_MASK         0x10000u
#define  DMA_DCR2_START_SHIFT        16
//   Start transfer
//     0b0 ==> DMA inactive
//     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

#define  DMA_DCR2_DSIZE_MASK         0x40000u
#define  DMA_DCR2_DSIZE_SHIFT        17
#define  DMA_DCR2_DSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_DSIZE_SHIFT))&DMA_DCR2_DSIZE_MASK)
//   Destination size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR2_DINC_MASK          0x80000u
#define  DMA_DCR2_DINC_SHIFT         19
//   Destination increment
//     0b0 ==> No change to the DAR after a successful transfer.
//     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

#define  DMA_DCR2_SSIZE_MASK         0x200000u
#define  DMA_DCR2_SSIZE_SHIFT        20
#define  DMA_DCR2_SSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR2_SSIZE_SHIFT))&DMA_DCR2_SSIZE_MASK)
//   Source size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR2_SINC_MASK          0x400000u
#define  DMA_DCR2_SINC_SHIFT         22
//   Source increment
//     0b0 ==> No change to SAR after a successful transfer.
//     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

#define  DMA_DCR2_AA_MASK            0x10000000u
#define  DMA_DCR2_AA_SHIFT           28
//   Auto-align
//     0b0 ==> Auto-align disabled
//     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

#define  DMA_DCR2_CS_MASK            0x20000000u
#define  DMA_DCR2_CS_SHIFT           29
//   Cycle steal
//     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
//     0b1 ==> Forces a single read/write transfer per request.

#define  DMA_DCR2_ERQ_MASK           0x40000000u
#define  DMA_DCR2_ERQ_SHIFT          30
//   Enable peripheral request
//     0b0 ==> Peripheral request is ignored.
//     0b1 ==> Enables peripheral request to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

#define  DMA_DCR2_EINT_MASK          0x80000000u
#define  DMA_DCR2_EINT_SHIFT         31
//   Enable interrupt on completion of transfer
//     0b0 ==> No interrupt is generated.
//     0b1 ==> Interrupt signal is enabled.

#define  DMA_SAR3_SAR_MASK           0x20u
#define  DMA_SAR3_SAR_SHIFT          0
#define  DMA_SAR3_SAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_SAR3_SAR_SHIFT))&DMA_SAR3_SAR_MASK)

#define  DMA_DAR3_DAR_MASK           0x20u
#define  DMA_DAR3_DAR_SHIFT          0
#define  DMA_DAR3_DAR(x)             (((uint32_t)(((uint32_t)(x))<<DMA_DAR3_DAR_SHIFT))&DMA_DAR3_DAR_MASK)

#define  DMA_DSR_BCR3_BCR_MASK       0x18u
#define  DMA_DSR_BCR3_BCR_SHIFT      0
#define  DMA_DSR_BCR3_BCR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR3_BCR_SHIFT))&DMA_DSR_BCR3_BCR_MASK)

#define  DMA_DSR_BCR3_DONE_MASK      0x1000000u
#define  DMA_DSR_BCR3_DONE_SHIFT     24
//   Transactions done
//     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
//     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

#define  DMA_DSR_BCR3_BSY_MASK       0x2000000u
#define  DMA_DSR_BCR3_BSY_SHIFT      25
//   Busy
//     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
//     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

#define  DMA_DSR_BCR3_REQ_MASK       0x4000000u
#define  DMA_DSR_BCR3_REQ_SHIFT      26
//   Request
//     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
//     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

#define  DMA_DSR_BCR3_BED_MASK       0x10000000u
#define  DMA_DSR_BCR3_BED_SHIFT      28
//   Bus error on destination
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

#define  DMA_DSR_BCR3_BES_MASK       0x20000000u
#define  DMA_DSR_BCR3_BES_SHIFT      29
//   Bus error on source
//     0b0 ==> No bus error occurred.
//     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

#define  DMA_DSR_BCR3_CE_MASK        0x40000000u
#define  DMA_DSR_BCR3_CE_SHIFT       30
//   Configuration error
//     0b0 ==> No configuration error exists.
//     0b1 ==> A configuration error has occurred.

#define  DMA_DCR3_LCH2_MASK          0x2u
#define  DMA_DCR3_LCH2_SHIFT         0
#define  DMA_DCR3_LCH2(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_LCH2_SHIFT))&DMA_DCR3_LCH2_MASK)
//   Link channel 2
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR3_LCH1_MASK          0x8u
#define  DMA_DCR3_LCH1_SHIFT         2
#define  DMA_DCR3_LCH1(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_LCH1_SHIFT))&DMA_DCR3_LCH1_MASK)
//   Link channel 1
//     0b00 ==> DMA Channel 0
//     0b01 ==> DMA Channel 1
//     0b10 ==> DMA Channel 2
//     0b11 ==> DMA Channel 3

#define  DMA_DCR3_LINKCC_MASK        0x20u
#define  DMA_DCR3_LINKCC_SHIFT       4
#define  DMA_DCR3_LINKCC(x)          (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_LINKCC_SHIFT))&DMA_DCR3_LINKCC_MASK)
//   Link channel control
//     0b00 ==> No channel-to-channel linking
//     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
//     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
//     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero

#define  DMA_DCR3_D_REQ_MASK         0x80u
#define  DMA_DCR3_D_REQ_SHIFT        7
//   Disable request
//     0b0 ==> ERQ bit is not affected.
//     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

#define  DMA_DCR3_DMOD_MASK          0x400u
#define  DMA_DCR3_DMOD_SHIFT         8
#define  DMA_DCR3_DMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_DMOD_SHIFT))&DMA_DCR3_DMOD_MASK)
//   Destination address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR3_SMOD_MASK          0x4000u
#define  DMA_DCR3_SMOD_SHIFT         12
#define  DMA_DCR3_SMOD(x)            (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_SMOD_SHIFT))&DMA_DCR3_SMOD_MASK)
//   Source address modulo
//     0b0000 ==> Buffer disabled
//     0b0001 ==> Circular buffer size is 16 bytes
//     0b0010 ==> Circular buffer size is 32 bytes
//     0b0011 ==> Circular buffer size is 64 bytes
//     0b0100 ==> Circular buffer size is 128 bytes
//     0b0101 ==> Circular buffer size is 256 bytes
//     0b0110 ==> Circular buffer size is 512 bytes
//     0b0111 ==> Circular buffer size is 1 KB
//     0b1000 ==> Circular buffer size is 2 KB
//     0b1001 ==> Circular buffer size is 4 KB
//     0b1010 ==> Circular buffer size is 8 KB
//     0b1011 ==> Circular buffer size is 16 KB
//     0b1100 ==> Circular buffer size is 32 KB
//     0b1101 ==> Circular buffer size is 64 KB
//     0b1110 ==> Circular buffer size is 128 KB
//     0b1111 ==> Circular buffer size is 256 KB

#define  DMA_DCR3_START_MASK         0x10000u
#define  DMA_DCR3_START_SHIFT        16
//   Start transfer
//     0b0 ==> DMA inactive
//     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

#define  DMA_DCR3_DSIZE_MASK         0x40000u
#define  DMA_DCR3_DSIZE_SHIFT        17
#define  DMA_DCR3_DSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_DSIZE_SHIFT))&DMA_DCR3_DSIZE_MASK)
//   Destination size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR3_DINC_MASK          0x80000u
#define  DMA_DCR3_DINC_SHIFT         19
//   Destination increment
//     0b0 ==> No change to the DAR after a successful transfer.
//     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

#define  DMA_DCR3_SSIZE_MASK         0x200000u
#define  DMA_DCR3_SSIZE_SHIFT        20
#define  DMA_DCR3_SSIZE(x)           (((uint32_t)(((uint32_t)(x))<<DMA_DCR3_SSIZE_SHIFT))&DMA_DCR3_SSIZE_MASK)
//   Source size
//     0b00 ==> Longword
//     0b01 ==> Byte
//     0b10 ==> Word
//     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)

#define  DMA_DCR3_SINC_MASK          0x400000u
#define  DMA_DCR3_SINC_SHIFT         22
//   Source increment
//     0b0 ==> No change to SAR after a successful transfer.
//     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

#define  DMA_DCR3_AA_MASK            0x10000000u
#define  DMA_DCR3_AA_SHIFT           28
//   Auto-align
//     0b0 ==> Auto-align disabled
//     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

#define  DMA_DCR3_CS_MASK            0x20000000u
#define  DMA_DCR3_CS_SHIFT           29
//   Cycle steal
//     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
//     0b1 ==> Forces a single read/write transfer per request.

#define  DMA_DCR3_ERQ_MASK           0x40000000u
#define  DMA_DCR3_ERQ_SHIFT          30
//   Enable peripheral request
//     0b0 ==> Peripheral request is ignored.
//     0b1 ==> Enables peripheral request to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

#define  DMA_DCR3_EINT_MASK          0x80000000u
#define  DMA_DCR3_EINT_SHIFT         31
//   Enable interrupt on completion of transfer
//     0b0 ==> No interrupt is generated.
//     0b1 ==> Interrupt signal is enabled.

#define  DMAMUX0_CHCFG0_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG0_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG0_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG0_SOURCE_SHIFT))&DMAMUX0_CHCFG0_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG0_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG0_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG0_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG0_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG1_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG1_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG1_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG1_SOURCE_SHIFT))&DMAMUX0_CHCFG1_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG1_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG1_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG1_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG1_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG2_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG2_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG2_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG2_SOURCE_SHIFT))&DMAMUX0_CHCFG2_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG2_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG2_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG2_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG2_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG3_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG3_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG3_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG3_SOURCE_SHIFT))&DMAMUX0_CHCFG3_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG3_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG3_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG3_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG3_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG4_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG4_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG4_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG4_SOURCE_SHIFT))&DMAMUX0_CHCFG4_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG4_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG4_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG4_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG4_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG5_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG5_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG5_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG5_SOURCE_SHIFT))&DMAMUX0_CHCFG5_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG5_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG5_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG5_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG5_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG6_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG6_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG6_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG6_SOURCE_SHIFT))&DMAMUX0_CHCFG6_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG6_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG6_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG6_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG6_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG7_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG7_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG7_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG7_SOURCE_SHIFT))&DMAMUX0_CHCFG7_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG7_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG7_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG7_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG7_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG8_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG8_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG8_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG8_SOURCE_SHIFT))&DMAMUX0_CHCFG8_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG8_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG8_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG8_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG8_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG9_SOURCE_MASK  0x6u
#define  DMAMUX0_CHCFG9_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG9_SOURCE(x)    (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG9_SOURCE_SHIFT))&DMAMUX0_CHCFG9_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG9_TRIG_MASK    0x40u
#define  DMAMUX0_CHCFG9_TRIG_SHIFT   6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG9_ENBL_MASK    0x80u
#define  DMAMUX0_CHCFG9_ENBL_SHIFT   7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG10_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG10_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG10_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG10_SOURCE_SHIFT))&DMAMUX0_CHCFG10_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG10_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG10_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG10_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG10_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG11_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG11_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG11_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG11_SOURCE_SHIFT))&DMAMUX0_CHCFG11_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG11_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG11_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG11_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG11_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG12_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG12_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG12_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG12_SOURCE_SHIFT))&DMAMUX0_CHCFG12_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG12_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG12_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG12_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG12_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG13_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG13_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG13_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG13_SOURCE_SHIFT))&DMAMUX0_CHCFG13_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG13_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG13_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG13_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG13_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG14_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG14_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG14_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG14_SOURCE_SHIFT))&DMAMUX0_CHCFG14_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG14_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG14_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG14_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG14_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  DMAMUX0_CHCFG15_SOURCE_MASK 0x6u
#define  DMAMUX0_CHCFG15_SOURCE_SHIFT 0
#define  DMAMUX0_CHCFG15_SOURCE(x)   (((uint8_t)(((uint8_t)(x))<<DMAMUX0_CHCFG15_SOURCE_SHIFT))&DMAMUX0_CHCFG15_SOURCE_MASK)
//   DMA Channel Source (Slot)

#define  DMAMUX0_CHCFG15_TRIG_MASK   0x40u
#define  DMAMUX0_CHCFG15_TRIG_SHIFT  6
//   DMA Channel Trigger Enable
//     0b0 ==> Triggering is disabled. If triggering is disabled, and the ENBL bit is set, the DMA Channel will simply route the specified source to the DMA channel. (Normal mode)
//     0b1 ==> Triggering is enabled. If triggering is enabled, and the ENBL bit is set, the DMAMUX is in Periodic Trigger mode.

#define  DMAMUX0_CHCFG15_ENBL_MASK   0x80u
#define  DMAMUX0_CHCFG15_ENBL_SHIFT  7
//   DMA Channel Enable
//     0b0 ==> DMA channel is disabled. This mode is primarily used during configuration of the DMA Mux. The DMA has separate channel enables/disables, which should be used to disable or re-configure a DMA channel.
//     0b1 ==> DMA channel is enabled

#define  FTFA_FSTAT_MGSTAT0_MASK     0x1u
#define  FTFA_FSTAT_MGSTAT0_SHIFT    0
//   Memory Controller Command Completion Status Flag

#define  FTFA_FSTAT_FPVIOL_MASK      0x10u
#define  FTFA_FSTAT_FPVIOL_SHIFT     4
//   Flash Protection Violation Flag
//     0b0 ==> No protection violation detected
//     0b1 ==> Protection violation detected

#define  FTFA_FSTAT_ACCERR_MASK      0x20u
#define  FTFA_FSTAT_ACCERR_SHIFT     5
//   Flash Access Error Flag
//     0b0 ==> No access error detected
//     0b1 ==> Access error detected

#define  FTFA_FSTAT_RDCOLERR_MASK    0x40u
#define  FTFA_FSTAT_RDCOLERR_SHIFT   6
//   Flash Read Collision Error Flag
//     0b0 ==> No collision error detected
//     0b1 ==> Collision error detected

#define  FTFA_FSTAT_CCIF_MASK        0x80u
#define  FTFA_FSTAT_CCIF_SHIFT       7
//   Command Complete Interrupt Flag
//     0b0 ==> Flash command in progress
//     0b1 ==> Flash command has completed

#define  FTFA_FCNFG_ERSSUSP_MASK     0x10u
#define  FTFA_FCNFG_ERSSUSP_SHIFT    4
//   Erase Suspend
//     0b0 ==> No suspend requested
//     0b1 ==> Suspend the current Erase Flash Sector command execution.

#define  FTFA_FCNFG_ERSAREQ_MASK     0x20u
#define  FTFA_FCNFG_ERSAREQ_SHIFT    5
//   Erase All Request
//     0b0 ==> No request or request complete
//     0b1 ==> Request to: run the Erase All Blocks command, verify the erased state, program the security byte in the Flash Configuration Field to the unsecure state, and release MCU security by setting the FSEC[SEC] field to the unsecure state.

#define  FTFA_FCNFG_RDCOLLIE_MASK    0x40u
#define  FTFA_FCNFG_RDCOLLIE_SHIFT   6
//   Read Collision Error Interrupt Enable
//     0b0 ==> Read collision error interrupt disabled
//     0b1 ==> Read collision error interrupt enabled. An interrupt request is generated whenever a flash memory read collision error is detected (see the description of FSTAT[RDCOLERR]).

#define  FTFA_FCNFG_CCIE_MASK        0x80u
#define  FTFA_FCNFG_CCIE_SHIFT       7
//   Command Complete Interrupt Enable
//     0b0 ==> Command complete interrupt disabled
//     0b1 ==> Command complete interrupt enabled. An interrupt request is generated whenever the FSTAT[CCIF] flag is set.

#define  FTFA_FSEC_SEC_MASK          0x2u
#define  FTFA_FSEC_SEC_SHIFT         0
#define  FTFA_FSEC_SEC(x)            (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK)
//   Flash Security
//     0b00 ==> MCU security status is secure
//     0b01 ==> MCU security status is secure
//     0b10 ==> MCU security status is unsecure (The standard shipping condition of the flash memory module is unsecure.)
//     0b11 ==> MCU security status is secure

#define  FTFA_FSEC_FSLACC_MASK       0x8u
#define  FTFA_FSEC_FSLACC_SHIFT      2
#define  FTFA_FSEC_FSLACC(x)         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK)
//   Freescale Failure Analysis Access Code
//     0b00 ==> Freescale factory access granted
//     0b01 ==> Freescale factory access denied
//     0b10 ==> Freescale factory access denied
//     0b11 ==> Freescale factory access granted

#define  FTFA_FSEC_MEEN_MASK         0x20u
#define  FTFA_FSEC_MEEN_SHIFT        4
#define  FTFA_FSEC_MEEN(x)           (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK)
//   Mass Erase Enable Bits
//     0b00 ==> Mass erase is enabled
//     0b01 ==> Mass erase is enabled
//     0b10 ==> Mass erase is disabled
//     0b11 ==> Mass erase is enabled

#define  FTFA_FSEC_KEYEN_MASK        0x80u
#define  FTFA_FSEC_KEYEN_SHIFT       6
#define  FTFA_FSEC_KEYEN(x)          (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK)
//   Backdoor Key Security Enable
//     0b00 ==> Backdoor key access disabled
//     0b01 ==> Backdoor key access disabled (preferred KEYEN state to disable backdoor key access)
//     0b10 ==> Backdoor key access enabled
//     0b11 ==> Backdoor key access disabled

#define  FTFA_FOPT_OPT_MASK          0x8u
#define  FTFA_FOPT_OPT_SHIFT         0
#define  FTFA_FOPT_OPT(x)            (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK)
//   Nonvolatile Option

#define  FTFA_FCCOB3_CCOBn_MASK      0x8u
#define  FTFA_FCCOB3_CCOBn_SHIFT     0
#define  FTFA_FCCOB3_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB3_CCOBn_SHIFT))&FTFA_FCCOB3_CCOBn_MASK)

#define  FTFA_FCCOB2_CCOBn_MASK      0x8u
#define  FTFA_FCCOB2_CCOBn_SHIFT     0
#define  FTFA_FCCOB2_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB2_CCOBn_SHIFT))&FTFA_FCCOB2_CCOBn_MASK)

#define  FTFA_FCCOB1_CCOBn_MASK      0x8u
#define  FTFA_FCCOB1_CCOBn_SHIFT     0
#define  FTFA_FCCOB1_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB1_CCOBn_SHIFT))&FTFA_FCCOB1_CCOBn_MASK)

#define  FTFA_FCCOB0_CCOBn_MASK      0x8u
#define  FTFA_FCCOB0_CCOBn_SHIFT     0
#define  FTFA_FCCOB0_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB0_CCOBn_SHIFT))&FTFA_FCCOB0_CCOBn_MASK)

#define  FTFA_FCCOB7_CCOBn_MASK      0x8u
#define  FTFA_FCCOB7_CCOBn_SHIFT     0
#define  FTFA_FCCOB7_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB7_CCOBn_SHIFT))&FTFA_FCCOB7_CCOBn_MASK)

#define  FTFA_FCCOB6_CCOBn_MASK      0x8u
#define  FTFA_FCCOB6_CCOBn_SHIFT     0
#define  FTFA_FCCOB6_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB6_CCOBn_SHIFT))&FTFA_FCCOB6_CCOBn_MASK)

#define  FTFA_FCCOB5_CCOBn_MASK      0x8u
#define  FTFA_FCCOB5_CCOBn_SHIFT     0
#define  FTFA_FCCOB5_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB5_CCOBn_SHIFT))&FTFA_FCCOB5_CCOBn_MASK)

#define  FTFA_FCCOB4_CCOBn_MASK      0x8u
#define  FTFA_FCCOB4_CCOBn_SHIFT     0
#define  FTFA_FCCOB4_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB4_CCOBn_SHIFT))&FTFA_FCCOB4_CCOBn_MASK)

#define  FTFA_FCCOBB_CCOBn_MASK      0x8u
#define  FTFA_FCCOBB_CCOBn_SHIFT     0
#define  FTFA_FCCOBB_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBB_CCOBn_SHIFT))&FTFA_FCCOBB_CCOBn_MASK)

#define  FTFA_FCCOBA_CCOBn_MASK      0x8u
#define  FTFA_FCCOBA_CCOBn_SHIFT     0
#define  FTFA_FCCOBA_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBA_CCOBn_SHIFT))&FTFA_FCCOBA_CCOBn_MASK)

#define  FTFA_FCCOB9_CCOBn_MASK      0x8u
#define  FTFA_FCCOB9_CCOBn_SHIFT     0
#define  FTFA_FCCOB9_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB9_CCOBn_SHIFT))&FTFA_FCCOB9_CCOBn_MASK)

#define  FTFA_FCCOB8_CCOBn_MASK      0x8u
#define  FTFA_FCCOB8_CCOBn_SHIFT     0
#define  FTFA_FCCOB8_CCOBn(x)        (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB8_CCOBn_SHIFT))&FTFA_FCCOB8_CCOBn_MASK)

#define  FTFA_FPROT3_PROT_MASK       0x8u
#define  FTFA_FPROT3_PROT_SHIFT      0
#define  FTFA_FPROT3_PROT(x)         (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT3_PROT_SHIFT))&FTFA_FPROT3_PROT_MASK)
//   Program Flash Region Protect
//     0b0 ==> Program flash region is protected.
//     0b1 ==> Program flash region is not protected

#define  FTFA_FPROT2_PROT_MASK       0x8u
#define  FTFA_FPROT2_PROT_SHIFT      0
#define  FTFA_FPROT2_PROT(x)         (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT2_PROT_SHIFT))&FTFA_FPROT2_PROT_MASK)
//   Program Flash Region Protect
//     0b0 ==> Program flash region is protected.
//     0b1 ==> Program flash region is not protected

#define  FTFA_FPROT1_PROT_MASK       0x8u
#define  FTFA_FPROT1_PROT_SHIFT      0
#define  FTFA_FPROT1_PROT(x)         (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT1_PROT_SHIFT))&FTFA_FPROT1_PROT_MASK)
//   Program Flash Region Protect
//     0b0 ==> Program flash region is protected.
//     0b1 ==> Program flash region is not protected

#define  FTFA_FPROT0_PROT_MASK       0x8u
#define  FTFA_FPROT0_PROT_SHIFT      0
#define  FTFA_FPROT0_PROT(x)         (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT0_PROT_SHIFT))&FTFA_FPROT0_PROT_MASK)
//   Program Flash Region Protect
//     0b0 ==> Program flash region is protected.
//     0b1 ==> Program flash region is not protected

#define  GPIOA_PDOR_PDO_MASK         0x20u
#define  GPIOA_PDOR_PDO_SHIFT        0
#define  GPIOA_PDOR_PDO(x)           (((uint32_t)(((uint32_t)(x))<<GPIOA_PDOR_PDO_SHIFT))&GPIOA_PDOR_PDO_MASK)
//   Port Data Output
//     0b0 ==> Logic level 0 is driven on pin, provided pin is configured for general-purpose output.
//     0b1 ==> Logic level 1 is driven on pin, provided pin is configured for general-purpose output.

#define  GPIOA_PSOR_PTSO_MASK        0x20u
#define  GPIOA_PSOR_PTSO_SHIFT       0
#define  GPIOA_PSOR_PTSO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOA_PSOR_PTSO_SHIFT))&GPIOA_PSOR_PTSO_MASK)
//   Port Set Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is set to logic 1.

#define  GPIOA_PCOR_PTCO_MASK        0x20u
#define  GPIOA_PCOR_PTCO_SHIFT       0
#define  GPIOA_PCOR_PTCO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOA_PCOR_PTCO_SHIFT))&GPIOA_PCOR_PTCO_MASK)
//   Port Clear Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is cleared to logic 0.

#define  GPIOA_PTOR_PTTO_MASK        0x20u
#define  GPIOA_PTOR_PTTO_SHIFT       0
#define  GPIOA_PTOR_PTTO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOA_PTOR_PTTO_SHIFT))&GPIOA_PTOR_PTTO_MASK)
//   Port Toggle Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is set to the inverse of its existing logic state.

#define  GPIOA_PDIR_PDI_MASK         0x20u
#define  GPIOA_PDIR_PDI_SHIFT        0
#define  GPIOA_PDIR_PDI(x)           (((uint32_t)(((uint32_t)(x))<<GPIOA_PDIR_PDI_SHIFT))&GPIOA_PDIR_PDI_MASK)
//   Port Data Input
//     0b0 ==> Pin logic level is logic 0, or is not configured for use by digital function.
//     0b1 ==> Pin logic level is logic 1.

#define  GPIOA_PDDR_PDD_MASK         0x20u
#define  GPIOA_PDDR_PDD_SHIFT        0
#define  GPIOA_PDDR_PDD(x)           (((uint32_t)(((uint32_t)(x))<<GPIOA_PDDR_PDD_SHIFT))&GPIOA_PDDR_PDD_MASK)
//   Port Data Direction
//     0b0 ==> Pin is configured as general-purpose input, for the GPIO function.
//     0b1 ==> Pin is configured as general-purpose output, for the GPIO function.

#define  GPIOB_PDOR_PDO_MASK         0x20u
#define  GPIOB_PDOR_PDO_SHIFT        0
#define  GPIOB_PDOR_PDO(x)           (((uint32_t)(((uint32_t)(x))<<GPIOB_PDOR_PDO_SHIFT))&GPIOB_PDOR_PDO_MASK)
//   Port Data Output
//     0b0 ==> Logic level 0 is driven on pin, provided pin is configured for general-purpose output.
//     0b1 ==> Logic level 1 is driven on pin, provided pin is configured for general-purpose output.

#define  GPIOB_PSOR_PTSO_MASK        0x20u
#define  GPIOB_PSOR_PTSO_SHIFT       0
#define  GPIOB_PSOR_PTSO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOB_PSOR_PTSO_SHIFT))&GPIOB_PSOR_PTSO_MASK)
//   Port Set Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is set to logic 1.

#define  GPIOB_PCOR_PTCO_MASK        0x20u
#define  GPIOB_PCOR_PTCO_SHIFT       0
#define  GPIOB_PCOR_PTCO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOB_PCOR_PTCO_SHIFT))&GPIOB_PCOR_PTCO_MASK)
//   Port Clear Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is cleared to logic 0.

#define  GPIOB_PTOR_PTTO_MASK        0x20u
#define  GPIOB_PTOR_PTTO_SHIFT       0
#define  GPIOB_PTOR_PTTO(x)          (((uint32_t)(((uint32_t)(x))<<GPIOB_PTOR_PTTO_SHIFT))&GPIOB_PTOR_PTTO_MASK)
//   Port Toggle Output
//     0b0 ==> Corresponding bit in PDORn does not change.
//     0b1 ==> Corresponding bit in PDORn is set to the inverse of its existing logic state.

#define  GPIOB_PDIR_PDI_MASK         0x20u
#define  GPIOB_PDIR_PDI_SHIFT        0
#define  GPIOB_PDIR_PDI(x)           (((uint32_t)(((uint32_t)(x))<<GPIOB_PDIR_PDI_SHIFT))&GPIOB_PDIR_PDI_MASK)
//   Port Data Input
//     0b0 ==> Pin logic level is logic 0, or is not configured for use by digital function.
//     0b1 ==> Pin logic level is logic 1.

#define  GPIOB_PDDR_PDD_MASK         0x20u
#define  GPIOB_PDDR_PDD_SHIFT        0
#define  GPIOB_PDDR_PDD(x)           (((uint32_t)(((uint32_t)(x))<<GPIOB_PDDR_PDD_SHIFT))&GPIOB_PDDR_PDD_MASK)
//   Port Data Direction
//     0b0 ==> Pin is configured as general-purpose input, for the GPIO function.
//     0b1 ==> Pin is configured as general-purpose output, for the GPIO function.

#define  I2C0_A1_AD_MASK             0xEu
#define  I2C0_A1_AD_SHIFT            1
#define  I2C0_A1_AD(x)               (((uint8_t)(((uint8_t)(x))<<I2C0_A1_AD_SHIFT))&I2C0_A1_AD_MASK)
//   Address

#define  I2C0_F_ICR_MASK             0x6u
#define  I2C0_F_ICR_SHIFT            0
#define  I2C0_F_ICR(x)               (((uint8_t)(((uint8_t)(x))<<I2C0_F_ICR_SHIFT))&I2C0_F_ICR_MASK)
//   ClockRate

#define  I2C0_F_MULT_MASK            0x80u
#define  I2C0_F_MULT_SHIFT           6
#define  I2C0_F_MULT(x)              (((uint8_t)(((uint8_t)(x))<<I2C0_F_MULT_SHIFT))&I2C0_F_MULT_MASK)
//     0b00 ==> mul = 1
//     0b01 ==> mul = 2
//     0b10 ==> mul = 4
//     0b11 ==> Reserved

#define  I2C0_C1_DMAEN_MASK          0x1u
#define  I2C0_C1_DMAEN_SHIFT         0
//   DMA Enable
//     0b0 ==> All DMA signalling disabled.
//     0b1 ==> DMA transfer is enabled and the following conditions trigger the DMA request: While FACK = 0, a data byte is received, either address or data is transmitted. (ACK/NACK automatic) While FACK = 0, the first byte received matches the A1 register or is general call address. If any address matching occurs, IAAS and TCF are set. If the direction of transfer is known from master to slave, then it is not required to check the SRW. With this assumption, DMA can also be used in this
//             case. In other cases, if the master reads data from the slave, then it is required to rewrite the C1 register operation. With this assumption, DMA cannot be used. When FACK = 1, an address or a data byte is transmitted.

#define  I2C0_C1_WUEN_MASK           0x2u
#define  I2C0_C1_WUEN_SHIFT          1
//   Wakeup Enable
//     0b0 ==> Normal operation. No interrupt generated when address matching in low power mode.
//     0b1 ==> Enables the wakeup function in low power mode.

#define  I2C0_C1_RSTA_MASK           0x4u
#define  I2C0_C1_RSTA_SHIFT          2
//   Repeat START

#define  I2C0_C1_TXAK_MASK           0x8u
#define  I2C0_C1_TXAK_SHIFT          3
//   Transmit Acknowledge Enable
//     0b0 ==> An acknowledge signal is sent to the bus on the following receiving byte (if FACK is cleared) or the current receiving byte (if FACK is set).
//     0b1 ==> No acknowledge signal is sent to the bus on the following receiving data byte (if FACK is cleared) or the current receiving data byte (if FACK is set).

#define  I2C0_C1_TX_MASK             0x10u
#define  I2C0_C1_TX_SHIFT            4
//   Transmit Mode Select
//     0b0 ==> Receive
//     0b1 ==> Transmit

#define  I2C0_C1_MST_MASK            0x20u
#define  I2C0_C1_MST_SHIFT           5
//   Master Mode Select
//     0b0 ==> Slave mode
//     0b1 ==> Master mode

#define  I2C0_C1_IICIE_MASK          0x40u
#define  I2C0_C1_IICIE_SHIFT         6
//   I2C Interrupt Enable
//     0b0 ==> Disabled
//     0b1 ==> Enabled

#define  I2C0_C1_IICEN_MASK          0x80u
#define  I2C0_C1_IICEN_SHIFT         7
//   I2C Enable
//     0b0 ==> Disabled
//     0b1 ==> Enabled

#define  I2C0_S_RXAK_MASK            0x1u
#define  I2C0_S_RXAK_SHIFT           0
//   Receive Acknowledge
//     0b0 ==> Acknowledge signal was received after the completion of one byte of data transmission on the bus
//     0b1 ==> No acknowledge signal detected

#define  I2C0_S_IICIF_MASK           0x2u
#define  I2C0_S_IICIF_SHIFT          1
//   Interrupt Flag
//     0b0 ==> No interrupt pending
//     0b1 ==> Interrupt pending

#define  I2C0_S_SRW_MASK             0x4u
#define  I2C0_S_SRW_SHIFT            2
//   Slave Read/Write
//     0b0 ==> Slave receive, master writing to slave
//     0b1 ==> Slave transmit, master reading from slave

#define  I2C0_S_RAM_MASK             0x8u
#define  I2C0_S_RAM_SHIFT            3
//   Range Address Match
//     0b0 ==> Not addressed
//     0b1 ==> Addressed as a slave

#define  I2C0_S_ARBL_MASK            0x10u
#define  I2C0_S_ARBL_SHIFT           4
//   Arbitration Lost
//     0b0 ==> Standard bus operation.
//     0b1 ==> Loss of arbitration.

#define  I2C0_S_BUSY_MASK            0x20u
#define  I2C0_S_BUSY_SHIFT           5
//   Bus Busy
//     0b0 ==> Bus is idle
//     0b1 ==> Bus is busy

#define  I2C0_S_IAAS_MASK            0x40u
#define  I2C0_S_IAAS_SHIFT           6
//   Addressed As A Slave
//     0b0 ==> Not addressed
//     0b1 ==> Addressed as a slave

#define  I2C0_S_TCF_MASK             0x80u
#define  I2C0_S_TCF_SHIFT            7
//   Transfer Complete Flag
//     0b0 ==> Transfer in progress
//     0b1 ==> Transfer complete

#define  I2C0_D_DATA_MASK            0x8u
#define  I2C0_D_DATA_SHIFT           0
#define  I2C0_D_DATA(x)              (((uint8_t)(((uint8_t)(x))<<I2C0_D_DATA_SHIFT))&I2C0_D_DATA_MASK)
//   Data

#define  I2C0_C2_AD_MASK             0x3u
#define  I2C0_C2_AD_SHIFT            0
#define  I2C0_C2_AD(x)               (((uint8_t)(((uint8_t)(x))<<I2C0_C2_AD_SHIFT))&I2C0_C2_AD_MASK)
//   Slave Address

#define  I2C0_C2_RMEN_MASK           0x8u
#define  I2C0_C2_RMEN_SHIFT          3
//   Range Address Matching Enable
//     0b0 ==> Range mode disabled. No address match occurs for an address within the range of values of the A1 and RA registers.
//     0b1 ==> Range mode enabled. Address matching occurs when a slave receives an address within the range of values of the A1 and RA registers.

#define  I2C0_C2_SBRC_MASK           0x10u
#define  I2C0_C2_SBRC_SHIFT          4
//   Slave Baud Rate Control
//     0b0 ==> The slave baud rate follows the master baud rate and clock stretching may occur
//     0b1 ==> Slave baud rate is independent of the master baud rate

#define  I2C0_C2_HDRS_MASK           0x20u
#define  I2C0_C2_HDRS_SHIFT          5
//   High Drive Select
//     0b0 ==> Normal drive mode
//     0b1 ==> High drive mode

#define  I2C0_C2_ADEXT_MASK          0x40u
#define  I2C0_C2_ADEXT_SHIFT         6
//   Address Extension
//     0b0 ==> 7-bit address scheme
//     0b1 ==> 10-bit address scheme

#define  I2C0_C2_GCAEN_MASK          0x80u
#define  I2C0_C2_GCAEN_SHIFT         7
//   General Call Address Enable
//     0b0 ==> Disabled
//     0b1 ==> Enabled

#define  I2C0_FLT_FLT_MASK           0x5u
#define  I2C0_FLT_FLT_SHIFT          0
#define  I2C0_FLT_FLT(x)             (((uint8_t)(((uint8_t)(x))<<I2C0_FLT_FLT_SHIFT))&I2C0_FLT_FLT_MASK)
//   I2C Programmable Filter Factor
//     0b0 ==> No filter/bypass

#define  I2C0_FLT_STOPIE_MASK        0x20u
#define  I2C0_FLT_STOPIE_SHIFT       5
//   I2C Bus Stop Interrupt Enable
//     0b0 ==> Stop detection interrupt is disabled
//     0b1 ==> Stop detection interrupt is enabled

#define  I2C0_FLT_STOPF_MASK         0x40u
#define  I2C0_FLT_STOPF_SHIFT        6
//   I2C Bus Stop Detect Flag
//     0b0 ==> No stop happens on I2C bus
//     0b1 ==> Stop detected on I2C bus

#define  I2C0_FLT_SHEN_MASK          0x80u
#define  I2C0_FLT_SHEN_SHIFT         7
//   Stop Hold Enable
//     0b0 ==> Stop holdoff is disabled. The MCU's entry to stop mode is not gated.
//     0b1 ==> Stop holdoff is enabled.

#define  I2C0_RA_RAD_MASK            0xEu
#define  I2C0_RA_RAD_SHIFT           1
#define  I2C0_RA_RAD(x)              (((uint8_t)(((uint8_t)(x))<<I2C0_RA_RAD_SHIFT))&I2C0_RA_RAD_MASK)
//   Range Slave Address

#define  I2C0_SMB_SHTF2IE_MASK       0x1u
#define  I2C0_SMB_SHTF2IE_SHIFT      0
//   SHTF2 Interrupt Enable
//     0b0 ==> SHTF2 interrupt is disabled
//     0b1 ==> SHTF2 interrupt is enabled

#define  I2C0_SMB_SHTF2_MASK         0x2u
#define  I2C0_SMB_SHTF2_SHIFT        1
//   SCL High Timeout Flag 2
//     0b0 ==> No SCL high and SDA low timeout occurs
//     0b1 ==> SCL high and SDA low timeout occurs

#define  I2C0_SMB_SHTF1_MASK         0x4u
#define  I2C0_SMB_SHTF1_SHIFT        2
//   SCL High Timeout Flag 1
//     0b0 ==> No SCL high and SDA high timeout occurs
//     0b1 ==> SCL high and SDA high timeout occurs

#define  I2C0_SMB_SLTF_MASK          0x8u
#define  I2C0_SMB_SLTF_SHIFT         3
//   SCL Low Timeout Flag
//     0b0 ==> No low timeout occurs
//     0b1 ==> Low timeout occurs

#define  I2C0_SMB_TCKSEL_MASK        0x10u
#define  I2C0_SMB_TCKSEL_SHIFT       4
//   Timeout Counter Clock Select
//     0b0 ==> Timeout counter counts at the frequency of the bus clock / 64
//     0b1 ==> Timeout counter counts at the frequency of the bus clock

#define  I2C0_SMB_SIICAEN_MASK       0x20u
#define  I2C0_SMB_SIICAEN_SHIFT      5
//   Second I2C Address Enable
//     0b0 ==> I2C address register 2 matching is disabled
//     0b1 ==> I2C address register 2 matching is enabled

#define  I2C0_SMB_ALERTEN_MASK       0x40u
#define  I2C0_SMB_ALERTEN_SHIFT      6
//   SMBus Alert Response Address Enable
//     0b0 ==> SMBus alert response address matching is disabled
//     0b1 ==> SMBus alert response address matching is enabled

#define  I2C0_SMB_FACK_MASK          0x80u
#define  I2C0_SMB_FACK_SHIFT         7
//   Fast NACK/ACK Enable
//     0b0 ==> An ACK or NACK is sent on the following receiving data byte
//     0b1 ==> Writing 0 to TXAK after receiving a data byte generates an ACK. Writing 1 to TXAK after receiving a data byte generates a NACK.

#define  I2C0_A2_SAD_MASK            0xEu
#define  I2C0_A2_SAD_SHIFT           1
#define  I2C0_A2_SAD(x)              (((uint8_t)(((uint8_t)(x))<<I2C0_A2_SAD_SHIFT))&I2C0_A2_SAD_MASK)
//   SMBus Address

#define  I2C0_SLTH_SSLT_MASK         0x8u
#define  I2C0_SLTH_SSLT_SHIFT        0
#define  I2C0_SLTH_SSLT(x)           (((uint8_t)(((uint8_t)(x))<<I2C0_SLTH_SSLT_SHIFT))&I2C0_SLTH_SSLT_MASK)

#define  I2C0_SLTL_SSLT_MASK         0x8u
#define  I2C0_SLTL_SSLT_SHIFT        0
#define  I2C0_SLTL_SSLT(x)           (((uint8_t)(((uint8_t)(x))<<I2C0_SLTL_SSLT_SHIFT))&I2C0_SLTL_SSLT_MASK)

#define  LLWU_PE1_WUPE0_MASK         0x2u
#define  LLWU_PE1_WUPE0_SHIFT        0
#define  LLWU_PE1_WUPE0(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
//   Wakeup Pin Enable For LLWU_P0
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE1_WUPE1_MASK         0x8u
#define  LLWU_PE1_WUPE1_SHIFT        2
#define  LLWU_PE1_WUPE1(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
//   Wakeup Pin Enable For LLWU_P1
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE1_WUPE2_MASK         0x20u
#define  LLWU_PE1_WUPE2_SHIFT        4
#define  LLWU_PE1_WUPE2(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
//   Wakeup Pin Enable For LLWU_P2
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE1_WUPE3_MASK         0x80u
#define  LLWU_PE1_WUPE3_SHIFT        6
#define  LLWU_PE1_WUPE3(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
//   Wakeup Pin Enable For LLWU_P3
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE2_WUPE4_MASK         0x2u
#define  LLWU_PE2_WUPE4_SHIFT        0
#define  LLWU_PE2_WUPE4(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK)
//   Wakeup Pin Enable For LLWU_P4
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE2_WUPE5_MASK         0x8u
#define  LLWU_PE2_WUPE5_SHIFT        2
#define  LLWU_PE2_WUPE5(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK)
//   Wakeup Pin Enable For LLWU_P5
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE2_WUPE6_MASK         0x20u
#define  LLWU_PE2_WUPE6_SHIFT        4
#define  LLWU_PE2_WUPE6(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK)
//   Wakeup Pin Enable For LLWU_P6
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE2_WUPE7_MASK         0x80u
#define  LLWU_PE2_WUPE7_SHIFT        6
#define  LLWU_PE2_WUPE7(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK)
//   Wakeup Pin Enable For LLWU_P7
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE3_WUPE8_MASK         0x2u
#define  LLWU_PE3_WUPE8_SHIFT        0
#define  LLWU_PE3_WUPE8(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK)
//   Wakeup Pin Enable For LLWU_P8
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE3_WUPE9_MASK         0x8u
#define  LLWU_PE3_WUPE9_SHIFT        2
#define  LLWU_PE3_WUPE9(x)           (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK)
//   Wakeup Pin Enable For LLWU_P9
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE3_WUPE10_MASK        0x20u
#define  LLWU_PE3_WUPE10_SHIFT       4
#define  LLWU_PE3_WUPE10(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK)
//   Wakeup Pin Enable For LLWU_P10
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE3_WUPE11_MASK        0x80u
#define  LLWU_PE3_WUPE11_SHIFT       6
#define  LLWU_PE3_WUPE11(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK)
//   Wakeup Pin Enable For LLWU_P11
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE4_WUPE12_MASK        0x2u
#define  LLWU_PE4_WUPE12_SHIFT       0
#define  LLWU_PE4_WUPE12(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK)
//   Wakeup Pin Enable For LLWU_P12
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE4_WUPE13_MASK        0x8u
#define  LLWU_PE4_WUPE13_SHIFT       2
#define  LLWU_PE4_WUPE13(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK)
//   Wakeup Pin Enable For LLWU_P13
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE4_WUPE14_MASK        0x20u
#define  LLWU_PE4_WUPE14_SHIFT       4
#define  LLWU_PE4_WUPE14(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK)
//   Wakeup Pin Enable For LLWU_P14
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_PE4_WUPE15_MASK        0x80u
#define  LLWU_PE4_WUPE15_SHIFT       6
#define  LLWU_PE4_WUPE15(x)          (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK)
//   Wakeup Pin Enable For LLWU_P15
//     0b00 ==> External input pin disabled as wakeup input
//     0b01 ==> External input pin enabled with rising edge detection
//     0b10 ==> External input pin enabled with falling edge detection
//     0b11 ==> External input pin enabled with any change detection

#define  LLWU_ME_WUME0_MASK          0x1u
#define  LLWU_ME_WUME0_SHIFT         0
//   Wakeup Module Enable For Module 0
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME1_MASK          0x2u
#define  LLWU_ME_WUME1_SHIFT         1
//   Wakeup Module Enable for Module 1
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME2_MASK          0x4u
#define  LLWU_ME_WUME2_SHIFT         2
//   Wakeup Module Enable For Module 2
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME3_MASK          0x8u
#define  LLWU_ME_WUME3_SHIFT         3
//   Wakeup Module Enable For Module 3
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME4_MASK          0x10u
#define  LLWU_ME_WUME4_SHIFT         4
//   Wakeup Module Enable For Module 4
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME5_MASK          0x20u
#define  LLWU_ME_WUME5_SHIFT         5
//   Wakeup Module Enable For Module 5
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME6_MASK          0x40u
#define  LLWU_ME_WUME6_SHIFT         6
//   Wakeup Module Enable For Module 6
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_ME_WUME7_MASK          0x80u
#define  LLWU_ME_WUME7_SHIFT         7
//   Wakeup Module Enable For Module 7
//     0b0 ==> Internal module flag not used as wakeup source
//     0b1 ==> Internal module flag used as wakeup source

#define  LLWU_F1_WUF0_MASK           0x1u
#define  LLWU_F1_WUF0_SHIFT          0
//   Wakeup Flag For LLWU_P0
//     0b0 ==> LLWU_P0 input was not a wakeup source
//     0b1 ==> LLWU_P0 input was a wakeup source

#define  LLWU_F1_WUF1_MASK           0x2u
#define  LLWU_F1_WUF1_SHIFT          1
//   Wakeup Flag For LLWU_P1
//     0b0 ==> LLWU_P1 input was not a wakeup source
//     0b1 ==> LLWU_P1 input was a wakeup source

#define  LLWU_F1_WUF2_MASK           0x4u
#define  LLWU_F1_WUF2_SHIFT          2
//   Wakeup Flag For LLWU_P2
//     0b0 ==> LLWU_P2 input was not a wakeup source
//     0b1 ==> LLWU_P2 input was a wakeup source

#define  LLWU_F1_WUF3_MASK           0x8u
#define  LLWU_F1_WUF3_SHIFT          3
//   Wakeup Flag For LLWU_P3
//     0b0 ==> LLWU_P3 input was not a wakeup source
//     0b1 ==> LLWU_P3 input was a wakeup source

#define  LLWU_F1_WUF4_MASK           0x10u
#define  LLWU_F1_WUF4_SHIFT          4
//   Wakeup Flag For LLWU_P4
//     0b0 ==> LLWU_P4 input was not a wakeup source
//     0b1 ==> LLWU_P4 input was a wakeup source

#define  LLWU_F1_WUF5_MASK           0x20u
#define  LLWU_F1_WUF5_SHIFT          5
//   Wakeup Flag For LLWU_P5
//     0b0 ==> LLWU_P5 input was not a wakeup source
//     0b1 ==> LLWU_P5 input was a wakeup source

#define  LLWU_F1_WUF6_MASK           0x40u
#define  LLWU_F1_WUF6_SHIFT          6
//   Wakeup Flag For LLWU_P6
//     0b0 ==> LLWU_P6 input was not a wakeup source
//     0b1 ==> LLWU_P6 input was a wakeup source

#define  LLWU_F1_WUF7_MASK           0x80u
#define  LLWU_F1_WUF7_SHIFT          7
//   Wakeup Flag For LLWU_P7
//     0b0 ==> LLWU_P7 input was not a wakeup source
//     0b1 ==> LLWU_P7 input was a wakeup source

#define  LLWU_F2_WUF8_MASK           0x1u
#define  LLWU_F2_WUF8_SHIFT          0
//   Wakeup Flag For LLWU_P8
//     0b0 ==> LLWU_P8 input was not a wakeup source
//     0b1 ==> LLWU_P8 input was a wakeup source

#define  LLWU_F2_WUF9_MASK           0x2u
#define  LLWU_F2_WUF9_SHIFT          1
//   Wakeup Flag For LLWU_P9
//     0b0 ==> LLWU_P9 input was not a wakeup source
//     0b1 ==> LLWU_P9 input was a wakeup source

#define  LLWU_F2_WUF10_MASK          0x4u
#define  LLWU_F2_WUF10_SHIFT         2
//   Wakeup Flag For LLWU_P10
//     0b0 ==> LLWU_P10 input was not a wakeup source
//     0b1 ==> LLWU_P10 input was a wakeup source

#define  LLWU_F2_WUF11_MASK          0x8u
#define  LLWU_F2_WUF11_SHIFT         3
//   Wakeup Flag For LLWU_P11
//     0b0 ==> LLWU_P11 input was not a wakeup source
//     0b1 ==> LLWU_P11 input was a wakeup source

#define  LLWU_F2_WUF12_MASK          0x10u
#define  LLWU_F2_WUF12_SHIFT         4
//   Wakeup Flag For LLWU_P12
//     0b0 ==> LLWU_P12 input was not a wakeup source
//     0b1 ==> LLWU_P12 input was a wakeup source

#define  LLWU_F2_WUF13_MASK          0x20u
#define  LLWU_F2_WUF13_SHIFT         5
//   Wakeup Flag For LLWU_P13
//     0b0 ==> LLWU_P13 input was not a wakeup source
//     0b1 ==> LLWU_P13 input was a wakeup source

#define  LLWU_F2_WUF14_MASK          0x40u
#define  LLWU_F2_WUF14_SHIFT         6
//   Wakeup Flag For LLWU_P14
//     0b0 ==> LLWU_P14 input was not a wakeup source
//     0b1 ==> LLWU_P14 input was a wakeup source

#define  LLWU_F2_WUF15_MASK          0x80u
#define  LLWU_F2_WUF15_SHIFT         7
//   Wakeup Flag For LLWU_P15
//     0b0 ==> LLWU_P15 input was not a wakeup source
//     0b1 ==> LLWU_P15 input was a wakeup source

#define  LLWU_F3_MWUF0_MASK          0x1u
#define  LLWU_F3_MWUF0_SHIFT         0
//   Wakeup flag For module 0
//     0b0 ==> Module 0 input was not a wakeup source
//     0b1 ==> Module 0 input was a wakeup source

#define  LLWU_F3_MWUF1_MASK          0x2u
#define  LLWU_F3_MWUF1_SHIFT         1
//   Wakeup flag For module 1
//     0b0 ==> Module 1 input was not a wakeup source
//     0b1 ==> Module 1 input was a wakeup source

#define  LLWU_F3_MWUF2_MASK          0x4u
#define  LLWU_F3_MWUF2_SHIFT         2
//   Wakeup flag For module 2
//     0b0 ==> Module 2 input was not a wakeup source
//     0b1 ==> Module 2 input was a wakeup source

#define  LLWU_F3_MWUF3_MASK          0x8u
#define  LLWU_F3_MWUF3_SHIFT         3
//   Wakeup flag For module 3
//     0b0 ==> Module 3 input was not a wakeup source
//     0b1 ==> Module 3 input was a wakeup source

#define  LLWU_F3_MWUF4_MASK          0x10u
#define  LLWU_F3_MWUF4_SHIFT         4
//   Wakeup flag For module 4
//     0b0 ==> Module 4 input was not a wakeup source
//     0b1 ==> Module 4 input was a wakeup source

#define  LLWU_F3_MWUF5_MASK          0x20u
#define  LLWU_F3_MWUF5_SHIFT         5
//   Wakeup flag For module 5
//     0b0 ==> Module 5 input was not a wakeup source
//     0b1 ==> Module 5 input was a wakeup source

#define  LLWU_F3_MWUF6_MASK          0x40u
#define  LLWU_F3_MWUF6_SHIFT         6
//   Wakeup flag For module 6
//     0b0 ==> Module 6 input was not a wakeup source
//     0b1 ==> Module 6 input was a wakeup source

#define  LLWU_F3_MWUF7_MASK          0x80u
#define  LLWU_F3_MWUF7_SHIFT         7
//   Wakeup flag For module 7
//     0b0 ==> Module 7 input was not a wakeup source
//     0b1 ==> Module 7 input was a wakeup source

#define  LLWU_FILT1_FILTSEL_MASK     0x4u
#define  LLWU_FILT1_FILTSEL_SHIFT    0
#define  LLWU_FILT1_FILTSEL(x)       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK)
//   Filter Pin Select
//     0b0000 ==> Select LLWU_P0 for filter
//     0b1111 ==> Select LLWU_P15 for filter

#define  LLWU_FILT1_FILTE_MASK       0x40u
#define  LLWU_FILT1_FILTE_SHIFT      5
#define  LLWU_FILT1_FILTE(x)         (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK)
//   Digital Filter On External Pin
//     0b00 ==> Filter disabled
//     0b01 ==> Filter posedge detect enabled
//     0b10 ==> Filter negedge detect enabled
//     0b11 ==> Filter any edge detect enabled

#define  LLWU_FILT1_FILTF_MASK       0x80u
#define  LLWU_FILT1_FILTF_SHIFT      7
//   Filter Detect Flag
//     0b0 ==> Pin Filter 1 was not a wakeup source
//     0b1 ==> Pin Filter 1 was a wakeup source

#define  LLWU_FILT2_FILTSEL_MASK     0x4u
#define  LLWU_FILT2_FILTSEL_SHIFT    0
#define  LLWU_FILT2_FILTSEL(x)       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK)
//   Filter Pin Select
//     0b0000 ==> Select LLWU_P0 for filter
//     0b1111 ==> Select LLWU_P15 for filter

#define  LLWU_FILT2_FILTE_MASK       0x40u
#define  LLWU_FILT2_FILTE_SHIFT      5
#define  LLWU_FILT2_FILTE(x)         (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK)
//   Digital Filter On External Pin
//     0b00 ==> Filter disabled
//     0b01 ==> Filter posedge detect enabled
//     0b10 ==> Filter negedge detect enabled
//     0b11 ==> Filter any edge detect enabled

#define  LLWU_FILT2_FILTF_MASK       0x80u
#define  LLWU_FILT2_FILTF_SHIFT      7
//   Filter Detect Flag
//     0b0 ==> Pin Filter 2 was not a wakeup source
//     0b1 ==> Pin Filter 2 was a wakeup source

#define  LPSCI0_BDH_SBR_MASK         0x5u
#define  LPSCI0_BDH_SBR_SHIFT        0
#define  LPSCI0_BDH_SBR(x)           (((uint8_t)(((uint8_t)(x))<<LPSCI0_BDH_SBR_SHIFT))&LPSCI0_BDH_SBR_MASK)
//   Baud Rate Modulo Divisor.

#define  LPSCI0_BDH_SBNS_MASK        0x20u
#define  LPSCI0_BDH_SBNS_SHIFT       5
//   Stop Bit Number Select
//     0b0 ==> One stop bit.
//     0b1 ==> Two stop bit.

#define  LPSCI0_BDH_RXEDGIE_MASK     0x40u
#define  LPSCI0_BDH_RXEDGIE_SHIFT    6
//   RX Input Active Edge Interrupt Enable (for RXEDGIF)
//     0b0 ==> Hardware interrupts from LPSCI_S2[RXEDGIF] disabled (use polling).
//     0b1 ==> Hardware interrupt requested when LPSCI_S2[RXEDGIF] flag is 1.

#define  LPSCI0_BDH_LBKDIE_MASK      0x80u
#define  LPSCI0_BDH_LBKDIE_SHIFT     7
//   LIN Break Detect Interrupt Enable (for LBKDIF)
//     0b0 ==> Hardware interrupts from LPSCI_S2[LBKDIF] disabled (use polling).
//     0b1 ==> Hardware interrupt requested when LPSCI_S2[LBKDIF] flag is 1.

#define  LPSCI0_BDL_SBR_MASK         0x8u
#define  LPSCI0_BDL_SBR_SHIFT        0
#define  LPSCI0_BDL_SBR(x)           (((uint8_t)(((uint8_t)(x))<<LPSCI0_BDL_SBR_SHIFT))&LPSCI0_BDL_SBR_MASK)
//   Baud Rate Modulo Divisor

#define  LPSCI0_C1_PT_MASK           0x1u
#define  LPSCI0_C1_PT_SHIFT          0
//   Parity Type
//     0b0 ==> Even parity.
//     0b1 ==> Odd parity.

#define  LPSCI0_C1_PE_MASK           0x2u
#define  LPSCI0_C1_PE_SHIFT          1
//   Parity Enable
//     0b0 ==> No hardware parity generation or checking.
//     0b1 ==> Parity enabled.

#define  LPSCI0_C1_ILT_MASK          0x4u
#define  LPSCI0_C1_ILT_SHIFT         2
//   Idle Line Type Select
//     0b0 ==> Idle character bit count starts after start bit.
//     0b1 ==> Idle character bit count starts after stop bit.

#define  LPSCI0_C1_WAKE_MASK         0x8u
#define  LPSCI0_C1_WAKE_SHIFT        3
//   Receiver Wakeup Method Select
//     0b0 ==> Idle-line wakeup.
//     0b1 ==> Address-mark wakeup.

#define  LPSCI0_C1_M_MASK            0x10u
#define  LPSCI0_C1_M_SHIFT           4
//   9-Bit or 8-Bit Mode Select
//     0b0 ==> Receiver and transmitter use 8-bit data characters.
//     0b1 ==> Receiver and transmitter use 9-bit data characters.

#define  LPSCI0_C1_RSRC_MASK         0x20u
#define  LPSCI0_C1_RSRC_SHIFT        5
//   Receiver Source Select
//     0b0 ==> Provided LOOPS is set, RSRC is cleared, selects internal loop back mode and the LPSCI does not use the LPSCI_RX pins.
//     0b1 ==> Single-wire LPSCI mode where the LPSCI_TX pin is connected to the transmitter output and receiver input.

#define  LPSCI0_C1_DOZEEN_MASK       0x40u
#define  LPSCI0_C1_DOZEEN_SHIFT      6
//   Doze Enable
//     0b0 ==> LPSCI is enabled in Wait mode.
//     0b1 ==> LPSCI is disabled in Wait mode.

#define  LPSCI0_C1_LOOPS_MASK        0x80u
#define  LPSCI0_C1_LOOPS_SHIFT       7
//   Loop Mode Select
//     0b0 ==> Normal operation - LPSCI_RX and LPSCI_TX use separate pins.
//     0b1 ==> Loop mode or single-wire mode where transmitter outputs are internally connected to receiver input. (See RSRC bit.) LPSCI_RX pin is not used by LPSCI.

#define  LPSCI0_C2_SBK_MASK          0x1u
#define  LPSCI0_C2_SBK_SHIFT         0
//   Send Break
//     0b0 ==> Normal transmitter operation.
//     0b1 ==> Queue break character(s) to be sent.

#define  LPSCI0_C2_RWU_MASK          0x2u
#define  LPSCI0_C2_RWU_SHIFT         1
//   Receiver Wakeup Control
//     0b0 ==> Normal LPSCI receiver operation.
//     0b1 ==> LPSCI receiver in standby waiting for wakeup condition.

#define  LPSCI0_C2_RE_MASK           0x4u
#define  LPSCI0_C2_RE_SHIFT          2
//   Receiver Enable
//     0b0 ==> Receiver disabled.
//     0b1 ==> Receiver enabled.

#define  LPSCI0_C2_TE_MASK           0x8u
#define  LPSCI0_C2_TE_SHIFT          3
//   Transmitter Enable
//     0b0 ==> Transmitter disabled.
//     0b1 ==> Transmitter enabled.

#define  LPSCI0_C2_ILIE_MASK         0x10u
#define  LPSCI0_C2_ILIE_SHIFT        4
//   Idle Line Interrupt Enable for IDLE
//     0b0 ==> Hardware interrupts from IDLE disabled; use polling.
//     0b1 ==> Hardware interrupt requested when IDLE flag is 1.

#define  LPSCI0_C2_RIE_MASK          0x20u
#define  LPSCI0_C2_RIE_SHIFT         5
//   Receiver Interrupt Enable for RDRF
//     0b0 ==> Hardware interrupts from RDRF disabled; use polling.
//     0b1 ==> Hardware interrupt requested when RDRF flag is 1.

#define  LPSCI0_C2_TCIE_MASK         0x40u
#define  LPSCI0_C2_TCIE_SHIFT        6
//   Transmission Complete Interrupt Enable for TC
//     0b0 ==> Hardware interrupts from TC disabled; use polling.
//     0b1 ==> Hardware interrupt requested when TC flag is 1.

#define  LPSCI0_C2_TIE_MASK          0x80u
#define  LPSCI0_C2_TIE_SHIFT         7
//   Transmit Interrupt Enable for TDRE
//     0b0 ==> Hardware interrupts from TDRE disabled; use polling.
//     0b1 ==> Hardware interrupt requested when TDRE flag is 1.

#define  LPSCI0_S1_PF_MASK           0x1u
#define  LPSCI0_S1_PF_SHIFT          0
//   Parity Error Flag
//     0b0 ==> No parity error.
//     0b1 ==> Parity error.

#define  LPSCI0_S1_FE_MASK           0x2u
#define  LPSCI0_S1_FE_SHIFT          1
//   Framing Error Flag
//     0b0 ==> No framing error detected. This does not guarantee the framing is correct.
//     0b1 ==> Framing error.

#define  LPSCI0_S1_NF_MASK           0x4u
#define  LPSCI0_S1_NF_SHIFT          2
//   Noise Flag
//     0b0 ==> No noise detected.
//     0b1 ==> Noise detected in the received character in LPSCI_D.

#define  LPSCI0_S1_OR_MASK           0x8u
#define  LPSCI0_S1_OR_SHIFT          3
//   Receiver Overrun Flag
//     0b0 ==> No overrun.
//     0b1 ==> Receive overrun (new SCI data lost).

#define  LPSCI0_S1_IDLE_MASK         0x10u
#define  LPSCI0_S1_IDLE_SHIFT        4
//   Idle Line Flag
//     0b0 ==> No idle line detected.
//     0b1 ==> Idle line was detected.

#define  LPSCI0_S1_RDRF_MASK         0x20u
#define  LPSCI0_S1_RDRF_SHIFT        5
//   Receive Data Register Full Flag
//     0b0 ==> Receive data buffer empty.
//     0b1 ==> Receive data buffer full.

#define  LPSCI0_S1_TC_MASK           0x40u
#define  LPSCI0_S1_TC_SHIFT          6
//   Transmission Complete Flag
//     0b0 ==> Transmitter active (sending data, a preamble, or a break).
//     0b1 ==> Transmitter idle (transmission activity complete).

#define  LPSCI0_S1_TDRE_MASK         0x80u
#define  LPSCI0_S1_TDRE_SHIFT        7
//   Transmit Data Register Empty Flag
//     0b0 ==> Transmit data buffer full.
//     0b1 ==> Transmit data buffer empty.

#define  LPSCI0_S2_RAF_MASK          0x1u
#define  LPSCI0_S2_RAF_SHIFT         0
//   Receiver Active Flag
//     0b0 ==> SCI receiver idle waiting for a start bit.
//     0b1 ==> SCI receiver active (LPSCI_RXD input not idle).

#define  LPSCI0_S2_LBKDE_MASK        0x2u
#define  LPSCI0_S2_LBKDE_SHIFT       1
//   LIN Break Detection Enable
//     0b0 ==> Break character is detected at length 10 bit times (if M = 0, SBNS = 0) or 11 (if M = 1, SBNS = 0 or M = 0, SBNS = 1) or 12 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 13 (if M10 = 1, SNBS = 1).
//     0b1 ==> Break character is detected at length of 11 bit times (if M = 0, SBNS = 0) or 12 (if M = 1, SBNS = 0 or M = 0, SBNS = 1) or 14 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 15 (if M10 = 1, SNBS = 1).

#define  LPSCI0_S2_BRK13_MASK        0x4u
#define  LPSCI0_S2_BRK13_SHIFT       2
//   Break Character Generation Length
//     0b0 ==> Break character is transmitted with length of 10 bit times (if M = 0, SBNS = 0) or 11 (if M = 1, SBNS = 0 or M = 0, SBNS = 1) or 12 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 13 (if M10 = 1, SNBS = 1).
//     0b1 ==> Break character is transmitted with length of 13 bit times (if M = 0, SBNS = 0) or 14 (if M = 1, SBNS = 0 or M = 0, SBNS = 1) or 15 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 16 (if M10 = 1, SNBS = 1).

#define  LPSCI0_S2_RWUID_MASK        0x8u
#define  LPSCI0_S2_RWUID_SHIFT       3
//   Receive Wake Up Idle Detect
//     0b0 ==> During receive standby state (RWU = 1), the IDLE bit does not get set upon detection of an idle character.
//     0b1 ==> During receive standby state (RWU = 1), the IDLE bit gets set upon detection of an idle character.

#define  LPSCI0_S2_RXINV_MASK        0x10u
#define  LPSCI0_S2_RXINV_SHIFT       4
//   Receive Data Inversion
//     0b0 ==> Receive data not inverted.
//     0b1 ==> Receive data inverted.

#define  LPSCI0_S2_MSBF_MASK         0x20u
#define  LPSCI0_S2_MSBF_SHIFT        5
//   MSB First
//     0b0 ==> LSB (bit0) is the first bit that is transmitted following the start bit. Further, the first bit received after the start bit is identified as bit0.
//     0b1 ==> MSB (bit9, bit8, bit7 or bit6) is the first bit that is transmitted following the start bit depending on the setting of C1[M], C1[PE] and C4[M10]. Further, the first bit received after the start bit is identified as bit9, bit8, bit7 or bit6 depending on the setting of C1[M] and C1[PE].

#define  LPSCI0_S2_RXEDGIF_MASK      0x40u
#define  LPSCI0_S2_RXEDGIF_SHIFT     6
//   LPSCI_RX Pin Active Edge Interrupt Flag
//     0b0 ==> No active edge on the receive pin has occurred.
//     0b1 ==> An active edge on the receive pin has occurred.

#define  LPSCI0_S2_LBKDIF_MASK       0x80u
#define  LPSCI0_S2_LBKDIF_SHIFT      7
//   LIN Break Detect Interrupt Flag
//     0b0 ==> No LIN break character has been detected.
//     0b1 ==> LIN break character has been detected.

#define  LPSCI0_C3_PEIE_MASK         0x1u
#define  LPSCI0_C3_PEIE_SHIFT        0
//   Parity Error Interrupt Enable
//     0b0 ==> PF interrupts disabled; use polling).
//     0b1 ==> Hardware interrupt requested when PF is set.

#define  LPSCI0_C3_FEIE_MASK         0x2u
#define  LPSCI0_C3_FEIE_SHIFT        1
//   Framing Error Interrupt Enable
//     0b0 ==> FE interrupts disabled; use polling).
//     0b1 ==> Hardware interrupt requested when FE is set.

#define  LPSCI0_C3_NEIE_MASK         0x4u
#define  LPSCI0_C3_NEIE_SHIFT        2
//   Noise Error Interrupt Enable
//     0b0 ==> NF interrupts disabled; use polling).
//     0b1 ==> Hardware interrupt requested when NF is set.

#define  LPSCI0_C3_ORIE_MASK         0x8u
#define  LPSCI0_C3_ORIE_SHIFT        3
//   Overrun Interrupt Enable
//     0b0 ==> OR interrupts disabled; use polling.
//     0b1 ==> Hardware interrupt requested when OR is set.

#define  LPSCI0_C3_TXINV_MASK        0x10u
#define  LPSCI0_C3_TXINV_SHIFT       4
//   Transmit Data Inversion
//     0b0 ==> Transmit data not inverted.
//     0b1 ==> Transmit data inverted.

#define  LPSCI0_C3_TXDIR_MASK        0x20u
#define  LPSCI0_C3_TXDIR_SHIFT       5
//   LPSCI_TX Pin Direction in Single-Wire Mode
//     0b0 ==> LPSCI_TXD pin is an input in single-wire mode.
//     0b1 ==> LPSCI_TXD pin is an output in single-wire mode.

#define  LPSCI0_C3_R9T8_MASK         0x40u
#define  LPSCI0_C3_R9T8_SHIFT        6
//   Receive Bit 9 / Transmit Bit 8

#define  LPSCI0_C3_R8T9_MASK         0x80u
#define  LPSCI0_C3_R8T9_SHIFT        7
//   Receive Bit 8 / Transmit Bit 9

#define  LPSCI0_D_R0T0_MASK          0x1u
#define  LPSCI0_D_R0T0_SHIFT         0

#define  LPSCI0_D_R1T1_MASK          0x2u
#define  LPSCI0_D_R1T1_SHIFT         1

#define  LPSCI0_D_R2T2_MASK          0x4u
#define  LPSCI0_D_R2T2_SHIFT         2

#define  LPSCI0_D_R3T3_MASK          0x8u
#define  LPSCI0_D_R3T3_SHIFT         3

#define  LPSCI0_D_R4T4_MASK          0x10u
#define  LPSCI0_D_R4T4_SHIFT         4

#define  LPSCI0_D_R5T5_MASK          0x20u
#define  LPSCI0_D_R5T5_SHIFT         5

#define  LPSCI0_D_R6T6_MASK          0x40u
#define  LPSCI0_D_R6T6_SHIFT         6

#define  LPSCI0_D_R7T7_MASK          0x80u
#define  LPSCI0_D_R7T7_SHIFT         7

#define  LPSCI0_MA1_MA_MASK          0x8u
#define  LPSCI0_MA1_MA_SHIFT         0
#define  LPSCI0_MA1_MA(x)            (((uint8_t)(((uint8_t)(x))<<LPSCI0_MA1_MA_SHIFT))&LPSCI0_MA1_MA_MASK)
//   Match Address

#define  LPSCI0_MA2_MA_MASK          0x8u
#define  LPSCI0_MA2_MA_SHIFT         0
#define  LPSCI0_MA2_MA(x)            (((uint8_t)(((uint8_t)(x))<<LPSCI0_MA2_MA_SHIFT))&LPSCI0_MA2_MA_MASK)
//   Match Address

#define  LPSCI0_C4_OSR_MASK          0x5u
#define  LPSCI0_C4_OSR_SHIFT         0
#define  LPSCI0_C4_OSR(x)            (((uint8_t)(((uint8_t)(x))<<LPSCI0_C4_OSR_SHIFT))&LPSCI0_C4_OSR_MASK)
//   Over Sampling Ratio

#define  LPSCI0_C4_M10_MASK          0x20u
#define  LPSCI0_C4_M10_SHIFT         5
//   10-bit Mode select
//     0b0 ==> Receiver and transmitter use 8-bit or 9-bit data characters.
//     0b1 ==> Receiver and transmitter use 10-bit data characters.

#define  LPSCI0_C4_MAEN2_MASK        0x40u
#define  LPSCI0_C4_MAEN2_SHIFT       6
//   Match Address Mode Enable 2
//     0b0 ==> All data received is transferred to the data buffer if MAEN1 is cleared.
//     0b1 ==> All data received with the most significant bit cleared, is discarded. All data received with the most significant bit set, is compared with contents of MA2 register. If no match occurs, the data is discarded. If match occurs, data is transferred to the data buffer.

#define  LPSCI0_C4_MAEN1_MASK        0x80u
#define  LPSCI0_C4_MAEN1_SHIFT       7
//   Match Address Mode Enable 1
//     0b0 ==> All data received is transferred to the data buffer if MAEN2 is cleared.
//     0b1 ==> All data received with the most significant bit cleared, is discarded. All data received with the most significant bit set, is compared with contents of MA1 register. If no match occurs, the data is discarded. If match occurs, data is transferred to the data buffer.

#define  LPSCI0_C5_RESYNCDIS_MASK    0x1u
#define  LPSCI0_C5_RESYNCDIS_SHIFT   0
//   Resynchronization Disable
//     0b0 ==> Resynchronization during received data word is supported
//     0b1 ==> Resynchronization during received data word is disabled

#define  LPSCI0_C5_BOTHEDGE_MASK     0x2u
#define  LPSCI0_C5_BOTHEDGE_SHIFT    1
//   Both Edge Sampling
//     0b0 ==> Receiver samples input data using the rising edge of the baud rate clock.
//     0b1 ==> Receiver samples input data using the rising and falling edge of the baud rate clock.

#define  LPSCI0_C5_RDMAE_MASK        0x20u
#define  LPSCI0_C5_RDMAE_SHIFT       5
//   Receiver Full DMA Enable
//     0b0 ==> DMA request disabled.
//     0b1 ==> DMA request enabled.

#define  LPSCI0_C5_TDMAE_MASK        0x80u
#define  LPSCI0_C5_TDMAE_SHIFT       7
//   Transmitter DMA Enable
//     0b0 ==> DMA request disabled.
//     0b1 ==> DMA request enabled.

#define  LPTMR0_CSR_TEN_MASK         0x1u
#define  LPTMR0_CSR_TEN_SHIFT        0
//   Timer Enable
//     0b0 ==> LPTMR is disabled and internal logic is reset.
//     0b1 ==> LPTMR is enabled.

#define  LPTMR0_CSR_TMS_MASK         0x2u
#define  LPTMR0_CSR_TMS_SHIFT        1
//   Timer Mode Select
//     0b0 ==> Time Counter mode.
//     0b1 ==> Pulse Counter mode.

#define  LPTMR0_CSR_TFC_MASK         0x4u
#define  LPTMR0_CSR_TFC_SHIFT        2
//   Timer Free-Running Counter
//     0b0 ==> CNR is reset whenever TCF is set.
//     0b1 ==> CNR is reset on overflow.

#define  LPTMR0_CSR_TPP_MASK         0x8u
#define  LPTMR0_CSR_TPP_SHIFT        3
//   Timer Pin Polarity
//     0b0 ==> Pulse Counter input source is active-high, and the CNR will increment on the rising-edge.
//     0b1 ==> Pulse Counter input source is active-low, and the CNR will increment on the falling-edge.

#define  LPTMR0_CSR_TPS_MASK         0x20u
#define  LPTMR0_CSR_TPS_SHIFT        4
#define  LPTMR0_CSR_TPS(x)           (((uint32_t)(((uint32_t)(x))<<LPTMR0_CSR_TPS_SHIFT))&LPTMR0_CSR_TPS_MASK)
//   Timer Pin Select
//     0b00 ==> Pulse counter input 0 is selected.
//     0b01 ==> Pulse counter input 1 is selected.
//     0b10 ==> Pulse counter input 2 is selected.
//     0b11 ==> Pulse counter input 3 is selected.

#define  LPTMR0_CSR_TIE_MASK         0x40u
#define  LPTMR0_CSR_TIE_SHIFT        6
//   Timer Interrupt Enable
//     0b0 ==> Timer interrupt disabled.
//     0b1 ==> Timer interrupt enabled.

#define  LPTMR0_CSR_TCF_MASK         0x80u
#define  LPTMR0_CSR_TCF_SHIFT        7
//   Timer Compare Flag
//     0b0 ==> The value of CNR is not equal to CMR and increments.
//     0b1 ==> The value of CNR is equal to CMR and increments.

#define  LPTMR0_PSR_PCS_MASK         0x2u
#define  LPTMR0_PSR_PCS_SHIFT        0
#define  LPTMR0_PSR_PCS(x)           (((uint32_t)(((uint32_t)(x))<<LPTMR0_PSR_PCS_SHIFT))&LPTMR0_PSR_PCS_MASK)
//   Prescaler Clock Select
//     0b00 ==> Prescaler/glitch filter clock 0 selected.
//     0b01 ==> Prescaler/glitch filter clock 1 selected.
//     0b10 ==> Prescaler/glitch filter clock 2 selected.
//     0b11 ==> Prescaler/glitch filter clock 3 selected.

#define  LPTMR0_PSR_PBYP_MASK        0x4u
#define  LPTMR0_PSR_PBYP_SHIFT       2
//   Prescaler Bypass
//     0b0 ==> Prescaler/glitch filter is enabled.
//     0b1 ==> Prescaler/glitch filter is bypassed.

#define  LPTMR0_PSR_PRESCALE_MASK    0x20u
#define  LPTMR0_PSR_PRESCALE_SHIFT   3
#define  LPTMR0_PSR_PRESCALE(x)      (((uint32_t)(((uint32_t)(x))<<LPTMR0_PSR_PRESCALE_SHIFT))&LPTMR0_PSR_PRESCALE_MASK)
//   Prescale Value
//     0b0000 ==> Prescaler divides the prescaler clock by 2; glitch filter does not support this configuration.
//     0b0001 ==> Prescaler divides the prescaler clock by 4; glitch filter recognizes change on input pin after 2 rising clock edges.
//     0b0010 ==> Prescaler divides the prescaler clock by 8; glitch filter recognizes change on input pin after 4 rising clock edges.
//     0b0011 ==> Prescaler divides the prescaler clock by 16; glitch filter recognizes change on input pin after 8 rising clock edges.
//     0b0100 ==> Prescaler divides the prescaler clock by 32; glitch filter recognizes change on input pin after 16 rising clock edges.
//     0b0101 ==> Prescaler divides the prescaler clock by 64; glitch filter recognizes change on input pin after 32 rising clock edges.
//     0b0110 ==> Prescaler divides the prescaler clock by 128; glitch filter recognizes change on input pin after 64 rising clock edges.
//     0b0111 ==> Prescaler divides the prescaler clock by 256; glitch filter recognizes change on input pin after 128 rising clock edges.
//     0b1000 ==> Prescaler divides the prescaler clock by 512; glitch filter recognizes change on input pin after 256 rising clock edges.
//     0b1001 ==> Prescaler divides the prescaler clock by 1024; glitch filter recognizes change on input pin after 512 rising clock edges.
//     0b1010 ==> Prescaler divides the prescaler clock by 2048; glitch filter recognizes change on input pin after 1024 rising clock edges.
//     0b1011 ==> Prescaler divides the prescaler clock by 4096; glitch filter recognizes change on input pin after 2048 rising clock edges.
//     0b1100 ==> Prescaler divides the prescaler clock by 8192; glitch filter recognizes change on input pin after 4096 rising clock edges.
//     0b1101 ==> Prescaler divides the prescaler clock by 16,384; glitch filter recognizes change on input pin after 8192 rising clock edges.
//     0b1110 ==> Prescaler divides the prescaler clock by 32,768; glitch filter recognizes change on input pin after 16,384 rising clock edges.
//     0b1111 ==> Prescaler divides the prescaler clock by 65,536; glitch filter recognizes change on input pin after 32,768 rising clock edges.

#define  LPTMR0_CMR_COMPARE_MASK     0x10u
#define  LPTMR0_CMR_COMPARE_SHIFT    0
#define  LPTMR0_CMR_COMPARE(x)       (((uint32_t)(((uint32_t)(x))<<LPTMR0_CMR_COMPARE_SHIFT))&LPTMR0_CMR_COMPARE_MASK)
//   Compare Value

#define  LPTMR0_CNR_COUNTER_MASK     0x10u
#define  LPTMR0_CNR_COUNTER_SHIFT    0
#define  LPTMR0_CNR_COUNTER(x)       (((uint32_t)(((uint32_t)(x))<<LPTMR0_CNR_COUNTER_SHIFT))&LPTMR0_CNR_COUNTER_MASK)
//   Counter Value

#define  LPTPM0_SC_PS_MASK           0x3u
#define  LPTPM0_SC_PS_SHIFT          0
#define  LPTPM0_SC_PS(x)             (((uint32_t)(((uint32_t)(x))<<LPTPM0_SC_PS_SHIFT))&LPTPM0_SC_PS_MASK)
//   Prescale Factor Selection
//     0b000 ==> Divide by 1
//     0b001 ==> Divide by 2
//     0b010 ==> Divide by 4
//     0b011 ==> Divide by 8
//     0b100 ==> Divide by 16
//     0b101 ==> Divide by 32
//     0b110 ==> Divide by 64
//     0b111 ==> Divide by 128

#define  LPTPM0_SC_CMOD_MASK         0x10u
#define  LPTPM0_SC_CMOD_SHIFT        3
#define  LPTPM0_SC_CMOD(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_SC_CMOD_SHIFT))&LPTPM0_SC_CMOD_MASK)
//   Clock Mode Selection
//     0b00 ==> LPTPM counter is disabled
//     0b01 ==> LPTPM counter increments on every LPTPM counter clock
//     0b10 ==> LPTPM counter increments on rising edge of LPTPM_EXTCLK synchronized to the LPTPM counter clock
//     0b11 ==> Reserved

#define  LPTPM0_SC_CPWMS_MASK        0x20u
#define  LPTPM0_SC_CPWMS_SHIFT       5
//   Center-aligned PWM Select
//     0b0 ==> LPTPM counter operates in up counting mode.
//     0b1 ==> LPTPM counter operates in up-down counting mode.

#define  LPTPM0_SC_TOIE_MASK         0x40u
#define  LPTPM0_SC_TOIE_SHIFT        6
//   Timer Overflow Interrupt Enable
//     0b0 ==> Disable TOF interrupts. Use software polling or DMA request.
//     0b1 ==> Enable TOF interrupts. An interrupt is generated when TOF equals one.

#define  LPTPM0_SC_TOF_MASK          0x80u
#define  LPTPM0_SC_TOF_SHIFT         7
//   Timer Overflow Flag
//     0b0 ==> LPTPM counter has not overflowed.
//     0b1 ==> LPTPM counter has overflowed.

#define  LPTPM0_SC_DMA_MASK          0x100u
#define  LPTPM0_SC_DMA_SHIFT         8
//   DMA Enable
//     0b0 ==> Disables DMA transfers.
//     0b1 ==> Enables DMA transfers.

#define  LPTPM0_CNT_COUNT_MASK       0x10u
#define  LPTPM0_CNT_COUNT_SHIFT      0
#define  LPTPM0_CNT_COUNT(x)         (((uint32_t)(((uint32_t)(x))<<LPTPM0_CNT_COUNT_SHIFT))&LPTPM0_CNT_COUNT_MASK)
//   Counter value

#define  LPTPM0_MOD_MOD_MASK         0x10u
#define  LPTPM0_MOD_MOD_SHIFT        0
#define  LPTPM0_MOD_MOD(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_MOD_MOD_SHIFT))&LPTPM0_MOD_MOD_MASK)
//   Modulo value

#define  LPTPM0_C0SC_DMA_MASK        0x1u
#define  LPTPM0_C0SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C0SC_ELSA_MASK       0x4u
#define  LPTPM0_C0SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C0SC_ELSB_MASK       0x8u
#define  LPTPM0_C0SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C0SC_MSA_MASK        0x10u
#define  LPTPM0_C0SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C0SC_MSB_MASK        0x20u
#define  LPTPM0_C0SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C0SC_CHIE_MASK       0x40u
#define  LPTPM0_C0SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C0SC_CHF_MASK        0x80u
#define  LPTPM0_C0SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C0V_VAL_MASK         0x10u
#define  LPTPM0_C0V_VAL_SHIFT        0
#define  LPTPM0_C0V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C0V_VAL_SHIFT))&LPTPM0_C0V_VAL_MASK)
//   Channel Value

#define  LPTPM0_C1SC_DMA_MASK        0x1u
#define  LPTPM0_C1SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C1SC_ELSA_MASK       0x4u
#define  LPTPM0_C1SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C1SC_ELSB_MASK       0x8u
#define  LPTPM0_C1SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C1SC_MSA_MASK        0x10u
#define  LPTPM0_C1SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C1SC_MSB_MASK        0x20u
#define  LPTPM0_C1SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C1SC_CHIE_MASK       0x40u
#define  LPTPM0_C1SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C1SC_CHF_MASK        0x80u
#define  LPTPM0_C1SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C1V_VAL_MASK         0x10u
#define  LPTPM0_C1V_VAL_SHIFT        0
#define  LPTPM0_C1V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C1V_VAL_SHIFT))&LPTPM0_C1V_VAL_MASK)
//   Channel Value

#define  LPTPM0_C2SC_DMA_MASK        0x1u
#define  LPTPM0_C2SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C2SC_ELSA_MASK       0x4u
#define  LPTPM0_C2SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C2SC_ELSB_MASK       0x8u
#define  LPTPM0_C2SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C2SC_MSA_MASK        0x10u
#define  LPTPM0_C2SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C2SC_MSB_MASK        0x20u
#define  LPTPM0_C2SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C2SC_CHIE_MASK       0x40u
#define  LPTPM0_C2SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C2SC_CHF_MASK        0x80u
#define  LPTPM0_C2SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C2V_VAL_MASK         0x10u
#define  LPTPM0_C2V_VAL_SHIFT        0
#define  LPTPM0_C2V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C2V_VAL_SHIFT))&LPTPM0_C2V_VAL_MASK)
//   Channel Value

#define  LPTPM0_C3SC_DMA_MASK        0x1u
#define  LPTPM0_C3SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C3SC_ELSA_MASK       0x4u
#define  LPTPM0_C3SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C3SC_ELSB_MASK       0x8u
#define  LPTPM0_C3SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C3SC_MSA_MASK        0x10u
#define  LPTPM0_C3SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C3SC_MSB_MASK        0x20u
#define  LPTPM0_C3SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C3SC_CHIE_MASK       0x40u
#define  LPTPM0_C3SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C3SC_CHF_MASK        0x80u
#define  LPTPM0_C3SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C3V_VAL_MASK         0x10u
#define  LPTPM0_C3V_VAL_SHIFT        0
#define  LPTPM0_C3V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C3V_VAL_SHIFT))&LPTPM0_C3V_VAL_MASK)
//   Channel Value

#define  LPTPM0_C4SC_DMA_MASK        0x1u
#define  LPTPM0_C4SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C4SC_ELSA_MASK       0x4u
#define  LPTPM0_C4SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C4SC_ELSB_MASK       0x8u
#define  LPTPM0_C4SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C4SC_MSA_MASK        0x10u
#define  LPTPM0_C4SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C4SC_MSB_MASK        0x20u
#define  LPTPM0_C4SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C4SC_CHIE_MASK       0x40u
#define  LPTPM0_C4SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C4SC_CHF_MASK        0x80u
#define  LPTPM0_C4SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C4V_VAL_MASK         0x10u
#define  LPTPM0_C4V_VAL_SHIFT        0
#define  LPTPM0_C4V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C4V_VAL_SHIFT))&LPTPM0_C4V_VAL_MASK)
//   Channel Value

#define  LPTPM0_C5SC_DMA_MASK        0x1u
#define  LPTPM0_C5SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM0_C5SC_ELSA_MASK       0x4u
#define  LPTPM0_C5SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM0_C5SC_ELSB_MASK       0x8u
#define  LPTPM0_C5SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM0_C5SC_MSA_MASK        0x10u
#define  LPTPM0_C5SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM0_C5SC_MSB_MASK        0x20u
#define  LPTPM0_C5SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM0_C5SC_CHIE_MASK       0x40u
#define  LPTPM0_C5SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM0_C5SC_CHF_MASK        0x80u
#define  LPTPM0_C5SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_C5V_VAL_MASK         0x10u
#define  LPTPM0_C5V_VAL_SHIFT        0
#define  LPTPM0_C5V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM0_C5V_VAL_SHIFT))&LPTPM0_C5V_VAL_MASK)
//   Channel Value

#define  LPTPM0_STATUS_CH0F_MASK     0x1u
#define  LPTPM0_STATUS_CH0F_SHIFT    0
//   Channel 0 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_CH1F_MASK     0x2u
#define  LPTPM0_STATUS_CH1F_SHIFT    1
//   Channel 1 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_CH2F_MASK     0x4u
#define  LPTPM0_STATUS_CH2F_SHIFT    2
//   Channel 2 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_CH3F_MASK     0x8u
#define  LPTPM0_STATUS_CH3F_SHIFT    3
//   Channel 3 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_CH4F_MASK     0x10u
#define  LPTPM0_STATUS_CH4F_SHIFT    4
//   Channel 4 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_CH5F_MASK     0x20u
#define  LPTPM0_STATUS_CH5F_SHIFT    5
//   Channel 5 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM0_STATUS_TOF_MASK      0x100u
#define  LPTPM0_STATUS_TOF_SHIFT     8
//   Timer Overflow Flag
//     0b0 ==> LPTPM counter has not overflowed.
//     0b1 ==> LPTPM counter has overflowed.

#define  LPTPM0_CONF_DOZEEN_MASK     0x20u
#define  LPTPM0_CONF_DOZEEN_SHIFT    5
//   Doze Enable
//     0b0 ==> Internal LPTPM counter continues in Doze mode.
//     0b1 ==> Internal LPTPM counter is paused and does not increment during Doze mode. Trigger inputs and input capture events are also ignored.

#define  LPTPM0_CONF_DBGMODE_MASK    0x80u
#define  LPTPM0_CONF_DBGMODE_SHIFT   6
#define  LPTPM0_CONF_DBGMODE(x)      (((uint32_t)(((uint32_t)(x))<<LPTPM0_CONF_DBGMODE_SHIFT))&LPTPM0_CONF_DBGMODE_MASK)
//   Debug Mode
//     0b00 ==> LPTPM counter is paused and does not increment during debug mode. Trigger inputs and input capture events are also ignored.
//     0b11 ==> LPTPM counter continues in debug mode.

#define  LPTPM0_CONF_GTBEEN_MASK     0x200u
#define  LPTPM0_CONF_GTBEEN_SHIFT    9
//   Global time base enable
//     0b0 ==> All channels use the internally generated LPTPM counter as their timebase
//     0b1 ==> All channels use an externally generated global timebase as their timebase

#define  LPTPM0_CONF_CSOT_MASK       0x10000u
#define  LPTPM0_CONF_CSOT_SHIFT      16
//   Counter Start on Trigger
//     0b0 ==> LPTPM counter starts to increment immediately, once it is enabled.
//     0b1 ==> LPTPM counter only starts to increment when it a rising edge on the selected input trigger is detected, after it has been enabled or after it has stopped due to overflow.

#define  LPTPM0_CONF_CSOO_MASK       0x20000u
#define  LPTPM0_CONF_CSOO_SHIFT      17
//   Counter Stop On Overflow
//     0b0 ==> LPTPM counter continues incrementing or decrementing after overflow
//     0b1 ==> LPTPM counter stops incrementing or decrementing after overflow.

#define  LPTPM0_CONF_CROT_MASK       0x40000u
#define  LPTPM0_CONF_CROT_SHIFT      18
//   Counter Reload On Trigger
//     0b0 ==> Counter is not reloaded due to a rising edge on the selected input trigger
//     0b1 ==> Counter is reloaded when a rising edge is detected on the selected input trigger

#define  LPTPM0_CONF_TRGSEL_MASK     0x4000000u
#define  LPTPM0_CONF_TRGSEL_SHIFT    24
#define  LPTPM0_CONF_TRGSEL(x)       (((uint32_t)(((uint32_t)(x))<<LPTPM0_CONF_TRGSEL_SHIFT))&LPTPM0_CONF_TRGSEL_MASK)
//   Trigger Select

#define  LPTPM1_SC_PS_MASK           0x3u
#define  LPTPM1_SC_PS_SHIFT          0
#define  LPTPM1_SC_PS(x)             (((uint32_t)(((uint32_t)(x))<<LPTPM1_SC_PS_SHIFT))&LPTPM1_SC_PS_MASK)
//   Prescale Factor Selection
//     0b000 ==> Divide by 1
//     0b001 ==> Divide by 2
//     0b010 ==> Divide by 4
//     0b011 ==> Divide by 8
//     0b100 ==> Divide by 16
//     0b101 ==> Divide by 32
//     0b110 ==> Divide by 64
//     0b111 ==> Divide by 128

#define  LPTPM1_SC_CMOD_MASK         0x10u
#define  LPTPM1_SC_CMOD_SHIFT        3
#define  LPTPM1_SC_CMOD(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_SC_CMOD_SHIFT))&LPTPM1_SC_CMOD_MASK)
//   Clock Mode Selection
//     0b00 ==> LPTPM counter is disabled
//     0b01 ==> LPTPM counter increments on every LPTPM counter clock
//     0b10 ==> LPTPM counter increments on rising edge of LPTPM_EXTCLK synchronized to the LPTPM counter clock
//     0b11 ==> Reserved

#define  LPTPM1_SC_CPWMS_MASK        0x20u
#define  LPTPM1_SC_CPWMS_SHIFT       5
//   Center-aligned PWM Select
//     0b0 ==> LPTPM counter operates in up counting mode.
//     0b1 ==> LPTPM counter operates in up-down counting mode.

#define  LPTPM1_SC_TOIE_MASK         0x40u
#define  LPTPM1_SC_TOIE_SHIFT        6
//   Timer Overflow Interrupt Enable
//     0b0 ==> Disable TOF interrupts. Use software polling or DMA request.
//     0b1 ==> Enable TOF interrupts. An interrupt is generated when TOF equals one.

#define  LPTPM1_SC_TOF_MASK          0x80u
#define  LPTPM1_SC_TOF_SHIFT         7
//   Timer Overflow Flag
//     0b0 ==> LPTPM counter has not overflowed.
//     0b1 ==> LPTPM counter has overflowed.

#define  LPTPM1_SC_DMA_MASK          0x100u
#define  LPTPM1_SC_DMA_SHIFT         8
//   DMA Enable
//     0b0 ==> Disables DMA transfers.
//     0b1 ==> Enables DMA transfers.

#define  LPTPM1_CNT_COUNT_MASK       0x10u
#define  LPTPM1_CNT_COUNT_SHIFT      0
#define  LPTPM1_CNT_COUNT(x)         (((uint32_t)(((uint32_t)(x))<<LPTPM1_CNT_COUNT_SHIFT))&LPTPM1_CNT_COUNT_MASK)
//   Counter value

#define  LPTPM1_MOD_MOD_MASK         0x10u
#define  LPTPM1_MOD_MOD_SHIFT        0
#define  LPTPM1_MOD_MOD(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_MOD_MOD_SHIFT))&LPTPM1_MOD_MOD_MASK)
//   Modulo value

#define  LPTPM1_C0SC_DMA_MASK        0x1u
#define  LPTPM1_C0SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C0SC_ELSA_MASK       0x4u
#define  LPTPM1_C0SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C0SC_ELSB_MASK       0x8u
#define  LPTPM1_C0SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C0SC_MSA_MASK        0x10u
#define  LPTPM1_C0SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C0SC_MSB_MASK        0x20u
#define  LPTPM1_C0SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C0SC_CHIE_MASK       0x40u
#define  LPTPM1_C0SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C0SC_CHF_MASK        0x80u
#define  LPTPM1_C0SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C0V_VAL_MASK         0x10u
#define  LPTPM1_C0V_VAL_SHIFT        0
#define  LPTPM1_C0V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C0V_VAL_SHIFT))&LPTPM1_C0V_VAL_MASK)
//   Channel Value

#define  LPTPM1_C1SC_DMA_MASK        0x1u
#define  LPTPM1_C1SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C1SC_ELSA_MASK       0x4u
#define  LPTPM1_C1SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C1SC_ELSB_MASK       0x8u
#define  LPTPM1_C1SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C1SC_MSA_MASK        0x10u
#define  LPTPM1_C1SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C1SC_MSB_MASK        0x20u
#define  LPTPM1_C1SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C1SC_CHIE_MASK       0x40u
#define  LPTPM1_C1SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C1SC_CHF_MASK        0x80u
#define  LPTPM1_C1SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C1V_VAL_MASK         0x10u
#define  LPTPM1_C1V_VAL_SHIFT        0
#define  LPTPM1_C1V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C1V_VAL_SHIFT))&LPTPM1_C1V_VAL_MASK)
//   Channel Value

#define  LPTPM1_C2SC_DMA_MASK        0x1u
#define  LPTPM1_C2SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C2SC_ELSA_MASK       0x4u
#define  LPTPM1_C2SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C2SC_ELSB_MASK       0x8u
#define  LPTPM1_C2SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C2SC_MSA_MASK        0x10u
#define  LPTPM1_C2SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C2SC_MSB_MASK        0x20u
#define  LPTPM1_C2SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C2SC_CHIE_MASK       0x40u
#define  LPTPM1_C2SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C2SC_CHF_MASK        0x80u
#define  LPTPM1_C2SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C2V_VAL_MASK         0x10u
#define  LPTPM1_C2V_VAL_SHIFT        0
#define  LPTPM1_C2V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C2V_VAL_SHIFT))&LPTPM1_C2V_VAL_MASK)
//   Channel Value

#define  LPTPM1_C3SC_DMA_MASK        0x1u
#define  LPTPM1_C3SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C3SC_ELSA_MASK       0x4u
#define  LPTPM1_C3SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C3SC_ELSB_MASK       0x8u
#define  LPTPM1_C3SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C3SC_MSA_MASK        0x10u
#define  LPTPM1_C3SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C3SC_MSB_MASK        0x20u
#define  LPTPM1_C3SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C3SC_CHIE_MASK       0x40u
#define  LPTPM1_C3SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C3SC_CHF_MASK        0x80u
#define  LPTPM1_C3SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C3V_VAL_MASK         0x10u
#define  LPTPM1_C3V_VAL_SHIFT        0
#define  LPTPM1_C3V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C3V_VAL_SHIFT))&LPTPM1_C3V_VAL_MASK)
//   Channel Value

#define  LPTPM1_C4SC_DMA_MASK        0x1u
#define  LPTPM1_C4SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C4SC_ELSA_MASK       0x4u
#define  LPTPM1_C4SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C4SC_ELSB_MASK       0x8u
#define  LPTPM1_C4SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C4SC_MSA_MASK        0x10u
#define  LPTPM1_C4SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C4SC_MSB_MASK        0x20u
#define  LPTPM1_C4SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C4SC_CHIE_MASK       0x40u
#define  LPTPM1_C4SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C4SC_CHF_MASK        0x80u
#define  LPTPM1_C4SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C4V_VAL_MASK         0x10u
#define  LPTPM1_C4V_VAL_SHIFT        0
#define  LPTPM1_C4V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C4V_VAL_SHIFT))&LPTPM1_C4V_VAL_MASK)
//   Channel Value

#define  LPTPM1_C5SC_DMA_MASK        0x1u
#define  LPTPM1_C5SC_DMA_SHIFT       0
//   DMA Enable
//     0b0 ==> Disable DMA transfers.
//     0b1 ==> Enable DMA transfers.

#define  LPTPM1_C5SC_ELSA_MASK       0x4u
#define  LPTPM1_C5SC_ELSA_SHIFT      2
//   Edge or Level Select

#define  LPTPM1_C5SC_ELSB_MASK       0x8u
#define  LPTPM1_C5SC_ELSB_SHIFT      3
//   Edge or Level Select

#define  LPTPM1_C5SC_MSA_MASK        0x10u
#define  LPTPM1_C5SC_MSA_SHIFT       4
//   Channel Mode Select

#define  LPTPM1_C5SC_MSB_MASK        0x20u
#define  LPTPM1_C5SC_MSB_SHIFT       5
//   Channel Mode Select

#define  LPTPM1_C5SC_CHIE_MASK       0x40u
#define  LPTPM1_C5SC_CHIE_SHIFT      6
//   Channel Interrupt Enable
//     0b0 ==> Disable channel interrupts.
//     0b1 ==> Enable channel interrupts.

#define  LPTPM1_C5SC_CHF_MASK        0x80u
#define  LPTPM1_C5SC_CHF_SHIFT       7
//   Channel Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_C5V_VAL_MASK         0x10u
#define  LPTPM1_C5V_VAL_SHIFT        0
#define  LPTPM1_C5V_VAL(x)           (((uint32_t)(((uint32_t)(x))<<LPTPM1_C5V_VAL_SHIFT))&LPTPM1_C5V_VAL_MASK)
//   Channel Value

#define  LPTPM1_STATUS_CH0F_MASK     0x1u
#define  LPTPM1_STATUS_CH0F_SHIFT    0
//   Channel 0 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_CH1F_MASK     0x2u
#define  LPTPM1_STATUS_CH1F_SHIFT    1
//   Channel 1 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_CH2F_MASK     0x4u
#define  LPTPM1_STATUS_CH2F_SHIFT    2
//   Channel 2 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_CH3F_MASK     0x8u
#define  LPTPM1_STATUS_CH3F_SHIFT    3
//   Channel 3 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_CH4F_MASK     0x10u
#define  LPTPM1_STATUS_CH4F_SHIFT    4
//   Channel 4 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_CH5F_MASK     0x20u
#define  LPTPM1_STATUS_CH5F_SHIFT    5
//   Channel 5 Flag
//     0b0 ==> No channel event has occurred.
//     0b1 ==> A channel event has occurred.

#define  LPTPM1_STATUS_TOF_MASK      0x100u
#define  LPTPM1_STATUS_TOF_SHIFT     8
//   Timer Overflow Flag
//     0b0 ==> LPTPM counter has not overflowed.
//     0b1 ==> LPTPM counter has overflowed.

#define  LPTPM1_CONF_DOZEEN_MASK     0x20u
#define  LPTPM1_CONF_DOZEEN_SHIFT    5
//   Doze Enable
//     0b0 ==> Internal LPTPM counter continues in Doze mode.
//     0b1 ==> Internal LPTPM counter is paused and does not increment during Doze mode. Trigger inputs and input capture events are also ignored.

#define  LPTPM1_CONF_DBGMODE_MASK    0x80u
#define  LPTPM1_CONF_DBGMODE_SHIFT   6
#define  LPTPM1_CONF_DBGMODE(x)      (((uint32_t)(((uint32_t)(x))<<LPTPM1_CONF_DBGMODE_SHIFT))&LPTPM1_CONF_DBGMODE_MASK)
//   Debug Mode
//     0b00 ==> LPTPM counter is paused and does not increment during debug mode. Trigger inputs and input capture events are also ignored.
//     0b11 ==> LPTPM counter continues in debug mode.

#define  LPTPM1_CONF_GTBEEN_MASK     0x200u
#define  LPTPM1_CONF_GTBEEN_SHIFT    9
//   Global time base enable
//     0b0 ==> All channels use the internally generated LPTPM counter as their timebase
//     0b1 ==> All channels use an externally generated global timebase as their timebase

#define  LPTPM1_CONF_CSOT_MASK       0x10000u
#define  LPTPM1_CONF_CSOT_SHIFT      16
//   Counter Start on Trigger
//     0b0 ==> LPTPM counter starts to increment immediately, once it is enabled.
//     0b1 ==> LPTPM counter only starts to increment when it a rising edge on the selected input trigger is detected, after it has been enabled or after it has stopped due to overflow.

#define  LPTPM1_CONF_CSOO_MASK       0x20000u
#define  LPTPM1_CONF_CSOO_SHIFT      17
//   Counter Stop On Overflow
//     0b0 ==> LPTPM counter continues incrementing or decrementing after overflow
//     0b1 ==> LPTPM counter stops incrementing or decrementing after overflow.

#define  LPTPM1_CONF_CROT_MASK       0x40000u
#define  LPTPM1_CONF_CROT_SHIFT      18
//   Counter Reload On Trigger
//     0b0 ==> Counter is not reloaded due to a rising edge on the selected input trigger
//     0b1 ==> Counter is reloaded when a rising edge is detected on the selected input trigger

#define  LPTPM1_CONF_TRGSEL_MASK     0x4000000u
#define  LPTPM1_CONF_TRGSEL_SHIFT    24
#define  LPTPM1_CONF_TRGSEL(x)       (((uint32_t)(((uint32_t)(x))<<LPTPM1_CONF_TRGSEL_SHIFT))&LPTPM1_CONF_TRGSEL_MASK)
//   Trigger Select

#define  MCG_C1_IREFSTEN_MASK        0x1u
#define  MCG_C1_IREFSTEN_SHIFT       0
//   Internal Reference Stop Enable
//     0b0 ==> Internal reference clock is disabled in Stop mode.
//     0b1 ==> Internal reference clock is enabled in Stop mode if IRCLKEN is set or if MCG is in FEI, FBI, or BLPI modes before entering Stop mode.

#define  MCG_C1_IRCLKEN_MASK         0x2u
#define  MCG_C1_IRCLKEN_SHIFT        1
//   Internal Reference Clock Enable
//     0b0 ==> MCGIRCLK inactive.
//     0b1 ==> MCGIRCLK active.

#define  MCG_C1_IREFS_MASK           0x4u
#define  MCG_C1_IREFS_SHIFT          2
//   Internal Reference Select
//     0b0 ==> External reference clock is selected.
//     0b1 ==> The slow internal reference clock is selected.

#define  MCG_C1_FRDIV_MASK           0x18u
#define  MCG_C1_FRDIV_SHIFT          3
#define  MCG_C1_FRDIV(x)             (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
//   FLL External Reference Divider
//     0b000 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 1; for all other RANGE 0 values, Divide Factor is 32.
//     0b001 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 2; for all other RANGE 0 values, Divide Factor is 64.
//     0b010 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 4; for all other RANGE 0 values, Divide Factor is 128.
//     0b011 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 8; for all other RANGE 0 values, Divide Factor is 256.
//     0b100 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 16; for all other RANGE 0 values, Divide Factor is 512.
//     0b101 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 32; for all other RANGE 0 values, Divide Factor is 1024.
//     0b110 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 64; for all other RANGE 0 values, Divide Factor is 1280 .
//     0b111 ==> If RANGE 0 = 0 or OSCSEL=1 , Divide Factor is 128; for all other RANGE 0 values, Divide Factor is 1536 .

#define  MCG_C1_CLKS_MASK            0x80u
#define  MCG_C1_CLKS_SHIFT           6
#define  MCG_C1_CLKS(x)              (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
//   Clock Source Select
//     0b00 ==> Encoding 0 - Output of FLL or PLL is selected (depends on PLLS control bit).
//     0b01 ==> Encoding 1 - Internal reference clock is selected.
//     0b10 ==> Encoding 2 - External reference clock is selected.
//     0b11 ==> Encoding 3 - Reserved.

#define  MCG_C2_IRCS_MASK            0x1u
#define  MCG_C2_IRCS_SHIFT           0
//   Internal Reference Clock Select
//     0b0 ==> Slow internal reference clock selected.
//     0b1 ==> Fast internal reference clock selected.

#define  MCG_C2_LP_MASK              0x2u
#define  MCG_C2_LP_SHIFT             1
//   Low Power Select
//     0b0 ==> FLL or PLL is not disabled in bypass modes.
//     0b1 ==> FLL or PLL is disabled in bypass modes (lower power)

#define  MCG_C2_EREFS0_MASK          0x4u
#define  MCG_C2_EREFS0_SHIFT         2
//   External Reference Select
//     0b0 ==> External reference clock requested.
//     0b1 ==> Oscillator requested.

#define  MCG_C2_HGO0_MASK            0x8u
#define  MCG_C2_HGO0_SHIFT           3
//   High Gain Oscillator Select
//     0b0 ==> Configure crystal oscillator for low-power operation.
//     0b1 ==> Configure crystal oscillator for high-gain operation.

#define  MCG_C2_RANGE0_MASK          0x20u
#define  MCG_C2_RANGE0_SHIFT         4
#define  MCG_C2_RANGE0(x)            (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK)
//   Frequency Range Select
//     0b00 ==> Encoding 0 - Low frequency range selected for the crystal oscillator .
//     0b01 ==> Encoding 1 - High frequency range selected for the crystal oscillator .

#define  MCG_C2_LOCRE0_MASK          0x80u
#define  MCG_C2_LOCRE0_SHIFT         7
//   Loss of Clock Reset Enable
//     0b0 ==> Interrupt request is generated on a loss of OSC0 external reference clock.
//     0b1 ==> Generate a reset request on a loss of OSC0 external reference clock.

#define  MCG_C3_SCTRIM_MASK          0x8u
#define  MCG_C3_SCTRIM_SHIFT         0
#define  MCG_C3_SCTRIM(x)            (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
//   Slow Internal Reference Clock Trim Setting

#define  MCG_C4_SCFTRIM_MASK         0x1u
#define  MCG_C4_SCFTRIM_SHIFT        0
//   Slow Internal Reference Clock Fine Trim

#define  MCG_C4_FCTRIM_MASK          0x8u
#define  MCG_C4_FCTRIM_SHIFT         1
#define  MCG_C4_FCTRIM(x)            (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
//   Fast Internal Reference Clock Trim Setting

#define  MCG_C4_DRST_DRS_MASK        0x40u
#define  MCG_C4_DRST_DRS_SHIFT       5
#define  MCG_C4_DRST_DRS(x)          (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
//   DCO Range Select
//     0b00 ==> Encoding 0 - Low range (reset default).
//     0b01 ==> Encoding 1 - Mid range.
//     0b10 ==> Encoding 2 - Mid-high range.
//     0b11 ==> Encoding 3 - High range.

#define  MCG_C4_DMX32_MASK           0x80u
#define  MCG_C4_DMX32_SHIFT          7
//   DCO Maximum Frequency with 32.768 kHz Reference
//     0b0 ==> DCO has a default range of 25%.
//     0b1 ==> DCO is fine-tuned for maximum frequency with 32.768 kHz reference.

#define  MCG_C6_CME_MASK             0x20u
#define  MCG_C6_CME_SHIFT            5
//   Clock Monitor Enable
//     0b0 ==> External clock monitor is disabled.
//     0b1 ==> Generate a reset request on loss of external clock.

#define  MCG_S_IRCST_MASK            0x1u
#define  MCG_S_IRCST_SHIFT           0
//   Internal Reference Clock Status
//     0b0 ==> Source of internal reference clock is the slow clock (32 kHz IRC).
//     0b1 ==> Source of internal reference clock is the fast clock (2 MHz IRC).

#define  MCG_S_OSCINIT0_MASK         0x2u
#define  MCG_S_OSCINIT0_SHIFT        1
//   OSC Initialization

#define  MCG_S_CLKST_MASK            0x8u
#define  MCG_S_CLKST_SHIFT           2
#define  MCG_S_CLKST(x)              (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
//   Clock Mode Status
//     0b00 ==> Encoding 0 - Output of the FLL is selected (reset default).
//     0b01 ==> Encoding 1 - Internal reference clock is selected.
//     0b10 ==> Encoding 2 - External reference clock is selected.
//     0b11 ==> Encoding 3 - Output of the PLL is selected.

#define  MCG_S_IREFST_MASK           0x10u
#define  MCG_S_IREFST_SHIFT          4
//   Internal Reference Status
//     0b0 ==> Source of FLL reference clock is the external reference clock.
//     0b1 ==> Source of FLL reference clock is the internal reference clock.

#define  MCG_SC_LOCS0_MASK           0x1u
#define  MCG_SC_LOCS0_SHIFT          0
//   OSC0 Loss of Clock Status
//     0b0 ==> Loss of OSC0 has not occurred.
//     0b1 ==> Loss of OSC0 has occurred.

#define  MCG_SC_FCRDIV_MASK          0x6u
#define  MCG_SC_FCRDIV_SHIFT         1
#define  MCG_SC_FCRDIV(x)            (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK)
//   Fast Clock Internal Reference Divider
//     0b000 ==> Divide Factor is 1
//     0b001 ==> Divide Factor is 2.
//     0b010 ==> Divide Factor is 4.
//     0b011 ==> Divide Factor is 8.
//     0b100 ==> Divide Factor is 16
//     0b101 ==> Divide Factor is 32
//     0b110 ==> Divide Factor is 64
//     0b111 ==> Divide Factor is 128.

#define  MCG_SC_FLTPRSRV_MASK        0x10u
#define  MCG_SC_FLTPRSRV_SHIFT       4
//   FLL Filter Preserve Enable
//     0b0 ==> FLL filter and FLL frequency will reset on changes to currect clock mode.
//     0b1 ==> Fll filter and FLL frequency retain their previous values during new clock mode change.

#define  MCG_SC_ATMF_MASK            0x20u
#define  MCG_SC_ATMF_SHIFT           5
//   Automatic Trim Machine Fail Flag
//     0b0 ==> Automatic Trim Machine completed normally.
//     0b1 ==> Automatic Trim Machine failed.

#define  MCG_SC_ATMS_MASK            0x40u
#define  MCG_SC_ATMS_SHIFT           6
//   Automatic Trim Machine Select
//     0b0 ==> 32 kHz Internal Reference Clock selected.
//     0b1 ==> 4 MHz Internal Reference Clock selected.

#define  MCG_SC_ATME_MASK            0x80u
#define  MCG_SC_ATME_SHIFT           7
//   Automatic Trim Machine Enable
//     0b0 ==> Auto Trim Machine disabled.
//     0b1 ==> Auto Trim Machine enabled.

#define  MCG_ATCVH_ATCVH_MASK        0x8u
#define  MCG_ATCVH_ATCVH_SHIFT       0
#define  MCG_ATCVH_ATCVH(x)          (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
//   ATM Compare Value High

#define  MCG_ATCVL_ATCVL_MASK        0x8u
#define  MCG_ATCVL_ATCVL_SHIFT       0
#define  MCG_ATCVL_ATCVL(x)          (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)
//   ATM Compare Value Low

#define  MCG_C7_OSCSEL_MASK          0x1u
#define  MCG_C7_OSCSEL_SHIFT         0
//   MCG OSC Clock Select
//     0b0 ==> Selects System Oscillator (OSCCLK).
//     0b1 ==> Selects 32 kHz RTC Oscillator.

#define  MCG_C8_LOCS1_MASK           0x1u
#define  MCG_C8_LOCS1_SHIFT          0
//   RTC Loss of Clock Status
//     0b0 ==> Loss of RTC has not occur.
//     0b1 ==> Loss of RTC has occur

#define  MCG_C8_CME1_MASK            0x20u
#define  MCG_C8_CME1_SHIFT           5
//   Clock Monitor Enable1
//     0b0 ==> External clock monitor is disabled for RTC clock.
//     0b1 ==> External clock monitor is enabled for RTC clock.

#define  MCG_C8_LOCRE1_MASK          0x80u
#define  MCG_C8_LOCRE1_SHIFT         7
//   Loss of Clock Reset Enable
//     0b0 ==> Interrupt request is generated on a loss of RTC external reference clock.
//     0b1 ==> Generate a reset request on a loss of RTC external reference clock

#define  OSC0_CR_SC16P_MASK          0x1u
#define  OSC0_CR_SC16P_SHIFT         0
//   Oscillator 16 pF Capacitor Load Configure
//     0b0 ==> Disable the selection.
//     0b1 ==> Add 16 pF capacitor to the oscillator load.

#define  OSC0_CR_SC8P_MASK           0x2u
#define  OSC0_CR_SC8P_SHIFT          1
//   Oscillator 8 pF Capacitor Load Configure
//     0b0 ==> Disable the selection.
//     0b1 ==> Add 8 pF capacitor to the oscillator load.

#define  OSC0_CR_SC4P_MASK           0x4u
#define  OSC0_CR_SC4P_SHIFT          2
//   Oscillator 4 pF Capacitor Load Configure
//     0b0 ==> Disable the selection.
//     0b1 ==> Add 4 pF capacitor to the oscillator load.

#define  OSC0_CR_SC2P_MASK           0x8u
#define  OSC0_CR_SC2P_SHIFT          3
//   Oscillator 2 pF Capacitor Load Configure
//     0b0 ==> Disable the selection.
//     0b1 ==> Add 2 pF capacitor to the oscillator load.

#define  OSC0_CR_EREFSTEN_MASK       0x20u
#define  OSC0_CR_EREFSTEN_SHIFT      5
//   External Reference Stop Enable
//     0b0 ==> External reference clock is disabled in Stop mode.
//     0b1 ==> External reference clock stays enabled in Stop mode if ERCLKEN is set before entering Stop mode.

#define  OSC0_CR_ERCLKEN_MASK        0x80u
#define  OSC0_CR_ERCLKEN_SHIFT       7
//   External Reference Enable
//     0b0 ==> External reference clock is inactive.
//     0b1 ==> External reference clock is enabled.

#define  PIT_MCR_FRZ_MASK            0x1u
#define  PIT_MCR_FRZ_SHIFT           0
//   Freeze
//     0b0 ==> Timers continue to run in Debug mode.
//     0b1 ==> Timers are stopped in Debug mode.

#define  PIT_MCR_MDIS_MASK           0x2u
#define  PIT_MCR_MDIS_SHIFT          1
//   Module Disable
//     0b0 ==> Clock for PIT timers is enabled.
//     0b1 ==> Clock for PIT timers is disabled.

#define  PIT_LTMR64H_LTH_MASK        0x20u
#define  PIT_LTMR64H_LTH_SHIFT       0
#define  PIT_LTMR64H_LTH(x)          (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64H_LTH_SHIFT))&PIT_LTMR64H_LTH_MASK)
//   Life Timer value

#define  PIT_LTMR64L_LTL_MASK        0x20u
#define  PIT_LTMR64L_LTL_SHIFT       0
#define  PIT_LTMR64L_LTL(x)          (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64L_LTL_SHIFT))&PIT_LTMR64L_LTL_MASK)
//   Life Timer value

#define  PIT_LDVAL0_TSV_MASK         0x20u
#define  PIT_LDVAL0_TSV_SHIFT        0
#define  PIT_LDVAL0_TSV(x)           (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL0_TSV_SHIFT))&PIT_LDVAL0_TSV_MASK)
//   Timer Start Value

#define  PIT_CVAL0_TVL_MASK          0x20u
#define  PIT_CVAL0_TVL_SHIFT         0
#define  PIT_CVAL0_TVL(x)            (((uint32_t)(((uint32_t)(x))<<PIT_CVAL0_TVL_SHIFT))&PIT_CVAL0_TVL_MASK)
//   Current Timer Value

#define  PIT_TCTRL0_TEN_MASK         0x1u
#define  PIT_TCTRL0_TEN_SHIFT        0
//   Timer Enable
//     0b0 ==> Timer n is disabled.
//     0b1 ==> Timer n is enabled.

#define  PIT_TCTRL0_TIE_MASK         0x2u
#define  PIT_TCTRL0_TIE_SHIFT        1
//   Timer Interrupt Enable
//     0b0 ==> Interrupt requests from Timer n are disabled.
//     0b1 ==> Interrupt will be requested whenever TIF is set.

#define  PIT_TCTRL0_CHN_MASK         0x4u
#define  PIT_TCTRL0_CHN_SHIFT        2
//   Chain Mode
//     0b0 ==> Timer is not chained.
//     0b1 ==> Timer is chained to previous timer. For example, for Channel 2, if this field is set, Timer 2 is chained to Timer 1.

#define  PIT_TFLG0_TIF_MASK          0x1u
#define  PIT_TFLG0_TIF_SHIFT         0
//   Timer Interrupt Flag
//     0b0 ==> Timeout has not yet occurred.
//     0b1 ==> Timeout has occurred.

#define  PIT_LDVAL1_TSV_MASK         0x20u
#define  PIT_LDVAL1_TSV_SHIFT        0
#define  PIT_LDVAL1_TSV(x)           (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL1_TSV_SHIFT))&PIT_LDVAL1_TSV_MASK)
//   Timer Start Value

#define  PIT_CVAL1_TVL_MASK          0x20u
#define  PIT_CVAL1_TVL_SHIFT         0
#define  PIT_CVAL1_TVL(x)            (((uint32_t)(((uint32_t)(x))<<PIT_CVAL1_TVL_SHIFT))&PIT_CVAL1_TVL_MASK)
//   Current Timer Value

#define  PIT_TCTRL1_TEN_MASK         0x1u
#define  PIT_TCTRL1_TEN_SHIFT        0
//   Timer Enable
//     0b0 ==> Timer n is disabled.
//     0b1 ==> Timer n is enabled.

#define  PIT_TCTRL1_TIE_MASK         0x2u
#define  PIT_TCTRL1_TIE_SHIFT        1
//   Timer Interrupt Enable
//     0b0 ==> Interrupt requests from Timer n are disabled.
//     0b1 ==> Interrupt will be requested whenever TIF is set.

#define  PIT_TCTRL1_CHN_MASK         0x4u
#define  PIT_TCTRL1_CHN_SHIFT        2
//   Chain Mode
//     0b0 ==> Timer is not chained.
//     0b1 ==> Timer is chained to previous timer. For example, for Channel 2, if this field is set, Timer 2 is chained to Timer 1.

#define  PIT_TFLG1_TIF_MASK          0x1u
#define  PIT_TFLG1_TIF_SHIFT         0
//   Timer Interrupt Flag
//     0b0 ==> Timeout has not yet occurred.
//     0b1 ==> Timeout has occurred.

#define  PIT_LDVAL2_TSV_MASK         0x20u
#define  PIT_LDVAL2_TSV_SHIFT        0
#define  PIT_LDVAL2_TSV(x)           (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL2_TSV_SHIFT))&PIT_LDVAL2_TSV_MASK)
//   Timer Start Value

#define  PIT_CVAL2_TVL_MASK          0x20u
#define  PIT_CVAL2_TVL_SHIFT         0
#define  PIT_CVAL2_TVL(x)            (((uint32_t)(((uint32_t)(x))<<PIT_CVAL2_TVL_SHIFT))&PIT_CVAL2_TVL_MASK)
//   Current Timer Value

#define  PIT_TCTRL2_TEN_MASK         0x1u
#define  PIT_TCTRL2_TEN_SHIFT        0
//   Timer Enable
//     0b0 ==> Timer n is disabled.
//     0b1 ==> Timer n is enabled.

#define  PIT_TCTRL2_TIE_MASK         0x2u
#define  PIT_TCTRL2_TIE_SHIFT        1
//   Timer Interrupt Enable
//     0b0 ==> Interrupt requests from Timer n are disabled.
//     0b1 ==> Interrupt will be requested whenever TIF is set.

#define  PIT_TCTRL2_CHN_MASK         0x4u
#define  PIT_TCTRL2_CHN_SHIFT        2
//   Chain Mode
//     0b0 ==> Timer is not chained.
//     0b1 ==> Timer is chained to previous timer. For example, for Channel 2, if this field is set, Timer 2 is chained to Timer 1.

#define  PIT_TFLG2_TIF_MASK          0x1u
#define  PIT_TFLG2_TIF_SHIFT         0
//   Timer Interrupt Flag
//     0b0 ==> Timeout has not yet occurred.
//     0b1 ==> Timeout has occurred.

#define  PIT_LDVAL3_TSV_MASK         0x20u
#define  PIT_LDVAL3_TSV_SHIFT        0
#define  PIT_LDVAL3_TSV(x)           (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL3_TSV_SHIFT))&PIT_LDVAL3_TSV_MASK)
//   Timer Start Value

#define  PIT_CVAL3_TVL_MASK          0x20u
#define  PIT_CVAL3_TVL_SHIFT         0
#define  PIT_CVAL3_TVL(x)            (((uint32_t)(((uint32_t)(x))<<PIT_CVAL3_TVL_SHIFT))&PIT_CVAL3_TVL_MASK)
//   Current Timer Value

#define  PIT_TCTRL3_TEN_MASK         0x1u
#define  PIT_TCTRL3_TEN_SHIFT        0
//   Timer Enable
//     0b0 ==> Timer n is disabled.
//     0b1 ==> Timer n is enabled.

#define  PIT_TCTRL3_TIE_MASK         0x2u
#define  PIT_TCTRL3_TIE_SHIFT        1
//   Timer Interrupt Enable
//     0b0 ==> Interrupt requests from Timer n are disabled.
//     0b1 ==> Interrupt will be requested whenever TIF is set.

#define  PIT_TCTRL3_CHN_MASK         0x4u
#define  PIT_TCTRL3_CHN_SHIFT        2
//   Chain Mode
//     0b0 ==> Timer is not chained.
//     0b1 ==> Timer is chained to previous timer. For example, for Channel 2, if this field is set, Timer 2 is chained to Timer 1.

#define  PIT_TFLG3_TIF_MASK          0x1u
#define  PIT_TFLG3_TIF_SHIFT         0
//   Timer Interrupt Flag
//     0b0 ==> Timeout has not yet occurred.
//     0b1 ==> Timeout has occurred.

#define  PMC_LVDSC1_LVDV_MASK        0x2u
#define  PMC_LVDSC1_LVDV_SHIFT       0
#define  PMC_LVDSC1_LVDV(x)          (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
//   Low-Voltage Detect Voltage Select
//     0b00 ==> Low trip point selected (V LVD = V LVDL )
//     0b01 ==> High trip point selected (V LVD = V LVDH )
//     0b10 ==> Reserved
//     0b11 ==> Reserved

#define  PMC_LVDSC1_LVDRE_MASK       0x10u
#define  PMC_LVDSC1_LVDRE_SHIFT      4
//   Low-Voltage Detect Reset Enable
//     0b0 ==> LVDF does not generate hardware resets
//     0b1 ==> Force an MCU reset when LVDF = 1

#define  PMC_LVDSC1_LVDIE_MASK       0x20u
#define  PMC_LVDSC1_LVDIE_SHIFT      5
//   Low-Voltage Detect Interrupt Enable
//     0b0 ==> Hardware interrupt disabled (use polling)
//     0b1 ==> Request a hardware interrupt when LVDF = 1

#define  PMC_LVDSC1_LVDACK_MASK      0x40u
#define  PMC_LVDSC1_LVDACK_SHIFT     6
//   Low-Voltage Detect Acknowledge

#define  PMC_LVDSC1_LVDF_MASK        0x80u
#define  PMC_LVDSC1_LVDF_SHIFT       7
//   Low-Voltage Detect Flag
//     0b0 ==> Low-voltage event not detected
//     0b1 ==> Low-voltage event detected

#define  PMC_LVDSC2_LVWV_MASK        0x2u
#define  PMC_LVDSC2_LVWV_SHIFT       0
#define  PMC_LVDSC2_LVWV(x)          (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
//   Low-Voltage Warning Voltage Select
//     0b00 ==> Low trip point selected (VLVW = VLVW1)
//     0b01 ==> Mid 1 trip point selected (VLVW = VLVW2)
//     0b10 ==> Mid 2 trip point selected (VLVW = VLVW3)
//     0b11 ==> High trip point selected (VLVW = VLVW4)

#define  PMC_LVDSC2_LVWIE_MASK       0x20u
#define  PMC_LVDSC2_LVWIE_SHIFT      5
//   Low-Voltage Warning Interrupt Enable
//     0b0 ==> Hardware interrupt disabled (use polling)
//     0b1 ==> Request a hardware interrupt when LVWF = 1

#define  PMC_LVDSC2_LVWACK_MASK      0x40u
#define  PMC_LVDSC2_LVWACK_SHIFT     6
//   Low-Voltage Warning Acknowledge

#define  PMC_LVDSC2_LVWF_MASK        0x80u
#define  PMC_LVDSC2_LVWF_SHIFT       7
//   Low-Voltage Warning Flag
//     0b0 ==> Low-voltage warning event not detected
//     0b1 ==> Low-voltage warning event detected

#define  PMC_REGSC_BGBE_MASK         0x1u
#define  PMC_REGSC_BGBE_SHIFT        0
//   Bandgap Buffer Enable
//     0b0 ==> Bandgap buffer not enabled
//     0b1 ==> Bandgap buffer enabled

#define  PMC_REGSC_REGONS_MASK       0x4u
#define  PMC_REGSC_REGONS_SHIFT      2
//   Regulator In Run Regulation Status
//     0b0 ==> Regulator is in stop regulation or in transition to/from it
//     0b1 ==> Regulator is in run regulation

#define  PMC_REGSC_ACKISO_MASK       0x8u
#define  PMC_REGSC_ACKISO_SHIFT      3
//   Acknowledge Isolation
//     0b0 ==> Peripherals and I/O pads are in normal run state
//     0b1 ==> Certain peripherals and I/O pads are in an isolated and latched state

#define  PMC_REGSC_BGEN_MASK         0x10u
#define  PMC_REGSC_BGEN_SHIFT        4
//   Bandgap Enable In VLPx Operation
//     0b0 ==> Bandgap voltage reference is disabled in VLPx , LLS , and VLLSx modes
//     0b1 ==> Bandgap voltage reference is enabled in VLPx , LLS , and VLLSx modes

#define  PORTA_PCR0_PE_MASK          0x2u
#define  PORTA_PCR0_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR0_MUX_MASK         0x300u
#define  PORTA_PCR0_MUX_SHIFT        8
#define  PORTA_PCR0_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR0_MUX_SHIFT))&PORTA_PCR0_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR0_IRQC_MASK        0x40000u
#define  PORTA_PCR0_IRQC_SHIFT       16
#define  PORTA_PCR0_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR0_IRQC_SHIFT))&PORTA_PCR0_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR0_ISF_MASK         0x1000000u
#define  PORTA_PCR0_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR1_PE_MASK          0x2u
#define  PORTA_PCR1_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR1_MUX_MASK         0x300u
#define  PORTA_PCR1_MUX_SHIFT        8
#define  PORTA_PCR1_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR1_MUX_SHIFT))&PORTA_PCR1_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR1_IRQC_MASK        0x40000u
#define  PORTA_PCR1_IRQC_SHIFT       16
#define  PORTA_PCR1_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR1_IRQC_SHIFT))&PORTA_PCR1_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR1_ISF_MASK         0x1000000u
#define  PORTA_PCR1_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR2_PE_MASK          0x2u
#define  PORTA_PCR2_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR2_MUX_MASK         0x300u
#define  PORTA_PCR2_MUX_SHIFT        8
#define  PORTA_PCR2_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR2_MUX_SHIFT))&PORTA_PCR2_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR2_IRQC_MASK        0x40000u
#define  PORTA_PCR2_IRQC_SHIFT       16
#define  PORTA_PCR2_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR2_IRQC_SHIFT))&PORTA_PCR2_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR2_ISF_MASK         0x1000000u
#define  PORTA_PCR2_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR3_PE_MASK          0x2u
#define  PORTA_PCR3_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR3_MUX_MASK         0x300u
#define  PORTA_PCR3_MUX_SHIFT        8
#define  PORTA_PCR3_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR3_MUX_SHIFT))&PORTA_PCR3_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR3_IRQC_MASK        0x40000u
#define  PORTA_PCR3_IRQC_SHIFT       16
#define  PORTA_PCR3_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR3_IRQC_SHIFT))&PORTA_PCR3_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR3_ISF_MASK         0x1000000u
#define  PORTA_PCR3_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR4_PE_MASK          0x2u
#define  PORTA_PCR4_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR4_MUX_MASK         0x300u
#define  PORTA_PCR4_MUX_SHIFT        8
#define  PORTA_PCR4_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR4_MUX_SHIFT))&PORTA_PCR4_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR4_IRQC_MASK        0x40000u
#define  PORTA_PCR4_IRQC_SHIFT       16
#define  PORTA_PCR4_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR4_IRQC_SHIFT))&PORTA_PCR4_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR4_ISF_MASK         0x1000000u
#define  PORTA_PCR4_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR5_PE_MASK          0x2u
#define  PORTA_PCR5_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR5_MUX_MASK         0x300u
#define  PORTA_PCR5_MUX_SHIFT        8
#define  PORTA_PCR5_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR5_MUX_SHIFT))&PORTA_PCR5_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR5_IRQC_MASK        0x40000u
#define  PORTA_PCR5_IRQC_SHIFT       16
#define  PORTA_PCR5_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR5_IRQC_SHIFT))&PORTA_PCR5_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR5_ISF_MASK         0x1000000u
#define  PORTA_PCR5_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR6_PE_MASK          0x2u
#define  PORTA_PCR6_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR6_MUX_MASK         0x300u
#define  PORTA_PCR6_MUX_SHIFT        8
#define  PORTA_PCR6_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR6_MUX_SHIFT))&PORTA_PCR6_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR6_IRQC_MASK        0x40000u
#define  PORTA_PCR6_IRQC_SHIFT       16
#define  PORTA_PCR6_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR6_IRQC_SHIFT))&PORTA_PCR6_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR6_ISF_MASK         0x1000000u
#define  PORTA_PCR6_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR7_PE_MASK          0x2u
#define  PORTA_PCR7_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR7_MUX_MASK         0x300u
#define  PORTA_PCR7_MUX_SHIFT        8
#define  PORTA_PCR7_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR7_MUX_SHIFT))&PORTA_PCR7_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR7_IRQC_MASK        0x40000u
#define  PORTA_PCR7_IRQC_SHIFT       16
#define  PORTA_PCR7_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR7_IRQC_SHIFT))&PORTA_PCR7_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR7_ISF_MASK         0x1000000u
#define  PORTA_PCR7_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR8_PE_MASK          0x2u
#define  PORTA_PCR8_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR8_MUX_MASK         0x300u
#define  PORTA_PCR8_MUX_SHIFT        8
#define  PORTA_PCR8_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR8_MUX_SHIFT))&PORTA_PCR8_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR8_IRQC_MASK        0x40000u
#define  PORTA_PCR8_IRQC_SHIFT       16
#define  PORTA_PCR8_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR8_IRQC_SHIFT))&PORTA_PCR8_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR8_ISF_MASK         0x1000000u
#define  PORTA_PCR8_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR9_PE_MASK          0x2u
#define  PORTA_PCR9_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR9_MUX_MASK         0x300u
#define  PORTA_PCR9_MUX_SHIFT        8
#define  PORTA_PCR9_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_PCR9_MUX_SHIFT))&PORTA_PCR9_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR9_IRQC_MASK        0x40000u
#define  PORTA_PCR9_IRQC_SHIFT       16
#define  PORTA_PCR9_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR9_IRQC_SHIFT))&PORTA_PCR9_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR9_ISF_MASK         0x1000000u
#define  PORTA_PCR9_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR10_PE_MASK         0x2u
#define  PORTA_PCR10_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR10_MUX_MASK        0x300u
#define  PORTA_PCR10_MUX_SHIFT       8
#define  PORTA_PCR10_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR10_MUX_SHIFT))&PORTA_PCR10_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR10_IRQC_MASK       0x40000u
#define  PORTA_PCR10_IRQC_SHIFT      16
#define  PORTA_PCR10_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR10_IRQC_SHIFT))&PORTA_PCR10_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR10_ISF_MASK        0x1000000u
#define  PORTA_PCR10_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR11_PE_MASK         0x2u
#define  PORTA_PCR11_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR11_MUX_MASK        0x300u
#define  PORTA_PCR11_MUX_SHIFT       8
#define  PORTA_PCR11_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR11_MUX_SHIFT))&PORTA_PCR11_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR11_IRQC_MASK       0x40000u
#define  PORTA_PCR11_IRQC_SHIFT      16
#define  PORTA_PCR11_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR11_IRQC_SHIFT))&PORTA_PCR11_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR11_ISF_MASK        0x1000000u
#define  PORTA_PCR11_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR12_PE_MASK         0x2u
#define  PORTA_PCR12_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR12_MUX_MASK        0x300u
#define  PORTA_PCR12_MUX_SHIFT       8
#define  PORTA_PCR12_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR12_MUX_SHIFT))&PORTA_PCR12_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR12_IRQC_MASK       0x40000u
#define  PORTA_PCR12_IRQC_SHIFT      16
#define  PORTA_PCR12_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR12_IRQC_SHIFT))&PORTA_PCR12_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR12_ISF_MASK        0x1000000u
#define  PORTA_PCR12_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR13_PE_MASK         0x2u
#define  PORTA_PCR13_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR13_MUX_MASK        0x300u
#define  PORTA_PCR13_MUX_SHIFT       8
#define  PORTA_PCR13_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR13_MUX_SHIFT))&PORTA_PCR13_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR13_IRQC_MASK       0x40000u
#define  PORTA_PCR13_IRQC_SHIFT      16
#define  PORTA_PCR13_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR13_IRQC_SHIFT))&PORTA_PCR13_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR13_ISF_MASK        0x1000000u
#define  PORTA_PCR13_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR14_PE_MASK         0x2u
#define  PORTA_PCR14_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR14_MUX_MASK        0x300u
#define  PORTA_PCR14_MUX_SHIFT       8
#define  PORTA_PCR14_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR14_MUX_SHIFT))&PORTA_PCR14_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR14_IRQC_MASK       0x40000u
#define  PORTA_PCR14_IRQC_SHIFT      16
#define  PORTA_PCR14_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR14_IRQC_SHIFT))&PORTA_PCR14_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR14_ISF_MASK        0x1000000u
#define  PORTA_PCR14_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR15_PE_MASK         0x2u
#define  PORTA_PCR15_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR15_MUX_MASK        0x300u
#define  PORTA_PCR15_MUX_SHIFT       8
#define  PORTA_PCR15_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR15_MUX_SHIFT))&PORTA_PCR15_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR15_IRQC_MASK       0x40000u
#define  PORTA_PCR15_IRQC_SHIFT      16
#define  PORTA_PCR15_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR15_IRQC_SHIFT))&PORTA_PCR15_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR15_ISF_MASK        0x1000000u
#define  PORTA_PCR15_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR16_PE_MASK         0x2u
#define  PORTA_PCR16_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR16_MUX_MASK        0x300u
#define  PORTA_PCR16_MUX_SHIFT       8
#define  PORTA_PCR16_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR16_MUX_SHIFT))&PORTA_PCR16_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR16_IRQC_MASK       0x40000u
#define  PORTA_PCR16_IRQC_SHIFT      16
#define  PORTA_PCR16_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR16_IRQC_SHIFT))&PORTA_PCR16_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR16_ISF_MASK        0x1000000u
#define  PORTA_PCR16_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR17_PE_MASK         0x2u
#define  PORTA_PCR17_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR17_MUX_MASK        0x300u
#define  PORTA_PCR17_MUX_SHIFT       8
#define  PORTA_PCR17_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR17_MUX_SHIFT))&PORTA_PCR17_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR17_IRQC_MASK       0x40000u
#define  PORTA_PCR17_IRQC_SHIFT      16
#define  PORTA_PCR17_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR17_IRQC_SHIFT))&PORTA_PCR17_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR17_ISF_MASK        0x1000000u
#define  PORTA_PCR17_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR18_PE_MASK         0x2u
#define  PORTA_PCR18_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR18_MUX_MASK        0x300u
#define  PORTA_PCR18_MUX_SHIFT       8
#define  PORTA_PCR18_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR18_MUX_SHIFT))&PORTA_PCR18_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR18_IRQC_MASK       0x40000u
#define  PORTA_PCR18_IRQC_SHIFT      16
#define  PORTA_PCR18_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR18_IRQC_SHIFT))&PORTA_PCR18_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR18_ISF_MASK        0x1000000u
#define  PORTA_PCR18_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR19_PE_MASK         0x2u
#define  PORTA_PCR19_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR19_MUX_MASK        0x300u
#define  PORTA_PCR19_MUX_SHIFT       8
#define  PORTA_PCR19_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR19_MUX_SHIFT))&PORTA_PCR19_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR19_IRQC_MASK       0x40000u
#define  PORTA_PCR19_IRQC_SHIFT      16
#define  PORTA_PCR19_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR19_IRQC_SHIFT))&PORTA_PCR19_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR19_ISF_MASK        0x1000000u
#define  PORTA_PCR19_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR20_PE_MASK         0x2u
#define  PORTA_PCR20_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR20_MUX_MASK        0x300u
#define  PORTA_PCR20_MUX_SHIFT       8
#define  PORTA_PCR20_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR20_MUX_SHIFT))&PORTA_PCR20_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR20_IRQC_MASK       0x40000u
#define  PORTA_PCR20_IRQC_SHIFT      16
#define  PORTA_PCR20_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR20_IRQC_SHIFT))&PORTA_PCR20_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR20_ISF_MASK        0x1000000u
#define  PORTA_PCR20_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR21_PE_MASK         0x2u
#define  PORTA_PCR21_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR21_MUX_MASK        0x300u
#define  PORTA_PCR21_MUX_SHIFT       8
#define  PORTA_PCR21_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR21_MUX_SHIFT))&PORTA_PCR21_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR21_IRQC_MASK       0x40000u
#define  PORTA_PCR21_IRQC_SHIFT      16
#define  PORTA_PCR21_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR21_IRQC_SHIFT))&PORTA_PCR21_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR21_ISF_MASK        0x1000000u
#define  PORTA_PCR21_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR22_PE_MASK         0x2u
#define  PORTA_PCR22_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR22_MUX_MASK        0x300u
#define  PORTA_PCR22_MUX_SHIFT       8
#define  PORTA_PCR22_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR22_MUX_SHIFT))&PORTA_PCR22_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR22_IRQC_MASK       0x40000u
#define  PORTA_PCR22_IRQC_SHIFT      16
#define  PORTA_PCR22_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR22_IRQC_SHIFT))&PORTA_PCR22_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR22_ISF_MASK        0x1000000u
#define  PORTA_PCR22_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR23_PE_MASK         0x2u
#define  PORTA_PCR23_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR23_MUX_MASK        0x300u
#define  PORTA_PCR23_MUX_SHIFT       8
#define  PORTA_PCR23_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR23_MUX_SHIFT))&PORTA_PCR23_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR23_IRQC_MASK       0x40000u
#define  PORTA_PCR23_IRQC_SHIFT      16
#define  PORTA_PCR23_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR23_IRQC_SHIFT))&PORTA_PCR23_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR23_ISF_MASK        0x1000000u
#define  PORTA_PCR23_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR24_PE_MASK         0x2u
#define  PORTA_PCR24_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR24_MUX_MASK        0x300u
#define  PORTA_PCR24_MUX_SHIFT       8
#define  PORTA_PCR24_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR24_MUX_SHIFT))&PORTA_PCR24_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR24_IRQC_MASK       0x40000u
#define  PORTA_PCR24_IRQC_SHIFT      16
#define  PORTA_PCR24_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR24_IRQC_SHIFT))&PORTA_PCR24_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR24_ISF_MASK        0x1000000u
#define  PORTA_PCR24_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR25_PE_MASK         0x2u
#define  PORTA_PCR25_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR25_MUX_MASK        0x300u
#define  PORTA_PCR25_MUX_SHIFT       8
#define  PORTA_PCR25_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR25_MUX_SHIFT))&PORTA_PCR25_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR25_IRQC_MASK       0x40000u
#define  PORTA_PCR25_IRQC_SHIFT      16
#define  PORTA_PCR25_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR25_IRQC_SHIFT))&PORTA_PCR25_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR25_ISF_MASK        0x1000000u
#define  PORTA_PCR25_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR26_PE_MASK         0x2u
#define  PORTA_PCR26_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR26_MUX_MASK        0x300u
#define  PORTA_PCR26_MUX_SHIFT       8
#define  PORTA_PCR26_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR26_MUX_SHIFT))&PORTA_PCR26_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR26_IRQC_MASK       0x40000u
#define  PORTA_PCR26_IRQC_SHIFT      16
#define  PORTA_PCR26_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR26_IRQC_SHIFT))&PORTA_PCR26_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR26_ISF_MASK        0x1000000u
#define  PORTA_PCR26_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR27_PE_MASK         0x2u
#define  PORTA_PCR27_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR27_MUX_MASK        0x300u
#define  PORTA_PCR27_MUX_SHIFT       8
#define  PORTA_PCR27_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR27_MUX_SHIFT))&PORTA_PCR27_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR27_IRQC_MASK       0x40000u
#define  PORTA_PCR27_IRQC_SHIFT      16
#define  PORTA_PCR27_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR27_IRQC_SHIFT))&PORTA_PCR27_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR27_ISF_MASK        0x1000000u
#define  PORTA_PCR27_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR28_PE_MASK         0x2u
#define  PORTA_PCR28_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR28_MUX_MASK        0x300u
#define  PORTA_PCR28_MUX_SHIFT       8
#define  PORTA_PCR28_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR28_MUX_SHIFT))&PORTA_PCR28_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR28_IRQC_MASK       0x40000u
#define  PORTA_PCR28_IRQC_SHIFT      16
#define  PORTA_PCR28_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR28_IRQC_SHIFT))&PORTA_PCR28_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR28_ISF_MASK        0x1000000u
#define  PORTA_PCR28_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR29_PE_MASK         0x2u
#define  PORTA_PCR29_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR29_MUX_MASK        0x300u
#define  PORTA_PCR29_MUX_SHIFT       8
#define  PORTA_PCR29_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR29_MUX_SHIFT))&PORTA_PCR29_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR29_IRQC_MASK       0x40000u
#define  PORTA_PCR29_IRQC_SHIFT      16
#define  PORTA_PCR29_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR29_IRQC_SHIFT))&PORTA_PCR29_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR29_ISF_MASK        0x1000000u
#define  PORTA_PCR29_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR30_PE_MASK         0x2u
#define  PORTA_PCR30_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR30_MUX_MASK        0x300u
#define  PORTA_PCR30_MUX_SHIFT       8
#define  PORTA_PCR30_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR30_MUX_SHIFT))&PORTA_PCR30_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR30_IRQC_MASK       0x40000u
#define  PORTA_PCR30_IRQC_SHIFT      16
#define  PORTA_PCR30_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR30_IRQC_SHIFT))&PORTA_PCR30_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR30_ISF_MASK        0x1000000u
#define  PORTA_PCR30_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_PCR31_PE_MASK         0x2u
#define  PORTA_PCR31_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTA_PCR31_MUX_MASK        0x300u
#define  PORTA_PCR31_MUX_SHIFT       8
#define  PORTA_PCR31_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTA_PCR31_MUX_SHIFT))&PORTA_PCR31_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTA_PCR31_IRQC_MASK       0x40000u
#define  PORTA_PCR31_IRQC_SHIFT      16
#define  PORTA_PCR31_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_PCR31_IRQC_SHIFT))&PORTA_PCR31_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTA_PCR31_ISF_MASK        0x1000000u
#define  PORTA_PCR31_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTA_GPCLR_GPWD_MASK       0x10u
#define  PORTA_GPCLR_GPWD_SHIFT      0
#define  PORTA_GPCLR_GPWD(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_GPCLR_GPWD_SHIFT))&PORTA_GPCLR_GPWD_MASK)
//   Global Pin Write Data

#define  PORTA_GPCLR_GPWE_MASK       0x100000u
#define  PORTA_GPCLR_GPWE_SHIFT      16
#define  PORTA_GPCLR_GPWE(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_GPCLR_GPWE_SHIFT))&PORTA_GPCLR_GPWE_MASK)
//   Global Pin Write Enable
//     0b0 ==> Corresponding Pin Control Register is not updated with the value in GPWD.
//     0b1 ==> Corresponding Pin Control Register is updated with the value in GPWD.

#define  PORTA_GPCHR_GPWD_MASK       0x10u
#define  PORTA_GPCHR_GPWD_SHIFT      0
#define  PORTA_GPCHR_GPWD(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_GPCHR_GPWD_SHIFT))&PORTA_GPCHR_GPWD_MASK)
//   Global Pin Write Data

#define  PORTA_GPCHR_GPWE_MASK       0x100000u
#define  PORTA_GPCHR_GPWE_SHIFT      16
#define  PORTA_GPCHR_GPWE(x)         (((uint32_t)(((uint32_t)(x))<<PORTA_GPCHR_GPWE_SHIFT))&PORTA_GPCHR_GPWE_MASK)
//   Global Pin Write Enable
//     0b0 ==> Corresponding Pin Control Register is not updated with the value in GPWD.
//     0b1 ==> Corresponding Pin Control Register is updated with the value in GPWD.

#define  PORTA_ISFR_ISF_MASK         0x20u
#define  PORTA_ISFR_ISF_SHIFT        0
#define  PORTA_ISFR_ISF(x)           (((uint32_t)(((uint32_t)(x))<<PORTA_ISFR_ISF_SHIFT))&PORTA_ISFR_ISF_MASK)
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR0_PE_MASK          0x2u
#define  PORTB_PCR0_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR0_MUX_MASK         0x300u
#define  PORTB_PCR0_MUX_SHIFT        8
#define  PORTB_PCR0_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR0_MUX_SHIFT))&PORTB_PCR0_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR0_IRQC_MASK        0x40000u
#define  PORTB_PCR0_IRQC_SHIFT       16
#define  PORTB_PCR0_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR0_IRQC_SHIFT))&PORTB_PCR0_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR0_ISF_MASK         0x1000000u
#define  PORTB_PCR0_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR1_PE_MASK          0x2u
#define  PORTB_PCR1_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR1_MUX_MASK         0x300u
#define  PORTB_PCR1_MUX_SHIFT        8
#define  PORTB_PCR1_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR1_MUX_SHIFT))&PORTB_PCR1_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR1_IRQC_MASK        0x40000u
#define  PORTB_PCR1_IRQC_SHIFT       16
#define  PORTB_PCR1_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR1_IRQC_SHIFT))&PORTB_PCR1_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR1_ISF_MASK         0x1000000u
#define  PORTB_PCR1_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR2_PE_MASK          0x2u
#define  PORTB_PCR2_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR2_MUX_MASK         0x300u
#define  PORTB_PCR2_MUX_SHIFT        8
#define  PORTB_PCR2_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR2_MUX_SHIFT))&PORTB_PCR2_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR2_IRQC_MASK        0x40000u
#define  PORTB_PCR2_IRQC_SHIFT       16
#define  PORTB_PCR2_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR2_IRQC_SHIFT))&PORTB_PCR2_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR2_ISF_MASK         0x1000000u
#define  PORTB_PCR2_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR3_PE_MASK          0x2u
#define  PORTB_PCR3_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR3_MUX_MASK         0x300u
#define  PORTB_PCR3_MUX_SHIFT        8
#define  PORTB_PCR3_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR3_MUX_SHIFT))&PORTB_PCR3_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR3_IRQC_MASK        0x40000u
#define  PORTB_PCR3_IRQC_SHIFT       16
#define  PORTB_PCR3_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR3_IRQC_SHIFT))&PORTB_PCR3_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR3_ISF_MASK         0x1000000u
#define  PORTB_PCR3_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR4_PE_MASK          0x2u
#define  PORTB_PCR4_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR4_MUX_MASK         0x300u
#define  PORTB_PCR4_MUX_SHIFT        8
#define  PORTB_PCR4_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR4_MUX_SHIFT))&PORTB_PCR4_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR4_IRQC_MASK        0x40000u
#define  PORTB_PCR4_IRQC_SHIFT       16
#define  PORTB_PCR4_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR4_IRQC_SHIFT))&PORTB_PCR4_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR4_ISF_MASK         0x1000000u
#define  PORTB_PCR4_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR5_PE_MASK          0x2u
#define  PORTB_PCR5_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR5_MUX_MASK         0x300u
#define  PORTB_PCR5_MUX_SHIFT        8
#define  PORTB_PCR5_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR5_MUX_SHIFT))&PORTB_PCR5_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR5_IRQC_MASK        0x40000u
#define  PORTB_PCR5_IRQC_SHIFT       16
#define  PORTB_PCR5_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR5_IRQC_SHIFT))&PORTB_PCR5_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR5_ISF_MASK         0x1000000u
#define  PORTB_PCR5_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR6_PE_MASK          0x2u
#define  PORTB_PCR6_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR6_MUX_MASK         0x300u
#define  PORTB_PCR6_MUX_SHIFT        8
#define  PORTB_PCR6_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR6_MUX_SHIFT))&PORTB_PCR6_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR6_IRQC_MASK        0x40000u
#define  PORTB_PCR6_IRQC_SHIFT       16
#define  PORTB_PCR6_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR6_IRQC_SHIFT))&PORTB_PCR6_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR6_ISF_MASK         0x1000000u
#define  PORTB_PCR6_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR7_PE_MASK          0x2u
#define  PORTB_PCR7_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR7_MUX_MASK         0x300u
#define  PORTB_PCR7_MUX_SHIFT        8
#define  PORTB_PCR7_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR7_MUX_SHIFT))&PORTB_PCR7_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR7_IRQC_MASK        0x40000u
#define  PORTB_PCR7_IRQC_SHIFT       16
#define  PORTB_PCR7_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR7_IRQC_SHIFT))&PORTB_PCR7_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR7_ISF_MASK         0x1000000u
#define  PORTB_PCR7_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR8_PE_MASK          0x2u
#define  PORTB_PCR8_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR8_MUX_MASK         0x300u
#define  PORTB_PCR8_MUX_SHIFT        8
#define  PORTB_PCR8_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR8_MUX_SHIFT))&PORTB_PCR8_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR8_IRQC_MASK        0x40000u
#define  PORTB_PCR8_IRQC_SHIFT       16
#define  PORTB_PCR8_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR8_IRQC_SHIFT))&PORTB_PCR8_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR8_ISF_MASK         0x1000000u
#define  PORTB_PCR8_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR9_PE_MASK          0x2u
#define  PORTB_PCR9_PE_SHIFT         1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR9_MUX_MASK         0x300u
#define  PORTB_PCR9_MUX_SHIFT        8
#define  PORTB_PCR9_MUX(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_PCR9_MUX_SHIFT))&PORTB_PCR9_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR9_IRQC_MASK        0x40000u
#define  PORTB_PCR9_IRQC_SHIFT       16
#define  PORTB_PCR9_IRQC(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR9_IRQC_SHIFT))&PORTB_PCR9_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR9_ISF_MASK         0x1000000u
#define  PORTB_PCR9_ISF_SHIFT        24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR10_PE_MASK         0x2u
#define  PORTB_PCR10_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR10_MUX_MASK        0x300u
#define  PORTB_PCR10_MUX_SHIFT       8
#define  PORTB_PCR10_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR10_MUX_SHIFT))&PORTB_PCR10_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR10_IRQC_MASK       0x40000u
#define  PORTB_PCR10_IRQC_SHIFT      16
#define  PORTB_PCR10_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR10_IRQC_SHIFT))&PORTB_PCR10_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR10_ISF_MASK        0x1000000u
#define  PORTB_PCR10_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR11_PE_MASK         0x2u
#define  PORTB_PCR11_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR11_MUX_MASK        0x300u
#define  PORTB_PCR11_MUX_SHIFT       8
#define  PORTB_PCR11_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR11_MUX_SHIFT))&PORTB_PCR11_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR11_IRQC_MASK       0x40000u
#define  PORTB_PCR11_IRQC_SHIFT      16
#define  PORTB_PCR11_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR11_IRQC_SHIFT))&PORTB_PCR11_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR11_ISF_MASK        0x1000000u
#define  PORTB_PCR11_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR12_PE_MASK         0x2u
#define  PORTB_PCR12_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR12_MUX_MASK        0x300u
#define  PORTB_PCR12_MUX_SHIFT       8
#define  PORTB_PCR12_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR12_MUX_SHIFT))&PORTB_PCR12_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR12_IRQC_MASK       0x40000u
#define  PORTB_PCR12_IRQC_SHIFT      16
#define  PORTB_PCR12_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR12_IRQC_SHIFT))&PORTB_PCR12_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR12_ISF_MASK        0x1000000u
#define  PORTB_PCR12_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR13_PE_MASK         0x2u
#define  PORTB_PCR13_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR13_MUX_MASK        0x300u
#define  PORTB_PCR13_MUX_SHIFT       8
#define  PORTB_PCR13_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR13_MUX_SHIFT))&PORTB_PCR13_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR13_IRQC_MASK       0x40000u
#define  PORTB_PCR13_IRQC_SHIFT      16
#define  PORTB_PCR13_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR13_IRQC_SHIFT))&PORTB_PCR13_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR13_ISF_MASK        0x1000000u
#define  PORTB_PCR13_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR14_PE_MASK         0x2u
#define  PORTB_PCR14_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR14_MUX_MASK        0x300u
#define  PORTB_PCR14_MUX_SHIFT       8
#define  PORTB_PCR14_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR14_MUX_SHIFT))&PORTB_PCR14_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR14_IRQC_MASK       0x40000u
#define  PORTB_PCR14_IRQC_SHIFT      16
#define  PORTB_PCR14_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR14_IRQC_SHIFT))&PORTB_PCR14_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR14_ISF_MASK        0x1000000u
#define  PORTB_PCR14_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR15_PE_MASK         0x2u
#define  PORTB_PCR15_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR15_MUX_MASK        0x300u
#define  PORTB_PCR15_MUX_SHIFT       8
#define  PORTB_PCR15_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR15_MUX_SHIFT))&PORTB_PCR15_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR15_IRQC_MASK       0x40000u
#define  PORTB_PCR15_IRQC_SHIFT      16
#define  PORTB_PCR15_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR15_IRQC_SHIFT))&PORTB_PCR15_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR15_ISF_MASK        0x1000000u
#define  PORTB_PCR15_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR16_PE_MASK         0x2u
#define  PORTB_PCR16_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR16_MUX_MASK        0x300u
#define  PORTB_PCR16_MUX_SHIFT       8
#define  PORTB_PCR16_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR16_MUX_SHIFT))&PORTB_PCR16_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR16_IRQC_MASK       0x40000u
#define  PORTB_PCR16_IRQC_SHIFT      16
#define  PORTB_PCR16_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR16_IRQC_SHIFT))&PORTB_PCR16_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR16_ISF_MASK        0x1000000u
#define  PORTB_PCR16_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR17_PE_MASK         0x2u
#define  PORTB_PCR17_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR17_MUX_MASK        0x300u
#define  PORTB_PCR17_MUX_SHIFT       8
#define  PORTB_PCR17_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR17_MUX_SHIFT))&PORTB_PCR17_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR17_IRQC_MASK       0x40000u
#define  PORTB_PCR17_IRQC_SHIFT      16
#define  PORTB_PCR17_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR17_IRQC_SHIFT))&PORTB_PCR17_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR17_ISF_MASK        0x1000000u
#define  PORTB_PCR17_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR18_PE_MASK         0x2u
#define  PORTB_PCR18_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR18_MUX_MASK        0x300u
#define  PORTB_PCR18_MUX_SHIFT       8
#define  PORTB_PCR18_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR18_MUX_SHIFT))&PORTB_PCR18_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR18_IRQC_MASK       0x40000u
#define  PORTB_PCR18_IRQC_SHIFT      16
#define  PORTB_PCR18_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR18_IRQC_SHIFT))&PORTB_PCR18_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR18_ISF_MASK        0x1000000u
#define  PORTB_PCR18_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR19_PE_MASK         0x2u
#define  PORTB_PCR19_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR19_MUX_MASK        0x300u
#define  PORTB_PCR19_MUX_SHIFT       8
#define  PORTB_PCR19_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR19_MUX_SHIFT))&PORTB_PCR19_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR19_IRQC_MASK       0x40000u
#define  PORTB_PCR19_IRQC_SHIFT      16
#define  PORTB_PCR19_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR19_IRQC_SHIFT))&PORTB_PCR19_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR19_ISF_MASK        0x1000000u
#define  PORTB_PCR19_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR20_PE_MASK         0x2u
#define  PORTB_PCR20_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR20_MUX_MASK        0x300u
#define  PORTB_PCR20_MUX_SHIFT       8
#define  PORTB_PCR20_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR20_MUX_SHIFT))&PORTB_PCR20_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR20_IRQC_MASK       0x40000u
#define  PORTB_PCR20_IRQC_SHIFT      16
#define  PORTB_PCR20_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR20_IRQC_SHIFT))&PORTB_PCR20_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR20_ISF_MASK        0x1000000u
#define  PORTB_PCR20_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR21_PE_MASK         0x2u
#define  PORTB_PCR21_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR21_MUX_MASK        0x300u
#define  PORTB_PCR21_MUX_SHIFT       8
#define  PORTB_PCR21_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR21_MUX_SHIFT))&PORTB_PCR21_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR21_IRQC_MASK       0x40000u
#define  PORTB_PCR21_IRQC_SHIFT      16
#define  PORTB_PCR21_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR21_IRQC_SHIFT))&PORTB_PCR21_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR21_ISF_MASK        0x1000000u
#define  PORTB_PCR21_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR22_PE_MASK         0x2u
#define  PORTB_PCR22_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR22_MUX_MASK        0x300u
#define  PORTB_PCR22_MUX_SHIFT       8
#define  PORTB_PCR22_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR22_MUX_SHIFT))&PORTB_PCR22_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR22_IRQC_MASK       0x40000u
#define  PORTB_PCR22_IRQC_SHIFT      16
#define  PORTB_PCR22_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR22_IRQC_SHIFT))&PORTB_PCR22_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR22_ISF_MASK        0x1000000u
#define  PORTB_PCR22_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR23_PE_MASK         0x2u
#define  PORTB_PCR23_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR23_MUX_MASK        0x300u
#define  PORTB_PCR23_MUX_SHIFT       8
#define  PORTB_PCR23_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR23_MUX_SHIFT))&PORTB_PCR23_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR23_IRQC_MASK       0x40000u
#define  PORTB_PCR23_IRQC_SHIFT      16
#define  PORTB_PCR23_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR23_IRQC_SHIFT))&PORTB_PCR23_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR23_ISF_MASK        0x1000000u
#define  PORTB_PCR23_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR24_PE_MASK         0x2u
#define  PORTB_PCR24_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR24_MUX_MASK        0x300u
#define  PORTB_PCR24_MUX_SHIFT       8
#define  PORTB_PCR24_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR24_MUX_SHIFT))&PORTB_PCR24_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR24_IRQC_MASK       0x40000u
#define  PORTB_PCR24_IRQC_SHIFT      16
#define  PORTB_PCR24_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR24_IRQC_SHIFT))&PORTB_PCR24_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR24_ISF_MASK        0x1000000u
#define  PORTB_PCR24_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR25_PE_MASK         0x2u
#define  PORTB_PCR25_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR25_MUX_MASK        0x300u
#define  PORTB_PCR25_MUX_SHIFT       8
#define  PORTB_PCR25_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR25_MUX_SHIFT))&PORTB_PCR25_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR25_IRQC_MASK       0x40000u
#define  PORTB_PCR25_IRQC_SHIFT      16
#define  PORTB_PCR25_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR25_IRQC_SHIFT))&PORTB_PCR25_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR25_ISF_MASK        0x1000000u
#define  PORTB_PCR25_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR26_PE_MASK         0x2u
#define  PORTB_PCR26_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR26_MUX_MASK        0x300u
#define  PORTB_PCR26_MUX_SHIFT       8
#define  PORTB_PCR26_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR26_MUX_SHIFT))&PORTB_PCR26_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR26_IRQC_MASK       0x40000u
#define  PORTB_PCR26_IRQC_SHIFT      16
#define  PORTB_PCR26_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR26_IRQC_SHIFT))&PORTB_PCR26_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR26_ISF_MASK        0x1000000u
#define  PORTB_PCR26_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR27_PE_MASK         0x2u
#define  PORTB_PCR27_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR27_MUX_MASK        0x300u
#define  PORTB_PCR27_MUX_SHIFT       8
#define  PORTB_PCR27_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR27_MUX_SHIFT))&PORTB_PCR27_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR27_IRQC_MASK       0x40000u
#define  PORTB_PCR27_IRQC_SHIFT      16
#define  PORTB_PCR27_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR27_IRQC_SHIFT))&PORTB_PCR27_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR27_ISF_MASK        0x1000000u
#define  PORTB_PCR27_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR28_PE_MASK         0x2u
#define  PORTB_PCR28_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR28_MUX_MASK        0x300u
#define  PORTB_PCR28_MUX_SHIFT       8
#define  PORTB_PCR28_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR28_MUX_SHIFT))&PORTB_PCR28_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR28_IRQC_MASK       0x40000u
#define  PORTB_PCR28_IRQC_SHIFT      16
#define  PORTB_PCR28_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR28_IRQC_SHIFT))&PORTB_PCR28_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR28_ISF_MASK        0x1000000u
#define  PORTB_PCR28_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR29_PE_MASK         0x2u
#define  PORTB_PCR29_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR29_MUX_MASK        0x300u
#define  PORTB_PCR29_MUX_SHIFT       8
#define  PORTB_PCR29_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR29_MUX_SHIFT))&PORTB_PCR29_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR29_IRQC_MASK       0x40000u
#define  PORTB_PCR29_IRQC_SHIFT      16
#define  PORTB_PCR29_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR29_IRQC_SHIFT))&PORTB_PCR29_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR29_ISF_MASK        0x1000000u
#define  PORTB_PCR29_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR30_PE_MASK         0x2u
#define  PORTB_PCR30_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR30_MUX_MASK        0x300u
#define  PORTB_PCR30_MUX_SHIFT       8
#define  PORTB_PCR30_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR30_MUX_SHIFT))&PORTB_PCR30_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR30_IRQC_MASK       0x40000u
#define  PORTB_PCR30_IRQC_SHIFT      16
#define  PORTB_PCR30_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR30_IRQC_SHIFT))&PORTB_PCR30_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR30_ISF_MASK        0x1000000u
#define  PORTB_PCR30_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_PCR31_PE_MASK         0x2u
#define  PORTB_PCR31_PE_SHIFT        1
//   Pull Enable
//     0b0 ==> Internal pullup or pulldown resistor is not enabled on the corresponding pin.
//     0b1 ==> Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.

#define  PORTB_PCR31_MUX_MASK        0x300u
#define  PORTB_PCR31_MUX_SHIFT       8
#define  PORTB_PCR31_MUX(x)          (((uint32_t)(((uint32_t)(x))<<PORTB_PCR31_MUX_SHIFT))&PORTB_PCR31_MUX_MASK)
//   Pin Mux Control
//     0b000 ==> Pin disabled (analog).
//     0b001 ==> Alternative 1 (GPIO).
//     0b010 ==> Alternative 2 (chip-specific).
//     0b011 ==> Alternative 3 (chip-specific).
//     0b100 ==> Alternative 4 (chip-specific).
//     0b101 ==> Alternative 5 (chip-specific).
//     0b110 ==> Alternative 6 (chip-specific).
//     0b111 ==> Alternative 7 (chip-specific).

#define  PORTB_PCR31_IRQC_MASK       0x40000u
#define  PORTB_PCR31_IRQC_SHIFT      16
#define  PORTB_PCR31_IRQC(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_PCR31_IRQC_SHIFT))&PORTB_PCR31_IRQC_MASK)
//   Interrupt Configuration
//     0b0000 ==> Interrupt/DMA request disabled.
//     0b0001 ==> DMA request on rising edge.
//     0b0010 ==> DMA request on falling edge.
//     0b0011 ==> DMA request on either edge.
//     0b0100 ==> Reserved.
//     0b1000 ==> Interrupt when logic zero.
//     0b1001 ==> Interrupt on rising edge.
//     0b1010 ==> Interrupt on falling edge.
//     0b1011 ==> Interrupt on either edge.
//     0b1100 ==> Interrupt when logic one.

#define  PORTB_PCR31_ISF_MASK        0x1000000u
#define  PORTB_PCR31_ISF_SHIFT       24
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  PORTB_GPCLR_GPWD_MASK       0x10u
#define  PORTB_GPCLR_GPWD_SHIFT      0
#define  PORTB_GPCLR_GPWD(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_GPCLR_GPWD_SHIFT))&PORTB_GPCLR_GPWD_MASK)
//   Global Pin Write Data

#define  PORTB_GPCLR_GPWE_MASK       0x100000u
#define  PORTB_GPCLR_GPWE_SHIFT      16
#define  PORTB_GPCLR_GPWE(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_GPCLR_GPWE_SHIFT))&PORTB_GPCLR_GPWE_MASK)
//   Global Pin Write Enable
//     0b0 ==> Corresponding Pin Control Register is not updated with the value in GPWD.
//     0b1 ==> Corresponding Pin Control Register is updated with the value in GPWD.

#define  PORTB_GPCHR_GPWD_MASK       0x10u
#define  PORTB_GPCHR_GPWD_SHIFT      0
#define  PORTB_GPCHR_GPWD(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_GPCHR_GPWD_SHIFT))&PORTB_GPCHR_GPWD_MASK)
//   Global Pin Write Data

#define  PORTB_GPCHR_GPWE_MASK       0x100000u
#define  PORTB_GPCHR_GPWE_SHIFT      16
#define  PORTB_GPCHR_GPWE(x)         (((uint32_t)(((uint32_t)(x))<<PORTB_GPCHR_GPWE_SHIFT))&PORTB_GPCHR_GPWE_MASK)
//   Global Pin Write Enable
//     0b0 ==> Corresponding Pin Control Register is not updated with the value in GPWD.
//     0b1 ==> Corresponding Pin Control Register is updated with the value in GPWD.

#define  PORTB_ISFR_ISF_MASK         0x20u
#define  PORTB_ISFR_ISF_SHIFT        0
#define  PORTB_ISFR_ISF(x)           (((uint32_t)(((uint32_t)(x))<<PORTB_ISFR_ISF_SHIFT))&PORTB_ISFR_ISF_MASK)
//   Interrupt Status Flag
//     0b0 ==> Configured interrupt is not detected.
//     0b1 ==> Configured interrupt is detected. If the pin is configured to generate a DMA request, then the corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the flag remains set until a logic one is written to the flag. If the pin is configured for a level sensitive interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.

#define  RCM_SRS0_WAKEUP_MASK        0x1u
#define  RCM_SRS0_WAKEUP_SHIFT       0
//   Low Leakage Wakeup Reset
//     0b0 ==> Reset not caused by LLWU module wakeup source
//     0b1 ==> Reset caused by LLWU module wakeup source

#define  RCM_SRS0_LVD_MASK           0x2u
#define  RCM_SRS0_LVD_SHIFT          1
//   Low-Voltage Detect Reset
//     0b0 ==> Reset not caused by LVD trip or POR
//     0b1 ==> Reset caused by LVD trip or POR

#define  RCM_SRS0_LOC_MASK           0x4u
#define  RCM_SRS0_LOC_SHIFT          2
//   Loss-of-Clock Reset
//     0b0 ==> Reset not caused by a loss of external clock.
//     0b1 ==> Reset caused by a loss of external clock.

#define  RCM_SRS0_WDOG_MASK          0x20u
#define  RCM_SRS0_WDOG_SHIFT         5
//   Watchdog
//     0b0 ==> Reset not caused by watchdog timeout
//     0b1 ==> Reset caused by watchdog timeout

#define  RCM_SRS0_PIN_MASK           0x40u
#define  RCM_SRS0_PIN_SHIFT          6
//   External Reset Pin
//     0b0 ==> Reset not caused by external reset pin
//     0b1 ==> Reset caused by external reset pin

#define  RCM_SRS0_POR_MASK           0x80u
#define  RCM_SRS0_POR_SHIFT          7
//   Power-On Reset
//     0b0 ==> Reset not caused by POR
//     0b1 ==> Reset caused by POR

#define  RCM_SRS1_LOCKUP_MASK        0x2u
#define  RCM_SRS1_LOCKUP_SHIFT       1
//   Core Lockup
//     0b0 ==> Reset not caused by core LOCKUP event
//     0b1 ==> Reset caused by core LOCKUP event

#define  RCM_SRS1_SW_MASK            0x4u
#define  RCM_SRS1_SW_SHIFT           2
//   Software
//     0b0 ==> Reset not caused by software setting of SYSRESETREQ bit
//     0b1 ==> Reset caused by software setting of SYSRESETREQ bit

#define  RCM_SRS1_MDM_AP_MASK        0x8u
#define  RCM_SRS1_MDM_AP_SHIFT       3
//   MDM-AP System Reset Request
//     0b0 ==> Reset not caused by host debugger system setting of the System Reset Request bit
//     0b1 ==> Reset caused by host debugger system setting of the System Reset Request bit

#define  RCM_SRS1_SACKERR_MASK       0x20u
#define  RCM_SRS1_SACKERR_SHIFT      5
//   Stop Mode Acknowledge Error Reset
//     0b0 ==> Reset not caused by peripheral failure to acknowledge attempt to enter stop mode
//     0b1 ==> Reset caused by peripheral failure to acknowledge attempt to enter stop mode

#define  RCM_RPFC_RSTFLTSRW_MASK     0x2u
#define  RCM_RPFC_RSTFLTSRW_SHIFT    0
#define  RCM_RPFC_RSTFLTSRW(x)       (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK)
//   Reset Pin Filter Select in Run and Wait Modes
//     0b00 ==> All filtering disabled
//     0b01 ==> Bus clock filter enabled for normal operation
//     0b10 ==> LPO clock filter enabled for normal operation
//     0b11 ==> Reserved

#define  RCM_RPFC_RSTFLTSS_MASK      0x4u
#define  RCM_RPFC_RSTFLTSS_SHIFT     2
//   Reset Pin Filter Select in Stop Mode
//     0b0 ==> All filtering disabled
//     0b1 ==> LPO clock filter enabled

#define  RCM_RPFW_RSTFLTSEL_MASK     0x5u
#define  RCM_RPFW_RSTFLTSEL_SHIFT    0
#define  RCM_RPFW_RSTFLTSEL(x)       (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK)
//   Reset Pin Filter Bus Clock Select
//     0b00000 ==> Bus clock filter count is 1
//     0b00001 ==> Bus clock filter count is 2
//     0b00010 ==> Bus clock filter count is 3
//     0b00011 ==> Bus clock filter count is 4
//     0b00100 ==> Bus clock filter count is 5
//     0b00101 ==> Bus clock filter count is 6
//     0b00110 ==> Bus clock filter count is 7
//     0b00111 ==> Bus clock filter count is 8
//     0b01000 ==> Bus clock filter count is 9
//     0b01001 ==> Bus clock filter count is 10
//     0b01010 ==> Bus clock filter count is 11
//     0b01011 ==> Bus clock filter count is 12
//     0b01100 ==> Bus clock filter count is 13
//     0b01101 ==> Bus clock filter count is 14
//     0b01110 ==> Bus clock filter count is 15
//     0b01111 ==> Bus clock filter count is 16
//     0b10000 ==> Bus clock filter count is 17
//     0b10001 ==> Bus clock filter count is 18
//     0b10010 ==> Bus clock filter count is 19
//     0b10011 ==> Bus clock filter count is 20
//     0b10100 ==> Bus clock filter count is 21
//     0b10101 ==> Bus clock filter count is 22
//     0b10110 ==> Bus clock filter count is 23
//     0b10111 ==> Bus clock filter count is 24
//     0b11000 ==> Bus clock filter count is 25
//     0b11001 ==> Bus clock filter count is 26
//     0b11010 ==> Bus clock filter count is 27
//     0b11011 ==> Bus clock filter count is 28
//     0b11100 ==> Bus clock filter count is 29
//     0b11101 ==> Bus clock filter count is 30
//     0b11110 ==> Bus clock filter count is 31
//     0b11111 ==> Bus clock filter count is 32

#define  RTC_TSR_TSR_MASK            0x20u
#define  RTC_TSR_TSR_SHIFT           0
#define  RTC_TSR_TSR(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK)
//   Time Seconds Register

#define  RTC_TPR_TPR_MASK            0x10u
#define  RTC_TPR_TPR_SHIFT           0
#define  RTC_TPR_TPR(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK)
//   Time Prescaler Register

#define  RTC_TAR_TAR_MASK            0x20u
#define  RTC_TAR_TAR_SHIFT           0
#define  RTC_TAR_TAR(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK)
//   Time Alarm Register

#define  RTC_TCR_TCR_MASK            0x8u
#define  RTC_TCR_TCR_SHIFT           0
#define  RTC_TCR_TCR(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK)
//   Time Compensation Register
//     0b10000000 ==> Time Prescaler Register overflows every 32896 clock cycles.
//     0b11111111 ==> Time Prescaler Register overflows every 32769 clock cycles.
//     0b0 ==> Time Prescaler Register overflows every 32768 clock cycles.
//     0b1 ==> Time Prescaler Register overflows every 32767 clock cycles.
//     0b1111111 ==> Time Prescaler Register overflows every 32641 clock cycles.

#define  RTC_TCR_CIR_MASK            0x800u
#define  RTC_TCR_CIR_SHIFT           8
#define  RTC_TCR_CIR(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK)
//   Compensation Interval Register

#define  RTC_TCR_TCV_MASK            0x80000u
#define  RTC_TCR_TCV_SHIFT           16
#define  RTC_TCR_TCV(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK)
//   Time Compensation Value

#define  RTC_TCR_CIC_MASK            0x8000000u
#define  RTC_TCR_CIC_SHIFT           24
#define  RTC_TCR_CIC(x)              (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK)
//   Compensation Interval Counter

#define  RTC_CR_SWR_MASK             0x1u
#define  RTC_CR_SWR_SHIFT            0
//   Software Reset
//     0b0 ==> No effect.
//     0b1 ==> Resets all RTC registers except for the SWR bit . The SWR bit is cleared by POR and by software explicitly clearing it.

#define  RTC_CR_WPE_MASK             0x2u
#define  RTC_CR_WPE_SHIFT            1
//   Wakeup Pin Enable
//     0b0 ==> Wakeup pin is disabled.
//     0b1 ==> Wakeup pin is enabled and wakeup pin asserts if the RTC interrupt asserts .

#define  RTC_CR_SUP_MASK             0x4u
#define  RTC_CR_SUP_SHIFT            2
//   Supervisor Access
//     0b0 ==> Non-supervisor mode write accesses are not supported and generate a bus error.
//     0b1 ==> Non-supervisor mode write accesses are supported.

#define  RTC_CR_UM_MASK              0x8u
#define  RTC_CR_UM_SHIFT             3
//   Update Mode
//     0b0 ==> Registers cannot be written when locked.
//     0b1 ==> Registers can be written when locked under limited conditions.

#define  RTC_CR_OSCE_MASK            0x100u
#define  RTC_CR_OSCE_SHIFT           8
//   Oscillator Enable
//     0b0 ==> 32.768 kHz oscillator is disabled.
//     0b1 ==> 32.768 kHz oscillator is enabled. After setting this bit, wait the oscillator startup time before enabling the time counter to allow the 32.768 kHz clock time to stabilize.

#define  RTC_CR_CLKO_MASK            0x200u
#define  RTC_CR_CLKO_SHIFT           9
//   Clock Output
//     0b0 ==> The 32 kHz clock is output to other peripherals.
//     0b1 ==> The 32 kHz clock is not output to other peripherals.

#define  RTC_CR_SC16P_MASK           0x400u
#define  RTC_CR_SC16P_SHIFT          10
//   Oscillator 16pF Load Configure
//     0b0 ==> Disable the load.
//     0b1 ==> Enable the additional load.

#define  RTC_CR_SC8P_MASK            0x800u
#define  RTC_CR_SC8P_SHIFT           11
//   Oscillator 8pF Load Configure
//     0b0 ==> Disable the load.
//     0b1 ==> Enable the additional load.

#define  RTC_CR_SC4P_MASK            0x1000u
#define  RTC_CR_SC4P_SHIFT           12
//   Oscillator 4pF Load Configure
//     0b0 ==> Disable the load.
//     0b1 ==> Enable the additional load.

#define  RTC_CR_SC2P_MASK            0x2000u
#define  RTC_CR_SC2P_SHIFT           13
//   Oscillator 2pF Load Configure
//     0b0 ==> Disable the load.
//     0b1 ==> Enable the additional load.

#define  RTC_SR_TIF_MASK             0x1u
#define  RTC_SR_TIF_SHIFT            0
//   Time Invalid Flag
//     0b0 ==> Time is valid.
//     0b1 ==> Time is invalid and time counter is read as zero.

#define  RTC_SR_TOF_MASK             0x2u
#define  RTC_SR_TOF_SHIFT            1
//   Time Overflow Flag
//     0b0 ==> Time overflow has not occurred.
//     0b1 ==> Time overflow has occurred and time counter is read as zero.

#define  RTC_SR_TAF_MASK             0x4u
#define  RTC_SR_TAF_SHIFT            2
//   Time Alarm Flag
//     0b0 ==> Time alarm has not occurred.
//     0b1 ==> Time alarm has occurred.

#define  RTC_SR_TCE_MASK             0x10u
#define  RTC_SR_TCE_SHIFT            4
//   Time Counter Enable
//     0b0 ==> Time counter is disabled.
//     0b1 ==> Time counter is enabled.

#define  RTC_LR_TCL_MASK             0x8u
#define  RTC_LR_TCL_SHIFT            3
//   Time Compensation Lock
//     0b0 ==> Time Compensation Register is locked and writes are ignored.
//     0b1 ==> Time Compensation Register is not locked and writes complete as normal.

#define  RTC_LR_CRL_MASK             0x10u
#define  RTC_LR_CRL_SHIFT            4
//   Control Register Lock
//     0b0 ==> Control Register is locked and writes are ignored.
//     0b1 ==> Control Register is not locked and writes complete as normal.

#define  RTC_LR_SRL_MASK             0x20u
#define  RTC_LR_SRL_SHIFT            5
//   Status Register Lock
//     0b0 ==> Status Register is locked and writes are ignored.
//     0b1 ==> Status Register is not locked and writes complete as normal.

#define  RTC_LR_LRL_MASK             0x40u
#define  RTC_LR_LRL_SHIFT            6
//   Lock Register Lock
//     0b0 ==> Lock Register is locked and writes are ignored.
//     0b1 ==> Lock Register is not locked and writes complete as normal.

#define  RTC_IER_TIIE_MASK           0x1u
#define  RTC_IER_TIIE_SHIFT          0
//   Time Invalid Interrupt Enable
//     0b0 ==> Time invalid flag does not generate an interrupt.
//     0b1 ==> Time invalid flag does generate an interrupt.

#define  RTC_IER_TOIE_MASK           0x2u
#define  RTC_IER_TOIE_SHIFT          1
//   Time Overflow Interrupt Enable
//     0b0 ==> Time overflow flag does not generate an interrupt.
//     0b1 ==> Time overflow flag does generate an interrupt.

#define  RTC_IER_TAIE_MASK           0x4u
#define  RTC_IER_TAIE_SHIFT          2
//   Time Alarm Interrupt Enable
//     0b0 ==> Time alarm flag does not generate an interrupt.
//     0b1 ==> Time alarm flag does generate an interrupt.

#define  RTC_IER_TSIE_MASK           0x10u
#define  RTC_IER_TSIE_SHIFT          4
//   Time Seconds Interrupt Enable
//     0b0 ==> Seconds interrupt is disabled.
//     0b1 ==> Seconds interrupt is enabled.

#define  SIM_SOPT1_OSC32KSEL_MASK    0x80000u
#define  SIM_SOPT1_OSC32KSEL_SHIFT   18
#define  SIM_SOPT1_OSC32KSEL(x)      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK)
//   32K oscillator clock select
//     0b00 ==> System oscillator (OSC32KCLK)
//     0b01 ==> Reserved
//     0b10 ==> RTC_CLKIN
//     0b11 ==> LPO 1kHz

#define  SIM_SOPT2_RTCCLKOUTSEL_MASK 0x10u
#define  SIM_SOPT2_RTCCLKOUTSEL_SHIFT 4
//   RTC clock out select
//     0b0 ==> RTC 1 Hz clock is output on the RTC_CLKOUT pin.
//     0b1 ==> OSCERCLK0 clock is output on the RTC_CLKOUT pin.

#define  SIM_SOPT2_CLKOUTSEL_MASK    0x60u
#define  SIM_SOPT2_CLKOUTSEL_SHIFT   5
#define  SIM_SOPT2_CLKOUTSEL(x)      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK)
//   CLKOUT select
//     0b000 ==> Reserved
//     0b001 ==> Reserved
//     0b010 ==> Bus clock
//     0b011 ==> LPO clock (1 kHz)
//     0b100 ==> MCGIRCLK
//     0b101 ==> Reserved
//     0b110 ==> OSCERCLK0
//     0b111 ==> Reserved

#define  SIM_SOPT2_LPTPMSRC_MASK     0x2000000u
#define  SIM_SOPT2_LPTPMSRC_SHIFT    24
#define  SIM_SOPT2_LPTPMSRC(x)       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_LPTPMSRC_SHIFT))&SIM_SOPT2_LPTPMSRC_MASK)
//   LPTPM clock source select
//     0b00 ==> Clock disabled
//     0b01 ==> MCGFLLCLK clock
//     0b10 ==> OSCERCLK clock
//     0b11 ==> MCGIRCLK clock

#define  SIM_SOPT2_UART0SRC_MASK     0x8000000u
#define  SIM_SOPT2_UART0SRC_SHIFT    26
#define  SIM_SOPT2_UART0SRC(x)       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_UART0SRC_SHIFT))&SIM_SOPT2_UART0SRC_MASK)
//   UART0 clock source select
//     0b00 ==> Clock disabled
//     0b01 ==> MCGFLLCLK clock
//     0b10 ==> OSCERCLK clock
//     0b11 ==> MCGIRCLK clock

#define  SIM_SOPT4_LPTPM1CH0SRC_MASK 0x40000u
#define  SIM_SOPT4_LPTPM1CH0SRC_SHIFT 18
//   LPTPM1 channel 0 input capture source select
//     0b0 ==> LPTPM1_CH0 signal
//     0b1 ==> CMP0 output

#define  SIM_SOPT4_LPTPM0CLKSEL_MASK 0x1000000u
#define  SIM_SOPT4_LPTPM0CLKSEL_SHIFT 24
//   LPTPM0 External Clock Pin Select
//     0b0 ==> LPTPM0 external clock driven by LPTPM_CLK0 pin.
//     0b1 ==> LPTPM0 external clock driven by LPTPM_CLK1 pin.

#define  SIM_SOPT4_LPTPM1CLKSEL_MASK 0x2000000u
#define  SIM_SOPT4_LPTPM1CLKSEL_SHIFT 25
//   LPTPM1 External Clock Pin Select
//     0b0 ==> LPTPM1 external clock driven by LPTPM_CLK0 pin.
//     0b1 ==> LPTPM1 external clock driven by LPTPM_CLK1 pin.

#define  SIM_SOPT5_UART0TXSRC_MASK   0x1u
#define  SIM_SOPT5_UART0TXSRC_SHIFT  0
//   UART0 transmit data source select
//     0b0 ==> UART0_TX pin
//     0b1 ==> UART0_TX pin modulated with LPTPM1 channel 0 output

#define  SIM_SOPT5_UART0RXSRC_MASK   0x4u
#define  SIM_SOPT5_UART0RXSRC_SHIFT  2
//   UART0 receive data source select
//     0b0 ==> UART0_RX pin
//     0b1 ==> CMP0 output

#define  SIM_SOPT5_UART0ODE_MASK     0x10000u
#define  SIM_SOPT5_UART0ODE_SHIFT    16
//   UART0 Open Drain Enable
//     0b0 ==> Open drain is disabled on UART0
//     0b1 ==> Open drain is enabled on UART0

#define  SIM_SOPT7_ADC0TRGSEL_MASK   0x4u
#define  SIM_SOPT7_ADC0TRGSEL_SHIFT  0
#define  SIM_SOPT7_ADC0TRGSEL(x)     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK)
//   ADC0 trigger select
//     0b0000 ==> External trigger pin input (EXTRG_IN)
//     0b0001 ==> HSCMP0 output
//     0b0010 ==> Reserved
//     0b0011 ==> Reserved
//     0b0100 ==> PIT trigger 0
//     0b0101 ==> PIT trigger 1
//     0b0110 ==> Reserved
//     0b0111 ==> Reserved
//     0b1000 ==> LPTPM0 overflow
//     0b1001 ==> LPTPM1 overflow
//     0b1010 ==> Reserved
//     0b1011 ==> Reserved
//     0b1100 ==> RTC alarm
//     0b1101 ==> RTC seconds
//     0b1110 ==> LPTMR0 trigger
//     0b1111 ==> Reserved

#define  SIM_SOPT7_ADC0PRETRGSEL_MASK 0x10u
#define  SIM_SOPT7_ADC0PRETRGSEL_SHIFT 4
//   ADC0 pretrigger select
//     0b0 ==> Pre-trigger A
//     0b1 ==> Pre-trigger B

#define  SIM_SOPT7_ADC0ALTTRGEN_MASK 0x80u
#define  SIM_SOPT7_ADC0ALTTRGEN_SHIFT 7
//   ADC0 alternate trigger enable
//     0b0 ==> LPTPM1 channel 0 (A) and channel 1 (B) triggers selected for ADC0.
//     0b1 ==> Alternate trigger selected for ADC0.

#define  SIM_SDID_PINID_MASK         0x4u
#define  SIM_SDID_PINID_SHIFT        0
#define  SIM_SDID_PINID(x)           (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK)
//   Pincount identification
//     0b0000 ==> 16-pin
//     0b0001 ==> 24-pin
//     0b0010 ==> 32-pin
//     0b0011 ==> 44-pin
//     0b0100 ==> 48-pin
//     0b0101 ==> 64-pin
//     0b0110 ==> 80-pin
//     0b0111 ==> Reserved
//     0b1000 ==> 100-pin
//     0b1001 ==> Reserved
//     0b1010 ==> Reserved
//     0b1011 ==> Reserved
//     0b1100 ==> Reserved
//     0b1101 ==> Reserved
//     0b1110 ==> Reserved
//     0b1111 ==> Reserved

#define  SIM_SDID_DIEID_MASK         0x280u
#define  SIM_SDID_DIEID_SHIFT        7
#define  SIM_SDID_DIEID(x)           (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK)
//   Device die number

#define  SIM_SDID_REVID_MASK         0x4000u
#define  SIM_SDID_REVID_SHIFT        12
#define  SIM_SDID_REVID(x)           (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
//   Device revision number

#define  SIM_SDID_SRAMSIZE_MASK      0x40000u
#define  SIM_SDID_SRAMSIZE_SHIFT     16
#define  SIM_SDID_SRAMSIZE(x)        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK)
//   System SRAM Size
//     0b0000 ==> 0.5kB
//     0b0001 ==> 1 kB
//     0b0010 ==> 2 kB
//     0b0011 ==> 4 kB
//     0b0100 ==> 8 kB
//     0b0101 ==> 16 kB
//     0b0110 ==> 32 kB
//     0b0111 ==> 64 kB

#define  SIM_SDID_ATTRID_MASK        0x400000u
#define  SIM_SDID_ATTRID_SHIFT       20
#define  SIM_SDID_ATTRID(x)          (((uint32_t)(((uint32_t)(x))<<SIM_SDID_ATTRID_SHIFT))&SIM_SDID_ATTRID_MASK)
//   Kinetis Attribute ID
//     0b0001 ==> Low Power Line with Cortex M0+

#define  SIM_SDID_SUBFAMID_MASK      0x4000000u
#define  SIM_SDID_SUBFAMID_SHIFT     24
#define  SIM_SDID_SUBFAMID(x)        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK)
//   Kinetis Sub-Family ID
//     0b0100 ==> Kx4 Subfamily (basic analog)
//     0b0101 ==> Kx5 Subfamily (advanced analog)

#define  SIM_SDID_FAMID_MASK         0x40000000u
#define  SIM_SDID_FAMID_SHIFT        28
#define  SIM_SDID_FAMID(x)           (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK)
//   Kinetis family ID
//     0b0000 ==> K0x Family
//     0b0001 ==> K1x Family (basic)
//     0b0010 ==> K2x Family (USB)
//     0b0011 ==> K3x Family (Segment LCD)
//     0b0100 ==> K4x Family (USB and Segment LCD)

#define  SIM_SCGC4_I2C0_MASK         0x40u
#define  SIM_SCGC4_I2C0_SHIFT        6
//   I2C0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC4_UART0_MASK        0x400u
#define  SIM_SCGC4_UART0_SHIFT       10
//   UART0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC4_CMP_MASK          0x80000u
#define  SIM_SCGC4_CMP_SHIFT         19
//   Comparator Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC4_SPI0_MASK         0x400000u
#define  SIM_SCGC4_SPI0_SHIFT        22
//   SPI0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC5_LPTMR_MASK        0x1u
#define  SIM_SCGC5_LPTMR_SHIFT       0
//   Low Power Timer Access Control
//     0b0 ==> Access disabled
//     0b1 ==> Access enabled

#define  SIM_SCGC5_TSI_MASK          0x20u
#define  SIM_SCGC5_TSI_SHIFT         5
//   TSI Clock Gate Control
//     0b0 ==> Access disabled
//     0b1 ==> Access enabled

#define  SIM_SCGC5_PORTA_MASK        0x200u
#define  SIM_SCGC5_PORTA_SHIFT       9
//   Port A Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC5_PORTB_MASK        0x400u
#define  SIM_SCGC5_PORTB_SHIFT       10
//   Port B Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_FTF_MASK          0x1u
#define  SIM_SCGC6_FTF_SHIFT         0
//   Flash Memory Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_DMAMUX_MASK       0x2u
#define  SIM_SCGC6_DMAMUX_SHIFT      1
//   DMA Mux Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_PIT_MASK          0x800000u
#define  SIM_SCGC6_PIT_SHIFT         23
//   PIT Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_LPTPM0_MASK       0x1000000u
#define  SIM_SCGC6_LPTPM0_SHIFT      24
//   LPTPM0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_LPTPM1_MASK       0x2000000u
#define  SIM_SCGC6_LPTPM1_SHIFT      25
//   LPTPM1 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_ADC0_MASK         0x8000000u
#define  SIM_SCGC6_ADC0_SHIFT        27
//   ADC0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC6_RTC_MASK          0x20000000u
#define  SIM_SCGC6_RTC_SHIFT         29
//   RTC Access Control
//     0b0 ==> Access and interrupts disabled
//     0b1 ==> Access and interrupts enabled

#define  SIM_SCGC6_DAC0_MASK         0x80000000u
#define  SIM_SCGC6_DAC0_SHIFT        31
//   DAC0 Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_SCGC7_DMA_MASK          0x100u
#define  SIM_SCGC7_DMA_SHIFT         8
//   DMA Clock Gate Control
//     0b0 ==> Clock disabled
//     0b1 ==> Clock enabled

#define  SIM_CLKDIV1_OUTDIV4_MASK    0x30000u
#define  SIM_CLKDIV1_OUTDIV4_SHIFT   16
#define  SIM_CLKDIV1_OUTDIV4(x)      (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK)
//   Clock 4 output divider value
//     0b000 ==> Divide-by-1.
//     0b001 ==> Divide-by-2.
//     0b010 ==> Divide-by-3.
//     0b011 ==> Divide-by-4.
//     0b100 ==> Divide-by-5.
//     0b101 ==> Divide-by-6.
//     0b110 ==> Divide-by-7.
//     0b111 ==> Divide-by-8.

#define  SIM_CLKDIV1_OUTDIV1_MASK    0x40000000u
#define  SIM_CLKDIV1_OUTDIV1_SHIFT   28
#define  SIM_CLKDIV1_OUTDIV1(x)      (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK)
//   Clock 1 output divider value
//     0b0000 ==> Divide-by-1.
//     0b0001 ==> Divide-by-2.
//     0b0010 ==> Divide-by-3.
//     0b0011 ==> Divide-by-4.
//     0b0100 ==> Divide-by-5.
//     0b0101 ==> Divide-by-6.
//     0b0110 ==> Divide-by-7.
//     0b0111 ==> Divide-by-8.
//     0b1000 ==> Divide-by-9.
//     0b1001 ==> Divide-by-10.
//     0b1010 ==> Divide-by-11.
//     0b1011 ==> Divide-by-12.
//     0b1100 ==> Divide-by-13.
//     0b1101 ==> Divide-by-14.
//     0b1110 ==> Divide-by-15.
//     0b1111 ==> Divide-by-16.

#define  SIM_FCFG1_FLASHDIS_MASK     0x1u
#define  SIM_FCFG1_FLASHDIS_SHIFT    0
//   Flash Disable
//     0b0 ==> Flash is enabled
//     0b1 ==> Flash is disabled

#define  SIM_FCFG1_FLASHDOZE_MASK    0x2u
#define  SIM_FCFG1_FLASHDOZE_SHIFT   1
//   Flash Doze
//     0b0 ==> Flash remains enabled during Doze mode
//     0b1 ==> Flash is disabled for the duration of Doze mode

#define  SIM_FCFG1_PFSIZE_MASK       0x4000000u
#define  SIM_FCFG1_PFSIZE_SHIFT      24
#define  SIM_FCFG1_PFSIZE(x)         (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK)
//   Program flash size
//     0b0000 ==> 8 KB of program flash memory, 0.25 KB protection region
//     0b0001 ==> 16 KB of program flash memory, 0.5 KB protection region
//     0b0011 ==> 32 KB of program flash memory, 1 KB protection region
//     0b0101 ==> 64 KB of program flash memory, 2 KB protection region
//     0b0111 ==> 128 KB of program flash memory, 4 KB protection region
//     0b1001 ==> 256 KB of program flash memory, 4 KB protection region
//     0b1111 ==> 32 KB of program flash memory, 1 KB protection region

#define  SIM_FCFG2_MAXADDR_MASK      0x7000000u
#define  SIM_FCFG2_MAXADDR_SHIFT     24
#define  SIM_FCFG2_MAXADDR(x)        (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR_SHIFT))&SIM_FCFG2_MAXADDR_MASK)
//   Max address block

#define  SIM_UIDMH_UID_MASK          0x10u
#define  SIM_UIDMH_UID_SHIFT         0
#define  SIM_UIDMH_UID(x)            (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK)
//   Unique Identification

#define  SIM_UIDML_UID_MASK          0x20u
#define  SIM_UIDML_UID_SHIFT         0
#define  SIM_UIDML_UID(x)            (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK)
//   Unique Identification

#define  SIM_UIDL_UID_MASK           0x20u
#define  SIM_UIDL_UID_SHIFT          0
#define  SIM_UIDL_UID(x)             (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK)
//   Unique Identification

#define  SIM_COPC_COPW_MASK          0x1u
#define  SIM_COPC_COPW_SHIFT         0
//   COP windowed mode
//     0b0 ==> Normal mode
//     0b1 ==> Windowed mode

#define  SIM_COPC_COPCLKS_MASK       0x2u
#define  SIM_COPC_COPCLKS_SHIFT      1
//   COP Clock Select
//     0b0 ==> Internal 1 kHz clock is source to COP
//     0b1 ==> Bus clock is source to COP

#define  SIM_COPC_COPT_MASK          0x8u
#define  SIM_COPC_COPT_SHIFT         2
#define  SIM_COPC_COPT(x)            (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPT_SHIFT))&SIM_COPC_COPT_MASK)
//   COP Watchdog Timeout
//     0b00 ==> COP disabled
//     0b01 ==> COP timeout after 2^5 LPO cycles or 2^13 bus clock cycles
//     0b10 ==> COP timeout after 2^8 LPO cycles or 2^16 bus clock cycles
//     0b11 ==> COP timeout after 2^10 LPO cycles or 2^18 bus clock cycles

#define  SIM_SRVCOP_SRVCOP_MASK      0x8u
#define  SIM_SRVCOP_SRVCOP_SHIFT     0
#define  SIM_SRVCOP_SRVCOP(x)        (((uint32_t)(((uint32_t)(x))<<SIM_SRVCOP_SRVCOP_SHIFT))&SIM_SRVCOP_SRVCOP_MASK)
//   Sevice COP Register

#define  SMC_PMPROT_AVLLS_MASK       0x2u
#define  SMC_PMPROT_AVLLS_SHIFT      1
//   Allow Very-Low-Leakage Stop Mode
//     0b0 ==> Any VLLSx mode is not allowed
//     0b1 ==> Any VLLSx mode is allowed

#define  SMC_PMPROT_ALLS_MASK        0x8u
#define  SMC_PMPROT_ALLS_SHIFT       3
//   Allow Low-Leakage Stop Mode
//     0b0 ==> LLS is not allowed
//     0b1 ==> LLS is allowed

#define  SMC_PMPROT_AVLP_MASK        0x20u
#define  SMC_PMPROT_AVLP_SHIFT       5
//   Allow Very-Low-Power Modes
//     0b0 ==> VLPR, VLPW and VLPS are not allowed
//     0b1 ==> VLPR, VLPW and VLPS are allowed

#define  SMC_PMCTRL_STOPM_MASK       0x3u
#define  SMC_PMCTRL_STOPM_SHIFT      0
#define  SMC_PMCTRL_STOPM(x)         (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
//   Stop Mode Control
//     0b000 ==> Normal Stop (STOP)
//     0b001 ==> Reserved
//     0b010 ==> Very-Low-Power Stop (VLPS)
//     0b011 ==> Low-Leakage Stop (LLS)
//     0b100 ==> Very-Low-Leakage Stop (VLLSx)
//     0b101 ==> Reserved
//     0b110 ==> Reseved
//     0b111 ==> Reserved

#define  SMC_PMCTRL_STOPA_MASK       0x8u
#define  SMC_PMCTRL_STOPA_SHIFT      3
//   Stop Aborted
//     0b0 ==> The previous stop mode entry was successsful.
//     0b1 ==> The previous stop mode entry was aborted.

#define  SMC_PMCTRL_RUNM_MASK        0x40u
#define  SMC_PMCTRL_RUNM_SHIFT       5
#define  SMC_PMCTRL_RUNM(x)          (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
//   Run Mode Control
//     0b00 ==> Normal Run mode (RUN)
//     0b01 ==> Reserved
//     0b10 ==> Very-Low-Power Run mode (VLPR)
//     0b11 ==> Reserved

#define  SMC_STOPCTRL_VLLSM_MASK     0x3u
#define  SMC_STOPCTRL_VLLSM_SHIFT    0
#define  SMC_STOPCTRL_VLLSM(x)       (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK)
//   VLLS Mode Control.
//     0b000 ==> VLLS0
//     0b001 ==> VLLS1
//     0b010 ==> VLLS2
//     0b011 ==> VLLS3
//     0b100 ==> Reserved
//     0b101 ==> Reserved
//     0b110 ==> Reserved
//     0b111 ==> Reserved

#define  SMC_STOPCTRL_PORPO_MASK     0x20u
#define  SMC_STOPCTRL_PORPO_SHIFT    5
//   POR Power Option
//     0b0 ==> POR detect circuit is enabled in VLLS0
//     0b1 ==> POR detect circuit is disabled in VLLS0

#define  SMC_STOPCTRL_PSTOPO_MASK    0x80u
#define  SMC_STOPCTRL_PSTOPO_SHIFT   6
#define  SMC_STOPCTRL_PSTOPO(x)      (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK)
//   Partial Stop Option
//     0b00 ==> STOP - Normal Stop mode
//     0b01 ==> PSTOP1 - Partial Stop with both system and bus clocks disabled
//     0b10 ==> PSTOP2 - Partial Stop with system clock disabled and bus clock enabled
//     0b11 ==> Reserved

#define  SMC_PMSTAT_PMSTAT_MASK      0x7u
#define  SMC_PMSTAT_PMSTAT_SHIFT     0
#define  SMC_PMSTAT_PMSTAT(x)        (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

#define  SPI0_C1_LSBFE_MASK          0x1u
#define  SPI0_C1_LSBFE_SHIFT         0
//   LSB first (shifter direction)
//     0b0 ==> SPI serial data transfers start with most significant bit
//     0b1 ==> SPI serial data transfers start with least significant bit

#define  SPI0_C1_SSOE_MASK           0x2u
#define  SPI0_C1_SSOE_SHIFT          1
//   Slave select output enable
//     0b0 ==> When MODFEN is 0: In master mode, SS pin function is general-purpose I/O (not SPI). In slave mode, SS pin function is slave select input. When MODFEN is 1: In master mode, SS pin function is SS input for mode fault. In slave mode, SS pin function is slave select input.
//     0b1 ==> When MODFEN is 0: In master mode, SS pin function is general-purpose I/O (not SPI). In slave mode, SS pin function is slave select input. When MODFEN is 1: In master mode, SS pin function is automatic SS output. In slave mode: SS pin function is slave select input.

#define  SPI0_C1_CPHA_MASK           0x4u
#define  SPI0_C1_CPHA_SHIFT          2
//   Clock phase
//     0b0 ==> First edge on SPSCK occurs at the middle of the first cycle of a data transfer
//     0b1 ==> First edge on SPSCK occurs at the start of the first cycle of a data transfer

#define  SPI0_C1_CPOL_MASK           0x8u
#define  SPI0_C1_CPOL_SHIFT          3
//   Clock polarity
//     0b0 ==> Active-high SPI clock (idles low)
//     0b1 ==> Active-low SPI clock (idles high)

#define  SPI0_C1_MSTR_MASK           0x10u
#define  SPI0_C1_MSTR_SHIFT          4
//   Master/slave mode select
//     0b0 ==> SPI module configured as a slave SPI device
//     0b1 ==> SPI module configured as a master SPI device

#define  SPI0_C1_SPTIE_MASK          0x20u
#define  SPI0_C1_SPTIE_SHIFT         5
//   SPI transmit interrupt enable
//     0b0 ==> Interrupts from SPTEF inhibited (use polling)
//     0b1 ==> When SPTEF is 1, hardware interrupt requested

#define  SPI0_C1_SPE_MASK            0x40u
#define  SPI0_C1_SPE_SHIFT           6
//   SPI system enable
//     0b0 ==> SPI system inactive
//     0b1 ==> SPI system enabled

#define  SPI0_C1_SPIE_MASK           0x80u
#define  SPI0_C1_SPIE_SHIFT          7
//   SPI interrupt enable: for SPRF and MODF
//     0b0 ==> Interrupts from SPRF and MODF are inhibited-use polling
//     0b1 ==> Request a hardware interrupt when SPRF or MODF is 1

#define  SPI0_C2_SPC0_MASK           0x1u
#define  SPI0_C2_SPC0_SHIFT          0
//   SPI pin control 0
//     0b0 ==> SPI uses separate pins for data input and data output (pin mode is normal). In master mode of operation: MISO is master in and MOSI is master out. In slave mode of operation: MISO is slave out and MOSI is slave in.
//     0b1 ==> SPI configured for single-wire bidirectional operation (pin mode is bidirectional). In master mode of operation: MISO is not used by SPI; MOSI is master in when BIDIROE is 0 or master I/O when BIDIROE is 1. In slave mode of operation: MISO is slave in when BIDIROE is 0 or slave I/O when BIDIROE is 1; MOSI is not used by SPI.

#define  SPI0_C2_SPISWAI_MASK        0x2u
#define  SPI0_C2_SPISWAI_SHIFT       1
//   SPI stop in wait mode
//     0b0 ==> SPI clocks continue to operate in wait mode
//     0b1 ==> SPI clocks stop when the MCU enters wait mode

#define  SPI0_C2_RXDMAE_MASK         0x4u
#define  SPI0_C2_RXDMAE_SHIFT        2
//   Receive DMA enable
//     0b0 ==> DMA request for receive is disabled and interrupt from SPRF is allowed
//     0b1 ==> DMA request for receive is enabled and interrupt from SPRF is disabled

#define  SPI0_C2_BIDIROE_MASK        0x8u
#define  SPI0_C2_BIDIROE_SHIFT       3
//   Bidirectional mode output enable
//     0b0 ==> Output driver disabled so SPI data I/O pin acts as an input
//     0b1 ==> SPI I/O pin enabled as an output

#define  SPI0_C2_MODFEN_MASK         0x10u
#define  SPI0_C2_MODFEN_SHIFT        4
//   Master mode-fault function enable
//     0b0 ==> Mode fault function disabled, master SS pin reverts to general-purpose I/O not controlled by SPI
//     0b1 ==> Mode fault function enabled, master SS pin acts as the mode fault input or the slave select output

#define  SPI0_C2_TXDMAE_MASK         0x20u
#define  SPI0_C2_TXDMAE_SHIFT        5
//   Transmit DMA enable
//     0b0 ==> DMA request for transmit is disabled and interrupt from SPTEF is allowed
//     0b1 ==> DMA request for transmit is enabled and interrupt from SPTEF is disabled

#define  SPI0_C2_SPLPIE_MASK         0x40u
#define  SPI0_C2_SPLPIE_SHIFT        6
//   SPI low power interrupt enable bit
//     0b0 ==> The SPI module cannot generate an asynchronous interrupt to wake the CPU from wait mode or stop mode.
//     0b1 ==> Under specific conditions, the SPI module can generate an asynchronous interrupt to wake the CPU from wait mode or stop mode.

#define  SPI0_C2_SPMIE_MASK          0x80u
#define  SPI0_C2_SPMIE_SHIFT         7
//   SPI match interrupt enable
//     0b0 ==> Interrupts from SPMF inhibited (use polling)
//     0b1 ==> When SPMF is 1, requests a hardware interrupt

#define  SPI0_BR_SPR_MASK            0x4u
#define  SPI0_BR_SPR_SHIFT           0
#define  SPI0_BR_SPR(x)              (((uint8_t)(((uint8_t)(x))<<SPI0_BR_SPR_SHIFT))&SPI0_BR_SPR_MASK)
//   SPI baud rate divisor
//     0b0000 ==> Baud rate divisor is 2
//     0b0001 ==> Baud rate divisor is 4
//     0b0010 ==> Baud rate divisor is 8
//     0b0011 ==> Baud rate divisor is 16
//     0b0100 ==> Baud rate divisor is 32
//     0b0101 ==> Baud rate divisor is 64
//     0b0110 ==> Baud rate divisor is 128
//     0b0111 ==> Baud rate divisor is 256
//     0b1000 ==> Baud rate divisor is 512

#define  SPI0_BR_SPPR_MASK           0x30u
#define  SPI0_BR_SPPR_SHIFT          4
#define  SPI0_BR_SPPR(x)             (((uint8_t)(((uint8_t)(x))<<SPI0_BR_SPPR_SHIFT))&SPI0_BR_SPPR_MASK)
//   SPI baud rate prescale divisor
//     0b000 ==> Baud rate prescaler divisor is 1
//     0b001 ==> Baud rate prescaler divisor is 2
//     0b010 ==> Baud rate prescaler divisor is 3
//     0b011 ==> Baud rate prescaler divisor is 4
//     0b100 ==> Baud rate prescaler divisor is 5
//     0b101 ==> Baud rate prescaler divisor is 6
//     0b110 ==> Baud rate prescaler divisor is 7
//     0b111 ==> Baud rate prescaler divisor is 8

#define  SPI0_S_MODF_MASK            0x10u
#define  SPI0_S_MODF_SHIFT           4
//   Master mode fault flag
//     0b0 ==> No mode fault error
//     0b1 ==> Mode fault error detected

#define  SPI0_S_SPTEF_MASK           0x20u
#define  SPI0_S_SPTEF_SHIFT          5
//   SPI transmit buffer empty flag
//     0b0 ==> SPI transmit buffer not empty
//     0b1 ==> SPI transmit buffer empty

#define  SPI0_S_SPMF_MASK            0x40u
#define  SPI0_S_SPMF_SHIFT           6
//   SPI match flag
//     0b0 ==> Value in the receive data buffer does not match the value in the M register
//     0b1 ==> Value in the receive data buffer matches the value in the M register

#define  SPI0_S_SPRF_MASK            0x80u
#define  SPI0_S_SPRF_SHIFT           7
//   SPI read buffer full flag
//     0b0 ==> No data available in the receive data buffer
//     0b1 ==> Data available in the receive data buffer

#define  SPI0_D_Bits_MASK            0x8u
#define  SPI0_D_Bits_SHIFT           0
#define  SPI0_D_Bits(x)              (((uint8_t)(((uint8_t)(x))<<SPI0_D_Bits_SHIFT))&SPI0_D_Bits_MASK)
//   Data (low byte)

#define  SPI0_M_Bits_MASK            0x8u
#define  SPI0_M_Bits_SHIFT           0
#define  SPI0_M_Bits(x)              (((uint8_t)(((uint8_t)(x))<<SPI0_M_Bits_SHIFT))&SPI0_M_Bits_MASK)
//   Hardware compare value (low byte)

#define  TSI0_GENCS_CURSW_MASK       0x2u
#define  TSI0_GENCS_CURSW_SHIFT      1
//   CURSW
//     0b0 ==> The current source pair are not swapped.
//     0b1 ==> The current source pair are swapped.

#define  TSI0_GENCS_EOSF_MASK        0x4u
#define  TSI0_GENCS_EOSF_SHIFT       2
//   End of Scan Flag
//     0b0 ==> Scan not complete.
//     0b1 ==> Scan complete.

#define  TSI0_GENCS_SCNIP_MASK       0x8u
#define  TSI0_GENCS_SCNIP_SHIFT      3
//   Scan In Progress Status
//     0b0 ==> No scan in progress.
//     0b1 ==> Scan in progress.

#define  TSI0_GENCS_STM_MASK         0x10u
#define  TSI0_GENCS_STM_SHIFT        4
//   Scan Trigger Mode
//     0b0 ==> Software trigger scan.
//     0b1 ==> Hardware trigger scan.

#define  TSI0_GENCS_STPE_MASK        0x20u
#define  TSI0_GENCS_STPE_SHIFT       5
//   TSI STOP Enable
//     0b0 ==> TSI is disabled when MCU goes into low power mode.
//     0b1 ==> Allows TSI to continue running in all low power modes.

#define  TSI0_GENCS_TSIIEN_MASK      0x40u
#define  TSI0_GENCS_TSIIEN_SHIFT     6
//   Touch Sensing Input Interrupt Enable
//     0b0 ==> TSI interrupt is disabled.
//     0b1 ==> TSI interrupt is enabled.

#define  TSI0_GENCS_TSIEN_MASK       0x80u
#define  TSI0_GENCS_TSIEN_SHIFT      7
//   Touch Sensing Input Module Enable
//     0b0 ==> TSI module disabled.
//     0b1 ==> TSI module enabled.

#define  TSI0_GENCS_NSCN_MASK        0x500u
#define  TSI0_GENCS_NSCN_SHIFT       8
#define  TSI0_GENCS_NSCN(x)          (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_NSCN_SHIFT))&TSI0_GENCS_NSCN_MASK)
//   NSCN
//     0b00000 ==> Once per electrode
//     0b00001 ==> Twice per electrode
//     0b00010 ==> 3 times per electrode
//     0b00011 ==> 4 times per electrode
//     0b00100 ==> 5 times per electrode
//     0b00101 ==> 6 times per electrode
//     0b00110 ==> 7 times per electrode
//     0b00111 ==> 8 times per electrode
//     0b01000 ==> 9 times per electrode
//     0b01001 ==> 10 times per electrode
//     0b01010 ==> 11 times per electrode
//     0b01011 ==> 12 times per electrode
//     0b01100 ==> 13 times per electrode
//     0b01101 ==> 14 times per electrode
//     0b01110 ==> 15 times per electrode
//     0b01111 ==> 16 times per electrode
//     0b10000 ==> 17 times per electrode
//     0b10001 ==> 18 times per electrode
//     0b10010 ==> 19 times per electrode
//     0b10011 ==> 20 times per electrode
//     0b10100 ==> 21 times per electrode
//     0b10101 ==> 22 times per electrode
//     0b10110 ==> 23 times per electrode
//     0b10111 ==> 24 times per electrode
//     0b11000 ==> 25 times per electrode
//     0b11001 ==> 26 times per electrode
//     0b11010 ==> 27 times per electrode
//     0b11011 ==> 28 times per electrode
//     0b11100 ==> 29 times per electrode
//     0b11101 ==> 30 times per electrode
//     0b11110 ==> 31 times per electrode
//     0b11111 ==> 32 times per electrode

#define  TSI0_GENCS_PS_MASK          0x6000u
#define  TSI0_GENCS_PS_SHIFT         13
#define  TSI0_GENCS_PS(x)            (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_PS_SHIFT))&TSI0_GENCS_PS_MASK)
//   PS
//     0b000 ==> Electrode Oscillator Frequency divided by 1
//     0b001 ==> Electrode Oscillator Frequency divided by 2
//     0b010 ==> Electrode Oscillator Frequency divided by 4
//     0b011 ==> Electrode Oscillator Frequency divided by 8
//     0b100 ==> Electrode Oscillator Frequency divided by 16
//     0b101 ==> Electrode Oscillator Frequency divided by 32
//     0b110 ==> Electrode Oscillator Frequency divided by 64
//     0b111 ==> Electrode Oscillator Frequency divided by 128

#define  TSI0_GENCS_EXTCHRG_MASK     0x30000u
#define  TSI0_GENCS_EXTCHRG_SHIFT    16
#define  TSI0_GENCS_EXTCHRG(x)       (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_EXTCHRG_SHIFT))&TSI0_GENCS_EXTCHRG_MASK)
//   EXTCHRG
//     0b000 ==> 500 nA.
//     0b001 ==> 1 μA.
//     0b010 ==> 2 μA.
//     0b011 ==> 4 μA.
//     0b100 ==> 8 μA.
//     0b101 ==> 16 μA.
//     0b110 ==> 32 μA.
//     0b111 ==> 64 μA.

#define  TSI0_GENCS_DVOLT_MASK       0x100000u
#define  TSI0_GENCS_DVOLT_SHIFT      19
#define  TSI0_GENCS_DVOLT(x)         (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_DVOLT_SHIFT))&TSI0_GENCS_DVOLT_MASK)
//   DVOLT
//     0b00 ==> DV = 1.03 V; VP = 1.33 V; Vm = 0.30 V.
//     0b01 ==> DV = 0.73 V; VP = 1.18 V; Vm = 0.45 V.
//     0b10 ==> DV = 0.43 V; VP = 1.03 V; Vm = 0.60 V.
//     0b11 ==> DV = 0.29 V; VP = 0.95 V; Vm = 0.67 V.

#define  TSI0_GENCS_REFCHRG_MASK     0x600000u
#define  TSI0_GENCS_REFCHRG_SHIFT    21
#define  TSI0_GENCS_REFCHRG(x)       (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_REFCHRG_SHIFT))&TSI0_GENCS_REFCHRG_MASK)
//   REFCHRG
//     0b000 ==> 500 nA.
//     0b001 ==> 1 μA.
//     0b010 ==> 2 μA.
//     0b011 ==> 4 μA.
//     0b100 ==> 8 μA.
//     0b101 ==> 16 μA.
//     0b110 ==> 32 μA.
//     0b111 ==> 64 μA.

#define  TSI0_GENCS_STATUS_SETUP_MASK 0x4000000u
#define  TSI0_GENCS_STATUS_SETUP_SHIFT 24
#define  TSI0_GENCS_STATUS_SETUP(x)  (((uint32_t)(((uint32_t)(x))<<TSI0_GENCS_STATUS_SETUP_SHIFT))&TSI0_GENCS_STATUS_SETUP_MASK)
//   TSI analog modes setup., especially, setting SETUP[3:2] to 2'b11 will configure TSI to noise detection mode.
//     0b0000 ==> No effect.
//     0b1100 ==> Set TSI analog to work in noise detection mode.

#define  TSI0_GENCS_ESOR_MASK        0x10000000u
#define  TSI0_GENCS_ESOR_SHIFT       28
//   End-of-scan or Out-of-Range Interrupt Selection
//     0b0 ==> Out-of-range interrupt is allowed.
//     0b1 ==> End-of-scan interrupt is allowed.

#define  TSI0_GENCS_OUTRGF_MASK      0x80000000u
#define  TSI0_GENCS_OUTRGF_SHIFT     31
//   Out of Range Flag.

#define  TSI0_DATA_TSICNT_MASK       0x10u
#define  TSI0_DATA_TSICNT_SHIFT      0
#define  TSI0_DATA_TSICNT(x)         (((uint32_t)(((uint32_t)(x))<<TSI0_DATA_TSICNT_SHIFT))&TSI0_DATA_TSICNT_MASK)
//   TSI Conversion Counter Value

#define  TSI0_DATA_SWTS_MASK         0x400000u
#define  TSI0_DATA_SWTS_SHIFT        22
//   Software Trigger Start
//     0b0 ==> No effect.
//     0b1 ==> Start a scan to determine which channel is specified by TSI_DATA[TSICH].

#define  TSI0_DATA_DMAEN_MASK        0x800000u
#define  TSI0_DATA_DMAEN_SHIFT       23
//   DMA Transfer Enabled
//     0b0 ==> Interrupt is selected when the interrupt enable bit is set and the corresponding TSI events assert.
//     0b1 ==> DMA transfer request is selected when the interrupt enable bit is set and the corresponding TSI events assert.

#define  TSI0_DATA_TSICH_MASK        0x40000000u
#define  TSI0_DATA_TSICH_SHIFT       28
#define  TSI0_DATA_TSICH(x)          (((uint32_t)(((uint32_t)(x))<<TSI0_DATA_TSICH_SHIFT))&TSI0_DATA_TSICH_MASK)
//   TSICH
//     0b0000 ==> Channel 0.
//     0b0001 ==> Channel 1.
//     0b0010 ==> Channel 2.
//     0b0011 ==> Channel 3.
//     0b0100 ==> Channel 4.
//     0b0101 ==> Channel 5.
//     0b0110 ==> Channel 6.
//     0b0111 ==> Channel 7.
//     0b1000 ==> Channel 8.
//     0b1001 ==> Channel 9.
//     0b1010 ==> Channel 10.
//     0b1011 ==> Channel 11.
//     0b1100 ==> Channel 12.
//     0b1101 ==> Channel 13.
//     0b1110 ==> Channel 14.
//     0b1111 ==> Channel 15.

#define  TSI0_TSHD_THRESL_MASK       0x10u
#define  TSI0_TSHD_THRESL_SHIFT      0
#define  TSI0_TSHD_THRESL(x)         (((uint32_t)(((uint32_t)(x))<<TSI0_TSHD_THRESL_SHIFT))&TSI0_TSHD_THRESL_MASK)
//   TSI Wakeup Channel Low-threshold

#define  TSI0_TSHD_THRESH_MASK       0x100000u
#define  TSI0_TSHD_THRESH_SHIFT      16
#define  TSI0_TSHD_THRESH(x)         (((uint32_t)(((uint32_t)(x))<<TSI0_TSHD_THRESH_SHIFT))&TSI0_TSHD_THRESH_MASK)
//   TSI Wakeup Channel High-threshold


//////////////////////////////////////////////////////////////////////////////////////
// Backward compatibility.

// No backward compatibility issues.
