//==============================================================================
// File       : data_toolsTest.cpp
// Author     : riyufuchi
// Created on : Mar 10, 2025
// Last edit  : Jan 13, 2026
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include <gtest/gtest.h>
#include "../src/consolelib/tools/data_tools.h"

using namespace consolelib;

TEST(data_tools_test, IsNumber)
{
	EXPECT_TRUE(data_tools::is_number("123"));
	EXPECT_TRUE(data_tools::is_number("-123"));
	EXPECT_TRUE(data_tools::is_number("000"));
	EXPECT_FALSE(data_tools::is_number("123a"));
	EXPECT_FALSE(data_tools::is_number("12.3"));
	EXPECT_FALSE(data_tools::is_number("1-23"));
	EXPECT_FALSE(data_tools::is_number(""));
	EXPECT_FALSE(data_tools::is_number("-"));
}

TEST(data_tools_test, IsDouble)
{
	EXPECT_TRUE(data_tools::is_double("12.3"));
	EXPECT_TRUE(data_tools::is_double("-12.3"));
	EXPECT_TRUE(data_tools::is_double("0.0"));
	EXPECT_FALSE(data_tools::is_double("abc"));
	EXPECT_FALSE(data_tools::is_double("12.3.4"));
	EXPECT_FALSE(data_tools::is_double(""));
	EXPECT_FALSE(data_tools::is_double("1-2.3"));
	EXPECT_FALSE(data_tools::is_double("-"));
}

TEST(data_tools_test, BoolToString)
{
	EXPECT_EQ(data_tools::bool_to_string(true), "Yes");
	EXPECT_EQ(data_tools::bool_to_string(false), "No");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

