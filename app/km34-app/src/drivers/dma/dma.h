/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      dma.h
 * @version   1.0.4.0
 * @date      Apr-21-2015
 * @brief     Direct Memory Access (DMA) driver header file.
 ******************************************************************************/
#ifndef __DMA_H
#define __DMA_H

#if !defined(MCU_MKM34ZA5)
  #error "The dma.h module is specific to the MKMxxZxxACxx5 microcontrollers."
#endif

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint32 CHCFG, SAR, DAR, DSR, DCR; } tDMA_CH;

/**************************************************************************//*!
*//*! @addtogroup dma0_request_sources
* @{
 *****************************************************************************/
#define DMA0_REQ_DISABLED (uint8)0x00   ///< Channel disabled (default)
#define DMA0_REQ_SPI0_TX  (uint8)0x01   ///< SPI0 TX
#define DMA0_REQ_SPI0_RX  (uint8)0x02   ///< SPI0 RX
#define DMA0_REQ_UART0_TX (uint8)0x03   ///< UART0 TX
#define DMA0_REQ_UART0_RX (uint8)0x04   ///< UART0 RX
#define DMA0_REQ_I2C0     (uint8)0x05   ///< I2C0
#define DMA0_REQ_XBAR     (uint8)0x06   ///< XBAR
#define DMA0_REQ_UART3_TX (uint8)0x07   ///< UART3 TX
#define DMA0_REQ_UART3_RX (uint8)0x08   ///< UART3 RX
#define DMA0_REQ_AFE_CH0  (uint8)0x09   ///< AFE CH0
#define DMA0_REQ_TMR_0    (uint8)0x0a   ///< TMR 0
#define DMA0_REQ_TMR_3    (uint8)0x0b   ///< TMR 3
#define DMA0_REQ_AFE_CH2  (uint8)0x0c   ///< AFE CH2
#define DMA0_REQ_ADC      (uint8)0x0d   ///< ADC
#define DMA0_REQ_CMP0     (uint8)0x0e   ///< CMP0
#define DMA0_REQ_PTE      (uint8)0x0f   ///< PTE
#define DMA0_REQ_PTA      (uint8)0x10   ///< PTA
#define DMA0_REQ_ENABLED  (uint8)0x11   ///< Always enabled
/*! @} End of dma0_request_sources                                           */

/**************************************************************************//*!
*//*! @addtogroup dma1_request_sources
* @{
 *****************************************************************************/
#define DMA1_REQ_DISABLED (uint8)0x00   ///< Channel disabled (default)
#define DMA1_REQ_SPI0_TX  (uint8)0x01   ///< SPI0 TX
#define DMA1_REQ_SPI0_RX  (uint8)0x02   ///< SPI0 RX
#define DMA1_REQ_UART1_TX (uint8)0x03   ///< UART1 TX
#define DMA1_REQ_UART1_RX (uint8)0x04   ///< UART1 RX
#define DMA1_REQ_I2C0     (uint8)0x05   ///< I2C0
#define DMA1_REQ_XBAR     (uint8)0x06   ///< XBAR
#define DMA1_REQ_UART3_TX (uint8)0x07   ///< UART3 TX
#define DMA1_REQ_UART3_RX (uint8)0x08   ///< UART3 RX
#define DMA1_REQ_AFE_CH0  (uint8)0x09   ///< AFE CH0
#define DMA1_REQ_TMR_0    (uint8)0x0a   ///< TMR 0
#define DMA1_REQ_TMR_3    (uint8)0x0b   ///< TMR 3
#define DMA1_REQ_AFE_CH2  (uint8)0x0c   ///< AFE CH2
#define DMA1_REQ_PTE      (uint8)0x0d   ///< PTE
#define DMA1_REQ_CMP0     (uint8)0x0e   ///< CMP0
#define DMA1_REQ_PTF      (uint8)0x0f   ///< PTF
#define DMA1_REQ_PTB      (uint8)0x10   ///< PTB
#define DMA1_REQ_ENABLED  (uint8)0x11   ///< Always enabled
/*! @} End of dma1_request_sources                                           */

/**************************************************************************//*!
*//*! @addtogroup dma2_request_sources
* @{
 *****************************************************************************/
