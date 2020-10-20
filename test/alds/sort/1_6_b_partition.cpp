#include "alds/sort/1_6_b_partition.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MergeSort, Test1) {
  std::vector<int> input { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };
  int result_idx = alds::sort::partition(input, 0, input.size() - 1);
  std::vector<int> expected { 9, 5, 8, 7, 4, 2, 6, 11, 21, 13, 19, 12 };
  int expected_idx = 7;
  alds::expect_vector_eq(input, expected);
  EXPECT_EQ(result_idx, expected_idx);
};
