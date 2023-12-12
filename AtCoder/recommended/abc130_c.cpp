#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;

  double half = 1.0 * w * h / 2.0;
  int ans = 0;
  if (x * 2 == w and y * 2 == h) ans = 1;
  printf("%.10f %d\n", half, ans);
}