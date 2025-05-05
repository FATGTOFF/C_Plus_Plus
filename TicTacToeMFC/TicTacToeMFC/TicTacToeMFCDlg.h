
// TicTacToeMFCDlg.h : header file
//

#pragma once
#include <array>
#include <chrono>
#include <random>
#include <string>
#include <thread>


// CTicTacToeMFCDlg dialog
class CTicTacToeMFCDlg : public CDialogEx
{
// Construction
public:
	explicit CTicTacToeMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTACTOEMFC_DIALOG };
#endif

	protected:
	void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support


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

   int player{1};
   const wchar_t* X{ L"X" };
   const wchar_t* O{ L"O" };
   CEdit* playerLabel{ nullptr };
   CEdit* winLabel{ nullptr };
   CStatic* playerNumlabel{ nullptr };
   CFont  m_font{};

   std::array<const wchar_t*, static_cast<unsigned>(Button_Number::TOTAL_NUM_OF_BUTTONS)> buttonLabel{nullptr};
   std::array<CButton*, static_cast<unsigned>(Button_Number::TOTAL_NUM_OF_BUTTONS)> pButton{ nullptr };
   void printToLabel(const std::string& textToPrint) const;
   bool determineWinner() const;
   std::size_t randomNumber(const std::size_t max) const;
   std::size_t randomNumber(const std::size_t min, const std::size_t max) const;
   void determinePlayerTurn();
   bool computerTurn(const std::size_t computerSelect);
   void computerSelectedButton(const Button_Number buttonNumber);
   void playerSelectedButton(const Button_Number buttonNumber);
   void computerSelects();

   /*
          Tic-Tac-Toe format
           Col 01  Col 02  Col 03
   Row 01 |   1   |   2   |   3   |
   Row 02 |   4   |   5   |   6   |
   Row 03 |   7   |   8   |   9   |
   */
   //Buttons 1->2->3
   bool checkRow01() const;
   //Buttons 4->5->8
   bool checkRow02() const;
   //Buttons 7->8->9
   bool checkRow03() const;
   //Buttons 1->4->7
   bool checkCol01() const;
   //Buttons 2->5->8
   bool checkCol02() const;
   //Buttons 3->6->9
   bool checkCol03() const;
   //Buttons 1->5->9
   bool checkDiagonal01() const;
   //Buttons 3->5->7
   bool checkDiagonal02() const;

   bool allButtonsFilled() const;

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
   afx_msg void OnBnClickedButtonClose();
};
