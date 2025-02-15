cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Protobuf REQUIRED CONFIG)

set(SERVER_SOURCES
    src/server_main.cc
    src/server.cc
    proto/header.pb.cc
)

set(CLIENT_SOURCES
    src/client_main.cc
    src/client.cc
    src/communicator.cc
    src/header_factory.cc
    proto/header.pb.cc
)

set(TEST_SOURCES
    src/test.cc
    src/header_factory.cc
    proto/header.pb.cc
    proto/dir_descriptor.pb.cc
)

include_directories(${Protobuf_INCLUDE_DIRS})

add_executable(server ${SERVER_SOURCES})
target_include_directories(server PRIVATE include)
target_link_libraries(server PRIVATE protobuf::libprotobuf)

add_executable(client ${CLIENT_SOURCES})
target_include_directories(client PRIVATE include)
target_link_libraries(client PRIVATE protobuf::libprotobuf)

add_executable(test ${TEST_SOURCES})
target_include_directories(test PRIVATE include)
target_link_libraries(test PRIVATE protobuf::libprotobuf)
