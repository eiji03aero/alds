#ifndef ALDS_SHARED_H_INCLUDED
#define ALDS_SHARED_H_INCLUDED

#include <vector>
#include <iostream>

namespace alds {

struct Card {
  char suit;
  int value;
};

template<typename T>
void print_vector(std::vector<T> &vec) {
  for (auto &v : vec) {
    std::cout << v << '\n';
  }
}

template<typename T>
void print_vector_inline(std::vector<T> &vec) {
  for (auto &v : vec) {
    std::cout << v << " ";
  }
  std::cout << '\n';
}

} /* namespace alds */

#endif /* ifndef ALDS_SHARED_H_INCLUDED */
