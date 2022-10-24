#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int ans = -1;
  if (0 < x) {
    if (y < 0 || x < y) {
      ans = x;
    } else {
      if (z < 0) {
        ans = -2*z + x;
      } else if (z < y) {
        ans = x;
      } else {
        ans = -1;
      }
    }
  } else {
    if (y < x || 0 < y) {
      ans = -x;
    } else {
      if (z > 0) {
        ans = 2*z - x;
      } else if (y < z) {
        ans = -x;
      } else {
        ans = -1;
      }
    }
  }
  cout << ans << endl;
}