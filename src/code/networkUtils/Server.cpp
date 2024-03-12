//==============================================================================
// File       : Server.cpp
// Author     : riyufuchi
// Created on : Mar 12, 2024
// Last edit  : Mar 12, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple server
//==============================================================================

#include "../../inc/Server.h"

namespace SufuServer
{
	Server::Server()
	{
		this->keepRunnig = true;
		this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (serverSocket == -1)
		{
			std::cerr << "Error: Failed to create socket\n";
			this->keepRunnig = false;
		}
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		serverAddr.sin_port = htons(12345); // Port number

		if (bind(serverSocket, (sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
		{
			std::cerr << "Error: Bind failed\n";
			close(serverSocket);
			this->keepRunnig = false;
		}

		if (listen(serverSocket, 5) == -1)
		{
			std::cerr << "Error: Listen failed\n";
			close(serverSocket);
			this->keepRunnig = false;
		}

		this->clientAddrLen = sizeof(clientAddr);
		this->clientSocket = 0;
	}
	Server::~Server()
	{
		close(serverSocket);
	}
	void Server::runServer(std::string& message)
	{
		while (keepRunnig)
		{
			clientSocket = accept(serverSocket, (sockaddr*) &clientAddr,&clientAddrLen);
			if (clientSocket == -1)
			{
				std::cerr << "Error: Accept failed\n";
				continue; // Continue to accept other connections
			}
			handleRequest(message);
		}
	}
	void Server::handleRequest(std::string& message)
	{
		ssize_t bytesRead = 0;
		std::string modifiedMessage = "ECHO";
		size_t modifiedMessageLength = modifiedMessage.length();
		while (true)
		{
			bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
			if (bytesRead == -1)
			{
				std::cerr << "Error: Receive failed " << strerror(errno) << "\n";
				break;
			}
			else if (bytesRead == 0)
			{
				std::cout << "Client disconnected\n";
				break;
			}

			buffer[bytesRead] = '\0';
			std::cout << "Received: " << buffer << std::endl;

			if (strcmp(buffer, "logout") == 0)
			{
				std::cout << "Client logged out\n";
				keepRunnig = false;
				break;
			}

			// Echo back to client
			modifiedMessage = std::string(buffer).append(" [Echo from server]");
			modifiedMessageLength = modifiedMessage.length();
			if (send(clientSocket, modifiedMessage.c_str(), modifiedMessageLength, 0) == -1)
			{
				std::cerr << "Error: Send failed\n";
				break;
			}
		}
		close(clientSocket);
	}
}
