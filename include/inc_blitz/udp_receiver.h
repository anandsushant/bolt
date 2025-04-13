// include/inc_blitz/udp_receiver.h
#ifndef UDP_RECEIVER_H
#define UDP_RECEIVER_H

#include <string>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include "inc_blitz/packet_handler.h"

class UDPReceiver {
    public:
        UDPReceiver(int port, PacketHandler& handler);
        ~UDPReceiver();
        void start();
        // bool receive(StockPacket &packet);
    private:
        int sockfd_;
        // int port;
        sockaddr_in server_addr_;
        // void receiveLoop();
        std::atomic<bool> running_;
        PacketHandler& packet_handler_;
};

#endif // UDP_RECEIVER_H