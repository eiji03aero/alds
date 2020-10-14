#ifndef ALDS_SEARCH_1_4_A_LINEAER_SEARCH_H_INCLUDED
#define ALDS_SEARCH_1_4_A_LINEAER_SEARCH_H_INCLUDED

#include <vector>

namespace alds { namespace search {

int linear_search(std::vector<int> input, int n, int key) {
  int i = 0;
  input[n] = key;
  while (input[i] != key) i++;
  return i;
}

int search_intersection(std::vector<int> input, std::vector<int> values) {
  int sum = 0;
  for (auto &v : values) {
    if (linear_search(input, input.size(), v) < input.size()) sum++;
  }
  return sum;
}

} /* namespace search */
} /* namespace alds */

#endif /* ifndef ALDS_SEARCH_1_4_A_LINEAER_SEARCH_H_INCLUDED */
