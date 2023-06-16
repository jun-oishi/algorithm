#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    p = (p * i) % MOD;
  }
  cout << p << endl;

  return 0;
}