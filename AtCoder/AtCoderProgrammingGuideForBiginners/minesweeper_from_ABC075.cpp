#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  string s[h + 2];
  for (int i = 1; i <= h; i++) cin >> s[i];
  s[0] = ".";
  for (int j = 1; j < w; j++) s[0] += ".";
  s[h + 1] = s[0];
  for (int i = 0; i <= h + 1; i++) s[i] = "." + s[i] + ".";

  string out[h];
  for (int i = 1; i <= h; i++) {
    out[i - 1] = "";
    for (int j = 1; j <= w; j++) {
      if (s[i].at(j) == '#') {
        out[i - 1] += "#";
        continue;
      }
      int count = 0;
      for (int ii = -1; ii <= 1; ii++) {
        for (int jj = -1; jj <= 1; jj++) {
          // i,j自身も調べても影響しない
          if (s[i + ii].at(j + jj) == '#') {
            count += 1;
          }
        }
      }
      out[i - 1] += to_string(count);
    }
  }

  for (int i = 0; i < h; i++) {
    cout << out[i] << endl;
  }
}
