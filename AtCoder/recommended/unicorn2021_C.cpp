#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> b[i][j];
  }

  if ((b[0][0] % 7 + m > 8) || (b[0][0] % 7 == 0 && m > 1)) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j + i == 0) continue;
      if (j == 0 && b[i][0] == b[i - 1][0] + 7) continue;
      if (j > 0 && b[i][j] == b[i][j - 1] + 1) continue;
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}