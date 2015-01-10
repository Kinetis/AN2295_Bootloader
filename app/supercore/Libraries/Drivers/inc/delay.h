/**
  ******************************************************************************
  * @file    delay.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.25
  * @brief   ����K60�̼��� ��ʱ ������ ͷ�ļ�
  ******************************************************************************
  */
#ifndef __DELAY_H__
#define __DELAY_H__

#ifdef __cplusplus
	 extern "C" {
#endif


#include "sys.h"

//������ʵ�ֵĽӿں����б�
void DelayInit(void); //��ʱ��ʼ��
void DelayUs(uint32_t us);      //��ʱus
void DelayMs(uint32_t ms);      //��ʱms
		 
#ifdef __cplusplus
}
#endif
		 
#endif