#define DMA2_REQ_DISABLED (uint8)0x00   ///< Channel disabled (default)
#define DMA2_REQ_SPI1_TX  (uint8)0x01   ///< SPI1 TX
#define DMA2_REQ_SPI1_RX  (uint8)0x02   ///< SPI1 RX
#define DMA2_REQ_UART1_TX (uint8)0x03   ///< UART1 TX
#define DMA2_REQ_UART1_RX (uint8)0x04   ///< UART1 RX
#define DMA2_REQ_I2C1     (uint8)0x05   ///< I2C1
#define DMA2_REQ_XBAR     (uint8)0x06   ///< XBAR
#define DMA2_REQ_UART2_TX (uint8)0x07   ///< UART2 TX
#define DMA2_REQ_UART2_RX (uint8)0x08   ///< UART2 RX
#define DMA2_REQ_AFE_CH1  (uint8)0x09   ///< AFE CH1
#define DMA2_REQ_TMR_2    (uint8)0x0a   ///< TMR 2
#define DMA2_REQ_TMR_1    (uint8)0x0b   ///< TMR 1
#define DMA2_REQ_AFE_CH3  (uint8)0x0c   ///< AFE CH3
#define DMA2_REQ_PTI      (uint8)0x0d   ///< PTI
#define DMA2_REQ_CMP1     (uint8)0x0e   ///< CMP1
#define DMA2_REQ_PTG      (uint8)0x0f   ///< PTG
#define DMA2_REQ_PTC      (uint8)0x10   ///< PTC
#define DMA2_REQ_ENABLED  (uint8)0x11   ///< Always enabled
/*! @} End of dma2_request_sources                                           */

/**************************************************************************//*!
*//*! @addtogroup dma3_request_sources
* @{
 *****************************************************************************/
#define DMA3_REQ_DISABLED (uint8)0x00   ///< Channel disabled (default)
#define DMA3_REQ_SPI1_TX  (uint8)0x01   ///< SPI1 TX
#define DMA3_REQ_SPI1_RX  (uint8)0x02   ///< SPI1 RX
#define DMA3_REQ_UART0_TX (uint8)0x03   ///< UART0 TX
#define DMA3_REQ_UART0_RX (uint8)0x04   ///< UART0 RX
#define DMA3_REQ_I2C1     (uint8)0x05   ///< I2C1
#define DMA3_REQ_XBAR     (uint8)0x06   ///< XBAR
#define DMA3_REQ_UART2_TX (uint8)0x07   ///< UART2 TX
#define DMA3_REQ_UART2_RX (uint8)0x08   ///< UART2 RX
#define DMA3_REQ_AFE_CH1  (uint8)0x09   ///< AFE CH1
#define DMA3_REQ_TMR_2    (uint8)0x0a   ///< TMR 2
#define DMA3_REQ_TMR_1    (uint8)0x0b   ///< TMR 1
#define DMA3_REQ_AFE_CH3  (uint8)0x0c   ///< AFE CH3
#define DMA3_REQ_ADC      (uint8)0x0d   ///< ADC
#define DMA3_REQ_CMP1     (uint8)0x0e   ///< CMP1
#define DMA3_REQ_PTH      (uint8)0x0f   ///< PTH
#define DMA3_REQ_PTD      (uint8)0x10   ///< PTD
#define DMA3_REQ_ENABLED  (uint8)0x11   ///< Always enabled
/*! @} End of dma3_request_sources                                           */

/**************************************************************************//*!
*//*! @addtogroup dma_request_sizes
* @{
* @details Determines the data size for the DMA controller transfers.
 *****************************************************************************/
#define DMA_SIZE32BIT       (uint8)0   ///< 4-byte transfer (default)
#define DMA_SIZE8BIT        (uint8)1   ///< 1-byte transfer
#define DMA_SIZE16BIT       (uint8)2   ///< 2-byte transfer
/*! @} End of dma_request_sizes                                               */

/***************************************************************************//*!
 *//*! @addtogroup dma_chacr_attr
 * @{
 ******************************************************************************/
#define DMA_CHACR_RW_RW_RW  (uint8)0  ///< User nonsecure=Read/Write, User secure=Read/Write, Privileged secure=Read/Write (default)
#define DMA_CHACR_NO_RW_RW  (uint8)1  ///< User nonsecure=None, User secure=Read/Write, Privileged secure=Read/Write
#define DMA_CHACR_NO_NO_RW  (uint8)2  ///< User nonsecure=None, User secure=None, Privileged secure=Read/Write
/*! @} End of dma_chacr_attr                                                  */

