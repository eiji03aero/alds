#ifndef ALDS_SORT_1_6_C_QUICK_SORT_H_INCLUDED
#define ALDS_SORT_1_6_C_QUICK_SORT_H_INCLUDED

#include <vector>
#include "alds/shared.h"

namespace alds { namespace sort {

int partition(std::vector<Card> &input, int p, int r) {
  int i, j;
  Card t, x;
  x = input[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (input[j].value <= x.value) {
      i++;
      t = input[i]; input[i] = input[j]; input[j] = t;
    }
  }
  t = input[i + 1]; input[i + 1] = input[r]; input[r] = t;
  return i + 1;
}

void quick_sort(std::vector<Card> &input, int p, int r) {
  int q;
  if (p < r) {
    q = partition(input, p, r);
    quick_sort(input, p, q - 1);
    quick_sort(input, q + 1, r);
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_6_C_QUICK_SORT_H_INCLUDED */
