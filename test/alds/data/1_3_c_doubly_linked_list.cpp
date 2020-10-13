#include "alds/data/1_3_c_doubly_linked_list.h"
#include "alds/util.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

TEST(DoublyLinkedListTest, Test1) {
  std::vector<alds::data::ListCommand> input {
    {"insert", 6},
    {"insert", 5},
    {"insert", 4},
    {"insert", 3},
    {"delete", 3},
    {"insert", 2},
    {"delete", 5},
    {"insert", 1},
    {"delete", 6},
  };
  std::vector<int> result = alds::data::execute_list_commands(input);
  std::vector<int> expected {
    1,
    2,
    4,
  };
  alds::expect_vector_eq(result, expected);
};
