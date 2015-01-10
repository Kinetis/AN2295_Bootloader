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



//  Kinetis ARM Cortex-M4 Microcontrollers models macros
#define K10_50MHz       0x1005
#define K11_50MHz       0x1105
#define K12_50MHz       0x1205
#define K10_72MHz       0x1007
#define K10_100MHz      0x1010
#define K10_120MHz      0x1012

#define K20_50MHz       0x2005
#define K21_50MHz       0x2105
#define K22_50MHz       0x2205
#define K22_100MHz      0x2210
#define K20_72MHz       0x2007
#define K20_100MHz      0x2010
#define K20_120MHz      0x2012

#define K30_72MHz       0x3007
#define K30_100MHz      0x3010

#define K40_72MHz       0x4007
#define K40_100MHz      0x4010

#define K50_72MHz       0x5007
#define K51_72MHz       0x5107
#define K50_100MHz      0x5010

#define K60_100MHz      0x6010
#define K60D_100MHz     0x6a10
#define K60_120MHz      0x6012

#define K70_120MHz      0x7012

//  Kinetis ARM Cortex-M0+ Microcontrollers models macros
#define KL0_48MHz       0x10004
#define KL1_48MHz       0x11004
#define KL2_48MHz       0x12004
#define KL25_48MHz      0x12504
#define KL26_48MHz      0x12604
#define KL46_48MHz      0x14604


//  Kinetis ARM Cortex-M0+ Microcontrollers metering models macros
#define KE02_20MHz      0x20202




#define KM13_48MHz       0x41304
#define KM14_48MHz       0x41404

#define KM32_48MHz       0x43204
#define KM33_48MHz       0x43304
#define KM34_48MHz       0x43404
#define KM38_48MHz       0x43804

#define IS_K10_FAMILY ((KINETIS_MODEL & 0xff000) == 0x1000)
#define IS_K20_FAMILY ((KINETIS_MODEL & 0xff000) == 0x2000)
#define IS_K30_FAMILY ((KINETIS_MODEL & 0xff000) == 0x3000)
#define IS_K40_FAMILY ((KINETIS_MODEL & 0xff000) == 0x4000)
#define IS_K50_FAMILY ((KINETIS_MODEL & 0xff000) == 0x5000)
#define IS_K60_FAMILY ((KINETIS_MODEL & 0xff000) == 0x6000)
#define IS_K70_FAMILY ((KINETIS_MODEL & 0xff000) == 0x7000)

#define IS_Kxx_FAMILY ((KINETIS_MODEL & 0xf0000) == 0)
#define GET_Kxx_FAMILY_FREQ (KINETIS_MODEL & 0xff)

#define IS_KL0_FAMILY ((KINETIS_MODEL & 0xff000) == 0x10000)
#define IS_KL1_FAMILY ((KINETIS_MODEL & 0xff000) == 0x11000)
#define IS_KL2_FAMILY ((KINETIS_MODEL & 0xff000) == 0x12000)
#define IS_KL4_FAMILY ((KINETIS_MODEL & 0xff000) == 0x14000)

#define IS_KLx_FAMILY ((KINETIS_MODEL & 0xf0000) == 0x10000)
#define GET_KLxx_FAMILY_FREQ (KINETIS_MODEL & 0xff)

#define IS_KM1_FAMILY ((KINETIS_MODEL & 0xff000) == 0x41000)
#define IS_KM3_FAMILY ((KINETIS_MODEL & 0xff000) == 0x43000)

#define IS_KMx_FAMILY ((KINETIS_MODEL & 0xf0000) == 0x40000)
#define GET_KMxx_FAMILY_FREQ (KINETIS_MODEL & 0xff)

#define IS_KE0_FAMILY ((KINETIS_MODEL & 0xff000) == 0x20000)
#define IS_KEx_FAMILY ((KINETIS_MODEL & 0xf0000) == 0x20000)
#define GET_KExx_FAMILY_FREQ (KINETIS_MODEL & 0xff)



//  Kinetis Flash memory sizes
#define FLASH_8K    (1<<13)
#define FLASH_16K   (1<<14)
#define FLASH_32K   (1<<15)
#define FLASH_64K   (1<<16)
#define FLASH_128K  (1<<17)
#define FLASH_256K  (1<<18)
#define FLASH_512K  (1<<19)
#define FLASH_1024K (1<<20)

