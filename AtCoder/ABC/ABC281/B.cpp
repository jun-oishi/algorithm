#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  if (n != 8) {
    cout << "No" << endl;
    return 0;
  }
  bool ans = true;
  for (int i = 0; i < n; i++) {
    char c = S[i];
    if (i == 0 || i == n - 1) {
      if (c < 'A' || 'Z' < c) {
        ans = false;
        break;
      }
    } else {
      if (c < '0' || '9' < c) {
        ans = false;
        break;
      }
      if (i == 1 && c == '0') {
        ans = false;
        break;
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}