/***************************************************************************//*!
 *//*! @addtogroup dma_umnsm_attr
 * @{
 ******************************************************************************/
#define DMA_UMNSM_EN_PRIV_OR_USER_SECURE_OR_NONSEC  (uint8)0  ///< Enable privileged or user, secure or nonsecure (default).
#define DMA_UMNSM_FR_PRIV_SECURE                    (uint8)1  ///< Forced to privileged secure.
#define DMA_UMNSM_FR_USER_SECURE                    (uint8)2  ///< Forced to user secure.
#define DMA_UMNSM_FR_USER_UNSEC                     (uint8)3  ///< Forced to user unsecure.
/*! @} End of dma_umnsm_attr                                                  */

/******************************************************************************
* DMA default configurations used by DMA_Init() function
*
*//*! @addtogroup dma_chan_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Selects and starts software triggered continuous memory to memory data
 * transfer.
 * @details Configures and starts DMA channel to operate in software trigger
 * continuous memory to memory data transfer.
 * @param   srcaddr   Source memory buffer address (uint32).
 * @param   dstaddr   Destination memory buffer address (uint32).
 * @param   nbytes    Bytes count to be transferred in range 0x000001 to 0x0FFFFF.
 * @note              Implemented as an inline macro.
 * @showinitializer
 ******************************************************************************/
#define DMA_CH_SWTRG_M2M_CN_CONFIG(srcaddr,dstaddr,nbytes)                    \
(tDMA_CH){                                                                    \
/* CHCFG */  CLR(DMAMUX_CHCFG_ENBL_MASK)|CLR(DMAMUX_CHCFG_TRIG_MASK)|         \
/* ..... */  SET(DMAMUX_CHCFG_SOURCE(0)), /* DMA_REQ_DISABLED */              \
/* SAR   */  (uint32)srcaddr,                                                 \
/* DAR   */  (uint32)dstaddr,                                                 \
/* DSR   */  CLR(DMA_DSR_BCR_DONE_MASK)|((uint32)nbytes&0x0FFFFF),            \
/* DCR   */  CLR(DMA_DCR_EINT_MASK)|CLR(DMA_DCR_ERQ_MASK)|                    \
/* ...   */  CLR(DMA_DCR_CS_MASK)|CLR(DMA_DCR_AA_MASK)|CLR(DMA_DCR_CHACR(0))| \
/* ...   */  CLR(DMA_DCR_UMNSM(0))|CLR(DMA_DCR_EADREQ_MASK)|                  \
/* ...   */  SET(DMA_DCR_SINC_MASK)|SET(DMA_DCR_SSIZE(DMA_SIZE8BIT))|         \
/* ...   */  SET(DMA_DCR_DINC_MASK)|SET(DMA_DCR_DSIZE(DMA_SIZE8BIT))|         \
/* ...   */  SET(DMA_DCR_START_MASK)|SET(DMA_DCR_SMOD(0))|                    \
/* ...   */  SET(DMA_DCR_DMOD(0))|CLR(DMA_DCR_D_REQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_LINKCC(0))|SET(DMA_DCR_LCH1(0))|SET(DMA_DCR_LCH2(0)) \
}

/***************************************************************************//*!
 * @brief Selects software initiated continuous memory to peripheral data transfer.
 * @details Configures software initiated continuous memory to peripheral data
 * transfer.
 * @param   srcaddr   Source memory buffer address (uint32-regsize aligned)
 * @param   regsize   Select @ref dma_request_sizes.
 * @param   regaddr   Destination peripheral register address (uint32).
 * @param   nbytes    Bytes count to be transferred in range 0x000001 to 0x0FFFFF.
 * @note              Implemented as an inline macro.
 * @showinitializer
 ******************************************************************************/
