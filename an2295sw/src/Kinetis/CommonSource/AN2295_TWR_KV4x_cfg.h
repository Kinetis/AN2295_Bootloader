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

#include "MKV46F15.h"

#define FLASH_PROT_SECTION 0x4000

// Bus clock frequency
#define BOOT_BUS_CLOCK        (32768*640)              //(48000000)      //

/** Kinetis Flash memory size */

#define KINETIS_FLASH FLASH_256K

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

#define BOOT_UART_GPIO_PORT PORTE_BASE_PTR

/*  setting of multiplexer for UART alternative of pin */
#define BOOT_PIN_UART_ALTERNATIVE 3

/*  setting of multiplexer for GPIO alternative of pin */
#define BOOT_PIN_GPIO_ALTERNATIVE 1

#define BOOT_UART_GPIO_PIN_RX   1  

#define BOOT_UART_GPIO_PIN_TX   0  

/**************************************************/
/* Actual used PIN reset setting */
#define BOOT_PIN_ENABLE_PORT_BASE  PORTC_BASE_PTR   

#define BOOT_PIN_ENABLE_GPIO_BASE  PTC_BASE_PTR   

#define BOOT_PIN_ENABLE_NUM        7          


/**************************************************/
/** BOOTLOADER FEATURES SETTINGS */
#define BOOTLOADER_ENABLE_READ_CMD  1

#define BOOTLOADER_INT_WATCHDOG     0

#define BOOTLOADER_ENABLE_VERIFY    1

#define BOOTLOADER_CRC_ENABLE       1

#define BOOTLOADER_AUTO_TRIMMING    1 

#define BOOTLOADER_PIN_ENABLE       0
/**************************************************/
/** CALIBRATION OF BOOTLOADER TRIM SETTINGS */
#define BOOT_CALIBRATION_GPIO_BASE  PTC_BASE_PTR

/* Description string */
#define KINETIS_MODEL_STR "KV4"

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
                                    
  #define INIT_CLOCKS_TO_MODULES    SIM_SCGC4 |= (SIM_SCGC4_UART0_MASK | SIM_SCGC4_UART1_MASK ); \
                                    SIM_SCGC5 |= 0xffffffff; \
                                    SIM_SCGC6 |= SIM_SCGC6_FTF_MASK;

/******************************************************************************
*
*
*     Advanced detail settings for non standard settings
*
*
******************************************************************************/

#define WDG_Disable()         WDOG_UNLOCK = 0xC520;  WDOG_UNLOCK = 0xD928; WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;               /* Disable watchdog */ 
#define WDG_Enable()          //WDOG_UNLOCK = 0xC520;  WDOG_UNLOCK = 0xD928; WDOG_STCTRLH |= WDOG_STCTRLH_WDOGEN_MASK;               /* Enable watchdog Already enabled*/ 
#define WDG_Refresh()         WDOG_REFRESH = 0xA602; WDOG_REFRESH = 0xB480;


/* Flash block count of this MCU */
#define FLASH_BLOCK_CNT 1

/* Start address of interrupt vector table */ 
#define INTERRUPT_VECTORS 0x0000

/* Start address of relocated interrutp vector table */
#define RELOCATED_VECTORS 0x4000 

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
#define FLASH_ERASE_PAGE 4096

/* Maximal length of ID_STRING */
//#define ID_STRING_MAX 5


