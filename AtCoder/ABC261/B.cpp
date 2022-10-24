#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<char>> A(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }

  string ans = "correct";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (A[i][j] == 'D' && A[j][i] != 'D') {
          ans = "incorrect";
          break;
      } else if (A[i][j] == 'W' && A[j][i] != 'L') {
          ans = "incorrect";
          break;
      } else if (A[i][j] == 'L' && A[j][i] != 'W') {
          ans = "incorrect";
          break;
      }
    }
  }
  cout << ans << endl;
}
