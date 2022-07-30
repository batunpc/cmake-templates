# Basic structure for CMAKE

One of the notable best practice for Cmake project is to create `CMakeLists.txt` file in every single directory you have in the project. This is because when the project gets too complicated Cmake can keep track of the files no matter how deep they are in.

```text
📦Basic project \
 ┣ 📂app\
 ┃ ┣ 📜CMakeLists.txt\
 ┃ ┗ 📜main.cpp\
 ┣ 📂src\
 ┃ ┣ 📂my_lib\
 ┃ ┃ ┣ 📜CMakeLists.txt\
 ┃ ┃ ┣ 📜my_lib.cpp\
 ┃ ┃ ┗ 📜my_lib.h\
 ┃ ┗ 📜CMakeLists.txt\
 ┣ 📜CMakeLists.txt\
 ┗ 📜README.md
```

## Couple things to note

- If you are having subdirectories they need to be explicitly stated in the root CMakeLists.txt file.

- When you have the src subdirectory, you need to specify the library directory in the CMakeLists.txt file where src is present.

- Those subdirectories, in our case libraries, need to be added with source files and know where are the corresponding header files.
This can be achieved by doing the following in the my_lib directory:

```cmake
add_library(Library STATIC my_lib.cpp)
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

- After having the library installed, they need to be linked to the executable we have in the app directory.

```cmake
add_executable(Executable main.cpp)
target_link_libraries(Executable PUBLIC Library)
```

❗ In the root ```CMakeLists.txt``` file,  make sure the libraries added as subdirectory beforehand the app directory.
