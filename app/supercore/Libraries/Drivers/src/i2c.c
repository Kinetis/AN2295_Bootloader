/**
  ******************************************************************************
  * @file    i2c.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   ����K60�̼��� IIC �����ļ�
  ******************************************************************************
  */
#include "i2c.h"

/***********************************************************************************************
 ���ܣ�I2C ��ʼ��
 �βΣ�I2C_InitStruct: I2C��ʼ���ṹ
 ���أ�0
 ��⣺0
************************************************************************************************/
void I2C_Init(I2C_InitTypeDef* I2C_InitStruct)
{
	uint8_t i;
	I2C_Type *I2Cx = NULL;
	uint32_t prescaler = 0;
	PeripheralMapTypeDef *pI2C_Map = (PeripheralMapTypeDef*)&(I2C_InitStruct->I2CxMAP);
	//�������
	assert_param(IS_I2C_CLOCK_SPEED(I2C_InitStruct->I2C_ClockSpeed));
	//ʹ��I2Cʱ��
	switch(pI2C_Map->m_ModuleIndex)
	{
		case 0:
			SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK; 
			I2Cx = I2C0;
			break;
		case 1:
			SIM->SCGC4 |= SIM_SCGC4_I2C1_MASK;
			I2Cx = I2C1;		
			break;
		default:break;
	}

	//����������Ϊ©�����
	//����I2C��Ƶ��
	prescaler = (((CPUInfo.BusClock /(I2C_InitStruct->I2C_ClockSpeed))-160))/32 +  0x20;
	I2Cx->F	= prescaler;
	//  config PinMux
	for(i=0;i<pI2C_Map->m_PinCntIndex;i++)
	{
		PinMuxConfig(pI2C_Map->m_PortIndex,pI2C_Map->m_PinBaseIndex+i,pI2C_Map->m_MuxIndex);
	}
	//ʹ��I2Cģ��
	I2Cx->C1 = I2C_C1_IICEN_MASK ;
	

}
/***********************************************************************************************
 ���ܣ�I2C ���Ϳ�ʼ�ź�
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ�0
 ��⣺ I2C ���ߵ�SCLΪ�ߵ�ƽ ʱ SDA�½������� ʶ��Ϊ��ʼ�ź�
************************************************************************************************/
void I2C_GenerateSTART(I2C_Type *I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->C1 |= I2C_C1_TX_MASK;
	I2Cx->C1 |= I2C_C1_MST_MASK;
}
/***********************************************************************************************
 ���ܣ�I2C �������¿�ʼ�ź�
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ�0
 ��⣺ I2C ���ߵ�SCLΪ�ߵ�ƽ ʱ SDA�½������� ʶ��Ϊ��ʼ�ź�
************************************************************************************************/
void I2C_GenerateRESTART(I2C_Type *I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->C1 |= I2C_C1_RSTA_MASK;
}
/***********************************************************************************************
 ���ܣ�I2C ����ֹͣ�ź�
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ�0
 ��⣺ I2C ���ߵ�SCLΪ�ߵ�ƽ ʱ SDA���������� ʶ��Ϊ�����ź�
************************************************************************************************/
void I2C_GenerateSTOP(I2C_Type *I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->C1 &= ~I2C_C1_MST_MASK;
	I2Cx->C1 &= ~I2C_C1_TX_MASK;
}
/***********************************************************************************************
 ���ܣ�I2C ����8bit����
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
			 data8: 8bit����
 ���أ�0
 ��⣺0
************************************************************************************************/
void I2C_SendData(I2C_Type *I2Cx,uint8_t data8)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->D = data8;
}
/***********************************************************************************************
 ���ܣ�I2C ��ȡ8bit����
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ���ȡ����8bit ����
 ��⣺0
************************************************************************************************/
uint8_t I2C_ReadData(I2C_Type *I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	return (I2Cx->D);
}
/***********************************************************************************************
 ���ܣ�I2C ����7λ��ַ��
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
			 Address: 7bit��ַ��
       I2C_Direction��
       @arg I2C_MASTER_WRITE: ����д
       @arg I2C_MASTER_READ:  ������
 ���أ�0
 ��⣺��װ��SendData
************************************************************************************************/
void I2C_Send7bitAddress(I2C_Type* I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_MASTER_DIRECTION(I2C_Direction));
	
	(I2C_Direction == I2C_MASTER_WRITE)?(Address &= 0xFE):(Address |= 0x01);
	I2Cx->D = Address;
}
/***********************************************************************************************
 ���ܣ�I2C �ȴ�Ӧ���ź����
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��

 ���أ�TRUE   :�յ�Ӧ����� 
       FALSE  :������� ��δ�յ�Ӧ���ź�
 ��⣺����ÿ����һ���ֽڶ���Ҫ����I2C_WaitAckһ��
************************************************************************************************/
uint8_t I2C_WaitAck(I2C_Type *I2Cx)
{
	uint8_t ret = 0;
	uint16_t err_time = 0;
	//param check
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	while((I2Cx->S & I2C_S_IICIF_MASK) == 0)
	{
		err_time++;
		if(err_time > 10000) return FALSE;
		if(I2Cx->S & I2C_S_RXAK_MASK)
		{
			ret = 1;
		}
	}
	I2Cx->S |= I2C_S_IICIF_MASK;
	if(ret == 1) return TRUE;
	return FALSE;
}
/***********************************************************************************************
 ���ܣ�I2C ����������дģʽ
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
			 I2C_Direction : ������д����
			 @arg  I2C_MASTER_WRITE : ����д
       @arg  I2C_MASTER_READ  : ������
 ���أ�0
 ��⣺0 
************************************************************************************************/
void I2C_SetMasterMode(I2C_Type* I2Cx,uint8_t I2C_Direction)
{
	//�������
	assert_param(IS_I2C_MASTER_DIRECTION(I2C_Direction));
	
	(I2C_Direction == I2C_MASTER_WRITE)?(I2Cx->C1 |= I2C_C1_TX_MASK):(I2Cx->C1 &= ~I2C_C1_TX_MASK);
}
/***********************************************************************************************
 ���ܣ�I2C ����Ϊ��ȡһ���ֽں󷵻�NACK
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ�0
 ��⣺0 
************************************************************************************************/
void I2C_GenerateAck(I2C_Type *I2Cx)
{
	//parameter check
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->C1 &= ~I2C_C1_TXAK_MASK;
}

