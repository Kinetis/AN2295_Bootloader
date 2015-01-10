/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           SYSDEPW32.C                                    *
*      Project:        Developper's HC08 Bootloader Master            *
*      Description:    Serial defines header file for Win32           *
*      Platform:       Win32                                          *
*      Revision:       1.0                                            *
*      Date:           Apr 8 2002                                     *
*      Author:         Michal Hanak                                   *
*      Company:        Freescale                                      *
*      Security:       General Business                               *
*                                                                     *
* =================================================================== *
* Copyright (c):       FREESCALE Inc., 2004, All rights reserved.     *
*                                                                     *
* =================================================================== *
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY              *
* EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  *
* PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR             *
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    *
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT        *
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;        *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)            *
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, *
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       *
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED *
* OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
* =================================================================== *
*
* HEADER_END
*/


#ifndef _SYSDEPW32_H
#define _SYSDEPW32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define sys_usleep(us) Sleep(us/1000)

// debugging macros

#ifdef _DEBUG
//#if 0
#define DBG(fmt)  printf(fmt)
#define DBG0(fmt)  printf(fmt)
#define DBG1(fmt, a1)  printf(fmt, a1)
#define DBG2(fmt, a1, a2)  printf(fmt, a1, a2)
#define DBG3(fmt, a1, a2, a3)  printf(fmt, a1, a2, a3)
#else
#define DBG(fmt)
#define DBG0(fmt)
#define DBG1(fmt, a1)
#define DBG2(fmt, a1, a2)
#define DBG3(fmt, a1, a2, a3)
#endif

#ifdef __cplusplus
	}
#endif

#endif
