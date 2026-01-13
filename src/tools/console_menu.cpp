//==============================================================================
// File       : ConsoleCallbackMenu.cpp
// Author     : riyufuchi
// Created on : Mar 15, 2025
// Last edit  : Jan 13, 2026
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include "../consolelib/tools/console_menu.h"

namespace consolelib
{

ConsoleMenu::ConsoleMenu(IConsole& console, std::vector<std::string>& menu, std::function<void()> print_header_function) : console(console), menu(menu), print_header_function(print_header_function),
	run_menu(true), highlighted_option_id(0), key(' ')
{
}

ConsoleMenu::~ConsoleMenu()
{
}

void ConsoleMenu::flush_input_buffer()
{
#ifdef _WIN32
	while (_kbhit()) _getch(); // clears typed characters
#else
	tcflush(STDIN_FILENO, TCIFLUSH); // On POSIX
#endif
}

#ifdef _WIN32
ConsoleMenu::KeyType ConsoleMenu::obtain_key_type()
{
	key = getch();

	if (key == 0 || key == 224)
	{
		key = getch();
		switch (key)
		{
		case 72: return KeyType::ARROW_UP;
		case 80: return KeyType::ARROW_DOWN;
		}
	}
	else if (key == 13)
	{
		return KeyType::ENTER;
	}
	return KeyType::UNKNOWN;
}
#else
ConsoleMenu::KeyType ConsoleMenu::obtain_key_type()
{
	key = getch();
	if (key == 27) // Escape sequence starts with ESC (27)
	{
		key = getch();
		if (key == '[') // Confirm it's a special key sequence
		{
			key = getch(); // Get the final character
			switch (key)
			{
			case 'A': return KeyType::ARROW_UP;
			case 'B': return KeyType::ARROW_DOWN;
			}
		}
	}
	else if (key == '\n')
	{
		return KeyType::ENTER;
	}
	return KeyType::UNKNOWN;
}
#endif

int ConsoleMenu::run_menu_loop()
{
	run_menu = true; // loop must runs every time this function is called
	if (menu.empty())
		run_menu = false;
	key = ' ';
	highlighted_option_id = 0;
	disable_line_buffering();
	flush_input_buffer();
	while (run_menu)
	{
		clear_console();
		print_header_function();
		print_menu();
		switch (obtain_key_type())
		{
			case KeyType::ARROW_UP: highlighted_option_id = (highlighted_option_id + menu.size() - 1) % menu.size(); break; // Up Arrow
			case KeyType::ARROW_DOWN: highlighted_option_id = (highlighted_option_id + 1) % menu.size(); break; // Down Arrow
			case KeyType::ENTER: run_menu = false; break;
			default: break;
		}
	}
	enable_line_buffering();
	return highlighted_option_id;
}

void ConsoleMenu::print_menu()
{
	for (size_t i = 0; i < menu.size(); ++i)
	{
		if (i == highlighted_option_id)
			console.out_highlighted(menu[i]);
		else
			console.out(menu[i]);
		std::cout << "\n";
	}
}

// Disable line buffering for non-blocking input
// Windows doesn't need to disable buffering; _kbhit() works out of the box.
void ConsoleMenu::disable_line_buffering()
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
void ConsoleMenu::enable_line_buffering()
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

void ConsoleMenu::exit_menu_loop()
{
	run_menu = false;
}

void ConsoleMenu::clear_console()
{
	#ifdef _WIN32
		system("cls"); // Windows
	#else
		std::cout << CLEAR_SCREEN << std::flush; // Unix-like systems
	#endif
}

} /* namespace consoleart */
