/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2011-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file ftm.h
*
* @author a13984
*
* @version 0.0.1
*
* @date Aug 4, 2011
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MA64, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/

#ifndef FTM_H_
#define FTM_H_

/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/
/* FTM mode */
enum {
FTM_MODE_GPIO = 0, 
FTM_MODE_INPUT_CAPTURE, 
FTM_MODE_OUTPUT_COMPARE, 
FTM_MODE_EDGE_ALIGNED_PWM, 
FTM_MODE_CENTER_ALIGNED_PWM,
FTM_MODE_COMBINE_PWM, 
FTM_MODE_DUAL_EDGE_CAPTURE
};

/* FTM channel edge control */
enum {
  FTM_EDGE_NO = 0,
  FTM_EDGE_RISING,
  FTM_EDGE_FALLING,
  FTM_EDGE_BOTH
};

/* FTM output compare control */
enum {
  FTM_OUTPUT_CMP_TOGGLE = 0,
  FTM_OUTPUT_CMP_CLEAR,
  FTM_OUTPUT_CMP_SET
};

/* FTM pwm polarity control */
enum {
  FTM_PWM_POL_HIGH_TRUE = 0,
  FTM_PWM_POL_LOW_TRUE,  
};

/* FTM dual edge capture mode */
enum {
  FTM_DUAL_EDGE_CAP_MODE_ONE_SHOT = 0,
  FTM_DUAL_EDGE_CAP_MODE_ONE_CONT
};
// channel number
enum {
PWM_CHANNEL0 =  0,
PWM_CHANNEL1,
PWM_CHANNEL2,
PWM_CHANNEL3,
PWM_CHANNEL4,
PWM_CHANNEL5,
};

/******************************************************************************
* Macros
******************************************************************************/

#define FTM_ERR_SUCCESS         0
#define FTM_ERR_INVALID_PARAM   1

#define TIMER   FTM0_BASE_PTR

#define ENABLE_FTM_OVF_INTERRUPT
#define ENABLE_FTM_CH0_INTERRUPT
#define ENABLE_FTM_CH1_INTERRUPT
#define ENABLE_FTM_CH2_INTERRUPT
#define ENABLE_FTM_CH3_INTERRUPT
#define ENABLE_FTM_CH4_INTERRUPT
#define ENABLE_FTM_CH5_INTERRUPT

/* define the FTM pwm mode: edge alligned or center alligned*/
#define FTM_PWMMODE_EDGEALLIGNED      1  /* EPWM */
#define FTM_PWMMODE_CENTERALLIGNED    2  /* CPWM */
#define FTM_PWMMODE_COMBINE           3  /* Combine PWM */

/* define FTM period and duty cycle init values */
#define FTM_MOD_INIT	(1000-1)
#define FTM_C0V_INIT	200
#define FTM_C1V_INIT	700
#define FTM_C2V_INIT	400     
#define FTM_C3V_INIT	700
#define FTM_C4V_INIT	300
#define FTM_C5V_INIT	700

#define FTM_COMBINE_FAULTEN_MASK  0x40
#define FTM_COMBINE_SYNCEN_MASK   0x20
#define FTM_COMBINE_DTEN_MASK     0x10
#define FTM_COMBINE_DECAP_MASK    0x08
#define FTM_COMBINE_DECAPEN_MASK  0x04
#define FTM_COMBINE_COMP_MASK     0x02
#define FTM_COMBINE_COMBINE_MASK  0x01

/* clock sources */
#define FTM_CLOCK_NOCLOCK             0 /* No Clock */
#define FTM_CLOCK_SYSTEMCLOCK         1 /* System clock/2 (if zFTMEN=0), else system clock (or Bus clock as is the terminology used here)*/
#define FTM_CLOCK_FIXEDFREQCLOCK      2 /* Fixed Freq Clock */
#define FTM_CLOCK_EXTERNALCLOCK       3 /* External Clock */

/* output mode */
#define FTM_OUTPUT_TOGGLE   1 /* toggle output on match */
#define FTM_OUTPUT_CLEAR    2 /* clear output on match */
#define FTM_OUTPUT_SET      3 /* set output on match */

/* mode edge select*/
#define FTM_INPUTCAPTURE_RISINGEDGE           1 /* rising edge */
#define FTM_INPUTCAPTURE_FALLINGEDGE          2 /* falling edge */
#define FTM_INPUTCAPTURE_BOTHEDGE             3 /* both edge */
#define FTM_INPUTCAPTURE_DUALEDGE_ONESHOT     4 /* dual edge one shot mode*/ 
#define FTM_INPUTCAPTURE_DUALEDGE_CONTINUOUS  5 /* dual edge continuouse mode*/

#define FTM_INPUTCAPTURE_DUALEDGE_NOEDGE          0
#define FTM_INPUTCAPTURE_DUALEDGE_RISINGEDGE      1
#define FTM_INPUTCAPTURE_DUALEDGE_FALLInGEDGE     2
#define FTM_INPUTCAPTURE_DUALEDGE_BOTHEDGE        3

