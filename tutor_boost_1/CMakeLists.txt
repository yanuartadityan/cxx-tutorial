cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_boost_1)

# add compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# all srcs set(boost_files_1 boost_1.cpp)

# add_library(boost_tutor STATIC ${boost_files_1})

# add executable
add_executable(test_boost_1 test_boost_1.cpp)

# target link lib
target_link_libraries(test_boost_1 fmt::fmt Boost::graph)
