#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans;
  long long sum = 0;
  for (int i=0; i<m; i++) {
    sum += (i+1) * a[i];
  }
  long long diff = 0;
  // diff は i番目からi+m-1番目までのm項の和
  for (int i=0; i<=m-1; i++) {
    diff += a[i];
  }

  // cout << "0:" << sum << "," << diff << endl;
  ans = sum;
  for (int i=1; i<=n-m; i++) {
    sum = sum - diff + m * a[i+m-1];
    diff = diff - a[i-1] + a[i + m - 1];
    // cout << i << ":" << sum << "," << diff << endl;
    if (sum > ans) {
      ans = sum;
    }
  }
  cout << ans << endl;
}