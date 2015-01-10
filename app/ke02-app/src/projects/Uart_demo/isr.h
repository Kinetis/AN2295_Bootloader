/******************************************************************************
* File:    isr.h
* Purpose: Define interrupt service routines referenced by the vector table.
* Note: Only "vectors.c" should include this header file.
******************************************************************************/

#ifndef __ISR_H
#define __ISR_H 1


/* Example */

#undef  VECTOR_028
#define VECTOR_028 SCI0_Isr

#undef  VECTOR_029
#define VECTOR_029 SCI1_Isr

extern void SCI0_Isr(void);
extern void SCI1_Isr(void);
extern void RTC_Isr(void);

#endif  //__ISR_H

/* End of "isr.h" */
