
#include "can.h"



// Globals
TFCAN_MailBox	RxMailBox[MAX_RX_MAILS];  // receive mail box queue
TFCAN_MailBox	TxMailBox[MAX_TX_MAILS];  // transmit mail box queue
TFCAN_MailBox	RxFIFOQue[MAX_RXFIFO_MAILS];  // rx FIFO queue
volatile int16  rdRxMailBox,              // read pointer for RxMailBox
                wrRxMailBox,              // write pointer for RxMailBox
                rdTxMailBox,              // read pointer for TxMailBox
                wrTxMailBox;              // write pointer for TxMailBox
volatile int16  rdRxFIFOQue;          // read pointer for RxFIFO queue
volatile int16  wrRxFIFOQue;          // write pointer for RxFIFO queue
volatile uint32 nCANErrorCount;
volatile uint32 bMBFlags1,bMBFlags2;   // flag if a MB is done by ISR

static int8 occurence;

static CAN_MemMapPtr pFlexCANReg =        // pointer to the CAN register
#ifndef  USE_FLEXCAN0
  CAN1_BASE_PTR    
#else
  CAN0_BASE_PTR      
#endif    
;
static TFCANDrv_Obj  FlexCANDrvObj;
static PTFCANDrv_Obj pFlexCANDrvObj;

// Prototypes
static void   FlexCAN_MB_Callback(uint16 iMBNo);
static void   FlexCAN_Err_Callback(uint32 status);
static void   FlexCAN_RxFIFOErr_Callback(void);


// Functions
HANDLE FlexCAN_Open(void)
{
	int16	i;
	
	// Initialize the driver structures
	for(i = 0; i < MAX_RX_MAILS; i++)
	{
		RxMailBox[i].dev_num = 0;
	}
	for(i = 0; i < MAX_TX_MAILS; i++)
	{
		TxMailBox[i].dev_num = 0;
	}	
 	for(i = 0; i < MAX_RXFIFO_MAILS; i++)
	{
		RxFIFOQue[i].dev_num = 0;
	}	       
        rdRxMailBox = wrRxMailBox = 0;
        rdTxMailBox = wrTxMailBox = 0;
        rdRxFIFOQue = wrRxFIFOQue = 0;
        
        occurence = 0; nCANErrorCount = 0;
        
        bMBFlags1 = bMBFlags2 = 0;
        
        // Initialize driver object based on custom macro definitions
        pFlexCANDrvObj = &FlexCANDrvObj;
        
        pFlexCANDrvObj->ctrlWord.Bits.bClockSource = (FLEXCAN_CLOCK_SOURCE? 1 : 0);                    
        pFlexCANDrvObj->ctrlWord.Bits.bSelfRxDis =   (FLEXCAN_SELF_RECEPTION? 0 : 1);                    
        pFlexCANDrvObj->ctrlWord.Bits.bScanPrio =    (FLEXCAN_SCAN_PRIORITY? 1 : 0);                        
        pFlexCANDrvObj->ctrlWord.Bits.bStoreRTR =    (FLEXCAN_STORE_RTR? 1 : 0);                     
        pFlexCANDrvObj->ctrlWord.Bits.bEACEN =       (FLEXCAN_ENTIRE_ARB_CMP? 1: 0);                     
        pFlexCANDrvObj->ctrlWord.Bits.bIRMQ =        (FLEXCAN_INDIVIDUAL_MASK? 1 : 0);                     
        pFlexCANDrvObj->ctrlWord.Bits.bLoopBack =    (FLEXCAN_LOOP_BACK? 1 : 0);                     
        pFlexCANDrvObj->ctrlWord.Bits.bLocalPrio =   (FLEXCAN_LOCAL_PRIO? 1 : 0);  
        
        pFlexCANDrvObj->bRxMBStart = FLEXCAN_RX_MB_START;                      /* start index of Rx MB# */
        pFlexCANDrvObj->bRxMBEnd   = FLEXCAN_RX_MB_END;                        /* end index of Rx MB# */
        pFlexCANDrvObj->bTxMBStart = FLEXCAN_TX_MB_START;                      /* start index of Tx MB# */  
        pFlexCANDrvObj->bTxMBEnd  = FLEXCAN_TX_MB_END;                          /* end index of Tx MB# */ 
        
        pFlexCANDrvObj->bRxFIFOFilterNo = FLEXCAN_NO_RXFIFO_FILTERS;   
        pFlexCANDrvObj->bRxFIFOIDFormat = FLEXCAN_ID_TAB_FORMAT;
        
        pFlexCANDrvObj->pCANRegs = pFlexCANReg;
        
	return ((HANDLE) pFlexCANReg);
}

