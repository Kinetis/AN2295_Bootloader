/*
 * File:        common.h
 * Purpose:     File to be included by all project files
 *
 * Notes:
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#define swap_bytes(ptrWord)   *ptrWord = (*ptrWord >>8) | (*ptrWord<<8)
typedef unsigned long   dword;
typedef unsigned short  word;

/********************************************************************/

/*
 * Debug prints ON (#define) or OFF (#undef)
 */

#define DEBUG
#define DEBUG_PRINT

/* 
 * Include the generic CPU header file 
 */
#include "arm_cm0.h"

/* 
 * Include the platform specific header file 
 */
#if (defined(FRDM_MA64))
  #include "MA64_freedom.h"
#elif (defined(FRDM_MA16))
 #include "MA16_freedom.h"
#elif (defined(EVB_MA16))
 #include "MA16_EVB.h"
#else
 #include  "MA64_evb.h"
#endif
/* 
 * Include the cpu specific header file 
*/
#if (defined(CPU_MA64))
 #include "MKE02Z2.h"
#else
  #error "No valid CPU defined"
#endif


/* 
 * Include any toolchain specfic header files 
 */
#if (defined(__MWERKS__))
  #include "mwerks.h"
#elif (defined(__DCC__))
  #include "build/wrs/diab.h"
#elif (defined(__ghs__))
  #include "build/ghs/ghs.h"
#elif (defined(__GNUC__))
  #if (defined(IAR))
    #include "build/gnu/gnu.h"
  #endif
#elif (defined(IAR))
  #include "iar.h"
#elif (defined(KEIL))
  
#else
#warning "No toolchain specific header included"
#endif

/* 
 * Include common utilities
 */
#include "assert.h"
#include "io.h"
#include "startup.h"
#include "stdlib.h"

#if (defined(IAR))
#include "intrinsics.h"
#endif
/********************************************************************/

#endif /* _COMMON_H_ */
