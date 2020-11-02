#include "alds/tree/1_8_b_binary_search_tree_2.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BinarySearchTree2Test, Test1) {
  std::vector<std::tuple<std::string, int>> input {
    {"insert", 30},
    {"insert", 88},
    {"insert", 12},
    {"insert", 1},
    {"insert", 20},
    {"find", 12},
    {"insert", 17},
    {"insert", 25},
    {"find", 16},
  };
  std::tuple<std::vector<bool>, std::vector<std::vector<int>>>
    result = alds::tree::solve2(input);
  std::vector<bool> expectedbool {true, false};
  std::vector<std::vector<int>> expectedprint {
    {1, 12, 17, 20, 25, 30, 88},
    {30, 12, 1, 20, 17, 25, 88},
  };
  EXPECT_EQ(std::get<0>(result), expectedbool);
  EXPECT_EQ(std::get<1>(result), expectedprint);
};
