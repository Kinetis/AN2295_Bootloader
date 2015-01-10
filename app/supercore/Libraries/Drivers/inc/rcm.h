#ifndef __RCM_H__
#define __RCM_H__

#ifdef __cplusplus
 extern "C" {
#endif


#include "sys.h"


#define RSTFLTSEL_FILTER_1  ((uint8_t)0x0000)
#define RSTFLTSEL_FILTER_2  ((uint8_t)0x0001)
#define RSTFLTSEL_FILTER_3  ((uint8_t)0x0002)
#define RSTFLTSEL_FILTER_4  ((uint8_t)0x0003)
#define RSTFLTSEL_FILTER_5  ((uint8_t)0x0004)
#define RSTFLTSEL_FILTER_6  ((uint8_t)0x0005)
#define RSTFLTSEL_FILTER_7  ((uint8_t)0x0006)
#define RSTFLTSEL_FILTER_8  ((uint8_t)0x0007)
#define RSTFLTSEL_FILTER_9  ((uint8_t)0x0008)
#define RSTFLTSEL_FILTER_10  ((uint8_t)0x0009)
#define RSTFLTSEL_FILTER_11  ((uint8_t)0x000a)
#define RSTFLTSEL_FILTER_12  ((uint8_t)0x000b)
#define RSTFLTSEL_FILTER_13  ((uint8_t)0x000c)
#define RSTFLTSEL_FILTER_14  ((uint8_t)0x000d)
#define RSTFLTSEL_FILTER_15  ((uint8_t)0x000e)
#define RSTFLTSEL_FILTER_16  ((uint8_t)0x000f)
#define RSTFLTSEL_FILTER_17  ((uint8_t)0x0010)
#define RSTFLTSEL_FILTER_18  ((uint8_t)0x0011)
#define RSTFLTSEL_FILTER_19  ((uint8_t)0x0012)
#define RSTFLTSEL_FILTER_20  ((uint8_t)0x0013)
#define RSTFLTSEL_FILTER_21  ((uint8_t)0x0014)
#define RSTFLTSEL_FILTER_22  ((uint8_t)0x0015)
#define RSTFLTSEL_FILTER_23  ((uint8_t)0x0016)
#define RSTFLTSEL_FILTER_24  ((uint8_t)0x0017)
#define RSTFLTSEL_FILTER_25  ((uint8_t)0x0018)
#define RSTFLTSEL_FILTER_26  ((uint8_t)0x0019)
#define RSTFLTSEL_FILTER_27  ((uint8_t)0x001a)
#define RSTFLTSEL_FILTER_28  ((uint8_t)0x001b)
#define RSTFLTSEL_FILTER_29  ((uint8_t)0x001c)
#define RSTFLTSEL_FILTER_30  ((uint8_t)0x001d)
#define RSTFLTSEL_FILTER_31  ((uint8_t)0x001e)
#define RSTFLTSEL_FILTER_32  ((uint8_t)0x001f)


#define RSTINSTOP_FILTER_LPO_ON 			 0x40u
#define RSTINSTOP_FILTER_OFF 			 	 0x00u

#define RSTINRUN_FILTER_OFF				 	 0x00u
#define RSTINRUN_FILTER_BUSCLOCK_ON			 0x01u
#define RSTINRUN_FILTER_LPO_ON			 	 0x02u



//   RCM Init struct 
typedef struct 
{
	//
    uint8_t  Rstfltss;           //
    uint8_t  Rstfltsrw;   		 //
    uint8_t  Rstfltsel;   		 //  

}RCM_InitTypeDef;

/*    API functions   */
void RCM_Init(RCM_InitTypeDef *RCM_InitStruct);
void RCM_SetResetFilter(uint16_t Data);
uint16_t RCM_GetResetStatus(void);








#ifdef __cplusplus
}
#endif




#endif

