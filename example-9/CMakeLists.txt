# To build the build system debug purpuse
# cmake . -B build/

# To build the project for release version
# cmake . -B build/ -DCMAKE_BUILD_TYPE=Release

# To build the project with a local install directory
# cmake . -B build/ -DCMAKE_INSTALL_PREFIX=./install/

# To compile the project:
# `cd build/ && make `

cmake_minimum_required(VERSION 3.5)

project(example VERSION 1.0.0
  DESCRIPTION "This is a simple statistically library for c++"
  LANGUAGES CXX
)

# Define the standard compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the compilation flags
if(UNIX)
  set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -pedantic -ggdb")
  set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
else()
  # Flags for Windows with MSVC
  set(CMAKE_CXX_FLAGS_DEBUG "/W3 /Od /Zi /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
endif()

# In the case the build a release version of the project
if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE EQUAL Release)
  message("Building a the release version")
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE})
else()
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG})
endif()

# Create a definitons
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${SRC_DIR}/)


