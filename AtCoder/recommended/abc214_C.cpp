#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  int s[n], t[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) cin >> t[i];

  int *memo = t;
  for (int i = 0; i < 2 * n; i++) {
    memo[(i + 1) % n] = min(memo[(i + 1) % n], memo[i % n] + s[i % n]);
  }
  for (int i = 0; i < n; i++) cout << memo[i] << endl;
}