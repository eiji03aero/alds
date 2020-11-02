#include "alds/tree/1_9_b_maximum_heap.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MaximumHeapTest, Test1) {
  std::vector<int> input {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  std::vector<int> result = alds::tree::solve(input);
  std::vector<int> expected {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  EXPECT_EQ(result, expected);
};
