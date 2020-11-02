#include "alds/tree/1_8_a_binary_search_tree_1.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BinarySearchTree1Test, Test1) {
  std::vector<int> input {30, 88, 12, 1, 20, 17, 25};
  std::vector<std::vector<int>> result = alds::tree::solve(input);
  std::vector<std::vector<int>> expected {
    {1, 12, 17, 20, 25, 30, 88},
    {30, 12, 1, 20, 17, 25, 88},
  };
  EXPECT_EQ(result, expected);
};
