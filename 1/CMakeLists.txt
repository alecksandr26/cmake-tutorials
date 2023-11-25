
# To build the build system:
# `cd build/ && cmake ..`
# To compile the project:
# `cd build/ && make `

cmake_minimum_required(VERSION 3.5)

project(example)

add_executable(helloworld
  "${CMAKE_CURRENT_SOURCE_DIR}/helloworld.cpp"
)

