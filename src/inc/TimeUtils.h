//==============================================================================
// File       : TimeUtils.h
// Author     : Riyufuchi
// Created on : Mar 26, 2024
// Last edit  : Mar 26, 2024
// Copyright  : Copyright (c) 2024, Riyufuchi
// Description: ConsoleArt
//==============================================================================

#ifndef _OTHER_TIME_UTILS_H_
#define _OTHER_TIME_UTILS_H_

#include <chrono>
#include <ctime>

namespace DataUtility
{
struct TimeStamp
{
	long seconds {0};
	long minutes {0};
	long hours {0};
};
struct Date
{
	int day;
	int month;
	int year;
};
class TimeUtils
{
public:
	TimeUtils();
	~TimeUtils();
	static TimeStamp convertMillis(long millis);
	static long convertToMinutes(TimeStamp& timeStamp);
	static long convertToHours(TimeStamp& timeStamp);
	static Date todaysDate();
};
} /* namespace */
#endif /* _OTHER_TIME_UTILS_H_ */
