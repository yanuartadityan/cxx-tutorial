cmake_minimum_required(VERSION 3.0)

# project name
project(tutor_primes)

# set C++ compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11")

# all srcs
set(prime_files
    primes_1.cpp)

add_library(primes_tutor STATIC ${prime_files})

# add executable
add_executable(test_prime_1 test_primes_1.cpp)

# target link lib
target_link_libraries(test_prime_1 primes_tutor)
