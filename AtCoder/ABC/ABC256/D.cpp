#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i=0; i<n; i++) cin >> l[i] >> r[i];

  // m[x] = {l[i]=xなるiの個数, r[i]=xなるiの個数}
  map<int, pair<int, int>> m;
  // O(NlogN)
  for (int i=0; i<n; i++) {
    // O(logN)
    if (m.count(l[i])) {
      m[l[i]].first++;
    } else {
      m[l[i]] = {1, 0};
    }
    if (m.count(r[i])) {
      m[r[i]].second++;
    } else {
      m[r[i]] = {0, 1};
    }
  }

  int count = 0;
  // O(N)
  for (auto itr : m) {
    int diff = itr.second.first - itr.second.second;
    if (count == 0 && diff > 0) {
      // 区間の左端になる
      cout << itr.first << ' ';
    } else if (count > 0 && diff == -count) {
      // 区間の右端になる
      cout << itr.first << endl;
    }
    count += diff;
  }
}