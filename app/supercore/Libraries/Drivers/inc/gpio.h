/**
  ******************************************************************************
  * @file    gpio.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.25
  * @brief   ����K60�̼��� GPIO API���� ͷ�ļ�
  ******************************************************************************
  */
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "sys.h"


#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == PTA) || \
                                    ((PERIPH) == PTB) || \
                                    ((PERIPH) == PTC) || \
                                    ((PERIPH) == PTD) || \
                                    ((PERIPH) == PTE))

#define IS_FGPIO_ALL_PERIPH(PERIPH) (((PERIPH) == FPTA) || \
                                    ((PERIPH) == FPTB) || \
                                    ((PERIPH) == FPTC) || \
                                    ((PERIPH) == FPTD) || \
                                    ((PERIPH) == FPTE))


#define IS_PORT_ALL_PERIPH(PERIPH) (((PERIPH) == PORTA) || \
                                    ((PERIPH) == PORTB) || \
                                    ((PERIPH) == PORTC) || \
                                    ((PERIPH) == PORTD) || \
                                    ((PERIPH) == PORTE))

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;
#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))


//GPIO����
#define GPIO_Pin_0             (uint16_t)(0)
#define GPIO_Pin_1             (uint16_t)(1)
#define GPIO_Pin_2             (uint16_t)(2)
#define GPIO_Pin_3             (uint16_t)(3)
#define GPIO_Pin_4             (uint16_t)(4)
#define GPIO_Pin_5             (uint16_t)(5)
#define GPIO_Pin_6             (uint16_t)(6)
#define GPIO_Pin_7             (uint16_t)(7)
#define GPIO_Pin_8             (uint16_t)(8)
#define GPIO_Pin_9             (uint16_t)(9)
#define GPIO_Pin_10            (uint16_t)(10)
#define GPIO_Pin_11            (uint16_t)(11)
#define GPIO_Pin_12            (uint16_t)(12)
#define GPIO_Pin_13            (uint16_t)(13)
#define GPIO_Pin_14            (uint16_t)(14)
#define GPIO_Pin_15            (uint16_t)(15)
#define GPIO_Pin_16            (uint16_t)(16)
#define GPIO_Pin_17            (uint16_t)(17)
#define GPIO_Pin_18            (uint16_t)(18)
#define GPIO_Pin_19            (uint16_t)(19)
#define GPIO_Pin_20            (uint16_t)(20)
#define GPIO_Pin_21            (uint16_t)(21)
#define GPIO_Pin_22            (uint16_t)(22)
#define GPIO_Pin_23            (uint16_t)(23)
#define GPIO_Pin_24            (uint16_t)(24)
#define GPIO_Pin_25            (uint16_t)(25)
#define GPIO_Pin_26            (uint16_t)(26)
#define GPIO_Pin_27            (uint16_t)(27)
#define GPIO_Pin_28            (uint16_t)(28)
#define GPIO_Pin_29            (uint16_t)(29)
#define GPIO_Pin_30            (uint16_t)(30)
#define GPIO_Pin_31            (uint16_t)(31)
#define IS_GPIO_PIN(PIN)            ((PIN < 32))



typedef enum
{
  GPIO_Mode_IN_FLOATING = 0x04,     //��������
  GPIO_Mode_IPD = 0x05,             //��������
  GPIO_Mode_IPU = 0x06,             //��������
  GPIO_Mode_OOD = 0x07,             //��©���
  GPIO_Mode_OPP = 0x08,             //�������
}GPIO_Mode_TypeDef;
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN_FLOATING) || \
                            ((MODE) == GPIO_Mode_IPD)         || \
                            ((MODE) == GPIO_Mode_IPU)         || \
                            ((MODE) == GPIO_Mode_OOD)         || \
                            ((MODE) == GPIO_Mode_OPP))
//�ж�����
typedef enum
{
  GPIO_IT_DISABLE = 0x00,              //��ֹ�ⲿ�ж�
	GPIO_IT_DMA_RISING = 0x01,           //DMA�����ش���
  GPIO_IT_DMA_FALLING = 0x02,          //DMA�½��ش���
	GPIO_IT_DMA_RASING_FALLING = 0x03,   //DMA�������½��ش���
	GPIO_IT_LOW = 0x08,                  //�߼�0״̬����
	GPIO_IT_RISING = 0x09,               //�����ش���
	GPIO_IT_FALLING = 0x0A,              //�½��ش���
	GPIO_IT_RISING_FALLING = 0x0B,       //�������½��ش���
	GPIO_IT_HIGH = 0x0C,                 //�߼�1����
}GPIO_IT_TypeDef;

#define IS_GPIO_IRQC(TRIGGER)    (((TRIGGER) == GPIO_IT_DISABLE)            || \
                                  ((TRIGGER) == GPIO_IT_DMA_RISING)         || \
																	((TRIGGER) == GPIO_IT_DMA_FALLING)        || \
                                  ((TRIGGER) == GPIO_IT_DMA_RASING_FALLING) || \
																	((TRIGGER) == GPIO_IT_LOW)                || \
                                  ((TRIGGER) == GPIO_IT_RISING)             || \
																	((TRIGGER) == GPIO_IT_FALLING)            || \
                                  ((TRIGGER) == GPIO_IT_RISING_FALLING)     || \
																	((TRIGGER) == GPIO_IT_HIGH))

typedef struct
{
  uint16_t GPIO_Pin;                //����
	BitAction GPIO_InitState;         //��ʼ״̬
	GPIO_IT_TypeDef GPIO_IRQMode;     //GPIO�ж�״̬����
  GPIO_Mode_TypeDef GPIO_Mode;      //GPIOģʽ����
	GPIO_Type *GPIOx;                 //GPIO�˿ں�
}GPIO_InitTypeDef;

//������ʵ�ֵĽӿں����б�
void GPIO_Init(GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_WriteBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin,BitAction BitVal);
void GPIO_SetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ToggleBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin);
void GPIO_Write(GPIO_Type *GPIOx,uint32_t PortVal);
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx);
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
uint32_t GPIO_ReadInputData(GPIO_Type *GPIOx);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
ITStatus GPIO_GetITStates(GPIO_Type *GPIOx,uint16_t GPIO_Pin);
void GPIO_ClearITPendingBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif
