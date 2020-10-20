#ifndef ALDS_SORT_1_5_BMERGE_SORT_H_INCLUDED
#define ALDS_SORT_1_5_BMERGE_SORT_H_INCLUDED

#include <vector>
#include <limits>
#include "alds/shared.h"

namespace alds { namespace sort {

constexpr int Infinity = std::numeric_limits<int>::max();

void merge(std::vector<int> &input, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  std::vector<int> L, R;
  L.resize(n1 + 1);
  R.resize(n2 + 1);
  for (int i = 0; i < n1; i++) {
    L[i] = input[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = input[mid + i];
  }
  L[n1] = Infinity;
  R[n2] = Infinity;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      input[k] = L[i];
      i += 1;
    } else {
      input[k] = R[j];
      j += 1;
    }
  }
}

void merge_sort(std::vector<int> &input, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(input, left, mid);
    merge_sort(input, mid, right);
    merge(input, left, mid, right);
    alds::print_vector_inline(input);
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_5_BMERGE_SORT_H_INCLUDED */
