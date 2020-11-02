#include "alds/tree/1_8_c_binary_search_tree_3.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BinarySearchTree3Test, Test1) {
  std::vector<std::tuple<std::string, int>> input {
    {"insert", 8},
    {"insert", 2},
    {"insert", 3},
    {"insert", 7},
    {"insert", 22},
    {"insert", 1},
    {"find", 1},
    {"find", 2},
    {"find", 3},
    {"find", 4},
    {"find", 5},
    {"find", 6},
    {"find", 7},
    {"find", 8},
    {"delete", 3},
    {"delete", 7},
  };
  std::tuple<std::vector<bool>, std::vector<std::vector<int>>>
    result = alds::tree::solve3(input);
  std::vector<bool> expectedbool {true, true, true, false, false, false, true, true};
  std::vector<std::vector<int>> expectedprint {
    {1, 2, 8, 22},
    {8, 2, 1, 22},
  };
  EXPECT_EQ(std::get<0>(result), expectedbool);
  EXPECT_EQ(std::get<1>(result), expectedprint);
};
