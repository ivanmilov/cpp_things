cmake_minimum_required(VERSION 3.1...3.21)

project(
    cpp_things
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options (-fdiagnostics-color=auto)
add_compile_options(-Wall -Werror -Wextra -Wshadow
)

include(FetchContent)

FetchContent_Declare(
    googletest
GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
    benchmark
GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.6.1
)
FetchContent_MakeAvailable(benchmark)


add_executable(fluentcpp_reverse-for-loops-in-cpp fluentcpp_reverse-for-loops-in-cpp.cpp)


add_executable(fluentcpp_transform-adaptor-equivalent-in-cpp fluentcpp_transform-adaptor-equivalent-in-cpp.cpp)

add_executable(cpp_weekly_13_fib_template cpp_weekly_13_fib_template.cpp)

add_executable(cpp_weekly_13_fib_binet cpp_weekly_13_fib_binet.cpp)

add_executable(cpp_weekly_37_fib_stateful_lambda cpp_weekly_37_fib_stateful_lambda.cpp)

add_executable(cpp_weekly_37_fib_stateful_lambda_ext cpp_weekly_37_fib_stateful_lambda_ext.cpp)

add_executable(cpp_weekly_189_fib_variable_template cpp_weekly_189_fib_variable_template.cpp)

add_executable(cpp_weekly_189_variable_template cpp_weekly_189_variable_template.cpp)

add_executable(rewrite_output rewrite_output.cpp)

add_executable(longest_common_subsequence longest_common_subsequence.cpp)

add_executable(cpp_weekly_11_std_future cpp_weekly_11_std_future.cpp)
target_link_libraries(cpp_weekly_11_std_future pthread)

add_executable(cpp_weekly_11_std_future_bench cpp_weekly_11_std_future_bench.cpp)
target_link_libraries(cpp_weekly_11_std_future_bench PUBLIC benchmark::benchmark)

# add_executable(ranges_dummy ranges_dummy.cpp)

add_executable(cpp_weekly_134_visitor cpp_weekly_134_visitor.cpp)

add_executable(template_check_member template_check_member.cpp)
