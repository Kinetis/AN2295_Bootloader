/**
  ******************************************************************************
  * @file    falsh.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.6.23
  * @brief   超核K60固件库 片内flash 驱动文件
  ******************************************************************************
  */
#include "flash.h"
/***********************************************************************************************
 功能：内部函数 检查命令是否完成
 形参：0
 返回：FLASH_OK 成功    FLASH_ERROR 失败 
 详解：
************************************************************************************************/
__ramfunc static uint8_t CommandLaunch(void)
{
    // 清除访问错误标志位和非法访问标志位 
    FTFA->FSTAT |=(FTFA_FSTAT_ACCERR_MASK|FTFA_FSTAT_FPVIOL_MASK|FTFA_FSTAT_RDCOLERR_MASK);
    // 启动命令
    FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
    // 等待命令结束
    while((FTFA->FSTAT &FTFA_FSTAT_CCIF_MASK)==0);
    // 检查错误标志
    if(FTFA->FSTAT & (FTFA_FSTAT_ACCERR_MASK|FTFA_FSTAT_FPVIOL_MASK|FTFA_FSTAT_MGSTAT0_MASK|FTFA_FSTAT_RDCOLERR_MASK))
    return(FLASH_ERROR); //出错
    return (FLASH_OK); //成功
}

/***********************************************************************************************
 功能：初始化片内Flash模块
 形参：0
 返回：0
 详解：0
************************************************************************************************/
void FLASH_Init(void)
{

	//检查Flash访问错误
  if(FTFA->FSTAT & FTFA_FSTAT_ACCERR_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_ACCERR_MASK;       //清除错误标志
  }
  //检查保护错误
  else if (FTFA->FSTAT & FTFA_FSTAT_FPVIOL_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_FPVIOL_MASK;
  }
  //检查读冲突错误
  else if (FTFA->FSTAT & FTFA_FSTAT_RDCOLERR_MASK)
  {
    FTFA->FSTAT |= FTFA_FSTAT_RDCOLERR_MASK;
  }

}

/***********************************************************************************************
 功能：片内Flash读取数据
 形参：FlashStartAdd : 地址
       len           : 读取的长度
       *pbuffer      : 缓存区指针
 返回：0
 详解：
************************************************************************************************/
void FLASH_ReadByte(uint32_t FlashStartAdd,uint32_t len,uint8_t *pbuffer)
{
	uint32_t i = 0;
	for(i=0;i<len;i++)
	{
	  pbuffer[i] = *(uint8_t *)(FlashStartAdd+i);		//读取指定地址的数据
	}
}

/***********************************************************************************************
 功能：FALSH写一个扇区
 形参：sectorNo      : 扇区号(地址/2048)
       len           : 读取的长度
       *pbuffer      : 缓存区指针
 返回：0
 详解：一个扇区2048字节 所以至少写2048字节
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

	// 设置写入命令
	FTFA->FCCOB0 = PGM4;
	// 四字节对齐
	for(i=0;i<count;i+=4)
	{
		// 设置存储地址
		FTFA->FCCOB1 = dest.byte[2];
		FTFA->FCCOB2 = dest.byte[1];
		FTFA->FCCOB3 = dest.byte[0];
		// 拷贝数据	（此数据排列按照从低位到高位存储）
		FTFA->FCCOB4 = buffer[3];
		FTFA->FCCOB5 = buffer[2];
		FTFA->FCCOB6 = buffer[1];
		FTFA->FCCOB7 = buffer[0];
		dest.word+=4; buffer+=4;
		//检测命令是否执行正常 
		if(FLASH_OK != CommandLaunch()) 
		return FLASH_ERROR;
    }
    return FLASH_OK;
}

static uint8_t flash_buffer[2048];	 //数据缓冲区
/***********************************************************************************************
 功能：写入Flash数据
 形参：FlashStartAdd:起始地址
    NumByteToWrite  :需要写入的数据长度
	        u8 *buffer: 参数指针
 返回：0
 详解：用户接口函数
************************************************************************************************/
void FLASH_Write(uint32_t FlashStartAdd,uint32_t NumByteToWrite,uint8_t *buffer)
{
	uint32_t i=0;
	uint32_t sectorNo = FlashStartAdd/(1<<10);        //该地址所在的扇区
	uint32_t offset =   FlashStartAdd%(1<<10);        //该地址所在扇区的偏移
	uint32_t remain =   (1<<10)-offset;               //扇区剩余大小
	if(NumByteToWrite<=remain)remain = NumByteToWrite;//不大于4096个字节
	while(1)
	{
		FLASH_ReadByte(sectorNo*(1<<10),(1<<10),flash_buffer);  //取出该扇区所有数据
		FLASH_EraseSector(sectorNo);             //擦除扇区
		for(i=0;i<remain;i++)
		{
			flash_buffer[offset+i]=buffer[i];	   //修改数据
		}
		FLASH_WriteSector(sectorNo,(1<<10),flash_buffer);	//写数据
		if(NumByteToWrite == remain) break;//写入结束了
		else
		{
			sectorNo++;              //扇区地址增1
			offset=0;                //偏移位置为0 	
		  buffer+=remain;       //指针偏移
			FlashStartAdd+=remain;    //写地址偏移	  
			NumByteToWrite-=remain;				//字节数递减
			if(NumByteToWrite > (1<<10)) remain = (1<<10);	//下一个扇区还是写不完
			else remain=NumByteToWrite;			//下一个扇区可以写完了
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
	// 设置擦除命令
	FTFA->FCCOB0 = ERSSCR; // 擦除扇区命令
	// 设置目标地址
	FTFA->FCCOB1 = dest.byte[2];
	FTFA->FCCOB2 = dest.byte[1];
	FTFA->FCCOB3 = dest.byte[0];
	//检测命令是否执行正常
		
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
 功能：FALSH 擦除一个扇区
 形参：sectorNo      : 扇区号(地址/2048)
 返回：0
 详解：0
************************************************************************************************/
uint8_t FLASH_EraseAllBlock()
{
	
	// 设置擦除命令
	FTFA->FCCOB0 = ERSALL; // 擦除扇区命令
	// 设置目标地址
	FTFA->FCCOB1 = 0;
	FTFA->FCCOB2 = 0;
	FTFA->FCCOB3 = 0;
	//检测命令是否执行正常
		
	if(FLASH_OK == CommandLaunch())
	{
		return FLASH_OK;
	}
	else
	{
		return FLASH_ERROR;
	}
}


