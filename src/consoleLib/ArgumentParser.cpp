//==============================================================================
// File       : ArgumentParser.cpp
// Author     : riyufuchi
// Created on : Apr 6, 2025
// Last edit  : Apr 6, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/ArgumentParser.h"

namespace ConsoleLib
{

void ArgumentParser::printArgumentPairs(const argMap& argPairs)
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

void ArgumentParser::printArgumentPairs(const argVector& argPairs)
{
	for (const argVectorItem& argument : argPairs)
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

bool ArgumentParser::contains(const argVector& argPairs, const std::string& value)
{
	for (const argVectorItem& argument : argPairs)
	{
		if (argument.first == value)
			return true;
	}
	return false;
}

bool ArgumentParser::remove(argVector& argPairs, const std::string& value)
{
	int id = 0;
	for (argVectorItem& argument : argPairs)
	{
		if (argument.first == value)
			break;
		id++;
	}
	argPairs.erase(argPairs.begin() + id);
	return true;
}

argMap ArgumentParser::analyze(int argc, char** argv, bool& success, std::string& message)
{
	argMap arguments;
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

argVector ArgumentParser::analyzeInOrder(int argc, char** argv, bool& success, std::string& message)
{
	argVector arguments;
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
			arguments.push_back(argVectorItem(currentArg, std::vector<std::string> {})); // Add a new option with an empty vector for its values
		}
		else
		{
			arguments.back().second.push_back(currentArg); // Add value to the most recent option
		}
	}
	message = "Argument parsing was successful.";
	return arguments;
}

} /* namespace ConsoleLib */