#define DMA_CH_SWTRG_M2P_CN_CONFIG(srcaddr,regsize,regaddr,nbytes)            \
(tDMA_CH){                                                                    \
/* CHCFG */  CLR(DMAMUX_CHCFG_ENBL_MASK)|CLR(DMAMUX_CHCFG_TRIG_MASK)|         \
/* ..... */  SET(DMAMUX_CHCFG_SOURCE(0)), /* DMA_REQ_DISABLED */              \
/* SAR   */  (uint32)srcaddr,                                                 \
/* DAR   */  (uint32)regaddr,                                                 \
/* DSR   */  CLR(DMA_DSR_BCR_DONE_MASK)|((uint32)nbytes&0x0FFFFF),            \
/* DCR   */  CLR(DMA_DCR_EINT_MASK)|CLR(DMA_DCR_ERQ_MASK)|                    \
/* ...   */  CLR(DMA_DCR_CS_MASK)|CLR(DMA_DCR_AA_MASK)|CLR(DMA_DCR_CHACR(0))| \
/* ...   */  CLR(DMA_DCR_UMNSM(0))|CLR(DMA_DCR_EADREQ_MASK)|                  \
/* ...   */  SET(DMA_DCR_SINC_MASK)|SET(DMA_DCR_SSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_DINC_MASK)|SET(DMA_DCR_DSIZE(regsize))|              \
/* ...   */  SET(DMA_DCR_START_MASK)|SET(DMA_DCR_SMOD(0))|                    \
/* ...   */  SET(DMA_DCR_DMOD(0))|CLR(DMA_DCR_D_REQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_LINKCC(0))|SET(DMA_DCR_LCH1(0))|SET(DMA_DCR_LCH2(0)) \
}

/***************************************************************************//*!
 * @brief Selects hardware initiated cycle steal peripheral to memory data
 * transfer.
 * @details Configures hardware initiated cycle steal peripheral to memory data
 * transfer.
 * @param   reqsrc    Request source chosen for DMA channel being configured:\n
 *                    DMA0=@ref dma0_request_sources\n
 *                    DMA1=@ref dma1_request_sources\n
 *                    DMA2=@ref dma2_request_sources\n
 *                    DMA3=@ref dma3_request_sources.
 * @param   regsize   Select @ref dma_request_sizes.
 * @param   regaddr   Peripheral register address (uint32).
 * @param   dstaddr   Destination memory buffer address (uint32-regsize aligned).
 * @param   nbytes    Bytes count to be transferred in range 0x000001 to 0x0FFFFF.
 * @note              Implemented as an inline macro.
 * @showinitializer
 ******************************************************************************/
#define DMA_CH_HWTRG_P2M_CS_CONFIG(reqsrc,regsize,regaddr,dstaddr,nbytes)     \
(tDMA_CH){                                                                    \
/* CHCFG */  SET(DMAMUX_CHCFG_ENBL_MASK)|CLR(DMAMUX_CHCFG_TRIG_MASK)|         \
/* ..... */  SET(DMAMUX_CHCFG_SOURCE(reqsrc)),                                \
/* SAR   */  (uint32)regaddr,                                                 \
/* DAR   */  (uint32)dstaddr,                                                 \
/* DSR   */  CLR(DMA_DSR_BCR_DONE_MASK)|((uint32)nbytes&0x0FFFFF),            \
/* DCR   */  CLR(DMA_DCR_EINT_MASK)|SET(DMA_DCR_ERQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_CS_MASK)|CLR(DMA_DCR_AA_MASK)|CLR(DMA_DCR_CHACR(0))| \
/* ...   */  CLR(DMA_DCR_UMNSM(0))|SET(DMA_DCR_EADREQ_MASK)|                  \
/* ...   */  CLR(DMA_DCR_SINC_MASK)|SET(DMA_DCR_SSIZE(regsize))|              \
/* ...   */  SET(DMA_DCR_DINC_MASK)|SET(DMA_DCR_DSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_START_MASK)|SET(DMA_DCR_SMOD(0))|                    \
/* ...   */  SET(DMA_DCR_DMOD(0))|SET(DMA_DCR_D_REQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_LINKCC(0))|SET(DMA_DCR_LCH1(0))|SET(DMA_DCR_LCH2(0)) \
}

/***************************************************************************//*!
 * @brief Selects hardware initiated cycle steal memory to peripheral data
 * transfer.
 * @details Configures hardware initiated cycle steal memory to peripheral data
 * transfer.
 * @param   reqsrc    Request source chosen for DMA channel being configured:\n
 *                    DMA0=@ref dma0_request_sources\n
 *                    DMA1=@ref dma1_request_sources\n
 *                    DMA2=@ref dma2_request_sources\n
 *                    DMA3=@ref dma3_request_sources.
 * @param   srcaddr   Source memory buffer address (uint32-regsize aligned)
 * @param   regsize   Select @ref dma_request_sizes.
 * @param   regaddr   Destination peripheral register address (uint32).
 * @param   nbytes    Bytes count to be transferred in range 0x000001 to 0x0FFFFF.
 * @note              Implemented as an inline macro.
 * @showinitializer
 ******************************************************************************/
