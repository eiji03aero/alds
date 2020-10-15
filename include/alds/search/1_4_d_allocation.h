#ifndef ALDS_SEARCH_1_4_D_ALLOCATION_H_INCLUDED
#define ALDS_SEARCH_1_4_D_ALLOCATION_H_INCLUDED

#include <vector>

namespace alds { namespace search {

constexpr int Max = 100000;
typedef long long llong;

llong T[Max];

int check(llong P, std::vector<int> loads, int num_tracks) {
  int i = 0;
  for (int j = 0; j < num_tracks; j++) {
    llong s = 0;
    while (s + loads[i] <= P) {
      s += loads[i];
      i ++;
      if (i == loads.size()) return loads.size();
    }
  }
  return i;
}

int solve(std::vector<int> loads, int num_tracks) {
  llong left = 0;
  llong right = 100000 * 10000;
  llong mid;
  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = check(mid, loads, num_tracks);
    if (v >= loads.size()) right = mid;
    else left = mid;
  }
  return right;
}


} /* namespace search */
} /* namespace alds */

#endif /* ifndef ALDS_SEARCH_1_4_D_ALLOCATION_H_INCLUDED */
