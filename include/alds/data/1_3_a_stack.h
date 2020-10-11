#ifndef ALDS_DATA_1_3_A_STACK_H_INCLUDED
#define ALDS_DATA_1_3_A_STACK_H_INCLUDED

#include <string>
#include <vector>

namespace alds { namespace data {

struct Stack {
public:
  void push(int i) {
    data.push_back(i);
  }

  int pop() {
    if (data.size() == 0) {
      exit(EXIT_FAILURE);
    }

    int last = data.back();
    data.pop_back();
    return last;
  }

  std::vector<int> data;
};

int calculate_reverse_polish_notation (std::vector<std::string> input) {
  Stack stk;

  for (auto &i : input) {
    if (i == "+") {
      int o2 = stk.pop();
      int o1 = stk.pop();
      stk.push(o1 + o2);
    }
    else if (i == "-") {
      int o2 = stk.pop();
      int o1 = stk.pop();
      stk.push(o1 - o2);
    }
    else if (i == "*") {
      int o2 = stk.pop();
      int o1 = stk.pop();
      stk.push(o1 * o2);
    }
    else {
      stk.push(atoi(i.c_str()));
    }
  }

  return stk.pop();
}


} /* namespace data */
} /* namespace alds */

#endif /* ifndef ALDS_DATA_1_3_A_STACK_H_INCLUDED */
