#include "isr.h"

#include "adc.h"
#include "pit.h"

void PIT_IRQHandler (void)
{
	ITStatus status;
	status = PIT_GetITStatus(PIT0, PIT_IT_TIF);
	if(status == SET)
	{
		UART_printf("PIT0_Enter\r\n");
		PIT_ClearITPendingBit(PIT0, PIT_IT_TIF);
	}
	status = PIT_GetITStatus(PIT1, PIT_IT_TIF);
	if(status == SET)
	{
		UART_printf("PIT1_Enter\r\n");
		PIT_ClearITPendingBit(PIT1, PIT_IT_TIF);
	}
}

void ADC0_IRQHandler(void)
{
	ADC_ClearITPendingBit(ADC0,A,ADC_IT_AI);
	UART_printf("!!!\r\n");
	
	
	
}



void UART1_IRQHandler(void)
{
	uint8_t ch;
	if(UART_ReceiveData(UART1,&ch) == TRUE)
	{
		UART_SendData(UART1,ch);
		
	}
		
}

void UART0_IRQHandler(void)
{
	uint8_t ch;
	if(UART_ReceiveData(UART0,&ch) == TRUE)
	{
		UART_SendData(UART0,ch+1);
		
	}

}




/*END OF FILE*/
