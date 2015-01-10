/******************************************************************************
* File:    TSS_SystemSetup.h
* Purpose: This file contains electrode and other Touch Sensing System setup parameters
* Note:
******************************************************************************/                                                                                       
#ifndef TSS_SYSTEM_SETUP_H
#define TSS_SYSTEM_SETUP_H

#include "main.h"

/* TSS Features Configuration */

#define TSS_KINETIS_MCU                        1  /* or add define MCU_MKE02 in TSS_Sensor.h to detecte the mcu */

#define TSS_USE_DELTA_LOG                      1

#define TSS_USE_SIGNAL_LOG                     1

#define TSS_USE_GPIO_STRENGTH                  0

#define TSS_USE_GPIO_SLEW_RATE                 0

#define TSS_USE_IIR_FILTER                     1

#define TSS_USE_NOISE_AMPLITUDE_FILTER         0  /* disable this on KLxxx, some bug need to be fixed */

#define TSS_USE_TRIGGER_FUNCTION               1

#define TSS_USE_AUTO_SENS_CALIBRATION          1

#define TSS_USE_AUTO_SENS_CALIB_INIT_DURATION  100

#define TSS_USE_BASELINE_INIT_DURATION         15

#define TSS_USE_DATA_CORRUPTION_CHECK          1

#define TSS_USE_SIGNAL_SHIELDING               0

#define TSS_USE_SIGNAL_DIVIDER                 1

#define TSS_USE_SIGNAL_MULTIPLIER              0

#define TSS_USE_STUCK_KEY                      1

#define TSS_USE_NEGATIVE_BASELINE_DROP         1

#define TSS_USE_AUTO_HW_RECALIBRATION          1

#define TSS_USE_CONTROL_PRIVATE_DATA           0

#define TSS_ENABLE_DIAGNOSTIC_MESSAGES         0

#define TSS_ONFAULT_CALLBACK                   TSS_fOnFault /* Identifier of the user's OnFault callback */

#define TSS_ONINIT_CALLBACK                    TSS_fOnInit  /* Identifier of the user's OnInit callback */

#define TSS_N_ELECTRODES                       2            /* Number of electrodes present in the system */



/* FTMx, TPMx or MTIMx, for GPIO method, FTM1 and TPM2 is for PWM in app_init.c file */
#ifndef OUT_LIBRARY
#define TSS_HW_TIMER                           FTM0  
#else
#define TSS_HW_TIMER                           FTM2
#endif


#define TSS_SENSOR_PRESCALER                   2
#define TSS_SENSOR_TIMEOUT                     65535


/* Electrode's GPIOs configuration */

// for GPIO method                 
#define TSS_E0_P                    A   /* it is PTD7 in KE02, but should configured as PTA30, check the RM */
#define TSS_E0_B                    30
#define TSS_E1_P                    A   /* it is PTD6 in KE02, but should configured as PTA31, check the RM */
#define TSS_E1_B                    31

#define TSS_E0_TYPE                 GPIO
#define TSS_E1_TYPE                 GPIO


/* Signal Multiplier & Divider */

#define TSS_E0_SIGNAL_DIVIDER       2
#define TSS_E1_SIGNAL_DIVIDER       2

/* Controls configuration */

#define TSS_N_CONTROLS              1

#define TSS_C0_TYPE                 TSS_CT_ASLIDER    /* Control type */
#define TSS_C0_ELECTRODES           2                 /* Number of electrodes in the control */
#define TSS_C0_STRUCTURE            cASlider1         /* Name of the C&S struct to create */
#define TSS_C0_CALLBACK             TSS1_fCallBack1   /* Identifier of the user's callback */

#endif /*__TSS_SYSTEM_SETUP_H__*/
