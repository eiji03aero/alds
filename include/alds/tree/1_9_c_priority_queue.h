#ifndef ALDS_TREE_1_9_C_PRIORITY_QUEUE_H_INCLUDED
#define ALDS_TREE_1_9_C_PRIORITY_QUEUE_H_INCLUDED

#include "alds/tree/1_9_b_maximum_heap.h"

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

#define INFTY (1 << 30)

namespace alds { namespace tree {

int extract(std::vector<int> &input, std::vector<int> &out) {
  int maxv;
  if (input.size() < 1) return -INFTY;
  maxv = out[1];
  out[1] = out[out.size() - 1];
  maxHeapify(1, input, out);
  return maxv;
}

void increaseKey(int i, int key, std::vector<int> &out) {
  if (key < out[i]) return;
  out[i] = key;
  while (i > 1 && out[i / 2] < out[i]) {
    std::swap(out[i], out[i / 2]);
    i = i / 2;
  }
}

void insert(int key, std::vector<int> &out) {
  out.push_back(-INFTY);
  increaseKey(out.size(), key, out);
}

std::vector<int> solve2(std::vector<std::tuple<std::string, int>> &input) {
  std::vector<int> result;

  for (auto &i : input) {
    std::string com = std::get<0>(i);
    int value = std::get<1>(i);
    if (com == "insert") {
      insert(value, result);
    }
    else if (com == "extract") {
      std::vector<int> ininput = result;
      ininput.insert(ininput.begin(), -1);
      result.push_back(extract(ininput, result));
    }
  }

  return result;
}


} /* namespace tree */
} /* namespace alds */

#endif /* ifndef ALDS_TREE_1_9_C_PRIORITY_QUEUE_H_INCLUDED */
