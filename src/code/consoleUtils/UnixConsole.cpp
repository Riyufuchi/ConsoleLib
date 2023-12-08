//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : 20.07.2020
// Last Edit   : 08.12.2023
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../../inc/UnixConsole.h"
namespace ConsoleUtils
{
UnixConsole::UnixConsole()
{
	mainColor.red = 5;
	mainColor.green = 195;
	mainColor.blue = 221;
}
void UnixConsole::resetTextColor()
{
	std::cout << "\e[m";
}
void UnixConsole::setTextColor(Colors::Color color)
{
	std::cout << "\e[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m";
}
void UnixConsole::setDefaultTextColor(Colors::Color color)
{
	mainColor = color;
}
Colors::Color UnixConsole::getDefaultTextColor()
{
	return mainColor;
}
void UnixConsole::out(const char* text)
{
	std::ostringstream t;
	t << "\e[38;2;" << mainColor.red << ";" << mainColor.green << ";" << mainColor.blue << "m" << text << "\e[m";
	std::cout << t.str();
}
void UnixConsole::out(std::string text)
{
	std::cout << "\e[38;2;" << mainColor.red << ";" << mainColor.green << ";" << mainColor.blue << "m" << text << "\e[m";
}
void UnixConsole::out(Colors::Color color, std::string text)
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
void UnixConsole::err(Colors::Color color, std::string text)
{
	std::cerr << "\e[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\e[m";
}
void UnixConsole::err(short int r, short int g, short int b, std::string text)
{
	std::cerr << "\e[38;2;" << r << ";" << g << ";" << b << "m" << text << "\e[m";

}
UnixConsole::~UnixConsole()
{
}
}
