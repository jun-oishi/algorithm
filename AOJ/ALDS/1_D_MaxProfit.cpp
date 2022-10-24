#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; i++) cin >> r[i];

  int max_profit = -1e9;
  int min_before = r[0];
  for (int i = 1; i < n; i++) {
    min_before = min(min_before, r[i - 1]);
    max_profit = max(max_profit, r[i] - min_before);
  }
  cout << max_profit << endl;
}