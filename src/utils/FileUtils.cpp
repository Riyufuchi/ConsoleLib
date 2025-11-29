//==============================================================================
// File       : FileUtils.cpp
// Author     : riyufuchi
// Created on : Nov 28, 2025
// Last edit  : Nov 28, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/FileUtils.h"

namespace ConsoleLib
{

std::vector<std::string> FileUtils::splitCSV(const std::string& line, char delimeter, size_t expectedCount)
{
	std::vector<std::string> result;
	result.reserve(expectedCount);

	std::string current;
	for (size_t i = 0; i < line.length(); ++i)
	{
		if (line[i] == delimeter)
		{
			result.push_back(current);
			current.clear();
		}
		else
		{
			current += line[i];
		}
	}

	// Add the last field
	result.push_back(current);
	// Pad with empty strings if fewer than expected
	while (result.size() < expectedCount)
		result.push_back("");

	return result;
}

} /* namespace ConsoleLib */
