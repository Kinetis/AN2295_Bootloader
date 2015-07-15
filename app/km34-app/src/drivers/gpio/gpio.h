/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      gpio.h
 * @version   1.0.7.0
 * @date      Jun-11-2015
 * @brief     General-Purpose Input/Output (GPIO) driver header file.
 ******************************************************************************/
#ifndef __GPIO_H
#define __GPIO_H

#if !defined(MCU_MKM34ZA5)
  #error "The gpio.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif
/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint32 PCR, DFER;  } tPORT;
typedef struct { uint8 PDDR, PDOR;  } tGPIO;

/* Fast GPIO - Peripheral instance base addresses for access via IOPORT       */
#define FGPIOA_BASE_PTR     ((GPIO_MemMapPtr)0xF8000000u)
#define FGPIOB_BASE_PTR     ((GPIO_MemMapPtr)0xF8000001u)
#define FGPIOC_BASE_PTR     ((GPIO_MemMapPtr)0xF8000002u)
#define FGPIOD_BASE_PTR     ((GPIO_MemMapPtr)0xF8000003u)
#define FGPIOE_BASE_PTR     ((GPIO_MemMapPtr)0xF8000040u)
#define FGPIOF_BASE_PTR     ((GPIO_MemMapPtr)0xF8000041u)
#define FGPIOG_BASE_PTR     ((GPIO_MemMapPtr)0xF8000042u)
#define FGPIOH_BASE_PTR     ((GPIO_MemMapPtr)0xF8000043u)
#define FGPIOI_BASE_PTR     ((GPIO_MemMapPtr)0xF8000080u)

/* Fast GPIO - Register instance definitions for access via IOPORT            */
/* FGPIOA                                                                     */
#define FGPIOA_PDOR         GPIO_PDOR_REG(FGPIOA_BASE_PTR)
#define FGPIOA_PDIR         GPIO_PDIR_REG(FGPIOA_BASE_PTR)
#define FGPIOA_PDDR         GPIO_PDDR_REG(FGPIOA_BASE_PTR)
#define FGPIOA_GACR         GPIO_GACR_REG(FGPIOA_BASE_PTR)
/* FGPIOB                                                                     */
#define FGPIOB_PDOR         GPIO_PDOR_REG(FGPIOB_BASE_PTR)
#define FGPIOB_PDIR         GPIO_PDIR_REG(FGPIOB_BASE_PTR)
#define FGPIOB_PDDR         GPIO_PDDR_REG(FGPIOB_BASE_PTR)
#define FGPIOB_GACR         GPIO_GACR_REG(FGPIOB_BASE_PTR)
/* FGPIOC                                                                     */
#define FGPIOC_PDOR         GPIO_PDOR_REG(FGPIOC_BASE_PTR)
#define FGPIOC_PDIR         GPIO_PDIR_REG(FGPIOC_BASE_PTR)
#define FGPIOC_PDDR         GPIO_PDDR_REG(FGPIOC_BASE_PTR)
#define FGPIOC_GACR         GPIO_GACR_REG(FGPIOC_BASE_PTR)
/* FGPIOD                                                                     */
#define FGPIOD_PDOR         GPIO_PDOR_REG(FGPIOD_BASE_PTR)
#define FGPIOD_PDIR         GPIO_PDIR_REG(FGPIOD_BASE_PTR)
#define FGPIOD_PDDR         GPIO_PDDR_REG(FGPIOD_BASE_PTR)
#define FGPIOD_GACR         GPIO_GACR_REG(FGPIOD_BASE_PTR)
/* FGPIOE                                                                     */
#define FGPIOE_PDOR         GPIO_PDOR_REG(FGPIOE_BASE_PTR)
#define FGPIOE_PDIR         GPIO_PDIR_REG(FGPIOE_BASE_PTR)
#define FGPIOE_PDDR         GPIO_PDDR_REG(FGPIOE_BASE_PTR)
#define FGPIOE_GACR         GPIO_GACR_REG(FGPIOE_BASE_PTR)
/* FGPIOF                                                                     */
#define FGPIOF_PDOR         GPIO_PDOR_REG(FGPIOF_BASE_PTR)
#define FGPIOF_PDIR         GPIO_PDIR_REG(FGPIOF_BASE_PTR)
#define FGPIOF_PDDR         GPIO_PDDR_REG(FGPIOF_BASE_PTR)
#define FGPIOF_GACR         GPIO_GACR_REG(FGPIOF_BASE_PTR)
/* FGPIOG                                                                     */
#define FGPIOG_PDOR         GPIO_PDOR_REG(FGPIOG_BASE_PTR)
#define FGPIOG_PDIR         GPIO_PDIR_REG(FGPIOG_BASE_PTR)
#define FGPIOG_PDDR         GPIO_PDDR_REG(FGPIOG_BASE_PTR)
#define FGPIOG_GACR         GPIO_GACR_REG(FGPIOG_BASE_PTR)
/* FGPIOH                                                                     */
#define FGPIOH_PDOR         GPIO_PDOR_REG(FGPIOH_BASE_PTR)
#define FGPIOH_PDIR         GPIO_PDIR_REG(FGPIOH_BASE_PTR)
#define FGPIOH_PDDR         GPIO_PDDR_REG(FGPIOH_BASE_PTR)
#define FGPIOH_GACR         GPIO_GACR_REG(FGPIOH_BASE_PTR)
/* FGPIOI                                                                     */
#define FGPIOI_PDOR         GPIO_PDOR_REG(FGPIOI_BASE_PTR)
#define FGPIOI_PDIR         GPIO_PDIR_REG(FGPIOI_BASE_PTR)
#define FGPIOI_PDDR         GPIO_PDDR_REG(FGPIOI_BASE_PTR)
#define FGPIOI_GACR         GPIO_GACR_REG(FGPIOI_BASE_PTR)

