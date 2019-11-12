cmake_minimum_required(VERSION 3.0)

project(tutor_kattis)

set(CMAKE_CXX_FLAGS "-std=c++14")

set(solver_kattis_files
        alice_bob.cpp
        )

add_library(kattis_solver STATIC ${solver_kattis_files})

add_executable(test_kattis test_kattis.cpp)
add_executable(test_kattis_1 alice_bob_solver.cpp)
add_executable(test_kattis_2 boiling_pots_solver.cpp)
add_executable(test_kattis_3 honeycomb_ant_solver.cpp)

target_link_libraries(test_kattis kattis_solver)