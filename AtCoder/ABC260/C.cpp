#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void step_forward(pair<ll, ll> &rb, int x, int y) {
  // すべての赤石を交換
  rb.second += rb.first * x;
  // すべての青石を交換
  rb.first += rb.second;
  rb.second = rb.second * y;
  // cout << "{" << rb.first << ", " << rb.second << "}" << endl;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  // すべての赤を交換して -> (r(n), b(n)) : (r(n-1), n+rx(n))
  // さらにすべての青を交換 -> (r(n), b(n)) : (n+rx(n-1), (n+rx)y(n-1))
  pair<ll, ll> rb = {1, 0};
  int level = n;
  while (level > 1) {
    step_forward(rb, x, y);
    level--;
  }
  cout << rb.second << endl;
}
