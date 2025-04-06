//============================================================================
// Name        : WindowsConsole
// Author      : Riyufuchi
// Created on  : Feb 28, 2024
// Last Edit   : Mar 31, 2025
//============================================================================

#ifdef _WIN32
#include "../inc/WindowsConsole.h"

namespace ConsoleLib
{
	WindowsConsole::WindowsConsole() : UnixConsole()
	{
		enableVirtualTerminalProcessing(); // Allows Unix style escape codes
		// Enabling UNICODE
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setDefaultTextColor(Color{ 204, 204, 204 });
	}

	WindowsConsole::~WindowsConsole()
	{
	}
	
	void WindowsConsole::enableVirtualTerminalProcessing()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}
}
#endif
