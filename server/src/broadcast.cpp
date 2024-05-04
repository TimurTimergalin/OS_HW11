#include <stdexcept>
#include <iostream>

#include "Server.h"
#include "stos.h"

class BroadcastServer : public Server {
public:
    BroadcastServer(const std::string& ip, unsigned short port) : Server(ip, port) {}
protected:
    void configure() override {
        int perm = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &perm, sizeof(perm)) < 0) {
            throw std::runtime_error("Unable to broadcast on this ip");
        }
    }
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <ip> <port>\n";
        return 1;
    }
    auto ip = argv[1];
    auto port = stos(argv[2]);
    BroadcastServer(ip, port).handle();
}