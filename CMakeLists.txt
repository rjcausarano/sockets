cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(server src/server.cpp)
target_include_directories(server PRIVATE include)

add_executable(client src/client.cpp)
target_include_directories(client PRIVATE include)