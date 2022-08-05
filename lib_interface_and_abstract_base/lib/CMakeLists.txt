cmake_minimum_required(VERSION 3.1...3.21)

project(
    test_lib
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)

add_library(test_lib SHARED src/test_lib_abstract.cpp)

target_include_directories(test_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
