#include "alds/dynamic_programming/1_10_c_longest_common_subsequence.h"
#include "alds/util.h"

#include "gtest/gtest.h"

TEST(LongestCommonSubsequenceTest, Test1) {
  std::vector<std::vector<std::string>> input = {
    {"abcbdab", "bdcaba"},
    {"abc", "abc"},
    {"abc", "bc"},
  };
  std::vector<int> result = alds::dynamic_programming::solve(input);
  std::vector<int> expected = { 4, 3, 2 };
  EXPECT_EQ(result, expected);
};
