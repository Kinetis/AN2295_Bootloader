/*
 * File:		FRDMKL46_Demo.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "lcd.h"
#include "gpio.h"
#include "TSIDrv.h"
#include "global.h"
#include "pit.h"
#include "task_mgr.h"
#include "usb_cdc.h"
#include "usb_reg.h"
#include "adc16.h"
#include "adc_test.h"
#include "median.h"   
#include "hal_i2c.h"

#include "hal_dev_mag3110.h"
#include "hal_dev_mma8451.h"
#include "sensorCompass.h"
#include "angle_cal.h"
#include "uart.h"




#ifdef CMSIS
#include "start.h"
#endif

#define CLKOUT

#define USB_PLL_PRDIV           4       //Divide 8MHz XTAL by 4 = 2MHz
#define USB_PLL_VDIV            48      //Multiply 2MHz ref with 48 = 96MHz



struct mediana_type arr_medianas[4];   

int adc_light_sensor;
char sw1_aux1;


/* Testing Suite */
#define USB_DEVICE_XCVR_TEST
   
uint8 gu8USB_Buffer[64];
int t_flash=300;

extern uint8 gu8USB_State;
extern uint8 gu8USB_Flags;
extern uint8 gu8EP3_OUT_ODD_Buffer[];
extern tBDT tBDTtable[];


void vfn_led_test(void);
void task_test_lcd(void);


void task_test_slider(void);

void task_hello(void);
void task_ecompass(void);
void task_light_sensor(void);
void task_accel_sensor(void);




/*
 *  Reconfigure MCG to work at 96MHz, to support USB module
 *
*******************************************************************/

void vfnMcuConfig (void)
{ 
#if defined(CLKOUT)
  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;            //Enable clock on PTC3
  PORTC_PCR3 = PORT_PCR_MUX(0x05);              //PTC3 as CLKOUT
  SIM_SOPT2 &= ~SIM_SOPT2_CLKOUTSEL_MASK;       //Clear CLKOUTSEL register
  SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0x02);       //Select BUSCLK as CLKOUT output
#endif
  
  /* Actual PLL frequency is 48MHz --> 96MHz needed for USB to work due freq divider by 2 */
  
  /* Set dividers for new PLL frequency */
  SIM_CLKDIV1 = ( 0
                        | SIM_CLKDIV1_OUTDIV1(1)
                        | SIM_CLKDIV1_OUTDIV4(1) );
  
  /* Return MCG to PBE */
  MCG_C6 |= MCG_C6_PLLS_MASK;
  MCG_C2 &= ~MCG_C2_LP_MASK;
  MCG_C1 &= ~MCG_C1_IREFS_MASK;
  MCG_C1 |= MCG_C1_CLKS(2);
  
  /* Move MCG to FBE */
  MCG_C6 &= ~MCG_C6_PLLS_MASK;
  MCG_C5 &= ~MCG_C5_PLLCLKEN0_MASK;
  
  /* Configure PLL to run @96MHz */
  MCG_C6 &= ~MCG_C6_VDIV0_MASK;
  MCG_C5 &= ~MCG_C5_PRDIV0_MASK;
  MCG_C6 |= (USB_PLL_VDIV - 24);
  MCG_C5 |= (USB_PLL_PRDIV - 1);
  MCG_C5 |= MCG_C5_PLLCLKEN0_MASK;              //Enable PLL
  while(!(MCG_S & MCG_S_LOCK0_MASK));           //Wait for PLL to lock
  
  /* Go to PBE */
  MCG_C6 |= MCG_C6_PLLS_MASK;
  
  /* Go to PEE */
  MCG_C1 &= ~MCG_C1_CLKS_MASK;
  
  /* MCG is now configured */
  
  /* Reconfigure UART0 with new frequency */
  
#if TERM_PORT_NUM==0
  uart0_init (UART0_BASE_PTR, 48000, TERMINAL_BAUD);
#elif TERM_PORT_NUM==1
  uart_init (UART1_BASE_PTR, 24000, TERMINAL_BAUD);
#else
  uart_init (UART2_BASE_PTR, 24000, TERMINAL_BAUD);
#endif
   
}


