# include <iostream>
using namespace std;

struct Tree {
  struct Node {
    static const int NIL = -1;
    int id=NIL, left=NIL, right=NIL, parent = NIL;
  };

  Node* nodes;
  int size;
  int root = Node::NIL;

  Tree(int n) {
    size = n;
    nodes = new Node[n];
  }
  ~Tree() {
    delete[] nodes;
  }

  void add(int id, int left, int right) {
    nodes[id].id = id;
    nodes[id].left = left;
    nodes[id].right = right;
    if (left != Node::NIL) nodes[left].parent = id;
    if (right != Node::NIL) nodes[right].parent = id;
  }

  Node operator[] (int id) const {
    return nodes[id];
  }

  int setRoot() {
    for (int i = 0; i < this->size; i++) {
      if (nodes[i].parent == Node::NIL) {
        this->root = i;
        return this->root;
      }
    }
    return Node::NIL;
  }

  // Arrは長さsizeの配列、nはすでに埋まった最大の添字
  void walkPreorderFrom(int from, int *Arr, int &n) {
    Arr[n++] = from;
    if (nodes[from].left != Node::NIL) {
      this->walkPreorderFrom(nodes[from].left, Arr, n);
    }
    if (nodes[from].right != Node::NIL) {
      this->walkPreorderFrom(nodes[from].right, Arr, n);
    }
  }

  void walkInorderFrom(int from, int *Arr, int &n) {
    if (nodes[from].left != Node::NIL) {
      this->walkInorderFrom(nodes[from].left, Arr, n);
    }
    Arr[n++] = from;
    if (nodes[from].right != Node::NIL) {
      this->walkInorderFrom(nodes[from].right, Arr, n);
    }
  }

  void walkPostorderFrom(int from, int *Arr, int &n) {
    if (nodes[from].left != Node::NIL) {
      this->walkPostorderFrom(nodes[from].left, Arr, n);
    }
    if (nodes[from].right != Node::NIL) {
      this->walkPostorderFrom(nodes[from].right, Arr, n);
    }
    Arr[n++] = from;
  }
};

void showArr(int *Arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << " " << Arr[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  Tree tree(n);
  for (int i = 0; i < n; i++) {
    int id, left, right;
    cin >> id >> left >> right;
    tree.add(id, left, right);
  }
  int root = tree.setRoot();

  int Arr[n];
  int end;

  end = 0;
  tree.walkPreorderFrom(root, Arr, end);
  cout << "Preorder" << endl;
  showArr(Arr, n);

  end = 0;
  tree.walkInorderFrom(root, Arr, end);
  cout << "Inorder" << endl;
  showArr(Arr, n);

  end = 0;
  tree.walkPostorderFrom(root, Arr, end);
  cout << "Postorder" << endl;
  showArr(Arr, n);
}