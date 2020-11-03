#ifndef ALDS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_MULTIPLICATION_H_INCLUDED
#define ALDS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_MULTIPLICATION_H_INCLUDED

#include <string>
#include <vector>

namespace alds { namespace dynamic_programming {

static const int N = 100;

int solve(std::vector<std::vector<int>> &input) {
  int p[N + 1], m[N + 1][N + 1];

  for (int i = 1; i <= input.size(); i++) {
    p[i - 1] = input[i  - 1][0];
    p[i] = input[i  - 1][1];
  }

  for (int i = 1; i <= input.size(); i++) m[i][i] = 0;

  for (int l = 2; l <= input.size(); l++) {
    for (int i = 1; i <= input.size() - 1; i++) {
      int j = i + l - 1;
      m[i][j] = (1 << 21);
      for (int k = i; k <= j - 1; k++) {
        m[i][j] = std::min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
    }
  }

  return m[1][input.size()];
}

} /* namespace dynamic_programming */
} /* namespace alds */

#endif /* ifndef ALDS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_MULTIPLICATION_H_INCLUDED */
