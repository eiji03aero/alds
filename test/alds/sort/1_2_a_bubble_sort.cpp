#include "alds/sort/1_2_a_bubble_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BubbleSortTest, Test1) {
  std::vector<int> input { 5, 3, 2, 4, 1 };
  alds::sort::bubble_sort(input);
  std::vector<int> expected { 1, 2, 3, 4, 5 };
  alds::expect_vector_eq(input, expected);
};
