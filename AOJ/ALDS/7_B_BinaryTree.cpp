#include <iostream>
#include <string>
using namespace std;
using ui = unsigned int;

struct BinaryTree {
  static const int NIL = -1;
  struct Node {
    int parent = BinaryTree::NIL;
    int left_child = BinaryTree::NIL;
    int right_child = BinaryTree::NIL;
    ui depth = 0, height = 0;

    ui countChildren() { return (this->left_child != NIL) + (this->right_child != NIL); }
    string type() {
      if (this->depth == 0) {
        return "root";
      } else if (this->countChildren()) {
        return "internal node";
      } else {
        return "leaf";
      }
    }
  };

  Node* nodes = nullptr;
  ui max_depth = 0;
  ui n = 0;

  BinaryTree(ui n) {
    this->n = n;
    this->nodes = new Node[n];
  }
  ~BinaryTree() {
    delete[] this->nodes;
    this->nodes = nullptr;
  }

  Node &operator[](ui i) { return this->nodes[i]; }

  void add(ui id, int left_child, int right_child) {
    this->nodes[id].left_child = left_child;
    this->nodes[id].right_child = right_child;
    this->nodes[left_child].parent = id;
    this->nodes[right_child].parent = id;
  }

  // 全ノードをaddしたあとに深さ等を特定する
  void scan() {
    ui root = this->findRoot();
    this->nodes[root].depth = 0;
    this->scanFrom(root);
  }

  ui findRoot() const {
    int parent = 0;
    while (this->nodes[parent].parent != NIL) {
      parent = this->nodes[parent].parent;
    }
    return parent;
  }

  ui scanFrom(ui from) {
    int right_depth = -1, left_depth = -1;
    ui height = 0;
    ui depth_from = this->nodes[from].depth;
    int left_child = this->nodes[from].left_child;
    if (left_child != NIL) {
      this->nodes[left_child].depth = depth_from + 1;
      if (depth_from + 1 > this->max_depth) this->max_depth = depth_from + 1;
      left_depth = this->scanFrom(left_child);
    }
    int right_child = this->nodes[from].right_child;
    if(right_child != NIL) {
      this->nodes[right_child].depth = depth_from + 1;
      if (depth_from + 1 > this->max_depth) this->max_depth = depth_from + 1;
      right_depth = this->scanFrom(right_child);
    }
    if (left_depth > right_depth) {
      height = left_depth + 1;
    } else {
      height = right_depth + 1;
    }
    this->nodes[from].height = height;
    return height;
  }

  ui getHeight(ui i) { return this->max_depth - this->nodes[i].depth; }

  int getSibling(int i) {
    if (this->nodes[i].parent == NIL) return NIL;
    Node parent = this->nodes[this->nodes[i].parent];
    if (parent.left_child == i) {
      return parent.right_child;
    } else {
      return parent.left_child;
    }
  }

  void showNode(ui i) {
    Node *node = &this->nodes[i];
    cout
      << "node " << i
      << ": parent = " << node->parent
      << ", sibling = " << this->getSibling(i)
      << ", degree = " << node->countChildren()
      << ", depth = " << node->depth
      << ", height = " << node->height
      << ", " << node->type()
      << endl;
  }
};

int main() {
  int n;
  cin >> n;
  BinaryTree tree(n);
  for (int i = 0; i < n; i++) {
    int id, left, right;
    cin >> id >> left >> right;
    tree.add(id, left, right);
  }
  tree.scan();
  for (int i = 0; i < n; i++) {
    tree.showNode(i);
  }
}