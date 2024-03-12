//==============================================================================
// File       : Client.cpp
// Author     : riyufuchi
// Created on : Mar 12, 2024
// Last edit  : Mar 12, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../../inc/Client.h"

namespace SufuServer
{
	Client::Client() : Client("127.0.0.1", 6969)
	{}
	Client::Client(const char* serverName, uint16_t port)
	{
		this->serverName = serverName;
		this->status = "OK";
		this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (clientSocket == -1)
		{
			status = "Error: Failed to create socket\n";
		}

		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr(serverName); // Server IP address
		serverAddr.sin_port = htons(port); // Server port

		if (connect(clientSocket, (sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
		{
			status = "Error: Connection failed\n";
			close(clientSocket);
		}

		this->bytesSent = 0;
	}
	Client::~Client()
	{
		close(clientSocket);
	}
	std::string Client::getClientStatus()
	{
		return status;
	}
	bool Client::isConnected()
	{
		return status == "OK";
	}
	bool Client::sendRequest(std::string& message)
	{
		bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
		if (bytesSent == -1)
		{
			status = "Error: Send failed\n";
			close(clientSocket);
			return false;
		}
		return true;
	}
	bool Client::listenForResponse(std::string& response)
	{
		ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytesRead == -1)
		{
			response = "Error: Receive failed\n";
			close(clientSocket);
			return false;
		}
		else if (bytesRead == 0)
		{
			response = "Server closed connection\n";
			close(clientSocket);
			return false;
		}
		buffer[bytesRead] = '\0';
		response = std::string(buffer);
		return true;
	}
}
