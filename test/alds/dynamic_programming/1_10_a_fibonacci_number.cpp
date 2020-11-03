#include "alds/dynamic_programming/1_10_a_fibonacci_number.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(FibonacciNumberTest, Test1) {
  int input = 3;
  int result = alds::dynamic_programming::solve(input);
  int expected = 3;
  EXPECT_EQ(result, expected);
};
