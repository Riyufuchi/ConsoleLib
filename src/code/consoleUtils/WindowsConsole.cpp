//============================================================================
// Name        : WindowsConsole
// Author      : Riyufuchi
// Created on  : 28.02.2024
// Last Edit   : Mar 4, 2024
//============================================================================

#ifdef _WIN32
#include "../../inc/WindowsConsole.h"

namespace ConsoleUtility
{
	WindowsConsole::WindowsConsole() : defaultColor(Color{204, 204, 204})
	{
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (consoleHandle == INVALID_HANDLE_VALUE)
		{
			throw std::runtime_error("Failed to get console handle");
		}
		consoleInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		GetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
		consoleInfo.ColorTable[DEFAULT_COLOR_INDEX] = RGB(204, 204, 204);
		SetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
		SetConsoleTextAttribute(consoleHandle, CURRENT_COLOR_INDEX);
		// Enabling UNICODE
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
}

	WindowsConsole::~WindowsConsole()
	{
	}

	void WindowsConsole::resetTextColor()
	{
		SetConsoleTextAttribute(consoleHandle, DEFAULT_COLOR_INDEX);
	}

	void WindowsConsole::defaultTextColor()
	{
		SetConsoleTextAttribute(consoleHandle, DEFAULT_COLOR_INDEX);
	}

	void WindowsConsole::setDefaultTextColor(Color color)
	{
		defaultColor = color;
		consoleInfo.ColorTable[DEFAULT_COLOR_INDEX] = RGB((uint8_t)color.red, (uint8_t)color.green, (uint8_t)color.blue);
		SetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
		SetConsoleTextAttribute(consoleHandle, DEFAULT_COLOR_INDEX);
	}

	void WindowsConsole::setTextColor(Color color)
	{
		if (colorIndex >= COLOR_TABLE_LENGHT)
			colorIndex = COLOR_TABLE_START_INDEX;
		consoleInfo.ColorTable[colorIndex] = RGB(color.red, color.green, color.blue);
		SetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorIndex);
		colorIndex++;
	}

	Color WindowsConsole::getDefaultTextColor()
	{
		return defaultColor;
	}

	void WindowsConsole::out(const char* text)
	{
		std::cout << text;
	}

	void WindowsConsole::out(std::string text)
	{
		std::cout << text;
	}

	void WindowsConsole::out(Color color, std::string text)
	{
		setTextColor(color);
		std::cout << text;
	}

	void WindowsConsole::out(short int r, short int g, short int b, std::string text)
	{
		setTextColor(Color{ r, g, b });
		std::cout << text;
	}

	void WindowsConsole::err(std::string text)
	{
		std::cerr << text;
	}

	void WindowsConsole::err(Color color, std::string text)
	{
		setTextColor(color);
		std::cerr << text;
	}

	void WindowsConsole::err(short int r, short int g, short int b, std::string text)
	{
		setTextColor(Color{ r, g, b });
		std::cerr << text;
	}
}
#endif
