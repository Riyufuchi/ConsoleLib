//============================================================================
// Name        : ConsoleUtility
// Author      : Riyufuchi
// Created on  : Oct 27, 2021
// Last Edit   : Dec 16, 2025
//============================================================================

#include "../inc/ConsoleUtils.h"

namespace consolelib
{
ConsoleUtils::ConsoleUtils()
{
}
ConsoleUtils::~ConsoleUtils()
{
}
bool ConsoleUtils::waitForEnter()
{
	std::string choice;
	getline(std::cin, choice);
	//std::cin.ignore(); //clears buffer
	return (choice == "" || choice == "y" || choice == "Y");
}
bool ConsoleUtils::yesNo(const char* text)
{
	std::cout << text;
	return waitForEnter();
}

bool ConsoleUtils::repeat()
{
	return yesNo("Again? [Y/n] ");
}

int ConsoleUtils::getIntSafe()
{
	int x = 0;
	while (true)
	{
		if (std::cin >> x)
			break;
		if (std::cin.eof()) // If no input available (e.g. started by double-click)
		{
			std::cerr << "No input available. Exiting safely.\n";
			throw new std::exception();
		}
		std::cerr << "Bad input, enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	// Clean leftover characters after the integer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return x;
}

int ConsoleUtils::getIntSafe(int min, int max)
{
	int x;

	do
	{
		std::cout << "Enter a number in range " << min << " - " << max << ": ";
		x = getIntSafe();
	} while (not(x >= min && x <= max));

	return x;
}

std::optional<int> ConsoleUtils::obtainInt()
{
	int x;
	std::cin >> x;

	if (!std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return x;
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return std::nullopt;
}


std::optional<int> ConsoleUtils::obtainInt(int min, int max)
{
	std::optional<int>  x;

	do
	{
		x = obtainInt();
	} while (x and not(x >= min && x <= max));

	return x;
}

void ConsoleUtils::header(const std::string& text)
{
	std::string line = "";
	int lenght = static_cast<int>(text.size());
	for(int i = 0; i < lenght; i++)
	{
		line += "-";
	}
	std::cout << line << "\n" << text << "\n" << line << std::endl;
}

void ConsoleUtils::header(const std::string& text, IConsole& console)
{
	std::string line = std::string(static_cast<int>(text.size()), '-').append("\n");
	console.out(line + text + "\n" + line);
}

void ConsoleUtils::header(const std::string& text, IConsole& console, const Color& textColor)
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

void ConsoleUtils::listFilesInFolder(const std::string& workspacePath)
{
	std::cout << "\n";
	std::filesystem::directory_iterator iterator(std::filesystem::current_path().generic_string());
	if (!workspacePath.empty())
		iterator = std::filesystem::directory_iterator(workspacePath);
	try
	{
		for (const auto& entry : iterator)
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

IConsole* ConsoleUtils::createPlatformConsole()
{
	#if defined(__linux__) || defined(__APPLE__)
		return new UnixConsole();
	#elif defined(_WIN32)
		return new WindowsConsole();
	#else
		return new DefaultConsole();
	#endif
}

} // Namespace
