#ifndef	__CAN_CONFIG_H
#define __CAN_CONFIG_H

/*=================================================================================================================*/
// Definition of FlexCAN control bits
#define FLEXCAN_CLOCK_SOURCE      1       /* clock source for FlexCAN: 0 -- external oscillator, 1 -- bus clock from PLL */
#define FLEXCAN_SELF_RECEPTION    0       /* enable self-reception: 0 - disable self-reception; 1 -- enable self-reception */
#define FLEXCAN_SCAN_PRIORITY     0       /* scan prio: 0 -- RxFIFO first, 1 -- MB first */ 
#define FLEXCAN_STORE_RTR         0       /* remote request storing: 0 -- do not store RTR, 1 -- store RTR as data frame */
#define FLEXCAN_ENTIRE_ARB_CMP    1       /* entire frame arbitration filed comparision including IDE,RTR, excluding RxFIFO 
                                           * 0 -- always compare ID of Rx MB regardless of masks, but not compare RTR
                                           * 1 -- mask compare both Rx MB ID and RTR
                                           */    
#define FLEXCAN_INDIVIDUAL_MASK   0       /* individual Rx Masking and queue enable:
                                           * 0 -- message queue is enabled, and masking with RXMGMASK/RX14MASK/RX15MASK,RXFGMASK
                                           * 1 -- message queue is disabled, and individual masking with RXIMRn
                                           */
 
#define FLEXCAN_LOCAL_PRIO        0       /* local priority enable: 0 -- disabled, 1 -- enabled */
#define FLEXCAN_LOOP_BACK         0       /* loop back for single node: 0 -- no loopback, 1 -- loopback */
/* NOTE: if use LOOPBACK, self-reception must be enabled by defining
 * #define FLEXCAN_SELF_RECEPTION  1
 */

#define FLEXCAN_NO_RXFIFO_FILTERS 0//8       /* # of Rx FIFO filters: 0 -- Rx FIFO disabled, or 8/16/24/32/40 */
#define FLEXCAN_ID_TAB_FORMAT     0       /* Rx FIFO ID table format: 0 -- Format A, 1 -- Format B, 2 -- Format C, 3 -- Format D */

// Configuration of MBs
#define NUMBER_OF_RX_MB		12		/* # of Receive MBs, can be changed per application */
#define NUMBER_OF_TX_MB		(NUMBER_OF_MB-NUMBER_OF_RX_MB)	/* # of MBs are  for Transmit MBs */

// Definition of Receive MBs index 
#define	FLEXCAN_RX_MB_START	8 //0                           /* start # of Rx MB */
#define	FLEXCAN_RX_MB_END	8 //(NUMBER_OF_RX_MB-1)         /* end # of Rx MB */

// Definition of Transmit MBs index
#define FLEXCAN_TX_MB_START	9 //(FLEXCAN_RX_MB_END+1)
#define	FLEXCAN_TX_MB_END	(NUMBER_OF_MB-1)

// Definition of max # of custom mails
#define MAX_RX_MAILS	  20
#define MAX_TX_MAILS      20
#define MAX_RXFIFO_MAILS  10
/*=====================================================================================================================*/

// Define Acceptance IDs for ID filter table
#if (FLEXCAN_NO_RXFIFO_FILTERS > 0)

  #define ID_TABLE0_ID      (1 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE1_ID      (2 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE2_ID      (3 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE3_ID      (4 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE4_ID      (5 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE5_ID      (6 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE6_ID      (7 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE7_ID      (8 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */

#endif

#if (FLEXCAN_NO_RXFIFO_FILTERS > 8)

  #define ID_TABLE8_ID      (9 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE9_ID      (10 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE10_ID     (11 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE11_ID     (12 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE12_ID     (13 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE13_ID     (14 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE14_ID     (15 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE15_ID     (16 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
#endif

#if (FLEXCAN_NO_RXFIFO_FILTERS > 16)

  #define ID_TABLE16_ID      (17 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE17_ID      (18 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE18_ID     (19 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE19_ID     (20 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE20_ID     (21 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE21_ID     (22 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE22_ID     (23 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE23_ID     (24 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
#endif

#if (FLEXCAN_NO_RXFIFO_FILTERS >24 )

  #define ID_TABLE24_ID     (25 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE25_ID     (26 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE26_ID     (27 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE27_ID     (28 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE28_ID     (29 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE29_ID     (30 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE30_ID     (31 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE31_ID     (32 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
#endif

#if (FLEXCAN_NO_RXFIFO_FILTERS >32 )

  #define ID_TABLE8_ID      (33 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE9_ID      (34 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE10_ID     (35 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE11_ID     (36 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE12_ID     (37 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE13_ID     (38 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE14_ID     (39 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
  #define ID_TABLE15_ID     (40 | CAN_MSG_IDE_MASK)       /* if the ID is in standard format, remove CAN_MSG_IDE_MASK */
#endif


//========================= DONT touch below ==========================================//
#if ((FLEXCAN_LOOP_BACK) ^ (FLEXCAN_SELF_RECEPTION))
  #error  "FLEXCAN_LOOP_BACK must be same as FLEXCAN_SELF_RECEPTION\r\n"
#endif

// Check limit of # of Rx FIFO Filters
#if ((FLEXCAN_NO_RXFIFO_FILTERS != 0) && (FLEXCAN_NO_RXFIFO_FILTERS != 8) && (FLEXCAN_NO_RXFIFO_FILTERS != 16) && (FLEXCAN_NO_RXFIFO_FILTERS != 24) && (FLEXCAN_NO_RXFIFO_FILTERS != 32)&& (FLEXCAN_NO_RXFIFO_FILTERS != 40))
  #error  "FLEXCAN_NO_RXFIFO_FILTERS is out of range!\r\n"
#endif

// Check MB # to see if it is out of range when Rx FIFO is enabled
#if ((FLEXCAN_NO_RXFIFO_FILTERS>0))
  #if (FLEXCAN_RX_MB_START < 8)
    #error  "FLEXCAN_RX_MB_START must be > 7 when Rx FIFO is enabled depending on FLEXCAN_NO_RXFIFO_FILTERS !\r\n"
  #endif
  #if (FLEXCAN_TX_MB_START < 8)
  #error  "FLEXCAN_TX_MB_START must be > 7 when Rx FIFO is enabled depending on FLEXCAN_NO_RXFIFO_FILTERS!\r\n"
  #endif
#endif


#endif