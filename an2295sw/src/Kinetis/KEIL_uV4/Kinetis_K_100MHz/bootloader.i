#line 1 "..\\CommonSource\\bootloader\\bootloader.c"
 


















 











 

#line 1 "..\\CommonSource\\bootloader\\bootloader.h"



















 











 






 
#line 1 "..\\CommonSource\\bootloader\\kinetis_params.h"



















 











 




#line 1 "..\\CommonSource\\bootloader_cfg.h"



















 











 





#line 57 "..\\CommonSource\\bootloader_cfg.h"
  
  
#line 1 "..\\CommonSource\\AN2295_TWR_K60_cfg.h"
 
 
 








 









 
 





 



 


 
 


 
 


 
 


 



 


 






 
 







 
 











 
 







 


 


  


 


 


 


 


 


 


 


 


 

#line 60 "..\\CommonSource\\bootloader_cfg.h"
  
  
  


#line 38 "..\\CommonSource\\bootloader\\kinetis_params.h"




#line 48 "..\\CommonSource\\bootloader\\kinetis_params.h"

#line 56 "..\\CommonSource\\bootloader\\kinetis_params.h"


















#line 80 "..\\CommonSource\\bootloader\\kinetis_params.h"
















#line 103 "..\\CommonSource\\bootloader\\kinetis_params.h"

























#line 136 "..\\CommonSource\\bootloader\\kinetis_params.h"

 
#line 1 "..\\CommonSource\\main.h"



















 











 




  
  #pragma anon_unions


#line 1 "..\\CommonSource\\headers\\MK60DZ10.h"















































 








 




 

 




 





#line 1 "C:\\Keil_ARM4\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 










#line 26 "C:\\Keil_ARM4\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 197 "C:\\Keil_ARM4\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 261 "C:\\Keil_ARM4\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"



 



#line 76 "..\\CommonSource\\headers\\MK60DZ10.h"

 








 




 




 

 
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                 
  INT_Initial_Program_Counter  = 1,                 
  INT_NMI                      = 2,                 
  INT_Hard_Fault               = 3,                 
  INT_Mem_Manage_Fault         = 4,                 
  INT_Bus_Fault                = 5,                 
  INT_Usage_Fault              = 6,                 
  INT_Reserved7                = 7,                 
  INT_Reserved8                = 8,                 
  INT_Reserved9                = 9,                 
  INT_Reserved10               = 10,                
  INT_SVCall                   = 11,                
  INT_DebugMonitor             = 12,                
  INT_Reserved13               = 13,                
  INT_PendableSrvReq           = 14,                
  INT_SysTick                  = 15,                
  INT_DMA0                     = 16,                
  INT_DMA1                     = 17,                
  INT_DMA2                     = 18,                
  INT_DMA3                     = 19,                
  INT_DMA4                     = 20,                
  INT_DMA5                     = 21,                
  INT_DMA6                     = 22,                
  INT_DMA7                     = 23,                
  INT_DMA8                     = 24,                
  INT_DMA9                     = 25,                
  INT_DMA10                    = 26,                
  INT_DMA11                    = 27,                
  INT_DMA12                    = 28,                
  INT_DMA13                    = 29,                
  INT_DMA14                    = 30,                
  INT_DMA15                    = 31,                
  INT_DMA_Error                = 32,                
  INT_MCM                      = 33,                
  INT_FTFL                     = 34,                
  INT_Read_Collision           = 35,                
  INT_LVD_LVW                  = 36,                
  INT_LLW                      = 37,                
  INT_Watchdog                 = 38,                
  INT_RNG                      = 39,                
  INT_I2C0                     = 40,                
  INT_I2C1                     = 41,                
  INT_SPI0                     = 42,                
  INT_SPI1                     = 43,                
  INT_SPI2                     = 44,                
  INT_CAN0_ORed_Message_buffer = 45,                
  INT_CAN0_Bus_Off             = 46,                
  INT_CAN0_Error               = 47,                
  INT_CAN0_Tx_Warning          = 48,                
  INT_CAN0_Rx_Warning          = 49,                
  INT_CAN0_Wake_Up             = 50,                
  INT_Reserved51               = 51,                
  INT_Reserved52               = 52,                
  INT_CAN1_ORed_Message_buffer = 53,                
  INT_CAN1_Bus_Off             = 54,                
  INT_CAN1_Error               = 55,                
  INT_CAN1_Tx_Warning          = 56,                
  INT_CAN1_Rx_Warning          = 57,                
  INT_CAN1_Wake_Up             = 58,                
  INT_Reserved59               = 59,                
  INT_Reserved60               = 60,                
  INT_UART0_RX_TX              = 61,                
  INT_UART0_ERR                = 62,                
  INT_UART1_RX_TX              = 63,                
  INT_UART1_ERR                = 64,                
  INT_UART2_RX_TX              = 65,                
  INT_UART2_ERR                = 66,                
  INT_UART3_RX_TX              = 67,                
  INT_UART3_ERR                = 68,                
  INT_UART4_RX_TX              = 69,                
  INT_UART4_ERR                = 70,                
  INT_UART5_RX_TX              = 71,                
  INT_UART5_ERR                = 72,                
  INT_ADC0                     = 73,                
  INT_ADC1                     = 74,                
  INT_CMP0                     = 75,                
  INT_CMP1                     = 76,                
  INT_CMP2                     = 77,                
  INT_FTM0                     = 78,                
  INT_FTM1                     = 79,                
  INT_FTM2                     = 80,                
  INT_CMT                      = 81,                
  INT_RTC                      = 82,                
  INT_Reserved83               = 83,                
  INT_PIT0                     = 84,                
  INT_PIT1                     = 85,                
  INT_PIT2                     = 86,                
  INT_PIT3                     = 87,                
  INT_PDB0                     = 88,                
  INT_USB0                     = 89,                
  INT_USBDCD                   = 90,                
  INT_ENET_1588_Timer          = 91,                
  INT_ENET_Transmit            = 92,                
  INT_ENET_Receive             = 93,                
  INT_ENET_Error               = 94,                
  INT_I2S0                     = 95,                
  INT_SDHC                     = 96,                
  INT_DAC0                     = 97,                
  INT_DAC1                     = 98,                
  INT_TSI0                     = 99,                
  INT_MCG                      = 100,               
  INT_LPTimer                  = 101,               
  INT_Reserved102              = 102,               
  INT_PORTA                    = 103,               
  INT_PORTB                    = 104,               
  INT_PORTC                    = 105,               
  INT_PORTD                    = 106,               
  INT_PORTE                    = 107,               
  INT_Reserved108              = 108,               
  INT_Reserved109              = 109,               
  INT_Reserved110              = 110,               
  INT_Reserved111              = 111,               
  INT_Reserved112              = 112,               
  INT_Reserved113              = 113,               
  INT_Reserved114              = 114,               
  INT_Reserved115              = 115,               
  INT_Reserved116              = 116,               
  INT_Reserved117              = 117,               
  INT_Reserved118              = 118,               
  INT_Reserved119              = 119                
} IRQInterruptIndex;



   




 




 




 





   








 




 

 
typedef struct ADC_MemMap {
  uint32_t SC1[2];                                  
  uint32_t CFG1;                                    
  uint32_t CFG2;                                    
  uint32_t R[2];                                    
  uint32_t CV1;                                     
  uint32_t CV2;                                     
  uint32_t SC2;                                     
  uint32_t SC3;                                     
  uint32_t OFS;                                     
  uint32_t PG;                                      
  uint32_t MG;                                      
  uint32_t CLPD;                                    
  uint32_t CLPS;                                    
  uint32_t CLP4;                                    
  uint32_t CLP3;                                    
  uint32_t CLP2;                                    
  uint32_t CLP1;                                    
  uint32_t CLP0;                                    
  uint32_t PGA;                                     
  uint32_t CLMD;                                    
  uint32_t CLMS;                                    
  uint32_t CLM4;                                    
  uint32_t CLM3;                                    
  uint32_t CLM2;                                    
  uint32_t CLM1;                                    
  uint32_t CLM0;                                    
} volatile *ADC_MemMapPtr;



 




 


 
#line 328 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 353 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 367 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 377 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 405 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 417 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 



 



 



 



 



 





 



 



 



 



 



 



 






   


 
 

 




 




 


 
 
#line 543 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 572 "..\\CommonSource\\headers\\MK60DZ10.h"

 







   




   




 




 

 
typedef struct AIPS_MemMap {
  uint32_t MPRA;                                    
  uint8_t RESERVED_0[28];
  uint32_t PACRA;                                   
  uint32_t PACRB;                                   
  uint32_t PACRC;                                   
  uint32_t PACRD;                                   
  uint8_t RESERVED_1[16];
  uint32_t PACRE;                                   
  uint32_t PACRF;                                   
  uint32_t PACRG;                                   
  uint32_t PACRH;                                   
  uint32_t PACRI;                                   
  uint32_t PACRJ;                                   
  uint32_t PACRK;                                   
  uint32_t PACRL;                                   
  uint32_t PACRM;                                   
  uint32_t PACRN;                                   
  uint32_t PACRO;                                   
  uint32_t PACRP;                                   
} volatile *AIPS_MemMapPtr;



 




 


 
#line 649 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 701 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 750 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 799 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 848 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 897 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 946 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 995 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1044 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1093 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1142 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1191 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1240 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1289 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1338 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1387 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1436 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1485 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 

 




 




 


 
 
#line 1526 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1544 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct AXBS_MemMap {
  struct {                                          
    uint32_t PRS;                                     
    uint8_t RESERVED_0[12];
    uint32_t CRS;                                     
    uint8_t RESERVED_1[236];
  } SLAVE[5];
  uint8_t RESERVED_0[768];
  uint32_t MGPCR0;                                  
  uint8_t RESERVED_1[252];
  uint32_t MGPCR1;                                  
  uint8_t RESERVED_2[252];
  uint32_t MGPCR2;                                  
  uint8_t RESERVED_3[252];
  uint32_t MGPCR3;                                  
  uint8_t RESERVED_4[252];
  uint32_t MGPCR4;                                  
  uint8_t RESERVED_5[252];
  uint32_t MGPCR5;                                  
} volatile *AXBS_MemMapPtr;



 




 


 
#line 1605 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 1639 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1653 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 






   


 
 




 




 


 
 
