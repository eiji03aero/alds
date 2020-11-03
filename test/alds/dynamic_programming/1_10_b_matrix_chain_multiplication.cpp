#include "alds/dynamic_programming/1_10_b_matrix_chain_multiplication.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(MatrixChainMultiplicationTest, Test1) {
  std::vector<std::vector<int>> input = {
    {30, 35},
    {35, 15},
    {15, 5},
    {5, 10},
    {10, 20},
    {20, 25},
  };
  int result = alds::dynamic_programming::solve(input);
  int expected = { 15125 };
  EXPECT_EQ(result, expected);
};
