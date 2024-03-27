//==============================================================================
// File       : Server.cpp
// Author     : riyufuchi
// Created on : Mar 12, 2024
// Last edit  : Mar 27, 2024
// Copyright  : Copyright (c) Riyufuchi
// Description: Simple server
//==============================================================================

#include "../inc/Server.h"
#if defined(__linux__) || defined(__APPLE__)
namespace SufuServer
{
	Server::Server() : Server(12345)
	{}
	Server::Server(uint16_t port)
	{
		this->keepRunning = true;
		this->serverStatus = "OK";
		this->port = port;
		this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (serverSocket == -1)
		{
			this->serverStatus = "Error: Failed to create socket\n";
			this->keepRunning = false;
		}

		int opt = 1;
		if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
		{
			this->serverStatus = "Error: setsockopt failed";
			this->keepRunning = false;
		}

		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		serverAddr.sin_port = htons(port); // Port number

		if (bind(serverSocket, (sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
		{
			this->serverStatus = "Error: Bind failed\n";
			close(serverSocket);
			this->keepRunning = false;
		}
		if (listen(serverSocket, SOMAXCONN) == -1)
		{
			this->serverStatus = "Error: Listen failed\n";
			close(serverSocket);
			this->keepRunning = false;
		}

		this->clientAddrLen = sizeof(clientAddr);
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
	void Server::shutdownServer()
	{
		keepRunning = false;
	}
	void Server::runServer()
	{
		//int clientSocket = 0;
		while (keepRunning)
		{
			// Accept new connection
			//sockaddr_in clientAddr;
			clientAddrLen = sizeof(clientAddr);
			int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);
			if (clientSocket == -1)
			{
				std::cerr << "Error: Accept failed" << std::endl;
				continue;
			}
			// Handle communication with the client in a new thread
			if (clientThreads.size() >= MAX_CONNECTED_USERS)
			{
				sendResponse(clientSocket, std::string("Server is full!"));
				close(clientSocket);
				continue;
			}
			std::lock_guard<std::mutex> lock(clientThreadsMutex);
			clientThreads.emplace_back(&Server::handleUser, this, clientSocket);
			clientThreads.back().detach(); // Detach the thread so it runs independently
		}
	}
	bool Server::sendResponse(int clientSocket, std::string message)
	{
		if (send(clientSocket, message.c_str(), message.length(), 0) == -1)
		{
			this->serverStatus = "Error: Send failed\n";
			return false;
		}
		return true;
	}
	void Server::handleUser(int clientSocket)
	{
		char buffer[1024];
		ssize_t bytesRead = 0;

		bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytesRead == -1)
		{
			serverStatus = "Error: Receive failed ";
			serverStatus += strerror(errno);
			serverStatus += "\n";
			return;
		}
		else if (bytesRead == 0)
		{
			this->serverStatus = "Client disconnected\n";
			return;
		}
		buffer[bytesRead] = '\0';
		std::string username = std::string(buffer);
		sendResponse(clientSocket, std::string("Welcome ").append(username).append(" to ConsoleArt server"));
		std::cout << "User " << username << " has joined" << " \n";

		User thisUser{username, clientSocket, true};

		while (true)
		{
			bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
			if (bytesRead == -1)
			{
				serverStatus = "Error: Receive failed ";
				serverStatus += strerror(errno);
				serverStatus += "\n";
				std::cout << serverStatus;
				break;
			}
			else if (bytesRead == 0)
			{
				std::cout << "User " + username + " disconnected\n";
				thisUser.connected = false;
				break;
			}

			buffer[bytesRead] = '\0';

			if (strcmp(buffer, "logout") == 0)
			{
				std::cout <<  "User " + username + " logged out\n";
				thisUser.connected = false;
				break;
			}
			//std::cout <<  username << ": " << buffer << " \n";
			// Echo back to client
			sendResponse(clientSocket, std::string(buffer).append(" [Echo from server]"));
		}

		close(clientSocket);
		// Remove the disconnected client's thread from clientThreads vector
		std::lock_guard<std::mutex> lock(clientThreadsMutex); // Lock the vector before modifying it
		clientThreads.erase(std::remove_if(clientThreads.begin(), clientThreads.end(), [&](std::thread& t)
		{
			return (t.get_id() == std::this_thread::get_id());
		}), clientThreads.end());
		if (clientThreads.size() == 0)
			std::cout << "Server is empty\n";
	}
}
#endif
