// win_blsrconvDlg.cpp : implementation file
//

#include "stdafx.h"
#include "win_blsrconv.h"
#include "win_blsrconvDlg.h"
#include "sysdep.h"
#include "hc08sprg.h"
#include "serial.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C type global functions 
extern "C" {


//#define MCU_TYPE_CNT 8

bool mcuTypeChange = false;
MCU_TYPE mcuTypeCurrent;
	int m_selFrom;
	int m_selTo;
	long m_vectbl, m_jumptbl;
	

BOOTPROTO_TYPE proto_type[] = {
	{"HC08",1},
	{"HCS08",2},
	{"Large HC08",3},
	{"ColdFire V1",4},
	{"Long HCS08",6},
	{"Kinetis",8},
	{"Large HCS08",10},
	{"Unknown",0}
};


MCU_TYPE mcu_type[] = 
{
	{0x012,	BL_HCS08,		"MC9S08AC(8/16)",					0xFFC6		,0xFDC6},
	{0x01D,	BL_HCS08,		"MC9S08AC(32-60)",					0xFFC6		,0xFDC6},		// S08ICGV4
	{0x01B,	BL_HCS08_LARGE,	"MC9S08AC(96/128)",					0xFFC6		,0xFDC6},		// S08ICGV4
	{0x008,	BL_HCS08,		"MC9S08AW(16-60)",					0xFFCC		,0xFDCC},		// S08ICGV4
//{0x000,	BL_HCS08,		"MC9S08CT16",						0xffC0		,-1	}	,									// to do vectors
	{0x00E,	BL_HCS08_LONG,	"MC9S08(DE/DN/DZ/DV/EN)(16-60)",	0xFFC0		,0xF9C0},		// S08MCGV1
	{0x019,	BL_HCS08_LONG,	"MC9S08(DZ/DV)(96/128)",			0xFF90		,0xDF90},		// S08MCGV2
	{0x002,	BL_HCS08,		"MC9S08(GB/GT)(32-60), MC1321x",	0xFFC0		,0xFDC0},		// S08ICGV4 (GT16A)
	{0x013,	BL_HCS08_LONG,	"MC9S08(EL/SL)(8/16/32)",			0xFFC0		,0xFBC0},		// S08ICSV2
	{0x016,	BL_HCS08,		"MC9S08JM(16-60)",					0xFFC0		,0xFDC0},		// S08MCGV1
	{0x00A,	BL_HCS08,		"MC9S08JR12",						0xFFC0		,0xFDC0},
	{0x00C,	BL_HCS08,		"MC9S08LC(36-60)",					0xFFD2		,0xFDD2},		// S08ICGV4
	{0x021,	BL_HCS08,		"MC9S08LL(8/16)",					0xFFD8		,0xFDD8},		// S08ICSV3
	{0x026,	BL_HCS08_LONG,  "MC9S08(LL/LH)(36/64)",				0xFFD2		,0xFDD2},	// S08ICSV3
	{0x027,	BL_HCS08,		"MC9S08MP(12-16)",					0xFFC0		,0xFDC0},		// S08ICSV3
	{0x011,	BL_HCS08,		"MC9S08QD(4/8)",					0xFFC0		,0xFDC0},		// S08ICSV1
	{0x015,	BL_HCS08_LARGE,	"MC9S08QE(64/96/128)",				0xFFC0		,0xFBA0},		// S08ICSV3
	{0x009,	BL_HCS08,		"MC9S08QG(4/8)",					0xFFC0		,0xFDC0},		// S08ICSV1
	{0x010,	BL_HCS08,		"MC9S08RA16",						0xFFC0		,0xFDC0},
	{0x003,	BL_HCS08,		"MC9S08(RC/RD/RE)(8/16)",			0xFFC0		,0xFDC0},		// xtal
	{0x003,	BL_HCS08,		"MC9S08(RC/RD/RE/RG)(32-60)",		0xFFC0		,0xFDC0},		// xtal
//{0x006,	BL_HCS08,		"MC3S08RX32",						0xFFC0		,0xFDC0},
//{0x007,	BL_HCS08,		"MC3S08RE16",						0xFFC0		,0xFDC0},
	{0x02B,	BL_HCS08,		"MC9S08SC4",						0xFFC0		,0xFDC0},		// S08ICSV3
	{0x014,	BL_HCS08,		"MC9S08(SG/SH)(4/8)",				0xFFC0		,0xFDC0},		// S08ICSV2
	{0x01A,	BL_HCS08,		"MC9S08(SG/SH)(16/32)",				0xFFC0		,0xFDC0},		// S08ICSV2
	{0x025,	BL_HCS08,		"MC9S08SE(4/8)",					0xFFC0		,0xFDC0},		// S08ICSV3
	{0x028,	BL_HCS08_LARGE,	"MC1323x",							0xFFC0		,0xFBA0},		// S08ICSV3
	{0xC1B,	BL_CFV1,		"MCF51AC(128/256)",					0			,0	}	,		// MCG
	{0xC05, BL_CFV1,		"MCF51AG(96/128)",					0			,0	}	,		// ICS
	{0xC2F, BL_CFV1,		"MCF51CN(64/128)",					0			,0	}	,		// MCG
	{0xC01, BL_CFV1,		"MCF51EM32 development device",		0			,0	}	,		// ICS
	{0xC02, BL_CFV1,		"MCF51EM(256/128)",					0			,0	}	,		// ICS
	{0xC03, BL_CFV1,		"MCF51EM32",						0			,0	}	,		// ICS
	{0xC16,	BL_CFV1,		"MCF51JM(64/128) CAU disabled",		0			,0	}	,		// S08MCGV3
	{0xC17,	BL_CFV1,		"MCF51JM(64/128) CAU enabled",		0			,0	}	,		// S08MCGV3
	{0xC15,	BL_CFV1,		"MCF51QE(32/64/128)",				0			,0	}	,		// S08ICSV3
	{0x08A,	BL_CFV1,		"MCF52252(CAF66)(256)",				0			,0	}	,
	{0x086,	BL_CFV1,		"MCF52252(AF80)(256)",				0			,0	}	,
	{0x083,	BL_CFV1,		"MCF52254(AF80)(512)",				0			,0	}	,
	{0x087,	BL_CFV1,		"MCF52254(CAF80)(512)",				0			,0	}	,
	{0x091,	BL_CFV1,		"MCF52255(CAF80)(512)",				0			,0	}	,
	{0x090,	BL_CFV1,		"MCF52256(CAG66,CVN66)(256)",		0			,0	}	,
	{0x08E,	BL_CFV1,		"MCF52256(AG80,VN80)(256)",			0			,0	}	,
	{0x08B,	BL_CFV1,		"MCF52258(AG80,VN80)(512)",			0			,0	}	,
	{0x08F,	BL_CFV1,		"MCF52258(CAG66,CVN66)(512)",		0			,0	}	,
	{0x092, BL_CFV1,		"MCF52259(CAG80,CVN80)(512)",		0			,0	}	,
	{0x093,	BL_CFV1,		"MCF52268(AG80,VN80)(512)",			0			,0	}	,
	{0x100,	BL_KINETIS,		"Kinetis Kxx - 32KB",				0			,0x800}	,
	{0x100,	BL_KINETIS,		"Kinetis Kxx - 64KB",				0			,0x800}	,
	{0x100,	BL_KINETIS,		"Kinetis Kxx - 128KB",				0			,0x1000},
	{0x100,	BL_KINETIS,		"Kinetis Kxx - 256KB",				0			,0x2000},
	{0x100,	BL_KINETIS,		"Kinetis Kxx - 512KB",				0			,0x4000},
	{0x000,	0,				"Custom",							-1			,-1	}	,
	{SDID_UNDEF,BL_UNKNOWN,	"unknown derivative",				-1			,-1	}		// last entry do not remove
};





int Get_McuTypeIx(CString text)
{
	int i = 0;
	
	while(mcu_type[i].sdid != SDID_UNDEF)
	{
		if(text == mcu_type[i].name)
			return i; 
		i++;
	}

	return -1;
}

int Get_BootProtoIx(CString text)
{
	int i = 0;
	
	while(proto_type[i].index != 0)
	{
		if(text == proto_type[i].name)
			return i; 
		i++;
	}

	return -1;
}

int Get_BootProtoIxByType(int type)
{
	int i = 0;
	
	while(proto_type[i].index != 0)
	{
		if(type == proto_type[i].index)
			return i; 
		i++;
	}

	return -1;
}
}

