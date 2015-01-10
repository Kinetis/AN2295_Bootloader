/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           SERIALW32.C                                    *
*      Project:        Developper's HC08 Bootloader Master            *
*      Description:    Serial communication routines file             *
*      Platform:       Win32                                          *
*      Revision:       1.1                                            *
*      Date:           May 3 2002                                     *
*      Author:         Michal Hanak                                   *
*      Change:         DTR signal is now negative, providing          *
*                      power supply for possible optoisolation        *
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

#include "sysdepw32.h"
#include "serial.h"

#pragma warning(disable : 4996)

#ifdef _WINDOWS

	int myprintf(const char * _Format, ...);
	int myfprintf(__inout FILE * _File, const char * _Format, ...);
	void progress_Changed(unsigned value);


	#define printf myprintf
	#define fprintf myfprintf
#else
	#define progress_Changed(x)
#endif

extern char defaultyes;

///////////////////////////////////////////////////////////////
// module vars

static HANDLE port = 0;

///////////////////////////////////////////////////////////////
// open and set tty

// allowed port name formats: x[:SD], COMx[:SD]
// other formats are passed verbatim to CreateFile

int _init_uart(char* nm, char* speed)
{
	char fullNm[20];
	DCB dcb;
	DWORD dwErr;
	COMMTIMEOUTS tmo;
	COMSTAT comStat;
	COMMCONFIG ccfg;
	DWORD ccfgLen;
	int portNum = 0;
	char* scannm;
	char* shownm;
	char modemode;

	// skip COM if specified and scan number and mode (optional)
	scannm = strnicmp(nm, "COM", 3) ? nm : nm+3;
	sscanf(scannm, "%i%c%c", &portNum, &modemode, &serial_mode);

	if (modemode == '!')
		defaultyes = 1;	// omit Yes/No before programming
	
	// port number specified ?
	if(portNum)
	{
		sprintf(fullNm, "\\\\.\\COM%d", portNum);
		nm = fullNm;
	}

	// name to show in error messages
	shownm = nm;
	// do not show backslashes in error message
	if(!strncmp(shownm, "\\\\.\\", 4))
		shownm += 4;

	// try not to make pulse on DTR line during open
	ccfgLen = sizeof(ccfg);
	if(GetDefaultCommConfig(shownm, &ccfg, &ccfgLen))
	{
		ccfg.dcb.fDtrControl = DTR_CONTROL_DISABLE;
		if(!SetDefaultCommConfig(shownm, &ccfg, ccfgLen))
			fprintf(stderr, "Warning: can not preset default comm config (%s)\n", shownm);
	}
	else
		fprintf(stderr, "Warning: can not get default comm config (%s)\n", shownm);

	// open port
	port = CreateFile(nm, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
						 	    FILE_ATTRIBUTE_NORMAL, NULL);

	if(port == INVALID_HANDLE_VALUE) 
	{
		fprintf(stderr, "Can't open serial port %s\n", shownm);
		return -1;
	}

	// init queues
	PurgeComm(port, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);

	// prepare DCB
	dcb.DCBlength = sizeof(dcb);		// sizeof(DCB) 
	dcb.BaudRate = CBR_9600;			// current baud rate 
	dcb.fBinary = TRUE;					// binary mode, no EOF check 
	dcb.fParity = FALSE;				// disable parity checking 
	dcb.fOutxCtsFlow = FALSE;			// CTS output flow control 
	dcb.fOutxDsrFlow = FALSE;			// DSR output flow control 
	dcb.fDtrControl = DTR_CONTROL_DISABLE; // DTR flow control type 
	dcb.fDsrSensitivity = FALSE;		// DSR sensitivity 
	dcb.fTXContinueOnXoff = FALSE;		// XOFF continues Tx 
	dcb.fOutX = FALSE;					// XON/XOFF out flow control 
	dcb.fInX = FALSE;					// XON/XOFF in flow control 
	dcb.fErrorChar = FALSE;				// enable error replacement 
	dcb.fNull = FALSE;					// enable null stripping 
	dcb.fRtsControl = RTS_CONTROL_ENABLE; // RTS flow control 
	dcb.fAbortOnError = FALSE;			// abort reads/writes on error 
	dcb.XonLim = 100;					// transmit XON threshold 
	dcb.XoffLim = 100;					// transmit XOFF threshold 
	dcb.ByteSize = 8;					// number of bits/, 4-8 
	dcb.Parity = NOPARITY;				// 0-4=no,odd,even,mark,space 
	dcb.StopBits = ONESTOPBIT;			// 0,1,2 = 1, 1.5, 2 
	dcb.XonChar = 17;					// Tx and Rx XON acter 
	dcb.XoffChar = 19;					// Tx and Rx XOFF acter 
	dcb.ErrorChar = 0;					// error replacement acter 
	dcb.EofChar = 0;					// end of input acter 
	dcb.EvtChar = 0;					// received event acter 

	// speed string specified ?
	if(speed)
	{
		if(sscanf(speed, "%lu", &dcb.BaudRate) != 1)
		{
			fprintf(stderr, "Invalid speed specified (%s)\n", speed);
			return -1;
		}
	}

	if(!SetCommState(port, &dcb))
	{
		fprintf(stderr, "Can't setup serial port (%s @ %s)\n", shownm, speed);
		return -1;
	}

	if(!SetupComm(port, 512, 512))
	{
		fprintf(stderr, "Can't setup serial port queues.\n");
		return -1;
	}

	tmo.ReadIntervalTimeout = 100;		// between two characters
	tmo.ReadTotalTimeoutMultiplier = 1;
	tmo.ReadTotalTimeoutConstant = 500;
	tmo.WriteTotalTimeoutMultiplier = 1;
	tmo.WriteTotalTimeoutConstant = 1000;

	if(!SetCommTimeouts(port, &tmo))
	{
		fprintf(stderr, "Can't set serial port timeouts (%s)\n", shownm);
		return -1;
	}
	if(!SetCommMask(port, EV_TXEMPTY))
	{
		fprintf(stderr, "Can't set serial port waitmask (%s)\n", shownm);
		return -1;
	}

	// we are ready !
	EscapeCommFunction(port, CLRDTR);
	ClearCommError(port, &dwErr, &comStat);
	return 1;
}