#line 1715 "..\\CommonSource\\headers\\MK60DZ10.h"

 





   




   




 




 

 
typedef struct CAN_MemMap {
  uint32_t MCR;                                     
  uint32_t CTRL1;                                   
  uint32_t TIMER;                                   
  uint8_t RESERVED_0[4];
  uint32_t RXMGMASK;                                
  uint32_t RX14MASK;                                
  uint32_t RX15MASK;                                
  uint32_t ECR;                                     
  uint32_t ESR1;                                    
  uint32_t IMASK2;                                  
  uint32_t IMASK1;                                  
  uint32_t IFLAG2;                                  
  uint32_t IFLAG1;                                  
  uint32_t CTRL2;                                   
  uint32_t ESR2;                                    
  uint8_t RESERVED_1[8];
  uint32_t CRCR;                                    
  uint32_t RXFGMASK;                                
  uint32_t RXFIR;                                   
  uint8_t RESERVED_2[48];
  struct {                                          
    uint32_t CS;                                      
    uint32_t ID;                                      
    uint32_t WORD0;                                   
    uint32_t WORD1;                                   
  } MB[16];
  uint8_t RESERVED_3[1792];
  uint32_t RXIMR[16];                               
} volatile *CAN_MemMapPtr;



 




 


 
#line 1804 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 1860 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1898 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 
#line 1921 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1959 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 1984 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 1999 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2007 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2014 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 2038 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2048 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2061 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2074 "..\\CommonSource\\headers\\MK60DZ10.h"
 






   


 
 

 




 




 


 
 
#line 2199 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2297 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 2309 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct CAU_MemMap {
  uint32_t DIRECT[16];                              
  uint8_t RESERVED_0[2048];
  uint32_t LDR_CASR;                                
  uint32_t LDR_CAA;                                 
  uint32_t LDR_CA[9];                               
  uint8_t RESERVED_1[20];
  uint32_t STR_CASR;                                
  uint32_t STR_CAA;                                 
  uint32_t STR_CA[9];                               
  uint8_t RESERVED_2[20];
  uint32_t ADR_CASR;                                
  uint32_t ADR_CAA;                                 
  uint32_t ADR_CA[9];                               
  uint8_t RESERVED_3[20];
  uint32_t RADR_CASR;                               
  uint32_t RADR_CAA;                                
  uint32_t RADR_CA[9];                              
  uint8_t RESERVED_4[84];
  uint32_t XOR_CASR;                                
  uint32_t XOR_CAA;                                 
  uint32_t XOR_CA[9];                               
  uint8_t RESERVED_5[20];
  uint32_t ROTL_CASR;                               
  uint32_t ROTL_CAA;                                
  uint32_t ROTL_CA[9];                              
  uint8_t RESERVED_6[276];
  uint32_t AESC_CASR;                               
  uint32_t AESC_CAA;                                
  uint32_t AESC_CA[9];                              
  uint8_t RESERVED_7[20];
  uint32_t AESIC_CASR;                              
  uint32_t AESIC_CAA;                               
  uint32_t AESIC_CA[9];                             
} volatile *CAU_MemMapPtr;



 




 


 
#line 2402 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 2425 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2433 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2441 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2449 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2457 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2465 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2473 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2481 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 2607 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 2618 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct CMP_MemMap {
  uint8_t CR0;                                      
  uint8_t CR1;                                      
  uint8_t FPR;                                      
  uint8_t SCR;                                      
  uint8_t DACCR;                                    
  uint8_t MUXCR;                                    
} volatile *CMP_MemMapPtr;



 




 


 
#line 2665 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 2687 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2702 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 2721 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2729 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2740 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 

 

 




 




 


 
 
#line 2772 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2779 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2786 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct CMT_MemMap {
  uint8_t CGH1;                                     
  uint8_t CGL1;                                     
  uint8_t CGH2;                                     
  uint8_t CGL2;                                     
  uint8_t OC;                                       
  uint8_t MSC;                                      
  uint8_t CMD1;                                     
  uint8_t CMD2;                                     
  uint8_t CMD3;                                     
  uint8_t CMD4;                                     
  uint8_t PPS;                                      
  uint8_t DMA;                                      
} volatile *CMT_MemMapPtr;



 




 


 
#line 2845 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 



 
#line 2883 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 2899 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 





   


 
 




 




 


 
 
#line 2956 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct CRC_MemMap {
  union {                                           
    uint32_t CRC;                                     
    struct {                                          
      uint16_t CRCL;                                    
      uint16_t CRCH;                                    
    } ACCESS16BIT;
    struct {                                          
      uint8_t CRCLL;                                    
      uint8_t CRCLU;                                    
      uint8_t CRCHL;                                    
      uint8_t CRCHU;                                    
    } ACCESS8BIT;
  };
  union {                                           
    uint32_t GPOLY;                                   
    struct {                                          
      uint16_t GPOLYL;                                  
      uint16_t GPOLYH;                                  
    } GPOLY_ACCESS16BIT;
    struct {                                          
      uint8_t GPOLYLL;                                  
      uint8_t GPOLYLU;                                  
      uint8_t GPOLYHL;                                  
      uint8_t GPOLYHU;                                  
    } GPOLY_ACCESS8BIT;
  };
  union {                                           
    uint32_t CTRL;                                    
    struct {                                          
      uint8_t RESERVED_0[3];
      uint8_t CTRLHU;                                   
    } CTRL_ACCESS8BIT;
  };
} volatile *CRC_MemMapPtr;



 




 


 
#line 3040 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 3068 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 



 
#line 3099 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 



 
#line 3136 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3149 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 3187 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct CoreDebug_MemMap {
  union {                                           
    uint32_t base_DHCSR_Read;                         
    uint32_t base_DHCSR_Write;                        
  };
  uint32_t base_DCRSR;                              
  uint32_t base_DCRDR;                              
  uint32_t base_DEMCR;                              
} volatile *CoreDebug_MemMapPtr;



 




 


 








   




 




 




   


 
 




 




 


 
 








   




   




 




 

 
typedef struct DAC_MemMap {
  struct {                                          
    uint8_t DATL;                                     
    uint8_t DATH;                                     
  } DAT[16];
  uint8_t SR;                                       
  uint8_t C0;                                       
  uint8_t C1;                                       
  uint8_t C2;                                       
} volatile *DAC_MemMapPtr;



 




 


 
#line 3325 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 
#line 3355 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3372 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3383 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3390 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 

 




 




 


 
 
