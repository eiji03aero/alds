#include "alds/sort/1_6_c_quick_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(QuickSort, Test1) {
  std::vector<alds::Card> input {
    {'D', 3},
    {'H', 2},
    {'D', 1},
    {'S', 3},
    {'D', 2},
    {'C', 1},
  };
  alds::sort::quick_sort(input, 0, input.size() - 1);
  std::vector<alds::Card> expected {
    {'D', 1},
    {'C', 1},
    {'D', 2},
    {'H', 2},
    {'D', 3},
    {'S', 3},
  };
  alds::expect_vector_eq(input, expected);
};