// Cwin_blsrconvDlg dialogclass Cwin_blsrconvDlg : public CDialog

Cwin_blsrconvDlg::Cwin_blsrconvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cwin_blsrconvDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_FSL_ICON);
}

void Cwin_blsrconvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CTMS19, m_cbCtmAppS19);
	DDX_Control(pDX, IDC_COMBO_BOOTS19, m_cbBootAppS19);
	DDX_Control(pDX, IDC_COMBO_MCUTYPE, m_cbMcuType);
	DDX_Control(pDX, IDC_EDIT_OUTS19, m_edbOutputS19);
	DDX_Control(pDX, IDC_EDIT_ORIGVECT, m_edbOrigVect);
	DDX_Control(pDX, IDC_EDIT_REDIRVECT, m_edbRedirectVect);
	DDX_Control(pDX, IDC_BUTTON_CONVERT, m_btConvert);
	DDX_Control(pDX, IDC_EDIT_LOG, m_edbLog);
	DDX_Control(pDX, IDC_COMBO_BOOTPROTO, m_cbBootProto);
}

BEGIN_MESSAGE_MAP(Cwin_blsrconvDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP

	ON_BN_CLICKED(IDC_BUTTON_OPENCTMS19, &Cwin_blsrconvDlg::OnBnClickedButtonOpenctms19)
	ON_BN_CLICKED(IDC_BUTTON_OPENBOOTS19, &Cwin_blsrconvDlg::OnBnClickedButtonOpenboots19)
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, &Cwin_blsrconvDlg::OnBnClickedButtonConvert)
	ON_CBN_SELCHANGE(IDC_COMBO_CTMS19, &Cwin_blsrconvDlg::OnCbnSelchangeComboCtms19)
	ON_CBN_SELCHANGE(IDC_COMBO_MCUTYPE, &Cwin_blsrconvDlg::OnCbnSelchangeComboMcutype)
	ON_CBN_SELCHANGE(IDC_COMBO_BOOTS19, &Cwin_blsrconvDlg::OnCbnSelchangeComboBoots19)
	ON_EN_CHANGE(IDC_EDIT_OUTS19, &Cwin_blsrconvDlg::OnEnChangeEditOuts19)
	ON_EN_CHANGE(IDC_EDIT_ORIGVECT, &Cwin_blsrconvDlg::OnEnChangeEditOrigvect)
	ON_EN_CHANGE(IDC_EDIT_REDIRVECT, &Cwin_blsrconvDlg::OnEnChangeEditRedirvect)
	ON_CBN_SELCHANGE(IDC_COMBO_BOOTPROTO, &Cwin_blsrconvDlg::OnCbnSelchangeComboBootproto)