/****************** Include the MCU header files and basic types **************/
#include "main.h"
/******************************************************************************/

//  Kinetis flash memory macros
#ifndef KINETIS_MODEL
  #define KINETIS_MODEL K60_100MHz
  #warning There is missing define of Kinetis model. It sets to default: 'K60_100MHz'!
#endif

#if (!defined(KINETIS_K) && !defined(KINETIS_L) && !defined(KINETIS_M) && !defined(KINETIS_E))
  #error There is selected bad target (currently supported targets are KINETIS_K & KINETIS_L & KINETIS_E).
#else

  #if defined(KINETIS_K)
    #if !IS_Kxx_FAMILY
      #error For this target (KINETIS_K) must be selected Kinetis Kxx MCU in Kinetis model KINETIS_MODEL.
    #else
      #if GET_Kxx_FAMILY_FREQ != KINETIS_K
        #error Is badly select the target. In configuration file is used MCU with different frequency as in target!
      #endif
    #endif
  #endif

  #if (defined(KINETIS_L) && !IS_KLx_FAMILY)
    #error For this target (KINETIS_L) must be selected Kinetis KLx MCU in Kinetis model KINETIS_MODEL.
  #endif

  #if (defined(KINETIS_E) && !IS_KEx_FAMILY)
    #error For this target (KINETIS_E) must be selected Kinetis KEx MCU in Kinetis model KINETIS_MODEL.
  #endif
  
  #if (defined(KINETIS_M) && !IS_KMx_FAMILY)
    #error For this target (KINETIS_M) must be selected Kinetis KMx MCU in Kinetis model KINETIS_MODEL.
  #endif
#endif

//  Kinetis memory sizes
#ifndef KINETIS_FLASH
  #define KINETIS_FLASH FLASH_512K
  #warning There is missing define of Kinetis flash memory. It sets to default: '512k'! 
#endif

#ifndef BOOTLOADER_FLASH_PROTECTION
  #define BOOTLOADER_FLASH_PROTECTION 1
  #warning There is missing define of Kinetis flash memory protection option. It sets to default: Enabled! 
#endif


//  size of one protection section depends on flash size in Bytes (protected block = flash size / 32)
#ifdef KINETIS_K
#define FLASH_PROT_SECTION (KINETIS_FLASH /32)
#else
#define FLASH_PROT_SECTION (0x1000)

#endif

//  size of bootloader in kilobytes 
#define BOOTLOADER_SIZE 2


//  Generation of value for FPROT register (protection of bootloader)
#if BOOTLOADER_FLASH_PROTECTION != 0
  #define FLASH_BOOT_PROTECTION (0xFFFFFFFE << (((BOOTLOADER_SIZE * 1024) / FLASH_PROT_SECTION)))
#else
  #define FLASH_BOOT_PROTECTION 0xFFFFFFFF
#endif

#ifndef KINETIS_MODEL_STR  
  #if IS_K10_FAMILY
    #define KINETIS_MODEL_STR "K10"
  #elif IS_K20_FAMILY
    #define KINETIS_MODEL_STR "K20"
  #elif IS_K30_FAMILY
    #define KINETIS_MODEL_STR "K30"
  #elif IS_K40_FAMILY
    #define KINETIS_MODEL_STR "K40"
  #elif IS_K50_FAMILY
    #define KINETIS_MODEL_STR "K50"
  #elif IS_K60_FAMILY
    #define KINETIS_MODEL_STR "K60"
  #elif IS_K70_FAMILY
    #define KINETIS_MODEL_STR "K70"  
  #elif IS_KL0_FAMILY
    #define KINETIS_MODEL_STR "KL0"  
  #elif IS_KL1_FAMILY
    #define KINETIS_MODEL_STR "KL1"  
  #elif IS_KL2_FAMILY
    #define KINETIS_MODEL_STR "KL2"  
  #elif IS_KL4_FAMILY
    #define KINETIS_MODEL_STR "KL4"  
  #elif IS_KM1_FAMILY
    #define KINETIS_MODEL_STR "KM1"  
  #elif IS_KM3_FAMILY
    #define KINETIS_MODEL_STR "KM3"  
  #elif IS_KE0_FAMILY
    #define KINETIS_MODEL_STR "KE0" 
  #else  
    #define KINETIS_MODEL_STR "xxx"
  #endif
#endif

