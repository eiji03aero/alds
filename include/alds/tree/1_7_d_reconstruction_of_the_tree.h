#ifndef ALDS_SORT_1_7_D_RECONSTRUCTION_OF_THE_TREE_H_INCLUDED
#define ALDS_SORT_1_7_D_RECONSTRUCTION_OF_THE_TREE_H_INCLUDED

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#define MAX 10000
#define NIL -1

namespace alds { namespace tree {

int n, pos;
std::vector<int> pre, in, post;

void rec(int l, int r) {
  if (l >= r) return;
  int root = pre[pos++];
  int m = distance(in.begin(), find(in.begin(), in.end(), root));
  rec(l, m);
  rec(m + 1, r);
  post.push_back(root);
}

std::vector<int> solve(std::vector<int> preinput, std::vector<int> ininput) {
  pre = preinput;
  in = ininput;

  pos = 0;
  rec(0, pre.size());

  return post;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_7_D_RECONSTRUCTION_OF_THE_TREE_H_INCLUDED */
