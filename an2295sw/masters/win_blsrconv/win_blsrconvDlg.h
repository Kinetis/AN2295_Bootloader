// win_blsrconvDlg.h : header file
//

#pragma once
#include "afxwin.h"

typedef struct
{
	short sdid;
	short index;
	CString name;
	int originalIT;
	int relocatedIT;
} 
MCU_TYPE;

typedef struct
{	
	CString name;
	short index;
} 
BOOTPROTO_TYPE;

// Application public data



// Cwin_blsrconvDlg dialog
class Cwin_blsrconvDlg : public CDialog
{
// Construction
public:
	Cwin_blsrconvDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WIN_BLSRCONV_DIALOG };




	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void Log(LPCTSTR pszText);
	void LogResetReplaceLine();
	void LogClear();	


public:
	CComboBox m_cbCtmAppS19;
public:
	CComboBox m_cbBootAppS19;
public:
	CComboBox m_cbMcuType;
public:
	CEdit m_edbOutputS19;
public:
	CEdit m_edbOrigVect;
public:
	CEdit m_edbRedirectVect;
public:
	CButton m_btConvert;
public:
	CEdit m_edbLog;
public:
	afx_msg void OnBnClickedButtonOpenctms19();
public:
	afx_msg void OnBnClickedButtonOpenboots19();
public:
	afx_msg void OnBnClickedButtonConvert();
public:
	void CreateOutputFileName(CString appPathName);
public:
	bool IsConvertPossible(void);
public:
	afx_msg void OnCbnSelchangeComboCtms19();
public:
	afx_msg void OnCbnSelchangeComboMcutype();
public:
	afx_msg void OnCbnSelchangeComboBoots19();
public:
	afx_msg void OnEnChangeEditOuts19();
public:
	afx_msg void OnEnChangeEditOrigvect();
public:
	afx_msg void OnEnChangeEditRedirvect();
public:
	CComboBox m_cbBootProto;
public:
	afx_msg void OnCbnSelchangeComboBootproto();
};


extern "C" {

	int Get_McuTypeIx(CString text);
	int Get_BootProtoIx(CString text);
	int Get_BootProtoIxByType(int type);
	int myprintf(const char * _Format, ...);
	int myfprintf(__inout FILE * _File, const char * _Format, ...);
}