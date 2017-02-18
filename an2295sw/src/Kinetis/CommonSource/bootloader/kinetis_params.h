/******************************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      kinetis_params.h
*
* @author    b01119
* 
* @version   0.0.25.0
* 
* @date      Feb-15-2013
* 
* @brief     Main configuration file for IIC bootloader
*
******************************************************************************/

#ifndef KINETIS_PARAMS_H
#define KINETIS_PARAMS_H

#include "bootloader_cfg.h"


//  Kinetis Flash memory sizes
#define FLASH_8K    (1<<13)
#define FLASH_16K   (1<<14)
#define FLASH_32K   (1<<15)
#define FLASH_64K   (1<<16)
#define FLASH_128K  (1<<17)
#define FLASH_256K  (1<<18)
#define FLASH_512K  (1<<19)
#define FLASH_1024K (1<<20)
#define FLASH_2048K (1<<21)
/****************** Include the MCU header files and basic types **************/
#include "main.h"
/******************************************************************************/

//  Kinetis memory sizes
#ifndef KINETIS_FLASH
  #error There is missing define of Kinetis flash memory.
#endif

//  size of one protection section depends on flash size in Bytes (protected block = flash size / 32)

#ifndef KINETIS_MODEL_STR  
  #error There need define KINETIS_MODEL_STR frist.
#endif

//  default values of GPIO Alternatives of the port  (Alternative to UART)
#ifndef BOOT_UART_GPIO_PORT
  #error There need define BOOT_UART_GPIO_PORT frist.
#endif

#ifndef BOOT_UART_GPIO_PORT_RX
  #define BOOT_UART_GPIO_PORT_RX   BOOT_UART_GPIO_PORT 
#endif 

#ifndef BOOT_UART_GPIO_PORT_TX
  #define BOOT_UART_GPIO_PORT_TX   BOOT_UART_GPIO_PORT 
#endif 

#ifndef BOOT_UART_GPIO_PIN_RX
  #error There need define BOOT_UART_GPIO_PIN_RX frist.
#endif

#ifndef BOOT_UART_GPIO_PIN_TX
  #error There need define BOOT_UART_GPIO_PIN_TX frist.
#endif

//#define GPIO_RX_MASK   (0x01 << BOOT_UART_GPIO_PIN_RX) 

//  PIN alternative definition
#ifndef BOOT_PIN_UART_ALTERNATIVE
  #error There need define BOOT_PIN_UART_ALTERNATIVE frist.
#endif

//  PIN alternative definition
#ifndef BOOT_PIN_GPIO_ALTERNATIVE
#error There need define BOOT_PIN_GPIO_ALTERNATIVE frist.
#endif

#ifndef BOOT_UART_BASE
#error There need define BOOT_UART_BASE frist.
#endif

#ifndef BOOT_UART_BAUD_RATE
#error There need define BOOT_UART_BAUD_RATE frist.
#endif

//  init macro for multiplexer setting - alternative UART
#define BOOT_PIN_INIT_AS_UART PORT_PCR_REG(BOOT_UART_GPIO_PORT_RX, BOOT_UART_GPIO_PIN_RX) = PORT_PCR_MUX(BOOT_PIN_UART_ALTERNATIVE); PORT_PCR_REG(BOOT_UART_GPIO_PORT_TX, BOOT_UART_GPIO_PIN_TX) = PORT_PCR_MUX(BOOT_PIN_UART_ALTERNATIVE);
//  init macro for multiplexer setting - alternative GPIO
#define BOOT_PIN_INIT_AS_GPIO PORT_PCR_REG(BOOT_UART_GPIO_PORT_RX, BOOT_UART_GPIO_PIN_RX) = PORT_PCR_MUX(BOOT_PIN_GPIO_ALTERNATIVE);

//  initialization for boot pin enable (MUX - GPIO alternative & PE - pull-up enable)      
#if (BOOTLOADER_PIN_ENABLE == 1) 
  #define BOOTLOADER_PIN_ENABLE_INIT    PORT_PCR_REG(BOOT_PIN_ENABLE_PORT_BASE, BOOT_PIN_ENABLE_NUM) = PORT_PCR_MUX(BOOT_PIN_GPIO_ALTERNATIVE) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
#endif


typedef union _FlashConfig_t
{
  unsigned int Data[4];
  struct {
    unsigned int BackDoorKey[2];
    unsigned int Protection;
    unsigned int Config;
  };
} FlashConfig_t;


/******************************************************************************/
//
//       Compiler differencies
//
//      __CWCC__                - CodeWarrior
//      __GNUC__                - GNU
//      __IAR_SYSTEMS_ICC__     - IAR
//      __ARMCC_VERSION         - KEIL
//
/******************************************************************************/

#if defined(__CWCC__)
//  #error The Code is not prepared for CodeWarrior (it will be done with version 10.3 due to Kinetis L)
//#elif defined(__GNUC__)

#elif defined(__IAR_SYSTEMS_ICC__)
  #define CONST_FIX_VECTORS        __root const
  #define CONST_FIX_VECTORS_END                 
#elif defined(__ARMCC_VERSION)
  #define CONST_FIX_DATA        const 
#else
  #error Not supported compiler type
#endif


// Register redefinition


#ifndef BOOT_BUS_CLOCK
  #error There need define BOOT_BUS_CLOCK frist.
#endif

#ifndef INIT_CLOCKS_TO_MODULES
  #error There need define INIT_CLOCKS_TO_MODULES frist.
#endif

#ifndef FLASH_PROGRAM
  #error There need define FLASH_PROGRAM frist.
#endif

#ifndef FLASH_BASE_PTR
  #error There need define FLASH_BASE_PTR frist.
#endif



#endif //KINETIS_PARAMS_H
