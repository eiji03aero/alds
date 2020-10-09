#ifndef ALDS_SORT_1_1_D_STABLE_SORT_H_INCLUDED
#define ALDS_SORT_1_1_D_STABLE_SORT_H_INCLUDED

#include "alds/shared.h"

#include <vector>

namespace alds { namespace sort {

void bubble_sort(std::vector<alds::Card> &input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = input.size() - 1; j >= i+1; j--) {
      if (input[j].value < input[j - 1].value) {
        std::swap(input[j], input[j - 1]);
      }
    }
  }
}

void selection_sort(std::vector<alds::Card> &input) {
  for (int i = 0; i < input.size(); i++) {
    int minj = i;
    for (int j = i; j < input.size(); j++) {
      if (input[j].value < input[minj].value) {
        minj = j;
      }
    }
    std::swap(input[i], input[minj]);
  }
}

bool is_stable(std::vector<alds::Card> v1, std::vector<alds::Card> v2) {
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i].suit != v2[i].suit) {
      return false;
    }
  }
  return true;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_1_D_STABLE_SORT_H_INCLUDED */
