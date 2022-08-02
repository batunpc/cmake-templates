#include <iostream>

#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <cxxopts.hpp>

#include "config.hpp"
#include "my_lib.h"

int main(int argc, char *argv[]) {

  std::cout << project_name << "\n"
            << project_version << "\n";
  my_lib::MyClass my_class;

  auto json_message =
      fmt::format("Using JSON Lib v{}.{}.{}\n",
                  NLOHMANN_JSON_VERSION_MAJOR,
                  NLOHMANN_JSON_VERSION_MINOR,
                  NLOHMANN_JSON_VERSION_PATCH);
  spdlog::info(json_message);

  auto welcome_message = fmt::format("Welcome to {} {}\n", project_name, project_version);
  spdlog::info(welcome_message);

  cxxopts::Options options(project_name.data());
  options.add_options("arguments")("h,help", "Print usage");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  return 0;
}
