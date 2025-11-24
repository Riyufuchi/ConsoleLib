//==============================================================================
// File       : StatisticsGenericTest.cpp
// Author     : riyufuchi
// Created on : Nov 24, 2025
// Last edit  : Nov 24, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../src/inc/Statistic.h"

#include <gtest/gtest.h>

using namespace ConsoleLib;

const std::vector<double> testNums = {25000, 25000, 25000, 25000, 100000};

TEST(Statistic, Mean)
{
	Statistic<double> stat(testNums);
	EXPECT_EQ(stat.mean(), 40000.0);
}

TEST(Statistic, Median)
{
	Statistic<double> stat(testNums);
	EXPECT_EQ(stat.median(), 25000);
}

TEST(Statistic, Mode)
{
	Statistic<double> stat(testNums);
	std::vector<double> modeVector = stat.mode();
	EXPECT_EQ(modeVector[0], 25000);
}

TEST(Statistic, VarX)
{
	Statistic<double> stat(testNums);
	EXPECT_EQ(stat.variance(false), 900000000);
}

TEST(Statistic, StandartVarX)
{
	Statistic<double> stat(testNums);
	EXPECT_EQ(stat.stadardizeVarX(stat.variance(false)), 30000);
}
