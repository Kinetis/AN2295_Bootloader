// MainDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMainDlg dialog
class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WIN_HC08SPRG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

protected:
	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void Log(LPCTSTR pszText);
	void LogResetReplaceLine();
	void CMainDlg::ProgressChanged(unsigned value);
	void LogClear();
	void FillUpIdentification();
	void EnableInputs(bool enable);
	void EnableControlBtn(bool enable);
	bool m_BootConnected;	
	int m_selFrom;
	int m_selTo;
public:
	 CEdit m_logCtrl;
public:
	CComboBox m_fileS19;
public:
	CComboBox m_comPorts;
public:
	afx_msg void OnBnClickedBtRescan();
public:
	afx_msg void OnBnClickedBtOpens19();
public:
	CButton m_btConnect;
public:
	CComboBox m_cbComSpeed;
public:
	afx_msg void OnBnClickedConnect();
public:
	afx_msg void OnClose();

	
	 
public:
	afx_msg void OnBnClickedFlProgram();
public:
	CStatic m_lbProtocVersion;
public:
	CStatic m_lbMcuInfo;
public:
	CStatic m_lbMem;
public:
	CStatic m_lbFlashPrty;
public:
	CStatic m_lbVectors;
public:
	afx_msg void OnBnClickedFlBcheck();
public:
	afx_msg void OnBnClickedFlErase();
public:
	afx_msg void OnBnClickedFlAutoprog();
public:
	afx_msg void OnBnClickedFlCompare();
public:
	CButton m_BtRescan;
public:
	CButton m_BtOpenS19;
public:
	CButton m_btErase;
public:
	CButton m_btCheckB;
public:
	CButton m_btProg;
public:
	CButton m_btCompare;
public:
	CButton m_btAutoProg;
public:
	CButton m_chbSingleWire;
public:
	CEdit m_edbCheckSum;
public:
	CButton m_chbVerify;
public:
	afx_msg void OnBnClickedCheckVerify();
public:
	CEdit m_edbImageSize;
public:
	CProgressCtrl m_pbProgress;
public:
	afx_msg void OnBnClickedFlRead();
public:
	CButton m_BtFlRead;
	CButton m_chbShortTrim;
};


class CBusy
{
protected:
	CWaitCursor* m_pwc;
	CWnd* m_wnd;

public:
	CBusy();
	~CBusy();
};



extern "C" {
	int myprintf(const char * _Format, ...);
	int myfprintf(__inout FILE * _File, const char * _Format, ...);
	void progress_Changed(unsigned value);
}
