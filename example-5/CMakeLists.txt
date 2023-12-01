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
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# You can chose STATIC or SHARED
add_library(my_math
  SHARED
  ${SRC_DIR}/vec.cpp
  ${SRC_DIR}/arithmetic.cpp
)

target_include_directories(my_math
  PUBLIC ${INCLUDE_DIR}
)

# Set compilation flags
target_compile_options(my_math
  PRIVATE ${CPP_DEBUG_FLAGS}
)

# Testing with CTest

# Firstly It is a good practice to enable the testing
# With cmake prepares to run with ctest
enable_testing()

# Secondly build the executable binaries

add_executable(test_my_math
  ${TEST_DIR}/test_my_math.cpp
)

target_link_libraries(test_my_math
  PRIVATE my_math
)

# Set compilation flags
target_compile_options(test_my_math
  PRIVATE ${CPP_DEBUG_FLAGS}
)

# With addt_test to run by ctest

# add_test(NAME <name> COMMAND <command> [<arg>...]
#          [CONFIGURATIONS <config>...]
#          [WORKING_DIRECTORY <dir>]
#          [COMMAND_EXPAND_LISTS])
# <name>: A descriptive name for your test.
# <command>: The command or executable to run for the test.
# <arg>...: Optional arguments for the command.
# CONFIGURATIONS: Optional. Restrict execution of the test only to the named configurations.
# WORKING_DIRECTORY: Optional. Set the working directory in which to execute the test.
# COMMAND_EXPAND_LISTS: Optional. Lists in COMMAND arguments will be expanded.

add_test(
  NAME test_my_math
  COMMAND ./test_my_math
)

