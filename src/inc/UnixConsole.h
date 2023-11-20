//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : 20.07.2020
// Last Edit   : 20.11.2023
// Description : This class contains methods for working with a Linux console
//============================================================================

#ifndef _UNIXCONSOLE_H_
#define _UNIXCONSOLE_H_
#include <iostream>
#include <sstream>

#include "IConsole.hpp"
namespace ConsoleUtils
{
//TODO: Add writeTextLine(std::string)
//TODO: Keep only useful overloads
class UnixConsole : public IConsole
{
public:
	UnixConsole();
	void writeText(const char* text) override;
	void writeText(std::string text) override;
	void writeText(Colors::Color color, std::string text) override;
	void writeText(short int r, short int g, short int b, std::string text) override;
	void setTextColor(Colors::Color color);
	~UnixConsole();
private:
	Colors::Color mainColor;
};
}
#endif
