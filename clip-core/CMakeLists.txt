cmake_minimum_required(VERSION 3.10)
project(clip-core VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Static library with all CLIP protocol logic
add_library(clip-core STATIC
    src/SocketCanAdapter.cpp
    src/ECUReader.cpp
    src/CLIPSessionManager.cpp
    src/CLIPTransportLayer.cpp
    src/CLIPInstructionBuilder.cpp
    src/J1939MessageBuilder.cpp
)

# Public include directory for consumers
target_include_directories(clip-core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Compiler warnings
target_compile_options(clip-core PRIVATE
    -Wall -Wextra -Wpedantic
)
