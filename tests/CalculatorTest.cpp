
#include "gtest/gtest.h"

#include "calculator/Calculator.h"
#include "calculator/Value.h"

TEST(CalculatorTest, AddTwoPositiveInts) {
  ValueInt v1(10);
  ValueInt v2(20);

  ASSERT_TRUE(Calculator::add(v1, v2)->isInt());
  ASSERT_EQ(30, Calculator::add(v1, v2)->toInt());
}

TEST(CalculatorTest, AddTwoNegativeInts) {
  ValueInt v1(-10);
  ValueInt v2(-42);

  ASSERT_TRUE(Calculator::add(v1, v2)->isInt());
  ASSERT_EQ(-52, Calculator::add(v1, v2)->toInt());
}

TEST(CalculatorTest, AddZeroToValue) {
  ValueInt v1(25);
  ValueInt v2(0);

  ASSERT_TRUE(Calculator::add(v1, v2)->isInt());
  ASSERT_EQ(25, Calculator::add(v1, v2)->toInt());
}

TEST(CalculatorTest, AddValueToZero) {
  ValueInt v1(0);
  ValueInt v2(43);

  ASSERT_TRUE(Calculator::add(v1, v2)->isInt());
  ASSERT_EQ(43, Calculator::add(v1, v2)->toInt());
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
