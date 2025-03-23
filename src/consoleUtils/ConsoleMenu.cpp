//==============================================================================
// File       : ConsoleCallbackMenu.cpp
// Author     : riyufuchi
// Created on : Mar 15, 2025
// Last edit  : Mar 23, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/ConsoleMenu.h"

namespace ConsoleLib
{

ConsoleMenu::ConsoleMenu(IConsole& console, std::vector<std::string>& menu, std::function<void()> printHeader) : console(console), menu(menu), printHeader(printHeader), runMenu(true), highlightedOptionID(0)
{
}

ConsoleMenu::~ConsoleMenu()
{
}

int ConsoleMenu::runMenuLoop()
{
	if (menu.empty())
		runMenu = false;
	char key = ' ';
	highlightedOptionID = 0;
	disableLineBuffering();
	while (runMenu)
	{
		clearConsole();
		printHeader();
		printMenu();
		key = getch();
		if (key == 27) // Escape sequence starts with ESC (27)
		{
			key = getch();
			if (key == '[') // Confirm it's a special key sequence
			{
				key = getch(); // Get the final character
				switch (key)
				{
					case 'A': highlightedOptionID = (highlightedOptionID - 1 + menu.size()) % menu.size(); break; // Up Arrow
					case 'B': highlightedOptionID = (highlightedOptionID + 1) % menu.size(); break; // Down Arrow
				}
			}
		}
		else if (key == '\n')
		{
			runMenu = false;
		}
	}
	enableLineBuffering();
	return highlightedOptionID;
}

void ConsoleMenu::printMenu()
{
	for (size_t i = 0; i < menu.size(); ++i)
	{
		if (i == highlightedOptionID)
			console.outHighlighted(menu[i]);
		else
			console.out(menu[i]);
		std::cout << "\n";
	}
}

// Disable line buffering for non-blocking input
// Windows doesn't need to disable buffering; _kbhit() works out of the box.
void ConsoleMenu::disableLineBuffering()
{
#ifndef _WIN32 
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

// Enable line buffering after reading input
void ConsoleMenu::enableLineBuffering()
{
#ifndef _WIN32
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag |= (ICANON | ECHO); // Enable canonical mode and echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

// Function to get a single character input
char ConsoleMenu::getch()
{
	#ifdef _WIN32
		return _getch();  // Windows
	#else
		char buf = 0;
		ssize_t size = read(STDIN_FILENO, &buf, 1);
		return (size > 0) ? buf : 0;  // Unix-like systems
	#endif
}

void ConsoleMenu::exitMenuLoop()
{
	runMenu = false;
}

void ConsoleMenu::highlight()
{
	std::cout << HIGHLIGHT;
}
void ConsoleMenu::resetHiglight()
{
	std::cout << RESET;
}
void ConsoleMenu::clearConsole()
{
	#ifdef _WIN32
		system("cls");  // Windows
	#else
		std::cout << "\033[2J\033[1;1H" << std::flush;  // Unix-like systems
	#endif
}

} /* namespace ConsoleArt */
