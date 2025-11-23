//==============================================================================
// File       : RealNumber.cpp
// Author     : riyufuchi
// Created on : Jun 16, 2025
// Last edit  : Nov 20, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/RealNumber.h"

namespace ConsoleLib
{

RealNumber::RealNumber() : RealNumber(0)
{}

RealNumber::RealNumber(realNumberType number) : number(number)
{
}

RealNumber::~RealNumber() = default;

std::ostream& operator<<(std::ostream& os, const RealNumber& rn)
{
	return os << rn.number;
}

realNumberType RealNumber::getValue() const
{
	return number;
}

std::string RealNumber::toString() const
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(PRECISION) << number; // High precision to keep accuracy

	std::string str = oss.str();

	// Remove trailing zeroes and possibly the decimal point
	str.erase(str.find_last_not_of('0') + 1, std::string::npos); // Trim trailing '0's
	if (!str.empty() && str.back() == '.') // Remove trailing '.'
		str.pop_back();

	return str;
}

realNumberType RealNumber::getIntegerPart() const
{
	return std::trunc(number); //static_cast<realNumberType>(static_cast<long long>(number));
}

realNumberType RealNumber::getDecimalPart() const
{
	return number - std::trunc(number); //static_cast<realNumberType>(static_cast<long long>(number));
}

} /* namespace */
