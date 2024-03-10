//============================================================================
// Name        : DefaultConsole
// Author      : Riyufuchi
// Created on  : Feb 19, 2024
// Last Edit   : Feb 20, 2024
// Description : This class contains methods for working with a Linux console
//============================================================================

#include "../../inc/DefaultConsole.h"
namespace ConsoleUtility
{
DefaultConsole::DefaultConsole()
{
}
void DefaultConsole::resetTextColor()
{
	//std::cout << "Nothing to reset\n";
}
void DefaultConsole::defaultTextColor()
{
	//std::cout << "Default console have already output in default color\n";
}
void DefaultConsole::setTextColor(Color color)
{
	//std::cout << "Color [" << color.red << ";" << color.green << ";" << color.blue << "] can't be set by default console\n";
}
void DefaultConsole::setDefaultTextColor(Color color)
{
	//setTextColor(color);
}
void DefaultConsole::out(const char* text)
{
	std::cout << text;
}
void DefaultConsole::out(std::string text)
{
	std::cout << text;
}
void DefaultConsole::out(Color color, std::string text)
{
	std::cout << text;
}
void DefaultConsole::out(short int r, short int g, short int b, std::string text)
{
	std::cout << text;

}
void DefaultConsole::err(std::string text)
{
	std::cerr << text;
}
void DefaultConsole::err(Color color, std::string text)
{
	std::cerr << text;
}
void DefaultConsole::err(short int r, short int g, short int b, std::string text)
{
	std::cerr << text;

}
DefaultConsole::~DefaultConsole()
{
	std::cout << "Destructed default console\n";
}
}
