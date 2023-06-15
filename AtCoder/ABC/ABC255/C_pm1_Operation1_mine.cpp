#include <bits/stdc++.h>
using namespace std;

long long my_abs(long long n) {
  return (n<0) ? -n : n;
}

int main() {
  long long x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d>0 && x <= a) {
    cout << a-x << endl;
    return 0;
  }
  if (d<0 && a <= x) {
    cout << x-a << endl;
    return 0;
  }

  if (d>0 && x >= a+(n-1)*d) {
    cout << x-(a+(n-1)*d) << endl;
    return 0;
  }
  if (d<0 && x <= a+(n-1)*d) {
    cout << (a+(n-1)*d) - x << endl;
    return 0;
  }

  long long r = my_abs((a-x) % d);
  if (r < my_abs(d) - r) {
    cout << r << endl;
  } else {
    cout << my_abs(d) - r << endl;
  }
}
