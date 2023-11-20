
// Password_Generator_GUIDlg.h : header file
//
#pragma once
#include <iostream>
#include <cctype>
#include <cstdint>
#include <random>
#include <string>
#include <algorithm>


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

   int lengthOfPassword{ minPasswordLength };
   int lenghtPassCountDown{};
   int lastSliderCursorPos{};

   CButton* pAllOptionsCheck{};
   CButton* pUpperCasesCheck{};
   CButton* pLowerCasesCheck{};
   CButton* pNumberCasesCheck{};
   CButton* pSymbolsCasesCheck{};
   CButton* pAllSpecialCharactersCheck{};
   CButton* pMyPaySpecialCharactersCheck{};

   // The symbols allow to be used in passwords.
   static constexpr char specialCharactersForAll[]{
      '\'', '-', '!', '\"', '#', '$',
      '%', '&', '(', ')', '*', ',',
      '.', '/', ':', ';', '?', '@',
      '[', ']', '^', '_', '`', '{',
      '|', '}', '~', '+', '<', '=',
      '>' };

   // https://www.dfas.mil/mypayinfo/password/
   static constexpr char specialCharactersForMyPay[]{
   '#', '@', '$', '=', '+', '%',
   '^', '!', '*', '_' };

   void printNewPassword(std::string& newPassword);
   void randomizeUpperCaseLetters(std::string& newPassword);
   void randomizeLowerCaseLetters(std::string& newPassword);
   void randomizeSymbols(std::string& newPassword);
   void randomizeNumsForPasswords(std::string& newPassword);
   void randomizePasswordsAllOptions(std::string& newPassword);

   std::uint16_t randomNumber(std::uint16_t min, std::uint16_t max) const;
   bool allCheckMarked() const;
   bool upperLowerNumChecked() const;
   bool upperLowerSymbolsChecked() const;
   bool upperNumSymbolsChecked() const;
   bool lowerNumSymbolsChecked() const;

public:
   afx_msg void OnBnClickedGenPasswordButton();
   afx_msg void OnNMCustomdrawSliderLengthPassword(NMHDR *pNMHDR, LRESULT *pResult);
   afx_msg void OnBnClickedCheckUppercases();
   afx_msg void OnBnClickedCheckLowercases();
   afx_msg void OnBnClickedCheckNumbers();
   afx_msg void OnBnClickedCheckSpecialcases();
   afx_msg void OnBnClickedCheckAlloptions();
   afx_msg void OnBnClickedRadioMypay();
   afx_msg void OnBnClickedRadioAll();
};
