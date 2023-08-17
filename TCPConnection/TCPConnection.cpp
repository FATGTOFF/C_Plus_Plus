#include "TCPConnection.h"

bool TCPConnection::initializeWinSock()
{
	ver = MAKEWORD(2, 2);
	wsOk = WSAStartup(ver, &wsData);

	if (0 != wsOk)
	{
		std::cerr << "Can't Initialize winsock! Quitting\r\n";
		return false;
	}

	return true;
}

bool TCPConnection::createASocket()
{
	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == listening)
	{
		std::cerr << "Can't create a socket! Quitting\r\n";
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
			std::clog << "Server " << serverName << " connected on port " << ntohs(server_in.sin_port) << "\r\n";
		}
		else
		{
			std::clog << serverIP << " connected on port " << ntohs(server_in.sin_port) << "\r\n";
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
	SOCKET client = accept(listening, (sockaddr*)&client_in, &clientSize);

	char hostName[NI_MAXHOST]{};      // Client's remote name
	char hostIP[NI_MAXHOST]{};


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
	std::string welcomeMsg = "Welcome to the Chat Server!\r\n";
	send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
}

void TCPConnection::transmitMessage(char buf[], const SOCKET sock, const SOCKET outSock) const
{
	std::ostringstream ss{};
	ss << "SOCKET #" << sock << ": " << buf;
	auto strOut = ss.str();

	if (strOut.back() != '\n')
	{
		strOut.push_back('\r');
		strOut.push_back('\n');
	}

	const auto bytesToSend = send(outSock, strOut.c_str(), strOut.size() + 1, 0);
	if (bytesToSend != -1)
	{
		std::clog << "Bytes Transmitted: " << bytesToSend << endline;
	}
	else
	{
		std::clog << "Failed to send message\r\n";
	}

	ZeroMemory(buf, 512);
}

void TCPConnection::sendMessageToOtherClient(char buf[], const SOCKET sock) const
{
	for (unsigned i = 0; i < master.fd_count; i++)
	{
		SOCKET outSock = master.fd_array[i];

		if (outSock != listening && outSock != sock)
		{
			std::ostringstream ss{};
			if (buf[0] == '\r' && buf[1] == '\n')
			{
				std::clog << "No escape sequence transmitted from client : " << outSock << endline;
			}
			else
			{
				transmitMessage(buf, sock, outSock);
			}
		}
	}
}

void TCPConnection::receiveInboundMessage(char buf[], const SOCKET sock)
{
	// Receive message
	int bytesIn = recv(sock, buf, 512, 0);

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
	std::string msg = "Server is shutting down. Goodbye\r\n";

	while (master.fd_count > 0)
	{
		// Get the socket number
		SOCKET sock = master.fd_array[0];

		// Send the goodbye message
		send(sock, msg.c_str(), msg.size() + 1, 0);

		// Remove it from the master file list and close the socket
		FD_CLR(sock, &master);
		closesocket(sock);
	}

	// Cleanup winsock
	WSACleanup();
}

TCPConnection::TCPConnection(USHORT port)
{
	bool WinSockInitialized = initializeWinSock();
	bool SocketCreated = createASocket();
	bool IPAddressBinded = bindTheIPAddress(port);
	bool ListeningSocketCreated = createListeningSocket();

	if (WinSockInitialized && SocketCreated && IPAddressBinded && ListeningSocketCreated)
	{
		std::clog << "Ready to listen...\r\n";
	}

}

void TCPConnection::run()
{

	while (running)
	{
		// Make a copy of the master file descriptor set, this is SUPER important because
		// the call to select() is _DESTRUCTIVE_. The copy only contains the sockets that
		// are accepting inbound connection requests OR messages. 

		// E.g. You have a server and it's master file descriptor set contains 5 items;
		// the listening socket and four clients. When you pass this set into select(), 
		// only the sockets that are interacting with the server are returned. Let's say
		// only one client is sending a message at that time. The contents of 'copy' will
		// be one socket. You will have LOST all the other sockets.

		// SO MAKE A COPY OF THE MASTER LIST TO PASS INTO select() !!!

		fd_set copy = master;

		// See who's talking to us
		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		// Loop through all the current connections / potential connect
		for (int i = 0; i < socketCount; i++)
		{
			// Makes things easy for us doing this assignment
			SOCKET sock = copy.fd_array[i];

			// Is it an inbound communication?
			if (sock == listening)
			{
				acceptNewConnection();
			}
			else // It's an inbound message
			{
				char buf[512];
				ZeroMemory(buf, 512);
				receiveInboundMessage(buf, sock);
			}
		}
	}

	// Remove the listening socket from the master file descriptor set and close it
	// to prevent anyone else trying to connect.
	closeTheSocket();
}
