#include "alds/tree/1_7_a_rooted_trees.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(RootedTreesTest, Test1) {
  std::vector<alds::tree::NodeInput> input {
    {0, {1,4,10}},
    {1, {2,3}},
    {2, {}},
    {3, {}},
    {4, {5,6,7}},
    {5, {}},
    {6, {}},
    {7, {8,9}},
    {8, {}},
    {9, {}},
    {10, {11, 12}},
    {11, {}},
    {12, {}},
  };
  std::vector<alds::tree::NodeInfo> result = alds::tree::solve(input);
  std::vector<alds::tree::NodeInfo> expected {
    {0, -1, 0, "root", {1,4,10}},
    {1, 0, 1, "internal", {2,3}},
    {2, 1, 2, "leaf", {}},
    {3, 1, 2, "leaf", {}},
    {4, 0, 1, "internal", {5,6,7}},
    {5, 4, 2, "leaf", {}},
    {6, 4, 2, "leaf", {}},
    {7, 4, 2, "internal", {8,9}},
    {8, 7, 3, "leaf", {}},
    {9, 7, 3, "leaf", {}},
    {10, 0, 1, "internal", {11, 12}},
    {11, 10, 2, "leaf", {}},
    {12, 10, 2, "leaf", {}},
  };

  EXPECT_EQ(result.size(), expected.size());
  for (int i = 0; i < result.size(); i++) {
    EXPECT_EQ(result[i].id, expected[i].id);
    EXPECT_EQ(result[i].parent, expected[i].parent);
    EXPECT_EQ(result[i].depth, expected[i].depth);
    EXPECT_EQ(result[i].type, expected[i].type);
    EXPECT_EQ(result[i].children, expected[i].children);
  }
};
