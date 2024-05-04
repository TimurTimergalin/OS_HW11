#ifndef OS_HW11_CLIENT_H
#define OS_HW11_CLIENT_H

#include <arpa/inet.h>
#include <string>

class Client {
protected:
    int sock;
public:
    [[noreturn]] void handle();

    explicit Client(unsigned short port);

private:
    sockaddr_in info{};
    [[nodiscard]] std::string recv() const;
protected:
    virtual void configure();
};


#endif //OS_HW11_CLIENT_H
