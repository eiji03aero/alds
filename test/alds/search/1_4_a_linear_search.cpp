#include "alds/search/1_4_a_linear_search.h"

#include <vector>

#include "gtest/gtest.h"

TEST(LinearSearchTest, Test1) {
  std::vector<int> input { 1, 2, 3, 4, 5 };
  std::vector<int> values { 3, 4, 1 };
  int result = alds::search::search_intersection(input, values);
  int expected { 3 };
  EXPECT_EQ(result, expected);
};
