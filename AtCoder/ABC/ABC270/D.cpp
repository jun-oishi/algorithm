#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  vi a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  int takahashi = 0;
  int aoki = 0;
  auto it = a.rbegin();
  while (n > 0) {
    while (n < *it) {
      it++;
    }
    takahashi += *it;
    n -= *it;

    if (n == 0) {
      break;
    }

    while (n < *it) {
      it++;
    }
    aoki += *it;
    n -= *it;
  }
  cout << takahashi << endl;
}