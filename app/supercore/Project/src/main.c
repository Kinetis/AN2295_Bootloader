
#include "sys.h"
#include "gpio.h"
#include "uart.h"
#include "delay.h"
#include "led.h"
#include "dma.h"
#include "spi.h"
#include "pit.h"
#include "adc.h"
#include "mma845x.h"

void UART0_Install();


int main(void)
{
    UART_InitTypeDef UART_DebugInitStruct1;
    //Clock Setup
	SystemClockSetup(ClockSource_EX8M,CoreClock_48M);
	//DelayInit
	DelayInit();
        //Init a debug UART prot
	UART_DebugPortInit(UART0_RX_PA01_TX_PA02,115200);    
	//UART0_Install();

	DisplayCPUInfo();

	UART_ITConfig(UART0,UART_IT_RDRF,ENABLE);
	//接通NVIC上对应串口中断线
	NVIC_EnableIRQ(UART0_IRQn);

	while(1)
	{
		LED_Test();
		//ADC_Test();
		//MMA845x_Test();
	}



}


void assert_failed(uint8_t* file, uint32_t line)
{
	//UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

void UART0_Install()
{
	UART_InitTypeDef UART_DebugInitStruct1;
	
	UART_DebugInitStruct1.UART_BaudRate = 115200;
	UART_DebugInitStruct1.UARTxMAP = UART0_RX_PA01_TX_PA02;
	UART_Init(&UART_DebugInitStruct1);

	UART_ITConfig(UART0,UART_IT_RDRF,ENABLE);
	//接通NVIC上对应串口中断线
	NVIC_EnableIRQ(UART0_IRQn);

}


