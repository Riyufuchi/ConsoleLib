//==============================================================================
// File       : ScriptMap.cpp
// Author     : riyufuchi
// Created on : Mar 28, 2025
// Last edit  : Dec 01, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consolelib
//==============================================================================

#include "../inc/ScriptMap.h"

namespace consolelib
{

ScriptMap::ScriptMap()
{
}

ScriptMap::~ScriptMap()
{
}

bool ScriptMap::loadScripts(const std::string& path)
{
	std::filesystem::directory_iterator iterator(std::filesystem::current_path().generic_string());
	if (!path.empty())
		iterator = std::filesystem::directory_iterator(path);
	try
	{
		for (const std::filesystem::directory_entry& entry : iterator)
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

const std::string& ScriptMap::getScript(const std::string& scriptname) const
{
	if (scripts.contains(scriptname))
		return scripts.find(scriptname)->second;
	return scriptname;
}

std::unordered_map<std::string, std::string>& ScriptMap::getScriptMap()
{
	return scripts;
}

} // Namespace
