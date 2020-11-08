#ifndef ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED
#define ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED

#include <vector>
#include <stack>

namespace alds { namespace graph {

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

std::vector<std::vector<int>> dijkstra() {
  int minv;
  int d[MAX], color[MAX];

  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[0] = 0;
  color[0] = GRAY;
  while (1) {
    minv = INFTY;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1) break;
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }

  std::vector<std::vector<int>> result;
  for (int i = 0; i < n; i++) {
    std::vector<int> r;
    r.push_back(i);
    r.push_back(d[i] == INFTY ? -1 : d[i]);
    result.push_back(r);
  }

  return result;
}

std::vector<std::vector<int>> solve(std::vector<std::vector<int>> &input) {
  n = input.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = INFTY;
    }
  }

  for (int i = 0; i < n; i++) {
    int u = input[i][0];
    for (int j = 2; j < input[i].size(); j += 2) {
      int v = input[i][j];
      int c = input[i][j+1];
      M[u][v] = c;
    }
  }

  return dijkstra();
}

} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED */
