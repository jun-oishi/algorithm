#include <bits/stdc++.h>
using namespace std;

int ROWS = 2;

int main() {
  int n;
  cin >> n;
  int a[ROWS][n];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }

  int dp[ROWS][n];
  dp[0][0] = a[0][0];
  for (int i = 1; i < ROWS; i++) dp[i][0] = dp[i - 1][0] + a[i][0];
  for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + a[0][j];
  for (int i = 1; i < ROWS; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
  }
  cout << dp[ROWS - 1][n - 1] << endl;
}