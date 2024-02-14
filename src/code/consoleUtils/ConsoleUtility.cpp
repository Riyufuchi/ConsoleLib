//============================================================================
// Name        : ConsoleUtility
// Author      : Riyufuchi
// Created on  : 27.10.2021
// Last Edit   : 14.12.2024
//============================================================================

#include "../../inc/ConsoleUtility.h"
namespace ConsoleUtils
{
ConsoleUtility::ConsoleUtility()
{
}

bool ConsoleUtility::yesNo(const char* text)
{
	std::string choice;
	std::cout << text;
	getline(std::cin, choice);
	//std::cin.ignore(); //clears buffer
	return (choice == "y" || choice == "Y" || choice == "");
}

bool ConsoleUtility::repeat()
{
	return yesNo("Again? [Y/n] ");
}

int ConsoleUtility::getIntSafe()
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

int ConsoleUtility::getIntSafe(int min, int max)
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

void ConsoleUtility::header(std::string text)
{
	std::string line = "";
	int lenght = static_cast<int>(text.size());
	for(int i = 0; i < lenght; i++)
	{
		line += "-";
	}
	std::cout << line << "\n" << text << "\n" << line << std::endl;
}

void ConsoleUtility::header(std::string text, IConsole& console, Color textColor)
{
	std::string line = std::string(static_cast<int>(text.size()), '-').append("\n");
	console.setTextColor(textColor);
	console.out(line + text + "\n" + line);
	console.resetTextColor();
}

int ConsoleUtility::basicMenu(int lenght, const char* menu[])
{
	for(int i = 0; i < lenght; i++)
	{
		printf("%d. %s \n", i + 1, menu[i]);
	}
	int result = getIntSafe(1, lenght) - 1;
	return result;
}

void ConsoleUtility::listFilesInFolder(std::string workspacePath)
{
	std::cout << "\n";
	if (workspacePath == "")
		workspacePath = std::filesystem::current_path();
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
void ConsoleUtility::createManual(std::string* args, int lenght)
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
	std::string line(lineLenght + columnWidth, '-');
	std::cout << line << "\n";
	for (int y = 0; y < lenght; y++)
	{
		x = 0;
		while (args[y][x] != '|')
			std::cout << args[y][x++];
		std::cout << std::string(columnWidth - x, ' ');
		if (args[y][x] == '|')
			x++;
		std::cout << " |";
		lineLenght = args[y].length();
		for (; x < lineLenght; x++)
			std::cout << args[y][x];
		std::cout << "\n";
	}
	std::cout << line << "\n";
}
ConsoleUtility::~ConsoleUtility()
{
}
} // Namespace
