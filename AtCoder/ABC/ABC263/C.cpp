#include <bits/stdc++.h>
using namespace std;

void showAns(vector<int> ans) {
  int n = ans.size();
  cout << ans[0];
  for (int i=1; i<n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> ans(n);
  for (int i = 1; i <= n; i++) {
    ans[i-1] = i;
  }
  showAns(ans);

  while (true) {
    if (ans[n-1] < m) {
      ans[n-1]++;
      showAns(ans);
      continue;
    } else {
      // oは操作する桁を右から数えた数(最下位が1、最上位がn)
      int o = 2;
      while (o <= n) {
        if (ans[n-o] < m - o + 1) {
          // o桁目が増加可能なら増やして最も若い数列を作る
          ans[n-o]++;
          for (int j = n-o+1; j < n; j++) {
            ans[j] = ans[j-1] + 1;
          }
          showAns(ans);
          break;
        } else {
          // o桁目が増加不可能ならo+1桁目を調べる
          if (o == n) return 0;
          o++;
          continue;
        }
      }
    }
  }
}
