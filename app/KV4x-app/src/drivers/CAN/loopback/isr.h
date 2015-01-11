

#ifndef __ISR_H
#define __ISR_H

//#define USE_FLEXCAN1
#define USE_FLEXCAN0

// Vector definition for FlexCAN0 OR'ed Message buffer

#ifdef  USE_FLEXCAN0
  #undef	VECTOR_091	
  #undef        VECTOR_046
  #undef	VECTOR_047	
  #undef        VECTOR_048
  #undef	VECTOR_049	
  #undef        VECTOR_050
  #undef        VECTOR_051
  #undef        VECTOR_052

  #define	VECTOR_045	FlexCAN_MB_ISR		// FlexCAN0 MB Interrupt Service Routine
  #define	VECTOR_046	FlexCAN_BusOff_ISR	// FlexCAN0 Bus Off Interrupt Service Routine
  #define	VECTOR_047	FlexCAN_Error_ISR       // FlexCAN0 Error Interrupt Service Routine
  #define	VECTOR_048	FlexCAN_TxWarning_ISR	// FlexCAN0 Transmit Warning Interrupt Service Routine
  #define	VECTOR_049	FlexCAN_RxWarning_ISR	// FlexCAN0 Receive Warning Interrupt Service Routine
  #define	VECTOR_050	FlexCAN_Wakeup_ISR	// FlexCAN0 Wakeup Interrupt Service Routine
  #define	VECTOR_051	FlexCAN_IMEU_ISR	// FlexCAN0 Individual Matching Elements Update Interrupt Service Routine
  #define	VECTOR_052	FlexCAN_LostRx_ISR	// FlexCAN0 Lost Receive Interrupt Service Routine

#else
  #undef	VECTOR_053	
  #undef	VECTOR_054	
  #undef	VECTOR_055	
  #undef	VECTOR_056	
  #undef	VECTOR_057	
  #undef	VECTOR_058	
  #undef	VECTOR_059	
  #undef	VECTOR_060	

  #define	VECTOR_053	FlexCAN_MB_ISR		// FlexCAN1 MB Interrupt Service Routine
  #define	VECTOR_054	FlexCAN_BusOff_ISR	// FlexCAN1 Bus Off Interrupt Service Routine
  #define	VECTOR_055	FlexCAN_Error_ISR       // FlexCAN1 Error Interrupt Service Routine
  #define	VECTOR_056	FlexCAN_TxWarning_ISR	// FlexCAN1 Transmit Warning Interrupt Service Routine
  #define	VECTOR_057	FlexCAN_RxWarning_ISR	// FlexCAN1 Receive Warning Interrupt Service Routine
  #define	VECTOR_058	FlexCAN_Wakeup_ISR	// FlexCAN1 Wakeup Interrupt Service Routine
  #define	VECTOR_059	FlexCAN_IMEU_ISR	// FlexCAN1 Individual Matching Elements Update Interrupt Service Routine
  #define	VECTOR_060	FlexCAN_LostRx_ISR	// FlexCAN1 Lost Receive Interrupt Service Routine

#endif

extern void	FlexCAN_MB_ISR(void);
extern void	FlexCAN_BusOff_ISR(void);
extern void	FlexCAN_Error_ISR(void);
extern void	FlexCAN_TxWarning_ISR(void);
extern void	FlexCAN_RxWarning_ISR(void);
extern void	FlexCAN_Wakeup_ISR(void);
extern void	FlexCAN_IMEU_ISR(void);
extern void	FlexCAN_LostRx_ISR(void);
#endif