cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(hackerrank_helper_src
    string_split.cpp)

add_library(hackerrank_helper STATIC ${hackerrank_helper_src})