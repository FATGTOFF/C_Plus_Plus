
// Binary File ReaderDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Binary File Reader.h"
#include "Binary File ReaderDlg.h"
#include "afxdialogex.h"
#include <errno.h>

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


// CBinaryFileReaderDlg dialog



CBinaryFileReaderDlg::CBinaryFileReaderDlg(CWnd* pParent /*=nullptr*/)
   : CDialogEx(IDD_BINARYFILEREADER_DIALOG, pParent)
{
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBinaryFileReaderDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialogEx::DoDataExchange(pDX);
   DDX_Text(pDX, IDC_EDIT_NUM_BYTES_PER_LINE, numOfBytesPerLine);
   // The 16384 is the max columns on the Excel (As of 2 Jun 23)
   DDV_MinMaxUInt(pDX, numOfBytesPerLine, 1, 16383);
}

BEGIN_MESSAGE_MAP(CBinaryFileReaderDlg, CDialogEx)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE, &CBinaryFileReaderDlg::OnBnClickedButtonOpenFile)
   ON_BN_CLICKED(IDCLOSE, &CBinaryFileReaderDlg::OnBnClickedClose)
END_MESSAGE_MAP()


// CBinaryFileReaderDlg message handlers

BOOL CBinaryFileReaderDlg::OnInitDialog()
{
   CDialogEx::OnInitDialog();

   // Add "About..." menu item to system menu.

   // IDM_ABOUTBOX must be in the system command range.
   ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
   ASSERT(IDM_ABOUTBOX < 0xF000);

   CMenu* pSysMenu = GetSystemMenu(FALSE);
   if (pSysMenu != nullptr)
   {
      CString strAboutMenu;
      ASSERT(strAboutMenu.LoadString(IDS_ABOUTBOX));
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

void CBinaryFileReaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBinaryFileReaderDlg::OnPaint()
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
HCURSOR CBinaryFileReaderDlg::OnQueryDragIcon()
{
   return m_hIcon;
}


void CBinaryFileReaderDlg::OnBnClickedButtonOpenFile()
{

   // Save the number of bytes per line
   UpdateData(true);
   CString numOfBytesPerLine_Cstr;
   GetDlgItemText(IDC_EDIT_NUM_BYTES_PER_LINE, numOfBytesPerLine_Cstr);

   // Don't try to look for the file
   // if the bytes value is not validated.
   if (numOfBytesPerLine < 0 || numOfBytesPerLine > 16384)
   {
      // Placed a default value to the edit box.
      GetDlgItem(IDC_EDIT_NUM_BYTES_PER_LINE)->SetWindowTextW(L"20");
      return;
   }

   LPCTSTR pfileFilterOpen =
      _T("Binary (*.bin)|*.bin|")
      _T("Binary (*.old)|*.old|");

   CFileDialog dialogFileOpen(TRUE, _T("bin"), nullptr,
      OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, pfileFilterOpen, AfxGetMainWnd());

   if (IDOK != dialogFileOpen.DoModal())
   {
      return;
   }

   std::ifstream binaryFile(dialogFileOpen.GetPathName(), std::ios::in | std::ios::binary);
   std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(binaryFile), {});

   // Display the number of byte(s) in the file.
   std::ostringstream pbuffer{};
   pbuffer << "File Size: " << buffer.size() << " bytes";
   MessageBoxA(nullptr, pbuffer.str().c_str(), "Total of Bytes", MB_OK);
   // Clear the buffer.
   pbuffer.str("");
   pbuffer.clear();

   // convert from CString to std::string.
   // From https://stackoverflow.com/questions/258050/how-do-you-convert-cstring-and-stdstring-stdwstring-to-each-other
   CT2CA pszConvertedAnsiString_1(dialogFileOpen.GetPathName());
   std::string getPathName = pszConvertedAnsiString_1;

   binaryFile.close();

   CT2CA pszConvertedAnsiString_2(numOfBytesPerLine_Cstr);
   std::string numOfBytesPerLine_str = pszConvertedAnsiString_2;

   // Convert from CString to std::string to get the file name to save.
   CT2CA pszConvertedAnsiString_3(dialogFileOpen.GetFileTitle());
   std::string getFileTitle{ pszConvertedAnsiString_3 };

   LPCTSTR pfileFilterSave =
      _T("Text Documents (*.txt)|*.txt|")
      _T("Comma Separated Values (*.csv)|*.csv|");

   CFileDialog dialogFileSave(FALSE, _T("txt"), dialogFileOpen.GetFileTitle(),
      OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST, pfileFilterSave, AfxGetMainWnd());

   if (IDOK == dialogFileSave.DoModal())
   {
      CT2CA pszConvertedAnsiString_4(dialogFileSave.GetFileExt());
      std::string getFileExtension{ pszConvertedAnsiString_4 };

      std::ofstream outputFile(dialogFileSave.GetPathName());

      if (!outputFile)
      {
         MessageBoxA(nullptr, "Error: The file could not be opened", nullptr, MB_OK);
      }

      for (unsigned count = 0; count < buffer.size(); count++)
      {

         if ((0 == count % std::stoi(numOfBytesPerLine_str)) && 0 != count)
         {
            outputFile << "\n";
         }

         outputFile << std::setw(2) << std::internal << std::setfill('0');

         if ("csv" == getFileExtension)
         {
            outputFile << std::hex << std::uppercase << static_cast<int>(buffer.at(count)) << ',';
         }
         else
         {
            outputFile << std::hex << std::uppercase << static_cast<int>(buffer.at(count)) << ' ';
         }
         
      }

      outputFile.close();

      pbuffer <<  getFileTitle.c_str() << "." << getFileExtension.c_str() << " saved.";
      MessageBoxA(nullptr, pbuffer.str().c_str(), "Binary File Reader", MB_OK);
      // Clear the buffer.
      pbuffer.str("");
      pbuffer.clear();

      // Open the *.csv file for the user to see the contents of the file.
      ShellExecute(nullptr, _T("open"), dialogFileSave.GetPathName(), nullptr, nullptr, SW_SHOW);
   }


}

void CBinaryFileReaderDlg::OnBnClickedClose()
{
   // 0 or 1 is used for success/error.
   EndDialog(0);
   return;
}