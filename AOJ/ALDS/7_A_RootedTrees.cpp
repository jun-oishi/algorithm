#include <iostream>
#include <algorithm>
#include <string>
using string = std::string;

void showArray(int *A, int n, bool linebreak = true) {
  std::cout << "[";
  for (int i = 0; i < n; i++) {
    if (i) std::cout << ", ";
    std::cout << A[i];
  }
  std::cout << "]";
  if (linebreak) std::cout << std::endl;
}

struct Tree {
  struct Node {
    int parent = NIL;
    int left_child = NIL;
    int right_sibling = NIL;
    int n_children = 0;
  };
  Node *nodes;

  static const int NIL = -1;
  Tree(int n) {
    nodes = new Node[n];
  }
  ~Tree() {
    delete[] this->nodes;
  }

  void add(int id, int n_children, int* children) {
    if (n_children == 0) return;
    // std::sort(children, children + n_children);
    // std::cout << "sorted:";
    // showArray(children, n_children);
    this->nodes[id].left_child = children[0];
    this->nodes[id].n_children = n_children;
    for (int i = 0; i < n_children; i++) {
      int child = children[i];
      this->nodes[child].parent = id;
      if (i < n_children - 1) {
        this->nodes[child].right_sibling = children[i+1];
      }
    }
  }

  int getDepth(int id) const {
    if (this->nodes[id].parent == NIL) {
      return 0;
    } else {
      return 1 + this->getDepth(this->nodes[id].parent);
    }
  }

  int* getChildren(int id) const {
    int n = this->nodes[id].n_children;
    int* Children = new int[n];
    int cur = this->nodes[id].left_child;
    for (int i = 0; i < n; i++) {
      Children[i] = cur;
      cur = this->nodes[cur].right_sibling;
    }
    return Children;
  }

  Node &operator[](int i) const {
    return this->nodes[i];
  }
};

void showNode(Tree &tree, int i) {
  int depth = tree.getDepth(i);
  // std::cout << "depth:" << depth << " fetched" << std::endl;
  string type;
  if (depth == 0) {
    type = "root";
  } else if (tree[i].left_child == Tree::NIL) {
    type = "leaf";
  } else {
    type = "internal node";
  }
  // std::cout << "type fetched" << std::endl;
  int *Children = tree.getChildren(i);
  // std::cout << "children fetched" << std::endl;
  std::cout << "node " << i << ": ";
  std::cout << "parent = " << tree[i].parent;
  std::cout << ", depth = " << depth;
  std::cout << ", " << type;
  std::cout << ", ";
  showArray(Children, tree[i].n_children);
}

int main() {
  int n;
  std::cin >> n;
  Tree tree(n);
  for (int i = 0; i < n; i++) {
    int id, n_children;
    std::cin >> id >> n_children;
    // std::cout << "id:" << id << ", n_children:" << n_children << ", children:";
    int Children[n_children];
    for (int i = 0; i < n_children; i++) {
      std::cin >> Children[i];
    }
    tree.add(id, n_children, Children);
    // std::cout << "`" << id << "` successfully added: children:";
    // showArray(tree.getChildren(id), tree[id].n_children);
  }

  for (int i = 0; i < n; i++) {
    showNode(tree, i);
  }
}