cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_opencv)

# add compiler flags
set(CMAKE_CXX_FLAGS "-std=c++14")

# exect
add_executable(cv_load_image load_image.cpp)

# link
target_link_libraries(cv_load_image ${OpenCV_LIB})