#line 3450 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3487 "..\\CommonSource\\headers\\MK60DZ10.h"

 







   




   




 




 

 
typedef struct DMA_MemMap {
  uint32_t CR;                                      
  uint32_t ES;                                      
  uint8_t RESERVED_0[4];
  uint32_t ERQ;                                     
  uint8_t RESERVED_1[4];
  uint32_t EEI;                                     
  uint8_t CEEI;                                     
  uint8_t SEEI;                                     
  uint8_t CERQ;                                     
  uint8_t SERQ;                                     
  uint8_t CDNE;                                     
  uint8_t SSRT;                                     
  uint8_t CERR;                                     
  uint8_t CINT;                                     
  uint8_t RESERVED_2[4];
  uint32_t INT;                                     
  uint8_t RESERVED_3[4];
  uint32_t ERR;                                     
  uint8_t RESERVED_4[4];
  uint32_t HRS;                                     
  uint8_t RESERVED_5[200];
  uint8_t DCHPRI3;                                  
  uint8_t DCHPRI2;                                  
  uint8_t DCHPRI1;                                  
  uint8_t DCHPRI0;                                  
  uint8_t DCHPRI7;                                  
  uint8_t DCHPRI6;                                  
  uint8_t DCHPRI5;                                  
  uint8_t DCHPRI4;                                  
  uint8_t DCHPRI11;                                 
  uint8_t DCHPRI10;                                 
  uint8_t DCHPRI9;                                  
  uint8_t DCHPRI8;                                  
  uint8_t DCHPRI15;                                 
  uint8_t DCHPRI14;                                 
  uint8_t DCHPRI13;                                 
  uint8_t DCHPRI12;                                 
  uint8_t RESERVED_6[3824];
  struct {                                          
    uint32_t SADDR;                                   
    uint16_t SOFF;                                    
    uint16_t ATTR;                                    
    union {                                           
      uint32_t NBYTES_MLNO;                             
      uint32_t NBYTES_MLOFFNO;                          
      uint32_t NBYTES_MLOFFYES;                         
    };
    uint32_t SLAST;                                   
    uint32_t DADDR;                                   
    uint16_t DOFF;                                    
    union {                                           
      uint16_t CITER_ELINKYES;                          
      uint16_t CITER_ELINKNO;                           
    };
    uint32_t DLAST_SGA;                               
    uint16_t CSR;                                     
    union {                                           
      uint16_t BITER_ELINKNO;                           
      uint16_t BITER_ELINKYES;                          
    };
  } TCD[16];
} volatile *DMA_MemMapPtr;



 




 


 
#line 3635 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 3667 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3693 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3726 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3759 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3767 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3775 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3783 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3791 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3799 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3807 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3815 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3823 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3856 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3889 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3922 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3930 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3938 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3946 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3954 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3962 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3970 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3978 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3986 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 3994 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4002 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4010 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4018 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4026 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4034 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4042 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4050 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 4071 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 4083 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 4094 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 4115 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 



 
#line 4148 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 
#line 4163 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 4456 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 4473 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[16];                                
} volatile *DMAMUX_MemMapPtr;



 




 


 




   




 




 

 
#line 4533 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 4571 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct DWT_MemMap {
  uint32_t CTRL;                                    
  uint32_t CYCCNT;                                  
  uint32_t CPICNT;                                  
  uint32_t EXCCNT;                                  
  uint32_t SLEEPCNT;                                
  uint32_t LSUCNT;                                  
  uint32_t FOLDCNT;                                 
  uint32_t PCSR;                                    
  struct {                                          
    uint32_t COMP;                                    
    uint32_t MASK;                                    
    uint32_t FUNCTION;                                
    uint8_t RESERVED_0[4];
  } COMPARATOR[4];
  uint8_t RESERVED_0[3952];
  uint32_t PID4;                                    
  uint32_t PID5;                                    
  uint32_t PID6;                                    
  uint32_t PID7;                                    
  uint32_t PID0;                                    
  uint32_t PID1;                                    
  uint32_t PID2;                                    
  uint32_t PID3;                                    
  uint32_t CID0;                                    
  uint32_t CID1;                                    
  uint32_t CID2;                                    
  uint32_t CID3;                                    
} volatile *DWT_MemMapPtr;



 




 


 
#line 4659 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 4728 "..\\CommonSource\\headers\\MK60DZ10.h"

 






   




   




 




 

 
typedef struct ENET_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t EIR;                                     
  uint32_t EIMR;                                    
  uint8_t RESERVED_1[4];
  uint32_t RDAR;                                    
  uint32_t TDAR;                                    
  uint8_t RESERVED_2[12];
  uint32_t ECR;                                     
  uint8_t RESERVED_3[24];
  uint32_t MMFR;                                    
  uint32_t MSCR;                                    
  uint8_t RESERVED_4[28];
  uint32_t MIBC;                                    
  uint8_t RESERVED_5[28];
  uint32_t RCR;                                     
  uint8_t RESERVED_6[60];
  uint32_t TCR;                                     
  uint8_t RESERVED_7[28];
  uint32_t PALR;                                    
  uint32_t PAUR;                                    
  uint32_t OPD;                                     
  uint8_t RESERVED_8[40];
  uint32_t IAUR;                                    
  uint32_t IALR;                                    
  uint32_t GAUR;                                    
  uint32_t GALR;                                    
  uint8_t RESERVED_9[28];
  uint32_t TFWR;                                    
  uint8_t RESERVED_10[56];
  uint32_t RDSR;                                    
  uint32_t TDSR;                                    
  uint32_t MRBR;                                    
  uint8_t RESERVED_11[4];
  uint32_t RSFL;                                    
  uint32_t RSEM;                                    
  uint32_t RAEM;                                    
  uint32_t RAFL;                                    
  uint32_t TSEM;                                    
  uint32_t TAEM;                                    
  uint32_t TAFL;                                    
  uint32_t TIPG;                                    
  uint32_t FTRL;                                    
  uint8_t RESERVED_12[12];
  uint32_t TACC;                                    
  uint32_t RACC;                                    
  uint8_t RESERVED_13[56];
  uint32_t RMON_T_DROP;                             
  uint32_t RMON_T_PACKETS;                          
  uint32_t RMON_T_BC_PKT;                           
  uint32_t RMON_T_MC_PKT;                           
  uint32_t RMON_T_CRC_ALIGN;                        
  uint32_t RMON_T_UNDERSIZE;                        
  uint32_t RMON_T_OVERSIZE;                         
  uint32_t RMON_T_FRAG;                             
  uint32_t RMON_T_JAB;                              
  uint32_t RMON_T_COL;                              
  uint32_t RMON_T_P64;                              
  uint32_t RMON_T_P65TO127;                         
  uint32_t RMON_T_P128TO255;                        
  uint32_t RMON_T_P256TO511;                        
  uint32_t RMON_T_P512TO1023;                       
  uint32_t RMON_T_P1024TO2047;                      
  uint32_t RMON_T_P_GTE2048;                        
  uint32_t RMON_T_OCTETS;                           
  uint32_t IEEE_T_DROP;                             
  uint32_t IEEE_T_FRAME_OK;                         
  uint32_t IEEE_T_1COL;                             
  uint32_t IEEE_T_MCOL;                             
  uint32_t IEEE_T_DEF;                              
  uint32_t IEEE_T_LCOL;                             
  uint32_t IEEE_T_EXCOL;                            
  uint32_t IEEE_T_MACERR;                           
  uint32_t IEEE_T_CSERR;                            
  uint32_t IEEE_T_SQE;                              
  uint32_t IEEE_T_FDXFC;                            
  uint32_t IEEE_T_OCTETS_OK;                        
  uint8_t RESERVED_14[12];
  uint32_t RMON_R_PACKETS;                          
  uint32_t RMON_R_BC_PKT;                           
  uint32_t RMON_R_MC_PKT;                           
  uint32_t RMON_R_CRC_ALIGN;                        
  uint32_t RMON_R_UNDERSIZE;                        
  uint32_t RMON_R_OVERSIZE;                         
  uint32_t RMON_R_FRAG;                             
  uint32_t RMON_R_JAB;                              
  uint32_t RMON_R_RESVD_0;                          
  uint32_t RMON_R_P64;                              
  uint32_t RMON_R_P65TO127;                         
  uint32_t RMON_R_P128TO255;                        
  uint32_t RMON_R_P256TO511;                        
  uint32_t RMON_R_P512TO1023;                       
  uint32_t RMON_R_P1024TO2047;                      
  uint32_t RMON_R_P_GTE2048;                        
  uint32_t RMON_R_OCTETS;                           
  uint32_t RMON_R_DROP;                             
  uint32_t RMON_R_FRAME_OK;                         
  uint32_t IEEE_R_CRC;                              
  uint32_t IEEE_R_ALIGN;                            
  uint32_t IEEE_R_MACERR;                           
  uint32_t IEEE_R_FDXFC;                            
  uint32_t IEEE_R_OCTETS_OK;                        
  uint8_t RESERVED_15[284];
  uint32_t ATCR;                                    
  uint32_t ATVR;                                    
  uint32_t ATOFF;                                   
  uint32_t ATPER;                                   
  uint32_t ATCOR;                                   
  uint32_t ATINC;                                   
  uint32_t ATSTMP;                                  
  uint8_t RESERVED_16[488];
  uint32_t TGSR;                                    
  struct {                                          
    uint32_t TCSR;                                    
    uint32_t TCCR;                                    
  } CHANNEL[4];
} volatile *ENET_MemMapPtr;



 




 


 
#line 4979 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 5027 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5060 "..\\CommonSource\\headers\\MK60DZ10.h"
 


 


 
#line 5081 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5100 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5109 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5116 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5148 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5164 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 5175 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5182 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 





 



 



 



 



 



 



 



 



 



 



 



 



 
#line 5259 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5270 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5287 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 
#line 5310 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 5323 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 5333 "..\\CommonSource\\headers\\MK60DZ10.h"
 






   


 
 




 




 


 
 
#line 5461 "..\\CommonSource\\headers\\MK60DZ10.h"

 





   




   




 




 

 
typedef struct ETB_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t RDP;                                     
  uint8_t RESERVED_1[4];
  uint32_t STS;                                     
  uint32_t RRD;                                     
  uint32_t RRP;                                     
  uint32_t RWP;                                     
  uint32_t TRG;                                     
  uint32_t CTL;                                     
  uint32_t RWD;                                     
  uint8_t RESERVED_2[728];
  uint32_t FFSR;                                    
  uint32_t FFCR;                                    
  uint8_t RESERVED_3[3032];
  uint32_t ITMISCOP0;                               
  uint32_t ITTRFLINACK;                             
  uint32_t ITTRFLIN;                                
  uint32_t ITATBDATA0;                              
  uint32_t ITATBCTR2;                               
  uint32_t ITATBCTR1;                               
  uint32_t ITATBCTR0;                               
  uint8_t RESERVED_4[4];
  uint32_t ITCTRL;                                  
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                                
  uint32_t CLAIMCLR;                                
  uint8_t RESERVED_6[8];
  uint32_t LAR;                                     
  uint32_t LSR;                                     
  uint32_t AUTHSTATUS;                              
  uint8_t RESERVED_7[12];
  uint32_t DEVID;                                   
  uint32_t DEVTYPE;                                 
  uint32_t PIDR4;                                   
  uint32_t PIDR5;                                   
  uint32_t PIDR6;                                   
  uint32_t PIDR7;                                   
  uint32_t PIDR0;                                   
  uint32_t PIDR1;                                   
  uint32_t PIDR2;                                   
  uint32_t PIDR3;                                   
  uint32_t CIDR0;                                   
  uint32_t CIDR1;                                   
  uint32_t CIDR2;                                   
  uint32_t CIDR3;                                   
} volatile *ETB_MemMapPtr;



 




 


 
#line 5582 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 5656 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct ETF_MemMap {
  uint32_t FCR;                                     
  uint32_t PCR;                                     
  uint8_t RESERVED_0[3812];
  uint32_t ITATBDATA0;                              
  uint32_t ITATBCTR2;                               
  uint32_t ITATBCTR1;                               
  uint32_t ITATBCTR0;                               
  uint8_t RESERVED_1[4];
  uint32_t ITCTRL;                                  
  uint8_t RESERVED_2[156];
  uint32_t CLAIMSET;                                
  uint32_t CLAIMCLR;                                
  uint8_t RESERVED_3[8];
  uint32_t LAR;                                     
  uint32_t LSR;                                     
  uint32_t AUTHSTATUS;                              
  uint8_t RESERVED_4[12];
  uint32_t DEVID;                                   
  uint32_t DEVTYPE;                                 
  uint32_t PIDR4;                                   
  uint32_t PIDR5;                                   
  uint32_t PIDR6;                                   
  uint32_t PIDR7;                                   
  uint32_t PIDR0;                                   
  uint32_t PIDR1;                                   
  uint32_t PIDR2;                                   
  uint32_t PIDR3;                                   
  uint32_t CIDR0;                                   
  uint32_t CIDR1;                                   
  uint32_t CIDR2;                                   
  uint32_t CIDR3;                                   
} volatile *ETF_MemMapPtr;



 




 


 
#line 5748 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 5811 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct ETM_MemMap {
  uint32_t CR;                                      
  uint32_t CCR;                                     
  uint32_t TRIGGER;                                 
  uint8_t RESERVED_0[4];
  uint32_t SR;                                      
  uint32_t SCR;                                     
  uint8_t RESERVED_1[8];
  uint32_t EEVR;                                    
  uint32_t TECR1;                                   
  uint32_t FFLR;                                    
  uint8_t RESERVED_2[276];
  uint32_t CNTRLDVR1;                               
  uint8_t RESERVED_3[156];
  uint32_t SYNCFR;                                  
  uint32_t IDR;                                     
  uint32_t CCER;                                    
  uint8_t RESERVED_4[4];
  uint32_t TESSEICR;                                
  uint8_t RESERVED_5[4];
  uint32_t TSEVR;                                   
  uint8_t RESERVED_6[4];
  uint32_t TRACEIDR;                                
  uint8_t RESERVED_7[4];
  uint32_t IDR2;                                    
  uint8_t RESERVED_8[264];
  uint32_t PDSR;                                    
  uint8_t RESERVED_9[3016];
  uint32_t ITMISCIN;                                
  uint8_t RESERVED_10[4];
  uint32_t ITTRIGOUT;                               
  uint8_t RESERVED_11[4];
  uint32_t ITATBCTR2;                               
  uint8_t RESERVED_12[4];
  uint32_t ITATBCTR0;                               
  uint8_t RESERVED_13[4];
  uint32_t ITCTRL;                                  
  uint8_t RESERVED_14[156];
  uint32_t CLAIMSET;                                
  uint32_t CLAIMCLR;                                
  uint8_t RESERVED_15[8];
  uint32_t LAR;                                     
  uint32_t LSR;                                     
  uint32_t AUTHSTATUS;                              
  uint8_t RESERVED_16[16];
  uint32_t DEVTYPE;                                 
  uint32_t PIDR4;                                   
  uint32_t PIDR5;                                   
  uint32_t PIDR6;                                   
  uint32_t PIDR7;                                   
  uint32_t PIDR0;                                   
  uint32_t PIDR1;                                   
  uint32_t PIDR2;                                   
  uint32_t PIDR3;                                   
  uint32_t CIDR0;                                   
  uint32_t CIDR1;                                   
  uint32_t CIDR2;                                   
  uint32_t CIDR3;                                   
} volatile *ETM_MemMapPtr;



 




 


 
#line 5943 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 6020 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct EWM_MemMap {
  uint8_t CTRL;                                     
  uint8_t SERV;                                     
  uint8_t CMPL;                                     
  uint8_t CMPH;                                     
} volatile *EWM_MemMapPtr;



 




 


 







   




 




 

 
#line 6085 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 






   


 
 




 




 


 
 







   




   




 




 

 
typedef struct FB_MemMap {
  struct {                                          
    uint32_t CSAR;                                    
    uint32_t CSMR;                                    
    uint32_t CSCR;                                    
  } CS[6];
  uint8_t RESERVED_0[24];
  uint32_t CSPMCR;                                  
} volatile *FB_MemMapPtr;



 




 


 







   




 




 

 



 
#line 6196 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6229 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6245 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 6286 "..\\CommonSource\\headers\\MK60DZ10.h"

 






   




   




 




 

 
typedef struct FMC_MemMap {
  uint32_t PFAPR;                                   
  uint32_t PFB0CR;                                  
  uint32_t PFB1CR;                                  
  uint8_t RESERVED_0[244];
  uint32_t TAGVD[4][8];                             
  uint8_t RESERVED_1[128];
  struct {                                          
    uint32_t DATA_U;                                  
    uint32_t DATA_L;                                  
  } SET[4][8];
} volatile *FMC_MemMapPtr;



 




 


 
#line 6342 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 6398 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6426 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6443 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 



 






   


 
 




 




 


 
 
