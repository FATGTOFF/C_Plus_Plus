
// Password_Generator_GUIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Password_Generator_GUI.h"
#include "Password_Generator_GUIDlg.h"
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


// CPasswordGeneratorGUIDlg dialog



CPasswordGeneratorGUIDlg::CPasswordGeneratorGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PASSWORD_GENERATOR_GUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPasswordGeneratorGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
   DDX_Text(pDX, IDC_EDIT_LABEL_NUM_PSWD, lengthOfPassword);
   DDV_MinMaxUInt(pDX, lengthOfPassword, minPasswordLength, maxPasswordLength);
}

BEGIN_MESSAGE_MAP(CPasswordGeneratorGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_GEN_PASSWORD_BUTTON, &CPasswordGeneratorGUIDlg::OnBnClickedGenPasswordButton)
   ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LENGTH_PASSWORD, &CPasswordGeneratorGUIDlg::OnNMCustomdrawSliderLengthPassword)
   ON_BN_CLICKED(IDC_CHECK_UPPERCASES, &CPasswordGeneratorGUIDlg::OnBnClickedCheckUppercases)
   ON_BN_CLICKED(IDC_CHECK_LOWERCASES, &CPasswordGeneratorGUIDlg::OnBnClickedCheckLowercases)
   ON_BN_CLICKED(IDC_CHECK_NUMBERS, &CPasswordGeneratorGUIDlg::OnBnClickedCheckNumbers)
   ON_BN_CLICKED(IDC_CHECK_SPECIALCASES, &CPasswordGeneratorGUIDlg::OnBnClickedCheckSpecialcases)
   ON_BN_CLICKED(IDC_CHECK_ALLOPTIONS, &CPasswordGeneratorGUIDlg::OnBnClickedCheckAlloptions)
END_MESSAGE_MAP()


// CPasswordGeneratorGUIDlg message handlers

BOOL CPasswordGeneratorGUIDlg::OnInitDialog()
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
   std::string newPassword{};
   printNewPassword(newPassword);

   pAllOptionsCheck = reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK_ALLOPTIONS));
   pAllOptionsCheck->SetCheck(true);
   pUpperCasesCheck = reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK_UPPERCASES));
   pUpperCasesCheck->EnableWindow(false);
   pLowerCasesCheck = reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK_LOWERCASES));
   pLowerCasesCheck->EnableWindow(false);
   pNumberCasesCheck = reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK_NUMBERS));
   pNumberCasesCheck->EnableWindow(false);
   pSymbolsCasesCheck = reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK_SPECIALCASES));
   pSymbolsCasesCheck->EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPasswordGeneratorGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPasswordGeneratorGUIDlg::OnPaint()
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
HCURSOR CPasswordGeneratorGUIDlg::OnQueryDragIcon()
{
	return m_hIcon;
}


