#include <gtest/gtest.h>
#include "../src/inc/RealNumber.h"
#include <string>

using namespace ConsoleLib;

TEST(RealNumberTest, BasicAssignment)
{
	RealNumber x = 5.5;
	EXPECT_EQ(x.getValue(), 5.5);
}

TEST(RealNumberTest, BasicAssignment_Operator)
{
	RealNumber x = 5.5;
	EXPECT_EQ(x, 5.5);
}

TEST(RealNumberTest, Operator_plusPlus_post)
{
	RealNumber x = 5.5;
	x++;
	EXPECT_EQ(x, 6.5);
}

TEST(RealNumberTest, Operator_plusPlus_pre)
{
	RealNumber x = 5.5;
	EXPECT_EQ(++x, 6.5);
}

TEST(RealNumberTest, Operator_minusMinus_post)
{
	RealNumber x = 5.5;
	x--;
	EXPECT_EQ(x, 4.5);
}

TEST(RealNumberTest, Operator_minusMinus_pre)
{
	RealNumber x = 5.5;
	EXPECT_EQ(--x, 4.5);
}

TEST(RealNumberTest, Operator_string)
{
	RealNumber x = 5.0125;
	std::string strX = std::string(x);
	EXPECT_EQ(strX, "5.0125");
}

TEST(RealNumberTest, Operator_string2)
{
	RealNumber x = 5.05;
	EXPECT_EQ(std::string(x), "5.05");
}

// /

TEST(RealNumberTest, Operator_division)
{
	RealNumber x = 25;
	x /= 5;
	EXPECT_EQ(x, 5);
	x /= RealNumber(5);
	EXPECT_EQ(x, 1);
}

// *

TEST(RealNumberTest, Operator_multiplication)
{
	RealNumber x = 1;
	x *= 5;
	EXPECT_EQ(x, 5);
	x *= RealNumber(5);
	EXPECT_EQ(x, 25);
}

TEST(RealNumberTest, Operator_modulo)
{
	RealNumber x = 30;
	EXPECT_EQ(x % 5, 0);
	EXPECT_EQ(x % RealNumber(4), 2);
}

TEST(RealNumberTest, Operator_unary_plus)
{
	RealNumber x = -25.5;
	EXPECT_EQ(+x, 25.5);
}

TEST(RealNumberTest, Operator_unary_minus)
{
	RealNumber x = -25.5;
	EXPECT_EQ(x = -x, 25.5);
	EXPECT_EQ(-x, -25.5);
}

TEST(RealNumberTest, Operator_binary_plus)
{
	RealNumber x = 25.5;
	x = x + 5;
	EXPECT_EQ(x, 30.5);
	x = 0.5 + x;
	EXPECT_EQ(x, 31);
}

TEST(RealNumberTest, Operator_binary_minus)
{
	RealNumber x = 25.5;
	x = x - 5;
	EXPECT_EQ(x, 20.5);
	x = 0.5 - x;
	EXPECT_EQ(x, -20);
}

TEST(RealNumberTest, IntegerPart)
{
	RealNumber x = 25.5;
	EXPECT_EQ(x.getIntegerPart(), 25);
	EXPECT_EQ(x.getDecimalPart(), 0.5);
	x = -x;
	EXPECT_EQ(x.getIntegerPart(), -25);
	EXPECT_EQ(x.getDecimalPart(), -0.5);
}

