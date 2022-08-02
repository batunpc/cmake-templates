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