int16 FlexCAN_Init(uint32  baudrateKHz )
{
      int16 i;
      int8  isCAN0;
       
      // Enable clock to FlexCAN
      isCAN0 = (pFlexCANReg == CAN0_BASE_PTR);
      if(isCAN0)
      {
        SIM_SCGC6 |=  SIM_SCGC6_FLEXCAN0_MASK;
      }
      else
      {
        SIM_SCGC6 |= SIM_SCGC6_FLEXCAN1_MASK;
      }
       // Configure NVIC to enable interrupts
       if(isCAN0)
       {
         NVICICPR0     =  (NVICICPR0 & ~(0x07<<29)) | (0x07<<29);      // Clear any pending interrupts on  FLEXCAN0    
         NVICISER0     =  (NVICISER0 & ~(0x07<<29))  | (0x07<<29);    // Enable interrupts for FLEXCAN0              
         NVICICPR1    =   (NVICICPR1 & ~(0x1F<<0)) | (0x1F);        // Clear any pending interrupts on  FLEXCAN0    
         NVICISER1     =  (NVICISER1 & ~(0x1F<<0))  | (0x1F);        // Enable interrupts for FLEXCAN0              
       }
       else
       {
          NVICICPR1     = (NVICICPR1 & ~(0xFF<<5)) | (0xFF<<5);        // Clear any pending interrupts on  FLEXCAN1    
          NVICISER1      = (NVICISER1  & ~(0xFF<<5)) | (0xFF<<5);        // Enable interrupts for FLEXCAN1                
       }
      
      // Select clock source for CAN first
      // NOTE: must ensure that LPM_ACK = 1 before changing clock source bit
      if(pFlexCANDrvObj->ctrlWord.Bits.bClockSource)
      {
         pFlexCANReg->CTRL1 |= FLEXCAN_CTRL_CLK_SRC; //Source --> bus clock
      }
      else
      {
         pFlexCANReg->CTRL1 &= ~FLEXCAN_CTRL_CLK_SRC; //Source --> external oscillator
      }
      // Enable CAN module
      pFlexCANReg->MCR |= FLEXCAN_MCR_FRZ;          // enable HALT feature
      pFlexCANReg->MCR &= ~FLEXCAN_MCR_MDIS; 
	
      while((FLEXCAN_MCR_LPM_ACK & pFlexCANReg->MCR));	

      // Now can apply Soft Reset
      pFlexCANReg->MCR ^= FLEXCAN_MCR_SOFT_RST;
      while(FLEXCAN_MCR_SOFT_RST & pFlexCANReg->MCR);
	 	
       // Now it should be in Freeze mode  
       while(!(FLEXCAN_MCR_FRZ_ACK & pFlexCANReg->MCR));
       
       // Disable self-reception
       if(pFlexCANDrvObj->ctrlWord.Bits.bSelfRxDis)
       {
          pFlexCANReg->MCR |= FLEXCAN_MCR_SRX_DIS;
       }
       
       // Enable individual masking and queue
       if(pFlexCANDrvObj->ctrlWord.Bits.bIRMQ)
       {
          pFlexCANReg->MCR |=  FLEXCAN_MCR_IRMQ;    
       }
       // Set local priority
       if(pFlexCANDrvObj->ctrlWord.Bits.bLocalPrio)
       {
          pFlexCANReg->MCR |=  FLEXCAN_MCR_LPRIO_EN;   
       }
       
       
        /* Initialize all 16 MBs */		  
        for(i=0;i<NUMBER_OF_MB;i++)
        {
              pFlexCANReg->MB[i].CS = 0x00000000;
              pFlexCANReg->MB[i].ID = 0x00000000;
              pFlexCANReg->MB[i].WORD0 = 0x00000000;
              pFlexCANReg->MB[i].WORD1 = 0x00000000;
        }
       // Set RRS and EACEN bits in CTRL2
       if(pFlexCANDrvObj->ctrlWord.Bits.bEACEN)
       {
          pFlexCANReg->CTRL2 |= FLEXCAN_CTRL2_EACEN;
       }
       else
       {
          pFlexCANReg->CTRL2 &= ~FLEXCAN_CTRL2_EACEN;         
       }
       if(pFlexCANDrvObj->ctrlWord.Bits.bStoreRTR)
       {
          pFlexCANReg->CTRL2 |= FLEXCAN_CTRL2_RRS;
       }
       else
       {
          pFlexCANReg->CTRL2 &= ~FLEXCAN_CTRL2_RRS;         
       }  
       // Set Scan priority (Mailbxes reception priority)
       if(pFlexCANDrvObj->ctrlWord.Bits.bScanPrio)
       {
          pFlexCANReg->CTRL2 |= FLEXCAN_CTRL2_MRP;
       }
       else
       {
          pFlexCANReg->CTRL2 &= ~FLEXCAN_CTRL2_MRP;         
       }        
       
       // Eanble RxFIFO if # of RxFIFO filters is >0
       if(pFlexCANDrvObj->bRxFIFOFilterNo)
       {
         pFlexCANReg->MCR |= FLEXCAN_MCR_FEN;
         
         // Configure RFFN field with # of Rx FIFO filters
         FLEXCAN_set_rffn(pFlexCANReg->CTRL2,((pFlexCANDrvObj->bRxFIFOFilterNo>>3)-1));
       }
       // Set ID filter table format
       pFlexCANReg->MCR |= (pFlexCANReg->MCR & ~FLEXCAN_MCR_IDAM_MASK) | FLEXCAN_MCR_IDAM(pFlexCANDrvObj->bRxFIFOIDFormat);
      
       // Configure bit rate
       switch (baudrateKHz)
       {

              case (33):	// 33.33K
                
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {
                         /* 
                         ** 48M/120= 400k sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 3, PSEG1 = 4, PSEG2 = 4,PRESDIV = 120
                         */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(119));
                 }
                 else
                 {
 		         /* 
                         ** 12M/20= 600k sclock, 18Tq
		         ** PROPSEG = 1, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 4, PSEG1 = 8, PSEG2 = 8,PRESDIV = 20
		         */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(0) | FLEXCAN_CTRL_RJW(3)
			 	    					    | FLEXCAN_CTRL_PSEG1(7) | FLEXCAN_CTRL_PSEG2(7)
			 	    					    | FLEXCAN_CTRL_PRESDIV(19));
                  
                 }
                     break;
              case (83):	// 83.33K
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {

                         /* 
                         ** 48M/48= 1M sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 3, PSEG1 = 4, PSEG2 = 4,PRESDIV = 48
                         */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(47));
                 }
                 else
                 {
		         /* 
                         ** 12M/12= 1M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 3, PSEG1 = 4, PSEG2 = 4,PRESDIV = 12
		         */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(11));
                   
                 }
                     break;
              case (50):
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {                
                         /* 
                         ** 48M/80= 0.6M sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                           ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 40
                         */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(1)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(79));
                 }
                 else
                 {
		         /* 
                         ** 12M/20= 0.6M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 20
		         */                   
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(19));                   
                 }
                     break;
              case (100):
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {
                         /* 
                         ** 48M/40= 1.2M sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 40
                         */
                        pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(39));
                 }
                 else
                 {
		         /* 
                         ** 12M/10= 1.2M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 10
		         */
                        pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(9));                   
                 }
                     break;
              case (125):
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {                
                       /* 
                       ** 48M/32= 1.5M sclock, 12Tq
                       ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                               ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 32
                       */
                       pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
                                                                          | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                          | FLEXCAN_CTRL_PRESDIV(31));
                 }
                 else
                 {
 		         /* 
                         ** 12M/8= 1.5M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 3, PSEG1 = 4, PSEG2 = 4, PRESDIV = 8
		         */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(2)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(7));                  
                 }
                     break;
              case (250):
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {                
                         /* 
                         ** 48M/16= 3M sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 2, PSEG1 = 4, PSEG2 = 4, PRESDIV = 16
                         */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(1)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(15));
                 }
                 else
                 {
		         /* 
                         ** 12M/4= 3M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 2, PSEG1 = 4, PSEG2 = 4, PRESDIV = 4
		         */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(1)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(3));                   
                 }
                     break;
              case (500):
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {                
                         /* 
                         ** 48M/8=6M sclock, 12Tq
                         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 2, PSEG1 = 4, PSEG2 = 4, PRESDIV = 6
                         */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(1)
                                                                            | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
                                                                            | FLEXCAN_CTRL_PRESDIV(7));
                 }
                 else
                 {
		         /* 
                         ** 12M/2=6M sclock, 12Tq
		         ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 2, PSEG1 = 4, PSEG2 = 4, PRESDIV = 2
		         */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(1)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(1));                   
                 }
                     break;
              case (1000): 
                 if(pFlexCANReg->CTRL1 & FLEXCAN_CTRL_CLK_SRC)
                 {                
                             /*  
                                 ** 48M/6=8M sclock
                                 ** PROPSEG = 4, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
                                 ** RJW = 1, PSEG1 = 1, PSEG2 = 2, PRESCALER = 6
                             */
                         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(3) | FLEXCAN_CTRL_RJW(0)
                                                                            | FLEXCAN_CTRL_PSEG1(0) | FLEXCAN_CTRL_PSEG2(1)
                                                                            | FLEXCAN_CTRL_PRESDIV(5));
                 }
                 else
                 {
			     /*  
                                 ** 12M/1=12M sclock,12Tq
				 ** PROPSEG = 3, LOM = 0x0, LBUF = 0x0, TSYNC = 0x0, SAMP = 1
				 ** RJW = 4, PSEG1 = 4, PSEG2 = 4, PRESCALER = 1
			     */
		         pFlexCANReg->CTRL1 = (0 | FLEXCAN_CTRL_PROPSEG(2) | FLEXCAN_CTRL_RJW(3)
			 	    					    | FLEXCAN_CTRL_PSEG1(3) | FLEXCAN_CTRL_PSEG2(3)
			 	    					    | FLEXCAN_CTRL_PRESDIV(0));
                   
                 }
                     break;
              default: 
                 return (FLEXCAN_ERROR_INVALID_BAUD);
           }
       

        if(pFlexCANDrvObj->ctrlWord.Bits.bLoopBack)
        {
          // use loopback for single node
          pFlexCANReg->CTRL1 |= FLEXCAN_CTRL_LPB;
        }
        else
        {
          // use external CAN bus
          pFlexCANReg->CTRL1 &= ~FLEXCAN_CTRL_LPB;          
        }
      
	 
	 /* Initialize mask registers */
	 pFlexCANReg->RXMGMASK = 0x1FFFFFFF;
	 pFlexCANReg->RX14MASK = 0x1FFFFFFF;
	 pFlexCANReg->RX15MASK = 0x1FFFFFFF;
	 
	 /* Initialize individual mask registers for the queue */
	 if(pFlexCANReg->MCR & FLEXCAN_MCR_IRMQ)
	 {
           for(i = 0; i < NUMBER_OF_MB ; i++)
           {
	 	pFlexCANReg->RXIMR[i] = 0x1FFFFFFFL;
           }
	 }	
         
         // Enable interrupts
         //pFlexCANReg->IMASK1 |=  (1<<FLEXCAN_RX_MB_START) | (1<<FLEXCAN_TX_MB_START);         
         
         // Start communication
         FlexCAN_Start();
         
         return (FLEXCAN_ERROR_SUCCESS);
}

