#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long x = N % 998244353;
  if (x < 0) x += 998244353;
  cout << x << endl;
}
