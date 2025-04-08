// src/main.cpp

#include "inc_blitz/udp_receiver.h"

int main() {
    UDPReceiver receiver(9000);
    StockPacket packet;

    while (true) {
        if (receiver.receive(packet)) {
            std::cout << "[RECEIVED] Symbol: " << packet.symbol << " | Price: " << packet.price << " | Volume: " << packet.volume << "\n";
        }
    }
    return 0;
}