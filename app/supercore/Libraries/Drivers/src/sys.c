/**
  ******************************************************************************
  * @file    sys.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   CH KL series Frimware Lib: SYS component
  ******************************************************************************
  */
#include "sys.h"
CPUInfoType_t CPUInfo; // struct to record important CPU information

extern uint32_t SystemCoreClock;


/**
  * @brief  Get MCU basic info
  * @param  none
  * @retval None
  */
void GetCPUInfo(void)
{
	//CPU Type
	switch((SIM->SDID & SIM_SDID_FAMID_MASK)>>SIM_SDID_FAMID_SHIFT) 
	{  
    	case 0x0: CPUInfo.FamilyType = 0; break; //KL0x Family(low end)
    	case 0x1: CPUInfo.FamilyType = 1; break; //KL1x Family(basic)
		  case 0x2: CPUInfo.FamilyType = 2; break; //KL2x Family(USB)
			case 0x3: CPUInfo.FamilyType = 3; break; //KL3x Family(segment LCD)
			case 0x4: CPUInfo.FamilyType = 4; break; //KL4x Familt(USB and segment LCD)
			 default: CPUInfo.FamilyType = 255;  break;
	}
	//Pin Package
	switch((SIM->SDID & SIM_SDID_PINID_MASK)>>SIM_SDID_PINID_SHIFT) 
	{  
		
		case 0x00: CPUInfo.PinCnt = 16;  break;
		case 0x01: CPUInfo.PinCnt = 24;  break;
		case 0x02: CPUInfo.PinCnt = 32;  break;
		case 0x03: CPUInfo.PinCnt =  0;  break;	
		case 0x04: CPUInfo.PinCnt = 48;  break;	
		case 0x05: CPUInfo.PinCnt = 64;  break;	
		case 0x06: CPUInfo.PinCnt = 80;  break;	
		case 0x07: CPUInfo.PinCnt =  0;  break;	
		case 0x08: CPUInfo.PinCnt =100;  break;	
		case 0x09: CPUInfo.PinCnt =  0;  break;	
		case 0x0A: CPUInfo.PinCnt =  0;  break;	
		case 0x0B: CPUInfo.PinCnt =  0;  break;	
		case 0x0C: CPUInfo.PinCnt =  0;  break;	
		case 0x0D: CPUInfo.PinCnt =  0;  break;	
		case 0x0E: CPUInfo.PinCnt =  0;  break;	
		case 0x0F: CPUInfo.PinCnt =  0;  break;	
	  default:  CPUInfo.PinCnt = 0;   break;	
	}  
   //SiliconRevID
    switch((SIM->SDID & SIM_SDID_REVID_MASK)>>SIM_SDID_REVID_SHIFT) 
    { 
			case 0x0: CPUInfo.SiliconRev = 10;break;
			case 0x1: CPUInfo.SiliconRev = 11;break;
			case 0x2: CPUInfo.SiliconRev = 12;break;
			default:  CPUInfo.SiliconRev = 0; break;
    }	
	//PFlash Size
	switch((SIM->FCFG1 & SIM_FCFG1_PFSIZE_MASK)>>SIM_FCFG1_PFSIZE_SHIFT)
	{
		case 0x01: CPUInfo.PFlashSize = 8*1024;break;
		case 0x02: CPUInfo.PFlashSize = 16*1024;break;
		case 0x03: CPUInfo.PFlashSize = 32*1024;break;
		case 0x04: CPUInfo.PFlashSize = 0*1024;break;
		case 0x05: CPUInfo.PFlashSize = 64*1024;break;
		case 0x06: CPUInfo.PFlashSize = 0*1024;break;
		case 0x07: CPUInfo.PFlashSize = 128*1024;break;
		case 0x08: CPUInfo.PFlashSize = 0*1024;break;
		case 0x09: CPUInfo.PFlashSize = 256*1024;break;
		case 0x0A: CPUInfo.PFlashSize = 0*1024;break;
		case 0x0B: CPUInfo.PFlashSize = 0*1024;break;
		case 0x0C: CPUInfo.PFlashSize = 0*1024;break;
		case 0x0D: CPUInfo.PFlashSize = 0*1024;break;	
		case 0x0E: CPUInfo.PFlashSize = 0*1024;break;	
		case 0x0F: CPUInfo.PFlashSize = 256*1024;break;	
	 	default:  CPUInfo.PFlashSize = 0*1024;  break; 		
	}
	//SRAM Size
	switch((SIM->SDID & SIM_SDID_SRAMSIZE_MASK)>>SIM_SDID_SRAMSIZE_SHIFT)
	{
		case 0x00: CPUInfo.RAMSize = 512;  break;
		case 0x01: CPUInfo.RAMSize = 1*1024;  break;
		case 0x02: CPUInfo.RAMSize = 2*1024;  break;
		case 0x03: CPUInfo.RAMSize = 4*1024;  break;
		case 0x04: CPUInfo.RAMSize = 8*1024;  break;
		case 0x05: CPUInfo.RAMSize = 16*1024;  break;
		case 0x06: CPUInfo.RAMSize = 32*1024;  break;
		case 0x07: CPUInfo.RAMSize = 64*1024;  break;
		default:break;
	}
	//Clock Config
	CPUInfo.CoreClock = SystemCoreClock;
	CPUInfo.BusClock=(SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1));     
	CPUInfo.FlashClock = (SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV4_MASK)>>SIM_CLKDIV1_OUTDIV4_SHIFT)+1));   
	CPUInfo.FlexBusClock = 0;
	CPUInfo.BusClock = (SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV4_MASK)>>SIM_CLKDIV1_OUTDIV4_SHIFT)+1));  
	
}

