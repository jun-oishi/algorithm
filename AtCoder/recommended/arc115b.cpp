#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int c[n][n];
  int a[n], b[n];
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      if (i == 0) b[j] = j ? (c[0][j] - c[0][0]) : 0;
      if (j == 0) a[i] = c[i][j];
      if (j && (c[i][j] - c[i][0] != b[j])) ans = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      for (int j = 0; j < n; j++) {
        a[j] += -b[i] + 1;
      }
    }
  }

  if (ans) {
    cout << "Yes" << endl;
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << c[j][0];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << b[i];
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}