#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans[2 * n + 2];
  ans[1] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    ans[2 * i] = ans[a] + 1;
    ans[2 * i + 1] = ans[a] + 1;
  }

  for (int i = 1; i <= 2 * n + 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}