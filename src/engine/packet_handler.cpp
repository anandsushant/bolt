// src/engine/packet_handler.cpp

#include "inc_blitz/packet_handler.h"
#include <iostream>

PacketHandler::PacketHandler (size_t buffer_limit) : buffer_limit_(buffer_limit) {}

void PacketHandler::handle_packet(const StockPacket& packet) {

    std::string symbol(packet.symbol);
    auto& buffer = symbol_packet_list_[symbol];

    // if (!buffer) {
    //     buffer = 
    // }
    // if (buffer.size() >= buffer_limit_) {
    //     buffer.pop_front();
    // }
    // buffer.push_back(packet);

    return;
}

void PacketHandler::print_buffers() const {
    std::lock_guard<std::mutex> lock(mutex_);

    for (const auto& [symbol, buffer] : symbol_packet_list_) {
        std::cout << "Symbol: " << symbol << ", Packets: " << buffer.size() << "\n";
    }
    return;
}