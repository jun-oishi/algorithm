#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n+1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<ll> for_diff(n-m+1, 0); // for_diff[i] = a[i] + ... + a[i+m-1]
  for (int i = 1; i <= m; i++) {
    for_diff[1] += a[i];
  }
  for (int i=2; i<=n-m; i++) {
    for_diff[i] = for_diff[i - 1] - a[i - 1] + a[i + m - 1];
  }

  ll sum = 0;
  for (int i = 1; i <= m; i++) {
    sum += i * a[i];
  }
  ll ans = sum;
  for (int i = 1; i <= n-m; i++) {
    // i+1番目始まりの和を求める(1<=i<=n-m)
    // [i+1番目始まりの和] = [i番目始まりの和] - [a[i]からa[i+m-1]までの和] + a[i+m]*m
    sum += -for_diff[i] + a[i+m]*m;
    ans = max(ans, sum);
  }

  cout << ans << endl;
}