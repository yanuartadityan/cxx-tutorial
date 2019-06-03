cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_graphs)

# all srcs
set(graphs_files
    graphs_1.cpp)

add_library(graphs_tutor STATIC ${graphs_files})

# add executable
add_executable(test_graphs_1 test_graphs_1.cpp)
add_executable(test_queue test_queue.cpp)

# target link lib
target_link_libraries(test_graphs_1 graphs_tutor)