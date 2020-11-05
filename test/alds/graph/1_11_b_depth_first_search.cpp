#include "alds/graph/1_11_b_depth_first_search.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(DepthFirstSearchTest, Test1) {
  std::vector<std::vector<int>> input = {
    {1,2,2,3},
    {2,2,3,4},
    {3,1,5},
    {4,1,6},
    {5,1,6},
    {6,0},
  };
  std::vector<std::vector<int>> result = alds::graph::solve(input);
  std::vector<std::vector<int>> expected = {
    {1,1,12},
    {2,2,11},
    {3,3,8},
    {4,9,10},
    {5,4,7},
    {6,5,6},
  };
  EXPECT_EQ(result, expected);
};
