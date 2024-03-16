//==============================================================================
// File       : Server.h
// Author     : riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 16, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple client
//==============================================================================

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <string>
#include <cstring>

#if defined(__linux__) || defined(__APPLE__)
	#include <unistd.h>
	#include <arpa/inet.h>
#elif defined(_WIN32)
	#include <winsock2.h>
	#include <windows.h>
	#include <Ws2tcpip.h>
	#pragma comment(lib, "Ws2_32.lib") // Link against Ws2_32.lib library
#endif

namespace SufuServer
{
class Client
{
private:
#if defined(__linux__) || defined(__APPLE__)
	ssize_t bytesSent;
	int clientSocket = 0;
#elif defined(_WIN32)
	SOCKET clientSocket = INVALID_SOCKET;
#endif
	sockaddr_in serverAddr;
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
	bool listenForResponse(std::string& message, int timeout_ms);
};
}
#endif /* _SERVER_H_ */
