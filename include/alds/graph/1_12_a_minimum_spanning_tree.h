#ifndef ALDS_GRAPH_MINIMUM_SPANNING_TREE_H_INCLUDED
#define ALDS_GRAPH_MINIMUM_SPANNING_TREE_H_INCLUDED

#include <vector>
#include <stack>

namespace alds { namespace graph {

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim() {
  int u, minv;
  int d[MAX], p[MAX], color[MAX];

  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while (1) {
    minv = INFTY;
    u = -1;
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
        if (d[v] > M[u][v]) {
          d[v] = M[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) sum += M[i][p[i]];
  }

  return sum;
}

int solve(std::vector<std::vector<int>> &input) {
  n = input.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int e = input[i][j];
      M[i][j] = (e == -1) ? INFTY : e;
    }
  }

  return prim();
}

} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_MINIMUM_SPANNING_TREE_H_INCLUDED */
