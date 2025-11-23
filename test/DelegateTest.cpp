//==============================================================================
// File       : DelegateTest.cpp
// Author     : riyufuchi
// Created on : Nov 23, 2025
// Last edit  : Nov 23, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include <gtest/gtest.h>
#include <cmath>
#include "../src/inc/Delegate.hpp"

using namespace ConsoleLib;

double root(double x)
{
	return std::sqrt(x);
}

double cosinus(double x)
{
	return std::cos(x);
}

TEST(Delegate, Basic)
{
	Delegate<double, double> deleg;
	deleg += &root;
	EXPECT_EQ(deleg(25), 5);
}

TEST(Delegate, Remove)
{
	Delegate<double, double> deleg;
	deleg += &root;
	deleg += &cosinus;
	deleg -= &cosinus;
	EXPECT_EQ(deleg(25), 5);
}

TEST(Delegate, InvokeLast)
{
	Delegate<double, double> deleg;
	deleg += &root;
	deleg += &cosinus;
	EXPECT_EQ(deleg(0), 1);
}

TEST(Delegate, InvokeList)
{
	Delegate<double, double> deleg;
	deleg += &root;
	deleg += &cosinus;
	std::vector<double> list = deleg.getInvocationList(0);
	EXPECT_EQ(list[0], 0);
	EXPECT_EQ(list[1], 1);
}

TEST(Delegate, Exception)
{
	Delegate<double, double> deleg;
	EXPECT_ANY_THROW(deleg(0));
}
