/*
 * File:		smc.h
 * Purpose:     Provides low power mode entry routines
 *
 * Notes:
 */

#ifndef __SMC_H__
#define __SMC_H__

/********************************************************************/

// function prototypes
void sleep(void);
void deepsleep(void);
void enter_wait(void);
void enter_stop(void);
int enter_vlpr(char lpwui_value);
void exit_vlpr(void);
void enter_vlps(void);
void enter_lls(void);
void enter_vlls3(void);
void enter_vlls2(void);
void enter_vlls1(void);
void enter_vlls0(unsigned char PORPO_value);
void enter_vlls0_nopor(void);
void enable_lpwui(void);
void disable_lpwui(void);

/********************************************************************/
#endif /* __SMC_H__ */
