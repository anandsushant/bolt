// src/udp_receiver.cpp

#include "inc_blitz/udp_receiver.h"

<<<<<<< HEAD
UDPReceiver::UDPReceiver(int port) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0){
        perror("Socket creation failed");
=======
UDPReceiver::UDPReceiver(int port, PacketHandler& handler) : running_(false), packet_handler_(handler) {
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0){
        perror("socket creation failed");
>>>>>>> 963dba0 (updating symbol-packet structure)
        exit(EXIT_FAILURE);
    }

    std::memset(&server_addr_, 0, sizeof(server_addr_));
    server_addr_.sin_family = AF_INET;
    server_addr_.sin_addr.s_addr = INADDR_ANY;
    server_addr_.sin_port = htons(port);

<<<<<<< HEAD
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed.");
        close(sockfd);
=======
    if (bind(sockfd_, (struct sockaddr*)&server_addr_, sizeof(server_addr_)) < 0) {
        perror("bind");
        close(sockfd_);
>>>>>>> 963dba0 (updating symbol-packet structure)
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

<<<<<<< HEAD
    sockaddr_in sender_addr;

    socklen_t addr_len = sizeof(sender_addr);
    ssize_t bytes_received = recvfrom(
        sockfd, &packet, sizeof(StockPacket), 0,
        (sockaddr*)&sender_addr, &addr_len
    );

    return bytes_received == sizeof(StockPacket);
}
=======
    while(running_) {
        ssize_t n = recvfrom(sockfd_, &_packet_, sizeof(_packet_), 0, nullptr, nullptr);
        if (n > 0) {
            packet_handler_.handle_packet(_packet_);
            // debug
            // std::cout << "Received: " << packet.symbol << " $" << packet.price << "\n";
        }
    }
}
>>>>>>> 963dba0 (updating symbol-packet structure)
