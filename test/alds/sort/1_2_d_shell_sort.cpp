#include "alds/sort/1_2_d_shell_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(ShellSort, Test1) {
  std::vector<int> input { 4, 8, 9, 1, 10, 6, 2, 5, 3, 7 };
  alds::sort::shell_sort(input);
  std::vector<int> expected { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  alds::expect_vector_eq(input, expected);
};
