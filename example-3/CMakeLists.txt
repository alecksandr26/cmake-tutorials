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

# Define the compilation flags
set(CPP_DEBUG_FLAGS -Wall -Wextra -pedantic -ggdb)

# Create a definitons
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# You can chose STATIC or SHARED
add_library(my_math
  SHARED
  ${SRC_DIR}/vec.cpp
  ${SRC_DIR}/arithmetic.cpp
)

target_include_directories(my_math
  PUBLIC ${INCLUDE_DIR}
)

add_executable(main
  ${SRC_DIR}/main.cpp
)

target_link_libraries(main
  PRIVATE my_math
)

# Set compilation flags
target_compile_options(my_math
  PRIVATE ${CPP_DEBUG_FLAGS}
)

target_compile_options(main
  PRIVATE ${CPP_DEBUG_FLAGS}
)
