//==============================================================================
// File       : UnixClient.cpp
// Author     : Riyufuchi
// Created on : Mar 12, 2024
// Last edit  : Mar 20, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: ConsoleLib
//==============================================================================

#include "../../inc/UnixClient.h"

namespace SufuServer
{
	UnixClient::UnixClient() : UnixClient("127.0.0.1", 6969)
	{}
	UnixClient::UnixClient(const char* serverName, uint16_t port)
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

		// Set timeout for connect
		struct timeval timeout;
		timeout.tv_sec = 30; // Timeout in seconds
		timeout.tv_usec = 0;
		if (setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0)
		{
			std::cout << "30 sec";
			status = "Error: Failed to set socket option\n";
			close(clientSocket);
		}

		if (connect(clientSocket, (sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
		{
			status = "Error: Connection failed\n";
			close(clientSocket);
		}

		this->bytesSent = 0;
	}
	UnixClient::~UnixClient()
	{
		close(clientSocket);
	}
	bool UnixClient::sendRequest(std::string& message)
	{
	bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
	if (bytesSent == -1)
	{
		if (errno == EPIPE)
		{
			status = "Connection closed by server\n";
		}
		else
		{
			status = "Error: Send failed\n";
		}
		return false;
	}
	return true;
	}
	bool UnixClient::listenForResponse(std::string& response)
	{
		ssize_t bytesRead = recv(this->clientSocket, this->buffer, sizeof(this->buffer), 0);
		if (bytesRead == -1)
		{
			status = response = "Error: Receive failed - " + std::string(strerror(errno)) + "\n";
			return false;
		}
		else if (bytesRead == 0) // Server closed connection
		{
			status = response = "Server closed connection\n";
			return false;
		}
		else // Data received
		{
			this->buffer[bytesRead] = '\0';
			response = std::string(this->buffer);
			return true;
		}
	}
	bool UnixClient::listenForResponse(std::string& response, int timeout_ms)
	{
		fd_set readfds;
		FD_ZERO(&readfds);
		FD_SET(this->clientSocket, &readfds);

		// Initialize timeval struct for timeout
		struct timeval tv;
		tv.tv_sec = timeout_ms / 1000;
		tv.tv_usec = (timeout_ms % 1000) * 1000;

		// Use select to wait for data on socket
		int result = select(this->clientSocket + 1, &readfds, NULL, NULL, &tv);
		if (result == -1)
		{
			status = response = "Error: Select failed - " + std::string(strerror(errno)) + "\n";
			return false;
		}
		else if (result == 0) // Timeout occurred
		{
			status = response = "Error: Receive timed out\n";
			return false;
		}
		else // Data is available on socket
		{
			ssize_t bytesRead = recv(this->clientSocket, this->buffer, sizeof(this->buffer), 0);
			if (bytesRead == -1)
			{
				status = response = "Error: Receive failed - " + std::string(strerror(errno)) + "\n";
				return false;
			}
			else if (bytesRead == 0) // Server closed connection
			{

				status = response = "Server closed connection\n";
				return false;
			}
			else // Data received
			{
				this->buffer[bytesRead] = '\0';
				response = std::string(this->buffer);
				return true;
			}
		}
	}
}