/******************************************************************************
*//*! @addtogroup port_filt_clk
* @{
*******************************************************************************/
#define PORT_FILT_BUS_CLK   0 ///< Digital filters are clocked by the bus clock
#define PORT_FILT_LPO_CLK   1 ///< Digital filters are clocked by the 1 KHz LPO clock
/*! @} End of port_filt_clk                                                   */

/***************************************************************************//*!
 *//*! @addtogroup gpio_port_attr
 * @{
 ******************************************************************************/
#define GPIO_PORT_RW_RW_RW  0 ///< User nonsecure=Read/Write, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_RO_RW_RW  1 ///< User nonsecure=Read Only, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_NO_RW_RW  2 ///< User nonsecure=None, User secure=Read/Write,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_RO_R0_RW  3 ///< User nonsecure=Read Only, User secure=Read Only,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_NO_R0_RW  4 ///< User nonsecure=None, User secure=Read Only,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_NO_NO_RW  5 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=Read/Write
#define GPIO_PORT_NO_NO_RO  6 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=Read Only
#define GPIO_PORT_NO_NO_NO  7 ///< User nonsecure=None, User secure=None,
                              ///  Privileged secure=None
/*! @} End of gpio_port_attr                                                  */

/******************************************************************************
*//*! @addtogroup pin_names
* @{
*******************************************************************************/
#define PIN0    (uint8)(1u << 0)    ///< PIN 0 (LSB)
#define PIN1    (uint8)(1u << 1)    ///< PIN 1
#define PIN2    (uint8)(1u << 2)    ///< PIN 2
#define PIN3    (uint8)(1u << 3)    ///< PIN 3
#define PIN4    (uint8)(1u << 4)    ///< PIN 4
#define PIN5    (uint8)(1u << 5)    ///< PIN 5
#define PIN6    (uint8)(1u << 6)    ///< PIN 6
#define PIN7    (uint8)(1u << 7)    ///< PIN 7 (MSB)
/*! @} End of pin_names                                                       */

