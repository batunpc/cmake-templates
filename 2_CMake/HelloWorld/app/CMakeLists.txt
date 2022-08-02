add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
  ${LIBRARY_NAME}
  nlohmann_json
  fmt::fmt
  spdlog::spdlog_header_only
  ${CONAN_CXXOPTS}
)
