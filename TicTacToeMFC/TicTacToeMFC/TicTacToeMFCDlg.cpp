
// TicTacToeMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "afxdialogex.h"
#include "framework.h"
#include "TicTacToeMFC.h"
#include "TicTacToeMFCDlg.h"

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
    void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support

// Implementation
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
   playerNumlabel = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_PLAYER_NUM_TURN));

   playerLabel->ShowWindow(false);
   playerNumlabel->ShowWindow(false);
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
      }
   }

   printToLabel(std::to_string(player));
}

BEGIN_MESSAGE_MAP(CTicTacToeMFCDlg, CDialogEx)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_BUTTON1,      &CTicTacToeMFCDlg::OnBnClickedButton1)
   ON_BN_CLICKED(IDC_BUTTON2,      &CTicTacToeMFCDlg::OnBnClickedButton2)
   ON_BN_CLICKED(IDC_BUTTON3,      &CTicTacToeMFCDlg::OnBnClickedButton3)
   ON_BN_CLICKED(IDC_BUTTON4,      &CTicTacToeMFCDlg::OnBnClickedButton4)
   ON_BN_CLICKED(IDC_BUTTON5,      &CTicTacToeMFCDlg::OnBnClickedButton5)
   ON_BN_CLICKED(IDC_BUTTON6,      &CTicTacToeMFCDlg::OnBnClickedButton6)
   ON_BN_CLICKED(IDC_BUTTON7,      &CTicTacToeMFCDlg::OnBnClickedButton7)
   ON_BN_CLICKED(IDC_BUTTON8,      &CTicTacToeMFCDlg::OnBnClickedButton8)
   ON_BN_CLICKED(IDC_BUTTON9,      &CTicTacToeMFCDlg::OnBnClickedButton9)
   ON_BN_CLICKED(IDC_BUTTON_RESET, &CTicTacToeMFCDlg::OnBnClickedButtonReset)
   ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CTicTacToeMFCDlg::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CTicTacToeMFCDlg message handlers

void CTicTacToeMFCDlg::printToLabel(const std::string& textToPrint) const
{
   const std::string pBuffer = textToPrint.c_str();
   const std::wstring w_pBuffer{ pBuffer.begin(), pBuffer.end() };
   playerNumlabel->SetWindowTextW(w_pBuffer.c_str());
}

bool CTicTacToeMFCDlg::determineWinner() const
{

   if (checkRow01()      || checkRow02() || checkRow03() ||
       checkCol01()      || checkCol02() || checkCol03() ||
       checkDiagonal01() || checkDiagonal02())
   {
      playerLabel->ShowWindow(true);
      playerNumlabel->ShowWindow(true);
      winLabel->ShowWindow(true);

      for (auto numOfbutton = static_cast<std::size_t>(Button_Number::BUTTON_NUM_1); 
           numOfbutton < static_cast<std::size_t>(Button_Number::TOTAL_NUM_OF_BUTTONS); 
           ++numOfbutton)
      {
         pButton.at(numOfbutton)->EnableWindow(false);
      }

      return true;
   }

   return false;
}

std::size_t CTicTacToeMFCDlg::randomNumber(const std::size_t max) const
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<std::size_t> distrib(0, max);

    const std::size_t random = distrib(rng);

    return random;
}

std::size_t CTicTacToeMFCDlg::randomNumber(const std::size_t min, const std::size_t max) const
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<std::size_t> distrib(min, max);

    const std::size_t random = distrib(rng);

    return random;
}

void CTicTacToeMFCDlg::determinePlayerTurn()
{
    if (determineWinner())
    {
        player = 2;
    }
    else
    {
        player = 1;
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

   return false;
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

   return false;
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

   return false;
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

   return false;
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

   return false;
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

   return false;
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

   return false;
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

   return false;
}

bool CTicTacToeMFCDlg::allButtonsFilled() const
{
    return (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) != nullptr &&
            buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) != nullptr);
}

bool CTicTacToeMFCDlg::computerTurn(const std::size_t computerSelect)
{

    switch (computerSelect)
    {
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_1):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_1)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_1);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_2):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_2)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_2);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_3):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_3)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_3);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_4):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_4)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_4);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_5):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_5)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_5);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_6):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_6)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_6);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_7):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_7)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_7);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_8):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_8)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_8);
                return false;
            }
            break;
        case static_cast<std::size_t>(Button_Number::BUTTON_NUM_9):
            if (buttonLabel.at(static_cast<unsigned>(Button_Number::BUTTON_NUM_9)) == nullptr)
            {
                computerSelectedButton(Button_Number::BUTTON_NUM_9);
                return false;
            }
            break;

        default:
            break;
    }

    return true;
}

void CTicTacToeMFCDlg::computerSelectedButton(const Button_Number buttonNumber)
{

    pButton.at(static_cast<unsigned>(buttonNumber))->SetWindowTextW(O);
    buttonLabel.at(static_cast<unsigned>(buttonNumber)) = O;
    pButton.at(static_cast<unsigned>(buttonNumber))->EnableWindow(false);
}

void CTicTacToeMFCDlg::playerSelectedButton(const Button_Number buttonNumber)
{

    if (pButton.at(static_cast<unsigned>(buttonNumber)))
    {
        CString buttonText;
        pButton.at(static_cast<unsigned>(buttonNumber))->GetWindowTextW(buttonText);

        if (2 == player)
        {
            pButton.at(static_cast<unsigned>(buttonNumber))->SetWindowTextW(O);
            buttonLabel.at(static_cast<unsigned>(buttonNumber)) = O;

            if (!determineWinner() && !allButtonsFilled())
            {
                player = 1;
            }
        }
        else
        {
            pButton.at(static_cast<unsigned>(buttonNumber))->SetWindowTextW(X);
            buttonLabel.at(static_cast<unsigned>(buttonNumber)) = X;
            pButton.at(static_cast<unsigned>(buttonNumber))->EnableWindow(false);
            computerSelects();
        }

        printToLabel(std::to_string(player));

    }
}

void CTicTacToeMFCDlg::computerSelects()
{

    if (!determineWinner() && !allButtonsFilled())
    {
        player = 2;

        bool keepLooping{ true };
        std::this_thread::sleep_for(std::chrono::seconds(randomNumber(1, 2)));
        while (keepLooping)
        {
            keepLooping = computerTurn(randomNumber(static_cast<std::size_t>(Button_Number::BUTTON_NUM_9)));
            determinePlayerTurn();
        }
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
	return m_hIcon;
}

void CTicTacToeMFCDlg::OnBnClickedButton1()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_1);
}


void CTicTacToeMFCDlg::OnBnClickedButton2()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_2);
}


void CTicTacToeMFCDlg::OnBnClickedButton3()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_3);
}


void CTicTacToeMFCDlg::OnBnClickedButton4()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_4);
}


void CTicTacToeMFCDlg::OnBnClickedButton5()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_5);
}


void CTicTacToeMFCDlg::OnBnClickedButton6()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_6);
}


void CTicTacToeMFCDlg::OnBnClickedButton7()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_7);
}


void CTicTacToeMFCDlg::OnBnClickedButton8()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_8);
}


void CTicTacToeMFCDlg::OnBnClickedButton9()
{
    playerSelectedButton(Button_Number::BUTTON_NUM_9);
}


void CTicTacToeMFCDlg::OnBnClickedButtonReset()
{
   playerLabel->ShowWindow(false);
   playerNumlabel->ShowWindow(false);
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

}

void CTicTacToeMFCDlg::OnBnClickedButtonClose()
{
    CDialogEx::OnCancel();
}
