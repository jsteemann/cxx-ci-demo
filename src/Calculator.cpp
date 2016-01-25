
#include "calculator/Calculator.h"

Value* Calculator::add(Value const& v1, Value const& v2) {
  if (v1.isInt() && v2.isInt()) {
    // TODO: check for overflow
    return new ValueInt(v1.toInt() + v2.toInt());
  }

  return new ValueDouble(v1.toDouble() + v2.toDouble());
}

Value* Calculator::divide(Value const& v1, Value const& v2) {
  if (v2.toDouble() == 0.0) {
    throw "division by zero";
  }
  // always cast to double, because result may not be integral
  return new ValueDouble(v1.toDouble() / v2.toDouble());
}

