//==============================================================================
// File       : Library.cpp
// Author     : riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Feb 24, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/Library.h"

#define _COPYRIGHT_HEADER "Riyufuchi (c) 2023 - 2025"

namespace ConsoleLib
{
Library::Library()
{
}
Library::~Library()
{
}
std::string Library::aboutLibrary()
{
	return std::format("ConsoleLib {}\n{}\nCompiled on: {} {}\nC++ version: {}", _VERSION, _COPYRIGHT_HEADER, __DATE__, __TIME__, __cplusplus);
}
} /* namespace ConsoleLib */
