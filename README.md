## Overview

This is a small template project to understand Modern CMake (>3.10.x) quickly. For this, I've created multiple tututorial as individual project directories. Inside each of the tutor, there are few source (.cpp) files and header (.h) as well. 

## Steps

1. Clone in your local workspace.
2. Go into the 'cxx-tutorial' directory.
3. Create a folder 'build'. Do `mkdir build`.
4. Compile the CMake. Do `cmake .. -G "Unix Makefiles"`.
5. Build. Do `make`.

For specific builds, e.g., to different IDEs, please refer to the CMake tutorials. For MacOS Xcode, this would be `cmake .. -G Xcode`. Then you can load the .project file to the Xcode directly.

## How it Works?

In each tutorials, there is at least one test file. This file is where the executable main function starts. In the entire project, there are multiple test files located in different projects. Some of the projects also require dependancies from common lib, located in 'tutor_utils'.

## Dependancies

This project uses mostly C++ STL libraries. Some of the project define specific CXX flags to use C++11 standard. You will find it easy to check their CMakeLists.txt file.

## Next

Will keep adding tutorials, maybe link it with either of these libraries:

* OpenCV
* Boost
* Eigen
* Ceres-solver
* etc

## Contact

Please contact me at yanuart.adityan[at]gmail.com
