#include "alds/shared.h"

#include <vector>

#include "gtest/gtest.h"

namespace alds {

void expect_vector_eq(std::vector<int> actual, std::vector<int> expected) {
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual.at(i), expected.at(i));
  }
}

void expect_vector_eq(std::vector<alds::Card> actual, std::vector<alds::Card> expected) {
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual.at(i).suit, expected.at(i).suit);
    EXPECT_EQ(actual.at(i).value, expected.at(i).value);
  }
}

} /* namespace alds */
