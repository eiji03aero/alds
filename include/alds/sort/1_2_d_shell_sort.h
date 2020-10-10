#ifndef ALDS_SORT_1_2_D_SHELL_SORT_H_INCLUDED
#define ALDS_SORT_1_2_D_SHELL_SORT_H_INCLUDED

#include "alds/shared.h"

#include <vector>

namespace alds { namespace sort {

void insertion_sort(std::vector<int> &input, int g) {
  for (int i = g; i < input.size(); i++) {
    int v = input[i];
    int j = i - g;
    while (j >= 0 && input[j] > v) {
      input[j + g] = input[j];
      j = j - g;
    }
    input[j + g] = v;
  }
}

std::vector<int> build_gaps (int size) {
  int gap = 1;
  std::vector<int> gaps;
  while (gap <= size) {
    gaps.push_back(gap);
    gap = 3*gap + 1;
  }
  return gaps;
}

void shell_sort(std::vector<int> &input) {
  std::vector<int> gaps = build_gaps(input.size());
  for (int i = gaps.size() - 1; i >= 0; i--) {
    insertion_sort(input, gaps[i]);
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_2_D_SHELL_SORT_H_INCLUDED */
