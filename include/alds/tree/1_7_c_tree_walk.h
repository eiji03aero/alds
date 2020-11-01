#ifndef ALDS_SORT_1_7_C_TREE_WALK_H_INCLUDED
#define ALDS_SORT_1_7_C_TREE_WALK_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#define MAX 10000
#define NIL -1

namespace alds { namespace tree {

struct NodeInput {
  int id, left, right;
};

struct Node {
  int p, l, r;
};

Node T[MAX];

void preParse(int u, std::vector<int> &out) {
  if (u == NIL) return;
  out.push_back(u);
  preParse(T[u].l, out);
  preParse(T[u].r, out);
}

void inParse(int u, std::vector<int> &out) {
  if (u == NIL) return;
  inParse(T[u].l, out);
  out.push_back(u);
  inParse(T[u].r, out);
}

void postParse(int u, std::vector<int> &out) {
  if (u == NIL) return;
  postParse(T[u].l, out);
  postParse(T[u].r, out);
  out.push_back(u);
}

std::vector<std::vector<int>> solve(std::vector<NodeInput> &input) {
  for (auto &i : input) {
    Node &node = T[i.id];
    node.p = node.l = node.r = NIL;
  }

  for (auto &i : input) {
    Node &node = T[i.id];
    node.l = i.left;
    node.r = i.right;
    if (node.l != NIL) {
      T[node.l].p = i.id;
    }
    if (node.r != NIL) {
      T[node.r].p = i.id;
    }
  }

  int root;
  for (int i = 0; i < input.size(); i++) {
    if (T[i].p == NIL) {
      root = i;
    }
  }

  std::vector<std::vector<int>> result;

  std::vector<int> preorder;
  preParse(root, preorder);
  result.push_back(preorder);

  std::vector<int> inorder;
  inParse(root, inorder);
  result.push_back(inorder);

  std::vector<int> postorder;
  postParse(root, postorder);
  result.push_back(postorder);

  return result;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_7_C_TREE_WALK_H_INCLUDED */
