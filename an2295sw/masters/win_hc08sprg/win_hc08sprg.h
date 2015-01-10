// win_hc08sprg.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThisApp:
// See win_hc08sprg.cpp for the implementation of this class
//

class CThisApp : public CWinApp
{
public:
	CThisApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThisApp theApp;