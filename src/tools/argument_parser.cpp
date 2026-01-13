//==============================================================================
// File       : ArgumentParser.cpp
// Author     : riyufuchi
// Created on : Apr 06, 2025
// Last edit  : Jan 13, 2026
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include "../consolelib/tools/argument_parser.h"

namespace consolelib
{

void ArgumentParser::print_argument_pairs(const argMap& arg_pairs)
{
	for (const auto& [key, values] : arg_pairs)
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

void ArgumentParser::print_argument_pairs(const argVector& arg_pairs)
{
	for (const argVectorItem& argument : arg_pairs)
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

bool ArgumentParser::contains(const argVector& arg_pairs, const std::string& value)
{
	for (const argVectorItem& argument : arg_pairs)
	{
		if (argument.first == value)
			return true;
	}
	return false;
}

bool ArgumentParser::remove(argVector& arg_pairs, const std::string& value)
{
	int id = 0;
	for (argVectorItem& argument : arg_pairs)
	{
		if (argument.first == value)
		{
			arg_pairs.erase(arg_pairs.begin() + id);
			return true;
		}
		id++;
	}
	return false;
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

argVector ArgumentParser::analyze_in_order(int argc, char** argv, bool& success, std::string& message)
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

	arguments.reserve(argc);

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

} /* namespace consolelib */
