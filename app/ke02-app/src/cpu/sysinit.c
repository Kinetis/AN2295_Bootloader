/*
 * File:        sysinit.c
 * Purpose:     Kinetis Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 */

#include "common.h"
#include "sysinit.h"
#include "uart.h"
#include "ics.h"

/********************************************************************/

unsigned short global_pass_count = 0;
unsigned short global_fail_count = 0;
#if	defined(SEE_DEFAULT_TRIM_VALUE)  
  unsigned short gwTrimValue;
#endif
void print_sys_log(void);


/********************************************************************/
void sysinit (void)
{
	/*
	/////////////////////////////////////////////////////////////////////////////////////////
	// Peripheral Init
	// --------------------------------------------------------------------------------------
	/////////////////////////////////////////////////////////////////////////////////////////
	*/

#if defined(BUS2CORE_CLOCK_1_2)
  /* bus clock/flash clock is half of the core*/
  SIM_BUSDIV |= 1;
#endif

#if	defined(SEE_DEFAULT_TRIM_VALUE)  
  gwTrimValue = (ICS_C4 << 8) | ICS_C3;
#endif
  
  /* If not trimmed, do trim first */
   ICS_C3 =  ICS_TRIM_VALUE;
   ICS_C4 = 1;
   while(!(ICS_S & ICS_S_LOCK_MASK));
  
  /* Initialize the Pass/Fail counts to 0 */
  global_pass_count = 0;
  global_fail_count = 0;

 /* Enable SWD pin, RESET pin */
 /* NOTE: please make sure other register bits are also write-once and
  * need add other bit mask here if needed.
  */
  SIM_SOPT = SIM_SOPT_SWDE_MASK | SIM_SOPT_RSTPE_MASK;

#if defined(SPI0_PINREMAP)    
  SIM_PINSEL |= SIM_PINSEL_SPI0PS_MASK;
#endif        
  
  
  /* output bus clock if enabled */
#if defined(OUTPUT_BUSCLK)
  SIM_SOPT |= SIM_SOPT_CLKOE_MASK;
#endif


  
 /* Initialize the internal clock module */
  ICS_Init();
 
 /* make sure clocks to peripheral modules are enabled */
  SIM_SCGC |= SIM_SCGC_UART0_MASK | SIM_SCGC_UART1_MASK | SIM_SCGC_UART2_MASK;
  
 /* Initialize SCI for printing */
 UART_InitPrint();                        

#if	defined(PRINT_SYS_LOG)
   print_sys_log();
#endif
#if	defined(SEE_DEFAULT_TRIM_VALUE)  
  printf("default trim value = %#4.4x\n",gwTrimValue);
#endif   
 }

/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: print_sys_log
*
* @brief  print system reset sources
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void print_sys_log(void) 
{
    uint8_t rst = 0;
   
    printf("\n\n--System Log BEGINS--\n\n");
    printf("\n SRS=0x%02x\n",SIM_SRSID);

    printf("\n Familly ID = 0x%x, Sub-family ID = 0x%x, Revision ID = 0x%x, Pin ID = 0x%x \n",      \
      (SIM_SRSID >> SIM_SRSID_FAMID_SHIFT) , (SIM_SRSID & SIM_SRSID_SUBFAMID_MASK) >> SIM_SRSID_SUBFAMID_SHIFT,     \
      (SIM_SRSID & SIM_SRSID_RevID_MASK) >> SIM_SRSID_RevID_SHIFT,              \
      (SIM_SRSID & SIM_SRSID_PINID_MASK) >> SIM_SRSID_PINID_SHIFT); 

    if((SIM_SRSID & SIM_SRSID_POR_MASK) && (SIM_SRSID & SIM_SRSID_LVD_MASK)) 
    {
      rst = 1;
      printf(" Power On Reset\n");
    }
    
    if(!(SIM_SRSID & SIM_SRSID_POR_MASK) && (SIM_SRSID & SIM_SRSID_LVD_MASK)) 
    {
      rst = 1;
      printf(" LVD Reset\n");
    }
    
    if(SIM_SRSID & SIM_SRSID_WDOG_MASK)                 
    {
      rst = 1;
      printf(" WDOG Reset\n");
    }
    
    
    if(SIM_SRSID & SIM_SRSID_PIN_MASK)
    {
      rst = 1;
      printf(" Pin Reset\n");
    }
    if(SIM_SRSID & SIM_SRSID_LOC_MASK)
    {
      rst = 1;
      printf(" Loss of Clock Reset\n");
    }    
    if(SIM_SRSID & SIM_SRSID_SACKERR_MASK)
    {
      rst = 1;
      printf(" Stop Mode Acknowledge Error Reset\n");
    }    
    if(SIM_SRSID & SIM_SRSID_MDMAP_MASK)
    {
      rst = 1;
      printf(" MDM-AP System Reset Request\n");
    }    
    if(SIM_SRSID & SIM_SRSID_SW_MASK)
    {
      rst = 1;
      printf(" Software/SYSRESETREQ Reset\n");
    }    
    if(SIM_SRSID & SIM_SRSID_LOCKUP_MASK)
    {
      rst = 1;
      printf(" Core lockup Reset\n");
    }    

    if(rst != 1)
    {
      printf("SWD Reset\n");
    }
    
    printf("\n--System Log ENDS--\n\n");
  }


/*****************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: end_test
*
* @brief  print test result (pass/fail counts) after end of test
*        
* @param  none 
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void end_test(void)
{

  if(global_fail_count==0){
    printf("\n global_pass_count = 0x%02x%02x",(byte)(global_pass_count>>8),(byte)global_pass_count);
    printf("\n\n TEST PASSED");       
  } else{
    printf("\n global_pass_count = 0x%02x%02x",(byte)(global_pass_count>>8),(byte)global_pass_count);
    printf("\n global_fail_count = 0x%02x%02x",(byte)(global_fail_count>>8),(byte)global_fail_count);
    printf("\n\n TEST FAILED");
  }
  
  printf("\n\n TEST FINISHED");  
  
}