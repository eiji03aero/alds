#ifndef ALDS_DATA_1_3_B_QUEUE_H_INCLUDED
#define ALDS_DATA_1_3_B_QUEUE_H_INCLUDED

#include <string>
#include <vector>
#include <stdlib.h>

namespace alds { namespace data {

struct Process {
  std::string name;
  int work;
  int spent = 0;
};

struct ProcessDetail {
  std::string name;
  int value;
};

struct Queue {
  void enqueue(Process i) {
    data.push_back(i);
  }

  Process dequeue() {
    Process front = data.front();
    data.erase(data.begin());
    return front;
  }

  std::size_t size() {
    return data.size();
  }

  std::vector<Process> data;
};

std::vector<ProcessDetail>
emulate_round_robin_scheduling(
  int quantum,
  std::vector<ProcessDetail> &input
) {
  Queue q;
  std::vector<ProcessDetail> result;
  int total_spent = 0;

  for (auto &i : input) {
    Process process {i.name, i.value};
    q.enqueue(process);
  }

  while (q.size() > 0) {
    Process p = q.dequeue();

    if (p.work > quantum) {
      total_spent += quantum;
      p.work -= quantum;
      q.enqueue(p);
    } else {
      total_spent += p.work;
      ProcessDetail pd {p.name, total_spent};
      result.push_back(pd);
    }
  }

  return result;
}


} /* namespace data */
} /* namespace alds */

#endif /* ifndef ALDS_DATA_1_3_B_QUEUE_H_INCLUDED */
