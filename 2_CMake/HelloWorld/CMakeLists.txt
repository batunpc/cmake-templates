cmake_minimum_required(VERSION 3.0.0)
project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_NAME "Library")
set(EXECUTABLE_NAME "Executable")

add_subdirectory(config)
add_subdirectory(src)
add_subdirectory(app)

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
