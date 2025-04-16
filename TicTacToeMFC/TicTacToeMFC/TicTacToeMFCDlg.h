
// TicTacToeMFCDlg.h : header file
//

#pragma once
#include <array>
#include <string>


// CTicTacToeMFCDlg dialog
class CTicTacToeMFCDlg : public CDialogEx
{
// Construction
public:
	CTicTacToeMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTACTOEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:

   enum class Button_Number
   {
      BUTTON_NUM_1 = 0,
      BUTTON_NUM_2,
      BUTTON_NUM_3,
      BUTTON_NUM_4,
      BUTTON_NUM_5,
      BUTTON_NUM_6,
      BUTTON_NUM_7,
      BUTTON_NUM_8,
      BUTTON_NUM_9,
      TOTAL_NUM_OF_BUTTONS
   };

   const wchar_t* X{ L"X" };
   const wchar_t* O{ L"O" };
   unsigned short player{1};
   CEdit* playerLabel{ nullptr };
   CEdit* winLabel{ nullptr };
   CFont  m_font{};

   std::array<const wchar_t*, static_cast<unsigned>(Button_Number::TOTAL_NUM_OF_BUTTONS)> buttonLabel{nullptr};
   std::array<CButton*, static_cast<unsigned>(Button_Number::TOTAL_NUM_OF_BUTTONS)> pButton{ nullptr };
   void printToLabel(const int nameID, const std::string& textToPrint) const;
   bool determineWinner() const;

   bool checkRow01() const;
   bool checkRow02() const;
   bool checkRow03() const;

   bool checkCol01() const;
   bool checkCol02() const;
   bool checkCol03() const;

   bool checkDiagonal01() const;
   bool checkDiagonal02() const;

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnBnClickedButton1();
   afx_msg void OnBnClickedButton2();
   afx_msg void OnBnClickedButton3();
   afx_msg void OnBnClickedButton4();
   afx_msg void OnBnClickedButton5();
   afx_msg void OnBnClickedButton6();
   afx_msg void OnBnClickedButton7();
   afx_msg void OnBnClickedButton8();
   afx_msg void OnBnClickedButton9();
   afx_msg void OnBnClickedButtonReset();
};
