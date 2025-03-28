//==============================================================================
// File       : ScriptMap.h
// Author     : riyufuchi
// Created on : Mar 28, 2025
// Last edit  : Mar 28, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: ConsoleLib
//==============================================================================

#ifndef SRC_INC_SCRIPTMAP_H_
#define SRC_INC_SCRIPTMAP_H_

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <filesystem>

namespace ConsoleLib
{
class ScriptMap : public std::unordered_map<std::string, std::string>
{
public:
	ScriptMap();
	virtual ~ScriptMap();
	bool loadScripts(std::string path = "");
};
}
#endif /* SRC_INC_SCRIPTMAP_H_ */
