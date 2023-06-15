#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i <= n-m; i++) {
    if (s.substr(i, m) == t) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}