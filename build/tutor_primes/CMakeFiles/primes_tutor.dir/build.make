# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mirkwood/Workspace/HPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mirkwood/Workspace/HPC/build

# Include any dependencies generated for this target.
include tutor_primes/CMakeFiles/primes_tutor.dir/depend.make

# Include the progress variables for this target.
include tutor_primes/CMakeFiles/primes_tutor.dir/progress.make

# Include the compile flags for this target's objects.
include tutor_primes/CMakeFiles/primes_tutor.dir/flags.make

tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.o: tutor_primes/CMakeFiles/primes_tutor.dir/flags.make
tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.o: ../tutor_primes/primes_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirkwood/Workspace/HPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.o"
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/primes_tutor.dir/primes_1.cpp.o -c /home/mirkwood/Workspace/HPC/tutor_primes/primes_1.cpp

tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/primes_tutor.dir/primes_1.cpp.i"
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirkwood/Workspace/HPC/tutor_primes/primes_1.cpp > CMakeFiles/primes_tutor.dir/primes_1.cpp.i

tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/primes_tutor.dir/primes_1.cpp.s"
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirkwood/Workspace/HPC/tutor_primes/primes_1.cpp -o CMakeFiles/primes_tutor.dir/primes_1.cpp.s

# Object files for target primes_tutor
primes_tutor_OBJECTS = \
"CMakeFiles/primes_tutor.dir/primes_1.cpp.o"

# External object files for target primes_tutor
primes_tutor_EXTERNAL_OBJECTS =

tutor_primes/libprimes_tutor.a: tutor_primes/CMakeFiles/primes_tutor.dir/primes_1.cpp.o
tutor_primes/libprimes_tutor.a: tutor_primes/CMakeFiles/primes_tutor.dir/build.make
tutor_primes/libprimes_tutor.a: tutor_primes/CMakeFiles/primes_tutor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mirkwood/Workspace/HPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libprimes_tutor.a"
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && $(CMAKE_COMMAND) -P CMakeFiles/primes_tutor.dir/cmake_clean_target.cmake
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/primes_tutor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutor_primes/CMakeFiles/primes_tutor.dir/build: tutor_primes/libprimes_tutor.a

.PHONY : tutor_primes/CMakeFiles/primes_tutor.dir/build

tutor_primes/CMakeFiles/primes_tutor.dir/clean:
	cd /home/mirkwood/Workspace/HPC/build/tutor_primes && $(CMAKE_COMMAND) -P CMakeFiles/primes_tutor.dir/cmake_clean.cmake
.PHONY : tutor_primes/CMakeFiles/primes_tutor.dir/clean

tutor_primes/CMakeFiles/primes_tutor.dir/depend:
	cd /home/mirkwood/Workspace/HPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mirkwood/Workspace/HPC /home/mirkwood/Workspace/HPC/tutor_primes /home/mirkwood/Workspace/HPC/build /home/mirkwood/Workspace/HPC/build/tutor_primes /home/mirkwood/Workspace/HPC/build/tutor_primes/CMakeFiles/primes_tutor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutor_primes/CMakeFiles/primes_tutor.dir/depend

