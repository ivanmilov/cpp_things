cmake_minimum_required(VERSION 3.1...3.21)

project(
    json_test
    VERSION 1.0
    LANGUAGES CXX
)


add_compile_options (-fdiagnostics-color=auto)

add_executable(test main.cpp)
set_property(TARGET test PROPERTY CXX_STANDARD 20)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
