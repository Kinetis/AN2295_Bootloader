/**
  ******************************************************************************
  * @file    gpio.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.25
  * @brief   ����K60�̼��� GPIO ������ API����
  ******************************************************************************
  */
 #include "gpio.h"
 
/***********************************************************************************************
 ���ܣ�GPIO��ʼ��
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
			 GPIO_InitStruct
       GPIO ��ʼ���ṹ
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_Init(GPIO_InitTypeDef* GPIO_InitStruct)
{
	GPIO_Type *GPIOx = NULL;
	PORT_Type *PORTx = NULL;
	//�������
	assert_param(IS_GPIO_ALL_PERIPH(GPIO_InitStruct->GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
	assert_param(IS_GPIO_BIT_ACTION(GPIO_InitStruct->GPIO_InitState )); 
	assert_param(IS_GPIO_IRQC(GPIO_InitStruct->GPIO_IRQMode));
	assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
	
	GPIOx = GPIO_InitStruct->GPIOx;
	//���˿�ʱ��
	switch((uint32_t)GPIOx)
	{
		case PTA_BASE:PORTx=PORTA;SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;break; //����PORTA��ʹ��ʱ�ӣ�������ǰ���ȿ���ʹ��ʱ�Ӳμ�k10�ֲ�268ҳ��
	  case PTB_BASE:PORTx=PORTB;SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;break;	//����PORTB��ʹ��ʱ��
	  case PTC_BASE:PORTx=PORTC;SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;break;	//����PORTC��ʹ��ʱ��
	  case PTD_BASE:PORTx=PORTD;SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;break;	//����PORTD��ʹ��ʱ��
	  case PTE_BASE:PORTx=PORTE;SIM->SCGC5|=SIM_SCGC5_PORTE_MASK;break;	//����PORTE��ʹ��ʱ��
	  default : break;
	} 
	//����ΪGPIOģʽ
	PORTx->PCR[GPIO_InitStruct->GPIO_Pin]&=~(PORT_PCR_MUX_MASK);    
	PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|=PORT_PCR_MUX(1); 
	//ȷ�������뻹�����
	if((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OOD) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OPP))
	{
		//����GPIOx�ڵĵ�GPIO_Pin����Ϊ���
		GPIOx->PDDR |= (1<<(GPIO_InitStruct->GPIO_Pin));	
		//��Ϊ�����ʱ�رո����ŵ����������蹦��
	  PORTx->PCR[(GPIO_InitStruct->GPIO_Pin)]&=~(PORT_PCR_PE_MASK); 
		//�����ƽ����
		(Bit_SET == GPIO_InitStruct->GPIO_InitState)?(GPIOx->PDOR |= (1<<(GPIO_InitStruct->GPIO_Pin))):(GPIOx->PDOR &= ~(1<<(GPIO_InitStruct->GPIO_Pin)));
		//��©�����������
		if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OOD)
		{
//			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|= PORT_PCR_ODE_MASK;
		}
		else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OPP)
		{
	//		PORTx->PCR[GPIO_InitStruct->GPIO_Pin]&= ~PORT_PCR_ODE_MASK;
		}
	}
	//���������ģʽ
	else if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN_FLOATING) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU))
	{
		//����GPIOx�ڵĵ�GPIO_Pin����Ϊ����
		GPIOx->PDDR &= ~(1<<(GPIO_InitStruct->GPIO_Pin));		
		if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN_FLOATING)
		{
			//�ر�����������
			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]&=~PORT_PCR_PE_MASK; 	//����������DISABLE
		}
		else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) //����
		{
			//������������
			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|= PORT_PCR_PE_MASK; 	//����������ʹ��
			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]&= ~PORT_PCR_PS_MASK;
			
		}
		else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) //����
		{
			//������������
			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|= PORT_PCR_PE_MASK; 	//����������ʹ��
			PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|= PORT_PCR_PS_MASK;
		}
	}
	//�����ж�ģʽ
	PORTx->PCR[GPIO_InitStruct->GPIO_Pin]&=~PORT_PCR_IRQC_MASK;
	PORTx->PCR[GPIO_InitStruct->GPIO_Pin]|=PORT_PCR_IRQC(GPIO_InitStruct->GPIO_IRQMode);//�ⲿ�жϴ������� 
}
/***********************************************************************************************
 ���ܣ�GPIO����жϱ�־
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
			 GPIO_Pin
       GPIO �˿ں� GPIO_Pin_0 - GPIO_Pin_31
 ���أ�0
 ��⣺0
************************************************************************************************/
ITStatus GPIO_GetITStates(GPIO_Type *GPIOx,uint16_t GPIO_Pin)
{
	PORT_Type *PORTx = NULL;
	//���˿�ʱ��
	switch((uint32_t)GPIOx)
	{
		case PTA_BASE:PORTx = PORTA;break;
	  case PTB_BASE:PORTx = PORTB;break;
	  case PTC_BASE:PORTx = PORTC;break;
	  case PTD_BASE:PORTx = PORTD;break;
	  case PTE_BASE:PORTx = PORTE;break;
	  default : break;
	} 
	//���ر�־λ
	if(PORTx->ISFR & (1<<GPIO_Pin))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/***********************************************************************************************
 ���ܣ�GPIO����жϱ�־
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
			 GPIO_Pin
       GPIO �˿ں� GPIO_Pin_0 - GPIO_Pin_31
 ���أ�0
 ��⣺��GPIO�ж��е��ô˺��������־λ
************************************************************************************************/
void GPIO_ClearITPendingBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin)
{
	PORT_Type *PORTx = NULL;
	//���˿�ʱ��
	switch((uint32_t)GPIOx)
	{
		case PTA_BASE:PORTx=PORTA;SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;break; //����PORTA��ʹ��ʱ�ӣ�������ǰ���ȿ���ʹ��ʱ�Ӳμ�k10�ֲ�268ҳ��
	  case PTB_BASE:PORTx=PORTB;SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;break;	//����PORTB��ʹ��ʱ��
	  case PTC_BASE:PORTx=PORTC;SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;break;	//����PORTC��ʹ��ʱ��
	  case PTD_BASE:PORTx=PORTD;SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;break;	//����PORTD��ʹ��ʱ��
	  case PTE_BASE:PORTx=PORTE;SIM->SCGC5|=SIM_SCGC5_PORTE_MASK;break;	//����PORTE��ʹ��ʱ��
	  default : break;
	} 
	PORTx->ISFR |= (1<<GPIO_Pin);
}
/***********************************************************************************************
 ���ܣ���ʼ���ṹ�� ����Ĭ�ϲ���
 �βΣ�GPIO_InitStruct: ��ʼ���ṹ
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
	GPIO_InitStruct->GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN_FLOATING;
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ0 �� 1
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
			 BitVal:
			 @arg Bit_RESET: ����Ϊ0
			 @arg Bit_SET  : ����Ϊ1
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_WriteBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin,BitAction BitVal)
{	 
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	assert_param(IS_GPIO_BIT_ACTION(BitVal)); 
	
  if (BitVal != Bit_RESET)
  {
    GPIOx->PSOR |= (1<<GPIO_Pin);
  }
  else
  {
    GPIOx->PCOR |= (1<<GPIO_Pin);
  }
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ1
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_SetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	GPIOx->PSOR |= (1<<GPIO_Pin);
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ0
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_ResetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	GPIOx->PCOR |= (1<<GPIO_Pin);
}

/***********************************************************************************************
 ���ܣ���תһ��IO Pin�ĵ�ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_ToggleBit(GPIO_Type *GPIOx,uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
	GPIOx->PTOR |= (1<<GPIO_Pin);	//�����ŵĵ�ƽ���з�ת���ο�k10�ֲ�1483ҳ
}
/***********************************************************************************************
 ���ܣ�д��˿�IO��ƽ ���
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 PortVal��
			 @arg : �˿�����
 ���أ�0
 ��⣺0
************************************************************************************************/
void GPIO_Write(GPIO_Type *GPIOx,uint32_t PortVal)
{
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	GPIOx->PDOR = PortVal;
}
/***********************************************************************************************
 ���ܣ���ȡһ���Ѿ�����Ϊ�����IO Pin�� ��ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg 0-31: �˿ں�
 ���أ��˿ڵ�ƽ
 ��⣺ʵ���Ͼ��Ƕ�ȡPDOR��ֵ
************************************************************************************************/
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
  if(((GPIOx->PDOR >> GPIO_Pin) & 1 ) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}