END_MESSAGE_MAP()


// Cwin_blsrconvDlg message handlers

BOOL Cwin_blsrconvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	int i = 0;

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	
	
	while(mcu_type[i].sdid != SDID_UNDEF)
	{
		m_cbMcuType.AddString(mcu_type[i++].name);
	}

	i = 0;

	while(proto_type[i].index != 0)
	{
		m_cbBootProto.AddString(proto_type[i++].name);
	}

	m_cbMcuType.SetCurSel(0);
	OnCbnSelchangeComboMcutype();
	OnCbnSelchangeComboBootproto();
	(void)IsConvertPossible();

	char tmpText[1024];

	sprintf(tmpText, "Freescale - Universal S19 files merge tool - AN2295 %s", an2295Version);
	
	SetWindowText( tmpText );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cwin_blsrconvDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cwin_blsrconvDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
m_cbCtmAppS19
m_cbBootAppS19
m_cbMcuType
m_edbOutputS19
m_edbOrigVect
m_edbRedirectVect
m_btConvert
m_edbLog
*/

bool Cwin_blsrconvDlg::IsConvertPossible(void)
{
	CString tmpStr;
	int tmpInt;
	bool res = true;
	
	if(m_cbCtmAppS19.GetCurSel() >= 0)
	{
		m_cbCtmAppS19.GetLBText(m_cbCtmAppS19.GetCurSel(), tmpStr);
		if(tmpStr.GetLength() == 0)
			res = false;
	}else
		res = false;

	if(m_cbBootAppS19.GetCurSel() >= 0)
	{
		m_cbBootAppS19.GetLBText(m_cbBootAppS19.GetCurSel(), tmpStr);
		if(tmpStr.GetLength() == 0)
			res = false;
	}else
		res = false;

	m_edbOutputS19.GetWindowTextA(tmpStr);
	if(tmpStr.GetLength() == 0)
		res = false;

	if(m_cbMcuType.GetCurSel() < 0)
		res = false;
	
	if(m_cbBootProto.GetCurSel() >= 0)
	{
		m_cbBootProto.GetLBText(m_cbBootProto.GetCurSel(), tmpStr);
		
		if(proto_type[Get_BootProtoIx(tmpStr)].index == 0) // to do
			res = false;
	}else
		res = false;
	

	m_edbOrigVect.GetWindowTextA(tmpStr);
	if(sscanf(tmpStr, "%x", &tmpInt) < 0)
		res = false;
	else if((tmpInt > MAX_ADDRESS) || (tmpInt < 0))
		res = false;


	m_edbRedirectVect.GetWindowTextA(tmpStr);
	if(sscanf(tmpStr, "%x", &tmpInt) < 0)
		res = false;
	else if((tmpInt > MAX_ADDRESS) || (tmpInt < 0))
		res = false;


	m_btConvert.EnableWindow(res);


	return res;
}

