#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
  int n;
  long long t;
  cin >> n >> t;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  for (long long i: a) {
    sum += i;
  }
  long long q = t % sum;
  // cout << "q:" << q << endl;
  for (int i = 0; i < n; i++) {
    q -= a[i];
    // cout << "-" << a[i] << " -> " << q << endl;
    if (q <= 0) {
      cout << i + 1 << " " << a[i] + q << endl;
      break;
    }
    if (i == n - 1) {
      cout << 1 << " " << q << endl;
    }
  }
  return 0;
}