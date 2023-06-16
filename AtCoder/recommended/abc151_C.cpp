#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int p[m];
  string s[m];
  for (int i = 0; i < m; i++) cin >> p[i] >> s[i];

  bool solved[n];
  for (int i = 0; i < n; i++) solved[i] = false;
  int penalty[n];
  for (int i = 0; i < n; i++) penalty[i] = 0;

  int score = 0;
  int total_penalty = 0;
  for (int i = 0; i < m; i++) {
    if (solved[p[i]]) continue;
    if (s[i] == "AC") {
      score++;
      total_penalty += penalty[p[i]];
      solved[p[i]] = true;
    } else {
      penalty[p[i]]++;
    }
  }
  cout << score << " " << total_penalty << endl;
  return 0;
}