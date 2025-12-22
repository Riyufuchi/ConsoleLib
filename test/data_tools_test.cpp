//==============================================================================
// File       : data_toolsTest.cpp
// Author     : riyufuchi
// Created on : Mar 10, 2025
// Last edit  : Dec 22, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include <gtest/gtest.h>
#include "../src/consolelib/tools/data_tools.h"

using namespace consolelib;

TEST(data_tools_test, IsNumber)
{
	EXPECT_TRUE(data_tools::isNumber("123"));
	EXPECT_TRUE(data_tools::isNumber("-123"));
	EXPECT_TRUE(data_tools::isNumber("000"));
	EXPECT_FALSE(data_tools::isNumber("123a"));
	EXPECT_FALSE(data_tools::isNumber("12.3"));
	EXPECT_FALSE(data_tools::isNumber("1-23"));
	EXPECT_FALSE(data_tools::isNumber(""));
	EXPECT_FALSE(data_tools::isNumber("-"));
}

TEST(data_tools_test, IsDouble)
{
	EXPECT_TRUE(data_tools::isDouble("12.3"));
	EXPECT_TRUE(data_tools::isDouble("-12.3"));
	EXPECT_TRUE(data_tools::isDouble("0.0"));
	EXPECT_FALSE(data_tools::isDouble("abc"));
	EXPECT_FALSE(data_tools::isDouble("12.3.4"));
	EXPECT_FALSE(data_tools::isDouble(""));
	EXPECT_FALSE(data_tools::isDouble("1-2.3"));
	EXPECT_FALSE(data_tools::isDouble("-"));
}

TEST(data_tools_test, BoolToString)
{
	EXPECT_EQ(data_tools::boolToString(true), "Yes");
	EXPECT_EQ(data_tools::boolToString(false), "No");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

