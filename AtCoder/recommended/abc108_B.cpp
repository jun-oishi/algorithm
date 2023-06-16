#include <bits/stdc++.h>
using namespace std;

int main() {
  int x[4], y[4];
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  for (int i = 2; i < 4; i++) {
    x[i] = x[i - 1] - (y[i - 1] - y[i - 2]);
    y[i] = y[i - 1] + (x[i - 1] - x[i - 2]);
  }
  printf("%d %d %d %d\n", x[2], y[2], x[3], y[3]);
  return 0;
}