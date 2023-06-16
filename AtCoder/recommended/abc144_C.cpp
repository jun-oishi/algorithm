#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  int r = sqrt(n) + 1;
  long long ans;
  for (long long i = r; i > 0; i--) {
    if (n % i) continue;
    ans = (i - 1) + (n / i - 1);
    break;
  }
  cout << ans << endl;
}