//==============================================================================
// File       : ConsoleCallbackMenu.h
// Author     : riyufuchi
// Created on : Mar 15, 2025
// Last edit  : Mar 23, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef SRC_CONSOLEUTILS_CONSOLECALLBACKMENU_H_
#define SRC_CONSOLEUTILS_CONSOLECALLBACKMENU_H_

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

#define CLEAR_SCREEN "\033[2J\033[1;1H"
#define HIGHLIGHT "\033[7m"
#define RESET "\033[0m"

namespace ConsoleLib
{
class ConsoleCallbackMenu
{
private:
	IConsole& console;
	std::vector<std::pair<std::string, std::function<void()>>>& menu;
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
	ConsoleCallbackMenu(IConsole& console, std::vector<std::pair<std::string, std::function<void()>>>& menu);
	virtual ~ConsoleCallbackMenu();
	void exitMenuLoop();
	void runMenuLoop();
};

} /* namespace ConsoleArt */

#endif /* SRC_CONSOLEUTILS_CONSOLEMENU_H_ */
