#include "alds/search/1_4_d_allocation.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(AllocationTest, Test1) {
  std::vector<int> loads { 8, 1, 7, 3, 9 };
  int num_tracks = 3;
  int result = alds::search::solve(loads, num_tracks);
  int expected = 10;
  EXPECT_EQ(result, expected);
};
