cmake_minimum_required(VERSION 3.1...3.21)

project(
    test
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)

add_subdirectory(lib)
add_subdirectory(my_lib_extention)

add_executable(test main.cpp)
target_link_libraries(test PUBLIC my_lib)
