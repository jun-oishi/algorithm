#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, a11, a12, a21, a22;
  cin >> r >> c;
  cin >> a11 >> a12 >> a21 >> a22;

  int ans;
  if (r==1) {
    if (c==1) {
      ans = a11;
    } else {
      ans = a12;
    }
  } else {
    if (c==1) {
      ans = a21;
    } else {
      ans = a22;
    }
  }

  cout << ans << endl;
}