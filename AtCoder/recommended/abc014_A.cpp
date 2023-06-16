#include <bits/stdc++.h>
using namespace std;

int MAX = 1e9 + 1;

int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);

  int ans = 0;
  for (ans = 0; ans < MAX; ans++) {
    if (a[0] % 2 + a[1] % 2 + a[2] % 2 > 0) break;
    if (a[0] == a[1] && a[1] == a[2]) {
      ans = -1;
      break;
    } else {
      int tmp[] = {a[0], a[1], a[2]};
      a[0] = (tmp[0] + tmp[1]) / 2;
      a[1] = (tmp[0] + tmp[2]) / 2;
      a[2] = (tmp[1] + tmp[2]) / 2;
    }
  }

  cout << ans << endl;

  return 0;
}