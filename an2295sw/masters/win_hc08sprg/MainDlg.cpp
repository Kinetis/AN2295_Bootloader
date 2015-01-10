// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "win_hc08sprg.h"
#include "MainDlg.h"
#include "my_lib.h"
#include "sysdep.h"
#include "hc08sprg.h"
#include "serial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma warning(disable : 4996)

#define printf myprintf
#define fprintf myfprintf


/*
Bootloader protocol version: 0x02 (S08, read command supported)
Bootloader version string: AC16
System device ID: 0x012 [unknown derivative] rev. 1
Number of memory blocks: 1
Memory block #1: 0xC000-0xFDC5
Erase block size: 512 bytes
Write block size:  64 bytes
Original vector table: 0xFFC6-0xFFFF
New vector table:      0xFDC6-0xFDFF

*/


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG, m_logCtrl);
	DDX_Control(pDX, IDC_COMBO_S19, m_fileS19);
	DDX_Control(pDX, IDC_COMBO_COMPORTS, m_comPorts);
	DDX_Control(pDX, IDC_CONNECT, m_btConnect);
	DDX_Control(pDX, IDC_COMBO_COMSPEED, m_cbComSpeed);
	DDX_Control(pDX, IDC_LbProtocVersion, m_lbProtocVersion);
	DDX_Control(pDX, IDC_LbMcuInfoStr, m_lbMcuInfo);
	DDX_Control(pDX, IDC_LbMem, m_lbMem);
	DDX_Control(pDX, IDC_LbFlashPrty, m_lbFlashPrty);
	DDX_Control(pDX, IDC_LbVectors, m_lbVectors);	
	DDX_Control(pDX, IDC_BT_RESCAN, m_BtRescan);
	DDX_Control(pDX, IDC_BT_OPENS19, m_BtOpenS19);
	DDX_Control(pDX, IDC_FL_ERASE, m_btErase);
	DDX_Control(pDX, IDC_FL_BCHECK, m_btCheckB);
	DDX_Control(pDX, IDC_FL_PROGRAM, m_btProg);
	DDX_Control(pDX, IDC_FL_COMPARE, m_btCompare);
	DDX_Control(pDX, IDC_FL_AUTOPROG, m_btAutoProg);
	DDX_Control(pDX, IDC_CHECK_SINGLEW, m_chbSingleWire);
	DDX_Control(pDX, IDC_EDIT_CHECKSUM, m_edbCheckSum);
	DDX_Control(pDX, IDC_CHECK_VERIFY, m_chbVerify);
	DDX_Control(pDX, IDC_EDIT_CHECKSUM2, m_edbImageSize);
	DDX_Control(pDX, IDC_PB_PROGRESS, m_pbProgress);
	DDX_Control(pDX, IDC_FL_READ, m_BtFlRead);
	DDX_Control(pDX, IDC_CHECK_SHORT_TRIM, m_chbShortTrim);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BT_RESCAN, &CMainDlg::OnBnClickedBtRescan)
	ON_BN_CLICKED(IDC_BT_OPENS19, &CMainDlg::OnBnClickedBtOpens19)
	ON_BN_CLICKED(IDC_CONNECT, &CMainDlg::OnBnClickedConnect)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_FL_PROGRAM, &CMainDlg::OnBnClickedFlProgram)
	ON_BN_CLICKED(IDC_FL_BCHECK, &CMainDlg::OnBnClickedFlBcheck)
	ON_BN_CLICKED(IDC_FL_ERASE, &CMainDlg::OnBnClickedFlErase)
	ON_BN_CLICKED(IDC_FL_AUTOPROG, &CMainDlg::OnBnClickedFlAutoprog)
	ON_BN_CLICKED(IDC_FL_COMPARE, &CMainDlg::OnBnClickedFlCompare)
	ON_BN_CLICKED(IDC_CHECK_VERIFY, &CMainDlg::OnBnClickedCheckVerify)
	ON_BN_CLICKED(IDC_FL_READ, &CMainDlg::OnBnClickedFlRead)
END_MESSAGE_MAP()


// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_cbComSpeed.SetCurSel(17);  // 115200 speed preselected
	m_BootConnected = false;


	EnableControlBtn(false);
	CMainDlg::OnBnClickedBtRescan();
	m_logCtrl.LimitText(0);

	m_pbProgress.SetRange(0, 100);
	

	m_selFrom = 0;
	m_selTo = 0;
	m_chbVerify.SetCheck(1);
	m_edbCheckSum.SetWindowTextA("0x0000");
	m_edbImageSize.SetWindowTextA("0x0 B, 0 B");
	
	char tmpText[1024];

	sprintf(tmpText, "Freescale - Universal Bootloader  AN2295 %s", an2295Version);
	
	SetWindowText( tmpText );


