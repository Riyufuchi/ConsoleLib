//============================================================================
// Name        : UnixConsole
// Author      : Riyufuchi
// Created on  : Jul 20, 2020
// Last Edit   : Mar 23, 2025
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
	void disableCustomFG() override;
	void enableCustomFG() override;
	// Out methods
	virtual void out(const std::string& text) override;
	virtual void outHighlighted(const std::string& text) override;
	virtual void out(const Color& color, const std::string& text) override;
	virtual void out(short int r, short int g, short int b, const std::string& text) override;
	virtual void err(const std::string& text) override;
	virtual void err(const Color& color, const std::string&) override;
	virtual void err(short int r, short int g, short int b, const std::string& text) override;


	/*virtual void out(const std::string& text) override;
	virtual void out(Color color, std::string text) override;
	virtual void out(short int r, short int g, short int b, std::string text) override;
	virtual void err(std::string text) override;
	virtual void err(Color color, std::string text) override;
	virtual void err(short int r, short int g, short int b, std::string text) override;*/
	// Setters
	void setDefaultTextColor(Color color) override;
	void enableCustomFG(Color color) override;
	// Getters
	Color getDefaultTextColor() override;
};
}
#endif
