//==============================================================================
// File       : DataUtilsTest.cpp
// Author     : riyufuchi
// Created on : Mar 10, 2025
// Last edit  : Mar 10, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include <gtest/gtest.h>
#include "../src/inc/DataUtils.h"

using namespace consolelib;

TEST(DataUtilsTest, IsNumber)
{
	EXPECT_TRUE(DataUtils::isNumber("123"));
	EXPECT_TRUE(DataUtils::isNumber("-123"));
	EXPECT_TRUE(DataUtils::isNumber("000"));
	EXPECT_FALSE(DataUtils::isNumber("123a"));
	EXPECT_FALSE(DataUtils::isNumber("12.3"));
	EXPECT_FALSE(DataUtils::isNumber("1-23"));
	EXPECT_FALSE(DataUtils::isNumber(""));
	EXPECT_FALSE(DataUtils::isNumber("-"));
}

TEST(DataUtilsTest, IsDouble)
{
	EXPECT_TRUE(DataUtils::isDouble("12.3"));
	EXPECT_TRUE(DataUtils::isDouble("-12.3"));
	EXPECT_TRUE(DataUtils::isDouble("0.0"));
	EXPECT_FALSE(DataUtils::isDouble("abc"));
	EXPECT_FALSE(DataUtils::isDouble("12.3.4"));
	EXPECT_FALSE(DataUtils::isDouble(""));
	EXPECT_FALSE(DataUtils::isDouble("1-2.3"));
	EXPECT_FALSE(DataUtils::isDouble("-"));
}

TEST(DataUtilsTest, BoolToString)
{
	EXPECT_EQ(DataUtils::boolToString(true), "Yes");
	EXPECT_EQ(DataUtils::boolToString(false), "No");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

