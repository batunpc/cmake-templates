cmake_minimum_required(VERSION 3.0.0)
project(helloworld VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_NAME "Library")
set(EXECUTABLE_NAME "Executable")

option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)

add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})

if(COMPILE_EXECUTABLE)
  add_subdirectory(app)
else()
  message("Without executable compiling")
endif()

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
