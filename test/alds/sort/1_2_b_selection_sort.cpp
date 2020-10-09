#include "alds/sort/1_2_b_selection_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(SelectionSort, Test1) {
  std::vector<int> input { 5, 6, 2, 4, 1, 3 };
  alds::sort::selection_sort(input);
  std::vector<int> expected { 1, 2, 3, 4, 5, 6 };
  alds::expect_vector_eq(input, expected);
};
