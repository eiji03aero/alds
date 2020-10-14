#ifndef ALDS_SEARCH_1_4_B_BINARY_SEARCH_H_INCLUDED
#define ALDS_SEARCH_1_4_B_BINARY_SEARCH_H_INCLUDED

#include <vector>

namespace alds { namespace search {

int binary_search(std::vector<int> input, int key) {
  int left = 0;
  int right = input.size();
  while (left < right) {
    int mid = (left + right) / 2;
    if (input[mid] == key) {
      return mid;
    }
    else if (key < input[mid]) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
  return input.size();
}

int search_intersection(std::vector<int> input, std::vector<int> values) {
  int sum = 0;
  for (auto &v : values) {
    if (binary_search(input, v) < input.size()) sum++;
  }
  return sum;
}

} /* namespace search */
} /* namespace alds */

#endif /* ifndef ALDS_SEARCH_1_4_B_BINARY_SEARCH_H_INCLUDED */
