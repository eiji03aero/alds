#ifndef ALDS_SORT_1_7_B_BINARY_TREE_H_INCLUDED
#define ALDS_SORT_1_7_B_BINARY_TREE_H_INCLUDED

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
  int id, parent, left, right;
};

struct NodeInfo {
  int id, parent, sibling, degree, depth, height;
  std::string type;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
  if (u == NIL) return;
  D[u] = d;
  setDepth(T[u].left, d + 1);
  setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].left != NIL) {
    h1 = setHeight(T[u].left) + 1;
  }
  if (T[u].right != NIL) {
    h2 = setHeight(T[u].right) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u) {
  if (T[u].parent == NIL) return NIL;
  if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
    return T[T[u].parent].left;
  }
  if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
    return T[T[u].parent].right;
  }
  return NIL;
}

std::vector<NodeInfo> solve(std::vector<NodeInput> &input) {
  for (auto &i : input) {
    T[i.id].parent = NIL;
  }

  for (auto &i : input) {
    Node &node = T[i.id];
    node.id = i.id;
    node.left = i.left;
    node.right = i.right;
    if (node.left != NIL) {
      T[node.left].parent = node.id;
    }
    if (node.right != NIL) {
      T[node.right].parent = node.id;
    }
  }

  int root;
  for (int i = 0; i < input.size(); i++) {
    if (T[i].parent == NIL) {
      root = i;
    }
  }

  setDepth(root, 0);
  setHeight(root);

  std::vector<NodeInfo> infos;
  for (int i = 0; i < input.size(); i++) {
    NodeInfo info;
    NodeInput ni = input[i];
    Node node = T[ni.id];
    info.id = ni.id;
    info.parent = node.parent;
    info.sibling = getSibling(ni.id);
    info.degree = 0;
    if (node.left != NIL) info.degree++;
    if (node.right != NIL) info.degree++;
    info.depth = D[ni.id];
    info.height = H[ni.id];
    info.type =
      node.parent == NIL ? "root" :
      node.left != NIL || node.right != NIL ? "internal" :
      "leaf";

    infos.push_back(info);
  }

  return infos;
}


} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_7_B_BINARY_TREE_H_INCLUDED */
