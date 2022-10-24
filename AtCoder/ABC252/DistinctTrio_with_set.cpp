#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a.at(i);

  int max_a = 2*100000;
  // vector<int> cnt(max_a+1, 0); // a[i] : aの要素でi以下のものの数
  unordered_map<int, int> cnt; // a[i] : aの要素でi以下のものの数
  for (int i=0; i<max_a+1; i++) cnt[i] = 0;
  for (int ai: a) {
    cnt[ai]++;
  }
  for (int i=1; i<max_a+1; i++) {
    cnt[i] += cnt[i-1];
  }

  int ans = 0;
  // ai, aj, akを昇順に並べて真ん中を決めれば両側の選び方はそれぞれcnt[aj-1], N-cnt[aj]
  for (int aj: a) {
    ans += cnt[aj-1] * (n - cnt[aj]);
  }

  cout << ans << endl;
}