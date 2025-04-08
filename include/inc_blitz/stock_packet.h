#pragma once

#include <cstdint>
#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <vector>
#include <random>
#include <unistd.h>
#include <arpa/inet.h>

#pragma pack(push, 1)

struct StockPacket {
    char symbol[8];
    double price;
    int32_t volume;
    uint64_t timestamp;
};
#pragma pack(pop)