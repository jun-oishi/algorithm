#include <bits/stdc++.h>
using namespace std;

using board = vector<vector<int>>;

long long getValue(
    board &v, int i_ini, int j_ini, int i_step, int j_step
) {
  int n = v.size();
  long long ret = 0;
  // cout << "i_ini: " << i_ini << " j_ini: " << j_ini;
  // cout << " i_step: " << i_step << " j_step: " << j_step << endl;
  for (int i=n-1; i>=0; i--) {
    ret += v[i_ini][j_ini] *  pow(10, i);
    i_ini += i_step;
    if (i_ini < 0) i_ini += n;
    if (i_ini >= n) i_ini -= n;
    j_ini += j_step;
    if (j_ini < 0) j_ini += n;
    if (j_ini >= n) j_ini -= n;
  }
  return ret;
}

long long getMax(board &v, int i_ini, int j_ini) {
  long long ret = 0;
  for (int i_step=-1; i_step<=1; i_step++) {
    for (int j_step=-1; j_step<=1; j_step++) {
      if (i_step == 0 && j_step == 0) continue;
      ret = max(ret, getValue(v, i_ini, j_ini, i_step, j_step));
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  board v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      v[i][j] = c - '0';
      // cout << v[i][j];
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = max(ans, getMax(v, i, j));
    }
  }
  cout << ans << endl;
}