#define DMA_CH_HWTRG_M2P_CS_CONFIG(reqsrc,srcaddr,regsize,regaddr,nbytes)     \
(tDMA_CH){                                                                    \
/* CHCFG */  SET(DMAMUX_CHCFG_ENBL_MASK)|CLR(DMAMUX_CHCFG_TRIG_MASK)|         \
/* ..... */  SET(DMAMUX_CHCFG_SOURCE(reqsrc)),                                \
/* SAR   */  (uint32)srcaddr,                                                 \
/* DAR   */  (uint32)regaddr,                                                 \
/* DSR   */  CLR(DMA_DSR_BCR_DONE_MASK)|((uint32)nbytes&0x0FFFFF),            \
/* DCR   */  CLR(DMA_DCR_EINT_MASK)|SET(DMA_DCR_ERQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_CS_MASK)|CLR(DMA_DCR_AA_MASK)|CLR(DMA_DCR_CHACR(0))| \
/* ...   */  CLR(DMA_DCR_UMNSM(0))|SET(DMA_DCR_EADREQ_MASK)|                  \
/* ...   */  SET(DMA_DCR_SINC_MASK)|SET(DMA_DCR_SSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_DINC_MASK)|SET(DMA_DCR_DSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_START_MASK)|SET(DMA_DCR_SMOD(0))|                    \
/* ...   */  SET(DMA_DCR_DMOD(0))|SET(DMA_DCR_D_REQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_LINKCC(0))|SET(DMA_DCR_LCH1(0))|SET(DMA_DCR_LCH2(0)) \
}

/***************************************************************************//*!
 * @brief Selects hardware initiated cycle steal peripheral to peripheral data
 * transfer executed in a loop.
 * @details Configures hardware initiated cycle steal peripheral to peripheral
 * data transfer executed in a loop.
 * @param   reqsrc    Request source chosen for DMA channel being configured:\n
 *                    DMA0=@ref dma0_request_sources\n
 *                    DMA1=@ref dma1_request_sources\n
 *                    DMA2=@ref dma2_request_sources\n
 *                    DMA3=@ref dma3_request_sources.
 * @param   regsize   Select @ref dma_request_sizes.
 * @param   reg1addr  Source peripheral register address (uint32).
 * @param   reg2addr  Destination peripheral register address (uint32).
 * @note              Implemented as an inline macro.
 * @showinitializer
 ******************************************************************************/
#define DMA_CH_HWTRG_P2P_CS_LOOP_CONFIG(reqsrc,regsize,reg1addr,reg2addr)     \
(tDMA_CH){                                                                    \
/* CHCFG */  SET(DMAMUX_CHCFG_ENBL_MASK)|CLR(DMAMUX_CHCFG_TRIG_MASK)|         \
/* ..... */  SET(DMAMUX_CHCFG_SOURCE(reqsrc)),                                \
/* SAR   */  (uint32)reg1addr,                                                \
/* DAR   */  (uint32)reg2addr,                                                \
/* DSR   */  CLR(DMA_DSR_BCR_DONE_MASK)|((uint32)regsize&0x0FFFFF),           \
/* DCR   */  CLR(DMA_DCR_EINT_MASK)|SET(DMA_DCR_ERQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_CS_MASK)|CLR(DMA_DCR_AA_MASK)|CLR(DMA_DCR_CHACR(0))| \
/* ...   */  CLR(DMA_DCR_UMNSM(0))|SET(DMA_DCR_EADREQ_MASK)|                  \
/* ...   */  CLR(DMA_DCR_SINC_MASK)|SET(DMA_DCR_SSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_DINC_MASK)|SET(DMA_DCR_DSIZE(regsize))|              \
/* ...   */  CLR(DMA_DCR_START_MASK)|SET(DMA_DCR_SMOD(0))|                    \
/* ...   */  SET(DMA_DCR_DMOD(0))|SET(DMA_DCR_D_REQ_MASK)|                    \
/* ...   */  SET(DMA_DCR_LINKCC(0))|SET(DMA_DCR_LCH1(0))|SET(DMA_DCR_LCH2(0)) \
}
/*! @} End of dma_chan_config                                                 */

