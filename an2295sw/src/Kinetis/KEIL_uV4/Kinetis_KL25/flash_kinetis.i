#line 1 "..\\CommonSource\\flash\\flash_kinetis.c"



 









 

#line 1 "..\\CommonSource\\bootloader\\kinetis_params.h"



















 











 




#line 1 "..\\CommonSource\\bootloader_cfg.h"



















 











 





#line 1 "..\\CommonSource\\AN2295_FRDM_KL25Z_cfg.h"
 
 
 








 







 
 




 



 


 
 


 
 


 
 


 



 


 






 
 






 
 











 
 







 


 


  


 


 


 


 


 


 


 


 


 

#line 41 "..\\CommonSource\\bootloader_cfg.h"






#line 64 "..\\CommonSource\\bootloader_cfg.h"

#line 38 "..\\CommonSource\\bootloader\\kinetis_params.h"




#line 48 "..\\CommonSource\\bootloader\\kinetis_params.h"

#line 56 "..\\CommonSource\\bootloader\\kinetis_params.h"


















#line 80 "..\\CommonSource\\bootloader\\kinetis_params.h"
















#line 103 "..\\CommonSource\\bootloader\\kinetis_params.h"

























#line 136 "..\\CommonSource\\bootloader\\kinetis_params.h"

 
#line 1 "..\\CommonSource\\main.h"



















 











 




  
  #pragma anon_unions


#line 1 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



























 








 




 

 



 





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



 



#line 55 "..\\CommonSource\\headers\\MKL25Z128LK4.h"


 

 








 




 




 

 
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                 
  INT_Initial_Program_Counter  = 1,                 
  INT_NMI                      = 2,                 
  INT_Hard_Fault               = 3,                 
  INT_Reserved4                = 4,                 
  INT_Reserved5                = 5,                 
  INT_Reserved6                = 6,                 
  INT_Reserved7                = 7,                 
  INT_Reserved8                = 8,                 
  INT_Reserved9                = 9,                 
  INT_Reserved10               = 10,                
  INT_SVCall                   = 11,                
  INT_Reserved12               = 12,                
  INT_Reserved13               = 13,                
  INT_PendableSrvReq           = 14,                
  INT_SysTick                  = 15,                
  INT_DMA0                     = 16,                
  INT_DMA1                     = 17,                
  INT_DMA2                     = 18,                
  INT_DMA3                     = 19,                
  INT_MCM                      = 20,                
  INT_FTFA                     = 21,                
  INT_LVD_LVW                  = 22,                
  INT_LLW                      = 23,                
  INT_I2C0                     = 24,                
  INT_I2C1                     = 25,                
  INT_SPI0                     = 26,                
  INT_SPI1                     = 27,                
  INT_UART0                    = 28,                
  INT_UART1                    = 29,                
  INT_UART2                    = 30,                
  INT_ADC0                     = 31,                
  INT_CMP0                     = 32,                
  INT_TPM0                     = 33,                
  INT_TPM1                     = 34,                
  INT_TPM2                     = 35,                
  INT_RTC                      = 36,                
  INT_RTC_Seconds              = 37,                
  INT_PIT                      = 38,                
  INT_Reserved39               = 39,                
  INT_USB0                     = 40,                
  INT_DAC0                     = 41,                
  INT_TSI0                     = 42,                
  INT_MCG                      = 43,                
  INT_LPTimer                  = 44,                
  INT_Reserved45               = 45,                
  INT_PORTA                    = 46,                
  INT_PORTD                    = 47                 
} IRQInterruptIndex;



   




 




 




 


  #pragma push
  #pragma anon_unions
#line 164 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



 




 

 
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
  uint8_t RESERVED_0[4];
  uint32_t CLMD;                                    
  uint32_t CLMS;                                    
  uint32_t CLM4;                                    
  uint32_t CLM3;                                    
  uint32_t CLM2;                                    
  uint32_t CLM1;                                    
  uint32_t CLM0;                                    
} volatile *ADC_MemMapPtr;



 




 


 
#line 240 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 265 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 279 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 289 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 
#line 317 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 329 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 






   


 
 

 




 




 


 
 
