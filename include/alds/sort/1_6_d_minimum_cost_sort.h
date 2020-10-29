#ifndef ALDS_SORT_1_6_D_MINIMUM_COST_SORT_H_INCLUDED
#define ALDS_SORT_1_6_D_MINIMUM_COST_SORT_H_INCLUDED

#include <vector>
#include <algorithm>
#include "alds/shared.h"

namespace alds { namespace sort {

static const int MAX = 1000;
static const int VMAX = 10000;

int B[MAX], T[VMAX + 1];

int solve(std::vector<int> input) {
  int n = input.size();
  int s = *(std::min_element(input.begin(), input.end()));
  int ans = 0;

  bool V[MAX];
  for (int i = 0; i < n; i++) {
    B[i] = input[i];
    V[i] = false;
  }
  std::sort(B, B+n);
  for (int i = 0; i < n; i++) T[B[i]] = i;
  for (int i = 0; i < n; i++) {
    if (V[i]) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    while (1) {
      V[cur] = true;
      an++;
      int v = input[cur];
      m = std::min(m, v);
      S += v;
      cur = T[v];
      if (V[cur]) break;
    }
    ans += std::min(S + (an - 2) * m, m + S + (an + 1) * s);
  }
  return ans;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_6_D_MINIMUM_COST_SORT_H_INCLUDED */
