#ifndef ALDS_SORT_1_1_D_BUBBLE_SORT_H_INCLUDED
#define ALDS_SORT_1_1_D_BUBBLE_SORT_H_INCLUDED

#include <vector>

namespace alds { namespace sort {

void bubble_sort(std::vector<int> &input) {
  bool flag = true;
  int i = 0;
  while (flag) {
    flag = false;
    for (int j = input.size() - 1; j >= i + 1; j--) {
      if (input[j] < input[j - 1]) {
        int tmp = input[j];
        input[j] = input[j - 1];
        input[j - 1] = tmp;
        flag = true;
      }
    }
    i++;
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_1_D_BUBBLE_SORT_H_INCLUDED */