#line 448 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 





   




   




 




 

 
typedef struct BP_MemMap {
  uint32_t CTRL;                                    
  uint8_t RESERVED_0[4];
  uint32_t COMP[8];                                 
  uint8_t RESERVED_1[4008];
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
} volatile *BP_MemMapPtr;



 




 


 
#line 517 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 




   


 
 

 




 




 


 
 
#line 577 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 




   




   




 




 

 
typedef struct CMP_MemMap {
  uint8_t CR0;                                      
  uint8_t CR1;                                      
  uint8_t FPR;                                      
  uint8_t SCR;                                      
  uint8_t DACCR;                                    
  uint8_t MUXCR;                                    
} volatile *CMP_MemMapPtr;



 




 


 
#line 627 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 649 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 666 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 683 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 691 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 700 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 730 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
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
  } DAT[2];
  uint8_t RESERVED_0[28];
  uint8_t SR;                                       
  uint8_t C0;                                       
  uint8_t C1;                                       
  uint8_t C2;                                       
} volatile *DAC_MemMapPtr;



 




 


 
#line 871 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 




 
#line 914 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 921 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 







   


 
 

 




 




 


 
 
#line 958 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 





   




   




 




 

 
typedef struct DMA_MemMap {
  union {                                           
    uint8_t REQC_ARR[4];                              
  };
  uint8_t RESERVED_0[252];
  struct {                                          
    uint32_t SAR;                                     
    uint32_t DAR;                                     
    union {                                           
      uint32_t DSR_BCR;                                 
      uint8_t DSR;                                      
    };
    uint32_t DCR;                                     
  } DMA[4];
} volatile *DMA_MemMapPtr;



 




 


 
#line 1016 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 





 



 



 
#line 1061 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1101 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 1149 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 
#line 1157 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[4];                                 
} volatile *DMAMUX_MemMapPtr;



 




 


 




   




 




 

 
#line 1217 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 





 




   




   




 




 

 
typedef struct FGPIO_MemMap {
  uint32_t PDOR;                                    
  uint32_t PSOR;                                    
  uint32_t PCOR;                                    
  uint32_t PTOR;                                    
  uint32_t PDIR;                                    
  uint32_t PDDR;                                    
} volatile *FGPIO_MemMapPtr;



 




 


 
#line 1295 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 



 



 






   


 
 

 

 

 

 

 




 




 


 
 
#line 1372 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1379 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1386 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1393 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1400 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct FTFA_MemMap {
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
} volatile *FTFA_MemMapPtr;



 




 


 
#line 1475 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 1501 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1510 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1523 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 






   


 
 

 




 




 


 
 
#line 1635 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                    
  uint32_t PSOR;                                    
  uint32_t PCOR;                                    
  uint32_t PTOR;                                    
  uint32_t PDIR;                                    
  uint32_t PDDR;                                    
} volatile *GPIO_MemMapPtr;



 




 


 
#line 1682 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 



 



 






   


 
 

 

 

 

 

 




 




 


 
 
#line 1759 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1766 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1773 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1780 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1787 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
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



 




 


 
#line 1846 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 
#line 1872 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1889 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1906 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 1924 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 1934 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 1955 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 






   


 
 

 

 




 




 


 
 
