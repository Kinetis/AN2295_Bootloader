
#ifndef __WDOG_H__
#define __WDOG_H__

#include "sys.h"


#define COPT_WDOG_TIMEOUT_DISABLE		(0x00U)
#define COPT_WDOG_TIMEOUT_2N5_LPO		(0x04U)
#define COPT_WDOG_TIMEOUT_2N8_LPO		(0x08U)
#define COPT_WDOG_TIMEOUT_2N10_LPO		(0x0CU)
#define COPT_WDOG_TIMEOUT_2N13_BUS		(0x06U)
#define COPT_WDOG_TIMEOUT_2N16_BUS		(0x0AU)
#define COPT_WDOG_TIMEOUT_2N18_BUS		(0x0EU)






#define IS_WDOG_ALL_PERIPH(PERIPH) (((PERIPH) == COPT_WDOG_TIMEOUT_DISABLE) || \
									((PERIPH) == COPT_WDOG_TIMEOUT_2N5_LPO)) || \
									((PERIPH) == COPT_WDOG_TIMEOUT_2N8_LPO)) || \
									((PERIPH) == COPT_WDOG_TIMEOUT_2N10_LPO)) || \
									((PERIPH) == COPT_WDOG_TIMEOUT_2N13_BUS)) || \
									((PERIPH) == COPT_WDOG_TIMEOUT_2N16_BUS)) || \
                                    ((PERIPH) == COPT_WDOG_TIMEOUT_2N18_BUS))


void WDOG_Init();
void WDOG_Refresh();





#endif


