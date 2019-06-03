cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_utils)

# add subdirectory here
# e.g. add_subdirectory(src)

# all srcs
set(tutor_utils
    tutor_utils.cpp)

# add library
add_library(tutor_utils STATIC ${tutor_utils})