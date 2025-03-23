//==============================================================================
// File       : ConsoleCallbackMenu.h
// Author     : riyufuchi
// Created on : Mar 15, 2025
// Last edit  : Mar 23, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef SRC_CONSOLEUTILS_CONSOLEMENU_H_
#define SRC_CONSOLEUTILS_CONSOLEMENU_H_

#include <utility>
#ifdef _WIN32
	#include <conio.h>  // For _kbhit() and _getch() on Windows
#else
	#include <unistd.h>
	#include <termios.h>
#endif

#include <vector>
#include <functional>

#include "IConsole.hpp"

#define CLEAR_SCREEN "\x1B[3J\x1B[H\x1B[2J"
#define HIGHLIGHT "\x1B[7m"
#define RESET "\x1B[0m"

namespace ConsoleLib
{
class ConsoleMenu
{
private:
	IConsole& console;
	std::vector<std::string>& menu;
	std::function<void()> printHeader;
	bool runMenu;
	size_t highlightedOptionID;
	void highlight();
	void resetHiglight();
	void clearConsole();
	void disableLineBuffering();
	void enableLineBuffering();
	void printMenu();
	char getch();
public:
	ConsoleMenu(IConsole& console, std::vector<std::string>& menu, std::function<void()> printHeader);
	virtual ~ConsoleMenu();
	void exitMenuLoop();
	int runMenuLoop();
};

} /* namespace ConsoleArt */

#endif /* SRC_CONSOLEUTILS_CONSOLEMENU_H_ */
