/**
  ******************************************************************************
  * @file    falsh.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.6.23
  * @brief   ����K60�̼��� Ƭ��flash �����ļ�
  ******************************************************************************
  */
#include "flash.h"
/***********************************************************************************************
 ���ܣ��ڲ����� ��������Ƿ����
 �βΣ�0
 ���أ�FLASH_OK �ɹ�    FLASH_ERROR ʧ�� 
 ��⣺
************************************************************************************************/
__ramfunc static uint8_t CommandLaunch(void)
{
    // ������ʴ����־λ�ͷǷ����ʱ�־λ 
    FTFA->FSTAT |=(FTFA_FSTAT_ACCERR_MASK|FTFA_FSTAT_FPVIOL_MASK|FTFA_FSTAT_RDCOLERR_MASK);
    // ��������
    FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
    // �ȴ��������
    while((FTFA->FSTAT &FTFA_FSTAT_CCIF_MASK)==0);
    // �������־
    if(FTFA->FSTAT & (FTFA_FSTAT_ACCERR_MASK|FTFA_FSTAT_FPVIOL_MASK|FTFA_FSTAT_MGSTAT0_MASK|FTFA_FSTAT_RDCOLERR_MASK))
    return(FLASH_ERROR); //����
    return (FLASH_OK); //�ɹ�
}

/***********************************************************************************************
 ���ܣ���ʼ��Ƭ��Flashģ��
 �βΣ�0
 ���أ�0
 ��⣺0
************************************************************************************************/
void FLASH_Init(void)
{

	//���Flash���ʴ���
  if(FTFA->FSTAT & FTFA_FSTAT_ACCERR_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_ACCERR_MASK;       //��������־
  }
  //��鱣������
  else if (FTFA->FSTAT & FTFA_FSTAT_FPVIOL_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_FPVIOL_MASK;
  }
  //������ͻ����
  else if (FTFA->FSTAT & FTFA_FSTAT_RDCOLERR_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_RDCOLERR_MASK;
  }

}

/***********************************************************************************************
 ���ܣ�Ƭ��Flash��ȡ����
 �βΣ�FlashStartAdd : ��ַ
       len           : ��ȡ�ĳ���
       *pbuffer      : ������ָ��
 ���أ�0
 ��⣺
************************************************************************************************/
void FLASH_ReadByte(uint32_t FlashStartAdd,uint32_t len,uint8_t *pbuffer)
{
	uint32_t i = 0;
	for(i=0;i<len;i++)
	{
	  pbuffer[i] = *(uint8_t *)(FlashStartAdd+i);		//��ȡָ����ַ������
	}
}

/***********************************************************************************************
 ���ܣ�FALSHдһ������
 �βΣ�sectorNo      : ������(��ַ/2048)
       len           : ��ȡ�ĳ���
       *pbuffer      : ������ָ��
 ���أ�0
 ��⣺һ������2048�ֽ� ��������д2048�ֽ�
************************************************************************************************/
uint8_t FLASH_WriteSector(uint32_t sectorNo,uint16_t count,uint8_t const *buffer)
{
	uint16_t i;
	union
	{
		uint32_t  word;
		uint8_t   byte[4];
	} dest;
	dest.word = (uint32_t)(sectorNo*(1<<10));

	// ����д������
	FTFA->FCCOB0 = PGM4;
	// ���ֽڶ���
	for(i=0;i<count;i+=4)
	{
		// ���ô洢��ַ
		FTFA->FCCOB1 = dest.byte[2];
		FTFA->FCCOB2 = dest.byte[1];
		FTFA->FCCOB3 = dest.byte[0];
		// ��������	�����������а��մӵ�λ����λ�洢��
		FTFA->FCCOB4 = buffer[3];
		FTFA->FCCOB5 = buffer[2];
		FTFA->FCCOB6 = buffer[1];
		FTFA->FCCOB7 = buffer[0];
		dest.word+=4; buffer+=4;
		//��������Ƿ�ִ������ 
		if(FLASH_OK != CommandLaunch()) 
		return FLASH_ERROR;
    }
    return FLASH_OK;
}

static uint8_t flash_buffer[2048];	 //���ݻ�����
/***********************************************************************************************
 ���ܣ�д��Flash����
 �βΣ�FlashStartAdd:��ʼ��ַ
    NumByteToWrite  :��Ҫд������ݳ���
	        u8 *buffer: ����ָ��
 ���أ�0
 ��⣺�û��ӿں���
************************************************************************************************/
void FLASH_Write(uint32_t FlashStartAdd,uint32_t NumByteToWrite,uint8_t *buffer)
{
	uint32_t i=0;
	uint32_t sectorNo = FlashStartAdd/(1<<10);        //�õ�ַ���ڵ�����
	uint32_t offset =   FlashStartAdd%(1<<10);        //�õ�ַ����������ƫ��
	uint32_t remain =   (1<<10)-offset;               //����ʣ���С
	if(NumByteToWrite<=remain)remain = NumByteToWrite;//������4096���ֽ�
	while(1)
	{
		FLASH_ReadByte(sectorNo*(1<<10),(1<<10),flash_buffer);  //ȡ����������������
		FLASH_EraseSector(sectorNo);             //��������
		for(i=0;i<remain;i++)
		{
			flash_buffer[offset+i]=buffer[i];	   //�޸�����
		}
		FLASH_WriteSector(sectorNo,(1<<10),flash_buffer);	//д����
		if(NumByteToWrite == remain) break;//д�������
		else
		{
			sectorNo++;              //������ַ��1
			offset=0;                //ƫ��λ��Ϊ0 	
		  buffer+=remain;       //ָ��ƫ��
			FlashStartAdd+=remain;    //д��ַƫ��	  
			NumByteToWrite-=remain;				//�ֽ����ݼ�
			if(NumByteToWrite > (1<<10)) remain = (1<<10);	//��һ����������д����
			else remain=NumByteToWrite;			//��һ����������д����
		}
	}
}


uint8_t FLASH_EraseSector(uint32_t sectorNo)
{
	union
	{
		uint32_t  word;
		uint8_t   byte[4];
	} dest;
	dest.word = (uint32_t)(sectorNo*(1<<10));
	// ���ò�������
	FTFA->FCCOB0 = ERSSCR; // ������������
	// ����Ŀ���ַ
	FTFA->FCCOB1 = dest.byte[2];
	FTFA->FCCOB2 = dest.byte[1];
	FTFA->FCCOB3 = dest.byte[0];
	//��������Ƿ�ִ������
		
	if(FLASH_OK == CommandLaunch())
	{
		return FLASH_OK;
	}
	else
	{
		return FLASH_ERROR;
	}
}

/***********************************************************************************************
 ���ܣ�FALSH ����һ������
 �βΣ�sectorNo      : ������(��ַ/2048)
 ���أ�0
 ��⣺0
************************************************************************************************/
uint8_t FLASH_EraseAllBlock()
{
	
	// ���ò�������
	FTFA->FCCOB0 = ERSALL; // ������������
	// ����Ŀ���ַ
	FTFA->FCCOB1 = 0;
	FTFA->FCCOB2 = 0;
	FTFA->FCCOB3 = 0;
	//��������Ƿ�ִ������
		
	if(FLASH_OK == CommandLaunch())
	{
		return FLASH_OK;
	}
	else
	{
		return FLASH_ERROR;
	}
}


