//==============================================================================
// File       : DataUtils.cpp
// Author     : riyufuchi
// Created on : Mar 8, 2024
// Last edit  : Jan 29, 2025
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
	if (s.empty())
		return false;

	const size_t LENGHT = s.length();
	char c = ' ';

	for (size_t i = 0; i < LENGHT; ++i)
	{
		c = s[i];
		if (std::isdigit(c))
			continue;
		else if (c == '-')
		{
			if (i != 0)
				return false;
		}
		else
			return false;
	}


	if (s[0] == '-' && s.size() == 1)
		return false;
	return true;
}
bool DataUtils::isDouble(const std::string& s)
{
	if (s.empty())
		return false; // Empty string is not a valid number

	bool hasMinus = false;
	bool hasDot = false;
	const size_t LENGHT = s.length();
	char c = ' ';
	for (size_t i = 0; i < LENGHT; ++i)
	{
		c = s[i];
		if (std::isdigit(c))
		{
			continue; // Valid digit
		}
		else
		{
			switch (c)
			{
				case '-' :
					if (hasMinus || i != 0) // '-' is only allowed at the beginning
						return false;
					hasMinus = true;
				break;
				case '.':
					if (hasDot) // Only one dot is allowed
						return false;
					hasDot = true;
				break;
				default: return false; // Any other character is invalid
			}
		}
	}
	// Ensure the string is not just '-' or '.'
	if (s == "-" || s == "." || s == "-.")
		return false;
	return true;
}

std::string DataUtils::boolToString(bool value)
{
	return value ? "Yes" : "No";
}
} // namespace
