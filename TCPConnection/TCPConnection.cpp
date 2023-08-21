#include "TCPConnection.h"

bool TCPConnection::initializeWinSock()
{
	ver = MAKEWORD(2, 2);
	wsOk = WSAStartup(ver, &wsData);

	if (0 != wsOk)
	{
		std::cerr << "Can't Initialize winsock! Quitting" << endline;
		return false;
	}

	return true;
}

bool TCPConnection::createASocket()
{
	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == listening)
	{
		std::cerr << "Can't create a socket! Quitting" << endline;
		return false;
	}

	return true;
}

bool TCPConnection::bindTheIPAddress(const USHORT port)
{
	server_in.sin_family = AF_INET;
	server_in.sin_port = htons(port);
	server_in.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 

	if (bind(listening, reinterpret_cast<sockaddr*>(&server_in), sizeof(server_in)) != 0)
	{
		return false;
	}

	return true;

}

bool TCPConnection::createListeningSocket()
{
	if (listen(listening, SOMAXCONN) != 0)
	{
		return false;
	}
	else
	{
		FD_ZERO(&master);

		FD_SET(listening, &master);

		inet_ntop(AF_INET, &server_in.sin_addr, serverIP, NI_MAXHOST);

		if (getnameinfo(reinterpret_cast<sockaddr*>(&server_in), sizeof(server_in), serverName, NI_MAXHOST, nullptr, 0, 0) == 0)
		{
			std::clog << "Server " << serverName << " connected on port " << ntohs(server_in.sin_port) << endline;
		}
		else
		{
			std::clog << serverIP << " connected on port " << ntohs(server_in.sin_port) << endline;
		}

		return true;
	}

}

void TCPConnection::acceptNewConnection()
{
	// Wait for a connection
	sockaddr_in client_in{};
	socklen_t clientSize = sizeof(client_in);

	// Accept a new connection
	auto client = accept(listening, reinterpret_cast<sockaddr*>(&client_in), &clientSize);

	inet_ntop(AF_INET, &client_in.sin_addr, hostIP, NI_MAXHOST);

	if (getnameinfo(reinterpret_cast<sockaddr*>(&client_in), sizeof(client_in), hostName, NI_MAXHOST, nullptr, 0, 0) == 0)
	{
		std::clog << hostName << " (" << hostIP << ") connected on port " << ntohs(client_in.sin_port) << endline;
	}
	else
	{
		std::clog << hostIP << " connected on port " << ntohs(client_in.sin_port) << endline;
	}

	// Add the new connection to the list of connected clients
	FD_SET(client, &master);

	// Send a welcome message to the connected client
	std::string welcomeMsg = "Welcome to the Chat Server!:\r\n";
	send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
	send(client, input.c_str(), input.size() + 1, 0);
}

void TCPConnection::transmitMessage(char buf[], const SOCKET outSock) const
{
	std::ostringstream ss{};
	ss << getTimeStamp() << " Client: " << hostName << ": " << buf;
	auto strOut = ss.str();

	if (strOut.size() < BUFFER_SIZE)
	{
		if (strOut.back() != '\n')
		{
			strOut.push_back('\r');
			strOut.push_back('\n');
		}

		const auto bytesToSend = send(outSock, strOut.c_str(), strOut.size() + 1, 0);
		send(outSock, input.c_str(), input.size() + 1, 0);

		if (bytesToSend != -1)
		{
			std::clog << strOut;
			std::clog << "Bytes Transmitted: " << bytesToSend << endline;
		}
		else
		{
			std::clog << "Failed to send message\r\n";
		}
	}
	ZeroMemory(buf, BUFFER_SIZE);
}

void TCPConnection::sendMessageToOtherClient(char buf[], const SOCKET sock) const
{
	for (unsigned i = 0; i < master.fd_count; i++)
	{
		const auto outSock = master.fd_array[i];

		if (outSock != listening && outSock != sock)
		{
			std::ostringstream ss{};
			if (buf[0] == '\r' && buf[1] == '\n')
			{
				std::clog << "No escape sequence transmitted from client : " << outSock << endline;
			}
			else
			{
				transmitMessage(buf, outSock);
			}
		}
	}
}

void TCPConnection::receiveInboundMessage(char buf[], const SOCKET sock)
{
	// Receive message
	const auto bytesIn = recv(sock, buf, BUFFER_SIZE, 0);

	if (bytesIn <= 0)
	{
		// Drop the client
		closesocket(sock);
		FD_CLR(sock, &master);
	}
	else
	{
		// Check to see if it's a command. \quit kills the server
		if (buf[0] == '\\')
		{
			// Is the command quit? 
			auto cmd = std::string(buf, bytesIn);
			if (cmd == "\\quit\r\n" || cmd == "\\quit")
			{
				running = false;
			}
		}

		// Send message to other clients, and definiately NOT the listening socket
		sendMessageToOtherClient(buf, sock);

	}

}

void TCPConnection::closeTheSocket()
{
	FD_CLR(listening, &master);
	closesocket(listening);

	// Message to let users know what's happening.
	const std::string msg = "Server is shutting down. Goodbye\r\n";

	while (master.fd_count > 0)
	{
		// Get the socket number
		auto sock = master.fd_array[0];

		// Send the goodbye message
		send(sock, msg.c_str(), msg.size() + 1, 0);

		// Remove it from the master file list and close the socket
		FD_CLR(sock, &master);
		closesocket(sock);
	}

	// Cleanup winsock
	WSACleanup();
}

std::string TCPConnection::getTimeStamp() const
{
	std::time_t time_now{ std::time(nullptr) };
	const std::tm tm{ *std::localtime(&time_now) };
	
	std::ostringstream ss{};
	ss << std::put_time(&tm, "%m-%d-%y %OH:%OM:%OS");
	
	const auto strOut = ss.str();

	return strOut;
}

TCPConnection::TCPConnection(USHORT port)
{
	auto WinSockInitialized{ initializeWinSock() };
	auto SocketCreated {createASocket()};
	auto IPAddressBinded {bindTheIPAddress(port)};
	auto ListeningSocketCreated{ createListeningSocket()};

	if (WinSockInitialized && SocketCreated && IPAddressBinded && ListeningSocketCreated)
	{
		std::clog << "Ready to listen..." << endline;
	}

}
 
void TCPConnection::run()
{

	while (running)
	{
		// Make a copy of the master file descriptor set because the call to select
		// will destroy it. 
		auto copy{ master };

		// See who's talking to us
		const auto socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		// Loop through all the current connections / potential connect
		for (auto i = 0; i < socketCount; i++)
		{
			// Makes things easy for us doing this assignment
			auto sock = copy.fd_array[i];

			// Is it an inbound communication?
			if (sock == listening)
			{
				acceptNewConnection();
			}
			else // It's an inbound message
			{
				char buf[BUFFER_SIZE];
				ZeroMemory(buf, BUFFER_SIZE);
				receiveInboundMessage(buf, sock);
			}
		}
	}

	// Remove the listening socket from the master file descriptor set and close it
	// to prevent anyone else trying to connect.
	closeTheSocket();
}
