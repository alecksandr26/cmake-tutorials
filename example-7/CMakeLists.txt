# To build the build system:
# `cd build/ && cmake ..`
# To compile the project:
# `cd build/ && make `

cmake_minimum_required(VERSION 3.5)

project(example VERSION 1.0.0
  DESCRIPTION "This is an example of how to use cmake"
  LANGUAGES CXX
)

# Define the standard compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the compilation flags
set(CPP_DEBUG_FLAGS -Wall -Wextra -pedantic -ggdb)

# Create a definitons
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)



add_subdirectory(${SRC_DIR}/)

# Firstly It is a good practice to enable the testing
# With cmake prepares to run with ctest
enable_testing()

add_subdirectory(${TEST_DIR})
