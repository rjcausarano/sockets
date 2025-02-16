cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/proto/generate_messages.sh)

include_directories(
    include
)

link_directories(
    libs
)

file(GLOB COMM_SOURCES
  src/comms/*.cc
)

add_library(comms SHARED ${COMM_SOURCES})
set_target_properties(comms PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(comms PUBLIC libprotobuf-lite.so)

add_executable(server src/server_main.cc)
target_link_libraries(server comms)

add_executable(client src/client_main.cc)
target_link_libraries(client comms)

add_executable(test src/test.cc)
target_link_libraries(test comms)
