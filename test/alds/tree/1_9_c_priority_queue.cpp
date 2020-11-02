#include "alds/tree/1_9_c_priority_queue.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(PriorityQueueTest, Test1) {
  std::vector<std::tuple<std::string, int>> input {
    {"insert", 8},
    {"insert", 2},
    {"extract", -1},
    {"insert", 10},
    {"insert", 11},
    {"extract", -1},
    {"extract", -1},
  };
  std::vector<int> result = alds::tree::solve2(input);
  std::vector<int> expected {8, 10, 11, 2};
  EXPECT_EQ(result, expected);
};
