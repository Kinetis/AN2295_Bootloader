#include "wdog.h"

void WDOG_Refresh(void)
{
    SIM->SRVCOP = 0x55;
    SIM->SRVCOP = 0xAA;
}

void WDOG_Init(uint32_t wdogcfg)
{	
	assert_param(IS_WDOG_ALL_PERIPH(wdogcfg));

    SIM->COPC &= ~SIM_COPC_COPT_MASK;

	SIM->COPC |= SIM_COPC_COPT(wdogcfg);

    SIM->COPC |= SIM_COPC_COPCLKS_MASK;
}