/******************************************************************************
* DMA callback registered by DMA_Init() function
*
*//*! @addtogroup dma_ch_callback
* @{
*******************************************************************************/
/*! DMA_CH_CALLBACK type declaration                                          */
typedef enum
{
  CE_CALLBACK   =1,   ///< Configuration error (CE) interrupt
  DONE_CALLBACK =2,   ///< Transactions done (DONE) interrupt
} DMA_CH_CALLBACK_TYPE;

/*! @brief DMA_CH_CALLBACK function declaration                               */
typedef void (*DMA_CH_CALLBACK)(DMA_CH_CALLBACK_TYPE type);
/*! @} End of dma_ch_callback                                                 */

/******************************************************************************
* DMA function and macro definitions
*
*//*! @addtogroup dma_macro
* @{
*******************************************************************************/
#define DMA0_Ack              DMA_DSR_BCR0=DMA_DSR_BCR0
#define DMA1_Ack              DMA_DSR_BCR1=DMA_DSR_BCR1
#define DMA2_Ack              DMA_DSR_BCR2=DMA_DSR_BCR2
#define DMA3_Ack              DMA_DSR_BCR3=DMA_DSR_BCR3
/***************************************************************************//*!
 * @brief   DMA channel transfer complete acknowledge.
 * @details This macro acknowledges completed DMA channel transfer.
 * @param   ch     DMA0,DMA1,DMA2,DMA3.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define DMA_Ack(ch)           ch##_Ack

#define DMA0_IsCfgError       (DMA_DSR_BCR0&DMA_DSR_BCR_CE_MASK)
#define DMA1_IsCfgError       (DMA_DSR_BCR1&DMA_DSR_BCR_CE_MASK)
#define DMA2_IsCfgError       (DMA_DSR_BCR2&DMA_DSR_BCR_CE_MASK)
#define DMA3_IsCfgError       (DMA_DSR_BCR3&DMA_DSR_BCR_CE_MASK)
/***************************************************************************//*!
 * @brief   DMA channel configuration error check.
 * @details This macro checks DMA channel for configuration error.
 * @param   ch     DMA0,DMA1,DMA2,DMA3.
 * @return  true (non-zero) channel configuration error occurred (call @ref DMA_Ack
 *                          to clear error condition),
 * @return  false           no configuration error exists.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define DMA_IsCfgError(ch)    ch##_IsCfgError

#define DMA0_IsRdError        (DMA_DSR_BCR0&DMA_DSR_BCR_BES_MASK)
#define DMA1_IsRdError        (DMA_DSR_BCR1&DMA_DSR_BCR_BES_MASK)
#define DMA2_IsRdError        (DMA_DSR_BCR2&DMA_DSR_BCR_BES_MASK)
#define DMA3_IsRdError        (DMA_DSR_BCR3&DMA_DSR_BCR_BES_MASK)
/***************************************************************************//*!
 * @brief   DMA channel bus error occurred during the read portion of a transfer.
 * @details This macro checks DMA channel for bus error during the read portion
 *          of a transfer.
 * @param   ch     DMA0,DMA1,DMA2,DMA3.
 * @return  true (non-zero) bus error occurred during the read (call
 *                          @ref DMA_Ack to clear error condition),
 * @return  false           no bus error occurred.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define DMA_IsRdError(ch)     ch##_IsRdError

#define DMA0_IsWrError        (DMA_DSR_BCR0&DMA_DSR_BCR_BED_MASK)
#define DMA1_IsWrError        (DMA_DSR_BCR1&DMA_DSR_BCR_BED_MASK)
#define DMA2_IsWrError        (DMA_DSR_BCR2&DMA_DSR_BCR_BED_MASK)
#define DMA3_IsWrError        (DMA_DSR_BCR3&DMA_DSR_BCR_BED_MASK)
/***************************************************************************//*!
 * @brief   DMA channel bus error occurred during the write portion of a transfer.
 * @details This macro checks DMA channel for bus error during the write portion
 *          of a transfer.
 * @param   ch    DMA0,DMA1,DMA2,DMA3.
 * @return  true (non-zero) bus error occurred during the write (call
 *                          @ref DMA_Ack to clear error condition),
 * @return  false           no bus error occurred.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define DMA_IsWrError(ch)     ch##_IsWrError

#define DMA0_IsDone           (DMA_DSR_BCR0&DMA_DSR_BCR_DONE_MASK)
#define DMA1_IsDone           (DMA_DSR_BCR1&DMA_DSR_BCR_DONE_MASK)
#define DMA2_IsDone           (DMA_DSR_BCR2&DMA_DSR_BCR_DONE_MASK)
#define DMA3_IsDone           (DMA_DSR_BCR3&DMA_DSR_BCR_DONE_MASK)
/***************************************************************************//*!
 * @brief   DMA channel transfer complete check.
 * @details This macro checks DMA channel transfer complete.
 * @param   ch    DMA0,DMA1,DMA2,DMA3.
 * @return  true (non-zero) channel DMA transfer completed call @ref DMA_Ack
 *                          to acknowledge the DMA transfer),
 * @return  false           DMA channel transfer is not yet complete.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define DMA_IsDone(ch)        ch##_IsDone

/***************************************************************************//*!
 * @brief   Installs callback function for specified DMA channel.
 * @details This function installs callback function for specified DMA channel.
 * @param   ch        DMA0,DMA1,DMA2,DMA3.
 * @param   ip        Select one of the @ref cm0plus_prilvl.
 * @param   callback  Pointer to the @ref dma_ch_callback.
 * @note    Implemented as a function call.
 * @see     @ref DMA_Init, @ref DMA_AdvInit
 ******************************************************************************/
