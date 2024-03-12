//==============================================================================
// File       : Server.h
// Author     : riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 11, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple client
//==============================================================================

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

namespace SufuServer
{
class Client
{
private:
	sockaddr_in serverAddr;
	ssize_t bytesSent;
	int clientSocket = 0;
	char buffer[1024];
	const char* serverName;
	std::string status;
public:
	Client();
	Client(const char* serverName, uint16_t port);
	~Client();
	std::string getClientStatus();
	bool isConnected();
	bool sendRequest(std::string& message);
	bool listenForResponse(std::string& message);
};
}
#endif /* _SERVER_H_ */
