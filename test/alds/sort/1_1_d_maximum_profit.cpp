#include "alds/sort/1_1_d_maximum_profit.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MaximumProfit, Test1) {
  std::vector<int> input { 5, 3, 1, 3, 4, 3 };
  int result = alds::sort::maximum_profit(input);
  int expected = 3;
  EXPECT_EQ(result, expected);
};

TEST(MaximumProfit, Test2) {
  std::vector<int> input { 4, 3, 2 };
  int result = alds::sort::maximum_profit(input);
  int expected = -1;
  EXPECT_EQ(result, expected);
};
