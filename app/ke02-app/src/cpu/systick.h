#ifndef __SYSTICK_H
#define __SYSTICK_H


#define SYS_COUNT_TIME		10 //ms
#define SYS_COUNT 				MCU_CLCOK*SYS_COUNT_TIME/16
/* Global variables */
extern uint32_t cnt_start_value;
extern uint32_t cnt_end_value;
extern uint32_t overhead;

/* Function declaration */
void systick_init(void);
void systick_disable(void);
void cal_systick_read_overhead(void);

#endif
