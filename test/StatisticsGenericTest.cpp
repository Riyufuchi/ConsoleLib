//==============================================================================
// File       : StatisticsGenericTest.cpp
// Author     : riyufuchi
// Created on : Nov 24, 2025
// Last edit  : Nov 24, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include <gtest/gtest.h>
#include "../src/inc/StatisticsGeneric.h"

using namespace ConsoleLib;

const std::vector<double> testNums = {25000, 25000, 25000, 25000, 100000};

TEST(StatisticsGeneric, Mean)
{
	StatisticsGeneric<double> stat(testNums);
	EXPECT_EQ(stat.mean(), 40000.0);
}

TEST(StatisticsGeneric, Median)
{
	StatisticsGeneric<double> stat(testNums);
	EXPECT_EQ(stat.median(), 25000);
}

TEST(StatisticsGeneric, Mode)
{
	StatisticsGeneric<double> stat(testNums);
	std::vector<double> modeVector = stat.mode();
	EXPECT_EQ(modeVector[0], 25000);
}

TEST(StatisticsGeneric, VarX)
{
	StatisticsGeneric<double> stat(testNums);
	EXPECT_EQ(stat.variance(false), 900000000);
}

TEST(StatisticsGeneric, StandartVarX)
{
	StatisticsGeneric<double> stat(testNums);
	EXPECT_EQ(stat.stadardizeVarX(stat.variance(false)), 30000);
}
