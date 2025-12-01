//==============================================================================
// File       : PoissonsDistribution.cpp
// Author     : riyufuchi
// Created on : Nov 01, 2024
// Last edit  : Nov 20, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleArt
//==============================================================================

#include "../../inc/PoissonsDistribution.h"

namespace consolelib
{
PoissonsDistribution::PoissonsDistribution(int lambda) : Distribution(), λ(lambda)
{
}
PoissonsDistribution::~PoissonsDistribution()
{
}
bigDouble PoissonsDistribution::distribute(int k)
{
	return (pow(λ, k)*pow(M_E, -1*λ))/factorial(k);
}
bigDouble PoissonsDistribution::ex()
{
	return λ;
}
bigDouble PoissonsDistribution::varX()
{
	return λ;
}
} /* namespace Other */
