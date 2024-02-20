//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : 20.07.2020
// Last Edit   : 20.02.2024
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../../inc/UnixConsole.h"
namespace ConsoleUtils
{
UnixConsole::UnixConsole() : defaultColor(Color{5, 195, 221})
{
	setDefaultTextColor(defaultColor);
}
void UnixConsole::resetTextColor()
{
	std::cout << "\e[m";
}
void UnixConsole::defaultTextColor()
{
	std::cout << defColorEscCode;
}
void UnixConsole::setTextColor(Color color)
{
	std::cout << "\e[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m";
}
void UnixConsole::setDefaultTextColor(Color color)
{
	defaultColor = color;
	std::ostringstream t;
	t << "\e[38;2;" << defaultColor.red << ";" << defaultColor.green << ";" << defaultColor.blue << "m";
	defColorEscCode = t.str();
}
Color UnixConsole::getDefaultTextColor()
{
	return defaultColor;
}
void UnixConsole::out(const char* text)
{
	std::cout << defColorEscCode << text << "\e[m";
}
void UnixConsole::out(std::string text)
{
	std::cout << defColorEscCode << text << "\e[m";
}
void UnixConsole::out(Color color, std::string text)
{
	std::cout << "\e[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\e[m";
}
void UnixConsole::out(short int r, short int g, short int b, std::string text)
{
	std::cout << "\e[38;2;" << r << ";" << g << ";" << b << "m" << text << "\e[m";

}
void UnixConsole::err(std::string text)
{
	std::cerr << "\e[38;2;" << 255 << ";0;0m" << text << "\e[m";
}
void UnixConsole::err(Color color, std::string text)
{
	std::cerr << "\e[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\e[m";
}
void UnixConsole::err(short int r, short int g, short int b, std::string text)
{
	std::cerr << "\e[38;2;" << r << ";" << g << ";" << b << "m" << text << "\e[m";

}
UnixConsole::~UnixConsole()
{
	std::cout << "Destructed Unix console\n";
}
}
