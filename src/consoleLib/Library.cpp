//==============================================================================
// File       : Library.cpp
// Author     : riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Jan 14, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/Library.h"

#define _COPYRIGHT_HEADER "Riyufuchi (c) 2023 - 2025\n"

namespace ConsoleLib
{
Library::Library()
{
}
Library::~Library()
{
}
void Library::aboutLibrary()
{
	std::cout << "ConsoleLib " << _VERSION << "\n";
	printf("Compiled on: %s %s\nC++ version: %ld\n\n%s\n", __DATE__, __TIME__, __cplusplus, _COPYRIGHT_HEADER);
}
} /* namespace ConsoleLib */
