# @author Alexia Sánchez Cabrera                (alu0101482323@ull.edu.es)
# @date 28/11/2023
#
# @brief CMakeLists.txt for Caja program:
#          CMakeLists.txt defines the whole build.
#          CMake reads CMakeLists.txt sequentially.
#
#        Build process:
#          1.- cd <project_folder>
#          2.- mkdir build
#          3.- cd build
#          4.- CMake ..
#          5.- make

# Set especifications
cmake_minimum_required(VERSION 3.1)

project(caja
        VERSION 1.0
        DESCRIPTION ""
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake to put binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Tell CMake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIRECTORY}/src)

# Add executable "caja" to be built from source files (*.h, *.cc)
add_executable(caja
               src/tools.h
               src/tools.cc
               src/caja.h
               src/caja.cc
               src/caja_main.cc)

# Add expected compiler features to target
target_compile_features(caja PRIVATE cxx_std_17)

# Add compile options to target
target_compile_options(caja PRIVATE -Wall -Wpedantic)
