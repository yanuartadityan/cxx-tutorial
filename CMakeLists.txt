cmake_minimum_required(VERSION 3.10)
# root-level CMakeLists.txt, all project level initialization
# e.g. find_package(), include path, etc

project(cxx_tutor)

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