#include <bits/stdc++.h>
using namespace std;

long long my_abs(long long n) {
  return (n<0) ? -n : n;
}

int main() {
  long long x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d<0) {
    d = -d;
    a = a - (n-1) * d;
  }
  long long b = a + (n-1) * d;

  long long ans;
  if (x < a) {
    ans = a - x;
  } else if (b < x) {
    ans = x - b;
  } else {
    if (d == 0) {
      ans = 0;
    } else {
      long long m = (x-a) % d;
      ans = min(m, d-m);
    }
  }

  cout << ans << endl;
}
