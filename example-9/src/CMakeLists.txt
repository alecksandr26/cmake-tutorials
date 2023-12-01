
# Add the library
find_package(statistic REQUIRED)

add_executable(main
  main.cpp
)

# Link the library to the source file
target_link_libraries(main
  PRIVATE statistic
)

