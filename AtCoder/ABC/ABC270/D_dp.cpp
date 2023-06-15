#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  vi a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  vi max_first(n+1, 0); // max_first[i] = [n=iで始めた先手の最大得点]
  for (int i=1; i<=n; i++) {
    for (int j: a) {
      if (i-j < 0) continue;
      // n=i-j始まりでの後手の(最大)得点
      int max_second = i - j - max_first[i-j];
      max_first[i] = max(max_first[i], max_second+j);
    }
  }

  cout << max_first[n] << endl;
}