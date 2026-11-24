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
    src/ServiceScanner.cpp
    src/SecurityAuth.cpp
    src/ChunkedRead.cpp
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

# Unit tests (only when clip-core is the top-level project, not inside kuminz-cli / kuminz-ui)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    enable_testing()
    add_executable(clip-core-tests tests/test_chunked_read.cpp)
    target_link_libraries(clip-core-tests PRIVATE clip-core)
    target_compile_options(clip-core-tests PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME chunked_read COMMAND clip-core-tests)
endif()
