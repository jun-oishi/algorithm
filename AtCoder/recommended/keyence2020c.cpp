#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, s;
  const int MAX = 1e9;
  cin >> n >> k >> s;

  if (s == MAX) {
    for (int i = 0; i < k; i++) {
      if (i) cout << " ";
      cout << s;
    }
    for (int i = k; i < n; i++) {
      if (i) cout << " ";
      cout << 1;
    }
  } else {
    for (int i = 0; i < k; i++) {
      if (i) cout << " ";
      cout << s;
    }
    for (int i = k; i < n; i++) {
      if (i) cout << " ";
      cout << s + 1;
    }
  }
  cout << endl;
}