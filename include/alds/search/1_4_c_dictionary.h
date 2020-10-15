#ifndef ALDS_SEARCH_1_4_C_DICTIONARY_H_INCLUDED
#define ALDS_SEARCH_1_4_C_DICTIONARY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

namespace alds { namespace search {

constexpr int M = 1046527;
constexpr int L = 14;

char H[M][L];

int getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getKey(char str[]) {
  long long sum = 0, p = 1, i;
  for (i = 0; i < strlen(str); i++) {
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int find(char str[]) {
  long long key, i, h;
  key = getKey(str);
  for (i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) return 1;
    else if (strlen(H[h]) == 0) return 0;
  }
  return 0;
}

int insert(char str[]) {
  long long key, i, h;
  key = getKey(str);
  for (i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) return 1;
    else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

std::vector<bool> test_dictionary(std::vector<std::vector<std::string>> input) {
  std::vector<bool> result;

  for (int i = 0; i < M; i++) H[i][0] = '\0';

  for (std::vector<std::string> &i : input) {
    char key[L];
    strcpy(key, i[1].c_str());
    if (i[0] == "insert") {
      insert(key);
    }
    else if (i[0] == "find") {
      result.push_back(find(key) == 1);
    }
  }

  return result;
}

} /* namespace search */
} /* namespace alds */

#endif /* ifndef ALDS_SEARCH_1_4_C_DICTIONARY_H_INCLUDED */
