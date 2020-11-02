#ifndef ALDS_TREE_1_8_A_BINARY_SEARCH_TREE_1_H_INCLUDED
#define ALDS_TREE_1_8_A_BINARY_SEARCH_TREE_1_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

namespace alds { namespace tree {

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u, std::vector<int> &out) {
  if (u == NIL) return;
  inorder(u->left, out);
  out.push_back(u->key);
  inorder(u->right, out);
}

void preorder(Node *u, std::vector<int> &out) {
  if (u == NIL) return;
  out.push_back(u->key);
  preorder(u->left, out);
  preorder(u->right, out);
}

std::vector<std::vector<int>> solve(std::vector<int> &input) {
  for (auto &i : input) {
    insert(i);
  }

  std::vector<std::vector<int>> result;

  std::vector<int> ininput;
  inorder(root, ininput);
  result.push_back(ininput);

  std::vector<int> preinput;
  preorder(root, preinput);
  result.push_back(preinput);

  return result;
}

} /* namespace tree */
} /* namespace alds */

#endif /* ifndef ALDS_TREE_1_8_A_BINARY_SEARCH_TREE_1_H_INCLUDED */
