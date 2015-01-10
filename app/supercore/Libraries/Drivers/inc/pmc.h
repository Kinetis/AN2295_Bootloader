#ifndef __PMC_H__
#define __PMC_H__


#ifdef __cplusplus
 extern "C" {
#endif


#include "sys.h"


#define LOWTRIP          0
#define HIGHTRIP		 1

#define LVD_ResetEnable(x)   ((ENABLE == NewState)? \
							 (PMC->LVDSC1 |= PMC_LVDSC1_LVDRE_MASK): \
							 (PMC->LVDSC1 &= ~PMC_LVDSC1_LVDRE_MASK))

/*    API functions   */
__ramfunc void LVD_ITConfig(FunctionalState NewState);






#ifdef __cplusplus
}
#endif








#endif