/******************************************************************************
* PORT default configurations used by PORT_init() function
*
*//*! @addtogroup port_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 0 (analogue) mode. Digital portion of
 * the port pin logic is disabled. Pins with no analogue functionality as well
 * as their internal pull-up resistors will be disabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT0_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(0))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 0 (analogue) mode. Digital portion of
 * the port pin logic is disabled. Pins with no analogue functionality will be
 * disabled keeping their pull-up resistors enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT0_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(0))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) IRQ when logic 0 mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt when logic zero enabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_LOGIC0_IRQ_MODE                                      \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(8))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) IRQ when logic 1 mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt when logic one enabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_LOGIC1_IRQ_MODE                                      \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(12))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))| \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) IRQ on rising edge mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt on rising edge enabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_POSEDGE_IRQ_MODE                                     \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(9))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) IRQ on falling edge mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt on falling edge enabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_NEGEDGE_IRQ_MODE                                     \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(10))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))| \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) IRQ on either edge mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt on either edge enabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT1_ANYEDGE_IRQ_MODE                                     \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(11))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))| \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 2 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT2_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(2))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 2 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT2_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(2))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 3 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT3_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(3))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 3 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT3_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(3))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 4 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT4_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(4))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 4 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT4_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(4))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 5 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT5_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(5))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 5 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT5_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(5))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 6 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT6_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(6))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 6 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT6_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(6))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 7 (chip-specific) mode.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT7_MODE                                                 \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(7))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 7 mode with pull-up enabled.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_ALT7_PULLUP_EN_MODE                                       \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(7))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) filtered mode ready for
 * button processing using polling.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter enabled
 * - Interrupt disabled
 * - Slew rate control disabled
 * @showinitializer
 * @note Only PORTE has the digital filter feature for reduced noise and
 * hardware switch de-bouncing. When applying this configuration on other ports
 * the digital filter will be disabled.
 ******************************************************************************/
#define PORT_MODULE_BUTTON_MODE                                               \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ SET(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) filtered mode ready for
 * button processing using interrupts.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up enabled
 * - Digital filter enabled
 * - Interrupt on falling edge enabled
 * - Slew rate control disabled
 * @showinitializer
 * @note Only PORTE has the digital filter feature for reduced noise and
 * hardware switch de-bouncing. When applying this configuration on other ports
 * the digital filter will be disabled.
 ******************************************************************************/
#define PORT_MODULE_BUTTON_IRQ_MODE                                           \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(10))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))| \
/* ...  */ CLR(PORT_PCR_SRE_MASK)|SET(PORT_PCR_PE_MASK)|SET(PORT_PCR_PS_MASK),\
/* DFER */ SET(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}

/***************************************************************************//*!
 * @brief Configures pin(s) to Alternative 1 (GPIO) mode ready for controlling
 * slow outputs such LEDs.
 * @details Configures port pin(s) with the following characteristics:
 * - Internal pull-up disabled
 * - Digital filter disabled
 * - Interrupt disabled
 * - Slew rate control enabled
 * @showinitializer
 ******************************************************************************/
#define PORT_MODULE_LED_MODE                                                  \
(tPORT){                                                                      \
/* PCR  */ SET(PORT_PCR_IRQC(0))|CLR(PORT_PCR_LK_MASK)|SET(PORT_PCR_MUX(1))|  \
/* ...  */ SET(PORT_PCR_SRE_MASK)|CLR(PORT_PCR_PE_MASK)|CLR(PORT_PCR_PS_MASK),\
/* DFER */ CLR(PORT_DFER_DFE_MASK), /* use mask for all pins */               \
}
/*! @} End of port_config                                                     */

/******************************************************************************
* GPIO default configurations used by GPIO_init() function
*
*//*! @addtogroup gpio_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Configures pin(s) in output mode (logic level 0 is driven on pin).
 * @details Pin(s) configured in output mode with logic 0 driven out of pin(s).
 * @showinitializer
 ******************************************************************************/
