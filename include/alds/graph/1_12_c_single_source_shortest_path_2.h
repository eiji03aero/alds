#ifndef ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED
#define ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED

#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

namespace alds { namespace graph {

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
std::vector<std::pair<int, int>> adj[MAX];

std::vector<std::vector<int>> dijkstra() {
  std::priority_queue<std::pair<int, int>> PQ;
  int color[MAX];
  int d[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[0] = 0;
  PQ.push(std::make_pair(0, 0));
  color[0] = GRAY;

  while (!PQ.empty()) {
    std::pair<int, int> f = PQ.top(); PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    if (d[u] < f.first * (-1)) continue;

    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        PQ.push(std::make_pair(d[v] * (-1), v));
        color[v] = GRAY;
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
    int u = input[i][0];
    for (int j = 2; j < input[i].size(); j += 2) {
      int v = input[i][j];
      int c = input[i][j+1];
      adj[u].push_back(std::make_pair(v, c));
    }
  }

  return dijkstra();
}

} /* namespace graph */
} /* namespace alds */

#endif /* ifndef ALDS_GRAPH_SINGLE_SOURCE_SHORTEST_PATH_H_INCLUDED */
