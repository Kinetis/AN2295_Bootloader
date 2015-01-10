/*
 * File:        sysinit.h
 * Purpose:     Kinetis Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 */

/********************************************************************/

// function prototypes
void sysinit (void);
void enable_abort_button(void);
void clk_out_init(void);
void end_test(void);

extern int mcg_clk_hz;
extern int mcg_clk_khz;
extern int core_clk_khz;
extern int periph_clk_khz;
extern int pll_clk_khz;
extern int uart0_clk_khz;
/********************************************************************/
