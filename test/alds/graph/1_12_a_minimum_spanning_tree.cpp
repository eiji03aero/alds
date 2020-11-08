#include "alds/graph/1_12_a_minimum_spanning_tree.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(MinimumSpanningTreeTest, Test1) {
  std::vector<std::vector<int>> input = {
    {-1,2,3,1,-1},
    {2,-1,-1,4,-1},
    {3,-1,-1,1,1},
    {1,4,1,-1,3},
    {-1,-1,1,3,-1},
  };
  int result = alds::graph::solve(input);
  int expected = 5;
  EXPECT_EQ(result, expected);
};
