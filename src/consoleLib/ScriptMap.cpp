//==============================================================================
// File       : ScriptMap.cpp
// Author     : riyufuchi
// Created on : Mar 28, 2025
// Last edit  : Mar 28, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../inc/ScriptMap.h"

namespace ConsoleLib
{

ScriptMap::ScriptMap()
{
}

ScriptMap::~ScriptMap()
{
}

bool ScriptMap::loadScripts(std::string path)
{
	if (path == "")
		path = std::filesystem::current_path().generic_string();
	try
	{
		for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(path))
		{
			std::ifstream infile(entry.path());
			if (infile)
			{
				scripts[entry.path().filename()] = std::string((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
			}
			else
			{
				std::cerr << "Error: Cannot open script file: " << entry << "\n";
			}
		}
	}
	catch (std::runtime_error& e)
	{
		std::cerr << "Error: Cannot load script files: " << e.what() << "\n";
		return false;
	}
	return true;
}

std::string ScriptMap::getScript(const std::string& scriptname) const
{
	if (scripts.contains(scriptname))
		return scripts.find(scriptname)->second;
	return "";
}

} // Namespace