void FlexCAN_Start(void)
{
      // De-assert Freeze Mode 
     pFlexCANReg->MCR &= ~(FLEXCAN_MCR_HALT);
     
     // Wait till exit of freeze mode
     while( pFlexCANReg->MCR & FLEXCAN_MCR_FRZ_ACK)
     {
     }
     
     // Wait till ready 
     while(pFlexCANReg->MCR & FLEXCAN_MCR_NOT_RDY)
     {
     }
}


void FlexCAN_Stop(void)
{
      // Assert Freeze Mode 
     pFlexCANReg->MCR |= (FLEXCAN_MCR_HALT);
     
     // Wait till enter freeze mode
     while(!(pFlexCANReg->MCR & FLEXCAN_MCR_FRZ_ACK))
     {
     }     
}


int16 FlexCAN_ConfigureRxFIFO_IDTable(uint32 idList[],uint16 idListNo)
{
    uint16  nTotalValidTabIDNo; // total # of Rx FIFO table RxIDs
    uint16  nIDTab;
    uint8   bIDAM;
    uint8   bIsExtID,bIsRTR;
    uint32  id;
    uint32  *pIDTabElement;
    int16   i,j;
    uint8   bFreezeMode;
    int16   status = FLEXCAN_ERROR_SUCCESS;
  

    // Calculate the total # of valid table elements
    bIDAM = (pFlexCANReg->MCR & FLEXCAN_MCR_IDAM_MASK)>>FLEXCAN_MCR_IDAM_BIT_NO;
    if(bIDAM == 3)
    {
        // all frames will be rejected, so just return without configuration
        status = FLEXCAN_ERROR_SUCCESS;
        return (status);
    }
    nTotalValidTabIDNo = (pFlexCANReg->CTRL2 & FLEXCAN_CTRL2_RFFN)>> FLEXCAN_CTRL2_RFFN_BIT_NO;
    nTotalValidTabIDNo = ((nTotalValidTabIDNo+1)<<3) * (1<<bIDAM);

    if((idListNo) > nTotalValidTabIDNo)
    {
        status = (FLEXCAN_ERROR_PARAM_OUT_OF_RANGE);
        return (status);
    }
    
    nIDTab = min(idListNo, nTotalValidTabIDNo);
   
    // Calculate the address of the starting ID Table Element corresponding startIDTabNo which bases 0
    pIDTabElement = (uint32*)&pFlexCANReg->MB[6];  // ID Filter Table Elements starts from MB6
  
    // Make sure FlexCAN is in Freeze mode before writing Filter tables
    if(!(pFlexCANReg->MCR & FLEXCAN_MCR_HALT))
    {
        FlexCAN_Stop(); // halt FlexCAN safely
        bFreezeMode = 0;
    }
    else
    {
        bFreezeMode = 1;
    }    
    // Configure the RX FIFO ID filter Tab elements
    for(i = 0; i < nIDTab; )
    {
        // Get IDE bit and RTR bit
        id = idList[i] & ~(CAN_MSG_IDE_MASK |CAN_MSG_TYPE_MASK);
        bIsExtID = (idList[i] &  CAN_MSG_IDE_MASK)>>CAN_MSG_IDE_BIT_NO;
        bIsRTR = (idList[i] &  CAN_MSG_TYPE_MASK)>>CAN_MSG_TYPE_BIT_NO;
        
        if(bIDAM==1)
        {
              // Format B two IDs
              *pIDTabElement = ((id & 0x03fff)<< (16+ (1-bIsExtID)*3)) | (bIsExtID<<30) | (bIsRTR<<31);        // RXIDB_0  
              i++;
              if(i < nIDTab)
              {
                id = idList[i] & ~(CAN_MSG_IDE_MASK |CAN_MSG_TYPE_MASK);
                bIsExtID = (idList[i] &  CAN_MSG_IDE_MASK)>>CAN_MSG_IDE_BIT_NO;
                bIsRTR = (idList[i] &  CAN_MSG_TYPE_MASK)>>CAN_MSG_TYPE_BIT_NO;
                *pIDTabElement |= ((id & 0x03fff)<< ((1-bIsExtID)*3)) | (bIsExtID<<14) | (bIsRTR<<15);    // RXIDB_1     
                i++;
              }              
        }
        else if (bIDAM==2)
        { 
            // Format C
            j = 0;
            *pIDTabElement = (id & 0x00ff) << (24-(j<<3));    // RXIDC_0
            i++;j++;
            do{
                if(i < nIDTab)
                {
                  id = idList[i] & ~(CAN_MSG_IDE_MASK |CAN_MSG_TYPE_MASK);
                  bIsExtID = (idList[i] &  CAN_MSG_IDE_MASK)>>CAN_MSG_IDE_BIT_NO;
                  bIsRTR = (idList[i] &  CAN_MSG_TYPE_MASK)>>CAN_MSG_TYPE_BIT_NO;
                  *pIDTabElement |= ((id & 0x00ff) << (24-(j<<3)));   // RXIDC_1 .. RXIDC_3
                  j++; i++;
                }
                else
                {
                  break;
                }
            }while(j<=3);
        } 
        else if (!bIDAM)
        {
          if(bIsExtID)
          {   // Format A with extended ID
              *pIDTabElement = (id<<1) |  (bIsExtID<<30) | (bIsRTR<<31);    // single ID acceptance codes          
          }
          else
          {   // Format A with standard ID
               *pIDTabElement = (id<<19)  |  (bIsRTR<<31);    // single ID acceptance codes    RXIDA                 
          }
          i++;
        }
        pIDTabElement++;  // advance to the next ID table element
    } 
    // Enable Rx FIFO interrupt
   // pFlexCANReg->IMASK1 |=  FLEXCAN_IFLAG1_BUF5I;         
    
end:    
    // Restore FlexCAN operation mode
    if(!bFreezeMode)
    {
        FlexCAN_Start();
    }
    return (status);    
}


