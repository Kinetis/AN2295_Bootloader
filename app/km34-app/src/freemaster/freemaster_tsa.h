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
* @brief  FreeMASTER Driver TSA feature
*
*******************************************************************************/

#ifndef __FREEMASTER_TSA_H
#define __FREEMASTER_TSA_H

#include "freemaster_defcfg.h"

/*****************************************************************************
 Target-side Address translation structures and macros
******************************************************************************/

/* current TSA version  */
#define FMSTR_TSA_VERSION 2U

/* TSA flags carried in TSA_ENTRY.info (except the first entry in table) */
#define FMSTR_TSA_INFO_ENTRYTYPE_MASK 0x0003U    /* flags reserved for TSA_ENTRY use */
#define FMSTR_TSA_INFO_STRUCT         0x0000U    /* ENTRYTYPE: structure parent type */
#define FMSTR_TSA_INFO_RO_VAR         0x0001U    /* ENTRYTYPE: read-only variable */
#define FMSTR_TSA_INFO_MEMBER         0x0002U    /* ENTRYTYPE: structure member */
#define FMSTR_TSA_INFO_RW_VAR         0x0003U    /* ENTRYTYPE: read-write variable */
#define FMSTR_TSA_INFO_VAR_FLAG       0x0001U    /* ENTRYTYPE: FLAG: any variable */
#define FMSTR_TSA_INFO_RWV_FLAG       0x0002U    /* ENTRYTYPE: FLAG: R/W access */

/* TSA table index and size (both unsigned, at least 16 bit wide) */
typedef FMSTR_SIZE FMSTR_TSA_TINDEX;
typedef FMSTR_SIZE FMSTR_TSA_TSIZE;

/* pointer types used in TSA tables can be overridden in freemaster.h */
/* (this is why macros are used instead of typedefs) */
#ifndef FMSTR_TSATBL_STRPTR
#define FMSTR_TSATBL_STRPTR  const char*
#endif
#ifndef FMSTR_TSATBL_STRPTR_CAST
#define FMSTR_TSATBL_STRPTR_CAST(x) ((FMSTR_TSATBL_STRPTR)(x))
#endif
#ifndef FMSTR_TSATBL_STRPTR_ENTRY
#define FMSTR_TSATBL_STRPTR_ENTRY(x) FMSTR_TSATBL_STRPTR_CAST(x)
#endif
#ifndef FMSTR_TSATBL_VOIDPTR
#define FMSTR_TSATBL_VOIDPTR const void*
#endif
#ifndef FMSTR_TSATBL_VOIDPTR_CAST
#define FMSTR_TSATBL_VOIDPTR_CAST(x) ((FMSTR_TSATBL_VOIDPTR)(x))
#endif
#ifndef FMSTR_TSATBL_VOIDPTR_ENTRY
#define FMSTR_TSATBL_VOIDPTR_ENTRY(x) FMSTR_TSATBL_VOIDPTR_CAST(x)
#endif

/* TSA table entry. The unions inside assures variables sized enough to */
/* accommodate both the C-pointer and the user-requested size (FMSTR_ADDR) */
#if defined(__S12Z__)
typedef struct
{
  FMSTR_DUMMY dummy0;
  union { FMSTR_ADDR  p; FMSTR_ADDR n; } name;
  FMSTR_DUMMY dummy1;
  union { FMSTR_ADDR  p; FMSTR_ADDR n; } type;
  FMSTR_DUMMY dummy2;
  union { FMSTR_ADDR p; FMSTR_ADDR n; } addr;
  FMSTR_DUMMY dummy3;
  union { FMSTR_ADDR p; FMSTR_ADDR n; } info;
} FMSTR_TSA_ENTRY;
#else
typedef struct
{
    union { FMSTR_TSATBL_STRPTR  p; FMSTR_ADDR n; } name;
    union { FMSTR_TSATBL_STRPTR  p; FMSTR_ADDR n; } type;
    union { FMSTR_TSATBL_VOIDPTR p; FMSTR_ADDR n; } addr;
    union { FMSTR_TSATBL_VOIDPTR p; FMSTR_ADDR n; } info;
} FMSTR_TSA_ENTRY;
#endif

/*//////////////////////////////////////////////// */
/* single table-building macros */

#define FMSTR_TSA_FUNC(id)  FMSTR_TsaGetTable_##id
#define FMSTR_TSA_FUNC_PROTO(id) const FMSTR_TSA_ENTRY* FMSTR_TSA_FUNC(id) (FMSTR_TSA_TSIZE* pTableSize)

