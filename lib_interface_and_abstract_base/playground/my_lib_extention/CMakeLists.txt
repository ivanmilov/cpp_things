cmake_minimum_required(VERSION 3.1...3.21)

project(
    my_lib
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)

add_library(my_lib SHARED my_lib.cpp)

target_link_libraries(my_lib PUBLIC test_lib)
target_link_directories(my_lib PUBLIC ${CMAKE_SOURCE_DIR}/libs)

target_include_directories(my_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                         ${CMAKE_SOURCE_DIR}/include)

