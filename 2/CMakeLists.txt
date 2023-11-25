
# To build the build system:
# `cd build/ && cmake ..`
# To compile the project:
# `cd build/ && make `

cmake_minimum_required(VERSION 3.5)

project(example VERSION 1.0.0
  DESCRIPTION "This is an example of how to use cmake"
  LANGUAGES CXX
)

# Create a definitons
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# You can make these changes and the compilation perfectly works
# add_executable(main
#   ${SRC_DIR}/main/main.cpp
# )

add_executable(main
  ${SRC_DIR}/main.cpp
)


# In CMake, the keywords PRIVATE, PUBLIC, and INTERFACE in target_include_directories
# are used to define the visibility of include paths in different contexts.

# PRIVATE means that this inclusion will only be available during the compilation of the target,
# specifically for the internal implementation of that target.

# PUBLIC means that this inclusion will be available both for the consumer of the target
# and during the compilation of the target itself. These paths are part of the public interface of the target
# and are shared with other targets depending on it.

# INTERFACE means that this inclusion will be available only to the consumer of the target,
# but not for the compilation of the target itself. These paths are useful to specify header dependencies
# necessary for consumers of the target, but not for its internal implementation.

target_include_directories(main
  PRIVATE
  ${INCLUDE_DIR}
)

