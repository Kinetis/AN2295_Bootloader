/**
  ******************************************************************************
  * @file    sys.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   CH KL series Frimware Lib: SYS component
  ******************************************************************************
  */
	 
#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "MKL25Z4.h"
//配置宏
//#define USE_FULL_ASSERT                          //是否启动参数检测机制，如果启用需要用户实现 assert_failed函数
//#define DEBUG_PRINT                              //是否用串口打印调试信息
//#define SYSTEM_SUPPORT_OS				               //支持uCOS操作系统

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
typedef enum{FALSE = 0, TRUE = !FALSE} ErrorState;

#ifndef NULL
	#define NULL 0
#endif


#define  FW_VERSION                 (240)                //CH_KL固件库版本
// assert_param marco
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

// general peripheral Map define
typedef struct
{
	uint32_t m_ModuleIndex:3;
	uint32_t m_PortIndex:3;
	uint32_t m_MuxIndex:3;
	uint32_t m_PinBaseIndex:5;
	uint32_t m_PinCntIndex:3;
	uint32_t m_ChlIndex:5;
	uint32_t m_SpecDefine1:2;
}PeripheralMapTypeDef;

//Microcontroller information
typedef struct
{
	uint8_t FamilyType;    //Kinetis Familt Type
	uint8_t ResetState;    //Reset States
	uint8_t SiliconRev;    //SiliconRev
	uint16_t PinCnt;       //Pin Cnt
	uint32_t PFlashSize;   //PFlash Size
	uint32_t FlexNVMSize;  //FlexNVM Size
	uint32_t RAMSize;      //RAM Size
	uint32_t CoreClock;    //CoreClock
	uint32_t BusClock;     //BusClock
	uint32_t FlexBusClock; //FlexBus Clock
	uint32_t FlashClock;   //Flash Clock
} CPUInfoType_t;
extern CPUInfoType_t CPUInfo;

//Clock source select
#define ClockSource_IRC     ((uint8_t)0x0)
#define ClockSource_EX8M  	((uint8_t)0x5)
//Clock source select check marco
#define IS_CLOCK_OPTION(SOURCE)			 (((SOURCE)  == ClockSource_IRC)  ||  \
                                       ((SOURCE) == ClockSource_EX50M) || \
                                       ((SOURCE) == ClockSource_EX8M))
//Core Clock ouput select
#define CoreClock_48M				((uint8_t)0x8)
#define CoreClock_24M				((uint8_t)0x7)

//Core clock output check macro
#define IS_CLOCK_SELECT(CLOCK_TYPE)   (((CLOCK_TYPE) ==    CoreClock_100M)||   \
																			 ((CLOCK_TYPE) ==    CoreClock_200M)||   \
																			 ((CLOCK_TYPE) ==    CoreClock_96M) ||   \
																			 ((CLOCK_TYPE) ==    CoreClock_72M) ||   \
																			 ((CLOCK_TYPE) ==    CoreClock_64M) ||   \
																			 ((CLOCK_TYPE) ==    CoreClock_48M))
//NVIC中断分组选择
#define NVIC_PriorityGroup_0         ((uint32_t)0x7) /*!< 0 bits for pre-emption priority   4 bits for subpriority */                                               
#define NVIC_PriorityGroup_1         ((uint32_t)0x6) /*!< 1 bits for pre-emption priority   3 bits for subpriority */                                                  
#define NVIC_PriorityGroup_2         ((uint32_t)0x5) /*!< 2 bits for pre-emption priority   2 bits for subpriority */                                                   
#define NVIC_PriorityGroup_3         ((uint32_t)0x4) /*!< 3 bits for pre-emption priority   1 bits for subpriority */                                                   
#define NVIC_PriorityGroup_4         ((uint32_t)0x3) /*!< 4 bits for pre-emption priority   0 bits for subpriority */
//参数检测器宏
#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PriorityGroup_0) || \
                                       ((GROUP) == NVIC_PriorityGroup_1) || \
                                       ((GROUP) == NVIC_PriorityGroup_2) || \
                                       ((GROUP) == NVIC_PriorityGroup_3) || \
                                       ((GROUP) == NVIC_PriorityGroup_4))
#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)
#define IS_NVIC_SUB_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)

//VETOR_OFFSET check marcro
#define IS_VECTOR_OFFSET(OFFSET)  ((OFFSET) % 4 == 0)

//  API functions
void SystemClockSetup(uint8_t ClockOption,uint16_t CoreClock);  
void SystemSoftReset(void);                                     
void GetCPUInfo(void);                                          
void EnableInterrupts(void);                                    
void DisableInterrupts(void);                                   
void SetVectorTable(uint32_t offset);                           
void NVIC_EnableIRQ(IRQn_Type IRQn);                                          
void NVIC_DisableIRQ(IRQn_Type IRQn);                           
void NVIC_Init(IRQn_Type IRQn,uint32_t PriorityGroup,uint32_t PreemptPriority,uint32_t SubPriority); //设置中断优先级
uint16_t GetFWVersion(void);
void PinMuxConfig(uint8_t GPIOIndex, uint8_t PinIndex, uint8_t MuxIndex);

#ifdef __cplusplus
}
#endif

#endif

