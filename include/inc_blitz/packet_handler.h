#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include <unordered_map>
#include <deque>
#include <mutex>
#include <string>
#include "inc_utils/stock_packet.h"
#include "inc_blitz/buffer.h"

class PacketHandler {
public:
    PacketHandler(size_t buffer_limit = 10);
    void handle_packet(const StockPacket& packet);
    void print_buffers() const;   // for printing and debugging

private:
    size_t buffer_limit_;
    mutable std::mutex mutex_;  // for symbol_packet_list_
    std::unordered_map<std::string, Buffer<StockPacket>> symbol_packet_list_;
};

#endif // PACKET_HANDLER_H