void vfn_led_test(void)
 {
   static char cont_sec=0;
   if (!ti_task)
   {
     ti_task = t_flash;    
     switch (++cont_sec)
     {
      case 1:
        LED1_OFF;
        LED2_OFF;
       break;
       
      case 2:
        LED1_ON;
        LED2_OFF;
       break;

      case 3:
        LED1_OFF;
        LED2_ON;
       break;

      case 4:
        LED1_OFF;
        LED2_ON;
       break;

      case 5:
        LED1_OFF;
        LED2_OFF;
       break;

     default:
         next_task(task_test_lcd);
     }
    }
 }


/******************************************************************************/
void usb_init(void)
{
      //printf("\n********** USB XCVR Module Testing **********\n");
      USB_REG_SET_ENABLE;
      CDC_Init();
      // Pull up enable
      FLAG_SET(USB_CONTROL_DPPULLUPNONOTG_SHIFT,USB0_CONTROL);
}
/******************************************************************************/
void usb_service(void)
{
    // If data transfer arrives
    if(FLAG_CHK(EP_OUT,gu8USB_Flags))
    {
        (void)USB_EP_OUT_SizeCheck(EP_OUT);
        usbEP_Reset(EP_OUT);
        usbSIE_CONTROL(EP_OUT);
        FLAG_CLR(EP_OUT,gu8USB_Flags);

        // Send it back to the PC
        EP_IN_Transfer(EP2,CDC_OUTPointer,1);
    }
    if (!ti_print)
    {
        ti_print = 300;
        sprintf((char *)gu8USB_Buffer,"\rtsi %%= %03i ", AbsolutePercentegePosition);
        EP_IN_Transfer(EP2,gu8USB_Buffer,15);
    }
}



/*configures TPM0_CH3   green LED to be PWM controlled*/
void tpm_init(void)
{
   SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;   //enable TPM clock gate
   SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK;  //select PLL as clock source of 
   
   TPM0_MOD = 1000;  
   
#ifdef FRDM_REVA   
   TPM0_C3SC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSB_MASK;  //PWM edge aligned
   TPM0_C3V = 500;
#else
   TPM0_C5SC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSB_MASK;  //PWM edge aligned
   TPM0_C5V = 500;
  
#endif
   
    TPM0_SC |= TPM_SC_PS(0) | TPM_SC_CMOD(1);
  
}


void task_hello(void)
 {
   vfnLCD_Write_Msg("-HI-");
 }


void task_test_lcd(void)
{
  static char count_mode=0;
  if (!ti_task)
  {
    ti_task = 200;
    if (count_mode++>=10)count_mode=0;
    
    switch(count_mode)
    {
    case 0: vfnLCD_Write_Msg("0000");  break;
    case 1: vfnLCD_Write_Msg("1111");  break;
    case 2: vfnLCD_Write_Msg("2222");  break;
    case 3: vfnLCD_Write_Msg("3333");  break;
    case 4: vfnLCD_Write_Msg("4444");  break;
    case 5: vfnLCD_Write_Msg("5555");  break;
    case 6: vfnLCD_Write_Msg("6666");  break;
    case 7: vfnLCD_Write_Msg("7777");  break;
    case 8: vfnLCD_Write_Msg("8888");  break;
    case 9: vfnLCD_Write_Msg("9999");  break;
    }
  
  } 
  
   if (input_rise(SW1_ON, &sw1_aux1)) 
   {
     next_task(task_test_slider);
     printf("\n\r TSI: slider test ");
   }
  
}

void task_test_slider(void)
{
     static int touch_slider_last_valid_value=50;
     
     
     if (AbsolutePercentegePosition>0) touch_slider_last_valid_value=AbsolutePercentegePosition;
     t_flash = (touch_slider_last_valid_value*2 + 50);
     sprintf((char *)gu8USB_Buffer,"%4i", touch_slider_last_valid_value);
     
#ifdef FRDM_REVA     
     PORTA_PCR6 = PORT_PCR_MUX(3); //enable as TPM0_CH3
     TPM0_C3V=touch_slider_last_valid_value*10;
#else
     PORTD_PCR5 = PORT_PCR_MUX(4); //enable as TPM0_CH5
     TPM0_C5V=touch_slider_last_valid_value*10; 
#endif
         
     
     
     
     vfnLCD_Write_Msg(gu8USB_Buffer);
     printf("\r tsi %%= %03i  ", AbsolutePercentegePosition);
     
     
     
  if (!ti_task)
   {
     ti_task = t_flash;    
     LED1_TOGGLE;
     LED2_TOGGLE;
   }     
 
    if (input_rise(SW1_ON, &sw1_aux1)) 
   {
#ifdef FRDM_REVA
                 PORTA_PCR6 = PORT_PCR_MUX(1); //PTA6 as GPIO LED3
#else
                 PORTD_PCR5 = PORT_PCR_MUX(1); //PTA6 as GPIO LED3
                 
#endif  
     
     
       next_task(task_ecompass);
       printf("\n\r eCompass,  Magenetomer + accelerometer test ");  
   }
  
}