#line 6578 "..\\CommonSource\\headers\\MK60DZ10.h"

 






   




   




 




 

 
typedef struct FPB_MemMap {
  uint32_t CTRL;                                    
  uint32_t REMAP;                                   
  uint32_t COMP[8];                                 
  uint8_t RESERVED_0[4008];
  uint32_t PID4;                                    
  uint32_t PID5;                                    
  uint32_t PID6;                                    
  uint32_t PID7;                                    
  uint32_t PID0;                                    
  uint32_t PID1;                                    
  uint32_t PID2;                                    
  uint32_t PID3;                                    
  uint32_t CID0;                                    
  uint32_t CID1;                                    
  uint32_t CID2;                                    
  uint32_t CID3;                                    
} volatile *FPB_MemMapPtr;



 




 


 
#line 6649 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 6708 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct FTFL_MemMap {
  uint8_t FSTAT;                                    
  uint8_t FCNFG;                                    
  uint8_t FSEC;                                     
  uint8_t FOPT;                                     
  uint8_t FCCOB3;                                   
  uint8_t FCCOB2;                                   
  uint8_t FCCOB1;                                   
  uint8_t FCCOB0;                                   
  uint8_t FCCOB7;                                   
  uint8_t FCCOB6;                                   
  uint8_t FCCOB5;                                   
  uint8_t FCCOB4;                                   
  uint8_t FCCOBB;                                   
  uint8_t FCCOBA;                                   
  uint8_t FCCOB9;                                   
  uint8_t FCCOB8;                                   
  uint8_t FPROT3;                                   
  uint8_t FPROT2;                                   
  uint8_t FPROT1;                                   
  uint8_t FPROT0;                                   
  uint8_t RESERVED_0[2];
  uint8_t FEPROT;                                   
  uint8_t FDPROT;                                   
} volatile *FTFL_MemMapPtr;



 




 


 
#line 6791 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 6817 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6834 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 6847 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 






   


 
 




 




 


 
 
#line 6967 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct NV_MemMap {
  uint8_t BACKKEY3;                                 
  uint8_t BACKKEY2;                                 
  uint8_t BACKKEY1;                                 
  uint8_t BACKKEY0;                                 
  uint8_t BACKKEY7;                                 
  uint8_t BACKKEY6;                                 
  uint8_t BACKKEY5;                                 
  uint8_t BACKKEY4;                                 
  uint8_t FPROT3;                                   
  uint8_t FPROT2;                                   
  uint8_t FPROT1;                                   
  uint8_t FPROT0;                                   
  uint8_t FSEC;                                     
  uint8_t FOPT;                                     
  uint8_t FEPROT;                                   
  uint8_t FDPROT;                                   
} volatile *NV_MemMapPtr;



 




 


 
#line 7034 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 



 



 



 



 



 



 



 



 



 
#line 7110 "..\\CommonSource\\headers\\MK60DZ10.h"
 




 



 






   


 
 




 




 


 
 
#line 7161 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct FTM_MemMap {
  uint32_t SC;                                      
  uint32_t CNT;                                     
  uint32_t MOD;                                     
  struct {                                          
    uint32_t CnSC;                                    
    uint32_t CnV;                                     
  } CONTROLS[8];
  uint32_t CNTIN;                                   
  uint32_t STATUS;                                  
  uint32_t MODE;                                    
  uint32_t SYNC;                                    
  uint32_t OUTINIT;                                 
  uint32_t OUTMASK;                                 
  uint32_t COMBINE;                                 
  uint32_t DEADTIME;                                
  uint32_t EXTTRIG;                                 
  uint32_t POL;                                     
  uint32_t FMS;                                     
  uint32_t FILTER;                                  
  uint32_t FLTCTRL;                                 
  uint32_t QDCTRL;                                  
  uint32_t CONF;                                    
  uint32_t FLTPOL;                                  
  uint32_t SYNCONF;                                 
  uint32_t INVCTRL;                                 
  uint32_t SWOCTRL;                                 
  uint32_t PWMLOAD;                                 
} volatile *FTM_MemMapPtr;



 




 


 
#line 7248 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 7276 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 7299 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 7324 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7340 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7357 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7374 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7391 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7448 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7455 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7472 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7489 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7504 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7517 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7537 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7554 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7565 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7574 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7605 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7614 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7647 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7666 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 

 

 




 




 


 
 
#line 7731 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7759 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7787 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 7795 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct I2C_MemMap {
  uint8_t A1;                                       
  uint8_t F;                                        
  uint8_t C1;                                       
  uint8_t S;                                        
  uint8_t D;                                        
  uint8_t C2;                                       
  uint8_t FLT;                                      
  uint8_t RA;                                       
  uint8_t SMB;                                      
  uint8_t A2;                                       
  uint8_t SLTH;                                     
  uint8_t SLTL;                                     
} volatile *I2C_MemMapPtr;



 




 


 
#line 7854 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 
#line 7880 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7897 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 7914 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 7932 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 7957 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 






   


 
 

 




 




 


 
 
#line 8005 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8018 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct I2S_MemMap {
  uint32_t TX0;                                     
  uint32_t TX1;                                     
  uint32_t RX0;                                     
  uint32_t RX1;                                     
  uint32_t CR;                                      
  uint32_t ISR;                                     
  uint32_t IER;                                     
  uint32_t TCR;                                     
  uint32_t RCR;                                     
  uint32_t TCCR;                                    
  uint32_t RCCR;                                    
  uint32_t FCSR;                                    
  uint8_t RESERVED_0[8];
  uint32_t ACNT;                                    
  uint32_t ACADD;                                   
  uint32_t ACDAT;                                   
  uint32_t ATAG;                                    
  uint32_t TMSK;                                    
  uint32_t RMSK;                                    
  uint32_t ACCST;                                   
  uint32_t ACCEN;                                   
  uint32_t ACCDIS;                                  
} volatile *I2S_MemMapPtr;



 




 


 
#line 8096 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 



 
#line 8153 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8196 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8247 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8268 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8291 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8305 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8319 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8344 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8358 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 



 



 



 






   


 
 




 




 


 
 
