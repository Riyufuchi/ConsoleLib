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
			// Skip if not a regular file (e.g., directory, symlink, device, etc.)
			if (!entry.is_regular_file())
				continue;

			std::ifstream infile(entry.path());
			if (infile)
			{
				scripts[entry.path().filename()] = std::string((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
			}
			else
			{
				std::cerr << "Error -> Cannot open script file: " << entry.path() << "\n";
			}
		}
	}
	catch (const std::filesystem::filesystem_error& e)
	{
			std::cerr << "Filesystem error: " << e.what() << "\n";
			return false;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected error: " << e.what() << "\n";
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

std::unordered_map<std::string, std::string>& ScriptMap::getScriptMap()
{
	return scripts;
}

} // Namespace