int16 FlexCAN_ConfigureRxMBMask(uint16 iMB,uint32 mask)
{
    uint8   bFreezeMode;
    
    if(iMB >  NUMBER_OF_MB)
    {
        return (FLEXCAN_ERROR_PARAM_OUT_OF_RANGE);
    }
    
    // Make sure FlexCAN is in Freeze mode
    if(!(pFlexCANReg->MCR & FLEXCAN_MCR_HALT))
    {
        FlexCAN_Stop(); // halt FlexCAN safely
        bFreezeMode = 0;
    }
    else
    {
        bFreezeMode = 1;
    }   
    // Check if individual masking is enabled
    if(pFlexCANReg->MCR & FLEXCAN_MCR_IRMQ)
    {
        // individual masks
        pFlexCANReg->RXIMR[iMB] = mask;
    }
    else
    {   // Legacy support with global masks
        if(iMB == 14)
        {
            pFlexCANReg->RX14MASK = mask;
        }
        else if (iMB == 15)
        {
            pFlexCANReg->RX15MASK = mask;        
        }
        else
        {
            pFlexCANReg->RXMGMASK = mask;
        }
    }
    // Restore FlexCAN operation mode
    if(!bFreezeMode)
    {
        FlexCAN_Start();
    }    
    return (FLEXCAN_ERROR_SUCCESS);
}


