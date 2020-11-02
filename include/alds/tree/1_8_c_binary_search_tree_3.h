#ifndef ALDS_TREE_1_8_C_BINARY_SEARCH_TREE_3_H_INCLUDED
#define ALDS_TREE_1_8_C_BINARY_SEARCH_TREE_3_H_INCLUDED

#include "alds/tree/1_8_b_binary_search_tree_2.h"

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

namespace alds { namespace tree {

Node* treeMinimum(Node *x) {
  while (x->left != NIL) x = x->left;
  return x;
}

Node* treeSuccessor(Node *x) {
  if (x->right != NIL) return treeMinimum(x->right);
  Node *y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *y;
  Node *x;

  if (z->left == NIL || z->right == NIL) y = z;
  else y = treeSuccessor(z);

  if (y->left != NIL) {
    x = y->left;
  } else {
    x = y->right;
  }

  if (x != NIL) {
    x->parent = y->parent;
  }

  if (y->parent == NIL) {
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }

  if (y != z) {
    z->key = y->key;
  }

  delete y;
}

std::tuple<std::vector<bool>, std::vector<std::vector<int>>>
solve3(std::vector<std::tuple<std::string, int>> &input) {
  std::vector<bool> found;
  std::vector<std::vector<int>> prints;

  for (auto &i : input) {
    std::string com = std::get<0>(i);
    int value = std::get<1>(i);

    if (com == "find") {
      Node *t = find(root, value);
      if (t != NIL) found.push_back(true);
      else found.push_back(false);
    }
    else if (com == "insert") {
      insert(value);
    }
    else if (com == "delete") {
      treeDelete(find(root, value));
    }
  }

  std::vector<int> ininput;
  inorder(root, ininput);
  prints.push_back(ininput);

  std::vector<int> preinput;
  preorder(root, preinput);
  prints.push_back(preinput);

  return std::make_tuple(found, prints);
}


} /* namespace tree */
} /* namespace alds */

#endif /* ifndef ALDS_TREE_1_8_C_BINARY_SEARCH_TREE_3_H_INCLUDED */
