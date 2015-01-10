#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "sys.h"


#define ADC0_DP0_PE20_DM0_PE21  (0xA860U)
#define ADC0_DP1_PE16_DM1_PE17  (0x2A060U)
#define ADC0_DP2_PE18_DM2_PE19  (0x4A460U)
#define ADC0_DP3_PE22_DM3_PE23  (0x6AC60U)
#define ADC0_SE1A_PE16					(0x26060U)
#define ADC0_SE5A_PE17					(0xA6260U)
#define ADC0_SE2A_PE18					(0x6460U)
#define ADC0_SE6A_PE19					(0xC6660U)
#define ADC0_SE0A_PE20					(0x6860U)
#define ADC0_SE4A_PE21					(0x86A60U)
#define ADC0_SE3A_PE22					(0x66C60U)
#define ADC0_SE7A_PE23					(0xE6E60U)

#define ADC0_SE4B_PE29					(0x87A60U)
#define ADC0_SE23A_PE30					(0x2E7C60U)
	 
#define ADC0_SE8A_PB0					  (0x104048U)
#define ADC0_SE9A_PB1					  (0x124248U)
#define ADC0_SE12A_PB2					(0x184448U)
#define ADC0_SE13A_PB3					(0x1A4648U)
#define ADC0_SE14A_PC0					(0x1C4050U)
#define ADC0_SE15A_PC1					(0x1E4250U)
#define ADC0_SE11A_PC2					(0x164450U)
#define ADC0_SE5B_PD1					  (0xA4258U)
#define ADC0_SE6B_PD5					  (0xC4A58U)
#define ADC0_SE7B_PD6					  (0xE4C58U)
	 
//ADC InitTpye Struct define
typedef struct
{
  uint32_t ADCxMap;              
	uint32_t ADC_Precision;
	uint16_t ADC_TriggerSelect; //触发源选择
}ADC_InitTypeDef;


#define IS_ADC_ALL_PERIPH(PERIPH)  ((PERIPH) == ADC0)

//ADC 精度定义
#define ADC_PRECISION_8BIT    (0x00U)
#define ADC_PRECISION_10BIT   (0x02U)
#define ADC_PRECISION_12BIT   (0x01U)
#define ADC_PRECISION_16BIT   (0x03U)
//参数检查
#define IS_ADC_PRECISION(VALUE) (((VALUE) == ADC_PRECISION_8BIT) ||  \
	                               ((VALUE) == ADC_PRECISION_10BIT) || \
	                               ((VALUE) == ADC_PRECISION_12BIT) || \
	                               ((VALUE) == ADC_PRECISION_16BIT))


//AD转换触发源定义
#define ADC_TRIGGER_HW     (uint16_t)(0)
#define ADC_TRIGGER_SW     (uint16_t)(1)
#define IS_ADC_TRIGGER_SELECT(TRIGGER)  (((TRIGGER) == ADC_TRIGGER_HW) || ((TRIGGER) == ADC_TRIGGER_SW))

//中断源定义
#define ADC_IT_AI       (uint16_t)(0)
#define IS_ADC_IT(IT)  ((IT) == ADC_IT_AI)
//DMA命令
#define ADC_DMAReq_COCO                     ((uint16_t)0)
#define IS_ADC_DMAREQ(REQ)   ((REQ) == ADC_DMAReq_COCO)


#define A                 0x0
#define B                 0x1
#define IS_ADC_MUX(MUX)   (((MUX) == A) || ((MUX) == B))



//API function
void ADC_Init(ADC_InitTypeDef* ADC_InitStruct);
void ADC_DMACmd(ADC_Type* ADCx, uint16_t ADC_DMAReq, FunctionalState NewState);
uint32_t ADC_GetConversionValue(uint32_t ADCxMap);
void ADC_ITConfig(ADC_Type* ADCx,uint8_t ADC_Mux, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ClearITPendingBit(ADC_Type* ADCx, uint8_t ADC_Mux, uint16_t ADC_IT);


#ifdef __cplusplus
}
#endif

#endif

