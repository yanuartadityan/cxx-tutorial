cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_strings)

# add compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# all srcs
set(string_files
        html_tags.cpp)

add_library(string_lib STATIC ${string_files})

# add executable
add_executable(test_string test_string.cpp)

# target link
target_link_libraries(test_string string_lib)