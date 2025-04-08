// include/inc_blitz.h

#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct StockPacket {
    char symbol[8];
    double price;
    int32_t volume;
    uint64_t timestamp;
};

class UDPReceiver {
    public:
        UDPReceiver(int port);
        ~UDPReceiver();
        bool receive(StockPacket &packet);
        // void start();
    private:
        int sockfd;
        // int port;
        sockaddr_in server_addr;
        // void receiveLoop();
};