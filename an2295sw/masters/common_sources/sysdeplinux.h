/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           SYSDEPLINUX.C                                  *
*      Project:        Developper's HC08 Bootloader Master            *
*      Description:    Serial defines header file for Linux           *
*      Platform:       Linux                                          *
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


#ifndef _SYSDEPLINUX_H
#define _SYSDEPLINUX_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef unsigned char BYTE;

#define sys_usleep(us) usleep(us)

// debugging macros

#ifdef _DEBUG
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

#endif
