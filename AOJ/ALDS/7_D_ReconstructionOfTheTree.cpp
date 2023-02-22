#include <iostream>
using namespace std;

void copyArr(int* from, int* to, int n) {
  for (int i = 0; i < n; i++) to[i] = from[i];
}

struct Tree {
  int size;
  int *preorder;
  int *inorder;
  int *postorder;

  Tree(int n, int* preorder, int* inorder) {
    this->size = n;
    this->preorder = new int(n);
    copyArr(preorder, this->preorder, n);
    this->inorder = new int(n);
    copyArr(inorder, this->inorder, n);
    this->postorder = new int(n);
  }
  ~Tree() {
    delete[] this->preorder;
    this->preorder = nullptr;
    delete[] this->inorder;
    this->inorder = nullptr;
    delete[] this->postorder;
    this->postorder = nullptr;
  }

  void setPostorder() {
    int read_head = 0;
    int write_head = 0;
    this->rec(0, this->size, read_head, write_head);
  }

private:
  // inorderのindexがlからr-1である要素を求めてセットする
  void rec(int l, int r, int &read_head, int &write_head) {
    if (r <= l) return;
    int root = preorder[read_head++];
    int divider = -1;
    for (int i = l; i < r; i++) {
      if (inorder[i] == root) divider = i;
    }
    this->rec(l, divider, read_head, write_head); // 左部分木の再構成
    this->rec(divider+1, r, read_head, write_head); // 右部分木の再構成
    postorder[write_head++] = root;
  }
};

int main() {
  int n;
  cin >> n;
  // n = 5;
  int preorder[n], inorder[n];
  for (int i = 0; i < n; i++) cin >> preorder[i];
  for (int i = 0; i < n; i++) cin >> inorder[i];
  // int preorder[5] = {1, 2, 3, 4, 5};
  // int inorder[5] = {3, 2, 4, 1, 5};

  Tree tree(n, preorder, inorder);
  tree.setPostorder();
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << tree.postorder[i];
  }
  cout << endl;
}