void Cwin_blsrconvDlg::CreateOutputFileName(CString appPathName)
{
	char tmpName[1024],tmpOutFile[1024];
	char * pCh;
	CString tmpstr;
	
	m_edbOutputS19.GetWindowTextA(tmpstr);
	
	if( tmpstr.GetLength() > 0)
	{
		if(MessageBox("Do you want to replace output file name automatically?.", "Information",  MB_ICONQUESTION | MB_YESNO) == IDNO)
			return;
	}


	strcpy(tmpOutFile, appPathName);
	
	pCh = (char*)strrchr(tmpOutFile,'\\');

	if(pCh == NULL)
	{
		// set any default path of output s19 file
		m_edbOutputS19.SetWindowTextA("C:\\AN2295_GenApp.s19");
	}else
	{
		pCh++;
		strcpy(tmpName, "AN2295_Boot_");
		strcat(tmpName, pCh);
		*pCh = 0;

		strcat(tmpOutFile, tmpName);
		m_edbOutputS19.SetWindowTextA(tmpOutFile);
	}

}

void Cwin_blsrconvDlg::OnBnClickedButtonOpenctms19()
{
	CString fileName,pathName;
	
	int idx;

	CFileDialog dlg(TRUE,NULL,NULL,(OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT),_T("S19 files (*.s19;*.sx;*.srec)|*.s19; *.sx; *.srec|MOT files (*.mot)|*.mot|All files (*.*)|*.*||"));
	
	if(dlg.DoModal() == IDOK)
	{
		pathName = dlg.GetPathName();
		fileName=dlg.GetFileName();
		m_cbCtmAppS19.AddString((LPCTSTR)pathName);
		idx = m_cbCtmAppS19.FindString(0, pathName);
		m_cbCtmAppS19.SetCurSel(idx);

		CreateOutputFileName(pathName);

		// fill up default name of output file
		(void)IsConvertPossible();
		
	}
}

void Cwin_blsrconvDlg::OnBnClickedButtonOpenboots19()
{
		CString fileName,pathName;
	int idx;

	CFileDialog dlg(TRUE,NULL,NULL,(OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT),_T("S19 files (*.s19;*.sx;*.srec)|*.s19; *.sx; *.srec|MOT files (*.mot)|*.mot|All files (*.*)|*.*||"));
	
	if(dlg.DoModal() == IDOK)
	{
		pathName = dlg.GetPathName();
		fileName=dlg.GetFileName();
		m_cbBootAppS19.AddString((LPCTSTR)pathName);
		idx = m_cbBootAppS19.FindString(0, pathName);
		m_cbBootAppS19.SetCurSel(idx);		
		(void)IsConvertPossible();
	}
}




