/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster_Kxx.c
*
* @brief  FreeMASTER Driver Kxx-hardware dependent stuff
*
* @version 1.0.1.0
* 
* @date Jan-21-2013
* 
*******************************************************************************/

#include "freemaster.h"
#include "freemaster_private.h"
#include "freemaster_Kxx.h"

//#include "TSS_API.h"
 
/*******************************************************************************
*
* @brief    API: Main SCI Interrupt handler call
*
* This Interrupt Service Routine handles the SCI interrupts for the FreeMASTER 
* driver. In case you want to handle the interrupt in the application yourselves,
* call the FMSTR_ProcessSCI function which does the same job but is not compiled
* as an Interrupt Service Routine.
*
* In poll-driven mode (FMSTR_POLL_DRIVEN) this function does nothing.
*
*******************************************************************************/

void FMSTR_Isr(void)
{
    //TSS_SET_SAMPLE_INTERRUPTED(); /* TSS Sample Interrupted Indication */
      
#if FMSTR_LONG_INTR || FMSTR_SHORT_INTR

/* process serial interface */
#if FMSTR_USE_SCI
    FMSTR_ProcessSCI(); 

/* process CAN interface */    
#elif FMSTR_USE_CAN
    /* separate interrupts specified */
    #if defined(FMSTR_CAN_RX_INTERRUPT) && defined(FMSTR_CAN_TX_INTERRUPT) && !defined(FMSTR_CAN_INTERRUPT)
        /* CAN RX only! */
        FMSTR_ProcessCanRx();
    #else        
        /* both CAN interrupts */
        FMSTR_ProcessCanRx();
        FMSTR_ProcessCanTx();
    #endif        
#endif
    
#endif /* FMSTR_LONG_INTR || FMSTR_SHORT_INTR */

}

/*******************************************************************************
*
* @brief    The second ISR for case separate vectors exist for RX and TX
*
* In poll-driven mode (FMSTR_POLL_DRIVEN) or is a common interrupt for RX and TX 
* was selected, this function is not compiled at all.
*
*******************************************************************************/

#undef FMSTR_IMPL_ISRTX

#if FMSTR_LONG_INTR || FMSTR_SHORT_INTR
#if FMSTR_USE_SCI && defined(FMSTR_SCI_TX_INTERRUPT) && defined(FMSTR_SCI_RX_INTERRUPT)
interrupt FMSTR_SCI_TX_INTERRUPT
#define FMSTR_IMPL_ISRTX 1
#elif FMSTR_USE_CAN && defined(FMSTR_CAN_TX_INTERRUPT) && defined(FMSTR_CAN_RX_INTERRUPT)
interrupt FMSTR_CAN_TX_INTERRUPT
#define FMSTR_IMPL_ISRTX 1
#endif
#endif

#ifdef FMSTR_IMPL_ISRTX

void FMSTR_Isr2(void)
{

/* process serial interface */
#if FMSTR_USE_SCI
    FMSTR_ProcessSCI(); 

/* process CAN interface */    
#elif FMSTR_USE_CAN
    FMSTR_ProcessCanTx();
#endif
    
}

#endif /* FMSTR_IMPL_ISRTX */

/* restore HC12 code segment */
#if defined(FMSTR_PLATFORM_HC12)
    #include "default.sgm"
#endif

/**************************************************************************//*!
*
* @brief    The "memcpy" used internally in FreeMASTER driver
*
* @param    nDestAddr - destination memory address
* @param    nSrcAddr  - source memory address
* @param    nSize     - memory size (always in bytes)
*
******************************************************************************/

void FMSTR_CopyMemory(FMSTR_ADDR nDestAddr, FMSTR_ADDR nSrcAddr, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) nSrcAddr;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;
    
    while(nSize--)
        *pd++ = *ps++;
}

/**************************************************************************//*!
*
* @brief  Write-into the communication buffer memory
*
* @param  pDestBuff - pointer to destination memory in communication buffer
* @param  nSrcAddr  - source memory address
* @param  nSize     - buffer size (always in bytes)
*
* @return This function returns a pointer to next byte in comm. buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_CopyToBuffer(FMSTR_BPTR pDestBuff, FMSTR_ADDR nSrcAddr, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) nSrcAddr;
    FMSTR_U8* pd = (FMSTR_U8*) pDestBuff;
    
    while(nSize--)
        *pd++ = *ps++;
        
    return (FMSTR_BPTR) pd;
}

/**************************************************************************//*!
*
* @brief  Read-out memory from communication buffer
*
* @param  nDestAddr - destination memory address
* @param  pSrcBuff  - pointer to source memory in communication buffer
* @param  nSize     - buffer size (always in bytes)
*
* @return This function returns a pointer to next byte in comm. buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_CopyFromBuffer(FMSTR_ADDR nDestAddr, FMSTR_BPTR pSrcBuff, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) pSrcBuff;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;
    
    while(nSize--)
        *pd++ = *ps++;
        
    return (FMSTR_BPTR) ps;
}


/**************************************************************************//*!
*
* @brief  Read-out memory from communication buffer, perform AND-masking
*
* @param  nDestAddr - destination memory address
* @param  pSrcBuff  - source memory in communication buffer, mask follows data
* @param  nSize     - buffer size (always in bytes)
*
******************************************************************************/

