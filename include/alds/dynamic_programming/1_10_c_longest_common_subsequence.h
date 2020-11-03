#ifndef ALDS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_INCLUDED
#define ALDS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_INCLUDED

#include <string>
#include <vector>

namespace alds { namespace dynamic_programming {

static const int N = 1000;

int lcs(std::string X, std::string Y) {
  int c[N + 1][N + 1];
  int m = X.size();
  int n = Y.size();
  int maxl = 0;
  X = ' ' + X;
  Y = ' ' + Y;
  for (int i = 0; i <= m; i++) c[i][0] = 0;
  for (int j = 0; j <= n; j++) c[0][j] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i] == Y[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else {
        c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
      }
      maxl = std::max(maxl, c[i][j]);
    }
  }

  return maxl;
}

std::vector<int> solve(std::vector<std::vector<std::string>> &input) {
  std::vector<int> result;
  for (auto &i : input) {
    result.push_back(lcs(i[0], i[1]));
  }
  return result;
}


} /* namespace dynamic_programming */
} /* namespace alds */

#endif /* ifndef ALDS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_INCLUDED */
