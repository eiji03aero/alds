#include "alds/data/1_3_b_queue.h"
#include "alds/util.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

TEST(QueueTest, Test1) {
  std::vector<alds::data::ProcessDetail> input {
    {"p1", 150},
    {"p2", 80},
    {"p3", 200},
    {"p4", 350},
    {"p5", 20},
  };
  std::vector<alds::data::ProcessDetail> result = alds::data::emulate_round_robin_scheduling(100, input);
  std::vector<alds::data::ProcessDetail> expected {
    {"p2", 180},
    {"p5", 400},
    {"p1", 450},
    {"p3", 550},
    {"p4", 800},
  };

  EXPECT_EQ(result.size(), expected.size());
  for (int i = 0; i < result.size(); i++) {
    EXPECT_EQ(result[i].name, expected[i].name);
    EXPECT_EQ(result[i].value, expected[i].value);
  }
};
