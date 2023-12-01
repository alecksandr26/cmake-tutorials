project(${CMAKE_PROJECT_NAME})

add_executable(main
  main.cpp
)

add_subdirectory(${SRC_DIR}/my_math/)

target_link_libraries(main
  PRIVATE my_math
)

target_compile_options(main
  PRIVATE ${CPP_DEBUG_FLAGS}
)