//m_TabMain.set

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{

	CDialog::OnSysCommand(nID, lParam);

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMainDlg::OnPaint()
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
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMainDlg::OnBnClickedBtRescan()
{
	CStringList ports;
	CString str, port, name;
	int ix, num, sel=0;
	
	m_comPorts.ResetContent();

	MgpEnumerateSystemPorts(_T("Ports"), _T("COM"), &ports);

	POSITION pos = ports.GetHeadPosition();

	while(pos)
	{
		str = ports.GetNext(pos);
		AfxExtractSubString(port, str, 0, '\n');
		AfxExtractSubString(name, str, 1, '\n');

		if(_stscanf(port, _T("COM%i"), &num) == 1)
		{
			ix = m_comPorts.AddString(name);
			m_comPorts.SetItemData(ix, (LPARAM) num);

			if(name.Find(_T("Bootloader")) >= 0)
			{
				sel = ix;
			}
		}
	}

	m_comPorts.SetCurSel(sel);
}

void CMainDlg::OnBnClickedBtOpens19()
{
	CString fileName,pathName;
	int idx;

	CFileDialog dlg(TRUE,NULL,NULL,(OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT),_T("S19 files (*.s19;*.sx;*.srec)|*.s19; *.sx; *.srec|MOT files (*.mot)|*.mot|All files (*.*)|*.*||"));
	
	if(dlg.DoModal() == IDOK)
	{
		pathName = dlg.GetPathName();
		fileName=dlg.GetFileName();
		m_fileS19.AddString((LPCTSTR)pathName);
		idx = m_fileS19.FindString(0, pathName);
		m_fileS19.SetCurSel(idx);
		//m_button_bootload.EnableWindow(true);
	}
	
}

void CMainDlg::EnableInputs(bool enable)
{
	m_BtRescan.EnableWindow(enable);
	m_BtOpenS19.EnableWindow(enable);
	m_fileS19.EnableWindow(enable);
	m_comPorts.EnableWindow(enable);
	m_cbComSpeed.EnableWindow(enable);
	m_chbSingleWire.EnableWindow(enable);
	m_chbShortTrim.EnableWindow(enable);
	if(enable)
		m_edbImageSize.SetWindowTextA("0x0 B, 0 B");
}

void CMainDlg::EnableControlBtn(bool enable)
{
	m_btErase.EnableWindow(enable);
	m_btProg.EnableWindow(enable);
	m_btAutoProg.EnableWindow(enable);
	if (!bl_rcs)
		enable = false;
	m_chbVerify.EnableWindow(enable);
	m_btCheckB.EnableWindow(enable);
	m_btCompare.EnableWindow(enable);
	m_BtFlRead.EnableWindow(enable);
}

void CMainDlg::OnBnClickedConnect()
{
	CBusy busy;

	progress_Changed(0);

	if(!m_BootConnected)
	{
		// Unconnected state => try to connect to bootloader
		char tmpstrCom[512];
		char tmpstr[1024];
		CString tmpStrFormat;
		EnableInputs(false);		

		;

		if(m_fileS19.GetLBText(m_fileS19.GetCurSel(),tmpstr) < 0)
		{
			EnableInputs(true);
			printf("S19 file must be selected!\n");
			return;
		}

		if(m_comPorts.GetLBText(m_comPorts.GetCurSel(),tmpstr) < 0)
		{
			EnableInputs(true);
			printf("Serial Com Port must be selected!\n");
			return;
		}

		if(m_cbComSpeed.GetLBText(m_cbComSpeed.GetCurSel(),tmpstr) < 0)
		{
			EnableInputs(true);
			printf("Speed of serial ComPort must be selected!\n");
			return;
		}

		// Dual mode !!!
		

		if(m_chbSingleWire.GetCheck())
		{
			if(m_chbVerify.GetCheck())
				tmpStrFormat = "COM%d!S";
			else
				tmpStrFormat = "COM%d!s";
		}else
		{
			if(m_chbVerify.GetCheck())
				tmpStrFormat = "COM%d!D";
			else
				tmpStrFormat = "COM%d!d";
		}
		
		sprintf(tmpstrCom, tmpStrFormat, (int)m_comPorts.GetItemData(m_comPorts.GetCurSel()));
		m_cbComSpeed.GetLBText(m_cbComSpeed.GetCurSel(),tmpstr);

		// open serial port 
		if(init_uart(tmpstrCom, tmpstr) < 0)
		{	
			EnableInputs(true);
			return;
		}
		LogResetReplaceLine();
		// wait for reset
		if(hook_reset() < 0) 
		{
			close_uart();
			EnableInputs(true);
			return;
		}
		LogResetReplaceLine();
		
		// calibrate target's oscilator
		if(calibrate_speed(m_chbShortTrim.GetCheck()) < 0)
		{
			close_uart();
			EnableInputs(true);
			return;
		}
		LogResetReplaceLine();

		// read info
		if(!read_mcu_info())
		{
			printf("\nBootloader protocol version: 0x%02X (%s, ", bl_version , Version_string(bl_version));
			printf("read command ");
			if (!bl_rcs) printf("NOT ");
			printf("supported)\n");
			printf("CRC protocol ");
			if (!bl_crcs) printf("NOT ");
			printf("supported)\n");
			printf("Bootloader version string: %s\n", ident.targ_name);

			if (!bl_rcs)
				m_chbVerify.SetCheck(0);

			if (bl_version == BL_HC08) // HC08
			{
				unsigned i;
				printf("Available flash memory: 0x%04X-0x%04X\n", ident.mem_start[0], ident.mem_end[0]-1);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				printf("Original vector table: 0x%04X\n",ident.int_vect_tbl);
				printf("Bootloader user table: 0x%04X\n",ident.bl_tbl);
				printf("Bootloader data (hex): ");
				for(i=0; i<sizeof(ident.priv_data); i++)
					printf("%02x ", ident.priv_data[i]);
				printf("\n");
			}
			else if (bl_version == BL_HCS08) // S08
			{
				unsigned i;
				printf("System device ID: 0x%03X [%s] rev. %u\n", ident.sdid, chipid ,ident.sdidrev);
				printf("Number of memory blocks: %u\n", ident.num_blocks);
				for(i=0; i<ident.num_blocks; i++)
					printf("Memory block #%u: 0x%04X-0x%04X\n", i+1, ident.mem_start[i], ident.mem_end[i]-1);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				printf("Original vector table: 0x%04X-0xFFFF\n",ident.int_vect_tbl);
				printf("New vector table:      0x%04X-0x%04X\n",ident.bl_tbl, ident.bl_tbl+(0xFFFF-ident.int_vect_tbl));
			}
			else if (bl_version == BL_HC08_LARGE)	// large HC08
			{
				unsigned i;
				printf("Number of memory blocks: %u\n", ident.num_blocks);
				for(i=0; i<ident.num_blocks; i++)
					printf("Memory block #%u: 0x%04X-0x%04X\n", i+1, ident.mem_start[i], ident.mem_end[i]-1);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				printf("Original vector table: 0x%04X\n",ident.int_vect_tbl);
				printf("Bootloader user table: 0x%04X\n",ident.bl_tbl);
			}
			else if ((bl_version == BL_HCS08_LARGE) || (bl_version == BL_HCS08_LONG))// large + long S08
			{
				unsigned i;
				printf("System device ID: 0x%03X [%s] rev. %u\n", ident.sdid, chipid ,ident.sdidrev);
				printf("Number of memory blocks: %u\n", ident.num_blocks);
				for(i=0; i<ident.num_blocks; i++)
					printf("Memory block #%u: 0x%06X-0x%06X\n", i+1, ident.mem_start[i], ident.mem_end[i]-1);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				printf("Original vector table: 0x%04X\n",ident.int_vect_tbl);
				printf("Bootloader user table: 0x%04X\n",ident.bl_tbl);
			}
			else if (bl_version == BL_CFV1) // CFV1
			{
				unsigned i;
				printf("System device ID: 0x%03X [%s] rev. %u\n", ident.sdid, chipid ,ident.sdidrev);
				printf("Number of memory blocks: %u\n", ident.num_blocks);
				for(i=0; i<ident.num_blocks; i++)
					printf("Memory block #%u: 0x%08X-0x%08X\n", i+1, ident.mem_start[i], ident.mem_end[i]);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				if (ident.int_vect_tbl != NULL) 
				{
    				printf("Original vector table: 0x%08X-0x%08X\n",NULL, ident.int_vect_tbl-1);
    				printf("New vector table: 0x%08X-0x%08X\n",ident.bl_tbl,ident.bl_tbl+ident.int_vect_tbl-1);
				} else
    				printf("Vector table not relocated\n");
			}
			else if (bl_version == BL_KINETIS) // Kinetis
			{
				unsigned i;
				printf("System device ID: 0x%03X [%s] rev. %u\n", ident.sdid, chipid ,ident.sdidrev);
				printf("Kinetis Package: %s .\n", get_package_str(ident.sdid));
				printf("Number of memory blocks: %u\n", ident.num_blocks);
				for(i=0; i<ident.num_blocks; i++)
					printf("Memory block #%u: 0x%08X-0x%08X\n", i+1, ident.mem_start[i], ident.mem_end[i]);
				printf("Erase block size: %3d bytes\n", ident.erblk);
				printf("Write block size: %3d bytes\n", ident.wrblk);
				printf("Original vector table: 0x%08X-0x%08X\n",ident.int_vect_tbl,ident.int_vect_tbl + 0x3FF);
				printf("New vector table: 0x%08X-0x%08X\n",ident.bl_tbl, ident.bl_tbl + 0x3FF);
				
			}
			else
			{
				fprintf(stderr, "This version [0x%02X] of protocol is not (yet) supported! Check AN2295SW for update!\n", bl_version);
				close_uart();
				EnableInputs(true);
				return;
			}
		}
		else 
		{
			fprintf(stderr, "Can't read MCU info. Could be protocol error.\n");
			fprintf(stderr, "(Or forgot to set single wire mode?)\n");
			close_uart();
			EnableInputs(true);
			return;
		}
		
		printf("\nS19 Image Control.\n");
		LogResetReplaceLine();
		// read S19 file
		
		reset_S19image(&image);

		m_fileS19.GetLBText(m_fileS19.GetCurSel(),tmpstr);
		if(read_s19(tmpstr, &image) < 0)
		{
			close_uart();
			EnableInputs(true);
			return;
		}
		
		sprintf(tmpstrCom, "0x%04x", S19_GetCRC());
		
		m_edbCheckSum.SetWindowTextA(tmpstrCom);
		
		if(S19_GetTotal() > 1024)
			sprintf(tmpstrCom, "0x%x B, %d KB", S19_GetTotal(), S19_GetTotal()/1024);
		else
			sprintf(tmpstrCom, "0x%x B, %d B", S19_GetTotal(), S19_GetTotal());
		
		m_edbImageSize.SetWindowTextA(tmpstrCom);
		LogResetReplaceLine();
		// masquerade vector table
		if(setup_vect_tbl(ident.int_vect_tbl , ident.bl_tbl) < 0)
		{
			close_uart();
			EnableInputs(true);
			return;
		}
		
		LogResetReplaceLine();
		// check if code goes to valid memory only - issue warning only, but continue! (r30323)
		check_image();

	
		LogResetReplaceLine();
		printf("\n ");
		printf("\n ");
		m_btConnect.SetWindowTextA("Quit/&Run");
		m_BootConnected = true;
		FillUpIdentification();
		EnableControlBtn(true);
	}else
	{
		// Connected state => Quit and run MCU application		
		unhook();
		LogResetReplaceLine();
		close_uart();
		m_btConnect.SetWindowTextA("Connect");
		EnableInputs(true);
		m_BootConnected = false;
		FillUpIdentification();
		EnableControlBtn(false);
		//LogClear();
	}
}

void CMainDlg::OnClose()
{
	if(m_BootConnected)
		OnBnClickedConnect();
	
	close_uart();

	CDialog::OnClose();
}

void CMainDlg::LogClear()
{
	m_logCtrl.SetSel(0, INT_MAX);
	m_logCtrl.ReplaceSel("");	
}

void CMainDlg::LogResetReplaceLine()
{
	m_logCtrl.SetSel(INT_MAX, INT_MAX);
	m_logCtrl.ReplaceSel("");
	m_logCtrl.GetSel(m_selFrom, m_selTo);
}

void CMainDlg::ProgressChanged(unsigned value)
{
	m_pbProgress.SetPos(value);
	m_pbProgress.RedrawWindow();
}

void CMainDlg::Log(LPCTSTR pszText)
{
	CString str = pszText;
	int pos;
	str.Replace("\r\n", "\n");

	pos = str.Find('\r');

	if(pos >= 0)
	{
		// replace last line !
		str.Replace("\r", "");
		str.Replace("\n", "\r\n");
		m_logCtrl.SetSel(m_selFrom, INT_MAX);
		m_logCtrl.ReplaceSel(str);
	}else
	{
		// add new line !!
		str.Replace("\n", "\r\n");
		m_logCtrl.SetSel(INT_MAX, INT_MAX);
		pos = str.Find("\r\n");
		if(pos >= 0)
		{
			m_logCtrl.ReplaceSel("");
			m_logCtrl.GetSel(m_selFrom, m_selTo);
		}
		m_logCtrl.ReplaceSel(str);
	}
	
	//m_logCtrl.RedrawWindow();
	
	


	
	
}

CMainDlg* GetMainWnd()
{
	return (CMainDlg*)AfxGetMainWnd();
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
		GetMainWnd()->ProgressChanged(value);
	}

}
void CMainDlg::OnBnClickedFlProgram()
{
	CBusy busy;

	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	prg_only_mem(); // to do what to do if error occured 	
	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}



