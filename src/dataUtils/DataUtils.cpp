//==============================================================================
// File       : DataUtils.cpp
// Author     : riyufuchi
// Created on : Mar 8, 2024
// Last edit  : Jan 25, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/DataUtils.h"

namespace ConsoleLib
{
DataUtils::DataUtils()
{}
DataUtils::~DataUtils()
{}
bool DataUtils::isNumber(const std::string& s)
{
	for (char c : s)
		if (!std::isdigit(c))
			return false;
	return true;
}
} // namespace
