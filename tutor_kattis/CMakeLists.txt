cmake_minimum_required(VERSION 3.0)

project(tutor_kattis)

set(CMAKE_CXX_FLAGS "-std=c++14")

add_executable(test_kattis_1 alice_bob_solver.cpp)
add_executable(test_kattis_2 boiling_pots_solver.cpp)
add_executable(test_kattis_3 honeycomb_ant_solver.cpp)
add_executable(test_kattis_4 ulam_spiral.cpp)