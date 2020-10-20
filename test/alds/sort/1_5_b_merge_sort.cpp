#include "alds/sort/1_5_b_merge_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MergeSort, Test1) {
  std::vector<int> input { 8, 5, 9, 2, 6, 3, 7, 1, 10, 4 };
  alds::sort::merge_sort(input, 0, input.size());
  std::vector<int> expected { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  alds::expect_vector_eq(input, expected);
};
