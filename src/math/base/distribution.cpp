//==============================================================================
// File       : Distribution.cpp
// Author     : riyufuchi
// Created on : Nov 01, 2024
// Last edit  : Dec 22, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: consoleart
//==============================================================================

#include "../../consolelib/math/base/distribution.h"

namespace consolelib
{
Distribution::Distribution() : resultHolder(0)
{}
u_bigInt Distribution::factorial(int number)
{
	resultHolder = 1;
	for (int i = 2; i <= number; i++)
		resultHolder *= i;
	return resultHolder;
}
bigDouble Distribution::power(bigDouble number, int power)
{
	resultHolder = 1.0L;
	for (int i = 0; i < power; i++)
		resultHolder = number * resultHolder;
	return resultHolder;
}
}
