#ifndef ALDS_GRAPH_CONNECTED_COMPONENTS_H_INCLUDED
#define ALDS_GRAPH_CONNECTED_COMPONENTS_H_INCLUDED

#include <vector>
#include <stack>

namespace alds { namespace graph {

static const int MAX = 100000;
static const int NIL = -1;

int n;
std::vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c) {
  std::stack<int> S;
  S.push(r);
  color[r] = c;
  while (!S.empty()) {
    int u = S.top(); S.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (color[v] == NIL) {
        color[v] = c;
        S.push(v);
      }
    }
  }
}

void assignColor() {
  int id = 1;
  for (int i = 0; i < n; i++) color[i] = NIL;
  for (int u = 0; u < n; u++) {
    if (color[u] == NIL) dfs(u, id++);
  }
}

std::vector<bool> solve(int num_users, std::vector<std::vector<int>> &rels, std::vector<std::vector<int>> &qs) {
  n = num_users;
  for (auto &r : rels) {
    G[r[0]].push_back(r[1]);
    G[r[1]].push_back(r[0]);
  }

  assignColor();

  std::vector<bool> result;
  for (auto &q : qs) {
    if (color[q[0]] == color[q[1]]) {
      result.push_back(true);
    } else {
      result.push_back(false);
    }
  }

  return result;
}


} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_CONNECTED_COMPONENTS_H_INCLUDED */
