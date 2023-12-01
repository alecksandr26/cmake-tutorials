# To build the build system debug purpuse
# cmake . -B build/

# To build the project for release version
# cmake . -B build/ -DCMAKE_BUILD_TYPE=Release

# To build the project with a local install directory
# cmake . -B build/ -DCMAKE_INSTALL_PREFIX=./install/

# To compile the project:
# `cd build/ && make `

cmake_minimum_required(VERSION 3.5)

project(statistic VERSION 1.0.0
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
if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE})
else()
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG})
endif()


include(GNUInstallDirs)

# Create a definitons
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_subdirectory(${SRC_DIR}/)
add_subdirectory(${INCLUDE_DIR}/)

if(NOT DEFINED CMAKE_BUILD_TYPE OR NOT CMAKE_BUILD_TYPE STREQUAL "Release")
  enable_testing()

  add_subdirectory(${TEST_DIR}/)
endif()

# To uninstall the project
# xargs rm < install_manifest.txt
# https://stackoverflow.com/questions/41471620/cmake-support-make-uninstall

# Packaging the code
# https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Export%20Configuration.html

install(EXPORT ${CMAKE_PROJECT_NAME}Targets
  FILE ${CMAKE_PROJECT_NAME}Targets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}
)


# At this point, we have CMake properly packaging the target information that is required but we will
# still need to generate a MathFunctionsConfig.cmake so that the CMake find_package() command can
# find our project.

# To finish to configure
include(CMakePackageConfigHelpers)




# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}/cmake/
)

# Write the pacakge version file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
  VERSION ${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}
  COMPATIBILITY AnyNewerVersion
)


# Install the config files
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}
)

# If we want our project to also be used from a build directory we only have to add
export(EXPORT ${CMAKE_PROJECT_NAME}Targets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Targets.cmake
)

# After running make install into our system 



