/**
  ******************************************************************************
  * @file    led.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   ����ԭ�Ӻ˺��İ� BSP���� LED����
  ******************************************************************************
  */
#ifndef __LED_H__
#define __LED_H__

#include "gpio.h"

#ifdef __cplusplus
 extern "C" {
#endif

//LEDͷ�ļ�
//IO ��
#define LED1_PORT PTD
#define LED2_PORT PTB
#define LED3_PORT PTB	

//����
#define LED1_PIN  (1)				//BLUE
#define LED2_PIN  (19)			//GREEN
#define LED3_PIN  (18)			//RED

#define LED_ON    0
#define LED_OFF   1

//��������ʵ�ֵĺ����ӿ��б�
void LED_Init(void);
void LED_Set(uint8_t LEDNum, uint8_t OnOff);
void LED_Toggle(uint8_t LEDNum);
	 
	 
#ifdef __cplusplus
}
#endif




#endif
