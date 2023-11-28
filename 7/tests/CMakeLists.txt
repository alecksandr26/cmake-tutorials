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

FetchContent_MakeAvailable(googletest)

# Make the google test library availabel
add_library(GTest::GTest INTERFACE IMPORTED)

# Secondly build the executable binaries
add_executable(test_my_math
  test_my_math.cpp
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

# # Here we add the tests to google tests
gtest_discover_tests(test_my_math)


