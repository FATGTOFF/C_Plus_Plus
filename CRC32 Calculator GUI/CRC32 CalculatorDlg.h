
// CRC32 CalculatorDlg.h : header file
//

#pragma once
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <sstream>
#include <array>

// Provide some meaningful names with the known data types.
using crc = unsigned long;
using bytes = int;
using bits = uint8_t;

constexpr uint16_t SIZEOFCRCTABLE{ 256 };


// CCRC32CalculatorDlg dialog
class CCRC32CalculatorDlg : public CDialogEx
{
// Construction
public:
	CCRC32CalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRC32CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon() noexcept;
	DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnBnClickedButtonOpenFile();

private:
   /* Constant values that we can define it at compile time. */
   static constexpr uint32_t POLYNOMIAL{ 0x04C11DB7 };
   static constexpr uint32_t INITIAL_REMAINDER{ 0xFFFFFFFF };
   static constexpr uint32_t FINAL_XOR_VALUE{ 0xFFFFFFFF };
   static constexpr uint32_t CHECK_VALUE{ 0xCBF43926 };
   static constexpr uint32_t WIDTH{ 8 * sizeof(crc) };
   static constexpr int TOPBIT{ 1 << (WIDTH - 1) };

   crc reflect(unsigned long data, bits nBits) const;
   crc REFLECT_DATA(unsigned long X) const;
   crc REFLECT_REMAINDER(unsigned long X) const;
   crc getBinaryFileCRC(std::string) const;
   crc getConfFileCRC(std::string) const;
   void DisplayCRC();
   void crcInit() noexcept;

   crc crc32;
   std::array<crc, SIZEOFCRCTABLE> crcTable{};
};