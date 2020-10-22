#include "alds/sort/1_6_a_counting_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(CountingSort, Test1) {
  std::vector<int> input { 2, 5, 1, 3, 2, 3, 0 };
  std::vector<int> result = alds::sort::counting_sort(input);
  std::vector<int> expected { 0, 1, 2, 2, 3, 3, 5 };
  alds::expect_vector_eq(result, expected);
};
