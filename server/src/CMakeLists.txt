cmake_minimum_required(VERSION 3.27)
project(os_hw11_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(broadcast broadcast.cpp Server.cpp stos.cpp)
add_executable(multicast multicast.cpp Server.cpp stos.cpp)
