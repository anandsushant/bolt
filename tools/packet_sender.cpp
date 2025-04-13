// tools/packet_sender.cpp

#include "inc_utils/stock_packet.h"

int main() {

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in servaddr{};
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // const char* msg = "MarketData:BUY AAPL 100 @ 170.32";

    std::default_random_engine rng(std::random_device{}());

    std::vector<std::string> symbols = {"AAPL", "GOOG", "TSLA", "MSFT"};
    std::uniform_real_distribution<double> price_dist(100.0, 500.0);
    std::uniform_int_distribution<int> vol_dist(100, 10000);
    std::uniform_int_distribution<size_t> symbol_dist(0, symbols.size() - 1);

    // while (true) {
    //     sendto(sockfd, msg, strlen(msg), 0,
    //            (sockaddr*)&servaddr, sizeof(servaddr));
    //     std::cout << "Sent packet\n";
    //     usleep(1000);  // 1ms -> ~1000 packets/sec
    // }

    while (true) {

        StockPacket packet{};

        std::string symbol = symbols[symbol_dist(rng)];
        std::strncpy(packet.symbol, symbol.c_str(), sizeof(packet.symbol) - 1);
        packet.symbol[sizeof(packet.symbol) - 1] = '\0';

        packet.price = price_dist(rng);
        packet.volume = vol_dist(rng);

        auto now = std::chrono::system_clock::now().time_since_epoch();
        packet.timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now).count();

        sendto(sockfd, &packet, sizeof(packet), 0, (sockaddr*)&servaddr, sizeof(servaddr));
        std::cout << "Sent: " << packet.symbol << " | Price: " << packet.price << " | Volume: " << packet.volume << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // to simulate interval
    }

    close(sockfd);
    return 0;
}