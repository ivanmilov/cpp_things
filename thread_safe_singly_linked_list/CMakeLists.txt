cmake_minimum_required(VERSION 3.1...3.21)

project(
    ll
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)
# add_compile_options(-Wall -Werror -Wextra -Wshadow)


add_executable(ll main.cpp)
target_link_libraries(ll pthread)
