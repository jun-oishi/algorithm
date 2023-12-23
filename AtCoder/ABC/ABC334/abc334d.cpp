#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  long long r[200002];
  long long s[200002];
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> r[i];

  sort(r + 1, r + n + 1);
  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + r[i];

  for (int i = 0; i < q; i++) {
    long long x;
    cin >> x;
    int left = 0, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (s[mid] <= x) {
        left = mid;
      } else {
        right = mid;
      }
    }
    cout << left << endl;
  }
}