void Cwin_blsrconvDlg::OnCbnSelchangeComboCtms19()
{
	CString tmpstr;

	m_cbCtmAppS19.GetWindowTextA(tmpstr);
	CreateOutputFileName(tmpstr);

	(void)IsConvertPossible();	
}

void Cwin_blsrconvDlg::OnCbnSelchangeComboMcutype()
{
	char tmpStr[32], tmpStr1[32];

	mcuTypeChange = true;

	m_cbMcuType.GetLBText(m_cbMcuType.GetCurSel(), tmpStr);
	
	sprintf(tmpStr1,"%x", mcu_type[Get_McuTypeIx(tmpStr)].originalIT);
	
	m_edbOrigVect.SetWindowTextA(tmpStr1);
	
	sprintf(tmpStr1,"%x", mcu_type[Get_McuTypeIx(tmpStr)].relocatedIT);

	m_edbRedirectVect.SetWindowTextA(tmpStr1);
	
	m_cbBootProto.SetCurSel(Get_BootProtoIxByType(mcu_type[Get_McuTypeIx(tmpStr)].index));

	OnCbnSelchangeComboBootproto();

	mcuTypeCurrent = mcu_type[Get_McuTypeIx(tmpStr)];

	mcuTypeChange = false;

	(void)IsConvertPossible();
}

void Cwin_blsrconvDlg::OnCbnSelchangeComboBoots19()
{
	// TODO: Add your control notification handler code here
	(void)IsConvertPossible();
}

void Cwin_blsrconvDlg::OnEnChangeEditOuts19()
{
	(void)IsConvertPossible();
}

void Cwin_blsrconvDlg::OnEnChangeEditOrigvect()
{
	CString tmpStr;
	int tmpInt;

	if(mcuTypeChange == false)
		m_cbMcuType.SetCurSel(Get_McuTypeIx("Custom"));
	

	(void)IsConvertPossible();
	
	m_edbOrigVect.GetWindowTextA(tmpStr);
	if(sscanf(tmpStr, "%x", &tmpInt) > 0)
		m_vectbl = tmpInt;
}

void Cwin_blsrconvDlg::OnEnChangeEditRedirvect()
{
	CString tmpStr;
	int tmpInt;

	if(mcuTypeChange == false)
		m_cbMcuType.SetCurSel(Get_McuTypeIx("Custom"));

	(void)IsConvertPossible();

	m_edbRedirectVect.GetWindowTextA(tmpStr);
	if(sscanf(tmpStr, "%x", &tmpInt) > 0)
		m_jumptbl = tmpInt;

		
}

void Cwin_blsrconvDlg::OnCbnSelchangeComboBootproto()
{
	CString tmpStr;
	if(mcuTypeChange == false)
		m_cbMcuType.SetCurSel(Get_McuTypeIx("Custom"));

	m_cbBootProto.GetWindowTextA(tmpStr);
	bl_version = proto_type[Get_BootProtoIx(tmpStr.GetBuffer())].index;
	//	m_cbBootProto.SetCurSel(Get_BootProtoIxByType(mcu_type[Get_McuTypeIx(tmpStr)].index));	

	(void)IsConvertPossible();
}

