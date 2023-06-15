#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  int m = min(n, x);
  long long ans = 0;
  // c[i] = i番目まで1回ずつクリアするのにかかる時間
  vector<long long> c(m+1);
  c[0] = 0;
  for (int i = 1; i <= m; i++) {
    // i番目までクリアしてその後x回までi番目を繰り返す場合
    c[i] = c[i-1] + a[i-1] + b[i-1];
    long long t = c[i] + ((long long)x-i) * (long long)b[i-1];
    if (ans == 0 || ans > t) ans = t;
  }
  cout << ans << endl;
}