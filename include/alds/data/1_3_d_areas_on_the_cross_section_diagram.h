#ifndef ALDS_DATA_1_3_D_AREAS_ON_THE_CROSS_SECTION_DIAGRAM_H_INCLUDED
#define ALDS_DATA_1_3_D_AREAS_ON_THE_CROSS_SECTION_DIAGRAM_H_INCLUDED

#include <string>
#include <vector>
#include <stack>
#include <tuple>

namespace alds { namespace data {

struct Pond {
  int start;
  int value;
};

struct DiagramResult {
  int total = 0;
  std::vector<int> values;

};

bool operator==(const DiagramResult &l, const DiagramResult &r) {
  return (
    l.total == r.total
    && l.values == r.values
  );
}

DiagramResult calculate_ponds(std::vector<std::string> diagram) {
  std::stack<int> downs;
  std::stack<Pond> ponds;
  DiagramResult result;

  for (int i = 0; i < diagram.size(); i++) {
    if (diagram[i] == "\\") {
      downs.push(i);
    }
    else if (diagram[i] == "/") {
      // if no matching down, skip calculation
      if (downs.empty()) {
        continue;
      }

      int match_start = downs.top();
      downs.pop();
      int current_volume = i - match_start;

      // merging ponds underlying current one.
      while (!ponds.empty() && ponds.top().start > match_start) {
        current_volume += ponds.top().value;
        ponds.pop();
      }

      Pond pond {match_start, current_volume};
      ponds.push(pond);
    }
    else {
      // should be '_' here. just continue iteration
      continue;
    }
  }

  result.values.insert(result.values.begin(), ponds.size());
  while (!ponds.empty()) {
    Pond &p = ponds.top();
    result.total += p.value;
    result.values.insert(result.values.begin()+1, p.value);
    ponds.pop();
  }

  return result;
}


} /* namespace data */
} /* namespace alds */

#endif /* ifndef ALDS_DATA_1_3_D_AREAS_ON_THE_CROSS_SECTION_DIAGRAM_H_INCLUDED */
