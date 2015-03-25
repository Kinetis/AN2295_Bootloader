/**************************************************/
/** USER SETTINGS OF KINETIS MCU */
/**  Kinetis ARM Cortex-M4 model */
//K10_50MHz K11_50MHz K12_50MHz K10_72MHz K10_100MHz K10_120MHz 
//K20_50MHz K21_50MHz K22_50MHz K20_72MHz K20_100MHz K20_120MHz 
//K30_72MHz K30_100MHz 
//K40_72MHz K40_100MHz 
//K50_72MHz K51_72MHz K50_100MHz 
//K60_100MHz K60_120MHz 
//K70_120MHz

/**  Kinetis ARM Cortex-M0+ model */
//KL0_48MHz
//KL1_48MHz
//KL2_48MHz KL25_48MHz

#include "MKE02Z2.h"


#define KINETIS_MODEL KE02_20MHz

#define FLASH_PROT_SECTION (0x1000)

#define BOOT_BUS_CLOCK     (31250*512)

/** Kinetis Flash memory size */

#define KINETIS_FLASH FLASH_64K

/** Bootloader flash protection */
#define BOOTLOADER_FLASH_PROTECTION 0

/** Boot timeout after POR (Power On Reset) for wait to connect Master **/
/** BOOT_WAITING_TIMEOUT * 10ms **/
#define BOOT_WAITING_TIMEOUT 1000

/**************************************************/
/* Actual used UART module */
#define BOOT_UART_BASE UART1_BASE_PTR

/* Actual used UART module */
/* A range of UART baudrates is (9600 - 115200) */
#define BOOT_UART_BAUD_RATE  9600 

/** GPIO & UART pins initialization */

#define BOOT_UART_GPIO_PORT PORTC_BASE_PTR

/*  setting of multiplexer for UART alternative of pin */
#define BOOT_PIN_UART_ALTERNATIVE 2

/*  setting of multiplexer for GPIO alternative of pin */
#define BOOT_PIN_GPIO_ALTERNATIVE 1

#define BOOT_UART_GPIO_PIN_RX   6  

#define BOOT_UART_GPIO_PIN_TX   7  

/**************************************************/
/* Actual used PIN reset setting */
#define BOOT_PIN_ENABLE_PORT_BASE  PORTA_BASE_PTR   

#define BOOT_PIN_ENABLE_GPIO_BASE  PTA_BASE_PTR   

#define BOOT_PIN_ENABLE_NUM        0          

/**************************************************/
/** BOOTLOADER FEATURES SETTINGS */
#define BOOTLOADER_ENABLE_READ_CMD  1

#define BOOTLOADER_INT_WATCHDOG     0

#define BOOTLOADER_ENABLE_VERIFY    1

#define BOOTLOADER_CRC_ENABLE       0

#define BOOTLOADER_AUTO_TRIMMING    1 

#define BOOTLOADER_PIN_ENABLE       0
/**************************************************/
/** CALIBRATION OF BOOTLOADER TRIM SETTINGS */
#define BOOT_CALIBRATION_GPIO_BASE  PTA_BASE_PTR

/* Description string */
#define KINETIS_MODEL_STR "KE0"

//Register

  // Bus clock frequency
  
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
/******************************************************************************
*
*
*     Advanced detail settings for non standard settings
*
*
******************************************************************************/


#define WDG_Disable();		WDOG_CS1 = 0x20;WDOG_CS2 = 0;WDOG_TOVALH = 0xFF; WDOG_TOVALL = 0xFF; WDOG_WINH = 0xFF; WDOG_WINL = 0xFF; WDOG_CS2 = 0x20;
#define WDG_Enable(); 


/* Flash block count of this MCU */
#define FLASH_BLOCK_CNT 1

/* Start address of interrupt vector table */ 
#define INTERRUPT_VECTORS 0x0000

/* Start address of relocated interrutp vector table */
#define RELOCATED_VECTORS 0x1000 

/* Flash start address */
#define USER_FLASH_START RELOCATED_VECTORS

/* Flash end address */
#define USER_FLASH_END (KINETIS_FLASH - 1)

/* Flash2 start address */
//#define USER_FLASH_START_2 0x00040000

/* Flash2 end address */
//#define USER_FLASH_END_2 0x0005FFFF

/* Size of write block */
#define FLASH_WRITE_PAGE 128

/* Size of erase block */
#define FLASH_ERASE_PAGE 512

/* Maximal length of ID_STRING */
//#define ID_STRING_MAX 5


