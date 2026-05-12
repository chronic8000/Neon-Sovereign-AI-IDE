cmake_minimum_required(VERSION 3.20)
project(NeonSovereign VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optimization and Warning flags
if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Find threading library
find_package(Threads REQUIRED)

# Define the executable
add_executable(NeonSovereign 
    main.cpp 
    server.cpp
)

# Link necessary libraries
target_link_libraries(NeonSovereign 
    PRIVATE 
    Threads::Threads
)

# Windows specific networking libraries
if(WIN32)
    target_link_libraries(NeonSovereign 
        PRIVATE 
        ws2_32 
        mswsock
    )
endif()

# Ensure the executable is placed in a specific directory if needed
set_target_properties(NeonSovereign PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)