#define FMSTR_TSA_TABLE_BEGIN(id) \
    FMSTR_TSA_FUNC_PROTO(id); \
    FMSTR_TSA_FUNC_PROTO(id) { \
        static FMSTR_TSA_CDECL FMSTR_TSA_ENTRY fmstr_tsatable[] = {

/* entry info  */
#define FMSTR_TSA_INFO1(elem, flags) FMSTR_TSATBL_VOIDPTR_ENTRY(((sizeof(elem))<<2)|(flags))
#define FMSTR_TSA_INFO2(size, flags) FMSTR_TSATBL_VOIDPTR_ENTRY(((size)<<2)|(flags))

#define FMSTR_TSA_STRUCT(name)  \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(NULL), FMSTR_TSATBL_VOIDPTR_ENTRY(NULL), FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_STRUCT) },

#define FMSTR_TSA_MEMBER(parenttype,name,type) \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMSTR_TSATBL_VOIDPTR_ENTRY(&((parenttype*)0)->name), FMSTR_TSA_INFO1(((parenttype*)0)->name, FMSTR_TSA_INFO_MEMBER) },

#define FMSTR_TSA_RO_VAR(name,type) \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMSTR_TSATBL_VOIDPTR_ENTRY(&(name)), FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_RO_VAR) },

#define FMSTR_TSA_RW_VAR(name,type) \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMSTR_TSATBL_VOIDPTR_ENTRY(&(name)), FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_RW_VAR) },

#define FMSTR_TSA_RO_MEM(name,type,addr,size) \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMSTR_TSATBL_VOIDPTR_ENTRY(addr), FMSTR_TSA_INFO2(size, FMSTR_TSA_INFO_RO_VAR) },

#define FMSTR_TSA_RW_MEM(name,type,addr,size) \
    { FMSTR_TSATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMSTR_TSATBL_VOIDPTR_ENTRY(addr), FMSTR_TSA_INFO2(size, FMSTR_TSA_INFO_RW_VAR) },

#define FMSTR_TSA_TABLE_END() }; \
    if(pTableSize) *pTableSize = sizeof(fmstr_tsatable); \
    return fmstr_tsatable; }

/*///////////////////////////////////////////////////////////////////// */
/* TSA "Base Types", all are implemented as a one-char strings */
/* retrieved by PC and parsed according to the binary scheme */
/* "111STTZZ" where TT=type[int,frac,fp,x] S=signed ZZ=size[1,2,4,8] */

#define FMSTR_TSA_UINT8   "\xE0"
#define FMSTR_TSA_UINT16  "\xE1"
#define FMSTR_TSA_UINT32  "\xE2"
#define FMSTR_TSA_UINT64  "\xE3"
#define FMSTR_TSA_SINT8   "\xF0"
#define FMSTR_TSA_SINT16  "\xF1"
#define FMSTR_TSA_SINT32  "\xF2"
#define FMSTR_TSA_SINT64  "\xF3"
#define FMSTR_TSA_UFRAC16 "\xE5"
#define FMSTR_TSA_UFRAC32 "\xE6"
#define FMSTR_TSA_FRAC16  "\xF5"
#define FMSTR_TSA_FRAC32  "\xF6"
#define FMSTR_TSA_FLOAT   "\xFA"
#define FMSTR_TSA_DOUBLE  "\xFB"

/* macro used to describe "User Type" */
#define FMSTR_TSA_USERTYPE(type) #type

/* macro used to describe pure memory space */
#define FMSTR_TSA_MEMORY NULL


/*//////////////////////////////////////////////// */
/* master TSA table-retrieval building macros */

#ifdef __cplusplus
extern "C" {
#endif

#define FMSTR_TSA_TABLE_LIST_BEGIN() \
    const FMSTR_TSA_ENTRY* FMSTR_TsaGetTable(FMSTR_TSA_TINDEX nTableIndex, FMSTR_TSA_TSIZE* pTableSize) {

#define FMSTR_TSA_TABLE(id) \
    if(!nTableIndex--) { \
        FMSTR_TSA_FUNC_PROTO(id); \
        return FMSTR_TSA_FUNC(id)(pTableSize); \
    } else

#define FMSTR_TSA_TABLE_LIST_END() \
    { return NULL; } }

/*****************************************************************************
 Target-side Address translation functions
******************************************************************************/

/* master TSA table-retrieval function */
const FMSTR_TSA_ENTRY* FMSTR_TsaGetTable(FMSTR_TSA_TINDEX nTableIndex, FMSTR_TSA_TSIZE* pTableSize);

#ifdef __cplusplus
}
#endif

#endif /* __FREEMASTER_TSA_H */

