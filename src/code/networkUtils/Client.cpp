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
#if defined(__linux__) || defined(__APPLE__)
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
#elif defined(_WIN32)

	Client::Client() : Client("127.0.0.1", 6969) {}

	Client::Client(const char* serverName, uint16_t port) {
		this->serverName = serverName;
		this->status = "OK";

		// Initialize Winsock
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			this->status = "Error: WSAStartup failed\n";
			return;
		}

		this->clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (this->clientSocket == INVALID_SOCKET) {
			this->status = "Error: Failed to create socket\n";
			WSACleanup();
			return;
		}

		// Convert serverName to wide string
		wchar_t wideServerName[256]; // Adjust the size as needed
		if (MultiByteToWideChar(CP_UTF8, 0, serverName, -1, wideServerName, sizeof(wideServerName)) == 0)
		{
			this->status = "Error: Failed to convert server name to wide string\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return;
		}

		serverAddr.sin_family = AF_INET;
		if (InetPton(AF_INET, wideServerName, &serverAddr.sin_addr) != 1) {
			this->status = "Error: Invalid address\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return;
		}
		serverAddr.sin_port = htons(port); // Server port

		if (connect(this->clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
			this->status = "Error: Connection failed\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return;
		}
	}

	Client::~Client() {
		closesocket(this->clientSocket);
		WSACleanup();
	}

	std::string Client::getClientStatus() {
		return this->status;
	}

	bool Client::isConnected() {
		return this->status == "OK";
	}

	bool Client::sendRequest(std::string& message) {
		int bytesSent = send(this->clientSocket, message.c_str(), message.length(), 0);
		if (bytesSent == SOCKET_ERROR) {
			this->status = "Error: Send failed\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return false;
		}
		return true;
	}

	bool Client::listenForResponse(std::string& response) {
		int bytesRead = recv(this->clientSocket, this->buffer, sizeof(this->buffer), 0);
		if (bytesRead == SOCKET_ERROR) {
			response = "Error: Receive failed\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return false;
		}
		else if (bytesRead == 0) {
			response = "Server closed connection\n";
			closesocket(this->clientSocket);
			WSACleanup();
			return false;
		}
		this->buffer[bytesRead] = '\0';
		response = std::string(this->buffer);
		return true;
	}
#endif
}
