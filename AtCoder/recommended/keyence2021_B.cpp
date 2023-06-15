#include <bits/stdc++.h>
using namespace std;

int MAX = 3e5;

int main() {
  int n, k;
  cin >> n >> k;
  int counts[MAX + 1];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    counts[a]++;
  }

  int ans = 0;
  int live = k;
  for (int i = 0; i <= MAX; i++) {
    if (counts[i] == 0) break;
    live = min(live, counts[i]);
    ans += live;
  }
  cout << ans << endl;
}