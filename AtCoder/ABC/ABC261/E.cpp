#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  uint32_t x = c;
  vector<int> t(n);
  vector<uint32_t> a(n);

  // これはTLE
  // nandのみで表現してj番目までをまとめられたら...?
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> a[i];
    // cout << x;
    for (int j=0; j<=i; j++) {
      if (t[j] == 1) {
        x = (x & a[j]);
      } else if (t[j] == 2) {
        x = (x | a[j]);
      } else if (t[j] == 3) {
        x = (x ^ a[j]);
      }
      // cout << " (" << t[j] << ',' << a[j] << ") ->" << x;
    }
    // cout << endl;
    cout << x << endl;
  }
}
