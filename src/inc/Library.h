//==============================================================================
// File       : Library.h
// Author     : Riyufuchi
// Created on : Mar 27, 2024
// Last edit  : Jan 25, 2025
// Copyright  : Copyright (c) Riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef _CONSOLE_LIB_LIBRARY_H_
#define _CONSOLE_LIB_LIBRARY_H_

#include <iostream>

#define _VERSION "4.6"

namespace ConsoleLib
{
class Library
{
public:
	static constexpr const char* VERSION = _VERSION;
	Library();
	~Library();
	static void aboutLibrary();
};
} /* namespace ConsoleLib */
#endif /* _CONSOLE_LIB_LIBRARY_H_ */
