cmake_minimum_required(VERSION 3.27)
project(os_hw11)

set(CMAKE_CXX_STANDARD 17)

add_executable(broadcast_server server/src/broadcast.cpp server/src/Server.cpp
        server/src/stos.cpp)
add_executable(multicast_server server/src/multicast.cpp server/src/Server.cpp
        server/src/stos.cpp)
add_executable(broadcast_client client/src/broadcast.cpp client/src/Client.cpp client/src/stos.cpp)
add_executable(multicast_client client/src/multicast.cpp client/src/Client.cpp client/src/stos.cpp)
