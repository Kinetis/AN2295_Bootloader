/*******************************************************************************
*
* Copyright 2004-2013 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale FreeMASTER License
* distributed with this Material.
* See the license file distributed for more details.
*
****************************************************************************//*!
*
* @brief  FreeMASTER TSA implementation
*
* This file implements a new FreeMASTER feature called Targer-side address
* translation.
*
*******************************************************************************/

#include "freemaster.h"
#include "freemaster_private.h"
#include "freemaster_protocol.h"

#if (FMSTR_USE_TSA) && (!(FMSTR_DISABLE))

/**************************************************************************//*!
*
* @brief    TSA Initialization
*
******************************************************************************/

void FMSTR_InitTsa(void)
{
}

/**************************************************************************//*!
*
* @brief    Handling GETTSAINFO and GETTSAINFO_EX command
*
* @param    pMessageIO - original command (in) and response buffer (out)
*
* @return   As all command handlers, the return value should be the buffer
*           pointer where the response output finished (except checksum)
*
******************************************************************************/

FMSTR_BPTR FMSTR_GetTsaInfo(FMSTR_BPTR pMessageIO)
{
    volatile FMSTR_BPTR pResponse = pMessageIO;
    const FMSTR_TSA_ENTRY* pTbl;
    FMSTR_TSA_TINDEX nTblIndex;
    FMSTR_TSA_TSIZE nTblSize = 0U;
    FMSTR_ADDR tmpAddr;
    FMSTR_U16 tmp16;

    /* get index of table the PC is requesting   */
    pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 2U);
    pMessageIO = FMSTR_ValueFromBuffer16(&nTblIndex, pMessageIO);

    /* TSA flags */
    tmp16 = FMSTR_TSA_VERSION | FMSTR_TSA_FLAGS;

    /* sizeof TSA table entry items */
    /*lint -e{506,774} constant value boolean */
    if((sizeof(FMSTR_TSA_ENTRY)/4U) == 4U)
    {
        tmp16 |= FMSTR_TSA_INFO_32BIT;  /* 32bit TSA entries */
    }

    /* success, flags */
    pResponse = FMSTR_ConstToBuffer8(pResponse, FMSTR_STS_OK);
    pResponse = FMSTR_ValueToBuffer16(pResponse, tmp16);

    /* get the table (or NULL if no table on given index) */
    pTbl = FMSTR_TsaGetTable(nTblIndex, &nTblSize);
    FMSTR_PTR2ADDR(tmpAddr, pTbl);

    /* table size in bytes */
    nTblSize *= FMSTR_CFG_BUS_WIDTH;
    pResponse = FMSTR_ValueToBuffer16(pResponse, nTblSize);

    /* table address */
    return FMSTR_AddressToBuffer(pResponse, tmpAddr);
}

/**************************************************************************//*!
*
* @brief    Handling GETSTRLEN and GETSTRLEN_EX commands
*
* @param    pMessageIO - original command (in) and response buffer (out)
*
* @return   As all command handlers, the return value should be the buffer
*           pointer where the response output finished (except checksum)
*
******************************************************************************/

FMSTR_BPTR FMSTR_GetStringLen(FMSTR_BPTR pMessageIO)
{
    FMSTR_BPTR pResponse = pMessageIO;
    FMSTR_ADDR nAddr;
    FMSTR_U16 nLen = 0U;

    pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 1U);
    pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

    nLen = FMSTR_StrLen(nAddr);

    /* return strign size in bytes (even on 16bit DSP) */
    nLen *= FMSTR_CFG_BUS_WIDTH ;

    pResponse = FMSTR_ConstToBuffer8(pResponse, FMSTR_STS_OK);
    return FMSTR_ValueToBuffer16(pResponse, nLen);
}

/**************************************************************************//*!
*
* @brief    Helper (inline) function for TSA memory region check
*
* @param    nAddrUser - address of region to be checked
* @param    nSizeUser - size of region to be checked
* @param    nAddrSafe - address of known "safe" region
* @param    wSizeSafe - size of safe region
*
* @return   This function returns non-zero if given user space is safe
*           (i.e. it lies in given safe space)
*
******************************************************************************/

#if defined(FMSTR_PLATFORM_56F8xxx) || defined(FMSTR_PLATFORM_56F8xx)
/* make inline */
inline FMSTR_BOOL FMSTR_CheckMemSpace(FMSTR_ADDR nAddrUser, FMSTR_SIZE8 nSizeUser,
    FMSTR_ADDR nAddrSafe, FMSTR_SIZE wSizeSafe);

inline
#else
/* declare function prototype */
static FMSTR_BOOL FMSTR_CheckMemSpace(FMSTR_ADDR nAddrUser, FMSTR_SIZE8 nSizeUser,
    FMSTR_ADDR nAddrSafe, FMSTR_SIZE wSizeSafe);

static
#endif

FMSTR_BOOL FMSTR_CheckMemSpace(FMSTR_ADDR nAddrUser, FMSTR_SIZE8 nSizeUser,
                               FMSTR_ADDR nAddrSafe, FMSTR_SIZE wSizeSafe)
{
    FMSTR_BOOL bRet = FMSTR_FALSE;

    #ifdef __HCS12X__
    /* convert from logical to global if needed */
    nAddrUser = FMSTR_FixHcs12xAddr(nAddrUser);
    nAddrSafe = FMSTR_FixHcs12xAddr(nAddrSafe);
    #endif

    if(nAddrUser >= nAddrSafe)
    {
        bRet = (FMSTR_BOOL)
            (((nAddrUser + nSizeUser) <= (nAddrSafe + wSizeSafe)) ? FMSTR_TRUE : FMSTR_FALSE);
    }

    return bRet;
}

