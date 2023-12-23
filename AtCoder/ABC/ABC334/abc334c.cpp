#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[k];
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  if (k % 2 == 0) {
    for (int i = 1; i < k; i += 2) {
      ans += a[i] - a[i - 1];
    }
  } else {
    ans = a[k - 1] - a[0];
    long long left[k], right[k];
    left[0] = 0;
    for (int i = 2; i < k; i += 2) left[i] = left[i - 2] + a[i - 1] - a[i - 2];
    right[k - 1] = 0;
    for (int i = k - 3; i >= 0; i -= 2)
      right[i] = right[i + 2] + a[i + 2] - a[i + 1];
    for (int i = 0; i < k; i += 2) {  // a[i]を使わない場合
      // cout << "left[" << i << "]=" << left[i] << " right[" << i
      //      << "]=" << right[i] << endl;
      int cand = left[i] + right[i];
      if (cand < ans) ans = cand;
    }
  }
  cout << ans << endl;
}
