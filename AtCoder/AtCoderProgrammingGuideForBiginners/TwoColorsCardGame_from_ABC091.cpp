#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<string> s(n, "");
  for (int i = 0; i < n; i++) cin >> s.at(i);
  cin >> m;
  vector<string> t(m, "");
  for (int j = 0; j < m; j++) cin >> t.at(j);

  int max = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    string si = s.at(i);
    for (int ii = 0; ii < n; ii++) {
      if (s.at(ii) == si) sum++;
    }
    for (int jj = 0; jj < m; jj++) {
      if (t.at(jj) == si) sum--;
    }
    if (sum > max) max = sum;
  }

  cout << max << endl;
}
