#include "alds/sort/1_2_c_stable_sort.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(StableSort, Test1) {
  std::vector<alds::Card> cards {
    alds::Card { 'H', 4 },
    alds::Card { 'C', 9 },
    alds::Card { 'S', 4 },
    alds::Card { 'D', 2 },
    alds::Card { 'C', 3 },
  };

  std::vector<alds::Card> input_bubble(cards);
  alds::sort::bubble_sort(input_bubble);
  std::vector<alds::Card> expected_bubble {
    alds::Card { 'D', 2 },
    alds::Card { 'C', 3 },
    alds::Card { 'H', 4 },
    alds::Card { 'S', 4 },
    alds::Card { 'C', 9 },
  };

  alds::expect_vector_eq(input_bubble, expected_bubble);

  std::vector<alds::Card> input_selection(cards);
  alds::sort::selection_sort(input_selection);
  std::vector<alds::Card> expected_selection {
    alds::Card { 'D', 2 },
    alds::Card { 'C', 3 },
    alds::Card { 'S', 4 },
    alds::Card { 'H', 4 },
    alds::Card { 'C', 9 },
  };

  alds::expect_vector_eq(input_selection, expected_selection);
  alds::sort::is_stable(input_bubble, input_selection);
};
