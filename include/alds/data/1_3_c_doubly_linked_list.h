#ifndef ALDS_DATA_1_3_C_DOUBLY_LINKED_LIST
#define ALDS_DATA_1_3_C_DOUBLY_LINKED_LIST

#include <string>
#include <vector>
#include <iostream>

namespace alds { namespace data {

struct Node {
  int key;
  Node *prev = nullptr;
  Node *next = nullptr;
};

struct DoublyLinkedList {
  Node *head = nullptr;
  Node *tail = nullptr;

  void connect_nodes(Node *prevNode, Node *nextNode) {
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  void insert_node(int x) {
    Node *node = new Node();
    node->key = x;

    // first insertion, meaning no node in list
    if (head == nullptr) {
      head = node;
      tail = node;
    }
    else {
      connect_nodes(node, head);
      head = node;
    }
  }

  void delete_first() {
    Node *oldHead = head;
    head = oldHead->next;
    head->prev = nullptr;
    delete oldHead;
  }

  void delete_last() {
    Node *oldTail = tail;
    tail = oldTail->prev;
    tail->next = nullptr;
    delete oldTail;
  }

  void delete_node(int x) {
    int c = 0;
    Node *cur = head;
    while (cur != nullptr) {
      c += 1;
      if (c > 10) {
        break;
      }

      if (cur->key != x) {
        cur = cur->next;
        continue;
      }

      if (cur == head) {
        delete_first();
      }
      else if (cur == tail) {
        delete_last();
      }
      else {
        connect_nodes(cur->prev, cur->next);
        delete cur;
      }
      break;
    }
  }
};

struct ListCommand {
  std::string command;
  int key;
};

std::vector<int> execute_list_commands(std::vector<ListCommand> &input) {
  DoublyLinkedList dll;
  for (auto &i : input) {
    if (i.command == "insert") {
      dll.insert_node(i.key);
    }
    else if (i.command == "delete") {
      dll.delete_node(i.key);
    }
  }

  std::vector<int> result;
  Node *cur = dll.head;
  while (cur != nullptr) {
    result.push_back(cur->key);
    cur = cur->next;
  }

  return result;
}

} /* namespace data */
} /* namespace alds */

#endif /* ifndef ALDS_DATA_1_3_C_DOUBLY_LINKED_LIST */
