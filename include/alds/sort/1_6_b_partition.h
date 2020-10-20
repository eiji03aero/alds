#ifndef ALDS_SORT_1_6_B_PARTITION_H_INCLUDED
#define ALDS_SORT_1_6_B_PARTITION_H_INCLUDED

#include <vector>
#include "alds/shared.h"

namespace alds { namespace sort {

int partition(std::vector<int> &input, int p, int r) {
  int x, i, j, t;
  x = input[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (input[j] <= x) {
      i++;
      t = input[i]; input[i] = input[j]; input[j] = t;
    }
  }
  t = input[i + 1]; input[i + 1] = input[r]; input[r] = t;
  return i + 1;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_6_B_PARTITION_H_INCLUDED */