#ifndef BOOTLOADER_SHORT_TRIM
  #define BOOTLOADER_SHORT_TRIM 0
#endif

#ifdef  KINETIS_FLASH
    /** Flash block count of this MCU */
    #ifndef FLASH_BLOCK_CNT
      #define FLASH_BLOCK_CNT 1
    #endif

    #ifndef INTERRUPT_VECTORS
      #define INTERRUPT_VECTORS 0x0000
    #endif
  
    #ifndef RELOCATED_VECTORS
      #define RELOCATED_VECTORS FLASH_PROT_SECTION 
    #endif
  
    #ifndef USER_FLASH_START
      #define USER_FLASH_START FLASH_PROT_SECTION
    #endif
  
    #ifndef USER_FLASH_END  
      #define USER_FLASH_END (KINETIS_FLASH - 1)
    #endif
  
    #ifndef FLASH_WRITE_PAGE  
      #define FLASH_WRITE_PAGE 128
    #endif
  
    #ifndef FLASH_ERASE_PAGE
      #if IS_Kxx_FAMILY
        #define FLASH_ERASE_PAGE 2048
      #elif IS_KLx_FAMILY
        #define FLASH_ERASE_PAGE 1024
      #elif IS_KMx_FAMILY
        #define FLASH_ERASE_PAGE 1024     
      #elif IS_KEx_FAMILY
        #define FLASH_ERASE_PAGE 512   
      #endif
    #endif

#endif 

//  default values of GPIO Alternatives of the port  (Alternative to UART)
#ifndef BOOT_UART_GPIO_PORT
  #define BOOT_UART_GPIO_PORT   PORTC_BASE_PTR
  
  #if !defined(BOOT_UART_GPIO_PORT_RX) && (!defined(BOOT_UART_GPIO_PORT_TX))
    #warning  There is missing define of Kinetis GPIO port. It sets to default: 'PORTC_BASE_PTR'!
  #endif

#endif

#ifndef BOOT_UART_GPIO_PORT_RX
  #define BOOT_UART_GPIO_PORT_RX   BOOT_UART_GPIO_PORT 
#endif 

#ifndef BOOT_UART_GPIO_PORT_TX
  #define BOOT_UART_GPIO_PORT_TX   BOOT_UART_GPIO_PORT 
#endif 


#ifndef BOOT_UART_GPIO_PIN_RX
  #define BOOT_UART_GPIO_PIN_RX 16
  #warning  There is missing define of Kinetis GPIO pin for UART Rx. It sets to default: 'PTC16'!
#endif

#ifndef BOOT_UART_GPIO_PIN_TX
  #define BOOT_UART_GPIO_PIN_TX 17
  #warning  There is missing define of Kinetis GPIO pin for UART Tx. It sets to default: 'PTC17'!
#endif

#define GPIO_RX_MASK   (0x01 << BOOT_UART_GPIO_PIN_RX) 

//  PIN alternative definition
#ifndef BOOT_PIN_UART_ALTERNATIVE
  #define BOOT_PIN_UART_ALTERNATIVE 3 
  #warning There is missing define of Kinetis pin BOOT_PIN_UART_ALTERNATIVE for PORT_PCR_MUX. It sets to default: '3'!
#endif

//  PIN alternative definition
#ifndef BOOT_PIN_GPIO_ALTERNATIVE
  #define BOOT_PIN_GPIO_ALTERNATIVE 1 
  #warning There is missing define of Kinetis pin PIN_ALTERNATIVE for BOOT_PIN_GPIO_ALTERNATIVE. It sets to default: '1'!
#endif

#ifndef BOOT_UART_BASE
  #define BOOT_UART_BASE UART3_BASE_PTR 
  #warning  There is missing define of BOOT_UART_BASE. It sets to default UART3_BASE_PTR!
#endif

#ifndef BOOT_UART_BAUD_RATE
  #define BOOT_UART_BAUD_RATE 115200
  #warning  There is missing define of BOOT_UART_BAUD_RATE. It sets to default 115200!
#endif