int16 FlexCAN_ConfigureRxFIFOFilterTabElementMask(uint16 iTabElement,uint32 mask)
{
    uint8   bFreezeMode;
    uint8   bIDAM;
    uint16  nTotalValidTabNo;
    
    bIDAM = (pFlexCANReg->MCR & FLEXCAN_MCR_IDAM_MASK)>>FLEXCAN_MCR_IDAM_BIT_NO;

    nTotalValidTabNo = (pFlexCANReg->CTRL2 & FLEXCAN_CTRL2_RFFN)>> FLEXCAN_CTRL2_RFFN_BIT_NO;
    nTotalValidTabNo = ((nTotalValidTabNo+1)<<3);

    
    if(iTabElement >  nTotalValidTabNo)
    {
        return (FLEXCAN_ERROR_PARAM_OUT_OF_RANGE);
    }
    
    // Make sure FlexCAN is in Freeze mode
    if(!(pFlexCANReg->MCR & FLEXCAN_MCR_HALT))
    {
        FlexCAN_Stop(); // halt FlexCAN safely
        bFreezeMode = 0;
    }
    else
    {
        bFreezeMode = 1;
    }   
    // Configure Rx FIFO table element filter
   // Check if individual masking is enabled
    if(pFlexCANReg->MCR & FLEXCAN_MCR_IRMQ)
    {
        // individual masks
        pFlexCANReg->RXIMR[iTabElement] = mask; // similar to MB RX IMR
    }
    else
    {   // Legacy support with global masks
         pFlexCANReg->RXFGMASK = mask;
    }    
  
    // Restore FlexCAN operation mode
    if(!bFreezeMode)
    {
        FlexCAN_Start();
    }    
    return (FLEXCAN_ERROR_SUCCESS);
}



int16 FlexCAN_ConfigureRxFIFOGlobalMask(uint32 mask)
{
    uint8   bFreezeMode;
    
    // Make sure FlexCAN is in Freeze mode
    if(!(pFlexCANReg->MCR & FLEXCAN_MCR_HALT)) //FLEXCAN_MCR_FRZ_ACK))
    {
        FlexCAN_Stop(); // halt FlexCAN safely
        bFreezeMode = 0;
    }
    else
    {
        bFreezeMode = 1;
    }   
    pFlexCANReg->RXFGMASK = mask;

    // Restore FlexCAN operation mode
    if(!bFreezeMode)
    {
        FlexCAN_Start();
    }    
    return (FLEXCAN_ERROR_SUCCESS);
}


                                 
void FlexCAN_Write(HANDLE h, uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes)
{
     int16 i;

     
     if((wrTxMailBox+1) == rdTxMailBox)
     {
        // if queue full, return
        return;
     }
     TxMailBox[wrTxMailBox].identifier = msgID;
     TxMailBox[wrTxMailBox].priority = prio;
     TxMailBox[wrTxMailBox].data_len = iNoBytes;
     
     for(i = 0; i < iNoBytes; i++)
     {
      TxMailBox[wrTxMailBox].data[i] = bBytes[i];
     }
     //
     wrTxMailBox++;
     if(wrTxMailBox >=MAX_TX_MAILS)
     {
          wrTxMailBox = 0;
     }
     
     // Prepare transmit for the first time
     if(!occurence)
     {       
       occurence = 1;
       FlexCAN_PrepareAndStartTransmit(pFlexCANDrvObj->bTxMBStart,
                                 TxMailBox[rdTxMailBox].identifier, 
                                 TxMailBox[rdTxMailBox].priority,
                                 (uint8*)TxMailBox[rdTxMailBox].data,
                                 TxMailBox[rdTxMailBox].data_len,
                                 FLEXCAN_MB_CODE_TX_ONCE              // tx once
                                 );
        rdTxMailBox++;
          if(rdTxMailBox >=MAX_TX_MAILS)
          {
            rdTxMailBox = 0;
          }        
     }    
}


int16 FlexCAN_Read(HANDLE h, int16 iMailBoxQue, uint32 *id, uint8 data[])
{
     int16 i;
     int16 noBytes = 0;

     if(rdRxMailBox == wrRxMailBox)
     {
        // if queue empty, return
        return (noBytes);
     }
     
     *id = RxMailBox[rdRxMailBox].identifier; 
     noBytes =  RxMailBox[rdRxMailBox].data_len;
    
     for(i = 0; i < noBytes; i++)
     {
       data[i] =  RxMailBox[rdRxMailBox].data[i];
     }
     rdRxMailBox++;
     if(rdRxMailBox >=MAX_RX_MAILS)
     {
          rdRxMailBox = 0;
     } 
     return (noBytes);     
}


int16 FlexCAN_Read_RxFIFOQueue(HANDLE h, uint32 *id, uint8 data[])
{
     int16 i;
     int16 noBytes = 0;
                 
     if(rdRxFIFOQue == wrRxFIFOQue)
     {
        // if queue empty, return
        return (noBytes);
     }
     
     *id = RxFIFOQue[rdRxFIFOQue].identifier; 
     noBytes =  RxFIFOQue[rdRxFIFOQue].data_len;
    
     for(i = 0; i < noBytes; i++)
     {
       data[i] =  RxFIFOQue[rdRxFIFOQue].data[i];
     }
     rdRxFIFOQue++;
     if(rdRxFIFOQue >=MAX_RXFIFO_MAILS)
     {
          rdRxFIFOQue = 0;
     } 
     return (noBytes);     
}


