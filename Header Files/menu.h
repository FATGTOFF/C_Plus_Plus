#ifndef MENU_H
#define MENU_H
#include <string>
#include <Windows.h>


class Menu
{
protected:

	int numofStates;
	int pos;
	std::string state;
	std::string statesFileName;
	std::string *abreviatedState{ nullptr };
	std::string *fullState{ nullptr };
	HANDLE outPut;
	CONSOLE_CURSOR_INFO ci;
	HWND hWnd;
	DWORD flag;
	DWORD written;
	COORD goTo(short, short);
	std::string notifyPressButton;
	int choice;
	int count;
	short xCoord;
	short yCoord;
	char waitPeriod;
	char tryAgain;
	bool salida;
	void displayMainMenu();
	void displaySubMenu();
	void displayStates() const;
	void displayCountdownTimer(int,short,short) const;
	void displayRules();
	void InputNumberOnly(int&, short, short);
	void displayTitle();
	void setStatesFileName(std::string);
	void setStates();
	void searchStates(const std::string[], const std::string[], int, std::string);


public:
	Menu();
	~Menu();
	void ClearScreen(short, short) const;
	std::string getStatesFileName() const;
	void menu();

};
#endif