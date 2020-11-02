#ifndef ALDS_TREE_1_9_B_MAXIMUM_HEAP_H_INCLUDED
#define ALDS_TREE_1_9_B_MAXIMUM_HEAP_H_INCLUDED

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

#define MAX 2000000

namespace alds { namespace tree {

void maxHeapify(int i, std::vector<int> &input, std::vector<int> &out) {
  int l, r, largest;

  l = 2 * i;
  r = 2 * i + 1;

  if (l <= input.size() && out[l] > out[i]) largest = l;
  else largest = i;

  if (r <= input.size() && out[r] > out[largest]) largest = r;

  if (largest != i) {
    std::swap(out[i], out[largest]);
    maxHeapify(largest, input, out);
  }
}

std::vector<int> solve(std::vector<int> &input) {
  std::vector<int> result;
  result.resize(input.size() + 1);

  for (int i = 1; i <= input.size(); i++) result[i] = input[i - 1];

  for (int i = input.size() / 2; i >= 1; i--) maxHeapify(i, input, result);

  result.erase(result.begin());

  return result;
}

} /* namespace tree */
} /* namespace alds */

#endif /* ifndef ALDS_TREE_1_9_B_MAXIMUM_HEAP_H_INCLUDED */