void CMainDlg::FillUpIdentification()
{
	if(m_BootConnected)
	{
		char tmpStr[1024];
		char tmpStr1[1024];

		
			
		
		
		sprintf(tmpStr, "ver:0x%02X - %s, Read command %s, Protocol secure: %s .", bl_version , Version_string(bl_version), (bl_rcs)? "supported":"NOT supported", (bl_crcs)? "CRC_CCITT":"none");	
		m_lbProtocVersion.SetWindowTextA(tmpStr);
		

		if (bl_version == BL_HC08) // HC08
		{			
			sprintf(tmpStr, "HC08 - %s.", ident.targ_name);	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: 1. #1: 0x%04X-0x%04X", ident.mem_start[0], ident.mem_end[0]-1);	
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes//%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Original: 0x%04X. Application: 0x%04X", ident.int_vect_tbl, ident.int_vect_tbl);	
			m_lbVectors.SetWindowTextA(tmpStr);			
		}	
		else if (bl_version == BL_HCS08) // S08
		{
			sprintf(tmpStr, "HCS08 - %s, 0x%03X [%s] %u.", ident.targ_name, ident.sdid, chipid ,ident.sdidrev);	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: %d. #1: 0x%04X-0x%04X", ident.num_blocks, ident.mem_start[0], ident.mem_end[0]-1);	
			if(ident.num_blocks > 1)
			{
				sprintf(tmpStr1, ", #2: 0x%04X-0x%04X %s", ident.mem_start[1], ident.mem_end[1]-1, (ident.num_blocks > 2)? ", ...":"");
				strcat(tmpStr, tmpStr1);
			}
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes//%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Original: 0x%04X-0xFFFF. Application: 0x%04X-0x%04X", ident.int_vect_tbl, ident.bl_tbl, ident.bl_tbl + (0xFFFF - ident.int_vect_tbl));	
			m_lbVectors.SetWindowTextA(tmpStr);
			
			/*
			sprintf(tmpStr, "0x%03X [%s] %u", ident.sdid, chipid ,ident.sdidrev);
			m_LbDevId.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%u", ident.num_blocks);
			m_LbMemBlkCnt.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0x%04X", ident.mem_start[0], ident.mem_end[0]-1);
			m_LbMemBlk1.SetWindowTextA(tmpStr);
			if(ident.num_blocks > 1)			
			{
				sprintf(tmpStr, "0x%04X-0x%04X", ident.mem_start[1], ident.mem_end[1]-1);
				m_LbMemBlk2.SetWindowTextA(tmpStr);	
			}
			else
				m_LbMemBlk2.SetWindowTextA("Not Available");
			
			sprintf(tmpStr, "%3d bytes", ident.erblk);
			m_LbEraseBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%3d bytes", ident.wrblk);
			m_LbWriteBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0xFFFF", ident.int_vect_tbl);
			m_LbVectTableOrig.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0x%04X\n", ident.bl_tbl, ident.bl_tbl+(0xFFFF-ident.int_vect_tbl));
			m_LbVectTableNew.SetWindowTextA(tmpStr);*/

		}
		
		else if (bl_version == BL_HC08_LARGE)	// large HC08
		{
			sprintf(tmpStr, "HC08 - %s.", ident.targ_name);	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: %d. #1: 0x%04X-0x%04X", ident.num_blocks, ident.mem_start[0], ident.mem_end[0]-1);	
			if(ident.num_blocks > 1)
			{
				sprintf(tmpStr1, ", #2: 0x%04X-0x%04X %s", ident.mem_start[1], ident.mem_end[1]-1, (ident.num_blocks > 2)? ", ...":"");
				strcat(tmpStr, tmpStr1);
			}
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes//%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Original: 0x%04X. Application: 0x%04X", ident.int_vect_tbl, ident.int_vect_tbl);	
			m_lbVectors.SetWindowTextA(tmpStr);
			/*
			m_LbDevId.SetWindowTextA("Not Available");	
			sprintf(tmpStr, "%u", ident.num_blocks);
			m_LbMemBlkCnt.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0x%04X", ident.mem_start[0], ident.mem_end[0]-1);
			m_LbMemBlk1.SetWindowTextA(tmpStr);
			if(ident.num_blocks > 1)			
			{
				sprintf(tmpStr, "0x%04X-0x%04X", ident.mem_start[1], ident.mem_end[1]-1);
				m_LbMemBlk2.SetWindowTextA(tmpStr);	
			}
			else
				m_LbMemBlk2.SetWindowTextA("Not Available");	
			sprintf(tmpStr, "%3d bytes", ident.erblk);
			m_LbEraseBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%3d bytes", ident.wrblk);
			m_LbWriteBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X", ident.int_vect_tbl);
			m_LbVectTableOrig.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X", ident.bl_tbl);
			m_LbVectTableNew.SetWindowTextA(tmpStr);			
			*/
		}
		else if ((bl_version == BL_HCS08_LARGE) || (bl_version == BL_HCS08_LONG))// large + long S08
		{
			sprintf(tmpStr, "HCS08 - %s, 0x%03X [%s] %u.", ident.targ_name, ident.sdid, chipid ,ident.sdidrev);	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: %d. #1: 0x%06X-0x%06X", ident.num_blocks, ident.mem_start[0], ident.mem_end[0]-1);	
			if(ident.num_blocks > 1)
			{
				sprintf(tmpStr1, ", #2: 0x%06X-0x%06X %s", ident.mem_start[1], ident.mem_end[1]-1, (ident.num_blocks > 2)? ", ...":"");
				strcat(tmpStr, tmpStr1);
			}
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes//%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Original: 0x%04X-0xFFFF. Application: 0x%04X-0x%04X", ident.int_vect_tbl, ident.bl_tbl, ident.bl_tbl + (0xFFFF - ident.int_vect_tbl));	
			m_lbVectors.SetWindowTextA(tmpStr);
			/*
			sprintf(tmpStr, "0x%03X [%s] %u", ident.sdid, chipid ,ident.sdidrev);
			m_LbDevId.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%u", ident.num_blocks);
			m_LbMemBlkCnt.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%06X-0x%06X", ident.mem_start[0], ident.mem_end[0]-1);
			m_LbMemBlk1.SetWindowTextA(tmpStr);
			if(ident.num_blocks > 1)			
			{
				sprintf(tmpStr, "0x%06X-0x%06X", ident.mem_start[1], ident.mem_end[1]-1);
				m_LbMemBlk2.SetWindowTextA(tmpStr);	
			}
			else
				m_LbMemBlk2.SetWindowTextA("Not Available");
			
			sprintf(tmpStr, "%3d bytes", ident.erblk);
			m_LbEraseBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%3d bytes", ident.wrblk);
			m_LbWriteBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0xFFFF", ident.int_vect_tbl);
			m_LbVectTableOrig.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%04X-0x%04X\n", ident.bl_tbl, ident.bl_tbl+(0xFFFF-ident.int_vect_tbl));
			m_LbVectTableNew.SetWindowTextA(tmpStr);
			*/
		}
		else if (bl_version == BL_CFV1) // CFV1
		{
			sprintf(tmpStr, "ColdFire - %s, 0x%03X [%s] %u.", ident.targ_name, ident.sdid, chipid ,ident.sdidrev);	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: %d. #1: 0x%08X-0x%08X", ident.num_blocks, ident.mem_start[0], ident.mem_end[0]-1);	
			if(ident.num_blocks > 1)
			{
				sprintf(tmpStr1, ", #2: 0x%08X-0x%08X %s", ident.mem_start[1], ident.mem_end[1]-1, (ident.num_blocks > 2)? ", ...":"");
				strcat(tmpStr, tmpStr1);
			}
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes//%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
			if (ident.int_vect_tbl != NULL) 
				sprintf(tmpStr, "Original: 0x%08X-0x%08X. Application: 0x%08X-0x%08X.", NULL, ident.int_vect_tbl-1, ident.bl_tbl,ident.bl_tbl+ident.int_vect_tbl-1);	
			else
				sprintf(tmpStr, "Vector table not relocated.");	
			m_lbVectors.SetWindowTextA(tmpStr);
/*
if (ident.int_vect_tbl != NULL) 
            {
    			printf("Original vector table: 0x%08X\n-0x%08X\n",NULL, ident.int_vect_tbl-1);
    			printf("New vector table: 0x%08X\n-0x%08X\n",ident.bl_tbl,ident.bl_tbl+ident.int_vect_tbl-1);
            } else
    			printf("Vector table not relocated\n");
		}


			sprintf(tmpStr, "0x%03X [%s] %u", ident.sdid, chipid ,ident.sdidrev);
			m_LbDevId.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%u", ident.num_blocks);
			m_LbMemBlkCnt.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "0x%08X-0x%08X", ident.mem_start[0], ident.mem_end[0]-1);
			m_LbMemBlk1.SetWindowTextA(tmpStr);
			if(ident.num_blocks > 1)			
			{
				sprintf(tmpStr, "0x%08X-0x%08X", ident.mem_start[1], ident.mem_end[1]-1);
				m_LbMemBlk2.SetWindowTextA(tmpStr);	
			}
			else
				m_LbMemBlk2.SetWindowTextA("Not Available");
			
			sprintf(tmpStr, "%3d bytes", ident.erblk);
			m_LbEraseBlkSize.SetWindowTextA(tmpStr);	
			sprintf(tmpStr, "%3d bytes", ident.wrblk);
			m_LbWriteBlkSize.SetWindowTextA(tmpStr);	
			
			if (ident.int_vect_tbl != NULL) 
			{
				sprintf(tmpStr, "0x%04X-0xFFFF", ident.int_vect_tbl);
				m_LbVectTableOrig.SetWindowTextA(tmpStr);	
				sprintf(tmpStr, "0x%04X-0x%04X\n", ident.bl_tbl, ident.bl_tbl+(0xFFFF-ident.int_vect_tbl));
				m_LbVectTableNew.SetWindowTextA(tmpStr);
			}else
			{
				m_LbVectTableOrig.SetWindowTextA("Not relocated");
				m_LbVectTableNew.SetWindowTextA("Not relocated");
			}	*/		
		}
		else if (bl_version == BL_KINETIS) // KINETIS
		{
			sprintf(tmpStr, "Kinetis - %s, 0x%03X [%s] rev:%u, Package: %s.", ident.targ_name, ident.sdid, chipid ,ident.sdidrev, get_package_str(ident.sdid));	
			m_lbMcuInfo.SetWindowTextA(tmpStr);
		
			sprintf(tmpStr, "Blocks: %d. #1: 0x%08X-0x%08X", ident.num_blocks, ident.mem_start[0], ident.mem_end[0]);	
			if(ident.num_blocks > 1)
			{
				sprintf(tmpStr1, ", #2: 0x%08X-0x%08X %s", ident.mem_start[1], ident.mem_end[1], (ident.num_blocks > 2)? ", ...":"");
				strcat(tmpStr, tmpStr1);
			}
			m_lbMem.SetWindowTextA(tmpStr);
			
			sprintf(tmpStr, "Erase/Write block sizes: %3d bytes/%3d bytes", ident.erblk, ident.wrblk);	
			m_lbFlashPrty.SetWindowTextA(tmpStr);
			
 
			sprintf(tmpStr, "Original: 0x%08X-0x%08X. Application: 0x%08X-0x%08X.", ident.int_vect_tbl,ident.int_vect_tbl + 0x3FF, ident.bl_tbl, ident.bl_tbl + 0x3FF);	
			m_lbVectors.SetWindowTextA(tmpStr);
		}
		
	
	}

	else
	{
		m_lbProtocVersion.SetWindowTextA("Not Available");	
		m_lbMcuInfo.SetWindowTextA("Not Available");
		m_lbMem.SetWindowTextA("Not Available");	
		m_lbFlashPrty.SetWindowTextA("Not Available");	
		m_lbVectors.SetWindowTextA("Not Available");	
	}
}