#line 2005 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2018 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct LLWU_MemMap {
  uint8_t PE1;                                      
  uint8_t PE2;                                      
  uint8_t PE3;                                      
  uint8_t PE4;                                      
  uint8_t ME;                                       
  uint8_t F1;                                       
  uint8_t F2;                                       
  uint8_t F3;                                       
  uint8_t FILT1;                                    
  uint8_t FILT2;                                    
} volatile *LLWU_MemMapPtr;



 




 


 
#line 2073 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 2101 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2114 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2127 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2140 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2157 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2174 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2191 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2208 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2217 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2226 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 2260 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                     
  uint32_t PSR;                                     
  uint32_t CMR;                                     
  uint32_t CNR;                                     
} volatile *LPTMR_MemMapPtr;



 




 


 







   




 




 

 
#line 2334 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2343 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 






   


 
 

 




 




 


 
 







   




   




 




 

 
typedef struct MCG_MemMap {
  uint8_t C1;                                       
  uint8_t C2;                                       
  uint8_t C3;                                       
  uint8_t C4;                                       
  uint8_t C5;                                       
  uint8_t C6;                                       
  uint8_t S;                                        
  uint8_t RESERVED_0[1];
  uint8_t SC;                                       
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                    
  uint8_t ATCVL;                                    
  uint8_t C7;                                       
  uint8_t C8;                                       
  uint8_t RESERVED_2[1];
  uint8_t C10;                                      
} volatile *MCG_MemMapPtr;



 




 


 
#line 2443 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 2471 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2485 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 2500 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2508 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2518 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2534 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2548 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 





   


 
 

 




 




 


 
 
#line 2596 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                   
  uint16_t PLAMC;                                   
  uint32_t PLACR;                                   
  uint8_t RESERVED_1[48];
  uint32_t CPO;                                     
} volatile *MCM_MemMapPtr;



 




 


 







   




 




 

 



 



 
#line 2681 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2688 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 







   




   




 




 

 
typedef struct MTB_MemMap {
  uint32_t POSITION;                                
  uint32_t MASTER;                                  
  uint32_t FLOW;                                    
  uint32_t BASE;                                    
  uint8_t RESERVED_0[3824];
  uint32_t MODECTRL;                                
  uint8_t RESERVED_1[156];
  uint32_t TAGSET;                                  
  uint32_t TAGCLEAR;                                
  uint8_t RESERVED_2[8];
  uint32_t LOCKACCESS;                              
  uint32_t LOCKSTAT;                                
  uint32_t AUTHSTAT;                                
  uint32_t DEVICEARCH;                              
  uint8_t RESERVED_3[8];
  uint32_t DEVICECFG;                               
  uint32_t DEVICETYPID;                             
  uint32_t PERIPHID[8];                             
  uint32_t COMPID[4];                               
} volatile *MTB_MemMapPtr;



 




 


 
#line 2785 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 





 
#line 2822 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 2830 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 



 



 



 
#line 2863 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 



 






   


 
 

 




 




 


 
 
#line 2932 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 





   




   




 




 

 
typedef struct MTBDWT_MemMap {
  uint8_t RESERVED_0[4096];
  uint32_t CTRL;                                    
  uint8_t RESERVED_1[28];
  struct {                                          
    uint32_t COMP;                                    
    uint32_t MASK;                                    
    uint32_t FCT;                                     
    uint8_t RESERVED_0[4];
  } COMPARATOR[2];
  uint8_t RESERVED_2[448];
  uint32_t TBCTRL;                                  
  uint8_t RESERVED_3[3524];
  uint32_t DEVICECFG;                               
  uint32_t DEVICETYPID;                             
  uint32_t PERIPHID[8];                             
  uint32_t COMPID[4];                               
} volatile *MTBDWT_MemMapPtr;



 




 


 
#line 2996 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 3018 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 
#line 3040 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 3048 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 






   


 
 

 




 




 


 
 
#line 3110 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 








   




   




 




 

 
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
} volatile *NV_MemMapPtr;



 




 


 
#line 3180 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 



 



 



 



 



 



 



 



 



 
#line 3256 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 







   


 
 

 




 




 


 
 
