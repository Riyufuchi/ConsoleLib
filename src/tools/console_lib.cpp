//==============================================================================
// File       : ConsoleLib.cpp
// Author     : riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Dec 23, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: consolelib
//==============================================================================

#include "../consolelib/console_lib.h"

namespace consolelib
{
std::string aboutLibrary()
{
	return std::format("ConsoleLib {}\n{}\nCompiled on: {} {}\nC++ version: {}", _VERSION, _COPYRIGHT_HEADER, __DATE__, __TIME__, __cplusplus);
}
}
