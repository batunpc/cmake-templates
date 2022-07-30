add_library(Library STATIC my_lib.cpp)
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
