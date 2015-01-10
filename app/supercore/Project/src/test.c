#include "gpio.h"
#include "delay.h"
#include "adc.h"
#include "MMA845x.h"

void GPIO_Test(void)
{
	uint32_t i = 0;
	GPIO_InitTypeDef GPIO_InitStruct1;
	GPIO_InitStruct1.GPIO_Pin = 6;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = PTA;
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = 5;
	GPIO_Init(&GPIO_InitStruct1);
	for(i=0;i<10;i++)
	{
		GPIO_ToggleBit(PTA,6);
		GPIO_ToggleBit(PTA,5);
		DelayMs(100);
	}
}


void ADC_Test(void)
{
	uint8_t i = 0;
	uint16_t res = 0;
	ADC_InitTypeDef ADC_InitStruct1;
	UART_printf("Begin ADC test\r\n");
	ADC_InitStruct1.ADCxMap = ADC0_SE3A_PE22;
	ADC_InitStruct1.ADC_Precision = ADC_PRECISION_12BIT;
	ADC_InitStruct1.ADC_TriggerSelect = ADC_TRIGGER_SW;
	ADC_Init(&ADC_InitStruct1);
	while(i<10)
	{
		res = ADC_GetConversionValue(ADC0_SE3A_PE22);
		UART_printf("ADRest:%d\r\n",res);
		DelayMs(200);
		i++;
	}
	UART_printf("ADC test complete\r\n");
}

void MMA845x_Test()
{
	uint16_t x,y,z;

	//初始化MMA845x加速度传感器
	//SCL:PC10 SDA:PC11  在MMA845x.h中定义	
	MMA845x_Init();

	x = MMA845x_GetData(OUT_X_MSB_REG);
	y = MMA845x_GetData(OUT_Y_MSB_REG);
	z = MMA845x_GetData(OUT_Z_MSB_REG);
	UART_printf("x:%d y:%d z:%d\r\n",x,y,z);
	DelayMs(200);


}

void LED_Test()
{

	//LED Init
	LED_Init();

	LED_Set(0,0);
	DelayMs(2000);
	LED_Set(0,1);
	DelayMs(2000);
	LED_Set(1,0);
	DelayMs(2000);
	LED_Set(1,1);
	DelayMs(2000);
	LED_Set(2,0);
	DelayMs(2000);
	LED_Set(2,1);
	DelayMs(2000);
}

