//==============================================================================
// File       : PoissonsDistribution.cpp
// Author     : riyufuchi
// Created on : Nov 01, 2024
// Last edit  : Dec 02, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleArt
//==============================================================================

#include "../../inc/PoissonsDistribution.h"

namespace consolelib
{
PoissonsDistribution::PoissonsDistribution(int lambda) : Distribution(), lambda(lambda)
{
}
PoissonsDistribution::~PoissonsDistribution()
{
}
bigDouble PoissonsDistribution::distribute(int k)
{
	return (pow(lambda, k)* std::exp(-lambda))/factorial(k);
}
bigDouble PoissonsDistribution::ex()
{
	return lambda;
}
bigDouble PoissonsDistribution::varX()
{
	return lambda;
}
} /* namespace Other */
