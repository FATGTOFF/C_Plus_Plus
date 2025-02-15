
// CRC32 CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CRC32 Calculator.h"
#include "CRC32 CalculatorDlg.h"
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


// CCRC32CalculatorDlg dialog



CCRC32CalculatorDlg::CCRC32CalculatorDlg(CWnd* pParent /*=nullptr*/)
   : CDialogEx(IDD_CRC32CALCULATOR_DIALOG, pParent)
{
   log.fileOutPut() << "Program Started\n" << std::flush;
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   crcInit();
}

void CCRC32CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCRC32CalculatorDlg, CDialogEx)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE, &CCRC32CalculatorDlg::OnBnClickedButtonOpenFile)
END_MESSAGE_MAP()


// CCRC32CalculatorDlg message handlers

BOOL CCRC32CalculatorDlg::OnInitDialog()
{
   CDialogEx::OnInitDialog();
   
     // When it opens, center the window.
     CenterWindow();

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
   SetIcon(m_hIcon, TRUE);     // Set big icon
   SetIcon(m_hIcon, FALSE);    // Set small icon
   
   // Load the customized icon.
     // https://www.codeproject.com/Tips/406870/Change-ICON-of-MFC-Application-and-Dialog
     HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
     SetIcon(hIcon, FALSE);
   
   return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCRC32CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCRC32CalculatorDlg::OnPaint()
{
   if (IsIconic())
   {
      CPaintDC dc(this); // device context for painting
      
      SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
      
      // Center icon in client rectangle
      const int cxIcon = GetSystemMetrics(SM_CXICON);
      const int cyIcon = GetSystemMetrics(SM_CYICON);
      CRect rect;
      GetClientRect(&rect);
          const int x = (rect.Width() - cxIcon + 1) / 2;
          const int y = (rect.Height() - cyIcon + 1) / 2;
      
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
HCURSOR CCRC32CalculatorDlg::OnQueryDragIcon() noexcept
{
   return m_hIcon;
}


void CCRC32CalculatorDlg::OnBnClickedButtonOpenFile()
{
   LPCTSTR pFileFilterOpen =
      _T("Binary (*.bin)|*.bin|")
      _T("Conf (*.conf)|*.conf|")
      _T("All files (*.*)|*.*|");

   CFileDialog dialogFileOpen(TRUE, _T("bin"), nullptr,
      OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, pFileFilterOpen, AfxGetMainWnd());

   if (IDOK == dialogFileOpen.DoModal())
   {

      CT2CA pszConvertedAnsiString(dialogFileOpen.GetPathName());
      std::string getPathName = pszConvertedAnsiString;
      log.fileOutPut() << "File selected: " << getPathName << std::endl << std::flush;

      GetDlgItem(IDC_STATIC_FILE_LOCATION)->SetWindowTextW(dialogFileOpen.GetFileName());
      std::wstring getFileName = dialogFileOpen.GetFileName();

      if (L"conf" == dialogFileOpen.GetFileExt())
      {
         crc32 = getConfFileCRC(getPathName);
      }
      else
      {
         crc32 = getBinaryFileCRC(getPathName);
      }

      DisplayCRC(getFileName);
   }

}

void CCRC32CalculatorDlg::crcInit() noexcept
{
   crc   remainder{};

   /*
    * Compute the remainder of each possible dividend.
    */
   for (int dividend = 0; dividend < 256; ++dividend)
   {
      /*
       * Start with the dividend followed by zeros.
       */
      remainder = dividend << (WIDTH - 8);

      /*
       * Perform modulo-2 division, a bit at a time.
       */
      for (bits bit = 8; bit > 0; --bit)
      {
         /*
          * Try to divide the current data bit.
          */
         if (remainder & TOPBIT)
         {
            remainder = (remainder << 1) ^ POLYNOMIAL;
         }
         else
         {
            remainder = (remainder << 1);
         }
      }

      /*
       * Store the result into the table.
       */
      crcTable.at(dividend) = remainder;

      if (DEBUG_LOGGER)
      {
         log.fileOutPut() << std::setfill('0') << std::setw(8) 
            << std::right << std::hex << std::uppercase 
            << crcTable.at(dividend) << std::endl;
      }

   }
}

crc CCRC32CalculatorDlg::reflect(unsigned long data, bits nBits) const
{
   unsigned long  reflection = 0x00000000;

   /*
    * Reflect the data about the center bit.
    */
   for (bits bit = 0; bit < nBits; ++bit)
   {
      /*
       * If the LSB bit is set, set the reflection of it.
       */
      if (data & 0x01)
      {
         reflection |= (1 << ((nBits - 1) - bit));
      }

      data = (data >> 1);
   }

   return reflection;
}

crc CCRC32CalculatorDlg::REFLECT_DATA(unsigned long X) const
{
   return reflect(X, 8);
}

crc CCRC32CalculatorDlg::REFLECT_REMAINDER(unsigned long X) const
{
   return reflect(X, WIDTH);
}

crc CCRC32CalculatorDlg::getBinaryFileCRC(const std::string &getPathName) const
{
   crc	         remainder{ 0 ^ INITIAL_REMAINDER };
   bits           data{};

   /* Get the file size by opening in binary mode */
   std::ifstream binaryFile(getPathName, std::ios::in | std::ios::binary);

   if (!binaryFile)
   {
      MessageBoxA(nullptr, "Error: The file could not be opened", nullptr, MB_OK);
      return INITIAL_REMAINDER;
   }

   std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(binaryFile), {});

   /*
    * Divide the message by the polynomial, a byte at a time.
    */
   for (bytes byte = 0; byte < static_cast<bytes>(buffer.size()); ++byte)
   {
      data = static_cast<bits>(REFLECT_DATA(buffer.at(byte)) ^ (remainder >> (WIDTH - 8)));
      remainder = crcTable.at(data) ^ (remainder << 8);
   }

   binaryFile.close();

   /*
    * The final remainder is the CRC.
    */
   return REFLECT_REMAINDER(remainder) ^ FINAL_XOR_VALUE;
}

crc CCRC32CalculatorDlg::getConfFileCRC(const std::string &getPathName) const
{
   crc remainder{ 0 ^ INITIAL_REMAINDER };
   std::vector<crc> crcValue{};
   std::stringstream textLineToStream{};
   bits data{};
   std::string dataFromConfFile{};
   std::string CRCInDecFormat{};

   std::ifstream confFile(getPathName, std::ios::in);

   if (!confFile)
   {
      MessageBoxA(nullptr, "Error: The *.conf file could not be opened", nullptr, MB_OK);
      return INITIAL_REMAINDER;
   }
   else
   {

      unsigned long foundCRCInDecFormat{};

      while (std::getline(confFile, dataFromConfFile))
      {
         textLineToStream << dataFromConfFile << std::endl;
      }

      confFile.close();

      while (textLineToStream >> CRCInDecFormat)
      {

         if (std::stringstream(CRCInDecFormat) >> foundCRCInDecFormat)
         {
            crcValue.push_back(foundCRCInDecFormat);
         }

      }
   }

   // Clear the stringstream object to be reused.
   textLineToStream.clear();

   for (std::size_t count = 0; count < crcValue.size(); ++count)
   {
      // Format the string so it would include leading zeroes. For example, for the
      // CRC in decimal value 221815283, it would be D38A1F3. So we need to add the
      // leading 0 so it would look like 0D38A1F3.
      textLineToStream << std::setfill('0') << std::setw(8) << std::right << std::hex << std::uppercase << crcValue.at(count);
   }

   std::string currentHexValue{};

   textLineToStream >> currentHexValue;

   std::string newHexValue{};

   for (size_t i = 0; i < currentHexValue.size(); i += 2)
   {
      std::string twoBytes = currentHexValue.substr(i, 2);
      const auto chr = static_cast<char>(static_cast<int>(strtol(twoBytes.c_str(), nullptr, 16)));
      newHexValue.push_back(chr);
   }

   // Open the *.conf file for the user to see the contents of the file.
   CA2CT getPathNameCstring{ getPathName.c_str() };
   ShellExecute(nullptr, _T("open"), getPathNameCstring, nullptr, nullptr, SW_SHOW);

   /*
   * If there is no digits in the file, then get the CRC for the actual file.
   */
   if (0 == newHexValue.size())
   {
      MessageBoxA(nullptr, 
         "Error: The file does not have CRC values in it\nThe computed CRC is for the file and not the cumulated CRCs", 
         nullptr, MB_OK);

      return getBinaryFileCRC(getPathName);
   }
   else
   {
      /*
      * Divide the message by the polynomial, a byte at a time.
      */
      for (bytes byte = 0; byte < static_cast<bytes>(newHexValue.size()); ++byte)
      {
         data = static_cast<bits>(REFLECT_DATA(newHexValue.at(byte)) ^ (remainder >> (WIDTH - 8)));
         remainder = crcTable.at(data) ^ (remainder << 8);
      }

      /*
      * The final remainder is the CRC.
      */
      return REFLECT_REMAINDER(remainder) ^ FINAL_XOR_VALUE;
   }
}

void CCRC32CalculatorDlg::DisplayCRC(const std::wstring &fileName) const
{
   std::wstringstream logEntry_w{};
   std::wstring pBuffer_w{};

   // Hexadecimal Format
   logEntry_w << L"0x" << std::setfill(L'0') << std::setw(8) << std::right << std::hex << std::uppercase << crc32;
   logEntry_w >> pBuffer_w;
   GetDlgItem(IDC_EDIT_CRC32_HEX)->SetWindowTextW(pBuffer_w.c_str());
   log.fileOutPut_w() << fileName << L" CRC32(Hex): " << pBuffer_w << std::endl << std::flush;

   // Clear the stream
   logEntry_w.str(L"");
   logEntry_w.clear();

   pBuffer_w.erase();
   
   // Decimal Format
   logEntry_w << std::dec << crc32;
   logEntry_w >> pBuffer_w;
   GetDlgItem(IDC_EDIT_CRC32_DEC)->SetWindowTextW(pBuffer_w.c_str());
   log.fileOutPut_w() << fileName << L" CRC32(Dec): " << pBuffer_w << std::endl << std::flush;

   // Clear the stream
   logEntry_w.str(L"");
   logEntry_w.clear();
}

bool CCRC32CalculatorDlg::operator==(const CCRC32CalculatorDlg& other) const
{
    return false;
}
