#include "rcm.h"



void RCM_Init(RCM_InitTypeDef *RCM_InitStruct)
{
	RCM->RPFC |= ( RCM_InitStruct->Rstfltss | RCM_InitStruct->Rstfltsrw);
	RCM->RPFW = (RCM_InitStruct->Rstfltsel) & 0x1F;
}
void RCM_SetResetFilter(uint16_t Data)
{
	RCM->RPFW = Data & 0x1F;
}
uint16_t RCM_GetResetStatus(void)
{
	return ((RCM->SRS1 << 8) | RCM->SRS0);
}



















