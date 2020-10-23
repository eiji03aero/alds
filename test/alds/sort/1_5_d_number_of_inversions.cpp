#include "alds/sort/1_5_d_number_of_inversions.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(NumberOfInversionsTest, Test1) {
  std::vector<int> input { 3, 5, 2, 1, 4 };
  alds::sort::llong result = alds::sort::merge_sort(input, 0, input.size());
  alds::sort::llong expected = 6;
  EXPECT_EQ(result, expected);
};
