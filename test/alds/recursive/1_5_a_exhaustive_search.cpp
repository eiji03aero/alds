#include "alds/recursive/1_5_a_exhaustive_search.h"
#include "alds/util.h"

#include <vector>
#include <string>

#include "gtest/gtest.h"

TEST(ExhaustiveSearchTest, Test1) {
  std::vector<int> input { 1, 5, 7, 10, 21 };
  std::vector<int> values { 2, 4, 17, 8 };
  std::vector<std::string> result = alds::recursive::solve_exhaustive_search(input, values);
  std::vector<std::string> expected {"no", "no", "yes", "yes"};
  alds::expect_vector_eq(result, expected);
};
