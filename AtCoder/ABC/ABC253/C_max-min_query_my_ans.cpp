#include <bits/stdc++.h>
using namespace std;

void drop(vector<int> &s, int x, int c) {
  int count = 0;
  for (auto it = s.begin(); it != s.end();) {
    if (*it == x) {
      it = s.erase(it);
      count++;
      if (count == c) break;
    } else {
      it++;
    }
  }
}

int main() {
  int q;
  vector<int> s;
  cin >> q;
  int max = 0, min = 1e9;

  for (int i = 0; i < q; i++) {
    int command, x, c;
    cin >> command;
    if (command == 1) {
      cin >> x;
      s.push_back(x);
      if (x < min) {
        min = x;
      } else if (x > max) {
        max = x;
      }
    } else if (command == 2) {
      cin >> x >> c;
      drop(s, x, c);
    } else if (command == 3) {
      x = max - min;
      cout << x << endl;
    }
  }
}