void CMainDlg::OnBnClickedFlBcheck()
{
	CBusy busy;
	
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	blank_check();  // to do - what to do when erase operation halted ?
	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}

void CMainDlg::OnBnClickedFlErase()
{
	CBusy busy;
	
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	erase_mem(1); // to do - what to do when erase operation halted ?
	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}

void CMainDlg::OnBnClickedFlAutoprog()
{
	CBusy busy;
	
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	// program it!
	if(prg_mem() < 0)
	{
		ProgressChanged(100);
		LogResetReplaceLine();
		fprintf(stderr, "Program memory failed.\n");
		LogResetReplaceLine();
		EnableControlBtn(true);
	}else
	{
		ProgressChanged(100);
		LogResetReplaceLine();
		EnableControlBtn(true);

		OnBnClickedConnect();
	}
}

void CMainDlg::OnBnClickedFlCompare()
{
	
	CBusy busy;
	
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	// check if code goes to valid memory only - issue warning only, but continue! (r30323)
	check_image();
	LogResetReplaceLine();
	
	verify_mem(1);// to do - what to do when erase operation halted ?
	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}
/*
void CMainDlg::OnBnClickedFlRead()
{
	CBusy busy;
	
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	// check if code goes to valid memory only - issue warning only, but continue! (r30323)
	checksum_mem();
	LogResetReplaceLine();
	

	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}
*/
void CMainDlg::OnBnClickedCheckVerify()
{
	set_verify(m_chbVerify.GetCheck());
}


