
#ifndef CALCULATOR_H
#define CALCULATOR_H 1

#include "calculator/Value.h"

struct Calculator {
  static Value* add(Value const&, Value const&);
};

#endif