void I2C_GenerateNAck(I2C_Type *I2Cx)
{
	//parameter check
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
  I2Cx->C1 |= I2C_C1_TXAK_MASK;
}

/***********************************************************************************************
 ���ܣ�I2C ����Ϊ��ȡһ���ֽں󷵻�ACK
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0: I2C0 ģ��
       @arg I2C1: I2C1 ģ��
 ���أ�0
 ��⣺0 
************************************************************************************************/
void I2C_EnableAck(I2C_Type *I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	I2Cx->C1 &= ~I2C_C1_TXAK_MASK;
}

/***********************************************************************************************
 ���ܣ�I2C �ж�����
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0 : I2C0ģ��
       @arg I2C1 : I2C1ģ��
			 I2C_IT : �ж�Դ
       @arg I2C_IT_TCF : I2C�жϴ������
       NewState : ʹ�ܻ��߽�ֹ
       @arg ENABLE : ʹ��
       @arg DISABLE: ��ֹ 
 ���أ�0
 ��⣺0
************************************************************************************************/
void I2C_ITConfig(I2C_Type* I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_IT(I2C_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	switch(I2C_IT)
	{
		case I2C_IT_TCF:
			(ENABLE == NewState)?(I2Cx->C1 |= I2C_C1_IICIE_MASK):(I2Cx->C1 &= ~I2C_C1_IICIE_MASK);
			break;
		case I2C_IT_IAAS:
			(ENABLE == NewState)?(I2Cx->C1 |= I2C_C1_IICIE_MASK):(I2Cx->C1 &= ~I2C_C1_IICIE_MASK);
		  (ENABLE == NewState)?(I2Cx->C1 |= I2C_C1_WUEN_MASK):(I2Cx->C1 &= ~I2C_C1_WUEN_MASK);
			break;
		case I2C_IT_SLTF:
			(ENABLE == NewState)?(I2Cx->C1 |= I2C_C1_IICIE_MASK):(I2Cx->C1 &= ~I2C_C1_IICIE_MASK);
			break;
		case I2C_IT_SHTF2:
			(ENABLE == NewState)?(I2Cx->C1 |= I2C_C1_IICIE_MASK):(I2Cx->C1 &= ~I2C_C1_IICIE_MASK);
		  (ENABLE == NewState)?(I2Cx->SMB |= I2C_SMB_SHTF2IE_MASK):(I2Cx->SMB &= ~I2C_SMB_SHTF2IE_MASK);
			break;
		default:break;
	}
}
/***********************************************************************************************
 ���ܣ�I2C ��ȡ�ж�״̬
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0 : I2C0ģ��
       @arg I2C1 : I2C1ģ��
			 I2C_IT : �ж�Դ
       @arg I2C_IT_TCF : I2C�жϴ������
 ���أ�0
 ��⣺0
************************************************************************************************/
ITStatus I2C_GetITStatus(I2C_Type* I2Cx, uint16_t I2C_IT)
{
	ITStatus retval = RESET;
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_IT(I2C_IT));
	switch(I2C_IT)
	{
		case I2C_IT_TCF:
			(I2Cx->S & I2C_S_TCF_MASK)?(retval = SET):(retval = RESET);
			break;
		case I2C_IT_IAAS:
			(I2Cx->S & I2C_S_IAAS_MASK)?(retval = SET):(retval = RESET);
			break;
		case I2C_IT_SLTF:
			(I2Cx->SMB & I2C_SMB_SLTF_MASK)?(retval = SET):(retval = RESET);
			break;
		case I2C_IT_ARBL:
			(I2Cx->S & I2C_S_ARBL_MASK)?(retval = SET):(retval = RESET);
			break;  
		case I2C_IT_SHTF2:
			(I2Cx->SMB & I2C_SMB_SHTF2_MASK)?(retval = SET):(retval = RESET);
			break;
		default:break;
	}
	return retval;
}

