#include "alds/sort/1_6_d_minimum_cost_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MinimumCostSort, Test1) {
  std::vector<int> input { 1, 5, 3, 4, 2 };
  int result = alds::sort::solve(input);
  int expected = 7;
  EXPECT_EQ(result, expected);
};

TEST(MinimumCostSort, Test2) {
  std::vector<int> input { 2, 1, 8, 10, 7, 9 };
  int result = alds::sort::solve(input);
  int expected = 49;
  EXPECT_EQ(result, expected);
};
