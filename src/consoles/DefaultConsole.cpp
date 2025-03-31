//============================================================================
// Name        : DefaultConsole
// Author      : Riyufuchi
// Created on  : Feb 19, 2024
// Last Edit   : Mar 23, 2025
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../inc/DefaultConsole.h"
namespace ConsoleLib
{
DefaultConsole::DefaultConsole()
{
}
void DefaultConsole::disableCustomFG()
{
	//std::cout << "Nothing to reset\n";
}
void DefaultConsole::enableCustomFG()
{
	//std::cout << "Default console have already output in default color\n";
}
void DefaultConsole::enableCustomFG([[maybe_unused]] Color color)
{
	//std::cout << "Color [" << color.red << ";" << color.green << ";" << color.blue << "] can't be set by default console\n";
}
void DefaultConsole::setDefaultTextColor([[maybe_unused]] Color color)
{
}
void DefaultConsole::out(const std::string& text)
{
	std::cout << text;
}
void DefaultConsole::outHighlighted(const std::string& text)
{
	std::cout << text;

}
void DefaultConsole::out([[maybe_unused]] const Color& color, const std::string& text)
{
	std::cout << text;
}
void DefaultConsole::out([[maybe_unused]] short int r, [[maybe_unused]] short int g, [[maybe_unused]] short int b, const std::string& text)
{
	std::cout << text;

}
void DefaultConsole::err(const std::string& text)
{
	std::cerr << text;
}
void DefaultConsole::err([[maybe_unused]] const Color& color, const std::string& text)
{
	std::cerr << text;
}
void DefaultConsole::err([[maybe_unused]] short int r, [[maybe_unused]] short int g, [[maybe_unused]] short int b, const std::string& text)
{
	std::cerr << text;

}
DefaultConsole::~DefaultConsole()
{
	std::cout << "Destructed default console\n";
}
}
