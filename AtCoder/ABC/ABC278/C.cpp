#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  // iがjをフォローしていれば follow[i][j] = true
  vector<vector<bool>> f(n+1, vector<bool>(n+1, false));

  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      f.at(a).at(b) = true;
    } else if (t == 2) {
      f.at(a).at(b) = false;
    } else if (t == 3) {
      if (f.at(a).at(b) && f.at(b).at(a)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}