cmake_minimum_required(VERSION 3.10)

# project name
project(project_thesis)

# add compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# set
set(SHARED_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SHARED_INCLUDE_DIR ${SHARED_INCLUDE_DIR} PARENT_SCOPE)
FILE(GLOB SHARED_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
FILE(GLOB SHARED_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(LIB_SOURCES
        ${SHARED_HEADER_FILES}
        ${SHARED_SRC_FILES})

# add include directories
include_directories(${SHARED_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

#set(LIB_SOURCES
#        ./include/cvhelper.h
#        ./src/cvhelper.cpp)

# add lib
add_library(libthesis ${LIB_SOURCES})

# add exec
add_executable(project_thesis main.cpp)

# link
target_link_libraries(project_thesis libthesis ${OpenCV_LIBS})
