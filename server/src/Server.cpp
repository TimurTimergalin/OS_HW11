#include "Server.h"

#include <stdexcept>
#include <iostream>
#include <sys/socket.h>
#include <cstring>

void Server::handle() {
    configure();
    std::cout << "Starting accepting messages\n";

    for (;;) {
        std::string input;
        std::getline(std::cin, input);
        send(input);
    }
}

void Server::send(const std::string &mes) {
    auto res = sendto(
            sock,
            mes.c_str(),
            mes.size(),
            0,
            reinterpret_cast<sockaddr *>(&info),
            sizeof(info)
    );
    if (res !=  mes.size()) {
        throw std::runtime_error("Unable to send the whole message");
    }
}

Server::Server(const std::string &ip, unsigned short port) {
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock < 0) {
            throw std::runtime_error("Unable to open socket");
        }
    memset(&info, 0, sizeof(info));
    info.sin_family = AF_INET;
    info.sin_port = htons(port);
    if (inet_aton(ip.c_str(), &info.sin_addr) < 0) {
        throw std::runtime_error("Invalid ip address");
    }
}
