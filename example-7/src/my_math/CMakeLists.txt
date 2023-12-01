project(${CMAKE_PROJECT_NAME})

add_library(my_math
  SHARED
  my_math.cpp
)

# message("Current list dir: ${CMAKE_CURRENT_LIST_DIR}/'")

# CMAKE_CURRENT_LIST_DIR -> Returns the current directory
target_include_directories(my_math
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/
)

target_compile_options(my_math
  PRIVATE ${CPP_DEBUG_FLAGS}
)
