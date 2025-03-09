//==============================================================================
// File       : Library.h
// Author     : Riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Feb 24, 2025
// Copyright  : Copyright (c) Riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef _CONSOLE_LIB_LIBRARY_H_
#define _CONSOLE_LIB_LIBRARY_H_

#include <iostream>
#include <string>
#include <format>

#define _VERSION "4.9"

namespace ConsoleLib
{
class Library
{
public:
	static constexpr const char* VERSION = _VERSION;
	Library();
	~Library();
	static std::string aboutLibrary();
};
} /* namespace ConsoleLib */
#endif /* _CONSOLE_LIB_LIBRARY_H_ */