CBusy::CBusy()
{
	m_pwc = new CWaitCursor();
	m_wnd = AfxGetMainWnd();
	
	//if(m_wnd)
//		m_wnd->EnableWindow(FALSE);
}

CBusy::~CBusy()
{
	if(m_pwc)
		delete m_pwc;

	if(m_wnd)
	{
		MSG msg;
		while(PeekMessage(&msg, m_wnd->m_hWnd, WM_MOUSEFIRST, WM_MOUSELAST, TRUE))
			;
		//m_wnd->EnableWindow(TRUE);
	}
}



/*
void CMainDlg::OnBnClickedFlRead()
{
	CBusy busy;
	BOARD_MEM imageOut;
	if(!m_BootConnected)
		return;

	EnableControlBtn(false);
	
	reset_S19image(&imageOut);



	if(read_mem(&imageOut) >= 0)
	{
		// save image!!
		CString fileName,pathName;

		CFileDialog dlg(TRUE,NULL,NULL,(OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT),_T("S19 files (*.s19;*.sx;*.srec)|*.s19; *.sx; *.srec|MOT files (*.mot)|*.mot|All files (*.*)|*.*||"));
		
		if(dlg.DoModal() == IDOK)
		{
			pathName = dlg.GetPathName();
			fileName=dlg.GetFileName();
			if(write_s19(pathName.GetBuffer(), &imageOut)<0)
			{
				MessageBox("Write output file operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
			}

			
		}else
			MessageBox("Open output file operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
		

	}else
	{
		MessageBox("Read image operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
	}
	
	LogResetReplaceLine();
	

	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
}
*/
void CMainDlg::OnBnClickedFlRead()
{

	
	CBusy busy;
	BOARD_MEM* pImageOut;
	
	myprintf("/n Experimental feature!!!");

	if(!m_BootConnected)
		return;

	pImageOut = (BOARD_MEM*)malloc(sizeof(BOARD_MEM));

	EnableControlBtn(false);
	
	reset_S19image(pImageOut);



	if(read_mem(pImageOut, 1) >= 0)
	{
		// save image!!
		CString fileName,pathName;

		CFileDialog dlg(TRUE,NULL,NULL,(OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT),_T("S19 files (*.s19;*.sx;*.srec)|*.s19; *.sx; *.srec|MOT files (*.mot)|*.mot|All files (*.*)|*.*||"));
		
		if(dlg.DoModal() == IDOK)
		{
			pathName = dlg.GetPathName();
			fileName=dlg.GetFileName();
			if(write_s19(pathName.GetBuffer(), pImageOut)<0)
			{
				MessageBox("Write output file operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
			}

			
		}else
			MessageBox("Open output file operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
		

	}else
	{
		MessageBox("Read image operation failed.", "Read image Error",  MB_ICONERROR | MB_OK);
	}
	
	free(pImageOut);

	LogResetReplaceLine();
	

	ProgressChanged(100);
	LogResetReplaceLine();
	EnableControlBtn(true);
	
}
