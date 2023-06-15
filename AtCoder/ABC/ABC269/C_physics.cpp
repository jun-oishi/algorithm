#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> ans = {0};
  for (int i=0; i<60; i++) {
    if (n&(1ll<<i)) {
      // 2^i の位が1の場合
      int sz = ans.size();
      for (int j = 0; j < sz; j++) {
        ans.push_back(ans[j] | (1ll<<i));
      }
    }
  }

  for (long long a: ans) {
    cout << a << endl;
  }
}