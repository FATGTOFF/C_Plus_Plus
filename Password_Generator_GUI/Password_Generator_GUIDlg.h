
// Password_Generator_GUIDlg.h : header file
//

#pragma once
#include <iostream>
#include <cctype>
#include <cstdint>
#include <random>
#include <string>
#include <algorithm>
#include <limits>

#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <sstream>
#include <array>
#include <cstdint>


// CPasswordGeneratorGUIDlg dialog
class CPasswordGeneratorGUIDlg : public CDialogEx
{
// Construction
public:
	CPasswordGeneratorGUIDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORD_GENERATOR_GUI_DIALOG };
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
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
   static constexpr std::uint16_t minPasswordLength{ 8 };
   static constexpr std::uint16_t maxPasswordLength{ 50 };
   int lengthOfPassword{};
   int lenghtPassCountDown{};

   // The symbols allow to be used in passwords.
   static constexpr char specialCharacters[]{
      '\'', '-', '!', '\"', '#', '$',
      '%', '&', '(', ')', '*', ',',
      '.', '/', ':', ';', '?', '@',
      '[', ']', '^', '_', '`', '{',
      '|', '}', '~', '+', '<', '=',
      '>' };

   void printNewPassword(std::string& newPassword);
   void randomizeUpperCaseLetters(std::string& newPassword);
   void randomizeLowerCaseLetters(std::string& newPassword);
   void randomizeSymbols(std::string& newPassword);
   void randomizeNumsForPasswords(std::string& newPassword);
   std::uint16_t randomNumber(std::uint16_t min, std::uint16_t max) const;

public:
   afx_msg void OnBnClickedGenPasswordButton();
   afx_msg void OnNMCustomdrawSliderLengthPassword(NMHDR *pNMHDR, LRESULT *pResult);
};
