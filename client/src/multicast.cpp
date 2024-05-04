#include <stdexcept>
#include <iostream>

#include "Client.h"
#include "stos.h"

class MulticastClient : public Client {
private:
    std::string ip;
public:
    MulticastClient(unsigned short port, std::string ip) : Client(port), ip(std::move(ip)) {}

protected:
    void configure() override {
        ip_mreq req{};
        req.imr_interface.s_addr = htonl(INADDR_ANY);
        if (inet_aton(ip.c_str(), &req.imr_multiaddr) < 0) {
            throw std::runtime_error("Invalid ip address");
        }
        if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req)) < 0) {
            throw std::runtime_error("Unable to subscribe to multicast");
        }
    }
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <ip> <port>\n";
        return 1;
    }

    auto ip = argv[1];
    unsigned short port = stos(argv[2]);
    MulticastClient(port, ip).handle();
}