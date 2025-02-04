cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SERVER_SOURCES
    src/server_main.cpp
    src/server.cpp
)

set(CLIENT_SOURCES
    src/client_main.cpp
    src/client.cpp
)

add_executable(server ${SERVER_SOURCES})
target_include_directories(server PRIVATE include)

add_executable(client ${CLIENT_SOURCES})
target_include_directories(client PRIVATE include)