#include "alds/graph/1_12_c_single_source_shortest_path_2.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(SingleSourceShortestPath2Test, Test1) {
  std::vector<std::vector<int>> input = {
    {0,3,2,3,3,1,1,2},
    {1,2,0,2,3,4},
    {2,3,0,3,3,1,4,1},
    {3,4,2,1,0,1,1,4,4,3},
    {4,2,2,1,3,3},
  };
  std::vector<std::vector<int>> result = alds::graph::solve(input);
  std::vector<std::vector<int>> expected = {
    {0,0},
    {1,2},
    {2,2},
    {3,1},
    {4,3},
  };
  EXPECT_EQ(result, expected);
};
