#include "alds/search/1_4_c_dictionary.h"
#include "alds/util.h"

#include <vector>

#include "gtest/gtest.h"

TEST(DictionaryTest, Test1) {
  std::vector<std::vector<std::string>> input {
    {"insert", "AAA"},
    {"insert", "AAC"},
    {"find", "AAA"},
    {"find", "CCC"},
    {"insert", "CCC"},
    {"find", "CCC"},
  };
  std::vector<bool> result = alds::search::test_dictionary(input);
  std::vector<bool> expected {true, false, true};
  alds::expect_vector_eq(result, expected);
};
