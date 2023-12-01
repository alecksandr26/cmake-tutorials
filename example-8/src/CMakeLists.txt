project(${CMAKE_PROJECT_NAME})

# Adding the library to build
add_library(${CMAKE_PROJECT_NAME}
  SHARED regression.cpp cost_functions.cpp utils.cpp
)

# It is important to add the interface headers files
# To generate the exportation
target_include_directories(${CMAKE_PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${INCLUDE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Installing the library into the directory

# message(${CMAKE_INSTALL_LIBDIR})
# message(${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS ${CMAKE_PROJECT_NAME}
  EXPORT ${CMAKE_PROJECT_NAME}Targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)






