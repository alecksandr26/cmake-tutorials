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

# Testing with CTest and GoogleTest

# Firstly It is a good practice to enable the testing
# With cmake prepares to run with ctest
enable_testing()


# First import the google test library

# include FetchContent Module
include(FetchContent)

# Fech from github the google test framework
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

# Make the google test library availabel
add_library(GTest::GTest INTERFACE IMPORTED)

# Secondly build the executable binaries
add_executable(test_my_math
  ${TEST_DIR}/test_my_math.cpp
)

# Link google test library to the testcase
# with gtest_main we actually are adding a runner functin
target_link_libraries(test_my_math
  PRIVATE
  GTest::gtest_main
  my_math
)

# Set compilation flags
target_compile_options(test_my_math
  PRIVATE ${CPP_DEBUG_FLAGS}
)

include(GoogleTest)

# Here we add the tests to google tests
gtest_discover_tests(test_my_math)

