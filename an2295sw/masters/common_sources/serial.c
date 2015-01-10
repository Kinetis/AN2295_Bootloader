/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           SERIAL.C                                       *
*      Project:        Developper's HC08 Bootloader Master            *
*      Description:    Serial communication routines file             *
*      Platform:       Linux/Win32                                    *
*      Revision:       1.0                                            *
*      Date:           Jun 26 2003                                    *
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


#include "sysdep.h"
#include "hc08sprg.h"
#include "serial.h"

#ifdef _WINDOWS

	int myprintf(const char * _Format, ...);
	int myfprintf(__inout FILE * _File, const char * _Format, ...);
	void progress_Changed(unsigned value);


	#define printf myprintf
	#define fprintf myfprintf
#else
	#define progress_Changed(x)
#endif

// single wire mode global
int serial_mode = SMOD_DUAL;

// see whether verify or not
int verify;

// single wire handling
static unsigned rxignore = 0;

// prototypes of Linux or Win32 specific routines

int _init_uart(char* nm, char* speed);
int _close_uart(void);
int _send_break10(void);
int _flush_uart(int out, int in);
int _wb(const void* data, unsigned len);
int _rb(void* dest, unsigned len);
static void detect_single_wire(char* nm);

// initialize UART

void set_verify(int parVerify)
{
	verify = parVerify;
}

int init_uart(char* nm, char* speed)
{
	int ret;

	// open port
	if((ret = _init_uart(nm, speed)) < 0)
		return ret;

	// verify yes, if serial mode in CAPS!
	verify = (serial_mode < 'a');

	// serial mode ?
	if(serial_mode == SMOD_DETECT)
		detect_single_wire(nm);
	else
		serial_mode = toupper(serial_mode);

	// unknown mode ?
	if(serial_mode != SMOD_SINGLE && serial_mode != SMOD_DUAL)
	{
		close_uart();

		fprintf(stderr, "Bad serial mode specified: '%c' (use 'S', 'D' or '?' only)\n", serial_mode);
		return -1;
	}

	// success
	return 0;
}

int close_uart()
{
	return _close_uart();
}

// detect single wire RS232 and set serial_mode global

#define SW_MAGIC ((char)0xa5)

static void detect_single_wire(char* nm)
{
	char buff[1] = { SW_MAGIC };
	_flush_uart(FDISCARD, FDISCARD);

	// dual mode by default
	serial_mode = SMOD_DUAL;

	// send & recv & test magic byte
	if(_wb(buff, 1) == 1 && _rb(buff, 1) == 1 && buff[0] == SW_MAGIC)
	{
		printf("RS232 single wire mode detected.\n");
		serial_mode = SMOD_SINGLE;
	}
}

// send break chracter (10 zero bits)

int send_break10(void)
{
	return _send_break10();
}

// flush output and kill input

int flush_uart(int out, int in)
{
	if(in == FDISCARD)
		rxignore = 0;

	return _flush_uart(out, in);
}

// write block, return -1=error, or number of bytes written 

int wb(const void* data, unsigned len)
{
	if(serial_mode == SMOD_SINGLE)
		rxignore += len;

	return _wb(data, len);
}

// read block, return -1=error, or number of bytes read

int rb(void* dest, unsigned len)
{
	// ignore self-recived characters
	if(rxignore)
	{
		char* dummy = (char*) malloc(rxignore);
		int ret;

		DBG1("want to ignore %d bytes\n", rxignore);
		ret = _rb(dummy, rxignore);
		free(dummy);
		DBG1("rb data ignored above %d\n", ret);

		// bytes received ?
		if(ret > 0)
			rxignore -= ret;
		else 
			return ret;

		// not all bytes received
		if(rxignore)
		{
			DBG1("still some data to ignore %d\n", rxignore);
			return 0;
		}
	}

	// now read real data
	return _rb(dest, len);
}


