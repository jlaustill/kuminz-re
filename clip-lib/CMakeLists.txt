cmake_minimum_required(VERSION 3.10)
project(clip-lib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CAN adapter library
add_library(can STATIC
    src/can/SocketCanAdapter.cpp
)
target_include_directories(can PUBLIC src)

# CLI tool
add_executable(clip-test
    src/cli/main.cpp
)
target_link_libraries(clip-test PRIVATE can)
target_include_directories(clip-test PRIVATE src)
