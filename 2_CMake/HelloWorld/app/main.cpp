#include "config.hpp"
#include "my_lib.h"
#include <iostream>

int main() {

  std::cout << project_name << "\n"
            << project_version << "\n";
  my_lib::MyClass my_class;

  // my_class.printHelloWorld();

  return 0;
}
