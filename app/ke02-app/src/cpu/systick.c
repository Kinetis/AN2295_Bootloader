#include "common.h"
#include "systick.h"

uint32_t cnt_start_value;
uint32_t cnt_end_value;
uint32_t overhead;

void systick_init(void)
{
	SYST_CVR = 0x0;	//clear current timer value
    SYST_RVR = 0x00FFFFFF;
    SYST_CSR = SysTick_CSR_CLKSOURCE_MASK | SysTick_CSR_ENABLE_MASK;   
}

void systick_disable(void)
{
    SYST_CSR &= ~SysTick_CSR_ENABLE_MASK;
}

void cal_systick_read_overhead(void)
{
  	uint32_t cnt_start_value;
    uint32_t cnt_end_value;
	
	cnt_start_value = SYST_CVR;
  
    cnt_end_value = SYST_CVR;
	
	overhead = cnt_start_value - cnt_end_value;
	
#ifdef DEBUG_PRINT
	printf("systick start value: 0x%x\n\r", cnt_start_value);
	printf("systick end value: 0x%x\n\r", cnt_end_value);
	printf("systick current value read overhead: 0x%x\n\r", overhead);
#endif

}
