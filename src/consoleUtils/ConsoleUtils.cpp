﻿//============================================================================
// Name        : ConsoleUtility
// Author      : Riyufuchi
// Created on  : Oct 27, 2021
// Last Edit   : Mar 23, 2025
//============================================================================

#include "../inc/ConsoleUtils.h"
namespace ConsoleLib
{
ConsoleUtils::ConsoleUtils()
{
}
ConsoleUtils::~ConsoleUtils()
{
}
bool ConsoleUtils::yesNo(const char* text)
{
	std::string choice;
	std::cout << text;
	getline(std::cin, choice);
	//std::cin.ignore(); //clears buffer
	return (choice == "y" || choice == "Y" || choice == "");
}

bool ConsoleUtils::repeat()
{
	return yesNo("Again? [Y/n] ");
}

int ConsoleUtils::getIntSafe()
{
	int x = 0;
	while(true)
	{
		std::cin >> x;
		std::cin.get();
		if (!std::cin.fail())
			break;
		std::cerr << "Bad input, enter a number: ";
		std::cin.clear();
		std::cin.ignore(10,'\n');
	}
	return x;
}

int ConsoleUtils::getIntSafe(int min, int max)
{
	int x = 0;
	while(true)
	{
		x = getIntSafe();
		if(x >= min && x <= max)
			return x;
		else
			std::cout << "Enter a number in range " << min << " - " << max << ": ";
	}
}

void ConsoleUtils::header(std::string text)
{
	std::string line = "";
	int lenght = static_cast<int>(text.size());
	for(int i = 0; i < lenght; i++)
	{
		line += "-";
	}
	std::cout << line << "\n" << text << "\n" << line << std::endl;
}

void ConsoleUtils::header(std::string text, IConsole& console)
{
	std::string line = std::string(static_cast<int>(text.size()), '-').append("\n");
	console.out(line + text + "\n" + line);
}

void ConsoleUtils::header(std::string text, IConsole& console, Color textColor)
{
	std::string line = std::string(static_cast<int>(text.size()), '-').append("\n");
	console.enableCustomFG(textColor);
	console.out(line + text + "\n" + line);
	console.disableCustomFG();
}

int ConsoleUtils::basicMenu(int lenght, const char* menu[])
{
	for(int i = 0; i < lenght; i++)
	{
		printf("%d. %s \n", i + 1, menu[i]);
	}
	return getIntSafe(1, lenght) - 1;
}

int ConsoleUtils::basicMenu(std::vector<const char*>& menu)
{
	const int LENGHT = menu.size();
	for(int i = 0; i < LENGHT; i++)
	{
		printf("%d. %s \n", i + 1, menu[i]);
	}
	return getIntSafe(1, LENGHT) - 1;
}

int ConsoleUtils::basicMenu(std::vector<std::string>& menu, IConsole& console)
{
	int index = 1;
	for (const std::string& text : menu)
	{
		console.out(std::format("{}. {}\n", index, text));
		index++;
	}
	return getIntSafe(1, index - 1) - 1;
}

void ConsoleUtils::listFilesInFolder(std::string workspacePath)
{
	std::cout << "\n";
	if (workspacePath == "")
		workspacePath = std::filesystem::current_path().generic_string();
	try
	{
		for (const auto& entry : std::filesystem::directory_iterator(workspacePath))
		{
			std::cout << entry.path().filename() << "\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n";
}
//args[x] = "arg| action";
void ConsoleUtils::createManual(std::string* args, int lenght)
{
	int lineLenght = 1;
	int lineLengthTemp = 0;
	int columnWidth = 0;
	int x = 0;
	size_t pipeIndex = 0;
	for (int i = 0; i < lenght; i++)
	{
		lineLengthTemp = args[i].length();
		pipeIndex = args[i].find('|');
		if (pipeIndex == std::string::npos)
			pipeIndex = lineLengthTemp;
		if (lineLengthTemp > lineLenght)
			lineLenght = lineLengthTemp;
		if (pipeIndex > static_cast<size_t>(columnWidth))
			columnWidth = pipeIndex;
	}
	std::string line((lineLenght + columnWidth), '-');
	std::cout << line << "\n";
	std::cout << args[0].substr(0, x = args[0].find("|"));
	std::cout << std::string(columnWidth - x, ' ');
	std::cout << " |" << args[0].substr(++x) << "\n";
	std::cout << line << "\n";
	for (int y = 1; y < lenght; y++)
	{
		std::cout << args[y].substr(0, x = args[y].find("|"));
		std::cout << std::string(columnWidth - x, ' ');
		std::cout << " |" << args[y].substr(++x) << "\n";
	}
	std::cout << line << "\n";
}
std::string ConsoleUtils::createTable(std::string* args, int lenght)
{
	std::stringstream tableStringStream;
	int lineLenght = 1;
	int lineLengthTemp = 0;
	int columnWidth = 0;
	int x = 0;
	size_t pipeIndex = 0;
	for (int i = 0; i < lenght; i++)
	{
		lineLengthTemp = args[i].length();
		pipeIndex = args[i].find('|');
		if (pipeIndex == std::string::npos)
			pipeIndex = lineLengthTemp;
		if (lineLengthTemp > lineLenght)
			lineLenght = lineLengthTemp;
		if (pipeIndex > static_cast<size_t>(columnWidth))
			columnWidth = pipeIndex;
	}
	std::string line((lineLenght + columnWidth), '-');
	tableStringStream << line << "\n";
	tableStringStream << args[0].substr(0, x = args[0].find("|"));
	tableStringStream << std::string(columnWidth - x, ' ');
	tableStringStream << " |" << args[0].substr(++x) << "\n";
	tableStringStream << line << "\n";
	for (int y = 1; y < lenght; y++)
	{
		tableStringStream << args[y].substr(0, x = args[y].find("|"));
		tableStringStream << std::string(columnWidth - x, ' ');
		tableStringStream << " |" << args[y].substr(++x) << "\n";
	}
	tableStringStream << line << "\n";
	return tableStringStream.str();
}
void ConsoleUtils::printArgumentPairs(const std::map<std::string, std::vector<std::string>>& argPairs)
{
	for (const auto& [key, values] : argPairs)
	{
		std::cout << key << ": [";
		for (size_t i = 0; i < values.size(); ++i)
		{
			std::cout << values[i];
			if (i < values.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}
void ConsoleUtils::printArgumentPairs(const std::vector<std::pair<std::string, std::vector<std::string>>>& argPairs)
{
	for (const std::pair<std::string, std::vector<std::string>>& argument : argPairs)
	{
		std::cout << argument.first << ": [";
		for (size_t i = 0; i < argument.second.size(); ++i)
		{
			std::cout << argument.second[i];
			if (i < argument.second.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}
bool ConsoleUtils::argumentsContains(const std::vector<std::pair<std::string, std::vector<std::string>>>& argPairs, std::string value)
{
	for (const std::pair<std::string, std::vector<std::string>>& argument : argPairs)
	{
		if (argument.first == value)
			return true;
	}
	return false;
}
bool ConsoleUtils::argumentsRemove(std::vector<std::pair<std::string, std::vector<std::string>>>& argPairs, std::string value)
{
	int id = 0;
	for (std::pair<std::string, std::vector<std::string>>& argument : argPairs)
	{
		if (argument.first == value)
			break;
		id++;
	}
	argPairs.erase(argPairs.begin() + id);
	return true;
}
std::map<std::string, std::vector<std::string>> ConsoleUtils::analyzeArguments(int argc, char** argv, bool& success, std::string& message)
{
	std::map<std::string, std::vector<std::string>> arguments;
	success = true;
	message.clear();

	if (argc < 2)
	{
		success = true;
		message = "No arguments provided.";
		return arguments;
	}

	std::string currentArg = argv[1];
	if (!(currentArg.starts_with("--") || currentArg.starts_with("-"))) // Check if first argument is't just an argument
	{
		success = false;
		message = "Value without option: " + currentArg;
		return arguments;
	}

	std::string currentArgV;

	for (int i = 1; i < argc; ++i)
	{
		currentArg = argv[i];
		if (currentArg.starts_with("--") || currentArg.starts_with("-"))
		{
			if (arguments.find(currentArg) != arguments.end()) // Check for duplicate options
			{
				success = false;
				message = "Duplicate option detected: " + currentArg;
				return arguments;
			}
			arguments[currentArg] = std::vector<std::string> {}; // Add a new option with an empty vector for its values
			currentArgV = currentArg;
		}
		else
		{
			arguments[currentArgV].push_back(currentArg); // Add value to the most recent option
		}
	}
	message = "Argument parsing was successful.";
	return arguments;
}

std::vector<std::pair<std::string, std::vector<std::string>>> ConsoleUtils::analyzeArgumentsInOrder(int argc, char **argv, bool &success, std::string &message)
{
	std::vector<std::pair<std::string, std::vector<std::string>>> arguments;
	success = true;
	message.clear();

	if (argc < 2)
	{
		success = true;
		message = "No arguments provided.";
		return arguments;
	}

	std::string currentArg = argv[1];
	if (!(currentArg.starts_with("--") || currentArg.starts_with("-"))) // Check if first argument is't just an argument
	{
		success = false;
		message = "Value without option: " + currentArg;
		return arguments;
	}

	for (int i = 1; i < argc; ++i)
	{
		currentArg = argv[i];
		if (currentArg.starts_with("--") || currentArg.starts_with("-"))
		{
			arguments.push_back(std::pair<std::string, std::vector<std::string>>(currentArg, std::vector<std::string> {})); // Add a new option with an empty vector for its values
		}
		else
		{
			arguments.back().second.push_back(currentArg); // Add value to the most recent option
		}
	}
	message = "Argument parsing was successful.";
	return arguments;
}
} // Namespace
