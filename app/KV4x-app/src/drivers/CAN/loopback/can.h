#ifndef	__CAN_H
#define __CAN_H

#include "common.h"
#include "kinetis_flexcan.h"


// Bit definition for CAN message structure
#define	CAN_MSG_IDE_MASK	(0x80000000L)
#define CAN_MSG_IDE_BIT_NO	(31)
#define CAN_MSG_ID_EXTENDED	(CAN_MSG_ID_MASK)
#define CAN_MSG_ID_STANDARD	(0)
#define CAN_MSG_TYPE_MASK 	(0x40000000L)
#define CAN_MSG_TYPE_BIT_NO	(30)
#define CAN_MSG_TYPE_DATA_FRAME	(CAN_MSG_TYPE_MASK)
#define CAN_MSG_TYPE_REMOTE_FRAME	(0)

// # of MBs supported
#define NUMBER_OF_MB		16


// Definition of Receive MBs index 
//#define	FLEXCAN_RX_MB_START	0
//#define	FLEXCAN_RX_MB_END	(NUMBER_OF_RX_MB-1)

// Definition of Transmit MBs index
//#define FLEXCAN_TX_MB_START	(FLEXCAN_RX_MB_END+1)
//#define	FLEXCAN_TX_MB_END	(NUMBER_OF_MB-1)

#ifndef	NULL
	#define	NULL	(void*)0
#endif	

#undef	HANDLE
#define	HANDLE	uint32 *

// Now it is safe to include custom macros
#include "can_config.h"

// Error code
#define FLEXCAN_ERROR_SUCCESS     0
#define FLEXCAN_ERROR_CODE_BASE   0x100
#define FLEXCAN_ERROR_INVALID_BAUD  (FLEXCAN_ERROR_CODE_BASE)
#define FLEXCAN_ERROR_PENDING_TX    (FLEXCAN_ERROR_CODE_BASE+1)
#define FLEXCAN_ERROR_TX_DONE       (FLEXCAN_ERROR_CODE_BASE+2)
#define FLEXCAN_ERROR_TX_ERR        (FLEXCAN_ERROR_CODE_BASE+3)
#define FLEXCAN_ERROR_PARAM_OUT_OF_RANGE   (FLEXCAN_ERROR_CODE_BASE+4)

// utilities
#define swap_4bytes(ptr)	{ uint8_t	byte;	\
								byte = (ptr)[0]; (ptr)[0] = (ptr)[3]; (ptr)[3]=byte;	\
								byte = (ptr)[1]; (ptr)[1] = (ptr)[2]; (ptr)[2]=byte;	\
							}

#define min(x,y)      ((x) < (y)? (x):(y))
#define max(x,y)      ((x) >= (y)? (x):(y))

typedef	void (*TCallBack)(uint16 iMBNo);

// mail box
typedef volatile struct {	
   uint8	dev_num;		        /*  FlexCAN device number */
   uint16	mailbox_number; 		/*  mailbox number */
   uint32	identifier;   			/*  message ID */
   uint8	format;				/*  mailbox format (FLEXCAN_STANDARD OR FLEXCAN_EXTENDED) */ 
   uint8	direction; 			/*  transmission or reception direction (FLEXCAN_TX or FLEXCAN_RX) */
   uint8	remote_req_flag;		/*  is remote request?   */  
   uint8	data_len;			/*  number of bytes to write to or read from the mailbox (0 to 8) */ 
   uint8	data[8]; 			/*  data bytes */
   uint8	code;				/* control code */ 
   uint8	priority;			/*  priority of the message in the mailbox */
   uint16	timestamp;			/*  timestamp */
   uint16	crc;				/*  crc of the message frame */
   uint32	imask;				/* individual mask */
 } TFCAN_MailBox, *PTFCAN_MailBox;

// Driver structure
typedef  union {
  uint16       Byte;
  struct{
    uint16        bClockSource: 1;                    /* clock source for FlexCAN: 0 -- external oscillator, 1 -- bus clock from PLL */
    uint16        bSelfRxDis:   1;                    /* disable self-reception: 0 - enable self-reception; 1 -- disable self-reception */
    uint16        bScanPrio:    1;                     /* scan prio: 0 -- RxFIFO first, 1 -- MB first */    
    uint16        bStoreRTR:    1;                     /* remote request storing */
    uint16        bEACEN:       1;                     /* entire frame arbitration filed comparision including IDE,RTR, excluding RxFIFO */
    uint16        bIRMQ:        1;                     /* individual Rx Masking and queue enable */
    uint16        bLoopBack:    1;                     /* loopback enable */
    uint16        bLocalPrio:   1;                     /* local priority enable */
    uint16        bResvd:       8;                    /* reserved */
  }Bits;
}  TCtrlWord;

typedef volatile struct {
  CAN_MemMapPtr pCANRegs;                      /* pointer to CAN register structure */
  uint8        bRxFIFOFilterNo;                /* no of RxFIFO filters: valid values are 
                                                * 0 -- disable RxFIFO
                                                * 8/16/24/32/40
                                                */
  uint8        bRxFIFOIDFormat;                 /* Rx FIFO ID table format: 0 -- Format A, 1 -- Format B, 2 -- Format C, 3 -- Format D */
  TCtrlWord    ctrlWord;                        /* control word */
  uint8        bRxMBStart;                      /* start index of Rx MB# */
  uint8        bRxMBEnd;                        /* end index of Rx MB# */
  uint8        bTxMBStart;                      /* start index of Tx MB# */  
  uint8        bTxMBEnd;                        /* end index of Tx MB# */  
} TFCANDrv_Obj, *PTFCANDrv_Obj;

// Prototypes
extern  HANDLE  FlexCAN_Open(void);
extern  int16   FlexCAN_Init(uint32  baudrateKHz );
extern  void    FlexCAN_Start(void);
extern  void    FlexCAN_Stop(void);
extern  int16   FlexCAN_ConfigureRxFIFO_IDTable(uint32 idList[],uint16 idListNo);
extern  int16   FlexCAN_ConfigureRxFIFOFilterTabElementMask(uint16 iTabElement,uint32 mask);
extern  int16   FlexCAN_ConfigureRxFIFOGlobalMask(uint32 mask);
extern  int16   FlexCAN_ConfigureRxMBMask(uint16 iMB,uint32 mask);

extern  void    FlexCAN_Write(HANDLE h, uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes);
extern  int16   FlexCAN_Read(HANDLE h, int16 iMailBoxQue, uint32 *id, uint8 data[]);
extern  int16   FlexCAN_Read_RxFIFOQueue(HANDLE h, uint32 *id, uint8 data[]);
extern  void    FlexCAN_PrepareTransmit(uint16 iTxMBNo,uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes);
extern  void    FlexCAN_PrepareAndStartTransmit(uint16 iTxMBNo,uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes, uint8 txCode);
extern  void    FlexCAN_PrepareRxCANMB(uint16 iMB, uint32 id);
extern  uint16  FlexCAN_ReadCANMB(uint16 iMB, uint32 *id, uint32 * timeStamp, uint8 *data, uint8 bUnlock );
extern  uint16  FlexCAN_CheckAbortStatus(uint16 iMB);
extern  void    FlexCAN_EnableMB_Interrupt(uint16 iMB);
extern  void    FlexCAN_DisableMB_Interrupt(uint16 iMB);
extern  uint8   FlexCAN_Is_Transfer_Done(uint16 iMB);

extern  void    FlexCAN_Poll_RxMBs(void);
extern  void    FlexCAN_Poll_TxMBs(void);
extern  void    FlexCAN_Poll_RxFIFO(void);
#endif