void task_ecompass(void)
{
   static  int temp_direction;

   ControlLoopCompass();
   
   /* determine how far is from north*/
   if (ecompass_direction<180)    temp_direction = ecompass_direction;         //0 to 180    NE
   else  temp_direction = (360 - ecompass_direction);   //0 to 180  NW
   t_flash = (temp_direction)*2 + 10 ;
   
   printf("Yaw =%4d Pitch =%4d Roll =%4d \r", APsi6DOF, APhi6DOF, AThe6DOF);

   
   if (!ti_task)
   {
     ti_task = t_flash;    
     LED1_TOGGLE;
     LED2_TOGGLE;
   }   
 
     if (input_rise(SW1_ON, &sw1_aux1)) 
   {
     next_task(task_light_sensor);
     printf("\n\r ADC:  light sensor test ");  
   }
   
   
}


void task_light_sensor(void)
{ 

   char buffer_char[10];
   if (!ti_task)
   {
     ti_task = 200;    

     printf("\r adc: light_sensor %4i",adc_light_sensor);
     sprintf(buffer_char,"%4d",adc_light_sensor);
     vfnLCD_Write_Msg((uint8 *)buffer_char);   //print when it is calibrated
     
   }  

  if (input_rise(SW1_ON, &sw1_aux1)) 
   {
    next_task(task_test_lcd);
    printf("\n\r sLCD test  ");
   }   
   
}


void task_accel_sensor(void)
{
   if (!ti_task)
   {
     ti_task = 200;    
     accel_read();

   }  
   
}




/********************************************************************/
int main (void)
{
    	char ch,aux1 ,aux2;
      
     
            int UsbDetected = FALSE;
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
         vfnMcuConfig();
         
    
  	printf("\n\rRunning the FRDMKL46_Demo project.\n\r");
        vfnLCD_Init();
        
        gpio_init();
        Pit_init();
        TSI_Init();

        usb_init();                   
        next_task(vfn_led_test);
        accel_init();
        mag_init();
        eCompassInit();
        adc_init();        
        tpm_init();  //Green LED 50%SIM_SCGC5_PORTC_MASK
         
        
        vfnLCD_Write_Msg("8888");
        _LCD_DP1_ON();
        _LCD_DP2_ON();
        _LCD_DP3_ON();
        _LCD_COL_ON();
         
 	while(1)
	{
        
#ifdef FRDM_REVA  
          if (uart_getchar_present(UART1_BASE_PTR))
#else
            
          if (uart0_getchar_present(UART0_BASE_PTR))
#endif
            
          {
            ch = in_char();
            printf("\n\r Received char = %c \n\r",ch);            
           if (ch==' ')
           {     
           printf("\n\r light_sensor  = %i",adc_light_sensor);
         //  printf("\n\r Yaw =%4d Pitch =%4d Roll =%4d \r", APhi6DOF, AThe6DOF, APsi6DOF);
           printf("\n\r Yaw =%4d Pitch =%4d Roll =%4d \r", APsi6DOF, APhi6DOF, AThe6DOF);
           
           printf("\n\r tsi %%= %03i  ", AbsolutePercentegePosition);
           }
         }
          
           if (input_rise(SW1_ON, &aux1))
            {  
              printf("\n\r SW1 \n\r");
            }
          
         
            if (input_rise(SW2_ON, &aux2))
            {  
              printf("\n\r SW2 \n\r ");
            }
                  
             ptr_next_task();  // do the actual function
             TSI_SliderRead();
            
             usb_service();
            if (gu8USB_State == uENUMERATED && !UsbDetected) 
            {
               UsbDetected = TRUE;
            }        
            
            adc_light_sensor = adc_read(3);
                
                    
              
                
        }
}
/********************************************************************/
