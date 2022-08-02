cmake_minimum_required(VERSION 3.0.0)
project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_NAME "Library")
set(EXECUTABLE_NAME "Executable")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(AddGitSubmodule)
include(FetchContent)

add_git_submodule("external/json")

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 9.0.0
)
FetchContent_MakeAvailable(fmt)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.10.0
)
FetchContent_MakeAvailable(spdlog)
add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
