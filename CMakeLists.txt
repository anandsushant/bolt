cmake_minimum_required(VERSION 3.10)
project(blitz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# === blitz main executable ===
file(GLOB BLITZ_SOURCES "src/main.cpp" "src/engine/*.cpp" "src/comm/*.cpp")
add_executable(blitz ${BLITZ_SOURCES})

# === packet_sender executable ===
add_executable(packet_sender tools/packet_sender.cpp)