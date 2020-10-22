#ifndef ALDS_SORT_1_6_A_COUNTING_SORT_H_INCLUDED
#define ALDS_SORT_1_6_A_COUNTING_SORT_H_INCLUDED

#include <vector>
#include "alds/shared.h"

namespace alds { namespace sort {

std::vector<int> counting_sort(std::vector<int> &input) {
  int i;
  int vmax = 10;

  std::vector<int> result, counter;
  result.resize(input.size());
  counter.resize(vmax, 0);

  for (i = 0; i < input.size(); i++) {
    counter[input[i]]++;
  }

  for (i = 1; i <= vmax; i++) {
    counter[i] = counter[i] + counter[i - 1];
  }

  for (i = input.size() - 1; i >= 0; i--) {
    result[counter[input[i]] - 1] = input[i];
    counter[input[i]]--;
  }

  return result;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_6_A_COUNTING_SORT_H_INCLUDED */
