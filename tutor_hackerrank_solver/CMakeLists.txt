cmake_minimum_required(VERSION 3.0)

project(tutor_hackerrank_solver)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(solver_lib_files pair_sock.cpp)

add_library(hackerrank_solver STATIC ${solver_lib_files})

add_executable(test_hackerrank test_hackerrank.cpp)

target_link_libraries(test_hackerrank hackerrank_solver)