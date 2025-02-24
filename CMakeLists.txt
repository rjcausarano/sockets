cmake_minimum_required(VERSION 3.30)

project(sockets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Protobuf CONFIG REQUIRED)

execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/proto/generate_messages.sh)

include_directories(
  include
  ${PROTOBUF_INCLUDE_DIR}
)

file(GLOB COMM_SOURCES
  src/comms/*.cc
  src/*.cc
)

set(TEST_FILES
  test/command_processor.cc
)

add_library(comms SHARED ${COMM_SOURCES})
set_target_properties(comms PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(comms PUBLIC protobuf::libprotobuf-lite)

add_executable(server test/server_main.cc ${TEST_FILES} ${COMM_SOURCES})
target_link_libraries(server comms)
