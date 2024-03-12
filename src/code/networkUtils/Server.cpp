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
	Server::Server() : Server(12345)
	{}
	Server::Server(uint16_t port)
	{
		this->keepRunnig = true;
		this->serverStatus = "OK";
		this->port = port;
		this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (serverSocket == -1)
		{
			this->serverStatus = "Error: Failed to create socket\n";
			this->keepRunnig = false;
		}
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		serverAddr.sin_port = htons(port); // Port number

		if (bind(serverSocket, (sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
		{
			this->serverStatus = "Error: Bind failed\n";
			close(serverSocket);
			this->keepRunnig = false;
		}
		if (listen(serverSocket, 5) == -1)
		{
			this->serverStatus = "Error: Listen failed\n";
			close(serverSocket);
			this->keepRunnig = false;
		}

		/*
		if (listen(serverSocket, 5) == -1)
		{
			this->serverStatus = "Error: Listen failed\n";
			close(serverSocket);
			this->keepRunnig = false;
		}*/

		this->clientAddrLen = sizeof(clientAddr);
		this->clientSocket = 0;
	}
	Server::~Server()
	{
		close(serverSocket);
	}
	uint16_t Server::getPort()
	{
		return port;
	}
	std::string Server::getServerStatus()
	{
		return serverStatus;
	}
	bool Server::isRunning()
	{
		return serverStatus == "OK";
	}
	void Server::runServer(std::string& message)
	{
		while (keepRunnig)
		{
			clientSocket = accept(serverSocket, (sockaddr*) &clientAddr,&clientAddrLen);
			if (clientSocket == -1)
			{
				this->serverStatus = "Error: Accept failed\n";
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
				serverStatus = "Error: Receive failed ";
				serverStatus += strerror(errno);
				serverStatus += "\n";
				break;
			}
			else if (bytesRead == 0)
			{
				this->serverStatus = "Client disconnected\n";
				break;
			}

			buffer[bytesRead] = '\0';
			std::cout << "Received: " << buffer << std::endl;

			if (strcmp(buffer, "logout") == 0)
			{
				this->serverStatus = "Client logged out\n";
				keepRunnig = false;
				break;
			}

			// Echo back to client
			modifiedMessage = std::string(buffer).append(" [Echo from server]");
			modifiedMessageLength = modifiedMessage.length();
			if (send(clientSocket, modifiedMessage.c_str(), modifiedMessageLength, 0) == -1)
			{
				this->serverStatus = "Error: Send failed\n";
				break;
			}
		}
		close(clientSocket);
	}
}
