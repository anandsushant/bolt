// src/udp_receiver.cpp

#include "inc_blitz/udp_receiver.h"

UDPReceiver::UDPReceiver(int port, PacketHandler& handler) : running_(false), packet_handler_(handler) {
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    std::memset(&server_addr_, 0, sizeof(server_addr_));
    server_addr_.sin_family = AF_INET;
    server_addr_.sin_addr.s_addr = INADDR_ANY;
    server_addr_.sin_port = htons(port);

    if (bind(sockfd_, (struct sockaddr*)&server_addr_, sizeof(server_addr_)) < 0) {
        perror("bind");
        close(sockfd_);
        exit(EXIT_FAILURE);
    }

    std::cout << "Listening on UDP port " << port << "...\n";

}
UDPReceiver::~UDPReceiver() {
    close(sockfd_);
}

void UDPReceiver::start() {
    running_ = true;
    StockPacket _packet_;

    while(running_) {
        ssize_t n = recvfrom(sockfd_, &_packet_, sizeof(_packet_), 0, nullptr, nullptr);
        if (n > 0) {
            packet_handler_.handle_packet(_packet_);
            // debug
            // std::cout << "Received: " << packet.symbol << " $" << packet.price << "\n";
        }
    }
}
