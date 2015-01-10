#include "dma.h"



void DMA_Init(DMA_InitTypeDef *DMA_InitStruct)
{
  // open clock gate    
  SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;    
  SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;
  //   config DMA req source      
  if(DMA_InitStruct->PeripheralDMAReq == DMA_SOFTWARE_TRIGGER)
  {
    // disable peripheral request 
    DMA0->DMA[DMA_InitStruct->Channelx].DCR &= ~DMA_DCR_ERQ_MASK;
  }
  else
  {
    // enable peripheral request  
    DMAMUX0->CHCFG[DMA_InitStruct->Channelx] = DMAMUX_CHCFG_SOURCE(DMA_InitStruct->PeripheralDMAReq);
    //  config if use periodic trigger mode 
    (DMA_InitStruct->PeriodicModeState == ENABLE)?(DMAMUX0->CHCFG[DMA_InitStruct->Channelx]|= DMAMUX_CHCFG_TRIG_MASK):(DMAMUX0->CHCFG[DMA_InitStruct->Channelx]&= ~DMAMUX_CHCFG_TRIG_MASK);
  }
  //   config DMA source address  
  DMA0->DMA[DMA_InitStruct->Channelx].SAR  = DMA_InitStruct->SourceBaseAddr;
  //   config DMA dest   address  
  DMA0->DMA[DMA_InitStruct->Channelx].DAR  = DMA_InitStruct->DestBaseAddr;
  //  config SSize and DSize     
  DMA0->DMA[DMA_InitStruct->Channelx].DCR &= (DMA_DCR_SSIZE_MASK | DMA_DCR_DSIZE_MASK);
  DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_SSIZE(DMA_InitStruct->SourceDataSize);
  DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_DSIZE(DMA_InitStruct->DestDataSize);
  //   config Source and dest auto inc  
  (DMA_InitStruct->SourceInc == ENABLE)?(DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_SINC_MASK):(DMA0->DMA[DMA_InitStruct->Channelx].DCR &= ~DMA_DCR_SINC_MASK);
  (DMA_InitStruct->DestInc == ENABLE)?(DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_DINC_MASK):(DMA0->DMA[DMA_InitStruct->Channelx].DCR &= ~DMA_DCR_DINC_MASK);
  //  config  TransferBytes            
  DMA0->DMA[DMA_InitStruct->Channelx].DSR_BCR &= ~DMA_DSR_BCR_BCR_MASK;
  DMA0->DMA[DMA_InitStruct->Channelx].DSR_BCR |=  DMA_DSR_BCR_BCR(DMA_InitStruct->BytesToTransfer);
  //  CS config   if CS = 0  DMA do contiune to transfer bytes without stop, so generaly cs = 1
  (DMA_InitStruct->CycleStealState == ENABLE)?(DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_CS_MASK):(DMA0->DMA[DMA_InitStruct->Channelx].DCR &= ~DMA_DCR_CS_MASK);
  //  config if start transfer immidtately  
  if(DMA_InitStruct->PeripheralDMAReq == DMA_SOFTWARE_TRIGGER)
  {
    DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_START_MASK;
  }
  else
  {
    DMA0->DMA[DMA_InitStruct->Channelx].DCR |= DMA_DCR_ERQ_MASK;
  }
  // enable chl    
  DMAMUX0->CHCFG[DMA_InitStruct->Channelx] |= DMAMUX_CHCFG_ENBL_MASK;
}


uint8_t DMA_IsComplete(uint8_t DMAChl)
{
  if(DMA0->DMA[DMAChl].DSR_BCR & DMA_DSR_BCR_DONE_MASK)
  {
    // w1c 
    DMA0->DMA[DMAChl].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}


//DMA IT Config
void DMA_ITConfig(uint16_t DMA_IT, uint8_t DMA_CH, FunctionalState NewState)
{
  switch(DMA_IT)
  {
    case DMA_IT_MAJOR:
    (ENABLE == NewState)?(DMA0->DMA[DMA_CH].DCR |= DMA_DCR_EINT_MASK):( DMA0->DMA[DMA_CH].DCR &= ~DMA_DCR_EINT_MASK);
    break;
    default:break;
  }
}

//DMA Clear interrupt pending bit
void DMA_ClearITPendingBit(uint16_t DMA_IT, uint8_t DMA_CH)
{
  DMA0->DMA[DMA_CH].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;

  
}

