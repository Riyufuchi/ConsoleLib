//==============================================================================
// File       : Server.h
// Author     : riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 11, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple server
//==============================================================================

#ifndef _SERVER_H_
#define _SERVER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

namespace SufuServer
{
class Server
{
private:
	int serverSocket;
	sockaddr_in serverAddr;
	sockaddr_in clientAddr;
	socklen_t clientAddrLen;
	int clientSocket = 0;
	bool keepRunnig;
	char buffer[1024];
	std::string serverStatus;
	uint16_t port;
	void handleRequest(std::string& message);
public:
	Server();
	Server(uint16_t port);
	~Server();
	void runServer(std::string& message);
	// Functions
	bool isRunning();
	uint16_t getPort();
	std::string getServerStatus();
};
}
#endif /* _SERVER_H_ */
