#include <bits/stdc++.h>
using namespace std;

vector<long long> getNext(vector<long long> v_before) {
  int n = v_before.size();
  vector<long long> v_after(n);
  for (int i=0; i<n; i++) {
    if (i == 0) {
      v_after[i] = max(v_before[i], v_before[i+1]);
    } else if (i == n-1) {
      v_after[i] = max(v_before[i], v_before[i-1]);
    } else {
      v_after[i] = max(
        v_before[i],
        max(v_before[i-1], v_before[i+1])
      );
    }
  }
  return v_after;
}

int v_max(vector<long long> v) {
  long long max = 0;
  int n = v.size();
  for (int i=0; i<n; i++) {
    if (v[i] > max) max = v[i];
  }
  return max;
}

void show_v(vector<long long> v) {
  int n = v.size();
  for (int i=0; i<n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> a[i];
  }

  // dp[i][j] := 時刻iに位置j個にいて得られる得点の最大値
  vector<vector<long long>> dp(t[n-1]+1, vector<long long>(5, 0));

  // 常に t[s] <= i < t[s+1] となるようにする
  int s = -1;
  for (int i=1; i<=t[n-1]; i++) {
    vector<long long> v = getNext(dp[i-1]);
    if (i == t[s+1]) {
      s++;
      v[x[s]] += a[s];
    }
    dp[i] = v;
    // show_v(dp[i]);
  }
  int ans = v_max(dp[t[n-1]]);
  cout << ans << endl;
}