/**
  * @brief  PinMux config, many peripheral need to call this function to finish pinmux control
  * @param  GPIOIndex:
            @arg 0: stand for PTA
            @arg 1: stand for PTB
            @arg 2: stand for PTC
            @arg 3: stand for PTD
            @arg 4: stand for PTE
            PinIndex��0 - 32
            MuxIndex: 0 - 7
  * @retval None
  */
void PinMuxConfig(uint8_t GPIOIndex, uint8_t PinIndex, uint8_t MuxIndex)
{
	switch(GPIOIndex)
	{
		case 0:
			SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
			PORTA->PCR[PinIndex]&= ~(PORT_PCR_MUX_MASK);    
			PORTA->PCR[PinIndex]|= PORT_PCR_MUX(MuxIndex); 
			break;
		case 1:
			SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;
			PORTB->PCR[PinIndex]&= ~(PORT_PCR_MUX_MASK);    
			PORTB->PCR[PinIndex]|= PORT_PCR_MUX(MuxIndex); 
			break;
		case 2:
			SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
			PORTC->PCR[PinIndex]&= ~(PORT_PCR_MUX_MASK);    
			PORTC->PCR[PinIndex]|= PORT_PCR_MUX(MuxIndex); 
			break;
		case 3:
			SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
			PORTD->PCR[PinIndex]&= ~(PORT_PCR_MUX_MASK);    
			PORTD->PCR[PinIndex]|= PORT_PCR_MUX(MuxIndex); 
			break;
		case 4:
			SIM->SCGC5|=SIM_SCGC5_PORTE_MASK;
			PORTE->PCR[PinIndex]&= ~(PORT_PCR_MUX_MASK);    
			PORTE->PCR[PinIndex]|= PORT_PCR_MUX(MuxIndex); 
			break;
		default:
			break;
	}
}

/***********************************************************************************************
 ���ܣ����� ����ϵͳ��Ƶ
 �βΣ�ClockOption ʱ��Դѡ��
			 @arg  ClockSource_IRC    : �ڲ�ʱ��Դ
			 @arg  ClockSource_EX8M   : �ⲿ8M����
			 @arg  ClockSource_EX50M  : �ⲿ50M����
			 CoreClock   ϣ���ﵽ���ں�Ƶ��
			 @arg  CoreClock_48M : CoreClock = 48M
			 @arg  CoreClock_64M : CoreClock = 64M
			 @arg  CoreClock_72M : CoreClock = 72M
			 @arg  CoreClock_96M : CoreClock = 96M
			 @arg  CoreClock_100M : CoreClock = 100M
 ���أ�0
 ��⣺�������е�Ƶ�ʶ��ܴﵽ ���øú��� �Ƽ�ʹ��DisplayCPUInfo����ʾһ����Ƶ
       SystemClockSetup(ClockSource_EX50M,CoreClock_100M) �ⲿ50M���� PLL��Ƶ��CoreClock = 100M
************************************************************************************************/

