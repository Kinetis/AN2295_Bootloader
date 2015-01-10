/**
  ******************************************************************************
  * @file    delay.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.25
  * @brief   ����K60�̼��� ��ʱ ������ API����
  ******************************************************************************
  */
#include "delay.h"

//��ʱ����C �ļ�
static uint8_t  fac_us=0;//us��ʱ������
static uint32_t fac_ms=0;//ms��ʱ������
#ifdef SYSTEM_SUPPORT_OS 	//���ʹ��UCOS����ģʽ
#include "includes.h"					//ucos ʹ��	 
uint32_t OS_ReloadValue;         //SysTick��װֵ
/***********************************************************************************************
 ���ܣ�SysTick�ں��ж�
 �βΣ�0
 ���أ�0
 ��⣺��Ҫ����Ϊ����ϵͳ�ṩʱ�ӽ���
************************************************************************************************/
void SysTick_Handler (void)
{
	OSIntEnter();		//�����ж�
	OSTimeTick();       //����ucos��ʱ�ӷ������               
	OSIntExit();        //���������л����ж�
}
#endif
/***********************************************************************************************
 ���ܣ���ʼ����ʱģ��
 �βΣ�0
 ���أ�0
 ��⣺�˺������ڳ�ʼ����ʱģ��,ʹ�ú���ʱ������á�����������ʱ��������
			 ��ʹ��uCOSʱ ������OSInit();֮�����DelayInit(); ������OS����
************************************************************************************************/
void DelayInit()//SYSCLKĬ�ϵ��ں���Ƶ��Ϊ48MHz Ƶ����MDK�����ļ������� CLOCK_SETUP ��
{
	SysTick->CTRL|=0x04;							//����ϵͳ�δ�ʱ��ԴΪϵͳ�ں�Ƶ��
	GetCPUInfo();  							//����ϵͳʱ��
	fac_us=CPUInfo.CoreClock/1000000;
#ifdef SYSTEM_SUPPORT_OS					//���OS_CRITICAL_METHOD������,˵��ʹ��ucosII��.
	SysTick->CTRL|=1<<1;   						//����SYSTICK�ж�
	SysTick->LOAD=CPUInfo.CoreClock/OS_TICKS_PER_SEC; 	//ÿ1/OS_TICKS_PER_SEC���ж�һ��	
	OS_ReloadValue=SysTick->LOAD;                     //��¼ʹ��UCOSʱ����ʱֵ
	SysTick->CTRL|=1<<0;   														//����SYSTICK 
#else
	fac_ms=(uint32_t)fac_us*1000;
#endif
}

#ifdef SYSTEM_SUPPORT_OS	      //���OS_CRITICAL_METHOD������,˵��ʹ��ucosII��.
/***********************************************************************************************
 ���ܣ�US����ʱ����
 �βΣ�US ��Ҫ��ʱ����US
 ���أ�0
 ��⣺������ϵͳ�µ���ʱUS
************************************************************************************************/
void DelayUs(uint32_t us)
{  
	uint32_t temp;
	uint32_t told;
	told=SysTick->VAL;								//�ս���ʱ�ļ�����ֵ
	OSSchedLock();										//��ֹucos���ȣ���ֹ���us��ʱ
	SysTick->CTRL&=~(1<<1);   				//�ر�SYSTICK�ж�
	SysTick->LOAD=us*fac_us; 					//ʱ�����
	SysTick->VAL=0x00;  						  //��ռ�����
	SysTick->CTRL|=1<<0	; 						//��ʼ����   
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16))); //�ȴ�ʱ�䵽��   
	SysTick->LOAD=OS_ReloadValue;      //�ָ�OS ��ʱֵ
	SysTick->VAL=told;                 //�ָ���ֵ
	SysTick->CTRL|=1<<1;               //����SYSTICK�ж�
	OSSchedUnlock();			             //����ucos���� 								
}
/***********************************************************************************************
 ���ܣ�MS����ʱ����
 �βΣ�MS��Ҫ��ʱ����MS
 ���أ�0
 ��⣺������ϵͳ�µ���ʱMS
************************************************************************************************/
void DelayMs(uint32_t ms)    
{
	if(OSRunning == TRUE)//���os�Ѿ�������	 
	{ 
		if(ms>=(1000/OS_TICKS_PER_SEC))//��ʱ��ʱ�����ucos������ʱ������ 
		{
   			OSTimeDly(ms/(1000/OS_TICKS_PER_SEC));//ucos��ʱ
		}
		ms%=(1000/OS_TICKS_PER_SEC);			//ucos�Ѿ��޷��ṩ��ôС����ʱ��,������ͨ��ʽ��ʱ    
	}	
	if(ms != 0) DelayUs((uint32_t)(ms*1000));	//��ͨ��ʽ��ʱ 	
}

#else //����UCOS�����

/***********************************************************************************************
 ���ܣ�US����ʱ����
 �βΣ�US ��Ҫ��ʱ����US
 ���أ�0
 ��⣺����µ���ʱUS
************************************************************************************************/
void DelayUs(uint32_t us)
{ 
	uint32_t temp;
   SysTick->LOAD=us*fac_us; 					//ʱ�����
   SysTick->VAL=0x00;   							//��ռ�����
   SysTick->CTRL|=0x01	;						 	//��ʼ����   
		do
		{
			temp=SysTick->CTRL;
		}
	while(temp&0x01&&!(temp&(1<<16)));	//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~0x01;      				  //�رռ�����
}
/***********************************************************************************************
 ���ܣ�MS����ʱ����
 �βΣ�MS��Ҫ��ʱ����MS
 ���أ�0
 ��⣺����µ���ʱMS
************************************************************************************************/
void DelayMs(uint32_t ms)    
{
	uint32_t temp;
	uint16_t i;
	for(i=0;i<ms;i++)      			 		 //��ʱ MS 
	{
		SysTick->LOAD=fac_ms;  					 //ʱ�����1ms
		SysTick->VAL=0x00;    				   //��ռ�����
		SysTick->CTRL|=0x01;   				 	 //��ʼ����   
		do
		{
			temp=SysTick->CTRL;
		}
		while(temp&0x01&&!(temp&(1<<16)));  //�ȴ�ʱ�䵽��   
		SysTick->CTRL&=~0x01;             	//�رռ�����
	}
}
#endif

