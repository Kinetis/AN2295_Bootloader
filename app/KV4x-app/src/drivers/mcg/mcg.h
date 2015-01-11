/*
 * All software, source code, included documentation, and any implied know-how
 * are property of Freescale Semiconductor and therefore considered
 * CONFIDENTIAL INFORMATION.
 * This confidential information is disclosed FOR DEMONSTRATION PURPOSES ONLY.
 *
 * All Confidential Information remains the property of Freescale Semiconductor
 * and will not be copied or reproduced without the express written permission
 * of the Discloser, except for copies that are absolutely necessary in order
 * to fulfill the Purpose.
 *
 * Services performed by FREESCALE in this matter are performed AS IS and
 * without any warranty.
 * CUSTOMER retains the final decision relative to the total design and
 * functionality of the end product.
 * FREESCALE neither guarantees nor will be held liable by CUSTOMER for the
 * success of this project.
 *
 * FREESCALE disclaims all warranties, express, implied or statutory
 * including, but not limited to, implied warranty of merchantability or
 * fitness for a particular purpose on any hardware, software ore advise
 * supplied to the project by FREESCALE, and or any product resulting from
 * FREESCALE services.
 * In no event shall FREESCALE be liable for incidental or consequential
 * damages arising out of this agreement. CUSTOMER agrees to hold FREESCALE
 * harmless against any and all claims demands or actions by anyone on account
 * of any damage,or injury, whether commercial, contractual, or tortuous,
 * rising directly or indirectly as a result of the advise or assistance
 * supplied CUSTOMER in connectionwith product, services or goods supplied
 * under this Agreement.
 */

#ifndef __MCG_H__
#define __MCG_H__

/* Constants for use in pll_init */
#define NO_OSCINIT	0
#define OSCINIT		1

#define OSC_0		0
#define OSC_1		1

#define LOW_POWER	0
#define HIGH_GAIN	1

#define CANNED_OSC	0
#define CRYSTAL		1

#define PLL_0		0
#define PLL_1		1

#define PLL_ONLY	0
#define MCGOUT		1

/* MCG Mode defines */
/*
#define FEI			1
#define FEE			2
#define FBI			3
#define FBE			4
#define BLPI		5
#define BLPE		6
#define PBE			7
#define PEE			8
*/

#define BLPI		1
#define FBI			2
#define FEI			3
#define FEE			4
#define FBE			5
#define BLPE		6
#define PBE			7
#define PEE			8

/* IRC defines */
#define SLOW_IRC	0
#define FAST_IRC	1

unsigned char fll_rtc_init(unsigned char, unsigned char);

/* prototypes */
void rtc_as_refclk(void);
int fee_fei(int slow_irc_freq);
int fei_fbe(int crystal_val, unsigned char hgo_val, unsigned char erefs_val);
int fbe_fei(int slow_irc_freq);
int fei_fbi(int irc_freq, unsigned char irc_select);
int fbi_fei(int slow_irc_freq);
int fbe_pbe(int crystal_val, signed char prdiv_val, signed char vdiv_val);
int pbe_pee(int crystal_val);
int pee_pbe(int crystal_val);
int pbe_fbe(int crystal_val);
int fbe_fbi(int irc_freq, unsigned char irc_select);
int fbi_fbe(int crystal_val, unsigned char hgo_val, unsigned char erefs_val);
int fbi_fee(int crystal_val, unsigned char hgo_val, unsigned char erefs_val);
int fbe_fee(int crystal_val);
int fee_fbe(int crystal_val);
int pbe_blpe(int crystal_val);
int blpe_pbe(int crystal_val, signed char prdiv_val, signed char vdiv_val);
int blpe_fbe(int crystal_val);
int fbi_blpi(int irc_freq, unsigned char irc_select);
int blpi_fbi(int irc_freq, unsigned char irc_select);
int fei_fee(int crystal_val, unsigned char hgo_val, unsigned char erefs_val);
int fee_fbi(int irc_freq, unsigned char irc_select);
int fbe_blpe(int crystal_val);
int fei_fee_rtc(int rtc_freq);
int fee_fei_rtc(int slow_irc_freq);

int pll_init(int crystal_val, unsigned char hgo_val, unsigned char erefs_val,
			 signed char prdiv_val, signed char vdiv_val,
			 unsigned char mcgout_select);

int fll_freq(int fll_ref);
unsigned char what_mcg_mode(void);
unsigned char atc(unsigned char irc_select, int irc_freq, int mcg_out_freq);
void clk_monitor_0(unsigned char en_dis);

#if (defined(IAR))
__ramfunc void set_sys_dividers(unsigned long int outdiv1,
								unsigned long int outdiv2,
								unsigned long int outdiv3,
								unsigned long int outdiv4);
#elif (defined(CW))
__relocate_code__
	void set_sys_dividers(unsigned long int outdiv1, unsigned long int outdiv2,
						  unsigned long int outdiv3, unsigned long int outdiv4);
#endif

#endif		/* __MCG_H__ */