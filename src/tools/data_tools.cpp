//==============================================================================
// File       : DataUtils.cpp
// Author     : riyufuchi
// Created on : Mar 08, 2024
// Last edit  : Dec 22, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: consolelib
//==============================================================================

#include "../consolelib/tools/data_tools.h"

namespace consolelib::data_tools
{
bool isNumber(const std::string& s)
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
bool isDouble(const std::string& s)
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

std::string boolToString(bool value)
{
	return value ? "Yes" : "No";
}

std::u32string string_to_u32string(const std::string& s)
{
	std::u32string out;

	char32_t cp = 0;
	unsigned char c = 0;

	for (size_t i = 0; i < s.size();)
	{
		cp = 0;
		c = s[i];

		if (c <= 0x7F)
		{
			cp = c;
			i += 1;
		}
		else if ((c & 0xE0) == 0xC0)
		{
			cp = ((c & 0x1F) << 6)
			| (s[i + 1] & 0x3F);
			i += 2;
		}
		else if ((c & 0xF0) == 0xE0)
		{
			cp = ((c & 0x0F) << 12)
			| ((s[i + 1] & 0x3F) << 6)
				| (s[i + 2] & 0x3F);
			i += 3;
		}
		else if ((c & 0xF8) == 0xF0)
		{
			cp = ((c & 0x07) << 18)
			| ((s[i + 1] & 0x3F) << 12)
				| ((s[i + 2] & 0x3F) << 6)
				| (s[i + 3] & 0x3F);
			i += 4;
		}
		else
		{
			throw std::runtime_error("Invalid UTF-8");
		}

		out.push_back(cp);
	}

	return out;
}

std::string u32char_to_string(char32_t cp)
{
	std::string out;

	if (cp <= 0x7F)
	{
		out.push_back(static_cast<char>(cp));
	}
	else if (cp <= 0x7FF)
	{
		out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
		out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
	}
	else if (cp <= 0xFFFF)
	{
		out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
		out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
		out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
	}
	else
	{
		out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
		out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
		out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
		out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
	}

	return out;
}

} // namespace
