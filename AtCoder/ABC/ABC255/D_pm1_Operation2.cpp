#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), x(q);
  for (int i=0; i<n; i++) cin >> a.at(i);
  for (int i=0; i<q; i++) cin >> x.at(i);

  sort(a.begin(), a.end());
  vector<int> s(n);
  s.at(0) = a.at(0);
  for (int i=1; i<n; i++) {
    s.at(i) = s.at(i-1) + a.at(i);
  }

  for (auto it = x.begin(); it != x.end(); it++) {
    int st=0, fi=n-1, xi = *it;
    while (st <= fi) {
      int te = (st+fi) / 2;
      if (a.at(te) < xi) {
        st = te + 1;
      } else {
        fi = te - 1;
      }
    }

    long long ans;
    ans = (s.back() - s.at(st)) - xi * (n-st)
          + xi * st - s.at(st);
    cout << ans << endl;
  }
}
