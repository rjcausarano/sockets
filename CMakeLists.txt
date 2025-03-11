cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
  include
)

set(LIB_SOURCES
  src/server.cpp
  src/client.cpp
)

set(SERVER_SOURCES
  src/server_main.cpp
)

set(CLIENT_SOURCES
  src/client_main.cpp
)

add_library(comms SHARED ${LIB_SOURCES})
set_target_properties(comms PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(server ${SERVER_SOURCES})
target_link_libraries(server comms)


add_executable(client ${CLIENT_SOURCES})
target_link_libraries(client comms)
