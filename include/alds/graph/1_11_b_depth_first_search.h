#ifndef ALDS_GRAPH_DEPTH_FIRST_SEARCH_H_INCLUDED
#define ALDS_GRAPH_DEPTH_FIRST_SEARCH_H_INCLUDED

#include <vector>
#include <stack>

namespace alds { namespace graph {

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, tt;
std::vector<std::vector<int>> M;
std::vector<int> color, d, f, nt;

int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;
    if (M[u][v]) return v;
  }
  return -1;
}

void dfs_visit(int r) {
  for (int i = 0; i < n; i++) nt[i] = 0;

  std::stack<int> S;
  S.push(r);
  color[r] = GRAY;
  d[r] = ++tt;

  while (!S.empty()) {
    int u = S.top();
    int v = next(u);
    if (v != -1) {
      if (color[v] == WHITE) {
        color[v] = GRAY;
        d[v] = ++tt;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = BLACK;
      f[u] = ++tt;
    }
  }
}

std::vector<std::vector<int>> dfs() {
  std::vector<std::vector<int>> result;

  for (int i = 0; i < n; i++) {
    color[i] = WHITE;
    nt[i] = 0;
  }

  tt = 0;

  for (int u = 0; u < n; u++) {
    if (color[u] == WHITE) dfs_visit(u);
  }

  for (int i = 0; i < n; i++) {
    std::vector<int> r;
    r.push_back(i + 1);
    r.push_back(d[i]);
    r.push_back(f[i]);
    result.push_back(r);
  }

  return result;
}

std::vector<std::vector<int>> solve(std::vector<std::vector<int>> &input) {
  n = input.size();
  M.resize(n);
  for (auto &m : M) m.resize(n);
  color.resize(n);
  d.resize(n);
  f.resize(n);
  nt.resize(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; i < n; i++) M[i][j] = 0;
  }

  for (int i = 0; i < n; i++) {
    int u = input[i][0] - 1;
    for (int j = 2; j < input[i].size(); j++) {
      int v = input[i][j] - 1;
      M[u][v] = 1;
    }
  }

  return dfs();
}


} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_DEPTH_FIRST_SEARCH_H_INCLUDED */
