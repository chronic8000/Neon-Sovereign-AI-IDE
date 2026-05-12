cmake_minimum_required(VERSION 3.15)
project(NeonSovereign VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project-wide definitions
add_definitions(-DNEON_SOVEREIGN_BUILD)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(NeonSovereign ${SOURCES})

# Link libraries (Example: pthread for Linux)
if(UNIX)
    target_link_libraries(NeonSovereign pthread)
endif()

# Installation rules
install(TARGETS NeonSovereign DESTINATION bin)