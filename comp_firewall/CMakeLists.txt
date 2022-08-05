cmake_minimum_required(VERSION 3.1...3.21)

project(
    test
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)

add_executable(test main.cpp test.cpp)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
