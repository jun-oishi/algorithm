#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  multiset<int> s;
  cin >> q;
  int max = 0, min = 1e9;

  for (int i = 0; i < q; i++) {
    int command, x, c;
    cin >> command;
    if (command == 1) {
      cin >> x;
      s.insert(x);
    } else if (command == 2) {
      cin >> x >> c;
      for (int j = 0; j < c; j++) {
        if (s.count(x)) {
          s.erase(s.find(x));
        } else {
          break;
        }
      }
    } else if (command == 3) {
      cout << *s.rbegin() - *s.begin() << endl;
    }
  }
}