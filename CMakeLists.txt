cmake_minimum_required(VERSION 3.10)
# root-level CMakeLists.txt, all project level initialization
# e.g. find_package(), include path, etc

# apple setting
if(APPLE)
    set(CMAKE_C_COMPILER "/usr/local/bin/gcc-12")
    set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-12")
endif()

project(cxx_tutor)

# packages
find_package(OpenCV REQUIRED)

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
add_subdirectory(tutor_boost_1)
add_subdirectory(tutor_strings)
add_subdirectory(tutor_hackerrank_solver)
add_subdirectory(tutor_kattis)

# projects
add_subdirectory(project_mrt)
add_subdirectory(project_thesis)
