#ifndef ALDS_SORT_1_1_D_SELECTION_SORT_H_INCLUDED
#define ALDS_SORT_1_1_D_SELECTION_SORT_H_INCLUDED

#include <vector>

namespace alds { namespace sort {

void selection_sort(std::vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    int minj = i;
    for (int j = minj; j < input.size(); j++) {
      if (input[j] < input[minj]) {
        minj = j;
      }
    }
    std::swap(input[i], input[minj]);
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_1_D_SELECTION_SORT_H_INCLUDED */
