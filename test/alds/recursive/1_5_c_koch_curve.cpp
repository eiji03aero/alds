#include "alds/recursive/1_5_c_koch_curve.h"
#include "alds/util.h"

#include <vector>
#include <iostream>

#include "gtest/gtest.h"

TEST(KochCurve, Test1) {
  std::vector<alds::recursive::Point> result =
    alds::recursive::calculate_koch(1, alds::recursive::Point{0, 0}, alds::recursive::Point{100, 0});
  std::vector<alds::recursive::Point> expected {
    alds::recursive::Point{0.0000, 0.0000},
    alds::recursive::Point{33.3333, 0.0000},
    alds::recursive::Point{50.0000, 28.8675},
    alds::recursive::Point{66.6666, 0.0000},
    alds::recursive::Point{100.0000, 0.0000},
  };
  alds::expect_vector_eq(result, expected);
};