#define GPIO_OUT_LOGIC0_MODE                                                  \
(tGPIO){                                                                      \
/* PDDR     */ SET(GPIO_PDDR_PDD_MASK), /* use mask for all pins */           \
/* PDOR     */ CLR(GPIO_PDOR_PDO_MASK), /* use mask for all pins */           \
}

/***************************************************************************//*!
 * @brief Configures pin(s) in output mode (logic level 1 is driven on pin).
 * @details Pin(s) configured in output mode with logic 1 driven out of pin(s).
 * @showinitializer
 ******************************************************************************/
#define GPIO_OUT_LOGIC1_MODE                                                  \
(tGPIO){                                                                      \
/* PDDR     */ SET(GPIO_PDDR_PDD_MASK), /* use mask for all pins */           \
/* PDOR     */ SET(GPIO_PDOR_PDO_MASK), /* use mask for all pins */           \
}

/***************************************************************************//*!
 * @brief Configures pin(s) in input mode.
 * @details Pin(s) configured in input mode.
 * @showinitializer
 ******************************************************************************/
#define GPIO_INP_MODE                                                         \
(tGPIO){                                                                      \
/* PDDR     */ CLR(GPIO_PDDR_PDD_MASK), /* use mask for all pins */           \
/* PDOR     */ CLR(GPIO_PDOR_PDO_MASK), /* use mask for all pins */           \
}
/*! @} End of gpio_config                                                     */

/******************************************************************************
* PORT callback registered by PORT_InstallCallback () function
*
*//*! @addtogroup port_callback
* @{
*******************************************************************************/
/*! @brief PORT_CALLBACK source declaration                                   */
typedef enum
{
  PORTA_CALLBACK =  1,  ///< PORTA interrupt
  PORTB_CALLBACK =  2,  ///< PORTB interrupt
  PORTC_CALLBACK =  3,  ///< PORTC interrupt
  PORTD_CALLBACK =  4,  ///< PORTD interrupt
  PORTE_CALLBACK =  5,  ///< PORTE interrupt
  PORTF_CALLBACK =  6,  ///< PORTF interrupt
  PORTG_CALLBACK =  7,  ///< PORTG interrupt
  PORTH_CALLBACK =  8,  ///< PORTH interrupt
  PORTI_CALLBACK =  9   ///< PORTI interrupt
} PORT_CALLBACK_SRC;

/*! @brief PORT_CALLBACK function declaration                                 */
typedef void (*PORT_CALLBACK)(PORT_CALLBACK_SRC src, uint8 pin);
/*! @} End of port_callback                                                   */

/******************************************************************************
* GPIO function and macro definitions
*
*//*! @addtogroup gpio_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns state of pin(s).
 * @details This macro returns state of pin(s).
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @return  @ref uint8 value.
 * @note    Implemented as an inline macro. Select FGPIOx parameter to read port
 *          state via single cycle IOPORT peripheral access rather than via
 *          peripheral bridge (AIPS).
 * @see     @ref GPIO_Set, @ref GPIO_Clr, @ref GPIO_Tgl
 ******************************************************************************/
#define GPIO_Get(gpio)      gpio##_PDIR

/***************************************************************************//*!
 * @brief   Sets pin(s) of the port.
 * @details This macro set(s) pins of the port.
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @param   mask  Select one or more OR'ed @ref pin_names.
 * @note    Implemented as an inline macro. Select FGPIOx parameter to read port
 *          state via single cycle IOPORT peripheral access rather than via
 *          peripheral bridge (AIPS).
 * @see     @ref GPIO_Get, @ref GPIO_Clr, @ref GPIO_Tgl
 ******************************************************************************/
#define GPIO_Set(gpio,mask) gpio##_PDOR|=(mask);  /* set bits on GPIO port    */

