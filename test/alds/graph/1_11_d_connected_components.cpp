#include "alds/graph/1_11_d_connected_components.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(ConnectedComponentsTest, Test1) {
  int num_users = 10;
  std::vector<std::vector<int>> users = {
    {0,1},
    {0,2},
    {3,4},
    {5,7},
    {5,6},
    {6,7},
    {6,8},
    {7,8},
    {8,9},
  };
  std::vector<std::vector<int>> qs = {
    {0,1},
    {5,9},
    {1,3},
  };
  std::vector<bool> result = alds::graph::solve(
    num_users,
    users,
    qs
  );
  std::vector<bool> expected = {
    true,
    true,
    false
  };
  EXPECT_EQ(result, expected);
};
