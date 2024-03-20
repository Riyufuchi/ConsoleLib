//==============================================================================
// File       : Client.h
// Author     : Riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 20, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple client
//==============================================================================

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <string>
#include <cstring>

namespace SufuServer
{
class Client
{
protected:
	std::string status;
public:
	Client() = default;
	virtual ~Client() = default;
	virtual std::string getClientStatus() const final;
	virtual bool isConnected() const final;
	virtual bool sendRequest(std::string& message) = 0;
	virtual bool listenForResponse(std::string& message) = 0;
	virtual bool listenForResponse(std::string& message, int timeout_ms) = 0;
};
}
#endif /* _SERVER_H_ */
