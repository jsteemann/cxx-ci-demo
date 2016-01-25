#include <iostream>
#include <string>

#include "calculator/Calculator.h"
#include "calculator/Value.h"

int main (int, char*[]) {
  ValueInt value1(23);
  ValueInt value2(42);

  std::cout << "The result of " 
            << value1 << " + " << value2 << " is: "
            << *(Calculator::add(value1, value2)) << std::endl;
}
