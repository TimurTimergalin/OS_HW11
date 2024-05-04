cmake_minimum_required(VERSION 3.27)
project(os_hw11_client)

set(CMAKE_CXX_STANDARD 17)

add_executable(broadcast broadcast.cpp Client.cpp stos.cpp)
add_executable(multicast multicast.cpp Client.cpp stos.cpp)