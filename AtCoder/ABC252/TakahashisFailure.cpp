#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(k);
  for (int i=0; i<n; i++) cin >> a.at(i);
  for (int i=0; i<k; i++) cin >> b.at(i);

  int max = 0;
  bool ans = false;
  for (int ai: a) {
    if (ai > max) max = ai;
  }
  for (int bi : b) {
    if (a.at(bi) == max) {
      ans = true;
      break;
    }
  }
  if (ans) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}