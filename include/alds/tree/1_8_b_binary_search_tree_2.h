#ifndef ALDS_TREE_1_8_B_BINARY_SEARCH_TREE_2_H_INCLUDED
#define ALDS_TREE_1_8_B_BINARY_SEARCH_TREE_2_H_INCLUDED

#include "alds/tree/1_8_a_binary_search_tree_1.h"

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

namespace alds { namespace tree {

Node* find(Node *u, int k) {
  while (u != NIL && k != u ->key) {
    if (k < u->key) u = u->left;
    else u = u->right;
  }
  return u;
}

std::tuple<std::vector<bool>, std::vector<std::vector<int>>>
solve2(std::vector<std::tuple<std::string, int>> &input) {
  std::vector<bool> found;
  std::vector<std::vector<int>> prints;

  for (auto &i : input) {
    std::string com = std::get<0>(i);
    int value = std::get<1>(i);

    if (com == "find") {
      int x = std::get<1>(i);
      Node *t = find(root, x);
      if (t != NIL) found.push_back(true);
      else found.push_back(false);
    }
    else if (com == "insert") {
      insert(value);
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

#endif /* ifndef ALDS_TREE_1_8_B_BINARY_SEARCH_TREE_2_H_INCLUDED */
