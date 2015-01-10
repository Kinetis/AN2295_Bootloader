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


#define KINETIS_MODEL KL25_48MHz

/*  in the case of using USB VIRTUAL SERIAL LINK you must activate No break TRIM CHECKBOX in the master AN2295 PC Application  */
/*  the break impulse is replaced by using only 9 bits zero impulse  */
//  BREAK IMPULSE       |START| |0| |0| |0| |0| |0| |0| |0| |0| |0| |0| STOP|
//  ZERO IMPULSE        |START| |0| |0| |0| |0| |0| |0| |0| |0| |0| |STOP|
#define BOOTLOADER_SHORT_TRIM  1

/** Kinetis Flash memory size */

#define KINETIS_FLASH FLASH_128K

/** Bootloader flash protection */
#define BOOTLOADER_FLASH_PROTECTION 0

/** Boot timeout after POR (Power On Reset) for wait to connect Master **/
/** BOOT_WAITING_TIMEOUT * 10ms **/
#define BOOT_WAITING_TIMEOUT 100

/**************************************************/
/* Actual used UART module */
#define BOOT_UART_BASE UART0_BASE_PTR

/* Actual used UART module */
/* A range of UART baudrates is (9600 - 115200) */
#define BOOT_UART_BAUD_RATE  115200

/** GPIO & UART pins initialization */

#define BOOT_UART_GPIO_PORT PORTA_BASE_PTR

/*  setting of multiplexer for UART alternative of pin */
#define BOOT_PIN_UART_ALTERNATIVE 3

/*  setting of multiplexer for GPIO alternative of pin */
#define BOOT_PIN_GPIO_ALTERNATIVE 1

#define BOOT_UART_GPIO_PIN_RX   15  

#define BOOT_UART_GPIO_PIN_TX   14  

/**************************************************/
/* Actual used PIN reset setting */
#define BOOT_PIN_ENABLE_PORT_BASE  PORTC_BASE_PTR   

#define BOOT_PIN_ENABLE_GPIO_BASE  PTC_BASE_PTR   

#define BOOT_PIN_ENABLE_NUM        9          

/**************************************************/
/** BOOTLOADER FEATURES SETTINGS */
#define BOOTLOADER_ENABLE_READ_CMD  1

#define BOOTLOADER_INT_WATCHDOG     0

#define BOOTLOADER_ENABLE_VERIFY    0

#define BOOTLOADER_CRC_ENABLE       0

#define BOOTLOADER_AUTO_TRIMMING    1 

#define BOOTLOADER_PIN_ENABLE       0
/**************************************************/
/** CALIBRATION OF BOOTLOADER TRIM SETTINGS */
#define BOOT_CALIBRATION_GPIO_BASE  PTA_BASE_PTR
/******************************************************************************
*
*
*     Advanced detail settings for non standard settings
*
*
******************************************************************************/


/* Flash block count of this MCU */
//#define FLASH_BLOCK_CNT 1

/* Start address of interrupt vector table */ 
//#define INTERRUPT_VECTORS 0x0000

/* Start address of relocated interrutp vector table */
//#define RELOCATED_VECTORS 0x4000 

/* Flash start address */
//#define USER_FLASH_START RELOCATED_VECTORS

/* Flash end address */
//#define USER_FLASH_END 0x0003FFFF

/* Flash2 start address */
//#define USER_FLASH_START_2 0x00040000

/* Flash2 end address */
//#define USER_FLASH_END_2 0x0005FFFF

/* Size of write block */
//#define FLASH_WRITE_PAGE 128

/* Size of erase block */
//#define FLASH_ERASE_PAGE 2048

/* Maximal length of ID_STRING */
//#define ID_STRING_MAX 5

/* Description string */
//#define KINETIS_MODEL_STR "K53"
