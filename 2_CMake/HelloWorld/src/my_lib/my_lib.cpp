#include "my_lib.h"
#include <iostream>

my_lib::MyClass::MyClass() {
  std::cout << "MyClass constructor" << std::endl;
}

unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}
