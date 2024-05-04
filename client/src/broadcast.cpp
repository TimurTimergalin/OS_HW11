#include <iostream>
#include "Client.h"
#include "stos.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <port>\n";
        return 1;
    }
    unsigned short port = stos(argv[1]);
    Client(port).handle();
}

