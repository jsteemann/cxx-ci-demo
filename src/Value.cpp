
#include <iostream>

#include "calculator/Value.h"

std::ostream& operator<<(std::ostream& stream, Value const& value) {
  stream << value.type() << "(" << value.toString() << ")";
  return stream;
}

