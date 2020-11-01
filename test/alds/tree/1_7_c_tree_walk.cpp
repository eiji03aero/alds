#include "alds/tree/1_7_c_tree_walk.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BinaryTreeTest, Test1) {
  std::vector<alds::tree::NodeInput> input {
    {0, 1, 4},
    {1, 2, 3},
    {2, -1, -1},
    {3, -1, -1},
    {4, 5, 8},
    {5, 6, 7},
    {6, -1, -1},
    {7, -1, -1},
    {8, -1, -1},
  };
  std::vector<std::vector<int>> result = alds::tree::solve(input);
  std::vector<std::vector<int>> expected {
    {0, 1, 2, 3, 4, 5, 6, 7, 8},
    {2, 1, 3, 0, 6, 5, 7, 4, 8},
    {2, 3, 1, 6, 7, 5, 8, 4, 0},
  };

  EXPECT_EQ(result, expected);
};
