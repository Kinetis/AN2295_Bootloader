/**
  ******************************************************************************
  * @file    led.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   ����ԭ�Ӻ˺��İ� BSP���� LED����
  ******************************************************************************
  */
#include "led.h"

/***********************************************************************************************
 ���ܣ�LED��ʼ��
 �βΣ�0
 ���أ�0
 ��⣺��ʼ�������ϵ�LED ����GPIO����
************************************************************************************************/
void LED_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStruct1;
	
	GPIO_InitStruct1.GPIO_Pin = LED1_PIN;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = LED1_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = LED2_PIN;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = LED2_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = LED3_PIN;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = LED3_PORT;
	GPIO_Init(&GPIO_InitStruct1);
}


void LED_Set(uint8_t LEDNum, uint8_t OnOff)
{
	switch(LEDNum)
	{
		case 0:
			GPIO_WriteBit(LED1_PORT,LED1_PIN,OnOff);
			break;
		case 1:
			GPIO_WriteBit(LED2_PORT,LED2_PIN,OnOff);
			break;	
		case 2:
			GPIO_WriteBit(LED3_PORT,LED3_PIN,OnOff);
			break;	
		default:break;
	}
}

void LED_Toggle(uint8_t LEDNum)
{
	switch(LEDNum)
	{
		case 0:
			GPIO_ToggleBit(LED1_PORT,LED1_PIN);
			break;
		case 1:
			GPIO_ToggleBit(LED2_PORT,LED2_PIN);
			break;
		case 2:
			GPIO_ToggleBit(LED3_PORT,LED3_PIN);
			break;
		default:break;
	}
}
