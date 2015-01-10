/**
  ******************************************************************************
  * @file    pit.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   ����K60�̼��� �ڲ���ʱ������
  ******************************************************************************
  */
#include "pit.h"
/***********************************************************************************************
 ���ܣ���ʼ��PITģ��
 �βΣ�PIT_InitStruct��PIT��ʼ���ṹ
 ���أ�0
 ��⣺
************************************************************************************************/
void PIT_Init(PIT_InitTypeDef* PIT_InitStruct)
{	 
	uint32_t time = 0;
	//������
	assert_param(IS_PIT_CH(PIT_InitStruct->PITx));
	//�����Ƶ��
	GetCPUInfo();
	time = (PIT_InitStruct->PIT_Interval)*(CPUInfo.BusClock/1000);
	//ʹ��PITʱ��
	SIM->SCGC6|=SIM_SCGC6_PIT_MASK;
	//ʹ��ģ��
	PIT->MCR&=~PIT_MCR_MDIS_MASK;
	//��ʼ��ʱ
	PIT->MCR|=PIT_MCR_FRZ_MASK;
	PIT->CHANNEL[PIT_InitStruct->PITx].LDVAL = (uint32_t)time;//������ʱʱ��
	PIT->CHANNEL[PIT_InitStruct->PITx].TFLG |= PIT_TFLG_TIF_MASK;//�����־λ
	PIT->CHANNEL[PIT_InitStruct->PITx].TCTRL |= (PIT_TCTRL_TEN_MASK);//������ʱ�����жϣ����ο��ֲ�976ҳ
}
/***********************************************************************************************
 ���ܣ�PIT ���Ԥ�趨ʱ��ֵ��С
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
 ���أ�0
 ��⣺
************************************************************************************************/
uint32_t PIT_GetLoadValue(uint8_t PITx)
{
	//������
	assert_param(IS_PIT_CH(PITx));
	
	return 	PIT->CHANNEL[PITx].LDVAL;
}
/***********************************************************************************************
 ���ܣ�PIT ��õ�ǰ���ж�ʱ��ֵ��С
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
 ���أ�0
 ��⣺
************************************************************************************************/
uint32_t PIT_GetCurrentValue(uint8_t PITx)
{
	//������
	assert_param(IS_PIT_CH(PITx));
		
	return PIT->CHANNEL[PITx].CVAL;
}
/***********************************************************************************************
 ���ܣ�PIT ����Ԥ��ֵ��ʱ��С
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
			 Value : ֵ 0-0xFFFFFFFF
 ���أ�0
 ��⣺
************************************************************************************************/
void PIT_SetLoadValue(uint8_t PITx, uint32_t Value)
{
	//������
	assert_param(IS_PIT_CH(PITx));
	
	PIT->CHANNEL[PITx].LDVAL = Value;
}
/***********************************************************************************************
 ���ܣ�PIT ��ʼ����
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
 ���أ�0
 ��⣺
************************************************************************************************/
void PIT_Start(uint8_t PITx)
{
	//������
	assert_param(IS_PIT_CH(PITx));
	
	PIT->CHANNEL[PITx].TCTRL |= PIT_TCTRL_TEN_MASK;
}
/***********************************************************************************************
 ���ܣ�PIT ��ͣ
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
 ���أ�0
 ��⣺
************************************************************************************************/
void PIT_Stop(uint8_t PITx)
{
	//������
	assert_param(IS_PIT_CH(PITx));
	
	PIT->CHANNEL[PITx].TCTRL &= ~PIT_TCTRL_TEN_MASK;
}
/***********************************************************************************************
 ���ܣ�PIT �ж�����
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
			 PIT_IT : �жϺ�
       @arg PIT_IT_TIF : PIT��ʱ�ж�
       NewState : �������߹ر�
			 @arg ENABLE : ���� 
       @arg DISABLE: �ر�
 ���أ�0
 ��⣺
************************************************************************************************/
void PIT_ITConfig(uint8_t PITx, uint16_t PIT_IT, FunctionalState NewState)
{
	//������
	assert_param(IS_PIT_IT(PIT_IT));
	assert_param(IS_PIT_CH(PITx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if(PIT_IT == PIT_IT_TIF)
	{
		(ENABLE == NewState)?(PIT->CHANNEL[PITx].TCTRL |= PIT_TCTRL_TIE_MASK):(PIT->CHANNEL[PITx].TCTRL &= ~PIT_TCTRL_TIE_MASK);
	}
}
/***********************************************************************************************
 ���ܣ�PIT ����жϱ�־
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
			 PIT_IT : �жϺ�
       @arg PIT_IT_TIF : PIT��ʱ�ж�
 ���أ�SET:�жϱ�־��λ RESET:û�з����ж�
 ��⣺
************************************************************************************************/
ITStatus PIT_GetITStatus(uint8_t PITx, uint16_t PIT_IT)
{
	//������
	assert_param(IS_PIT_IT(PIT_IT));
	assert_param(IS_PIT_CH(PITx));
	
	if(PIT_IT == PIT_IT_TIF)
	{
		if(PIT->CHANNEL[PITx].TFLG & PIT_TFLG_TIF_MASK)
		{
			return SET;
		}
		else
		{
			return RESET;
		}
	}
	return RESET;
}
/***********************************************************************************************
 ���ܣ�PIT ����жϱ�־
 �βΣ�PITx��PITͨ��
       @arg PIT0 : PIT0ͨ��
       @arg PIT1 : PIT1ͨ��
       @arg PIT2 : PIT2ͨ��
       @arg PIT3 : PIT3ͨ��
			 PIT_IT : �жϺ�
       @arg PIT_IT_TIF : PIT��ʱ�ж�
 ���أ�0
 ��⣺�жϺ����е���
************************************************************************************************/
void PIT_ClearITPendingBit(uint8_t PITx,uint16_t PIT_IT)
{
	//������
	assert_param(IS_PIT_IT(PIT_IT));
	assert_param(IS_PIT_CH(PITx));
	
	PIT->CHANNEL[PITx].TFLG |= PIT_TFLG_TIF_MASK;
}


