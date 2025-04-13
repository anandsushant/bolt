// src/main.cpp

#include "inc_blitz/udp_receiver.h"
#include "inc_blitz/packet_handler.h"

int main() {
    // UDPReceiver receiver(9000);
    // StockPacket packet;

    // while (true) {
    //     if (receiver.receive(packet)) {
    //         std::cout << "[RECEIVED] Symbol: " << packet.symbol << " | Price: " << packet.price << " | Volume: " << packet.volume << "\n";
    //     }
    // }

    PacketHandler _handler_(10); // Buffer size per symbol
    UDPReceiver _receiver_(9000, _handler_);
    _receiver_.start();

    return 0;
}