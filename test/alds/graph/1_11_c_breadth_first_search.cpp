#include "alds/graph/1_11_c_breadth_first_search.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(BreadthFirstSearchTest, Test1) {
  std::vector<std::vector<int>> input = {
    {1,2,2,4},
    {2,1,4},
    {3,0},
    {4,1,3},
  };
  std::vector<std::vector<int>> result = alds::graph::solve(input);
  std::vector<std::vector<int>> expected = {
    {1,0},
    {2,1},
    {3,2},
    {4,1},
  };
  EXPECT_EQ(result, expected);
};
