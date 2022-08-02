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

<hr>

## Using GitSubmodules for CMake external libraries
- 1)  Use this below command conventiant to add external libraries to your project as submodule. The below library is just an example for the demonstration. </br></br>
  

  ```git
  git submodule add https://github.com/nlohmann/json external/json
  ```
- 2)  Then create cmake folder in your project. ``mkdir cmake`` (we will add cmake functions)
- 3)  Then create ``AddGitSubmodule.cmake`` file in the cmake folder.
- 4)  Then add the following code to the ``AddGitSubmodule.cmake`` file:

```cmake
function(add_git_submodule dirname)
  find_package(Git REQUIRED)

  if(NOT EXISTS ${dirname}/CMakeLists.txt)
    execute_process(COMMAND ${GIT_EXECUTABLE}
      submodule update --init --recursive -- ${dirname}
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
  endif()

  add_subdirectory(${dirname})
endfunction()

```
- 5) In the main ```CMakeLists.txt``` file, add the following code to finally call the function we have writting abobe:


```cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(AddGitSubmodule) #includes CMake module files
add_git_submodule("external/json") #function call
```

- 6) We can link this external library we finally have added with our executable. Navigate to your app ```CMakeLists.txt``` file and add the following code:

```cmake
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
  ${LIBRARY_NAME}
  nlohmann_json #Linked library name 
)
```
