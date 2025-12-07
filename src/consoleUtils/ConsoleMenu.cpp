//==============================================================================
// File       : ConsoleCallbackMenu.cpp
// Author     : riyufuchi
// Created on : Mar 15, 2025
// Last edit  : Apr 24, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include "../inc/ConsoleMenu.h"

namespace consolelib
{

ConsoleMenu::ConsoleMenu(IConsole& console, std::vector<std::string>& menu, std::function<void()> printHeader) : console(console), menu(menu), printHeader(printHeader), runMenu(true), highlightedOptionID(0), key(' ')
{
}

ConsoleMenu::~ConsoleMenu()
{
}

void ConsoleMenu::flushInputBuffer()
{
#ifdef _WIN32
	while (_kbhit()) _getch(); // clears typed characters
#else
	tcflush(STDIN_FILENO, TCIFLUSH); // On POSIX
#endif
}

int ConsoleMenu::runMenuLoop()
{
	runMenu = true; // loop must runs every time this function is called
	if (menu.empty())
		runMenu = false;
	key = ' ';
	highlightedOptionID = 0;
	disableLineBuffering();
	flushInputBuffer();
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
					case 'A': highlightedOptionID = (highlightedOptionID + menu.size() - 1) % menu.size(); break; // Up Arrow
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
		return _getch(); // Windows
	#else
		char buf = 0;
		return (read(STDIN_FILENO, &buf, 1) > 0) ? buf : 0; // Unix-like systems
	#endif
}

void ConsoleMenu::exitMenuLoop()
{
	runMenu = false;
}

void ConsoleMenu::clearConsole()
{
	#ifdef _WIN32
		system("cls"); // Windows
	#else
		std::cout << CLEAR_SCREEN << std::flush; // Unix-like systems
	#endif
}

} /* namespace consoleart */
