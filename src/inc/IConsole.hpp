//============================================================================
// Name        : IConsole
// Author      : Riyufuchi
// Created on  : Oct 13, 2023
// Last Edit   : Jan 28, 2025
// Description : This a base class Classes working with console
//============================================================================

#ifndef SRC_INC_ICONSOLE_HPP_
#define SRC_INC_ICONSOLE_HPP_

#include <sstream>

#include "ColorUtils.h"

namespace ConsoleLib
{
class IConsole
{
public:
	virtual void resetTextColor() = 0;
	virtual void defaultTextColor() = 0;
	// Getters
	virtual Color getDefaultTextColor()
	{
		return Color{211, 215, 207};
	}
	// Setters
	virtual void setTextColor(Color color) = 0;
	virtual void setDefaultTextColor(Color color) = 0;
	// Output methods
	virtual void out(const char* text) = 0;
	virtual void out(std::string text) = 0;
	virtual void out(Color color, std::string text) = 0;
	virtual void out(short int r, short int g, short int b, std::string text) = 0;
	virtual void err(std::string text) = 0;
	virtual void err(Color color, std::string text) = 0;
	virtual void err(short int r, short int g, short int b, std::string text) = 0;
	// Virtual destructor in the base class
	virtual ~IConsole() = default;
};
}
#endif /* CONSOLEUTILS_ICONSOLE_HPP_ */
