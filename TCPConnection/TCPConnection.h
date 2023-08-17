#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <iostream>
#include <string>
#include <sstream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

class TCPConnection
{
private:
	WSADATA wsData;
	WORD ver;
	int wsOk;
	SOCKET listening;
	sockaddr_in server_in;
	fd_set master;
	const std::string endline = "\r\n";
	bool running = true;
	char serverName[NI_MAXHOST]{};
	char serverIP[NI_MAXHOST]{};

	bool initializeWinSock();
	bool createASocket();
	bool bindTheIPAddress(const USHORT);
	bool createListeningSocket();
	void acceptNewConnection();
	void transmitMessage(char buf[], const SOCKET sock, const SOCKET outSock) const;
	void sendMessageToOtherClient(char buf[], const SOCKET sock) const;
	void receiveInboundMessage(char buf[], const SOCKET sock);
	void closeTheSocket();

public:
	explicit TCPConnection(USHORT);
	void run();
};

#endif

