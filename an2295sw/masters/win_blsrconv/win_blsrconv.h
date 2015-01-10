// win_blsrconv.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cwin_blsrconvApp:
// See win_blsrconv.cpp for the implementation of this class
//

class Cwin_blsrconvApp : public CWinApp
{
public:
	Cwin_blsrconvApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cwin_blsrconvApp theApp;