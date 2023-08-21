#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

constexpr auto BUFFER_SIZE{ 512 };

class TCPConnection
{
private:
	WSADATA wsData{};
	WORD ver{};
	int wsOk{};
	SOCKET listening{};
	sockaddr_in server_in{};
	fd_set master{};
	const std::string input{ ">>>" };
	const std::string endline{ "\r\n" };
	bool running{ true };
	char serverName[NI_MAXHOST]{};
	char serverIP[NI_MAXHOST]{};
	char hostName[NI_MAXHOST]{};
	char hostIP[NI_MAXHOST]{};

	bool initializeWinSock();
	bool createASocket();
	bool bindTheIPAddress(const USHORT);
	bool createListeningSocket();
	void acceptNewConnection();
	void transmitMessage(char buf[], const SOCKET outSock) const;
	void sendMessageToOtherClient(char buf[], const SOCKET sock) const;
	void receiveInboundMessage(char buf[], const SOCKET sock);
	void closeTheSocket();
	std::string getTimeStamp() const;

public:
	explicit TCPConnection(USHORT);
	void run();
};

#endif

