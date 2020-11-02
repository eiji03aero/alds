#include "alds/tree/1_9_a_complete_binary_tree.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(CompleteBinaryTreeTest, Test1) {
  std::vector<int> input {7, 8, 1, 2, 3};
  std::vector<alds::tree::NodeInfo> result = alds::tree::solve(input);
  std::vector<alds::tree::NodeInfo> expected {
    {1, 7, -1, 8, 1},
    {2, 8, 7, 2, 3},
    {3, 1, 7, -1, -1},
    {4, 2, 8, -1, -1},
    {5, 3, 8, -1, -1},
  };
  EXPECT_EQ(result.size(), expected.size());
  for (int i = 0; i < result.size(); i++) {
    EXPECT_EQ(result[i].id, expected[i].id);
    EXPECT_EQ(result[i].key, expected[i].key);
    EXPECT_EQ(result[i].parent, expected[i].parent);
    EXPECT_EQ(result[i].left, expected[i].left);
    EXPECT_EQ(result[i].right, expected[i].right);
  }
};
