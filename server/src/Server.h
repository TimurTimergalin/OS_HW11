#ifndef OS_HW11_SERVER_H
#define OS_HW11_SERVER_H

#include <string>

#include <arpa/inet.h>


class Server {
protected:
    int sock;
public:
    [[noreturn]] void handle();
private:
    sockaddr_in info{};
    void send(const std::string &mes);

protected:
    Server(const std::string &ip, unsigned short port);
    virtual void configure() = 0;
};


#endif //OS_HW11_SERVER_H
