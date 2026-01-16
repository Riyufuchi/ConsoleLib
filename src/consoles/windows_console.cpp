//============================================================================
// Name        : WindowsConsole
// Author      : Riyufuchi
// Created on  : Feb 28, 2024
// Last Edit   : Jan 16, 2026
//============================================================================

#ifdef _WIN32
#include "../consolelib/consoles/windows_console.h"

namespace consolelib
{
	WindowsConsole::WindowsConsole() : UnixConsole()
	{
		enableVirtualTerminalProcessing(); // Allows Unix style escape codes
		// Enabling UNICODE
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		set_default_fg_color(Color{ 204, 204, 204 });
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
