#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  deque<char> s;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s.push_back(c);
  }

  // O(nq)
  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      // O(x) = O(n)
      for (int j=0; j<x; j++) {
        s.push_front(s.back());
        s.pop_back();
      }
    } else {
      // O(n)
      for (int j=0; j<n; j++) {
        char c = s.front();
        s.push_back(c);
        s.pop_front();
        if (j == x-1) {
          cout << c << endl;
        }
      }
    }
  }
}