//  init macro for multiplexer setting - alternative UART
#define BOOT_PIN_INIT_AS_UART PORT_PCR_REG(BOOT_UART_GPIO_PORT_RX, BOOT_UART_GPIO_PIN_RX) = PORT_PCR_MUX(BOOT_PIN_UART_ALTERNATIVE); PORT_PCR_REG(BOOT_UART_GPIO_PORT_TX, BOOT_UART_GPIO_PIN_TX) = PORT_PCR_MUX(BOOT_PIN_UART_ALTERNATIVE);
//  init macro for multiplexer setting - alternative GPIO
#define BOOT_PIN_INIT_AS_GPIO PORT_PCR_REG(BOOT_UART_GPIO_PORT_RX, BOOT_UART_GPIO_PIN_RX) = PORT_PCR_MUX(BOOT_PIN_GPIO_ALTERNATIVE);


//  Trim auto calibration 
//  Trim register
#define TRIM_REG  MCG_C3

//      As calibration impulse can be used break impulse with 10 bits or zero impulse with 9bit. Reason is impossibility of using break impulse on the USB VIRTUAL SERIAL LINK   
#if (BOOTLOADER_SHORT_TRIM == 1) 
  #define CALIB_PULSE_LENGTH  (BOOT_BUS_CLOCK / (BOOT_UART_BAUD_RATE / 9))
#else
  #define CALIB_PULSE_LENGTH  (BOOT_BUS_CLOCK / (BOOT_UART_BAUD_RATE / 10))
#endif

#define BAUDRATE_ONE_PERCENT_ERROR (CALIB_PULSE_LENGTH / 75)


//      initialization for boot pin enable (MUX - GPIO alternative & PE - pull-up enable)      
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

#if IS_Kxx_FAMILY
  // Bus clock frequency
#ifdef KINETIS_K60_OM33Z
  #define BOOT_BUS_CLOCK        25000000
#else
  #define BOOT_BUS_CLOCK        (48000000)//(32768 * 640)
#endif

  #ifndef  MC_SRSL
    #define SRS_REG               RCM_SRS0
    #define SRS_POR_MASK          RCM_SRS0_POR_MASK
  #else
    #define SRS_REG               MC_SRSL
    #define SRS_POR_MASK          MC_SRSL_POR_MASK
  #endif
  
  #if (KINETIS_MODEL == K70_120MHz) || (KINETIS_MODEL == K22_100MHz)
    #define FLASH_INIT_FLASH_CLOCK SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(1);
    #define FLASH_BASE_PTR                FTFE_BASE_PTR
    #define FLASH_FSTAT                   FTFE_FSTAT                                  
    #define FLASH_FSTAT_CCIF_MASK         FTFE_FSTAT_CCIF_MASK
    #define FLASH_FSTAT_ACCERR_MASK       FTFE_FSTAT_ACCERR_MASK
    #define FLASH_FSTAT_FPVIOL_MASK       FTFE_FSTAT_FPVIOL_MASK
    #define FLASH_FSTAT_RDCOLERR_MASK     FTFE_FSTAT_RDCOLERR_MASK
    #define FLASH_FSTAT_MGSTAT0_MASK      FTFE_FSTAT_MGSTAT0_MASK 

    #define FLASH_PROGRAM                 FLASH_ProgramSectionByPhrases

  #else
    #define FLASH_INIT_FLASH_CLOCK SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(1);
    #define FLASH_BASE_PTR                FTFL_BASE_PTR
    #define FLASH_FSTAT                   FTFL_FSTAT                                  
    #define FLASH_FSTAT_CCIF_MASK         FTFL_FSTAT_CCIF_MASK
    #define FLASH_FSTAT_ACCERR_MASK       FTFL_FSTAT_ACCERR_MASK
    #define FLASH_FSTAT_FPVIOL_MASK       FTFL_FSTAT_FPVIOL_MASK
    #define FLASH_FSTAT_RDCOLERR_MASK     FTFL_FSTAT_RDCOLERR_MASK
    #define FLASH_FSTAT_MGSTAT0_MASK      FTFL_FSTAT_MGSTAT0_MASK 

    #define FLASH_PROGRAM                 FLASH_ProgramSectionByLongs

  #endif

  #define INIT_CLOCKS_TO_MODULES    SIM_SCGC1 |= 0xffffffff; \
                                    SIM_SCGC4 |= 0xffffffff; \
                                    SIM_SCGC5 |= 0xffffffff; \
                                    SIM_SCGC6 |= 0xffffffff;
                                                                        
