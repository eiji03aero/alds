#ifndef ALDS_GRAPH_BREADTH_FIRST_SEARCH_H_INCLUDED
#define ALDS_GRAPH_BREADTH_FIRST_SEARCH_H_INCLUDED

#include <vector>
#include <queue>

namespace alds { namespace graph {

static const int INFTY = (1<<21);

int n;
std::vector<std::vector<int>> M;
std::vector<int> d;

std::vector<std::vector<int>> bfs(int s) {
  std::queue<int> q;
  q.push(s);

  for (int i = 0; i < n; i++) d[i] = INFTY;
  d[s] = 0;
  int u;

  while (!q.empty()) {
    u = q.front(); q.pop();
    for (int v = 0; v < n; v++) {
      if (M[u][v] == 0) continue;
      if (d[v] != INFTY) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }

  std::vector<std::vector<int>> result;
  for (int i = 0; i < n; i++) {
    std::vector<int> r;
    r.push_back(i+1);
    r.push_back(d[i] == INFTY ? (-1) : d[i]);
    result.push_back(r);
  }

  return result;
}

std::vector<std::vector<int>> solve(std::vector<std::vector<int>> &input) {
  n = input.size();
  M.resize(n);
  for (auto &m : M) m.resize(n);
  d.resize(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) M[i][j] = 0;
  }

  for (int i = 0; i < n; i++) {
    int u = input[i][0] - 1;
    for (int j = 2; j < input[i].size(); j++) {
      int v = input[i][j] - 1;
      M[u][v] = 1;
    }
  }

  return bfs(0);
}

} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_BREADTH_FIRST_SEARCH_H_INCLUDED */