#line 8433 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct ITM_MemMap {
  union {                                           
    uint32_t STIM_READ[32];                           
    uint32_t STIM_WRITE[32];                          
  };
  uint8_t RESERVED_0[3456];
  uint32_t TER;                                     
  uint8_t RESERVED_1[60];
  uint32_t TPR;                                     
  uint8_t RESERVED_2[60];
  uint32_t TCR;                                     
  uint8_t RESERVED_3[300];
  uint32_t LAR;                                     
  uint32_t LSR;                                     
  uint8_t RESERVED_4[24];
  uint32_t PID4;                                    
  uint32_t PID5;                                    
  uint32_t PID6;                                    
  uint32_t PID7;                                    
  uint32_t PID0;                                    
  uint32_t PID1;                                    
  uint32_t PID2;                                    
  uint32_t PID3;                                    
  uint32_t CID0;                                    
  uint32_t CID1;                                    
  uint32_t CID2;                                    
  uint32_t CID3;                                    
} volatile *ITM_MemMapPtr;



 




 


 
#line 8513 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 8631 "..\\CommonSource\\headers\\MK60DZ10.h"

 





   




   




 




 

 
typedef struct LLWU_MemMap {
  uint8_t PE1;                                      
  uint8_t PE2;                                      
  uint8_t PE3;                                      
  uint8_t PE4;                                      
  uint8_t ME;                                       
  uint8_t F1;                                       
  uint8_t F2;                                       
  uint8_t F3;                                       
  uint8_t CS;                                       
} volatile *LLWU_MemMapPtr;



 




 


 
#line 8688 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 8716 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8729 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8742 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8755 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8772 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8789 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8806 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8823 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8830 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 8861 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                     
  uint32_t PSR;                                     
  uint32_t CMR;                                     
  uint32_t CNR;                                     
} volatile *LPTMR_MemMapPtr;



 




 


 







   




 




 

 
#line 8935 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 8944 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 






   


 
 




 




 


 
 







   




   




 




 

 
typedef struct MC_MemMap {
  uint8_t SRSH;                                     
  uint8_t SRSL;                                     
  uint8_t PMPROT;                                   
  uint8_t PMCTRL;                                   
} volatile *MC_MemMapPtr;



 




 


 







   




 




 

 
#line 9043 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9056 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9067 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9076 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 







   




   




 




 

 
typedef struct MCG_MemMap {
  uint8_t C1;                                       
  uint8_t C2;                                       
  uint8_t C3;                                       
  uint8_t C4;                                       
  uint8_t C5;                                       
  uint8_t C6;                                       
  uint8_t S;                                        
  uint8_t RESERVED_0[1];
  uint8_t ATC;                                      
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                    
  uint8_t ATCVL;                                    
} volatile *MCG_MemMapPtr;



 




 


 
#line 9159 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 9187 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9199 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 9214 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9222 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9232 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9248 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9255 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 






   


 
 




 




 


 
 
#line 9295 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                   
  uint16_t PLAMC;                                   
  uint32_t SRAMAP;                                  
  uint32_t ISR;                                     
  uint32_t ETBCC;                                   
  uint32_t ETBRL;                                   
  uint32_t ETBCNT;                                  
} volatile *MCM_MemMapPtr;



 




 


 
#line 9345 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 
#line 9379 "..\\CommonSource\\headers\\MK60DZ10.h"
 




 
#line 9396 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 






   


 
 




 




 


 
 
#line 9433 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct MPU_MemMap {
  uint32_t CESR;                                    
  uint8_t RESERVED_0[12];
  struct {                                          
    uint32_t EAR;                                     
    uint32_t EDR;                                     
  } SP[5];
  uint8_t RESERVED_1[968];
  uint32_t WORD[12][4];                             
  uint8_t RESERVED_2[832];
  uint32_t RGDAAC[12];                              
} volatile *MPU_MemMapPtr;



 




 


 








   




 




 

 
#line 9513 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 9529 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9578 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 9619 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 9712 "..\\CommonSource\\headers\\MK60DZ10.h"

 







   




   




 




 

 
typedef struct NVIC_MemMap {
  uint32_t ISER[4];                                 
  uint8_t RESERVED_0[112];
  uint32_t ICER[4];                                 
  uint8_t RESERVED_1[112];
  uint32_t ISPR[4];                                 
  uint8_t RESERVED_2[112];
  uint32_t ICPR[4];                                 
  uint8_t RESERVED_3[112];
  uint32_t IABR[4];                                 
  uint8_t RESERVED_4[240];
  uint8_t IP[104];                                  
  uint8_t RESERVED_5[2712];
  uint32_t STIR[1];                                 
} volatile *NVIC_MemMapPtr;



 




 


 
#line 9773 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 



 



 
#line 10121 "..\\CommonSource\\headers\\MK60DZ10.h"
 






   


 
 




 




 


 
 
#line 10272 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 10281 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct OSC_MemMap {
  uint8_t CR;                                       
} volatile *OSC_MemMapPtr;



 




 


 




   




 




 

 
#line 10346 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 




   




   




 




 

 
typedef struct PDB_MemMap {
  uint32_t SC;                                      
  uint32_t MOD;                                     
  uint32_t CNT;                                     
  uint32_t IDLY;                                    
  struct {                                          
    uint32_t C1;                                      
    uint32_t S;                                       
    uint32_t DLY[2];                                  
    uint8_t RESERVED_0[24];
  } CH[2];
  uint8_t RESERVED_0[240];
  struct {                                          
    uint32_t INTC;                                    
    uint32_t INT;                                     
  } DAC[2];
  uint8_t RESERVED_1[48];
  uint32_t POEN;                                    
  uint32_t PODLY;                                   
} volatile *PDB_MemMapPtr;



 




 


 
#line 10433 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 10477 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 10499 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 10506 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 




 



 



 
#line 10530 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 10570 "..\\CommonSource\\headers\\MK60DZ10.h"

 








   




   




 




 

 
typedef struct PIT_MemMap {
  uint32_t MCR;                                     
  uint8_t RESERVED_0[252];
  struct {                                          
    uint32_t LDVAL;                                   
    uint32_t CVAL;                                    
    uint32_t TCTRL;                                   
    uint32_t TFLG;                                    
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;



 




 


 








   




 




 

 




 



 



 




 





   


 
 




 




 


 
 
#line 10700 "..\\CommonSource\\headers\\MK60DZ10.h"

 







   




   




 




 

 
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                   
  uint8_t LVDSC2;                                   
  uint8_t REGSC;                                    
} volatile *PMC_MemMapPtr;



 




 


 






   




 




 

 
#line 10774 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 10784 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 10793 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 






   




   




 




 

 
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                 
  uint32_t GPCLR;                                   
  uint32_t GPCHR;                                   
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                    
  uint8_t RESERVED_1[28];
  uint32_t DFER;                                    
  uint32_t DFCR;                                    
  uint32_t DFWR;                                    
} volatile *PORT_MemMapPtr;



 




 


 
#line 10869 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 10907 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 10914 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 10921 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 


 






   


 
 

 

 

 

 




 




 


 
 
#line 11004 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11043 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11082 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11121 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11160 "..\\CommonSource\\headers\\MK60DZ10.h"

 








   




   




 




 

 
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                    
  uint32_t PSOR;                                    
  uint32_t PCOR;                                    
  uint32_t PTOR;                                    
  uint32_t PDIR;                                    
  uint32_t PDDR;                                    
} volatile *GPIO_MemMapPtr;



 




 


 
#line 11214 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 



 



 






   


 
 

 

 

 

 




 




 


 
 
#line 11289 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11296 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11303 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11310 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11317 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct RFSYS_MemMap {
  uint32_t REG[8];                                  
} volatile *RFSYS_MemMapPtr;



 




 


 




   




 




 

 
#line 11382 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 11412 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct RFVBAT_MemMap {
  uint32_t REG[8];                                  
} volatile *RFVBAT_MemMapPtr;



 




 


 




   




 




 

 
#line 11480 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 11510 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct RNG_MemMap {
  uint32_t VER;                                     
  uint32_t CMD;                                     
  uint32_t CR;                                      
  uint32_t SR;                                      
  uint32_t ESR;                                     
  uint32_t OUT;                                     
} volatile *RNG_MemMapPtr;



 




 


 
#line 11560 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 11585 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11596 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11606 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11633 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11644 "..\\CommonSource\\headers\\MK60DZ10.h"
 






   


 
 




 




 


 
 
#line 11676 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct RTC_MemMap {
  uint32_t TSR;                                     
  uint32_t TPR;                                     
  uint32_t TAR;                                     
  uint32_t TCR;                                     
  uint32_t CR;                                      
  uint32_t SR;                                      
  uint32_t LR;                                      
  uint32_t IER;                                     
  uint8_t RESERVED_0[2016];
  uint32_t WAR;                                     
  uint32_t RAR;                                     
} volatile *RTC_MemMapPtr;



 




 


 
#line 11732 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 
#line 11772 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11793 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11802 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11811 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11818 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11835 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 11852 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 11884 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct SDHC_MemMap {
  uint32_t DSADDR;                                  
  uint32_t BLKATTR;                                 
  uint32_t CMDARG;                                  
  uint32_t XFERTYP;                                 
  uint32_t CMDRSP[4];                               
  uint32_t DATPORT;                                 
  uint32_t PRSSTAT;                                 
  uint32_t PROCTL;                                  
  uint32_t SYSCTL;                                  
  uint32_t IRQSTAT;                                 
  uint32_t IRQSTATEN;                               
  uint32_t IRQSIGEN;                                
  uint32_t AC12ERR;                                 
  uint32_t HTCAPBLT;                                
  uint32_t WML;                                     
  uint8_t RESERVED_0[8];
  uint32_t FEVT;                                    
  uint32_t ADMAES;                                  
  uint32_t ADSADDR;                                 
  uint8_t RESERVED_1[100];
  uint32_t VENDOR;                                  
  uint32_t MMCBOOT;                                 
  uint8_t RESERVED_2[52];
  uint32_t HOSTVER;                                 
} volatile *SDHC_MemMapPtr;



 




 


 
#line 11964 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 
#line 11990 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 12020 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12033 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 12069 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12101 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12127 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12164 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12201 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12238 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12251 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12269 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12279 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12312 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12320 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 12332 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12347 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12354 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 12400 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                   
  uint8_t RESERVED_0[4096];
  uint32_t SOPT2;                                   
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                   
  uint32_t SOPT5;                                   
  uint32_t SOPT6;                                   
  uint32_t SOPT7;                                   
  uint8_t RESERVED_2[8];
  uint32_t SDID;                                    
  uint32_t SCGC1;                                   
  uint32_t SCGC2;                                   
  uint32_t SCGC3;                                   
  uint32_t SCGC4;                                   
  uint32_t SCGC5;                                   
  uint32_t SCGC6;                                   
  uint32_t SCGC7;                                   
  uint32_t CLKDIV1;                                 
  uint32_t CLKDIV2;                                 
  uint32_t FCFG1;                                   
  uint32_t FCFG2;                                   
  uint32_t UIDH;                                    
  uint32_t UIDMH;                                   
  uint32_t UIDML;                                   
  uint32_t UIDL;                                    
} volatile *SIM_MemMapPtr;



 




 


 
#line 12485 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 12512 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12535 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12558 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12571 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12578 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12593 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12603 "..\\CommonSource\\headers\\MK60DZ10.h"
 




 
#line 12615 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12628 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12653 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12670 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12699 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12706 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12719 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12731 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12744 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12755 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 






   


 
 




 




 


 
 
