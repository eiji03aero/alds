#ifndef ALDS_SORT_1_1_D_H_INCLUDED
#define ALDS_SORT_1_1_D_H_INCLUDED

#include <vector>
#include <algorithm>

namespace alds { namespace sort {

int maximum_profit (std::vector<int> input) {
  int maxv = -200000000;
  int minv = input.at(0);

  for (int i = 1; i < input.size() - 1; i++) {
    maxv = std::max(maxv, input[i] - minv);
    minv = std::min(minv, input[i]);
  }

  return maxv;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_1_D_H_INCLUDED */
