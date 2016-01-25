
#include "gtest/gtest.h"

#include "calculator/Calculator.h"
#include "calculator/Value.h"

TEST(DivideTest, DivideTwoPositiveInts) {
  ValueInt v1(10);
  ValueInt v2(20);

  ASSERT_FALSE(Calculator::divide(v1, v2)->isInt());

  ASSERT_FLOAT_EQ(0.5, Calculator::divide(v1, v2)->toDouble());
}

TEST(DivideTest, DivideTwoNegativeInts) {
  ValueInt v1(-10);
  ValueInt v2(-25);

  ASSERT_FALSE(Calculator::divide(v1, v2)->isInt());
  ASSERT_FLOAT_EQ(0.4, Calculator::divide(v1, v2)->toDouble());
}

TEST(DivideTest, DivideTwoDoubles) {
  ValueDouble v1(3.0);
  ValueDouble v2(1.5);

  ASSERT_FALSE(Calculator::divide(v1, v2)->isInt());
  ASSERT_FLOAT_EQ(2., Calculator::divide(v1, v2)->toDouble());
}

TEST(DivideTest, DivisionByZero) {
  ValueInt v1(23);
  ValueInt v2(0);

  ASSERT_FALSE(Calculator::divide(v1, v2)->isInt());
  ASSERT_FLOAT_EQ(0., Calculator::divide(v1, v2)->toInt());
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
