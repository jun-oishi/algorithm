#include <bits/stdc++.h>
using namespace std;

int main() {
  int L1, L2, R1, R2;
  cin >> L1 >> R1 >> L2 >> R2;
  int ans;
  if (L1 > R2 || L2 > R1) {
    // 重なりなし
    ans = 0;
  } else {
    // 重なりあり
    ans = min(R1, R2) - max(L1, L2);
  }
  cout << ans << endl;
}