/**
  * @brief  config system/core clock, if ClockOption is ClockSource_IRC,we use FLL ,
  * if ClockOption is ClockSource_EX..M, we use PLL
  * @param  ClockOption:
            @arg ClockSource_IRC : use internal clock(32.768K slow interal clock)
            @arg ClockSource_EX8M: use exteral  osc (8M)
            CoreClock��
						@arg CoreClock_24M:  CoreClock = 24M
						@arg CoreClock_48M:  CoreClock = 48M
  * @retval None
  */
void SystemClockSetup(uint8_t ClockOption,uint16_t CoreClock)
{
	if(ClockOption == ClockSource_IRC)
	{
		SIM->CLKDIV1 = (uint32_t)0x00020000UL; 
		MCG->C1 |= (MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK);
		MCG->C2 = 0;
		MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;
		switch(CoreClock)
		{
			case CoreClock_48M:
				MCG->C4 |= (MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS(1));
				SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(1));
				SystemCoreClock = 48000000;
				break;				
			case CoreClock_24M:	
				MCG->C4 |= (MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS(0));
				SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(0));
				SystemCoreClock = 24000000;
				break;		
		}
		OSC0->CR = (uint8_t)0x80U;
		MCG->C5 = (uint8_t)0x00U;
		MCG->C6 = (uint8_t)0x00U;
		while((MCG->S & MCG_S_IREFST_MASK) == 0x00U) {};/* Check that the source of the FLL reference clock is the internal reference clock. */
		while((MCG->S & 0x0CU) != 0x00U) {};    /* Wait until output of the FLL is selected */
	}
	if(ClockOption == ClockSource_EX8M)
	{
		/* SIM->SCGC5: PORTA=1 */
		SIM->SCGC5 |= (uint32_t)0x0200UL;     /* Enable clock gate for ports to enable pin routing */
		/* SIM->CLKDIV1: OUTDIV1=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
		SIM->CLKDIV1 = (uint32_t)0x10010000UL; /* Update system prescalers */
		/* PORTA->PCR18: ISF=0,MUX=0 */
		PORTA->PCR[18] &= (uint32_t)~0x01000700UL;
		/* PORTA->PCR19: ISF=0,MUX=0 */
		PORTA->PCR[19] &= (uint32_t)~0x01000700UL;
		/* Switch to FBE Mode */
		/* OSC0->CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=1,SC4P=0,SC8P=0,SC16P=1 */
		OSC0->CR = (uint8_t)0x89U;
		/* MCG->C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
		MCG->C2 = (uint8_t)0x24U;
		/* MCG->C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
		MCG->C1 = (uint8_t)0x9AU;
		/* MCG->C4: DMX32=0,DRST_DRS=0 */
		MCG->C4 &= (uint8_t)~(uint8_t)0xE0U;
		/* MCG->C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=1 */
		MCG->C5 = (uint8_t)0x03U;  //8M/4 = 2M
		/* MCG->C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
		switch(CoreClock)
		{
			case CoreClock_48M:
				MCG->C6 = MCG_C6_VDIV0(0); //2M*24 = 48M
				SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(1)); //Core=48M/1  Bus=48M/1/2
				SystemCoreClock = 48000000;
				break;				
			case CoreClock_24M:	
				MCG->C6 = MCG_C6_VDIV0(0); //2M*48 = 48M
				SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV4(0)); //Core=48M/2  Bus=48M/2/1
				SystemCoreClock = 24000000;
				break;		
		}
		while((MCG->S & MCG_S_IREFST_MASK) != 0x00U) {}; /* Check that the source of the FLL reference clock is the external reference clock. */
		while((MCG->S & 0x0CU) != 0x08U) {};    /* Wait until external reference clock is selected as MCG output */
		/* Switch to PBE Mode */
		/* MCG->C6: LOLIE0=0,PLLS=1,CME0=0,VDIV0=0 */
		MCG->C6 = (uint8_t)0x40U;
		while((MCG->S & 0x0CU) != 0x08U) {};    /* Wait until external reference clock is selected as MCG output */
		while((MCG->S & MCG_S_LOCK0_MASK) == 0x00U) {}; /* Wait until locked */
		/* Switch to PEE Mode */
		/* MCG->C1: CLKS=0,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
		MCG->C1 = (uint8_t)0x1AU;
		while((MCG->S & 0x0CU) != 0x0CU) {};    /* Wait until output of the PLL is selected */
	}
	GetCPUInfo();//��ȡCPU��Ϣ ���¼����������Ƶ��
}
/***********************************************************************************************
 ���ܣ�����һ���жϵ����ȼ�
 �βΣ�IRQn �жϺ�
			 PriorityGroup ���ȼ����� 
		   @arg NVIC_PriorityGroup_0
			 @arg NVIC_PriorityGroup_1
		   @arg NVIC_PriorityGroup_2
			 @arg NVIC_PriorityGroup_3
		   @arg NVIC_PriorityGroup_4
		 	 PreemptPriority  ��ռ���ȼ�
			 SubPriority      �����ȼ�(��Ӧ���ȼ�)
 ���أ�0
 ��⣺��������жϵ���ռ���ȼ�����Ӧ���ȼ���һ���Ļ� �������ж��ȷ�������ִ��
			 �����ȼ�����ռ���ȼ��ǿ��Դ�ϵ����ȼ�����ռ���ȼ��жϵ�
			 ����ռ���ȼ���ͬ���ж� �����ȼ�����Ӧ���ȼ������Դ�ϵ����ȼ�����Ӧ���ȼ� 
************************************************************************************************/
void NVIC_Init(IRQn_Type IRQn,uint32_t PriorityGroup,uint32_t PreemptPriority,uint32_t SubPriority)
{
	//������
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
  assert_param(IS_NVIC_PREEMPTION_PRIORITY(PreemptPriority));  
  assert_param(IS_NVIC_SUB_PRIORITY(SubPriority));
	
//	NVIC_SetPriorityGrouping(PriorityGroup);
	
	//NVIC_SetPriority(IRQn,NVIC_EncodePriority(PriorityGroup,PreemptPriority,SubPriority));
}
/***********************************************************************************************
 ���ܣ���λ
 �βΣ�0
 ���أ�0
 ��⣺��λ
************************************************************************************************/
void SystemSoftReset(void)
{   
	//SCB->AIRCR =0X05FA0000|(uint32_t)0x04;	 
	NVIC_SystemReset();
} 
/***********************************************************************************************
 ���ܣ�ʹ�����ж�
 �βΣ�0
 ���أ�0
 ��⣺����  CMSIS Cortex-M Core Function Access �� ���� ��.core_cmFunc.h
************************************************************************************************/
void EnableInterrupts(void)
{
	__enable_irq();
}
/***********************************************************************************************
 ���ܣ��ر����ж�
 �βΣ�0
 ���أ�0
 ��⣺����  CMSIS Cortex-M Core Function Access �� ���� ��.core_cmFunc.h
************************************************************************************************/
void DisableInterrupts(void)
{
	__disable_irq();
}
/***********************************************************************************************
 ���ܣ������ж���������ʼλ��
 �βΣ�0
 ���أ�0
 ��⣺
************************************************************************************************/
void SetVectorTable(uint32_t VectorOffset)
{
	//������
  assert_param(IS_VECTOR_OFFSET(VectorOffset));
	SCB->VTOR = VectorOffset;  //�����ж�������ƫ�Ƶ�ַ
}
/***********************************************************************************************
 ���ܣ���ù̼���汾
 �βΣ�0
 ���أ��̼���汾
 ��⣺
************************************************************************************************/
uint16_t GetFWVersion(void)
{
	return(FW_VERSION);
}
