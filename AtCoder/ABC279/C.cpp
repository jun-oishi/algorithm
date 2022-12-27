#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;


int main() {
  int h, w;
  cin >> h >> w;
  vs s(h), t(h);
  for (int i = 0; i < h; i++) cin >> s[i];
  for (int i = 0; i < h; i++) cin >> t[i];
  vs s_cols(w), t_cols(w);
  for (int j = 0; j < w; j++) {
    s_cols[j] = "";
    t_cols[j] = "";
    for (int i = 0; i < h; i++) {
      s_cols[j] += s[i][j];
      t_cols[j] += t[i][j];
    }
  }

  sort(s_cols.begin(), s_cols.end());
  sort(t_cols.begin(), t_cols.end());
  if (s_cols == t_cols) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}