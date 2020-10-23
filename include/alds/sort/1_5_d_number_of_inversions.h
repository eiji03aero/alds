#ifndef ALDS_SORT_1_5_D_NUMBER_OF_INVERSIONS_H_INCLUDED
#define ALDS_SORT_1_5_D_NUMBER_OF_INVERSIONS_H_INCLUDED

#include <vector>
#include "alds/shared.h"

namespace alds { namespace sort {

// {3,6,4,8,1,4,5}

// s1: check from back ... O(n!)
// count = 0;
// for i = size - 1; i > 0; i++
//   for j = i - 1; j > 0; j++
//     if input[i] < input[j]
//       count++;
//
// s2: utilize counting-sort-ish array
// count = 0;
// counter = int[max_value];
// not working, since maximum value is 1,000,000,000, array cannot be allocated

#define MAX 200000
#define SENTINEL 2000000000
using llong = long long;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

llong merge(std::vector<int> &input, int left, int mid, int right) {
  int i, j, k;
  llong count = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0; i < n1; i++) L[i] = input[left + i];
  for (i = 0; i < n2; i++) R[i] = input[mid + i];
  L[n1] = R[n2] = SENTINEL;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      input[k] = L[i++];
    } else {
      input[k] = R[j++];
      count += n1 - i;
    }
  }
  return count;
}

llong merge_sort(std::vector<int> &input, int left, int right) {
  int mid;
  llong v1, v2, v3;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    v1 = merge_sort(input, left, mid);
    v2 = merge_sort(input, mid, right);
    v3 = merge(input, left, mid, right);
    return v1 + v2 + v3;
  } else {
    return 0;
  }
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_5_D_NUMBER_OF_INVERSIONS_H_INCLUDED */
