#ifndef ALDS_DYNAMIC_PROGRAMMING_FIBONACCI_NUMBER_H_INCLUDED
#define ALDS_DYNAMIC_PROGRAMMING_FIBONACCI_NUMBER_H_INCLUDED

namespace alds { namespace dynamic_programming {

int solve(int n) {
  int F[50];
  F[0] = F[1] = 1;
  for (int i = 2; i<= n; i++) F[i] = F[i - 1] + F[i - 2];

  return F[n];
}

} /* namespace dynamic_programming */
} /* namespace alds */

#endif /* ifndef ALDS_DYNAMIC_PROGRAMMING_FIBONACCI_NUMBER_H_INCLUDED */
