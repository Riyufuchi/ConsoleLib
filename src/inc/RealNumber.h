//==============================================================================
// File       : RealNumber.h
// Author     : riyufuchi
// Created on : Jun 16, 2025
// Last edit  : Jun 19, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef SRC_CONSOLELIB_REALNUMBER_H_
#define SRC_CONSOLELIB_REALNUMBER_H_

#include <concepts>
#include <type_traits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#define PRECISION 10

namespace ConsoleLib
{

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

using realNumberType = long double;

class RealNumber
{
private:
	realNumberType number;
public:
	RealNumber();
	RealNumber(realNumberType numbers);
	~RealNumber();

	// Allow implicit conversion from int, float, etc.
	template<Arithmetic T>
	RealNumber(T value) : number(static_cast<realNumberType>(value))
	{}

	explicit operator realNumberType() const
	{
		return number;
	}

	explicit operator std::string() const
	{
		return toString();
	}

	bool operator > (const RealNumber& other) const
	{
		return number > other.number;
	}

	bool operator < (const RealNumber& other) const
	{
		return number < other.number;
	}

	bool operator == (const RealNumber& other) const
	{
		return number == other.number;
	}

	bool operator != (const RealNumber& other) const
	{
		return number != other.number;
	}

	// +

	RealNumber operator+() const
	{
		return RealNumber(std::abs(number));
	}

	RealNumber operator + (const RealNumber& other) const
	{
		return RealNumber(number + other.number);
	}

	RealNumber& operator += (const RealNumber& other)
	{
		number += other.number;
		return *this;
	}

	template<Arithmetic T>
	RealNumber& operator += (const T& other)
	{
		number += static_cast<realNumberType>(other);
		return *this;
	}

	RealNumber& operator ++ ()
	{
		number++;
		return *this;
	}

	RealNumber operator++(int) // Postfix
	{
		RealNumber temp = *this; // Store original
		number++;
		return temp; // Return the original state
	}

	// -

	RealNumber operator-() const
	{
		return RealNumber(-1 * number);
	}

	template<Arithmetic T>
	RealNumber& operator -= (const T& other)
	{
		number += static_cast<realNumberType>(other);
		return *this;
	}

	RealNumber operator -= (const RealNumber& other) const
	{
		return RealNumber(number - other.number);
	}

	RealNumber& operator -= (const RealNumber& other)
	{
		number -= other.number;
		return *this;
	}

	RealNumber& operator -- ()
	{
		number--;
		return *this;
	}

	RealNumber operator--(int) // Postfix
	{
		RealNumber temp = *this; // Store original
		number--;
		return temp; // Return the original state
	}

	// Binary *

	template<Arithmetic T>
	RealNumber& operator *= (const T& other)
	{
		number *= static_cast<realNumberType>(other);
		return *this;
	}

	RealNumber operator * (const RealNumber& other) const
	{
		return RealNumber(number * other.number);
	}

	RealNumber& operator *= (const RealNumber& other)
	{
		number *= other.number;
		return *this;
	}

	// Binary /

	template<Arithmetic T>
	RealNumber& operator /= (const T& other)
	{
		number /= static_cast<realNumberType>(other);
		return *this;
	}

	RealNumber operator / (const RealNumber& other) const
	{
		return RealNumber(number / other.number);
	}

	RealNumber& operator /= (const RealNumber& other)
	{
		number /= other.number;
		return *this;
	}

	// Binary %

	realNumberType operator % (const RealNumber& other) const
	{
		return std::fmod(number, other.number);
	}

	template<Arithmetic T>
	realNumberType operator % (const T& other)
	{
		return std::fmod(number, static_cast<realNumberType>(other));
	}

	template<Arithmetic T>
	RealNumber& operator %= (const T& other)
	{
		number = std::fmod(number, static_cast<realNumberType>(other));
		return *this;
	}

	RealNumber& operator %= (const RealNumber& other)
	{
		number = std::fmod(number, other.number);
		return *this;
	}

	template<Arithmetic T>
	friend RealNumber operator+(const RealNumber& lhs, const T& rhs);

	template<Arithmetic T>
	friend RealNumber operator+(const T& lhs, const RealNumber& rhs);

	template<Arithmetic T>
	friend RealNumber operator-(const RealNumber& lhs, const T& rhs);

	template<Arithmetic T>
	friend RealNumber operator-(const T& lhs, const RealNumber& rhs);

	template<Arithmetic T>
	friend RealNumber operator*(const RealNumber& lhs, const T& rhs);

	template<Arithmetic T>
	friend RealNumber operator*(const T& lhs, const RealNumber& rhs);

	template<Arithmetic T>
	friend RealNumber operator/(const RealNumber& lhs, const T& rhs);

	template<Arithmetic T>
	friend RealNumber operator/(const T& lhs, const RealNumber& rhs);

	std::string toString() const;
	realNumberType getValue() const;
	realNumberType getIntegerPart() const;
	realNumberType getDecimalPart() const;
};

// Allow templated operator overloads as friends
template<Arithmetic T>
RealNumber operator+(const RealNumber& lhs, const T& rhs)
{
	return RealNumber(lhs.number + static_cast<realNumberType>(rhs));
}

template<Arithmetic T>
RealNumber operator+(const T& lhs, const RealNumber& rhs)
{
	return RealNumber(static_cast<realNumberType>(lhs) + rhs.number);
}

template<Arithmetic T>
RealNumber operator-(const RealNumber& lhs, const T& rhs)
{
	return RealNumber(lhs.number - static_cast<realNumberType>(rhs));
}

template<Arithmetic T>
RealNumber operator-(const T& lhs, const RealNumber& rhs)
{
	return RealNumber(static_cast<realNumberType>(lhs) - rhs.number);
}

template<Arithmetic T>
RealNumber operator*(const RealNumber& lhs, const T& rhs)
{
	return RealNumber(lhs.number * static_cast<realNumberType>(rhs));
}

template<Arithmetic T>
RealNumber operator*(const T& lhs, const RealNumber& rhs)
{
	return RealNumber(static_cast<realNumberType>(lhs) * rhs.number);
}

template<Arithmetic T>
RealNumber operator/(const RealNumber& lhs, const T& rhs)
{
	return RealNumber(lhs.number / static_cast<realNumberType>(rhs));
}

template<Arithmetic T>
RealNumber operator/(const T& lhs, const RealNumber& rhs)
{
	return RealNumber(static_cast<realNumberType>(lhs) / rhs.number);
}

} /* namespace */

#endif /* SRC_CONSOLELIB_REALNUMBER_H_ */
