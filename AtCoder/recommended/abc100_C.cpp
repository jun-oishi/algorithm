#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (!(a[i] & 1)) {
      ans++;
      a[i] >>= 1;
    }
  }
  cout << ans << endl;
  return 0;
}