void CPasswordGeneratorGUIDlg::printNewPassword(std::string & newPassword)
{

   while (lenghtPassCountDown > 0)
   {

      if (allCheckMarked())
      {
         pUpperCasesCheck->SetCheck(false);
         pLowerCasesCheck->SetCheck(false);
         pNumberCasesCheck->SetCheck(false);
         pSymbolsCasesCheck->SetCheck(false);
         pAllOptionsCheck->SetCheck(true);

         randomizePasswordsAllOptions(newPassword);

      }

       else if (upperLowerNumChecked())
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeLowerCaseLetters(newPassword);
         randomizeNumsForPasswords(newPassword);
      }

      else if (upperLowerSymbolsChecked())
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeLowerCaseLetters(newPassword);
         randomizeSymbols(newPassword);
      }

      else if (upperNumSymbolsChecked())
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeNumsForPasswords(newPassword);
         randomizeSymbols(newPassword);
      }

      else if (lowerNumSymbolsChecked())
      {
         randomizeLowerCaseLetters(newPassword);
         randomizeNumsForPasswords(newPassword);
         randomizeSymbols(newPassword);
      }

      else if ((static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
         (static_cast<bool>(pNumberCasesCheck->GetCheck())))
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeNumsForPasswords(newPassword);
      }

      else if ((static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
         (static_cast<bool>(pSymbolsCasesCheck->GetCheck())))
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeSymbols(newPassword);
      }

      else if ((static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
         (static_cast<bool>(pLowerCasesCheck->GetCheck())))
      {
         randomizeUpperCaseLetters(newPassword);
         randomizeLowerCaseLetters(newPassword);
      }

      else if ((static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
         (static_cast<bool>(pNumberCasesCheck->GetCheck())))
      {
         randomizeLowerCaseLetters(newPassword);
         randomizeNumsForPasswords(newPassword);
      }

      else if ((static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
         (static_cast<bool>(pSymbolsCasesCheck->GetCheck())))
      {
         randomizeLowerCaseLetters(newPassword);
         randomizeSymbols(newPassword);
      }

      else if ((static_cast<bool>(pNumberCasesCheck->GetCheck())) &&
         (static_cast<bool>(pSymbolsCasesCheck->GetCheck())))
      {
         randomizeNumsForPasswords(newPassword);
         randomizeSymbols(newPassword);
      }

      else if (static_cast<bool>(pUpperCasesCheck->GetCheck()))
      {
         randomizeUpperCaseLetters(newPassword);
      }

      else if (static_cast<bool>(pLowerCasesCheck->GetCheck()))
      {
         randomizeLowerCaseLetters(newPassword);
      }

      else if (static_cast<bool>(pNumberCasesCheck->GetCheck()))
      {
         randomizeNumsForPasswords(newPassword);
      }

      else if (static_cast<bool>(pSymbolsCasesCheck->GetCheck()))
      {
         randomizeSymbols(newPassword);
      }

      else
      {
         pAllOptionsCheck->SetCheck(true);
         randomizePasswordsAllOptions(newPassword);
      }

   }

   // Let's shuffle the generated password before we print it.
   std::mt19937_64 rng(std::random_device{}());
   std::shuffle(newPassword.begin(), newPassword.end(), rng);

   const unsigned int bufferSize{ maxPasswordLength + 1 };
   wchar_t pBuffer[bufferSize]{};

   static_cast<void>(_snwprintf_s(pBuffer, bufferSize - 1, L"%hs", newPassword.c_str()));
   GetDlgItem(IDC_EDIT_PASSWORD)->SetWindowTextW(pBuffer);

   lenghtPassCountDown = lengthOfPassword;
}

void CPasswordGeneratorGUIDlg::randomizeUpperCaseLetters(std::string & newPassword)
{
   // No reason to keep going if the length is 0.
   if (0 == lenghtPassCountDown)
   {
      return;
   }

   std::uint16_t numOfUpperCaseLetters{};

   if (lenghtPassCountDown > 1)
   {
      numOfUpperCaseLetters = randomNumber(1, 2);
   }
   else // If the length is 1
   {
      numOfUpperCaseLetters = 1;
   }

   lenghtPassCountDown -= numOfUpperCaseLetters;

   for (std::uint16_t count = 0; count < numOfUpperCaseLetters; ++count)
   {
      const char upperCaseLetter{ static_cast<char>(randomNumber(65, 90)) };
      newPassword.push_back(upperCaseLetter);
   }
}

void CPasswordGeneratorGUIDlg::randomizeLowerCaseLetters(std::string & newPassword)
{
   // No reason to keep going if the length is 0.
   if (0 == lenghtPassCountDown)
   {
      return;
   }

   std::uint16_t numOfLowerCaseLetters{};

   if (lenghtPassCountDown > 1)
   {
      numOfLowerCaseLetters = randomNumber(1, 2);
   }
   else // If the length is 1
   {
      numOfLowerCaseLetters = 1;
   }

   lenghtPassCountDown -= numOfLowerCaseLetters;

   for (std::uint16_t count = 0; count < numOfLowerCaseLetters; ++count)
   {
      const char lowerCaseLetter{ static_cast<char>(randomNumber(97, 122)) };
      newPassword.push_back(lowerCaseLetter);
   }
}

void CPasswordGeneratorGUIDlg::randomizeSymbols(std::string & newPassword)
{
   // No reason to keep going if the length is 0.
   if (0 == lenghtPassCountDown)
   {
      return;
   }

   std::uint16_t numOfSymbols{};

   if (lenghtPassCountDown > 1)
   {
      numOfSymbols = randomNumber(1, 2);
   }
   else // If the length is 1
   {
      numOfSymbols = 1;
   }

   lenghtPassCountDown -= numOfSymbols;

   for (std::uint16_t count = 0; count < numOfSymbols; ++count)
   {
      newPassword.push_back(specialCharacters[randomNumber(0, 30)]);
   }
}

void CPasswordGeneratorGUIDlg::randomizeNumsForPasswords(std::string & newPassword)
{
   // No reason to keep going if the length is 0.
   if (0 == lenghtPassCountDown)
   {
      return;
   }

   std::uint16_t numOfNumbers{};

   if (lenghtPassCountDown > 1)
   {
      numOfNumbers = randomNumber(1, 2);
   }
   else  // If the length is 1
   {
      numOfNumbers = 1;
   }

   lenghtPassCountDown -= numOfNumbers;

   for (std::uint16_t count = 0; count < numOfNumbers; ++count)
   {
      const char number{ static_cast<char>(randomNumber(48, 57)) };
      newPassword.push_back(number);
   }
}

void CPasswordGeneratorGUIDlg::randomizePasswordsAllOptions(std::string & newPassword)
{
   randomizeUpperCaseLetters(newPassword);
   randomizeLowerCaseLetters(newPassword);
   randomizeNumsForPasswords(newPassword);
   randomizeSymbols(newPassword);
}

std::uint16_t CPasswordGeneratorGUIDlg::randomNumber(std::uint16_t min, std::uint16_t max) const
{
   std::mt19937_64 rng(std::random_device{}());
   std::uniform_int_distribution<std::uint16_t> distrib(min, max);

   const std::uint16_t random = distrib(rng);

   return random;
}

bool CPasswordGeneratorGUIDlg::allCheckMarked() const
{
   return (static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
      (static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
      (static_cast<bool>(pNumberCasesCheck->GetCheck())) &&
      (static_cast<bool>(pSymbolsCasesCheck->GetCheck()));
}

bool CPasswordGeneratorGUIDlg::upperLowerNumChecked() const
{
   return (static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
      (static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
      (static_cast<bool>(pNumberCasesCheck->GetCheck()));
}

bool CPasswordGeneratorGUIDlg::upperLowerSymbolsChecked() const
{
   return (static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
      (static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
      (static_cast<bool>(pSymbolsCasesCheck->GetCheck()));
}

bool CPasswordGeneratorGUIDlg::upperNumSymbolsChecked() const
{
   return (static_cast<bool>(pUpperCasesCheck->GetCheck())) &&
      (static_cast<bool>(pNumberCasesCheck->GetCheck())) &&
      (static_cast<bool>(pSymbolsCasesCheck->GetCheck()));
}

bool CPasswordGeneratorGUIDlg::lowerNumSymbolsChecked() const
{
   return (static_cast<bool>(pLowerCasesCheck->GetCheck())) &&
      (static_cast<bool>(pNumberCasesCheck->GetCheck())) &&
      (static_cast<bool>(pSymbolsCasesCheck->GetCheck()));
}

void CPasswordGeneratorGUIDlg::OnBnClickedGenPasswordButton()
{
   auto label = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_LABEL_NUM_PSWD));
   std::string newPassword{};

   if (lengthOfPassword == 0)
   {
      lenghtPassCountDown = lengthOfPassword = 8;
   }

   const unsigned int bufferSize{ 10 };
   wchar_t pBuffer[bufferSize]{};
   static_cast<void>(_snwprintf_s(pBuffer, bufferSize - 1, L"%d", lengthOfPassword));
   label->SetWindowTextW(pBuffer);

   printNewPassword(newPassword);

   pUpperCasesCheck->EnableWindow(true);
   pLowerCasesCheck->EnableWindow(true);
   pNumberCasesCheck->EnableWindow(true);
   pSymbolsCasesCheck->EnableWindow(true);
}


void CPasswordGeneratorGUIDlg::OnNMCustomdrawSliderLengthPassword(NMHDR *pNMHDR, LRESULT *pResult)
{

   auto slider = reinterpret_cast<CSliderCtrl*>(GetDlgItem(IDC_SLIDER_LENGTH_PASSWORD));
   auto label = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_LABEL_NUM_PSWD));
   auto currentSliderCursorPos = slider->GetPos();

   slider->SetRange(minPasswordLength, maxPasswordLength);
   lenghtPassCountDown = lengthOfPassword = currentSliderCursorPos;

   const unsigned int bufferSize{ 10 };
   wchar_t pBuffer[bufferSize]{};

   static_cast<void>(_snwprintf_s(pBuffer, bufferSize - 1, L"%d", lengthOfPassword));
   label->SetWindowTextW(pBuffer);

   // Create a new password if the slider move
   if (currentSliderCursorPos != lastSliderCursorPos)
   {
      std::string newPassword{};
      printNewPassword(newPassword);
      lastSliderCursorPos = currentSliderCursorPos;

      pUpperCasesCheck->EnableWindow(true);
      pLowerCasesCheck->EnableWindow(true);
      pNumberCasesCheck->EnableWindow(true);
      pSymbolsCasesCheck->EnableWindow(true);
   }

   *pResult = 0;
}

void CPasswordGeneratorGUIDlg::OnBnClickedCheckUppercases()
{
   UpdateData(true);

   if (static_cast<bool>(pUpperCasesCheck->GetCheck()))
   {
      pAllOptionsCheck->SetCheck(false);
   }

}


void CPasswordGeneratorGUIDlg::OnBnClickedCheckLowercases()
{
   UpdateData(true);

   if (static_cast<bool>(pLowerCasesCheck->GetCheck()))
   {
      pAllOptionsCheck->SetCheck(false);
   }
}


void CPasswordGeneratorGUIDlg::OnBnClickedCheckNumbers()
{
   UpdateData(true);

   if (static_cast<bool>(pNumberCasesCheck->GetCheck()))
   {
      pAllOptionsCheck->SetCheck(false);
   }
}


void CPasswordGeneratorGUIDlg::OnBnClickedCheckSpecialcases()
{
   UpdateData(true);

   if (static_cast<bool>(pSymbolsCasesCheck->GetCheck()))
   {
      pAllOptionsCheck->SetCheck(false);
   }
}


void CPasswordGeneratorGUIDlg::OnBnClickedCheckAlloptions()
{
   UpdateData(true);

   if (static_cast<bool>(pAllOptionsCheck->GetCheck()))
   {

      pUpperCasesCheck->SetCheck(false);
      pLowerCasesCheck->SetCheck(false);
      pNumberCasesCheck->SetCheck(false);
      pSymbolsCasesCheck->SetCheck(false);
   }
}

