#ifndef ALDS_SORT_1_7_A_ROOTED_TREES_H_INCLUDED
#define ALDS_SORT_1_7_A_ROOTED_TREES_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#define MAX 100005
#define NIL -1

namespace alds { namespace tree {

struct NodeInput {
  int id;
  std::vector<int> children;
};

struct Node {
  int id, p, l, r;
};

struct NodeInfo {
  int id;
  int parent;
  int depth;
  std::string type;
  std::vector<int> children;
};

bool operator==(const NodeInfo &l, const NodeInfo &r) {
  return (
    l.id == r.id
    && l.parent == r.parent
    && l.depth == r.depth
    && l.type == r.type
    && l.children == r.children
  );
}

int find_by_id(std::vector<Node> &nodes, int id) {
  for (int i = 0; i < nodes.size(); i++) {
    if (nodes[i].id == id) {
      return i;
    }
  }
  return NIL;
}

int find_root(std::vector<Node> &nodes) {
  for (int i = 0; i < nodes.size(); i++) {
    if (nodes[i].p == NIL) {
      return i;
    }
  }
  return NIL;
}

std::vector<Node> build_nodes(std::vector<NodeInput> &input) {
  std::vector<Node> nodes;

  for (int i = 0; i < input.size(); i++) {
    Node node;
    node.id = input[i].id;
    node.p = node.l = node.r = NIL;
    nodes.push_back(node);
  }

  for (int i = 0; i < input.size(); i++) {
    Node &node = nodes[i];
    Node left_child;
    for (int j = 0; j < input[i].children.size(); j++) {
      int cid = input[i].children[j];
      int cidx = find_by_id(nodes, cid);
      if (cidx == NIL) {
        exit(EXIT_FAILURE);
      }

      Node &child = nodes[cidx];
      child.p = node.id;
      if (j == 0) {
        node.l = cid;
      } else {
        int tmp = find_by_id(nodes, left_child.id);
        Node &lc = nodes[tmp];
        lc.r = child.id;
      }
      left_child = child;
    }
  }

  return nodes;
}

std::vector<NodeInfo> build_node_infos(std::vector<NodeInput> &input, std::vector<Node> &nodes) {
  std::vector<NodeInfo> infos;

  for (int i = 0; i < input.size(); i++) {
    NodeInfo info;
    info.id = input[i].id;

    int nodeidx = find_by_id(nodes, info.id);
    if (nodeidx == NIL) {
      exit(EXIT_FAILURE);
    }
    Node node = nodes[nodeidx];

    info.parent = node.p;
    info.children = input[i].children;

    infos.push_back(info);
  }

  return infos;
}

void rec(std::vector<Node> &nodes, std::vector<NodeInfo> &infos, int u, int p) {
  int nidx = find_by_id(nodes, u);
  if (nidx == NIL) {
    exit(EXIT_FAILURE);
  }
  Node &node = nodes[nidx];

  for (auto &info : infos) {
    if (info.id == node.id) {
      info.depth = p;
      if (node.r != NIL) rec(nodes, infos, node.r, p);
      if (node.l != NIL) rec(nodes, infos, node.l, p + 1);
      info.type =
        node.p == NIL ? "root" :
        node.l == NIL ? "leaf" :
        "internal";
      break;
    }
  }
}

std::vector<NodeInfo> solve(std::vector<NodeInput> &input) {
  std::vector<Node> nodes = build_nodes(input);
  std::vector<NodeInfo> infos = build_node_infos(input, nodes);

  int root = find_root(nodes);
  rec(nodes, infos, root, 0);

  return infos;
}

} /* namespace sort */
} /* namespace alds */

#endif /* ifndef ALDS_SORT_1_7_A_ROOTED_TREES_H_INCLUDED */