void FlexCAN_PrepareTransmit(uint16 iTxMBNo,uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes)
{
   int16  i,wno,bno;
   uint32 word[2];
   
   
   if(iTxMBNo >= NUMBER_OF_MB || iNoBytes >8)
   {
      return; // out of range
   }
    // convert data bytes to words
    wno = (iNoBytes-1)>>2;
    bno = (iNoBytes-1)%4;
    if(wno >0)
    {
    	word[0] = ((bBytes[0]<<24) | (bBytes[1]<<16) | (bBytes[2]<< 8) | bBytes[3]);
    }
    for(i=0;i<=bno;i++)
    {
       word[wno] |=   bBytes[(wno<<2)+i] << (24-(i<<3)); 
    } 
    // Get IDE bit and RTR bit
    wno = (msgID &  CAN_MSG_IDE_MASK)>>CAN_MSG_IDE_BIT_NO;
    bno = (msgID &  CAN_MSG_TYPE_MASK)>>CAN_MSG_TYPE_BIT_NO;
    
    // Get ID bit no
    i =  wno? 0: FLEXCAN_MB_ID_STD_BIT_NO;
    
    // Follow 4 steps for Transmit Process
    pFlexCANReg->MB[iTxMBNo].CS = FLEXCAN_MB_CS_CODE(FLEXCAN_MB_CODE_TX_INACTIVE) // write inactive code
    				| (wno<<FLEXCAN_MB_CS_IDE_BIT_NO)
    				| (bno<<FLEXCAN_MB_CS_RTR_BIT_NO)
                                | FLEXCAN_MB_CS_LENGTH(iNoBytes)      // can write size here
    				;
    pFlexCANReg->MB[iTxMBNo].ID = (prio << FLEXCAN_MB_ID_PRIO_BIT_NO) | ((msgID & ~(CAN_MSG_IDE_MASK|CAN_MSG_TYPE_MASK))<<i);    
    pFlexCANReg->MB[iTxMBNo].WORD0 = word[0];
    pFlexCANReg->MB[iTxMBNo].WORD1 = word[1];   
   
    // do not start transmit
}


void FlexCAN_PrepareAndStartTransmit(uint16 iTxMBNo,uint32 msgID, uint8 prio,uint8 bBytes[], int8 iNoBytes, uint8 txCode)
{
   int16  i,wno,bno;
   
   
   if(iTxMBNo >= NUMBER_OF_MB || iNoBytes >8)
   {
      return; // out of range
   }
   
   // Enable tx MB interrupt
   //pFlexCANReg->IMASK1 |=  (1<<iTxMBNo);    
   
   // Flag transfer starts
   bMBFlags1 &= ~(1<<iTxMBNo);
   
   //
   FlexCAN_PrepareTransmit(iTxMBNo,msgID,prio, bBytes,iNoBytes);
    
   
    // Start transmit with specified tx code
    pFlexCANReg->MB[iTxMBNo].CS = (pFlexCANReg->MB[iTxMBNo].CS & ~(FLEXCAN_MB_CS_CODE_MASK)) | FLEXCAN_MB_CS_CODE(txCode) // write activate code
    				|  FLEXCAN_MB_CS_LENGTH(iNoBytes);     
}


void FlexCAN_WriteCode(uint16 iTxMBNo, uint8 txrxCode)
{
   uint8   bFreezeMode;
   
   if(iTxMBNo >= NUMBER_OF_MB)
   {
      return; // out of range
   }    
    // Make sure FlexCAN is in Freeze mode
    if(!(pFlexCANReg->MCR & FLEXCAN_MCR_HALT)) //FLEXCAN_MCR_FRZ_ACK))
    {
        FlexCAN_Stop(); // halt FlexCAN safely
        bFreezeMode = 0;
    }
    else
    {
        bFreezeMode = 1;
    }      
    // Start transmit/receive with specified tx/rx code
    pFlexCANReg->MB[iTxMBNo].CS = (pFlexCANReg->MB[iTxMBNo].CS & ~(FLEXCAN_MB_CS_CODE_MASK)) 
          | FLEXCAN_MB_CS_CODE(txrxCode) // write code
            ;
   
    // Restore FlexCAN operation mode
    if(!bFreezeMode)
    {
        FlexCAN_Start();
    }       
}



/**************************************************************
					ReadCANMB
** Read directly from CAN Message Buffer up to 8 bytes and return
** the size in bytes of data read.
 					
** NOTE:
** So the ID format is:
** B31 30 29 28 27 26 ... 11 10 9 8 7 6 5 4 3 2 1 0
** |	|	 |									  |
** |    |    |------------------------------------|
** |	|					|--> 29 bits ID
** |	|
** |    |--> 1: RTR bit set, 0: RTR bit clear
** |
** |--> 1 : Extended ID, 0: Standardard ID
**************************************************************/
uint16 FlexCAN_ReadCANMB(uint16 iMB, uint32 *id, uint32 * timeStamp, uint8 *data, uint8 bUnlock )
{
	int8 i,wno,bno;
	uint16 code;
	uint8 *pMBData;
	int16 length;
        int8  leftBytes;
        int8  format;
        uint8 *pBytes = data;
	
        // Lock the MB
        code = FLEXCAN_get_code(pFlexCANReg->MB[iMB].CS);
 
	length = FLEXCAN_get_length(pFlexCANReg->MB[iMB].CS);       
        // 
        format = (pFlexCANReg->MB[iMB].CS & FLEXCAN_MB_CS_IDE)? 1:0;
	*id = (pFlexCANReg->MB[iMB].ID & FLEXCAN_MB_ID_EXT_MASK);
        if(!format)  
        {
            // standard ID
          *id >>= FLEXCAN_MB_ID_STD_BIT_NO;         
        }
        else
        { 
          *id |= CAN_MSG_IDE_MASK;          // flag extended ID
        }
        format = (pFlexCANReg->MB[iMB].CS & FLEXCAN_MB_CS_RTR)? 1:0;  
        if(format)
        {
          *id |= CAN_MSG_TYPE_MASK;         // flag Remote Frame type
        }
        // Read message bytes
        wno = (length-1)>>2;
        bno = length-1;
        if(wno>0)
        {
            //
            (*(uint32*)pBytes) = pFlexCANReg->MB[iMB].WORD0;
            swap_4bytes(pBytes);
            bno -= 4;
            pMBData = (uint8*)&pFlexCANReg->MB[iMB].WORD1+3;
        }
        else
        {
            pMBData = (uint8*)&pFlexCANReg->MB[iMB].WORD0+3;
        }
	for(i=0; i <= bno; i++)
	{
          pBytes[i+(wno<<2)] = *pMBData--;	
        }
       
       // Read time stamp
       *timeStamp = pFlexCANReg->MB[iMB].CS & FLEXCAN_MB_CS_TIMESTAMP_MASK ;
    
        if(bUnlock)
        {
          // Unlock the MB
          code = pFlexCANReg->TIMER;
        }
	return length;
}


