#include "alds/data/1_3_a_stack.h"
#include "alds/util.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

TEST(StackTest, Test1) {
  std::vector<std::string> input { "1", "2", "+", "3", "4", "-", "*" };
  int result { alds::data::calculate_reverse_polish_notation(input) };
  int expected { -3 };
  EXPECT_EQ(result, expected);
};
