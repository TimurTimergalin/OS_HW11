//
// Created by user1 on 04/05/24.
//

#include <stdexcept>
#include <cstring>
#include <iostream>
#include "Client.h"

const size_t max_size = 255;

Client::Client(unsigned short port) {
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        throw std::runtime_error("Unable to open socket");
    }
    memset(&info, 0, sizeof(info));
    info.sin_family = AF_INET;
    info.sin_port = htons(port);
    info.sin_addr.s_addr = htonl(INADDR_ANY);

    auto bind_res = bind(
            sock,
            reinterpret_cast<sockaddr *>(&info),
            sizeof(info)
    );
    if (bind_res < 0) {
        throw std::runtime_error("Unable to bind socket");
    }
}

std::string Client::recv() const {
    char buf[max_size];
    ssize_t rec_len = recvfrom(sock, buf, max_size, 0, nullptr, nullptr);
    if (rec_len < 0) {
        throw std::runtime_error("Unable to receive");
    }
    return {buf, static_cast<size_t>(rec_len)};
}

void Client::handle() {
    configure();
    std::cout << "Starting accepting messages\n";

    for (;;) {
        std::cout << "Message received: " << recv() << '\n';
    }
}

void Client::configure() {}
