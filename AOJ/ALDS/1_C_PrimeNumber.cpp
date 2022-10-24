#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
  if (a == 1) return false;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (isPrime(a)) ans++;
  }
  cout << ans << endl;
}