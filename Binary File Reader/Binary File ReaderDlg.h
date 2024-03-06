
// Binary File ReaderDlg.h : header file
//

#pragma once
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <sstream>

constexpr UINT minExcelColumns{ 1 };
constexpr UINT maxExcelColumns{ 16383 };

// CBinaryFileReaderDlg dialog
class CBinaryFileReaderDlg : public CDialogEx
{
   // Construction
public:
   explicit CBinaryFileReaderDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
   enum { IDD = IDD_BINARYFILEREADER_DIALOG };
#endif

protected:
   void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support

   // Generated message map functions
   BOOL OnInitDialog() override;
   afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
   afx_msg void OnPaint();
   afx_msg HCURSOR OnQueryDragIcon();
   DECLARE_MESSAGE_MAP()

private:
   // Implementation
   HICON m_hIcon;
   int numOfBytesPerLine = 20;

public:
   afx_msg void OnBnClickedButtonOpenFile();
   afx_msg void OnBnClickedClose();
};