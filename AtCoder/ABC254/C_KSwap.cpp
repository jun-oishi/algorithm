#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a.at(i);

  vector<vector<int>> ak(k);
  for (int i=0; i<n; i++) {
    ak.at(i%k).push_back(a.at(i));
  }
  // akの各ベクトルをソート
  for (int i=0; i<k; i++) {
    vector<int> v = ak.at(i);
    int s = v.size();
    sort(v.begin(), v.end());
    for (int j=0; j<s; j++) {
      a.at(j*k+i) = v.at(j);
    }
  }
  // -> 1つに並べ直して食い違う箇所があればNo
  string ans = "Yes";
  for (int i=0; i<n-1; i++) {
    if (a.at(i) > a.at(i+1)) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}