//==============================================================================
// File       : ConsoleLib.cpp
// Author     : riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Feb 24, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: consolelib
//==============================================================================

#include "../inc/ConsoleLib.h"

#define _COPYRIGHT_HEADER "Riyufuchi (c) 2023 - 2025"

namespace consolelib
{
ConsoleLib::ConsoleLib()
{
}
ConsoleLib::~ConsoleLib()
{
}
std::string ConsoleLib::aboutLibrary()
{
	return std::format("ConsoleLib {}\n{}\nCompiled on: {} {}\nC++ version: {}", _VERSION, _COPYRIGHT_HEADER, __DATE__, __TIME__, __cplusplus);
}
} /* namespace consolelib */
