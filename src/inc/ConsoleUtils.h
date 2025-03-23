//============================================================================
// Name        : ConsoleUtility
// Author      : Riyufuchi
// Created on  : Oct 27, 2021
// Last Edit   : Mar 21, 2025
//============================================================================

#ifndef _CONSOLE_UTILITY_H_
#define _CONSOLE_UTILITY_H_

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <format>

#include "IConsole.hpp"

/**
 * This class helps with console interactions
 */
namespace ConsoleLib
{
class ConsoleUtils
{
public:
	ConsoleUtils();
	~ConsoleUtils();
	static bool repeat();
	static bool yesNo(const char* text);
	static int getIntSafe();
	static int getIntSafe(int min, int max);
	template <typename T> static T getInput()
	{
		T x;
		while(true)
		{
			std::cin >> x;
			std::cin.get();
			if (!std::cin.fail())
				break;
			std::cerr << "Bad input.\n";
			std::cout << "Input again: ";
			std::cin.clear();
			std::cin.ignore(10,'\n');
		}
		return x;
	}
	static void header(std::string);
	static void header(std::string text, IConsole& console);
	[[deprecated("Redudant color attribute")]]
	static void header(std::string text, IConsole& console, Color textColor);
	static int basicMenu(int lenght, const char* menu[]);
	static int basicMenu(std::vector<const char*>& menu);
	static int basicMenu(std::vector<std::string>& menu, IConsole& console);
	static void createManual(std::string* args, int lenght);
	static std::string createTable(std::string* args, int lenght);
	static void listFilesInFolder(std::string workspacePath);
	static void printArgumentPairs(const std::map<std::string, std::vector<std::string>>& argPairs);
	static void printArgumentPairs(const std::vector<std::pair<std::string, std::vector<std::string>>>& argPairs);
	static bool argumentsContains(const std::vector<std::pair<std::string, std::vector<std::string>>>& argPairs, std::string value);
	static std::map<std::string, std::vector<std::string>> analyzeArguments(int argc, char** argv, bool& success, std::string& message);
	static std::vector<std::pair<std::string, std::vector<std::string>>> analyzeArgumentsInOrder(int argc, char** argv, bool& success, std::string& message);
};
}
#endif