#line 3299 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct NVIC_MemMap {
  uint32_t ISER;                                    
  uint8_t RESERVED_0[124];
  uint32_t ICER;                                    
  uint8_t RESERVED_1[124];
  uint32_t ISPR;                                    
  uint8_t RESERVED_2[124];
  uint32_t ICPR;                                    
  uint8_t RESERVED_3[380];
  uint32_t IP[8];                                   
} volatile *NVIC_MemMapPtr;



 




 


 








   




 




 

 



 



 



 



 
#line 3476 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 3512 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 




   




   




 




 

 
typedef struct OSC_MemMap {
  uint8_t CR;                                       
} volatile *OSC_MemMapPtr;



 




 


 




   




 




 

 
#line 3580 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 




   




   




 




 

 
typedef struct PIT_MemMap {
  uint32_t MCR;                                     
  uint8_t RESERVED_0[220];
  uint32_t LTMR64H;                                 
  uint32_t LTMR64L;                                 
  uint8_t RESERVED_1[24];
  struct {                                          
    uint32_t LDVAL;                                   
    uint32_t CVAL;                                    
    uint32_t TCTRL;                                   
    uint32_t TFLG;                                    
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;



 




 


 
#line 3658 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 




 



 



 



 



 
#line 3701 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 





   


 
 

 




 




 


 
 
#line 3747 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 







   




   




 




 

 
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                   
  uint8_t LVDSC2;                                   
  uint8_t REGSC;                                    
} volatile *PMC_MemMapPtr;



 




 


 






   




 




 

 
#line 3821 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 3831 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 3840 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 






   




   




 




 

 
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                 
  uint32_t GPCLR;                                   
  uint32_t GPCHR;                                   
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                    
} volatile *PORT_MemMapPtr;



 




 


 







   




 




 

 
#line 3945 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 3952 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 3959 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 






   


 
 

 

 

 

 

 




 




 


 
 
#line 4030 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4066 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4102 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4138 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4174 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 








   




   




 




 

 
typedef struct RCM_MemMap {
  uint8_t SRS0;                                     
  uint8_t SRS1;                                     
  uint8_t RESERVED_0[2];
  uint8_t RPFC;                                     
  uint8_t RPFW;                                     
} volatile *RCM_MemMapPtr;



 




 


 







   




 




 

 
#line 4255 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4264 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 





 






   


 
 

 




 




 


 
 







   




   




 




 

 
typedef struct ROM_MemMap {
  uint8_t RESERVED_0[8192];
  uint32_t ENTRY[3];                                
  uint32_t TABLEMARK;                               
  uint8_t RESERVED_1[4032];
  uint32_t PERIPHID4;                               
  uint32_t PERIPHID5;                               
  uint32_t PERIPHID6;                               
  uint32_t PERIPHID7;                               
  uint32_t PERIPHID0;                               
  uint32_t PERIPHID1;                               
  uint32_t PERIPHID2;                               
  uint32_t PERIPHID3;                               
  uint32_t COMPID[4];                               
} volatile *ROM_MemMapPtr;



 




 


 
#line 4361 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 



 



 



 



 



 



 



 






   


 
 

 




 




 


 
 
#line 4460 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 





   




   




 




 

 
typedef struct RTC_MemMap {
  uint32_t TSR;                                     
  uint32_t TPR;                                     
  uint32_t TAR;                                     
  uint32_t TCR;                                     
  uint32_t CR;                                      
  uint32_t SR;                                      
  uint32_t LR;                                      
  uint32_t IER;                                     
} volatile *RTC_MemMapPtr;



 




 


 
#line 4515 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 
#line 4555 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4576 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4585 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4594 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4605 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 4637 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
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
  uint8_t RESERVED_2[4];
  uint32_t SHPR2;                                   
  uint32_t SHPR3;                                   
  uint32_t SHCSR;                                   
  uint8_t RESERVED_3[8];
  uint32_t DFSR;                                    
} volatile *SCB_MemMapPtr;



 




 


 
#line 4698 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 4726 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4745 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 4759 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4766 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 




 



 
#line 4782 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 


 
#line 4796 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 4831 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                   
  uint32_t SOPT1CFG;                                
  uint8_t RESERVED_0[4092];
  uint32_t SOPT2;                                   
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                   
  uint32_t SOPT5;                                   
  uint8_t RESERVED_2[4];
  uint32_t SOPT7;                                   
  uint8_t RESERVED_3[8];
  uint32_t SDID;                                    
  uint8_t RESERVED_4[12];
  uint32_t SCGC4;                                   
  uint32_t SCGC5;                                   
  uint32_t SCGC6;                                   
  uint32_t SCGC7;                                   
  uint32_t CLKDIV1;                                 
  uint8_t RESERVED_5[4];
  uint32_t FCFG1;                                   
  uint32_t FCFG2;                                   
  uint8_t RESERVED_6[4];
  uint32_t UIDMH;                                   
  uint32_t UIDML;                                   
  uint32_t UIDL;                                    
  uint8_t RESERVED_7[156];
  uint32_t COPC;                                    
  uint32_t SRVCOP;                                  
} volatile *SIM_MemMapPtr;



 




 


 
#line 4912 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 4937 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4944 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4960 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4971 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4988 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 4996 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5018 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5037 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5052 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5071 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 


 
#line 5081 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5089 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 



 
#line 5113 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 






   


 
 

 




 




 


 
 
