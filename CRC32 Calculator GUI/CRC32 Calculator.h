
// CRC32 Calculator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCRC32CalculatorApp:
// See CRC32 Calculator.cpp for the implementation of this class
//

class CCRC32CalculatorApp : public CWinApp
{
public:
	CCRC32CalculatorApp() noexcept;

// Overrides
	BOOL InitInstance() override;

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCRC32CalculatorApp theApp;
