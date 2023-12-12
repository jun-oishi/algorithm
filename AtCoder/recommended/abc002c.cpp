#include <bits/stdc++.h>

using namespace std;

int main() {
  int x[3], y[3];
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

  x[1] -= x[0];
  y[1] -= y[0];
  x[2] -= x[0];
  y[2] -= y[0];

  double s = (x[1] * y[2] - y[1] * x[2]) * 0.5;
  s = (s > 0) ? s : -s;

  cout << fixed << setprecision(3) << s << endl;
}