/***********************************************************************************************
 ���ܣ���ȡһ���Ѿ�����Ϊ�����IO�� ��ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
 ���أ��˿ڵ�ƽ
 ��⣺ʵ���Ͼ��Ƕ�ȡPDOR��ֵ
************************************************************************************************/
uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx)
{
  //������
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    
  return ((uint16_t)GPIOx->PDOR);
}
/***********************************************************************************************
 ���ܣ���ȡһ��IO�˿ڵ�ĳһ��PIN�ĵ�ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
			 GPIO_Pin:
			 @arg 0-31 ����
 ���أ��߼���ƽ 0 ���� 1
 ��⣺���������ö˿�Ϊ����˿�
************************************************************************************************/
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{	 
	uint8_t bitstatus = 0x00;
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
  if (((GPIOx->PDIR >> GPIO_Pin)& 0x01) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}
/***********************************************************************************************
 ���ܣ���ȡһ��IO�˿ڵ������ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
 ���أ��˿ڵ�ƽ
 ��⣺���������ö˿�Ϊ����˿�
************************************************************************************************/
uint32_t GPIO_ReadInputData(GPIO_Type *GPIOx)
{
	//������
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
	 return(GPIOx->PDIR);
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ0 �� 1
 �βΣ�FGPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
			 BitVal:
			 @arg Bit_RESET: ����Ϊ0
			 @arg Bit_SET  : ����Ϊ1
 ���أ�0
 ��⣺0
************************************************************************************************/
void FGPIO_WriteBit(FGPIO_Type *GPIOx,uint16_t GPIO_Pin,BitAction BitVal)
{	 
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	assert_param(IS_GPIO_BIT_ACTION(BitVal)); 
	
  if (BitVal != Bit_RESET)
  {
    GPIOx->PSOR |= (1<<GPIO_Pin);
  }
  else
  {
    GPIOx->PCOR |= (1<<GPIO_Pin);
  }
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ1
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void FGPIO_SetBits(FGPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	GPIOx->PSOR |= (1<<GPIO_Pin);
}
/***********************************************************************************************
 ���ܣ���һ��IO Pin����Ϊ0
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void FGPIO_ResetBits(FGPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	GPIOx->PCOR |= (1<<GPIO_Pin);
}

/***********************************************************************************************
 ���ܣ���תһ��IO Pin�ĵ�ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg : 0-31 ����
 ���أ�0
 ��⣺0
************************************************************************************************/
void FGPIO_ToggleBit(FGPIO_Type *GPIOx,uint16_t GPIO_Pin)
{
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
	GPIOx->PTOR |= (1<<GPIO_Pin);	//�����ŵĵ�ƽ���з�ת���ο�k10�ֲ�1483ҳ
}
/***********************************************************************************************
 ���ܣ�д��˿�IO��ƽ ���
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 PortVal��
			 @arg : �˿�����
 ���أ�0
 ��⣺0
************************************************************************************************/
void FGPIO_Write(FGPIO_Type *GPIOx,uint32_t PortVal)
{
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	GPIOx->PDOR = PortVal;
}
/***********************************************************************************************
 ���ܣ���ȡһ���Ѿ�����Ϊ�����IO Pin�� ��ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
		 	 GPIO_Pin��
			 @arg 0-31: �˿ں�
 ���أ��˿ڵ�ƽ
 ��⣺ʵ���Ͼ��Ƕ�ȡPDOR��ֵ
************************************************************************************************/
uint8_t FGPIO_ReadOutputDataBit(FGPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
  if(((GPIOx->PDOR >> GPIO_Pin) & 1 ) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}
/***********************************************************************************************
 ���ܣ���ȡһ���Ѿ�����Ϊ�����IO�� ��ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
 ���أ��˿ڵ�ƽ
 ��⣺ʵ���Ͼ��Ƕ�ȡPDOR��ֵ
************************************************************************************************/
uint32_t FGPIO_ReadOutputData(FGPIO_Type* GPIOx)
{
  //������
  assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
    
  return ((uint16_t)GPIOx->PDOR);
}
/***********************************************************************************************
 ���ܣ���ȡһ��IO�˿ڵ�ĳһ��PIN�ĵ�ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
			 GPIO_Pin:
			 @arg 0-31 ����
 ���أ��߼���ƽ 0 ���� 1
 ��⣺���������ö˿�Ϊ����˿�
************************************************************************************************/
uint8_t FGPIO_ReadInputDataBit(FGPIO_Type* GPIOx, uint16_t GPIO_Pin)
{	 
	uint8_t bitstatus = 0x00;
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(GPIO_Pin));
	
  if (((GPIOx->PDIR >> GPIO_Pin)& 0x01) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}
/***********************************************************************************************
 ���ܣ���ȡһ��IO�˿ڵ������ƽ
 �βΣ�GPIOx:
			 @arg PTA:A�˿�
			 @arg PTB:B�˿�
			 @arg PTC:C�˿�
			 @arg PTD:D�˿�
			 @arg PTE:E�˿�
 ���أ��˿ڵ�ƽ
 ��⣺���������ö˿�Ϊ����˿�
************************************************************************************************/
uint32_t FGPIO_ReadInputData(FGPIO_Type *GPIOx)
{
	//������
	assert_param(IS_FGPIO_ALL_PERIPH(GPIOx));
	
	 return(GPIOx->PDIR);
}