/***************************************************************************//*!
 * @brief   Clears pin(s) of the port.
 * @details This macro clears pin(s) of the port.
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @param   mask  Select one or more OR'ed @ref pin_names.
 * @note    Implemented as an inline macro. Select FGPIOx parameter to read port
 *          state via single cycle IOPORT peripheral access rather than via
 *          peripheral bridge (AIPS).
 * @see     @ref GPIO_Get, @ref GPIO_Set, @ref GPIO_Tgl
 ******************************************************************************/
#define GPIO_Clr(gpio,mask) gpio##_PDOR&=~(mask); /* clear bits on GPIO port  */

/***************************************************************************//*!
 * @brief   Toggles pin(s) of the port.
 * @details This macro toggles pin(s) of the port.
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @param   mask  Select one or more OR'ed @ref pin_names.
 * @note    Implemented as an inline macro. Select FGPIOx parameter to read port
 *          state via single cycle IOPORT peripheral access rather than via
 *          peripheral bridge (AIPS).
 * @see     @ref GPIO_Get, @ref GPIO_Set, @ref GPIO_Clr
 ******************************************************************************/
#define GPIO_Tgl(gpio,mask) gpio##_PDOR^=(mask);  /* toggle bits on GPIO port */

/***************************************************************************//*!
 * @brief   Installs callback function for interrupt vector 33.
 * @details This function install callback function for interrupt vector 33.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref port_callback.
 * @note    Implemented as a function call.
 * @warning All PORT interrupt sources are OR'ed into single interrupt vector.
 * @see     @ref PORT_Init
 ******************************************************************************/
#define PORT_InstallCallback(ip,callback) PORT_InstallCallback (ip,callback)

#define PORTE_EnableFilter(port,clksrc,length)                                \
{                                                                             \
  register uint32 tmp32 = PORTE_DFER;                                         \
  PORTE_DFER = (uint32)0l;                                                    \
  PORTE_DFCR = (uint32)clksrc;                                                \
  PORTE_DFWR = (uint32)length;                                                \
  PORTE_DFER = (uint32)tmp32;                                                 \
}
/***************************************************************************//*!
 * @brief   Enables digital filter on PORTE.
 * @details This macro enables digital filter on PORTE. The digital filter
 *          configuration is valid in all digital pin muxing modes. Configures
 *          the maximum size of the glitches, in clock cycles that the digital
 *          filter absorbs for the enabled digital filters.
 * @param   port      PORTE.
 * @param   clksrc    Select one of the @ref port_filt_clk.
 * @param   length    @ref uint8 filter length in range from 0 up 31; glitches
 *                    that are longer than this setting will pass through the
 *                    digital filter, and glitches that are equal to or less
 *                    than this setting are filtered.
 * @note    Implemented as an inline macro.
 * @warning The clock to the PORTE must be enabled otherwise software freezes.
 * @warning If the digital filters for the PORTE are configured to use the bus
 *          clock, then the digital filters are bypassed for the duration of
 *          Stop mode.
 ******************************************************************************/
#define PORT_EnableFilter(port,clksrc,length)                                 \
                                    port##_EnableFilter(port,clksrc,length)

/***************************************************************************//*!
 * @brief   PORT pin(s) initialization.
 * @details This function initializes selected port pin(s).
 * @param   port  PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,PORTG,PORTH,PORTI.
 * @param   cfg   Select one of the @ref port_config.
 * @param   mask  Select one or more OR'ed @ref pin_names.
 * @note    Implemented as a function call.
 * @see     @ref GPIO_Init, @ref PORT_InstallCallback, @ref device_pinout
 ******************************************************************************/
#define PORT_Init(port,cfg,mask)    port##_Init(cfg,mask)

