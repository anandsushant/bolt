// src/udp_receiver.cpp

#include "inc_blitz/udp_receiver.h"

UDPReceiver::UDPReceiver(int port) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Listening on UDP port " << port << "...\n";

}
UDPReceiver::~UDPReceiver() {
    close(sockfd);
}

bool UDPReceiver::receive(StockPacket &packet) {

    sockaddr_in sender_addr;

    socklen_t addr_len = sizeof(sender_addr);
    ssize_t bytes_received = recvfrom(
        sockfd, &packet, sizeof(StockPacket), 0,
        (sockaddr*)&sender_addr, &addr_len
    );

    return bytes_received == sizeof(StockPacket);
}