int _close_uart(void)
{
	
	int ret = 0;
	if(port)
	{
		ret = (int)(CloseHandle(port) ? 0 : -1);
		#ifdef _DEBUG
		{
			if(ret > 0)
				DBG("Close of Comport FAILED!");
			else
				DBG("Close of Comport finished!");
		
		}
		#endif
		port = NULL;
	}
	return ret;
}

// write block, return -1=error, or number of bytes written 

int _wb(const void* data, unsigned len)
{
	DWORD wrtn;
	BOOL succ = WriteFile(port, data, len, &wrtn, NULL);
	int ret = succ ? wrtn : -1;

#ifdef _DEBUG
	{
		unsigned i;
		DBG("wb(");
		for(i=0; i<len; i++)
			DBG1("%x,", ((BYTE*)data)[i]);
		DBG1(") returned %d\n", ret);
	}
#endif

	return ret;
}

// read block, return -1=error, or number of bytes read

int _rb(void* dest, unsigned len)
{
	DWORD rd;
	BOOL succ = ReadFile(port, dest, len, &rd, NULL);
	int ret = succ ? rd : -1;

#ifdef _DEBUG
	{
		int i;
		DBG1("rb returned %d", ret);
		if(ret > 0)
			DBG(" data:");
		for(i=0; i<ret; i++)
			DBG1("%x,", ((BYTE*)dest)[i]);
		DBG("\n");
	}
#endif

	return ret;
}

// send 10 zero bits

int _send_break10(void)
{
	static const BYTE zero = 0;
	DCB dcb;
	int ret;

	if(!GetCommState(port, &dcb))
		return -1;

	dcb.Parity = EVENPARITY;
	if(!SetCommState(port, &dcb))
		return -1;

	// write hex 0
	ret = wb(&zero, 1);

	if(ret > 0)
		flush_uart(FDRAIN, 0);

	// give him a chance to finish 
	// 1ms is enough, but you never know...
	Sleep(10);

	// revert back to original state
	dcb.Parity = NOPARITY;
	if(!SetCommState(port, &dcb))
		return -1;

	return ret;
}

// flush output out=1=>discard; out>1=>wait_for_tx

int _flush_uart(int out, int in)
{
	DWORD dw;

	if(out=FDISCARD) PurgeComm(port, PURGE_TXCLEAR);
	else if(out) WaitCommEvent(port, &dw, NULL);
	if(in) PurgeComm(port, PURGE_RXCLEAR);

	return 0;
}

int _kill_zeros(int kill)
{
	DCB dcb;
	if(!GetCommState(port, &dcb))
		return -1;

	if(kill)
		dcb.fNull = TRUE;
	else
		dcb.fNull = FALSE;

	if(!SetCommState(port, &dcb))
		return -1;

	return 0;
}




