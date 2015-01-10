
/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ics.c
*
* @author a13984
*
* @version 0.0.1
*
* @date Jul-15-2011
*
* @brief providing APIs for configuring internal clock sources (ICS). 
*
*******************************************************************************
*
* provide APIs for configuring internal clock sources (ICS)
******************************************************************************/
#include "common.h"
#include "ics.h"

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void FEI_to_FEE(void);
void FEE_to_FEI(void);
void FBE_to_FBI(void);

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEI_to_FEE
   *
   * @brief change clock from FEI mode to FEE mode and divide clock by 2
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEI_to_FEE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* enable OSC with high gain, high range and select oscillator output as OSCOUT
	 * 
	 */
	OSC_CR = OSC_CR_OSCEN_MASK
        | OSC_CR_OSCSTEN_MASK         /* enable stop */
#if defined(CRYST_HIGH_GAIN)
	|  OSC_CR_HGO_MASK 		/* Rs must be added and be large up to 200K */
#endif
#if  (EXT_CLK_CRYST >=4000)
	| OSC_CR_RANGE_MASK 
#endif	
	| OSC_CR_OSCOS_MASK;		/* for crystal only */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
};        
#endif        
	/* wait for OSC to be initialized
	 * 
	 */
	while(!(OSC_CR & OSC_CR_OSCINIT_MASK));
	
	/* divide down external clock frequency to be within 31.25K to 39.0625K
	 * 
	 */
 
  #if (EXT_CLK_CRYST == 8000)||	(EXT_CLK_CRYST == 10000)
          /* 8MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(3);	/* now the divided frequency is 8000/256 = 31.25K */
  #elif (EXT_CLK_CRYST == 4000)
          /* 4MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(2);	/* now the divided frequency is 4000/128 = 31.25K */	
  #elif (EXT_CLK_CRYST == 16000)	
          /* 16MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 16000/512 = 31.25K */
          
  #elif (EXT_CLK_CRYST == 20000)
          /* 20MHz */
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 20000/512 = 39.0625K */
          
  #elif (EXT_CLK_CRYST == 32)
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK);
  #else
          #error "Error: crystal value not supported!\n";
  #endif

	/* change FLL reference clock to external clock */
	ICS_C1 =  ICS_C1 & ~ICS_C1_IREFS_MASK;
         
	
	/* wait for the reference clock to be changed to external */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
};        
#endif        
	while(ICS_S & ICS_S_IREFST_MASK);
	
	/* wait for FLL to lock */
	while(!(ICS_S & ICS_S_LOCK_MASK));
		
	/* now FLL output clock is 31.25K*512*2 = 32MHz
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is the target frequency
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEI_to_FBI
   *
   * @brief change clock from FEI mode to FBI mode and divide clock by 2
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEI_to_FBI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* change clock source to internal reference clock */
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
	/* wait for the reference clock to be changed  */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif        
	while((ICS_S >> ICS_S_CLKST_SHIFT) !=1);
			
	/* now internal reference clock is the system clock
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is around 32KHz
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEI_to_FBE
   *
   * @brief change clock from FEI mode to FBE mode and divide clock by 2
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEI_to_FBE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* change clock source to external reference clock */
        ICS_C1 =  ICS_C1 & ~(ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
        
	/* wait for the reference clock to be changed  */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif        

	while((ICS_S >> ICS_S_CLKST_SHIFT) !=2);
        while(ICS_S & ICS_S_IREFST_MASK);
			
	/* now external  clock is the system clock
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is external clock
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEI_to_FBE_OSC
   *
   * @brief change clock from FEI mode to FBE mode with external clock/oscillator 
   * and divide clock by 2
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEI_to_FBE_OSC(void)
{
#if	!defined(XOSC_ENABLE)	
	/* XOSC bypass mode, i.e. XOSC is disabled */
	/* PASS */
	OSC_CR = 0 	/* low range */
#if  (EXT_CLK_CRYST >=4000)
		| 0x04    /* high range */
#endif
	;
#else
	/* XOSC is enabled */
	/* PASS */
	OSC_CR = 0x0
#if  (EXT_CLK_CRYST >=4000)
		| 0x04    /* high range */
#endif	
	| OSC_CR_OSCEN_MASK | OSC_CR_OSCSTEN_MASK;	/* high range */	
#endif
	/* change RDIV  reference divider to divide reference clock to be with FLL input spec
	 * 
	 */
  #if (EXT_CLK_CRYST == 8000)||	(EXT_CLK_CRYST == 10000)
          /* 8MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(3);	/* now the divided frequency is 8000/256 = 31.25K */
  #elif (EXT_CLK_CRYST == 4000)
          /* 4MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(2);	/* now the divided frequency is 4000/128 = 31.25K */	
  #elif (EXT_CLK_CRYST == 16000)	
          /* 16MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 16000/512 = 31.25K */
          
  #elif (EXT_CLK_CRYST == 20000)
          /* 20MHz */
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 20000/512 = 39.0625K */
          
  #elif (EXT_CLK_CRYST == 32)
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK);
  #else
          #error "Error: crystal value not supported!\n";
  #endif
	/* assume external oscillator is 8Mhz or 4MHz
	 * 
	 */
	/* change clock source to external reference clock */
        ICS_C1 =  ICS_C1 & ~(ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
        
	/* wait for the reference clock to be changed  */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S >> ICS_S_CLKST_SHIFT) !=2);
        while(ICS_S & ICS_S_IREFST_MASK);
			
	/* now external  clock is the system clock
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is external clock
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEI_to_FEE_OSC
   *
   * @brief change clock from FEI mode to FEE mode with external clock/oscillator 
   * and divide clock by 2
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEI_to_FEE_OSC(void)
{

#if	!defined(XOSC_ENABLE)	
	/* XOSC bypass mode, i.e. XOSC is disabled */
	/* PASS */
	OSC_CR = 0	/* low range */