#line 5160 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct SMC_MemMap {
  uint8_t PMPROT;                                   
  uint8_t PMCTRL;                                   
  uint8_t STOPCTRL;                                 
  uint8_t PMSTAT;                                   
} volatile *SMC_MemMapPtr;



 




 


 







   




 




 

 
#line 5225 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5234 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5243 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 






   


 
 

 




 




 


 
 







   




   




 




 

 
typedef struct SPI_MemMap {
  uint8_t C1;                                       
  uint8_t C2;                                       
  uint8_t BR;                                       
  uint8_t S;                                        
  uint8_t RESERVED_0[1];
  uint8_t DL;                                       
  uint8_t RESERVED_1[1];
  uint8_t ML;                                       
} volatile *SPI_MemMapPtr;



 




 


 
#line 5324 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 5356 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5373 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5380 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5389 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 






   


 
 

 

 




 




 


 
 
#line 5429 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5436 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct SysTick_MemMap {
  uint32_t CSR;                                     
  uint32_t RVR;                                     
  uint32_t CVR;                                     
  uint32_t CALIB;                                   
} volatile *SysTick_MemMapPtr;



 




 


 







   




 




 

 
#line 5503 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 
#line 5519 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 







   




   




 




 

 
typedef struct TPM_MemMap {
  uint32_t SC;                                      
  uint32_t CNT;                                     
  uint32_t MOD;                                     
  struct {                                          
    uint32_t CnSC;                                    
    uint32_t CnV;                                     
  } CONTROLS[6];
  uint8_t RESERVED_0[20];
  uint32_t STATUS;                                  
  uint8_t RESERVED_1[48];
  uint32_t CONF;                                    
} volatile *TPM_MemMapPtr;



 




 


 
#line 5600 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 5630 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 
#line 5653 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 5672 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5689 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 

 

 




 




 


 
 
#line 5734 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5744 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5754 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 
#line 5762 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
typedef struct TSI_MemMap {
  uint32_t GENCS;                                   
  uint32_t DATA;                                    
  uint32_t TSHD;                                    
} volatile *TSI_MemMapPtr;



 




 


 






   




 




 

 
#line 5855 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5866 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 5873 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 






   




   


 
typedef struct UART_MemMap {
  uint8_t R1;                                      
  uint8_t R2;                                      
  uint8_t R3;                                       
  uint8_t R4;                                       
  uint8_t R5;                                       
  uint8_t R6;                                       
  uint8_t R7;                                       
  uint8_t R8;                                        
  uint8_t R9;                                      
  uint8_t R10;                                      
  uint8_t R11;                                       
  uint8_t R12;                                       
} volatile *UART_MemMapPtr;





 

 
#line 5946 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 
#line 5957 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 
#line 5982 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 6003 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6020 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6037 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6052 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6069 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 6084 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 
 
#line 6096 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 
#line 6117 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6134 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6151 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6166 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6183 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 


 


 
#line 6203 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6212 "..\\CommonSource\\headers\\MKL25Z128LK4.h"


   


 

 

 

 




 




 


 
 