#define DMA_InstallCallback(ch,ip,callback)                                 \
                              DMA_InstallCallback##ch(ip,callback)

/***************************************************************************//*!
 * @brief   DMA channel initialization.
 * @details This function initializes specified DMA channel for data transfer.
 * @param   ch        DMA0,DMA1,DMA2,DMA3.
 * @param   dma       Structure containing the initialization parameters
 *                    @ref dma_chan_config
 * @note    Implemented as a function call.
 * @see     @ref DMA_AdvInit, @ref DMA_InstallCallback
 ******************************************************************************/
#define DMA_Init(ch,dma)      ch##_Init(dma)

/***************************************************************************//*!
 * @brief   Advanced DMA channel initialization with access rights setting.
 * @details This function initializes specified DMA channel for data transfer.
 * It also sets the access control attributes needed to reference the channel's
 * transfer channel descriptor (TCDn) and defines the privileged/user and
 * secure/nonsecure attributes for the DMA channel as it executes.
 * @param   ch      DMA0,DMA1,DMA2,DMA3.
 * @param   dma     Structure containing the initialization parameters
 *                  @ref dma_chan_config
 * @param   chacr   Select one of the @ref dma_chacr_attr.
 * @param   umnsm   Select one of the @ref dma_umnsm_attr.
 * @note    Implemented as a function call.
 * @see     @ref DMA_Init, @ref DMA_InstallCallback
 ******************************************************************************/
#define DMA_AdvInit(ch,dma,chacr,umnsm)     ch##_AdvInit(dma,chacr,umnsm)
/*! @} End of dma_macro                                                       */

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
extern void DMA_InstallCallbackDMA0 (uint8 ip, DMA_CH_CALLBACK pCallback);
extern void DMA_InstallCallbackDMA1 (uint8 ip, DMA_CH_CALLBACK pCallback);
extern void DMA_InstallCallbackDMA2 (uint8 ip, DMA_CH_CALLBACK pCallback);
extern void DMA_InstallCallbackDMA3 (uint8 ip, DMA_CH_CALLBACK pCallback);

extern void DMA0_Init(tDMA_CH dma);
extern void DMA1_Init(tDMA_CH dma);
extern void DMA2_Init(tDMA_CH dma);
extern void DMA3_Init(tDMA_CH dma);

extern void DMA0_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm);
extern void DMA1_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm);
extern void DMA2_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm);
extern void DMA3_AdvInit(tDMA_CH dma, uint8 chacr, uint8 umnsm);

/******************************************************************************
 * interrupt function prototypes                                              *
 ******************************************************************************/
extern void dma0_isr (void);
extern void dma1_isr (void);
extern void dma2_isr (void);
extern void dma3_isr (void);

#endif /* __DMA_H */