/***************************************************************************//*!
 * @brief   GPIO pin(s) initialization.
 * @details This macro initializes selected pin(s) into either input or output
 *          mode.
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @param   cfg   Select one of the @ref gpio_config.
 * @param   mask  Select one or more OR'ed @ref pin_names.
 * @note    Implemented as an inline macro. Select FGPIOx parameter to perform
 *          single cycle peripheral access via IOPORT rather than via peripheral
 *          bridge (AIPS).
 * @see     @ref PORT_Init, @ref GPIO_SetPortAttr, @ref GPIO_LockAllPortsAttr
 ******************************************************************************/
#define GPIO_Init(gpio,cfg,mask)                                              \
{                                                                             \
  gpio##_PDOR=(gpio##_PDOR&~(mask))|(cfg.PDOR&(mask));                        \
  gpio##_PDDR=(gpio##_PDDR&~(mask))|(cfg.PDDR&(mask));                        \
}

/***************************************************************************//*!
 * @brief   Configures and lock access attributes for specified GPIO port.
 * @details This macro configures and locks access attributes for specified
 *          GPIO port.
 * @param   gpio  GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,FGPIOA,
 *                FGPIOB,FGPIOC,FGPIOD,FGPIOE,FGPIOF,FGPIOG,FGPIOH,FGPIOI.
 * @param   attr  @ref gpio_port_attr to be applied to the selected gpio port.
 * @param   lock  TRUE  (configuration locked until next power on reset)\n
 *                FALSE (configuration left opened for further changes).
 * @note    Implemented as an inline macro. Select FGPIOx parameter to perform
 *          single cycle peripheral access via IOPORT rather than via peripheral
 *          bridge (AIPS).
 * @see     @ref GPIO_LockAllPortsAttr
 ******************************************************************************/
#define GPIO_SetPortAttr(gpio,attr,lock)                                      \
{                                                                             \
  gpio##_GACR=((gpio##_GACR&~GPIO_GACR_ACB_MASK)|                             \
              ((attr)<<GPIO_GACR_ACB_SHIFT)     |                             \
              ((lock)<<GPIO_GACR_ROB_SHIFT));                                 \
}

/***************************************************************************//*!
 * @brief   Lock access to all enabled gpio ports attributes.
 * @details This macro locks access to all enabled gpio ports attributes. Once
 * locked, any attempts to change gpio port access attributes are ignored until
 * the next system reset.
 * @note    Implemented as an inline macro.
 * @see     @ref GPIO_SetPortAttr
 ******************************************************************************/
#define GPIO_LockAllPortsAttr()                                               \
{                                                                             \
  if (SIM_SCGC5&SIM_SCGC5_PORTA_MASK) iosetb (GPIOA_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTB_MASK) iosetb (GPIOB_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTC_MASK) iosetb (GPIOC_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTD_MASK) iosetb (GPIOD_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTE_MASK) iosetb (GPIOE_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTF_MASK) iosetb (GPIOF_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTG_MASK) iosetb (GPIOG_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTH_MASK) iosetb (GPIOH_GACR,GPIO_GACR_ROB_MASK); \
  if (SIM_SCGC5&SIM_SCGC5_PORTI_MASK) iosetb (GPIOI_GACR,GPIO_GACR_ROB_MASK); \
}
/*! @} End of gpio_macro                                                      */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void PORT_InstallCallback (uint8 ip, PORT_CALLBACK pCallback);

extern void PORTA_Init (tPORT port, uint8 pin_mask);
extern void PORTB_Init (tPORT port, uint8 pin_mask);
extern void PORTC_Init (tPORT port, uint8 pin_mask);
extern void PORTD_Init (tPORT port, uint8 pin_mask);
extern void PORTE_Init (tPORT port, uint8 pin_mask);
extern void PORTF_Init (tPORT port, uint8 pin_mask);
extern void PORTG_Init (tPORT port, uint8 pin_mask);
extern void PORTH_Init (tPORT port, uint8 pin_mask);
extern void PORTI_Init (tPORT port, uint8 pin_mask);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void portx_isr (void);

#endif /* __GPIO_H */