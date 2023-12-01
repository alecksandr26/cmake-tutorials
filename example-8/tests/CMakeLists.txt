project(${CMAKE_PROJECT_NAME})

# Testing with CTest and GoogleTest

# First import the google test library

# include FetchContent Module
include(FetchContent)

# Fech from github the google test framework
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# TO AVOID INSTALLING GTEST
# https://github.com/google/googletest/issues/3486
option(INSTALL_GTEST "Enable installation of googletest." OFF)

FetchContent_MakeAvailable(googletest)

# Make the google test library availabel
add_library(GTest::GTest INTERFACE IMPORTED)

# Secondly build the executable binaries
add_executable(test_mse
  test_mse.cpp
)

add_executable(test_utils
  test_utils.cpp
)

add_executable(test_regression
  test_regression.cpp
)

# Link google test library to the testcase
# with gtest_main we actually are adding a runner functin
target_link_libraries(test_mse
  PRIVATE
  statistic
  GTest::gtest_main
)

target_link_libraries(test_utils
  PRIVATE
  statistic
  GTest::gtest_main
)

target_link_libraries(test_regression
  PRIVATE
  statistic
  GTest::gtest_main
)

# Set compilation flags
target_compile_options(test_mse
  PRIVATE ${CPP_DEBUG_FLAGS}
)

target_compile_options(test_utils
  PRIVATE ${CPP_DEBUG_FLAGS}
)

target_compile_options(test_regression
  PRIVATE ${CPP_DEBUG_FLAGS}
)

include(GoogleTest)

# # Here we add the tests to google tests
gtest_discover_tests(test_mse)
gtest_discover_tests(test_utils)
gtest_discover_tests(test_regression)


