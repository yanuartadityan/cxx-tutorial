cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_linked_list)

# all srcs
set(linked_list_files
    linked_list_1.cpp)

add_library(linked_list_tutor STATIC ${linked_list_files})

# add executable
add_executable(test_linked_list_1 test_linked_list_1.cpp)

# add target link library (dependancies)
# e.g. target_link_libraries(pointer_tutor common)
target_link_libraries(test_linked_list_1 linked_list_tutor)