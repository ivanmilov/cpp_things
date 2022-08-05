cmake_minimum_required(VERSION 3.1...3.21)

project(
    test
    VERSION 1.0
    LANGUAGES CXX
)

add_compile_options(-fdiagnostics-color=auto)

message(STATUS "MY_DEF: " ${MY_DEF})

if(${MY_DEF})
    add_definitions(-DMY_DEF=${MY_DEF})
endif()

add_compile_options(-Wall -Werror -Wextra -Wshadow)
add_executable(test main.cpp)
target_compile_features(test PUBLIC cxx_std_20)
