#include "TCPConnection.h"

int main()
{
	TCPConnection server(58000);
	server.run();
}