void Cwin_blsrconvDlg::OnBnClickedButtonConvert()
{
	char tmpStr[1024];
	char tmpStr1[1024];
	CString tmpCString;

	SHFILEINFO shFileInfo;

	
	m_edbOutputS19.GetWindowTextA(tmpCString);

	if(SHGetFileInfo((LPCSTR)tmpCString.GetBuffer(), 0, &shFileInfo, sizeof(SHFILEINFO), SHGFI_TYPENAME) != 0)
	{
		if(MessageBox("The output file exist, do you want to continue?", "Conversion Warning",  MB_ICONWARNING | MB_YESNO) == IDNO)
			return;
	}

	Prog_ResetWarnings();
	reset_S19image(&image);

	m_cbCtmAppS19.GetLBText(m_cbCtmAppS19.GetCurSel(), tmpStr);
	m_cbBootAppS19.GetLBText(m_cbBootAppS19.GetCurSel(), tmpStr1);
	
	LogResetReplaceLine();

	myprintf("Start of S19 merge of files:\r\nApplication: %s\r\nBootloder:%s\n", tmpStr, tmpStr1);


	// read S19 file
	
	myprintf("\r\n");
	myprintf("Start parsing and checking of Application S19 file.\n");
	myprintf("\r\n");
	
	if(read_s19(tmpStr, &image) < 0)
	{
		MessageBox("Reading User application S19 file failed.", "Conversion Fatal Error",  MB_ICONERROR | MB_OK);
		return;
	}

	myprintf("Masquerading vector table of Application S19 file.\n");
	myprintf("\r\n");
	
	if(setup_vect_tbl(m_vectbl, m_jumptbl) < 0)
	{
		MessageBox("Masquerading vector table failed.", "Conversion Fatal Error",  MB_ICONERROR | MB_OK);
		return;
	}	
	myprintf("\r\n");
	// read Bootloader application S19 file

	myprintf("Start parsing and checking of Bootloader S19 file.\n");
	myprintf("\r\n");
	if(read_s19(tmpStr1, &image) < 0)
	{
		MessageBox("Reading Bootloader S19 file failed.", "Conversion Fatal Error",  MB_ICONERROR | MB_OK);
		return;
	}



	LogResetReplaceLine();

	// write S19 file
	//m_edbOutputS19.GetWindowTextA(tmpCString);
	myprintf("\r\n");
	myprintf("Start of writing output file:\r\n%s", tmpCString);
	myprintf("\r\n");

	if(write_s19(tmpCString.GetBuffer(), &image) < 0)
	{
		MessageBox("Writing final output S19 file failed.", "Conversion Fatal Error",  MB_ICONERROR | MB_OK);
		return;
	}
	
	if(S19_GetWarnings() + Prog_GetWarningsCnt())
	{
		myprintf("\nOperation finished with warnings.");
		myprintf("\n************************************************************");
		myprintf("\n S19 files parsing warnings: %d. ", S19_GetWarnings());
		myprintf("\n Masquerading vector table warnings: %d. ", Prog_GetWarningsCnt());
		myprintf("\n************************************************************");
		
	}else
		myprintf("\nOperation finished succesfully.");
	
	LogResetReplaceLine();
	myprintf("\r\n");
}

void Cwin_blsrconvDlg::LogClear()
{
	m_edbLog.SetSel(0, INT_MAX);
	m_edbLog.ReplaceSel("");	
}

void Cwin_blsrconvDlg::LogResetReplaceLine()
{
	m_edbLog.SetSel(INT_MAX, INT_MAX);
	m_edbLog.ReplaceSel("");
	m_edbLog.GetSel(m_selFrom, m_selTo);
}

void Cwin_blsrconvDlg::Log(LPCTSTR pszText)
{
	CString str = pszText;
	int pos;
	str.Replace("\r\n", "\n");

	pos = str.Find('\r');

	if(pos == 0)
	{
		// replace last line !
		str.Replace("\r", "");
		str.Replace("\n", "\r\n");
		m_edbLog.SetSel(m_selFrom, INT_MAX);
		m_edbLog.ReplaceSel(str);
	}else
	{
		// add new line !!
		str.Replace("\n", "\r\n");
		m_edbLog.SetSel(INT_MAX, INT_MAX);
		pos = str.Find("\r\n");
		if(pos >= 0)
		{
			m_edbLog.ReplaceSel("");
			m_edbLog.GetSel(m_selFrom, m_selTo);
		}
		m_edbLog.ReplaceSel(str);
	}	
}

Cwin_blsrconvDlg* GetMainWnd()
{
	return (Cwin_blsrconvDlg*)AfxGetMainWnd();
}

extern "C" {
	int myfprintf(__inout FILE * _File, const char * _Format, ...)
	{
		
		char tmpStr[1024];
		va_list marker;

		(void)_File;
		

		va_start(marker, _Format);
		vsnprintf(tmpStr, 1024, _Format, marker);
		va_end(marker);

		GetMainWnd()->Log(tmpStr);

		return 0;
	}

	int myprintf(const char * _Format, ...)
	{
		char tmpStr[1024];
		va_list marker;

		va_start(marker, _Format);
		vsnprintf(tmpStr, 1024, _Format, marker);
		va_end(marker);

		
		GetMainWnd()->Log(tmpStr);

		return 0;		
	}

	void progress_Changed(unsigned value)
	{
		(void)value;
	}

}