#line 6250 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6260 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6270 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




   




 




 

 
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



 




 


 
#line 6387 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



 



 



 





 
#line 6433 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6446 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6459 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6468 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6485 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6502 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6517 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6532 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6540 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 
#line 6557 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 





 



 



 



 
#line 6582 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 



 



 



 
#line 6609 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 




 
#line 6621 "..\\CommonSource\\headers\\MKL25Z128LK4.h"
 


 
#line 6633 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   


 
 

 




 




 


 
 
#line 6699 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 




   




   




 


  #pragma pop
#line 6728 "..\\CommonSource\\headers\\MKL25Z128LK4.h"



   




 




 

 



   


#line 6758 "..\\CommonSource\\headers\\MKL25Z128LK4.h"

 
#line 97 "..\\CommonSource\\main.h"
#line 108 "..\\CommonSource\\main.h"


typedef unsigned char Byte;
typedef unsigned long LWord;
typedef unsigned short Word;

#line 139 "..\\CommonSource\\bootloader\\kinetis_params.h"
 











#line 160 "..\\CommonSource\\bootloader\\kinetis_params.h"








  




































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




#line 448 "..\\CommonSource\\bootloader\\kinetis_params.h"
                                    
  



  
#line 462 "..\\CommonSource\\bootloader\\kinetis_params.h"
  

                                    





#line 514 "..\\CommonSource\\bootloader\\kinetis_params.h"



#line 17 "..\\CommonSource\\flash\\flash_kinetis.c"
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






#line 18 "..\\CommonSource\\flash\\flash_kinetis.c"

#line 27 "..\\CommonSource\\flash\\flash_kinetis.c"
  __attribute__((section(".codeRam"))) Byte buffer[128];





  
FCC0B_STR CommandObj;




extern LWord FLASH_FlashCommandSequenceStart(Byte index);




 
void FLASH_Initialization(void)
{
  LWord i;
  volatile Byte* ptr_FlashCommandSequenceStart = ((Byte*)FLASH_FlashCommandSequenceStart - 1);
  
  
  
  for(i=0;i<128;i++)
    buffer[i] =	*ptr_FlashCommandSequenceStart++;
  
  
   ;; 
}





 
LWord FLASH_ProgramLongWord(LWord destination, LWord data32b)
{
   
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x06;
  CommandObj.regsLong.fccob7654 = data32b; 




	return ((LWord (*)(Byte))&buffer[1])(8);


  
}




 
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b)
{
   
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x07;
  CommandObj.regsLong.fccob7654 = data64b[0];
  CommandObj.regsLong.fccobBA98 = data64b[1];
  
  return ((LWord (*)(Byte))&buffer[1])(12);
}




 
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size)
{ 
  while(size--)
  {
    if(FLASH_ProgramLongWord(destination, *pSource++) != 0)
      return 1;
    destination += 4;
  }
  return 0;
}




 
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size)
{
  LWord my_size;
  
  
  if(size >= 64 - 2)
    return 1;
  
  if(destination & 0x00000003)
    return 1;
  
  
  if(destination & 0x00000004)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = 0xFFFFFFFF;    
    tmp_buff[1] = *(pSource++);
    
    
    if(FLASH_ProgramPhrase((destination & 0xFFFFFFF8), tmp_buff))
      return 1;
    
    destination += 4;    
  }
  
  my_size = size & 0xFFFFFFFE;
 
  if(my_size)
  {
    
    while(my_size)
    {
      
      if(FLASH_ProgramPhrase(destination, pSource))
        return 1;
    
      pSource += 2;
      destination += 8;
      my_size -= 2;      
    }
  }
  
  
  if(size & 0x00000001)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = *pSource;    
    tmp_buff[1] = 0xFFFFFFFF;
    
    
    if(FLASH_ProgramPhrase(destination, tmp_buff))
      return 1;           
  }
  return 0;
}




 
LWord FLASH_EraseSector(LWord destination)
{  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x09;




		return ((LWord (*)(Byte))&buffer[1])(4);

  
  
}



