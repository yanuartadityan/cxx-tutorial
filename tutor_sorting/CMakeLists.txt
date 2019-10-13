cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_sorting)

# add subdirectory here
# e.g. add_subdirectory(src)

# all srcs
set(pointer_sorting_files 
    merge_sort.cpp
    quick_sort.cpp)

# add library
add_library(pointer_sorting STATIC ${pointer_sorting_files})

# add executable
add_executable(test_tutor_sort_1 test_tutor_sort_1.cpp)

# add target link library (dependancies)
# e.g. target_link_libraries(pointer_tutor common)
target_link_libraries(test_tutor_sort_1 pointer_sorting tutor_utils)