#elif IS_KLx_FAMILY
                                    
  // Bus clock frequency
  #define BOOT_BUS_CLOCK        (48000000)      //(32768*640)
  #define SRS_REG               RCM_SRS0
  #define SRS_POR_MASK          RCM_SRS0_POR_MASK
  
  #define FLASH_INIT_FLASH_CLOCK        ;//SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(2);
  #define FLASH_BASE_PTR                FTFA_BASE_PTR
  #define FLASH_FSTAT                   FTFA_FSTAT                                  
  #define FLASH_FSTAT_CCIF_MASK         FTFA_FSTAT_CCIF_MASK
  #define FLASH_FSTAT_ACCERR_MASK       FTFA_FSTAT_ACCERR_MASK
  #define FLASH_FSTAT_FPVIOL_MASK       FTFA_FSTAT_FPVIOL_MASK
  #define FLASH_FSTAT_RDCOLERR_MASK     FTFA_FSTAT_RDCOLERR_MASK
  #define FLASH_FSTAT_MGSTAT0_MASK      FTFA_FSTAT_MGSTAT0_MASK                            
  
  #define FLASH_PROGRAM                 FLASH_ProgramSectionByLongs                                  
                                    
  #define INIT_CLOCKS_TO_MODULES    SIM_SOPT2 = SIM_SOPT2_UART0SRC(1);\
                                    SIM_SCGC4 |= (SIM_SCGC4_UART0_MASK | SIM_SCGC4_UART1_MASK | SIM_SCGC4_UART2_MASK); \
                                    SIM_SCGC5 |= 0xffffffff; \
                                    SIM_SCGC6 |= SIM_SCGC6_FTF_MASK;

#elif IS_KMx_FAMILY
                                    
  // Bus clock frequency
  #define BOOT_BUS_CLOCK        4000000
  #define SRS_REG               RCM_SRS0
  #define SRS_POR_MASK          RCM_SRS0_POR_MASK
  
  #define FLASH_INIT_FLASH_CLOCK        ;//SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(2);
  #define FLASH_BASE_PTR                FTFA_BASE_PTR
  #define FLASH_FSTAT                   FTFA_FSTAT                                  
  #define FLASH_FSTAT_CCIF_MASK         FTFA_FSTAT_CCIF_MASK
  #define FLASH_FSTAT_ACCERR_MASK       FTFA_FSTAT_ACCERR_MASK
  #define FLASH_FSTAT_FPVIOL_MASK       FTFA_FSTAT_FPVIOL_MASK
  #define FLASH_FSTAT_RDCOLERR_MASK     FTFA_FSTAT_RDCOLERR_MASK
  #define FLASH_FSTAT_MGSTAT0_MASK      FTFA_FSTAT_MGSTAT0_MASK                            
  
  #define FLASH_PROGRAM                 FLASH_ProgramSectionByLongs                                  
                                    
  #define INIT_CLOCKS_TO_MODULES    SIM_CLKDIV1 = 0;\
                                    MCG_SC = 0; \
                                    SIM_SCGC4 |= (SIM_SCGC4_UART0_MASK | SIM_SCGC4_UART1_MASK | SIM_SCGC4_UART2_MASK | SIM_SCGC4_UART3_MASK); \
                                    SIM_SCGC5 |= 0xffffffff; \
                                    SIM_SCGC6 |= (SIM_SCGC6_CRC_MASK);  
                                    
#elif IS_KEx_FAMILY
                                    
  // Bus clock frequency
  #define BOOT_BUS_CLOCK        (32768*640)
  #define SRS_REG               (SIM_SRSID)
  #define SRS_POR_MASK          SIM_SRSID_POR_MASK
  
  #define FLASH_INIT_FLASH_CLOCK        FTMRH_FCLKDIV = 0x93;//SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(2);
  #define FLASH_BASE_PTR                FTMRH_BASE_PTR
  #define FLASH_FSTAT                   FTMRH_FSTAT                                  
  #define FLASH_FSTAT_CCIF_MASK         FTMRH_FSTAT_CCIF_MASK
  #define FLASH_FSTAT_ACCERR_MASK       FTMRH_FSTAT_ACCERR_MASK
  #define FLASH_FSTAT_FPVIOL_MASK       FTMRH_FSTAT_FPVIOL_MASK
                          
  
  #define FLASH_PROGRAM                 FLASH_ProgramSectionByLongs                                  
                                   
  #define INIT_CLOCKS_TO_MODULES    SIM_SCGC |= SIM_SCGC_UART1_MASK;
                                    
#endif



#endif //KINETIS_PARAMS_H