/**************************************************************************//*!
*
* @brief    Check wether given memory region is "safe" (covered by TSA)
*
* @param    dwAddr - address of the memory to be checked
* @param    nSize  - size of the memory to be checked
* @param    bWriteAccess - write access is required
*
* @return   This function returns non-zero if user space is safe
*
******************************************************************************/

FMSTR_BOOL FMSTR_CheckTsaSpace(FMSTR_ADDR dwAddr, FMSTR_SIZE8 nSize, FMSTR_BOOL bWriteAccess)
{
    const FMSTR_TSA_ENTRY* pte;
    FMSTR_TSA_TINDEX nTableIndex;
    FMSTR_TSA_TSIZE i, cnt;
    FMSTR_SIZE nInfo;

#if FMSTR_CFG_BUS_WIDTH >= 2U
    /* TSA tables use sizeof() operator which returns size in "bus-widths" (e.g. 56F8xx) */
    nSize = (nSize + 1) / FMSTR_CFG_BUS_WIDTH;
#endif

    /* to be as fast as possible during normal operation,
       check variable entries in all tables first */
    for(nTableIndex=0U; (pte=FMSTR_TsaGetTable(nTableIndex, &cnt)) != NULL; nTableIndex++)
    {
        /* number of items in a table */
        cnt /= (FMSTR_TSA_TSIZE) sizeof(FMSTR_TSA_ENTRY);

        /* all table entries */
        for(i=0U; i<cnt; i++)
        {
            /*lint -e{506,774} condition always true/false */
#if !defined(__S12Z__)
            if(sizeof(pte->addr.p) < sizeof(pte->addr.n))
                nInfo = (FMSTR_SIZE)((unsigned long) pte->info.n);
            else
#endif
            nInfo = (FMSTR_SIZE) ((unsigned long)pte->info.p);

            /* variable entry only (also check read-write flag) */
            if((nInfo & FMSTR_TSA_INFO_VAR_FLAG) && (!bWriteAccess || (nInfo & FMSTR_TSA_INFO_RWV_FLAG)))
            {
                /* need to take the larger of the two in union (will be optimized by compiler anyway) */
                /*lint -e{506,774} condition always true/false */
#if !defined(__S12Z__)
                if(sizeof(pte->addr.p) < sizeof(pte->addr.n))
                {
                    if(FMSTR_CheckMemSpace(dwAddr, nSize, (FMSTR_ADDR) pte->addr.n, (FMSTR_SIZE) (nInfo >> 2)))
                    {
                        return FMSTR_TRUE; /* access granted! */
                    }
                }
                else
#endif
                {
                    /*lint -e{923} casting pointer to long (on some architectures) */
                    if(FMSTR_CheckMemSpace(dwAddr, nSize, (FMSTR_ADDR) pte->addr.p, (FMSTR_SIZE) (nInfo >> 2)))
                    {
                        return FMSTR_TRUE; /* access granted! */
                    }
                }
            }

            pte++;
        }
    }

    /* no more writable memory chunks available */
    if(bWriteAccess)
    {
        return FMSTR_FALSE;
    }

    /* allow reading of recorder buffer */
#if FMSTR_USE_RECORDER
    if(FMSTR_IsInRecBuffer(dwAddr, nSize))
    {
        return FMSTR_TRUE;
    }
#endif

    /* allow reading of any C-constant string referenced in TSA tables */
    for(nTableIndex=0U; (pte=FMSTR_TsaGetTable(nTableIndex, &cnt)) != NULL; nTableIndex++)
    {
        FMSTR_ADDR tmpAddr;

        /* allow reading of the TSA table itself */
        FMSTR_PTR2ADDR(tmpAddr, pte);
        if(FMSTR_CheckMemSpace(dwAddr, nSize, tmpAddr, cnt))
        {
            return FMSTR_TRUE;
        }

        /* number of items in a table */
        cnt /= (FMSTR_TSA_TSIZE) sizeof(FMSTR_TSA_ENTRY);

        /* all table entries */
        for(i=0U; i<cnt; i++)
        {
            /* system strings are always accessible at C-pointers */
            FMSTR_PTR2ADDR(tmpAddr, pte->name.p);
            if(pte->name.p)
            {
                if(FMSTR_CheckMemSpace(dwAddr, nSize, tmpAddr, FMSTR_StrLen(tmpAddr)))
                {
                    return FMSTR_TRUE;
                }
            }

            FMSTR_PTR2ADDR(tmpAddr, pte->type.p);
            if(pte->type.p)
            {
                if(FMSTR_CheckMemSpace(dwAddr, nSize, tmpAddr, FMSTR_StrLen(tmpAddr)))
                {
                    return FMSTR_TRUE;
                }
            }

            pte++;
        }
    }

    /* no valid TSA entry found => not-safe to access the memory */
    return FMSTR_FALSE;
}

#else /* (FMSTR_USE_TSA) && (!(FMSTR_DISABLE)) */

/*lint -efile(766, freemaster_protocol.h) include file is not used in this case */

#endif /* (FMSTR_USE_TSA) && (!(FMSTR_DISABLE)) */

