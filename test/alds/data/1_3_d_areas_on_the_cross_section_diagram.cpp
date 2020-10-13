#include "alds/data/1_3_d_areas_on_the_cross_section_diagram.h"
#include "alds/util.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

void expect_results_equal(alds::data::DiagramResult &actual, alds::data::DiagramResult &expected) {
  EXPECT_EQ(actual.total, expected.total);
  EXPECT_EQ(actual.values, expected.values);
}

TEST(AreasOnTheCrossSectionDiagramTest, Test1) {
  // \/
  std::vector<std::string> input {
    "\\",
    "/",
  };
  alds::data::DiagramResult result = alds::data::calculate_ponds(input);
  alds::data::DiagramResult expected {
    1,
    {1, 1}
  };
  expect_results_equal(result, expected);
};

TEST(AreasOnTheCrossSectionDiagramTest, Test2) {
  // \  _/
  //  \/
  std::vector<std::string> input {
    "\\",
    "\\",
    "/",
    "_",
    "/",
  };
  alds::data::DiagramResult result = alds::data::calculate_ponds(input);
  alds::data::DiagramResult expected {
    5,
    {1, 5}
  };
  expect_results_equal(result, expected);
};

TEST(AreasOnTheCrossSectionDiagramTest, Test3) {
  //     /\_/\/\           __
  // \  /       \         /  \
  //  \/         \  _/\  /    \
  //              \/   \/      \_
  //                             \  _  _/\
  //                              \/ \/
  std::vector<std::string> input {
    "\\", "\\",
    "/", "/", "/",
    "\\", "_", "/", "\\", "/",
    "\\", "\\", "\\", "\\",
    "/", "_", "/", "\\", "\\",
    "/", "/", "/",
    "_", "_",
    "\\", "\\", "\\", "_", "\\", "\\",
    "/", "_", "\\",
    "/", "_", "/", "\\",
  };
  alds::data::DiagramResult result = alds::data::calculate_ponds(input);
  alds::data::DiagramResult expected {
    35,
    {5, 4, 2, 1, 19, 9}
  };
  expect_results_equal(result, expected);
};
