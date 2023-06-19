cmake_minimum_required(VERSION 3.10)
# root-level CMakeLists.txt, all project level initialization e.g.
# find_package(), include path, etc

# apple setting
if(APPLE)
  set(CMAKE_C_COMPILER "/usr/bin/clang")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

project(cxx_tutor)

# OpenCV Package
if(OPENCV)
  if(APPLE)
    set(OpenCV_DIR /usr/local/Cellar/opencv/4.7.0_2/lib/cmake/opencv4/)
    find_package(OpenCV HINTS /usr/local/Cellar/opencv/ REQUIRED)
  else()
    find_package(OpenCV REQUIRED)
  endif()

  option(OPENCV "Build OpencV Examples" ON)

  # OpenCV status
  message(STATUS "OpenCV library status:")
  message(STATUS " config: ${OpenCV_DIR}")
  message(STATUS " version: ${OpenCV_VERSION}")
  message(STATUS " libraries: ${OpenCV_LIBS}")
  message(STATUS " include path: ${OpenCV_INCLUDE_DIRS}")
  message(STATUS " link path: ${OpenCV_LINK_DIRS}")
endif(OPENCV)

# external submodules
add_subdirectory(external/fmt)
add_subdirectory(external/boost EXCLUDE_FROM_ALL)

# tutorials
add_subdirectory(tutor_utils)
add_subdirectory(tutor_pointer)
add_subdirectory(tutor_linked_list)
add_subdirectory(tutor_graphs)
add_subdirectory(tutor_sorting)
add_subdirectory(tutor_primes)
add_subdirectory(tutor_strings)
add_subdirectory(tutor_hackerrank_solver)
add_subdirectory(tutor_kattis)
add_subdirectory(tutor_boost_1)
add_subdirectory(tutor_template)
if(OPENCV)
  add_subdirectory(tutor_opencv)
  add_subdirectory(project_thesis)
endif(OPENCV)

# projects
add_subdirectory(project_mrt)
