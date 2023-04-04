cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_opencv)

# add compiler flags
set(CMAKE_CXX_STANDARD 17)

# exect
add_executable(${PROJECT_NAME} load_image.cpp)

# working with assets directory
message(STATUS "Project ${PROJECT_NAME} directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "Build directory: ${CMAKE_CURRENT_BINARY_DIR}")
set (source "${PROJECT_SOURCE_DIR}/assets")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/assets")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
)

# link
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

