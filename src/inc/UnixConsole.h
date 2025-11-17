//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : Jul 20, 2020
// Last Edit   : Nov 17, 2025
// Description : This class contains methods for working with a Linux console
//============================================================================

#ifndef _UNIXCONSOLE_H_
#define _UNIXCONSOLE_H_

#include <iostream>
#include <sstream>

#include "IConsole.hpp"

#define HIGHLIGHT "\x1B[7m"
#define RESET "\x1B[0m"

namespace ConsoleLib
{
class UnixConsole : public IConsole
{
private:
	Color defaultColor;
	std::string defColorEscCode;
public:
	UnixConsole();
	~UnixConsole();
	virtual void disableCustomFG() override;
	virtual void enableCustomFG() override;
	virtual void disableCustomBG() override;
	// Out methods
	virtual void out(const std::string& text) override;
	virtual void outHighlighted(const std::string& text) override;
	virtual void out(const Color& color, const std::string& text) override;
	virtual void out(short int r, short int g, short int b, const std::string& text) override;
	virtual void err(const std::string& text) override;
	virtual void err(const Color& color, const std::string& text) override;
	virtual void err(short int r, short int g, short int b, const std::string& text) override;
	// Setters
	virtual void setDefaultTextColor(Color color) override;
	virtual void enableCustomFG(Color color) override;
	virtual void enableCustomBG(Color color) override;
	// Getters
	virtual Color getDefaultTextColor() override;
};
}
#endif
