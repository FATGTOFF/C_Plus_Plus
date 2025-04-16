
// TicTacToeMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TicTacToeMFC.h"
#include "TicTacToeMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTicTacToeMFCDlg dialog



CTicTacToeMFCDlg::CTicTacToeMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TICTACTOEMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CTicTacToeMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
   
   // Create the bold font
   m_font.CreateFont(
      120,                        // Height
      0,                          // Width
      0,                          // Escapement
      0,                          // Orientation
      FW_BOLD,                    // Weight (FW_BOLD makes it bold)
      FALSE,                      // Italic
      FALSE,                      // Underline
      0,                          // StrikeOut
      ANSI_CHARSET,               // CharSet
      OUT_DEFAULT_PRECIS,         // OutPrecision
      CLIP_DEFAULT_PRECIS,        // ClipPrecision
      DEFAULT_QUALITY,            // Quality
      DEFAULT_PITCH | FF_SWISS,   // PitchAndFamily
      _T("Arial"));               // Facename


   playerLabel = reinterpret_cast<CEdit*>(GetDlgItem(IDC_STATIC_PLAYER));
   winLabel = reinterpret_cast<CEdit*>(GetDlgItem(IDC_STATIC_WON));
   playerLabel->ShowWindow(true);
   winLabel->ShowWindow(false);

   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) = 
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON1));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON2));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON3));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON4));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON5));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON6));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON7));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON8));
   pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) =
      reinterpret_cast<CButton*>(GetDlgItem(IDC_BUTTON9));

   for (auto numOfbutton = static_cast<std::size_t>(Button_Number::BUTTON_NUM_1);
      numOfbutton < static_cast<std::size_t>(Button_Number::TOTAL_NUM_OF_BUTTONS);
      ++numOfbutton)
   {
      if (pButton.at(numOfbutton) != nullptr)
      {
         pButton.at(numOfbutton)->EnableWindow(true);
         pButton.at(numOfbutton)->SetWindowTextW(nullptr);
         pButton.at(numOfbutton)->SetFont(&m_font);
         buttonLabel.at(numOfbutton) = nullptr;
         player = 1;
      }
   }

   printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
}

BEGIN_MESSAGE_MAP(CTicTacToeMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_BUTTON1, &CTicTacToeMFCDlg::OnBnClickedButton1)
   ON_BN_CLICKED(IDC_BUTTON2, &CTicTacToeMFCDlg::OnBnClickedButton2)
   ON_BN_CLICKED(IDC_BUTTON3, &CTicTacToeMFCDlg::OnBnClickedButton3)
   ON_BN_CLICKED(IDC_BUTTON4, &CTicTacToeMFCDlg::OnBnClickedButton4)
   ON_BN_CLICKED(IDC_BUTTON5, &CTicTacToeMFCDlg::OnBnClickedButton5)
   ON_BN_CLICKED(IDC_BUTTON6, &CTicTacToeMFCDlg::OnBnClickedButton6)
   ON_BN_CLICKED(IDC_BUTTON7, &CTicTacToeMFCDlg::OnBnClickedButton7)
   ON_BN_CLICKED(IDC_BUTTON8, &CTicTacToeMFCDlg::OnBnClickedButton8)
   ON_BN_CLICKED(IDC_BUTTON9, &CTicTacToeMFCDlg::OnBnClickedButton9)
   ON_BN_CLICKED(IDC_BUTTON_RESET, &CTicTacToeMFCDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// CTicTacToeMFCDlg message handlers

void CTicTacToeMFCDlg::printToLabel(const int nameID, const std::string& textToPrint) const
{
   auto label = reinterpret_cast<CEdit*>(GetDlgItem(nameID));
   const std::string pBuffer = textToPrint.c_str();
   const std::wstring w_pBuffer{ pBuffer.begin(), pBuffer.end() };
   label->SetWindowTextW(w_pBuffer.c_str());
}

bool CTicTacToeMFCDlg::determineWinner() const
{

   if (checkRow01()      || checkRow02() || checkRow03() ||
       checkCol01()      || checkCol02() || checkCol03() ||
       checkDiagonal01() || checkDiagonal02())
   {
      playerLabel->ShowWindow(true);
      winLabel->ShowWindow(true);

      for (auto numOfbutton = static_cast<std::size_t>(Button_Number::BUTTON_NUM_1); 
           numOfbutton < static_cast<std::size_t>(Button_Number::TOTAL_NUM_OF_BUTTONS); 
           ++numOfbutton)
      {
         pButton.at(numOfbutton)->EnableWindow(false);
      }

      return true;
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkRow01() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)));
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkRow02() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)));
   }
   else
   {
      return false;
   }

}

bool CTicTacToeMFCDlg::checkRow03() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)));
   }
   else
   {
      return false;
   }

}

bool CTicTacToeMFCDlg::checkCol01() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)));
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkCol02() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)));
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkCol03() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)));
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkDiagonal01() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))) &&
             (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)));
   }
   else
   {
      return false;
   }
}

bool CTicTacToeMFCDlg::checkDiagonal02() const
{
   if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) != nullptr ||
       buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) != nullptr)
   {
      return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))) &&
             (buttonLabel.at(4) == buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)));
   }
   else
   {
      return false;
   }
}

BOOL CTicTacToeMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTicTacToeMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicTacToeMFCDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTicTacToeMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTicTacToeMFCDlg::OnBnClickedButton1()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1))->EnableWindow(false);

      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }

}


void CTicTacToeMFCDlg::OnBnClickedButton2()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2))->EnableWindow(false);

      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton3()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3))->EnableWindow(false);

      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton4()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4))->EnableWindow(false);



      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton5()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5))->EnableWindow(false);

      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton6()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) = O;


         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) = X;


         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6))->EnableWindow(false);


      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton7()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) = O;


         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) = X;


         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7))->EnableWindow(false);


      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton8()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) = O;

         if (!determineWinner())
         {
            player = 1;
         }
      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8))->EnableWindow(false);


      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButton9()
{

   if (pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)))
   {
      CString buttonText;
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9))->GetWindowTextW(buttonText);

      if (2 == player)
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9))->SetWindowTextW(O);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) = O;

         if (!determineWinner())
         {
            player = 1;
         }

      }
      else
      {
         pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9))->SetWindowTextW(X);
         buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) = X;

         if (!determineWinner())
         {
            player = 2;
         }
      }
      pButton.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9))->EnableWindow(false);


      printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));
   }
}


void CTicTacToeMFCDlg::OnBnClickedButtonReset()
{
   playerLabel->ShowWindow(true);
   winLabel->ShowWindow(false);

   for (auto numOfbutton = static_cast<std::size_t>(Button_Number::BUTTON_NUM_1);
      numOfbutton < static_cast<std::size_t>(Button_Number::TOTAL_NUM_OF_BUTTONS);
      ++numOfbutton)
   {
      pButton.at(numOfbutton)->EnableWindow(true);
      pButton.at(numOfbutton)->SetWindowTextW(nullptr);
      buttonLabel.at(numOfbutton) = nullptr;
   }

   player = 1;
   printToLabel(IDC_EDIT_PLAYER_NUM, std::to_string(player));

}
