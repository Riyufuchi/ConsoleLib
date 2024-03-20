//==============================================================================
// File       : UnixClient.h
// Author     : riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 20, 2024
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: ConsoleLib
//==============================================================================

#if defined(__linux__) || defined(__APPLE__)

#ifndef _UNIX_CLIENT_H_
#define _UNIX_CLIENT_H_

#include <iostream>
#include <string>
#include <cstring>

#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Client.h"


namespace SufuServer
{
class UnixClient : public Client
{
private:
	const char* serverName;
	ssize_t bytesSent;
	int clientSocket = 0;
	sockaddr_in serverAddr;
	char buffer[1024];
public:
	UnixClient();
	UnixClient(const char* serverName, uint16_t port);
	~UnixClient();
	bool sendRequest(std::string& message) override;
	bool listenForResponse(std::string& message) override;
	bool listenForResponse(std::string& message, int timeout_ms) override;
};
}
#endif /* _SERVER_H_ */
#endif
