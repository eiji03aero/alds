#ifndef ALDS_TREE_1_9_A_COMPLETE_BINARY_TREE_HINCLUDED
#define ALDS_TREE_1_9_A_COMPLETE_BINARY_TREE_HINCLUDED

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

#define MAX 100000

namespace alds { namespace tree {

struct NodeInfo {
  int id, key, parent, left, right;
};

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

std::vector<NodeInfo> solve(std::vector<int> &input) {
  std::vector<NodeInfo> result;
  int i, A[MAX+1];

  for (i = 1; i <= input.size(); i++) A[i] = input[i - 1];

  for (int i = 1; i <= input.size(); i++) {
    NodeInfo info;
    info.parent = info.left = info.right = -1;
    info.id = i;
    info.key = A[i];
    if (parent(i) >= 1) info.parent = A[parent(i)];
    if (left(i) <= input.size()) info.left = A[left(i)];
    if (right(i) <= input.size()) info.right = A[right(i)];
    result.push_back(info);
  }

  return result;
}

} /* namespace tree */
} /* namespace alds */

#endif /* ifndef ALDS_TREE_1_9_A_COMPLETE_BINARY_TREE_HINCLUDED */
