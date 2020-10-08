#include <vector>

#include "gtest/gtest.h"

namespace alds {

void expect_vector_eq(std::vector<int> actual, std::vector<int> expected) {
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual.at(i), expected.at(i));
  }
}

} /* namespace alds */