#line 12815 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct SPI_MemMap {
  uint32_t MCR;                                     
  uint8_t RESERVED_0[4];
  uint32_t TCR;                                     
  union {                                           
    uint32_t CTAR[2];                                 
    uint32_t CTAR_SLAVE[1];                           
  };
  uint8_t RESERVED_1[24];
  uint32_t SR;                                      
  uint32_t RSER;                                    
  union {                                           
    uint32_t PUSHR;                                   
    uint32_t PUSHR_SLAVE;                             
  };
  uint32_t POPR;                                    
  uint32_t TXFR0;                                   
  uint32_t TXFR1;                                   
  uint32_t TXFR2;                                   
  uint32_t TXFR3;                                   
  uint8_t RESERVED_2[48];
  uint32_t RXFR0;                                   
  uint32_t RXFR1;                                   
  uint32_t RXFR2;                                   
  uint32_t RXFR3;                                   
} volatile *SPI_MemMapPtr;



 




 


 
#line 12891 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 12942 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 12982 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 12990 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13017 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13034 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13050 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 13065 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13072 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13079 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13086 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 






   


 
 

 

 




 




 


 
 
#line 13146 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13165 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13184 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 13192 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct SysTick_MemMap {
  uint32_t CSR;                                     
  uint32_t RVR;                                     
  uint32_t CVR;                                     
  uint32_t CALIB;                                   
} volatile *SysTick_MemMapPtr;



 




 


 







   




 




 

 
#line 13259 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 13275 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 







   




   




 




 

 
typedef struct SCB_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t ACTLR;                                   
  uint8_t RESERVED_1[3316];
  uint32_t CPUID;                                   
  uint32_t ICSR;                                    
  uint32_t VTOR;                                    
  uint32_t AIRCR;                                   
  uint32_t SCR;                                     
  uint32_t CCR;                                     
  uint32_t SHPR1;                                   
  uint32_t SHPR2;                                   
  uint32_t SHPR3;                                   
  uint32_t SHCSR;                                   
  uint32_t CFSR;                                    
  uint32_t HFSR;                                    
  uint32_t DFSR;                                    
  uint32_t MMFAR;                                   
  uint32_t BFAR;                                    
  uint32_t AFSR;                                    
} volatile *SCB_MemMapPtr;



 




 


 
#line 13372 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 13394 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13407 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13430 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 13449 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13456 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13469 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13479 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 13490 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13519 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13558 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13565 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13576 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 






   


 
 




 




 


 
 
#line 13627 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct TPIU_MemMap {
  uint32_t SSPSR;                                   
  uint32_t CSPSR;                                   
  uint8_t RESERVED_0[8];
  uint32_t ACPR;                                    
  uint8_t RESERVED_1[220];
  uint32_t SPPR;                                    
  uint8_t RESERVED_2[524];
  uint32_t FFSR;                                    
  uint32_t FFCR;                                    
  uint32_t FSCR;                                    
  uint8_t RESERVED_3[3036];
  uint32_t TRIGGER;                                 
  uint32_t FIFODATA0;                               
  uint32_t ITATBCTR2;                               
  uint8_t RESERVED_4[4];
  uint32_t ITATBCTR0;                               
  uint32_t FIFODATA1;                               
  uint32_t ITCTRL;                                  
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                                
  uint32_t CLAIMCLR;                                
  uint8_t RESERVED_6[32];
  uint32_t DEVID;                                   
  uint8_t RESERVED_7[4];
  uint32_t PID4;                                    
  uint32_t PID5;                                    
  uint32_t PID6;                                    
  uint32_t PID7;                                    
  uint32_t PID0;                                    
  uint32_t PID1;                                    
  uint32_t PID2;                                    
  uint32_t PID3;                                    
  uint32_t CID0;                                    
  uint32_t CID1;                                    
  uint32_t CID2;                                    
  uint32_t CID4;                                    
} volatile *TPIU_MemMapPtr;



 




 


 
#line 13726 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 




   


 
 




 




 


 
 
#line 13791 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct TSI_MemMap {
  uint32_t GENCS;                                   
  uint32_t SCANC;                                   
  uint32_t PEN;                                     
  uint32_t STATUS;                                  
  uint8_t RESERVED_0[240];
  uint32_t CNTR1;                                   
  uint32_t CNTR3;                                   
  uint32_t CNTR5;                                   
  uint32_t CNTR7;                                   
  uint32_t CNTR9;                                   
  uint32_t CNTR11;                                  
  uint32_t CNTR13;                                  
  uint32_t CNTR15;                                  
  uint32_t THRESHLD[16];                            
} volatile *TSI_MemMapPtr;



 




 


 
#line 13853 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 13904 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13928 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 13964 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14029 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14036 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14043 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14050 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14057 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14064 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14071 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14078 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14085 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14092 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 14142 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct UART_MemMap {
  uint8_t BDH;                                      
  uint8_t BDL;                                      
  uint8_t C1;                                       
  uint8_t C2;                                       
  uint8_t S1;                                       
  uint8_t S2;                                       
  uint8_t C3;                                       
  uint8_t D;                                        
  uint8_t MA1;                                      
  uint8_t MA2;                                      
  uint8_t C4;                                       
  uint8_t C5;                                       
  uint8_t ED;                                       
  uint8_t MODEM;                                    
  uint8_t IR;                                       
  uint8_t RESERVED_0[1];
  uint8_t PFIFO;                                    
  uint8_t CFIFO;                                    
  uint8_t SFIFO;                                    
  uint8_t TWFIFO;                                   
  uint8_t TCFIFO;                                   
  uint8_t RWFIFO;                                   
  uint8_t RCFIFO;                                   
  uint8_t RESERVED_1[1];
  uint8_t C7816;                                    
  uint8_t IE7816;                                   
  uint8_t IS7816;                                   
  union {                                           
    uint8_t WP7816_T_TYPE0;                           
    uint8_t WP7816_T_TYPE1;                           
  };
  uint8_t WN7816;                                   
  uint8_t WF7816;                                   
  uint8_t ET7816;                                   
  uint8_t TL7816;                                   
} volatile *UART_MemMapPtr;



 




 


 
#line 14246 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 14269 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 14290 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14307 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14324 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14341 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14358 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 14380 "..\\CommonSource\\headers\\MK60DZ10.h"
 




 




 
#line 14399 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 
#line 14416 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14425 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14434 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 



 
#line 14461 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14476 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14491 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 
#line 14502 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 
#line 14517 "..\\CommonSource\\headers\\MK60DZ10.h"
 






   


 
 

 

 

 

 

 




 




 


 
 
#line 14584 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14607 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14630 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14653 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14676 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14699 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct USB_MemMap {
  uint8_t PERID;                                    
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                   
  uint8_t RESERVED_1[3];
  uint8_t REV;                                      
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                  
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                 
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                   
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                  
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                   
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                    
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                    
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                  
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                    
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                     
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                      
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                     
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                 
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                  
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                  
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                    
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                  
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                 
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                 
  uint8_t RESERVED_21[11];
  struct {                                          
    uint8_t ENDPT;                                    
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                  
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                  
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                  
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                  
} volatile *USB_MemMapPtr;



 




 


 
#line 14816 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 



 



 



 





 
#line 14862 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14875 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14888 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14897 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14914 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14931 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14946 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14961 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14969 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 14986 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 



 



 



 
#line 15011 "..\\CommonSource\\headers\\MK60DZ10.h"
 



 



 



 
#line 15038 "..\\CommonSource\\headers\\MK60DZ10.h"
 




 
#line 15050 "..\\CommonSource\\headers\\MK60DZ10.h"
 


 
#line 15062 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 15126 "..\\CommonSource\\headers\\MK60DZ10.h"

 




   




   




 




 

 
typedef struct USBDCD_MemMap {
  uint32_t CONTROL;                                 
  uint32_t CLOCK;                                   
  uint32_t STATUS;                                  
  uint8_t RESERVED_0[4];
  uint32_t TIMER0;                                  
  uint32_t TIMER1;                                  
  uint32_t TIMER2;                                  
} volatile *USBDCD_MemMapPtr;



 




 


 
#line 15177 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 15203 "..\\CommonSource\\headers\\MK60DZ10.h"
 





 
#line 15222 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 15229 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 15236 "..\\CommonSource\\headers\\MK60DZ10.h"
 
#line 15243 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 
#line 15271 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




 

 
typedef struct VREF_MemMap {
  uint8_t TRM;                                      
  uint8_t SC;                                       
} volatile *VREF_MemMapPtr;



 




 


 





   




 




 

 



 
#line 15339 "..\\CommonSource\\headers\\MK60DZ10.h"



   


 
 




 




 


 
 





   




   




 




 

 
typedef struct WDOG_MemMap {
  uint16_t STCTRLH;                                 
  uint16_t STCTRLL;                                 
  uint16_t TOVALH;                                  
  uint16_t TOVALL;                                  
  uint16_t WINH;                                    
  uint16_t WINL;                                    
  uint16_t REFRESH;                                 
  uint16_t UNLOCK;                                  
  uint16_t TMROUTH;                                 
  uint16_t TMROUTL;                                 
  uint16_t RSTCNT;                                  
  uint16_t PRESC;                                   
} volatile *WDOG_MemMapPtr;



 




 


 
#line 15422 "..\\CommonSource\\headers\\MK60DZ10.h"



   




 




 

 
#line 15465 "..\\CommonSource\\headers\\MK60DZ10.h"
 


 



 



 



 



 



 



 



 



 



 






   


 
 




 




 


 
 
