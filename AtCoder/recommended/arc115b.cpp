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

  int min_a = a[0];
  for (int i = 1; i < n; i++) min_a = min(min_a, a[i]);
  for (int i = 0; i < n; i++) {
    a[i] -= min_a;
    b[i] += min_a;
  }

  int min_b = b[0];
  for (int i = 0; i < n; i++) min_b = min(min_b, b[i]);
  if (min_b < 0) ans = 0;

  if (ans) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << a[i];
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