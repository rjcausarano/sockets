cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Protobuf REQUIRED CONFIG)

set(SERVER_SOURCES
    src/server_main.cpp
    src/server.cpp
    proto/person.pb.cc
)

set(CLIENT_SOURCES
    src/client_main.cpp
    src/client.cpp
)

include_directories(${Protobuf_INCLUDE_DIRS})

add_executable(server ${SERVER_SOURCES})
target_include_directories(server PRIVATE include)
target_link_libraries(server PRIVATE protobuf::libprotobuf)

add_executable(client ${CLIENT_SOURCES})
target_include_directories(client PRIVATE include)