//==============================================================================
// File       : DefaultConsole.h
// Author     : Riyufuchi
// Created on : Feb 19, 2024
// Last edit  : Jan 28, 2025
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
	void resetTextColor() override;
	void defaultTextColor() override;
	// Setters
	void setDefaultTextColor([[maybe_unused]] Color color) override;
	void setTextColor([[maybe_unused]] Color color) override;
	// Write methods
	void out(const char* text) override;
	void out(std::string text) override;
	void out([[maybe_unused]] Color color, std::string text) override;
	void out([[maybe_unused]] short int r, [[maybe_unused]] short int g, [[maybe_unused]] short int b, std::string text) override;
	void err(std::string text) override;
	void err([[maybe_unused]] Color color, std::string text) override;
	void err([[maybe_unused]] short int r, [[maybe_unused]] short int g, [[maybe_unused]] short int b, std::string text) override;
};
}
#endif /* SRC_INC_DEFAULTCONSOLE_H_ */
