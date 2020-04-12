cmake_minimum_required(VERSION 3.10)

# project name
project(project_mrt)

# add compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# add subdirectory
add_subdirectory(src)

# add executable
add_executable(project_mrt main.cpp include/platform.h)

# target link
target_link_libraries(project_mrt mrt)