void FMSTR_CopyFromBufferWithMask(FMSTR_ADDR nDestAddr, FMSTR_BPTR pSrcBuff, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) pSrcBuff;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;
    FMSTR_U8* pm = ps + nSize;
    FMSTR_U8 mask, stmp, dtmp;
    
    while(nSize--) 
    {
        mask = *pm++;
        stmp = *ps++;
        dtmp = *pd;
        
        /* perform AND-masking */
        stmp = (stmp & mask) | (dtmp & ~mask);

        /* put the result back       */
        *pd++ = stmp;
    }
}

/******************************************************************************/

/* S12X LARGE model special handling (FMSTR_ADDR is __far pointer, global address) */
#if defined(__HCS12X__) && FMSTR_LARGE_MODEL

/* mixed EX and no-EX commands? */
#if FMSTR_USE_EX_CMDS && FMSTR_USE_NOEX_CMDS

/**************************************************************************//*!
*
* @brief  When mixed EX and no-EX command may occur, this variable is
*         here to remember what command is just being handled.
*
******************************************************************************/

static FMSTR_BOOL pcm_bNextAddrIsEx;

void FMSTR_SetExAddr(FMSTR_BOOL bNextAddrIsEx)
{
    pcm_bNextAddrIsEx = bNextAddrIsEx;
}

#else /* only no-EX commands (we are in LARGE model) */

/**************************************************************************//*!
*
* @brief  When mixed EX and no-EX commands are disabled, we are sure
*         only the EX are used (we are in LARGE mode here).
*
******************************************************************************/

static const FMSTR_BOOL pcm_bNextAddrIsEx = 1;

#endif /* mixed EX and no-EX commands */

/**************************************************************************//*!
*
* @brief  Store (global) address to communication buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_AddressToBuffer(FMSTR_BPTR pDest, FMSTR_ADDR nAddr)
{
    if(pcm_bNextAddrIsEx)
    {
        /* fill in the 24bit (global) address, right-align in 32bit destination */
        *(FMSTR_U32*) pDest = ((FMSTR_U32)nAddr);
        pDest += 4;
    }
    else
    {
        /* this should never happen, the result address would be invalid */
        asm BGND;
        
        /* use NULL address rather than invalid one */
        *(FMSTR_U16*) pDest = 0;
        pDest += 2; 
    }
    
    return pDest;
}

/**************************************************************************//*!
*
* @brief  Test if given numeric (FMSTR_U32) address is global one
*
* Although not really general approach, this condition works on all current 
* S12X devices. In fact, this will work until the valid PPAGE and RPAGE values
* will be 0x80 or higher. On current devices, the PPAGE and RPAGE values start
* at 0xFF and going down depending on the ammount of available memory.
*
* Non-global address is either near (16bit only) or or logical (24bit page+offs, 
* Bit23 set (no device uses page 7f or less). The conversion of both such formats 
* to a global format is handled by CodeWarrior library function 
* _CONV_LOGICAL_TO_GLOBAL function.
*
* For us now, it is okay to assume the global adddress is the one with 
* non-zero page (GPAGE) while having Bit23 cleared.
*
******************************************************************************/

#define FMSTR_IsGlobalAddress(addr) \
    (((addr) & 0xff0000L) && !((addr) & 0x800000L))
    
/**************************************************************************//*!
*
* @brief  CodeWarrior logical-to-global translation function 
*
* FMSTR_ADDR is defined as void*__far which is passed in B:X as
* the library function expects it. The function is NEAR so JSR is used
*
******************************************************************************/

FMSTR_ADDR NEAR _CONV_LOGICAL_TO_GLOBAL(FMSTR_ADDR);

/**************************************************************************//*!
*
* @brief  Fetch address from communication buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_AddressFromBuffer(FMSTR_ADDR* pAddr, FMSTR_BPTR pSrc)
{
    /* treat address as long word to determine the kind of the address */
    FMSTR_U32 addr = 0;
    
    if(pcm_bNextAddrIsEx)
    {
        addr = *((FMSTR_U32*) pSrc);
        pSrc += 4;
    }
    else
    {
        addr = *((FMSTR_U16*) pSrc);
        pSrc += 2;
    }

    if(FMSTR_IsGlobalAddress(addr))
    {
        *pAddr = (FMSTR_ADDR) (void*__far) (addr & 0xffffff);
    }
    else
    {
        *pAddr = (FMSTR_ADDR) _CONV_LOGICAL_TO_GLOBAL((FMSTR_ADDR)addr);
    }
    
    return pSrc;
}

#endif /* S12X FMSTR_LARGE_MODEL */
