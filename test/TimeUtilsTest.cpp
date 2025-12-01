#include <gtest/gtest.h>
#include "../src/inc/TimeUtils.h"

using namespace consolelib;

TEST(TimeUtilsTest, ConvertMillis)
{
	TimeStamp ts = TimeUtils::convertMillis(3661000); // 1 hour, 1 minute, 1 second
	EXPECT_EQ(ts.hours, 1);
	EXPECT_EQ(ts.minutes, 1);
	EXPECT_EQ(ts.seconds, 1);
}

TEST(TimeUtilsTest, ConvertToMinutes)
{
	TimeStamp ts = {30, 45, 2}; // 2 hours, 45 minutes, 30 seconds
	EXPECT_EQ(TimeUtils::convertToMinutes(ts), 165); // (2 * 60) + 45
}

TEST(TimeUtilsTest, ConvertToHours)
{
	TimeStamp ts = {30, 45, 3}; // 3 hours, 45 minutes, 30 seconds
	EXPECT_EQ(TimeUtils::convertToHours(ts), 3); // Only full hours
}

TEST(TimeUtilsTest, TodaysDate)
{
	Date today = TimeUtils::todaysDate();
	EXPECT_GT(today.year, 2000); // Ensure it returns a reasonable year
	EXPECT_GE(today.month, 1);
	EXPECT_LE(today.month, 12);
	EXPECT_GE(today.day, 1);
	EXPECT_LE(today.day, 31);
}
