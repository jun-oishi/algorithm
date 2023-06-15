#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;

void showAns(vector<int> ans) {
  int n = ans.size();
  cout << ans[0];
  for (int i=1; i<n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}

void showVvi(vvi v) {
  int n = v.size();
  cout << "{";
  for (int i=0; i<n; i++) {
    cout << ",";
    showAns(v[i]);
  }
  cout << "}";
}

// n桁でlからmまでの数からなる数列を全て求める
vvi solve(int n, int l, int m) {
  if (n < 1) {
    return {};
  } else if (n==1) {
    vvi ret;
    for (int i=l; i<=m; i++) {
      ret.push_back({i});
    }
    return ret;
  }

  // cout << "n=" << n << ", l=" << l << ", m=" << m << endl;
  vvi ret;
  for (int i=l; i<=m-n+1; i++) {
    vvi tmp = solve(n-1, i+1, m);
    for (auto v : tmp) {
      v.insert(v.begin(), i);
      ret.push_back(v);
    }
  }
  // showVvi(ret);
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  vvi ans = solve(n, 1, m);
  for (auto v : ans) {
    showAns(v);
  }
}
