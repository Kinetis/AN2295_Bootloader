#include "pmc.h"



__ramfunc void PMC_ITConfig(FunctionalState NewState)
{

	(ENABLE == NewState)?(PMC->LVDSC1 |= PMC_LVDSC1_LVDIE_MASK):(PMC->LVDSC1 &= ~PMC_LVDSC1_LVDIE_MASK);
}





















