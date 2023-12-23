#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, m, l, r;
  cin >> a >> m >> l >> r;
  l -= a;
  r -= a;

  if (l < 0) {
    r -= m * (l / m - 1);
    l -= m * (l / m - 1);
  }
  long long n = (r / m) - (l / m);
  if (l % m == 0) n++;
  cout << n << endl;
  return 0;
}