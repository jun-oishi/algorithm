#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b;
ll g = 1;

double calcTime(ll n) {
  return a/sqrt(g+n) + n*b;
}

int main() {
  cin >> a >> b;
  double n_ = pow(a/b/2.0, 2.0/3) - 1.0;
  if (n_ < 0) n_ = 0;
  cout << fixed << setprecision(10) << min(calcTime(floor(n_)), calcTime(ceil(n_))) << endl;
  return 0;
}