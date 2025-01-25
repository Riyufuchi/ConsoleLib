//==============================================================================
// File       : TimeUtils.cpp
// Author     : Riyufuchi
// Created on : Mar 26, 2024
// Last edit  : Jan 25, 2025
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleArt
//==============================================================================

#include "../inc/TimeUtils.h"

namespace ConsoleLib
{
TimeUtils::TimeUtils()
{
}
TimeUtils::~TimeUtils()
{
}
TimeStamp TimeUtils::convertMillis(long millis)
{
	TimeStamp tTime;
	tTime.seconds = millis / 1000;
	tTime.hours = tTime.seconds / 3600;
	tTime.minutes = tTime.seconds / 60 - (tTime.hours * 60);
	tTime.seconds = tTime.seconds % 60;
	return tTime;
}
long TimeUtils::convertToMinutes(TimeStamp& timeStamp)
{
	return timeStamp.minutes + (timeStamp.seconds / 60) + (timeStamp.hours * 60);
}
long TimeUtils::convertToHours(TimeStamp& timeStamp)
{
	return timeStamp.hours + (timeStamp.seconds / 3600) + (timeStamp.minutes / 60);
}
Date TimeUtils::todaysDate()
{
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); // Convert the time point to a time_t object
	std::tm* localTime = std::localtime(&currentTime); // Convert the time_t object to a struct tm object
	// Extract the year, month, and day from the struct tm object
	//today.year = localTime->tm_year + 1900; // tm_year is years since 1900
	//today.month = localTime->tm_mon + 1; // tm_mon is months since January (0-based)
	//today.day = localTime->tm_mday; // tm_mday is day of the month
	return Date{localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900};
}
} /* namespace ConsoleArt */