#if  (EXT_CLK_CRYST >=4000)
		| 0x04 		/* high range */
#endif
		;
	
#else
	/* XOSC is enabled */
	/* PASS */
	OSC_CR =  0
#if  (EXT_CLK_CRYST >=4000)
		| 0x04    /* high range */
#endif
	            | OSC_CR_OSCEN_MASK | OSC_CR_OSCSTEN_MASK;		
#endif

#if defined(XOSC_HGO)
	OSC_CR |= OSC_CR_HGO_MASK;	//
#endif
	/* change RDIV  reference divider to divide reference clock to be with FLL input spec
	 * 
	 */
  #if (EXT_CLK_CRYST == 8000)||(EXT_CLK_CRYST == 10000)	
          /* 8MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(3);	/* now the divided frequency is 8000/256 = 31.25K */
  #elif (EXT_CLK_CRYST == 4000)
          /* 4MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(2);	/* now the divided frequency is 4000/128 = 31.25K */	
  #elif (EXT_CLK_CRYST == 16000)	
          /* 16MHz */
         ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 16000/512 = 31.25K */
          
  #elif (EXT_CLK_CRYST == 20000)
          /* 20MHz */
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK) | ICS_C1_RDIV(4);	/* now the divided frequency is 20000/512 = 39.0625K */
          
  #elif (EXT_CLK_CRYST == 32)
          ICS_C1 = ICS_C1 & ~(ICS_C1_RDIV_MASK);
  #else
          #error "Error: crystal value not supported!\n";
  #endif
	/* assume external oscillator is 8Mhz or 4MHz
	 * 
	 */
	/* change FLL reference clock to external clock */
        ICS_C1 =  ICS_C1 & ~(ICS_C1_IREFS_MASK);
	
	/* wait for the reference clock to be changed to external */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(ICS_S & ICS_S_IREFST_MASK);
	
	/* wait for FLL to lock */
	while(!(ICS_S & ICS_S_LOCK_MASK));
		
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is the target frequency
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEE_to_FEI
   *
   * @brief change clock from FEE mode to FEI mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEE_to_FEI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
		
	
	/* select internal reference for FLL */ 
        ICS_C1 =  ICS_C1 | (ICS_C1_IREFS_MASK);
	
	/* wait for the reference clock to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(!(ICS_S & ICS_S_IREFST_MASK));
	
	/* wait for FLL to lock */
	while(!(ICS_S & ICS_S_LOCK_MASK));

	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;
	
	/* now FLL output clock is target frequency
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* now system/bus clock is around 16MHz
	 * 
	 */
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEE_to_FBI
   *
   * @brief change clock from FEE mode to FBI mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEE_to_FBI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;
	
	/* select internal clock as clock source */
	/* select internal reference for FLL */ 
	/* LP = 0 */

        ICS_C1 =  ICS_C1 | (ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
	
	/* wait for the reference clock to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(!(ICS_S & ICS_S_IREFST_MASK));
	while((ICS_S >> ICS_S_CLKST_SHIFT) !=1);
	
	/* now system clock source is internal reference clock around 32K
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FEE_to_FBE
   *
   * @brief change clock from FEE mode to FBE mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FEE_to_FBE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;
	
	/* select the external clock as clock source */
        /* LP = 0 */
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S >> ICS_S_CLKST_SHIFT) !=2);
	
	/* now system clock source is external clock
	 * NOTE: make sure that the external clock is within 20MHz 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBI_to_FBE
   *
   * @brief change clock from FBI mode to FBE mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBI_to_FBE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* select external reference clock */
	/* select the external clock as clock source */

        ICS_C1 =  ICS_C1 & ~(ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S >> ICS_S_CLKST_SHIFT) !=2);
	while((ICS_S & ICS_S_IREFST_MASK));
	
	/* now system clock source is external clock
	 * NOTE: make sure that the external clock is within 20MHz 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBI_to_FEE
   *
   * @brief change clock from FBI mode to FEE mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBI_to_FEE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* select external reference clock */
	/* select the FLL output as clock source */

        ICS_C1 =  ICS_C1 & ~(ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK));   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     

	while((ICS_S & ICS_S_CLKST_MASK));
	while((ICS_S & ICS_S_IREFST_MASK));
	
	
	/* now system clock source is external clock
	 * NOTE: make sure that the external clock is within 20MHz 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBI_to_FBILP
   *
   * @brief change clock from FBI mode to FBILP mode. NOTE: make sure that
   *        BDM is disabled.
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBI_to_FBILP(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	ICS_C2 |= ICS_C2_LP_MASK;	/* enter low power mode */
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBI_to_FEI
   *
   * @brief change clock from FBI mode to FEIP mode. 
   * 
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBI_to_FEI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* select internal reference clock */
	/* select the FLL output as clock source */
        ICS_C1 =  ICS_C1 | (ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK));   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S & ICS_S_CLKST_MASK));
	while(!(ICS_S & ICS_S_IREFST_MASK));

        
	/* now system clock source is FLL output
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}



/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBE_to_FBI
   *
   * @brief change clock from FBE mode to FBI mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBE_to_FBI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* select internal reference clock */
	/* select the internal clock as clock source */
        ICS_C1 =  ICS_C1 | (ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S >> ICS_S_CLKST_SHIFT) != 1);
	while(!(ICS_S & ICS_S_IREFST_MASK));
	
	/* now system clock source is internal clock
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBE_to_FEE
   *
   * @brief change clock from FBE mode to FEE mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBE_to_FEE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */

	/* select the FLL output as clock source */
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK));   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(ICS_S & ICS_S_CLKST_MASK);

	
	/* now system clock source is FLL output
	 * NOTE: external clock <= 20MHz
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBE_to_FEI
   *
   * @brief change clock from FBE mode to FEI mode
   *        
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBE_to_FEI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* select internal reference clock */
	/* select the internal clock as clock source */

        ICS_C1 =  ICS_C1 | (ICS_C1_IREFS_MASK);
	ICS_C1 = (ICS_C1 & ~(ICS_C1_CLKS_MASK));   
	
	/* wait for the clock source to be changed */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS_S & ICS_S_CLKST_MASK));
	while(!(ICS_S & ICS_S_IREFST_MASK));
	
	/* now system clock source is internal clock
	 * 
	 */
	if(((ICS_C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS_C2 = (ICS_C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
	/* clear Loss of lock sticky bit */
	ICS_S |= ICS_S_LOLS_MASK;	
}



/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBE_to_FBELP
   *
   * @brief change clock from FBE mode to FBELP mode. NOTE: make sure that
   *        BDM is disabled.
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBE_to_FBELP(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* enter low power mode */
 	ICS_C2 = ICS_C2 | (ICS_C2_LP_MASK); 
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBELP_to_FBE
   *
   * @brief change clock from FBELP mode to FBE mode. 
   * 
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBELP_to_FBE(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* enter low power mode */
 	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
}

/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: FBILP_to_FBI
   *
   * @brief change clock from FBILP mode to FBI mode. 
   * 
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void FBILP_to_FBI(void)
{
	/* assume external crystal is 8Mhz or 4MHz
	 * 
	 */
	/* enter low power mode */
	ICS_C2 = ICS_C2 & ~(ICS_C2_LP_MASK); 
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: XOSC_Init
   *
   * @brief initialize XOSC with given parameters: GAIN, RANGE in control structure
   * 
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/
void XOSC_Init(TXOSC_Control *pOSCCtrl)
{
	
	/* 
	 * 
	 */
	if(pOSCCtrl->gain)
	{
		/* high gain */
		OSC_CR |= OSC_CR_HGO_MASK ;		/* Rs must be added and be large up to 200K */
	}
	else
	{
		/* low gain */
		OSC_CR &= ~OSC_CR_HGO_MASK;			
	}
	
	if(pOSCCtrl->range)
	{
		OSC_CR |= OSC_CR_RANGE_MASK; /* high range */	
	}
	else
	{
		OSC_CR &= ~OSC_CR_RANGE_MASK; /* low range */			
	}
	if(pOSCCtrl->stopEnable)
	{
		OSC_CR |= OSC_CR_OSCSTEN_MASK; 
	}
	else
	{
		OSC_CR &= ~OSC_CR_OSCSTEN_MASK; 		
	}
	if(pOSCCtrl->oscOut)
	{
		OSC_CR |= OSC_CR_OSCOS_MASK;
	}
	else
	{
		OSC_CR &= ~OSC_CR_OSCOS_MASK;		
	}
	if(pOSCCtrl->enable)
	{
		OSC_CR |= OSC_CR_OSCEN_MASK;
	}
	else
	{
		OSC_CR &= ~OSC_CR_OSCEN_MASK;		
	}	
	if(pOSCCtrl->waitInit)
	{

		/* wait for OSC to be initialized
		 * 
		 */
		while(!(OSC_CR & OSC_CR_OSCINIT_MASK));
		
	}
}


/*****************************************************************************//*!
   +FUNCTION----------------------------------------------------------------
   * @function name: ICS_Init
   *
   * @brief initialize ICS to the desired clock as defined in BUS_CLK_HZ
   * 
   * @param  none 
   *
   * @return none
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/

void ICS_Init(void)
{
#if defined(USE_FEE)  
 /* Initialize system clock to 16M with external 8M crystal*/
  FEI_to_FEE();
#elif	defined(USE_FBE_OSC)
  FEI_to_FBE_OSC();  
#elif	defined(USE_FEE_OSC)
  FEI_to_FEE_OSC();   
#endif  
}

