cmake_minimum_required(VERSION 3.10)
project(socket_test)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Protobuf REQUIRED CONFIG)

# set(PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/comms/entity.proto)
# protobuf_generate(
#     LANGUAGE cpp
#     OUT_VAR PROTO_SRCS
#     PROTOS ${PROTO_FILES}
#     EXPORT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/proto
# )

execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/proto/generate_messages.sh)

include_directories(${Protobuf_INCLUDE_DIRS})

file(GLOB COMM_SOURCES
  src/comms/*.cc
)

add_library(comms SHARED ${COMM_SOURCES})
set_target_properties(comms PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(comms PRIVATE include)
target_link_libraries(comms PUBLIC protobuf::libprotobuf-lite)

add_executable(server src/server_main.cc)
target_include_directories(server PRIVATE include)
target_link_libraries(server comms)

add_executable(client src/client_main.cc)
target_include_directories(client PRIVATE include)
target_link_libraries(client comms)

add_executable(test src/test.cc)
target_include_directories(test PRIVATE include)
target_link_libraries(test comms)
