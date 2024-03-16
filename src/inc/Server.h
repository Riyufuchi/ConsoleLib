//==============================================================================
// File       : Server.h
// Author     : riyufuchi
// Created on : Mar 11, 2024
// Last edit  : Mar 16, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple server
//==============================================================================

#ifndef _SERVER_H_
#define _SERVER_H_

#if defined(__linux__) || defined(__APPLE__)

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <thread> // for std::thread
#include <vector> // for std::vecto
#include <mutex>
#include <algorithm>

namespace SufuServer
{
class Server
{
private:
	const size_t MAX_CONNECTED_USERS = 4;
	int serverSocket;
	sockaddr_in serverAddr;
	sockaddr_in clientAddr;
	socklen_t clientAddrLen;
	bool keepRunning;
	std::string serverStatus, temporaryString;
	uint16_t port;

	struct User
	{
		std::string name;
		int userSocket;
		bool connected;
	};

	void handleUser(int clientSocket); // Function to handle communication with a single user
	bool sendResponse(int clientSocket, std::string message);
	std::vector<std::thread> clientThreads; // Vector to store client threads
	std::mutex clientThreadsMutex;
public:
	Server();
	Server(uint16_t port);
	~Server();
	void runServer();
	void shutdownServer();
	// Functions
	bool isRunning();
	uint16_t getPort();
	std::string getServerStatus();
};
}
#endif
#endif /* _SERVER_H_ */
