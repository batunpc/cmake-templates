#include "config.hpp"
#include "my_lib.h"
#include <fmt/format.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

int main() {

  std::cout << project_name << "\n"
            << project_version << "\n";
  my_lib::MyClass my_class;

  auto json_message = fmt::format("Using JSON Lib v{}.{}.{}\n",
                                  NLOHMANN_JSON_VERSION_MAJOR,
                                  NLOHMANN_JSON_VERSION_MINOR,
                                  NLOHMANN_JSON_VERSION_PATCH);
  spdlog::info(json_message);

  auto welcome_message = fmt::format("Welcome to {} {}\n", project_name, project_version);
  spdlog::info(welcome_message);

  return 0;
}
