cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_pointer)

# add subdirectory here
# e.g. add_subdirectory(src)

# all srcs
set(pointer_tutor_files 
    training.cpp)

# add library
add_library(pointer_tutor STATIC ${pointer_tutor_files})

# add executable
add_executable(test_tutor_ptr_1 test_tutor_ptr_1.cpp)

# add target link library (dependancies)
# e.g. target_link_libraries(pointer_tutor common)
target_link_libraries(test_tutor_ptr_1 pointer_tutor)