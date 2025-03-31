//==============================================================================
// File       : DefaultConsole.h
// Author     : Riyufuchi
// Created on : Feb 19, 2024
// Last edit  : Mar 31, 2025
// Copyright  : Copyright (c) 2024, Riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef SRC_INC_DEFAULTCONSOLE_H_
#define SRC_INC_DEFAULTCONSOLE_H_

#include <iostream>
#include <sstream>

#include "IConsole.hpp"

namespace ConsoleLib
{
class DefaultConsole : public IConsole
{
private:
public:
	DefaultConsole();
	~DefaultConsole();
	void disableCustomFG() override;
	void enableCustomFG() override;
	// Setters
	void setDefaultTextColor([[maybe_unused]] Color color) override;
	void enableCustomFG([[maybe_unused]] Color color) override;
	// Write methods
	virtual void out(const std::string& text) override;
	virtual void outHighlighted(const std::string& text) override;
	virtual void out(const Color& color, const std::string& text) override;
	virtual void out(short int r, short int g, short int b, const std::string& text) override;
	virtual void err(const std::string& text) override;
	virtual void err(const Color& color, const std::string& text) override;
	virtual void err(short int r, short int g, short int b, const std::string& text) override;
};
}
#endif /* SRC_INC_DEFAULTCONSOLE_H_ */
