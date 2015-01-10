/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           HC08SPRG.H                                     *
*      Project:        Developper's HC08 Bootloader Master            *
*      Description:    Main header file                               *
*      Platform:       Linux/Win32                                    *
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


#ifndef _HC08SPRG_H
#define _HC08SPRG_H

#ifdef __cplusplus
extern "C" {
#endif


typedef unsigned char BYTE;

// types

#define MAX_NUM_BLOCKS	16	// max. no. of Flash blocks
#define SDID_UNDEF	-1		// end marker in SDID properties table
#define MAX_ADDRESS  0x1000000
#define MAX_LENGTH   0x100

#define SPEED_CALIB_MAX_ATTEMPS 20

enum{
	FAMILY_HC08=0,
	FAMILY_HCS08,
	FAMILY_CFV1,
	FAMILY_KINETIS,
	FAMILY_NEXT
};

#define BL_HC08			(1 << FAMILY_HC08)						// 00000001
#define BL_HC08_LARGE	(BL_HC08 | 0x1 << (FAMILY_HC08+1))		// 00000011

#define BL_HCS08		(1 << FAMILY_HCS08)						// 00000010
#define BL_HCS08_LONG	(BL_HCS08 | 0x1 << (FAMILY_HCS08+1))	// 00000110
#define BL_HCS08_LARGE	(BL_HCS08 | 0x2 << (FAMILY_HCS08+1))	// 00001010

#define BL_CFV1			(1 << FAMILY_CFV1)						// 00000100

#define BL_KINETIS		(1 << FAMILY_KINETIS)					// 00001000

#define BL_UNKNOWN		-1

#define CRC_HC08SPRG_SEED 0xffff

#define OPERATION_TIMEOUT 10

extern const char an2295Version[];

typedef struct
{
	short sdid;
	short proto;
	char* name;
	int noneVerAddrStart;
	int noneVerAddrEnd;
} 
t_sdid;


typedef struct
{
	unsigned long mem_start[MAX_NUM_BLOCKS];	// start of usable flash
	unsigned long mem_end[MAX_NUM_BLOCKS];	// end of usable flash
	unsigned long erblk;			// erase block size
	unsigned long wrblk;			// write block size
	unsigned long bl_tbl;		// start of boot-loader table (private data and jump table)
	unsigned long int_vect_tbl;	// start of hard-wired interrupt vectors
	BYTE priv_data[8];		// 8 bytes of private info
	char targ_name[40];		// target name
	unsigned num_blocks;	// number of flash memory blocks (BL protocol version 2 and up)
	unsigned sdid;			// SDID number   (BL protocol version 2 and up)
	unsigned sdidrev;		// SDID revision (BL protocol version 2 and up)
} IDENT_DATA;

typedef struct {
	BYTE d[MAX_ADDRESS];	// data
	BYTE f[MAX_ADDRESS];	// valid flag 0=empty; 1=usercode; 2=systemcode
} BOARD_MEM;

// globals

extern IDENT_DATA ident;
extern BOARD_MEM  image;
extern long g_offset;
extern int bl_version;
extern int bl_rcs;	/* read command supported flag */
extern int bl_crcs;	/* crc supported flag */
extern char * chipid; /* chip ID name */
extern int verify;
extern t_sdid sdidprops[];
extern const char bl_ver_index[];
extern char const *BL_VER_STRING[];
extern char defaultyes;
extern IDENT_DATA ident;
// shared functions

char const * Version_string(int bl_ver);
int read_s19(char *fn, BOARD_MEM* pImage);
int write_s19(char *fn, BOARD_MEM* pImage);
unsigned int S19_GetWarnings(void);
void reset_S19image(BOARD_MEM* pImage);
int hook_reset(void);
int calibrate_speed(int short_trim);
int read_mcu_info(void);
int read_mem(BOARD_MEM* pImage, int readIT);
int setup_vect_tbl(unsigned org_tbl, unsigned jump_tbl);
int	prg_mem(void);
int	prg_only_mem(void);
int	blank_check(void);
int	erase_mem(unsigned all);
int	verify_mem(int byS19_range);
int	check_image(void);
int	checksum_mem(void);
int	unhook(void);
char const * get_package_str(short sdid);
void CRC_AddByte(unsigned short *pCrc, unsigned char data);
void CRC_AddWord(unsigned short *pCrc, unsigned short data);
void CRC_Add3Bytes(unsigned short *pCrc, unsigned long data);
void CRC_AddLong(unsigned short *pCrc, unsigned long data);
void CRC_AddByteArray(unsigned short *pCrc, unsigned char* data, int size);
void CRC_AddString(unsigned short *pCrc, unsigned char* str);
void CRC_ResetCRC(unsigned short *pCrc, unsigned short seed);
unsigned short CRC_GetCRC(unsigned short *pCrc);
unsigned int S19_GetTotal(void);
unsigned short S19_GetCRC(void);
void Prog_ResetWarnings(void);
int Prog_GetWarningsCnt(void);
#ifdef __cplusplus
	}
#endif

#endif
