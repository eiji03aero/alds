#ifndef ALDS_SORT_1_1_D_INSERTION_SORT_H_INCLUDED
#define ALDS_SORT_1_1_D_INSERTION_SORT_H_INCLUDED

#include <vector>

namespace alds { namespace sort {

void insertion_sort(std::vector<int> &input) {
  for (int i = 1; i < input.size(); i++) {
    int v = input[i];
    int j = i - 1;
    while (j >= 0 && input[j] > v) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = v;
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_1_D_INSERTION_SORT_H_INCLUDED */
