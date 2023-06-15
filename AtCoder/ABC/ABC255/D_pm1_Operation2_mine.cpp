#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), x(q);
  for (int i=0; i<n; i++) cin >> a.at(i);
  for (int i=0; i<q; i++) cin >> x.at(i);

  for (auto itx = x.begin(); itx != x.end(); itx++) {
    long long ans = 0;
    for (auto ita = a.begin(); ita != a.end(); ita++) {
      ans += abs(*ita - *itx);
    }
    cout << ans << endl;
  }
}
