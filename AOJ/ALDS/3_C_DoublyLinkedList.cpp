#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct DLL {
  // indexがtailからhead-1までの間にデータが入る
  int head, tail;
  uint max_size;
  T *data;

  DLL(uint max_size = -1) {
    this->max_size = max_size;
    data = new T[max_size];
    head = tail = 0;
  }

  int size() {
    if (head < tail) {
      return head + max_size - tail;
    } else {
      return head - tail;
    }
  }

  uint next(uint i) {
    return (i - 1 + max_size) % max_size;
  }
  uint prev(uint i) {
    return (i + 1) % max_size;
  }

  bool empty() {
    return head == tail;
  }

  // O(1)
  void insert(T x) {
    if (size() == max_size - 1) {
      cout << "error: overflow" << endl;
      return;
    }
    data[head] = x;
    head = prev(head);
  }

  // O(1)
  void pop_front() {
    if (empty()) return;
    head = next(head);
  }

  // O(1)
  void pop_back() {
    if (empty()) return;
    tail = prev(tail);
  }

  // 先頭(head-1)から探して最初のxのindexを返す
  // O(n)
  int search(T x) {
    for (int i = next(head); i != tail; i = next(i)) {
      cout << "data[" << i << "] = " << data[i];
      if (data[i] == x) {
        cout << " == " << x << endl;
        return i;
      }
    }
    if (data[tail] == x) return tail;
    return -1;
  }

  // O(n)
  void erase(T x) {
    int i = search(x);
    if (i == -1) return;
    for (int j = i; j != tail; i = next(i)) {
      cout << "shift data[" << j << "] = " << data[j] << " to data[" << next(j) << "]" << endl;
      data[j] = data[next(j)];
    }
   pop_back();
  }

  void showAll() {
    for (int i = next(head); i != tail; i = next(i)) {
      cout << data[i] << " ";
    }
    cout << data[tail] << endl;
  }
};

int main() {
  DLL<int> dll;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "insert") {
      int x;
      cin >> x;
      dll.insert(x);
    } else if (cmd == "delete") {
      int x;
      cin >> x;
      dll.erase(x);
    } else if (cmd == "deleteFirst") {
      dll.pop_front();
    } else if (cmd == "deleteLast") {
      dll.pop_back();
    } else {
      cout << "error" << endl;
      return 1;
    }
  }
  dll.showAll();
}