/**************************************************************
					PrepareRxCANMB
** Prepare a CAN MB for rx.
 					
** NOTE:
** If using FCANMB_SET_ID or FCANMB_GET_ID, consider the condition:
** #define FCAN_ID_EXT 0x80000000	// specifies extended ID anywhere the ID is required
** #define FCAN_ID_RTR 0x40000000	// turns on the RTR bit when calling FCANMB_SET_ID (only)
** So the ID format is:
** B31 30 29 28 27 26 ... 11 10 9 8 7 6 5 4 3 2 1 0
** |	|	 |									  |
** |    |    |------------------------------------|
** |	|					|--> 29 bits ID
** |	|
** |    |--> 1: RTR bit set, 0: RTR bit clear
** |
** |--> 1 : Extended ID, 0: Standardard ID
**************************************************************/
void FlexCAN_PrepareRxCANMB(uint16 iMB, uint32 id)
{
      uint32 id2;
      
      uint32 cs = FLEXCAN_MB_CS_CODE(FLEXCAN_MB_CODE_RX_EMPTY);
      
	// Deactivate the rx MB for cpu write 
        pFlexCANReg->MB[iMB].CS = FLEXCAN_MB_CS_CODE(FLEXCAN_MB_CODE_RX_INACTIVE); // write inactive code	
	
	// Write ID
        id2 = id & ~(CAN_MSG_IDE_MASK | CAN_MSG_TYPE_MASK);
        if(id & CAN_MSG_IDE_MASK)
        {
           pFlexCANReg->MB[iMB].ID = id2;
           cs |= FLEXCAN_MB_CS_IDE;
        }
        else
        {
           pFlexCANReg->MB[iMB].ID = id2<<FLEXCAN_MB_ID_STD_BIT_NO;          
        }
        
         // Activate the MB for rx 
        pFlexCANReg->MB[iMB].CS = cs;    
        
        // flag to caller transfer is started
        bMBFlags1 &= ~((long)1<<iMB);
}


void    FlexCAN_EnableMB_Interrupt(uint16 iMB)
{
      pFlexCANReg->IMASK1 |= (1<<iMB);
}

void    FlexCAN_DisableMB_Interrupt(uint16 iMB)
{
      pFlexCANReg->IMASK1 &= ~(1<<iMB);
}


uint8   FlexCAN_Is_Transfer_Done(uint16 iMB)
{
   if(bMBFlags1 & (1<<iMB))
   {
     return 1;
   }
   return 0;
}

void	FlexCAN_MB_ISR(void)
{
	// Check Rx MB flags, so Rx MBs has highest priority than Tx MBs
        FlexCAN_Poll_RxMBs();
        
	// Check Tx MB flags
        FlexCAN_Poll_TxMBs();
        
        // Check Rx FIFO status and handle it
        // If Rx FIFO is enabled, check FIFO flag
        if(pFlexCANReg->MCR & FLEXCAN_MCR_FEN)	
        {        
          FlexCAN_Poll_RxFIFO();
        }
}

void    FlexCAN_Poll_RxMBs(void)
{
  	int16 iMB;

	for(iMB =  pFlexCANDrvObj->bRxMBStart; iMB <=  pFlexCANDrvObj->bRxMBEnd; iMB++)
	{
		if(pFlexCANReg->IFLAG1 & (1<<iMB))
		{
			 // Read the Message information
                         if((wrRxMailBox+1) != rdRxMailBox)
                         {
                           RxMailBox[wrRxMailBox].data_len = 
                              FlexCAN_ReadCANMB(iMB, 
                                                (uint32*)&RxMailBox[wrRxMailBox].identifier, 
                                                (uint32*)&RxMailBox[wrRxMailBox].timestamp, 
                                                (uint8*)RxMailBox[wrRxMailBox].data,
                                                 1);
                           wrRxMailBox++;
                           if(wrRxMailBox >=MAX_RX_MAILS)
                           {
                             wrRxMailBox = 0;
                           }
                         }
                         
			 // clear flag
			 pFlexCANReg->IFLAG1 = (1<<iMB);
                         
                         bMBFlags1 |= (1<<iMB);       // set flag to caller indicating this MB is done
			 
			 // Call custom Rx callback to do follow up processing 
                         FlexCAN_MB_Callback(iMB);
		}
	}  
}


