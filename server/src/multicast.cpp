#include "Server.h"
#include "stos.h"

#include <sys/socket.h>
#include <stdexcept>
#include <iostream>

class MulticastServer : public Server {
private:
    int ttl;
public:
    MulticastServer(const std::string &ip, unsigned short port, int ttl) : Server(ip, port), ttl(ttl) {}
protected:
    void configure() override {
        if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl)) < 0) {
            throw std::runtime_error("Unable to set ttl");
        }
    }
};

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        std::cout << "Usage: " << argv[0] << " <ip> <port> [<ttl>]\n";
        return 1;
    }

    auto ip = argv[1];
    auto port = stos(argv[2]);
    auto ttl = argc == 4 ? std::stoi(argv[3]) : 5;
    MulticastServer(ip, port, ttl).handle();
}