/* PWM edge select*/
#define FTM_PWM_HIGHTRUEPULSE     1 /* high true pulses */
#define FTM_PWM_LOWTRUEPULSE      2 /* low true pulses */


/* sync trigger source */
#define FTM_SYNC_TRIGGER_SOFTWARE    1 /* Software synchronization */
#define FTM_SYNC_TRIGGER_TRIGGER2    2 /* Tigger2 synchronization, SIM_SOPT[FTMSYNC] */
#define FTM_SYNC_TRIGGER_TRIGGER1    3 /* Tigger1 synchronization, FTM0CH0 */
#define FTM_SYNC_TRIGGER_TRIGGER0    4 /* Tigger0 synchronization, ACMP0 */

/*  SW output control value */ 
#define FTM_SWOCTRL_HIGH    1
#define FTM_SWOCTRL_LOW     0

/*  polarity */ 
#define FTM_POLARITY_HIGHACTIVE     0
#define FTM_POLARITY_LOWACTIVE      1

// maco utilities
#define start_FTM(n,clks) FTM##n##_SC = (FTM##n##_SC & ~FTM_SC_CLKS_MASK) |  FTM_SC_CLKS(clks)
#define stop_FTM(n)       FTM##n##_SC = 0; FTM##n##_CNT = 0      
#define enable_FTM_channel_trigger(ftm,ch)      FTM##ftm##_EXTTRIG |= (ch>1)? (1<<(ch-2)) : (1<<(4+ch))
#define enable_FTM_init_trigger(ftm)            FTM##ftm##_EXTTRIG |= FTM##ftm##_EXTTRIG_INITTRIGEN_MASK

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
  uint8         clk_source;
  uint8         prescaler;
  uint8         sc;
  uint16        modulo;
  uint16        cnt;
  uint16        cntin;
  uint8         mode;
  uint8         sync;
  uint8         outinit;
  uint8         outmask;
  uint32        combine;
  uint16        deadtime;
  uint8         exttrig;
  uint8         pol;
  uint16        filter;
  uint8         fms;
  uint16        fltctrl;
  uint8         fltpol;
  uint16        conf;
  uint32        synconf;
  uint8         invctrl;
  uint16        swoctrl;
  uint16        pwmload;
} TFTM_Params, *P_TFTM_Params;

typedef struct
{
  uint8         cnsc;
  uint16        cnv;
  union{
    uint32      dw;
    struct 
    {
      uint32    mode:   3;      // flextimer mode: GPIO, INPUT_CAPTURE, OUTPUT_COMPARE, EDGE_ALIGNED_PWM, CENTER_ALIGNED_PWM,
                                // COMBINE_PWM, DUAL_EDGE_CAPTURE
      uint32    edge:   2;      // which edge
      uint32    out_cmp: 2;     // toggle, clear, set
      uint32    pwm_pol: 1;     //  high-true pulse, low-true pulses
      uint32    dcap_mode: 1;    //  dual edge capture mode: one-shot, continuous mode
      uint32    chie:   1;       // enable channel interrupt
    }bitfields;
  }ctrl;
} TFTMCH_Params, *P_TFTMCH_Params;


/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

uint8 FTM_PWM_Init(FTM_MemMapPtr FTM_No, unsigned char PWMModeSelect, unsigned char PWMEdgeSelect);
uint8 FTM_InputCapture_Init(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char CaptureMode);
uint8 FTM_DualEdgeCapture_Init(FTM_MemMapPtr FTM_No, unsigned char ChannelPair, unsigned char CaptureMode, 
                               unsigned char Channel_N_Edge, unsigned char Channel_Np1_Edge);
uint8 FTM_OutputCompare_Init(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char CompareMode);
uint8 FTM_SYNC_Software(FTM_MemMapPtr FTM_No);
uint8 FTM_SYNC_Hardware(FTM_MemMapPtr FTM_No, unsigned char TriggerN);
uint8 FTM_PWM_Deadtime_Set(FTM_MemMapPtr FTM_No, unsigned char PrescalerValue, unsigned char DeadtimeValue);
uint8 FTM_OutputMask_Set(FTM_MemMapPtr FTM_No, unsigned char Channel);
uint8 FTM_SWOutputControl_Set(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char ChannelValue);
uint8 FTM_Polarity_Set(FTM_MemMapPtr FTM_No, unsigned char Channel, unsigned char ActiveValue);
uint8 FTM_InvertingCTRL_Set(FTM_MemMapPtr FTM_No, unsigned char ChannelPair);
void FTM_Init(FTM_MemMapPtr FTM_No, TFTM_Params *pFTM_Params);
void  FTM_Set_DutyCycle_Combine(FTM_MemMapPtr FTM_No, uint8 FTM_Channel, uint16 dutyCycle);
#endif /* FTM_H_ */
