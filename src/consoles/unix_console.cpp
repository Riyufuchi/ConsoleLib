//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : Jul 20, 2020
// Last Edit   : Jan 13, 2026
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../consolelib/consoles/unix_console.h"

namespace consolelib
{
UnixConsole::UnixConsole() : defaultColor(Color{5, 195, 221})
{
	set_default_fg_color(defaultColor);
}
void UnixConsole::disable_custom_bg() const
{
	std::cout << RESET;
}
void UnixConsole::enable_custom_bg(const Color& color) const
{
	std::cout << "\x1B[48;2;" << color.red << ";" << color.green << ";" << color.blue << "m";
}
void UnixConsole::disable_custom_fg() const
{
	std::cout << "\x1B[m";
}
void UnixConsole::enable_custom_fg() const
{
	std::cout << defColorEscCode;
}
void UnixConsole::enable_custom_fg(const Color& color) const
{
	std::cout << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m";
}
void UnixConsole::set_default_fg_color(Color color)
{
	defaultColor = color;
	std::ostringstream t;
	t << "\x1B[38;2;" << defaultColor.red << ";" << defaultColor.green << ";" << defaultColor.blue << "m";
	defColorEscCode = t.str();
}
Color UnixConsole::get_default_fg_color() const
{
	return defaultColor;
}
void UnixConsole::out(const std::string& text) const
{
	std::cout << defColorEscCode << text << "\x1B[m";
}
void UnixConsole::out_highlighted(const std::string& text) const
{
	std::cout << HIGHLIGHT << defColorEscCode << text << RESET;

}
void UnixConsole::out(const Color& color, const std::string& text) const
{
	std::cout << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\x1B[m";
}
void UnixConsole::out(short int r, short int g, short int b, const std::string& text) const
{
	std::cout << "\x1B[38;2;" << r << ";" << g << ";" << b << "m" << text << "\x1B[m";

}
void UnixConsole::err(const std::string& text) const
{
	std::cerr << "\x1B[38;2;" << 255 << ";0;0m" << text << "\x1B[m";
}
void UnixConsole::err(const Color& color, const std::string& text) const
{
	std::cerr << "\x1B[38;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << text << "\x1B[m";
}
void UnixConsole::err(short int r, short int g, short int b, const std::string& text) const
{
	std::cerr << "\x1B[38;2;" << r << ";" << g << ";" << b << "m" << text << "\x1B[m";
}
UnixConsole::~UnixConsole()
{
	std::cout << "Destructed Unix console\n";
}

}
