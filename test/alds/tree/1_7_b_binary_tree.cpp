#include "alds/tree/1_7_b_binary_tree.h"
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
  std::vector<alds::tree::NodeInfo> result = alds::tree::solve(input);
  std::vector<alds::tree::NodeInfo> expected {
    {0, -1, -1, 2, 0, 3, "root"},
    {1, 0, 4, 2, 1, 1, "internal"},
    {2, 1, 3, 0, 2, 0, "leaf"},
    {3, 1, 2, 0, 2, 0, "leaf"},
    {4, 0, 1, 2, 1, 2, "internal"},
    {5, 4, 8, 2, 2, 1, "internal"},
    {6, 5, 7, 0, 3, 0, "leaf"},
    {7, 5, 6, 0, 3, 0, "leaf"},
    {8, 4, 5, 0, 2, 0, "leaf"},
  };

  EXPECT_EQ(result.size(), expected.size());
  for (int i = 0; i < result.size(); i++) {
    EXPECT_EQ(result[i].id, expected[i].id);
    EXPECT_EQ(result[i].parent, expected[i].parent);
    EXPECT_EQ(result[i].sibling, expected[i].sibling);
    EXPECT_EQ(result[i].degree, expected[i].degree);
    EXPECT_EQ(result[i].depth, expected[i].depth);
    EXPECT_EQ(result[i].height, expected[i].height);
    EXPECT_EQ(result[i].type, expected[i].type);
  }
};
