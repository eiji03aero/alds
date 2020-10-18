#ifndef ALDS_RECURSIVE_1_5_A_EXHAUSTIVE_RECURSIVE_H_INCLUDED
#define ALDS_RECURSIVE_1_5_A_EXHAUSTIVE_RECURSIVE_H_INCLUDED

#include <vector>
#include <string>

namespace alds { namespace recursive {

int solve(int i, int m, std::vector<int> values) {
  if (m == 0) return 1;
  if (i >= values.size()) return 0;
  int res = solve(i + 1, m, values) || solve(i + 1, m - values[i], values);
  return res;
}

std::vector<std::string> solve_exhaustive_search(std::vector<int> input, std::vector<int> values) {
  std::vector<std::string> result;
  for (auto & v : values) {
    if (solve(0, v, input)) {
      result.push_back("yes");
    } else {
      result.push_back("no");
    }
  }
  return result;
}


} /* namespace recursive */
} /* namespace alds */

#endif /* ifndef ALDS_RECURSIVE_1_5_A_EXHAUSTIVE_RECURSIVE_H_INCLUDED */
