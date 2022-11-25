#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n;
  map<int, ll> a;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cin >> q;
  int def_value = 0;
  for (int j = 0; j < q; j++) {
    int t, i, x;
    cin >> t;
    if (t == 1) {
      cin >> x;
      def_value = x;
      a.clear();
    } else if (t == 2) {
      cin >> i >> x;
      a[i] += x;
    } else if (t == 3) {
      cin >> i;
      if (a.count(i) == 0) {
        cout << def_value << endl;
      } else {
        cout << def_value + a[i] << endl;
      }
    }
  }
}