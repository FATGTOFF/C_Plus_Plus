
// Binary File Reader.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <memory>


// CBinaryFileReaderApp:
// See Binary File Reader.cpp for the implementation of this class
//

class CBinaryFileReaderApp : public CWinApp
{
public:
   CBinaryFileReaderApp();

   // Overrides
public:
   virtual BOOL InitInstance();

   // Implementation

   DECLARE_MESSAGE_MAP()
};

extern const CBinaryFileReaderApp theApp;