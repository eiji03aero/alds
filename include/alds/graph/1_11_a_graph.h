#ifndef ALDS_GRAPH_GRAPH_H_INCLUDED
#define ALDS_GRAPH_GRAPH_H_INCLUDED

#include <vector>

namespace alds { namespace graph {

std::vector<std::vector<int>> solve(std::vector<std::vector<int>> &input) {
  std::vector<std::vector<int>> result;
  result.resize(input.size());
  for (auto &r : result) r.resize(input.size());

  for (int i = 0; i < input.size(); i ++) {
    for (int j = 0; j < input.size(); j++) result[i][j] = 0;
  }

  for (int i = 0; i < input.size(); i++) {
    int u = input[i][0] - 1;
    for (int j = 2; j < input[i].size(); j++) {
      int v = input[i][j] - 1;
      result[u][v] = 1;
    }
  }

  return result;
}

} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_GRAPH_H_INCLUDED */