void    FlexCAN_Poll_TxMBs(void)
{
      int16 iMB;
    
      for(iMB =  pFlexCANDrvObj->bTxMBStart; iMB <=  pFlexCANDrvObj->bTxMBEnd; iMB++)
      {
              if(pFlexCANReg->IFLAG1 & (1<<iMB))
              {
                       // Read the time stamp information
                       if(rdTxMailBox != wrTxMailBox)
                       {
                          // if Tx MailBox not empty,do
                          FlexCAN_PrepareAndStartTransmit(iMB,
                                       TxMailBox[rdTxMailBox].identifier, 
                                       TxMailBox[rdTxMailBox].priority,
                                       (uint8*)TxMailBox[rdTxMailBox].data,
                                       TxMailBox[rdTxMailBox].data_len,
                                       FLEXCAN_MB_CODE_TX_ONCE              // tx once code
                                       );
                          rdTxMailBox++;
                          if(rdTxMailBox >=MAX_TX_MAILS)
                          {
                            rdTxMailBox = 0;
                          } 
                       }
                       else
                       {
                          occurence = 0;  // flag to call PrepareTransmit again
                          bMBFlags1 |= (1<<iMB);       // set flag to caller indicating this MB is done by ISR
                       }
                       // clear flag
                       pFlexCANReg->IFLAG1 = (1<<iMB);
                                              
                       // Call custom Tx callback to do follow up processing
                       // such as queue another message to be transmitted
                       FlexCAN_MB_Callback(iMB);
              }	
      }  
}
  
  
void    FlexCAN_Poll_RxFIFO(void)
{
    uint16  iMatchHit;
    
          if(pFlexCANReg->IFLAG1 & FLEXCAN_IFLAG1_BUF5I)
           {
              // frames are available in Rx FIFO, read it into RxFIFO queue
               if((wrRxFIFOQue+1) != rdRxFIFOQue)
               {
                 RxFIFOQue[wrRxFIFOQue].data_len = 
                    FlexCAN_ReadCANMB(0, // MB0 is the read buffer of RxFIFO 
                                      (uint32*)&RxFIFOQue[wrRxFIFOQue].identifier, 
                                      (uint32*)&RxFIFOQue[wrRxFIFOQue].timestamp, 
                                      (uint8*)RxFIFOQue[wrRxFIFOQue].data,
                                       0);
                 // read RXFIR
		 iMatchHit = pFlexCANReg->RXFIR & 0x1FF;
                 
                 wrRxFIFOQue++;
                 if(wrRxFIFOQue >=MAX_RXFIFO_MAILS)
                 {
                   wrRxFIFOQue = 0;
                 }
               }              
              // clear Rx FIFO flag
              pFlexCANReg->IFLAG1 = FLEXCAN_IFLAG1_BUF5I;
           }
           // Check Rx FIFO Warning flag
           if(pFlexCANReg->IFLAG1 & FLEXCAN_IFLAG1_BUF6I)
           {
              pFlexCANReg->IFLAG1 = FLEXCAN_IFLAG1_BUF6I;
           }
           // Check Rx FIFO Overflow flag
           if(pFlexCANReg->IFLAG1 & FLEXCAN_IFLAG1_BUF7I)
           {
              // This should be error
              nCANErrorCount++;
              
              pFlexCANReg->IFLAG1 = FLEXCAN_IFLAG1_BUF7I;
              
              // Call RxFIFO error call back
              FlexCAN_RxFIFOErr_Callback();
           } 
}



void	FlexCAN_BusOff_ISR(void)
{
       pFlexCANReg->ESR1 = FLEXCAN_ESR_BOFF_INT;  
}

void	FlexCAN_Error_ISR(void)
{
	// check error flags
	uint32_t status;
	
	status = pFlexCANReg->ESR1;
	
	if( status  & FLEXCAN_ESR_ERR_INT)
	{
		nCANErrorCount++;
                
                // Call CAN error call back                		
		FlexCAN_Err_Callback(status);
                
		// clear the error flag
		pFlexCANReg->ESR1 = status;		
	}	
}

void	FlexCAN_TxWarning_ISR(void)
{
      pFlexCANReg->ESR1 = FLEXCAN_ESR_TX_WRN;  
      //printf("FlexCAN Transmit warning occured!\n");
}

void	FlexCAN_RxWarning_ISR(void)
{
      pFlexCANReg->ESR1 = FLEXCAN_ESR_RX_WRN;  
      //printf("FlexCAN Receive warning occured!\n");  
}

void	FlexCAN_Wakeup_ISR(void)
{

      pFlexCANReg->ESR1 = FLEXCAN_ESR_WAK_INT;	// clear wakeup interrupt
      //printf("FlexCAN wakeup interrupt occurs!\n");
}

void	FlexCAN_IMEU_ISR(void)
{
    pFlexCANReg->ESR2 = FLEXCAN_ESR2_IMEUF; 
}


void	FlexCAN_LostRx_ISR(void)
{
    if( pFlexCANReg->ESR2  & FLEXCAN_ESR2_LOSTRLF)
    {
        // Lost Rx is locked 
        pFlexCANReg->ESR2 = FLEXCAN_ESR2_LOSTRLF;
    }
    if( pFlexCANReg->ESR2  & FLEXCAN_ESR2_LOSTRMF)
    {
        // Lost Rx is matched
        pFlexCANReg->ESR2 = FLEXCAN_ESR2_LOSTRMF;      
    }    
    //printf("FlexCAN Lost receive interrupt occurs!\n");  
}


uint16 FlexCAN_CheckAbortStatus(uint16 iMB)
{
  uint8 code;
  // If it is still pending, just return pending status
  if(!(pFlexCANReg->IFLAG1 & (1<<iMB)))
  {
      return (FLEXCAN_ERROR_PENDING_TX);
  }
  // Check CODE field to see if it is aborted or not
  code = FLEXCAN_get_code(pFlexCANReg->MB[iMB].CS);
  if(code == FLEXCAN_MB_CODE_TX_ABORT)
  {
    // Abort success
    return (FLEXCAN_ERROR_SUCCESS);
  }
  else if(code == FLEXCAN_MB_CODE_TX_INACTIVE )
  {
      // MB is not aborted but transmitted instead
      return (FLEXCAN_ERROR_TX_DONE);
  }
  // Other status
  return (FLEXCAN_ERROR_TX_ERR);
}


// Callback routines
void    FlexCAN_MB_Callback(uint16 iMBNo)
{
}

void    FlexCAN_RxFIFOErr_Callback(void)
{
}

void    FlexCAN_Err_Callback(uint32 status)
{
        if(status & FLEXCAN_ESR_BIT0_ERR)
        {
                printf("BIT0 error occured!\n");
        }	
        if(status & FLEXCAN_ESR_BIT1_ERR)
        {
                printf("BIT1 error occured!\n");
        }
        if(status & FLEXCAN_ESR_STF_ERR)
        {
                printf("Stuffing error occured!\n");
        }
        if(status & FLEXCAN_ESR_FRM_ERR)
        {
                printf("Form error occured!\n");
        }
        if(status & FLEXCAN_ESR_CRC_ERR)
        {
                printf("CRC error occured!\n");
        }
        if(status & FLEXCAN_ESR_ACK_ERR)
        {
                printf("Ack error occured!\n");
        }
}

