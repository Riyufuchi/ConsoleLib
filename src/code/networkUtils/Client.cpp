//==============================================================================
// File       : Client.cpp
// Author     : Riyufuchi
// Created on : Mar 12, 2024
// Last edit  : Mar 20, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../../inc/Client.h"

namespace SufuServer
{
	std::string Client::getClientStatus() const
	{
		return status;
	}
	bool Client::isConnected() const
	{
		return status == "OK";
	}
}
