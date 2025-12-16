cmake_minimum_required(VERSION 3.10)
project(kuminz-cli VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add clip-core library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../clip-core ${CMAKE_CURRENT_BINARY_DIR}/clip-core)

# CLI executable
add_executable(kuminz-cli
    src/main.cpp
)

# Link clip-core library
target_link_libraries(kuminz-cli PRIVATE clip-core)

# Compiler warnings
target_compile_options(kuminz-cli PRIVATE
    -Wall -Wextra -Wpedantic
)