/***********************************************************************************************
 ���ܣ�I2C DMAʹ��
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0 : I2C0ģ��
       @arg I2C1 : I2C1ģ��
			 I2C_DMAReq : �ж�Դ
       @arg I2C_DMAReq_TCF : I2C�������
       NewState : ʹ�ܻ��߽�ֹ
       @arg ENABLE : ʹ��
       @arg DISABLE: ��ֹ 
 ���أ�0
 ��⣺0
************************************************************************************************/
void I2C_DMACmd(I2C_Type* I2Cx, uint16_t I2C_DMAReq, FunctionalState NewState)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_DMAREQ(I2C_DMAReq));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	switch(I2C_DMAReq)
	{
		case I2C_DMAReq_TCF:
			(NewState == ENABLE)?(I2Cx->C1 |= I2C_C1_DMAEN_MASK):(I2Cx->C1 &= ~I2C_C1_DMAEN_MASK);
			break;
		default:break;
	}
}

/***********************************************************************************************
 ���ܣ�I2C ����жϱ�־
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0 : I2C0ģ��
       @arg I2C1 : I2C1ģ��
			 I2C_IT : �ж�Դ
       @arg I2C_IT_TCF : I2C�жϴ������
 ���أ�0
 ��⣺0
************************************************************************************************/
void I2C_ClearITPendingBit(I2C_Type* I2Cx, uint16_t I2C_IT)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_IT(I2C_IT));
	
	//���жϱ�־λ
	I2Cx->C1 |= I2C_C1_IICEN_MASK;
	switch(I2C_IT)
	{
		case I2C_IT_TCF:
			break;
		case I2C_IT_IAAS:
			break;
		case I2C_IT_SLTF:
			I2Cx->SMB |= I2C_SMB_SLTF_MASK;
			break; 
		case I2C_IT_ARBL:
	  	I2Cx->S |= I2C_S_ARBL_MASK;
			break;
		case I2C_IT_SHTF2:
			I2Cx->SMB |= I2C_SMB_SHTF2_MASK;
			break;
	}
}
/***********************************************************************************************
 ���ܣ��ж�I2C �����Ƿ���� �ߵ�ƽ
 �βΣ�I2Cx: I2Cģ���
       @arg I2C0 : I2C0ģ��
       @arg I2C1 : I2C1ģ��
 ���أ�TRUE: ���� FALSE :æ
 ��⣺0
************************************************************************************************/
uint8_t I2C_IsLineBusy(I2C_Type* I2Cx)
{
	//�������
	assert_param(IS_I2C_ALL_PERIPH(I2Cx));
	
	if(I2Cx->S & I2C_S_BUSY_MASK)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
static const PeripheralMapTypeDef I2C_Check_Maps[] = 
{ 
    {0, 4, 6, 0, 2},  //I2C0_SCL_PE01_SDA_PE00
    {0, 4, 4,18, 2},  //I2C0_SCL_PE19_SDA_PE18
    {0, 4, 5,24, 2},  //I2C0_SCL_PE24_SDA_PE25
    {1, 0, 2, 3, 2},  //I2C1_SCL_PA03_SDA_PA04
    {0, 1, 2, 0, 2},  //I2C0_SCL_PB00_SDA_PB01
    {0, 1, 2, 2, 2},  //I2C0_SCL_PB02_SDA_PB03
    {1, 2, 2, 1, 2},  //I2C1_SCL_PC01_SDA_PC02
    {0, 2, 2, 8, 2},  //I2C0_SCL_PC08_SDA_PC09
    {1, 2, 2,10, 2},  //I2C1_SCL_PC10_SDA_PC11

};
void I2C_CalConstValue(void)
{
	uint8_t i =0;
	uint32_t value = 0;
	for(i=0;i<sizeof(I2C_Check_Maps)/sizeof(PeripheralMapTypeDef);i++)
	{
		value =   I2C_Check_Maps[i].m_ModuleIndex<<0;
		value |=  I2C_Check_Maps[i].m_PortIndex <<3;
		value |=  I2C_Check_Maps[i].m_MuxIndex<<6;
		value |=  I2C_Check_Maps[i].m_PinBaseIndex<<9;
		value |=  I2C_Check_Maps[i].m_PinCntIndex<<14;
		UART_printf("(0x%xU)\r\n",value);
	}
}

*/