#line 15542 "..\\CommonSource\\headers\\MK60DZ10.h"



   




   




 




   








   




 




 

#line 15648 "..\\CommonSource\\headers\\MK60DZ10.h"



   


#line 15662 "..\\CommonSource\\headers\\MK60DZ10.h"

 
#line 83 "..\\CommonSource\\main.h"
#line 108 "..\\CommonSource\\main.h"


typedef unsigned char Byte;
typedef unsigned long LWord;
typedef unsigned short Word;

#line 139 "..\\CommonSource\\bootloader\\kinetis_params.h"
 











#line 160 "..\\CommonSource\\bootloader\\kinetis_params.h"








  


















#line 193 "..\\CommonSource\\bootloader\\kinetis_params.h"












#line 238 "..\\CommonSource\\bootloader\\kinetis_params.h"






     







  



  



  



  



  
#line 280 "..\\CommonSource\\bootloader\\kinetis_params.h"




#line 292 "..\\CommonSource\\bootloader\\kinetis_params.h"






































































typedef union _FlashConfig_t
{
  unsigned int Data[4];
  struct {
    unsigned int BackDoorKey[2];
    unsigned int Protection;
    unsigned int Config;
  };
} FlashConfig_t;


 








 

#line 396 "..\\CommonSource\\bootloader\\kinetis_params.h"





  






#line 415 "..\\CommonSource\\bootloader\\kinetis_params.h"
  
#line 437 "..\\CommonSource\\bootloader\\kinetis_params.h"









                                                                        
#line 514 "..\\CommonSource\\bootloader\\kinetis_params.h"



#line 41 "..\\CommonSource\\bootloader\\bootloader.h"



 

  
#line 54 "..\\CommonSource\\bootloader\\bootloader.h"

 
#line 63 "..\\CommonSource\\bootloader\\bootloader.h"


 










  































#line 114 "..\\CommonSource\\bootloader\\bootloader.h"

#line 122 "..\\CommonSource\\bootloader\\bootloader.h"


#line 133 "..\\CommonSource\\bootloader\\bootloader.h"




 

  typedef unsigned long addrType;
 
  typedef unsigned char BootloaderProtocolType;
  
  typedef union Address 
  {
    unsigned long complete;
    struct
    {
      unsigned short low;
      unsigned short high;        
    }Words;
    struct
    {
      unsigned char ll;
      unsigned char lh;
      unsigned char hl;
      unsigned char hh;
    }Bytes;
  }AddressType;
  
  #pragma pack(1)
  #pragma pack(push)
  
   
  
  typedef struct FlashBlocksDesc
  {
    addrType startAddr;
    addrType endAddr; 
  }FlashBlocksDescType;
  
   
   
  typedef struct BootloaderIdent
  {
           
          BootloaderProtocolType version;
           
          unsigned short sdid;
           
          addrType blocksCnt;
           
          FlashBlocksDescType blockDesc[1];
           
          addrType relocatedVectors;
           
          addrType interruptsVectors;
           
          addrType eraseBlockSize;
           
          addrType writeBlockSize;
           
          unsigned char idString[sizeof("K60")];      
  }BootloaderIdentType;
	
	 
  typedef struct BootloaderIdentOptimType
  {
           
          addrType blocksCnt;
           
          FlashBlocksDescType blockDesc[1];
           
          addrType relocatedVectors;
           
          addrType interruptsVectors;
           
          addrType eraseBlockSize;
           
          addrType writeBlockSize;
           
          unsigned char idString[sizeof("K60")];      
  }BootloaderIdentOptimType;
	
  #pragma pack(pop) 
  

	
typedef void (*vector_entry)(void);
typedef void pointer(void);


 
  


 



 
void Boot_ResetMCU(void);
void Bootloader(void);

 







#line 35 "..\\CommonSource\\bootloader\\bootloader.c"
#line 1 "..\\CommonSource\\rs232\\rs232.h"



 









 



#line 19 "..\\CommonSource\\rs232\\rs232.h"





	
	void UART_Initialization(void);

	void UART_PutChar(unsigned char data);
	unsigned char UART_GetChar(void);
#line 36 "..\\CommonSource\\bootloader\\bootloader.c"
#line 1 "..\\CommonSource\\flash\\flash_kinetis.h"



 









 




















#line 62 "..\\CommonSource\\flash\\flash_kinetis.h"


typedef union 
{
  Byte all[12];
  struct
  {
    Byte fccob3;
    Byte fccob2;
    Byte fccob1;
    Byte fccob0;
    Byte fccob7;
    Byte fccob6;
    Byte fccob5;
    Byte fccob4;
    Byte fccobB;
    Byte fccobA;
    Byte fccob9;
    Byte fccob8;
  }regs;
  
  struct
  {
    LWord fccob3210;
    LWord fccob7654;
    LWord fccobBA98;
  }regsLong;
}FCC0B_STR;


void  FLASH_Initialization(void);
LWord FLASH_EraseSector(LWord destination);
LWord FLASH_ProgramLongWord(LWord destination, LWord data);
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b);
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size);
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size);
LWord FLASH_MassErase(void);






#line 37 "..\\CommonSource\\bootloader\\bootloader.c"
#line 1 "..\\CommonSource\\wdg\\wdg.h"



















 











 







 
#line 55 "..\\CommonSource\\wdg\\wdg.h"







#line 38 "..\\CommonSource\\bootloader\\bootloader.c"
#line 1 "..\\CommonSource\\crc\\crc.h"



















 











 






    
#line 47 "..\\CommonSource\\crc\\crc.h"
  
#line 69 "..\\CommonSource\\crc\\crc.h"





#line 39 "..\\CommonSource\\bootloader\\bootloader.c"



static void SendResult(unsigned long res);
static void SendResultCRC(unsigned long res);
extern void JumpToUserApplication(LWord userSP, LWord userStartup);

extern int __main(void);
extern unsigned long __BOOT_STACK_ADDRESS[];

#line 58 "..\\CommonSource\\bootloader\\bootloader.c"
#pragma diag_suppress=61
    __attribute__((section(".IntVectTable"))) const vector_entry __vector_table[16] __attribute__((used)) =   





{
   (pointer*)__BOOT_STACK_ADDRESS,   
   (vector_entry)__main,                             
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU,      
   Boot_ResetMCU          
};

#line 90 "..\\CommonSource\\bootloader\\bootloader.c"
    __attribute__((section(".FlashConfig"))) const FlashConfig_t Config __attribute__((used)) =   




{
 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE,
};



AddressType address;
AddressType tmp_transpone;

unsigned char write_buffer[256];

unsigned long length;

unsigned long i;

AddressType  crc_res;

unsigned long enableBootMode;

unsigned long timeout_cnt;

const BootloaderIdentOptimType bootloaderIdent = 
{
    
   ((unsigned long)(((unsigned long)((unsigned char)(1)<<24) & 0xff000000) | (unsigned long)(((unsigned short)(1)<<8) & 0x00ff0000) | (unsigned long)(((1)>>8) & 0x0000ff00) | (unsigned long)(((1)>>24) & 0x00000000ff))),
    
   {((unsigned long)(((unsigned long)((unsigned char)(((1<<19) /32))<<24) & 0xff000000) | (unsigned long)(((unsigned short)(((1<<19) /32))<<8) & 0x00ff0000) | (unsigned long)(((((1<<19) /32))>>8) & 0x0000ff00) | (unsigned long)(((((1<<19) /32))>>24) & 0x00000000ff))), ((unsigned long)(((unsigned long)((unsigned char)(((1<<19) - 1))<<24) & 0xff000000) | (unsigned long)(((unsigned short)(((1<<19) - 1))<<8) & 0x00ff0000) | (unsigned long)(((((1<<19) - 1))>>8) & 0x0000ff00) | (unsigned long)(((((1<<19) - 1))>>24) & 0x00000000ff)))},



    
   ((unsigned long)(((unsigned long)((unsigned char)(((1<<19) /32))<<24) & 0xff000000) | (unsigned long)(((unsigned short)(((1<<19) /32))<<8) & 0x00ff0000) | (unsigned long)(((((1<<19) /32))>>8) & 0x0000ff00) | (unsigned long)(((((1<<19) /32))>>24) & 0x00000000ff))),
    
   ((unsigned long)(((unsigned long)((unsigned char)(0x0000)<<24) & 0xff000000) | (unsigned long)(((unsigned short)(0x0000)<<8) & 0x00ff0000) | (unsigned long)(((0x0000)>>8) & 0x0000ff00) | (unsigned long)(((0x0000)>>24) & 0x00000000ff))),
    
   ((unsigned long)(((unsigned long)((unsigned char)(2048)<<24) & 0xff000000) | (unsigned long)(((unsigned short)(2048)<<8) & 0x00ff0000) | (unsigned long)(((2048)>>8) & 0x0000ff00) | (unsigned long)(((2048)>>24) & 0x00000000ff))),
    
   ((unsigned long)(((unsigned long)((unsigned char)(128)<<24) & 0xff000000) | (unsigned long)(((unsigned short)(128)<<8) & 0x00ff0000) | (unsigned long)(((128)>>8) & 0x0000ff00) | (unsigned long)(((128)>>24) & 0x00000000ff))),
    
   "K60"      
};










void Boot_ResetMCU(void)
{ 
  ((((SCB_MemMapPtr)0xE000E000u))->AIRCR) = (((uint32_t)(((uint32_t)(0x5FA))<<16))&0xFFFF0000u) | 0x4u;
  while(1)
  {};   
}

#line 185 "..\\CommonSource\\bootloader\\bootloader.c"









static void SendResult(unsigned long res)
{ 
  if(!res)
    UART_PutChar(0xFC);
  else
    UART_PutChar(0x03);
}










static void SendResultCRC(unsigned long res)
{ 
  SendResult(res);

  if(!res)
  {
    UART_PutChar(0xcf);
    UART_PutChar(0x63);
  }else
  {
    UART_PutChar(0xd1);
    UART_PutChar(0x93);
  }

}











