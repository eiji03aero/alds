#include "alds/tree/1_7_d_reconstruction_of_the_tree.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(ReconstructionOfTheTreeTest, Test1) {
  std::vector<int> pre {1, 2, 3, 4, 5};
  std::vector<int> in {3, 2, 4, 1, 5};
  std::vector<int> result = alds::tree::solve(pre, in);
  std::vector<int> expected {3, 4, 2, 5, 1};
  EXPECT_EQ(result, expected);
};
