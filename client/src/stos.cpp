#include "stos.h"

#include <stdexcept>
#include <limits>

unsigned short stos(const std::string &s) {
    int resi = std::stoi(s);

    if (resi <= std::numeric_limits<unsigned short>::max() && resi >= 0) {
        return static_cast<unsigned short>(resi);
    }

    throw std::runtime_error("Invalid port number");
}