static void ReadAddress(void)
{
  address.Bytes.hh = UART_GetChar();
  address.Bytes.hl = UART_GetChar();
  address.Bytes.lh = UART_GetChar();
  address.Bytes.ll = UART_GetChar();
}












  static void ReadCrc(void)
  {
    crc_res.Bytes.lh = UART_GetChar();
    crc_res.Bytes.ll = UART_GetChar();
  }



#line 358 "..\\CommonSource\\bootloader\\bootloader.c"










 
 

int __main(void)
{
  unsigned char getcommand = 0;

   



    ((((WDOG_MemMapPtr)0x40052000u))->UNLOCK) = 0xC520; ((((WDOG_MemMapPtr)0x40052000u))->UNLOCK) = 0xD928; ((((WDOG_MemMapPtr)0x40052000u))->STCTRLH) &= ~0x1u;;    

  
#line 396 "..\\CommonSource\\bootloader\\bootloader.c"
  

   ((((SIM_MemMapPtr)0x40047000u))->CLKDIV1) = (uint32_t)0xFFFFFFFFu; 
   ((((MCG_MemMapPtr)0x40064000u))->C1) = (uint8_t)0x06u;
   ((((MCG_MemMapPtr)0x40064000u))->C2) = (uint8_t)0x00u;
   ((((MCG_MemMapPtr)0x40064000u))->C4) &= ~((1<<6)|(1<<7)|(1<<5)); 
   ((((MCG_MemMapPtr)0x40064000u))->C4)|= (0<<6)|(1<<7)|(1<<5);  
   ((((SIM_MemMapPtr)0x40047000u))->CLKDIV1) =((((uint32_t)(((uint32_t)(0))<<28))&0xF0000000u)|(((uint32_t)(((uint32_t)(0))<<24))&0xF000000u)|(((uint32_t)(((uint32_t)(0))<<20))&0xF00000u)|(((uint32_t)(((uint32_t)(1))<<16))&0xF0000u));
   ((((MCG_MemMapPtr)0x40064000u))->C5) = (uint8_t)0x00u;
   ((((MCG_MemMapPtr)0x40064000u))->C6) = (uint8_t)0x00u;
   while((((((MCG_MemMapPtr)0x40064000u))->S) & 0x10u) == 0u);  
   while((((((MCG_MemMapPtr)0x40064000u))->S) & 0x0Cu) != 0x00u);           


#line 416 "..\\CommonSource\\bootloader\\bootloader.c"
  
  
  ((((SIM_MemMapPtr)0x40047000u))->SCGC1) |= 0xffffffff; ((((SIM_MemMapPtr)0x40047000u))->SCGC4) |= 0xffffffff; ((((SIM_MemMapPtr)0x40047000u))->SCGC5) |= 0xffffffff; ((((SIM_MemMapPtr)0x40047000u))->SCGC6) |= 0xffffffff;
  
  

    ((((PORT_MemMapPtr)0x40049000u))->PCR[19]) = (((uint32_t)(((uint32_t)(1))<<8))&0x700u) | 0x2u | 0x1u;;


  
  
  
  
  
  timeout_cnt = 0;
  enableBootMode = 1;
	
  
  if(((((MC_MemMapPtr)0x4007E000u))->SRSL) & 0x80u)
    enableBootMode = 1;
  





  
   

    
    if((((((GPIO_MemMapPtr)0x400FF000u))->PDIR) & (1 << 19)) == 0) 
    {
        enableBootMode = 1;
    }
    else
    {
        enableBootMode = 0;
    }
      

  
  
  if(enableBootMode)
  {
	  
	  unsigned char i;    
    

      ((((CRC_MemMapPtr)0x40032000u))->CTRL) = 0;;    

    
      

    ((((PORT_MemMapPtr)0x4004D000u))->PCR[9]) = (((uint32_t)(((uint32_t)(3))<<8))&0x700u); ((((PORT_MemMapPtr)0x4004D000u))->PCR[8]) = (((uint32_t)(((uint32_t)(3))<<8))&0x700u);;

    
    UART_Initialization(); 
    
    
    ((((SysTick_MemMapPtr)0xE000E010u))->RVR) = (unsigned long)(0.01 * (48000000)); 
    ((((SysTick_MemMapPtr)0xE000E010u))->CSR) = (0x4u | 0x1u);
    
    while(1)
    {




      if(((((SysTick_MemMapPtr)0xE000E010u))->CSR) & 0x10000u)
      {
    	  ((((SysTick_MemMapPtr)0xE000E010u))->CVR) = 0; 
        
    	  

    	  timeout_cnt++;		



    	  
    	  if((timeout_cnt & 0x1F) == 0x10)
    		  SendResult(0);    	  
    	  if((timeout_cnt > 1000) && ((*(unsigned long*)(((1<<19) /32) + 8)) != 0xffffffff))
    		  break;
      }
      
      
      if((((((UART_MemMapPtr)0x400EB000u))->S1) & 0x20u))
      {
        unsigned char getch = 0;
        
        getch = UART_GetChar();
	if(getch != 0xFC)
        {
             Boot_ResetMCU();
        }
	
        

        if(getch != 0xFC)
        {
             
        }


        
        FLASH_Initialization(); 
        enableBootMode++;
        SendResult(0);
        break;
      }  
    }
    
    
    while(enableBootMode > 1)
    {
      
      timeout_cnt = 0;
      
      
      if((((((SysTick_MemMapPtr)0xE000E010u))->CSR) & 0x10000u)&&(getcommand == 0))
      {
    	  ((((SysTick_MemMapPtr)0xE000E010u))->CVR) = 0; 
        
    	  

            timeout_cnt++;		



    	  	  
    	  if((timeout_cnt > 100) )
          {
            break;
          }
    		  
      }
      



        

        ((((CRC_MemMapPtr)0x40032000u))->CTRL) |= 0x2000000u; ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL) = 0xFFFF; ((((CRC_MemMapPtr)0x40032000u))->CTRL) &= ~0x2000000u;;


      switch(UART_GetChar())
      {
        case 'Q':                                 

            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ('Q');;  
            ReadCrc();
            if(crc_res.Words.low != ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL))
            {            
              SendResultCRC(1);
              break;
            }

        
          
          SendResultCRC(0);
          
          Boot_ResetMCU();

        case 0xFC:
          SendResult(0);                                   
          break;
        
        case 'I':                               
          
          getcommand = 1;

            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ('I');;  
            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ((BootloaderProtocolType)8 | 0xc0);;

          UART_PutChar((BootloaderProtocolType)8 | 0xc0);


              ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = (((((SIM_MemMapPtr)0x40047000u))->SDID) >> 8);;




              

            UART_PutChar(((((SIM_MemMapPtr)0x40047000u))->SDID) >> 8); 



          


              ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = (((((SIM_MemMapPtr)0x40047000u))->SDID));;




              

            UART_PutChar(((((SIM_MemMapPtr)0x40047000u))->SDID));  



               
          
          for(i=0; i < sizeof(bootloaderIdent); i++)
          {

              ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = (((unsigned char*)&bootloaderIdent)[i]);;

              UART_PutChar(((unsigned char*)&bootloaderIdent)[i]);
          }


            UART_PutChar(((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLU));         
            UART_PutChar(((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL));

              
          break;
          
        case 'E':                                
          
          ReadAddress();
          

            
            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ('E');;
            ((((CRC_MemMapPtr)0x40032000u))->CRC) = (address . complete);;
            
            ReadCrc();
            if(crc_res.Words.low != ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL))
            {            
              SendResultCRC(1);
              break;
            }

          
          SendResultCRC(FLASH_EraseSector(address.complete));
          break;
          
        case 'W':
          
          ReadAddress();
          
          length = UART_GetChar();
          

            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ('W');;
            ((((CRC_MemMapPtr)0x40032000u))->CRC) = (address . complete);;
            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ((unsigned char)length);;

          
          
          for(i = 0;i<length; i++)
          {
            write_buffer[i] =  UART_GetChar(); 

              ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = (write_buffer[i]);;

          }
          
          length >>= 2;    
          
          
          

            ReadCrc();
            if(crc_res.Words.low != ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL))
            {            
              SendResultCRC(1);
              break;
            }

                
          if(FLASH_ProgramSectionByLongs(address.complete, (LWord*)write_buffer, length))
          {            
            SendResultCRC(1);
            break;
          }
          
          

            for(i = 0;i<length; i++)
            {              
              if(((unsigned long*)write_buffer)[i] != ((unsigned long*)address.complete)[i])
              {
                SendResultCRC(1);
                break;
              }
            }

          SendResultCRC(0);
          break;
       

          
        case 'R':                                   
          ReadAddress();
          length = UART_GetChar();
          

            ReadCrc();
            
            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ('R');;
            ((((CRC_MemMapPtr)0x40032000u))->CRC) = (address . complete);;
            ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = ((unsigned char)length);;
            
            if(crc_res.Words.low != ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL))
            {            
              SendResultCRC(1);
              break;
            }

          

            ((((CRC_MemMapPtr)0x40032000u))->CTRL) |= 0x2000000u; ((((CRC_MemMapPtr)0x40032000u))->ACCESS16BIT . CRCL) = 0xFFFF; ((((CRC_MemMapPtr)0x40032000u))->CTRL) &= ~0x2000000u;;

          
          for(i = 0;i<length; i++)
          {

              ((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL) = (((unsigned char*)(address . complete))[i]);;

              UART_PutChar(((unsigned char*)(address.complete))[i]); 
            



          }
          

            UART_PutChar(((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLU));         
            UART_PutChar(((((CRC_MemMapPtr)0x40032000u))->ACCESS8BIT . CRCLL));

          
          break;
          

          
      }      
    } 
  }
    
    ((((SysTick_MemMapPtr)0xE000E010u))->CSR) = 0;
  
    
    ((((UART_MemMapPtr)0x400EB000u))->C2) = 0;
  
    
    ((((SCB_MemMapPtr)0xE000E000u))->VTOR) = ((1<<19) /32);
    
    
    JumpToUserApplication(*((unsigned long*)((1<<19) /32)), *((unsigned long*)(((1<<19) /32)+4)));   
    
	return 0;
}
