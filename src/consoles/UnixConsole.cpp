//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : Jul 20, 2020
// Last Edit   : Mar 31, 2025
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../inc/UnixConsole.h"

namespace ConsoleLib
{
UnixConsole::UnixConsole() : defaultColor(Color{5, 195, 221})
{
	setDefaultTextColor(defaultColor);
}
void UnixConsole::disableCustomFG()
{
	std::cout << "\x1B[m";
}
void UnixConsole::enableCustomFG()
{
	std::cout << defColorEscCode;
}
void UnixConsole::enableCustomFG(Color color)
{
	std::cout << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m";
}
void UnixConsole::setDefaultTextColor(Color color)
{
	defaultColor = color;
	std::ostringstream t;
	t << "\x1B[38;2;" << defaultColor.red << ";" << defaultColor.green << ";" << defaultColor.blue << "m";
	defColorEscCode = t.str();
}
Color UnixConsole::getDefaultTextColor()
{
	return defaultColor;
}
void UnixConsole::out(const std::string& text)
{
	std::cout << defColorEscCode << text << "\x1B[m";
}
void UnixConsole::outHighlighted(const std::string& text)
{
	std::cout << HIGHLIGHT << defColorEscCode << text << RESET;

}
void UnixConsole::out(const Color& color, const std::string& text)
{
	std::cout << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\x1B[m";
}
void UnixConsole::out(short int r, short int g, short int b, const std::string& text)
{
	std::cout << "\x1B[38;2;" << r << ";" << g << ";" << b << "m" << text << "\x1B[m";

}
void UnixConsole::err(const std::string& text)
{
	std::cerr << "\x1B[38;2;" << 255 << ";0;0m" << text << "\x1B[m";
}
void UnixConsole::err(const Color& color, const std::string& text)
{
	std::cerr << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\x1B[m";
}
void UnixConsole::err(short int r, short int g, short int b, const std::string& text)
{
	std::cerr << "\x1B[38;2;" << r << ";" << g << ";" << b << "m" << text << "\x1B[m";
}
UnixConsole::~UnixConsole()
{
	std::cout << "Destructed Unix console\n";
}

}
