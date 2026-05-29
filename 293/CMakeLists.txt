cmake_minimum_required(VERSION 3.15)

project(NeonSmokeApp VERSION 1.0 LANGUAGES CXX)

# Smoke/integration: avoid MSVC kit libs (ole32/shell32) that can autolink Qt5AxServer on some dev boxes.
set(CMAKE_C_STANDARD_LIBRARIES "")
set(CMAKE_CXX_STANDARD_LIBRARIES "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/CounterApp.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    target_link_libraries(${PROJECT_NAME} PRIVATE user32 gdi32)
    target_link_options(${PROJECT_NAME} PRIVATE "/NODEFAULTLIB:Qt5AxServer.lib")
endif()
