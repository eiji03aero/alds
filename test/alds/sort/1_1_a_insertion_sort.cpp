#include "alds/sort/1_1_a_insertion_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(InsertionSortTest, Test1) {
  std::vector<int> input { 5, 2, 4, 6, 1, 3 };
  alds::sort::insertion_sort(input);
  std::vector<int> expected { 1, 2, 3, 4, 5, 6 };
  alds::expect_vector_eq(input, expected);
};
